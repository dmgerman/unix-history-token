begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_POWERMAC_UNINORTHVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_POWERMAC_UNINORTHVAR_H_
end_define

begin_struct
struct|struct
name|uninorth_range
block|{
name|u_int32_t
name|pci_hi
decl_stmt|;
name|u_int32_t
name|pci_mid
decl_stmt|;
name|u_int32_t
name|pci_lo
decl_stmt|;
name|u_int32_t
name|host
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
name|uninorth_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
name|vm_offset_t
name|sc_addr
decl_stmt|;
name|vm_offset_t
name|sc_data
decl_stmt|;
name|int
name|sc_bus
decl_stmt|;
name|struct
name|uninorth_range
name|sc_range
index|[
literal|6
index|]
decl_stmt|;
name|int
name|sc_nrange
decl_stmt|;
name|int
name|sc_iostart
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
name|sc_iot
decl_stmt|;
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unin_chip_softc
block|{
name|vm_offset_t
name|sc_physaddr
decl_stmt|;
name|vm_offset_t
name|sc_addr
decl_stmt|;
name|u_int
name|sc_size
decl_stmt|;
name|int
name|sc_version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Version register  */
end_comment

begin_define
define|#
directive|define
name|UNIN_VERS
value|0x0
end_define

begin_comment
comment|/*  * Clock-control register  */
end_comment

begin_define
define|#
directive|define
name|UNIN_CLOCKCNTL
value|0x20
end_define

begin_define
define|#
directive|define
name|UNIN_CLOCKCNTL_GMAC
value|0x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_POWERMAC_UNINORTHVAR_H_ */
end_comment

end_unit

