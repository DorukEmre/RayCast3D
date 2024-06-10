#include "raycast3d.h"

void	calculate_col_height(t_pfv *pfv)
{
	pfv->calculated_h = 0.94 * WIDTH / pfv->ray_length;
	if (pfv->calculated_h > HEIGHT)
		pfv->display_h = HEIGHT;
	else
		pfv->display_h = pfv->calculated_h;
}

void	get_obstacle_type_on_right_side(t_data *data, t_pfv *pfv)
{
	if (sin(pfv->ray_angle) > 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y + 0.2);
	}
	else if (sin(pfv->ray_angle) > 0)
	{
		pfv->obs_x = (int)(pfv->wall_x + 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	else if (sin(pfv->ray_angle) <= 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y - 0.2);
	}
	else
	{
		pfv->obs_x = (int)(pfv->wall_x + 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	pfv->obstacle = data->map[pfv->obs_y][pfv->obs_x];
}

void	get_obstacle_type_on_left_side(t_data *data, t_pfv *pfv)
{
	if (sin(pfv->ray_angle) > 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y + 0.2);
	}
	else if (sin(pfv->ray_angle) > 0)
	{
		pfv->obs_x = (int)(pfv->wall_x - 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	else if (sin(pfv->ray_angle) <= 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y - 0.2);
	}
	else
	{
		pfv->obs_x = (int)(pfv->wall_x - 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	pfv->obstacle = data->map[pfv->obs_y][pfv->obs_x];
}

void	update_wall_data(t_data *data, t_pfv *pfv)
{
	pfv->wall_x_n1 = pfv->wall_x;
	pfv->wall_y_n1 = pfv->wall_y;
	pfv->wall_x = data->player_x + cos(pfv->ray_angle) * pfv->ray_length;
	pfv->wall_y = data->player_y + sin(pfv->ray_angle) * pfv->ray_length;
}

void	update_prev_rays_distance_data(t_pfv *pfv)
{
	if (pfv->i == 0)
		pfv->ray_length_n1 = pfv->ray_length;
	pfv->ray_length_n2 = pfv->ray_length_n1;
	pfv->ray_length_n1 = pfv->ray_length;
}
