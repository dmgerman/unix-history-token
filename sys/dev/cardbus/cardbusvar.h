begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: cardbusvar.h,v 1.1.2.1 1999/02/16 16:46:08 haya Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 HAYAKAWA Koichi.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the author.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|SYS_DEV_PCCARD_CARDBUSVAR_H
end_if

begin_define
define|#
directive|define
name|SYS_DEV_PCCARD_CARDBUSVAR_H
end_define

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_typedef
typedef|typedef
name|pcitag_t
name|cardbustag_t
typedef|;
end_typedef

begin_comment
comment|/* XXX */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cardbus_functions
block|{
name|int
argument_list|(
argument|*cardbus_ctrl
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*cardbus_power
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*cardbus_mem_open
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*cardbus_mem_close
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*cardbus_io_open
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*cardbus_io_close
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
operator|*
operator|(
operator|*
name|cardbus_intr_establish
operator|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
name|irq
operator|,
name|int
name|level
operator|,
name|int
argument_list|(
operator|*
name|ih
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|sc
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*cardbus_intr_disestablish
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
name|ct
operator|,
name|void
operator|*
name|ih
operator|)
argument_list|)
expr_stmt|;
name|cardbustag_t
argument_list|(
argument|*cardbus_make_tag
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*cardbus_free_tag
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|cardbustag_t
operator|)
argument_list|)
expr_stmt|;
name|cardbusreg_t
argument_list|(
argument|*cardbus_conf_read
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|cardbustag_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*cardbus_conf_write
argument_list|)
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|cardbustag_t
operator|,
name|int
operator|,
name|cardbusreg_t
operator|)
argument_list|)
expr_stmt|;
block|}
name|cardbus_function_t
operator|,
typedef|*
name|cardbus_function_tag_t
typedef|;
end_typedef

begin_comment
comment|/********************************************************************** * struct cbslot_attach_args is the attach argument for cardbus slot. **********************************************************************/
end_comment

