begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISK_BSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISK_BSD_H_
end_define

begin_comment
comment|/* The disk magic number */
end_comment

begin_define
define|#
directive|define
name|BSD_MAGIC
value|0x82564557U
end_define

begin_define
define|#
directive|define
name|BSD_NPARTS_MIN
value|8
end_define

begin_define
define|#
directive|define
name|BSD_NPARTS_MAX
value|20
end_define

begin_comment
comment|/* Size of bootblock area in sector-size neutral bytes */
end_comment

begin_define
define|#
directive|define
name|BSD_BOOTBLOCK_SIZE
value|8192
end_define

begin_comment
comment|/* partition containing whole disk */
end_comment

begin_define
define|#
directive|define
name|BSD_PART_RAW
value|2
end_define

begin_comment
comment|/* partition normally containing swap */
end_comment

begin_define
define|#
directive|define
name|BSD_PART_SWAP
value|1
end_define

begin_comment
comment|/* Drive-type specific data size (in number of 32-bit inegrals) */
end_comment

begin_define
define|#
directive|define
name|BSD_NDRIVEDATA
value|5
end_define

begin_comment
comment|/* Number of spare 32-bit integrals following drive-type data */
end_comment

begin_define
define|#
directive|define
name|BSD_NSPARE
value|5
end_define

begin_struct
struct|struct
name|disklabel
block|{
name|uint32_t
name|d_magic
decl_stmt|;
comment|/* the magic number */
name|uint16_t
name|d_type
decl_stmt|;
comment|/* drive type */
name|uint16_t
name|d_subtype
decl_stmt|;
comment|/* controller/d_type specific */
name|char
name|d_typename
index|[
literal|16
index|]
decl_stmt|;
comment|/* type name, e.g. "eagle" */
name|char
name|d_packname
index|[
literal|16
index|]
decl_stmt|;
comment|/* pack identifier */
comment|/* disk geometry: */
name|uint32_t
name|d_secsize
decl_stmt|;
comment|/* # of bytes per sector */
name|uint32_t
name|d_nsectors
decl_stmt|;
comment|/* # of data sectors per track */
name|uint32_t
name|d_ntracks
decl_stmt|;
comment|/* # of tracks per cylinder */
name|uint32_t
name|d_ncylinders
decl_stmt|;
comment|/* # of data cylinders per unit */
name|uint32_t
name|d_secpercyl
decl_stmt|;
comment|/* # of data sectors per cylinder */
name|uint32_t
name|d_secperunit
decl_stmt|;
comment|/* # of data sectors per unit */
comment|/* 	 * Spares (bad sector replacements) below are not counted in 	 * d_nsectors or d_secpercyl.  Spare sectors are assumed to 	 * be physical sectors which occupy space at the end of each 	 * track and/or cylinder. 	 */
name|uint16_t
name|d_sparespertrack
decl_stmt|;
comment|/* # of spare sectors per track */
name|uint16_t
name|d_sparespercyl
decl_stmt|;
comment|/* # of spare sectors per cylinder */
comment|/* 	 * Alternate cylinders include maintenance, replacement, configuration 	 * description areas, etc. 	 */
name|uint32_t
name|d_acylinders
decl_stmt|;
comment|/* # of alt. cylinders per unit */
comment|/* hardware characteristics: */
comment|/* 	 * d_interleave, d_trackskew and d_cylskew describe perturbations 	 * in the media format used to compensate for a slow controller. 	 * Interleave is physical sector interleave, set up by the 	 * formatter or controller when formatting.  When interleaving is 	 * in use, logically adjacent sectors are not physically 	 * contiguous, but instead are separated by some number of 	 * sectors.  It is specified as the ratio of physical sectors 	 * traversed per logical sector.  Thus an interleave of 1:1 	 * implies contiguous layout, while 2:1 implies that logical 	 * sector 0 is separated by one sector from logical sector 1. 	 * d_trackskew is the offset of sector 0 on track N relative to 	 * sector 0 on track N-1 on the same cylinder.  Finally, d_cylskew 	 * is the offset of sector 0 on cylinder N relative to sector 0 	 * on cylinder N-1. 	 */
name|uint16_t
name|d_rpm
decl_stmt|;
comment|/* rotational speed */
name|uint16_t
name|d_interleave
decl_stmt|;
comment|/* hardware sector interleave */
name|uint16_t
name|d_trackskew
decl_stmt|;
comment|/* sector 0 skew, per track */
name|uint16_t
name|d_cylskew
decl_stmt|;
comment|/* sector 0 skew, per cylinder */
name|uint32_t
name|d_headswitch
decl_stmt|;
comment|/* head switch time, usec */
name|uint32_t
name|d_trkseek
decl_stmt|;
comment|/* track-to-track seek, usec */
name|uint32_t
name|d_flags
decl_stmt|;
comment|/* generic flags */
name|uint32_t
name|d_drivedata
index|[
name|BSD_NDRIVEDATA
index|]
decl_stmt|;
comment|/* drive-type specific data */
name|uint32_t
name|d_spare
index|[
name|BSD_NSPARE
index|]
decl_stmt|;
comment|/* reserved for future use */
name|uint32_t
name|d_magic2
decl_stmt|;
comment|/* the magic number (again) */
name|uint16_t
name|d_checksum
decl_stmt|;
comment|/* xor of data incl. partitions */
comment|/* filesystem and partition information: */
name|uint16_t
name|d_npartitions
decl_stmt|;
comment|/* number of partitions in following */
name|uint32_t
name|d_bbsize
decl_stmt|;
comment|/* size of boot area at sn0, bytes */
name|uint32_t
name|d_sbsize
decl_stmt|;
comment|/* max size of fs superblock, bytes */
struct|struct
name|partition
block|{
comment|/* the partition table */
name|uint32_t
name|p_size
decl_stmt|;
comment|/* number of sectors in partition */
name|uint32_t
name|p_offset
decl_stmt|;
comment|/* starting sector */
name|uint32_t
name|p_fsize
decl_stmt|;
comment|/* filesystem basic fragment size */
name|uint8_t
name|p_fstype
decl_stmt|;
comment|/* filesystem type, see below */
name|uint8_t
name|p_frag
decl_stmt|;
comment|/* filesystem fragments per block */
name|uint16_t
name|p_cpg
decl_stmt|;
comment|/* filesystem cylinders per group */
block|}
name|d_partitions
index|[
name|BSD_NPARTS_MIN
index|]
struct|;
comment|/* actually may be more */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|disklabel
argument_list|)
operator|==
literal|148
operator|+
name|BSD_NPARTS_MIN
operator|*
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* d_type values: */
end_comment

