begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"_libdwarf.h"
end_include

begin_expr_stmt
name|ELFTC_VCSID
argument_list|(
literal|"$Id: dwarf_errmsg.c 2576 2012-09-13 09:16:11Z jkoshy $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|_libdwarf_errors
index|[]
init|=
block|{
define|#
directive|define
name|DEFINE_ERROR
parameter_list|(
name|N
parameter_list|,
name|S
parameter_list|)
value|[DW_DLE_##N] = S
name|DEFINE_ERROR
argument_list|(
name|NONE
argument_list|,
literal|"No Error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ERROR
argument_list|,
literal|"An error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|NO_ENTRY
argument_list|,
literal|"No entry found"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ARGUMENT
argument_list|,
literal|"Invalid argument"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_INFO_NULL
argument_list|,
literal|"Debug info NULL"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|MEMORY
argument_list|,
literal|"Insufficient memory"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ELF
argument_list|,
literal|"ELF error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|CU_LENGTH_ERROR
argument_list|,
literal|"Invalid compilation unit data"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|VERSION_STAMP_ERROR
argument_list|,
literal|"Unsupported version"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_ABBREV_NULL
argument_list|,
literal|"Abbrev not found"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DIE_NO_CU_CONTEXT
argument_list|,
literal|"No current compilation unit"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|LOC_EXPR_BAD
argument_list|,
literal|"Invalid location expression"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|EXPR_LENGTH_BAD
argument_list|,
literal|"Invalid DWARF expression length"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_LOC_SECTION_SHORT
argument_list|,
literal|"Loclist section too short"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ATTR_FORM_BAD
argument_list|,
literal|"Invalid attribute form"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_LINE_LENGTH_BAD
argument_list|,
literal|"Line info section too short"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|LINE_FILE_NUM_BAD
argument_list|,
literal|"Invalid file number."
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DIR_INDEX_BAD
argument_list|,
literal|"Invalid dir index."
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_FRAME_LENGTH_BAD
argument_list|,
literal|"Frame section too short"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|NO_CIE_FOR_FDE
argument_list|,
literal|"FDE without corresponding CIE"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|FRAME_AUGMENTATION_UNKNOWN
argument_list|,
literal|"Unknown CIE augmentation"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|FRAME_INSTR_EXEC_ERROR
argument_list|,
literal|"Frame instruction exec error"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|FRAME_VERSION_BAD
argument_list|,
literal|"Unsupported frame section version"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|FRAME_TABLE_COL_BAD
argument_list|,
literal|"Invalid table column value"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DF_REG_NUM_TOO_HIGH
argument_list|,
literal|"Register number too large"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|PC_NOT_IN_FDE_RANGE
argument_list|,
literal|"PC requested not in the FDE range"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ARANGE_OFFSET_BAD
argument_list|,
literal|"Invalid address range offset"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|DEBUG_MACRO_INCONSISTENT
argument_list|,
literal|"Invalid macinfo data"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
name|ELF_SECT_ERR
argument_list|,
literal|"Application callback failed"
argument_list|)
block|,
name|DEFINE_ERROR
argument_list|(
argument|NUM
argument_list|,
literal|"Unknown DWARF error"
argument_list|)
undef|#
directive|undef
name|DEFINE_ERROR
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|dwarf_errmsg_
parameter_list|(
name|Dwarf_Error
modifier|*
name|error
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|error
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
if|if
condition|(
name|error
operator|->
name|err_error
operator|<
literal|0
operator|||
name|error
operator|->
name|err_error
operator|>=
name|DW_DLE_NUM
condition|)
return|return
name|_libdwarf_errors
index|[
name|DW_DLE_NUM
index|]
return|;
elseif|else
if|if
condition|(
name|error
operator|->
name|err_error
operator|==
name|DW_DLE_NONE
condition|)
return|return
name|_libdwarf_errors
index|[
name|DW_DLE_NONE
index|]
return|;
else|else
name|p
operator|=
name|_libdwarf_errors
index|[
name|error
operator|->
name|err_error
index|]
expr_stmt|;
if|if
condition|(
name|error
operator|->
name|err_error
operator|==
name|DW_DLE_ELF
condition|)
name|snprintf
argument_list|(
name|error
operator|->
name|err_msg
argument_list|,
sizeof|sizeof
argument_list|(
name|error
operator|->
name|err_msg
argument_list|)
argument_list|,
literal|"ELF error : %s [%s(%d)]"
argument_list|,
name|elf_errmsg
argument_list|(
name|error
operator|->
name|err_elferror
argument_list|)
argument_list|,
name|error
operator|->
name|err_func
argument_list|,
name|error
operator|->
name|err_line
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|error
operator|->
name|err_msg
argument_list|,
sizeof|sizeof
argument_list|(
name|error
operator|->
name|err_msg
argument_list|)
argument_list|,
literal|"%s [%s(%d)]"
argument_list|,
name|p
argument_list|,
name|error
operator|->
name|err_func
argument_list|,
name|error
operator|->
name|err_line
argument_list|)
expr_stmt|;
return|return
operator|(
specifier|const
name|char
operator|*
operator|)
name|error
operator|->
name|err_msg
return|;
block|}
end_function

end_unit

