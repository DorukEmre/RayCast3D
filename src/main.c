/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 15:37:15 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void render(void* param)
{
	t_data	*data;

	data = (t_data *)param;
	//printf("sin(ray_angle) = %f, cos(ray_angle) = %f\n", sin(data->player_angle), cos(data->player_angle));
	player_input(data);
	if (data->paint_in_render == TRUE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	initialise(argv[1], &data);
	data.paint_in_render = FALSE;
	mlx_loop_hook(data.mlx, render, &data);
	mlx_key_hook(data.mlx, &minimap_control, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	exit(EXIT_SUCCESS);
}
