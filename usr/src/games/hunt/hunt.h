begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)hunt.h	5.2 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OLDIPC
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_else
else|#
directive|else
else|OLDIPC
end_else

begin_include
include|#
directive|include
file|<sys/localopts.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/netltoshort.h>
end_include

begin_endif
endif|#
directive|endif
endif|OLDIPC
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OLDIPC
end_ifndef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
endif|!OLDIPC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROADCAST
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
endif|BROADCAST
end_endif

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_define
define|#
directive|define
name|SOCK_FAMILY
value|AF_INET
end_define

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_define
define|#
directive|define
name|SOCK_FAMILY
value|AF_UNIX
end_define

begin_define
define|#
directive|define
name|AF_UNIX_HACK
end_define

begin_comment
comment|/* 4.2 hack; leaves files around */
end_comment

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_define
define|#
directive|define
name|ADDCH
value|('a' | 0200)
end_define

begin_define
define|#
directive|define
name|MOVE
value|('m' | 0200)
end_define

begin_define
define|#
directive|define
name|REFRESH
value|('r' | 0200)
end_define

begin_define
define|#
directive|define
name|CLRTOEOL
value|('c' | 0200)
end_define

begin_define
define|#
directive|define
name|ENDWIN
value|('e' | 0200)
end_define

begin_define
define|#
directive|define
name|CLEAR
value|('C' | 0200)
end_define

begin_define
define|#
directive|define
name|REDRAW
value|('R' | 0200)
end_define

begin_define
define|#
directive|define
name|LAST_PLAYER
value|('l' | 0200)
end_define

begin_define
define|#
directive|define
name|BELL
value|('b' | 0200)
end_define

begin_define
define|#
directive|define
name|READY
value|('g' | 0200)
end_define

begin_comment
comment|/*  * Choose MAXPL and MAXMON carefully.  The screen is assumed to be  * 23 lines high and will only tolerate (MAXPL == 12&& MAXMON == 0)  * or (MAXPL + MAXMON<= 10).  */
end_comment

begin_define
define|#
directive|define
name|MAXPL
value|9
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MONITOR
end_ifdef

begin_define
define|#
directive|define
name|MAXMON
value|1
end_define

begin_endif
endif|#
directive|endif
endif|MONITOR
end_endif

begin_define
define|#
directive|define
name|NAMELEN
value|20
end_define

begin_define
define|#
directive|define
name|MSGLEN
value|80
end_define

begin_define
define|#
directive|define
name|DECAY
value|50.0
end_define

begin_define
define|#
directive|define
name|NASCII
value|128
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REFLECT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOM
end_ifndef

begin_define
define|#
directive|define
name|RANDOM
end_define

begin_endif
endif|#
directive|endif
endif|RANDOM
end_endif

begin_endif
endif|#
directive|endif
endif|REFLECT
end_endif

begin_define
define|#
directive|define
name|WIDTH
value|59
end_define

begin_define
define|#
directive|define
name|WIDTH2
value|64
end_define

begin_comment
comment|/* Next power of 2>= WIDTH (for fast access) */
end_comment

begin_define
define|#
directive|define
name|HEIGHT
value|23
end_define

begin_define
define|#
directive|define
name|UBOUND
value|1
end_define

begin_define
define|#
directive|define
name|DBOUND
value|22
end_define

begin_define
define|#
directive|define
name|LBOUND
value|1
end_define

begin_define
define|#
directive|define
name|RBOUND
value|(WIDTH - 1)
end_define

begin_define
define|#
directive|define
name|STAT_LABEL_COL
value|60
end_define

begin_define
define|#
directive|define
name|STAT_VALUE_COL
value|74
end_define

begin_define
define|#
directive|define
name|STAT_NAME_COL
value|61
end_define

begin_define
define|#
directive|define
name|STAT_SCAN_COL
value|(STAT_NAME_COL + 5)
end_define

begin_define
define|#
directive|define
name|STAT_NAME_ROW
value|0
end_define

