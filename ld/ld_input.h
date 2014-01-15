begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld_input.h 2960 2013-08-25 03:13:07Z kaiwang27 $  */
end_comment

begin_struct_decl
struct_decl|struct
name|ld_reloc_entry_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_ehframe_fde_head
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_section_group
block|{
name|char
modifier|*
name|sg_name
decl_stmt|;
name|UT_hash_handle
name|hh
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_input_section
block|{
name|char
modifier|*
name|is_name
decl_stmt|;
comment|/* section name */
name|struct
name|ld_input
modifier|*
name|is_input
decl_stmt|;
comment|/* containing input object */
name|struct
name|ld_output_section
modifier|*
name|is_output
decl_stmt|;
comment|/* containing output section */
name|uint64_t
name|is_off
decl_stmt|;
comment|/* section file offset */
name|uint64_t
name|is_reloff
decl_stmt|;
comment|/* relative offset in output section */
name|uint64_t
name|is_addr
decl_stmt|;
comment|/* section vma */
name|uint64_t
name|is_size
decl_stmt|;
comment|/* section file size */
name|uint64_t
name|is_shrink
decl_stmt|;
comment|/* section shrinked bytes */
name|uint64_t
name|is_entsize
decl_stmt|;
comment|/* seciton entry size */
name|uint64_t
name|is_align
decl_stmt|;
comment|/* section align */
name|uint64_t
name|is_type
decl_stmt|;
comment|/* section type */
name|uint64_t
name|is_flags
decl_stmt|;
comment|/* section flags */
name|uint64_t
name|is_link
decl_stmt|;
comment|/* section link */
name|uint64_t
name|is_info
decl_stmt|;
comment|/* section info */
name|uint64_t
name|is_index
decl_stmt|;
comment|/* section index */
name|unsigned
name|char
name|is_discard
decl_stmt|;
comment|/* dicard section */
name|unsigned
name|char
name|is_dynrel
decl_stmt|;
comment|/* section holds dynamic relocations */
name|unsigned
name|char
name|is_pltrel
decl_stmt|;
comment|/* section holds PLT relocations */
name|unsigned
name|char
name|is_refed
decl_stmt|;
comment|/* should not be gc'ed */
name|unsigned
name|char
name|is_need_reloc
decl_stmt|;
comment|/* need apply relocation */
name|void
modifier|*
name|is_data
decl_stmt|;
comment|/* output section data descriptor */
name|void
modifier|*
name|is_ibuf
decl_stmt|;
comment|/* buffer for internal sections */
name|void
modifier|*
name|is_ehframe
decl_stmt|;
comment|/* temp buffer for ehframe section. */
name|struct
name|ld_reloc_entry_head
modifier|*
name|is_reloc
decl_stmt|;
comment|/* list of relocation entries */
name|uint64_t
name|is_num_reloc
decl_stmt|;
comment|/* number of reloc entries */
name|struct
name|ld_input_section
modifier|*
name|is_tis
decl_stmt|;
comment|/* relocation target */
name|struct
name|ld_input_section
modifier|*
name|is_ris
decl_stmt|;
comment|/* relocation section */
name|struct
name|ld_ehframe_fde_head
modifier|*
name|is_fde
decl_stmt|;
comment|/* list of FDE */
name|STAILQ_ENTRY
argument_list|(
argument|ld_input_section
argument_list|)
name|is_next
expr_stmt|;
comment|/* next section */
name|STAILQ_ENTRY
argument_list|(
argument|ld_input_section
argument_list|)
name|is_gc_next
expr_stmt|;
comment|/* next gc search */
name|UT_hash_handle
name|hh
decl_stmt|;
comment|/* hash handle (internal section) */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_input_section_head
argument_list|,
name|ld_input_section
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|ld_input_type
block|{
name|LIT_UNKNOWN
block|,
name|LIT_RELOCATABLE
block|,
name|LIT_DSO
block|, }
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ld_symver_verdef_head
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_input
block|{
name|char
modifier|*
name|li_name
decl_stmt|;
comment|/* input object name */
name|char
modifier|*
name|li_fullname
decl_stmt|;
comment|/* input object and archive name */
name|char
modifier|*
name|li_soname
decl_stmt|;
comment|/* input object DT_SONAME. */
name|Elf
modifier|*
name|li_elf
decl_stmt|;
comment|/* input object ELF descriptor */
name|enum
name|ld_input_type
name|li_type
decl_stmt|;
comment|/* input object kind */
name|struct
name|ld_file
modifier|*
name|li_file
decl_stmt|;
comment|/* containing file */
name|size_t
name|li_shnum
decl_stmt|;
comment|/* num of sections in ELF object */
name|struct
name|ld_input_section
modifier|*
name|li_is
decl_stmt|;
comment|/* input section list */
name|struct
name|ld_input_section
modifier|*
name|li_istbl
decl_stmt|;
comment|/* internal section hash table */
name|struct
name|ld_archive_member
modifier|*
name|li_lam
decl_stmt|;
comment|/* archive member */
name|struct
name|ld_symbol_head
modifier|*
name|li_local
decl_stmt|;
comment|/* local symbol list */
name|struct
name|ld_symbol
modifier|*
modifier|*
name|li_symindex
decl_stmt|;
comment|/* symbol index table */
name|size_t
name|li_symnum
decl_stmt|;
comment|/* number of symbols */
name|char
modifier|*
modifier|*
name|li_vername
decl_stmt|;
comment|/* version name array */
name|size_t
name|li_vername_sz
decl_stmt|;
comment|/* version name array size */
name|uint16_t
modifier|*
name|li_versym
decl_stmt|;
comment|/* symbol version array */
name|size_t
name|li_versym_sz
decl_stmt|;
comment|/* symbol version array size */
name|int
name|li_dso_refcnt
decl_stmt|;
comment|/* symbol reference count (DSO) */
name|struct
name|ld_symver_verdef_head
modifier|*
name|li_verdef
decl_stmt|;
comment|/* version definition */
name|STAILQ_ENTRY
argument_list|(
argument|ld_input
argument_list|)
name|li_next
expr_stmt|;
comment|/* next input object */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ld_input_init
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_add_symbol
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input
modifier|*
parameter_list|,
name|struct
name|ld_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_input_section
modifier|*
name|ld_input_add_internal_section
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_input_section
modifier|*
name|ld_input_find_internal_section
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_alloc_internal_section_buffers
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_input
modifier|*
name|ld_input_alloc
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_alloc_common_symbol
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ld_input_get_section_rawdata
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input_section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_cleanup
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ld_input_get_fullname
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_init_sections
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input
modifier|*
parameter_list|,
name|Elf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_link_objects
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_load
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_input_unload
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_input
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|ld_input_reserve_ibuf
parameter_list|(
name|struct
name|ld_input_section
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