begin_struct
struct|struct
name|cbslot_attach_args
block|{
name|char
modifier|*
name|cba_busname
decl_stmt|;
name|bus_space_tag_t
name|cba_iot
decl_stmt|;
comment|/* cardbus i/o space tag */
name|bus_space_tag_t
name|cba_memt
decl_stmt|;
comment|/* cardbus mem space tag */
name|bus_dma_tag_t
name|cba_dmat
decl_stmt|;
comment|/* DMA tag */
name|int
name|cba_bus
decl_stmt|;
comment|/* cardbus bus number */
name|int
name|cba_function
decl_stmt|;
comment|/* slot number on this Host Bus Adaptor */
name|cardbus_chipset_tag_t
name|cba_cc
decl_stmt|;
comment|/* cardbus chipset */
name|cardbus_function_tag_t
name|cba_cf
decl_stmt|;
comment|/* cardbus functions */
name|int
name|cba_intrline
decl_stmt|;
comment|/* interrupt line */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cbslotcf_slot
value|cf_loc[0]
end_define

begin_define
define|#
directive|define
name|CBSLOT_UNK_SLOT
value|-1
end_define

begin_comment
comment|/********************************************************************** * struct cardslot_if is the interface for cardslot. **********************************************************************/
end_comment

begin_struct
struct|struct
name|cardslot_if
block|{
name|struct
name|device
modifier|*
argument_list|(
operator|*
name|if_card_attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|cardbus_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/********************************************************************** * struct cardbus_softc is the softc for cardbus card. **********************************************************************/
end_comment

begin_struct
struct|struct
name|cardbus_softc
block|{
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* fundamental device structure */
name|int
name|sc_bus
decl_stmt|;
comment|/* cardbus bus number */
name|int
name|sc_device
decl_stmt|;
comment|/* cardbus device number */
name|int
name|sc_intrline
decl_stmt|;
comment|/* CardBus intrline */
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
comment|/* CardBus I/O space tag */
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
comment|/* CardBus MEM space tag */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* DMA tag */
name|cardbus_chipset_tag_t
name|sc_cc
decl_stmt|;
comment|/* CardBus chipset */
name|cardbus_function_tag_t
name|sc_cf
decl_stmt|;
comment|/* CardBus function */
name|int
name|sc_volt
decl_stmt|;
comment|/* applied Vcc voltage */
define|#
directive|define
name|PCCARD_33V
value|0x02
define|#
directive|define
name|PCCARD_XXV
value|0x04
define|#
directive|define
name|PCCARD_YYV
value|0x08
name|struct
name|cardslot_if
name|sc_if
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|cardslot_if_setup
name|__P
argument_list|(
operator|(
expr|struct
name|cardbus_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************************************************************** * struct cbslot_attach_args is the attach argument for cardbus card. **********************************************************************/
end_comment

begin_struct
struct|struct
name|cardbus_attach_args
block|{
name|int
name|ca_unit
decl_stmt|;
name|cardbus_chipset_tag_t
name|ca_cc
decl_stmt|;
name|cardbus_function_tag_t
name|ca_cf
decl_stmt|;
name|bus_space_tag_t
name|ca_iot
decl_stmt|;
comment|/* CardBus I/O space tag */
name|bus_space_tag_t
name|ca_memt
decl_stmt|;
comment|/* CardBus MEM space tag */
name|bus_dma_tag_t
name|ca_dmat
decl_stmt|;
comment|/* DMA tag */
name|u_int
name|ca_device
decl_stmt|;
name|u_int
name|ca_function
decl_stmt|;
name|cardbustag_t
name|ca_tag
decl_stmt|;
name|cardbusreg_t
name|ca_id
decl_stmt|;
name|cardbusreg_t
name|ca_class
decl_stmt|;
comment|/* interrupt information */
name|cardbus_intr_line_t
name|ca_intrline
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CARDBUS_ENABLE
value|1
end_define

begin_comment
comment|/* enable the channel */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_DISABLE
value|2
end_define

begin_comment
comment|/* disable the channel */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_RESET
value|4
end_define

begin_define
define|#
directive|define
name|CARDBUS_CD
value|7
end_define

begin_define
define|#
directive|define
name|CARDBUS_NOCARD
value|0
end_define

begin_define
define|#
directive|define
name|CARDBUS_5V_CARD
value|0x01
end_define

begin_comment
comment|/* XXX: It must not exist */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_3V_CARD
value|0x02
end_define

begin_define
define|#
directive|define
name|CARDBUS_XV_CARD
value|0x04
end_define

begin_define
define|#
directive|define
name|CARDBUS_YV_CARD
value|0x08
end_define

begin_define
define|#
directive|define
name|CARDBUS_IO_ENABLE
value|100
end_define

begin_define
define|#
directive|define
name|CARDBUS_IO_DISABLE
value|101
end_define

begin_define
define|#
directive|define
name|CARDBUS_MEM_ENABLE
value|102
end_define

begin_define
define|#
directive|define
name|CARDBUS_MEM_DISABLE
value|103
end_define

begin_define
define|#
directive|define
name|CARDBUS_BM_ENABLE
value|104
end_define

begin_comment
comment|/* bus master */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_BM_DISABLE
value|105
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_UC
value|0x0000
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_3V
value|0x0001
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_XV
value|0x0002
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_YV
value|0x0003
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_0V
value|0x0004
end_define

begin_define
define|#
directive|define
name|CARDBUS_VCC_5V
value|0x0005
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VCCMASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|CARDBUS_VPP_UC
value|0x0000
end_define

begin_define
define|#
directive|define
name|CARDBUS_VPP_VCC
value|0x0010
end_define

begin_define
define|#
directive|define
name|CARDBUS_VPP_12V
value|0x0030
end_define

begin_define
define|#
directive|define
name|CARDBUS_VPP_0V
value|0x0040
end_define

begin_define
define|#
directive|define
name|CARDBUS_VPPMASK
value|0x00f0
end_define

begin_comment
comment|/********************************************************************** * Locators devies that attach to 'cardbus', as specified to config. **********************************************************************/
end_comment

begin_include
include|#
directive|include
file|"locators.h"
end_include

begin_define
define|#
directive|define
name|cardbuscf_dev
value|cf_loc[CARDBUSCF_DEV]
end_define

begin_define
define|#
directive|define
name|CARDBUS_UNK_DEV
value|CARDBUSCF_DEV_DEFAULT
end_define

begin_define
define|#
directive|define
name|cardbuscf_function
value|cf_loc[CARDBUSCF_FUNC]
end_define

begin_define
define|#
directive|define
name|CARDBUS_UNK_FUNCTION
value|CARDBUSCF_FUNC_DEFAULT
end_define

begin_decl_stmt
name|struct
name|device
modifier|*
name|cardbus_attach_card
name|__P
argument_list|(
operator|(
expr|struct
name|cardbus_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|cardbus_intr_establish
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|cardbus_function_tag_t
operator|,
name|cardbus_intr_handle_t
name|irq
operator|,
name|int
name|level
operator|,
name|int
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cardbus_intr_disestablish
name|__P
argument_list|(
operator|(
name|cardbus_chipset_tag_t
operator|,
name|cardbus_function_tag_t
operator|,
name|void
operator|*
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cardbus_conf_read
parameter_list|(
name|cc
parameter_list|,
name|cf
parameter_list|,
name|tag
parameter_list|,
name|offs
parameter_list|)
value|((cf)->cardbus_conf_read)((cc), (tag), (offs))
end_define

begin_define
define|#
directive|define
name|cardbus_conf_write
parameter_list|(
name|cc
parameter_list|,
name|cf
parameter_list|,
name|tag
parameter_list|,
name|offs
parameter_list|,
name|val
parameter_list|)
value|((cf)->cardbus_conf_write)((cc), (tag), (offs), (val))
end_define

begin_define
define|#
directive|define
name|cardbus_make_tag
parameter_list|(
name|cc
parameter_list|,
name|cf
parameter_list|,
name|bus
parameter_list|,
name|device
parameter_list|,
name|function
parameter_list|)
value|((cf)->cardbus_make_tag)((cc), (bus), (device), (function))
end_define

begin_define
define|#
directive|define
name|cardbus_free_tag
parameter_list|(
name|cc
parameter_list|,
name|cf
parameter_list|,
name|tag
parameter_list|)
value|((cf)->cardbus_free_tag)((cc), (tag))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_PCCARD_CARDBUSVAR_H */
end_comment

end_unit