begin_define
define|#
directive|define
name|STAT_AMMO_ROW
value|2
end_define

begin_define
define|#
directive|define
name|STAT_SCAN_ROW
value|3
end_define

begin_define
define|#
directive|define
name|STAT_CLOAK_ROW
value|4
end_define

begin_define
define|#
directive|define
name|STAT_GUN_ROW
value|5
end_define

begin_define
define|#
directive|define
name|STAT_DAM_ROW
value|7
end_define

begin_define
define|#
directive|define
name|STAT_KILL_ROW
value|8
end_define

begin_define
define|#
directive|define
name|STAT_PLAY_ROW
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MONITOR
end_ifdef

begin_define
define|#
directive|define
name|STAT_MON_ROW
value|(STAT_PLAY_ROW + MAXPL + 1)
end_define

begin_endif
endif|#
directive|endif
endif|MONITOR
end_endif

begin_define
define|#
directive|define
name|STAT_NAME_LEN
value|16
end_define

begin_define
define|#
directive|define
name|DOOR
value|'#'
end_define

begin_define
define|#
directive|define
name|WALL1
value|'-'
end_define

begin_define
define|#
directive|define
name|WALL2
value|'|'
end_define

begin_define
define|#
directive|define
name|WALL3
value|'+'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REFLECT
end_ifdef

begin_define
define|#
directive|define
name|WALL4
value|'/'
end_define

begin_define
define|#
directive|define
name|WALL5
value|'\\'
end_define

begin_endif
endif|#
directive|endif
endif|REFLECT
end_endif

begin_define
define|#
directive|define
name|KNIFE
value|'K'
end_define

begin_define
define|#
directive|define
name|SHOT
value|':'
end_define

begin_define
define|#
directive|define
name|GRENADE
value|'o'
end_define

begin_define
define|#
directive|define
name|SATCHEL
value|'O'
end_define

begin_define
define|#
directive|define
name|BOMB
value|'@'
end_define

begin_define
define|#
directive|define
name|MINE
value|';'
end_define

begin_define
define|#
directive|define
name|GMINE
value|'g'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OOZE
end_ifdef

begin_define
define|#
directive|define
name|SLIME
value|'$'
end_define

begin_endif
endif|#
directive|endif
endif|OOZE
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOLCANO
end_ifdef

begin_define
define|#
directive|define
name|LAVA
value|'~'
end_define

begin_endif
endif|#
directive|endif
endif|VOLCANO
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLY
end_ifdef

begin_define
define|#
directive|define
name|FALL
value|'F'
end_define

begin_endif
endif|#
directive|endif
endif|FLY
end_endif

begin_define
define|#
directive|define
name|SPACE
value|' '
end_define

begin_define
define|#
directive|define
name|ABOVE
value|'i'
end_define

begin_define
define|#
directive|define
name|BELOW
value|'!'
end_define

begin_define
define|#
directive|define
name|RIGHT
value|'}'
end_define

begin_define
define|#
directive|define
name|LEFTS
value|'{'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FLY
end_ifdef

begin_define
define|#
directive|define
name|FLYER
value|'&'
end_define

begin_endif
endif|#
directive|endif
endif|FLY
end_endif

begin_define
define|#
directive|define
name|NORTH
value|01
end_define

begin_define
define|#
directive|define
name|SOUTH
value|02
end_define

begin_define
define|#
directive|define
name|EAST
value|010
end_define

begin_define
define|#
directive|define
name|WEST
value|020
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
endif|TRUE
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL
end_ifndef

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|x
parameter_list|)
value|('x'& 037)
end_define

begin_endif
endif|#
directive|endif
endif|CTRL
end_endif

begin_define
define|#
directive|define
name|BULSPD
value|5
end_define

begin_comment
comment|/* bullets movement speed */
end_comment

begin_define
define|#
directive|define
name|ISHOTS
value|15
end_define

begin_define
define|#
directive|define
name|NSHOTS
value|5
end_define

