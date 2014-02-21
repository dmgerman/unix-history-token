begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|"kgz.h"
end_include

begin_comment
comment|/* Relocatable header: part 0 */
end_comment

begin_struct
struct|struct
name|kgz_aouthdr0
block|{
name|struct
name|exec
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Symbol table entries */
end_comment

begin_define
define|#
directive|define
name|KGZ__STNUM
value|2
end_define

begin_comment
comment|/* Symbol table strings */
end_comment

begin_define
define|#
directive|define
name|KGZ__STR_KGZ
value|"_kgz"
end_define

begin_define
define|#
directive|define
name|KGZ__STR_KGZ_NDATA
value|"_kgz_ndata"
end_define

begin_comment
comment|/* String table */
end_comment

begin_struct
struct|struct
name|kgz__strtab
block|{
name|unsigned
name|long
name|length
decl_stmt|;
name|char
name|kgz
index|[
sizeof|sizeof
argument_list|(
name|KGZ__STR_KGZ
argument_list|)
index|]
decl_stmt|;
name|char
name|kgz_ndata
index|[
sizeof|sizeof
argument_list|(
name|KGZ__STR_KGZ_NDATA
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Relocatable header: part 1 */
end_comment

begin_struct
struct|struct
name|kgz_aouthdr1
block|{
name|struct
name|nlist
name|st
index|[
name|KGZ__STNUM
index|]
decl_stmt|;
name|struct
name|kgz__strtab
name|strtab
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|kgz_aouthdr0
name|aouthdr0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|kgz_aouthdr1
name|aouthdr1
decl_stmt|;
end_decl_stmt

end_unit

