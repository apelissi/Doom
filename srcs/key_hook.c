/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/11 19:11:15 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int	key_press(int k, t_env *e)
{
	e->pe->mv_y = (k == W) ? 1 : e->pe->mv_y;
	e->pe->mv_y = (k == S) ? -1 : e->pe->mv_y;
	e->pe->mv_x = (k == D) ? -1 : e->pe->mv_x;
	e->pe->mv_x = (k == A) ? 1 : e->pe->mv_x;
	e->pe->mv_r = (k == RIGHT) ? -1 : e->pe->mv_r;
	e->pe->mv_r = (k == LEFT) ? 1 : e->pe->mv_r;
	e->pe->mv_z = (k == DOWN) ? -5 : e->pe->mv_z;
	e->pe->mv_z = (k == UP) ? 5 : e->pe->mv_z;

	if (k == M)
		e->pm = (e->pm) ? 0 : 1;
	if (k == P)
	{
		e->p = 0;
		e->psi = (e->psi) ? 0 : 1;
	}
	if (k == C)
	{
		e->pe->pos_z = (!e->pe->pos_z) ? -TS : 0;
		e->pe->vd = (!e->pe->pos_z) ? 3 : 5;
	}  
	printf("Z = %d \n", e->pe->pos_z);
	expose_hook(e);
	return (0);
}

int	key_release(int k, t_env *e)
{
	if (k == ESC)
		ft_exit(3);
	if (k == W || k == S)
		e->pe->mv_y = 0;
	if (k == D || k == A)
		e->pe->mv_x = 0;
	if (k == LEFT || k == RIGHT)
		e->pe->mv_r = 0;
	if (k == UP || k == DOWN)
		e->pe->mv_z = 0;
	expose_hook(e);
	return (0);
}
