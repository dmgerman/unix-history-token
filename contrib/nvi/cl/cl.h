begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)cl.h	10.19 (Berkeley) 9/24/96  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_private
block|{
name|CHAR_T
name|ibuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* Input keys. */
name|int
name|eof_count
decl_stmt|;
comment|/* EOF count. */
name|struct
name|termios
name|orig
decl_stmt|;
comment|/* Original terminal values. */
name|struct
name|termios
name|ex_enter
decl_stmt|;
comment|/* Terminal values to enter ex. */
name|struct
name|termios
name|vi_enter
decl_stmt|;
comment|/* Terminal values to enter vi. */
name|char
modifier|*
name|el
decl_stmt|;
comment|/* Clear to EOL terminal string. */
name|char
modifier|*
name|cup
decl_stmt|;
comment|/* Cursor movement terminal string. */
name|char
modifier|*
name|cuu1
decl_stmt|;
comment|/* Cursor up terminal string. */
name|char
modifier|*
name|rmso
decl_stmt|,
modifier|*
name|smso
decl_stmt|;
comment|/* Inverse video terminal strings. */
name|char
modifier|*
name|smcup
decl_stmt|,
modifier|*
name|rmcup
decl_stmt|;
comment|/* Terminal start/stop strings. */
name|int
name|killersig
decl_stmt|;
comment|/* Killer signal. */
define|#
directive|define
name|INDX_HUP
value|0
define|#
directive|define
name|INDX_INT
value|1
define|#
directive|define
name|INDX_TERM
value|2
define|#
directive|define
name|INDX_WINCH
value|3
define|#
directive|define
name|INDX_MAX
value|4
comment|/* Original signal information. */
name|struct
name|sigaction
name|oact
index|[
name|INDX_MAX
index|]
decl_stmt|;
enum|enum
block|{
comment|/* Tty group write mode. */
name|TGW_UNKNOWN
init|=
literal|0
block|,
name|TGW_SET
block|,
name|TGW_UNSET
block|}
name|tgw
enum|;
enum|enum
block|{
comment|/* Terminal initialization strings. */
name|TE_SENT
init|=
literal|0
block|,
name|TI_SENT
block|}
name|ti_te
enum|;
define|#
directive|define
name|CL_IN_EX
value|0x0001
comment|/* Currently running ex. */
define|#
directive|define
name|CL_RENAME
value|0x0002
comment|/* X11 xterm icon/window renamed. */
define|#
directive|define
name|CL_RENAME_OK
value|0x0004
comment|/* User wants the windows renamed. */
define|#
directive|define
name|CL_SCR_EX_INIT
value|0x0008
comment|/* Ex screen initialized. */
define|#
directive|define
name|CL_SCR_VI_INIT
value|0x0010
comment|/* Vi screen initialized. */
define|#
directive|define
name|CL_SIGHUP
value|0x0020
comment|/* SIGHUP arrived. */
define|#
directive|define
name|CL_SIGINT
value|0x0040
comment|/* SIGINT arrived. */
define|#
directive|define
name|CL_SIGTERM
value|0x0080
comment|/* SIGTERM arrived. */
define|#
directive|define
name|CL_SIGWINCH
value|0x0100
comment|/* SIGWINCH arrived. */
define|#
directive|define
name|CL_STDIN_TTY
value|0x0200
comment|/* Talking to a terminal. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
name|CL_PRIVATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLP
parameter_list|(
name|sp
parameter_list|)
value|((CL_PRIVATE *)((sp)->gp->cl_private))
end_define

begin_define
define|#
directive|define
name|GCLP
parameter_list|(
name|gp
parameter_list|)
value|((CL_PRIVATE *)gp->cl_private)
end_define

begin_comment
comment|/* Return possibilities from the keyboard read routine. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|INP_OK
init|=
literal|0
block|,
name|INP_EOF
block|,
name|INP_ERR
block|,
name|INP_INTR
block|,
name|INP_TIMEOUT
block|}
name|input_t
typedef|;
end_typedef

begin_comment
comment|/* The screen line relative to a specific window. */
end_comment

begin_define
define|#
directive|define
name|RLNO
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|)
value|(sp)->woff + (lno)
end_define

begin_comment
comment|/* X11 xterm escape sequence to rename the icon/window. */
end_comment

begin_define
define|#
directive|define
name|XTERM_RENAME
value|"\033]0;%s\007"
end_define

begin_comment
comment|/*  * XXX  * Some implementations of curses.h don't define these for us.  Used for  * compatibility only.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cl_extern.h"
end_include

end_unit

