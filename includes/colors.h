/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:34:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/28 13:17:41 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*
** Reset color / background
*/
# define CRES		"\033[0m"

/*
** Color text
*/
# define CBLA		"\033[30m"
# define CRED		"\033[31m"
# define CGRE		"\033[32m"
# define CYEL		"\033[33m"
# define CBLU		"\033[34m"
# define CPIN		"\033[35m"
# define CCYA		"\033[36m"
# define CWHI		"\033[37m"

/*
** Color text lihgt
*/
# define LBLA		"\033[1m\033[30m"
# define LRED		"\033[1m\033[31m"
# define LGRE		"\033[1m\033[32m"
# define LYEL		"\033[1m\033[33m"
# define LBLU		"\033[1m\033[34m"
# define LPIN		"\033[1m\033[35m"
# define LCYA		"\033[1m\033[36m"
# define LWHI		"\033[1m\033[37m"

/*
** Color text after reset color
*/
# define RBLA		"\033[0m\033[30m"
# define RRED		"\033[0m\033[31m"
# define RGRE		"\033[0m\033[32m"
# define RYEL		"\033[0m\033[33m"
# define RBLU		"\033[0m\033[34m"
# define RPIN		"\033[0m\033[35m"
# define RCYA		"\033[0m\033[36m"
# define RWHI		"\033[0m\033[37m"

/*
** Color backgroud (revers with SVID)
*/
# define BBLA		"\033[40m"
# define BRED		"\033[41m"
# define BGRE		"\033[42m"
# define BYEL		"\033[43m"
# define BBLU		"\033[44m"
# define BPIN		"\033[45m"
# define BCYA		"\033[46m"
# define BWHI		"\033[47m"

/*
** Style text
*/
# define SBOL		"\033[1m"
# define SUND		"\033[4m"
# define SBLI		"\033[5m"
# define SVID		"\033[7m"

# define BOLDNRM	"\033[1m\033[37m"

#endif
