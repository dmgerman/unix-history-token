begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ww.h	2.1 83/07/30		*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|"window.h"
end_include

begin_struct
struct|struct
name|ww_dim
block|{
name|short
name|col
decl_stmt|;
name|short
name|row
decl_stmt|;
name|short
name|ncol
decl_stmt|;
name|short
name|nrow
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ww
block|{
name|char
name|ww_state
decl_stmt|;
comment|/* state of window creation */
name|char
name|ww_mode
decl_stmt|;
comment|/* mode used to open this window */
name|char
name|ww_wstate
decl_stmt|;
comment|/* state for printing charcters */
name|int
name|ww_insert
range|:
literal|1
decl_stmt|;
comment|/* insert mode, for printing */
name|int
name|ww_refresh
range|:
literal|1
decl_stmt|;
comment|/* force refresh after \n and others */
name|char
name|ww_ident
decl_stmt|;
comment|/* the window id */
name|char
modifier|*
name|ww_label
decl_stmt|;
comment|/* the user supplied label */
name|Win
modifier|*
name|ww_win
decl_stmt|;
name|struct
name|ww_dim
name|ww_o
decl_stmt|;
comment|/* outside dimemsions */
name|struct
name|ww_dim
name|ww_i
decl_stmt|;
comment|/* inside dimemsions */
name|struct
name|ww_dim
name|ww_w
decl_stmt|;
comment|/* window dimemsions */
name|int
name|ww_pty
decl_stmt|;
comment|/* pty or socket pair */
name|int
name|ww_tty
decl_stmt|;
name|int
name|ww_pid
decl_stmt|;
name|struct
name|ww
modifier|*
name|ww_next
decl_stmt|;
name|char
name|ww_ttyname
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ww_tty
block|{
name|struct
name|sgttyb
name|ww_sgttyb
decl_stmt|;
name|struct
name|tchars
name|ww_tchars
decl_stmt|;
name|struct
name|ltchars
name|ww_ltchars
decl_stmt|;
name|int
name|ww_lmode
decl_stmt|;
name|int
name|ww_ldisc
decl_stmt|;
name|int
name|ww_pgrp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ww_state values */
end_comment

begin_define
define|#
directive|define
name|WW_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|WW_HASPROC
value|1
end_define

begin_define
define|#
directive|define
name|WW_INCHILD
value|2
end_define

begin_define
define|#
directive|define
name|WW_DEAD
value|3
end_define

begin_comment
comment|/* ww_mode values */
end_comment

begin_define
define|#
directive|define
name|WW_PTY
value|0
end_define

begin_comment
comment|/* has pty */
end_comment

begin_define
define|#
directive|define
name|WW_SOCKET
value|1
end_define

begin_comment
comment|/* has socket pair */
end_comment

begin_define
define|#
directive|define
name|WW_NONE
value|2
end_define

begin_comment
comment|/* has nothing */
end_comment

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'&0x1f)
end_define

begin_define
define|#
directive|define
name|DEL
value|0x7f
end_define

begin_define
define|#
directive|define
name|ISCTRL
parameter_list|(
name|c
parameter_list|)
value|((c)< ' ' || (c)>= DEL)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ww
modifier|*
name|wwhead
decl_stmt|,
modifier|*
name|curwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ww_tty
name|wwoldtty
decl_stmt|,
name|wwnewtty
decl_stmt|,
name|wwwintty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wwnwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wwnwritec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wwnrow
decl_stmt|,
name|wwncol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the screen size */
end_comment

begin_define
define|#
directive|define
name|wwputchar
parameter_list|(
name|c
parameter_list|)
value|wwputc((c), curwin)
end_define

begin_define
define|#
directive|define
name|wwputstr
parameter_list|(
name|s
parameter_list|)
value|wwputs((s), curwin)
end_define

begin_define
define|#
directive|define
name|wwsetcursor
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|(WRCurRow = (r), WRCurCol = (c))
end_define

begin_define
define|#
directive|define
name|wwflush
parameter_list|()
value|Wrefresh(1)
end_define

begin_function_decl
name|struct
name|ww
modifier|*
name|wwopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|wwfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wwchild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|unctrl
parameter_list|()
function_decl|;
end_function_decl

end_unit

