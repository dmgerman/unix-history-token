begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* nmman.h */
end_comment

begin_comment
comment|/* New memory manager internal definitions for Ghostscript */
end_comment

begin_comment
comment|/* ====== Allocator ====== */
end_comment

begin_comment
comment|/* Define the alignment modulus for aligned objects. */
end_comment

begin_define
define|#
directive|define
name|log2_align_mod
value|3
end_define

begin_comment
comment|/* big enough for a double */
end_comment

begin_comment
comment|/* and for a struct_header */
end_comment

begin_define
define|#
directive|define
name|align_mod
value|(1<< log2_align_mod)
end_define

begin_define
define|#
directive|define
name|align_mask
value|(align_mod-1)
end_define

begin_define
define|#
directive|define
name|align_round
parameter_list|(
name|siz
parameter_list|)
value|(uint)(((siz) + align_mask)& -align_mod)
end_define

begin_comment
comment|/* Structure header. */
end_comment

begin_comment
comment|/* There are 3 different formats, as indicated below. */
end_comment

begin_comment
comment|/* Note that we force the size of a structure header to be align_mod. */
end_comment

begin_typedef
typedef|typedef
name|union
name|struct_header_s
name|struct_header_t
typedef|;
end_typedef

begin_union
union|union
name|struct_header_s
block|{
struct|struct
block|{
name|unsigned
name|mark
range|:
literal|1
decl_stmt|,
name|large
range|:
literal|1
decl_stmt|,
name|bytes
range|:
literal|1
decl_stmt|;
block|}
name|h
struct|;
comment|/* all formats */
comment|/* Ordinary typed structure */
struct|struct
block|{
name|unsigned
name|_
range|:
literal|3
decl_stmt|,
name|reloc8
range|:
literal|13
decl_stmt|;
name|at_ptr_t
name|type
decl_stmt|;
block|}
name|s
struct|;
comment|/* large = 0, bytes = 0 */
comment|/* Plain (but aligned) bytes */
struct|struct
block|{
name|unsigned
name|_
range|:
literal|3
decl_stmt|,
name|reloc8
range|:
literal|13
decl_stmt|;
name|ushort
name|size
decl_stmt|;
block|}
name|b
struct|;
comment|/* large = 0, bytes = 1 */
comment|/* Large bytes (in a chunk by themselves) */
struct|struct
block|{
name|unsigned
name|_
range|:
literal|3
decl_stmt|,
name|lsize
range|:
literal|13
decl_stmt|;
name|ushort
name|size
decl_stmt|;
block|}
name|l
struct|;
comment|/* large = 1, bytes = 1 */
comment|/* Force size up to align_mod */
name|byte
name|_
index|[
name|align_mod
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|struct_size
parameter_list|(
name|shp
parameter_list|)
define|\
value|((shp)->h.bytes ? (shp)->b.size : (shp)->s.type->size)
end_define

begin_define
define|#
directive|define
name|struct_large_size
parameter_list|(
name|shp
parameter_list|)
define|\
value|(((ulong)(shp)->l.lsize<< 16) + (shp)->l.size)
end_define

begin_define
define|#
directive|define
name|struct_next
parameter_list|(
name|shp
parameter_list|)
define|\
value|((struct_header_t *)((byte *)(shp) + struct_size(shp)))
end_define

begin_comment
comment|/* ====== Chunks ====== */
end_comment

begin_comment
comment|/* Chunks are "objects", i.e. they have a header that identifies */
end_comment

begin_comment
comment|/* which implementation is being used. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|chunk_s
name|chunk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|chunk_locator_s
name|chunk_locator_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|chunk_locator_t
name|_ss
modifier|*
name|cl_ptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|declare_chunk_procs
parameter_list|(
name|dscope
parameter_list|,
name|ctype
parameter_list|,
name|init
parameter_list|,
name|status
parameter_list|,
name|gc_init
parameter_list|,
name|gc_trace_from_marked
parameter_list|,
name|gc_set_reloc
parameter_list|,
name|gc_do_reloc
parameter_list|,
name|gc_compact
parameter_list|)
define|\ \
comment|/* Initialize the chunk. */
define|\
value|dscope void init(P3(ctype *, byte *, usize_t));\ \
comment|/* Return the space allocated and used. */
value|\ 	dscope void status(P2(ctype *, alloc_status_t *));\ \
comment|/**** The rest of the procedures are only for the GC. ****/
value|\ \
comment|/* Initialize for a GC by clearing marks. */
value|\ 	dscope void gc_init(P1(ctype *));\ \
comment|/* Trace from all marked pointers. */
value|\
comment|/* Return true if any new marks. */
value|\ 	dscope bool gc_trace_from_marked(P1(ctype *));\ \
comment|/* Compute and store relocation amounts. */
value|\ 	dscope void gc_set_reloc(P2(ctype *, cl_ptr_t));\ \
comment|/* Relocate pointers. */
value|\ 	dscope void gc_do_reloc(P2(ctype *, cl_ptr_t));\ \
comment|/* Compact to remove unmarked components. */
value|\ 	dscope void gc_compact(P1(ctype *))
end_define

begin_define
define|#
directive|define
name|chunk_procs_struct
parameter_list|(
name|ctype
parameter_list|)
define|\
value|struct {\     declare_chunk_procs(, ctype, (*init), (*status), (*gc_init), (*gc_trace_from_marked), (*gc_set_reloc), (*gc_do_reloc), (*gc_compact));\   }
end_define

begin_typedef
typedef|typedef
name|chunk_procs_struct
argument_list|(
argument|chunk_t
argument_list|)
name|chunk_procs_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|chunk_common
define|\
value|chunk_procs_t _ds *procs;\   byte *cbot, *ctop;\   chunk_t *cprev, *cnext
end_define

begin_comment
comment|/* sorted by address */
end_comment

begin_struct
struct|struct
name|chunk_s
block|{
name|chunk_common
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Find the chunk for a pointer. */
end_comment

begin_define
define|#
directive|define
name|ptr_is_in_chunk
parameter_list|(
name|ptr
parameter_list|,
name|cp
parameter_list|)
define|\
value|ptr_between((byte *)ptr, (cp)->cbot, (cp)->ctop)
end_define

begin_struct
struct|struct
name|chunk_locator_s
block|{
name|chunk_t
modifier|*
name|cp
decl_stmt|;
comment|/* one-element cache */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|bool
name|chunk_locate_ptr
argument_list|(
name|P2
argument_list|(
name|byte
operator|*
argument_list|,
name|cl_ptr_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|chunk_locate
parameter_list|(
name|ptr
parameter_list|,
name|clp
parameter_list|)
define|\
value|(ptr_is_in_chunk((byte *)(ptr), (clp)->cp) ||\    chunk_locate_ptr((byte *)(ptr), clp))
end_define

begin_comment
comment|/* ------ Concrete chunks ------ */
end_comment

begin_comment
comment|/* Many small structures. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|chunk_common
expr_stmt|;
name|struct_header_t
modifier|*
name|top
decl_stmt|;
block|}
name|chunk_structs_t
typedef|;
end_typedef

begin_comment
comment|/* One large structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|chunk_common
expr_stmt|;
block|}
name|chunk_large_struct_t
typedef|;
end_typedef

begin_comment
comment|/* Refs and strings. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|chunk_common
expr_stmt|;
name|struct
name|ref_s
modifier|*
name|rtop
decl_stmt|;
name|byte
modifier|*
name|ibot
decl_stmt|,
modifier|*
name|itop
decl_stmt|;
comment|/* Rest is for GC */
name|byte
modifier|*
name|ibits
decl_stmt|;
name|byte
modifier|*
name|ibase
decl_stmt|;
name|usize_t
name|ibitsize
decl_stmt|;
name|ushort
modifier|*
name|ireloc
decl_stmt|;
name|uint
name|imove
decl_stmt|;
block|}
name|chunk_refs_t
typedef|;
end_typedef

begin_comment
comment|/* ====== Definition of allocator state ====== */
end_comment

begin_typedef
typedef|typedef
name|struct
name|std_alloc_state_s
name|std_alloc_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|std_alloc_state_s
block|{
name|alloc_state_common
expr_stmt|;
name|chunk_structs_t
name|ccs
decl_stmt|;
comment|/* current structs chunk */
name|chunk_structs_t
modifier|*
name|pccs
decl_stmt|;
comment|/* where to put ccs */
name|chunk_refs_t
name|ccrs
decl_stmt|;
comment|/* current refs chunk */
name|chunk_refs_t
modifier|*
name|pccrs
decl_stmt|;
comment|/* where to put ccrs */
name|uint
name|chunk_size
decl_stmt|;
name|uint
name|large_size
decl_stmt|;
comment|/* min size for large chunk */
name|gc_root_t
modifier|*
name|roots
decl_stmt|;
name|chunk_t
name|chunk_min
decl_stmt|,
name|chunk_max
decl_stmt|;
comment|/* head and tail of chunk list */
block|}
struct|;
end_struct

end_unit