begin_define
define|#
directive|define
name|MAXNCSHOT
value|2
end_define

begin_define
define|#
directive|define
name|MAXDAM
value|10
end_define

begin_define
define|#
directive|define
name|MINDAM
value|5
end_define

begin_define
define|#
directive|define
name|STABDAM
value|2
end_define

begin_define
define|#
directive|define
name|BULREQ
value|1
end_define

begin_define
define|#
directive|define
name|GRENREQ
value|9
end_define

begin_define
define|#
directive|define
name|SATREQ
value|25
end_define

begin_define
define|#
directive|define
name|BOMBREQ
value|49
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OOZE
end_ifdef

begin_define
define|#
directive|define
name|SLIMEREQ
value|15
end_define

begin_define
define|#
directive|define
name|SSLIMEREQ
value|30
end_define

begin_define
define|#
directive|define
name|SLIMESPEED
value|5
end_define

begin_endif
endif|#
directive|endif
endif|OOZE
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOLCANO
end_ifdef

begin_define
define|#
directive|define
name|LAVASPEED
value|2
end_define

begin_endif
endif|#
directive|endif
endif|VOLCANO
end_endif

begin_define
define|#
directive|define
name|CLOAKLEN
value|20
end_define

begin_define
define|#
directive|define
name|SCANLEN
value|(Nplayer * 20)
end_define

begin_define
define|#
directive|define
name|EXPLEN
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FLY
end_ifdef

begin_define
define|#
directive|define
name|_cloak_char
parameter_list|(
name|pp
parameter_list|)
value|(((pp)->p_cloak< 0) ? ' ' : '+')
end_define

begin_define
define|#
directive|define
name|_scan_char
parameter_list|(
name|pp
parameter_list|)
value|(((pp)->p_scan< 0) ? _cloak_char(pp) : '*')
end_define

begin_define
define|#
directive|define
name|stat_char
parameter_list|(
name|pp
parameter_list|)
value|(((pp)->p_flying< 0) ? _scan_char(pp) : FLYER)
end_define

begin_else
else|#
directive|else
else|FLY
end_else

begin_define
define|#
directive|define
name|_cloak_char
parameter_list|(
name|pp
parameter_list|)
value|(((pp)->p_cloak< 0) ? ' ' : '+')
end_define

begin_define
define|#
directive|define
name|stat_char
parameter_list|(
name|pp
parameter_list|)
value|(((pp)->p_scan< 0) ? _cloak_char(pp) : '*')
end_define

begin_endif
endif|#
directive|endif
endif|FLY
end_endif

begin_typedef
typedef|typedef
name|int
name|FLAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bullet_def
name|BULLET
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|expl_def
name|EXPL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|player_def
name|PLAYER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ident_def
name|IDENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|regen_def
name|REGEN
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|sockaddr_in
name|SOCKET
typedef|;
end_typedef

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_typedef
typedef|typedef
name|struct
name|sockaddr_un
name|SOCKET
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_typedef
typedef|typedef
name|struct
name|sgttyb
name|TTYB
typedef|;
end_typedef

