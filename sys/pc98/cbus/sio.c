begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)com.c	7.5 (Berkeley) 5/16/91  *	$Id: sio.c,v 1.1.1.1 1996/06/14 10:04:45 asami Exp $  */
end_comment

begin_include
include|#
directive|include
file|"opt_comconsole.h"
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_sio.h"
end_include

begin_include
include|#
directive|include
file|"sio.h"
end_include

begin_comment
comment|/*  * Serial driver, based on 386BSD-0.1 com driver.  * Mostly rewritten to use pseudo-DMA.  * Works for National Semiconductor NS8250-NS16550AF UARTs.  * COM driver, based on HP dca driver.  *  * Changes for PC-Card integration:  *	- Added PC-Card driver table and handlers  */
end_comment

begin_comment
comment|/*===============================================================  * 386BSD(98),FreeBSD-1.1x(98) com driver.  * -----  * modified for PC9801 by M.Ishii   *			Kyoto University Microcomputer Club (KMC)  * Chou "TEFUTEFU" Hirotomi  *			Kyoto Univ.  the faculty of medicine  *===============================================================  * FreeBSD-2.0.1(98) sio driver.  * -----  * modified for pc98 Internal i8251 and MICRO CORE MC16550II  *			T.Koike(hfc01340@niftyserve.or.jp)  * implement kernel device configuration  *			aizu@orient.center.nitech.ac.jp  *  * Notes.  * -----  *  PC98 localization based on 386BSD(98) com driver. Using its PC98 local  *  functions.  *  This driver is under debugging,has bugs.  *  * 1) config  *  options COM_MULTIPORT  #if using MC16550II  *  device sio0 at nec? port 0x30  tty irq 4 vector siointr #internal  *  device sio1 at nec? port 0xd2  tty irq 5 flags 0x101 vector siointr #mc1  *  device sio2 at nec? port 0x8d2 tty flags 0x101 vector siointr       #mc2  *                         # ~~~~~iobase        ~~multi port flag  *                         #                   ~  master device is sio1  * 2) device  *  cd /dev; MAKEDEV ttyd0 ttyd1 ..  * 3) /etc/rc.serial  *  57600bps is too fast for sio0(internal8251)  *  my ex.  *    #set default speed 9600  *    modem()  *       :  *      stty</dev/ttyid$i crtscts 9600  *       :                 #       ~~~~ default speed(can change after init.)  *    modem 0 1 2  * 4) COMCONSOLE  *  not changed.  * 5) PC9861K,PIO9032B,B98_01  *  not tested.  */
end_comment

begin_comment
comment|/*  * modified for AIWA B98-01  * by T.Hatanou<hatanou@yasuda.comm.waseda.ac.jp>  last update: 15 Sep.1995   *  * How to configure...  *   # options COM_MULTIPORT         # support for MICROCORE MC16550II  *      ... comment-out this line, which will conflict with B98_01.  *   options "B98_01"                # support for AIWA B98-01  *   device  sio1 at nec? port 0x00d1 tty irq ? vector siointr  *   device  sio2 at nec? port 0x00d5 tty irq ? vector siointr  *      ... you can leave these lines `irq ?', irq will be autodetected.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|MC16550
value|0
end_define

begin_define
define|#
directive|define
name|COM_IF_INTERNAL
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|COM_IF_PC9861K
value|2
end_define

begin_define
define|#
directive|define
name|COM_IF_PIO9032B
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|B98_01
end_ifdef

begin_undef
undef|#
directive|undef
name|COM_MULTIPORT
end_undef

begin_comment
comment|/* COM_MULTIPORT will conflict with B98_01 */
end_comment

begin_define
define|#
directive|define
name|COM_IF_B98_01
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* B98_01 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkstat.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/devconf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/devfsext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/icu.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/pc98_device.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/sioreg.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/ic/i8251.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/ic/ns16550.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/sioreg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|COM_ESP
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/ic/esp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i386/isa/ic/ns16550.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"crd.h"
end_include

begin_if
if|#
directive|if
name|NCRD
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<pccard/card.h>
end_include

begin_include
include|#
directive|include
file|<pccard/driver.h>
end_include

begin_include
include|#
directive|include
file|<pccard/slot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOTS_OF_EVENTS
value|64
end_define

begin_comment
comment|/* helps separate urgent events from input */
end_comment

begin_define
define|#
directive|define
name|RB_I_HIGH_WATER
value|(TTYHOG - 2 * RS_IBUFSIZE)
end_define

begin_define
define|#
directive|define
name|RS_IBUFSIZE
value|256
end_define

begin_define
define|#
directive|define
name|CALLOUT_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|CONTROL_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|CONTROL_INIT_STATE
value|0x20
end_define

begin_define
define|#
directive|define
name|CONTROL_LOCK_STATE
value|0x40
end_define

begin_define
define|#
directive|define
name|DEV_TO_UNIT
parameter_list|(
name|dev
parameter_list|)
value|(MINOR_TO_UNIT(minor(dev)))
end_define

begin_define
define|#
directive|define
name|MINOR_MAGIC_MASK
value|(CALLOUT_MASK | CONTROL_MASK)
end_define

