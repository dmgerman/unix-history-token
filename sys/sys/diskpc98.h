begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|DISKTAB
value|"/etc/disktab"
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_comment
comment|/*  * Each disk has a label which includes information about the hardware  * disk geometry, filesystem partitions, and drive specific information.  * The label is in block 0 or 1, possibly offset from the beginning  * to leave room for a bootstrap, etc.  */
end_comment

begin_comment
comment|/* XXX these should be defined per controller (or drive) elsewhere, not here! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|LABELSECTOR
value|0
end_define

begin_define
define|#
directive|define
name|LABELOFFSET
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|LABELSECTOR
value|1
end_define

begin_define
define|#
directive|define
name|LABELOFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_define
define|#
directive|define
name|LABELSECTOR
value|0
end_define

begin_define
define|#
directive|define
name|LABELOFFSET
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LABELSECTOR
end_ifndef

begin_define
define|#
directive|define
name|LABELSECTOR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LABELOFFSET
end_ifndef

begin_define
define|#
directive|define
name|LABELOFFSET
value|64
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
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
comment|/*  	 * d_packname contains the pack identifier and is returned when 	 * the disklabel is read off the disk or in-core copy. 	 * d_boot0 and d_boot1 are the (optional) names of the 	 * primary (block 0) and secondary (block 1-15) bootstraps 	 * as found in /boot.  These are returned when using 	 * getdiskbyname(3) to retrieve the values from /etc/disktab. 	 */
union|union
block|{
name|char
name|un_d_packname
index|[
literal|16
index|]
decl_stmt|;
comment|/* pack identifier */
ifndef|#
directive|ifndef
name|_KERNEL
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
endif|#
directive|endif
block|}
name|d_un
union|;
define|#
directive|define
name|d_packname
value|d_un.un_d_packname
ifndef|#
directive|ifndef
name|_KERNEL
define|#
directive|define
name|d_boot0
value|d_un.un_b.un_d_boot0
define|#
directive|define
name|d_boot1
value|d_un.un_b.un_d_boot1
endif|#
directive|endif
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
name|lp
parameter_list|)
name|struct
name|disklabel
modifier|*
name|lp
decl_stmt|;
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCORE */
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
comment|/* LOCORE */
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
comment|/* concatenated disk */
define|#
directive|define
name|DTYPE_VINUM
value|12
comment|/* vinum volume */
define|#
directive|define
name|DTYPE_DOC2K
value|13
comment|/* Msys DiskOnChip */
if|#
directive|if
name|defined
argument_list|(
name|PC98
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PC98_ATCOMPAT
argument_list|)
define|#
directive|define
name|DSTYPE_SEC256
value|0x80
comment|/* physical sector size=256 */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DKTYPENAMES
specifier|static
name|char
operator|*
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
literal|"CCD"
block|,
literal|"Vinum"
block|,
literal|"DOC2K"
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
name|FS_VINUM
value|14
end_define

begin_comment
comment|/* Vinum drive */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DKTYPENAMES
end_ifdef

begin_decl_stmt
specifier|static
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
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Structure used to perform a format or other raw operation, returning  * data and/or register values.  Register identification and format  * are device- and driver-dependent.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOS partition table -- located in boot block */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PC98
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PC98_ATCOMPAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOSBBSECTOR
value|0
end_define

begin_comment
comment|/* DOS boot block relative sector number */
end_comment

begin_define
define|#
directive|define
name|DOSLABELSECTOR
value|1
end_define

begin_comment
comment|/* 0: 256b/s, 1: 512b/s */
end_comment

begin_define
define|#
directive|define
name|DOSPARTOFF
value|0
end_define

begin_define
define|#
directive|define
name|NDOSPART
value|16
end_define

begin_define
define|#
directive|define
name|DOSPTYP_386BSD
value|0x94
end_define

begin_comment
comment|/* 386BSD partition type */
end_comment

begin_define
define|#
directive|define
name|MBR_PTYPE_FreeBSD
value|0x94
end_define

begin_comment
comment|/* FreeBSD partition type */
end_comment

