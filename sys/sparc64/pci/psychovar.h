begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychovar.h,v 1.6 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_PSYCHOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_PSYCHOVAR_H_
end_define

begin_comment
comment|/*  * per-PCI bus on mainbus softc structure; one for sabre, or two  * per pair of psycho's.  */
end_comment

begin_struct
struct|struct
name|psycho_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* 	 * PSYCHO register.  we record the base physical address of these 	 * also as it is the base of the entire PSYCHO 	 */
name|vm_offset_t
name|sc_basepaddr
decl_stmt|;
comment|/* Interrupt Group Number for this device */
name|int
name|sc_ign
decl_stmt|;
comment|/* our tags (from parent) */
name|bus_space_tag_t
name|sc_bustag
decl_stmt|;
name|bus_space_handle_t
name|sc_bushandle
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmatag
decl_stmt|;
name|bus_addr_t
name|sc_pcictl
decl_stmt|;
name|int
name|sc_clockfreq
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
comment|/* prom node */
name|int
name|sc_mode
decl_stmt|;
define|#
directive|define
name|PSYCHO_MODE_SABRE
value|1
define|#
directive|define
name|PSYCHO_MODE_PSYCHO
value|2
name|struct
name|iommu_state
modifier|*
name|sc_is
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
index|[
literal|6
index|]
decl_stmt|;
name|void
modifier|*
name|sc_ihand
index|[
literal|6
index|]
decl_stmt|;
comment|/* 	 * note that the sabre really only has one ranges property, 	 * used for both simba a and simba b (but the ranges for 	 * real psychos are the same for PCI A and PCI B anyway). 	 */
name|struct
name|upa_ranges
modifier|*
name|sc_range
decl_stmt|;
name|int
name|sc_nrange
decl_stmt|;
name|struct
name|ofw_pci_imap
modifier|*
name|sc_intrmap
decl_stmt|;
name|int
name|sc_nintrmap
decl_stmt|;
name|struct
name|ofw_pci_imap_msk
name|sc_intrmapmsk
decl_stmt|;
comment|/* our tags */
name|bus_space_tag_t
name|sc_cfgt
decl_stmt|;
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
index|[
literal|4
index|]
decl_stmt|;
name|int
name|sc_busno
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|struct
name|rman
name|sc_io_rman
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPARC64_PCI_PSYCHOVAR_H_ */
end_comment

end_unit

