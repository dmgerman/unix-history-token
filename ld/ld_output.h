begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld_output.h 2959 2013-08-25 03:12:47Z kaiwang27 $  */
end_comment

begin_enum
enum|enum
name|ld_output_element_type
block|{
name|OET_ASSERT
block|,
name|OET_ASSIGN
block|,
name|OET_DATA
block|,
name|OET_ENTRY
block|,
name|OET_INPUT_SECTION_LIST
block|,
name|OET_KEYWORD
block|,
name|OET_OUTPUT_SECTION
block|,
name|OET_OVERLAY
block|,
name|OET_DATA_BUFFER
block|,
name|OET_SYMTAB
block|,
name|OET_STRTAB
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ld_output_element
block|{
name|enum
name|ld_output_element_type
name|oe_type
decl_stmt|;
comment|/* output element type */
name|uint64_t
name|oe_off
decl_stmt|;
comment|/* output element offset */
name|void
modifier|*
name|oe_entry
decl_stmt|;
comment|/* output element */
name|void
modifier|*
name|oe_islist
decl_stmt|;
comment|/* input section list */
name|unsigned
name|char
name|oe_insec
decl_stmt|;
comment|/* element inside SECTIONS */
name|STAILQ_ENTRY
argument_list|(
argument|ld_output_element
argument_list|)
name|oe_next
expr_stmt|;
comment|/* next element */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_output_element_head
argument_list|,
name|ld_output_element
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ld_output_data_buffer
block|{
name|uint8_t
modifier|*
name|odb_buf
decl_stmt|;
comment|/* point to data */
name|uint64_t
name|odb_size
decl_stmt|;
comment|/* buffer size */
name|uint64_t
name|odb_off
decl_stmt|;
comment|/* relative offset in output section */
name|uint64_t
name|odb_align
decl_stmt|;
comment|/* buffer alignment */
name|uint64_t
name|odb_type
decl_stmt|;
comment|/* buffer data type */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ld_reloc_entry_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_symbol
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_output_section
block|{
name|Elf_Scn
modifier|*
name|os_scn
decl_stmt|;
comment|/* output section descriptor */
name|char
modifier|*
name|os_name
decl_stmt|;
comment|/* output section name */
name|uint64_t
name|os_addr
decl_stmt|;
comment|/* output section vma */
name|uint64_t
name|os_lma
decl_stmt|;
comment|/* output section lma */
name|uint64_t
name|os_off
decl_stmt|;
comment|/* output section offset */
name|uint64_t
name|os_size
decl_stmt|;
comment|/* output section size */
name|uint64_t
name|os_align
decl_stmt|;
comment|/* output section alignment */
name|uint64_t
name|os_flags
decl_stmt|;
comment|/* output section flags */
name|uint64_t
name|os_type
decl_stmt|;
comment|/* output section type */
name|uint64_t
name|os_entsize
decl_stmt|;
comment|/* output seciton entry size */
name|uint64_t
name|os_info_val
decl_stmt|;
comment|/* output section info */
name|unsigned
name|char
name|os_empty
decl_stmt|;
comment|/* output section is empty */
name|unsigned
name|char
name|os_dynrel
decl_stmt|;
comment|/* contains dynamic relocations */
name|unsigned
name|char
name|os_pltrel
decl_stmt|;
comment|/* contains PLT relocations */
name|unsigned
name|char
name|os_rel
decl_stmt|;
comment|/* contains normal relocations */
name|unsigned
name|char
name|os_entsize_set
decl_stmt|;
comment|/* entsize is set */
name|char
modifier|*
name|os_link
decl_stmt|;
comment|/* link to other output section */
name|struct
name|ld_symbol
modifier|*
name|os_secsym
decl_stmt|;
comment|/* assoicated STT_SECTION symbol */
name|struct
name|ld_output_section
modifier|*
name|os_info
decl_stmt|;
comment|/* info refer to other section */
name|struct
name|ld_output_section
modifier|*
name|os_r
decl_stmt|;
comment|/* relocation section */
name|struct
name|ld_script_sections_output
modifier|*
name|os_ldso
decl_stmt|;
comment|/* output section descriptor */
name|struct
name|ld_output_element
modifier|*
name|os_pe
decl_stmt|;
comment|/* parent element */
name|struct
name|ld_output_element_head
name|os_e
decl_stmt|;
comment|/* list of child elements */
name|struct
name|ld_reloc_entry_head
modifier|*
name|os_reloc
decl_stmt|;
comment|/* list of relocations */
name|uint64_t
name|os_num_reloc
decl_stmt|;
comment|/* number of relocations */
name|STAILQ_ENTRY
argument_list|(
argument|ld_output_section
argument_list|)
name|os_next
expr_stmt|;
comment|/* next output section */
name|UT_hash_handle
name|hh
decl_stmt|;
comment|/* hash handle */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_output_section_head
argument_list|,
name|ld_output_section
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|ld_symver_verneed_head
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_output
block|{
name|int
name|lo_fd
decl_stmt|;
comment|/* output file descriptor */
name|Elf
modifier|*
name|lo_elf
decl_stmt|;
comment|/* output ELF descriptor */
name|int
name|lo_ec
decl_stmt|;
comment|/* output object elf class */
name|int
name|lo_endian
decl_stmt|;
comment|/* outout object endianess */
name|int
name|lo_osabi
decl_stmt|;
comment|/* output object osabi */
name|int
name|lo_soname_nameindex
decl_stmt|;
comment|/* string index for DT_SONAME */
name|int
name|lo_rpath_nameindex
decl_stmt|;
comment|/* string index for DT_RPATH */
name|unsigned
name|lo_phdr_num
decl_stmt|;
comment|/* num of phdrs */
name|unsigned
name|lo_phdr_note
decl_stmt|;
comment|/* create PT_NOTE */
name|unsigned
name|lo_dso_needed
decl_stmt|;
comment|/* num of DSO referenced */
name|unsigned
name|lo_version_index
decl_stmt|;
comment|/* current symver index */
name|unsigned
name|lo_verdef_num
decl_stmt|;
comment|/* num of verdef entries */
name|unsigned
name|lo_verneed_num
decl_stmt|;
comment|/* num of verneed entries */
name|unsigned
name|lo_rel_plt_type
decl_stmt|;
comment|/* type of PLT relocation */
name|unsigned
name|lo_rel_dyn_type
decl_stmt|;
comment|/* type of dynamic relocation */
name|unsigned
name|lo_fde_num
decl_stmt|;
comment|/* num of FDE in .eh_frame */
name|uint64_t
name|lo_shoff
decl_stmt|;
comment|/* section header table offset */
name|uint64_t
name|lo_tls_size
decl_stmt|;
comment|/* TLS segment size */
name|uint64_t
name|lo_tls_align
decl_stmt|;
comment|/* TLS segment align */
name|uint64_t
name|lo_tls_addr
decl_stmt|;
comment|/* TLS segment VMA */
name|size_t
name|lo_symtab_shndx
decl_stmt|;
comment|/* .symtab section index */
name|UT_array
modifier|*
name|lo_dso_nameindex
decl_stmt|;
comment|/* array of DSO name indices */
name|struct
name|ld_symver_verneed_head
modifier|*
name|lo_vnlist
decl_stmt|;
comment|/* Verneed list */
name|struct
name|ld_output_element_head
name|lo_oelist
decl_stmt|;
comment|/* output element list */
name|struct
name|ld_output_section_head
name|lo_oslist
decl_stmt|;
comment|/* output section list */
name|struct
name|ld_output_section
modifier|*
name|lo_ostbl
decl_stmt|;
comment|/* output section hash table */
name|struct
name|ld_output_section
modifier|*
name|lo_interp
decl_stmt|;
comment|/* .interp section. */
name|struct
name|ld_output_section
modifier|*
name|lo_init
decl_stmt|;
comment|/* .init section */
name|struct
name|ld_output_section
modifier|*
name|lo_fini
decl_stmt|;
comment|/* .fini section */
name|struct
name|ld_output_section
modifier|*
name|lo_dynamic
decl_stmt|;
comment|/* .dynamic section. */
name|struct
name|ld_output_section
modifier|*
name|lo_dynsym
decl_stmt|;
comment|/* .dynsym section. */
name|struct
name|ld_output_section
modifier|*
name|lo_dynstr
decl_stmt|;
comment|/* .dynstr section. */
name|struct
name|ld_output_section
modifier|*
name|lo_hash
decl_stmt|;
comment|/* .hash section. */
name|struct
name|ld_output_section
modifier|*
name|lo_verdef
decl_stmt|;
comment|/* .gnu.version.d section */
name|struct
name|ld_output_section
modifier|*
name|lo_verneed
decl_stmt|;
comment|/* .gnu.version.r section */
name|struct
name|ld_output_section
modifier|*
name|lo_versym
decl_stmt|;
comment|/* .gnu.version section */
name|struct
name|ld_output_section
modifier|*
name|lo_gotplt
decl_stmt|;
comment|/* GOT(for PLT) section */
name|struct
name|ld_output_section
modifier|*
name|lo_plt
decl_stmt|;
comment|/* PLT section */
name|struct
name|ld_output_section
modifier|*
name|lo_rel_plt
decl_stmt|;
comment|/* PLT relocation section */
name|struct
name|ld_output_section
modifier|*
name|lo_rel_dyn
decl_stmt|;
comment|/* Dynamic relocation section */
name|struct
name|ld_output_section
modifier|*
name|lo_ehframe_hdr
decl_stmt|;
comment|/* .eh_frame_hdr section */
name|struct
name|ld_output_data_buffer
modifier|*
name|lo_dynamic_odb
decl_stmt|;
comment|/* .dynamic buffer */
name|struct
name|ld_output_data_buffer
modifier|*
name|lo_got_odb
decl_stmt|;
comment|/* GOT section data */
name|struct
name|ld_output_data_buffer
modifier|*
name|lo_plt_odb
decl_stmt|;
comment|/* PLT section data */
name|struct
name|ld_output_data_buffer
modifier|*
name|lo_rel_plt_odb
decl_stmt|;
comment|/* PLT reloc data */
name|struct
name|ld_output_data_buffer
modifier|*
name|lo_rel_dyn_odb
decl_stmt|;
comment|/* dynamic reloc data */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|ld_output_section
modifier|*
name|ld_output_alloc_section
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ld_output_section
modifier|*
parameter_list|,
name|struct
name|ld_output_section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_create
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_output_element
modifier|*
name|ld_output_create_element
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_output_element_head
modifier|*
parameter_list|,
name|enum
name|ld_output_element_type
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|ld_output_element
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_output_element
modifier|*
name|ld_output_create_section_element
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_output_section
modifier|*
parameter_list|,
name|enum
name|ld_output_element_type
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|ld_output_element
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_create_elf_sections
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_create_string_table_section
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ld_strtab
modifier|*
parameter_list|,
name|Elf_Scn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_emit_gnu_stack_section
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_format
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_early_init
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_init
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_output_write
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

