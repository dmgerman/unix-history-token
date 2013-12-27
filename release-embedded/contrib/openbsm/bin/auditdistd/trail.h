begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/auditdistd/trail.h#1 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUDITDISTD_TRAIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_AUDITDISTD_TRAIL_H_
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* off_t */
end_comment

begin_define
define|#
directive|define
name|TRAIL_IDENTICAL
value|0
end_define

begin_define
define|#
directive|define
name|TRAIL_RENAMED
value|1
end_define

begin_define
define|#
directive|define
name|TRAIL_OLDER
value|2
end_define

begin_define
define|#
directive|define
name|TRAIL_NEWER
value|3
end_define

begin_struct_decl
struct_decl|struct
name|trail
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|trail
modifier|*
name|trail_new
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|,
name|bool
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_free
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|trail_is_not_terminated
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|trail_is_crash_recovery
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_start
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|off_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_next
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_close
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_reset
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_unlink
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|trail_switch
parameter_list|(
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|trail_filename
parameter_list|(
specifier|const
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trail_filefd
parameter_list|(
specifier|const
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trail_dirfd
parameter_list|(
specifier|const
name|struct
name|trail
modifier|*
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trail_last
parameter_list|(
name|DIR
modifier|*
name|dirfp
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|,
name|size_t
name|filenamesize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|trail_validate_name
parameter_list|(
specifier|const
name|char
modifier|*
name|srcname
parameter_list|,
specifier|const
name|char
modifier|*
name|dstname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trail_name_compare
parameter_list|(
specifier|const
name|char
modifier|*
name|name0
parameter_list|,
specifier|const
name|char
modifier|*
name|name1
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AUDITDISTD_TRAIL_H_ */
end_comment

end_unit

