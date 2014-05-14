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

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_pci.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/ofw/ofw_pci.h>
end_include

begin_struct
struct|struct
name|uninorth_softc
block|{
name|struct
name|ofw_pci_softc
name|pci_sc
decl_stmt|;
name|vm_offset_t
name|sc_addr
decl_stmt|;
name|vm_offset_t
name|sc_data
decl_stmt|;
name|int
name|sc_ver
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unin_chip_softc
block|{
name|uint64_t
name|sc_physaddr
decl_stmt|;
name|uint64_t
name|sc_size
decl_stmt|;
name|vm_offset_t
name|sc_addr
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|int
name|sc_version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Format of a unin reg property entry.  */
end_comment

begin_struct
struct|struct
name|unin_chip_reg
block|{
name|u_int32_t
name|mr_base
decl_stmt|;
name|u_int32_t
name|mr_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per unin device structure.  */
end_comment

begin_struct
struct|struct
name|unin_chip_devinfo
block|{
name|int
name|udi_interrupts
index|[
literal|6
index|]
decl_stmt|;
name|int
name|udi_ninterrupts
decl_stmt|;
name|int
name|udi_base
decl_stmt|;
name|struct
name|ofw_bus_devinfo
name|udi_obdinfo
decl_stmt|;
name|struct
name|resource_list
name|udi_resources
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

begin_comment
comment|/*  * Power management register  */
end_comment

begin_define
define|#
directive|define
name|UNIN_PWR_MGMT
value|0x30
end_define

begin_define
define|#
directive|define
name|UNIN_PWR_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|UNIN_PWR_IDLE2
value|0x01
end_define

begin_define
define|#
directive|define
name|UNIN_PWR_SLEEP
value|0x02
end_define

begin_define
define|#
directive|define
name|UNIN_PWR_SAVE
value|0x03
end_define

begin_define
define|#
directive|define
name|UNIN_PWR_MASK
value|0x03
end_define

begin_comment
comment|/*  * Hardware initialization state register  */
end_comment

begin_define
define|#
directive|define
name|UNIN_HWINIT_STATE
value|0x70
end_define

begin_define
define|#
directive|define
name|UNIN_SLEEPING
value|0x01
end_define

begin_define
define|#
directive|define
name|UNIN_RUNNING
value|0x02
end_define

begin_comment
comment|/*  * Toggle registers  */
end_comment

begin_define
define|#
directive|define
name|UNIN_TOGGLE_REG
value|0xe0
end_define

begin_define
define|#
directive|define
name|UNIN_MPIC_RESET
value|0x2
end_define

begin_define
define|#
directive|define
name|UNIN_MPIC_OUTPUT_ENABLE
value|0x4
end_define

begin_function_decl
specifier|extern
name|int
name|unin_chip_sleep
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|idle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unin_chip_wake
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_POWERMAC_UNINORTHVAR_H_ */
end_comment

end_unit

