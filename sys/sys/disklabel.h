begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISKLABEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISKLABEL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Disk description table, see disktab(5)  */
end_comment

begin_define
define|#
directive|define
name|_PATH_DISKTAB
value|"/etc/disktab"
end_define

begin_comment
comment|/*  * Each disk has a label which includes information about the hardware  * disk geometry, filesystem partitions, and drive specific information.  * The label is in block 0 or 1, possibly offset from the beginning  * to leave room for a bootstrap, etc.  */
end_comment

begin_comment
comment|/* XXX these should be defined per controller (or drive) elsewhere, not here! */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LABELSECTOR
value|1
end_define

begin_comment
comment|/* sector containing label */
end_comment

begin_define
define|#
directive|define
name|LABELOFFSET
value|0
end_define

begin_comment
comment|/* offset of label in sector */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DISKMAGIC
value|((u_int32_t)0x82564557)
end_define

begin_comment
comment|/* The disk magic number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPARTITIONS
end_ifndef

begin_define
define|#
directive|define
name|MAXPARTITIONS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Size of bootblock area in sector-size neutral bytes */
end_comment

begin_define
define|#
directive|define
name|BBSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|LABEL_PART
value|2
end_define

begin_comment
comment|/* partition containing label */
end_comment

begin_define
define|#
directive|define
name|RAW_PART
value|2
end_define

begin_comment
comment|/* partition containing whole disk */
end_comment

begin_define
define|#
directive|define
name|SWAP_PART
value|1
end_define

begin_comment
comment|/* partition normally containing swap */
end_comment

