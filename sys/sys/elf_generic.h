begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ELF_GENERIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ELF_GENERIC_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Definitions of generic ELF names which relieve applications from  * needing to know the word size.  */
end_comment

begin_if
if|#
directive|if
name|__ELF_WORD_SIZE
operator|!=
literal|32
operator|&&
name|__ELF_WORD_SIZE
operator|!=
literal|64
end_if

begin_error
error|#
directive|error
literal|"__ELF_WORD_SIZE must be defined as 32 or 64"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ELF_CLASS
value|__CONCAT(ELFCLASS,__ELF_WORD_SIZE)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ELF_DATA
value|ELFDATA2LSB
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|ELF_DATA
value|ELFDATA2MSB
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unknown byte order"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__ElfN
parameter_list|(
name|x
parameter_list|)
value|__CONCAT(__CONCAT(__CONCAT(Elf,__ELF_WORD_SIZE),_),x)
end_define

begin_define
define|#
directive|define
name|__ELFN
parameter_list|(
name|x
parameter_list|)
value|__CONCAT(__CONCAT(__CONCAT(ELF,__ELF_WORD_SIZE),_),x)
end_define

begin_define
define|#
directive|define
name|__ElfType
parameter_list|(
name|x
parameter_list|)
value|typedef __ElfN(x) __CONCAT(Elf_,x)
end_define

begin_expr_stmt
name|__ElfType
argument_list|(
name|Addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Half
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Off
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Sword
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Word
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Ehdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Shdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Phdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Dyn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Rel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Rela
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Sym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ELF_R_SYM
value|__ELFN(R_SYM)
end_define

begin_define
define|#
directive|define
name|ELF_R_TYPE
value|__ELFN(R_TYPE)
end_define

begin_define
define|#
directive|define
name|ELF_R_INFO
value|__ELFN(R_INFO)
end_define

begin_define
define|#
directive|define
name|ELF_ST_BIND
value|__ELFN(ST_BIND)
end_define

begin_define
define|#
directive|define
name|ELF_ST_TYPE
value|__ELFN(ST_TYPE)
end_define

begin_define
define|#
directive|define
name|ELF_ST_INFO
value|__ELFN(ST_INFO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ELF_GENERIC_H_ */
end_comment

end_unit

