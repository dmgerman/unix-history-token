begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|"kgz.h"
end_include

begin_comment
comment|/* Section header indices */
end_comment

begin_define
define|#
directive|define
name|KGZ_SH_SYMTAB
value|1
end_define

begin_define
define|#
directive|define
name|KGZ_SH_SHSTRTAB
value|2
end_define

begin_define
define|#
directive|define
name|KGZ_SH_STRTAB
value|3
end_define

begin_define
define|#
directive|define
name|KGZ_SH_DATA
value|4
end_define

begin_define
define|#
directive|define
name|KGZ_SHNUM
value|5
end_define

begin_comment
comment|/* Section header strings */
end_comment

begin_define
define|#
directive|define
name|KGZ_SHSTR_ZERO
value|""
end_define

begin_define
define|#
directive|define
name|KGZ_SHSTR_SYMTAB
value|".symtab"
end_define

begin_define
define|#
directive|define
name|KGZ_SHSTR_SHSTRTAB
value|".shstrtab"
end_define

begin_define
define|#
directive|define
name|KGZ_SHSTR_STRTAB
value|".strtab"
end_define

begin_define
define|#
directive|define
name|KGZ_SHSTR_DATA
value|".data"
end_define

begin_comment
comment|/* Section header string table */
end_comment

begin_struct
struct|struct
name|kgz_shstrtab
block|{
name|char
name|zero
index|[
sizeof|sizeof
argument_list|(
name|KGZ_SHSTR_ZERO
argument_list|)
index|]
decl_stmt|;
name|char
name|symtab
index|[
sizeof|sizeof
argument_list|(
name|KGZ_SHSTR_SYMTAB
argument_list|)
index|]
decl_stmt|;
name|char
name|shstrtab
index|[
sizeof|sizeof
argument_list|(
name|KGZ_SHSTR_SHSTRTAB
argument_list|)
index|]
decl_stmt|;
name|char
name|strtab
index|[
sizeof|sizeof
argument_list|(
name|KGZ_SHSTR_STRTAB
argument_list|)
index|]
decl_stmt|;
name|char
name|data
index|[
sizeof|sizeof
argument_list|(
name|KGZ_SHSTR_DATA
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Symbol table indices */
end_comment

begin_define
define|#
directive|define
name|KGZ_ST_KGZ
value|1
end_define

begin_define
define|#
directive|define
name|KGZ_ST_KGZ_NDATA
value|2
end_define

begin_define
define|#
directive|define
name|KGZ_STNUM
value|3
end_define

begin_comment
comment|/* Symbol table strings */
end_comment

begin_define
define|#
directive|define
name|KGZ_STR_ZERO
value|""
end_define

begin_define
define|#
directive|define
name|KGZ_STR_KGZ
value|"kgz"
end_define

begin_define
define|#
directive|define
name|KGZ_STR_KGZ_NDATA
value|"kgz_ndata"
end_define

begin_comment
comment|/* String table */
end_comment

begin_struct
struct|struct
name|kgz_strtab
block|{
name|char
name|zero
index|[
sizeof|sizeof
argument_list|(
name|KGZ_STR_ZERO
argument_list|)
index|]
decl_stmt|;
name|char
name|kgz
index|[
sizeof|sizeof
argument_list|(
name|KGZ_STR_KGZ
argument_list|)
index|]
decl_stmt|;
name|char
name|kgz_ndata
index|[
sizeof|sizeof
argument_list|(
name|KGZ_STR_KGZ_NDATA
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Relocatable header format */
end_comment

begin_struct
struct|struct
name|kgz_elfhdr
block|{
name|Elf32_Ehdr
name|e
decl_stmt|;
name|Elf32_Shdr
name|sh
index|[
name|KGZ_SHNUM
index|]
decl_stmt|;
name|Elf32_Sym
name|st
index|[
name|KGZ_STNUM
index|]
decl_stmt|;
name|struct
name|kgz_shstrtab
name|shstrtab
decl_stmt|;
name|struct
name|kgz_strtab
name|strtab
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|kgz_elfhdr
name|elfhdr
decl_stmt|;
end_decl_stmt

end_unit

