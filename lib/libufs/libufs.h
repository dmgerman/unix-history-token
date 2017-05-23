begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Juli Mallett.  All rights reserved.  *  * This software was written by Juli Mallett<jmallett@FreeBSD.org> for the  * FreeBSD project.  Redistribution and use in source and binary forms, with  * or without modification, are permitted provided that the following  * conditions are met:  *  * 1. Redistribution of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistribution in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBUFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIBUFS_H__
end_define

begin_comment
comment|/*  * libufs structures.  */
end_comment

begin_comment
comment|/*  * userland ufs disk.  */
end_comment

begin_struct
struct|struct
name|uufsd
block|{
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* disk name */
name|int
name|d_ufs
decl_stmt|;
comment|/* decimal UFS version */
name|int
name|d_fd
decl_stmt|;
comment|/* raw device file descriptor */
name|long
name|d_bsize
decl_stmt|;
comment|/* device bsize */
name|ufs2_daddr_t
name|d_sblock
decl_stmt|;
comment|/* superblock location */
name|struct
name|csum
modifier|*
name|d_sbcsum
decl_stmt|;
comment|/* Superblock summary info */
name|caddr_t
name|d_inoblock
decl_stmt|;
comment|/* inode block */
name|uint32_t
name|d_inomin
decl_stmt|;
comment|/* low inode (not ino_t for ABI compat) */
name|uint32_t
name|d_inomax
decl_stmt|;
comment|/* high inode (not ino_t for ABI compat) */
union|union
block|{
name|struct
name|fs
name|d_fs
decl_stmt|;
comment|/* filesystem information */
name|char
name|d_sb
index|[
name|MAXBSIZE
index|]
decl_stmt|;
comment|/* superblock as buffer */
block|}
name|d_sbunion
union|;
union|union
block|{
name|struct
name|cg
name|d_cg
decl_stmt|;
comment|/* cylinder group */
name|char
name|d_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
comment|/* cylinder group storage */
block|}
name|d_cgunion
union|;
name|int
name|d_ccg
decl_stmt|;
comment|/* current cylinder group */
name|int
name|d_lcg
decl_stmt|;
comment|/* last cylinder group (in d_cg) */
specifier|const
name|char
modifier|*
name|d_error
decl_stmt|;
comment|/* human readable disk error */
name|int
name|d_mine
decl_stmt|;
comment|/* internal flags */
define|#
directive|define
name|d_fs
value|d_sbunion.d_fs
define|#
directive|define
name|d_sb
value|d_sbunion.d_sb
define|#
directive|define
name|d_cg
value|d_cgunion.d_cg
block|}
struct|;
end_struct

begin_comment
comment|/*  * libufs macros (internal, non-exported).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBUFS
end_ifdef

begin_comment
comment|/*  * Trace steps through libufs, to be used at entry and erroneous return.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ERROR
parameter_list|(
name|struct
name|uufsd
modifier|*
name|u
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_LIBUFS_DEBUGGING
if|if
condition|(
name|str
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"libufs: %s"
argument_list|,
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|u
operator|!=
name|NULL
condition|)
name|u
operator|->
name|d_error
operator|=
name|str
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUFS */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * libufs prototypes.  */
comment|/*  * block.c  */
name|ssize_t
name|bread
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|ufs2_daddr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|bwrite
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|ufs2_daddr_t
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
name|int
name|berase
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|ufs2_daddr_t
parameter_list|,
name|ufs2_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cgroup.c  */
end_comment

begin_function_decl
name|ufs2_daddr_t
name|cgballoc
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgbfree
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|ufs2_daddr_t
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|cgialloc
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgread
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgread1
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgwrite
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgwrite1
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * inode.c  */
end_comment

begin_function_decl
name|int
name|getino
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putino
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * sblock.c  */
end_comment

begin_function_decl
name|int
name|sbread
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbwrite
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * type.c  */
end_comment

begin_function_decl
name|int
name|ufs_disk_close
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_disk_fillout
parameter_list|(
name|struct
name|uufsd
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
name|ufs_disk_fillout_blank
parameter_list|(
name|struct
name|uufsd
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
name|ufs_disk_write
parameter_list|(
name|struct
name|uufsd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ffs_subr.c  */
end_comment

begin_function_decl
name|void
name|ffs_clrblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs1_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_clusteracct
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|,
name|ufs1_daddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_fragacct
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int32_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffs_isblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs1_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffs_isfreeblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs1_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_setblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs1_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBUFS_H__ */
end_comment

end_unit

