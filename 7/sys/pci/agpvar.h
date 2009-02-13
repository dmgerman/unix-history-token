begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_AGPVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_AGPVAR_H_
end_define

begin_comment
comment|/*  * The AGP chipset can be acquired by user or kernel code. If the  * chipset has already been acquired, it cannot be acquired by another   * user until the previous user has released it.  */
end_comment

begin_enum
enum|enum
name|agp_acquire_state
block|{
name|AGP_ACQUIRE_FREE
block|,
name|AGP_ACQUIRE_USER
block|,
name|AGP_ACQUIRE_KERNEL
block|}
enum|;
end_enum

begin_comment
comment|/*  * This structure is used to query the state of the AGP system.  */
end_comment

begin_struct
struct|struct
name|agp_info
block|{
name|u_int32_t
name|ai_mode
decl_stmt|;
name|vm_offset_t
name|ai_aperture_base
decl_stmt|;
name|vm_size_t
name|ai_aperture_size
decl_stmt|;
name|vm_size_t
name|ai_memory_allowed
decl_stmt|;
name|vm_size_t
name|ai_memory_used
decl_stmt|;
name|u_int32_t
name|ai_devid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agp_memory_info
block|{
name|vm_size_t
name|ami_size
decl_stmt|;
comment|/* size in bytes */
name|vm_offset_t
name|ami_physical
decl_stmt|;
comment|/* bogus hack for i810 */
name|vm_offset_t
name|ami_offset
decl_stmt|;
comment|/* page offset if bound */
name|int
name|ami_is_bound
decl_stmt|;
comment|/* non-zero if bound */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Find the AGP device and return it.  */
end_comment

begin_function_decl
name|device_t
name|agp_find_device
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current owner of the AGP chipset.  */
end_comment

begin_function_decl
name|enum
name|agp_acquire_state
name|agp_state
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Query the state of the AGP system.  */
end_comment

begin_function_decl
name|void
name|agp_get_info
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|agp_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquire the AGP chipset for use by the kernel. Returns EBUSY if the  * AGP chipset is already acquired by another user.   */
end_comment

begin_function_decl
name|int
name|agp_acquire
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release the AGP chipset.  */
end_comment

begin_function_decl
name|int
name|agp_release
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable the agp hardware with the relavent mode. The mode bits are  * defined in<pci/agpreg.h>  */
end_comment

begin_function_decl
name|int
name|agp_enable
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate physical memory suitable for mapping into the AGP  * aperture.  The value returned is an opaque handle which can be  * passed to agp_bind(), agp_unbind() or agp_deallocate().  */
end_comment

begin_function_decl
name|void
modifier|*
name|agp_alloc_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|vm_size_t
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free memory which was allocated with agp_allocate().  */
end_comment

begin_function_decl
name|void
name|agp_free_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind memory allocated with agp_allocate() at a given offset within  * the AGP aperture. Returns EINVAL if the memory is already bound or  * the offset is not at an AGP page boundary.  */
end_comment

begin_function_decl
name|int
name|agp_bind_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unbind memory from the AGP aperture. Returns EINVAL if the memory  * is not bound.  */
end_comment

begin_function_decl
name|int
name|agp_unbind_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve information about a memory block allocated with  * agp_alloc_memory().  */
end_comment

begin_function_decl
name|void
name|agp_memory_info
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|,
name|struct
name|agp_memory_info
modifier|*
name|mi
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCI_AGPVAR_H_ */
end_comment

end_unit

