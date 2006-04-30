begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Marshall  * Kirk McKusick and Network Associates Laboratories, the Security  * Research Division of Network Associates, Inc. under DARPA/SPAWAR  * contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA CHATS  * research program.  *  * Copyright (c) 1980, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<libufs.h>
end_include

begin_comment
comment|/*  * variables set up by front end.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add a volume label */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* run mkfs without writing file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Oflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* build UFS1 format file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regression test */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Uflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable soft updates for file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit as if error, for testing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable multilabel MAC for file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do not create .snap directory */
end_comment

begin_decl_stmt
specifier|extern
name|quad_t
name|fssize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sectorsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bytes/sector */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|realsectorsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bytes/sector in hardware*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fragment size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxbsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum clustering */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxblkspercg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum blocks per cylinder group */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|minfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free space threshold */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|opt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optimization preference (space or time) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|density
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes per inode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxcontig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max contiguous blocks to allocate */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxbpg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum blocks per file in a cyl group */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|avgfilesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected average file size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|avgfilesperdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected number of files per directory */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|volumelabel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* volume label for filesystem */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|uufsd
name|disk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* libufs disk structure */
end_comment

begin_function_decl
name|void
name|mkfs
parameter_list|(
name|struct
name|partition
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

