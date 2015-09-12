begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Eduardo E. Horvath  * Copyright (c) 2001, 2003 by Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychoreg.h,v 1.14 2008/05/30 02:29:37 mrg Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_OFW_PCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_OFW_PCI_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|"ofw_pci_if.h"
end_include

begin_typedef
typedef|typedef
name|uint32_t
name|ofw_pci_intr_t
typedef|;
end_typedef

begin_comment
comment|/* PCI range child spaces. XXX: are these MI? */
end_comment

begin_define
define|#
directive|define
name|OFW_PCI_CS_CONFIG
value|0x00
end_define

begin_define
define|#
directive|define
name|OFW_PCI_CS_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|OFW_PCI_CS_MEM32
value|0x02
end_define

begin_define
define|#
directive|define
name|OFW_PCI_CS_MEM64
value|0x03
end_define

begin_define
define|#
directive|define
name|OFW_PCI_NUM_CS
value|4
end_define

begin_comment
comment|/* OFW device types */
end_comment

begin_define
define|#
directive|define
name|OFW_TYPE_PCI
value|"pci"
end_define

begin_define
define|#
directive|define
name|OFW_TYPE_PCIE
value|"pciex"
end_define

begin_struct
struct|struct
name|ofw_pci_msi_addr_ranges
block|{
name|uint32_t
name|addr32_hi
decl_stmt|;
name|uint32_t
name|addr32_lo
decl_stmt|;
name|uint32_t
name|addr32_sz
decl_stmt|;
name|uint32_t
name|addr64_hi
decl_stmt|;
name|uint32_t
name|addr64_lo
decl_stmt|;
name|uint32_t
name|addr64_sz
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OFW_PCI_MSI_ADDR_RANGE_32
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->addr32_hi<< 32) | (uint64_t)(r)->addr32_lo)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_MSI_ADDR_RANGE_64
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->addr64_hi<< 32) | (uint64_t)(r)->addr64_lo)
end_define

begin_struct
struct|struct
name|ofw_pci_msi_eq_to_devino
block|{
name|uint32_t
name|eq_first
decl_stmt|;
name|uint32_t
name|eq_count
decl_stmt|;
name|uint32_t
name|devino_first
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ofw_pci_msi_ranges
block|{
name|uint32_t
name|first
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ofw_pci_ranges
block|{
name|uint32_t
name|cspace
decl_stmt|;
name|uint32_t
name|child_hi
decl_stmt|;
name|uint32_t
name|child_lo
decl_stmt|;
name|uint32_t
name|phys_hi
decl_stmt|;
name|uint32_t
name|phys_lo
decl_stmt|;
name|uint32_t
name|size_hi
decl_stmt|;
name|uint32_t
name|size_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OFW_PCI_RANGE_CHILD
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->child_hi<< 32) | (uint64_t)(r)->child_lo)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_RANGE_PHYS
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->phys_hi<< 32) | (uint64_t)(r)->phys_lo)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_RANGE_SIZE
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->size_hi<< 32) | (uint64_t)(r)->size_lo)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_RANGE_CS
parameter_list|(
name|r
parameter_list|)
value|(((r)->cspace>> 24)& 0x03)
end_define

begin_comment
comment|/* default values */
end_comment

begin_define
define|#
directive|define
name|OFW_PCI_LATENCY
value|64
end_define

begin_comment
comment|/*  * Common and generic parts of host-PCI-bridge support  */
end_comment

begin_struct
struct|struct
name|ofw_pci_softc
block|{
name|struct
name|rman
name|sc_pci_mem_rman
decl_stmt|;
name|struct
name|rman
name|sc_pci_io_rman
decl_stmt|;
name|bus_space_handle_t
name|sc_pci_bh
index|[
name|OFW_PCI_NUM_CS
index|]
decl_stmt|;
name|bus_space_tag_t
name|sc_pci_cfgt
decl_stmt|;
name|bus_space_tag_t
name|sc_pci_iot
decl_stmt|;
name|bus_dma_tag_t
name|sc_pci_dmat
decl_stmt|;
name|struct
name|ofw_bus_iinfo
name|sc_pci_iinfo
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
name|uint8_t
name|sc_pci_secbus
decl_stmt|;
name|uint8_t
name|sc_pci_subbus
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ofw_pci_attach_common
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|u_long
name|iosize
parameter_list|,
name|u_long
name|memsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ofw_pci_read_config_common
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|regmax
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int
name|bus
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|u_int
name|func
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_pci_write_config_common
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|regmax
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int
name|bus
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|u_int
name|func
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ofw_pci_intr_t
name|ofw_pci_route_interrupt_common
parameter_list|(
name|device_t
name|bridge
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_pci_dmamap_sync_stst_order_common
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bus_activate_resource_t
name|ofw_pci_activate_resource
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_adjust_resource_t
name|ofw_pci_adjust_resource
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_alloc_resource_t
name|ofw_pci_alloc_resource
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_get_dma_tag_t
name|ofw_pci_get_dma_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_read_ivar_t
name|ofw_pci_read_ivar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_node_t
name|ofw_pci_get_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SPARC64_PCI_OFW_PCI_H_ */
end_comment

end_unit

