begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tty.h	8.6 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTY_H_
end_define

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* For struct selinfo. */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Clists are character lists, which is a variable length linked list  * of cblocks, with a count of the number of characters in the list.  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
comment|/* Number of characters in the clist. */
name|int
name|c_cbcount
decl_stmt|;
comment|/* Number of cblocks. */
name|int
name|c_cbmax
decl_stmt|;
comment|/* Max # cblocks allowed for this clist. */
name|int
name|c_cbreserved
decl_stmt|;
comment|/* # cblocks reserved for this clist. */
name|char
modifier|*
name|c_cf
decl_stmt|;
comment|/* Pointer to the first cblock. */
name|char
modifier|*
name|c_cl
decl_stmt|;
comment|/* Pointer to the last cblock. */
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
comment|/* Device raw input queue. */
name|long
name|t_rawcc
decl_stmt|;
comment|/* Raw input queue statistics. */
name|struct
name|clist
name|t_canq
decl_stmt|;
comment|/* Device canonical queue. */
name|long
name|t_cancc
decl_stmt|;
comment|/* Canonical queue statistics. */
name|struct
name|clist
name|t_outq
decl_stmt|;
comment|/* Device output queue. */
name|long
name|t_outcc
decl_stmt|;
comment|/* Output queue statistics. */
name|int
name|t_line
decl_stmt|;
comment|/* Interface to device drivers. */
name|dev_t
name|t_dev
decl_stmt|;
comment|/* Device. */
name|int
name|t_state
decl_stmt|;
comment|/* Device and driver (TS*) state. */
name|int
name|t_flags
decl_stmt|;
comment|/* Tty flags. */
name|int
name|t_timeout
decl_stmt|;
comment|/* Timeout for ttywait() */
name|struct
name|pgrp
modifier|*
name|t_pgrp
decl_stmt|;
comment|/* Foreground process group. */
name|struct
name|session
modifier|*
name|t_session
decl_stmt|;
comment|/* Enclosing session. */
name|struct
name|sigio
modifier|*
name|t_sigio
decl_stmt|;
comment|/* Information for async I/O. */
name|struct
name|selinfo
name|t_rsel
decl_stmt|;
comment|/* Tty read/oob select. */
name|struct
name|selinfo
name|t_wsel
decl_stmt|;
comment|/* Tty write select. */
name|struct
name|termios
name|t_termios
decl_stmt|;
comment|/* Termios state. */
name|struct
name|winsize
name|t_winsize
decl_stmt|;
comment|/* Window size. */
comment|/* Start output. */
name|void
argument_list|(
argument|*t_oproc
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Stop output. */
name|void
argument_list|(
argument|*t_stop
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Set hardware state. */
name|int
argument_list|(
argument|*t_param
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|,
expr|struct
name|termios
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|t_sc
decl_stmt|;
comment|/* XXX: net/if_sl.c:sl_softc. */
name|int
name|t_column
decl_stmt|;
comment|/* Tty output column. */
name|int
name|t_rocount
decl_stmt|,
name|t_rocol
decl_stmt|;
comment|/* Tty. */
name|int
name|t_ififosize
decl_stmt|;
comment|/* Total size of upstream fifos. */
name|int
name|t_ihiwat
decl_stmt|;
comment|/* High water mark for input. */
name|int
name|t_ilowat
decl_stmt|;
comment|/* Low water mark for input. */
name|speed_t
name|t_ispeedwat
decl_stmt|;
comment|/* t_ispeed override for watermarks. */
name|int
name|t_ohiwat
decl_stmt|;
comment|/* High water mark for output. */
name|int
name|t_olowat
decl_stmt|;
comment|/* Low water mark for output. */
name|speed_t
name|t_ospeedwat
decl_stmt|;
comment|/* t_ospeed override for watermarks. */
name|int
name|t_gen
decl_stmt|;
comment|/* Generation number. */
name|SLIST_ENTRY
argument_list|(
argument|tty
argument_list|)
name|t_list
expr_stmt|;
comment|/* Global chain of ttys for pstat(8) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|t_cc
value|t_termios.c_cc
end_define

begin_define
define|#
directive|define
name|t_cflag
value|t_termios.c_cflag
end_define

begin_define
define|#
directive|define
name|t_iflag
value|t_termios.c_iflag
end_define

begin_define
define|#
directive|define
name|t_ispeed
value|t_termios.c_ispeed
end_define

begin_define
define|#
directive|define
name|t_lflag
value|t_termios.c_lflag
end_define

begin_define
define|#
directive|define
name|t_min
value|t_termios.c_min
end_define

begin_define
define|#
directive|define
name|t_oflag
value|t_termios.c_oflag
end_define

begin_define
define|#
directive|define
name|t_ospeed
value|t_termios.c_ospeed
end_define

begin_define
define|#
directive|define
name|t_time
value|t_termios.c_time
end_define

begin_define
define|#
directive|define
name|TTIPRI
value|25
end_define

begin_comment
comment|/* Sleep priority for tty reads. */
end_comment

begin_define
define|#
directive|define
name|TTOPRI
value|26
end_define

begin_comment
comment|/* Sleep priority for tty writes. */
end_comment

begin_comment
comment|/*  * User data unfortunately has to be copied through buffers on the way to  * and from clists.  The buffers are on the stack so their sizes must be  * fairly small.  */
end_comment

begin_define
define|#
directive|define
name|IBUFSIZ
value|384
end_define

begin_comment
comment|/* Should be>= max value of MIN. */
end_comment

begin_define
define|#
directive|define
name|OBUFSIZ
value|100
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TTYHOG
end_ifndef

begin_define
define|#
directive|define
name|TTYHOG
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These flags are kept in t_state. */
end_comment

begin_define
define|#
directive|define
name|TS_SO_OLOWAT
value|0x00001
end_define

begin_comment
comment|/* Wake up when output<= low water. */
end_comment

begin_define
define|#
directive|define
name|TS_ASYNC
value|0x00002
end_define

begin_comment
comment|/* Tty in async I/O mode. */
end_comment

begin_define
define|#
directive|define
name|TS_BUSY
value|0x00004
end_define

begin_comment
comment|/* Draining output. */
end_comment

begin_define
define|#
directive|define
name|TS_CARR_ON
value|0x00008
end_define

begin_comment
comment|/* Carrier is present. */
end_comment

begin_define
define|#
directive|define
name|TS_FLUSH
value|0x00010
end_define

begin_comment
comment|/* Outq has been flushed during DMA. */
end_comment

begin_define
define|#
directive|define
name|TS_ISOPEN
value|0x00020
end_define

begin_comment
comment|/* Open has completed. */
end_comment

begin_define
define|#
directive|define
name|TS_TBLOCK
value|0x00040
end_define

begin_comment
comment|/* Further input blocked. */
end_comment

begin_define
define|#
directive|define
name|TS_TIMEOUT
value|0x00080
end_define

begin_comment
comment|/* Wait for output char processing. */
end_comment

begin_define
define|#
directive|define
name|TS_TTSTOP
value|0x00100
end_define

begin_comment
comment|/* Output paused. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|TS_WOPEN
value|0x00200
end_define

begin_comment
comment|/* Open in progress. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TS_XCLUDE
value|0x00400
end_define

begin_comment
comment|/* Tty requires exclusivity. */
end_comment

begin_comment
comment|/* State for intra-line fancy editing work. */
end_comment

begin_define
define|#
directive|define
name|TS_BKSL
value|0x00800
end_define

begin_comment
comment|/* State for lowercase \ work. */
end_comment

begin_define
define|#
directive|define
name|TS_CNTTB
value|0x01000
end_define

begin_comment
comment|/* Counting tab width, ignore FLUSHO. */
end_comment

begin_define
define|#
directive|define
name|TS_ERASE
value|0x02000
end_define

begin_comment
comment|/* Within a \.../ for PRTRUB. */
end_comment

begin_define
define|#
directive|define
name|TS_LNCH
value|0x04000
end_define

begin_comment
comment|/* Next character is literal. */
end_comment

begin_define
define|#
directive|define
name|TS_TYPEN
value|0x08000
end_define

begin_comment
comment|/* Retyping suspended input (PENDIN). */
end_comment

begin_define
define|#
directive|define
name|TS_LOCAL
value|(TS_BKSL | TS_CNTTB | TS_ERASE | TS_LNCH | TS_TYPEN)
end_define

begin_comment
comment|/* Extras. */
end_comment

begin_define
define|#
directive|define
name|TS_CAN_BYPASS_L_RINT
value|0x010000
end_define

begin_comment
comment|/* Device in "raw" mode. */
end_comment

begin_define
define|#
directive|define
name|TS_CONNECTED
value|0x020000
end_define

begin_comment
comment|/* Connection open. */
end_comment

begin_define
define|#
directive|define
name|TS_SNOOP
value|0x040000
end_define

begin_comment
comment|/* Device is being snooped on. */
end_comment

begin_define
define|#
directive|define
name|TS_SO_OCOMPLETE
value|0x080000
end_define

begin_comment
comment|/* Wake up when output completes. */
end_comment

begin_define
define|#
directive|define
name|TS_ZOMBIE
value|0x100000
end_define

begin_comment
comment|/* Connection lost. */
end_comment

begin_comment
comment|/* Hardware flow-control-invoked bits. */
end_comment

begin_define
define|#
directive|define
name|TS_CAR_OFLOW
value|0x200000
end_define

begin_comment
comment|/* For MDMBUF (XXX handle in driver). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|TS_CTS_OFLOW
value|0x400000
end_define

begin_comment
comment|/* For CCTS_OFLOW. */
end_comment

begin_define
define|#
directive|define
name|TS_DSR_OFLOW
value|0x800000
end_define

begin_comment
comment|/* For CDSR_OFLOW. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Character type information. */
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
comment|/* Speed. */
name|int
name|sp_code
decl_stmt|;
comment|/* Code. */
block|}
struct|;
end_struct

begin_comment
comment|/* Modem control commands (driver). */
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

begin_comment
comment|/* Flags on a character passed to ttyinput. */
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
comment|/* Framing error */
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

begin_define
define|#
directive|define
name|TTY_OE
value|0x04000000
end_define

begin_comment
comment|/* Overrun error */
end_comment

begin_define
define|#
directive|define
name|TTY_BI
value|0x08000000
end_define

begin_comment
comment|/* Break condition */
end_comment

begin_comment
comment|/* Is tp controlling terminal for p? */
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
define|\
value|((p)->p_session == (tp)->t_session&& (p)->p_flag& P_CONTROLT)
end_define

begin_comment
comment|/* Is p in background of tp? */
end_comment

begin_define
define|#
directive|define
name|isbackground
parameter_list|(
name|p
parameter_list|,
name|tp
parameter_list|)
define|\
value|(isctty((p), (tp))&& (p)->p_pgrp != (tp)->t_pgrp)
end_define

begin_comment
comment|/* Unique sleep addresses. */
end_comment

begin_define
define|#
directive|define
name|TSA_CARR_ON
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_rawq)
end_define

begin_define
define|#
directive|define
name|TSA_HUP_OR_INPUT
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_rawq.c_cf)
end_define

