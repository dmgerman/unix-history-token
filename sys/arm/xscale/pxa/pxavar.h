begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: obiovar.h,v 1.4 2003/06/16 17:40:53 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PXAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PXAVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|obio_softc
block|{
name|bus_space_tag_t
name|obio_bst
decl_stmt|;
comment|/* bus space tag */
name|struct
name|rman
name|obio_mem
decl_stmt|;
name|struct
name|rman
name|obio_irq
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|bus_space_tag_t
name|base_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bus_space_tag_t
name|obio_tag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pxa_obio_tag_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_space_tag_t
name|pxa_bus_tag_alloc
parameter_list|(
name|bus_addr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pxa_gpio_get_function
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pxa_gpio_set_function
parameter_list|(
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_gpio_setup_intrhandler
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|driver_filter_t
modifier|*
parameter_list|,
name|driver_intr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pxa_gpio_mask_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pxa_gpio_unmask_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_gpio_get_next_irq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|dmac_channel
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|dmac_descriptor
block|{
name|uint32_t
name|ddadr
decl_stmt|;
name|uint32_t
name|dsadr
decl_stmt|;
name|uint32_t
name|dtadr
decl_stmt|;
name|uint32_t
name|dcmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DMACD_SET_DESCRIPTOR
parameter_list|(
name|d
parameter_list|,
name|dadr
parameter_list|)
value|do { d->ddadr = dadr; } while (0)
end_define

begin_define
define|#
directive|define
name|DMACD_SET_SOURCE
parameter_list|(
name|d
parameter_list|,
name|sadr
parameter_list|)
value|do { d->dsadr = sadr; } while (0)
end_define

begin_define
define|#
directive|define
name|DMACD_SET_TARGET
parameter_list|(
name|d
parameter_list|,
name|tadr
parameter_list|)
value|do { d->dtadr = tadr; } while (0)
end_define

begin_define
define|#
directive|define
name|DMACD_SET_COMMAND
parameter_list|(
name|d
parameter_list|,
name|cmd
parameter_list|)
value|do { d->dcmd = cmd; } while (0)
end_define

begin_define
define|#
directive|define
name|DMAC_PRIORITY_HIGHEST
value|1
end_define

begin_define
define|#
directive|define
name|DMAC_PRIORITY_HIGH
value|2
end_define

begin_define
define|#
directive|define
name|DMAC_PRIORITY_LOW
value|3
end_define

begin_function_decl
name|int
name|pxa_dmac_alloc
parameter_list|(
name|int
parameter_list|,
name|struct
name|dmac_channel
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pxa_dmac_release
parameter_list|(
name|struct
name|dmac_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_dmac_transfer
parameter_list|(
name|struct
name|dmac_channel
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_dmac_transfer_single
parameter_list|(
name|struct
name|dmac_channel
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_dmac_transfer_done
parameter_list|(
name|struct
name|dmac_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pxa_dmac_transfer_failed
parameter_list|(
name|struct
name|dmac_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|pxa_device_ivars
block|{
name|PXA_IVAR_BASE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|smi_device_ivars
block|{
name|SMI_IVAR_PHYSBASE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PXA_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(pxa, var, PXA, ivar, type)
end_define

begin_macro
name|PXA_ACCESSOR
argument_list|(
argument|base
argument_list|,
argument|BASE
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|PXA_ACCESSOR
end_undef

begin_define
define|#
directive|define
name|SMI_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(smi, var, SMI, ivar, type)
end_define

begin_macro
name|SMI_ACCESSOR
argument_list|(
argument|physbase
argument_list|,
argument|PHYSBASE
argument_list|,
argument|bus_addr_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CSR_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PXAVAR_H_ */
end_comment

end_unit

