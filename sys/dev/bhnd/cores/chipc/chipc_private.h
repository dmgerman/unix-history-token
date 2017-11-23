begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPC_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPC_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhndvar.h>
end_include

begin_comment
comment|/*  * Private bhnd_chipc(4) driver definitions.  */
end_comment

begin_struct_decl
struct_decl|struct
name|chipc_caps
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|chipc_region
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|chipc_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|chipc_init_child_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|struct
name|resource
modifier|*
name|parent
parameter_list|,
name|bhnd_size_t
name|offset
parameter_list|,
name|bhnd_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_set_irq_resource
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_int
name|intr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_set_mem_resource
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|rid
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|count
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
name|struct
name|chipc_region
modifier|*
name|chipc_alloc_region
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
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
name|void
name|chipc_free_region
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|chipc_region
modifier|*
name|cr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|chipc_region
modifier|*
name|chipc_find_region
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|chipc_region
modifier|*
name|chipc_find_region_by_rid
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_retain_region
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|chipc_region
modifier|*
name|cr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_release_region
parameter_list|(
name|struct
name|chipc_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|chipc_region
modifier|*
name|cr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chipc_print_caps
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|chipc_caps
modifier|*
name|caps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * chipc SYS_RES_MEMORY region allocation record.  */
end_comment

begin_struct
struct|struct
name|chipc_region
block|{
name|bhnd_port_type
name|cr_port_type
decl_stmt|;
comment|/**< bhnd port type */
name|u_int
name|cr_port_num
decl_stmt|;
comment|/**< bhnd port number */
name|u_int
name|cr_region_num
decl_stmt|;
comment|/**< bhnd region number */
name|bhnd_addr_t
name|cr_addr
decl_stmt|;
comment|/**< region base address */
name|bhnd_addr_t
name|cr_end
decl_stmt|;
comment|/**< region end address */
name|bhnd_size_t
name|cr_count
decl_stmt|;
comment|/**< region count */
name|int
name|cr_rid
decl_stmt|;
comment|/**< rid to use when performing 						     resource allocation, or -1 						     if region has no assigned 						     resource ID */
name|struct
name|bhnd_resource
modifier|*
name|cr_res
decl_stmt|;
comment|/**< bus resource, or NULL */
name|int
name|cr_res_rid
decl_stmt|;
comment|/**< cr_res RID, if any. */
name|u_int
name|cr_refs
decl_stmt|;
comment|/**< RF_ALLOCATED refcount */
name|u_int
name|cr_act_refs
decl_stmt|;
comment|/**< RF_ACTIVE refcount */
name|STAILQ_ENTRY
argument_list|(
argument|chipc_region
argument_list|)
name|cr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPC_PRIVATE_H_ */
end_comment

end_unit

