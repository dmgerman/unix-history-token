begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tty.h	7.6 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"termios.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A clist structure is the head of a linked list queue  * of characters.  The characters are stored in blocks  * containing a link and CBSIZE (param.h) characters.   * The routines in tty_subr.c manipulate these structures.  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
comment|/* character count */
name|char
modifier|*
name|c_cf
decl_stmt|;
comment|/* pointer to first char */
name|char
modifier|*
name|c_cl
decl_stmt|;
comment|/* pointer to last char */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-tty structure.  *  * Should be split in two, into device and tty drivers.  * Glue could be masks of what to echo and circular buffer  * (low, high, timeout).  */
end_comment

begin_struct
struct|struct
name|tty
block|{
name|struct
name|clist
name|t_rawq
decl_stmt|;
name|struct
name|clist
name|t_canq
decl_stmt|;
name|struct
name|clist
name|t_outq
decl_stmt|;
comment|/* device */
name|int
function_decl|(
modifier|*
name|t_oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* device */
name|int
function_decl|(
modifier|*
name|t_param
function_decl|)
parameter_list|()
function_decl|;
comment|/* device */
name|struct
name|proc
modifier|*
name|t_rsel
decl_stmt|;
comment|/* tty */
name|struct
name|proc
modifier|*
name|t_wsel
decl_stmt|;
name|caddr_t
name|T_LINEP
decl_stmt|;
comment|/* XXX */
name|caddr_t
name|t_addr
decl_stmt|;
comment|/* ??? */
name|dev_t
name|t_dev
decl_stmt|;
comment|/* device */
name|int
name|t_flags
decl_stmt|;
comment|/* (compat) some of both */
name|int
name|t_state
decl_stmt|;
comment|/* some of both */
name|struct
name|session
modifier|*
name|t_session
decl_stmt|;
comment|/* tty */
name|struct
name|pgrp
modifier|*
name|t_pgrp
decl_stmt|;
comment|/* foreground process group */
name|char
name|t_line
decl_stmt|;
comment|/* glue */
name|char
name|t_col
decl_stmt|;
comment|/* tty */
name|char
name|t_rocount
decl_stmt|,
name|t_rocol
decl_stmt|;
comment|/* tty */
name|short
name|t_hiwat
decl_stmt|;
comment|/* hi water mark */
name|short
name|t_lowat
decl_stmt|;
comment|/* low water mark */
name|struct
name|winsize
name|t_winsize
decl_stmt|;
comment|/* window size */
name|struct
name|termios
name|t_termios
decl_stmt|;
comment|/* termios state */
define|#
directive|define
name|t_iflag
value|t_termios.c_iflag
define|#
directive|define
name|t_oflag
value|t_termios.c_oflag
define|#
directive|define
name|t_cflag
value|t_termios.c_cflag
define|#
directive|define
name|t_lflag
value|t_termios.c_lflag
define|#
directive|define
name|t_min
value|t_termios.c_min
define|#
directive|define
name|t_time
value|t_termios.c_time
define|#
directive|define
name|t_cc
value|t_termios.c_cc
define|#
directive|define
name|t_ispeed
value|t_termios.c_ispeed
define|#
directive|define
name|t_ospeed
value|t_termios.c_ospeed
name|long
name|t_cancc
decl_stmt|;
comment|/* stats */
name|long
name|t_rawcc
decl_stmt|;
name|long
name|t_outcc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TTIPRI
value|28
end_define

begin_define
define|#
directive|define
name|TTOPRI
value|29
end_define

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|TTMASK
value|15
end_define

begin_define
define|#
directive|define
name|OBUFSIZ
value|100
end_define

begin_define
define|#
directive|define
name|TTYHOG
value|1024
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|TTMAXHIWAT
value|roundup(2048, CBSIZE)
end_define

begin_define
define|#
directive|define
name|TTMINHIWAT
value|roundup(100, CBSIZE)
end_define

begin_define
define|#
directive|define
name|TTMAXLOWAT
value|256
end_define

begin_define
define|#
directive|define
name|TTMINLOWAT
value|32
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ttychars
name|ttydefaults
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*KERNEL*/
end_comment

begin_comment
comment|/* internal state bits */
end_comment

begin_define
define|#
directive|define
name|TS_TIMEOUT
value|0x000001
end_define

begin_comment
comment|/* delay timeout in progress */
end_comment

begin_define
define|#
directive|define
name|TS_WOPEN
value|0x000002
end_define

begin_comment
comment|/* waiting for open to complete */
end_comment

begin_define
define|#
directive|define
name|TS_ISOPEN
value|0x000004
end_define

begin_comment
comment|/* device is open */
end_comment

begin_define
define|#
directive|define
name|TS_FLUSH
value|0x000008
end_define

begin_comment
comment|/* outq has been flushed during DMA */
end_comment

begin_define
define|#
directive|define
name|TS_CARR_ON
value|0x000010
end_define

begin_comment
comment|/* software copy of carrier-present */
end_comment

begin_define
define|#
directive|define
name|TS_BUSY
value|0x000020
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|TS_ASLEEP
value|0x000040
end_define

begin_comment
comment|/* wakeup when output done */
end_comment

begin_define
define|#
directive|define
name|TS_XCLUDE
value|0x000080
end_define

begin_comment
comment|/* exclusive-use flag against open */
end_comment

begin_define
define|#
directive|define
name|TS_TTSTOP
value|0x000100
end_define

begin_comment
comment|/* output stopped by ctl-s */
end_comment

begin_define
define|#
directive|define
name|TS_HUPCLS
value|0x000200
end_define

begin_comment
comment|/* hang up upon last close */
end_comment

begin_define
define|#
directive|define
name|TS_TBLOCK
value|0x000400
end_define

begin_comment
comment|/* tandem queue blocked */
end_comment

begin_define
define|#
directive|define
name|TS_RCOLL
value|0x000800
end_define

begin_comment
comment|/* collision in read select */
end_comment

begin_define
define|#
directive|define
name|TS_WCOLL
value|0x001000
end_define

begin_comment
comment|/* collision in write select */
end_comment

begin_define
define|#
directive|define
name|TS_ASYNC
value|0x004000
end_define

begin_comment
comment|/* tty in async i/o mode */
end_comment

begin_comment
comment|/* state for intra-line fancy editing work */
end_comment

begin_define
define|#
directive|define
name|TS_BKSL
value|0x010000
end_define

begin_comment
comment|/* state for lowercase \ work */
end_comment

begin_define
define|#
directive|define
name|TS_ERASE
value|0x040000
end_define

begin_comment
comment|/* within a \.../ for PRTRUB */
end_comment

begin_define
define|#
directive|define
name|TS_LNCH
value|0x080000
end_define

begin_comment
comment|/* next character is literal */
end_comment

begin_define
define|#
directive|define
name|TS_TYPEN
value|0x100000
end_define

begin_comment
comment|/* retyping suspended input (PENDIN) */
end_comment

begin_define
define|#
directive|define
name|TS_CNTTB
value|0x200000
end_define

begin_comment
comment|/* counting tab width, leave FLUSHO alone */
end_comment

begin_define
define|#
directive|define
name|TS_LOCAL
value|(TS_BKSL|TS_ERASE|TS_LNCH|TS_TYPEN|TS_CNTTB)
end_define

begin_comment
comment|/* define partab character types */
end_comment

begin_define
define|#
directive|define
name|ORDINARY
value|0
end_define

begin_define
define|#
directive|define
name|CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|BACKSPACE
value|2
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|3
end_define

begin_define
define|#
directive|define
name|TAB
value|4
end_define

begin_define
define|#
directive|define
name|VTAB
value|5
end_define

begin_define
define|#
directive|define
name|RETURN
value|6
end_define

begin_struct
struct|struct
name|speedtab
block|{
name|int
name|sp_speed
decl_stmt|;
name|int
name|sp_code
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags on character passed to ttyinput  */
end_comment

begin_define
define|#
directive|define
name|TTY_CHARMASK
value|0x000000ff
end_define

begin_comment
comment|/* Character mask */
end_comment

begin_define
define|#
directive|define
name|TTY_QUOTE
value|0x00000100
end_define

begin_comment
comment|/* Character quoted */
end_comment

begin_define
define|#
directive|define
name|TTY_ERRORMASK
value|0xff000000
end_define

begin_comment
comment|/* Error mask */
end_comment

begin_define
define|#
directive|define
name|TTY_FE
value|0x01000000
end_define

begin_comment
comment|/* Framing error or BREAK condition */
end_comment

begin_define
define|#
directive|define
name|TTY_PE
value|0x02000000
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_comment
comment|/*  * Macros  */
end_comment

begin_define
define|#
directive|define
name|isctty
parameter_list|(
name|p
parameter_list|,
name|tp
parameter_list|)
value|((p)->p_session == (tp)->t_session&& \ 			 (p)->p_flag&SCTTY)
end_define

begin_define
define|#
directive|define
name|isbackground
parameter_list|(
name|p
parameter_list|,
name|tp
parameter_list|)
value|(isctty((p), (tp))&& \ 				(p)->p_pgrp != (tp)->t_pgrp)
end_define

begin_comment
comment|/*  * Modem control commands (driver).  */
end_comment

begin_define
define|#
directive|define
name|DMSET
value|0
end_define

begin_define
define|#
directive|define
name|DMBIS
value|1
end_define

begin_define
define|#
directive|define
name|DMBIC
value|2
end_define

begin_define
define|#
directive|define
name|DMGET
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* symbolic sleep message strings */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ttyin
index|[]
decl_stmt|,
name|ttyout
index|[]
decl_stmt|,
name|ttopen
index|[]
decl_stmt|,
name|ttclos
index|[]
decl_stmt|,
name|ttybg
index|[]
decl_stmt|,
name|ttybuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

