begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: disklabel.h,v 1.69 2001/04/03 20:25:22 ragge Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  *	$FreeBSD$  */
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

begin_comment
comment|/*  * We need<machine/types.h> for __HAVE_OLD_DISKLABEL  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
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

begin_comment
comment|/*  * Each disk has a label which includes information about the hardware  * disk geometry, filesystem partitions, and drive specific information.  * The location of the label, as well as the number of partitions the  * label can describe and the number of the "whole disk" (raw)  * paritition are machine dependent.  */
end_comment

begin_include
include|#
directive|include
file|<machine/disklabel.h>
end_include

begin_comment
comment|/*  * The absolute maximum number of disk partitions allowed.  * This is the maximum value of MAXPARTITIONS for which 'struct disklabel'  * is<= DEV_BSIZE bytes long.  If MAXPARTITIONS is greater than this, beware.  */
end_comment

begin_define
define|#
directive|define
name|MAXMAXPARTITIONS
value|22
end_define

begin_if
if|#
directive|if
name|MAXPARTITIONS
operator|>
name|MAXMAXPARTITIONS
end_if

begin_warning
warning|#
directive|warning
warning|beware: MAXPARTITIONS bigger than MAXMAXPARTITIONS
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ports can switch their MAXPARTITIONS once, as follows:  *  * - define OLDMAXPARTITIONS in<machine/disklabel.h> as the old number  * - define MAXPARTITIONS as the new number  * - define DISKUNIT, DISKPART and DISKMINOR macros in<machine/disklabel.h>  *   as appropriate for the port (see the i386 one for an example).  * - define __HAVE_OLD_DISKLABEL in<machine/types.h>  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__HAVE_OLD_DISKLABEL
argument_list|)
operator|&&
expr|\
operator|(
name|MAXPARTITIONS
operator|<
name|OLDMAXPARTITIONS
operator|)
end_if

begin_error
error|#
directive|error
literal|"can only grow disklabel size"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Translate between device numbers and major/disk unit/disk partition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_OLD_DISKLABEL
end_ifndef

begin_define
define|#
directive|define
name|DISKUNIT
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev) / MAXPARTITIONS)
end_define

begin_define
define|#
directive|define
name|DISKPART
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev) % MAXPARTITIONS)
end_define

begin_define
define|#
directive|define
name|DISKMINOR
parameter_list|(
name|unit
parameter_list|,
name|part
parameter_list|)
define|\
value|(((unit) * MAXPARTITIONS) + (part))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAKEDISKDEV
parameter_list|(
name|maj
parameter_list|,
name|unit
parameter_list|,
name|part
parameter_list|)
define|\
value|(makedev((maj), DISKMINOR((unit), (part))))
end_define

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
name|_LOCORE
end_ifndef

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
comment|/* 	 * d_packname contains the pack identifier and is returned when 	 * the disklabel is read off the disk or in-core copy. 	 * d_boot0 and d_boot1 are the (optional) names of the 	 * primary (block 0) and secondary (block 1-15) bootstraps 	 * as found in /usr/mdec.  These are returned when using 	 * getdiskbyname(3) to retrieve the values from /etc/disktab. 	 */
union|union
block|{
name|char
name|un_d_packname
index|[
literal|16
index|]
decl_stmt|;
comment|/* pack identifier */
struct|struct
block|{
name|char
modifier|*
name|un_d_boot0
decl_stmt|;
comment|/* primary bootstrap name */
name|char
modifier|*
name|un_d_boot1
decl_stmt|;
comment|/* secondary bootstrap name */
block|}
name|un_b
struct|;
block|}
name|d_un
union|;
define|#
directive|define
name|d_packname
value|d_un.un_d_packname
define|#
directive|define
name|d_boot0
value|d_un.un_b.un_d_boot0
define|#
directive|define
name|d_boot1
value|d_un.un_b.un_d_boot1
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
comment|/* 	 * Alternative cylinders include maintenance, replacement, 	 * configuration description areas, etc. 	 */
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
union|union
block|{
name|u_int16_t
name|cpg
decl_stmt|;
comment|/* UFS: FS cylinders per group */
name|u_int16_t
name|sgs
decl_stmt|;
comment|/* LFS: FS segment shift */
block|}
name|__partition_u1
union|;
define|#
directive|define
name|p_cpg
value|__partition_u1.cpg
define|#
directive|define
name|p_sgs
value|__partition_u1.sgs
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
name|__HAVE_OLD_DISKLABEL
end_ifdef

