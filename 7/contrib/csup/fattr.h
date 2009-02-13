begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FATTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_FATTR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/*  * File types.  */
end_comment

begin_define
define|#
directive|define
name|FT_UNKNOWN
value|0
end_define

begin_comment
comment|/* Unknown file type. */
end_comment

begin_define
define|#
directive|define
name|FT_FILE
value|1
end_define

begin_comment
comment|/* Regular file. */
end_comment

begin_define
define|#
directive|define
name|FT_DIRECTORY
value|2
end_define

begin_comment
comment|/* Directory. */
end_comment

begin_define
define|#
directive|define
name|FT_CDEV
value|3
end_define

begin_comment
comment|/* Character device. */
end_comment

begin_define
define|#
directive|define
name|FT_BDEV
value|4
end_define

begin_comment
comment|/* Block device. */
end_comment

begin_define
define|#
directive|define
name|FT_SYMLINK
value|5
end_define

begin_comment
comment|/* Symbolic link. */
end_comment

begin_define
define|#
directive|define
name|FT_MAX
value|FT_SYMLINK
end_define

begin_comment
comment|/* Maximum file type number. */
end_comment

begin_define
define|#
directive|define
name|FT_NUMBER
value|(FT_MAX + 1)
end_define

begin_comment
comment|/* Number of file types. */
end_comment

begin_comment
comment|/*  * File attributes.  */
end_comment

begin_define
define|#
directive|define
name|FA_FILETYPE
value|0x0001
end_define

begin_comment
comment|/* True for all supported file types. */
end_comment

begin_define
define|#
directive|define
name|FA_MODTIME
value|0x0002
end_define

begin_comment
comment|/* Last file modification time. */
end_comment

begin_define
define|#
directive|define
name|FA_SIZE
value|0x0004
end_define

begin_comment
comment|/* Size of the file. */
end_comment

begin_define
define|#
directive|define
name|FA_LINKTARGET
value|0x0008
end_define

begin_comment
comment|/* Target of a symbolic link. */
end_comment

begin_define
define|#
directive|define
name|FA_RDEV
value|0x0010
end_define

begin_comment
comment|/* Device for a device node. */
end_comment

begin_define
define|#
directive|define
name|FA_OWNER
value|0x0020
end_define

begin_comment
comment|/* Owner of the file. */
end_comment

begin_define
define|#
directive|define
name|FA_GROUP
value|0x0040
end_define

begin_comment
comment|/* Group of the file. */
end_comment

begin_define
define|#
directive|define
name|FA_MODE
value|0x0080
end_define

begin_comment
comment|/* File permissions. */
end_comment

begin_define
define|#
directive|define
name|FA_FLAGS
value|0x0100
end_define

begin_comment
comment|/* 4.4BSD flags, a la chflags(2). */
end_comment

begin_define
define|#
directive|define
name|FA_LINKCOUNT
value|0x0200
end_define

begin_comment
comment|/* Hard link count. */
end_comment

begin_define
define|#
directive|define
name|FA_DEV
value|0x0400
end_define

begin_comment
comment|/* Device holding the inode. */
end_comment

begin_define
define|#
directive|define
name|FA_INODE
value|0x0800
end_define

begin_comment
comment|/* Inode number. */
end_comment

begin_define
define|#
directive|define
name|FA_MASK
value|0x0fff
end_define

begin_define
define|#
directive|define
name|FA_NUMBER
value|12
end_define

begin_comment
comment|/* Number of file attributes. */
end_comment

begin_comment
comment|/* Attributes that we might be able to change. */
end_comment

begin_define
define|#
directive|define
name|FA_CHANGEABLE
value|(FA_MODTIME | FA_OWNER | FA_GROUP | FA_MODE | FA_FLAGS)
end_define

begin_comment
comment|/*  * Attributes that we don't want to save in the "checkouts" file  * when in checkout mode.  */
end_comment

begin_define
define|#
directive|define
name|FA_COIGNORE
value|(FA_MASK& ~(FA_FILETYPE|FA_MODTIME|FA_SIZE|FA_MODE))
end_define

begin_comment
comment|/* These are for fattr_frompath(). */
end_comment

begin_define
define|#
directive|define
name|FATTR_FOLLOW
value|0
end_define

begin_define
define|#
directive|define
name|FATTR_NOFOLLOW
value|1
end_define

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fattr
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|fattr_support_t
index|[
name|FT_NUMBER
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|fattr
modifier|*
name|fattr_bogus
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fattr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_new
parameter_list|(
name|int
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_default
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_fromstat
parameter_list|(
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_frompath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_fromfd
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_decode
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_forcheckout
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fattr
modifier|*
name|fattr_dup
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fattr_encode
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|,
name|fattr_support_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_type
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_maskout
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_getmask
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nlink_t
name|fattr_getlinkcount
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_umask
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_merge
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|,
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_mergedefault
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_override
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|,
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_makenode
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_delete
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_install
parameter_list|(
name|struct
name|fattr
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
name|int
name|fattr_equal
parameter_list|(
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|,
specifier|const
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattr_free
parameter_list|(
name|struct
name|fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fattr_supported
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FATTR_H_ */
end_comment

end_unit

