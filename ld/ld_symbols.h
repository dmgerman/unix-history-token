begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld_symbols.h 2882 2013-01-09 22:47:04Z kaiwang27 $  */
end_comment

begin_struct_decl
struct_decl|struct
name|ld_symver_verdef
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ld_symbol
block|{
name|char
modifier|*
name|lsb_name
decl_stmt|;
comment|/* symbol name */
name|uint64_t
name|lsb_nameindex
decl_stmt|;
comment|/* symbol name index */
name|char
modifier|*
name|lsb_ver
decl_stmt|;
comment|/* symbol version */
name|char
modifier|*
name|lsb_longname
decl_stmt|;
comment|/* symbol name+version (as hash key)*/
name|uint64_t
name|lsb_size
decl_stmt|;
comment|/* symbol size */
name|uint64_t
name|lsb_value
decl_stmt|;
comment|/* symbol value */
name|uint16_t
name|lsb_shndx
decl_stmt|;
comment|/* symbol section index */
name|uint64_t
name|lsb_index
decl_stmt|;
comment|/* symbol index */
name|uint64_t
name|lsb_dyn_index
decl_stmt|;
comment|/* dynamic symbol index */
name|uint64_t
name|lsb_out_index
decl_stmt|;
comment|/* symbol index (in output) */
name|uint64_t
name|lsb_got_off
decl_stmt|;
comment|/* got entry offset */
name|uint64_t
name|lsb_plt_off
decl_stmt|;
comment|/* plt entry offset */
name|struct
name|ld_script_variable
modifier|*
name|lsb_var
decl_stmt|;
comment|/* associated ldscript variable */
name|unsigned
name|char
name|lsb_bind
decl_stmt|;
comment|/* symbol binding */
name|unsigned
name|char
name|lsb_type
decl_stmt|;
comment|/* symbol type */
name|unsigned
name|char
name|lsb_other
decl_stmt|;
comment|/* symbol visibility */
name|unsigned
name|char
name|lsb_default
decl_stmt|;
comment|/* symbol is default/only version */
name|unsigned
name|char
name|lsb_provide
decl_stmt|;
comment|/* provide symbol */
name|unsigned
name|char
name|lsb_import
decl_stmt|;
comment|/* symbol is a import symbol */
name|unsigned
name|char
name|lsb_ref_dso
decl_stmt|;
comment|/* symbol appeared in a DSO */
name|unsigned
name|char
name|lsb_ref_ndso
decl_stmt|;
comment|/* symbol appeared in elsewhere */
name|unsigned
name|char
name|lsb_dynrel
decl_stmt|;
comment|/* symbol used by dynamic reloc */
name|unsigned
name|char
name|lsb_copy_reloc
decl_stmt|;
comment|/* symbol has copy reloc */
name|unsigned
name|char
name|lsb_got
decl_stmt|;
comment|/* symbol has got entry */
name|unsigned
name|char
name|lsb_plt
decl_stmt|;
comment|/* symbol has plt entry */
name|unsigned
name|char
name|lsb_func_addr
decl_stmt|;
comment|/* symbol(function) has address */
name|unsigned
name|char
name|lsb_tls_ld
decl_stmt|;
comment|/* local dynamic TLS symbol */
name|unsigned
name|char
name|lsb_vndx_known
decl_stmt|;
comment|/* version index is known */
name|uint16_t
name|lsb_vndx
decl_stmt|;
comment|/* version index */
name|struct
name|ld_symver_verdef
modifier|*
name|lsb_vd
decl_stmt|;
comment|/* version definition */
name|struct
name|ld_symbol
modifier|*
name|lsb_prev
decl_stmt|;
comment|/* symbol resolved by this symbol */
name|struct
name|ld_symbol
modifier|*
name|lsb_ref
decl_stmt|;
comment|/* this symbol resolves to ... */
name|struct
name|ld_input
modifier|*
name|lsb_input
decl_stmt|;
comment|/* containing input object */
name|struct
name|ld_input_section
modifier|*
name|lsb_is
decl_stmt|;
comment|/* containing input section */
name|struct
name|ld_output_section
modifier|*
name|lsb_preset_os
decl_stmt|;
comment|/* Preset output section */
name|UT_hash_handle
name|hh
decl_stmt|;
comment|/* hash handle */
name|STAILQ_ENTRY
argument_list|(
argument|ld_symbol
argument_list|)
name|lsb_next
expr_stmt|;
comment|/* next symbol */
name|STAILQ_ENTRY
argument_list|(
argument|ld_symbol
argument_list|)
name|lsb_dyn
expr_stmt|;
comment|/* next dynamic symbol */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|ld_symbol_head
argument_list|,
name|ld_symbol
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ld_symbol_table
block|{
name|void
modifier|*
name|sy_buf
decl_stmt|;
name|size_t
name|sy_cap
decl_stmt|;
name|size_t
name|sy_size
decl_stmt|;
name|size_t
name|sy_first_nonlocal
decl_stmt|;
name|size_t
name|sy_write_pos
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_symbol_defver
block|{
name|char
modifier|*
name|dv_name
decl_stmt|;
name|char
modifier|*
name|dv_longname
decl_stmt|;
name|char
modifier|*
name|dv_ver
decl_stmt|;
name|UT_hash_handle
name|hh
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ld_symbols_add_extern
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
name|ld_symbols_add_variable
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_script_variable
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
name|ld_symbols_add_internal
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint16_t
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|struct
name|ld_input_section
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
name|ld_symbols_build_symtab
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_symbols_cleanup
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_symbols_scan
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_symbols_finalize_dynsym
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ld_symbols_get_value
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_symbols_resolve
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_symbols_update
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ld_symbol
modifier|*
name|ld_symbols_ref
parameter_list|(
name|struct
name|ld_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ld_symbols_overridden
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
name|int
name|ld_symbols_in_dso
parameter_list|(
name|struct
name|ld_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ld_symbols_in_regular
parameter_list|(
name|struct
name|ld_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

