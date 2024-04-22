/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 15:19:19 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void hook(void* param)
{
	const mlx_t* mlx = param;
} */

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	
	initialise(argv[1], &data);

//	mlx_loop_hook(mlx, hook, mlx);
	mlx_key_hook(data.mlx, &player_input, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	exit(EXIT_SUCCESS);
}
