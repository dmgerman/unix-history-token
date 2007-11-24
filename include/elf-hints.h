begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_HINTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ELF_HINTS_H_
end_define

begin_comment
comment|/*  * Hints file produced by ldconfig.  */
end_comment

begin_struct
struct|struct
name|elfhints_hdr
block|{
name|u_int32_t
name|magic
decl_stmt|;
comment|/* Magic number */
name|u_int32_t
name|version
decl_stmt|;
comment|/* File version (1) */
name|u_int32_t
name|strtab
decl_stmt|;
comment|/* Offset of string table in file */
name|u_int32_t
name|strsize
decl_stmt|;
comment|/* Size of string table */
name|u_int32_t
name|dirlist
decl_stmt|;
comment|/* Offset of directory list in 					   string table */
name|u_int32_t
name|dirlistlen
decl_stmt|;
comment|/* strlen(dirlist) */
name|u_int32_t
name|spare
index|[
literal|26
index|]
decl_stmt|;
comment|/* Room for expansion */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ELFHINTS_MAGIC
value|0x746e6845
end_define

begin_define
define|#
directive|define
name|_PATH_ELF_HINTS
value|"/var/run/ld-elf.so.hints"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ELF_HINTS_H_ */
end_comment

end_unit

