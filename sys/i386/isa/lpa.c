begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 William F. Jolitz, TeleMuse  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *   This software is a component of "386BSD" developed by   *   William F. Jolitz, TeleMuse.  * 4. Neither the name of the developer nor the name "386BSD"  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS A COMPONENT OF 386BSD DEVELOPED BY WILLIAM F. JOLITZ   * AND IS INTENDED FOR RESEARCH AND EDUCATIONAL PURPOSES ONLY. THIS   * SOFTWARE SHOULD NOT BE CONSIDERED TO BE A COMMERCIAL PRODUCT.   * THE DEVELOPER URGES THAT USERS WHO REQUIRE A COMMERCIAL PRODUCT   * NOT MAKE USE OF THIS WORK.  *  * FOR USERS WHO WISH TO UNDERSTAND THE 386BSD SYSTEM DEVELOPED  * BY WILLIAM F. JOLITZ, WE RECOMMEND THE USER STUDY WRITTEN   * REFERENCES SUCH AS THE  "PORTING UNIX TO THE 386" SERIES   * (BEGINNING JANUARY 1991 "DR. DOBBS JOURNAL", USA AND BEGINNING   * JUNE 1991 "UNIX MAGAZIN", GERMANY) BY WILLIAM F. JOLITZ AND   * LYNNE GREER JOLITZ, AS WELL AS OTHER BOOKS ON UNIX AND THE   * ON-LINE 386BSD USER MANUAL BEFORE USE. A BOOK DISCUSSING THE INTERNALS   * OF 386BSD ENTITLED "386BSD FROM THE INSIDE OUT" WILL BE AVAILABLE LATE 1992.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPER BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  * Device Driver for AT parallel printer port, without using interrupts  */
end_comment

begin_include
include|#
directive|include
file|"lpa.h"
end_include

begin_if
if|#
directive|if
name|NLPA
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/lptreg.h"
end_include

begin_comment
comment|/* internal used flags */
end_comment

begin_define
define|#
directive|define
name|OPEN
value|(0x01)
end_define

begin_comment
comment|/* device is open */
end_comment

begin_define
define|#
directive|define
name|INIT
value|(0x02)
end_define

begin_comment
comment|/* device in open procedure */
end_comment

begin_comment
comment|/* flags from minor device */
end_comment

begin_define
define|#
directive|define
name|LPA_PRIME
value|(0x20)
end_define

begin_comment
comment|/* prime printer on open   */
end_comment

begin_define
define|#
directive|define
name|LPA_ERROR
value|(0x10)
end_define

begin_comment
comment|/* log error conditions    */
end_comment

begin_define
define|#
directive|define
name|LPA_FLAG
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfc)
end_define

begin_define
define|#
directive|define
name|LPA_UNIT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x03)
end_define

begin_comment
comment|/* Printer Ready condition */
end_comment

begin_define
define|#
directive|define
name|LPS_INVERT
value|(LPS_NBSY | LPS_NACK |           LPS_SEL | LPS_NERR)
end_define

begin_define
define|#
directive|define
name|LPS_MASK
value|(LPS_NBSY | LPS_NACK | LPS_OUT | LPS_SEL | LPS_NERR)
end_define

begin_define
define|#
directive|define
name|NOT_READY
parameter_list|()
value|((inb(sc->sc_stat)^LPS_INVERT)&LPS_MASK)
end_define

begin_comment
comment|/* tsleep priority */
end_comment

begin_define
define|#
directive|define
name|LPPRI
value|((PZERO+8) | PCATCH)
end_define

begin_comment
comment|/* debug flags */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|lprintf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lprintf
value|if (lpaflag) printf
end_define

