begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tty.h	4.9	82/01/30	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../h/ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/*  * A clist structure is the head of a linked list queue of characters.  * The characters are stored in blocks containing a link and CBSIZE (param.h)  * characters.  The routines in prim.c manipulate these structures.  */
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
comment|/*  * Per-tty structre.  *  * Should be split in two, into device and tty drivers.  * Glue could be masks of what to echo and circular buffer  * (low, high, timeout).  */
end_comment

begin_struct
struct|struct
name|tty
block|{
union|union
block|{
struct|struct
block|{
name|struct
name|clist
name|T_rawq
decl_stmt|;
name|struct
name|clist
name|T_canq
decl_stmt|;
block|}
name|t_t
struct|;
define|#
directive|define
name|t_rawq
value|t_nu.t_t.T_rawq
comment|/* raw characters or partial line */
define|#
directive|define
name|t_canq
value|t_nu.t_t.T_canq
comment|/* raw characters or partial line */
struct|struct
block|{
name|struct
name|buf
modifier|*
name|T_bufp
decl_stmt|;
name|char
modifier|*
name|T_cp
decl_stmt|;
name|int
name|T_inbuf
decl_stmt|;
name|int
name|T_rec
decl_stmt|;
block|}
name|t_n
struct|;
define|#
directive|define
name|t_bufp
value|t_nu.t_n.T_bufp
comment|/* buffer allocated to protocol */
define|#
directive|define
name|t_cp
value|t_nu.t_n.T_cp
comment|/* pointer into the ripped off buffer */
define|#
directive|define
name|t_inbuf
value|t_nu.t_n.T_inbuf
comment|/* number chars in the buffer */
define|#
directive|define
name|t_rec
value|t_nu.t_n.T_rec
comment|/* have a complete record */
block|}
name|t_nu
union|;
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
comment|/* ### */
name|caddr_t
name|t_addr
decl_stmt|;
comment|/* ??? */
name|dev_t
name|t_dev
decl_stmt|;
comment|/* device */
name|short
name|t_flags
decl_stmt|;
comment|/* some of both */
name|short
name|t_state
decl_stmt|;
comment|/* some of both */
name|short
name|t_pgrp
decl_stmt|;
comment|/* tty */
name|char
name|t_delct
decl_stmt|;
comment|/* tty */
name|char
name|t_line
decl_stmt|;
comment|/* glue */
name|char
name|t_col
decl_stmt|;
comment|/* tty */
name|char
name|t_erase
decl_stmt|,
name|t_kill
decl_stmt|;
comment|/* tty */
name|char
name|t_char
decl_stmt|;
comment|/* tty */
name|char
name|t_ispeed
decl_stmt|,
name|t_ospeed
decl_stmt|;
comment|/* device */
comment|/* begin local */
name|char
name|t_rocount
decl_stmt|,
name|t_rocol
decl_stmt|;
comment|/* tty */
name|struct
name|ltchars
name|t_lchr
decl_stmt|;
comment|/* tty */
name|short
name|t_local
decl_stmt|;
comment|/* tty */
name|short
name|t_lstate
decl_stmt|;
comment|/* tty */
comment|/* end local */
union|union
block|{
name|struct
name|tchars
name|t_chr
decl_stmt|;
comment|/* tty */
name|struct
name|clist
name|T_CTLQ
decl_stmt|;
block|}
name|t_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tun
value|tp->t_un.t_chr
end_define

begin_define
define|#
directive|define
name|tlun
value|tp->t_lchr
end_define

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

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'&037)
end_define

begin_comment
comment|/* default special characters */
end_comment

begin_define
define|#
directive|define
name|CERASE
value|'#'
end_define

begin_define
define|#
directive|define
name|CEOT
value|CTRL(d)
end_define

begin_define
define|#
directive|define
name|CKILL
value|'@'
end_define

begin_define
define|#
directive|define
name|CQUIT
value|034
end_define

begin_comment
comment|/* FS, cntl shift L */
end_comment

begin_define
define|#
directive|define
name|CINTR
value|0177
end_define

begin_comment
comment|/* DEL */
end_comment

begin_define
define|#
directive|define
name|CSTOP
value|CTRL(s)
end_define

begin_define
define|#
directive|define
name|CSTART
value|CTRL(q)
end_define

begin_define
define|#
directive|define
name|CBRK
value|0377
end_define

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|NSPEEDS
value|16
end_define

begin_define
define|#
directive|define
name|TTMASK
value|15
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|short
name|tthiwat
index|[
name|NSPEEDS
index|]
decl_stmt|,
name|ttlowat
index|[
name|NSPEEDS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TTHIWAT
parameter_list|(
name|tp
parameter_list|)
value|tthiwat[(tp)->t_ospeed&TTMASK]
end_define

begin_define
define|#
directive|define
name|TTLOWAT
parameter_list|(
name|tp
parameter_list|)
value|ttlowat[(tp)->t_ospeed&TTMASK]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TTYHOG
value|255
end_define

begin_comment
comment|/* hardware bits */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0200
end_define

begin_define
define|#
directive|define
name|IENABLE
value|0100
end_define

begin_comment
comment|/* internal state bits */
end_comment

begin_define
define|#
directive|define
name|TS_TIMEOUT
value|000001
end_define

begin_comment
comment|/* delay timeout in progress */
end_comment

begin_define
define|#
directive|define
name|TS_WOPEN
value|000002
end_define

begin_comment
comment|/* waiting for open to complete */
end_comment

begin_define
define|#
directive|define
name|TS_ISOPEN
value|000004
end_define

begin_comment
comment|/* device is open */
end_comment

begin_define
define|#
directive|define
name|TS_FLUSH
value|000010
end_define

begin_comment
comment|/* outq has been flushed during DMA */
end_comment

begin_define
define|#
directive|define
name|TS_CARR_ON
value|000020
end_define

begin_comment
comment|/* software copy of carrier-present */
end_comment

begin_define
define|#
directive|define
name|TS_BUSY
value|000040
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|TS_ASLEEP
value|000100
end_define

begin_comment
comment|/* wakeup when output done */
end_comment

begin_define
define|#
directive|define
name|TS_XCLUDE
value|000200
end_define

begin_comment
comment|/* exclusive-use flag against open */
end_comment

begin_define
define|#
directive|define
name|TS_TTSTOP
value|000400
end_define

begin_comment
comment|/* output stopped by ctl-s */
end_comment

begin_define
define|#
directive|define
name|TS_HUPCLS
value|001000
end_define

begin_comment
comment|/* hang up upon last close */
end_comment

begin_define
define|#
directive|define
name|TS_TBLOCK
value|002000
end_define

begin_comment
comment|/* tandem queue blocked */
end_comment

begin_define
define|#
directive|define
name|TS_RCOLL
value|004000
end_define

begin_comment
comment|/* collision in read select */
end_comment

begin_define
define|#
directive|define
name|TS_WCOLL
value|010000
end_define

begin_comment
comment|/* collision in write select */
end_comment

begin_define
define|#
directive|define
name|TS_NBIO
value|020000
end_define

begin_comment
comment|/* tty in non-blocking mode */
end_comment

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

begin_comment
comment|/* define dmctl actions */
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

end_unit

