begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: dec_kn20aa.c,v 1.38 1998/04/17 02:45:19 mjacob Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
file|<alpha/pci/ciareg.h>
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
name|dec_kn20aa_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_kn20aa_cons_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_kn20aa_intr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_kn20aa_intr_map
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_kn20aa_intr_disable
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_kn20aa_intr_enable
parameter_list|(
name|int
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static void dec_kn20aa_device_register(struct device *, void *);
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|struct
name|alpha_variation_table
name|dec_kn20aa_variations
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"AlphaStation 500 or 600 (KN20AA)"
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
name|void
name|dec_kn20aa_init
parameter_list|()
block|{
name|u_int64_t
name|variation
decl_stmt|;
name|platform
operator|.
name|family
operator|=
literal|"AlphaStation 500 or 600 (KN20AA)"
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
name|dec_kn20aa_variations
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
literal|"cia"
expr_stmt|;
name|platform
operator|.
name|cons_init
operator|=
name|dec_kn20aa_cons_init
expr_stmt|;
name|platform
operator|.
name|pci_intr_init
operator|=
name|dec_kn20aa_intr_init
expr_stmt|;
name|platform
operator|.
name|pci_intr_map
operator|=
name|dec_kn20aa_intr_map
expr_stmt|;
name|platform
operator|.
name|pci_intr_disable
operator|=
name|dec_kn20aa_intr_disable
expr_stmt|;
name|platform
operator|.
name|pci_intr_enable
operator|=
name|dec_kn20aa_intr_enable
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|dec_kn20aa_cons_init
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
literal|9600
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

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|static void dec_kn20aa_device_register(dev, aux) 	struct device *dev; 	void *aux; { 	static int found, initted, scsiboot, netboot; 	static struct device *pcidev, *scsidev; 	struct bootdev_data *b = bootdev_data; 	struct device *parent = dev->dv_parent; 	struct cfdata *cf = dev->dv_cfdata; 	struct cfdriver *cd = cf->cf_driver;  	if (found) 		return;  	if (!initted) { 		scsiboot = (strcmp(b->protocol, "SCSI") == 0); 		netboot = (strcmp(b->protocol, "BOOTP") == 0);
if|#
directive|if
literal|0
end_if

begin_endif
unit|printf("scsiboot = %d, netboot = %d\n", scsiboot, netboot);
endif|#
directive|endif
end_endif

begin_if
unit|initted =1; 	}  	if (pcidev == NULL) { 		if (strcmp(cd->cd_name, "pci")) 			return; 		else { 			struct pcibus_attach_args *pba = aux;  			if ((b->slot / 1000) != pba->pba_bus) 				return; 	 			pcidev = dev;
if|#
directive|if
literal|0
end_if

begin_endif
unit|printf("\npcidev = %s\n", pcidev->dv_xname);
endif|#
directive|endif
end_endif

begin_comment
unit|return; 		} 	}  	if (scsiboot&& (scsidev == NULL)) { 		if (parent != pcidev) 			return; 		else { 			struct pci_attach_args *pa = aux;  			if ((b->slot % 1000) != pa->pa_device) 				return;
comment|/* XXX function? */
end_comment

begin_if
unit|scsidev = dev;
if|#
directive|if
literal|0
end_if

begin_endif
unit|printf("\nscsidev = %s\n", scsidev->dv_xname);
endif|#
directive|endif
end_endif

begin_comment
unit|return; 		} 	}  	if (scsiboot&& 	    (!strcmp(cd->cd_name, "sd") || 	     !strcmp(cd->cd_name, "st") || 	     !strcmp(cd->cd_name, "cd"))) { 		struct scsipibus_attach_args *sa = aux;  		if (parent->dv_parent != scsidev) 			return;  		if (b->unit / 100 != sa->sa_sc_link->scsipi_scsi.target) 			return;
comment|/* XXX LUN! */
end_comment

begin_comment
unit|switch (b->boot_dev_type) { 		case 0: 			if (strcmp(cd->cd_name, "sd")&& 			    strcmp(cd->cd_name, "cd")) 				return; 			break; 		case 1: 			if (strcmp(cd->cd_name, "st")) 				return; 			break; 		default: 			return; 		}
comment|/* we've found it! */
end_comment

begin_if
unit|booted_device = dev;
if|#
directive|if
literal|0
end_if

begin_endif
unit|printf("\nbooted_device = %s\n", booted_device->dv_xname);
endif|#
directive|endif
end_endif

begin_comment
unit|found = 1; 	}  	if (netboot) { 		if (parent != pcidev) 			return; 		else { 			struct pci_attach_args *pa = aux;  			if ((b->slot % 1000) != pa->pa_device) 				return;
comment|/* XXX function? */
end_comment

begin_if
unit|booted_device = dev;
if|#
directive|if
literal|0
end_if

begin_endif
unit|printf("\nbooted_device = %s\n", booted_device->dv_xname);
endif|#
directive|endif
end_endif

begin_endif
unit|found = 1; 			return; 		} 	} }
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KN20AA_MAX_IRQ
value|32
end_define

begin_function
name|void
name|dec_kn20aa_intr_init
parameter_list|()
block|{
comment|/* 	 * Enable ISA-PCI cascade interrupt. 	 */
name|dec_kn20aa_intr_enable
argument_list|(
literal|31
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dec_kn20aa_intr_map
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|pcicfgregs
modifier|*
name|cfg
decl_stmt|;
name|cfg
operator|=
operator|(
name|pcicfgregs
operator|*
operator|)
name|arg
expr_stmt|;
comment|/* 	 * Slot->interrupt translation.  Appears to work, though it 	 * may not hold up forever. 	 * 	 * The DEC engineers who did this hardware obviously engaged 	 * in random drug testing. 	 */
switch|switch
condition|(
name|cfg
operator|->
name|slot
condition|)
block|{
case|case
literal|11
case|:
case|case
literal|12
case|:
name|cfg
operator|->
name|intline
operator|=
operator|(
operator|(
name|cfg
operator|->
name|slot
operator|-
literal|11
operator|)
operator|+
literal|0
operator|)
operator|*
literal|4
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|cfg
operator|->
name|intline
operator|=
literal|8
expr_stmt|;
break|break;
case|case
literal|9
case|:
name|cfg
operator|->
name|intline
operator|=
literal|12
expr_stmt|;
break|break;
case|case
literal|6
case|:
comment|/* 21040 on AlphaStation 500 */
name|cfg
operator|->
name|intline
operator|=
literal|13
expr_stmt|;
break|break;
case|case
literal|8
case|:
name|cfg
operator|->
name|intline
operator|=
literal|16
expr_stmt|;
break|break;
case|case
literal|10
case|:
comment|/* 8275EB on AlphaStation 500 */
return|return;
default|default:
if|if
condition|(
operator|!
name|cfg
operator|->
name|bus
condition|)
block|{
name|printf
argument_list|(
literal|"dec_kn20aa_intr_map: weird slot %d\n"
argument_list|,
name|cfg
operator|->
name|slot
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
name|cfg
operator|->
name|intline
operator|=
name|cfg
operator|->
name|slot
expr_stmt|;
block|}
block|}
name|cfg
operator|->
name|intline
operator|+=
name|cfg
operator|->
name|bus
operator|*
literal|16
expr_stmt|;
if|if
condition|(
name|cfg
operator|->
name|intline
operator|>
name|KN20AA_MAX_IRQ
condition|)
name|panic
argument_list|(
literal|"dec_kn20aa_intr_map: cfg->intline too large (%d)\n"
argument_list|,
name|cfg
operator|->
name|intline
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dec_kn20aa_intr_enable
parameter_list|(
name|irq
parameter_list|)
name|int
name|irq
decl_stmt|;
block|{
comment|/* 	 * From disassembling small bits of the OSF/1 kernel: 	 * the following appears to enable a given interrupt request. 	 * "blech."  I'd give valuable body parts for better docs or 	 * for a good decompiler. 	 */
name|alpha_mb
argument_list|()
expr_stmt|;
name|REGVAL
argument_list|(
literal|0x8780000000L
operator|+
literal|0x40L
argument_list|)
operator||=
operator|(
literal|1
operator|<<
name|irq
operator|)
expr_stmt|;
comment|/* XXX */
name|alpha_mb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dec_kn20aa_intr_disable
parameter_list|(
name|irq
parameter_list|)
name|int
name|irq
decl_stmt|;
block|{
name|alpha_mb
argument_list|()
expr_stmt|;
name|REGVAL
argument_list|(
literal|0x8780000000L
operator|+
literal|0x40L
argument_list|)
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|irq
operator|)
expr_stmt|;
comment|/* XXX */
name|alpha_mb
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