begin_decl_stmt
name|int
name|lpaflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|lpaprobe
argument_list|()
decl_stmt|,
name|lpaattach
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_driver
name|lpadriver
init|=
block|{
name|lpaprobe
block|,
name|lpaattach
block|,
literal|"lpa"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   copy usermode data into sysmode buffer  */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|1024
end_define

begin_comment
comment|/* **   Waittimes */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|(hz*16)
end_define

begin_comment
comment|/* Timeout while open device */
end_comment

begin_define
define|#
directive|define
name|LONG
value|(hz* 1)
end_define

begin_comment
comment|/* Timesteps while open      */
end_comment

begin_define
define|#
directive|define
name|MAX_SLEEP
value|(hz*5)
end_define

begin_comment
comment|/* Timeout while waiting for device ready */
end_comment

begin_define
define|#
directive|define
name|MAX_SPIN
value|20
end_define

begin_comment
comment|/* Max delay for device ready in usecs */
end_comment

begin_struct
struct|struct
name|lpa_softc
block|{
name|char
modifier|*
name|sc_cp
decl_stmt|;
comment|/* current data to print	*/
name|int
name|sc_count
decl_stmt|;
comment|/* bytes queued in sc_inbuf	*/
name|short
name|sc_data
decl_stmt|;
comment|/* printer data port		*/
name|short
name|sc_stat
decl_stmt|;
comment|/* printer control port		*/
name|short
name|sc_ctrl
decl_stmt|;
comment|/* printer status port		*/
name|u_char
name|sc_flags
decl_stmt|;
comment|/* flags (open and internal)	*/
name|u_char
name|sc_unit
decl_stmt|;
comment|/* unit-number			*/
name|char
comment|/* buffer for data		*/
modifier|*
name|sc_inbuf
decl_stmt|;
block|}
name|lpa_sc
index|[
name|NLPA
index|]
struct|;
end_struct

begin_comment
comment|/*  * Internal routine to lpaprobe to do port tests of one byte value  */
end_comment

begin_function
name|int
name|lpa_port_test
parameter_list|(
name|short
name|port
parameter_list|,
name|u_char
name|data
parameter_list|,
name|u_char
name|mask
parameter_list|)
block|{
name|int
name|temp
decl_stmt|,
name|timeout
decl_stmt|;
name|data
operator|=
name|data
operator|&
name|mask
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|timeout
operator|=
literal|100
expr_stmt|;
do|do
name|temp
operator|=
name|inb
argument_list|(
name|port
argument_list|)
operator|&
name|mask
expr_stmt|;
do|while
condition|(
name|temp
operator|!=
name|data
operator|&&
operator|--
name|timeout
condition|)
do|;
name|lprintf
argument_list|(
literal|"Port 0x%x\tout=%x\tin=%x\n"
argument_list|,
name|port
argument_list|,
name|data
argument_list|,
name|temp
argument_list|)
expr_stmt|;
return|return
operator|(
name|temp
operator|==
name|data
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * New lpaprobe routine written by Rodney W. Grimes, 3/25/1993  *  * Logic:  *	1) You should be able to write to and read back the same value  *	   to the data port.  Do an alternating zeros, alternating ones,  *	   walking zero, and walking one test to check for stuck bits.  *  *	2) You should be able to write to and read back the same value  *	   to the control port lower 5 bits, the upper 3 bits are reserved  *	   per the IBM PC technical reference manauls and different boards  *	   do different things with them.  Do an alternating zeros, alternating  *	   ones, walking zero, and walking one test to check for stuck bits.  *  *	   Some printers drag the strobe line down when the are powered off  * 	   so this bit has been masked out of the control port test.  *  *	   XXX Some printers may not like a fast pulse on init or strobe, I  *	   don't know at this point, if that becomes a problem these bits  *	   should be turned off in the mask byte for the control port test.  *  *	3) Set the data and control ports to a value of 0  */
end_comment

begin_function
name|int
name|lpaprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
name|short
name|port
decl_stmt|;
name|u_char
name|data
decl_stmt|;
name|u_char
name|mask
decl_stmt|;
name|int
name|i
decl_stmt|;
name|status
operator|=
name|IO_LPTSIZE
expr_stmt|;
name|port
operator|=
name|dvp
operator|->
name|id_iobase
operator|+
name|lpt_data
expr_stmt|;
name|mask
operator|=
literal|0xff
expr_stmt|;
while|while
condition|(
name|mask
operator|!=
literal|0
condition|)
block|{
name|data
operator|=
literal|0x55
expr_stmt|;
comment|/* Alternating zeros */
if|if
condition|(
operator|!
name|lpa_port_test
argument_list|(
name|port
argument_list|,
name|data
argument_list|,
name|mask
argument_list|)
condition|)
name|status
operator|=
literal|0
expr_stmt|;
name|data
operator|=
literal|0xaa
expr_stmt|;
comment|/* Alternating ones */
if|if
condition|(
operator|!
name|lpa_port_test
argument_list|(
name|port
argument_list|,
name|data
argument_list|,
name|mask
argument_list|)
condition|)
name|status
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
comment|/* Walking zero */
block|{
name|data
operator|=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|lpa_port_test
argument_list|(
name|port
argument_list|,
name|data
argument_list|,
name|mask
argument_list|)
condition|)
name|status
operator|=
literal|0
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
comment|/* Walking one */
block|{
name|data
operator|=
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|lpa_port_test
argument_list|(
name|port
argument_list|,
name|data
argument_list|,
name|mask
argument_list|)
condition|)
name|status
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|port
operator|==
name|dvp
operator|->
name|id_iobase
operator|+
name|lpt_data
condition|)
block|{
name|port
operator|=
name|dvp
operator|->
name|id_iobase
operator|+
name|lpt_control
expr_stmt|;
name|mask
operator|=
literal|0x1e
expr_stmt|;
block|}
else|else
name|mask
operator|=
literal|0
expr_stmt|;
block|}
name|outb
argument_list|(
name|dvp
operator|->
name|id_iobase
operator|+
name|lpt_data
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|dvp
operator|->
name|id_iobase
operator|+
name|lpt_control
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * lpaattach()  *	Install device  */
end_comment

begin_macro
name|lpaattach
argument_list|(
argument|isdp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|isdp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|lpa_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|lpa_sc
operator|+
name|isdp
operator|->
name|id_unit
expr_stmt|;
name|sc
operator|->
name|sc_unit
operator|=
name|isdp
operator|->
name|id_unit
expr_stmt|;
name|sc
operator|->
name|sc_data
operator|=
name|isdp
operator|->
name|id_iobase
operator|+
name|lpt_data
expr_stmt|;
name|sc
operator|->
name|sc_stat
operator|=
name|isdp
operator|->
name|id_iobase
operator|+
name|lpt_status
expr_stmt|;
name|sc
operator|->
name|sc_ctrl
operator|=
name|isdp
operator|->
name|id_iobase
operator|+
name|lpt_control
expr_stmt|;
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
name|LPC_NINIT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * lpaopen()  *	New open on device.  *  * We forbid all but first open  */
end_comment

begin_macro
name|lpaopen
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|lpa_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|delay
decl_stmt|;
comment|/* slept time in 1/hz seconds of tsleep */
name|int
name|err
decl_stmt|;
name|u_char
name|sta
decl_stmt|,
name|unit
decl_stmt|;
name|unit
operator|=
name|LPA_UNIT
argument_list|(
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|sta
operator|=
name|LPA_FLAG
argument_list|(
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
comment|/* minor number out of limits ? */
if|if
condition|(
name|unit
operator|>=
name|NLPA
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|sc
operator|=
name|lpa_sc
operator|+
name|unit
expr_stmt|;
comment|/* Attached ? */
if|if
condition|(
operator|!
name|sc
operator|->
name|sc_ctrl
condition|)
block|{
comment|/* not attached */
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Printer busy ? */
if|if
condition|(
name|sc
operator|->
name|sc_flags
condition|)
block|{
comment|/* too late .. */
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
comment|/* Have memory for buffer? */
name|sc
operator|->
name|sc_inbuf
operator|=
name|malloc
argument_list|(
name|BUFSIZE
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_inbuf
operator|==
literal|0
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
comment|/* Init printer */
name|sc
operator|->
name|sc_flags
operator|=
name|sta
operator||
name|INIT
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_flags
operator|&
name|LPA_PRIME
condition|)
block|{
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Select printer */
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
name|LPC_SEL
operator||
name|LPC_NINIT
argument_list|)
expr_stmt|;
comment|/* and wait for ready .. */
for|for
control|(
name|delay
operator|=
literal|0
init|;
name|NOT_READY
argument_list|()
condition|;
name|delay
operator|+=
name|LONG
control|)
block|{
if|if
condition|(
name|delay
operator|>=
name|TIMEOUT
condition|)
block|{
comment|/* too long waited .. */
name|sc
operator|->
name|sc_flags
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
comment|/* sleep a moment */
if|if
condition|(
operator|(
name|err
operator|=
name|tsleep
argument_list|(
name|sc
argument_list|,
name|LPPRI
argument_list|,
literal|"lpaopen"
argument_list|,
name|LONG
argument_list|)
operator|)
operator|!=
name|EWOULDBLOCK
condition|)
block|{
name|sc
operator|->
name|sc_flags
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
block|}
comment|/* Printer ready .. set variables */
name|sc
operator|->
name|sc_flags
operator||=
name|OPEN
expr_stmt|;
name|sc
operator|->
name|sc_count
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * pushbytes()  *	Workhorse for actually spinning and writing bytes to printer  */
end_comment

begin_expr_stmt
specifier|static
name|pushbytes
argument_list|(
argument|sc
argument_list|)
expr|struct
name|lpa_softc
operator|*
name|sc
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|spin
decl_stmt|,
name|err
decl_stmt|,
name|tic
decl_stmt|;
name|char
name|ch
decl_stmt|;
comment|/* loop for every character .. */
while|while
condition|(
name|sc
operator|->
name|sc_count
operator|>
literal|0
condition|)
block|{
comment|/* printer data */
name|ch
operator|=
operator|*
operator|(
name|sc
operator|->
name|sc_cp
operator|)
expr_stmt|;
name|sc
operator|->
name|sc_cp
operator|+=
literal|1
expr_stmt|;
name|sc
operator|->
name|sc_count
operator|-=
literal|1
expr_stmt|;
comment|/*                * Wait for printer ready.                * Loop 20 usecs testing BUSY bit, then sleep                * for exponentially increasing timeout. (vak)                */
for|for
control|(
name|spin
operator|=
literal|0
init|;
name|NOT_READY
argument_list|()
operator|&&
name|spin
operator|<
name|MAX_SPIN
condition|;
operator|++
name|spin
control|)
name|DELAY
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|spin
operator|>=
name|MAX_SPIN
condition|)
block|{
name|tic
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|NOT_READY
argument_list|()
condition|)
block|{
comment|/* 				 * Now sleep, every cycle a 				 * little longer .. 				 */
name|tic
operator|=
name|tic
operator|+
name|tic
operator|+
literal|1
expr_stmt|;
comment|/*                                  * But no more than 10 seconds. (vak)                                  */
if|if
condition|(
name|tic
operator|>
name|MAX_SLEEP
condition|)
name|tic
operator|=
name|MAX_SLEEP
expr_stmt|;
name|err
operator|=
name|tsleep
argument_list|(
name|sc
argument_list|,
name|LPPRI
argument_list|,
literal|"lpawrite"
argument_list|,
name|tic
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|EWOULDBLOCK
condition|)
block|{
return|return
operator|(
name|err
operator|)
return|;
block|}
block|}
block|}
comment|/* output data */
name|outb
argument_list|(
name|sc
operator|->
name|sc_data
argument_list|,
name|ch
argument_list|)
expr_stmt|;
comment|/* strobe */
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
name|LPC_NINIT
operator||
name|LPC_SEL
operator||
name|LPC_STB
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
name|LPC_NINIT
operator||
name|LPC_SEL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * lpaclose()  *	Close on lp.  Try to flush data in buffer out.  */
end_comment

begin_macro
name|lpaclose
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|lpa_softc
modifier|*
name|sc
init|=
name|lpa_sc
operator|+
name|LPA_UNIT
argument_list|(
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
decl_stmt|;
comment|/* If there's queued data, try to flush it */
operator|(
name|void
operator|)
name|pushbytes
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* really close .. quite simple :-)  */
name|outb
argument_list|(
name|sc
operator|->
name|sc_ctrl
argument_list|,
name|LPC_NINIT
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_flags
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|sc
operator|->
name|sc_inbuf
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_inbuf
operator|=
literal|0
expr_stmt|;
comment|/* Sanity */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * lpawrite()  *	Copy from user's buffer, then print  */
end_comment

begin_macro
name|lpawrite
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|lpa_softc
modifier|*
name|sc
init|=
name|lpa_sc
operator|+
name|LPA_UNIT
argument_list|(
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* Write out old bytes from interrupted syscall */
if|if
condition|(
name|sc
operator|->
name|sc_count
operator|>
literal|0
condition|)
block|{
name|err
operator|=
name|pushbytes
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* main loop */
while|while
condition|(
operator|(
name|sc
operator|->
name|sc_count
operator|=
name|MIN
argument_list|(
name|BUFSIZE
argument_list|,
name|uio
operator|->
name|uio_resid
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
comment|/*  get from user-space  */
name|sc
operator|->
name|sc_cp
operator|=
name|sc
operator|->
name|sc_inbuf
expr_stmt|;
name|uiomove
argument_list|(
name|sc
operator|->
name|sc_inbuf
argument_list|,
name|sc
operator|->
name|sc_count
argument_list|,
name|uio
argument_list|)
expr_stmt|;
name|err
operator|=
name|pushbytes
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
return|return
operator|(
name|err
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|int
name|lpaioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
ifdef|#
directive|ifdef
name|THISISASAMPLE
case|case
name|XXX
case|:
name|dothis
expr_stmt|;
name|andthis
expr_stmt|;
name|andthat
expr_stmt|;
name|error
operator|=
name|x
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* THISISASAMPLE */
default|default:
name|error
operator|=
name|ENODEV
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NLPA> 0 */
end_comment

end_unit

