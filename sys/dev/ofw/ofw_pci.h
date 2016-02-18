begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: ofw_pci.h,v 1.5 2003/10/22 09:04:39 mjl Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_OFW_OFW_PCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_OFW_OFW_PCI_H_
end_define

begin_comment
comment|/*  * PCI Bus Binding to:  *  * IEEE Std 1275-1994  * Standard for Boot (Initialization Configuration) Firmware  *  * Revision 2.1  */
end_comment

begin_comment
comment|/*  * Section 2.2.1. Physical Address Formats  *  * A PCI physical address is represented by 3 address cells:  *  *	phys.hi cell:	npt000ss bbbbbbbb dddddfff rrrrrrrr  *	phys.mid cell:	hhhhhhhh hhhhhhhh hhhhhhhh hhhhhhhh  *	phys.lo cell:	llllllll llllllll llllllll llllllll  *  *	n	nonrelocatable  *	p	prefetchable  *	t	aliased below 1MB (memory) or 64k (i/o)  *	ss	space code  *	b	bus number  *	d	device number  *	f	function number  *	r	register number  *	h	high 32-bits of PCI address  *	l	low 32-bits of PCI address  */
end_comment

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_NONRELOCATABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_PREFETCHABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_ALIASED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_SPACEMASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_BUSMASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_BUSSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_DEVICEMASK
value|0x0000f800
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_DEVICESHIFT
value|11
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_FUNCTIONMASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_FUNCTIONSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_REGISTERMASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_SPACE_CONFIG
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_SPACE_IO
value|0x01000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_SPACE_MEM32
value|0x02000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_SPACE_MEM64
value|0x03000000
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_BUS
parameter_list|(
name|hi
parameter_list|)
define|\
value|(((hi)& OFW_PCI_PHYS_HI_BUSMASK)>> OFW_PCI_PHYS_HI_BUSSHIFT)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_DEVICE
parameter_list|(
name|hi
parameter_list|)
define|\
value|(((hi)& OFW_PCI_PHYS_HI_DEVICEMASK)>> OFW_PCI_PHYS_HI_DEVICESHIFT)
end_define

begin_define
define|#
directive|define
name|OFW_PCI_PHYS_HI_FUNCTION
parameter_list|(
name|hi
parameter_list|)
define|\
value|(((hi)& OFW_PCI_PHYS_HI_FUNCTIONMASK)>> OFW_PCI_PHYS_HI_FUNCTIONSHIFT)
end_define

begin_comment
comment|/*  * Export class definition for inheritance purposes  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|ofw_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This has the 3 32bit cell values, plus 2 more to make up a 64-bit size.  */
end_comment

begin_struct
struct|struct
name|ofw_pci_register
block|{
name|u_int32_t
name|phys_hi
decl_stmt|;
name|u_int32_t
name|phys_mid
decl_stmt|;
name|u_int32_t
name|phys_lo
decl_stmt|;
name|u_int32_t
name|size_hi
decl_stmt|;
name|u_int32_t
name|size_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ofw_pci_cell_info
block|{
name|pcell_t
name|host_address_cells
decl_stmt|;
name|pcell_t
name|pci_address_cell
decl_stmt|;
name|pcell_t
name|size_cells
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ofw_pci_range
block|{
name|uint32_t
name|pci_hi
decl_stmt|;
name|uint64_t
name|pci
decl_stmt|;
name|uint64_t
name|host
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Quirks for some adapters  */
end_comment

begin_enum
enum|enum
block|{
name|OFW_PCI_QUIRK_RANGES_ON_CHILDREN
init|=
literal|1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ofw_pci_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
name|int
name|sc_bus
decl_stmt|;
name|int
name|sc_initialized
decl_stmt|;
name|int
name|sc_quirks
decl_stmt|;
name|struct
name|ofw_pci_range
modifier|*
name|sc_range
decl_stmt|;
name|int
name|sc_nrange
decl_stmt|;
name|struct
name|ofw_pci_cell_info
modifier|*
name|sc_cell_info
decl_stmt|;
name|struct
name|rman
name|sc_io_rman
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
name|struct
name|ofw_bus_iinfo
name|sc_pci_iinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ofw_pci_init
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_read_ivar
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_write_ivar
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_route_interrupt
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_nranges
parameter_list|(
name|phandle_t
parameter_list|,
name|struct
name|ofw_pci_cell_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_OFW_OFW_PCI_H_ */
end_comment

end_unit

