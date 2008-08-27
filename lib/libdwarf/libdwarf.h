begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBDWARF_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBDWARF_H_
end_define

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_typedef
typedef|typedef
name|int
name|Dwarf_Bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|off_t
name|Dwarf_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Dwarf_Unsigned
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|Dwarf_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|Dwarf_Small
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|Dwarf_Signed
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Dwarf_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|Dwarf_Ptr
typedef|;
end_typedef

begin_comment
comment|/* Forward definitions. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Abbrev
modifier|*
name|Dwarf_Abbrev
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Arange
modifier|*
name|Dwarf_Arange
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Attribute
modifier|*
name|Dwarf_Attribute
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_AttrValue
modifier|*
name|Dwarf_AttrValue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_CU
modifier|*
name|Dwarf_CU
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Cie
modifier|*
name|Dwarf_Cie
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Debug
modifier|*
name|Dwarf_Debug
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Die
modifier|*
name|Dwarf_Die
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Fde
modifier|*
name|Dwarf_Fde
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Func
modifier|*
name|Dwarf_Func
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Global
modifier|*
name|Dwarf_Global
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Line
modifier|*
name|Dwarf_Line
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Type
modifier|*
name|Dwarf_Type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Var
modifier|*
name|Dwarf_Var
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Dwarf_Weak
modifier|*
name|Dwarf_Weak
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Dwarf_Small
name|lr_atom
decl_stmt|;
name|Dwarf_Unsigned
name|lr_number
decl_stmt|;
name|Dwarf_Unsigned
name|lr_number2
decl_stmt|;
name|Dwarf_Unsigned
name|lr_offset
decl_stmt|;
block|}
name|Dwarf_Loc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Dwarf_Addr
name|ld_lopc
decl_stmt|;
name|Dwarf_Addr
name|ld_hipc
decl_stmt|;
name|Dwarf_Half
name|ld_cents
decl_stmt|;
name|Dwarf_Loc
modifier|*
name|ld_s
decl_stmt|;
block|}
name|Dwarf_Locdesc
typedef|;
end_typedef

begin_comment
comment|/*  * Error numbers which are specific to this implementation.  */
end_comment

begin_enum
enum|enum
block|{
name|DWARF_E_NONE
block|,
comment|/* No error. */
name|DWARF_E_ERROR
block|,
comment|/* An error! */
name|DWARF_E_NO_ENTRY
block|,
comment|/* No entry. */
name|DWARF_E_ARGUMENT
block|,
comment|/* Invalid argument. */
name|DWARF_E_DEBUG_INFO
block|,
comment|/* Debug info NULL. */
name|DWARF_E_MEMORY
block|,
comment|/* Insufficient memory. */
name|DWARF_E_ELF
block|,
comment|/* ELF error. */
name|DWARF_E_INVALID_CU
block|,
comment|/* Invalid compilation unit data. */
name|DWARF_E_CU_VERSION
block|,
comment|/* Wrong CU version. */
name|DWARF_E_MISSING_ABBREV
block|,
comment|/* Abbrev not found. */
name|DWARF_E_NOT_IMPLEMENTED
block|,
comment|/* Not implemented. */
name|DWARF_E_CU_CURRENT
block|,
comment|/* No current compilation unit. */
name|DWARF_E_BAD_FORM
block|,
comment|/* Wrong form type for attribute value. */
name|DWARF_E_INVALID_EXPR
block|,
comment|/* Invalid DWARF expression. */
name|DWARF_E_NUM
comment|/* Max error number. */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|_Dwarf_Error
block|{
name|int
name|err_error
decl_stmt|;
comment|/* DWARF error. */
name|int
name|elf_error
decl_stmt|;
comment|/* ELF error. */
specifier|const
name|char
modifier|*
name|err_func
decl_stmt|;
comment|/* Function name where error occurred. */
name|int
name|err_line
decl_stmt|;
comment|/* Line number where error occurred. */
name|char
name|err_msg
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Formatted error message. */
block|}
name|Dwarf_Error
typedef|;
end_typedef

begin_comment
comment|/*  * Return values which have to be compatible with other  * implementations of libdwarf.  */
end_comment

begin_define
define|#
directive|define
name|DW_DLV_NO_ENTRY
value|DWARF_E_NO_ENTRY
end_define

begin_define
define|#
directive|define
name|DW_DLV_OK
value|DWARF_E_NONE
end_define

begin_define
define|#
directive|define
name|DW_DLE_DEBUG_INFO_NULL
value|DWARF_E_DEBUG_INFO
end_define

begin_define
define|#
directive|define
name|DW_DLC_READ
value|0
end_define

begin_comment
comment|/* read only access */
end_comment

begin_comment
comment|/* Function prototype definitions. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|Dwarf_Abbrev
name|dwarf_abbrev_find
parameter_list|(
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_AttrValue
name|dwarf_attrval_find
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Half
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Die
name|dwarf_die_find
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|dwarf_errmsg
parameter_list|(
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_sht_desc
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_attr_desc
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_form_desc
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_tag_desc
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_abbrev_add
parameter_list|(
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint8_t
parameter_list|,
name|Dwarf_Abbrev
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attr
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|Dwarf_Attribute
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attr_add
parameter_list|(
name|Dwarf_Abbrev
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Attribute
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|Dwarf_AttrValue
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval_add
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_AttrValue
parameter_list|,
name|Dwarf_AttrValue
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval_flag
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Bool
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval_signed
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Signed
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval_string
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_attrval_unsigned
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_child
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Die
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_die_add
parameter_list|(
name|Dwarf_CU
parameter_list|,
name|int
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Abbrev
parameter_list|,
name|Dwarf_Die
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_dieoffset
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Off
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_elf_init
parameter_list|(
name|Elf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Debug
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_errno
parameter_list|(
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_finish
parameter_list|(
name|Dwarf_Debug
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_locdesc
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Locdesc
modifier|*
modifier|*
parameter_list|,
name|Dwarf_Signed
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_locdesc_free
parameter_list|(
name|Dwarf_Locdesc
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_init
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Debug
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_next_cu_header
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|Dwarf_Half
modifier|*
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|Dwarf_Half
modifier|*
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_op_num
parameter_list|(
name|uint8_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_siblingof
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Die
parameter_list|,
name|Dwarf_Die
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_tag
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Half
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwarf_whatform
parameter_list|(
name|Dwarf_Attribute
parameter_list|,
name|Dwarf_Half
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dealloc
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Ptr
parameter_list|,
name|Dwarf_Unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_abbrev
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_av
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_AttrValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_dbgstr
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_die
parameter_list|(
name|Dwarf_Die
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_die_at_offset
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_info
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_shstrtab
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_strtab
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_symtab
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_raw
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_dump_tree
parameter_list|(
name|Dwarf_Debug
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
comment|/* !_LIBDWARF_H_ */
end_comment

end_unit

