begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)dec_boot.h	7.1 (Berkeley) %G%  *  * devDiskLabel.h --  *  *      This defines the disk label that Sun writes on the 0'th sector of  *      the 0'th cylinder of its SMD disks.  The disk label contains some  *      geometry information and also the division of the disk into a  *      number of partitions.  Each partition is identified to the drive  *      by a different unit number.  *  * from: $Header: /sprite/src/kernel/dev/RCS/devDiskLabel.h,  *	v 9.4 90/03/01 12:22:36 jhh Exp $ SPRITE (Berkeley)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVDISKLABEL
end_ifndef

begin_define
define|#
directive|define
name|_DEVDISKLABEL
end_define

begin_comment
comment|/*  * SUN_NUM_DISK_PARTS is the number of partitions that are recorded in  * the label information.  The size of the padding in the Sun_DiskLabel  * type is dependend on this number...  */
end_comment

begin_define
define|#
directive|define
name|SUN_NUM_DISK_PARTS
value|8
end_define

begin_comment
comment|/*  * A disk is divided into partitions and this type specifies where a  * partition starts and how many blocks (sectors) it contains.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Sun_DiskMap
block|{
name|int
name|cylinder
decl_stmt|;
name|int
name|numBlocks
decl_stmt|;
block|}
name|Sun_DiskMap
typedef|;
end_typedef

begin_comment
comment|/*  * Label information on the zero'th sector.  The partition map and the  * number of heads, sectors, and cylinders are used by the disk driver to  * map from a block number in a disk partion to a block number on the raw  * disk.  The gap and interleaving information are used by the block  * allocation routines.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Sun_DiskLabel
block|{
name|char
name|asciiLabel
index|[
literal|128
index|]
decl_stmt|;
comment|/* For compatibility with other systems 					 * that write an ascii label on a disk*/
name|char
name|pad
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
operator|)
index|]
decl_stmt|;
comment|/* The sector size is 512 bytes, and 					 * padding puts our label info at the 					 * end of the sector. */
name|unsigned
name|short
name|gap1
decl_stmt|;
comment|/* size of gap 1 */
name|unsigned
name|short
name|gap2
decl_stmt|;
comment|/* size of gap 2 */
name|unsigned
name|short
name|interleave
decl_stmt|;
comment|/* interleave factor */
name|unsigned
name|short
name|numCylinders
decl_stmt|;
comment|/* # of data cylinders */
name|unsigned
name|short
name|numAltCylinders
decl_stmt|;
comment|/* # of alternate cylinders */
name|unsigned
name|short
name|numHeads
decl_stmt|;
comment|/* # of heads in this partition */
name|unsigned
name|short
name|numSectors
decl_stmt|;
comment|/* # of 512 byte sectors per track */
name|unsigned
name|short
name|bhead
decl_stmt|;
comment|/* ?? Head number under which this 					 * label is found, consistency chk */
name|unsigned
name|short
name|partitionID
decl_stmt|;
comment|/* physical partition # */
name|Sun_DiskMap
name|map
index|[
name|SUN_NUM_DISK_PARTS
index|]
decl_stmt|;
comment|/* Indicates the size and starting 					 * cylinder of the disk partitions */
name|unsigned
name|short
name|magic
decl_stmt|;
comment|/* Identifies this label format */
name|unsigned
name|short
name|checkSum
decl_stmt|;
comment|/* XOR checksum of sector */
block|}
name|Sun_DiskLabel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SUN_DISK_MAGIC
value|0xDABE
end_define

begin_comment
comment|/*  * The sun label does not describe the location of the filesystem header  * information that comes after the zero'th label sector.  (The sprite label  * will, but is never used.)  Instead, the following constants are used.  * SUN_SUMMARY_SECTOR  one sector of summary info  * SUN_DOMAIN_SECTOR  the first sector of the static domain header  */
end_comment

begin_define
define|#
directive|define
name|SUN_SUMMARY_SECTOR
value|17
end_define

begin_define
define|#
directive|define
name|SUN_DOMAIN_SECTOR
value|18
end_define

begin_comment
comment|/*   * SUN_LABEL_SECTOR -- sector holding the disk label  * SUN_BOOT_SECTOR -- first sector of the boot program  */
end_comment

begin_define
define|#
directive|define
name|SUN_LABEL_SECTOR
value|0
end_define

begin_define
define|#
directive|define
name|SUN_BOOT_SECTOR
value|1
end_define

begin_comment
comment|/*  * DEC_NUM_DISK_PARTS is the number of partitions that are recorded in  * the label information.  The size of the padding in the Dec_DiskLabel  * type is dependend on this number...  */
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

begin_typedef
typedef|typedef
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
name|Dec_BootMap
typedef|;
end_typedef

begin_comment
comment|/*  * Label information on the 31st (DEC_LABEL_SECTOR)  sector.  */
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

begin_comment
comment|/*  * Boot block information on the 0th sector.  * The boot program is stored in sequences of contiguous blocks.  * If mode is 0, there is just one sequence of blocks and one Dec_BootMap  * is used.  If mode is 1, there are multiple sequences of blocks  * and multiple Dec_BootMaps are used, the last with numBlocks = 0.  */
end_comment

begin_typedef
typedef|typedef
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
name|Dec_BootMap
name|map
index|[
literal|61
index|]
decl_stmt|;
comment|/* Position of boot program. */
block|}
name|Dec_DiskBoot
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEC_BOOT_MAGIC
value|0x02757a
end_define

begin_define
define|#
directive|define
name|DEC_LABEL_MAGIC
value|0x032957
end_define

begin_comment
comment|/*  * The following default values are used:  * DEC_BOOT_SECTOR	The sector holding the boot information.  * DEC_SUMMARY_SECTOR  one sector of summary info  * DEC_DOMAIN_SECTOR  the first sector of the static domain header  * DEC_LABEL_SECTOR	The sector holding the disk label.  */
end_comment

begin_define
define|#
directive|define
name|DEC_BOOT_SECTOR
value|0
end_define

begin_define
define|#
directive|define
name|DEC_SUMMARY_SECTOR
value|17
end_define

begin_define
define|#
directive|define
name|DEC_DOMAIN_SECTOR
value|18
end_define

begin_define
define|#
directive|define
name|DEC_LABEL_SECTOR
value|31
end_define

begin_comment
comment|/*  * There are generally 8 disk partitions defined for a disk.  */
end_comment

begin_define
define|#
directive|define
name|DEV_NUM_DISK_PARTS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEVDISKLABEL */
end_comment

end_unit

