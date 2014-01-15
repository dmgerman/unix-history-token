begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld_script.h 2881 2013-01-09 22:46:54Z kaiwang27 $  */
end_comment

begin_enum
enum|enum
name|ld_script_cmd_type
block|{
name|LSC_ASSERT
block|,
name|LSC_ASSIGN
block|,
name|LSC_AS_NEEDED
block|,
name|LSC_ENTRY
block|,
name|LSC_EXTERN
block|,
name|LSC_FCA
block|,
name|LSC_HIDDEN_ASSIGN
block|,
name|LSC_ICA
block|,
name|LSC_INPUT
block|,
name|LSC_MEMORY
block|,
name|LSC_NOCROSSREFS
block|,
name|LSC_OUTPUT
block|,
name|LSC_OUTPUT_ARCH
block|,
name|LSC_OUTPUT_FORMAT
block|,
name|LSC_PHDRS
block|,
name|LSC_PROVIDE_ASSIGN
block|,
name|LSC_REGION_ALIAS
block|,
name|LSC_SEARCH_DIR
block|,
name|LSC_SECTIONS
block|,
name|LSC_SECTIONS_OUTPUT
block|,
name|LSC_SECTIONS_OUTPUT_DATA
block|,
name|LSC_SECTIONS_OUTPUT_INPUT
block|,
name|LSC_SECTIONS_OUTPUT_KEYWORD
block|,
name|LSC_SECTIONS_OVERLAY
block|,
name|LSC_STARTUP
block|,
name|LSC_TARGET
block|,
name|LSC_VERSION
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ld_script_cmd
block|{
name|enum
name|ld_script_cmd_type
name|ldc_type
decl_stmt|;
comment|/* ldscript cmd type */
name|void
modifier|*
name|ldc_cmd
decl_stmt|;
comment|/* ldscript cmd */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_cmd
argument_list|)
name|ldc_next
expr_stmt|;
comment|/* next cmd */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_script_cmd_head
argument_list|,
name|ld_script_cmd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ld_script_list
block|{
name|void
modifier|*
name|ldl_entry
decl_stmt|;
comment|/* list entry */
name|struct
name|ld_script_list
modifier|*
name|ldl_next
decl_stmt|;
comment|/* next entry */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_assert
block|{
name|struct
name|ld_exp
modifier|*
name|lda_exp
decl_stmt|;
comment|/* expression to assert */
name|char
modifier|*
name|lda_msg
decl_stmt|;
comment|/* assertion message */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ld_script_assign_op
block|{
name|LSAOP_ADD_E
block|,
name|LSAOP_AND_E
block|,
name|LSAOP_DIV_E
block|,
name|LSAOP_E
block|,
name|LSAOP_LSHIFT_E
block|,
name|LSAOP_MUL_E
block|,
name|LSAOP_OR_E
block|,
name|LSAOP_RSHIFT_E
block|,
name|LSAOP_SUB_E
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ld_script_assign
block|{
name|struct
name|ld_exp
modifier|*
name|lda_var
decl_stmt|;
comment|/* symbol */
name|struct
name|ld_exp
modifier|*
name|lda_val
decl_stmt|;
comment|/* value */
name|enum
name|ld_script_assign_op
name|lda_op
decl_stmt|;
comment|/* assign op */
name|unsigned
name|lda_provide
decl_stmt|;
comment|/* provide assign */
name|int64_t
name|lda_res
decl_stmt|;
comment|/* assign result */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_input_file
block|{
name|unsigned
name|ldif_as_needed
decl_stmt|;
comment|/* as_needed list */
union|union
block|{
name|char
modifier|*
name|ldif_name
decl_stmt|;
comment|/* input file name */
name|struct
name|ld_script_list
modifier|*
name|ldif_ldl
decl_stmt|;
comment|/* input file list */
block|}
name|ldif_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_nocrossref
block|{
name|struct
name|ld_script_list
modifier|*
name|ldn_l
decl_stmt|;
comment|/* nocrossref sections */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_nocrossref
argument_list|)
name|ldn_next
expr_stmt|;
comment|/* next nocrossref */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_region
block|{
name|char
modifier|*
name|ldsr_name
decl_stmt|;
comment|/* memory region name */
name|char
modifier|*
name|ldsr_attr
decl_stmt|;
comment|/* memory region attribute */
name|struct
name|ld_exp
modifier|*
name|ldsr_origin
decl_stmt|;
comment|/* memroy region start address */
name|struct
name|ld_exp
modifier|*
name|ldsr_len
decl_stmt|;
comment|/* memroy region length */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_region
argument_list|)
name|ldsr_next
expr_stmt|;
comment|/* next memory region */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_region_alias
block|{
name|char
modifier|*
name|ldra_alias
decl_stmt|;
comment|/* memory region alias name */
name|char
modifier|*
name|ldra_region
decl_stmt|;
comment|/* memory region */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_region_alias
argument_list|)
name|ldra_next
expr_stmt|;
comment|/* next region alias */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_phdr
block|{
name|char
modifier|*
name|ldsp_name
decl_stmt|;
comment|/* phdr name */
name|char
modifier|*
name|ldsp_type
decl_stmt|;
comment|/* phdr type */
name|unsigned
name|ldsp_filehdr
decl_stmt|;
comment|/* FILEHDR keyword */
name|unsigned
name|ldsp_phdrs
decl_stmt|;
comment|/* PHDRS keyword */
name|struct
name|ld_exp
modifier|*
name|ldsp_addr
decl_stmt|;
comment|/* segment address */
name|unsigned
name|ldsp_flags
decl_stmt|;
comment|/* segment flags */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_phdr
argument_list|)
name|ldsp_next
expr_stmt|;
comment|/* next phdr */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ld_script_sections_output_data_type
block|{
name|LSODT_BYTE
block|,
name|LSODT_SHORT
block|,
name|LSODT_LONG
block|,
name|LSODT_QUAD
block|,
name|LSODT_SQUAD
block|,
name|LSODT_FILL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ld_script_sections_output_data
block|{
name|enum
name|ld_script_sections_output_data_type
name|ldod_type
decl_stmt|;
comment|/* data type */
name|struct
name|ld_exp
modifier|*
name|ldod_exp
decl_stmt|;
comment|/* data expression */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_sections_output_input
block|{
name|struct
name|ld_wildcard
modifier|*
name|ldoi_ar
decl_stmt|;
comment|/* archive name */
name|struct
name|ld_wildcard
modifier|*
name|ldoi_file
decl_stmt|;
comment|/* file/member name */
name|struct
name|ld_script_list
modifier|*
name|ldoi_exclude
decl_stmt|;
comment|/* exclude file list */
name|struct
name|ld_script_list
modifier|*
name|ldoi_sec
decl_stmt|;
comment|/* section name list */
name|unsigned
name|ldoi_flags
decl_stmt|;
comment|/* input section flags */
name|unsigned
name|ldoi_keep
decl_stmt|;
comment|/* keep input section */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ld_script_sections_output_keywords
block|{
name|LSOK_CONSTRUCTORS
block|,
name|LSOK_CONSTRUCTORS_SORT_BY_NAME
block|,
name|LSOK_CREATE_OBJECT_SYMBOLS
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ld_script_sections_output
block|{
name|char
modifier|*
name|ldso_name
decl_stmt|;
comment|/* output section name */
name|char
modifier|*
name|ldso_type
decl_stmt|;
comment|/* output section type */
name|struct
name|ld_exp
modifier|*
name|ldso_vma
decl_stmt|;
comment|/* output section vma */
name|struct
name|ld_exp
modifier|*
name|ldso_lma
decl_stmt|;
comment|/* output section lma */
name|struct
name|ld_exp
modifier|*
name|ldso_align
decl_stmt|;
comment|/* output section align */
name|struct
name|ld_exp
modifier|*
name|ldso_subalign
decl_stmt|;
comment|/* output sectino subalign */
name|char
modifier|*
name|ldso_constraint
decl_stmt|;
comment|/* output section constraint */
name|char
modifier|*
name|ldso_region
decl_stmt|;
comment|/* output section region */
name|char
modifier|*
name|ldso_lma_region
decl_stmt|;
comment|/* output section lma region */
name|struct
name|ld_script_list
modifier|*
name|ldso_phdr
decl_stmt|;
comment|/* output section segment list */
name|struct
name|ld_exp
modifier|*
name|ldso_fill
decl_stmt|;
comment|/* output section fill exp */
name|struct
name|ld_script_cmd_head
name|ldso_c
decl_stmt|;
comment|/* output section cmd list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_sections_overlay_section
block|{
name|char
modifier|*
name|ldos_name
decl_stmt|;
comment|/* overlay section name */
name|struct
name|ld_script_list
modifier|*
name|ldos_phdr
decl_stmt|;
comment|/* overlay section segment */
name|struct
name|ld_exp
modifier|*
name|ldos_fill
decl_stmt|;
comment|/* overlay section fill exp */
name|struct
name|ld_script_cmd_head
name|ldos_c
decl_stmt|;
comment|/* output section cmd list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_sections_overlay
block|{
name|struct
name|ld_exp
modifier|*
name|ldso_vma
decl_stmt|;
comment|/* overlay vma */
name|struct
name|ld_exp
modifier|*
name|ldso_lma
decl_stmt|;
comment|/* overlay lma */
name|unsigned
name|ldso_nocrossref
decl_stmt|;
comment|/* no corss-ref between sections */
name|char
modifier|*
name|ldso_region
decl_stmt|;
comment|/* overlay region */
name|struct
name|ld_script_list
modifier|*
name|ldso_phdr
decl_stmt|;
comment|/* overlay segment */
name|struct
name|ld_exp
modifier|*
name|ldso_fill
decl_stmt|;
comment|/* overlay fill exp */
name|struct
name|ld_script_list
modifier|*
name|ldso_s
decl_stmt|;
comment|/* overlay section list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_sections
block|{
name|struct
name|ld_script_cmd_head
name|ldss_c
decl_stmt|;
comment|/* section cmd list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script_variable
block|{
name|char
modifier|*
name|ldv_name
decl_stmt|;
comment|/* variable name */
name|struct
name|ld_symbol
modifier|*
name|ldv_symbol
decl_stmt|;
comment|/* assoicated symbol */
name|int64_t
name|ldv_val
decl_stmt|;
comment|/* variable value */
name|UT_hash_handle
name|hh
decl_stmt|;
comment|/* hash handle */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ld_script_version_lang
block|{
name|VL_C
init|=
literal|0
block|,
name|VL_CPP
block|,
name|VL_JAVA
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ld_script_version_entry_head
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_script_version_entry
block|{
name|enum
name|ld_script_version_lang
name|ldve_lang
decl_stmt|;
comment|/* version entry lanauage */
name|char
modifier|*
name|ldve_sym
decl_stmt|;
comment|/* symbol wildcard */
name|unsigned
name|char
name|ldve_local
decl_stmt|;
comment|/* symbol scope */
name|unsigned
name|char
name|ldve_glob
decl_stmt|;
comment|/* ldve_sym contains glob chars. */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_version_entry
argument_list|)
name|ldve_next
expr_stmt|;
comment|/* Following fields are only used during script parsing. */
name|struct
name|ld_script_version_entry_head
modifier|*
name|ldve_list
decl_stmt|;
comment|/* extern block */
name|unsigned
name|char
name|ldve_lang_set
decl_stmt|;
comment|/* lang is set  */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_script_version_entry_head
argument_list|,
name|ld_script_version_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ld_script_version_node
block|{
name|char
modifier|*
name|ldvn_name
decl_stmt|;
comment|/* version name */
name|char
modifier|*
name|ldvn_dep
decl_stmt|;
comment|/* version dependency */
name|struct
name|ld_script_version_entry_head
modifier|*
name|ldvn_e
decl_stmt|;
comment|/* version entries */
name|STAILQ_ENTRY
argument_list|(
argument|ld_script_version_node
argument_list|)
name|ldvn_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_script
block|{
name|char
modifier|*
name|lds_entry_point
decl_stmt|;
comment|/* entry point symbol */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_script_phdr
argument_list|)
name|lds_p
expr_stmt|;
comment|/* phdr table */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_script_region_alias
argument_list|)
name|lds_a
expr_stmt|;
comment|/* region aliases list */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_script_region
argument_list|)
name|lds_r
expr_stmt|;
comment|/* memory region list */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_script_nocrossref
argument_list|)
name|lds_n
expr_stmt|;
comment|/* nocrossref list */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_script_version_node
argument_list|)
name|lds_vn
expr_stmt|;
comment|/* version node list */
name|unsigned
name|char
name|lds_vn_name_omitted
decl_stmt|;
comment|/* version node w/o name exists */
name|struct
name|ld_script_cmd_head
name|lds_c
decl_stmt|;
comment|/* other ldscript cmd list */
name|struct
name|ld_script_variable
modifier|*
name|lds_v
decl_stmt|;
comment|/* variable table */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|ld_script_cmd
modifier|*
name|ld_script_assert
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_exp
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_assign
modifier|*
name|ld_script_assign
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_exp
modifier|*
parameter_list|,
name|enum
name|ld_script_assign_op
parameter_list|,
name|struct
name|ld_exp
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_assign_dump
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_assign
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_assign_free
parameter_list|(
name|struct
name|ld_script_assign
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_cleanup
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_cmd
modifier|*
name|ld_script_cmd
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|enum
name|ld_script_cmd_type
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_cmd_free
parameter_list|(
name|struct
name|ld_script_cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_cmd_insert
parameter_list|(
name|struct
name|ld_script_cmd_head
modifier|*
parameter_list|,
name|struct
name|ld_script_cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_extern
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_group
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_init
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_input
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_input_file
modifier|*
name|ld_script_input_file
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_list
modifier|*
name|ld_script_list
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_list
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_list_free
parameter_list|(
name|struct
name|ld_script_list
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_list
modifier|*
name|ld_script_list_reverse
parameter_list|(
name|struct
name|ld_script_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_nocrossrefs
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_phdr
modifier|*
name|ld_script_phdr
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
name|unsigned
parameter_list|,
name|unsigned
parameter_list|,
name|struct
name|ld_exp
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_parse_internal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_region
modifier|*
name|ld_script_region
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
name|struct
name|ld_exp
modifier|*
parameter_list|,
name|struct
name|ld_exp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_process_assign
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_assign
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_process_entry
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_region_alias
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|ld_script_variable_value
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_version_add_node
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_script_version_entry
modifier|*
name|ld_script_version_alloc_entry
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ld_script_version_link_entry
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_version_entry_head
modifier|*
parameter_list|,
name|struct
name|ld_script_version_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_script_version_set_lang
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_version_entry_head
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

