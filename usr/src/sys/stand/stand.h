begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stand.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stand/saioctl.h>
end_include

begin_define
define|#
directive|define
name|UNIX
value|"/vmunix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|open_file
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure is used to define file system operations in a file system  * independent way.  */
end_comment

begin_struct
struct|struct
name|fs_ops
block|{
name|int
argument_list|(
argument|*open
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
expr|struct
name|open_file
operator|*
name|f
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*read
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
name|char
operator|*
name|buf
operator|,
name|u_int
name|size
operator|,
name|u_int
operator|*
name|resid
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
name|char
operator|*
name|buf
operator|,
name|u_int
name|size
operator|,
name|u_int
operator|*
name|resid
operator|)
argument_list|)
expr_stmt|;
name|off_t
argument_list|(
argument|*seek
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
name|off_t
name|offset
operator|,
name|int
name|where
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*stat
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
expr|struct
name|stat
operator|*
name|sb
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|file_system
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where values for lseek(2) */
end_comment

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_comment
comment|/* Device switch */
end_comment

begin_struct
struct|struct
name|devsw
block|{
name|char
modifier|*
name|dv_name
decl_stmt|;
name|int
argument_list|(
argument|*dv_strategy
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|devdata
operator|,
name|int
name|rw
operator|,
name|daddr_t
name|blk
operator|,
name|u_int
name|size
operator|,
name|char
operator|*
name|buf
operator|,
name|u_int
operator|*
name|rsize
operator|)
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|*
name|dv_open
function_decl|)
parameter_list|()
function_decl|;
comment|/* (struct open_file *f, ...) */
name|int
argument_list|(
argument|*dv_close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dv_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
name|int
name|cmd
operator|,
name|void
operator|*
name|data
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|devsw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ndevs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of elements in devsw[] */
end_comment

begin_struct
struct|struct
name|open_file
block|{
name|int
name|f_flags
decl_stmt|;
comment|/* see F_* below */
name|struct
name|devsw
modifier|*
name|f_dev
decl_stmt|;
comment|/* pointer to device operations */
name|void
modifier|*
name|f_devdata
decl_stmt|;
comment|/* device specific data */
name|struct
name|fs_ops
modifier|*
name|f_ops
decl_stmt|;
comment|/* pointer to file system operations */
name|void
modifier|*
name|f_fsdata
decl_stmt|;
comment|/* file system specific data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SOPEN_MAX
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|open_file
name|files
index|[
name|SOPEN_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* f_flags values */
end_comment

begin_define
define|#
directive|define
name|F_READ
value|0x0001
end_define

begin_comment
comment|/* file opened for reading */
end_comment

begin_define
define|#
directive|define
name|F_WRITE
value|0x0002
end_define

begin_comment
comment|/* file opened for writing */
end_comment

begin_define
define|#
directive|define
name|F_RAW
value|0x0004
end_define

begin_comment
comment|/* raw device open - no file system */
end_comment

begin_decl_stmt
name|int
name|devopen
name|__P
argument_list|(
operator|(
expr|struct
name|open_file
operator|*
name|f
operator|,
name|char
operator|*
name|fname
operator|,
name|char
operator|*
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|alloc
name|__P
argument_list|(
operator|(
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free
name|__P
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|,
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|disklabel
struct_decl|;
end_struct_decl

begin_decl_stmt
name|char
modifier|*
name|getdisklabel
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|buf
operator|,
expr|struct
name|disklabel
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

