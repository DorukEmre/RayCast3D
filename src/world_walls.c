#include "raycast3d.h"

static mlx_texture_t *get_texture(t_data *data,
  mlx_texture_t *texture[], int n_frames)
{
  int num = data->loop % n_frames;
  return (texture[num]);
}

static void	paint_column(t_data *data, double display_h,
	double col_start_y, t_pfv pfv)
{
	double		h;
	double		adjusted_col_start_y;
	uint32_t	wall_color;

	if (col_start_y < 0)
		adjusted_col_start_y = 0;
	else
		adjusted_col_start_y = col_start_y;
	h = 0;
	while (h < adjusted_col_start_y)
		mlx_put_pixel(data->world, pfv.i, h++, data->sky_color);
	while (h < adjusted_col_start_y + display_h)
	{
		if (pfv.obstacle == 'C')
			wall_color = get_col_px_colour_door((h - col_start_y)
					/ pfv.calculated_h, data, pfv,
          get_texture(data, data->door_closed, 18));
		else
			wall_color = get_col_px_colour((h - col_start_y)
					/ pfv.calculated_h, data, pfv);
		mlx_put_pixel(data->world, pfv.i, h, wall_color);
		h++;
	}
	while (h < HEIGHT)
		mlx_put_pixel(data->world, pfv.i, h++, data->floor_color);
}

static void	check_anomalies(t_data *data, t_pfv *pfv)
{
	double	diff1;
	double	diff2;
	double	threshold1;
	double	threshold2;

	diff1 = fabs(pfv->ray_length_n2 - pfv->ray_length_n1);
	diff2 = fabs(pfv->ray_length_n1 - pfv->ray_length);
	threshold1 = 0.1 * pfv->ray_length_n2;
	threshold2 = 0.1 * pfv->ray_length_n1;
	if (pfv->i != 0 && diff1 > threshold1 && diff2 > threshold2)
	{
		pfv->i--;
		paint_column(data, pfv->display_h,
			(HEIGHT / 2) - (pfv->calculated_h / 2), *pfv);
		pfv->i++;
	}
}

void	paint_walls(t_data *data)
{
	t_pfv	pfv;

	pfv.i = 0;
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (data->view_angle / 2) + pfv.i * data->angle_step;
		update_prev_rays_distance_data(&pfv);
		pfv.ray_length = get_wall_distance(data, pfv.ray_angle);
		update_wall_data(data, &pfv);
		if (cos(pfv.ray_angle) > 0)
			get_obstacle_type_on_right_side(data, &pfv);
		else
			get_obstacle_type_on_left_side(data, &pfv);
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		calculate_col_height(&pfv);
		check_player_can_open_door(data, pfv);
		if (pfv.i < WIDTH)
			paint_column(data, pfv.display_h,
				(HEIGHT / 2) - (pfv.calculated_h / 2), pfv);
		check_anomalies(data, &pfv);
		pfv.i++;
	}
}
