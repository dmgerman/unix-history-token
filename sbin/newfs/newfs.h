begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * variables set up by front end.  */
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
comment|/* format as an 4.3BSD file system */
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
name|fssize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ntracks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # tracks/cylinder */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nsectors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # sectors/track */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nphyssectors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # sectors/track including spares */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|secpercyl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sectors per cylinder */
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
name|rpm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* revolutions/minute of drive */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interleave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hardware sector interleave */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trackskew
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sector 0 skew, per track */
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
name|cpg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cylinders/cylinder group */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cpgflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cylinders/cylinder group flag was given */
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
name|rotdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rotational delay between blocks */
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
name|nrpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of distinguished rotational positions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bbsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boot block size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sbsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* superblock size */
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

end_unit

