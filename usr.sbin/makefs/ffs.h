begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ffs.h,v 1.2 2004/12/20 20:51:42 jmc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001-2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Luke Mewburn for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FFS_H
end_ifndef

begin_define
define|#
directive|define
name|_FFS_H
end_define

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|label
index|[
name|MAXVOLLEN
index|]
decl_stmt|;
comment|/* volume name/label */
name|int
name|bsize
decl_stmt|;
comment|/* block size */
name|int
name|fsize
decl_stmt|;
comment|/* fragment size */
name|int
name|cpg
decl_stmt|;
comment|/* cylinders per group */
name|int
name|cpgflg
decl_stmt|;
comment|/* cpg was specified by user */
name|int
name|density
decl_stmt|;
comment|/* bytes per inode */
name|int
name|ntracks
decl_stmt|;
comment|/* number of tracks */
name|int
name|nsectors
decl_stmt|;
comment|/* number of sectors */
name|int
name|rpm
decl_stmt|;
comment|/* rpm */
name|int
name|minfree
decl_stmt|;
comment|/* free space threshold */
name|int
name|optimization
decl_stmt|;
comment|/* optimization (space or time) */
name|int
name|maxcontig
decl_stmt|;
comment|/* max contiguous blocks to allocate */
name|int
name|rotdelay
decl_stmt|;
comment|/* rotational delay between blocks */
name|int
name|maxbpg
decl_stmt|;
comment|/* maximum blocks per file in a cyl group */
name|int
name|nrpos
decl_stmt|;
comment|/* # of distinguished rotational positions */
name|int
name|avgfilesize
decl_stmt|;
comment|/* expected average file size */
name|int
name|avgfpdir
decl_stmt|;
comment|/* expected # of files per directory */
name|int
name|version
decl_stmt|;
comment|/* filesystem version (1 = FFS, 2 = UFS2) */
name|int
name|maxbsize
decl_stmt|;
comment|/* maximum extent size */
name|int
name|maxblkspercg
decl_stmt|;
comment|/* max # of blocks per cylinder group */
name|int
name|softupdates
decl_stmt|;
comment|/* soft updates */
comment|/* XXX: support `old' file systems ? */
block|}
name|ffs_opt_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFS_H */
end_comment

end_unit

