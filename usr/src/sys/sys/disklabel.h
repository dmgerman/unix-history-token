begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)disklabel.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Disk description table, see disktab(5)  */
end_comment

begin_define
define|#
directive|define
name|DISKTAB
value|"/etc/disktab"
end_define

begin_comment
comment|/*  * Each disk has a label which includes information about the hardware  * disk geometry, filesystem partitions, and drive specific information.  * The label is in block 0 or 1, possibly offset from the beginning  * to leave room for a bootstrap, etc.  */
end_comment

begin_define
define|#
directive|define
name|LABELSECTOR
value|0
end_define

begin_comment
comment|/* sector containing label */
end_comment

begin_define
define|#
directive|define
name|LABELOFFSET
value|64
end_define

begin_comment
comment|/* offset of label in sector */
end_comment

begin_define
define|#
directive|define
name|DISKMAGIC
value|0x82564557
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|disklabel
block|{
name|u_long
name|d_magic
decl_stmt|;
comment|/* the magic number */
name|short
name|d_type
decl_stmt|;
comment|/* drive type */
name|short
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
name|d_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* pack identifier */
comment|/* disk geometry: */
name|u_long
name|d_secsize
decl_stmt|;
comment|/* # of bytes per sector */
name|u_long
name|d_nsectors
decl_stmt|;
comment|/* # of data sectors per track */
name|u_long
name|d_ntracks
decl_stmt|;
comment|/* # of tracks per cylinder */
name|u_long
name|d_ncylinders
decl_stmt|;
comment|/* # of data cylinders per unit */
name|u_long
name|d_secpercyl
decl_stmt|;
comment|/* # of data sectors per cylinder */
name|u_long
name|d_secperunit
decl_stmt|;
comment|/* # of data sectors per unit */
comment|/* 	 * Spares (bad sector replacements) below 	 * are not counted in d_nsectors or d_secpercyl. 	 * Spare sectors are assumed to be physical sectors 	 * which occupy space at the end of each track and/or cylinder. 	 */
name|u_short
name|d_sparespertrack
decl_stmt|;
comment|/* # of spare sectors per track */
name|u_short
name|d_sparespercyl
decl_stmt|;
comment|/* # of spare sectors per cylinder */
comment|/* 	 * Alternate cylinders include maintenance, replacement, 	 * configuration description areas, etc. 	 */
name|u_long
name|d_acylinders
decl_stmt|;
comment|/* # of alt. cylinders per unit */
comment|/* hardware characteristics: */
comment|/* 	 * d_interleave, d_trackskew and d_cylskew describe perturbations 	 * in the media format used to compensate for a slow controller. 	 * Interleave is physical sector interleave, set up by the formatter 	 * or controller when formatting.  When interleaving is in use, 	 * logically adjacent sectors are not physically contiguous, 	 * but instead are separated by some number of sectors. 	 * It is specified as the ratio of physical sectors traversed 	 * per logical sector.  Thus an interleave of 1:1 implies contiguous 	 * layout, while 2:1 implies that logical sector 0 is separated 	 * by one sector from logical sector 1. 	 * d_trackskew is the offset of sector 0 on track N 	 * relative to sector 0 on track N-1 on the same cylinder. 	 * Finally, d_cylskew is the offset of sector 0 on cylinder N 	 * relative to sector 0 on cylinder N-1. 	 */
name|u_short
name|d_rpm
decl_stmt|;
comment|/* rotational speed */
name|u_short
name|d_interleave
decl_stmt|;
comment|/* hardware sector interleave */
name|u_short
name|d_trackskew
decl_stmt|;
comment|/* sector 0 skew, per track */
name|u_short
name|d_cylskew
decl_stmt|;
comment|/* sector 0 skew, per cylinder */
name|u_long
name|d_headswitch
decl_stmt|;
comment|/* head switch time, usec */
name|u_long
name|d_trkseek
decl_stmt|;
comment|/* track-to-track seek, usec */
name|u_long
name|d_flags
decl_stmt|;
comment|/* generic flags */
define|#
directive|define
name|NDDATA
value|5
name|u_long
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
name|u_long
name|d_spare
index|[
name|NSPARE
index|]
decl_stmt|;
comment|/* reserved for future use */
name|u_long
name|d_magic2
decl_stmt|;
comment|/* the magic number (again) */
name|u_short
name|d_checksum
decl_stmt|;
comment|/* xor of data incl. partitions */
comment|/* filesystem and partition information: */
name|u_short
name|d_npartitions
decl_stmt|;
comment|/* number of partitions in following */
name|u_long
name|d_bbsize
decl_stmt|;
comment|/* size of boot area at sn0, bytes */
name|u_long
name|d_sbsize
decl_stmt|;
comment|/* max size of fs superblock, bytes */
struct|struct
name|partition
block|{
comment|/* the partition table */
name|u_long
name|p_size
decl_stmt|;
comment|/* number of sectors in partition */
name|u_long
name|p_offset
decl_stmt|;
comment|/* starting sector */
name|u_long
name|p_fsize
decl_stmt|;
comment|/* filesystem basic fragment size */
name|u_char
name|p_fstype
decl_stmt|;
comment|/* filesystem type, see below */
name|u_char
name|p_frag
decl_stmt|;
comment|/* filesystem fragments per block */
name|u_short
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

begin_else
else|#
directive|else
else|LOCORE
end_else

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
endif|LOCORE
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
name|DTYPE_FLOPPY
value|10
comment|/* floppy */
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
literal|"type 6"
block|,
literal|"type 7"
block|,
literal|"type 8"
block|,
literal|"type 9"
block|,
literal|"floppy"
block|,
literal|0
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
literal|0
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Structure used to perform a format  * or other raw operation, returning data  * and/or register values.  * Register identification and format  * are device- and driver-dependent.  */
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
comment|/*  * Disk-specific ioctls.  */
end_comment

begin_comment
comment|/* get and set disklabel; last form used internally */
end_comment

begin_define
define|#
directive|define
name|DIOCGDINFO
value|_IOR(d, 101, struct disklabel)
end_define

begin_comment
comment|/* get */
end_comment

begin_define
define|#
directive|define
name|DIOCSDINFO
value|_IOW(d, 102, struct disklabel)
end_define

begin_comment
comment|/* set */
end_comment

begin_define
define|#
directive|define
name|DIOCWDINFO
value|_IOW(d, 103, struct disklabel)
end_define

begin_comment
comment|/* set and write back */
end_comment

begin_define
define|#
directive|define
name|DIOCGDINFOP
value|_IOW(d, 104, struct disklabel *)
end_define

begin_comment
comment|/* get pointer */
end_comment

begin_comment
comment|/* do format operation, read or write */
end_comment

begin_define
define|#
directive|define
name|DIOCRFORMAT
value|_IOWR(d, 105, struct format_op)
end_define

begin_define
define|#
directive|define
name|DIOCWFORMAT
value|_IOWR(d, 106, struct format_op)
end_define

begin_define
define|#
directive|define
name|DIOCSSTEP
value|_IOW(d, 107, int)
end_define

begin_comment
comment|/* set step rate */
end_comment

begin_define
define|#
directive|define
name|DIOCSRETRIES
value|_IOW(d, 108, int)
end_define

begin_comment
comment|/* set # of retries */
end_comment

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_function_decl
name|struct
name|disklabel
modifier|*
name|getdiskbyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

