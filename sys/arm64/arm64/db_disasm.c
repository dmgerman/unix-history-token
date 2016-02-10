begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_access.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_sym.h>
end_include

begin_include
include|#
directive|include
file|<machine/disassem.h>
end_include

begin_function_decl
specifier|static
name|u_int
name|db_disasm_read_word
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|db_disasm_printaddr
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Glue code to interface db_disasm to the generic ARM disassembler */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|disasm_interface
name|db_disasm_interface
init|=
block|{
operator|.
name|di_readword
operator|=
name|db_disasm_read_word
block|,
operator|.
name|di_printaddr
operator|=
name|db_disasm_printaddr
block|,
operator|.
name|di_printf
operator|=
name|db_printf
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|u_int
name|db_disasm_read_word
parameter_list|(
name|vm_offset_t
name|address
parameter_list|)
block|{
return|return
operator|(
name|db_get_value
argument_list|(
name|address
argument_list|,
name|INSN_SIZE
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|db_disasm_printaddr
parameter_list|(
name|vm_offset_t
name|address
parameter_list|)
block|{
name|db_printsym
argument_list|(
operator|(
name|db_addr_t
operator|)
name|address
argument_list|,
name|DB_STGY_ANY
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|vm_offset_t
name|db_disasm
parameter_list|(
name|vm_offset_t
name|loc
parameter_list|,
name|bool
name|altfmt
parameter_list|)
block|{
return|return
operator|(
name|disasm
argument_list|(
operator|&
name|db_disasm_interface
argument_list|,
name|loc
argument_list|,
name|altfmt
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* End of db_disasm.c */
end_comment

end_unit

