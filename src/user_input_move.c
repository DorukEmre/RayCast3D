#include "raycast3d.h"

void	move_forward(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle) * 4;
	end_y = (speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, end_x, end_y) == true)
	{
		data->player_x += (end_x / 4);
		data->player_y += (end_y / 4);
	}
}

void	move_backward(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle) * 4;
	end_y = (speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}

void	move_right(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle - M_PI_2) * 4;
	end_y = (speed / 10) * sin(data->player_angle - M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}

void	move_left(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle + M_PI_2) * 4;
	end_y = (speed / 10) * sin(data->player_angle + M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}
