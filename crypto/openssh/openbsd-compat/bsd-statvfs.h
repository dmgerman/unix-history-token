begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-statvfs.h,v 1.3 2014/01/17 07:48:22 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008,2014 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STATVFS
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_FSTATVFS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STATFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/statfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSBLKCNT_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|fsblkcnt_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSFILCNT_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|fsfilcnt_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ST_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|ST_RDONLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ST_NOSUID
end_ifndef

begin_define
define|#
directive|define
name|ST_NOSUID
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* as defined in IEEE Std 1003.1, 2004 Edition */
end_comment

begin_struct
struct|struct
name|statvfs
block|{
name|unsigned
name|long
name|f_bsize
decl_stmt|;
comment|/* File system block size. */
name|unsigned
name|long
name|f_frsize
decl_stmt|;
comment|/* Fundamental file system block size. */
name|fsblkcnt_t
name|f_blocks
decl_stmt|;
comment|/* Total number of blocks on file system in */
comment|/* units of f_frsize. */
name|fsblkcnt_t
name|f_bfree
decl_stmt|;
comment|/* Total number of free blocks. */
name|fsblkcnt_t
name|f_bavail
decl_stmt|;
comment|/* Number of free blocks available to  */
comment|/* non-privileged process.  */
name|fsfilcnt_t
name|f_files
decl_stmt|;
comment|/* Total number of file serial numbers. */
name|fsfilcnt_t
name|f_ffree
decl_stmt|;
comment|/* Total number of free file serial numbers. */
name|fsfilcnt_t
name|f_favail
decl_stmt|;
comment|/* Number of file serial numbers available to */
comment|/* non-privileged process. */
name|unsigned
name|long
name|f_fsid
decl_stmt|;
comment|/* File system ID. */
name|unsigned
name|long
name|f_flag
decl_stmt|;
comment|/* BBit mask of f_flag values. */
name|unsigned
name|long
name|f_namemax
decl_stmt|;
comment|/*  Maximum filename length. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STATVFS
end_ifndef

begin_function_decl
name|int
name|statvfs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|statvfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSTATVFS
end_ifndef

begin_function_decl
name|int
name|fstatvfs
parameter_list|(
name|int
parameter_list|,
name|struct
name|statvfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