begin_struct
struct|struct
name|ident_def
block|{
name|char
name|i_name
index|[
name|NAMELEN
index|]
decl_stmt|;
name|long
name|i_machine
decl_stmt|;
name|long
name|i_uid
decl_stmt|;
name|int
name|i_kills
decl_stmt|;
name|int
name|i_entries
decl_stmt|;
name|float
name|i_score
decl_stmt|;
name|IDENT
modifier|*
name|i_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|player_def
block|{
name|IDENT
modifier|*
name|p_ident
decl_stmt|;
name|int
name|p_face
decl_stmt|;
name|char
name|p_over
decl_stmt|;
name|int
name|p_undershot
decl_stmt|;
ifdef|#
directive|ifdef
name|FLY
name|int
name|p_flying
decl_stmt|;
name|int
name|p_flyx
decl_stmt|,
name|p_flyy
decl_stmt|;
endif|#
directive|endif
endif|FLY
name|FILE
modifier|*
name|p_output
decl_stmt|;
name|int
name|p_fd
decl_stmt|;
name|int
name|p_mask
decl_stmt|;
name|int
name|p_damage
decl_stmt|;
name|int
name|p_damcap
decl_stmt|;
name|int
name|p_ammo
decl_stmt|;
name|int
name|p_ncshot
decl_stmt|;
name|int
name|p_scan
decl_stmt|;
name|int
name|p_cloak
decl_stmt|;
name|int
name|p_x
decl_stmt|,
name|p_y
decl_stmt|;
name|int
name|p_ncount
decl_stmt|;
name|int
name|p_nexec
decl_stmt|;
name|long
name|p_nchar
decl_stmt|;
name|char
name|p_death
index|[
name|MSGLEN
index|]
decl_stmt|;
name|char
name|p_maze
index|[
name|HEIGHT
index|]
index|[
name|WIDTH2
index|]
decl_stmt|;
name|int
name|p_curx
decl_stmt|,
name|p_cury
decl_stmt|;
name|int
name|p_lastx
decl_stmt|,
name|p_lasty
decl_stmt|;
name|int
name|p_changed
decl_stmt|;
name|char
name|p_cbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bullet_def
block|{
name|int
name|b_x
decl_stmt|,
name|b_y
decl_stmt|;
name|int
name|b_face
decl_stmt|;
name|int
name|b_charge
decl_stmt|;
name|char
name|b_type
decl_stmt|;
name|char
name|b_over
decl_stmt|;
name|PLAYER
modifier|*
name|b_owner
decl_stmt|;
name|IDENT
modifier|*
name|b_score
decl_stmt|;
name|FLAG
name|b_expl
decl_stmt|;
name|BULLET
modifier|*
name|b_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|expl_def
block|{
name|int
name|e_x
decl_stmt|,
name|e_y
decl_stmt|;
name|char
name|e_char
decl_stmt|;
name|EXPL
modifier|*
name|e_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regen_def
block|{
name|int
name|r_x
decl_stmt|,
name|r_y
decl_stmt|;
name|REGEN
modifier|*
name|r_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * external variables  */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|Last_player
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Buf
index|[
name|BUFSIZ
index|]
decl_stmt|,
name|Maze
index|[
name|HEIGHT
index|]
index|[
name|WIDTH2
index|]
decl_stmt|,
name|Orig_maze
index|[
name|HEIGHT
index|]
index|[
name|WIDTH2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Sock_name
decl_stmt|,
modifier|*
name|Driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|,
name|Have_inp
decl_stmt|,
name|Nplayer
decl_stmt|,
name|Num_fds
decl_stmt|,
name|Socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Fds_mask
decl_stmt|,
name|Sock_mask
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|Test_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Sock_port
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Sock_name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOLCANO
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|volcano
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VOLCANO
end_endif

begin_decl_stmt
specifier|extern
name|int
name|See_over
index|[
name|NASCII
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BULLET
modifier|*
name|Bullets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EXPL
modifier|*
name|Expl
index|[
name|EXPLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|IDENT
modifier|*
name|Scores
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PLAYER
name|Player
index|[
name|MAXPL
index|]
decl_stmt|,
modifier|*
name|End_player
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MONITOR
end_ifdef

begin_decl_stmt
specifier|extern
name|FLAG
name|Am_monitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PLAYER
name|Monitor
index|[
name|MAXMON
index|]
decl_stmt|,
modifier|*
name|End_monitor
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MONITOR
end_endif

begin_comment
comment|/*  * function types  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|IDENT
modifier|*
name|get_ident
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|moveshots
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|BULLET
modifier|*
name|is_bullet
argument_list|()
decl_stmt|,
modifier|*
name|create_shot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PLAYER
modifier|*
name|play_at
parameter_list|()
function_decl|;
end_function_decl

end_unit

