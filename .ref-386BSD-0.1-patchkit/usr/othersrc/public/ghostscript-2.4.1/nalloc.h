begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* nalloc.h */
end_comment

begin_comment
comment|/* Library client interface for new Ghostscript allocator */
end_comment

begin_comment
comment|/* Define the type for the size of an object. */
end_comment

begin_typedef
typedef|typedef
name|uint
name|usize_t
typedef|;
end_typedef

begin_comment
comment|/* Define the type for identifying an allocator client. */
end_comment

begin_typedef
typedef|typedef
name|char
name|_ds
modifier|*
name|client_name_t
typedef|;
end_typedef

begin_comment
comment|/* Define the type for an allocator instance. */
end_comment

begin_struct_decl
struct_decl|struct
name|alloc_state_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|alloc_state_s
name|_ds
modifier|*
name|as_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* Define the type for a structure descriptor. */
end_comment

begin_struct_decl
struct_decl|struct
name|struct_type_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|struct_type_s
name|_ds
modifier|*
name|at_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* Define the type for allocator statistics. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|alloc_status_s
block|{
name|ulong
name|allocated
decl_stmt|;
name|ulong
name|used
decl_stmt|;
block|}
name|alloc_status_t
typedef|;
end_typedef

begin_comment
comment|/* Define the allocator client procedures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|alloc_procs_s
name|alloc_procs_t
typedef|;
end_typedef

begin_struct
struct|struct
name|alloc_procs_s
block|{
comment|/* Allocate a structure */
define|#
directive|define
name|alloc_proc_alloc_struct
parameter_list|(
name|proc
parameter_list|)
define|\
value|void *proc(P3(as_ptr_t, at_ptr_t, client_name_t))
name|alloc_proc_alloc_struct
argument_list|(
operator|(
operator|*
name|alloc_struct
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|gs_alloc_struct
parameter_list|(
name|ap
parameter_list|,
name|tp
parameter_list|,
name|cn
parameter_list|)
value|(*(ap)->procs.alloc_struct)(ap,tp,cn)
comment|/* Allocate (aligned) bytes */
define|#
directive|define
name|alloc_proc_alloc_bytes
parameter_list|(
name|proc
parameter_list|)
define|\
value|byte *proc(P4(as_ptr_t, uint, uint, client_name_t))
name|alloc_proc_alloc_bytes
argument_list|(
operator|(
operator|*
name|alloc_bytes
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|gs_alloc_bytes
parameter_list|(
name|ap
parameter_list|,
name|es
parameter_list|,
name|n
parameter_list|,
name|cn
parameter_list|)
value|(*(ap)->procs.alloc_bytes)(ap,es,n,cn)
comment|/* Change the size of a byte object */
define|#
directive|define
name|alloc_proc_resize
parameter_list|(
name|proc
parameter_list|)
define|\
value|byte *proc(P5(as_ptr_t, byte *, uint, uint, client_name_t))
name|alloc_proc_resize
argument_list|(
operator|(
operator|*
name|resize
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|gs_resize
parameter_list|(
name|ap
parameter_list|,
name|p
parameter_list|,
name|es
parameter_list|,
name|n
parameter_list|,
name|cn
parameter_list|)
value|(*(ap)->procs.resize)(ap,p,es,n,cn)
comment|/* Free an object (structure or bytes) */
define|#
directive|define
name|alloc_proc_free
parameter_list|(
name|proc
parameter_list|)
define|\
value|void proc(P3(as_ptr_t, void *, client_name_t))
name|alloc_proc_free
argument_list|(
operator|(
operator|*
name|free
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|gs_free
parameter_list|(
name|ap
parameter_list|,
name|p
parameter_list|,
name|cn
parameter_list|)
value|(*(ap)->procs.free)(ap,p,cn)
comment|/* Report status (assigned, used) */
define|#
directive|define
name|alloc_proc_status
parameter_list|(
name|proc
parameter_list|)
define|\
value|void proc(P2(as_ptr_t, alloc_status_t *))
name|alloc_proc_status
argument_list|(
operator|(
operator|*
name|status
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|gs_alloc_status
parameter_list|(
name|ap
parameter_list|,
name|s
parameter_list|)
value|(*(ap)->procs.status)(ap,s)
block|}
struct|;
end_struct

begin_comment
comment|/* Define the generic allocator state. */
end_comment

begin_comment
comment|/* "Subclasses" will extend this. */
end_comment

begin_define
define|#
directive|define
name|alloc_state_common
define|\
value|alloc_procs_t procs
end_define

begin_struct
struct|struct
name|alloc_state_s
block|{
name|alloc_state_common
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Define the standard Ghostscript allocator implementation. */
end_comment

begin_decl_stmt
specifier|extern
name|alloc_procs_t
name|gs_alloc_std_procs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ====== Root-registering clients ====== */
end_comment

begin_union_decl
union_decl|union
name|struct_header_s
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|ref_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* Define the type for a pointer descriptor. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ptr_procs_s
block|{
comment|/* Mark the referent of a pointer. */
define|#
directive|define
name|ptr_proc_mark
parameter_list|(
name|proc
parameter_list|)
define|\
value|bool proc(P1(void *))
name|ptr_proc_mark
argument_list|(
operator|(
operator|*
name|mark
operator|)
argument_list|)
expr_stmt|;
comment|/* Relocate a pointer. */
define|#
directive|define
name|ptr_proc_reloc
parameter_list|(
name|proc
parameter_list|)
define|\
value|void *proc(P1(void *))
name|ptr_proc_reloc
argument_list|(
operator|(
operator|*
name|reloc
operator|)
argument_list|)
expr_stmt|;
block|}
name|ptr_procs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptr_procs_t
name|_ds
modifier|*
name|ptr_type_t
typedef|;
end_typedef

begin_comment
comment|/* Define the pointer type for ordinary structure pointers. */
end_comment

begin_decl_stmt
specifier|extern
name|ptr_procs_t
name|ptr_struct_procs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ptr_struct_type
value|(&ptr_struct_procs)
end_define

begin_comment
comment|/* Define the type for a GC root. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gc_root_s
name|gc_root_t
typedef|;
end_typedef

begin_struct
struct|struct
name|gc_root_s
block|{
name|gc_root_t
modifier|*
name|next
decl_stmt|;
name|ptr_type_t
name|ptype
decl_stmt|;
name|void
modifier|*
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register/unregister a root. */
end_comment

begin_decl_stmt
name|void
name|gs_struct_root_register
argument_list|(
name|P3
argument_list|(
name|as_ptr_t
argument_list|,
name|gc_root_t
operator|*
argument_list|,
expr|union
name|struct_header_s
operator|*
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gs_root_unregister
argument_list|(
name|P2
argument_list|(
name|as_ptr_t
argument_list|,
name|gc_root_t
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ====== Structure-defining clients ====== */
end_comment

begin_comment
comment|/* These are clients who define new types of structure. */
end_comment

begin_comment
comment|/* Object contents enumerator type */
end_comment

begin_define
define|#
directive|define
name|mark_enum_proc
parameter_list|(
name|proc
parameter_list|)
define|\
value|ptr_type_t proc(P3(void *ptr, uint index, void ***pep))
end_define

begin_comment
comment|/* Object type */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|struct_type_s
block|{
name|usize_t
name|size
decl_stmt|;
name|char
name|_ds
modifier|*
name|sname
decl_stmt|;
name|mark_enum_proc
argument_list|(
operator|(
operator|*
name|gc_mark_proc
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|*
name|pre_gc_proc
argument_list|)
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|*
name|post_gc_proc
argument_list|)
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|*
name|finalize_proc
argument_list|)
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|struct_type_t
typedef|;
end_typedef

begin_comment
comment|/* Default object procedures */
end_comment

begin_extern
extern|extern	mark_enum_proc(no_gc_mark_proc
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|void
name|no_pre_gc_proc
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|no_post_gc_proc
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|no_finalize_proc
argument_list|(
name|P1
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

