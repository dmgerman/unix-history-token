begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ww.h	1.2 83/07/17		*/
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
name|ww
block|{
name|int
name|ww_state
range|:
literal|4
decl_stmt|;
name|int
name|ww_wstate
range|:
literal|4
decl_stmt|;
name|int
name|ww_insert
range|:
literal|1
decl_stmt|;
comment|/* insert mode */
name|int
name|ww_refresh
range|:
literal|1
decl_stmt|;
comment|/* force refresh after \n and others */
name|Win
modifier|*
name|ww_win
decl_stmt|;
name|int
name|ww_row
decl_stmt|;
name|int
name|ww_col
decl_stmt|;
name|int
name|ww_nrow
decl_stmt|;
name|int
name|ww_ncol
decl_stmt|;
name|int
name|ww_pty
decl_stmt|;
name|int
name|ww_tty
decl_stmt|;
name|int
name|ww_pid
decl_stmt|;
name|int
name|ww_newrow
decl_stmt|;
comment|/* for cursor addressing */
name|struct
name|ww
modifier|*
name|ww_next
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
name|c
parameter_list|)
value|('c'&0x1f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|ww
modifier|*
name|wwopen
parameter_list|()
function_decl|;
end_function_decl

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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wwnwrite
decl_stmt|;
end_decl_stmt

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

end_unit