begin_struct
struct|struct
name|disklabel
block|{
name|u_int32_t
name|d_magic
decl_stmt|;
comment|/* the magic number */
name|u_int16_t
name|d_type
decl_stmt|;
comment|/* drive type */
name|u_int16_t
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
name|u_int32_t
name|d_secsize
decl_stmt|;
comment|/* # of bytes per sector */
name|u_int32_t
name|d_nsectors
decl_stmt|;
comment|/* # of data sectors per track */
name|u_int32_t
name|d_ntracks
decl_stmt|;
comment|/* # of tracks per cylinder */
name|u_int32_t
name|d_ncylinders
decl_stmt|;
comment|/* # of data cylinders per unit */
name|u_int32_t
name|d_secpercyl
decl_stmt|;
comment|/* # of data sectors per cylinder */
name|u_int32_t
name|d_secperunit
decl_stmt|;
comment|/* # of data sectors per unit */
comment|/* 	 * Spares (bad sector replacements) below are not counted in 	 * d_nsectors or d_secpercyl.  Spare sectors are assumed to 	 * be physical sectors which occupy space at the end of each 	 * track and/or cylinder. 	 */
name|u_int16_t
name|d_sparespertrack
decl_stmt|;
comment|/* # of spare sectors per track */
name|u_int16_t
name|d_sparespercyl
decl_stmt|;
comment|/* # of spare sectors per cylinder */
comment|/* 	 * Alternate cylinders include maintenance, replacement, configuration 	 * description areas, etc. 	 */
name|u_int32_t
name|d_acylinders
decl_stmt|;
comment|/* # of alt. cylinders per unit */
comment|/* hardware characteristics: */
comment|/* 	 * d_interleave, d_trackskew and d_cylskew describe perturbations 	 * in the media format used to compensate for a slow controller. 	 * Interleave is physical sector interleave, set up by the 	 * formatter or controller when formatting.  When interleaving is 	 * in use, logically adjacent sectors are not physically 	 * contiguous, but instead are separated by some number of 	 * sectors.  It is specified as the ratio of physical sectors 	 * traversed per logical sector.  Thus an interleave of 1:1 	 * implies contiguous layout, while 2:1 implies that logical 	 * sector 0 is separated by one sector from logical sector 1. 	 * d_trackskew is the offset of sector 0 on track N relative to 	 * sector 0 on track N-1 on the same cylinder.  Finally, d_cylskew 	 * is the offset of sector 0 on cylinder N relative to sector 0 	 * on cylinder N-1. 	 */
name|u_int16_t
name|d_rpm
decl_stmt|;
comment|/* rotational speed */
name|u_int16_t
name|d_interleave
decl_stmt|;
comment|/* hardware sector interleave */
name|u_int16_t
name|d_trackskew
decl_stmt|;
comment|/* sector 0 skew, per track */
name|u_int16_t
name|d_cylskew
decl_stmt|;
comment|/* sector 0 skew, per cylinder */
name|u_int32_t
name|d_headswitch
decl_stmt|;
comment|/* head switch time, usec */
name|u_int32_t
name|d_trkseek
decl_stmt|;
comment|/* track-to-track seek, usec */
name|u_int32_t
name|d_flags
decl_stmt|;
comment|/* generic flags */
define|#
directive|define
name|NDDATA
value|5
name|u_int32_t
name|d_drivedata
index|[
name|NDDATA
index|]
decl_stmt|;
comment|/* drive-type specific information */
define|#
directive|define
name|NSPARE
value|5
name|u_int32_t
name|d_spare
index|[
name|NSPARE
index|]
decl_stmt|;
comment|/* reserved for future use */
name|u_int32_t
name|d_magic2
decl_stmt|;
comment|/* the magic number (again) */
name|u_int16_t
name|d_checksum
decl_stmt|;
comment|/* xor of data incl. partitions */
comment|/* filesystem and partition information: */
name|u_int16_t
name|d_npartitions
decl_stmt|;
comment|/* number of partitions in following */
name|u_int32_t
name|d_bbsize
decl_stmt|;
comment|/* size of boot area at sn0, bytes */
name|u_int32_t
name|d_sbsize
decl_stmt|;
comment|/* max size of fs superblock, bytes */
struct|struct
name|partition
block|{
comment|/* the partition table */
name|u_int32_t
name|p_size
decl_stmt|;
comment|/* number of sectors in partition */
name|u_int32_t
name|p_offset
decl_stmt|;
comment|/* starting sector */
name|u_int32_t
name|p_fsize
decl_stmt|;
comment|/* filesystem basic fragment size */
name|u_int8_t
name|p_fstype
decl_stmt|;
comment|/* filesystem type, see below */
name|u_int8_t
name|p_frag
decl_stmt|;
comment|/* filesystem fragments per block */
name|u_int16_t
name|p_cpg
decl_stmt|;
comment|/* filesystem cylinders per group */
block|}
name|d_partitions
index|[
name|MAXPARTITIONS
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
name|MAXPARTITIONS
operator|*
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|__inline
name|u_int16_t
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_int16_t
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
block|{
name|u_int16_t
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|u_int16_t
name|sum
init|=
literal|0
decl_stmt|;
name|start
operator|=
operator|(
name|u_int16_t
operator|*
operator|)
name|lp
expr_stmt|;
name|end
operator|=
operator|(
name|u_int16_t
operator|*
operator|)
operator|&
name|lp
operator|->
name|d_partitions
index|[
name|lp
operator|->
name|d_npartitions
index|]
expr_stmt|;
while|while
condition|(
name|start
operator|<
name|end
condition|)
name|sum
operator|^=
operator|*
name|start
operator|++
expr_stmt|;
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_function

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

begin_ifdef
ifdef|#
directive|ifdef
name|DKTYPENAMES
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|dktypenames
index|[]
init|=
block|{
literal|"unknown"
block|,
literal|"SMD"
block|,
literal|"MSCP"
block|,
literal|"old DEC"
block|,
literal|"SCSI"
block|,
literal|"ESDI"
block|,
literal|"ST506"
block|,
literal|"HP-IB"
block|,
literal|"HP-FL"
block|,
literal|"type 9"
block|,
literal|"floppy"
block|,
literal|"CCD"
block|,
literal|"Vinum"
block|,
literal|"DOC2K"
block|,
literal|"Raid"
block|,
literal|"?"
block|,
literal|"jfs"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DKMAXTYPES
value|(sizeof(dktypenames) / sizeof(dktypenames[0]) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|FSTYPENAMES
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|fstypenames
index|[]
init|=
block|{
literal|"unused"
block|,
literal|"swap"
block|,
literal|"Version 6"
block|,
literal|"Version 7"
block|,
literal|"System V"
block|,
literal|"4.1BSD"
block|,
literal|"Eighth Edition"
block|,
literal|"4.2BSD"
block|,
literal|"MSDOS"
block|,
literal|"4.4LFS"
block|,
literal|"unknown"
block|,
literal|"HPFS"
block|,
literal|"ISO9660"
block|,
literal|"boot"
block|,
literal|"vinum"
block|,
literal|"raid"
block|,
literal|"Filecore"
block|,
literal|"EXT2FS"
block|,
literal|"NTFS"
block|,
literal|"?"
block|,
literal|"ccd"
block|,
literal|"jfs"
block|,
literal|"HAMMER"
block|,
literal|"HAMMER2"
block|,
literal|"UDF"
block|,
literal|"?"
block|,
literal|"EFS"
block|,
literal|"ZFS"
block|,
literal|"?"
block|,
literal|"?"
block|,
literal|"nandfs"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FSMAXTYPES
value|(sizeof(fstypenames) / sizeof(fstypenames[0]) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Disklabel-specific ioctls.  *  * NB:<sys/disk.h> defines ioctls from 'd'/128 and up.  */
end_comment

begin_comment
comment|/* get and set disklabel */
end_comment

begin_define
define|#
directive|define
name|DIOCGDINFO
value|_IOR('d', 101, struct disklabel)
end_define

begin_comment
comment|/* get */
end_comment

begin_define
define|#
directive|define
name|DIOCSDINFO
value|_IOW('d', 102, struct disklabel)
end_define

begin_comment
comment|/* set */
end_comment

begin_define
define|#
directive|define
name|DIOCWDINFO
value|_IOW('d', 103, struct disklabel)
end_define

begin_comment
comment|/* set, update disk */
end_comment

begin_define
define|#
directive|define
name|DIOCBSDBB
value|_IOW('d', 110, void *)
end_define

begin_comment
comment|/* write bootblocks */
end_comment

begin_comment
comment|/*  * Functions for proper encoding/decoding of struct disklabel into/from  * bytestring.  */
end_comment

begin_function_decl
name|void
name|bsd_partition_le_dec
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|partition
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsd_disklabel_le_dec
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|disklabel
modifier|*
name|d
parameter_list|,
name|int
name|maxpart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_partition_le_enc
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|partition
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_disklabel_le_enc
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|disklabel
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|disklabel
modifier|*
name|getdiskbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISKLABEL_H_ */
end_comment

end_unit

