begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1998 Matthias Apitz. All rights reserved.  *  *   Copyright (c) 1998, 1999 Hellmuth Michaelis. All rights reserved.   *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_isic_pcmcia.c - i4b FreeBSD PCMCIA support  *	----------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Mon Apr 26 10:52:57 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"isic.h"
end_include

begin_include
include|#
directive|include
file|"opt_i4b.h"
end_include

begin_include
include|#
directive|include
file|"card.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NISIC
operator|>
literal|0
operator|)
operator|&&
operator|(
name|NCARD
operator|>
literal|0
operator|)
end_if

begin_include
include|#
directive|include
file|"apm.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_include
include|#
directive|include
file|<sys/ioccom.h>
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<pccard/cardinfo.h>
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

begin_include
include|#
directive|include
file|<machine/i4b_debug.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_trace.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_l1.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_isac.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_hscx.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_l1l2.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_mbuf.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_global.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300006
operator|)
end_if

begin_function_decl
name|void
name|isicintr
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|isicintr
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|isicattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*    * PC-Card (PCMCIA) specific code.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|isic_pccard_init
name|__P
argument_list|(
operator|(
expr|struct
name|pccard_devinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|isic_unload
name|__P
argument_list|(
operator|(
expr|struct
name|pccard_devinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|isic_card_intr
name|__P
argument_list|(
operator|(
expr|struct
name|pccard_devinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|<
literal|3
end_if

begin_decl_stmt
specifier|static
name|struct
name|pccard_device
name|isic_info
init|=
block|{
literal|"isic"
block|,
name|isic_pccard_init
block|,
name|isic_unload
block|,
name|isic_card_intr
block|,
literal|0
block|,
comment|/* Attributes - presently unused */
operator|&
name|net_imask
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DATA_SET
argument_list|(
name|pccarddrv_set
argument_list|,
name|isic_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|PCCARD_MODULE
argument_list|(
name|isic
argument_list|,
name|isic_pccard_init
argument_list|,
name|isic_unload
argument_list|,
name|isic_card_intr
argument_list|,
literal|0
argument_list|,
name|net_imask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Initialize the device - called from Slot manager.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|opened
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our cards status */
end_comment

begin_function
specifier|static
name|int
name|isic_pccard_init
parameter_list|(
name|devi
parameter_list|)
name|struct
name|pccard_devinfo
modifier|*
name|devi
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|AVM_A1_PCMCIA
name|struct
name|isa_device
modifier|*
name|is
init|=
operator|&
name|devi
operator|->
name|isahd
decl_stmt|;
if|if
condition|(
operator|(
literal|1
operator|<<
name|is
operator|->
name|id_unit
operator|)
operator|&
name|opened
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
name|opened
operator||=
literal|1
operator|<<
name|is
operator|->
name|id_unit
expr_stmt|;
name|printf
argument_list|(
literal|"isic%d: PCMCIA init, irqmask = 0x%x (%d), iobase = 0x%x\n"
argument_list|,
name|is
operator|->
name|id_unit
argument_list|,
name|is
operator|->
name|id_irq
argument_list|,
name|devi
operator|->
name|slt
operator|->
name|irq
argument_list|,
name|is
operator|->
name|id_iobase
argument_list|)
expr_stmt|;
comment|/*  	 * look if there is really an AVM PCMCIA Fritz!Card and 	 * setup the card specific stuff 	 */
name|isic_probe_avma1_pcmcia
argument_list|(
name|is
argument_list|)
expr_stmt|;
comment|/* ap: 	 * XXX what's to do with the return value? 	 */
comment|/* 	 * try to attach the PCMCIA card as a normal A1 card 	 */
name|isic_realattach
argument_list|(
name|is
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|isic_unload
parameter_list|(
name|devi
parameter_list|)
name|struct
name|pccard_devinfo
modifier|*
name|devi
decl_stmt|;
block|{
name|struct
name|isa_device
modifier|*
name|is
init|=
operator|&
name|devi
operator|->
name|isahd
decl_stmt|;
name|printf
argument_list|(
literal|"isic%d: unloaded\n"
argument_list|,
name|is
operator|->
name|id_unit
argument_list|)
expr_stmt|;
name|opened
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|is
operator|->
name|id_unit
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * card_intr - Shared interrupt called from  * front end of PC-Card handler.  */
end_comment

begin_function
specifier|static
name|int
name|isic_card_intr
parameter_list|(
name|devi
parameter_list|)
name|struct
name|pccard_devinfo
modifier|*
name|devi
decl_stmt|;
block|{
name|isicintr
argument_list|(
name|devi
operator|->
name|isahd
operator|.
name|id_unit
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (NISIC> 0)&& (NCARD> 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

end_unit

