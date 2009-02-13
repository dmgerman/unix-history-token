begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TTE_HASH_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TTE_HASH_H_
end_define

begin_define
define|#
directive|define
name|HASH_ENTRY_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HASH_ENTRIES
value|((1<< HASH_ENTRY_SHIFT) - 1)
end_define

begin_define
define|#
directive|define
name|THE_SHIFT
value|(TTE_SHIFT + HASH_ENTRY_SHIFT)
end_define

begin_comment
comment|/* size of TSB entry * #entries */
end_comment

begin_define
define|#
directive|define
name|TH_COLLISION_SHIFT
value|47
end_define

begin_comment
comment|/* bit 47 will never be set for a valid tag */
end_comment

begin_define
define|#
directive|define
name|TH_COLLISION
value|(1UL<< TH_COLLISION_SHIFT)
end_define

begin_define
define|#
directive|define
name|TH_INVALID_SHIFT
value|46
end_define

begin_comment
comment|/* bit 47 will never be set for a valid tag */
end_comment

begin_define
define|#
directive|define
name|TH_INVALID
value|(1UL<< TH_INVALID_SHIFT)
end_define

begin_struct_decl
struct_decl|struct
name|tte_hash
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|tte_hash
modifier|*
name|tte_hash_t
typedef|;
end_typedef

begin_function_decl
name|void
name|tte_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_hash_clear
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tte_hash_clear_bits
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_hash_t
name|tte_hash_kernel_create
parameter_list|(
name|vm_offset_t
parameter_list|,
name|uint16_t
parameter_list|,
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_hash_t
name|tte_hash_create
parameter_list|(
name|uint64_t
name|context
parameter_list|,
name|uint64_t
modifier|*
name|scratchval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_hash_destroy
parameter_list|(
name|tte_hash_t
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tte_hash_delete
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_hash_delete_all
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_hash_insert
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|tte_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tte_hash_lookup
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tte_hash_lookup_nolock
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_hash_t
name|tte_hash_reset
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|uint64_t
modifier|*
name|scratchval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|tte_hash_set_scratchpad_kernel
parameter_list|(
name|tte_hash_t
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|tte_hash_set_scratchpad_user
parameter_list|(
name|tte_hash_t
name|th
parameter_list|,
name|uint64_t
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tte_hash_update
parameter_list|(
name|tte_hash_t
name|hash
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|tte_t
name|tte_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tte_hash_needs_resize
parameter_list|(
name|tte_hash_t
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_hash_t
name|tte_hash_resize
parameter_list|(
name|tte_hash_t
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TTE_HASH_H_ */
end_comment

end_unit

