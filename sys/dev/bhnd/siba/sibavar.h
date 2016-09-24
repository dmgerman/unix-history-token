begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_SIBAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_SIBAVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|"siba.h"
end_include

begin_comment
comment|/*  * Internal definitions shared by siba(4) driver implementations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|siba_addrspace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|siba_devinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|siba_core_id
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|siba_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_get_intr_count
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_get_core_ivec
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|u_int
name|intr
parameter_list|,
name|uint32_t
modifier|*
name|ivec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|siba_get_bhnd_mfgid
parameter_list|(
name|uint16_t
name|ocp_vendor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|siba_core_id
name|siba_parse_core_id
parameter_list|(
name|uint32_t
name|idhigh
parameter_list|,
name|uint32_t
name|idlow
parameter_list|,
name|u_int
name|core_idx
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_add_children
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|siba_devinfo
modifier|*
name|siba_alloc_dinfo
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_init_dinfo
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|,
specifier|const
name|struct
name|siba_core_id
modifier|*
name|core_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siba_free_dinfo
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|siba_addrspace_port_count
parameter_list|(
name|u_int
name|num_addrspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|siba_addrspace_region_count
parameter_list|(
name|u_int
name|num_addrspace
parameter_list|,
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|siba_addrspace_port
parameter_list|(
name|u_int
name|addrspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|siba_addrspace_region
parameter_list|(
name|u_int
name|addrspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_addrspace_index
parameter_list|(
name|u_int
name|num_addrspace
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|,
name|u_int
modifier|*
name|addridx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|siba_is_port_valid
parameter_list|(
name|u_int
name|num_addrspace
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|siba_addrspace
modifier|*
name|siba_find_addrspace
parameter_list|(
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_append_dinfo_region
parameter_list|(
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|,
name|uint8_t
name|sid
parameter_list|,
name|uint32_t
name|base
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|bus_reserved
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|siba_admatch_offset
parameter_list|(
name|uint8_t
name|addrspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_parse_admatch
parameter_list|(
name|uint32_t
name|am
parameter_list|,
name|uint32_t
modifier|*
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_write_target_state
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|,
name|bus_size_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siba_wait_target_busy
parameter_list|(
name|device_t
name|child
parameter_list|,
name|struct
name|siba_devinfo
modifier|*
name|dinfo
parameter_list|,
name|int
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sonics configuration register blocks */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_NUM_2_2
value|1
end_define

begin_comment
comment|/**< sonics<= 2.2 maps SIBA_CFG0. */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_NUM_2_3
value|2
end_define

begin_comment
comment|/**< sonics<= 2.3 maps SIBA_CFG0 and SIBA_CFG1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_CFG
value|SIBA_CFG_NUM_2_3
end_define

begin_comment
comment|/**< maximum number of supported config 							     register blocks */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_RID_BASE
value|100
end_define

begin_comment
comment|/**< base resource ID for SIBA_CFG* register allocations */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_RID
parameter_list|(
name|_dinfo
parameter_list|,
name|_cfg
parameter_list|)
define|\
value|(SIBA_CFG_RID_BASE + (_cfg) +	\ 	    (_dinfo->core_id.core_info.core_idx * SIBA_MAX_CFG))
end_define

begin_comment
comment|/* Sonics/OCP address space mappings */
end_comment

begin_define
define|#
directive|define
name|SIBA_CORE_ADDRSPACE
value|0
end_define

begin_comment
comment|/**< Address space mapping the primary 					     device registers */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_ADDRSPACE
value|4
end_define

begin_comment
comment|/**< Maximum number of Sonics/OCP 					  *  address space mappings for a 					  *  single core. */
end_comment

begin_comment
comment|/* bhnd(4) (port,region) representation of siba address space mappings */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_PORT
value|2
end_define

begin_comment
comment|/**< maximum number of advertised 					  *  bhnd(4) ports */
end_comment

begin_comment
comment|/** siba(4) address space descriptor */
end_comment

begin_struct
struct|struct
name|siba_addrspace
block|{
name|uint32_t
name|sa_base
decl_stmt|;
comment|/**< base address */
name|uint32_t
name|sa_size
decl_stmt|;
comment|/**< size */
name|int
name|sa_rid
decl_stmt|;
comment|/**< bus resource id */
name|uint32_t
name|sa_bus_reserved
decl_stmt|;
comment|/**< number of bytes at high end of 					  *  address space reserved for the bus */
block|}
struct|;
end_struct

begin_comment
comment|/**  * siba(4) per-core identification info.  */
end_comment

begin_struct
struct|struct
name|siba_core_id
block|{
name|struct
name|bhnd_core_info
name|core_info
decl_stmt|;
comment|/**< standard bhnd(4) core info */
name|uint16_t
name|sonics_vendor
decl_stmt|;
comment|/**< OCP vendor identifier used to generate 						  *  the JEDEC-106 bhnd(4) vendor identifier. */
name|uint8_t
name|sonics_rev
decl_stmt|;
comment|/**< sonics backplane revision code */
name|uint8_t
name|num_addrspace
decl_stmt|;
comment|/**< number of address ranges mapped to 						     this core. */
name|uint8_t
name|num_cfg_blocks
decl_stmt|;
comment|/**< number of Sonics configuration register 						     blocks mapped to the core's enumeration 						     space */
block|}
struct|;
end_struct

begin_comment
comment|/**  * siba(4) per-device info  */
end_comment

begin_struct
struct|struct
name|siba_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
comment|/**< per-core memory regions. */
name|struct
name|siba_core_id
name|core_id
decl_stmt|;
comment|/**< core identification info */
name|struct
name|siba_addrspace
name|addrspace
index|[
name|SIBA_MAX_ADDRSPACE
index|]
decl_stmt|;
comment|/**< memory map descriptors */
name|struct
name|bhnd_resource
modifier|*
name|cfg
index|[
name|SIBA_MAX_CFG
index|]
decl_stmt|;
comment|/**< SIBA_CFG_* registers */
name|int
name|cfg_rid
index|[
name|SIBA_MAX_CFG
index|]
decl_stmt|;
comment|/**< SIBA_CFG_* resource IDs */
name|struct
name|bhnd_core_pmu_info
modifier|*
name|pmu_info
decl_stmt|;
comment|/**< Bus-managed PMU state, or NULL */
block|}
struct|;
end_struct

begin_comment
comment|/** siba(4) per-instance state */
end_comment

begin_struct
struct|struct
name|siba_softc
block|{
name|struct
name|bhnd_softc
name|bhnd_sc
decl_stmt|;
comment|/**< bhnd state */
name|device_t
name|dev
decl_stmt|;
comment|/**< siba device */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIBA_SIBAVAR_H_ */
end_comment

end_unit

