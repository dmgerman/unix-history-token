begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cdvar.h 1.1 90/07/09$  *  *	@(#)cdvar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|NCDISKS
value|8
end_define

begin_comment
comment|/* max # of component disks */
end_comment

begin_comment
comment|/*  * A concatenated disk is described at config time by this structure.  */
end_comment

begin_struct
struct|struct
name|cddevice
block|{
name|int
name|cd_unit
decl_stmt|;
comment|/* logical unit of this cd */
name|int
name|cd_interleave
decl_stmt|;
comment|/* interleave (DEV_BSIZE blocks) */
name|int
name|cd_flags
decl_stmt|;
comment|/* misc. information */
name|int
name|cd_dk
decl_stmt|;
comment|/* disk number */
name|dev_t
name|cd_dev
index|[
name|NCDISKS
index|]
decl_stmt|;
comment|/* component devices */
block|}
struct|;
end_struct

begin_comment
comment|/* cd_flags */
end_comment

begin_define
define|#
directive|define
name|CDF_SWAP
value|0x01
end_define

begin_comment
comment|/* interleave should be dmmax */
end_comment

begin_define
define|#
directive|define
name|CDF_UNIFORM
value|0x02
end_define

begin_comment
comment|/* use LCD of sizes for uniform interleave */
end_comment

begin_comment
comment|/*  * Component info table.  * Describes a single component of a concatenated disk.  */
end_comment

begin_struct
struct|struct
name|cdcinfo
block|{
name|dev_t
name|ci_dev
decl_stmt|;
comment|/* devno */
name|size_t
name|ci_size
decl_stmt|;
comment|/* size */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interleave description table.  * Computed at boot time to speed irregular-interleave lookups.  * The idea is that we interleave in "groups".  First we interleave  * evenly over all component disks up to the size of the smallest  * component (the first group), then we interleave evenly over all  * remaining disks up to the size of the next-smallest (second group),  * and so on.  *  * Each table entry describes the interleave characteristics of one  * of these groups.  For example if a concatenated disk consisted of  * three components of 5, 3, and 7 DEV_BSIZE blocks interleaved at  * DEV_BSIZE (1), the table would have three entries:  *  *	ndisk	startblk	startoff	dev  *	3	0		0		0, 1, 2  *	2	9		3		0, 2  *	1	13		5		2  *	0	-		-		-  *  * which says that the first nine blocks (0-8) are interleaved over  * 3 disks (0, 1, 2) starting at block offset 0 on any component disk,  * the next 4 blocks (9-12) are interleaved over 2 disks (0, 2) starting  * at component block 3, and the remaining blocks (13-14) are on disk  * 2 starting at offset 5.  */
end_comment

begin_struct
struct|struct
name|cdiinfo
block|{
name|int
name|ii_ndisk
decl_stmt|;
comment|/* # of disks range is interleaved over */
name|daddr_t
name|ii_startblk
decl_stmt|;
comment|/* starting scaled block # for range */
name|daddr_t
name|ii_startoff
decl_stmt|;
comment|/* starting component offset (block #) */
name|char
name|ii_index
index|[
name|NCDISKS
index|]
decl_stmt|;
comment|/* ordered list of components in range */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|cddevice
name|cddevice
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

