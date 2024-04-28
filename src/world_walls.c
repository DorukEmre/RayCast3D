/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 17:02:45 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_intersection(t_data *data, double ray_angle,
	double *wall_x, double *wall_y)
{
	double	distance_to_wall;
	double	ray_dx;
	double	ray_dy;

	distance_to_wall = 0;
	*wall_x = data->player_x;
	*wall_y = data->player_y;
	ray_dx = cos(ray_angle) * 0.01;
	ray_dy = sin(ray_angle) * 0.01;
//	printf("wall_x: %f, wall_y: %f\n", *wall_x, *wall_y);
	while (1)
	{
		distance_to_wall += 0.01;
		*wall_x += ray_dx;
		*wall_y += ray_dy;
		if (can_move(data->map[(int)(*wall_y)][(int)(*wall_x)]) == false)
			break ;
	}
	distance_to_wall *= cos(ray_angle - data->player_angle);
	distance_to_wall = round(distance_to_wall * 100 ) / 100;
//	printf("wall_x: %f, wall_y: %f, distance_to_wall: %f\n", *wall_x, *wall_y, distance_to_wall);
	return (distance_to_wall);
}

static void	paint_column(t_data *data, double calculated_h, t_pfv pfv)
{
	double			h;
	unsigned int	colour;

	h = 0;
	while (h < calculated_h)
	{
		if ((WIDTH * pfv.i / NUM_OF_RAYS) < WIDTH)
		{
			colour = get_col_px_colour(data, pfv);
			mlx_put_pixel(data->world,
				WIDTH * pfv.i / NUM_OF_RAYS,
				(HEIGHT / 2) - (calculated_h / 2) + h,
				colour);
		}
		h++;
	}
}

void	paint_walls(t_data *data)
{
	t_pfv	pfv;
	double	calculated_h;

	pfv.i = 0;
	pfv.view_angle = PLAYER_FOV * (M_PI / 180);
	pfv.angle_step = pfv.view_angle / NUM_OF_RAYS;
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (pfv.view_angle / 2) + pfv.i * pfv.angle_step;
		pfv.ray_length = get_intersection(data, pfv.ray_angle, &pfv.wall_x,
			&pfv.wall_y);
//	unsigned int colour = get_col_px_colour(data, pfv); //
//	printf("%d, wall_x:y: %f:%f, player_x:y: %f:%f, distance_to_wall: %.2f, colour: %u\n", pfv.i, pfv.wall_x, pfv.wall_y, data->player_x, data->player_y, pfv.ray_length, colour);
//	printf("pfv.wall_x - data->player_x: %.3f, (pfv.wall_x - round(pfv.wall_x): %.3f, pfv.wall_y - data->player_y: %.3f, (pfv.wall_y - round(pfv.wall_y)): %.3f\n", pfv.wall_x - data->player_x, (pfv.wall_x - round(pfv.wall_x)), pfv.wall_y - data->player_y, (pfv.wall_y - round(pfv.wall_y)));
		calculated_h = calculate_col_height(data, pfv);
	//	printf("WIDTH * %d / NUM_OF_RAYS: %d, calculated_h: %f\n",
	//		pfv.i, WIDTH * pfv.i / NUM_OF_RAYS, calculated_h);
	//	printf("(HEIGHT / 2) - (calculated_h / 2) - h: %f\n",
	//		(HEIGHT / 2) - (calculated_h / 2) + 0);

		paint_column(data, calculated_h, pfv);
		pfv.i++;
	}
}