begin_define
define|#
directive|define
name|TSA_OCOMPLETE
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_outq.c_cl)
end_define

begin_define
define|#
directive|define
name|TSA_OLOWAT
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_outq)
end_define

begin_define
define|#
directive|define
name|TSA_PTC_READ
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_outq.c_cf)
end_define

begin_define
define|#
directive|define
name|TSA_PTC_WRITE
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_rawq.c_cl)
end_define

begin_define
define|#
directive|define
name|TSA_PTS_READ
parameter_list|(
name|tp
parameter_list|)
value|((void *)&(tp)->t_canq)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TTYS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|constty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary virtual console. */
end_comment

begin_decl_stmt
name|int
name|b_to_q
name|__P
argument_list|(
operator|(
name|char
operator|*
name|cp
operator|,
name|int
name|cc
operator|,
expr|struct
name|clist
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|catq
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|from
operator|,
expr|struct
name|clist
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clist_alloc_cblocks
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|,
name|int
name|ccmax
operator|,
name|int
name|ccres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clist_free_cblocks
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getc
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ndflush
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|,
name|int
name|cc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nextc
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|,
name|char
operator|*
name|cp
operator|,
name|int
operator|*
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nottystop
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|rw
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|putc
name|__P
argument_list|(
operator|(
name|int
name|c
operator|,
expr|struct
name|clist
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|q_to_b
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|,
name|char
operator|*
name|cp
operator|,
name|int
name|cc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|termioschars
name|__P
argument_list|(
operator|(
expr|struct
name|termios
operator|*
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tputchar
name|__P
argument_list|(
operator|(
name|int
name|c
operator|,
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttcompat
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|u_long
name|com
operator|,
name|caddr_t
name|data
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttioctl
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|u_long
name|com
operator|,
name|void
operator|*
name|data
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttread
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttrstrt
name|__P
argument_list|(
operator|(
name|void
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttsetcompat
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|u_long
operator|*
name|com
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|termios
operator|*
name|term
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttsetwater
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttspeedtab
name|__P
argument_list|(
operator|(
name|int
name|speed
operator|,
expr|struct
name|speedtab
operator|*
name|table
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttstart
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttwakeup
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttwrite
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttwwakeup
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyblock
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttychars
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttycheckoutq
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|wait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyclose
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyflush
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|rw
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyfree
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyinfo
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyinput
name|__P
argument_list|(
operator|(
name|int
name|c
operator|,
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttylclose
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tty
modifier|*
name|ttymalloc
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttymodem
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyopen
name|__P
argument_list|(
operator|(
name|dev_t
name|device
operator|,
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttypoll
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|events
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttykqfilter
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|knote
operator|*
name|kn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyread
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyregister
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttysleep
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|void
operator|*
name|chan
operator|,
name|int
name|pri
operator|,
name|char
operator|*
name|wmesg
operator|,
name|int
name|timeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttywait
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttywrite
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unputc
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTY_H_ */
end_comment

end_unit

