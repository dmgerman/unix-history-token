begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disktab.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DISKTAB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DISKTAB_H_
end_define

begin_comment
comment|/*  * Disk description table, see disktab(5)  */
end_comment

begin_define
define|#
directive|define
name|DISKTAB
value|"/etc/disktab"
end_define

begin_struct
struct|struct
name|disktab
block|{
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* drive name */
name|char
modifier|*
name|d_type
decl_stmt|;
comment|/* drive type */
name|int
name|d_secsize
decl_stmt|;
comment|/* sector size in bytes */
name|int
name|d_ntracks
decl_stmt|;
comment|/* # tracks/cylinder */
name|int
name|d_nsectors
decl_stmt|;
comment|/* # sectors/track */
name|int
name|d_ncylinders
decl_stmt|;
comment|/* # cylinders */
name|int
name|d_rpm
decl_stmt|;
comment|/* revolutions/minute */
name|int
name|d_badsectforw
decl_stmt|;
comment|/* supports DEC bad144 std */
name|int
name|d_sectoffset
decl_stmt|;
comment|/* use sect rather than cyl offsets */
struct|struct
name|partition
block|{
name|int
name|p_size
decl_stmt|;
comment|/* #sectors in partition */
name|short
name|p_bsize
decl_stmt|;
comment|/* block size in bytes */
name|short
name|p_fsize
decl_stmt|;
comment|/* frag size in bytes */
block|}
name|d_partitions
index|[
literal|8
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DISKTAB_H_ */
end_comment

end_unit

