begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tty.h	8.2 (Berkeley) %G%  */
end_comment

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
name|struct
name|clist
name|t_canq
decl_stmt|;
comment|/* Device canonical queue. */
name|struct
name|clist
name|t_outq
decl_stmt|;
comment|/* Device output queue. */
name|void
function_decl|(
modifier|*
name|t_oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* Device. */
ifdef|#
directive|ifdef
name|sun4c
name|void
function_decl|(
modifier|*
name|t_stop
function_decl|)
parameter_list|()
function_decl|;
comment|/* Device. */
endif|#
directive|endif
name|int
function_decl|(
modifier|*
name|t_param
function_decl|)
parameter_list|()
function_decl|;
comment|/* Device. */
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
name|caddr_t
name|T_LINEP
decl_stmt|;
comment|/* XXX */
name|caddr_t
name|t_addr
decl_stmt|;
comment|/* XXX */
name|dev_t
name|t_dev
decl_stmt|;
comment|/* Device. */
name|int
name|t_flags
decl_stmt|;
comment|/* (compat) some of both */
name|int
name|t_state
decl_stmt|;
comment|/* Device and driver internal state. */
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
comment|/* Foreground process group. */
name|char
name|t_line
decl_stmt|;
comment|/* Glue. */
name|short
name|t_col
decl_stmt|;
comment|/* Tty. */
name|short
name|t_rocount
decl_stmt|,
name|t_rocol
decl_stmt|;
comment|/* Tty. */
name|short
name|t_hiwat
decl_stmt|;
comment|/* High water mark. */
name|short
name|t_lowat
decl_stmt|;
comment|/* Low water mark. */
name|struct
name|winsize
name|t_winsize
decl_stmt|;
comment|/* Window size. */
name|struct
name|termios
name|t_termios
decl_stmt|;
comment|/* Termios state. */
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
comment|/* Statistics. */
name|long
name|t_rawcc
decl_stmt|;
name|long
name|t_outcc
decl_stmt|;
name|short
name|t_gen
decl_stmt|;
comment|/* Generation number. */
block|}
struct|;
end_struct

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* Internal state bits. */
end_comment

begin_define
define|#
directive|define
name|TS_TIMEOUT
value|0x000001
end_define

begin_comment
comment|/* Delay timeout in progress. */
end_comment

begin_define
define|#
directive|define
name|TS_WOPEN
value|0x000002
end_define

begin_comment
comment|/* Waiting for open to complete. */
end_comment

begin_define
define|#
directive|define
name|TS_ISOPEN
value|0x000004
end_define

begin_comment
comment|/* Indicates the device is open. */
end_comment

begin_define
define|#
directive|define
name|TS_FLUSH
value|0x000008
end_define

begin_comment
comment|/* Outq has been flushed during DMA. */
end_comment

begin_define
define|#
directive|define
name|TS_CARR_ON
value|0x000010
end_define

begin_comment
comment|/* Software image of carrier-present. */
end_comment

begin_define
define|#
directive|define
name|TS_BUSY
value|0x000020
end_define

begin_comment
comment|/* Indicates output is in progress. */
end_comment

begin_define
define|#
directive|define
name|TS_ASLEEP
value|0x000040
end_define

begin_comment
comment|/* Wakeup when output done. */
end_comment

begin_define
define|#
directive|define
name|TS_XCLUDE
value|0x000080
end_define

begin_comment
comment|/* Exclusive-use flag against open. */
end_comment

begin_define
define|#
directive|define
name|TS_TTSTOP
value|0x000100
end_define

begin_comment
comment|/* Output stopped by ctl-s. */
end_comment

begin_comment
comment|/* was	TS_HUPCLS	0x000200 	 * Hang up upon last close. */
end_comment

begin_define
define|#
directive|define
name|TS_TBLOCK
value|0x000400
end_define

begin_comment
comment|/* Tandem queue blocked. */
end_comment

begin_define
define|#
directive|define
name|TS_ASYNC
value|0x004000
end_define

begin_comment
comment|/* Tty in async i/o mode. */
end_comment

begin_comment
comment|/* State for intra-line fancy editing work. */
end_comment

begin_define
define|#
directive|define
name|TS_BKSL
value|0x010000
end_define

begin_comment
comment|/* State for lowercase \ work. */
end_comment

begin_define
define|#
directive|define
name|TS_ERASE
value|0x040000
end_define

begin_comment
comment|/* Within a \.../ for PRTRUB. */
end_comment

begin_define
define|#
directive|define
name|TS_LNCH
value|0x080000
end_define

begin_comment
comment|/* Next character is literal. */
end_comment

begin_define
define|#
directive|define
name|TS_TYPEN
value|0x100000
end_define

begin_comment
comment|/* Retyping suspended input (PENDIN). */
end_comment

begin_define
define|#
directive|define
name|TS_CNTTB
value|0x200000
end_define

begin_comment
comment|/* Counting tab width, ignore FLUSHO. */
end_comment

begin_define
define|#
directive|define
name|TS_LOCAL
value|(TS_BKSL|TS_ERASE|TS_LNCH|TS_TYPEN|TS_CNTTB)
end_define

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
value|((p)->p_session == (tp)->t_session&& (p)->p_flag&SCTTY)
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ttychars
name|ttydefaults
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symbolic sleep message strings. */
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
name|clist_init
name|__P
argument_list|(
operator|(
name|void
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
name|int
name|ndqb
name|__P
argument_list|(
operator|(
expr|struct
name|clist
operator|*
name|q
operator|,
name|int
name|flag
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

begin_decl_stmt
name|int
name|nullmodem
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
name|ttioctl
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
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
name|ttselect
name|__P
argument_list|(
operator|(
name|dev_t
name|device
operator|,
name|int
name|rw
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
name|ttyoutput
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
name|void
name|ttypend
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
name|ttyretype
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
name|ttyrub
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
name|ttywflush
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