begin_define
define|#
directive|define
name|DTYPE_SMD
value|1
end_define

begin_comment
comment|/* SMD, XSMD; VAX hp/up */
end_comment

begin_define
define|#
directive|define
name|DTYPE_MSCP
value|2
end_define

begin_comment
comment|/* MSCP */
end_comment

begin_define
define|#
directive|define
name|DTYPE_DEC
value|3
end_define

begin_comment
comment|/* other DEC (rk, rl) */
end_comment

begin_define
define|#
directive|define
name|DTYPE_SCSI
value|4
end_define

begin_comment
comment|/* SCSI */
end_comment

begin_define
define|#
directive|define
name|DTYPE_ESDI
value|5
end_define

begin_comment
comment|/* ESDI interface */
end_comment

begin_define
define|#
directive|define
name|DTYPE_ST506
value|6
end_define

begin_comment
comment|/* ST506 etc. */
end_comment

begin_define
define|#
directive|define
name|DTYPE_HPIB
value|7
end_define

begin_comment
comment|/* CS/80 on HP-IB */
end_comment

begin_define
define|#
directive|define
name|DTYPE_HPFL
value|8
end_define

begin_comment
comment|/* HP Fiber-link */
end_comment

begin_define
define|#
directive|define
name|DTYPE_FLOPPY
value|10
end_define

begin_comment
comment|/* floppy */
end_comment

begin_define
define|#
directive|define
name|DTYPE_CCD
value|11
end_define

begin_comment
comment|/* concatenated disk */
end_comment

begin_define
define|#
directive|define
name|DTYPE_VINUM
value|12
end_define

begin_comment
comment|/* vinum volume */
end_comment

begin_define
define|#
directive|define
name|DTYPE_DOC2K
value|13
end_define

begin_comment
comment|/* Msys DiskOnChip */
end_comment

begin_define
define|#
directive|define
name|DTYPE_RAID
value|14
end_define

begin_comment
comment|/* CMU RAIDFrame */
end_comment

begin_define
define|#
directive|define
name|DTYPE_JFS2
value|16
end_define

begin_comment
comment|/* IBM JFS 2 */
end_comment

begin_comment
comment|/*  * Filesystem type and version.  * Used to interpret other filesystem-specific  * per-partition information.  */
end_comment

begin_define
define|#
directive|define
name|FS_UNUSED
value|0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|FS_SWAP
value|1
end_define

begin_comment
comment|/* swap */
end_comment

begin_define
define|#
directive|define
name|FS_V6
value|2
end_define

