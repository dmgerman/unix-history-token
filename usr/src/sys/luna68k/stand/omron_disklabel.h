begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)omron_disklabel.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/* omron_dislabel.h from UniOS-B */
end_comment

begin_comment
comment|/*    by A.Fujita, JAN-30-1992   */
end_comment

begin_define
define|#
directive|define
name|DKL_MAGIC
value|0xDABE
end_define

begin_comment
comment|/* Disk label Magic number */
end_comment

begin_define
define|#
directive|define
name|NLPART
value|8
end_define

begin_comment
comment|/* # of logical partition */
end_comment

begin_struct
struct|struct
name|scd_dk_label
block|{
name|char
name|dkl_asciilabel
index|[
literal|128
index|]
decl_stmt|;
comment|/* for compatibility */
name|char
name|dkl_pad
index|[
literal|512
operator|-
operator|(
literal|128
operator|+
literal|8
operator|*
literal|8
operator|+
literal|11
operator|*
literal|2
operator|+
literal|4
operator|)
index|]
decl_stmt|;
name|unsigned
name|short
name|dkl_badchk
decl_stmt|;
comment|/* checksum of bad track */
name|unsigned
name|long
name|dkl_maxblk
decl_stmt|;
comment|/* # of total logical block */
name|unsigned
name|short
name|dkl_dtype
decl_stmt|;
comment|/* disk drive type */
name|unsigned
name|short
name|dkl_ndisk
decl_stmt|;
comment|/* # of disk drives */
name|unsigned
name|short
name|dkl_ncyl
decl_stmt|;
comment|/* # of data cylinders */
name|unsigned
name|short
name|dkl_acyl
decl_stmt|;
comment|/* # of alternate cylinders */
name|unsigned
name|short
name|dkl_nhead
decl_stmt|;
comment|/* # of heads in this partition */
name|unsigned
name|short
name|dkl_nsect
decl_stmt|;
comment|/* # of 512 byte sectors per track */
name|unsigned
name|short
name|dkl_bhead
decl_stmt|;
comment|/* identifies proper label locations */
name|unsigned
name|short
name|dkl_ppart
decl_stmt|;
comment|/* physical partition # */
struct|struct
name|dk_map
block|{
comment|/* logical partitions */
name|daddr_t
name|dkl_blkno
decl_stmt|;
comment|/* starting block */
name|daddr_t
name|dkl_nblk
decl_stmt|;
comment|/* number of blocks */
block|}
name|dkl_map
index|[
name|NLPART
index|]
struct|;
name|unsigned
name|short
name|dkl_magic
decl_stmt|;
comment|/* identifies this label format */
name|unsigned
name|short
name|dkl_cksum
decl_stmt|;
comment|/* xor checksum of sector */
block|}
struct|;
end_struct

end_unit

