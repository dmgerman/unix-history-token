begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: dec_eb164.c,v 1.26 1998/04/17 02:45:19 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 1997 by Matthew Jacob for NASA/Ames Research Center  */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/ciavar.h>
end_include

begin_include
include|#
directive|include
file|"sc.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CONSPEED
end_ifndef

begin_define
define|#
directive|define
name|CONSPEED
value|TTYDEF_SPEED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|comcnrate
init|=
name|CONSPEED
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dec_eb164_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_eb164_cons_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|eb164_intr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eb164_intr_enable
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eb164_intr_disable
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eb164_intr_enable_icsr
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eb164_intr_disable_icsr
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|siocnattach
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|siogdbattach
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sccnattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|dec_eb164_init
parameter_list|()
block|{
name|platform
operator|.
name|family
operator|=
literal|"EB164"
expr_stmt|;
if|if
condition|(
operator|(
name|platform
operator|.
name|model
operator|=
name|alpha_dsr_sysname
argument_list|()
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* XXX Don't know the system variations, yet. */
name|platform
operator|.
name|model
operator|=
name|alpha_unknown_sysname
argument_list|()
expr_stmt|;
block|}
name|platform
operator|.
name|iobus
operator|=
literal|"cia"
expr_stmt|;
name|platform
operator|.
name|cons_init
operator|=
name|dec_eb164_cons_init
expr_stmt|;
name|platform
operator|.
name|pci_intr_init
operator|=
name|eb164_intr_init
expr_stmt|;
name|platform
operator|.
name|pci_intr_map
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|platform
operator|.
name|model
argument_list|,
literal|"Digital AlphaPC 164 "
argument_list|,
literal|20
argument_list|)
operator|==
literal|0
condition|)
block|{
name|platform
operator|.
name|pci_intr_disable
operator|=
name|eb164_intr_disable_icsr
expr_stmt|;
name|platform
operator|.
name|pci_intr_enable
operator|=
name|eb164_intr_enable_icsr
expr_stmt|;
block|}
else|else
block|{
name|platform
operator|.
name|pci_intr_disable
operator|=
name|eb164_intr_disable
expr_stmt|;
name|platform
operator|.
name|pci_intr_enable
operator|=
name|eb164_intr_enable
expr_stmt|;
block|}
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|comconsole
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX for forcing comconsole when srm serial console is used */
end_comment

begin_function
specifier|static
name|void
name|dec_eb164_cons_init
parameter_list|()
block|{
name|struct
name|ctb
modifier|*
name|ctb
decl_stmt|;
name|cia_init
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DDB
name|siogdbattach
argument_list|(
literal|0x2f8
argument_list|,
literal|57600
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ctb
operator|=
operator|(
expr|struct
name|ctb
operator|*
operator|)
operator|(
operator|(
operator|(
name|caddr_t
operator|)
name|hwrpb
operator|)
operator|+
name|hwrpb
operator|->
name|rpb_ctb_off
operator|)
expr_stmt|;
switch|switch
condition|(
name|ctb
operator|->
name|ctb_term_type
condition|)
block|{
case|case
literal|2
case|:
comment|/* serial console ... */
comment|/* XXX */
block|{
comment|/* 			 * Delay to allow PROM putchars to complete. 			 * FIFO depth * character time, 			 * character time = (1000000 / (defaultrate / 10)) 			 */
name|DELAY
argument_list|(
literal|160000000
operator|/
name|comcnrate
argument_list|)
expr_stmt|;
comment|/* 			 * Force a comconsole on com1 if the SRM has a serial 			 * console. 			 */
name|comconsole
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|siocnattach
argument_list|(
literal|0x3f8
argument_list|,
name|comcnrate
argument_list|)
condition|)
name|panic
argument_list|(
literal|"can't init serial console"
argument_list|)
expr_stmt|;
name|boothowto
operator||=
name|RB_SERIAL
expr_stmt|;
break|break;
block|}
case|case
literal|3
case|:
comment|/* display console ... */
comment|/* XXX */
if|#
directive|if
name|NSC
operator|>
literal|0
name|sccnattach
argument_list|()
expr_stmt|;
else|#
directive|else
name|panic
argument_list|(
literal|"not configured to use display&& keyboard console"
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
default|default:
name|printf
argument_list|(
literal|"ctb->ctb_term_type = 0x%lx\n"
argument_list|,
name|ctb
operator|->
name|ctb_term_type
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ctb->ctb_turboslot = 0x%lx\n"
argument_list|,
name|ctb
operator|->
name|ctb_turboslot
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"consinit: unknown console type %d\n"
argument_list|,
operator|(
name|int
operator|)
name|ctb
operator|->
name|ctb_term_type
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|eb164_intr_init
parameter_list|()
block|{
comment|/*      * Enable ISA-PCI cascade interrupt.      */
name|eb164_intr_enable
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

