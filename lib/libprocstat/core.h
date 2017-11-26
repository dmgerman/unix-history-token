begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2013 Mikolaj Golub<trociny@FreeBSD.org>  * Copyright (c) 2017 Dell EMC  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CORE_H
end_ifndef

begin_define
define|#
directive|define
name|_CORE_H
end_define

begin_enum
enum|enum
name|psc_type
block|{
name|PSC_TYPE_PROC
block|,
name|PSC_TYPE_FILES
block|,
name|PSC_TYPE_VMMAP
block|,
name|PSC_TYPE_GROUPS
block|,
name|PSC_TYPE_UMASK
block|,
name|PSC_TYPE_RLIMIT
block|,
name|PSC_TYPE_OSREL
block|,
name|PSC_TYPE_PSSTRINGS
block|,
name|PSC_TYPE_ARGV
block|,
name|PSC_TYPE_ENVV
block|,
name|PSC_TYPE_AUXV
block|,
name|PSC_TYPE_PTLWPINFO
block|,
name|PSC_TYPE_MAX
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|procstat_core
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|procstat_core_close
parameter_list|(
name|struct
name|procstat_core
modifier|*
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|procstat_core_get
parameter_list|(
name|struct
name|procstat_core
modifier|*
name|core
parameter_list|,
name|enum
name|psc_type
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procstat_core_note_count
parameter_list|(
name|struct
name|procstat_core
modifier|*
name|core
parameter_list|,
name|enum
name|psc_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|procstat_core
modifier|*
name|procstat_core_open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CORE_H_ */
end_comment

end_unit

