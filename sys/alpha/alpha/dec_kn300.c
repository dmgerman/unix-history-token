begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
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
file|<alpha/mcbus/mcbusreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/mcbus/mcbusvar.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<alpha/mcbus/mcpciareg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/mcbsu/mcpciavar.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/pci_kn300.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sio.h"
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

begin_decl_stmt
name|void
name|dec_kn300_init
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
name|dec_kn300_cons_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALPHASERVER_4100
value|"AlphaServer 4100"
end_define

begin_decl_stmt
specifier|const
name|struct
name|alpha_variation_table
name|dec_kn300_variations
index|[]
init|=
block|{
block|{
literal|0
block|,
name|ALPHASERVER_4100
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

begin_if
if|#
directive|if
name|NSC
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|int
name|siocnattach
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|siogdbattach
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|sccnattach
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
name|dec_kn300_init
parameter_list|()
block|{
name|u_int64_t
name|variation
decl_stmt|;
name|platform
operator|.
name|family
operator|=
name|ALPHASERVER_4100
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
name|dec_kn300_variations
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
literal|"mcbus"
expr_stmt|;
name|platform
operator|.
name|cons_init
operator|=
name|dec_kn300_cons_init
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|comconsole
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|dec_kn300_cons_init
parameter_list|()
block|{
if|#
directive|if
literal|0
block|struct ctb *ctb;
comment|/*	mcpcia_init(); */
ifdef|#
directive|ifdef
name|DDB
block|siogdbattach(0x2f8, 57600);
endif|#
directive|endif
block|ctb = (struct ctb *)(((caddr_t)hwrpb) + hwrpb->rpb_ctb_off);  	switch (ctb->ctb_term_type) { 	case 2:
comment|/* serial console ... */
comment|/* 		 * Delay to allow PROM putchars to complete. 		 * FIFO depth * character time, 		 * character time = (1000000 / (defaultrate / 10)) 		 */
block|DELAY(160000000 / comcnrate); 		comconsole = 0; 		if (siocnattach(0x3f8, comcnrate)) 			panic("can't init serial console"); 		break;  	case 3:
if|#
directive|if
name|NSC
operator|>
literal|0
block|sccnattach();
else|#
directive|else
block|panic("not configured to use display&& keyboard console");
endif|#
directive|endif
block|break;  	default: 		printf("ctb->ctb_term_type = 0x%lx\n", ctb->ctb_term_type); 		printf("ctb->ctb_turboslot = 0x%lx\n", ctb->ctb_turboslot);  		panic("consinit: unknown console type %ld\n", 		    ctb->ctb_term_type); 	}
endif|#
directive|endif
block|}
end_function

end_unit

