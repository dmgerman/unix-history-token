begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2008 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBPROC_H_
end_ifndef

begin_define
define|#
directive|define
name|__LIBPROC_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|<rtld_db.h>
end_include

begin_include
include|#
directive|include
file|"libproc.h"
end_include

begin_struct_decl
struct_decl|struct
name|procstat
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|symtab
block|{
name|Elf_Data
modifier|*
name|data
decl_stmt|;
name|u_int
name|nsyms
decl_stmt|;
name|u_int
modifier|*
name|index
decl_stmt|;
name|u_long
name|stridx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|file_info
block|{
name|Elf
modifier|*
name|elf
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|u_int
name|refs
decl_stmt|;
name|GElf_Ehdr
name|ehdr
decl_stmt|;
comment|/* Symbol tables, sorted by value. */
name|struct
name|symtab
name|dynsymtab
decl_stmt|;
name|struct
name|symtab
name|symtab
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|map_info
block|{
name|prmap_t
name|map
decl_stmt|;
name|struct
name|file_info
modifier|*
name|file
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|proc_handle
block|{
name|struct
name|proc_handle_public
name|public
decl_stmt|;
comment|/* Public fields. */
name|int
name|flags
decl_stmt|;
comment|/* Process flags. */
name|int
name|status
decl_stmt|;
comment|/* Process status (PS_*). */
name|int
name|wstat
decl_stmt|;
comment|/* Process wait status. */
name|int
name|model
decl_stmt|;
comment|/* Process data model. */
name|rd_agent_t
modifier|*
name|rdap
decl_stmt|;
comment|/* librtld_db agent */
name|struct
name|map_info
modifier|*
name|mappings
decl_stmt|;
comment|/* File mappings for proc. */
name|size_t
name|maparrsz
decl_stmt|;
comment|/* Map array size. */
name|size_t
name|nmappings
decl_stmt|;
comment|/* Number of mappings. */
name|size_t
name|exec_map
decl_stmt|;
comment|/* Executable text mapping index. */
name|lwpstatus_t
name|lwps
decl_stmt|;
comment|/* Process status. */
name|struct
name|procstat
modifier|*
name|procstat
decl_stmt|;
comment|/* libprocstat handle. */
name|char
name|execpath
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to program executable. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|warn(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DPRINTFX
parameter_list|(
modifier|...
parameter_list|)
value|warnx(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|DPRINTFX
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBPROC_H_ */
end_comment

end_unit

