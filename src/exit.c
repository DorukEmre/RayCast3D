#include "raycast3d.h"

void	exit_game(t_data *data)
{
	if (data->display_minimap == TRUE)
		mlx_delete_image(data->mlx, data->minimap);
	mlx_delete_image(data->mlx, data->sprite);
	mlx_delete_image(data->mlx, data->world);
	mlx_delete_texture(data->wall_no);
	mlx_delete_texture(data->wall_so);
	mlx_delete_texture(data->wall_we);
	mlx_delete_texture(data->wall_ea);
  for (size_t i = 0; i < 18; i++)
  {
  	mlx_delete_texture(data->door_closed[i]);
  }
  for (size_t i = 0; i < 2; i++)
  {
  	mlx_delete_texture(data->anim1[i]);
  }
  for (size_t i = 0; i < 13; i++) // 25
  {
  	mlx_delete_texture(data->anim2[i]);
  }
  for (size_t i = 0; i < 16; i++) // 24
  {
  	mlx_delete_texture(data->anim3[i]);
  }
  for (size_t i = 0; i < 10; i++)
  {
  	mlx_delete_texture(data->anim4[i]);
  }
	mlx_terminate(data->mlx);
	free_string_array(data->map);
}
