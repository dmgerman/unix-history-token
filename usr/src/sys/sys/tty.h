begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tty.h	4.5	81/06/11	*/
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
comment|/*  * A clist structure is the head  * of a linked list queue of characters.  * The characters are stored in  * blocks containing a link and CBSIZE (param.h)  * characters.  The routines getc, putc, ... in prim.c  * manipulate these structures.  */
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
comment|/*  * A tty structure is needed for  * each UNIX character device that  * is used for normal terminal IO.  * The routines in tty.c handle the  * common code associated with  * these structures.  The definition  * and device dependent code is in  * each driver. (cons.c, dh.c, dz.c, kl.c)  */
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
comment|/* complete input lines */
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
comment|/* output list to device */
name|int
function_decl|(
modifier|*
name|t_oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to start output */
name|int
function_decl|(
modifier|*
name|t_iproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to start input */
name|struct
name|chan
modifier|*
name|t_chan
decl_stmt|;
comment|/* destination channel */
name|caddr_t
name|t_linep
decl_stmt|;
comment|/* aux line discipline pointer */
name|caddr_t
name|t_addr
decl_stmt|;
comment|/* device address */
name|dev_t
name|t_dev
decl_stmt|;
comment|/* device number */
name|short
name|t_flags
decl_stmt|;
comment|/* mode, settable by ioctl call */
name|short
name|t_state
decl_stmt|;
comment|/* internal state, not visible externally */
name|short
name|t_pgrp
decl_stmt|;
comment|/* process group name */
name|char
name|t_delct
decl_stmt|;
comment|/* number of delimiters in raw q */
name|char
name|t_line
decl_stmt|;
comment|/* line discipline */
name|char
name|t_col
decl_stmt|;
comment|/* printing column of device */
name|char
name|t_erase
decl_stmt|;
comment|/* erase character */
name|char
name|t_kill
decl_stmt|;
comment|/* kill character */
name|char
name|t_char
decl_stmt|;
comment|/* character temporary */
name|char
name|t_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|t_ospeed
decl_stmt|;
comment|/* output speed */
comment|/* begin local */
name|char
name|t_rocount
decl_stmt|;
comment|/* chars input since a ttwrite() */
name|char
name|t_rocol
decl_stmt|;
comment|/* t_col when first input this line */
name|struct
name|ltchars
name|t_lchr
decl_stmt|;
comment|/* local special characters */
name|short
name|t_local
decl_stmt|;
comment|/* local mode word */
name|short
name|t_lstate
decl_stmt|;
comment|/* local state bits */
comment|/* end local */
union|union
block|{
name|struct
name|tchars
name|t_chr
decl_stmt|;
name|struct
name|clist
name|t_ctlq
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
name|TIMEOUT
value|01
end_define

begin_comment
comment|/* delay timeout in progress */
end_comment

begin_define
define|#
directive|define
name|WOPEN
value|02
end_define

begin_comment
comment|/* waiting for open to complete */
end_comment

begin_define
define|#
directive|define
name|ISOPEN
value|04
end_define

begin_comment
comment|/* device is open */
end_comment

begin_define
define|#
directive|define
name|FLUSH
value|010
end_define

begin_comment
comment|/* outq has been flushed during DMA */
end_comment

begin_define
define|#
directive|define
name|CARR_ON
value|020
end_define

begin_comment
comment|/* software copy of carrier-present */
end_comment

begin_define
define|#
directive|define
name|BUSY
value|040
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|ASLEEP
value|0100
end_define

begin_comment
comment|/* wakeup when output done */
end_comment

begin_define
define|#
directive|define
name|XCLUDE
value|0200
end_define

begin_comment
comment|/* exclusive-use flag against open */
end_comment

begin_define
define|#
directive|define
name|TTSTOP
value|0400
end_define

begin_comment
comment|/* output stopped by ctl-s */
end_comment

begin_define
define|#
directive|define
name|HUPCLS
value|01000
end_define

begin_comment
comment|/* hang up upon last close */
end_comment

begin_define
define|#
directive|define
name|TBLOCK
value|02000
end_define

begin_comment
comment|/* tandem queue blocked */
end_comment

begin_define
define|#
directive|define
name|SPEEDS
value|04000
end_define

begin_comment
comment|/* t_ispeed and t_ospeed used by driver */
end_comment

begin_define
define|#
directive|define
name|NDQB
value|010000
end_define

begin_define
define|#
directive|define
name|EXTPROC
value|020000
end_define

begin_comment
comment|/* external processor (kmc) */
end_comment

begin_define
define|#
directive|define
name|FSLEEP
value|040000
end_define

begin_comment
comment|/* Wakeup on input framing */
end_comment

begin_define
define|#
directive|define
name|BEXT
value|0100000
end_define

begin_comment
comment|/* use (external) system buffers */
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

