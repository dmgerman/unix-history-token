begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 1997 by Matthew Jacob for NASA/Ames Research Center  */
end_comment

begin_comment
comment|/*  * Port to based on NetBSD/axp by Wilko Bulte<wilko@freebsd.org>  * FreeBSD version based on:  *     NetBSD: dec_eb64plus.c,v 1.15 1998/11/19 02:20:07 ross Exp  *  * Some info on the Aspen Alpine as this might be hard to come by:  * - Hardware is close enough to the DEC EB64+ design to allow it to run  *   the EB64+ SRM console f/w  * - 3 PCI slots, closest to the SIMMs: Alpine calls this slot C  *                the middle one Alpine calls this slot B  *		  the 3rd one is Alpine calls this slot A  *	(A, B, C is silkscreened on the PCB)  * - embedded NCR810, located at PCI slot 5  * - 3 ISA slots, hanging off an Intel 82378IB PCI-ISA bridge at PCI slot 8  * - embedded floppy, PC keyboard interface, PS/2 mouse interface, 2x serial  *   ports and a parallel port. All of this hiding after the ISA bridge  */
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
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/apecsreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/apecsvar.h>
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
name|dec_eb64plus_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_eb64plus_cons_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_eb64plus_intr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eb64plus_intr_enable
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ../pci/pci_eb64plus_intr.s */
end_comment

begin_function_decl
specifier|extern
name|void
name|eb64plus_intr_disable
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ../pci/pci_eb64plus_intr.s */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|bootdev_protocol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bootdev_boot_dev_type
parameter_list|(
name|void
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
name|sccnattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|struct
name|alpha_variation_table
name|dec_eb64plus_variations
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"DEC EB64-plus"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|dec_eb64plus_init
parameter_list|()
block|{
name|u_int64_t
name|variation
decl_stmt|;
name|platform
operator|.
name|family
operator|=
literal|"EB64+"
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
name|variation
operator|=
name|hwrpb
operator|->
name|rpb_variation
operator|&
name|SV_ST_MASK
expr_stmt|;
if|if
condition|(
operator|(
name|platform
operator|.
name|model
operator|=
name|alpha_variation_name
argument_list|(
name|variation
argument_list|,
name|dec_eb64plus_variations
argument_list|)
operator|)
operator|==
name|NULL
condition|)
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
literal|"apecs"
expr_stmt|;
name|platform
operator|.
name|cons_init
operator|=
name|dec_eb64plus_cons_init
expr_stmt|;
name|platform
operator|.
name|pci_intr_init
operator|=
name|dec_eb64plus_intr_init
expr_stmt|;
comment|/* SRM handles PCI interrupt mapping */
name|platform
operator|.
name|pci_intr_map
operator|=
name|NULL
expr_stmt|;
comment|/* see ../pci/pci_eb64plus_intr.s for intr. dis/enable */
name|platform
operator|.
name|pci_intr_disable
operator|=
name|eb64plus_intr_disable
expr_stmt|;
name|platform
operator|.
name|pci_intr_enable
operator|=
name|eb64plus_intr_enable
expr_stmt|;
block|}
end_function

begin_comment
comment|/* XXX for forcing comconsole when srm serial console is used */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|comconsole
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* init the console, serial or graphics */
end_comment

begin_function
specifier|static
name|void
name|dec_eb64plus_cons_init
parameter_list|()
block|{
name|struct
name|ctb
modifier|*
name|ctb
decl_stmt|;
name|apecs_init
argument_list|()
expr_stmt|;
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
comment|/* 			 * force a comconsole on com1 if the SRM has a serial 			 * console. 			 */
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
if|#
directive|if
name|NSC
operator|>
literal|0
comment|/* graphics adapter console */
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

begin_comment
comment|/*  * The SRM console may have left some some interrupts enabled.  */
end_comment

begin_function
specifier|static
name|void
name|dec_eb64plus_intr_init
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* disable all PCI interrupts */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|32
condition|;
name|i
operator|++
control|)
comment|/* 32 ?? NetBSD sez so */
name|eb64plus_intr_disable
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|/* Enable ISA-PCI cascade interrupt */
name|eb64plus_intr_enable
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

