begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sftp-common.h,v 1.3 2001/06/26 17:27:24 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  * Copyright (c) 2001 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Attrib
name|Attrib
typedef|;
end_typedef

begin_comment
comment|/* File attributes */
end_comment

begin_struct
struct|struct
name|Attrib
block|{
name|u_int32_t
name|flags
decl_stmt|;
name|u_int64_t
name|size
decl_stmt|;
name|u_int32_t
name|uid
decl_stmt|;
name|u_int32_t
name|gid
decl_stmt|;
name|u_int32_t
name|perm
decl_stmt|;
name|u_int32_t
name|atime
decl_stmt|;
name|u_int32_t
name|mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|attrib_clear
parameter_list|(
name|Attrib
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_to_attrib
parameter_list|(
name|struct
name|stat
modifier|*
parameter_list|,
name|Attrib
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Attrib
modifier|*
name|decode_attrib
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|encode_attrib
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|Attrib
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|fx2txt
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

