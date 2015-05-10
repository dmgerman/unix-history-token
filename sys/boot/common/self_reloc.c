begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2010 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<elf.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ElfW_Rel
value|Elf64_Rela
end_define

begin_define
define|#
directive|define
name|ElfW_Dyn
value|Elf64_Dyn
end_define

begin_define
define|#
directive|define
name|ELFW_R_TYPE
value|ELF64_R_TYPE
end_define

begin_define
define|#
directive|define
name|ELF_RELA
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ElfW_Rel
value|Elf32_Rel
end_define

begin_define
define|#
directive|define
name|ElfW_Dyn
value|Elf32_Dyn
end_define

begin_define
define|#
directive|define
name|ELFW_R_TYPE
value|ELF32_R_TYPE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ElfW_Rel
value|Elf64_Rel
end_define

begin_define
define|#
directive|define
name|ElfW_Dyn
value|Elf64_Dyn
end_define

begin_define
define|#
directive|define
name|ELFW_R_TYPE
value|ELF64_R_TYPE
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|architecture not supported
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RELOC_TYPE_NONE
value|R_AARCH64_NONE
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE_RELATIVE
value|R_AARCH64_RELATIVE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RELOC_TYPE_NONE
value|R_X86_64_NONE
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE_RELATIVE
value|R_X86_64_RELATIVE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RELOC_TYPE_NONE
value|R_ARM_NONE
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE_RELATIVE
value|R_ARM_RELATIVE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RELOC_TYPE_NONE
value|R_386_NONE
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE_RELATIVE
value|R_386_RELATIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A simple elf relocator.  */
end_comment

begin_function
name|void
name|self_reloc
parameter_list|(
name|Elf_Addr
name|baseaddr
parameter_list|,
name|ElfW_Dyn
modifier|*
name|dynamic
parameter_list|)
block|{
name|Elf_Word
name|relsz
decl_stmt|,
name|relent
decl_stmt|;
name|Elf_Addr
modifier|*
name|newaddr
decl_stmt|;
name|ElfW_Rel
modifier|*
name|rel
decl_stmt|;
name|ElfW_Dyn
modifier|*
name|dynp
decl_stmt|;
comment|/* 	 * Find the relocation address, its size and the relocation entry. 	 */
name|relsz
operator|=
literal|0
expr_stmt|;
name|relent
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|dynp
operator|=
name|dynamic
init|;
name|dynp
operator|->
name|d_tag
operator|!=
name|DT_NULL
condition|;
name|dynp
operator|++
control|)
block|{
switch|switch
condition|(
name|dynp
operator|->
name|d_tag
condition|)
block|{
case|case
name|DT_REL
case|:
case|case
name|DT_RELA
case|:
name|rel
operator|=
operator|(
name|ElfW_Rel
operator|*
operator|)
operator|(
name|dynp
operator|->
name|d_un
operator|.
name|d_ptr
operator|+
name|baseaddr
operator|)
expr_stmt|;
break|break;
case|case
name|DT_RELSZ
case|:
case|case
name|DT_RELASZ
case|:
name|relsz
operator|=
name|dynp
operator|->
name|d_un
operator|.
name|d_val
expr_stmt|;
break|break;
case|case
name|DT_RELENT
case|:
case|case
name|DT_RELAENT
case|:
name|relent
operator|=
name|dynp
operator|->
name|d_un
operator|.
name|d_val
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
comment|/* 	 * Perform the actual relocation. 	 */
for|for
control|(
init|;
name|relsz
operator|>
literal|0
condition|;
name|relsz
operator|-=
name|relent
control|)
block|{
switch|switch
condition|(
name|ELFW_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
condition|)
block|{
case|case
name|RELOC_TYPE_NONE
case|:
comment|/* No relocation needs be performed. */
break|break;
case|case
name|RELOC_TYPE_RELATIVE
case|:
comment|/* Address relative to the base address. */
name|newaddr
operator|=
operator|(
name|Elf_Addr
operator|*
operator|)
operator|(
name|rel
operator|->
name|r_offset
operator|+
name|baseaddr
operator|)
expr_stmt|;
operator|*
name|newaddr
operator|+=
name|baseaddr
expr_stmt|;
comment|/* Add the addend when the ABI uses them */
ifdef|#
directive|ifdef
name|ELF_RELA
operator|*
name|newaddr
operator|+=
name|rel
operator|->
name|r_addend
expr_stmt|;
endif|#
directive|endif
break|break;
default|default:
comment|/* XXX: do we need other relocations ? */
break|break;
block|}
name|rel
operator|=
operator|(
name|ElfW_Rel
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|rel
operator|+
name|relent
operator|)
expr_stmt|;
block|}
block|}
end_function

end_unit

