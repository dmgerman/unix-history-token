begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEMSTAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEMSTAT_H_
end_define

begin_comment
comment|/*  * Number of CPU slots in library-internal data structures.  This should be  * at least the value of MAXCPU from param.h.  */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_MAXCPU
value|32
end_define

begin_comment
comment|/*  * Amount of caller data to maintain for each caller data slot.  Applications  * must not request more than this number of caller save data, or risk  * corrupting internal libmemstat(3) data structures.  A compile time check  * in the application is probably appropriate.  */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_MAXCALLER
value|16
end_define

begin_comment
comment|/*  * libmemstat(3) is able to extract memory data from different allocators;  * when it does so, it tags which allocator it got the data from so that  * consumers can determine which fields are usable, as data returned varies  * some.  */
end_comment

begin_define
define|#
directive|define
name|ALLOCATOR_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|ALLOCATOR_MALLOC
value|1
end_define

begin_define
define|#
directive|define
name|ALLOCATOR_UMA
value|2
end_define

begin_define
define|#
directive|define
name|ALLOCATOR_ANY
value|255
end_define

begin_comment
comment|/*  * Library maximum type name.  Should be max(set of name maximums over  * various allocators).  */
end_comment

begin_define
define|#
directive|define
name|MEMTYPE_MAXNAME
value|32
end_define

begin_comment
comment|/*  * Library error conditions, mostly from the underlying data sources.  On  * failure, functions typically return (-1) or (NULL); on success, (0) or a  * valid data pointer.  The error from the last operation is stored in  * struct memory_type_list, and accessed via memstat_get_error(list).  */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_UNDEFINED
value|0
end_define

begin_comment
comment|/* Initialization value. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_NOMEMORY
value|1
end_define

begin_comment
comment|/* Out of memory. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_VERSION
value|2
end_define

begin_comment
comment|/* Unsupported version. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_PERMISSION
value|3
end_define

begin_comment
comment|/* Permission denied. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_TOOMANYCPUS
value|4
end_define

begin_comment
comment|/* Too many CPUs. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_DATAERROR
value|5
end_define

begin_comment
comment|/* Error in stat data. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_KVM
value|6
end_define

begin_comment
comment|/* See kvm_geterr() for err. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_KVM_NOSYMBOL
value|7
end_define

begin_comment
comment|/* Symbol not available. */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ERROR_KVM_SHORTREAD
value|8
end_define

begin_comment
comment|/* Short kvm_read return. */
end_comment

begin_comment
comment|/*  * Forward declare struct memory_type, which holds per-type properties and  * statistics.  This is an opaque type, to be frobbed only from within the  * library, in order to avoid building ABI assumptions into the application.  * Accessor methods should be used to get and sometimes set the fields from  * consumers of the library.  */
end_comment

begin_struct_decl
struct_decl|struct
name|memory_type
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * struct memory_type_list is the head of a list of memory types and  * statistics.  */
end_comment

begin_struct_decl
struct_decl|struct
name|memory_type_list
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Functions that operate without memory type or memory type list context.  */
specifier|const
name|char
modifier|*
name|memstat_strerror
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions for managing memory type and statistics data.  */
end_comment

begin_function_decl
name|struct
name|memory_type_list
modifier|*
name|memstat_mtl_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|memory_type
modifier|*
name|memstat_mtl_first
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|memory_type
modifier|*
name|memstat_mtl_next
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|memory_type
modifier|*
name|memstat_mtl_find
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|int
name|allocator
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstat_mtl_free
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_mtl_geterror
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to retrieve data from a live kernel using sysctl.  */
end_comment

begin_function_decl
name|int
name|memstat_sysctl_all
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_sysctl_malloc
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_sysctl_uma
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to retrieve data from a kernel core (or /dev/kmem).  */
end_comment

begin_function_decl
name|int
name|memstat_kvm_all
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|void
modifier|*
name|kvm_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_kvm_malloc
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|void
modifier|*
name|kvm_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_kvm_uma
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|void
modifier|*
name|kvm_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Accessor methods for struct memory_type.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|memstat_get_name
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memstat_get_allocator
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_countlimit
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_byteslimit
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_sizemask
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_size
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_memalloced
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_memfreed
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_numallocs
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_numfrees
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_bytes
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_count
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_free
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_failures
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memstat_get_caller_pointer
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstat_set_caller_pointer
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_caller_uint64
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstat_set_caller_uint64
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|index
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_zonefree
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_kegfree
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_memalloced
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_memfreed
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_numallocs
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_numfrees
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_sizemask
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memstat_get_percpu_caller_pointer
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstat_set_percpu_caller_pointer
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_caller_uint64
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstat_set_percpu_caller_uint64
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|index
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|memstat_get_percpu_free
parameter_list|(
specifier|const
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MEMSTAT_H_ */
end_comment

end_unit

