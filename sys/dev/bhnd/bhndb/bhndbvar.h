begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDBVAR_H_
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhndvar.h>
end_include

begin_include
include|#
directive|include
file|"bhndb.h"
end_include

begin_include
include|#
directive|include
file|"bhndb_if.h"
end_include

begin_comment
comment|/*  * Definitions shared by bhndb(4) driver implementations.  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhndb_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bhndb_resources
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhndb_host_resources
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bhndb_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|cores
parameter_list|,
name|u_int
name|ncores
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|bridge_core
parameter_list|,
name|bhnd_erom_class_t
modifier|*
name|erom_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_generic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_generic_init_full_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
specifier|const
name|struct
name|bhndb_hw_priority
modifier|*
name|hw_prio_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_generic_br_suspend_child
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
name|bhnd_generic_br_resume_child
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
name|bhndb_find_hostb_core
parameter_list|(
name|struct
name|bhnd_core_info
modifier|*
name|cores
parameter_list|,
name|u_int
name|ncores
parameter_list|,
name|bhnd_devclass_t
name|bridge_devclass
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_alloc_host_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|hwcfg
parameter_list|,
name|struct
name|bhndb_host_resources
modifier|*
modifier|*
name|resources
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhndb_release_host_resources
parameter_list|(
name|struct
name|bhndb_host_resources
modifier|*
name|resources
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bhndb_host_resource_for_range
parameter_list|(
name|struct
name|bhndb_host_resources
modifier|*
name|resources
parameter_list|,
name|int
name|type
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bhndb_host_resource_for_regwin
parameter_list|(
name|struct
name|bhndb_host_resources
modifier|*
name|resources
parameter_list|,
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|win
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhndb_regwin_count
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhndb_regwin_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_type
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhndb_regwin_type_t
name|type
parameter_list|,
name|bus_size_t
name|min_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_core
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|,
name|int
name|unit
parameter_list|,
name|bhnd_port_type
name|port_type
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
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_best
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|,
name|int
name|unit
parameter_list|,
name|bhnd_port_type
name|port_type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|,
name|bus_size_t
name|min_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhndb_regwin_match_core
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|regw
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * bhndb child address space. Children either operate in the bridged  * SoC address space, or within the address space mapped to the host  * device (e.g. the PCI BAR(s)).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHNDB_ADDRSPACE_BRIDGED
block|,
comment|/**< bridged (SoC) address space */
name|BHNDB_ADDRSPACE_NATIVE
comment|/**< host address space */
block|}
name|bhndb_addrspace
typedef|;
end_typedef

begin_comment
comment|/** bhndb child instance state */
end_comment

begin_struct
struct|struct
name|bhndb_devinfo
block|{
name|bhndb_addrspace
name|addrspace
decl_stmt|;
comment|/**< child address space. */
name|struct
name|resource_list
name|resources
decl_stmt|;
comment|/**< child resources. */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Host resources allocated for a bridge hardware configuration.  */
end_comment

begin_struct
struct|struct
name|bhndb_host_resources
block|{
name|device_t
name|owner
decl_stmt|;
comment|/**< device owning the allocated resources */
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|cfg
decl_stmt|;
comment|/**< bridge hardware configuration */
name|struct
name|resource_spec
modifier|*
name|resource_specs
decl_stmt|;
comment|/**< resource specification table */
name|struct
name|resource
modifier|*
modifier|*
name|resources
decl_stmt|;
comment|/**< allocated resource table */
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhndb driver instance state. Must be first member of all subclass  * softc structures.  */
end_comment

begin_struct
struct|struct
name|bhndb_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< bridge device */
name|struct
name|bhnd_chipid
name|chipid
decl_stmt|;
comment|/**< chip identification */
name|struct
name|bhnd_core_info
name|bridge_core
decl_stmt|;
comment|/**< bridge core info */
name|device_t
name|parent_dev
decl_stmt|;
comment|/**< parent device */
name|device_t
name|bus_dev
decl_stmt|;
comment|/**< child bhnd(4) bus */
name|struct
name|bhnd_service_registry
name|services
decl_stmt|;
comment|/**< local service registry */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/**< resource lock. */
name|struct
name|bhndb_resources
modifier|*
name|bus_res
decl_stmt|;
comment|/**< bus resource state */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDBVAR_H_ */
end_comment

end_unit

