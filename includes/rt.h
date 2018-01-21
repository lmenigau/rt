/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 03:28:23 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/21 04:20:39 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdint.h>
# include "SDL.h"
# include "libft.h"

/*
** =============================================================================
** 								Variables
** =============================================================================
*/

# define WIDTH				1920
# define HEIGHT				1080
# define TITLE				"RTv1"

# define FOV_H				90.0f
# define FOV_V				(int32_t)(FOV_H * (double)HEIGHT / (double)WIDTH)

/*
** =============================================================================
**
** 								Strings
**
** =============================================================================
** 								Colors
** =============================================================================
*/

# define C_SUC				"\033[38;2;141;143;38m"
# define C_ERR				"\033[38;2;231;76;60m"
# define C_INF				"\033[38;2;243;156;18m"
# define C_WRN				"\033[38;2;230;126;34m"

# define C_RED				"\033[38;2;231;76;60m"
# define C_ORA				"\033[38;2;230;126;34m"
# define C_YEL				"\033[38;2;241;196;15m"
# define C_GRE				"\033[38;2;46;204;113m"
# define C_TEA				"\033[38;2;26;188;156m"
# define C_BLU				"\033[38;2;52;152;219m"
# define C_PUR				"\033[38;2;155;89;182m"
# define C_PIN				"\033[38;2;236;64;122m"

# define W_RED				0xe74c3c
# define W_ORA				0xe67e22
# define W_YEL				0xf1c40f
# define W_GRE				0x2ecc71
# define W_TEA				0x1abc9c
# define W_BLU				0x3498db
# define W_PUR				0x9b59b6
# define W_PIN				0xec407a

# define C_WHI				"\033[38;2;236;240;241m"
# define C_LGR				"\033[38;2;146;131;116m"
# define C_MGR				"\033[38;2;102;92;84m"
# define C_DGR				"\033[38;2;60;56;54m"
# define C_BLA				"\033[38;2;44;62;80m"

# define W_WHI				0xecf0f1
# define W_LGR				0x928374
# define W_MGR				0x665c64
# define W_DGR				0x3C3836
# define W_BLA				0x2c3e50

# define C_NRM				"\033[0m"

# define HEADER				C_MGR "[" C_ORA "RTv1" C_MGR "]" C_DGR "-" C_NRM

# define STR_INFO(s)		HEADER C_LGR "[" C_INF "i" C_LGR "] " C_MGR s C_NRM
# define STR_EROR(s)		HEADER C_LGR "[" C_ERR "-" C_LGR "] " C_MGR s C_NRM
# define STR_WARN(s)		HEADER C_LGR "[" C_WRN "!" C_LGR "] " C_MGR s C_NRM

/*
** =============================================================================
**
** 								Typedefs
**
** =============================================================================
** 								Vectors / Utils
** =============================================================================
*/

typedef float				t_vec_type;

typedef struct				s_vec2
{
	t_vec_type				x;
	t_vec_type				y;
}							t_vec2;

typedef struct				s_vec3
{
	t_vec_type				x;
	t_vec_type				y;
	t_vec_type				z;
}							t_vec3;

typedef struct				s_vec4
{
	t_vec_type				w;
	t_vec_type				x;
	t_vec_type				y;
	t_vec_type				z;
}							t_vec4;

typedef struct				s_part_color
{
	uint32_t				a : 8;
	uint32_t				r : 8;
	uint32_t				g : 8;
	uint32_t				b : 8;
}							t_part_color;

typedef union				u_color
{
	uint32_t				code;
	t_part_color			part;
}							t_color;

/*
** =============================================================================
** 								Camera
** =============================================================================
*/

typedef struct				s_cam
{
	t_vec3					pos;
	t_vec3					yaw;
	t_vec3					roll;
	t_vec3					pitch;
	t_vec_type				fov_h;
	t_vec_type				fov_v;
}							t_cam;

/*
** =============================================================================
** 								Objects
** =============================================================================
*/

typedef enum				e_obj_type
{
	OBJ_CUBOID = 0,
	OBJ_SPHERE,
	OBJ_CONE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_MAX,
	OBJ_NONE
}							t_obj_type;

typedef struct				s_obj_template
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
}							t_obj_template;

typedef struct				s_obj_cuboid
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
	t_vec_type				width;
	t_vec_type				height;
	t_vec_type				depth;
}							t_obj_cuboid;

typedef struct				s_obj_elipsoid
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
	t_vec_type				width;
	t_vec_type				height;
	t_vec_type				depth;
}							t_obj_ellipsoid;

typedef struct				s_obj_cone
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
	t_vec_type				theta;
}							t_obj_cone;

typedef struct				s_obj_cylinder
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
	t_vec_type				width;
}							t_obj_cylinder;

typedef struct				s_obj_plane
{
	t_obj_type				type;
	t_color					col;
	t_vec3					pos;
	t_vec3					dir;
}							t_obj_plane;

typedef union				u_object
{
	t_obj_template			template_obj;
	t_obj_cuboid			cuboid;
	t_obj_ellipsoid			ellipsoid;
	t_obj_cone				cone;
	t_obj_cylinder			cylinder;
	t_obj_plane				plane;
}							t_object;

/*
** =============================================================================
** 								Context
** =============================================================================
*/

typedef uint32_t			(*t_input_function)(SDL_Event);

typedef struct				s_context
{
	t_cam					cam;
	SDL_Window				*win;
	SDL_Surface				*surface;
	t_input_function		*key_functions;
	t_input_function		*mouse_functions;
	t_object				*objs;
}							t_context;

/*
** =============================================================================
**
** 								Prototypes
**
** =============================================================================
*/

inline t_vec3				vec3(t_vec_type x, t_vec_type y, t_vec_type z);
inline t_vec_type			dot3(t_vec3 a, t_vec3 b);
inline t_vec_type			mag3(t_vec3 a);
inline t_vec3				cross3(t_vec3 a, t_vec3 b);
inline t_vec3				scal3(t_vec3 a, t_vec_type s);
inline t_vec3				add3(t_vec3 a, t_vec3 b);
inline t_vec3				sub3(t_vec3 a, t_vec3 b);
inline t_vec3				norm3(t_vec3 a);

NORETURN					leave(char *str);

#endif