begin_comment
comment|/*  * Same as above, but with OLDMAXPARTITIONS partitions. For use in  * the old DIOC* ioctl calls.  */
end_comment

begin_struct
struct|struct
name|olddisklabel
block|{
name|u_int32_t
name|d_magic
decl_stmt|;
name|u_int16_t
name|d_type
decl_stmt|;
name|u_int16_t
name|d_subtype
decl_stmt|;
name|char
name|d_typename
index|[
literal|16
index|]
decl_stmt|;
union|union
block|{
name|char
name|un_d_packname
index|[
literal|16
index|]
decl_stmt|;
struct|struct
block|{
name|char
modifier|*
name|un_d_boot0
decl_stmt|;
name|char
modifier|*
name|un_d_boot1
decl_stmt|;
block|}
name|un_b
struct|;
block|}
name|d_un
union|;
name|u_int32_t
name|d_secsize
decl_stmt|;
name|u_int32_t
name|d_nsectors
decl_stmt|;
name|u_int32_t
name|d_ntracks
decl_stmt|;
name|u_int32_t
name|d_ncylinders
decl_stmt|;
name|u_int32_t
name|d_secpercyl
decl_stmt|;
name|u_int32_t
name|d_secperunit
decl_stmt|;
name|u_int16_t
name|d_sparespertrack
decl_stmt|;
name|u_int16_t
name|d_sparespercyl
decl_stmt|;
name|u_int32_t
name|d_acylinders
decl_stmt|;
name|u_int16_t
name|d_rpm
decl_stmt|;
name|u_int16_t
name|d_interleave
decl_stmt|;
name|u_int16_t
name|d_trackskew
decl_stmt|;
name|u_int16_t
name|d_cylskew
decl_stmt|;
name|u_int32_t
name|d_headswitch
decl_stmt|;
name|u_int32_t
name|d_trkseek
decl_stmt|;
name|u_int32_t
name|d_flags
decl_stmt|;
name|u_int32_t
name|d_drivedata
index|[
name|NDDATA
index|]
decl_stmt|;
name|u_int32_t
name|d_spare
index|[
name|NSPARE
index|]
decl_stmt|;
name|u_int32_t
name|d_magic2
decl_stmt|;
name|u_int16_t
name|d_checksum
decl_stmt|;
name|u_int16_t
name|d_npartitions
decl_stmt|;
name|u_int32_t
name|d_bbsize
decl_stmt|;
name|u_int32_t
name|d_sbsize
decl_stmt|;
struct|struct
name|opartition
block|{
name|u_int32_t
name|p_size
decl_stmt|;
name|u_int32_t
name|p_offset
decl_stmt|;
name|u_int32_t
name|p_fsize
decl_stmt|;
name|u_int8_t
name|p_fstype
decl_stmt|;
name|u_int8_t
name|p_frag
decl_stmt|;
union|union
block|{
name|u_int16_t
name|cpg
decl_stmt|;
name|u_int16_t
name|sgs
decl_stmt|;
block|}
name|__partition_u1
union|;
block|}
name|d_partitions
index|[
name|OLDMAXPARTITIONS
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
comment|/* __HAVE_OLD_DISKLABEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _LOCORE */
end_comment

begin_comment
comment|/* 	 * offsets for asm boot files. 	 */
end_comment

begin_expr_stmt
operator|.
name|set
name|d_secsize
operator|,
literal|40
operator|.
name|set
name|d_nsectors
operator|,
literal|44
operator|.
name|set
name|d_ntracks
operator|,
literal|48
operator|.
name|set
name|d_ncylinders
operator|,
literal|52
operator|.
name|set
name|d_secpercyl
operator|,
literal|56
operator|.
name|set
name|d_secperunit
operator|,
literal|60
operator|.
name|set
name|d_end_
operator|,
literal|276
comment|/* size of disk label */
endif|#
directive|endif
comment|/* _LOCORE */
comment|/* d_type values: */
define|#
directive|define
name|DTYPE_SMD
value|1
comment|/* SMD, XSMD; VAX hp/up */
define|#
directive|define
name|DTYPE_MSCP
value|2
comment|/* MSCP */
define|#
directive|define
name|DTYPE_DEC
value|3
comment|/* other DEC (rk, rl) */
define|#
directive|define
name|DTYPE_SCSI
value|4
comment|/* SCSI */
define|#
directive|define
name|DTYPE_ESDI
value|5
comment|/* ESDI interface */
define|#
directive|define
name|DTYPE_ST506
value|6
comment|/* ST506 etc. */
define|#
directive|define
name|DTYPE_HPIB
value|7
comment|/* CS/80 on HP-IB */
define|#
directive|define
name|DTYPE_HPFL
value|8
comment|/* HP Fiber-link */
define|#
directive|define
name|DTYPE_FLOPPY
value|10
comment|/* floppy */
define|#
directive|define
name|DTYPE_CCD
value|11
comment|/* concatenated disk device */
define|#
directive|define
name|DTYPE_VND
value|12
comment|/* vnode pseudo-disk */
define|#
directive|define
name|DTYPE_ATAPI
value|13
comment|/* ATAPI */
define|#
directive|define
name|DTYPE_RAID
value|14
comment|/* RAIDframe */
define|#
directive|define
name|DTYPE_LD
value|15
comment|/* logical disk */
ifdef|#
directive|ifdef
name|DKTYPENAMES
specifier|static
specifier|const
name|char
operator|*
specifier|const
name|dktypenames
index|[]
operator|=
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
literal|"ccd"
block|,
literal|"vnd"
block|,
literal|"ATAPI"
block|,
literal|"RAID"
block|,
literal|"ld"
block|,
name|NULL
block|}
expr_stmt|;
end_expr_stmt

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
comment|/* 4.2BSD fast file system */
end_comment

begin_define
define|#
directive|define
name|FS_MSDOS
value|8
end_define

begin_comment
comment|/* MSDOS file system */
end_comment

begin_define
define|#
directive|define
name|FS_BSDLFS
value|9
end_define

begin_comment
comment|/* 4.4BSD log-structured file system */
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
comment|/* OS/2 high-performance file system */
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
name|FS_ADOS
value|14
end_define

begin_comment
comment|/* AmigaDOS fast file system */
end_comment

begin_define
define|#
directive|define
name|FS_HFS
value|15
end_define

begin_comment
comment|/* Macintosh HFS */
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
name|FS_EX2FS
value|17
end_define

begin_comment
comment|/* Linux Extended 2 file system */
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
name|FS_RAID
value|19
end_define

begin_comment
comment|/* RAIDframe component */
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
specifier|const
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
literal|"ADOS"
block|,
literal|"HFS"
block|,
literal|"FILECORE"
block|,
literal|"Linux Ext2"
block|,
literal|"NTFS"
block|,
literal|"RAID"
block|,
literal|"ccd"
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

begin_ifdef
ifdef|#
directive|ifdef
name|FSCKNAMES
end_ifdef

begin_comment
comment|/* These are the names MOUNT_XXX from<sys/mount.h> */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|fscknames
index|[]
init|=
block|{
name|NULL
block|,
comment|/* unused */
name|NULL
block|,
comment|/* swap */
name|NULL
block|,
comment|/* Version 6 */
name|NULL
block|,
comment|/* Version 7 */
name|NULL
block|,
comment|/* System V */
name|NULL
block|,
comment|/* 4.1BSD */
name|NULL
block|,
comment|/* Eighth edition */
literal|"ffs"
block|,
comment|/* 4.2BSD */
literal|"msdos"
block|,
comment|/* MSDOS */
literal|"lfs"
block|,
comment|/* 4.4LFS */
name|NULL
block|,
comment|/* unknown */
name|NULL
block|,
comment|/* HPFS */
name|NULL
block|,
comment|/* ISO9660 */
name|NULL
block|,
comment|/* boot */
name|NULL
block|,
comment|/* ADOS */
name|NULL
block|,
comment|/* HFS */
name|NULL
block|,
comment|/* FILECORE */
literal|"ext2fs"
block|,
comment|/* Linux Ext2 */
name|NULL
block|,
comment|/* Windows/NT */
name|NULL
block|,
comment|/* RAID Component */
name|NULL
block|,
comment|/* concatenated disk component */
name|NULL
comment|/* NULL */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FSMAXNAMES
value|(sizeof(fscknames) / sizeof(fscknames[0]) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MOUNTNAMES
end_ifdef

begin_comment
comment|/* These are the names MOUNT_XXX from<sys/mount.h> */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|mountnames
index|[]
init|=
block|{
name|NULL
block|,
comment|/* unused */
name|NULL
block|,
comment|/* swap */
name|NULL
block|,
comment|/* Version 6 */
name|NULL
block|,
comment|/* Version 7 */
name|NULL
block|,
comment|/* System V */
name|NULL
block|,
comment|/* 4.1BSD */
name|NULL
block|,
comment|/* Eighth edition */
literal|"ffs"
block|,
comment|/* 4.2BSD */
literal|"msdos"
block|,
comment|/* MSDOS */
literal|"lfs"
block|,
comment|/* 4.4LFS */
name|NULL
block|,
comment|/* unknown */
name|NULL
block|,
comment|/* HPFS */
literal|"cd9660"
block|,
comment|/* ISO9660 */
name|NULL
block|,
comment|/* boot */
literal|"ados"
block|,
comment|/* ADOS */
name|NULL
block|,
comment|/* HFS */
literal|"filecore"
block|,
comment|/* FILECORE */
literal|"ext2fs"
block|,
comment|/* Linux Ext2 */
literal|"ntfs"
block|,
comment|/* Windows/NT */
name|NULL
block|,
comment|/* RAID Component */
name|NULL
block|,
comment|/* concatenated disk component */
name|NULL
comment|/* NULL */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FSMAXMOUNTNAMES
value|(sizeof(mountnames) / sizeof(mountnames[0]) - 1)
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
comment|/*  * Drive data for SMD.  */
end_comment

begin_define
define|#
directive|define
name|d_smdflags
value|d_drivedata[0]
end_define

begin_define
define|#
directive|define
name|D_SSE
value|0x1
end_define

begin_comment
comment|/* supports skip sectoring */
end_comment

begin_define
define|#
directive|define
name|d_mindist
value|d_drivedata[1]
end_define

begin_define
define|#
directive|define
name|d_maxdist
value|d_drivedata[2]
end_define

begin_define
define|#
directive|define
name|d_sdist
value|d_drivedata[3]
end_define

begin_comment
comment|/*  * Drive data for ST506.  */
end_comment

begin_define
define|#
directive|define
name|d_precompcyl
value|d_drivedata[0]
end_define

begin_define
define|#
directive|define
name|d_gap3
value|d_drivedata[1]
end_define

begin_comment
comment|/* used only when formatting */
end_comment

begin_comment
comment|/*  * Drive data for SCSI.  */
end_comment

begin_define
define|#
directive|define
name|d_blind
value|d_drivedata[0]
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_comment
comment|/*  * Structure used to perform a format or other raw operation,  * returning data and/or register values.  Register identification  * and format are device- and driver-dependent.  */
end_comment

begin_struct
struct|struct
name|format_op
block|{
name|char
modifier|*
name|df_buf
decl_stmt|;
name|int
name|df_count
decl_stmt|;
comment|/* value-result */
name|daddr_t
name|df_startblk
decl_stmt|;
name|int
name|df_reg
index|[
literal|8
index|]
decl_stmt|;
comment|/* result */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used internally to retrieve information about a partition  * on a disk.  */
end_comment

begin_struct
struct|struct
name|partinfo
block|{
name|struct
name|disklabel
modifier|*
name|disklab
decl_stmt|;
name|struct
name|partition
modifier|*
name|part
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|buf_queue
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|diskerr
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disksort_cylinder
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disksort_blkno
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disksort_tail
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|dkcksum
name|__P
argument_list|(
operator|(
expr|struct
name|disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setdisklabel
name|__P
argument_list|(
operator|(
expr|struct
name|disklabel
operator|*
operator|,
expr|struct
name|disklabel
operator|*
operator|,
name|u_long
operator|,
expr|struct
name|cpu_disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|readdisklabel
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
argument_list|)
operator|,
expr|struct
name|disklabel
operator|*
operator|,
expr|struct
name|cpu_disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|writedisklabel
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
argument_list|)
operator|,
expr|struct
name|disklabel
operator|*
operator|,
expr|struct
name|cpu_disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bounds_check_with_label
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|disklabel
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LOCORE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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

