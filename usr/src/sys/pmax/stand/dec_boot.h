begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)dec_boot.h	7.3 (Berkeley) %G%  *  * devDiskLabel.h --  *  *      This defines the disk label that Sun writes on the 0'th sector of  *      the 0'th cylinder of its SMD disks.  The disk label contains some  *      geometry information and also the division of the disk into a  *      number of partitions.  Each partition is identified to the drive  *      by a different unit number.  *  * from: $Header: /sprite/src/kernel/dev/RCS/devDiskLabel.h,  *	v 9.4 90/03/01 12:22:36 jhh Exp $ SPRITE (Berkeley)  */
end_comment

begin_comment
comment|/*  * Boot block information on the 0th sector.  * The boot program is stored in sequences of contiguous blocks.  * If mode is 0, there is just one sequence of blocks and one Dec_BootMap  * is used.  If mode is 1, there are multiple sequences of blocks  * and multiple Dec_BootMaps are used, the last with numBlocks = 0.  *  * NOTE: The standard disk label offset is 64 which is  * after the boot information expected by the PROM boot loader.  */
end_comment

begin_struct
struct|struct
name|Dec_BootMap
block|{
name|int
name|numBlocks
decl_stmt|;
comment|/* Number of blocks to read. */
name|int
name|startBlock
decl_stmt|;
comment|/* Starting block on disk. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Dec_DiskBoot
block|{
name|char
name|pad
index|[
literal|8
index|]
decl_stmt|;
name|int
name|magic
decl_stmt|;
comment|/* DEC_BOOT_MAGIC */
name|int
name|mode
decl_stmt|;
comment|/* Mode for boot info. */
name|int
name|loadAddr
decl_stmt|;
comment|/* Address to start loading. */
name|int
name|execAddr
decl_stmt|;
comment|/* Address to start execing. */
name|struct
name|Dec_BootMap
name|map
index|[
literal|61
index|]
decl_stmt|;
comment|/* boot program sections. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEC_BOOT_MAGIC
value|0x0002757a
end_define

begin_define
define|#
directive|define
name|DEC_BOOT_SECTOR
value|0
end_define

begin_comment
comment|/*  * DEC_NUM_DISK_PARTS is the number of partitions that are recorded in  * the label information.  The size of the padding in the Dec_DiskLabel  * type is dependent on this number...  */
end_comment

begin_define
define|#
directive|define
name|DEC_NUM_DISK_PARTS
value|8
end_define

begin_comment
comment|/*  * A disk is divided into partitions and this type specifies where a  * partition starts and how many bytes it contains.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Dec_DiskMap
block|{
name|int
name|numBlocks
decl_stmt|;
comment|/* Number of 512 byte blocks in partition. */
name|int
name|startBlock
decl_stmt|;
comment|/* Start of partition in blocks. */
block|}
name|Dec_DiskMap
typedef|;
end_typedef

begin_comment
comment|/*  * Label information on the 31st (DEC_LABEL_SECTOR) sector.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Dec_DiskLabel
block|{
name|char
name|pad0
index|[
literal|440
index|]
decl_stmt|;
comment|/* DIFFERENT from sprite!!! */
name|int
name|magic
decl_stmt|;
comment|/* DEC_LABEL_MAGIC */
name|int
name|isPartitioned
decl_stmt|;
comment|/* 1 if disk is partitioned. */
name|Dec_DiskMap
name|map
index|[
name|DEC_NUM_DISK_PARTS
index|]
decl_stmt|;
comment|/* Indicates disk partitions. */
block|}
name|Dec_DiskLabel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEC_LABEL_MAGIC
value|0x00032957
end_define

begin_define
define|#
directive|define
name|DEC_LABEL_SECTOR
value|31
end_define

end_unit

