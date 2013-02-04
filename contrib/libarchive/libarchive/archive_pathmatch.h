begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_TEST
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PATHMATCH_H
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PATHMATCH_H
end_define

begin_comment
comment|/* Don't anchor at beginning unless the pattern starts with "^" */
end_comment

begin_define
define|#
directive|define
name|PATHMATCH_NO_ANCHOR_START
value|1
end_define

begin_comment
comment|/* Don't anchor at end unless the pattern ends with "$" */
end_comment

begin_define
define|#
directive|define
name|PATHMATCH_NO_ANCHOR_END
value|2
end_define

begin_comment
comment|/* Note that "^" and "$" are not special unless you set the corresponding  * flag above. */
end_comment

begin_function_decl
name|int
name|__archive_pathmatch
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__archive_pathmatch_w
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|p
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|s
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_pathmatch
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|__archive_pathmatch(p, s, f)
end_define

begin_define
define|#
directive|define
name|archive_pathmatch_w
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|__archive_pathmatch_w(p, s, f)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

