/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:55:53 by demre             #+#    #+#             */
/*   Updated: 2024/04/29 13:17:48 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_data *data)
{
	mlx_delete_texture(data->wall_no);
	mlx_delete_texture(data->wall_so);
	mlx_delete_texture(data->wall_we);
	mlx_delete_texture(data->wall_ea);
//	mlx_delete_image(data->mlx, data->minimap);
//	mlx_delete_image(data->mlx, data->world);
//	mlx_delete_image(data->mlx, data->buffer_world);
	mlx_terminate(data->mlx);
	free_string_array(data->map);
}