begin_define
define|#
directive|define
name|MINOR_TO_UNIT
parameter_list|(
name|mynor
parameter_list|)
value|((mynor)& ~MINOR_MAGIC_MASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COM_MULTIPORT
end_ifdef

begin_comment
comment|/* checks in flags for multiport and which is multiport "master chip"  * for a given card  */
end_comment

begin_define
define|#
directive|define
name|COM_ISMULTIPORT
parameter_list|(
name|dev
parameter_list|)
value|((dev)->id_flags& 0x01)
end_define

begin_define
define|#
directive|define
name|COM_MPMASTER
parameter_list|(
name|dev
parameter_list|)
value|(((dev)->id_flags>> 8)& 0x0ff)
end_define

begin_define
define|#
directive|define
name|COM_NOTAST4
parameter_list|(
name|dev
parameter_list|)
value|((dev)->id_flags& 0x04)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COM_MULTIPORT */
end_comment

begin_define
define|#
directive|define
name|COM_LOSESOUTINTS
parameter_list|(
name|dev
parameter_list|)
value|((dev)->id_flags& 0x08)
end_define

begin_define
define|#
directive|define
name|COM_NOFIFO
parameter_list|(
name|dev
parameter_list|)
value|((dev)->id_flags& 0x02)
end_define

begin_define
define|#
directive|define
name|COM_VERBOSE
parameter_list|(
name|dev
parameter_list|)
value|((dev)->id_flags& 0x80)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_define
define|#
directive|define
name|com_scr
value|7
end_define

begin_comment
comment|/* scratch register for 16450-16550 (R/W) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PC98 */
end_comment

begin_comment
comment|/*  * Input buffer watermarks.  * The external device is asked to stop sending when the buffer exactly reaches  * high water, or when the high level requests it.  * The high level is notified immediately (rather than at a later clock tick)  * when this watermark is reached.  * The buffer size is chosen so the watermark should almost never be reached.  * The low watermark is invisibly 0 since the buffer is always emptied all at  * once.  */
end_comment

begin_define
define|#
directive|define
name|RS_IHIGHWATER
value|(3 * RS_IBUFSIZE / 4)
end_define

begin_comment
comment|/*  * com state bits.  * (CS_BUSY | CS_TTGO) and (CS_BUSY | CS_TTGO | CS_ODEVREADY) must be higher  * than the other bits so that they can be tested as a group without masking  * off the low bits.  *  * The following com and tty flags correspond closely:  *	CS_BUSY		= TS_BUSY (maintained by comstart(), siopoll() and  *				   siostop())  *	CS_TTGO		= ~TS_TTSTOP (maintained by comparam() and comstart())  *	CS_CTS_OFLOW	= CCTS_OFLOW (maintained by comparam())  *	CS_RTS_IFLOW	= CRTS_IFLOW (maintained by comparam())  * TS_FLUSH is not used.  * XXX I think TIOCSETA doesn't clear TS_TTSTOP when it clears IXON.  * XXX CS_*FLOW should be CF_*FLOW in com->flags (control flags not state).  */
end_comment

begin_define
define|#
directive|define
name|CS_BUSY
value|0x80
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|CS_TTGO
value|0x40
end_define

begin_comment
comment|/* output not stopped by XOFF */
end_comment

begin_define
define|#
directive|define
name|CS_ODEVREADY
value|0x20
end_define

begin_comment
comment|/* external device h/w ready (CTS) */
end_comment

begin_define
define|#
directive|define
name|CS_CHECKMSR
value|1
end_define

begin_comment
comment|/* check of MSR scheduled */
end_comment

begin_define
define|#
directive|define
name|CS_CTS_OFLOW
value|2
end_define

begin_comment
comment|/* use CTS output flow control */
end_comment

begin_define
define|#
directive|define
name|CS_DTR_OFF
value|0x10
end_define

begin_comment
comment|/* DTR held off */
end_comment

begin_define
define|#
directive|define
name|CS_ODONE
value|4
end_define

begin_comment
comment|/* output completed */
end_comment

begin_define
define|#
directive|define
name|CS_RTS_IFLOW
value|8
end_define

begin_comment
comment|/* use RTS input flow control */
end_comment

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|error_desc
index|[]
init|=
block|{
define|#
directive|define
name|CE_OVERRUN
value|0
literal|"silo overflow"
block|,
define|#
directive|define
name|CE_INTERRUPT_BUF_OVERFLOW
value|1
literal|"interrupt-level buffer overflow"
block|,
define|#
directive|define
name|CE_TTY_BUF_OVERFLOW
value|2
literal|"tty-level buffer overflow"
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CE_NTYPES
value|3
end_define

begin_define
define|#
directive|define
name|CE_RECORD
parameter_list|(
name|com
parameter_list|,
name|errnum
parameter_list|)
value|(++(com)->delta_error_counts[errnum])
end_define

begin_comment
comment|/* types.  XXX - should be elsewhere */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|Port_t
typedef|;
end_typedef

begin_comment
comment|/* hardware port */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|bool_t
typedef|;
end_typedef

begin_comment
comment|/* boolean */
end_comment

begin_comment
comment|/* queue of linear buffers */
end_comment

begin_struct
struct|struct
name|lbq
block|{
name|u_char
modifier|*
name|l_head
decl_stmt|;
comment|/* next char to process */
name|u_char
modifier|*
name|l_tail
decl_stmt|;
comment|/* one past the last char to process */
name|struct
name|lbq
modifier|*
name|l_next
decl_stmt|;
comment|/* next in queue */
name|bool_t
name|l_queued
decl_stmt|;
comment|/* nonzero if queued */
block|}
struct|;
end_struct

begin_comment
comment|/* com device structure */
end_comment

begin_struct
struct|struct
name|com_s
block|{
name|u_char
name|state
decl_stmt|;
comment|/* miscellaneous flag bits */
name|bool_t
name|active_out
decl_stmt|;
comment|/* nonzero if the callout device is open */
name|u_char
name|cfcr_image
decl_stmt|;
comment|/* copy of value written to CFCR */
ifdef|#
directive|ifdef
name|COM_ESP
name|bool_t
name|esp
decl_stmt|;
comment|/* is this unit a hayes esp board? */
endif|#
directive|endif
name|u_char
name|fifo_image
decl_stmt|;
comment|/* copy of value written to FIFO */
name|bool_t
name|hasfifo
decl_stmt|;
comment|/* nonzero for 16550 UARTs */
name|bool_t
name|loses_outints
decl_stmt|;
comment|/* nonzero if device loses output interrupts */
name|u_char
name|mcr_image
decl_stmt|;
comment|/* copy of value written to MCR */
ifdef|#
directive|ifdef
name|COM_MULTIPORT
name|bool_t
name|multiport
decl_stmt|;
comment|/* is this unit part of a multiport device? */
endif|#
directive|endif
comment|/* COM_MULTIPORT */
name|bool_t
name|no_irq
decl_stmt|;
comment|/* nonzero if irq is not attached */
name|bool_t
name|gone
decl_stmt|;
comment|/* hardware disappeared */
name|bool_t
name|poll
decl_stmt|;
comment|/* nonzero if polling is required */
name|bool_t
name|poll_output
decl_stmt|;
comment|/* nonzero if polling for output is required */
name|int
name|unit
decl_stmt|;
comment|/* unit	number */
name|int
name|dtr_wait
decl_stmt|;
comment|/* time to hold DTR down on close (* 1/hz) */
name|u_int
name|tx_fifo_size
decl_stmt|;
name|u_int
name|wopeners
decl_stmt|;
comment|/* # processes waiting for DCD in open() */
comment|/* 	 * The high level of the driver never reads status registers directly 	 * because there would be too many side effects to handle conveniently. 	 * Instead, it reads copies of the registers stored here by the 	 * interrupt handler. 	 */
name|u_char
name|last_modem_status
decl_stmt|;
comment|/* last MSR read by intr handler */
name|u_char
name|prev_modem_status
decl_stmt|;
comment|/* last MSR handled by high level */
name|u_char
name|hotchar
decl_stmt|;
comment|/* ldisc-specific char to be handled ASAP */
name|u_char
modifier|*
name|ibuf
decl_stmt|;
comment|/* start of input buffer */
name|u_char
modifier|*
name|ibufend
decl_stmt|;
comment|/* end of input buffer */
name|u_char
modifier|*
name|ihighwater
decl_stmt|;
comment|/* threshold in input buffer */
name|u_char
modifier|*
name|iptr
decl_stmt|;
comment|/* next free spot in input buffer */
name|struct
name|lbq
name|obufq
decl_stmt|;
comment|/* head of queue of output buffers */
name|struct
name|lbq
name|obufs
index|[
literal|2
index|]
decl_stmt|;
comment|/* output buffers */
ifdef|#
directive|ifdef
name|PC98
name|Port_t
name|cmd_port
decl_stmt|;
name|Port_t
name|sts_port
decl_stmt|;
name|Port_t
name|in_modem_port
decl_stmt|;
name|Port_t
name|intr_ctrl_port
decl_stmt|;
name|int
name|intr_enable
decl_stmt|;
name|int
name|pc98_prev_modem_status
decl_stmt|;
name|int
name|pc98_modem_delta
decl_stmt|;
name|int
name|modem_car_chg_timer
decl_stmt|;
name|int
name|pc98_prev_siocmd
decl_stmt|;
name|int
name|pc98_prev_siomod
decl_stmt|;
name|int
name|modem_checking
decl_stmt|;
name|int
name|pc98_if_type
decl_stmt|;
endif|#
directive|endif
comment|/* PC98 */
name|Port_t
name|data_port
decl_stmt|;
comment|/* i/o ports */
ifdef|#
directive|ifdef
name|COM_ESP
name|Port_t
name|esp_port
decl_stmt|;
endif|#
directive|endif
name|Port_t
name|int_id_port
decl_stmt|;
name|Port_t
name|iobase
decl_stmt|;
name|Port_t
name|modem_ctl_port
decl_stmt|;
name|Port_t
name|line_status_port
decl_stmt|;
name|Port_t
name|modem_status_port
decl_stmt|;
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
comment|/* cross reference */
comment|/* Initial state. */
name|struct
name|termios
name|it_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|it_out
decl_stmt|;
comment|/* Lock state. */
name|struct
name|termios
name|lt_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|lt_out
decl_stmt|;
name|bool_t
name|do_timestamp
decl_stmt|;
name|bool_t
name|do_dcd_timestamp
decl_stmt|;
name|struct
name|timeval
name|timestamp
decl_stmt|;
name|struct
name|timeval
name|dcd_timestamp
decl_stmt|;
name|u_long
name|bytes_in
decl_stmt|;
comment|/* statistics */
name|u_long
name|bytes_out
decl_stmt|;
name|u_int
name|delta_error_counts
index|[
name|CE_NTYPES
index|]
decl_stmt|;
name|u_long
name|error_counts
index|[
name|CE_NTYPES
index|]
decl_stmt|;
comment|/* 	 * Ping-pong input buffers.  The extra factor of 2 in the sizes is 	 * to allow for an error byte for each input byte. 	 */
define|#
directive|define
name|CE_INPUT_OFFSET
value|RS_IBUFSIZE
name|u_char
name|ibuf1
index|[
literal|2
operator|*
name|RS_IBUFSIZE
index|]
decl_stmt|;
name|u_char
name|ibuf2
index|[
literal|2
operator|*
name|RS_IBUFSIZE
index|]
decl_stmt|;
comment|/* 	 * Data area for output buffers.  Someday we should build the output 	 * buffer queue without copying data. 	 */
name|u_char
name|obuf1
index|[
literal|256
index|]
decl_stmt|;
name|u_char
name|obuf2
index|[
literal|256
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|devfs_token_ttyd
decl_stmt|;
name|void
modifier|*
name|devfs_token_ttyl
decl_stmt|;
name|void
modifier|*
name|devfs_token_ttyi
decl_stmt|;
name|void
modifier|*
name|devfs_token_cuaa
decl_stmt|;
name|void
modifier|*
name|devfs_token_cual
decl_stmt|;
name|void
modifier|*
name|devfs_token_cuai
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX public functions in drivers should be declared in headers produced  * by `config', not here.  */
end_comment

begin_comment
comment|/* Interrupt handling entry point. */
end_comment

begin_decl_stmt
name|void
name|siopoll
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device switch entry points. */
end_comment

begin_define
define|#
directive|define
name|sioreset
value|noreset
end_define

begin_define
define|#
directive|define
name|siommap
value|nommap
end_define

begin_define
define|#
directive|define
name|siostrategy
value|nostrategy
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|COM_ESP
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|espattach
name|__P
argument_list|(
operator|(
expr|struct
name|pc98_device
operator|*
name|isdp
operator|,
expr|struct
name|com_s
operator|*
name|com
operator|,
name|Port_t
name|esp_port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|sioattach
name|__P
argument_list|(
operator|(
expr|struct
name|pc98_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|COM_ESP
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|espattach
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|isdp
operator|,
expr|struct
name|com_s
operator|*
name|com
operator|,
name|Port_t
name|esp_port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|sioattach
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|timeout_t
name|siodtrwakeup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|comhardclose
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|siointr1
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|commctl
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|,
name|int
name|bits
operator|,
name|int
name|how
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|comparam
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
expr|struct
name|termios
operator|*
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|sioprobe
name|__P
argument_list|(
operator|(
expr|struct
name|pc98_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sioregisterdev
name|__P
argument_list|(
operator|(
expr|struct
name|pc98_device
operator|*
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|int
name|sioprobe
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sioregisterdev
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|siosettimeout
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|comstart
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
specifier|static
name|timeout_t
name|comwakeup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tiocm_xxx2mcr
name|__P
argument_list|(
operator|(
name|int
name|tiocm_xxx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|disc_optim
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
expr|struct
name|termios
operator|*
name|t
operator|,
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DSI_SOFT_MODEM
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|LoadSoftModem
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|int
name|base_io
operator|,
name|u_long
name|size
operator|,
name|u_char
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DSI_SOFT_MODEM */
end_comment

begin_decl_stmt
specifier|static
name|char
name|driver_name
index|[]
init|=
literal|"sio"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table and macro for fast conversion from a unit number to its com struct */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|com_s
modifier|*
name|p_com_addr
index|[
name|NSIO
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|com_addr
parameter_list|(
name|unit
parameter_list|)
value|(p_com_addr[unit])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_decl_stmt
name|struct
name|pc98_driver
name|siodriver
init|=
block|{
else|#
directive|else
block|struct
name|isa_driver
name|siodriver
operator|=
block|{
endif|#
directive|endif
name|sioprobe
block|,
name|sioattach
block|,
name|driver_name
block|}
block|;
specifier|static
name|d_open_t
name|sioopen
block|;
specifier|static
name|d_close_t
name|sioclose
block|;
specifier|static
name|d_read_t
name|sioread
block|;
specifier|static
name|d_write_t
name|siowrite
block|;
specifier|static
name|d_ioctl_t
name|sioioctl
block|;
specifier|static
name|d_stop_t
name|siostop
block|;
specifier|static
name|d_devtotty_t
name|siodevtotty
block|;
define|#
directive|define
name|CDEV_MAJOR
value|28
specifier|static
expr|struct
name|cdevsw
name|sio_cdevsw
operator|=
block|{
name|sioopen
block|,
name|sioclose
block|,
name|sioread
block|,
name|siowrite
block|,
name|sioioctl
block|,
name|siostop
block|,
name|noreset
block|,
name|siodevtotty
block|,
name|ttselect
block|,
name|nommap
block|,
name|NULL
block|,
name|driver_name
block|,
name|NULL
block|,
operator|-
literal|1
block|, }
block|;
specifier|static
name|int
name|comconsole
operator|=
operator|-
literal|1
block|;
specifier|static
name|speed_t
name|comdefaultrate
operator|=
name|TTYDEF_SPEED
block|;
specifier|static
name|u_int
name|com_events
block|;
comment|/* input chars + weighted output completions */
specifier|static
name|int
name|sio_timeout
block|;
specifier|static
name|int
name|sio_timeouts_until_log
block|;
if|#
directive|if
literal|0
comment|/* XXX */
block|static struct tty	*sio_tty[NSIO];
else|#
directive|else
specifier|static
expr|struct
name|tty
name|sio_tty
index|[
name|NSIO
index|]
block|;
endif|#
directive|endif
specifier|static
specifier|const
name|int
name|nsio_tty
operator|=
name|NSIO
block|;
ifdef|#
directive|ifdef
name|PC98
block|struct
name|siodev
block|{
name|short
name|if_type
block|;
name|short
name|irq
block|;
name|Port_t
name|cmd
block|,
name|sts
block|,
name|ctrl
block|,
name|mod
block|; 	}
block|;
specifier|static
name|int
name|sysclock
block|;
specifier|static
name|short
name|port_table
index|[
literal|5
index|]
index|[
literal|3
index|]
operator|=
block|{
block|{
literal|0x30
block|,
literal|0xb1
block|,
literal|0xb9
block|}
block|,
block|{
literal|0x32
block|,
literal|0xb3
block|,
literal|0xbb
block|}
block|,
block|{
literal|0x32
block|,
literal|0xb3
block|,
literal|0xbb
block|}
block|,
block|{
literal|0x33
block|,
literal|0xb0
block|,
literal|0xb2
block|}
block|,
block|{
literal|0x35
block|,
literal|0xb0
block|,
literal|0xb2
block|}
block|}
block|;
define|#
directive|define
name|PC98SIO_data_port
parameter_list|(
name|ch
parameter_list|)
value|port_table[0][ch]
define|#
directive|define
name|PC98SIO_cmd_port
parameter_list|(
name|ch
parameter_list|)
value|port_table[1][ch]
define|#
directive|define
name|PC98SIO_sts_port
parameter_list|(
name|ch
parameter_list|)
value|port_table[2][ch]
define|#
directive|define
name|PC98SIO_in_modem_port
parameter_list|(
name|ch
parameter_list|)
value|port_table[3][ch]
define|#
directive|define
name|PC98SIO_intr_ctrl_port
parameter_list|(
name|ch
parameter_list|)
value|port_table[4][ch]
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
define|#
directive|define
name|IO_COM_PIO9032B_2
value|0x0b8
define|#
directive|define
name|IO_COM_PIO9032B_3
value|0x0ba
endif|#
directive|endif
comment|/* COM_IF_PIO9032B */
ifdef|#
directive|ifdef
name|COM_IF_B98_01
define|#
directive|define
name|IO_COM_B98_01_2
value|0x0d1
define|#
directive|define
name|IO_COM_B98_01_3
value|0x0d5
endif|#
directive|endif
comment|/* COM_IF_B98_01 */
define|#
directive|define
name|COM_INT_DISABLE
value|{int previpri; previpri=spltty();
define|#
directive|define
name|COM_INT_ENABLE
value|splx(previpri);}
define|#
directive|define
name|IEN_TxFLAG
value|IEN_Tx
define|#
directive|define
name|COM_CARRIER_DETECT_EMULATE
value|0
define|#
directive|define
name|PC98_CHECK_MODEM_INTERVAL
value|(hz/10)
define|#
directive|define
name|DCD_OFF_TOLERANCE
value|2
define|#
directive|define
name|DCD_ON_RECOGNITION
value|2
define|#
directive|define
name|IS_8251
parameter_list|(
name|type
parameter_list|)
value|(type != MC16550)
define|#
directive|define
name|IS_PC98IN
parameter_list|(
name|adr
parameter_list|)
value|(adr == 0x30)
specifier|static
name|void
name|commint
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
block|;
specifier|static
name|void
name|com_tiocm_set
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|msr
operator|)
argument_list|)
block|;
specifier|static
name|void
name|com_tiocm_bis
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|msr
operator|)
argument_list|)
block|;
specifier|static
name|void
name|com_tiocm_bic
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|msr
operator|)
argument_list|)
block|;
specifier|static
name|int
name|com_tiocm_get
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|int
name|com_tiocm_get_delta
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_msrint_start
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
block|;
specifier|static
name|void
name|com_cflag_and_speed_set
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|cflag
expr|,
name|int
name|speed
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_ttspeedtab
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|speed
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_get_modem_status
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|timeout_t
name|pc98_check_msr
block|;
specifier|static
name|void
name|pc98_set_baud_rate
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|count
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_i8251_reset
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|mode
expr|,
name|int
name|command
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_disable_i8251_interrupt
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|mod
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_enable_i8251_interrupt
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|mod
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_check_i8251_interrupt
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_i8251_get_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_i8251_get_mod
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_i8251_set_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|x
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_i8251_or_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|x
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_i8251_clear_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|x
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_i8251_clear_or_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|clr
expr|,
name|int
name|x
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_check_if_type
name|__P
argument_list|(
operator|(
name|int
name|iobase
expr|, struct
name|siodev
operator|*
name|iod
operator|)
argument_list|)
block|;
specifier|static
name|void
name|pc98_check_sysclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
block|;
specifier|static
name|int
name|pc98_set_ioport
name|__P
argument_list|(
operator|(
expr|struct
name|com_s
operator|*
name|com
expr|,
name|int
name|io_base
operator|)
argument_list|)
block|;
define|#
directive|define
name|com_int_Tx_disable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_disable_i8251_interrupt(com,IEN_Tx|IEN_TxEMP)
define|#
directive|define
name|com_int_Tx_enable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_enable_i8251_interrupt(com,IEN_TxFLAG)
define|#
directive|define
name|com_int_Rx_disable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_disable_i8251_interrupt(com,IEN_Rx)
define|#
directive|define
name|com_int_Rx_enable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_enable_i8251_interrupt(com,IEN_Rx)
define|#
directive|define
name|com_int_TxRx_disable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_disable_i8251_interrupt(com,IEN_Tx|IEN_TxEMP|IEN_Rx)
define|#
directive|define
name|com_int_TxRx_enable
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_enable_i8251_interrupt(com,IEN_TxFLAG|IEN_Rx)
define|#
directive|define
name|com_send_break_on
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_i8251_or_cmd(com,CMD8251_SBRK)
define|#
directive|define
name|com_send_break_off
parameter_list|(
name|com
parameter_list|)
define|\
value|pc98_i8251_clear_cmd(com,CMD8251_SBRK)
block|struct
name|speedtab
name|pc98speedtab
index|[]
operator|=
block|{
comment|/* internal RS232C interface */
literal|0
block|,
literal|0
block|,
literal|50
block|,
literal|50
block|,
literal|75
block|,
literal|75
block|,
literal|150
block|,
literal|150
block|,
literal|200
block|,
literal|200
block|,
literal|300
block|,
literal|300
block|,
literal|600
block|,
literal|600
block|,
literal|1200
block|,
literal|1200
block|,
literal|2400
block|,
literal|2400
block|,
literal|4800
block|,
literal|4800
block|,
literal|9600
block|,
literal|9600
block|,
literal|19200
block|,
literal|19200
block|,
literal|38400
block|,
literal|38400
block|,
literal|76800
block|,
literal|76800
block|,
literal|20800
block|,
literal|20800
block|,
literal|41600
block|,
literal|41600
block|,
literal|15600
block|,
literal|15600
block|,
literal|31200
block|,
literal|31200
block|,
literal|62400
block|,
literal|62400
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|;
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
block|struct
name|speedtab
name|comspeedtab_pio9032b
index|[]
operator|=
block|{
literal|300
block|,
literal|6
block|,
literal|600
block|,
literal|5
block|,
literal|1200
block|,
literal|4
block|,
literal|2400
block|,
literal|3
block|,
literal|4800
block|,
literal|2
block|,
literal|9600
block|,
literal|1
block|,
literal|19200
block|,
literal|0
block|,
literal|38400
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_B98_01
block|struct
name|speedtab
name|comspeedtab_b98_01
index|[]
operator|=
block|{
literal|0
block|,
literal|0
block|,
literal|75
block|,
literal|15
block|,
literal|150
block|,
literal|14
block|,
literal|300
block|,
literal|13
block|,
literal|600
block|,
literal|12
block|,
literal|1200
block|,
literal|11
block|,
literal|2400
block|,
literal|10
block|,
literal|4800
block|,
literal|9
block|,
literal|9600
block|,
literal|8
block|,
literal|19200
block|,
literal|7
block|,
literal|38400
block|,
literal|6
block|,
literal|76800
block|,
literal|5
block|,
literal|153600
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* PC98 */
specifier|static
expr|struct
name|speedtab
name|comspeedtab
index|[]
operator|=
block|{
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|50
block|,
name|COMBRD
argument_list|(
literal|50
argument_list|)
block|}
block|,
block|{
literal|75
block|,
name|COMBRD
argument_list|(
literal|75
argument_list|)
block|}
block|,
block|{
literal|110
block|,
name|COMBRD
argument_list|(
literal|110
argument_list|)
block|}
block|,
block|{
literal|134
block|,
name|COMBRD
argument_list|(
literal|134
argument_list|)
block|}
block|,
block|{
literal|150
block|,
name|COMBRD
argument_list|(
literal|150
argument_list|)
block|}
block|,
block|{
literal|200
block|,
name|COMBRD
argument_list|(
literal|200
argument_list|)
block|}
block|,
block|{
literal|300
block|,
name|COMBRD
argument_list|(
literal|300
argument_list|)
block|}
block|,
block|{
literal|600
block|,
name|COMBRD
argument_list|(
literal|600
argument_list|)
block|}
block|,
block|{
literal|1200
block|,
name|COMBRD
argument_list|(
literal|1200
argument_list|)
block|}
block|,
block|{
literal|1800
block|,
name|COMBRD
argument_list|(
literal|1800
argument_list|)
block|}
block|,
block|{
literal|2400
block|,
name|COMBRD
argument_list|(
literal|2400
argument_list|)
block|}
block|,
block|{
literal|4800
block|,
name|COMBRD
argument_list|(
literal|4800
argument_list|)
block|}
block|,
block|{
literal|9600
block|,
name|COMBRD
argument_list|(
literal|9600
argument_list|)
block|}
block|,
block|{
literal|19200
block|,
name|COMBRD
argument_list|(
literal|19200
argument_list|)
block|}
block|,
block|{
literal|38400
block|,
name|COMBRD
argument_list|(
literal|38400
argument_list|)
block|}
block|,
block|{
literal|57600
block|,
name|COMBRD
argument_list|(
literal|57600
argument_list|)
block|}
block|,
block|{
literal|115200
block|,
name|COMBRD
argument_list|(
literal|115200
argument_list|)
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
block|;
specifier|static
expr|struct
name|kern_devconf
name|kdc_sio
index|[
name|NSIO
index|]
operator|=
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* filled in by dev_attach */
ifdef|#
directive|ifdef
name|PC98
name|driver_name
block|,
literal|0
block|,
block|{
name|MDDT_PC98
block|,
literal|0
block|,
literal|"tty"
block|}
block|,
name|pc98_generic_externalize
block|,
literal|0
block|,
literal|0
block|,
name|PC98_EXTERNALLEN
block|,
operator|&
name|kdc_nec0
block|,
comment|/* parent */
else|#
directive|else
name|driver_name
block|,
literal|0
block|,
block|{
name|MDDT_ISA
block|,
literal|0
block|,
literal|"tty"
block|}
block|,
name|isa_generic_externalize
block|,
literal|0
block|,
literal|0
block|,
name|ISA_EXTERNALLEN
block|,
operator|&
name|kdc_isa0
block|,
comment|/* parent */
endif|#
directive|endif
literal|0
block|,
comment|/* parentdata */
name|DC_UNCONFIGURED
block|,
comment|/* state */
literal|"Serial port"
block|,
name|DC_CLS_SERIAL
comment|/* class */
block|}
block|}
block|;
ifdef|#
directive|ifdef
name|COM_ESP
comment|/* XXX configure this properly. */
specifier|static
name|Port_t
name|likely_com_ports
index|[]
operator|=
block|{
literal|0x3f8
block|,
literal|0x2f8
block|,
literal|0x3e8
block|,
literal|0x2e8
block|, }
block|;
specifier|static
name|Port_t
name|likely_esp_ports
index|[]
operator|=
block|{
literal|0x140
block|,
literal|0x180
block|,
literal|0x280
block|,
literal|0
block|}
block|;
endif|#
directive|endif
if|#
directive|if
name|NCRD
operator|>
literal|0
comment|/*  *	PC-Card (PCMCIA) specific code.  */
specifier|static
name|int
name|card_intr
argument_list|(
expr|struct
name|pccard_dev
operator|*
argument_list|)
block|;
comment|/* Interrupt handler */
specifier|static
name|void
name|siounload
argument_list|(
expr|struct
name|pccard_dev
operator|*
argument_list|)
block|;
comment|/* Disable driver */
specifier|static
name|void
name|siosuspend
argument_list|(
expr|struct
name|pccard_dev
operator|*
argument_list|)
block|;
comment|/* Suspend driver */
specifier|static
name|int
name|sioinit
argument_list|(
expr|struct
name|pccard_dev
operator|*
argument_list|,
name|int
argument_list|)
block|;
comment|/* init device */
specifier|static
expr|struct
name|pccard_drv
name|sio_info
operator|=
block|{
name|driver_name
block|,
name|card_intr
block|,
name|siounload
block|,
name|siosuspend
block|,
name|sioinit
block|,
literal|0
block|,
comment|/* Attributes - presently unused */
operator|&
name|tty_imask
comment|/* Interrupt mask for device */
comment|/* XXX - Should this also include net_imask? */
block|}
block|;
comment|/*  *	Called when a power down is requested. Shuts down the  *	device and configures the device as unavailable (but  *	still loaded...). A resume is done by calling  *	sioinit with first=0. This is called when the user suspends  *	the system, or the APM code suspends the system.  */
specifier|static
name|void
name|siosuspend
argument_list|(
argument|struct pccard_dev *dp
argument_list|)
block|{
name|printf
argument_list|(
literal|"sio%d: suspending\n"
argument_list|,
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
block|; }
comment|/*  *	Initialize the device - called from Slot manager.  *	If first is set, then check for the device's existence  *	before initializing it.  Once initialized, the device table may  *	be set up.  */
name|int
name|sioinit
argument_list|(
argument|struct pccard_dev *dp
argument_list|,
argument|int first
argument_list|)
block|{
comment|/* validate unit number. */
if|if
condition|(
name|first
condition|)
block|{
if|if
condition|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
operator|>=
name|NSIO
condition|)
return|return
operator|(
name|ENODEV
operator|)
return|;
comment|/* Make sure it isn't already probed. */
if|if
condition|(
name|com_addr
argument_list|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
comment|/* 		 * Probe the device. If a value is returned, the 		 * device was found at the location. 		 */
if|if
condition|(
name|sioprobe
argument_list|(
operator|&
name|dp
operator|->
name|isahd
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|sioattach
argument_list|(
operator|&
name|dp
operator|->
name|isahd
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* 	 * XXX TODO: 	 * If it was initialized before, the device structure 	 * should also be initialized.  We should 	 * reset (and possibly restart) the hardware, but 	 * I am not sure of the best way to do this... 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*  *	siounload - unload the driver and clear the table.  *	XXX TODO:  *	This is usually called when the card is ejected, but  *	can be caused by a modunload of a controller driver.  *	The idea is to reset the driver's view of the device  *	and ensure that any driver entry points such as  *	read and write do not hang.  */
specifier|static
name|void
name|siounload
argument_list|(
argument|struct pccard_dev *dp
argument_list|)
block|{ 	struct
name|com_s
operator|*
name|com
block|;
name|com
operator|=
name|com_addr
argument_list|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
block|;
if|if
condition|(
operator|!
name|com
operator|->
name|iobase
condition|)
block|{
name|printf
argument_list|(
literal|"sio%d already unloaded!\n"
argument_list|,
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
expr_stmt|;
return|return;
block|}
name|kdc_sio
index|[
name|com
operator|->
name|unit
index|]
operator|.
name|kdc_state
operator|=
name|DC_UNCONFIGURED
expr_stmt|;
name|kdc_sio
index|[
name|com
operator|->
name|unit
index|]
operator|.
name|kdc_description
operator|=
literal|"Serial port"
block|;
if|if
condition|(
name|com
operator|->
name|tp
operator|&&
operator|(
name|com
operator|->
name|tp
operator|->
name|t_state
operator|&
name|TS_ISOPEN
operator|)
condition|)
block|{
name|com
operator|->
name|gone
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"sio%d: unload\n"
argument_list|,
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
expr_stmt|;
name|com
operator|->
name|tp
operator|->
name|t_gen
operator|++
expr_stmt|;
name|ttyclose
argument_list|(
name|com
operator|->
name|tp
argument_list|)
expr_stmt|;
name|ttwakeup
argument_list|(
name|com
operator|->
name|tp
argument_list|)
expr_stmt|;
name|ttwwakeup
argument_list|(
name|com
operator|->
name|tp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|com_addr
argument_list|(
name|com
operator|->
name|unit
argument_list|)
operator|=
name|NULL
expr_stmt|;
name|bzero
argument_list|(
name|com
argument_list|,
sizeof|sizeof
expr|*
name|com
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|com
argument_list|,
name|M_TTYS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sio%d: unload,gone\n"
argument_list|,
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
expr_stmt|;
block|}
block|}
comment|/*  *	card_intr - Shared interrupt called from  *	front end of PC-Card handler.  */
specifier|static
name|int
name|card_intr
argument_list|(
argument|struct pccard_dev *dp
argument_list|)
block|{ 	struct
name|com_s
operator|*
name|com
block|;
name|com
operator|=
name|com_addr
argument_list|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
block|;
if|if
condition|(
name|com
operator|&&
operator|!
name|com_addr
argument_list|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
operator|->
name|gone
condition|)
name|siointr1
argument_list|(
name|com_addr
argument_list|(
name|dp
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
argument_list|)
expr_stmt|;
end_decl_stmt

begin_return
return|return
operator|(
literal|1
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCRD> 0 */
end_comment

begin_function
unit|static
name|void
name|sioregisterdev
parameter_list|(
name|id
parameter_list|)
ifdef|#
directive|ifdef
name|PC98
name|struct
name|pc98_device
modifier|*
name|id
decl_stmt|;
else|#
directive|else
name|struct
name|isa_device
modifier|*
name|id
decl_stmt|;
endif|#
directive|endif
block|{
name|int
name|unit
decl_stmt|;
name|unit
operator|=
name|id
operator|->
name|id_unit
expr_stmt|;
comment|/*  *	If already registered, don't try to re-register.  */
ifdef|#
directive|ifdef
name|PC98
if|if
condition|(
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_pc98
condition|)
else|#
directive|else
if|if
condition|(
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_isa
condition|)
endif|#
directive|endif
return|return;
if|if
condition|(
name|unit
operator|!=
literal|0
condition|)
name|kdc_sio
index|[
name|unit
index|]
operator|=
name|kdc_sio
index|[
literal|0
index|]
expr_stmt|;
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_state
operator|=
name|DC_UNCONFIGURED
expr_stmt|;
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_description
operator|=
literal|"Serial port"
expr_stmt|;
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_unit
operator|=
name|unit
expr_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_pc98
operator|=
name|id
expr_stmt|;
else|#
directive|else
name|kdc_sio
index|[
name|unit
index|]
operator|.
name|kdc_isa
operator|=
name|id
expr_stmt|;
endif|#
directive|endif
name|dev_attach
argument_list|(
operator|&
name|kdc_sio
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|sioprobe
parameter_list|(
name|dev
parameter_list|)
ifdef|#
directive|ifdef
name|PC98
name|struct
name|pc98_device
modifier|*
name|dev
decl_stmt|;
else|#
directive|else
name|struct
name|isa_device
modifier|*
name|dev
decl_stmt|;
endif|#
directive|endif
block|{
specifier|static
name|bool_t
name|already_init
decl_stmt|;
name|bool_t
name|failures
index|[
literal|10
index|]
decl_stmt|;
name|int
name|fn
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|struct
name|pc98_device
modifier|*
name|idev
decl_stmt|;
else|#
directive|else
name|struct
name|isa_device
modifier|*
name|idev
decl_stmt|;
endif|#
directive|endif
name|Port_t
name|iobase
decl_stmt|;
name|u_char
name|mcr_image
decl_stmt|;
name|int
name|result
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|struct
name|pc98_device
modifier|*
name|xdev
decl_stmt|;
name|int
name|irqout
init|=
literal|0
decl_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|int
name|tmp
decl_stmt|;
name|struct
name|siodev
name|iod
decl_stmt|;
else|#
directive|else
name|struct
name|isa_device
modifier|*
name|xdev
decl_stmt|;
endif|#
directive|endif
name|sioregisterdev
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|already_init
condition|)
block|{
comment|/* 		 * Turn off MCR_IENABLE for all likely serial ports.  An unused 		 * port with its MCR_IENABLE gate open will inhibit interrupts 		 * from any used port that shares the interrupt vector. 		 * XXX the gate enable is elsewhere for some multiports. 		 */
ifdef|#
directive|ifdef
name|PC98
for|for
control|(
name|xdev
operator|=
name|pc98_devtab_tty
init|;
name|xdev
operator|->
name|id_driver
operator|!=
name|NULL
condition|;
name|xdev
operator|++
control|)
else|#
directive|else
for|for
control|(
name|xdev
operator|=
name|isa_devtab_tty
init|;
name|xdev
operator|->
name|id_driver
operator|!=
name|NULL
condition|;
name|xdev
operator|++
control|)
endif|#
directive|endif
if|if
condition|(
name|xdev
operator|->
name|id_driver
operator|==
operator|&
name|siodriver
operator|&&
name|xdev
operator|->
name|id_enabled
condition|)
ifdef|#
directive|ifdef
name|PC98
if|if
condition|(
name|IS_PC98IN
argument_list|(
name|xdev
operator|->
name|id_iobase
argument_list|)
condition|)
name|outb
argument_list|(
name|xdev
operator|->
name|id_iobase
operator|+
literal|2
argument_list|,
literal|0xf2
argument_list|)
expr_stmt|;
else|else
else|#
directive|else
name|outb
argument_list|(
name|xdev
operator|->
name|id_iobase
operator|+
name|com_mcr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NCRD
operator|>
literal|0
comment|/* 		 * If PC-Card probe required, then register driver with 		 * slot manager. 		 */
name|pccard_add_driver
argument_list|(
operator|&
name|sio_info
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|already_init
operator|=
name|TRUE
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|PC98
comment|/* 	 * If the port is i8251 UART (internal, B98_01) 	 */
if|if
condition|(
name|pc98_check_if_type
argument_list|(
name|dev
operator|->
name|id_iobase
argument_list|,
operator|&
name|iod
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|IS_8251
argument_list|(
name|iod
operator|.
name|if_type
argument_list|)
condition|)
block|{
if|if
condition|(
name|iod
operator|.
name|irq
operator|>
literal|0
condition|)
name|dev
operator|->
name|id_irq
operator|=
operator|(
literal|1
operator|<<
name|iod
operator|.
name|irq
operator|)
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
name|CMD8251_RESET
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* for a while...*/
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
literal|0xf2
argument_list|)
expr_stmt|;
comment|/* MODE (dummy) */
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|cmd
argument_list|,
literal|0x01
argument_list|)
expr_stmt|;
comment|/* CMD (dummy) */
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* for a while...*/
if|if
condition|(
operator|(
name|inb
argument_list|(
name|iod
operator|.
name|sts
argument_list|)
operator|&
name|STS8251_TxEMP
operator|)
operator|==
literal|0
condition|)
block|{
name|ret
operator|=
literal|0
expr_stmt|;
block|}
switch|switch
condition|(
name|iod
operator|.
name|if_type
condition|)
block|{
case|case
name|COM_IF_INTERNAL
case|:
name|COM_INT_DISABLE
name|tmp
init|=
operator|(
name|inb
argument_list|(
name|iod
operator|.
name|ctrl
argument_list|)
operator|&
operator|~
operator|(
name|IEN_Rx
operator||
name|IEN_TxEMP
operator||
name|IEN_Tx
operator|)
operator|)
decl_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|ctrl
argument_list|,
name|tmp
operator||
name|IEN_TxEMP
argument_list|)
expr_stmt|;
name|ret
operator|=
name|pc98_irq_pending
argument_list|(
name|dev
argument_list|)
condition|?
literal|4
else|:
literal|0
expr_stmt|;
name|outb
argument_list|(
name|iod
operator|.
name|ctrl
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|COM_INT_ENABLE
break|break;
ifdef|#
directive|ifdef
name|COM_IF_B98_01
case|case
name|COM_IF_B98_01
case|:
comment|/* B98_01 doesn't activate TxEMP interrupt line 			   when being reset, so we can't check irq pending.*/
name|ret
operator|=
literal|4
expr_stmt|;
break|break;
endif|#
directive|endif
block|}
if|if
condition|(
name|epson_machine_id
operator|==
literal|0x20
condition|)
block|{
comment|/* XXX */
name|ret
operator|=
literal|4
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
endif|#
directive|endif
comment|/* PC98 */
comment|/* 	 * If the device is on a multiport card and has an AST/4 	 * compatible interrupt control register, initialize this 	 * register and prepare to leave MCR_IENABLE clear in the mcr. 	 * Otherwise, prepare to set MCR_IENABLE in the mcr. 	 * Point idev to the device struct giving the correct id_irq. 	 * This is the struct for the master device if there is one. 	 */
name|idev
operator|=
name|dev
expr_stmt|;
name|mcr_image
operator|=
name|MCR_IENABLE
expr_stmt|;
ifdef|#
directive|ifdef
name|COM_MULTIPORT
if|if
condition|(
name|COM_ISMULTIPORT
argument_list|(
name|dev
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|PC98
name|idev
operator|=
name|find_pc98dev
argument_list|(
argument|pc98_devtab_tty
argument_list|,
argument|&siodriver
argument_list|,
else|#
directive|else
argument|idev = find_isadev(isa_devtab_tty,&siodriver,
endif|#
directive|endif
argument|COM_MPMASTER(dev)); 		if (idev == NULL) { 			printf(
literal|"sio%d: master device %d not configured\n"
argument|, 			       dev->id_unit, COM_MPMASTER(dev)); 			return (
literal|0
argument|); 		}
ifndef|#
directive|ifndef
name|PC98
argument|if (!COM_NOTAST4(dev)) { 			outb(idev->id_iobase + com_scr, 			     idev->id_irq ?
literal|0x80
argument|:
literal|0
argument|); 			mcr_image =
literal|0
argument|; 		}
endif|#
directive|endif
comment|/* !PC98 */
argument|}
endif|#
directive|endif
comment|/* COM_MULTIPORT */
argument|if (idev->id_irq ==
literal|0
argument|) 		mcr_image =
literal|0
argument|;
ifdef|#
directive|ifdef
name|PC98
argument|switch(idev->id_irq){ 		case IRQ3: irqout =
literal|4
argument|; break; 		case IRQ5: irqout =
literal|5
argument|; break; 		case IRQ6: irqout =
literal|6
argument|; break; 		case IRQ12: irqout =
literal|7
argument|; break; 		default: 			printf(
literal|"sio%d: irq configuration error\n"
argument|,dev->id_unit); 			return (
literal|0
argument|); 	} 	outb(dev->id_iobase+
literal|0x1000
argument|, irqout);
endif|#
directive|endif
argument|bzero(failures, sizeof failures); 	iobase = dev->id_iobase;
comment|/* 	 * We don't want to get actual interrupts, just masked ones. 	 * Interrupts from this line should already be masked in the ICU, 	 * but mask them in the processor as well in case there are some 	 * (misconfigured) shared interrupts. 	 */
argument|disable_intr();
comment|/* EXTRA DELAY? */
comment|/* 	 * Initialize the speed and the word size and wait long enough to 	 * drain the maximum of 16 bytes of junk in device output queues. 	 * The speed is undefined after a master reset and must be set 	 * before relying on anything related to output.  There may be 	 * junk after a (very fast) soft reboot and (apparently) after 	 * master reset. 	 * XXX what about the UART bug avoided by waiting in comparam()? 	 * We don't want to to wait long enough to drain at 2 bps. 	 */
argument|outb(iobase + com_cfcr, CFCR_DLAB); 	outb(iobase + com_dlbl, COMBRD(
literal|9600
argument|)&
literal|0xff
argument|); 	outb(iobase + com_dlbh, (u_int) COMBRD(
literal|9600
argument|)>>
literal|8
argument|); 	outb(iobase + com_cfcr, CFCR_8BITS); 	DELAY((
literal|16
argument|+
literal|1
argument|) *
literal|1000000
argument|/ (
literal|9600
argument|/
literal|10
argument|));
comment|/* 	 * Enable the interrupt gate and disable device interupts.  This 	 * should leave the device driving the interrupt line low and 	 * guarantee an edge trigger if an interrupt can be generated. 	 */
comment|/* EXTRA DELAY? */
argument|outb(iobase + com_mcr, mcr_image); 	outb(iobase + com_ier,
literal|0
argument|);
comment|/* 	 * Attempt to set loopback mode so that we can send a null byte 	 * without annoying any external device. 	 */
comment|/* EXTRA DELAY? */
argument|outb(iobase + com_mcr, mcr_image | MCR_LOOPBACK);
comment|/* 	 * Attempt to generate an output interrupt.  On 8250's, setting 	 * IER_ETXRDY generates an interrupt independent of the current 	 * setting and independent of whether the THR is empty.  On 16450's, 	 * setting IER_ETXRDY generates an interrupt independent of the 	 * current setting.  On 16550A's, setting IER_ETXRDY only 	 * generates an interrupt when IER_ETXRDY is not already set. 	 */
argument|outb(iobase + com_ier, IER_ETXRDY);
comment|/* 	 * On some 16x50 incompatibles, setting IER_ETXRDY doesn't generate 	 * an interrupt.  They'd better generate one for actually doing 	 * output.  Loopback may be broken on the same incompatibles but 	 * it's unlikely to do more than allow the null byte out. 	 */
argument|outb(iobase + com_data,
literal|0
argument|); 	DELAY((
literal|1
argument|+
literal|2
argument|) *
literal|1000000
argument|/ (
literal|9600
argument|/
literal|10
argument|));
comment|/* 	 * Turn off loopback mode so that the interrupt gate works again 	 * (MCR_IENABLE was hidden).  This should leave the device driving 	 * an interrupt line high.  It doesn't matter if the interrupt 	 * line oscillates while we are not looking at it, since interrupts 	 * are disabled. 	 */
comment|/* EXTRA DELAY? */
argument|outb(iobase + com_mcr, mcr_image);
comment|/* 	 * Check that 	 *	o the CFCR, IER and MCR in UART hold the values written to them 	 *	  (the values happen to be all distinct - this is good for 	 *	  avoiding false positive tests from bus echoes). 	 *	o an output interrupt is generated and its vector is correct. 	 *	o the interrupt goes away when the IIR in the UART is read. 	 */
comment|/* EXTRA DELAY? */
argument|failures[
literal|0
argument|] = inb(iobase + com_cfcr) - CFCR_8BITS; 	failures[
literal|1
argument|] = inb(iobase + com_ier) - IER_ETXRDY; 	failures[
literal|2
argument|] = inb(iobase + com_mcr) - mcr_image; 	DELAY(
literal|10000
argument|);
comment|/* Some internal modems need this time */
argument|if (idev->id_irq !=
literal|0
argument|)
ifdef|#
directive|ifdef
name|PC98
argument|failures[
literal|3
argument|] = pc98_irq_pending(idev) ?
literal|0
argument|:
literal|1
argument|;
else|#
directive|else
argument|failures[
literal|3
argument|] = isa_irq_pending(idev) ?
literal|0
argument|:
literal|1
argument|;
endif|#
directive|endif
argument|failures[
literal|4
argument|] = (inb(iobase + com_iir)& IIR_IMASK) - IIR_TXRDY; 	DELAY(
literal|1000
argument|);
comment|/* XXX */
ifdef|#
directive|ifdef
name|PC98
argument|if (idev->id_irq !=
literal|0
argument|) 		failures[
literal|5
argument|] = pc98_irq_pending(idev) ?
literal|1
argument|:
literal|0
argument|;
else|#
directive|else
argument|if (idev->id_irq !=
literal|0
argument|) 		failures[
literal|5
argument|] = isa_irq_pending(idev) ?
literal|1
argument|:
literal|0
argument|;
endif|#
directive|endif
argument|failures[
literal|6
argument|] = (inb(iobase + com_iir)& IIR_IMASK) - IIR_NOPEND;
comment|/* 	 * Turn off all device interrupts and check that they go off properly. 	 * Leave MCR_IENABLE alone.  For ports without a master port, it gates 	 * the OUT2 output of the UART to 	 * the ICU input.  Closing the gate would give a floating ICU input 	 * (unless there is another device driving at) and spurious interrupts. 	 * (On the system that this was first tested on, the input floats high 	 * and gives a (masked) interrupt as soon as the gate is closed.) 	 */
argument|outb(iobase + com_ier,
literal|0
argument|); 	outb(iobase + com_cfcr, CFCR_8BITS);
comment|/* dummy to avoid bus echo */
argument|failures[
literal|7
argument|] = inb(iobase + com_ier); 	DELAY(
literal|1000
argument|);
comment|/* XXX */
ifdef|#
directive|ifdef
name|PC98
argument|if (idev->id_irq !=
literal|0
argument|) 		failures[
literal|8
argument|] = pc98_irq_pending(idev) ?
literal|1
argument|:
literal|0
argument|;
else|#
directive|else
argument|if (idev->id_irq !=
literal|0
argument|) 		failures[
literal|8
argument|] = isa_irq_pending(idev) ?
literal|1
argument|:
literal|0
argument|;
endif|#
directive|endif
argument|failures[
literal|9
argument|] = (inb(iobase + com_iir)& IIR_IMASK) - IIR_NOPEND;  	enable_intr();  	result = IO_COMSIZE; 	for (fn =
literal|0
argument|; fn< sizeof failures; ++fn) 		if (failures[fn]) { 			outb(iobase + com_mcr,
literal|0
argument|); 			result =
literal|0
argument|; 			if (COM_VERBOSE(dev)) 				printf(
literal|"sio%d: probe test %d failed\n"
argument|, 				       dev->id_unit, fn); 		} 	return (result); }
ifdef|#
directive|ifdef
name|COM_ESP
argument|static int espattach(isdp, com, esp_port) 	struct isa_device	*isdp; 	struct com_s		*com; 	Port_t			esp_port; { 	u_char	dips; 	u_char	val;
comment|/* 	 * Check the ESP-specific I/O port to see if we're an ESP 	 * card.  If not, return failure immediately. 	 */
argument|if ((inb(esp_port)&
literal|0xf3
argument|) ==
literal|0
argument|) { 		printf(
literal|" port 0x%x is not an ESP board?\n"
argument|, esp_port); 		return (
literal|0
argument|); 	}
comment|/* 	 * We've got something that claims to be a Hayes ESP card. 	 * Let's hope so. 	 */
comment|/* Get the dip-switch configuration */
argument|outb(esp_port + ESP_CMD1, ESP_GETDIPS); 	dips = inb(esp_port + ESP_STATUS1);
comment|/* 	 * Bits 0,1 of dips say which COM port we are. 	 */
argument|if (com->iobase == likely_com_ports[dips&
literal|0x03
argument|]) 		printf(
literal|" : ESP"
argument|); 	else { 		printf(
literal|" esp_port has com %d\n"
argument|, dips&
literal|0x03
argument|); 		return (
literal|0
argument|); 	}
comment|/* 	 * Check for ESP version 2.0 or later:  bits 4,5,6 = 010. 	 */
argument|outb(esp_port + ESP_CMD1, ESP_GETTEST); 	val = inb(esp_port + ESP_STATUS1);
comment|/* clear reg 1 */
argument|val = inb(esp_port + ESP_STATUS2); 	if ((val&
literal|0x70
argument|)<
literal|0x20
argument|) { 		printf(
literal|"-old (%o)"
argument|, val&
literal|0x70
argument|); 		return (
literal|0
argument|); 	}
comment|/* 	 * Check for ability to emulate 16550:  bit 7 == 1 	 */
argument|if ((dips&
literal|0x80
argument|) ==
literal|0
argument|) { 		printf(
literal|" slave"
argument|); 		return (
literal|0
argument|); 	}
comment|/* 	 * Okay, we seem to be a Hayes ESP card.  Whee. 	 */
argument|com->esp = TRUE; 	com->esp_port = esp_port; 	return (
literal|1
argument|); }
endif|#
directive|endif
comment|/* COM_ESP */
argument|static int sioattach(isdp)
ifdef|#
directive|ifdef
name|PC98
argument|struct pc98_device	*isdp;
else|#
directive|else
argument|struct isa_device	*isdp;
endif|#
directive|endif
argument|{ 	struct com_s	*com; 	dev_t		dev;
ifdef|#
directive|ifdef
name|COM_ESP
argument|Port_t		*espp;
endif|#
directive|endif
argument|Port_t		iobase; 	int		s; 	int		unit;  	isdp->id_ri_flags |= RI_FAST; 	iobase = isdp->id_iobase; 	unit = isdp->id_unit; 	com = malloc(sizeof *com, M_TTYS, M_NOWAIT); 	if (com == NULL) 		return (
literal|0
argument|);
comment|/* 	 * sioprobe() has initialized the device registers as follows: 	 *	o cfcr = CFCR_8BITS. 	 *	  It is most important that CFCR_DLAB is off, so that the 	 *	  data port is not hidden when we enable interrupts. 	 *	o ier = 0. 	 *	  Interrupts are only enabled when the line is open. 	 *	o mcr = MCR_IENABLE, or 0 if the port has AST/4 compatible 	 *	  interrupt control register or the config specifies no irq. 	 *	  Keeping MCR_DTR and MCR_RTS off might stop the external 	 *	  device from sending before we are ready. 	 */
argument|bzero(com, sizeof *com); 	com->unit = unit; 	com->cfcr_image = CFCR_8BITS; 	com->dtr_wait =
literal|3
argument|* hz; 	com->loses_outints = COM_LOSESOUTINTS(isdp) !=
literal|0
argument|; 	com->no_irq = isdp->id_irq ==
literal|0
argument|; 	com->tx_fifo_size =
literal|1
argument|; 	com->iptr = com->ibuf = com->ibuf1; 	com->ibufend = com->ibuf1 + RS_IBUFSIZE; 	com->ihighwater = com->ibuf1 + RS_IHIGHWATER; 	com->obufs[
literal|0
argument|].l_head = com->obuf1; 	com->obufs[
literal|1
argument|].l_head = com->obuf2;  	com->iobase = iobase;
ifdef|#
directive|ifdef
name|PC98
argument|if(pc98_set_ioport(com, iobase) == -
literal|1
argument|) 		if((iobase&
literal|0x0f0
argument|) ==
literal|0xd0
argument|) { 			com->pc98_if_type = MC16550; 			com->data_port = iobase + com_data; 			com->int_id_port = iobase + com_iir; 			com->modem_ctl_port = iobase + com_mcr; 			com->mcr_image = inb(com->modem_ctl_port); 			com->line_status_port = iobase + com_lsr; 			com->modem_status_port = iobase + com_msr; 		}
else|#
directive|else
comment|/* not PC98 */
argument|com->data_port = iobase + com_data; 	com->int_id_port = iobase + com_iir; 	com->modem_ctl_port = iobase + com_mcr; 	com->mcr_image = inb(com->modem_ctl_port); 	com->line_status_port = iobase + com_lsr; 	com->modem_status_port = iobase + com_msr;
endif|#
directive|endif
comment|/* 	 * We don't use all the flags from<sys/ttydefaults.h> since they 	 * are only relevant for logins.  It's important to have echo off 	 * initially so that the line doesn't start blathering before the 	 * echo flag can be turned off. 	 */
argument|com->it_in.c_iflag =
literal|0
argument|; 	com->it_in.c_oflag =
literal|0
argument|; 	com->it_in.c_cflag = TTYDEF_CFLAG; 	com->it_in.c_lflag =
literal|0
argument|; 	if (unit == comconsole) {
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 			DELAY(
literal|100000
argument|);
endif|#
directive|endif
argument|com->it_in.c_iflag = TTYDEF_IFLAG; 		com->it_in.c_oflag = TTYDEF_OFLAG; 		com->it_in.c_cflag = TTYDEF_CFLAG | CLOCAL; 		com->it_in.c_lflag = TTYDEF_LFLAG; 		com->lt_out.c_cflag = com->lt_in.c_cflag = CLOCAL; 	} 	termioschars(&com->it_in); 	com->it_in.c_ispeed = com->it_in.c_ospeed = comdefaultrate; 	com->it_out = com->it_in;
comment|/* attempt to determine UART type */
argument|printf(
literal|"sio%d: type"
argument|, unit);
ifdef|#
directive|ifdef
name|DSI_SOFT_MODEM
argument|if((inb(iobase+
literal|7
argument|) ^ inb(iobase+
literal|7
argument|))&
literal|0x80
argument|) { 	    printf(
literal|" Digicom Systems, Inc. SoftModem"
argument|); 	    kdc_sio[unit].kdc_description =
literal|"Serial port: Digicom Systems SoftModem"
argument|; 	goto determined_type; 	}
endif|#
directive|endif
comment|/* DSI_SOFT_MODEM */
ifndef|#
directive|ifndef
name|PC98
ifdef|#
directive|ifdef
name|COM_MULTIPORT
argument|if (!COM_ISMULTIPORT(isdp))
endif|#
directive|endif
argument|{ 		u_char	scr; 		u_char	scr1; 		u_char	scr2;  		scr = inb(iobase + com_scr); 		outb(iobase + com_scr,
literal|0xa5
argument|); 		scr1 = inb(iobase + com_scr); 		outb(iobase + com_scr,
literal|0x5a
argument|); 		scr2 = inb(iobase + com_scr); 		outb(iobase + com_scr, scr); 		if (scr1 !=
literal|0xa5
argument||| scr2 !=
literal|0x5a
argument|) { 			printf(
literal|" 8250"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: National 8250 or compatible"
argument|; 			goto determined_type; 		} 	}
endif|#
directive|endif
comment|/* !PC98 */
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 		com_int_TxRx_disable( com ); 		com_cflag_and_speed_set( com, com->it_in.c_cflag, 						comdefaultrate ); 		com_tiocm_bic( com, TIOCM_DTR|TIOCM_RTS|TIOCM_LE ); 		com_send_break_off( com ); 		switch(com->pc98_if_type){ 		case COM_IF_INTERNAL: 			printf(
literal|" 8251 (internal)"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: PC-9801 internal"
argument|; 			break;
ifdef|#
directive|ifdef
name|COM_IF_PC9861K
argument|case COM_IF_PC9861K: 			printf(
literal|" 8251 (PC9861K)"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: PC-9861K"
argument|; 			break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
argument|case COM_IF_PIO9032B: 			printf(
literal|" 8251 (PIO9032B)"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: PIO9032B"
argument|; 			break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_B98_01
argument|case COM_IF_B98_01: 			printf(
literal|" 8251 (B98_01)"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: B98_01"
argument|; 			break;
endif|#
directive|endif
argument|} 	} else {
endif|#
directive|endif
comment|/* PC98 */
argument|outb(iobase + com_fifo, FIFO_ENABLE | FIFO_RX_HIGH); 	DELAY(
literal|100
argument|); 	switch (inb(com->int_id_port)& IIR_FIFO_MASK) { 	case FIFO_RX_LOW: 		printf(
literal|" 16450"
argument|); 		kdc_sio[unit].kdc_description =
literal|"Serial port: National 16450 or compatible"
argument|; 		break; 	case FIFO_RX_MEDL: 		printf(
literal|" 16450?"
argument|); 		kdc_sio[unit].kdc_description =
literal|"Serial port: maybe National 16450"
argument|; 		break; 	case FIFO_RX_MEDH: 		printf(
literal|" 16550?"
argument|); 		kdc_sio[unit].kdc_description =
literal|"Serial port: maybe National 16550"
argument|; 		break; 	case FIFO_RX_HIGH: 		printf(
literal|" 16550A"
argument|); 		if (COM_NOFIFO(isdp)) { 			printf(
literal|" fifo disabled"
argument|); 			kdc_sio[unit].kdc_description =
literal|"Serial port: National 16550A, FIFO disabled"
argument|; 		} else { 			com->hasfifo = TRUE; 			com->tx_fifo_size =
literal|16
argument|; 			kdc_sio[unit].kdc_description =
literal|"Serial port: National 16550A or compatible"
argument|;
ifdef|#
directive|ifdef
name|COM_ESP
argument|for (espp = likely_esp_ports; *espp !=
literal|0
argument|; espp++) 				if (espattach(isdp, com, *espp)) { 					com->tx_fifo_size =
literal|1024
argument|; 					kdc_sio[unit].kdc_description =
literal|"Serial port: Hayes ESP"
argument|; 					break; 				}
endif|#
directive|endif
argument|}
if|#
directive|if
literal|0
comment|/* 		 * Check for the Startech ST16C650 chip. 		 * it has a shadow register under the com_iir, 		 * which can only be accessed when cfcr == 0xff 		 */
argument|{ 		u_char i, j;  		i = inb(iobase + com_iir); 		outb(iobase + com_cfcr, 0xff); 		outb(iobase + com_iir, 0x0); 		outb(iobase + com_cfcr, CFCR_8BITS); 		j = inb(iobase + com_iir); 		outb(iobase + com_iir, i); 		if (i != j) { 			printf(" 16550A"); 		} else { 			com->tx_fifo_size = 32; 			printf(" 16650"); 			kdc_sio[unit].kdc_description = 			  "Serial port: Startech 16C650 or similar"; 		} 		if (!com->tx_fifo_size) 			printf(" fifo disabled"); 		}
endif|#
directive|endif
argument|break; 	}
ifdef|#
directive|ifdef
name|COM_ESP
argument|if (com->esp) { 		outb(iobase + com_fifo, 		     FIFO_DMA_MODE | FIFO_ENABLE | FIFO_RCV_RST | FIFO_XMT_RST 		     | FIFO_RX_MEDH);
comment|/* Set 16550 compatibility mode. */
argument|outb(com->esp_port + ESP_CMD1, ESP_SETMODE); 		outb(com->esp_port + ESP_CMD2, 		     ESP_MODE_SCALE | ESP_MODE_RTS | ESP_MODE_FIFO);
comment|/* Set RTS/CTS flow control. */
argument|outb(com->esp_port + ESP_CMD1, ESP_SETFLOWTYPE); 		outb(com->esp_port + ESP_CMD2, ESP_FLOW_RTS); 		outb(com->esp_port + ESP_CMD2, ESP_FLOW_CTS);
comment|/* Set flow-control levels. */
argument|outb(com->esp_port + ESP_CMD1, ESP_SETRXFLOW); 		outb(com->esp_port + ESP_CMD2, HIBYTE(
literal|768
argument|)); 		outb(com->esp_port + ESP_CMD2, LOBYTE(
literal|768
argument|)); 		outb(com->esp_port + ESP_CMD2, HIBYTE(
literal|512
argument|)); 		outb(com->esp_port + ESP_CMD2, LOBYTE(
literal|512
argument|)); 	}
endif|#
directive|endif
comment|/* COM_ESP */
argument|outb(iobase + com_fifo,
literal|0
argument|); determined_type: ;
ifdef|#
directive|ifdef
name|COM_MULTIPORT
argument|if (COM_ISMULTIPORT(isdp)) { 		com->multiport = TRUE; 		printf(
literal|" (multiport"
argument|); 		if (unit == COM_MPMASTER(isdp)) 			printf(
literal|" master"
argument|); 		printf(
literal|")"
argument|);
ifdef|#
directive|ifdef
name|PC98
argument|com->no_irq = find_pc98dev(pc98_devtab_tty,&siodriver,
else|#
directive|else
argument|com->no_irq = find_isadev(isa_devtab_tty,&siodriver,
endif|#
directive|endif
argument|COM_MPMASTER(isdp))->id_irq ==
literal|0
argument|; 	 }
endif|#
directive|endif
comment|/* COM_MULTIPORT */
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|printf(
literal|"\n"
argument|);  	kdc_sio[unit].kdc_state = (unit == comconsole) ? DC_BUSY : DC_IDLE;  	s = spltty(); 	com_addr(unit) = com; 	splx(s);  	dev = makedev(CDEV_MAJOR,
literal|0
argument|); 	cdevsw_add(&dev,&sio_cdevsw, NULL);
ifdef|#
directive|ifdef
name|DEVFS
comment|/* devsw, minor, type, uid, gid, perm, fmt, ... */
argument|com->devfs_token_ttyd = devfs_add_devswf(&sio_cdevsw, 		unit, DV_CHR, 		UID_ROOT, GID_WHEEL,
literal|0600
argument|,
literal|"ttyd%n"
argument|, unit); 	com->devfs_token_ttyi = devfs_add_devswf(&sio_cdevsw, 		unit | CONTROL_INIT_STATE, DV_CHR, 		UID_ROOT, GID_WHEEL,
literal|0600
argument|,
literal|"ttyid%n"
argument|, unit); 	com->devfs_token_ttyl = devfs_add_devswf(&sio_cdevsw, 		unit | CONTROL_LOCK_STATE, DV_CHR, 		UID_ROOT, GID_WHEEL,
literal|0600
argument|,
literal|"ttyld%n"
argument|, unit); 	com->devfs_token_cuaa = devfs_add_devswf(&sio_cdevsw, 		unit | CALLOUT_MASK, DV_CHR, 		UID_UUCP, GID_DIALER,
literal|0660
argument|,
literal|"cuaa%n"
argument|, unit); 	com->devfs_token_cuai = devfs_add_devswf(&sio_cdevsw, 		unit | CALLOUT_MASK | CONTROL_INIT_STATE, DV_CHR, 		UID_UUCP, GID_DIALER,
literal|0660
argument|,
literal|"cuaia%n"
argument|, unit); 	com->devfs_token_cual = devfs_add_devswf(&sio_cdevsw, 		unit | CALLOUT_MASK | CONTROL_LOCK_STATE, DV_CHR, 		UID_UUCP, GID_DIALER,
literal|0660
argument|,
literal|"cuala%n"
argument|, unit);
endif|#
directive|endif
argument|return (
literal|1
argument|); }  static int sioopen(dev, flag, mode, p) 	dev_t		dev; 	int		flag; 	int		mode; 	struct proc	*p; { 	struct com_s	*com; 	int		error; 	Port_t		iobase; 	int		mynor; 	int		s; 	struct tty	*tp; 	int		unit;  	mynor = minor(dev); 	unit = MINOR_TO_UNIT(mynor); 	if ((u_int) unit>= NSIO || (com = com_addr(unit)) == NULL) 		return (ENXIO); 	if (com->gone) 		return (ENXIO); 	if (mynor& CONTROL_MASK) 		return (
literal|0
argument|);
if|#
directive|if
literal|0
comment|/* XXX */
argument|tp = com->tp = sio_tty[unit] = ttymalloc(sio_tty[unit]);
else|#
directive|else
argument|tp = com->tp =&sio_tty[unit];
endif|#
directive|endif
argument|s = spltty();
comment|/* 	 * We jump to this label after all non-interrupted sleeps to pick 	 * up any changes of the device state. 	 */
argument|open_top: 	while (com->state& CS_DTR_OFF) { 		error = tsleep(&com->dtr_wait, TTIPRI | PCATCH,
literal|"siodtr"
argument|,
literal|0
argument|); 		if (com_addr(unit) == NULL) 			return (ENXIO); 		if (error !=
literal|0
argument||| com->gone) 			goto out; 	} 	kdc_sio[unit].kdc_state = DC_BUSY; 	if (tp->t_state& TS_ISOPEN) {
comment|/* 		 * The device is open, so everything has been initialized. 		 * Handle conflicts. 		 */
argument|if (mynor& CALLOUT_MASK) { 			if (!com->active_out) { 				error = EBUSY; 				goto out; 			} 		} else { 			if (com->active_out) { 				if (flag& O_NONBLOCK) { 					error = EBUSY; 					goto out; 				} 				error =	tsleep(&com->active_out, 					       TTIPRI | PCATCH,
literal|"siobi"
argument|,
literal|0
argument|); 				if (com_addr(unit) == NULL) 					return (ENXIO); 				if (error !=
literal|0
argument||| com->gone) 					goto out; 				goto open_top; 			} 		} 		if (tp->t_state& TS_XCLUDE&& p->p_ucred->cr_uid !=
literal|0
argument|) { 			error = EBUSY; 			goto out; 		} 	} else {
comment|/* 		 * The device isn't open, so there are no conflicts. 		 * Initialize it.  Initialization is done twice in many 		 * cases: to preempt sleeping callin opens if we are 		 * callout, and to complete a callin open after DCD rises. 		 */
argument|tp->t_oproc = comstart; 		tp->t_param = comparam; 		tp->t_dev = dev; 		tp->t_termios = mynor& CALLOUT_MASK 				? com->it_out : com->it_in;
ifdef|#
directive|ifdef
name|PC98
argument|if(!IS_8251(com->pc98_if_type))
endif|#
directive|endif
argument|(void)commctl(com, TIOCM_DTR | TIOCM_RTS, DMSET); 		com->poll = com->no_irq; 		com->poll_output = com->loses_outints; 		++com->wopeners; 		error = comparam(tp,&tp->t_termios); 		--com->wopeners; 		if (error !=
literal|0
argument|) 			goto out;
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 			com_tiocm_bis(com, TIOCM_DTR|TIOCM_RTS); 			pc98_msrint_start(dev); 		}
endif|#
directive|endif
comment|/* 		 * XXX we should goto open_top if comparam() slept. 		 */
argument|ttsetwater(tp); 		iobase = com->iobase; 		if (com->hasfifo) {
comment|/* 			 * (Re)enable and drain fifos. 			 * 			 * Certain SMC chips cause problems if the fifos 			 * are enabled while input is ready.  Turn off the 			 * fifo if necessary to clear the input.  We test 			 * the input ready bit after enabling the fifos 			 * since we've already enabled them in comparam() 			 * and to handle races between enabling and fresh 			 * input. 			 */
argument|while (TRUE) { 				outb(iobase + com_fifo, 				     FIFO_RCV_RST | FIFO_XMT_RST 				     | com->fifo_image); 				DELAY(
literal|100
argument|); 				if (!(inb(com->line_status_port)& LSR_RXRDY)) 					break; 				outb(iobase + com_fifo,
literal|0
argument|); 				DELAY(
literal|100
argument|); 				(void) inb(com->data_port); 			} 		}  		disable_intr();
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 			com_tiocm_bis(com, TIOCM_LE); 			com->pc98_prev_modem_status = 				pc98_get_modem_status(com); 			com_int_Rx_enable(com); 		} else {
endif|#
directive|endif
argument|(void) inb(com->line_status_port); 		(void) inb(com->data_port); 		com->prev_modem_status = com->last_modem_status 		    = inb(com->modem_status_port); 		outb(iobase + com_ier, IER_ERXRDY | IER_ETXRDY | IER_ERLS 				       | IER_EMSC);
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|enable_intr();
comment|/* 		 * Handle initial DCD.  Callout devices get a fake initial 		 * DCD (trapdoor DCD).  If we are callout, then any sleeping 		 * callin opens get woken up and resume sleeping on "siobi" 		 * instead of "siodcd". 		 */
comment|/* 		 * XXX `mynor& CALLOUT_MASK' should be 		 * `tp->t_cflag& (SOFT_CARRIER | TRAPDOOR_CARRIER) where 		 * TRAPDOOR_CARRIER is the default initial state for callout 		 * devices and SOFT_CARRIER is like CLOCAL except it hides 		 * the true carrier. 		 */
ifdef|#
directive|ifdef
name|PC98
argument|if ((IS_8251(com->pc98_if_type)&& 			(pc98_get_modem_status(com)& TIOCM_CAR)) || 		    (!IS_8251(com->pc98_if_type)&& 			(com->prev_modem_status& MSR_DCD)) || 		    mynor& CALLOUT_MASK)
else|#
directive|else
argument|if (com->prev_modem_status& MSR_DCD || mynor& CALLOUT_MASK)
endif|#
directive|endif
argument|(*linesw[tp->t_line].l_modem)(tp,
literal|1
argument|); 	}
comment|/* 	 * Wait for DCD if necessary. 	 */
argument|if (!(tp->t_state& TS_CARR_ON)&& !(mynor& CALLOUT_MASK)&& !(tp->t_cflag& CLOCAL)&& !(flag& O_NONBLOCK)) { 		++com->wopeners; 		error = tsleep(TSA_CARR_ON(tp), TTIPRI | PCATCH,
literal|"siodcd"
argument|,
literal|0
argument|); 		if (com_addr(unit) == NULL) 			return (ENXIO); 		--com->wopeners; 		if (error !=
literal|0
argument||| com->gone) 			goto out; 		goto open_top; 	} 	error =	(*linesw[tp->t_line].l_open)(dev, tp); 	disc_optim(tp,&tp->t_termios, com); 	if (tp->t_state& TS_ISOPEN&& mynor& CALLOUT_MASK) 		com->active_out = TRUE; 	siosettimeout(); out: 	splx(s); 	if (!(tp->t_state& TS_ISOPEN)&& com->wopeners ==
literal|0
argument|) 		comhardclose(com); 	return (error); }  static int sioclose(dev, flag, mode, p) 	dev_t		dev; 	int		flag; 	int		mode; 	struct proc	*p; { 	struct com_s	*com; 	int		mynor; 	int		s; 	struct tty	*tp;  	mynor = minor(dev); 	if (mynor& CONTROL_MASK) 		return (
literal|0
argument|); 	com = com_addr(MINOR_TO_UNIT(mynor)); 	tp = com->tp; 	s = spltty(); 	(*linesw[tp->t_line].l_close)(tp, flag);
ifdef|#
directive|ifdef
name|PC98
argument|com->modem_checking =
literal|0
argument|;
endif|#
directive|endif
argument|disc_optim(tp,&tp->t_termios, com); 	siostop(tp, FREAD | FWRITE); 	comhardclose(com); 	ttyclose(tp); 	siosettimeout(); 	splx(s); 	if (com->gone) { 		printf(
literal|"sio%d: gone\n"
argument|, com->unit); 		s = spltty(); 		com_addr(com->unit) =
literal|0
argument|; 		bzero(tp,sizeof *tp); 		bzero(com,sizeof *com); 		free(com,M_TTYS); 		splx(s); 	} 	return (
literal|0
argument|); }  static void comhardclose(com) 	struct com_s	*com; { 	Port_t		iobase; 	int		s; 	struct tty	*tp; 	int		unit;  	unit = com->unit; 	iobase = com->iobase; 	s = spltty(); 	com->poll = FALSE; 	com->poll_output = FALSE; 	com->do_timestamp =
literal|0
argument|;
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 		com_send_break_off(com); 	else
endif|#
directive|endif
argument|outb(iobase + com_cfcr, com->cfcr_image&= ~CFCR_SBREAK); 	{
ifdef|#
directive|ifdef
name|PC98
argument|int tmp; 		if(IS_8251(com->pc98_if_type)) 			com_int_TxRx_disable(com); 		else
endif|#
directive|endif
argument|outb(iobase + com_ier,
literal|0
argument|); 		tp = com->tp;
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 			tmp = pc98_get_modem_status(com)& TIOCM_CAR; 		else 			tmp = com->prev_modem_status& MSR_DCD;
endif|#
directive|endif
argument|if (tp->t_cflag& HUPCL
comment|/* 		     * XXX we will miss any carrier drop between here and the 		     * next open.  Perhaps we should watch DCD even when the 		     * port is closed; it is not sufficient to check it at 		     * the next open because it might go up and down while 		     * we're not watching. 		     */
argument||| !com->active_out
ifdef|#
directive|ifdef
name|PC98
argument|&& !(tmp)
else|#
directive|else
argument|&& !(com->prev_modem_status& MSR_DCD)
endif|#
directive|endif
argument|&& !(com->it_in.c_cflag& CLOCAL) 		    || !(tp->t_state& TS_ISOPEN)) {
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				com_tiocm_bic(com, TIOCM_DTR|TIOCM_RTS|TIOCM_LE); 			else
endif|#
directive|endif
argument|(void)commctl(com, TIOCM_DTR, DMBIC); 			if (com->dtr_wait !=
literal|0
argument|) { 				timeout(siodtrwakeup, com, com->dtr_wait); 				com->state |= CS_DTR_OFF; 			} 		}
ifdef|#
directive|ifdef
name|PC98
argument|else { 			if(IS_8251(com->pc98_if_type)) 				com_tiocm_bic(com, TIOCM_LE ); 		}
endif|#
directive|endif
argument|} 	if (com->hasfifo) {
comment|/* 		 * Disable fifos so that they are off after controlled 		 * reboots.  Some BIOSes fail to detect 16550s when the 		 * fifos are enabled. 		 */
argument|outb(iobase + com_fifo,
literal|0
argument|); 	} 	com->active_out = FALSE; 	wakeup(&com->active_out); 	wakeup(TSA_CARR_ON(tp));
comment|/* restart any wopeners */
argument|if (!(com->state& CS_DTR_OFF)&& unit != comconsole) 		kdc_sio[unit].kdc_state = DC_IDLE; 	splx(s); }  static int sioread(dev, uio, flag) 	dev_t		dev; 	struct uio	*uio; 	int		flag; { 	int		mynor; 	int		unit; 	struct tty	*tp;  	mynor = minor(dev); 	if (mynor& CONTROL_MASK) 		return (ENODEV); 	unit = MINOR_TO_UNIT(mynor); 	if (com_addr(unit)->gone) 		return (ENODEV); 	tp = com_addr(unit)->tp; 	return ((*linesw[tp->t_line].l_read)(tp, uio, flag)); }  static int siowrite(dev, uio, flag) 	dev_t		dev; 	struct uio	*uio; 	int		flag; { 	int		mynor; 	struct tty	*tp; 	int		unit;  	mynor = minor(dev); 	if (mynor& CONTROL_MASK) 		return (ENODEV);  	unit = MINOR_TO_UNIT(mynor); 	if (com_addr(unit)->gone) 		return (ENODEV); 	tp = com_addr(unit)->tp;
comment|/* 	 * (XXX) We disallow virtual consoles if the physical console is 	 * a serial port.  This is in case there is a display attached that 	 * is not the console.  In that situation we don't need/want the X 	 * server taking over the console. 	 */
argument|if (constty != NULL&& unit == comconsole) 		constty = NULL; 	return ((*linesw[tp->t_line].l_write)(tp, uio, flag)); }  static void siodtrwakeup(chan) 	void	*chan; { 	struct com_s	*com;  	com = (struct com_s *)chan; 	com->state&= ~CS_DTR_OFF; 	if (com->unit != comconsole) 		kdc_sio[com->unit].kdc_state = DC_IDLE; 	wakeup(&com->dtr_wait); }  void siointr(unit) 	int	unit; {
ifndef|#
directive|ifndef
name|COM_MULTIPORT
argument|siointr1(com_addr(unit));
else|#
directive|else
comment|/* COM_MULTIPORT */
argument|struct com_s    *com; 	bool_t		possibly_more_intrs;
comment|/* 	 * Loop until there is no activity on any port.  This is necessary 	 * to get an interrupt edge more than to avoid another interrupt. 	 * If the IRQ signal is just an OR of the IRQ signals from several 	 * devices, then the edge from one may be lost because another is 	 * on. 	 */
argument|do { 		possibly_more_intrs = FALSE; 		for (unit =
literal|0
argument|; unit< NSIO; ++unit) { 			com = com_addr(unit);
ifdef|#
directive|ifdef
name|PC98
argument|if (com != NULL&& !com->gone&& IS_8251(com->pc98_if_type)){ 				siointr1(com); 			} else
endif|#
directive|endif
comment|/* PC98 */
argument|if (com != NULL&& !com->gone&& (inb(com->int_id_port)& IIR_IMASK) 			       != IIR_NOPEND) { 				siointr1(com); 				possibly_more_intrs = TRUE; 			} 		} 	} while (possibly_more_intrs);
endif|#
directive|endif
comment|/* COM_MULTIPORT */
argument|}  static void siointr1(com) 	struct com_s	*com; { 	u_char	line_status; 	u_char	modem_status; 	u_char	*ioptr; 	u_char	recv_data;
ifdef|#
directive|ifdef
name|PC98
argument|u_char	tmp=
literal|0
argument|; recv_data=
literal|0
argument|;
endif|#
directive|endif
comment|/* PC98 */
argument|while (TRUE) {
ifdef|#
directive|ifdef
name|PC98
argument|status_read:; 		if (IS_8251(com->pc98_if_type)) { 			tmp = inb(com->sts_port); more_intr: 			line_status =
literal|0
argument|; 			if (tmp& STS8251_TxRDY) line_status |= LSR_TXRDY; 			if (tmp& STS8251_RxRDY) line_status |= LSR_RXRDY; 			if (tmp& STS8251_TxEMP) line_status |= LSR_TSRE; 			if (tmp& STS8251_PE)    line_status |= LSR_PE; 			if (tmp& STS8251_OE)    line_status |= LSR_OE; 			if (tmp& STS8251_FE)    line_status |= LSR_FE; 			if (tmp& STS8251_BD_SD) line_status |= LSR_BI; 		} else
endif|#
directive|endif
comment|/* PC98 */
argument|line_status = inb(com->line_status_port);
comment|/* input event? (check first to help avoid overruns) */
argument|while (line_status& LSR_RCV_MASK) {
comment|/* break/unnattached error bits or real input? */
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 				recv_data = inb(com->data_port); 				if(tmp&
literal|0x78
argument|){ 					pc98_i8251_or_cmd(com,CMD8251_ER); 					recv_data =
literal|0
argument|; 				} 			} else {
endif|#
directive|endif
comment|/* PC98 */
argument|if (!(line_status& LSR_RXRDY)) 				recv_data =
literal|0
argument|; 			else 				recv_data = inb(com->data_port);
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|if (line_status& (LSR_PE|LSR_FE|LSR_BI)) {
ifdef|#
directive|ifdef
name|DDB
ifdef|#
directive|ifdef
name|BREAK_TO_DEBUGGER
argument|if (line_status& LSR_BI&& com->unit == comconsole)	{ 					Debugger(
literal|"serial console break"
argument|); 					goto cont; 				}
endif|#
directive|endif
endif|#
directive|endif
comment|/* 				  Don't store PE if IGNPAR and BI if IGNBRK, 				  this hack allows "raw" tty optimization 				  works even if IGN* is set. 				*/
argument|if (   com->tp == NULL 				    || !(com->tp->t_state& TS_ISOPEN) 				    || (line_status& (LSR_PE|LSR_FE))&&  (com->tp->t_iflag& IGNPAR) 				    || (line_status& LSR_BI)&&  (com->tp->t_iflag& IGNBRK)) 					goto cont; 				if (   (line_status& (LSR_PE|LSR_FE))&& (com->tp->t_state& TS_CAN_BYPASS_L_RINT)&& ((line_status& LSR_FE) 				    ||  (line_status& LSR_PE)&&  (com->tp->t_iflag& INPCK))) 					recv_data =
literal|0
argument|; 			}  			++com->bytes_in; 			if (com->hotchar !=
literal|0
argument|&& recv_data == com->hotchar) 				setsofttty(); 			ioptr = com->iptr; 			if (ioptr>= com->ibufend) 				CE_RECORD(com, CE_INTERRUPT_BUF_OVERFLOW); 			else { 				if (com->do_timestamp) 					microtime(&com->timestamp); 				++com_events; 				schedsofttty();
if|#
directive|if
literal|0
comment|/* for testing input latency vs efficiency */
argument|if (com->iptr - com->ibuf == 8) 	setsofttty();
endif|#
directive|endif
argument|ioptr[
literal|0
argument|] = recv_data; 				ioptr[CE_INPUT_OFFSET] = line_status; 				com->iptr = ++ioptr; 				if (ioptr == com->ihighwater&& com->state& CS_RTS_IFLOW)
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 						com_tiocm_bic(com, TIOCM_RTS); 					else
endif|#
directive|endif
argument|outb(com->modem_ctl_port, 					     com->mcr_image&= ~MCR_RTS); 				if (line_status& LSR_OE) 					CE_RECORD(com, CE_OVERRUN); 			} cont:
comment|/* 			 * "& 0x7F" is to avoid the gcc-1.40 generating a slow 			 * jump from the top of the loop to here 			 */
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				goto status_read; 			else
endif|#
directive|endif
argument|line_status = inb(com->line_status_port)&
literal|0x7F
argument|; 		}
comment|/* modem status change? (always check before doing output) */
ifdef|#
directive|ifdef
name|PC98
argument|if(!IS_8251(com->pc98_if_type)){
endif|#
directive|endif
argument|modem_status = inb(com->modem_status_port); 		if (modem_status != com->last_modem_status) { 			if (com->do_dcd_timestamp&& !(com->last_modem_status& MSR_DCD)&& modem_status& MSR_DCD) 				microtime(&com->dcd_timestamp);
comment|/* 			 * Schedule high level to handle DCD changes.  Note 			 * that we don't use the delta bits anywhere.  Some 			 * UARTs mess them up, and it's easy to remember the 			 * previous bits and calculate the delta. 			 */
argument|com->last_modem_status = modem_status; 			if (!(com->state& CS_CHECKMSR)) { 				com_events += LOTS_OF_EVENTS; 				com->state |= CS_CHECKMSR; 				setsofttty(); 			}
comment|/* handle CTS change immediately for crisp flow ctl */
argument|if (com->state& CS_CTS_OFLOW) { 				if (modem_status& MSR_CTS) 					com->state |= CS_ODEVREADY; 				else 					com->state&= ~CS_ODEVREADY; 			} 		}
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
comment|/* output queued and everything ready? */
argument|if (line_status& LSR_TXRDY&& com->state>= (CS_BUSY | CS_TTGO | CS_ODEVREADY)) { 			ioptr = com->obufq.l_head; 			if (com->tx_fifo_size>
literal|1
argument|) { 				u_int	ocount;  				ocount = com->obufq.l_tail - ioptr; 				if (ocount> com->tx_fifo_size) 					ocount = com->tx_fifo_size; 				com->bytes_out += ocount; 				do 					outb(com->data_port, *ioptr++); 				while (--ocount !=
literal|0
argument|); 			} else { 				outb(com->data_port, *ioptr++); 				++com->bytes_out; 			}
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				if ( !(pc98_check_i8251_interrupt(com)& IEN_TxFLAG) ) 					com_int_Tx_enable(com);
endif|#
directive|endif
argument|com->obufq.l_head = ioptr; 			if (ioptr>= com->obufq.l_tail) { 				struct lbq	*qp;  				qp = com->obufq.l_next; 				qp->l_queued = FALSE; 				qp = qp->l_next; 				if (qp != NULL) { 					com->obufq.l_head = qp->l_head; 					com->obufq.l_tail = qp->l_tail; 					com->obufq.l_next = qp; 				} else {
comment|/* output just completed */
argument|com->state&= ~CS_BUSY;
if|#
directive|if
name|defined
argument_list|(
name|PC98
argument_list|)
argument|if(IS_8251(com->pc98_if_type)) 						if ( pc98_check_i8251_interrupt(com)& IEN_TxFLAG ) 							com_int_Tx_disable(com);
endif|#
directive|endif
argument|} 				if (!(com->state& CS_ODONE)) { 					com_events += LOTS_OF_EVENTS; 					com->state |= CS_ODONE; 					setsofttty();
comment|/* handle at high level ASAP */
argument|} 			} 		}
ifdef|#
directive|ifdef
name|PC98
argument|else if (line_status& LSR_TXRDY) { 			if(IS_8251(com->pc98_if_type)) 				if ( pc98_check_i8251_interrupt(com)& IEN_TxFLAG ) 					com_int_Tx_disable(com); 		} 		if(IS_8251(com->pc98_if_type)) 			if ((tmp = inb(com->sts_port))& STS8251_RxRDY) 				goto more_intr;
endif|#
directive|endif
comment|/* finished? */
ifndef|#
directive|ifndef
name|COM_MULTIPORT
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 			return;
endif|#
directive|endif
argument|if ((inb(com->int_id_port)& IIR_IMASK) == IIR_NOPEND)
endif|#
directive|endif
comment|/* COM_MULTIPORT */
argument|return; 	} }  static int sioioctl(dev, cmd, data, flag, p) 	dev_t		dev; 	int		cmd; 	caddr_t		data; 	int		flag; 	struct proc	*p; { 	struct com_s	*com; 	int		error; 	Port_t		iobase; 	int		mynor; 	int		s; 	struct tty	*tp;
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
argument|int		oldcmd; 	struct termios	term;
endif|#
directive|endif
argument|mynor = minor(dev); 	com = com_addr(MINOR_TO_UNIT(mynor)); 	if (com->gone) 		return (ENODEV); 	iobase = com->iobase; 	if (mynor& CONTROL_MASK) { 		struct termios	*ct;  		switch (mynor& CONTROL_MASK) { 		case CONTROL_INIT_STATE: 			ct = mynor& CALLOUT_MASK ?&com->it_out :&com->it_in; 			break; 		case CONTROL_LOCK_STATE: 			ct = mynor& CALLOUT_MASK ?&com->lt_out :&com->lt_in; 			break; 		default: 			return (ENODEV);
comment|/* /dev/nodev */
argument|} 		switch (cmd) { 		case TIOCSETA: 			error = suser(p->p_ucred,&p->p_acflag); 			if (error !=
literal|0
argument|) 				return (error); 			*ct = *(struct termios *)data; 			return (
literal|0
argument|); 		case TIOCGETA: 			*(struct termios *)data = *ct; 			return (
literal|0
argument|); 		case TIOCGETD: 			*(int *)data = TTYDISC; 			return (
literal|0
argument|); 		case TIOCGWINSZ: 			bzero(data, sizeof(struct winsize)); 			return (
literal|0
argument|);
ifdef|#
directive|ifdef
name|DSI_SOFT_MODEM
comment|/* 		 * Download micro-code to Digicom modem. 		 */
argument|case TIOCDSIMICROCODE: 			{ 			u_long l; 			u_char *p,*pi;  			pi = (u_char*)(*(caddr_t*)data); 			error = copyin(pi,&l,sizeof l); 			if(error) 				{return error;}; 			pi += sizeof l;  			p = malloc(l,M_TEMP,M_NOWAIT); 			if(!p) 				{return ENOBUFS;} 			error = copyin(pi,p,l); 			if(error) 				{free(p,M_TEMP); return error;}; 			if(error = LoadSoftModem( 			    MINOR_TO_UNIT(mynor),iobase,l,p)) 				{free(p,M_TEMP); return error;} 			free(p,M_TEMP); 			return(
literal|0
argument|); 			}
endif|#
directive|endif
comment|/* DSI_SOFT_MODEM */
argument|default: 			return (ENOTTY); 		} 	} 	tp = com->tp;
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
argument|term = tp->t_termios; 	oldcmd = cmd; 	error = ttsetcompat(tp,&cmd, data,&term); 	if (error !=
literal|0
argument|) 		return (error); 	if (cmd != oldcmd) 		data = (caddr_t)&term;
endif|#
directive|endif
argument|if (cmd == TIOCSETA || cmd == TIOCSETAW || cmd == TIOCSETAF) { 		int	cc; 		struct termios *dt = (struct termios *)data; 		struct termios *lt = mynor& CALLOUT_MASK 				     ?&com->lt_out :&com->lt_in;  		dt->c_iflag = (tp->t_iflag& lt->c_iflag) 			      | (dt->c_iflag& ~lt->c_iflag); 		dt->c_oflag = (tp->t_oflag& lt->c_oflag) 			      | (dt->c_oflag& ~lt->c_oflag); 		dt->c_cflag = (tp->t_cflag& lt->c_cflag) 			      | (dt->c_cflag& ~lt->c_cflag); 		dt->c_lflag = (tp->t_lflag& lt->c_lflag) 			      | (dt->c_lflag& ~lt->c_lflag); 		for (cc =
literal|0
argument|; cc< NCCS; ++cc) 			if (lt->c_cc[cc] !=
literal|0
argument|) 				dt->c_cc[cc] = tp->t_cc[cc]; 		if (lt->c_ispeed !=
literal|0
argument|) 			dt->c_ispeed = tp->t_ispeed; 		if (lt->c_ospeed !=
literal|0
argument|) 			dt->c_ospeed = tp->t_ospeed; 	} 	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag, p); 	if (error>=
literal|0
argument|) 		return (error); 	s = spltty(); 	error = ttioctl(tp, cmd, data, flag); 	disc_optim(tp,&tp->t_termios, com); 	if (error>=
literal|0
argument|) { 		splx(s); 		return (error); 	}
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 	switch (cmd) { 	case TIOCSBRK: 		com_send_break_on( com ); 		break; 	case TIOCCBRK: 		com_send_break_off( com ); 		break; 	case TIOCSDTR: 		(void)commctl(com, TIOCM_DTR, DMBIS); 		break; 	case TIOCCDTR: 		(void)commctl(com, TIOCM_DTR, DMBIC); 		break; 	case TIOCMSET: 		(void)commctl(com, *(int *)data, DMSET); 		break; 	case TIOCMBIS: 		(void)commctl(com, *(int *)data, DMBIS); 		break; 	case TIOCMBIC: 		(void)commctl(com, *(int *)data, DMBIC); 		break; 	case TIOCMGET: 		*(int *)data = commctl(com,
literal|0
argument|, DMGET); 		break; 	case TIOCMSDTRWAIT:
comment|/* must be root since the wait applies to following logins */
argument|error = suser(p->p_ucred,&p->p_acflag); 		if (error !=
literal|0
argument|) { 			splx(s); 			return (error); 		} 		com->dtr_wait = *(int *)data * hz /
literal|100
argument|; 		break; 	case TIOCMGDTRWAIT: 		*(int *)data = com->dtr_wait *
literal|100
argument|/ hz; 		break; 	case TIOCTIMESTAMP: 		com->do_timestamp = TRUE; 		*(struct timeval *)data = com->timestamp; 		break; 	case TIOCDCDTIMESTAMP: 		com->do_dcd_timestamp = TRUE; 		*(struct timeval *)data = com->dcd_timestamp; 		break; 	default: 		splx(s); 		return (ENOTTY); 	} 	} else {
endif|#
directive|endif
argument|switch (cmd) { 	case TIOCSBRK: 		outb(iobase + com_cfcr, com->cfcr_image |= CFCR_SBREAK); 		break; 	case TIOCCBRK: 		outb(iobase + com_cfcr, com->cfcr_image&= ~CFCR_SBREAK); 		break; 	case TIOCSDTR: 		(void)commctl(com, TIOCM_DTR, DMBIS); 		break; 	case TIOCCDTR: 		(void)commctl(com, TIOCM_DTR, DMBIC); 		break; 	case TIOCMSET: 		(void)commctl(com, *(int *)data, DMSET); 		break; 	case TIOCMBIS: 		(void)commctl(com, *(int *)data, DMBIS); 		break; 	case TIOCMBIC: 		(void)commctl(com, *(int *)data, DMBIC); 		break; 	case TIOCMGET: 		*(int *)data = commctl(com,
literal|0
argument|, DMGET); 		break; 	case TIOCMSDTRWAIT:
comment|/* must be root since the wait applies to following logins */
argument|error = suser(p->p_ucred,&p->p_acflag); 		if (error !=
literal|0
argument|) { 			splx(s); 			return (error); 		} 		com->dtr_wait = *(int *)data * hz /
literal|100
argument|; 		break; 	case TIOCMGDTRWAIT: 		*(int *)data = com->dtr_wait *
literal|100
argument|/ hz; 		break; 	case TIOCTIMESTAMP: 		com->do_timestamp = TRUE; 		*(struct timeval *)data = com->timestamp; 		break; 	default: 		splx(s); 		return (ENOTTY); 	}
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|splx(s); 	return (
literal|0
argument|); }  void siopoll() { 	int		unit;  	if (com_events ==
literal|0
argument|) 		return; repeat: 	for (unit =
literal|0
argument|; unit< NSIO; ++unit) { 		u_char		*buf; 		struct com_s	*com; 		u_char		*ibuf; 		int		incc; 		struct tty	*tp;
ifdef|#
directive|ifdef
name|PC98
argument|int		tmp;
endif|#
directive|endif
argument|com = com_addr(unit); 		if (com == NULL) 			continue; 		if (com->gone) 			continue; 		tp = com->tp; 		if (tp == NULL) {
comment|/* 			 * XXX forget any events related to closed devices 			 * (actually never opened devices) so that we don't 			 * loop. 			 */
argument|disable_intr(); 			incc = com->iptr - com->ibuf; 			com->iptr = com->ibuf; 			if (com->state& CS_CHECKMSR) { 				incc += LOTS_OF_EVENTS; 				com->state&= ~CS_CHECKMSR; 			} 			com_events -= incc; 			enable_intr(); 			if (incc !=
literal|0
argument|) 				log(LOG_DEBUG,
literal|"sio%d: %d events for device with no tp\n"
argument|, 				    unit, incc); 			continue; 		}
comment|/* switch the role of the low-level input buffers */
argument|if (com->iptr == (ibuf = com->ibuf)) { 			buf = NULL;
comment|/* not used, but compiler can't tell */
argument|incc =
literal|0
argument|; 		} else { 			buf = ibuf; 			disable_intr(); 			incc = com->iptr - buf; 			com_events -= incc; 			if (ibuf == com->ibuf1) 				ibuf = com->ibuf2; 			else 				ibuf = com->ibuf1; 			com->ibufend = ibuf + RS_IBUFSIZE; 			com->ihighwater = ibuf + RS_IHIGHWATER; 			com->iptr = ibuf;
comment|/* 			 * There is now room for another low-level buffer full 			 * of input, so enable RTS if it is now disabled and 			 * there is room in the high-level buffer. 			 */
comment|/* 			 * XXX this used not to look at CS_RTS_IFLOW.  The 			 * change is to allow full control of MCR_RTS via 			 * ioctls after turning CS_RTS_IFLOW off.  Check 			 * for races.  We shouldn't allow the ioctls while 			 * CS_RTS_IFLOW is on. 			 */
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				tmp = com_tiocm_get(com)& TIOCM_RTS; 			else 				tmp = com->mcr_image& MCR_RTS;
endif|#
directive|endif
argument|if ((com->state& CS_RTS_IFLOW)
ifdef|#
directive|ifdef
name|PC98
argument|&& !(tmp)
else|#
directive|else
argument|&& !(com->mcr_image& MCR_RTS)
endif|#
directive|endif
argument|&& !(tp->t_state& TS_TBLOCK))
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 					com_tiocm_bis(com, TIOCM_RTS); 				else
endif|#
directive|endif
argument|outb(com->modem_ctl_port, 				     com->mcr_image |= MCR_RTS); 			enable_intr(); 			com->ibuf = ibuf; 		}  		if (com->state& CS_CHECKMSR) { 			u_char	delta_modem_status;
ifdef|#
directive|ifdef
name|PC98
argument|if(!IS_8251(com->pc98_if_type)){
endif|#
directive|endif
argument|disable_intr(); 			delta_modem_status = com->last_modem_status 					     ^ com->prev_modem_status; 			com->prev_modem_status = com->last_modem_status; 			com_events -= LOTS_OF_EVENTS; 			com->state&= ~CS_CHECKMSR; 			enable_intr(); 			if (delta_modem_status& MSR_DCD) 				(*linesw[tp->t_line].l_modem) 					(tp, com->prev_modem_status& MSR_DCD);
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|} 		if (com->state& CS_ODONE) { 			disable_intr(); 			com_events -= LOTS_OF_EVENTS; 			com->state&= ~CS_ODONE; 			if (!(com->state& CS_BUSY)) 				com->tp->t_state&= ~TS_BUSY; 			enable_intr(); 			(*linesw[tp->t_line].l_start)(tp); 		} 		if (incc<=
literal|0
argument||| !(tp->t_state& TS_ISOPEN)) 			continue;
comment|/* 		 * Avoid the grotesquely inefficient lineswitch routine 		 * (ttyinput) in "raw" mode.  It usually takes about 450 		 * instructions (that's without canonical processing or echo!). 		 * slinput is reasonably fast (usually 40 instructions plus 		 * call overhead). 		 */
argument|if (tp->t_state& TS_CAN_BYPASS_L_RINT) { 			if (tp->t_rawq.c_cc + incc>= RB_I_HIGH_WATER&& (com->state& CS_RTS_IFLOW 				|| tp->t_iflag& IXOFF)&& !(tp->t_state& TS_TBLOCK)) 				ttyblock(tp); 			tk_nin += incc; 			tk_rawcc += incc; 			tp->t_rawcc += incc; 			com->delta_error_counts[CE_TTY_BUF_OVERFLOW] 				+= b_to_q((char *)buf, incc,&tp->t_rawq); 			ttwakeup(tp); 			if (tp->t_state& TS_TTSTOP&& (tp->t_iflag& IXANY 				|| tp->t_cc[VSTART] == tp->t_cc[VSTOP])) { 				tp->t_state&= ~TS_TTSTOP; 				tp->t_lflag&= ~FLUSHO; 				comstart(tp); 			} 		} else { 			do { 				u_char	line_status; 				int	recv_data;  				line_status = (u_char) buf[CE_INPUT_OFFSET]; 				recv_data = (u_char) *buf++; 				if (line_status& (LSR_BI | LSR_FE | LSR_OE | LSR_PE)) { 					if (line_status& LSR_BI) 						recv_data |= TTY_BI; 					if (line_status& LSR_FE) 						recv_data |= TTY_FE; 					if (line_status& LSR_OE) 						recv_data |= TTY_OE; 					if (line_status& LSR_PE) 						recv_data |= TTY_PE; 				} 				(*linesw[tp->t_line].l_rint)(recv_data, tp); 			} while (--incc>
literal|0
argument|); 		} 		if (com_events ==
literal|0
argument|) 			break; 	} 	if (com_events>= LOTS_OF_EVENTS) 		goto repeat; }  static int comparam(tp, t) 	struct tty	*tp; 	struct termios	*t; { 	u_int		cfcr; 	int		cflag; 	struct com_s	*com; 	int		divisor; 	int		error; 	Port_t		iobase; 	int		s; 	int		unit; 	int		txtimeout;
ifdef|#
directive|ifdef
name|PC98
argument|Port_t		tmp_port; 	int		tmp_flg;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PC98
argument|cfcr =
literal|0
argument|; 	unit = DEV_TO_UNIT(tp->t_dev); 	com = com_addr(unit); 	iobase = com->iobase; 	if(IS_8251(com->pc98_if_type)) { 		divisor = pc98_ttspeedtab(com, t->c_ospeed); 	} else
endif|#
directive|endif
comment|/* do historical conversions */
argument|if (t->c_ispeed ==
literal|0
argument|) 		t->c_ispeed = t->c_ospeed;
comment|/* check requested parameters */
argument|divisor = ttspeedtab(t->c_ospeed, comspeedtab); 	if (divisor<
literal|0
argument||| divisor>
literal|0
argument|&& t->c_ispeed != t->c_ospeed) 		return (EINVAL);
comment|/* parameters are OK, convert them to the com struct and the device */
ifndef|#
directive|ifndef
name|PC98
argument|unit = DEV_TO_UNIT(tp->t_dev); 	com = com_addr(unit); 	iobase = com->iobase;
endif|#
directive|endif
argument|s = spltty();
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 		if(divisor ==
literal|0
argument|){ 			com_int_TxRx_disable( com ); 			com_tiocm_bic( com, TIOCM_DTR|TIOCM_RTS|TIOCM_LE ); 		} 	} else {
endif|#
directive|endif
argument|if (divisor ==
literal|0
argument|) 		(void)commctl(com, TIOCM_DTR, DMBIC);
comment|/* hang up line */
argument|else 		(void)commctl(com, TIOCM_DTR, DMBIS);
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|cflag = t->c_cflag;
ifdef|#
directive|ifdef
name|PC98
argument|if(!IS_8251(com->pc98_if_type)){
endif|#
directive|endif
argument|switch (cflag& CSIZE) { 	case CS5: 		cfcr = CFCR_5BITS; 		break; 	case CS6: 		cfcr = CFCR_6BITS; 		break; 	case CS7: 		cfcr = CFCR_7BITS; 		break; 	default: 		cfcr = CFCR_8BITS; 		break; 	} 	if (cflag& PARENB) { 		cfcr |= CFCR_PENAB; 		if (!(cflag& PARODD)) 			cfcr |= CFCR_PEVEN; 	} 	if (cflag& CSTOPB) 		cfcr |= CFCR_STOPB;  	if (com->hasfifo&& divisor !=
literal|0
argument|) {
comment|/* 		 * Use a fifo trigger level low enough so that the input 		 * latency from the fifo is less than about 16 msec and 		 * the total latency is less than about 30 msec.  These 		 * latencies are reasonable for humans.  Serial comms 		 * protocols shouldn't expect anything better since modem 		 * latencies are larger. 		 */
argument|com->fifo_image = t->c_ospeed<=
literal|4800
argument|? FIFO_ENABLE : FIFO_ENABLE | FIFO_RX_HIGH; 		outb(iobase + com_fifo, com->fifo_image); 	}
comment|/* 	 * Some UARTs lock up if the divisor latch registers are selected 	 * while the UART is doing output (they refuse to transmit anything 	 * more until given a hard reset).  Fix this by stopping filling 	 * the device buffers and waiting for them to drain.  Reading the 	 * line status port outside of siointr1() might lose some receiver 	 * error bits, but that is acceptable here. 	 */
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|disable_intr(); retry: 	com->state&= ~CS_TTGO; 	txtimeout = tp->t_timeout; 	enable_intr();
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 		tmp_port = com->sts_port; 		tmp_flg = (STS8251_TxRDY|STS8251_TxEMP); 	} else { 		tmp_port = com->line_status_port; 		tmp_flg = (LSR_TSRE|LSR_TXRDY); 	} 	while ((inb(tmp_port)& tmp_flg) != tmp_flg) {
else|#
directive|else
argument|while ((inb(com->line_status_port)& (LSR_TSRE | LSR_TXRDY)) 	       != (LSR_TSRE | LSR_TXRDY)) {
endif|#
directive|endif
argument|tp->t_state |= TS_SO_OCOMPLETE; 		error = ttysleep(tp, TSA_OCOMPLETE(tp), TTIPRI | PCATCH,
literal|"siotx"
argument|, hz /
literal|100
argument|); 		if (   txtimeout !=
literal|0
argument|&& (!error || error	== EAGAIN)&& (txtimeout -= hz	/
literal|100
argument|)<=
literal|0
argument|) 			error = EIO; 		if (com->gone) 			error = ENODEV; 		if (error !=
literal|0
argument|&& error != EAGAIN) { 			if (!(tp->t_state& TS_TTSTOP)) { 				disable_intr(); 				com->state |= CS_TTGO; 				enable_intr(); 			} 			splx(s); 			return (error); 		} 	}  	disable_intr();
comment|/* very important while com_data is hidden */
comment|/* 	 * XXX - clearing CS_TTGO is not sufficient to stop further output, 	 * because siopoll() calls comstart() which usually sets it again 	 * because TS_TTSTOP is clear.  Setting TS_TTSTOP would not be 	 * sufficient, for similar reasons. 	 */
ifdef|#
directive|ifdef
name|PC98
argument|if ((inb(tmp_port)& tmp_flg) != tmp_flg)
else|#
directive|else
argument|if ((inb(com->line_status_port)& (LSR_TSRE | LSR_TXRDY)) 	    != (LSR_TSRE | LSR_TXRDY))
endif|#
directive|endif
argument|goto retry;
ifdef|#
directive|ifdef
name|PC98
argument|if(!IS_8251(com->pc98_if_type)){
endif|#
directive|endif
argument|if (divisor !=
literal|0
argument|) { 		outb(iobase + com_cfcr, cfcr | CFCR_DLAB); 		outb(iobase + com_dlbl, divisor&
literal|0xFF
argument|); 		outb(iobase + com_dlbh, (u_int) divisor>>
literal|8
argument|); 	} 	outb(iobase + com_cfcr, com->cfcr_image = cfcr);
ifdef|#
directive|ifdef
name|PC98
argument|} else 		com_cflag_and_speed_set(com, cflag, t->c_ospeed);
endif|#
directive|endif
argument|if (!(tp->t_state& TS_TTSTOP)) 		com->state |= CS_TTGO; 	if (cflag& CRTS_IFLOW) 		com->state |= CS_RTS_IFLOW;
comment|/* XXX - secondary changes? */
argument|else 		com->state&= ~CS_RTS_IFLOW;
comment|/* 	 * Set up state to handle output flow control. 	 * XXX - worth handling MDMBUF (DCD) flow control at the lowest level? 	 * Now has 10+ msec latency, while CTS flow has 50- usec latency. 	 */
argument|com->state |= CS_ODEVREADY; 	com->state&= ~CS_CTS_OFLOW; 	if (cflag& CCTS_OFLOW) { 		com->state |= CS_CTS_OFLOW;
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)){ 			if (!(pc98_get_modem_status(com)& TIOCM_CTS)) 				com->state&= ~CS_ODEVREADY; 		} else {
endif|#
directive|endif
argument|if (!(com->last_modem_status& MSR_CTS)) 			com->state&= ~CS_ODEVREADY;
ifdef|#
directive|ifdef
name|PC98
argument|}
endif|#
directive|endif
argument|}
comment|/* XXX shouldn't call functions while intrs are disabled. */
argument|disc_optim(tp, t, com);
comment|/* 	 * Recover from fiddling with CS_TTGO.  We used to call siointr1() 	 * unconditionally, but that defeated the careful discarding of 	 * stale input in sioopen(). 	 */
argument|if (com->state>= (CS_BUSY | CS_TTGO)) 		siointr1(com);  	enable_intr(); 	splx(s); 	return (
literal|0
argument|); }  static void comstart(tp) 	struct tty	*tp; { 	struct com_s	*com; 	int		s; 	int		unit;
ifdef|#
directive|ifdef
name|PC98
argument|int		tmp;
endif|#
directive|endif
argument|unit = DEV_TO_UNIT(tp->t_dev); 	com = com_addr(unit); 	s = spltty(); 	disable_intr(); 	if (tp->t_state& TS_TTSTOP) 		com->state&= ~CS_TTGO; 	else 		com->state |= CS_TTGO; 	if (tp->t_state& TS_TBLOCK) {
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 			tmp = com_tiocm_get(com)& TIOCM_RTS; 		else 			tmp = com->mcr_image& MCR_RTS; 		if (tmp&& (com->state& CS_RTS_IFLOW))
else|#
directive|else
argument|if (com->mcr_image& MCR_RTS&& com->state& CS_RTS_IFLOW)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				com_tiocm_bic(com, TIOCM_RTS); 			else
endif|#
directive|endif
argument|outb(com->modem_ctl_port, com->mcr_image&= ~MCR_RTS); 	} else {
comment|/* 		 * XXX don't raise MCR_RTS if CTS_RTS_IFLOW is off.  Set it 		 * appropriately in comparam() if RTS-flow is being changed. 		 * Check for races. 		 */
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 			tmp = com_tiocm_get(com)& TIOCM_RTS; 		else 			tmp = com->mcr_image& MCR_RTS; 		if (!(tmp)&& com->iptr< com->ihighwater)
else|#
directive|else
argument|if (!(com->mcr_image& MCR_RTS)&& com->iptr< com->ihighwater)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PC98
argument|if(IS_8251(com->pc98_if_type)) 				com_tiocm_bis(com, TIOCM_RTS); 			else
endif|#
directive|endif
argument|outb(com->modem_ctl_port, com->mcr_image |= MCR_RTS); 	} 	enable_intr(); 	if (tp->t_state& (TS_TIMEOUT | TS_TTSTOP)) {
ifdef|#
directive|ifdef
name|PC98
comment|/*		if(IS_8251(com->pc98_if_type)) 			com_int_Tx_enable(com); */
endif|#
directive|endif
argument|splx(s); 		return; 	} 	if (tp->t_outq.c_cc !=
literal|0
argument|) { 		struct lbq	*qp; 		struct lbq	*next;  		if (!com->obufs[
literal|0
argument|].l_queued) { 			com->obufs[
literal|0
argument|].l_tail 			    = com->obuf1 + q_to_b(&tp->t_outq, com->obuf1, 						  sizeof com->obuf1); 			com->obufs[
literal|0
argument|].l_next = NULL; 			com->obufs[
literal|0
argument|].l_queued = TRUE; 			disable_intr(); 			if (com->state& CS_BUSY) { 				qp = com->obufq.l_next; 				while ((next = qp->l_next) != NULL) 					qp = next; 				qp->l_next =&com->obufs[
literal|0
argument|]; 			} else { 				com->obufq.l_head = com->obufs[
literal|0
argument|].l_head; 				com->obufq.l_tail = com->obufs[
literal|0
argument|].l_tail; 				com->obufq.l_next =&com->obufs[
literal|0
argument|]; 				com->state |= CS_BUSY; 			} 			enable_intr(); 		} 		if (tp->t_outq.c_cc !=
literal|0
argument|&& !com->obufs[
literal|1
argument|].l_queued) { 			com->obufs[
literal|1
argument|].l_tail 			    = com->obuf2 + q_to_b(&tp->t_outq, com->obuf2, 						  sizeof com->obuf2); 			com->obufs[
literal|1
argument|].l_next = NULL; 			com->obufs[
literal|1
argument|].l_queued = TRUE; 			disable_intr(); 			if (com->state& CS_BUSY) { 				qp = com->obufq.l_next; 				while ((next = qp->l_next) != NULL) 					qp = next; 				qp->l_next =&com->obufs[
literal|1
argument|]; 			} else { 				com->obufq.l_head = com->obufs[
literal|1
argument|].l_head; 				com->obufq.l_tail = com->obufs[
literal|1
argument|].l_tail; 				com->obufq.l_next =&com->obufs[
literal|1
argument|]; 				com->state |= CS_BUSY; 			} 			enable_intr(); 		} 		tp->t_state |= TS_BUSY; 	} 	disable_intr(); 	if (com->state>= (CS_BUSY | CS_TTGO)) 		siointr1(com);
comment|/* fake interrupt to start output */
argument|enable_intr();
ifdef|#
directive|ifdef
name|PC98
comment|/*		if(IS_8251(com->pc98_if_type)) 			com_int_Tx_enable(com); */
endif|#
directive|endif
argument|ttwwakeup(tp); 	splx(s); }  static void siostop(tp, rw) 	struct tty	*tp; 	int		rw; { 	struct com_s	*com;  	com = com_addr(DEV_TO_UNIT(tp->t_dev)); 	if (com->gone) 		return; 	disable_intr(); 	if (rw& FWRITE) { 		com->obufs[
literal|0
argument|].l_queued = FALSE; 		com->obufs[
literal|1
argument|].l_queued = FALSE; 		if (com->state& CS_ODONE) 			com_events -= LOTS_OF_EVENTS; 		com->state&= ~(CS_ODONE | CS_BUSY); 		com->tp->t_state&= ~TS_BUSY; 	} 	if (rw& FREAD) { 		com_events -= (com->iptr - com->ibuf); 		com->iptr = com->ibuf; 	} 	enable_intr(); 	comstart(tp);
comment|/* XXX should clear h/w fifos too. */
argument|}  static struct tty * siodevtotty(dev) 	dev_t	dev; { 	int	mynor; 	int	unit;  	mynor = minor(dev); 	if (mynor& CONTROL_MASK) 		return (NULL); 	unit = MINOR_TO_UNIT(mynor); 	if ((u_int) unit>= NSIO) 		return (NULL); 	return (&sio_tty[unit]); }  static int commctl(com, bits, how) 	struct com_s	*com; 	int		bits; 	int		how; { 	int	mcr; 	int	msr;  	if (how == DMGET) { 		bits = TIOCM_LE;
comment|/* XXX - always enabled while open */
argument|mcr = com->mcr_image; 		if (mcr& MCR_DTR) 			bits |= TIOCM_DTR; 		if (mcr& MCR_RTS) 			bits |= TIOCM_RTS; 		msr = com->prev_modem_status; 		if (msr& MSR_CTS) 			bits |= TIOCM_CTS; 		if (msr& MSR_DCD) 			bits |= TIOCM_CD; 		if (msr& MSR_DSR) 			bits |= TIOCM_DSR;
comment|/* 		 * XXX - MSR_RI is naturally volatile, and we make MSR_TERI 		 * more volatile by reading the modem status a lot.  Perhaps 		 * we should latch both bits until the status is read here. 		 */
argument|if (msr& (MSR_RI | MSR_TERI)) 			bits |= TIOCM_RI; 		return (bits); 	} 	mcr =
literal|0
argument|; 	if (bits& TIOCM_DTR) 		mcr |= MCR_DTR; 	if (bits& TIOCM_RTS) 		mcr |= MCR_RTS; 	if (com->gone) 		return(
literal|0
argument|); 	disable_intr(); 	switch (how) { 	case DMSET: 		outb(com->modem_ctl_port, 		     com->mcr_image = mcr | (com->mcr_image& MCR_IENABLE)); 		break; 	case DMBIS: 		outb(com->modem_ctl_port, com->mcr_image |= mcr); 		break; 	case DMBIC: 		outb(com->modem_ctl_port, com->mcr_image&= ~mcr); 		break; 	} 	enable_intr(); 	return (
literal|0
argument|); }  static void siosettimeout() { 	struct com_s	*com; 	bool_t		someopen; 	int		unit;
comment|/* 	 * Set our timeout period to 1 second if no polled devices are open. 	 * Otherwise set it to max(1/200, 1/hz). 	 * Enable timeouts iff some device is open. 	 */
argument|untimeout(comwakeup, (void *)NULL); 	sio_timeout = hz; 	someopen = FALSE; 	for (unit =
literal|0
argument|; unit< NSIO; ++unit) { 		com = com_addr(unit); 		if (com != NULL&& com->tp != NULL&& com->tp->t_state& TS_ISOPEN&& !com->gone) { 			someopen = TRUE; 			if (com->poll || com->poll_output) { 				sio_timeout = hz>
literal|200
argument|? hz /
literal|200
argument|:
literal|1
argument|; 				break; 			} 		} 	} 	if (someopen) { 		sio_timeouts_until_log = hz / sio_timeout; 		timeout(comwakeup, (void *)NULL, sio_timeout); 	} else {
comment|/* Flush error messages, if any. */
argument|sio_timeouts_until_log =
literal|1
argument|; 		comwakeup((void *)NULL); 		untimeout(comwakeup, (void *)NULL); 	} }  static void comwakeup(chan) 	void	*chan; { 	struct com_s	*com; 	int		unit;  	timeout(comwakeup, (void *)NULL, sio_timeout);
comment|/* 	 * Recover from lost output interrupts. 	 * Poll any lines that don't use interrupts. 	 */
argument|for (unit =
literal|0
argument|; unit< NSIO; ++unit) { 		com = com_addr(unit); 		if (com != NULL&& !com->gone&& (com->state>= (CS_BUSY | CS_TTGO) || com->poll)) { 			disable_intr(); 			siointr1(com); 			enable_intr(); 		} 	}
comment|/* 	 * Check for and log errors, but not too often. 	 */
argument|if (--sio_timeouts_until_log>
literal|0
argument|) 		return; 	sio_timeouts_until_log = hz / sio_timeout; 	for (unit =
literal|0
argument|; unit< NSIO; ++unit) { 		int	errnum;  		com = com_addr(unit); 		if (com == NULL) 			continue; 		if (com->gone) 			continue; 		for (errnum =
literal|0
argument|; errnum< CE_NTYPES; ++errnum) { 			u_int	delta; 			u_long	total;  			disable_intr(); 			delta = com->delta_error_counts[errnum]; 			com->delta_error_counts[errnum] =
literal|0
argument|; 			enable_intr(); 			if (delta ==
literal|0
argument|) 				continue; 			total = com->error_counts[errnum] += delta; 			log(LOG_ERR,
literal|"sio%d: %u more %s%s (total %lu)\n"
argument|, 			    unit, delta, error_desc[errnum], 			    delta ==
literal|1
argument|?
literal|""
argument|:
literal|"s"
argument|, total); 		} 	} }
ifdef|#
directive|ifdef
name|PC98
comment|/* commint is called when modem control line changes */
argument|static void commint(dev_t dev) { 	register struct tty *tp; 	int	stat,delta; 	struct com_s *com; 	int	mynor,unit;  	mynor = minor(dev); 	unit = MINOR_TO_UNIT(mynor); 	com = com_addr(unit); 	tp = com->tp;  	stat = com_tiocm_get(com); 	delta = com_tiocm_get_delta(com);  	if (com->state& CS_CTS_OFLOW) { 		if (stat& TIOCM_CTS) 			com->state |= CS_ODEVREADY; 		else 			com->state&= ~CS_ODEVREADY; 	} 	if ((delta& TIOCM_CAR)&& (mynor& CALLOUT_MASK) ==
literal|0
argument|) { 	    if (stat& TIOCM_CAR ) 		(void)(*linesw[tp->t_line].l_modem)(tp,
literal|1
argument|); 	    else if ((*linesw[tp->t_line].l_modem)(tp,
literal|0
argument|) ==
literal|0
argument|) {
comment|/* negate DTR, RTS */
argument|com_tiocm_bic(com, (tp->t_cflag& HUPCL) ? 				TIOCM_DTR|TIOCM_RTS|TIOCM_LE : TIOCM_LE );
comment|/* disable IENABLE */
argument|com_int_TxRx_disable( com ); 	    } 	} }
endif|#
directive|endif
argument|static void disc_optim(tp, t, com) 	struct tty	*tp; 	struct termios	*t; 	struct com_s	*com; { 	if (!(t->c_iflag& (ICRNL | IGNCR | IMAXBEL | INLCR | ISTRIP | IXON))&& (!(t->c_iflag& BRKINT) || (t->c_iflag& IGNBRK))&& (!(t->c_iflag& PARMRK) 		|| (t->c_iflag& (IGNPAR | IGNBRK)) == (IGNPAR | IGNBRK))&& !(t->c_lflag& (ECHO | ICANON | IEXTEN | ISIG | PENDIN))&& linesw[tp->t_line].l_rint == ttyinput) 		tp->t_state |= TS_CAN_BYPASS_L_RINT; 	else 		tp->t_state&= ~TS_CAN_BYPASS_L_RINT;
comment|/* 	 * Prepare to reduce input latency for packet 	 * discplines with a end of packet character. 	 */
argument|if (tp->t_line == SLIPDISC) 		com->hotchar =
literal|0xc0
argument|; 	else if (tp->t_line == PPPDISC) 		com->hotchar =
literal|0x7e
argument|; 	else 		com->hotchar =
literal|0
argument|; }
comment|/*  * Following are all routines needed for SIO to act as console  */
include|#
directive|include
file|<machine/cons.h>
argument|struct siocnstate { 	u_char	dlbl; 	u_char	dlbh; 	u_char	ier; 	u_char	cfcr; 	u_char	mcr; };  static	Port_t	siocniobase;  static void siocnclose	__P((struct siocnstate *sp)); static void siocnopen	__P((struct siocnstate *sp)); static void siocntxwait	__P((void));  static void siocntxwait() { 	int	timo;
comment|/* 	 * Wait for any pending transmission to finish.  Required to avoid 	 * the UART lockup bug when the speed is changed, and for normal 	 * transmits. 	 */
argument|timo =
literal|100000
argument|; 	while ((inb(siocniobase + com_lsr)& (LSR_TSRE | LSR_TXRDY)) 	       != (LSR_TSRE | LSR_TXRDY)&& --timo !=
literal|0
argument|) 		; }  static void siocnopen(sp) 	struct siocnstate	*sp; { 	int	divisor; 	Port_t	iobase;
comment|/* 	 * Save all the device control registers except the fifo register 	 * and set our default ones (cs8 -parenb speed=comdefaultrate). 	 * We can't save the fifo register since it is read-only. 	 */
argument|iobase = siocniobase; 	sp->ier = inb(iobase + com_ier); 	outb(iobase + com_ier,
literal|0
argument|);
comment|/* spltty() doesn't stop siointr() */
argument|siocntxwait(); 	sp->cfcr = inb(iobase + com_cfcr); 	outb(iobase + com_cfcr, CFCR_DLAB); 	sp->dlbl = inb(iobase + com_dlbl); 	sp->dlbh = inb(iobase + com_dlbh); 	divisor = ttspeedtab(comdefaultrate, comspeedtab); 	outb(iobase + com_dlbl, divisor&
literal|0xFF
argument|); 	outb(iobase + com_dlbh, (u_int) divisor>>
literal|8
argument|); 	outb(iobase + com_cfcr, CFCR_8BITS); 	sp->mcr = inb(iobase + com_mcr);
comment|/* 	 * We don't want interrupts, but must be careful not to "disable" 	 * them by clearing the MCR_IENABLE bit, since that might cause 	 * an interrupt by floating the IRQ line. 	 */
argument|outb(iobase + com_mcr, (sp->mcr& MCR_IENABLE) | MCR_DTR | MCR_RTS); }  static void siocnclose(sp) 	struct siocnstate	*sp; { 	Port_t	iobase;
comment|/* 	 * Restore the device control registers. 	 */
argument|siocntxwait(); 	iobase = siocniobase; 	outb(iobase + com_cfcr, CFCR_DLAB); 	outb(iobase + com_dlbl, sp->dlbl); 	outb(iobase + com_dlbh, sp->dlbh); 	outb(iobase + com_cfcr, sp->cfcr);
comment|/* 	 * XXX damp oscillations of MCR_DTR and MCR_RTS by not restoring them. 	 */
argument|outb(iobase + com_mcr, sp->mcr | MCR_DTR | MCR_RTS); 	outb(iobase + com_ier, sp->ier); }  void siocnprobe(cp) 	struct consdev	*cp; { 	int	unit;
comment|/* XXX: ick */
argument|unit = DEV_TO_UNIT(CONUNIT); 	siocniobase = CONADDR;
comment|/* make sure hardware exists?  XXX */
comment|/* initialize required fields */
argument|cp->cn_dev = makedev(CDEV_MAJOR, unit);
ifdef|#
directive|ifdef
name|COMCONSOLE
argument|cp->cn_pri = CN_REMOTE;
comment|/* Force a serial port console */
else|#
directive|else
argument|cp->cn_pri = (boothowto& RB_SERIAL) ? CN_REMOTE : CN_NORMAL;
endif|#
directive|endif
argument|}  void siocninit(cp) 	struct consdev	*cp; { 	comconsole = DEV_TO_UNIT(cp->cn_dev); }  int siocncheckc(dev) 	dev_t	dev; { 	int	c; 	Port_t	iobase; 	int	s; 	struct siocnstate	sp;  	iobase = siocniobase; 	s = spltty(); 	siocnopen(&sp); 	if (inb(iobase + com_lsr)& LSR_RXRDY) 		c = inb(iobase + com_data); 	else 		c =
literal|0
argument|; 	siocnclose(&sp); 	splx(s); 	return (c); }   int siocngetc(dev) 	dev_t	dev; { 	int	c; 	Port_t	iobase; 	int	s; 	struct siocnstate	sp;  	iobase = siocniobase; 	s = spltty(); 	siocnopen(&sp); 	while (!(inb(iobase + com_lsr)& LSR_RXRDY)) 		; 	c = inb(iobase + com_data); 	siocnclose(&sp); 	splx(s); 	return (c); }  void siocnputc(dev, c) 	dev_t	dev; 	int	c; { 	int	s; 	struct siocnstate	sp;  	s = spltty(); 	siocnopen(&sp); 	siocntxwait(); 	outb(siocniobase + com_data, c); 	siocnclose(&sp); 	splx(s); }
ifdef|#
directive|ifdef
name|DSI_SOFT_MODEM
comment|/*  * The magic code to download microcode to a "Connection 14.4+Fax"  * modem from Digicom Systems Inc.  Very magic.  */
define|#
directive|define
name|DSI_ERROR
parameter_list|(
name|str
parameter_list|)
value|{ ptr = str; goto error; }
argument|static int LoadSoftModem(int unit, int base_io, u_long size, u_char *ptr) {     int int_c,int_k;     int data_0188, data_0187;
comment|/*      * First see if it is a DSI SoftModem      */
argument|if(!((inb(base_io+
literal|7
argument|) ^ inb(base_io+
literal|7
argument|)&
literal|0x80
argument|))) 	return ENODEV;      data_0188 = inb(base_io+
literal|4
argument|);     data_0187 = inb(base_io+
literal|3
argument|);     outb(base_io+
literal|3
argument|,
literal|0x80
argument|);     outb(base_io+
literal|4
argument|,
literal|0x0C
argument|);     outb(base_io+
literal|0
argument|,
literal|0x31
argument|);     outb(base_io+
literal|1
argument|,
literal|0x8C
argument|);     outb(base_io+
literal|7
argument|,
literal|0x10
argument|);     outb(base_io+
literal|7
argument|,
literal|0x19
argument|);      if(
literal|0x18
argument|!= (inb(base_io+
literal|7
argument|)&
literal|0x1A
argument|)) 	DSI_ERROR(
literal|"dsp bus not granted"
argument|);      if(
literal|0x01
argument|!= (inb(base_io+
literal|7
argument|)&
literal|0x01
argument|)) { 	outb(base_io+
literal|7
argument|,
literal|0x18
argument|); 	outb(base_io+
literal|7
argument|,
literal|0x19
argument|); 	if(
literal|0x01
argument|!= (inb(base_io+
literal|7
argument|)&
literal|0x01
argument|)) 	    DSI_ERROR(
literal|"program mem not granted"
argument|);     }      int_c =
literal|0
argument|;      while(
literal|1
argument|) { 	if(int_c>=
literal|7
argument||| size<=
literal|0x1800
argument|) 	    break;  	for(int_k =
literal|0
argument|; int_k<
literal|0x800
argument|; int_k++) { 	    outb(base_io+
literal|0
argument|,*ptr++); 	    outb(base_io+
literal|1
argument|,*ptr++); 	    outb(base_io+
literal|2
argument|,*ptr++); 	}  	size -=
literal|0x1800
argument|; 	int_c++;     }      if(size>
literal|0x1800
argument|) {  	outb(base_io+
literal|7
argument|,
literal|0x18
argument|);  	outb(base_io+
literal|7
argument|,
literal|0x19
argument|); 	if(
literal|0x00
argument|!= (inb(base_io+
literal|7
argument|)&
literal|0x01
argument|)) 	    DSI_ERROR(
literal|"program data not granted"
argument|);  	for(int_k =
literal|0
argument|; int_k<
literal|0x800
argument|; int_k++) { 	    outb(base_io+
literal|1
argument|,*ptr++); 	    outb(base_io+
literal|2
argument|,
literal|0
argument|); 	    outb(base_io+
literal|1
argument|,*ptr++); 	    outb(base_io+
literal|2
argument|,*ptr++); 	}  	size -=
literal|0x1800
argument|;  	while(size>
literal|0x1800
argument|) { 	    for(int_k =
literal|0
argument|; int_k<
literal|0xC00
argument|; int_k++) { 		outb(base_io+
literal|1
argument|,*ptr++); 		outb(base_io+
literal|2
argument|,*ptr++); 	    } 	    size -=
literal|0x1800
argument|; 	}  	if(size<
literal|0x1800
argument|) { 	    for(int_k=
literal|0
argument|;int_k<size/
literal|2
argument|;int_k++) { 		outb(base_io+
literal|1
argument|,*ptr++); 		outb(base_io+
literal|2
argument|,*ptr++); 	    } 	}      } else if (size>
literal|0
argument|) { 	if(int_c ==
literal|7
argument|) { 	    outb(base_io+
literal|7
argument|,
literal|0x18
argument|); 	    outb(base_io+
literal|7
argument|,
literal|0x19
argument|); 	    if(
literal|0x00
argument|!= (inb(base_io+
literal|7
argument|)&
literal|0x01
argument|)) 		DSI_ERROR(
literal|"program data not granted"
argument|); 	    for(int_k =
literal|0
argument|; int_k< size/
literal|3
argument|; int_k++) { 		outb(base_io+
literal|1
argument|,*ptr++); 		outb(base_io+
literal|2
argument|,
literal|0
argument|); 		outb(base_io+
literal|1
argument|,*ptr++); 		outb(base_io+
literal|2
argument|,*ptr++); 	    } 	} else { 	    for(int_k =
literal|0
argument|; int_k< size/
literal|3
argument|; int_k++) { 		outb(base_io+
literal|0
argument|,*ptr++); 		outb(base_io+
literal|1
argument|,*ptr++); 		outb(base_io+
literal|2
argument|,*ptr++); 	    } 	}     }     outb(base_io+
literal|7
argument|,
literal|0x11
argument|);     outb(base_io+
literal|7
argument|,
literal|3
argument|);      outb(base_io+
literal|4
argument|,data_0188&
literal|0xfb
argument|);      outb(base_io+
literal|3
argument|,data_0187);      return
literal|0
argument|; error:     printf(
literal|"sio%d: DSI SoftModem microcode load failed:<%s>\n"
argument|,unit,ptr);     outb(base_io+
literal|7
argument|,
literal|0x00
argument|); \     outb(base_io+
literal|3
argument|,data_0187); \     outb(base_io+
literal|4
argument|,data_0188);  \     return EIO; }
endif|#
directive|endif
comment|/* DSI_SOFT_MODEM */
ifdef|#
directive|ifdef
name|PC98
comment|/*  *  pc98 local function  */
argument|static void com_tiocm_set(struct com_s *com, int msr) { 	int	s; 	int	tmp =
literal|0
argument|; 	int	mask = CMD8251_TxEN|CMD8251_RxEN|CMD8251_DTR|CMD8251_RTS;  	s=spltty(); 	com->pc98_prev_modem_status = ( msr& (TIOCM_LE|TIOCM_DTR|TIOCM_RTS) ) 	   | ( com->pc98_prev_modem_status& ~(TIOCM_LE|TIOCM_DTR|TIOCM_RTS) ); 	tmp |= (CMD8251_TxEN|CMD8251_RxEN); 	if ( msr& TIOCM_DTR ) tmp |= CMD8251_DTR; 	if ( msr& TIOCM_RTS ) tmp |= CMD8251_RTS; 	pc98_i8251_clear_or_cmd( com, mask, tmp ); 	splx(s); }  static void com_tiocm_bis(struct com_s *com, int msr) { 	int	s; 	int	tmp =
literal|0
argument|;  	s=spltty(); 	com->pc98_prev_modem_status |= ( msr& (TIOCM_LE|TIOCM_DTR|TIOCM_RTS) ); 	tmp |= CMD8251_TxEN|CMD8251_RxEN; 	if ( msr& TIOCM_DTR ) tmp |= CMD8251_DTR; 	if ( msr& TIOCM_RTS ) tmp |= CMD8251_RTS;  	pc98_i8251_or_cmd( com, tmp ); 	splx(s); }  static void com_tiocm_bic(struct com_s *com, int msr) { 	int	s; 	int	tmp = msr;  	s=spltty(); 	com->pc98_prev_modem_status&= ~( msr& (TIOCM_LE|TIOCM_DTR|TIOCM_RTS) ); 	if ( msr& TIOCM_DTR ) tmp |= CMD8251_DTR; 	if ( msr& TIOCM_RTS ) tmp |= CMD8251_RTS;  	pc98_i8251_clear_cmd( com, tmp ); 	splx(s); }  static int com_tiocm_get(struct com_s *com) { 	return( com->pc98_prev_modem_status ); }  static int com_tiocm_get_delta(struct com_s *com) { 	int	tmp;  	tmp = com->pc98_modem_delta; 	com->pc98_modem_delta =
literal|0
argument|; 	return( tmp ); }
comment|/* convert to TIOCM_?? ( ioctl.h ) */
argument|static int pc98_get_modem_status(struct com_s *com) { 	int	stat, stat2; 	register int	msr;  	stat  = inb(com->sts_port); 	stat2 = inb(com->in_modem_port); 	msr = com->pc98_prev_modem_status& ~(TIOCM_CAR|TIOCM_RI|TIOCM_DSR|TIOCM_CTS); 	if ( !(stat2& CICSCD_CD) ) msr |= TIOCM_CAR; 	if ( !(stat2& CICSCD_CI) ) msr |= TIOCM_RI; 	if (   stat& STS8251_DSR ) msr |= TIOCM_DSR; 	if ( !(stat2& CICSCD_CS) ) msr |= TIOCM_CTS;
if|#
directive|if
name|COM_CARRIER_DETECT_EMULATE
argument|if ( msr& (TIOCM_DSR|TIOCM_CTS) ) { 		msr |= TIOCM_CAR; 	}
endif|#
directive|endif
argument|return(msr); }  static void pc98_check_msr(void* chan) { 	int	msr, delta; 	int	s; 	register struct tty *tp; 	struct	com_s *com; 	int	mynor; 	int	unit; 	dev_t	dev;  	dev=(dev_t)chan; 	mynor = minor(dev); 	unit = MINOR_TO_UNIT(mynor); 	com = com_addr(unit); 	tp = com->tp;  	s = spltty(); 	msr = pc98_get_modem_status(com);
comment|/* make change flag */
argument|delta = msr ^ com->pc98_prev_modem_status; 	if ( delta& TIOCM_CAR ) { 	    if ( com->modem_car_chg_timer ) { 		if ( -- com->modem_car_chg_timer ) 		    msr ^= TIOCM_CAR; 	    } else { 		if ( com->modem_car_chg_timer = ( msr& TIOCM_CAR ) ? 			     DCD_ON_RECOGNITION : DCD_OFF_TOLERANCE ) 		    msr ^= TIOCM_CAR; 	    } 	} else 	    com->modem_car_chg_timer =
literal|0
argument|; 	delta = ( msr ^ com->pc98_prev_modem_status )& 			(TIOCM_CAR|TIOCM_RI|TIOCM_DSR|TIOCM_CTS); 	com->pc98_prev_modem_status = msr; 	delta = ( com->pc98_modem_delta |= delta ); 	splx(s); 	if ( com->modem_checking || (tp->t_state& (TS_ISOPEN)) ) { 		if ( delta ) { 			commint(dev); 		} 		timeout(pc98_check_msr, (caddr_t)dev, 					PC98_CHECK_MODEM_INTERVAL); 	} else { 		com->modem_checking =
literal|0
argument|; 	} }  static void pc98_msrint_start(dev_t dev) { 	struct	com_s *com; 	int	mynor; 	int	unit; 	int	s = spltty();  	mynor = minor(dev); 	unit = MINOR_TO_UNIT(mynor); 	com = com_addr(unit);
comment|/* modem control line check routine envoke interval is 1/10 sec */
argument|if ( com->modem_checking ==
literal|0
argument|) { 		com->pc98_prev_modem_status = pc98_get_modem_status(com); 		com->pc98_modem_delta =
literal|0
argument|; 		timeout(pc98_check_msr, (caddr_t)dev, 					PC98_CHECK_MODEM_INTERVAL); 		com->modem_checking =
literal|1
argument|; 	} 	splx(s); }  static void pc98_disable_i8251_interrupt(struct com_s *com, int mod) {
comment|/* disable interrupt */
argument|register int	tmp;  	mod |= ~(IEN_Tx|IEN_TxEMP|IEN_Rx); 	COM_INT_DISABLE 	tmp = inb( com->intr_ctrl_port )& ~(IEN_Tx|IEN_TxEMP|IEN_Rx); 	outb( com->intr_ctrl_port, (com->intr_enable&=~mod) | tmp ); 	COM_INT_ENABLE }  static void pc98_enable_i8251_interrupt(struct com_s *com, int mod) { 	register int	tmp;  	COM_INT_DISABLE 	tmp = inb( com->intr_ctrl_port )& ~(IEN_Tx|IEN_TxEMP|IEN_Rx); 	outb( com->intr_ctrl_port, (com->intr_enable|=mod) | tmp ); 	COM_INT_ENABLE }  static int pc98_check_i8251_interrupt(struct com_s *com) { 	return ( com->intr_enable&
literal|0x07
argument|); }  static void pc98_i8251_clear_cmd(struct com_s *com, int x) { 	int	tmp;  	COM_INT_DISABLE 	tmp = com->pc98_prev_siocmd& ~(x); 	outb(com->cmd_port, tmp); 	com->pc98_prev_siocmd = tmp& ~(CMD8251_ER|CMD8251_RESET|CMD8251_EH); 	COM_INT_ENABLE }  static void pc98_i8251_or_cmd(struct com_s *com, int x) { 	int	tmp;  	COM_INT_DISABLE 	tmp = com->pc98_prev_siocmd | (x); 	outb(com->cmd_port, tmp); 	com->pc98_prev_siocmd = tmp& ~(CMD8251_ER|CMD8251_RESET|CMD8251_EH); 	COM_INT_ENABLE }  static void pc98_i8251_set_cmd(struct com_s *com, int x) { 	int	tmp;  	COM_INT_DISABLE 	tmp = (x); 	outb(com->cmd_port, tmp); 	com->pc98_prev_siocmd = tmp& ~(CMD8251_ER|CMD8251_RESET|CMD8251_EH); 	COM_INT_ENABLE }  static void pc98_i8251_clear_or_cmd(struct com_s *com, int clr, int x) { 	int	tmp; 	COM_INT_DISABLE 	tmp = com->pc98_prev_siocmd& ~(clr); 	tmp |= (x); 	outb(com->cmd_port, tmp); 	com->pc98_prev_siocmd = tmp& ~(CMD8251_ER|CMD8251_RESET|CMD8251_EH); 	COM_INT_ENABLE }  static int pc98_i8251_get_cmd(struct com_s *com) { 	return com->pc98_prev_siocmd; }  static int pc98_i8251_get_mod(struct com_s *com) { 	return com->pc98_prev_siomod; }  static void pc98_i8251_reset(struct com_s *com, int mode, int command) { 	outb(com->cmd_port,
literal|0
argument|);
comment|/* dummy */
argument|DELAY(
literal|2
argument|); 	outb(com->cmd_port,
literal|0
argument|);
comment|/* dummy */
argument|DELAY(
literal|2
argument|); 	outb(com->cmd_port,
literal|0
argument|);
comment|/* dummy */
argument|DELAY(
literal|2
argument|); 	outb(com->cmd_port, CMD8251_RESET);
comment|/* internal reset */
argument|DELAY(
literal|2
argument|); 	outb(com->cmd_port, mode );
comment|/* mode register */
argument|com->pc98_prev_siomod = mode; 	DELAY(
literal|2
argument|); 	pc98_i8251_set_cmd( com, (command|CMD8251_ER) ); }  static void pc98_check_sysclock(void) {
comment|/* get system clock from port */
argument|if ( pc98_machine_type& M_8M ) {
comment|/* 8 MHz system& H98 */
argument|sysclock =
literal|8
argument|; 	} else {
comment|/* 5 MHz system */
argument|sysclock =
literal|5
argument|; 	} }  static void com_cflag_and_speed_set( struct com_s *com, int cflag, int speed) { 	int	cfcr=
literal|0
argument|, count; 	int	previnterrupt;  	count = pc98_ttspeedtab( com, speed ); 	if ( count<
literal|0
argument|) return;  	previnterrupt = pc98_check_i8251_interrupt(com); 	pc98_disable_i8251_interrupt( com, IEN_Tx|IEN_TxEMP|IEN_Rx );  	switch ( cflag&CSIZE ) { 	  case CS5: 		cfcr = MOD8251_5BITS; break; 	  case CS6: 		cfcr = MOD8251_6BITS; break; 	  case CS7: 		cfcr = MOD8251_7BITS; break; 	  case CS8: 		cfcr = MOD8251_8BITS; break; 	} 	if ( cflag&PARENB ) { 	    if ( cflag&PARODD ) 		cfcr |= MOD8251_PODD; 	    else 		cfcr |= MOD8251_PEVEN; 	} else 		cfcr |= MOD8251_PDISAB;  	if ( cflag&CSTOPB ) 		cfcr |= MOD8251_STOP2; 	else 		cfcr |= MOD8251_STOP1;  	if ( count&
literal|0x10000
argument|) 		cfcr |= MOD8251_CLKX1; 	else 		cfcr |= MOD8251_CLKX16;  	if (epson_machine_id !=
literal|0x20
argument|) {
comment|/* XXX */
argument|{ 		int	tmp; 		while (!((tmp = inb(com->sts_port))& STS8251_TxEMP)) 			; 	} 	}
comment|/* set baud rate from ospeed */
argument|pc98_set_baud_rate( com, count );  	if ( cfcr != pc98_i8251_get_mod(com) ) 		pc98_i8251_reset(com, cfcr, pc98_i8251_get_cmd(com) );  	pc98_enable_i8251_interrupt( com, previnterrupt ); }  static int pc98_ttspeedtab(struct com_s *com, int speed) { 	int	effect_sp, count=-
literal|1
argument|, mod;  	switch ( com->pc98_if_type ) { 	    case COM_IF_INTERNAL:
comment|/* for *1CLK asynchronous! mode		, TEFUTEFU */
argument|effect_sp = ttspeedtab( speed, pc98speedtab ); 		if ( effect_sp<
literal|0
argument|) 			effect_sp = ttspeedtab( (speed-
literal|1
argument|), pc98speedtab ); 		if ( effect_sp<=
literal|0
argument|) 			return effect_sp; 		mod = (sysclock ==
literal|5
argument|?
literal|2457600
argument|:
literal|1996800
argument|); 		if ( effect_sp == speed ) 			mod /=
literal|16
argument|; 		count = mod / effect_sp; 		if ( count>
literal|65535
argument|) 			return(-
literal|1
argument|); 		if ( effect_sp>=
literal|2400
argument|) 			if ( !(sysclock !=
literal|5
argument|&&  				(effect_sp ==
literal|19200
argument||| effect_sp ==
literal|38400
argument|)) ) 				if ( ( mod % effect_sp ) !=
literal|0
argument|) 					return(-
literal|1
argument|); 		if ( effect_sp != speed ) 			count |=
literal|0x10000
argument|; 		break;
ifdef|#
directive|ifdef
name|COM_IF_PC9861K
argument|case COM_IF_PC9861K: 		effect_sp = speed; 		count =
literal|1
argument|; 		break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
argument|case COM_IF_PIO9032B: 		if ( speed ==
literal|0
argument|) return
literal|0
argument|; 		count = ttspeedtab( speed, comspeedtab_pio9032b ); 		if ( count<
literal|0
argument|) return count; 		effect_sp = speed; 		break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_B98_01
argument|case COM_IF_B98_01: 		effect_sp=speed; 		count = ttspeedtab( speed, comspeedtab_b98_01 ); 		if ( count<=
literal|3
argument|) 			return -
literal|1
argument|;
comment|/* invalid speed/count */
argument|if ( count<=
literal|5
argument|) 			count |=
literal|0x10000
argument|;
comment|/* x1 mode for 76800 and 153600 */
argument|else 			count -=
literal|4
argument|;
comment|/* x16 mode for slower */
argument|break;
endif|#
directive|endif
argument|} 	return count; }  static void pc98_set_baud_rate( struct com_s *com, int count) { 	int	s;  	switch ( com->pc98_if_type ) { 	    case COM_IF_INTERNAL: 		if ( count<
literal|0
argument|) { 			printf(
literal|"[ Illegal count : %d ]"
argument|, count ); 			return; 		} else if ( count ==
literal|0
argument|)  			return;
comment|/* set i8253 */
argument|s = splclock(); 		outb(
literal|0x77
argument|,
literal|0xb6
argument|); 		outb(
literal|0x5f
argument|,
literal|0
argument|); 		outb(
literal|0x75
argument|, count&
literal|0xff
argument|); 		outb(
literal|0x5f
argument|,
literal|0
argument|); 		outb(
literal|0x75
argument|, (count>>
literal|8
argument|)&
literal|0xff
argument|); 		splx(s); 		break;
if|#
directive|if
literal|0
ifdef|#
directive|ifdef
name|COM_IF_PC9861K
argument|case COM_IF_PC9861K: 		break;
comment|/* ext. RS232C board: speed is determined by DIP switch */
endif|#
directive|endif
endif|#
directive|endif
comment|/* 0 */
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
argument|case COM_IF_PIO9032B: 		outb( com_addr[unit], count&
literal|0x07
argument|); 		break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_B98_01
argument|case COM_IF_B98_01: 		outb( com->iobase,     count&
literal|0x0f
argument|);
ifdef|#
directive|ifdef
name|B98_01_OLD
comment|/* some old board should be controlled in different way, 		   but this hasn't been tested yet.*/
argument|outb( com->iobase+
literal|2
argument|, ( count&
literal|0x10000
argument|) ?
literal|0xf0
argument|:
literal|0xf2
argument|);
endif|#
directive|endif
argument|break;
endif|#
directive|endif
argument|} } static int pc98_check_if_type( int iobase, struct siodev *iod) { 	int	irr =
literal|0
argument|, tmp =
literal|0
argument|; 	int	ret =
literal|0
argument|; 	static  short	irq_tab[
literal|2
argument|][
literal|8
argument|] = { 		{
literal|3
argument|,
literal|5
argument|,
literal|6
argument|,
literal|9
argument|,
literal|10
argument|,
literal|12
argument|,
literal|13
argument|, -
literal|1
argument|}, 		{
literal|3
argument|,
literal|10
argument|,
literal|12
argument|,
literal|13
argument|,
literal|5
argument|,
literal|6
argument|,
literal|9
argument|, -
literal|1
argument|} 	}; 	iod->irq =
literal|0
argument|; 	switch ( iobase&
literal|0xff
argument|) { 		case IO_COM1: 			iod->if_type = COM_IF_INTERNAL; 			ret =
literal|0
argument|; iod->irq =
literal|4
argument|; break;
ifdef|#
directive|ifdef
name|COM_IF_PC9861K
argument|case IO_COM2: 			iod->if_type = COM_IF_PC9861K; 			ret =
literal|1
argument|; irr =
literal|0
argument|; tmp =
literal|3
argument|; break; 		case IO_COM3: 			iod->if_type = COM_IF_PC9861K; 			ret =
literal|2
argument|; irr =
literal|1
argument|; tmp =
literal|3
argument|; break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
argument|case IO_COM_PIO9032B_2: 			iod->if_type = COM_IF_PIO9032B; 			ret =
literal|1
argument|; irr =
literal|0
argument|; tmp =
literal|7
argument|; break; 	    case IO_COM_PIO9032B_3: 			iod->if_type = COM_IF_PIO9032B; 			ret =
literal|2
argument|; irr =
literal|1
argument|; tmp =
literal|7
argument|; break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COM_IF_B98_01
argument|case IO_COM_B98_01_2: 			iod->if_type = COM_IF_B98_01; 			ret =
literal|1
argument|; irr =
literal|0
argument|; tmp =
literal|7
argument|; 			outb(iobase +
literal|2
argument|,
literal|0xf2
argument|); 			outb(iobase,
literal|4
argument|); 			break; 	    case IO_COM_B98_01_3: 			iod->if_type = COM_IF_B98_01; 			ret =
literal|2
argument|; irr =
literal|1
argument|; tmp =
literal|7
argument|; 			outb(iobase +
literal|2
argument|,
literal|0xf2
argument|); 			outb(iobase    ,
literal|4
argument|); 			break;
endif|#
directive|endif
argument|default: 			if((iobase&
literal|0x0f0
argument|) ==
literal|0xd0
argument|){ 				iod->if_type = MC16550; 				return
literal|0
argument|; 			} 			return -
literal|1
argument|; 	}  	iod->cmd  = ( iobase&
literal|0xff00
argument|)|PC98SIO_cmd_port(ret); 	iod->sts  = ( iobase&
literal|0xff00
argument|)|PC98SIO_sts_port(ret); 	iod->mod  = ( iobase&
literal|0xff00
argument|)|PC98SIO_in_modem_port(ret); 	iod->ctrl = ( iobase&
literal|0xff00
argument|)|PC98SIO_intr_ctrl_port(ret);  	if ( iod->irq ==
literal|0
argument|) { 		tmp&= inb( iod->mod ); 		iod->irq = irq_tab[irr][tmp]; 		if ( iod->irq == -
literal|1
argument|) return -
literal|1
argument|; 	} 	return
literal|0
argument|; } static int pc98_set_ioport( struct com_s *com, int io_base ) { 	int	a, io, type;  	switch ( io_base&
literal|0xff
argument|) { 	    case IO_COM1: a =
literal|0
argument|; io =
literal|0
argument|; type = COM_IF_INTERNAL; 					 pc98_check_sysclock(); break;
ifdef|#
directive|ifdef
name|COM_IF_PC9861K
argument|case IO_COM2: a =
literal|1
argument|; io =
literal|0
argument|; type = COM_IF_PC9861K; break; 	    case IO_COM3: a =
literal|2
argument|; io =
literal|0
argument|; type = COM_IF_PC9861K; break;
endif|#
directive|endif
comment|/* COM_IF_PC9861K */
ifdef|#
directive|ifdef
name|COM_IF_PIO9032B
comment|/* PIO9032B : I/O address is changeable */
argument|case IO_COM_PIO9032B_2: 			a =
literal|1
argument|; io = io_base&
literal|0xff00
argument|; 			type = COM_IF_PIO9032B; break; 	    case IO_COM_PIO9032B_3: 			a =
literal|2
argument|; io = io_base&
literal|0xff00
argument|; 			type = COM_IF_PIO9032B; break;
endif|#
directive|endif
comment|/* COM_IF_PIO9032B */
ifdef|#
directive|ifdef
name|COM_IF_B98_01
argument|case IO_COM_B98_01_2: 			a =
literal|1
argument|; io =
literal|0
argument|; type = COM_IF_B98_01; break; 	    case IO_COM_B98_01_3: 			a =
literal|2
argument|; io =
literal|0
argument|; type = COM_IF_B98_01; break;
endif|#
directive|endif
comment|/* COM_IF_B98_01*/
argument|default:
comment|/* i/o address not match */
argument|return -
literal|1
argument|; 	}  	com->pc98_if_type	= type; 	com->data_port		= io | PC98SIO_data_port(a); 	com->cmd_port		= io | PC98SIO_cmd_port(a); 	com->sts_port		= io | PC98SIO_sts_port(a); 	com->in_modem_port	= io | PC98SIO_in_modem_port(a); 	com->intr_ctrl_port	= io | PC98SIO_intr_ctrl_port(a); 	return
literal|0
argument|; }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 defined */
end_comment

end_unit

