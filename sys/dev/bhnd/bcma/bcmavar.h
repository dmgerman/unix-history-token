begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCMA_BCMAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCMA_BCMAVAR_H_
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
file|"bcma.h"
end_include

begin_comment
comment|/*  * Internal definitions shared by bcma(4) driver implementations.  */
end_comment

begin_comment
comment|/** Base resource ID for per-core agent register allocations */
end_comment

begin_define
define|#
directive|define
name|BCMA_AGENT_RID_BASE
value|100
end_define

begin_comment
comment|/**  * Return the device's core index.  *   * @param _dinfo The bcma_devinfo instance to query.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_DINFO_COREIDX
parameter_list|(
name|_dinfo
parameter_list|)
define|\
value|((_dinfo)->corecfg->core_info.core_idx)
end_define

begin_comment
comment|/** BCMA port identifier. */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|bcma_pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BCMA_PID_MAX
value|UINT_MAX
end_define

begin_comment
comment|/**< Maximum bcma_pid_t value */
end_comment

begin_comment
comment|/** BCMA per-port region map identifier. */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|bcma_rmid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BCMA_RMID_MAX
value|UINT_MAX
end_define

begin_comment
comment|/**< Maximum bcma_rmid_t value */
end_comment

begin_struct_decl
struct_decl|struct
name|bcma_devinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcma_corecfg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcma_intr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcma_map
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcma_mport
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcma_sport
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bcma_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bcma_get_intr_count
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
name|bcma_get_intr_ivec
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
name|int
name|bcma_add_children
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcma_sport_list
modifier|*
name|bcma_corecfg_get_port_list
parameter_list|(
name|struct
name|bcma_corecfg
modifier|*
name|cfg
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcma_devinfo
modifier|*
name|bcma_alloc_dinfo
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_init_dinfo
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|bcma_devinfo
modifier|*
name|dinfo
parameter_list|,
name|struct
name|bcma_corecfg
modifier|*
name|corecfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_free_dinfo
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|bcma_devinfo
modifier|*
name|dinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcma_corecfg
modifier|*
name|bcma_alloc_corecfg
parameter_list|(
name|u_int
name|core_index
parameter_list|,
name|int
name|core_unit
parameter_list|,
name|uint16_t
name|vendor
parameter_list|,
name|uint16_t
name|device
parameter_list|,
name|uint8_t
name|hwrev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_free_corecfg
parameter_list|(
name|struct
name|bcma_corecfg
modifier|*
name|corecfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcma_intr
modifier|*
name|bcma_alloc_intr
parameter_list|(
name|uint8_t
name|bank
parameter_list|,
name|uint8_t
name|sel
parameter_list|,
name|uint8_t
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_free_intr
parameter_list|(
name|struct
name|bcma_intr
modifier|*
name|intr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcma_sport
modifier|*
name|bcma_alloc_sport
parameter_list|(
name|bcma_pid_t
name|port_num
parameter_list|,
name|bhnd_port_type
name|port_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_free_sport
parameter_list|(
name|struct
name|bcma_sport
modifier|*
name|sport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_dmp_wait_reset
parameter_list|(
name|device_t
name|child
parameter_list|,
name|struct
name|bcma_devinfo
modifier|*
name|dinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_dmp_write_reset
parameter_list|(
name|device_t
name|child
parameter_list|,
name|struct
name|bcma_devinfo
modifier|*
name|dinfo
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** BCMA master port descriptor */
end_comment

begin_struct
struct|struct
name|bcma_mport
block|{
name|bcma_pid_t
name|mp_num
decl_stmt|;
comment|/**< AXI port identifier (bus-unique) */
name|bcma_pid_t
name|mp_vid
decl_stmt|;
comment|/**< AXI master virtual ID (core-unique) */
name|STAILQ_ENTRY
argument_list|(
argument|bcma_mport
argument_list|)
name|mp_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** BCMA memory region descriptor */
end_comment

begin_struct
struct|struct
name|bcma_map
block|{
name|bcma_rmid_t
name|m_region_num
decl_stmt|;
comment|/**< region identifier (port-unique). */
name|bhnd_addr_t
name|m_base
decl_stmt|;
comment|/**< base address */
name|bhnd_size_t
name|m_size
decl_stmt|;
comment|/**< size */
name|int
name|m_rid
decl_stmt|;
comment|/**< bus resource id, or -1. */
name|STAILQ_ENTRY
argument_list|(
argument|bcma_map
argument_list|)
name|m_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** BCMA interrupt descriptor */
end_comment

begin_struct
struct|struct
name|bcma_intr
block|{
name|uint8_t
name|i_bank
decl_stmt|;
comment|/**< OOB bank (see BCMA_OOB_BANK[A-D]) */
name|uint8_t
name|i_sel
decl_stmt|;
comment|/**< OOB selector (0-7) */
name|uint8_t
name|i_busline
decl_stmt|;
comment|/**< OOB bus line assigned to this selector */
name|bool
name|i_mapped
decl_stmt|;
comment|/**< if an irq has been mapped for this selector */
name|int
name|i_rid
decl_stmt|;
comment|/**< bus resource id, or -1 */
name|rman_res_t
name|i_irq
decl_stmt|;
comment|/**< the mapped bus irq, if any */
name|STAILQ_ENTRY
argument_list|(
argument|bcma_intr
argument_list|)
name|i_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** BCMA slave port descriptor */
end_comment

begin_struct
struct|struct
name|bcma_sport
block|{
name|bcma_pid_t
name|sp_num
decl_stmt|;
comment|/**< slave port number (core-unique) */
name|bhnd_port_type
name|sp_type
decl_stmt|;
comment|/**< port type */
name|u_long
name|sp_num_maps
decl_stmt|;
comment|/**< number of regions mapped to this port */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|bcma_map
argument_list|)
name|sp_maps
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|bcma_sport
argument_list|)
name|sp_link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|bcma_mport_list
argument_list|,
name|bcma_mport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|bcma_intr_list
argument_list|,
name|bcma_intr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|bcma_sport_list
argument_list|,
name|bcma_sport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** BCMA IP core/block configuration */
end_comment

begin_struct
struct|struct
name|bcma_corecfg
block|{
name|struct
name|bhnd_core_info
name|core_info
decl_stmt|;
comment|/**< standard core info */
name|u_long
name|num_master_ports
decl_stmt|;
comment|/**< number of master port descriptors. */
name|struct
name|bcma_mport_list
name|master_ports
decl_stmt|;
comment|/**< master port descriptors */
name|u_long
name|num_dev_ports
decl_stmt|;
comment|/**< number of device slave port descriptors. */
name|struct
name|bcma_sport_list
name|dev_ports
decl_stmt|;
comment|/**< device port descriptors */
name|u_long
name|num_bridge_ports
decl_stmt|;
comment|/**< number of bridge slave port descriptors. */
name|struct
name|bcma_sport_list
name|bridge_ports
decl_stmt|;
comment|/**< bridge port descriptors */
name|u_long
name|num_wrapper_ports
decl_stmt|;
comment|/**< number of wrapper slave port descriptors. */
name|struct
name|bcma_sport_list
name|wrapper_ports
decl_stmt|;
comment|/**< wrapper port descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/**  * BCMA per-device info  */
end_comment

begin_struct
struct|struct
name|bcma_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
comment|/**< Slave port memory regions. */
name|struct
name|bcma_corecfg
modifier|*
name|corecfg
decl_stmt|;
comment|/**< IP core/block config */
name|struct
name|bhnd_resource
modifier|*
name|res_agent
decl_stmt|;
comment|/**< Agent (wrapper) resource, or NULL. Not 						  *  all bcma(4) cores have or require an agent. */
name|int
name|rid_agent
decl_stmt|;
comment|/**< Agent resource ID, or -1 */
name|u_int
name|num_intrs
decl_stmt|;
comment|/**< number of interrupt descriptors. */
name|struct
name|bcma_intr_list
name|intrs
decl_stmt|;
comment|/**< interrupt descriptors */
name|void
modifier|*
name|pmu_info
decl_stmt|;
comment|/**< Bus-managed PMU state, or NULL */
block|}
struct|;
end_struct

begin_comment
comment|/** BMCA per-instance state */
end_comment

begin_struct
struct|struct
name|bcma_softc
block|{
name|struct
name|bhnd_softc
name|bhnd_sc
decl_stmt|;
comment|/**< bhnd state */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCMA_BCMAVAR_H_ */
end_comment

end_unit

