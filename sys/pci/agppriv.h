begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_AGPPRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_AGPPRIV_H_
end_define

begin_comment
comment|/*  * This file *must not* be included by code outside the agp driver itself.  */
end_comment

begin_include
include|#
directive|include
file|<sys/agpio.h>
end_include

begin_include
include|#
directive|include
file|<pci/agpvar.h>
end_include

begin_define
define|#
directive|define
name|AGP_DEBUGxx
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AGP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGP_DPF
parameter_list|(
name|x
modifier|...
parameter_list|)
value|do {			\     printf("agp: ");				\     printf(##x);				\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGP_DPF
parameter_list|(
name|x
modifier|...
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"agp_if.h"
end_include

begin_comment
comment|/*  * Data structure to describe an AGP memory allocation.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|agp_memory_list
argument_list|,
name|agp_memory
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|agp_memory
block|{
name|TAILQ_ENTRY
argument_list|(
argument|agp_memory
argument_list|)
name|am_link
expr_stmt|;
comment|/* wiring for the tailq */
name|int
name|am_id
decl_stmt|;
comment|/* unique id for block */
name|vm_size_t
name|am_size
decl_stmt|;
comment|/* number of bytes allocated */
name|int
name|am_type
decl_stmt|;
comment|/* chipset specific type */
name|struct
name|vm_object
modifier|*
name|am_obj
decl_stmt|;
comment|/* VM object owning pages */
name|vm_offset_t
name|am_physical
decl_stmt|;
comment|/* bogus hack for i810 */
name|vm_offset_t
name|am_offset
decl_stmt|;
comment|/* page offset if bound */
name|int
name|am_is_bound
decl_stmt|;
comment|/* non-zero if bound */
block|}
struct|;
end_struct

begin_comment
comment|/*  * All chipset drivers must have this at the start of their softc.  */
end_comment

begin_struct
struct|struct
name|agp_softc
block|{
name|struct
name|resource
modifier|*
name|as_aperture
decl_stmt|;
comment|/* location of aperture */
name|u_int32_t
name|as_maxmem
decl_stmt|;
comment|/* allocation upper bound */
name|u_int32_t
name|as_allocated
decl_stmt|;
comment|/* amount allocated */
name|enum
name|agp_acquire_state
name|as_state
decl_stmt|;
name|struct
name|agp_memory_list
name|as_memory
decl_stmt|;
comment|/* list of allocated memory */
name|int
name|as_nextid
decl_stmt|;
comment|/* next memory block id */
name|int
name|as_isopen
decl_stmt|;
comment|/* user device is open */
name|dev_t
name|as_devnode
decl_stmt|;
comment|/* from make_dev */
name|struct
name|lock
name|as_lock
decl_stmt|;
comment|/* lock for access to GATT */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agp_gatt
block|{
name|u_int32_t
name|ag_entries
decl_stmt|;
name|u_int32_t
modifier|*
name|ag_virtual
decl_stmt|;
name|vm_offset_t
name|ag_physical
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|agp_flush_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|agp_find_caps
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|agp_gatt
modifier|*
name|agp_alloc_gatt
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agp_free_gatt
parameter_list|(
name|struct
name|agp_gatt
modifier|*
name|gatt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_enable
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|agp_memory
modifier|*
name|agp_generic_alloc_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_free_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|agp_memory
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_bind_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|agp_memory
modifier|*
name|mem
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_generic_unbind_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|agp_memory
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCI_AGPPRIV_H_ */
end_comment

end_unit

