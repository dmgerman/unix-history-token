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
comment|/*  * libufs macros (internal, non-exported).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBUFS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBUFS_DEBUGGING
end_ifdef

begin_comment
comment|/*  * Trace steps through libufs, to be used at entry and erroneous return.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 	fprintf(stderr, "libufs in %s", __func__);		\ 	if (str != NULL)					\ 		fprintf(stderr, ": %s", str);			\ 	if (errno)						\ 		fprintf(stderr, ": %s", strerror(errno));	\ 	fprintf(stderr, "\n");					\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _LIBUFS_DEBUGGING */
end_comment

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|str
parameter_list|)
end_define

begin_comment
comment|/* nil */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUFS_DEBUGGING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUFS */
end_comment

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
name|caddr_t
name|d_inoblock
decl_stmt|;
comment|/* inode block */
name|ino_t
name|d_inomin
decl_stmt|;
comment|/* low inode */
name|ino_t
name|d_inomax
decl_stmt|;
comment|/* high inode */
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
specifier|const
name|char
modifier|*
name|d_error
decl_stmt|;
comment|/* human readable disk error */
define|#
directive|define
name|d_fs
value|d_sbunion.d_fs
define|#
directive|define
name|d_sb
value|d_sbunion.d_sb
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * error.c  */
end_comment

begin_function_decl
name|void
name|libufs_printerror
parameter_list|(
name|struct
name|uufsd
modifier|*
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
name|struct
name|uufsd
modifier|*
name|ufs_disk_ctor
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|ufs_disk_dtor
parameter_list|(
name|struct
name|uufsd
modifier|*
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

