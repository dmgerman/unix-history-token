begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Martin Matuska  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
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

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ACL_MAPS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ACL_MAPS_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|"archive_platform_acl.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|int
name|a_perm
decl_stmt|;
comment|/* Libarchive permission or flag */
specifier|const
name|int
name|p_perm
decl_stmt|;
comment|/* Platform permission or flag */
block|}
name|acl_perm_map_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|ARCHIVE_ACL_POSIX1E
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|acl_perm_map_t
name|acl_posix_perm_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|acl_posix_perm_map_size
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARCHIVE_ACL_NFS4
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|acl_perm_map_t
name|acl_nfs4_perm_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|acl_nfs4_perm_map_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|acl_perm_map_t
name|acl_nfs4_flag_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|acl_nfs4_flag_map_size
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCHIVE_ACL_MAPS_H_INCLUDED */
end_comment

end_unit

