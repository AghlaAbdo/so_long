/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:50:00 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/26 10:08:21 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_destroy_imgs(t_data *data, void **img, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		mlx_destroy_image(data->mlx_ptr, img[i++]);
	}
}

// void	data_imgs_des_init(t_data *data, int der)
// {
// 	if (data->der == 0 && der == 1)
// 	{
// 		// mlx_destroy_image(data->mlx_ptr, data->p_img);
// 		init_plr_frames(data, 1);
// 		data->der = 1;
// 	}
// 	else if (data->der == 1 && der == 0)
// 	{
// 		// mlx_destroy_image(data->mlx_ptr, data->p_img);
// 		init_plr_frames(data, 0);
// 		data->der = 0;
// 	}
// }
