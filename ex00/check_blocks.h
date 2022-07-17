/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_blocks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:47:24 by lmontes-          #+#    #+#             */
/*   Updated: 2022/07/17 11:48:02 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BLOCKS_H
# define CHECK_BLOCKS_H

int	top_check(char **m, char *user_input, int dim);
int	down_check(char **m, char *user_input, int dim);
int	left_check(char **m, char *user_input, int dim);
int	right_check(char **m, char *user_input, int dim);
#endif
