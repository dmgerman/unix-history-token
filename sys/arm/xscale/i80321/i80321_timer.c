begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: i80321_timer.c,v 1.7 2003/07/27 04:52:28 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Timer/clock support for the Intel i80321 I/O processor.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/i80321reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/i80321var.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/xscalevar.h>
end_include

begin_include
include|#
directive|include
file|"opt_timer.h"
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|i80321_hardclock_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_struct
struct|struct
name|i80321_timer_softc
block|{
name|device_t
name|dev
decl_stmt|;
block|}
name|timer_softc
struct|;
end_struct

begin_function_decl
specifier|static
name|unsigned
name|i80321_timer_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|uint32_t
name|counts_per_hz
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XSCALE_DISABLE_CCNT
end_ifdef

begin_decl_stmt
specifier|static
name|uint32_t
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|last
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|ticked
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|COUNTS_PER_SEC
end_ifndef

begin_define
define|#
directive|define
name|COUNTS_PER_SEC
value|200000000
end_define

begin_comment
comment|/* 200MHz */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COUNTS_PER_USEC
value|(COUNTS_PER_SEC / 1000000)
end_define

begin_decl_stmt
specifier|static
name|struct
name|timecounter
name|i80321_timer_timecounter
init|=
block|{
name|i80321_timer_get_timecount
block|,
comment|/* get_timecount */
name|NULL
block|,
comment|/* no poll_pps */
operator|~
literal|0u
block|,
comment|/* counter_mask */
ifdef|#
directive|ifdef
name|XSCALE_DISABLE_CCNT
name|COUNTS_PER_SEC
block|,
else|#
directive|else
name|COUNTS_PER_SEC
operator|*
literal|3
block|,
comment|/* frequency */
endif|#
directive|endif
literal|"i80321 timer"
block|,
comment|/* name */
literal|1000
comment|/* quality */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|i80321_timer_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"i80321 timer"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|i80321_timer_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|timer_softc
operator|.
name|dev
operator|=
name|dev
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|i80321_timer_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|i80321_timer_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|i80321_timer_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|i80321_timer_driver
init|=
block|{
literal|"itimer"
block|,
name|i80321_timer_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|i80321_timer_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|i80321_timer_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|itimer
argument_list|,
name|iq
argument_list|,
name|i80321_timer_driver
argument_list|,
name|i80321_timer_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|clockhandler
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|uint32_t
name|tmr1_read
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm __volatile("mrc p6, 0, %0, c1, c1, 0"
block|:
literal|"=r"
operator|(
name|rv
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|rv
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|tmr1_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c1, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint32_t
name|tcr1_read
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm __volatile("mrc p6, 0, %0, c3, c1, 0"
block|:
literal|"=r"
operator|(
name|rv
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|rv
operator|)
return|;
end_return

begin_function
unit|} static
name|__inline
name|void
name|tcr1_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c3, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|trr1_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 1, %0, c5, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint32_t
name|tmr0_read
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm __volatile("mrc p6, 0, %0, c0, c1, 0"
block|:
literal|"=r"
operator|(
name|rv
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|rv
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|tmr0_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c0, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint32_t
name|tcr0_read
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm __volatile("mrc p6, 0, %0, c2, c1, 0"
block|:
literal|"=r"
operator|(
name|rv
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|rv
operator|)
return|;
end_return

begin_function
unit|} static
name|__inline
name|void
name|tcr0_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c2, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|trr0_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c4, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|tisr_write
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c6, c1, 0"
block|: 		:
literal|"r"
operator|(
name|val
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint32_t
name|tisr_read
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
asm|__asm __volatile("mrc p6, 0, %0, c6, c1, 0" : "=r" (ret));
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|i80321_timer_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|XSCALE_DISABLE_CCNT
name|uint32_t
name|cur
init|=
name|tcr0_read
argument_list|()
decl_stmt|;
if|if
condition|(
name|cur
operator|>
name|last
operator|&&
name|last
operator|!=
operator|-
literal|1
condition|)
block|{
name|offset
operator|+=
name|counts_per_hz
expr_stmt|;
if|if
condition|(
name|ticked
operator|>
literal|0
condition|)
name|ticked
operator|--
expr_stmt|;
block|}
if|if
condition|(
name|ticked
condition|)
block|{
name|offset
operator|+=
name|ticked
operator|*
name|counts_per_hz
expr_stmt|;
name|ticked
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|counts_per_hz
operator|-
name|cur
operator|+
name|offset
operator|)
return|;
else|#
directive|else
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile("mrc p14, 0, %0, c1, c0, 0\n"
block|:
literal|"=r"
operator|(
name|ret
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/*  * i80321_calibrate_delay:  *  *	Calibrate the delay loop.  */
end_comment

begin_macro
unit|void
name|i80321_calibrate_delay
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
comment|/* 	 * Just use hz=100 for now -- we'll adjust it, if necessary, 	 * in cpu_initclocks(). 	 */
name|counts_per_hz
operator|=
name|COUNTS_PER_SEC
operator|/
literal|100
expr_stmt|;
name|tmr0_write
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* stop timer */
name|tisr_write
argument_list|(
name|TISR_TMR0
argument_list|)
expr_stmt|;
comment|/* clear interrupt */
name|trr0_write
argument_list|(
name|counts_per_hz
argument_list|)
expr_stmt|;
comment|/* reload value */
name|tcr0_write
argument_list|(
name|counts_per_hz
argument_list|)
expr_stmt|;
comment|/* current value */
name|tmr0_write
argument_list|(
name|TMRx_ENABLE
operator||
name|TMRx_RELOAD
operator||
name|TMRx_CSEL_CORE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * cpu_initclocks:  *  *	Initialize the clock and get them going.  */
end_comment

begin_function
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|oldirqstate
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|rid
init|=
literal|0
decl_stmt|;
name|void
modifier|*
name|ihl
decl_stmt|;
name|device_t
name|dev
init|=
name|timer_softc
operator|.
name|dev
decl_stmt|;
if|if
condition|(
name|hz
operator|<
literal|50
operator|||
name|COUNTS_PER_SEC
operator|%
name|hz
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot get %d Hz clock; using 100 Hz\n"
argument_list|,
name|hz
argument_list|)
expr_stmt|;
name|hz
operator|=
literal|100
expr_stmt|;
block|}
name|tick
operator|=
literal|1000000
operator|/
name|hz
expr_stmt|;
comment|/* number of microseconds between interrupts */
comment|/* 	 * We only have one timer available; stathz and profhz are 	 * always left as 0 (the upper-layer clock code deals with 	 * this situation). 	 */
if|if
condition|(
name|stathz
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"Cannot get %d Hz statclock\n"
argument_list|,
name|stathz
argument_list|)
expr_stmt|;
name|stathz
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|profhz
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"Cannot get %d Hz profclock\n"
argument_list|,
name|profhz
argument_list|)
expr_stmt|;
name|profhz
operator|=
literal|0
expr_stmt|;
comment|/* Report the clock frequency. */
name|oldirqstate
operator|=
name|disable_interrupts
argument_list|(
name|I32_bit
argument_list|)
expr_stmt|;
name|irq
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|rid
argument_list|,
name|ICU_INT_TMR0
argument_list|,
name|ICU_INT_TMR0
argument_list|,
literal|1
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|irq
condition|)
name|panic
argument_list|(
literal|"Unable to setup the clock irq handler.\n"
argument_list|)
expr_stmt|;
else|else
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|irq
argument_list|,
name|INTR_TYPE_CLK
argument_list|,
name|clockhandler
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|ihl
argument_list|)
expr_stmt|;
name|tmr0_write
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* stop timer */
name|tisr_write
argument_list|(
name|TISR_TMR0
argument_list|)
expr_stmt|;
comment|/* clear interrupt */
name|counts_per_hz
operator|=
name|COUNTS_PER_SEC
operator|/
name|hz
expr_stmt|;
name|trr0_write
argument_list|(
name|counts_per_hz
argument_list|)
expr_stmt|;
comment|/* reload value */
name|tcr0_write
argument_list|(
name|counts_per_hz
argument_list|)
expr_stmt|;
comment|/* current value */
name|tmr0_write
argument_list|(
name|TMRx_ENABLE
operator||
name|TMRx_RELOAD
operator||
name|TMRx_CSEL_CORE
argument_list|)
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|i80321_timer_timecounter
argument_list|)
expr_stmt|;
name|restore_interrupts
argument_list|(
name|oldirqstate
argument_list|)
expr_stmt|;
name|rid
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|XSCALE_DISABLE_CCNT
comment|/* Enable the clock count register. */
asm|__asm __volatile("mrc p14, 0, %0, c0, c0, 0\n" : "=r" (rid));
name|rid
operator|&=
operator|~
operator|(
literal|1
operator|<<
literal|3
operator|)
expr_stmt|;
name|rid
operator||=
operator|(
literal|1
operator|<<
literal|2
operator|)
operator||
literal|1
expr_stmt|;
asm|__asm __volatile("mcr p14, 0, %0, c0, c0, 0\n"
block|: :
literal|"r"
operator|(
name|rid
operator|)
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/*  * DELAY:  *  *	Delay for at least N microseconds.  */
end_comment

begin_macro
unit|void
name|DELAY
argument_list|(
argument|int n
argument_list|)
end_macro

begin_block
block|{
name|uint32_t
name|cur
decl_stmt|,
name|last
decl_stmt|,
name|delta
decl_stmt|,
name|usecs
decl_stmt|;
comment|/* 	 * This works by polling the timer and counting the 	 * number of microseconds that go by. 	 */
name|last
operator|=
name|tcr0_read
argument_list|()
expr_stmt|;
name|delta
operator|=
name|usecs
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|n
operator|>
name|usecs
condition|)
block|{
name|cur
operator|=
name|tcr0_read
argument_list|()
expr_stmt|;
comment|/* Check to see if the timer has wrapped around. */
if|if
condition|(
name|last
operator|<
name|cur
condition|)
name|delta
operator|+=
operator|(
name|last
operator|+
operator|(
name|counts_per_hz
operator|-
name|cur
operator|)
operator|)
expr_stmt|;
else|else
name|delta
operator|+=
operator|(
name|last
operator|-
name|cur
operator|)
expr_stmt|;
name|last
operator|=
name|cur
expr_stmt|;
if|if
condition|(
name|delta
operator|>=
name|COUNTS_PER_USEC
condition|)
block|{
name|usecs
operator|+=
name|delta
operator|/
name|COUNTS_PER_USEC
expr_stmt|;
name|delta
operator|%=
name|COUNTS_PER_USEC
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * clockhandler:  *  *	Handle the hardclock interrupt.  */
end_comment

begin_function
name|int
name|clockhandler
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|trapframe
modifier|*
name|frame
init|=
name|arg
decl_stmt|;
name|ticked
operator|++
expr_stmt|;
name|tisr_write
argument_list|(
name|TISR_TMR0
argument_list|)
expr_stmt|;
name|hardclock
argument_list|(
name|TRAPF_USERMODE
argument_list|(
name|frame
argument_list|)
argument_list|,
name|TRAPF_PC
argument_list|(
name|frame
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i80321_hardclock_hook
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|i80321_hardclock_hook
call|)
argument_list|()
expr_stmt|;
return|return
operator|(
name|FILTER_HANDLED
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cpu_startprofclock
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|cpu_stopprofclock
parameter_list|(
name|void
parameter_list|)
block|{ 	 }
end_function

end_unit

