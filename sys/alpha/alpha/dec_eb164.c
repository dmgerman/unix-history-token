begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* $NetBSD: dec_eb164.c,v 1.26 1998/04/17 02:45:19 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 1997 by Matthew Jacob for NASA/Ames Research Center  */
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
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<sys/termios.h>
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

begin_decl_stmt
name|void
name|dec_eb164_init
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
name|dec_eb164_cons_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
block|}
end_function

begin_function
specifier|static
name|void
name|dec_eb164_cons_init
parameter_list|()
block|{
name|cia_init
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DDB
name|siocnattach
argument_list|(
literal|0x3f8
argument_list|,
literal|57600
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|struct ctb *ctb; 	struct cia_config *ccp; 	extern struct cia_config cia_configuration;  	ccp =&cia_configuration; 	cia_init(ccp, 0);  	ctb = (struct ctb *)(((caddr_t)hwrpb) + hwrpb->rpb_ctb_off);  	switch (ctb->ctb_term_type) { 	case 2:
comment|/* serial console ... */
comment|/* XXX */
block|{
comment|/* 			 * Delay to allow PROM putchars to complete. 			 * FIFO depth * character time, 			 * character time = (1000000 / (defaultrate / 10)) 			 */
block|DELAY(160000000 / comcnrate);  			if(comcnattach(&ccp->cc_iot, 0x3f8, comcnrate, 			    COM_FREQ, 			    (TTYDEF_CFLAG& ~(CSIZE | PARENB)) | CS8)) 				panic("can't init serial console");  			break; 		}  	case 3:
if|#
directive|if
name|NPCKBD
operator|>
literal|0
comment|/* display console ... */
comment|/* XXX */
block|(void) pckbc_cnattach(&ccp->cc_iot, PCKBC_KBD_SLOT);  		if ((ctb->ctb_turboslot& 0xffff) == 0) 			isa_display_console(&ccp->cc_iot,&ccp->cc_memt); 		else 			pci_display_console(&ccp->cc_iot,&ccp->cc_memt,&ccp->cc_pc, (ctb->ctb_turboslot>> 8)& 0xff, 			    ctb->ctb_turboslot& 0xff, 0);
else|#
directive|else
block|panic("not configured to use display&& keyboard console");
endif|#
directive|endif
block|break;  	default: 		printf("ctb->ctb_term_type = 0x%lx\n", ctb->ctb_term_type); 		printf("ctb->ctb_turboslot = 0x%lx\n", ctb->ctb_turboslot);  		panic("consinit: unknown console type %d\n", 		    ctb->ctb_term_type); 	}
endif|#
directive|endif
block|}
end_function

end_unit

