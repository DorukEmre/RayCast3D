#include "raycast3d.h"

static void	rotate_player(int key, t_data *data)
{
	double	angle_rotate;

	angle_rotate = 2 * M_PI * data->player_speed / 100;
	if (key == MLX_KEY_LEFT)
	{
		if (data->player_angle - angle_rotate >= 0)
			data->player_angle -= angle_rotate;
		else
			data->player_angle = (2 * M_PI + data->player_angle) - angle_rotate;
	}
	else if (key == MLX_KEY_RIGHT)
	{
		if (data->player_angle + angle_rotate < 2 * M_PI)
			data->player_angle += angle_rotate;
		else
			data->player_angle = angle_rotate - (2 * M_PI - data->player_angle);
	}
}

void	player_input(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(MLX_KEY_LEFT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(MLX_KEY_RIGHT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}