begin_comment
comment|/* Sixth Edition */
end_comment

begin_define
define|#
directive|define
name|FS_V7
value|3
end_define

begin_comment
comment|/* Seventh Edition */
end_comment

begin_define
define|#
directive|define
name|FS_SYSV
value|4
end_define

begin_comment
comment|/* System V */
end_comment

begin_define
define|#
directive|define
name|FS_V71K
value|5
end_define

begin_comment
comment|/* V7 with 1K blocks (4.1, 2.9) */
end_comment

begin_define
define|#
directive|define
name|FS_V8
value|6
end_define

begin_comment
comment|/* Eighth Edition, 4K blocks */
end_comment

begin_define
define|#
directive|define
name|FS_BSDFFS
value|7
end_define

begin_comment
comment|/* 4.2BSD fast filesystem */
end_comment

begin_define
define|#
directive|define
name|FS_MSDOS
value|8
end_define

begin_comment
comment|/* MSDOS filesystem */
end_comment

begin_define
define|#
directive|define
name|FS_BSDLFS
value|9
end_define

begin_comment
comment|/* 4.4BSD log-structured filesystem */
end_comment

begin_define
define|#
directive|define
name|FS_OTHER
value|10
end_define

begin_comment
comment|/* in use, but unknown/unsupported */
end_comment

begin_define
define|#
directive|define
name|FS_HPFS
value|11
end_define

begin_comment
comment|/* OS/2 high-performance filesystem */
end_comment

begin_define
define|#
directive|define
name|FS_ISO9660
value|12
end_define

begin_comment
comment|/* ISO 9660, normally CD-ROM */
end_comment

begin_define
define|#
directive|define
name|FS_BOOT
value|13
end_define

begin_comment
comment|/* partition contains bootstrap */
end_comment

begin_define
define|#
directive|define
name|FS_VINUM
value|14
end_define

begin_comment
comment|/* Vinum drive */
end_comment

begin_define
define|#
directive|define
name|FS_RAID
value|15
end_define

begin_comment
comment|/* RAIDFrame drive */
end_comment

begin_define
define|#
directive|define
name|FS_FILECORE
value|16
end_define

begin_comment
comment|/* Acorn Filecore Filing System */
end_comment

begin_define
define|#
directive|define
name|FS_EXT2FS
value|17
end_define

begin_comment
comment|/* ext2fs */
end_comment

begin_define
define|#
directive|define
name|FS_NTFS
value|18
end_define

begin_comment
comment|/* Windows/NT file system */
end_comment

begin_define
define|#
directive|define
name|FS_CCD
value|20
end_define

begin_comment
comment|/* concatenated disk component */
end_comment

begin_define
define|#
directive|define
name|FS_JFS2
value|21
end_define

begin_comment
comment|/* IBM JFS2 */
end_comment

begin_define
define|#
directive|define
name|FS_HAMMER
value|22
end_define

begin_comment
comment|/* DragonFlyBSD Hammer FS */
end_comment

begin_define
define|#
directive|define
name|FS_HAMMER2
value|23
end_define

begin_comment
comment|/* DragonFlyBSD Hammer2 FS */
end_comment

begin_define
define|#
directive|define
name|FS_UDF
value|24
end_define

begin_comment
comment|/* UDF */
end_comment

begin_define
define|#
directive|define
name|FS_EFS
value|26
end_define

begin_comment
comment|/* SGI's Extent File system */
end_comment

begin_define
define|#
directive|define
name|FS_ZFS
value|27
end_define

begin_comment
comment|/* Sun's ZFS */
end_comment

begin_define
define|#
directive|define
name|FS_NANDFS
value|30
end_define

begin_comment
comment|/* FreeBSD nandfs (NiLFS derived) */
end_comment

begin_comment
comment|/*  * flags shared by various drives:  */
end_comment

begin_define
define|#
directive|define
name|D_REMOVABLE
value|0x01
end_define

begin_comment
comment|/* removable media */
end_comment

begin_define
define|#
directive|define
name|D_ECC
value|0x02
end_define

begin_comment
comment|/* supports ECC */
end_comment

begin_define
define|#
directive|define
name|D_BADSECT
value|0x04
end_define

begin_comment
comment|/* supports bad sector forw. */
end_comment

begin_define
define|#
directive|define
name|D_RAMDISK
value|0x08
end_define

begin_comment
comment|/* disk emulator */
end_comment

begin_define
define|#
directive|define
name|D_CHAIN
value|0x10
end_define

begin_comment
comment|/* can do back-back transfers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISK_BSD_H_ */
end_comment

end_unit