begin_struct
struct|struct
name|dos_partition
block|{
name|unsigned
name|char
name|dp_mid
decl_stmt|;
define|#
directive|define
name|DOSMID_386BSD
value|(0x14|0x80)
comment|/* 386bsd|bootable */
name|unsigned
name|char
name|dp_sid
decl_stmt|;
define|#
directive|define
name|DOSSID_386BSD
value|(0x44|0x80)
comment|/* 386bsd|active */
name|unsigned
name|char
name|dp_dum1
decl_stmt|;
name|unsigned
name|char
name|dp_dum2
decl_stmt|;
name|unsigned
name|char
name|dp_ipl_sct
decl_stmt|;
name|unsigned
name|char
name|dp_ipl_head
decl_stmt|;
name|unsigned
name|short
name|dp_ipl_cyl
decl_stmt|;
name|unsigned
name|char
name|dp_ssect
decl_stmt|;
comment|/* starting sector */
name|unsigned
name|char
name|dp_shd
decl_stmt|;
comment|/* starting head */
name|unsigned
name|short
name|dp_scyl
decl_stmt|;
comment|/* starting cylinder */
name|unsigned
name|char
name|dp_esect
decl_stmt|;
comment|/* end sector */
name|unsigned
name|char
name|dp_ehd
decl_stmt|;
comment|/* end head */
name|unsigned
name|short
name|dp_ecyl
decl_stmt|;
comment|/* end cylinder */
name|unsigned
name|char
name|dp_name
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBMPC */
end_comment

begin_define
define|#
directive|define
name|DOSBBSECTOR
value|0
end_define

begin_comment
comment|/* DOS boot block relative sector number */
end_comment

begin_define
define|#
directive|define
name|DOSPARTOFF
value|446
end_define

begin_define
define|#
directive|define
name|NDOSPART
value|4
end_define

begin_define
define|#
directive|define
name|DOSPTYP_386BSD
value|0xa5
end_define

begin_comment
comment|/* 386BSD partition type */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINSWP
value|0x82
end_define

begin_comment
comment|/* Linux swap partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINUX
value|0x83
end_define

begin_comment
comment|/* Linux partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_EXT
value|5
end_define

begin_comment
comment|/* DOS extended partition */
end_comment

begin_struct
struct|struct
name|dos_partition
block|{
name|unsigned
name|char
name|dp_flag
decl_stmt|;
comment|/* bootstrap flags */
name|unsigned
name|char
name|dp_shd
decl_stmt|;
comment|/* starting head */
name|unsigned
name|char
name|dp_ssect
decl_stmt|;
comment|/* starting sector */
name|unsigned
name|char
name|dp_scyl
decl_stmt|;
comment|/* starting cylinder */
name|unsigned
name|char
name|dp_typ
decl_stmt|;
comment|/* partition type */
name|unsigned
name|char
name|dp_ehd
decl_stmt|;
comment|/* end head */
name|unsigned
name|char
name|dp_esect
decl_stmt|;
comment|/* end sector */
name|unsigned
name|char
name|dp_ecyl
decl_stmt|;
comment|/* end cylinder */
name|u_int32_t
name|dp_start
decl_stmt|;
comment|/* absolute starting sector number */
name|u_int32_t
name|dp_size
decl_stmt|;
comment|/* partition size in sectors */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DPSECT
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x3f)
end_define

begin_comment
comment|/* isolate relevant bits of sector */
end_comment

begin_define
define|#
directive|define
name|DPCYL
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|((c) + (((s)& 0xc0)<<2))
end_define

begin_comment
comment|/* and those that are cylinder */
end_comment

begin_comment
comment|/*  * Disk-specific ioctls.  */
end_comment

begin_comment
comment|/* get and set disklabel; DIOCGPART used internally */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|DIOCGPART
value|_IOW('d', 104, struct partinfo)
end_define

begin_comment
comment|/* get partition */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIOCGDVIRGIN
value|_IOR('d', 105, struct disklabel)
end_define

begin_comment
comment|/* get virgin label */
end_comment

begin_define
define|#
directive|define
name|DIOCWLABEL
value|_IOW('d', 109, int)
end_define

begin_comment
comment|/* write en/disable label */
end_comment

begin_define
define|#
directive|define
name|DIOCGSECTORSIZE
value|_IOR('d', 128, u_int)
end_define

begin_comment
comment|/* Get sector size in bytes */
end_comment

begin_define
define|#
directive|define
name|DIOCGMEDIASIZE
value|_IOR('d', 129, off_t)
end_define

begin_comment
comment|/* Get media size in bytes */
end_comment

begin_define
define|#
directive|define
name|DIOCGFWSECTORS
value|_IOR('d', 130, u_int)
end_define

begin_comment
comment|/* Get firmware sectorcount */
end_comment

begin_define
define|#
directive|define
name|DIOCGFWHEADS
value|_IOR('d', 131, u_int)
end_define

begin_comment
comment|/* Get firmware headcount */
end_comment

begin_define
define|#
directive|define
name|DIOCGFWCYLINDERS
value|_IOR('d', 132, u_int)
end_define

begin_comment
comment|/* Get firmware cyl'scount */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX encoding of disk minor numbers, should be elsewhere.  *  * See<sys/reboot.h> for a possibly better encoding.  *  * "cpio -H newc" can be used to back up device files with large minor  * numbers (but not ones>= 2^31).  Old cpio formats and all tar formats  * don't have enough bits, and cpio and tar don't notice the lossage.  * There are also some sign extension bugs.  */
end_comment

begin_comment
comment|/*        3                   2                   1                   0      1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0     _________________________________________________________________     | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |     -----------------------------------------------------------------     |    SPARE    |UNIT_2 | SLICE   |  MAJOR?       |  UNIT   |PART |     ----------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|DKMAXUNIT
value|0x1ff
end_define

begin_define
define|#
directive|define
name|dkmakeminor
parameter_list|(
name|unit
parameter_list|,
name|slice
parameter_list|,
name|part
parameter_list|)
define|\
value|(((slice)<< 16) | (((unit)& 0x1e0)<< 16) | \ 				(((unit)& 0x1f)<< 3) | (part))
end_define

begin_define
define|#
directive|define
name|dkpart
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev)& 7)
end_define

begin_define
define|#
directive|define
name|dkslice
parameter_list|(
name|dev
parameter_list|)
value|((minor(dev)>> 16)& 0x1f)
end_define

begin_define
define|#
directive|define
name|dksparebits
parameter_list|(
name|dev
parameter_list|)
value|((minor(dev)>> 25)& 0x7f)
end_define

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bio_queue_head
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bounds_check_with_label
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|,
name|int
name|wlabel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diskerr
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|char
modifier|*
name|what
parameter_list|,
name|int
name|blkdone
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|dkmodpart
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|part
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|dkmodslice
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|dkunit
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|readdisklabel
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bioqdisksort
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|ap
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setdisklabel
parameter_list|(
name|struct
name|disklabel
modifier|*
name|olp
parameter_list|,
name|struct
name|disklabel
modifier|*
name|nlp
parameter_list|,
name|u_long
name|openmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|writedisklabel
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|alpha_fix_srm_checksum
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

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

