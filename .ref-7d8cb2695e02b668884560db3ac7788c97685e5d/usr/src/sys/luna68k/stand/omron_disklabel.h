begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)omron_disklabel.h	7.1 (Berkeley) %G%  */
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

