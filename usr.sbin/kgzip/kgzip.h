begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"kgz.h"
end_include

begin_define
define|#
directive|define
name|F_AOUT
value|1
end_define

begin_comment
comment|/* Format: a.out */
end_comment

begin_define
define|#
directive|define
name|F_ELF
value|2
end_define

begin_comment
comment|/* Format: ELF32 */
end_comment

begin_comment
comment|/* Used by I/O routines */
end_comment

begin_struct
struct|struct
name|iodesc
block|{
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* File name */
name|int
name|fd
decl_stmt|;
comment|/* File descriptor */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|loader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default loader */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output format */
end_comment

begin_function_decl
name|void
name|kgzcmp
parameter_list|(
name|struct
name|kgz_hdr
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kgzld
parameter_list|(
name|struct
name|kgz_hdr
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xclose
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xcopy
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xzero
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|xread
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xwrite
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xseek
parameter_list|(
specifier|const
name|struct
name|iodesc
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

