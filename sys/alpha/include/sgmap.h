begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SGMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SGMAP_H_
end_define

begin_struct_decl
struct_decl|struct
name|sgmap
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|sgmap_map_callback
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_addr_t
name|ba
parameter_list|,
name|vm_offset_t
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|vm_offset_t
name|sgmap_overflow_page
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sgmap
modifier|*
name|sgmap_map_create
parameter_list|(
name|bus_addr_t
name|sba
parameter_list|,
name|bus_addr_t
name|eba
parameter_list|,
name|sgmap_map_callback
modifier|*
name|map
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sgmap_map_destroy
parameter_list|(
name|struct
name|sgmap
modifier|*
name|sgmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_addr_t
name|sgmap_alloc_region
parameter_list|(
name|struct
name|sgmap
modifier|*
name|sgmap
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|bus_size_t
name|boundary
parameter_list|,
name|void
modifier|*
modifier|*
name|mhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sgmap_load_region
parameter_list|(
name|struct
name|sgmap
modifier|*
name|sgmap
parameter_list|,
name|bus_addr_t
name|sba
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sgmap_unload_region
parameter_list|(
name|struct
name|sgmap
modifier|*
name|sgmap
parameter_list|,
name|bus_addr_t
name|sba
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sgmap_free_region
parameter_list|(
name|struct
name|sgmap
modifier|*
name|sgmap
parameter_list|,
name|void
modifier|*
name|mh
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SGMAP_H_ */
end_comment

end_unit

