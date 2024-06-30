#include "raycast3d.h"

uint32_t	pack_rgba(uint8_t pixels[4])
{
	uint32_t	color;

	color = 0;
	color |= ((uint32_t)pixels[0] << 24);
	color |= ((uint32_t)pixels[1] << 16);
	color |= ((uint32_t)pixels[2] << 8);
	color |= pixels[3];
	return (color);
}

static uint32_t	get_colour_from_texture(double ratio_x, double calc_h,
	mlx_texture_t *texture)
{
	uint32_t		index;
	uint8_t			rgba[4];
	unsigned int	i;

	if (!texture || !texture->pixels || ratio_x >= 1 || calc_h >= 1)
		return (0);
	index = ((uint32_t)(texture->height * calc_h) * texture->width
			+ (uint32_t)(texture->width * ratio_x))
		* texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
}

mlx_texture_t *get_texture(t_data *data,
  mlx_texture_t *texture[], int n_frames)
{
  int num = data->loop % n_frames;
  return (texture[num]);
}

mlx_texture_t *get_current_texture(t_data *data, mlx_texture_t *texture[],
  int n_textures)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    double elapsed_time = (current_time.tv_sec - data->start_time.tv_sec) +
                          (current_time.tv_usec - data->start_time.tv_usec) / 1000000.0;

    int current_frame = (int)(elapsed_time / 0.15) % n_textures;

    return texture[current_frame];
}

uint32_t	get_col_px_colour(double calc_h, t_data *data, t_pfv pfv)
{
  static mlx_texture_t *text_no;
  static mlx_texture_t *text_so;
  static mlx_texture_t *text_ea;
  static mlx_texture_t *text_we;
  if (pfv.i == 0)
  {
    text_no = get_current_texture(data, data->anim1, 2);
    text_so = get_current_texture(data, data->anim4, 10);
    text_ea = get_current_texture(data, data->anim3, 24);
    text_we = get_current_texture(data, data->anim2, 25);
  }

	if (pfv.i != 0 && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
	{
		pfv.wall_x = pfv.wall_x_n1;
		pfv.wall_y = pfv.wall_y_n1;
	}
	if (pfv.wall_y > data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001)
		return (get_colour_from_texture(1 - pfv.wall_x + (int)pfv.wall_x,
				calc_h, text_no)); // data->wall_no
	else if (pfv.wall_y < data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001)
		return (get_colour_from_texture(pfv.wall_x - (int)pfv.wall_x,
				calc_h, text_so)); // data->wall_so
	else if (pfv.wall_x > data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
		return (get_colour_from_texture(pfv.wall_y - (int)pfv.wall_y,
				calc_h, text_ea)); // data->wall_ea
	else if (pfv.wall_x < data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
		return (get_colour_from_texture(1 - pfv.wall_y + (int)pfv.wall_y,
				calc_h, text_we)); // data->wall_we
	else
		return (0x33333388);
}
