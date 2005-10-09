begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Christos Zoulas 2003.  * All Rights Reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAGIC_H
end_ifndef

begin_define
define|#
directive|define
name|_MAGIC_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|MAGIC_NONE
value|0x000
end_define

begin_comment
comment|/* No flags */
end_comment

begin_define
define|#
directive|define
name|MAGIC_DEBUG
value|0x001
end_define

begin_comment
comment|/* Turn on debugging */
end_comment

begin_define
define|#
directive|define
name|MAGIC_SYMLINK
value|0x002
end_define

begin_comment
comment|/* Follow symlinks */
end_comment

begin_define
define|#
directive|define
name|MAGIC_COMPRESS
value|0x004
end_define

begin_comment
comment|/* Check inside compressed files */
end_comment

begin_define
define|#
directive|define
name|MAGIC_DEVICES
value|0x008
end_define

begin_comment
comment|/* Look at the contents of devices */
end_comment

begin_define
define|#
directive|define
name|MAGIC_MIME
value|0x010
end_define

begin_comment
comment|/* Return a mime string */
end_comment

begin_define
define|#
directive|define
name|MAGIC_CONTINUE
value|0x020
end_define

begin_comment
comment|/* Return all matches */
end_comment

begin_define
define|#
directive|define
name|MAGIC_CHECK
value|0x040
end_define

begin_comment
comment|/* Print warnings to stderr */
end_comment

begin_define
define|#
directive|define
name|MAGIC_PRESERVE_ATIME
value|0x080
end_define

begin_comment
comment|/* Restore access time on exit */
end_comment

begin_define
define|#
directive|define
name|MAGIC_RAW
value|0x100
end_define

begin_comment
comment|/* Don't translate unprintable chars */
end_comment

begin_define
define|#
directive|define
name|MAGIC_ERROR
value|0x200
end_define

begin_comment
comment|/* Handle ENOENT etc as real errors */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|struct
name|magic_set
modifier|*
name|magic_t
typedef|;
name|magic_t
name|magic_open
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
name|magic_close
parameter_list|(
name|magic_t
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|magic_file
parameter_list|(
name|magic_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|magic_buffer
parameter_list|(
name|magic_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|magic_error
parameter_list|(
name|magic_t
parameter_list|)
function_decl|;
name|int
name|magic_setflags
parameter_list|(
name|magic_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|magic_load
parameter_list|(
name|magic_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|magic_compile
parameter_list|(
name|magic_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|magic_check
parameter_list|(
name|magic_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|magic_errno
parameter_list|(
name|magic_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAGIC_H */
end_comment

end_unit

