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
name|dec_kn300_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dec_kn300_cons_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|struct
name|ctb
modifier|*
name|ctb
decl_stmt|;
name|mcbus_init
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
comment|/* 		 * Delay to allow PROM putchars to complete. 		 * FIFO depth * character time, 		 * character time = (1000000 / (defaultrate / 10)) 		 */
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
case|case
literal|3
case|:
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
literal|"consinit: unknown cons type %ld\n"
argument_list|,
name|ctb
operator|->
name|ctb_term_type
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

