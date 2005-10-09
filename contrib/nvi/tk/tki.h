begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)tki.h	8.6 (Berkeley) 4/27/96  */
end_comment

begin_include
include|#
directive|include
file|<tcl.h>
end_include

begin_include
include|#
directive|include
file|<tk.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_tk_private
block|{
name|Tcl_Interp
modifier|*
name|interp
decl_stmt|;
comment|/* Tcl interpreter cookie. */
comment|/* Shared variables. */
name|int
name|tk_cursor_row
decl_stmt|;
comment|/* Current cursor row. */
name|int
name|tk_cursor_col
decl_stmt|;
comment|/* Current cursor col. */
name|int
name|tk_ssize_row
decl_stmt|;
comment|/* Screen rows. */
name|int
name|tk_ssize_col
decl_stmt|;
comment|/* Screen columns. */
name|struct
name|termios
name|orig
decl_stmt|;
comment|/* Original terminal values. */
name|CHAR_T
name|ibuf
index|[
literal|64
index|]
decl_stmt|;
comment|/* Input keys. */
name|int
name|ibuf_cnt
decl_stmt|;
comment|/* Number of input keys. */
comment|/* Event queue. */
name|TAILQ_HEAD
argument_list|(
argument|_eventh
argument_list|,
argument|_event
argument_list|)
name|evq
expr_stmt|;
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
define|#
directive|define
name|TK_LLINE_IV
value|0x0001
comment|/* Last line is in inverse video. */
define|#
directive|define
name|TK_SCR_VI_INIT
value|0x0002
comment|/* Vi screen initialized. */
define|#
directive|define
name|TK_SIGHUP
value|0x0004
comment|/* SIGHUP arrived. */
define|#
directive|define
name|TK_SIGINT
value|0x0008
comment|/* SIGINT arrived. */
define|#
directive|define
name|TK_SIGTERM
value|0x0010
comment|/* SIGTERM arrived. */
define|#
directive|define
name|TK_SIGWINCH
value|0x0020
comment|/* SIGWINCH arrived. */
name|u_int16_t
name|flags
decl_stmt|;
block|}
name|TK_PRIVATE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|GS
modifier|*
name|__global_list
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TKP
parameter_list|(
name|sp
parameter_list|)
value|((TK_PRIVATE *)((sp)->gp->tk_private))
end_define

begin_define
define|#
directive|define
name|GTKP
parameter_list|(
name|gp
parameter_list|)
value|((TK_PRIVATE *)gp->tk_private)
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
comment|/* Some functions can be safely ignored until the screen is running. */
end_comment

begin_define
define|#
directive|define
name|VI_INIT_IGNORE
parameter_list|(
name|sp
parameter_list|)
define|\
value|if (F_ISSET(sp, SC_VI)&& !F_ISSET(TKP(sp), TK_SCR_VI_INIT))	\ 		return (0);
end_define

begin_include
include|#
directive|include
file|"tk_extern.h"
end_include

end_unit

