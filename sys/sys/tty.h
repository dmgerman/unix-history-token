begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)tty.h	7.10 (Berkeley) 6/26/91  *	$Id: tty.h,v 1.8 1994/01/28 23:15:17 ache Exp $  */
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

begin_comment
comment|/*  * Ring buffers provide a contiguous, dense storage for  * character data used by the tty driver.  *  * Make sizeof(struct ringb) be such that it fits exactly in  * a malloc bucket.  */
end_comment

begin_define
define|#
directive|define
name|RBSZ
value|2040
end_define

begin_struct
struct|struct
name|ringb
block|{
name|char
modifier|*
name|rb_hd
decl_stmt|;
comment|/* head of buffer segment to be read */
name|char
modifier|*
name|rb_tl
decl_stmt|;
comment|/* tail of buffer segment to be written */
name|char
name|rb_buf
index|[
name|RBSZ
index|]
decl_stmt|;
comment|/* segment contents */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RB_SUCC
parameter_list|(
name|rbp
parameter_list|,
name|p
parameter_list|)
define|\
value|((p)>= (rbp)->rb_buf + RBSZ - 1 ? (rbp)->rb_buf : (p) + 1)
end_define

begin_define
define|#
directive|define
name|RB_ROLLOVER
parameter_list|(
name|rbp
parameter_list|,
name|p
parameter_list|)
define|\
value|((p)> (rbp)->rb_buf + RBSZ - 1 ? (rbp)->rb_buf : (p))
end_define

begin_define
define|#
directive|define
name|RB_PRED
parameter_list|(
name|rbp
parameter_list|,
name|p
parameter_list|)
define|\
value|((p)<= (rbp)->rb_buf ? (rbp)->rb_buf + RBSZ - 1 : (p) - 1)
end_define

begin_define
define|#
directive|define
name|RB_LEN
parameter_list|(
name|rp
parameter_list|)
define|\
value|((rp)->rb_hd<= (rp)->rb_tl ? (rp)->rb_tl - (rp)->rb_hd : \ 		RBSZ - ((rp)->rb_hd - (rp)->rb_tl))
end_define

begin_define
define|#
directive|define
name|RB_CONTIGPUT
parameter_list|(
name|rp
parameter_list|)
define|\
value|(RB_PRED(rp, (rp)->rb_hd)< (rp)->rb_tl ?  \ 			(rp)->rb_buf + RBSZ - (rp)->rb_tl : \ 			RB_PRED(rp, (rp)->rb_hd) - (rp)->rb_tl)
end_define

begin_define
define|#
directive|define
name|RB_CONTIGGET
parameter_list|(
name|rp
parameter_list|)
define|\
value|((rp)->rb_hd<= (rp)->rb_tl ? (rp)->rb_tl - (rp)->rb_hd : \ 		(rp)->rb_buf + RBSZ - (rp)->rb_hd)
end_define

begin_comment
comment|/*  * Per-tty structure.  *  * Should be split in two, into device and tty drivers.  * Glue could be masks of what to echo and circular buffer  * (low, high, timeout).  */
end_comment

begin_struct
struct|struct
name|tty
block|{
name|void
function_decl|(
modifier|*
name|t_oproc
function_decl|)
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
comment|/* device */
name|int
function_decl|(
modifier|*
name|t_param
function_decl|)
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
comment|/* device */
name|pid_t
name|t_rsel
decl_stmt|;
comment|/* tty */
name|pid_t
name|t_wsel
decl_stmt|;
name|caddr_t
name|T_LINEP
decl_stmt|;
comment|/* XXX */
if|#
directive|if
literal|0
block|caddr_t	t_addr;
comment|/* ??? */
endif|#
directive|endif
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
name|int
name|t_line
decl_stmt|;
comment|/* glue */
name|int
name|t_col
decl_stmt|;
comment|/* tty */
name|int
name|t_rocount
decl_stmt|,
name|t_rocol
decl_stmt|;
comment|/* tty */
name|int
name|t_hiwat
decl_stmt|;
comment|/* hi water mark */
name|int
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
name|int
name|t_gen
decl_stmt|;
comment|/* generation number */
if|#
directive|if
literal|0
block|int     t_mask;
comment|/* interrupt mask */
endif|#
directive|endif
name|struct
name|ringb
modifier|*
name|t_raw
decl_stmt|;
comment|/* ring buffers */
name|struct
name|ringb
modifier|*
name|t_can
decl_stmt|;
name|struct
name|ringb
modifier|*
name|t_out
decl_stmt|;
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
comment|/* sleep priority for tty reads */
end_comment

begin_define
define|#
directive|define
name|TTOPRI
value|26
end_define

begin_comment
comment|/* sleep priority for tty writes */
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
value|RBSZ
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
value|(RBSZ/2)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|TTMINHIWAT
value|128
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
comment|/* KERNEL */
end_comment

begin_comment
comment|/* internal state bits */
end_comment

begin_define
define|#
directive|define
name|TS_TIMEOUT
value|0x000001UL
end_define

begin_comment
comment|/* delay timeout in progress */
end_comment

begin_define
define|#
directive|define
name|TS_WOPEN
value|0x000002UL
end_define

begin_comment
comment|/* waiting for open to complete */
end_comment

begin_define
define|#
directive|define
name|TS_ISOPEN
value|0x000004UL
end_define

begin_comment
comment|/* device is open */
end_comment

begin_define
define|#
directive|define
name|TS_FLUSH
value|0x000008UL
end_define

begin_comment
comment|/* outq has been flushed during DMA */
end_comment

begin_define
define|#
directive|define
name|TS_CARR_ON
value|0x000010UL
end_define

begin_comment
comment|/* software copy of carrier-present */
end_comment

begin_define
define|#
directive|define
name|TS_BUSY
value|0x000020UL
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|TS_ASLEEP
value|0x000040UL
end_define

begin_comment
comment|/* wakeup when output done */
end_comment

begin_define
define|#
directive|define
name|TS_XCLUDE
value|0x000080UL
end_define

begin_comment
comment|/* exclusive-use flag against open */
end_comment

begin_define
define|#
directive|define
name|TS_TTSTOP
value|0x000100UL
end_define

begin_comment
comment|/* output stopped by ctl-s */
end_comment

begin_comment
comment|/* was	TS_HUPCLS	0x000200UL 	 * hang up upon last close */
end_comment

begin_define
define|#
directive|define
name|TS_TBLOCK
value|0x000400UL
end_define

begin_comment
comment|/* tandem queue blocked */
end_comment

begin_define
define|#
directive|define
name|TS_RCOLL
value|0x000800UL
end_define

begin_comment
comment|/* collision in read select */
end_comment

begin_define
define|#
directive|define
name|TS_WCOLL
value|0x001000UL
end_define

begin_comment
comment|/* collision in write select */
end_comment

begin_define
define|#
directive|define
name|TS_ASYNC
value|0x004000UL
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
value|0x010000UL
end_define

begin_comment
comment|/* state for lowercase \ work */
end_comment

begin_define
define|#
directive|define
name|TS_ERASE
value|0x040000UL
end_define

begin_comment
comment|/* within a \.../ for PRTRUB */
end_comment

begin_define
define|#
directive|define
name|TS_LNCH
value|0x080000UL
end_define

begin_comment
comment|/* next character is literal */
end_comment

begin_define
define|#
directive|define
name|TS_TYPEN
value|0x100000UL
end_define

begin_comment
comment|/* retyping suspended input (PENDIN) */
end_comment

begin_define
define|#
directive|define
name|TS_CNTTB
value|0x200000UL
end_define

begin_comment
comment|/* counting tab width, ignore FLUSHO */
end_comment

begin_comment
comment|/* flow-control-invoked bits */
end_comment

begin_define
define|#
directive|define
name|TS_CAR_OFLOW
value|0x0400000UL
end_define

begin_comment
comment|/* for MDMBUF (XXX handle in driver) */
end_comment

begin_define
define|#
directive|define
name|TS_DTR_IFLOW
value|0x2000000UL
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|TS_RTS_IFLOW
value|0x4000000UL
end_define

begin_comment
comment|/* for CRTS_IFLOW */
end_comment

begin_define
define|#
directive|define
name|TS_HW_IFLOW
value|(TS_DTR_IFLOW | TS_RTS_IFLOW)
end_define

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
value|0x000000ffUL
end_define

begin_comment
comment|/* Character mask */
end_comment

begin_define
define|#
directive|define
name|TTY_QUOTE
value|0x00000100UL
end_define

begin_comment
comment|/* Character quoted */
end_comment

begin_define
define|#
directive|define
name|TTY_ERRORMASK
value|0xff000000UL
end_define

begin_comment
comment|/* Error mask */
end_comment

begin_define
define|#
directive|define
name|TTY_FE
value|0x01000000UL
end_define

begin_comment
comment|/* Framing error or BREAK condition */
end_comment

begin_define
define|#
directive|define
name|TTY_PE
value|0x02000000UL
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_comment
comment|/*  * Is tp controlling terminal for p  */
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

begin_comment
comment|/*  * Is p in background of tp  */
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
specifier|const
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

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/* From tty.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttychars
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttwflush
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttywait
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttyflush
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttstart
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttrstrt
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttioctl
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttnread
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttselect
parameter_list|(
name|int
comment|/*dev_t*/
parameter_list|,
name|int
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttyopen
parameter_list|(
name|int
comment|/*dev_t*/
parameter_list|,
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttylclose
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttyclose
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttymodem
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nullmodem
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttyinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttread
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttycheckoutq
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttwrite
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttwakeup
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttspeedtab
parameter_list|(
name|int
parameter_list|,
name|struct
name|speedtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttsetwater
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttyinfo
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tputchar
parameter_list|(
name|int
parameter_list|,
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttysleep
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tty
modifier|*
name|ttymalloc
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttyfree
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tty_ring.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|putc
parameter_list|(
name|int
parameter_list|,
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getc
parameter_list|(
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nextc
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ungetc
parameter_list|(
name|int
parameter_list|,
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unputc
parameter_list|(
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initrb
parameter_list|(
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|catb
parameter_list|(
name|struct
name|ringb
modifier|*
parameter_list|,
name|struct
name|ringb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|rb_write
parameter_list|(
name|struct
name|ringb
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tty_compat.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttcompat
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TTY_H_ */
end_comment

end_unit

