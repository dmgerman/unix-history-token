begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 1990-2002 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DKLABEL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DKLABEL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types32.h>
end_include

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Miscellaneous defines  */
define|#
directive|define
name|DKL_MAGIC
value|0xDABE
comment|/* magic number */
define|#
directive|define
name|FKL_MAGIC
value|0xff
comment|/* magic number for DOS floppies */
if|#
directive|if
name|defined
argument_list|(
name|_SUNOS_VTOC_16
argument_list|)
define|#
directive|define
name|NDKMAP
value|16
comment|/* # of logical partitions */
define|#
directive|define
name|DK_LABEL_LOC
value|1
comment|/* location of disk label */
elif|#
directive|elif
name|defined
argument_list|(
name|_SUNOS_VTOC_8
argument_list|)
define|#
directive|define
name|NDKMAP
value|8
comment|/* # of logical partitions */
define|#
directive|define
name|DK_LABEL_LOC
value|0
comment|/* location of disk label */
else|#
directive|else
error|#
directive|error
literal|"No VTOC format defined."
endif|#
directive|endif
define|#
directive|define
name|LEN_DKL_ASCII
value|128
comment|/* length of dkl_asciilabel */
define|#
directive|define
name|LEN_DKL_VVOL
value|8
comment|/* length of v_volume */
define|#
directive|define
name|DK_LABEL_SIZE
value|512
comment|/* size of disk label */
define|#
directive|define
name|DK_MAX_BLOCKS
value|0x7fffffff
comment|/* max # of blocks handled */
comment|/*  * Reserve two cylinders on SCSI disks.  * One is for the backup disk label and the other is for the deviceid.  *  * IPI disks only reserve one cylinder, but they will go away soon.  * CDROMs do not reserve any cylinders.  */
define|#
directive|define
name|DK_ACYL
value|2
comment|/*  * Format of a Sun disk label.  * Resides in cylinder 0, head 0, sector 0.  *  * sizeof (struct dk_label) should be 512 (the current sector size),  * but should the sector size increase, this structure should remain  * at the beginning of the sector.  */
comment|/*  * partition headers:  section 1  * Returned in struct dk_allmap by ioctl DKIOC[SG]APART (dkio(7I))  */
struct|struct
name|dk_map
block|{
name|daddr_t
name|dkl_cylno
decl_stmt|;
comment|/* starting cylinder */
name|daddr_t
name|dkl_nblk
decl_stmt|;
comment|/* number of blocks;  if == 0, */
comment|/* partition is undefined */
block|}
struct|;
comment|/*  * partition headers:  section 1  * Fixed size for on-disk dk_label  */
struct|struct
name|dk_map32
block|{
name|daddr32_t
name|dkl_cylno
decl_stmt|;
comment|/* starting cylinder */
name|daddr32_t
name|dkl_nblk
decl_stmt|;
comment|/* number of blocks;  if == 0, */
comment|/* partition is undefined */
block|}
struct|;
comment|/*  * partition headers:  section 2,  * brought over from AT&T SVr4 vtoc structure.  */
struct|struct
name|dk_map2
block|{
name|uint16_t
name|p_tag
decl_stmt|;
comment|/* ID tag of partition */
name|uint16_t
name|p_flag
decl_stmt|;
comment|/* permission flag */
block|}
struct|;
struct|struct
name|dkl_partition
block|{
name|uint16_t
name|p_tag
decl_stmt|;
comment|/* ID tag of partition */
name|uint16_t
name|p_flag
decl_stmt|;
comment|/* permision flags */
name|daddr32_t
name|p_start
decl_stmt|;
comment|/* start sector no of partition */
name|int32_t
name|p_size
decl_stmt|;
comment|/* # of blocks in partition */
block|}
struct|;
comment|/*  * VTOC inclusions from AT&T SVr4  * Fixed sized types for on-disk VTOC  */
struct|struct
name|dk_vtoc
block|{
if|#
directive|if
name|defined
argument_list|(
name|_SUNOS_VTOC_16
argument_list|)
name|uint32_t
name|v_bootinfo
index|[
literal|3
index|]
decl_stmt|;
comment|/* info for mboot (unsupported) */
name|uint32_t
name|v_sanity
decl_stmt|;
comment|/* to verify vtoc sanity */
name|uint32_t
name|v_version
decl_stmt|;
comment|/* layout version */
name|char
name|v_volume
index|[
name|LEN_DKL_VVOL
index|]
decl_stmt|;
comment|/* volume name */
name|uint16_t
name|v_sectorsz
decl_stmt|;
comment|/* sector size in bytes */
name|uint16_t
name|v_nparts
decl_stmt|;
comment|/* number of partitions */
name|uint32_t
name|v_reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* free space */
name|struct
name|dkl_partition
name|v_part
index|[
name|NDKMAP
index|]
decl_stmt|;
comment|/* partition headers */
name|time32_t
name|timestamp
index|[
name|NDKMAP
index|]
decl_stmt|;
comment|/* partition timestamp (unsupported) */
name|char
name|v_asciilabel
index|[
name|LEN_DKL_ASCII
index|]
decl_stmt|;
comment|/* for compatibility    */
elif|#
directive|elif
name|defined
argument_list|(
name|_SUNOS_VTOC_8
argument_list|)
name|uint32_t
name|v_version
decl_stmt|;
comment|/* layout version */
name|char
name|v_volume
index|[
name|LEN_DKL_VVOL
index|]
decl_stmt|;
comment|/* volume name */
name|uint16_t
name|v_nparts
decl_stmt|;
comment|/* number of partitions  */
name|struct
name|dk_map2
name|v_part
index|[
name|NDKMAP
index|]
decl_stmt|;
comment|/* partition hdrs, sec 2 */
name|uint32_t
name|v_bootinfo
index|[
literal|3
index|]
decl_stmt|;
comment|/* info needed by mboot */
name|uint32_t
name|v_sanity
decl_stmt|;
comment|/* to verify vtoc sanity */
name|uint32_t
name|v_reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* free space */
name|time32_t
name|v_timestamp
index|[
name|NDKMAP
index|]
decl_stmt|;
comment|/* partition timestamp */
else|#
directive|else
error|#
directive|error
literal|"No VTOC format defined."
endif|#
directive|endif
block|}
struct|;
comment|/*  * define the amount of disk label padding needed to make  * the entire structure occupy 512 bytes.  */
if|#
directive|if
name|defined
argument_list|(
name|_SUNOS_VTOC_16
argument_list|)
define|#
directive|define
name|LEN_DKL_PAD
value|(DK_LABEL_SIZE - \ 			    ((sizeof (struct dk_vtoc) + \ 			    (4 * sizeof (uint32_t)) + \ 			    (12 * sizeof (uint16_t)) + \ 			    (2 * (sizeof (uint16_t))))))
elif|#
directive|elif
name|defined
argument_list|(
name|_SUNOS_VTOC_8
argument_list|)
define|#
directive|define
name|LEN_DKL_PAD
value|(DK_LABEL_SIZE \ 			    - ((LEN_DKL_ASCII) + \ 			    (sizeof (struct dk_vtoc)) + \ 			    (sizeof (struct dk_map32)  * NDKMAP) + \ 			    (14 * (sizeof (uint16_t))) + \ 			    (2 * (sizeof (uint16_t)))))
else|#
directive|else
error|#
directive|error
literal|"No VTOC format defined."
endif|#
directive|endif
struct|struct
name|dk_label
block|{
if|#
directive|if
name|defined
argument_list|(
name|_SUNOS_VTOC_16
argument_list|)
name|struct
name|dk_vtoc
name|dkl_vtoc
decl_stmt|;
comment|/* vtoc inclusions from AT&T SVr4 */
name|uint32_t
name|dkl_pcyl
decl_stmt|;
comment|/* # of physical cylinders */
name|uint32_t
name|dkl_ncyl
decl_stmt|;
comment|/* # of data cylinders */
name|uint16_t
name|dkl_acyl
decl_stmt|;
comment|/* # of alternate cylinders */
name|uint16_t
name|dkl_bcyl
decl_stmt|;
comment|/* cyl offset (for fixed head area) */
name|uint32_t
name|dkl_nhead
decl_stmt|;
comment|/* # of heads */
name|uint32_t
name|dkl_nsect
decl_stmt|;
comment|/* # of data sectors per track */
name|uint16_t
name|dkl_intrlv
decl_stmt|;
comment|/* interleave factor */
name|uint16_t
name|dkl_skew
decl_stmt|;
comment|/* skew factor */
name|uint16_t
name|dkl_apc
decl_stmt|;
comment|/* alternates per cyl (SCSI only)   */
name|uint16_t
name|dkl_rpm
decl_stmt|;
comment|/* revolutions per minute */
name|uint16_t
name|dkl_write_reinstruct
decl_stmt|;
comment|/* # sectors to skip, writes */
name|uint16_t
name|dkl_read_reinstruct
decl_stmt|;
comment|/* # sectors to skip, reads  */
name|uint16_t
name|dkl_extra
index|[
literal|4
index|]
decl_stmt|;
comment|/* for compatible expansion */
name|char
name|dkl_pad
index|[
name|LEN_DKL_PAD
index|]
decl_stmt|;
comment|/* unused part of 512 bytes */
elif|#
directive|elif
name|defined
argument_list|(
name|_SUNOS_VTOC_8
argument_list|)
name|char
name|dkl_asciilabel
index|[
name|LEN_DKL_ASCII
index|]
decl_stmt|;
comment|/* for compatibility */
name|struct
name|dk_vtoc
name|dkl_vtoc
decl_stmt|;
comment|/* vtoc inclusions from AT&T SVr4 */
name|uint16_t
name|dkl_write_reinstruct
decl_stmt|;
comment|/* # sectors to skip, writes */
name|uint16_t
name|dkl_read_reinstruct
decl_stmt|;
comment|/* # sectors to skip, reads */
name|char
name|dkl_pad
index|[
name|LEN_DKL_PAD
index|]
decl_stmt|;
comment|/* unused part of 512 bytes */
name|uint16_t
name|dkl_rpm
decl_stmt|;
comment|/* rotations per minute */
name|uint16_t
name|dkl_pcyl
decl_stmt|;
comment|/* # physical cylinders */
name|uint16_t
name|dkl_apc
decl_stmt|;
comment|/* alternates per cylinder */
name|uint16_t
name|dkl_obs1
decl_stmt|;
comment|/* obsolete */
name|uint16_t
name|dkl_obs2
decl_stmt|;
comment|/* obsolete */
name|uint16_t
name|dkl_intrlv
decl_stmt|;
comment|/* interleave factor */
name|uint16_t
name|dkl_ncyl
decl_stmt|;
comment|/* # of data cylinders */
name|uint16_t
name|dkl_acyl
decl_stmt|;
comment|/* # of alternate cylinders */
name|uint16_t
name|dkl_nhead
decl_stmt|;
comment|/* # of heads in this partition */
name|uint16_t
name|dkl_nsect
decl_stmt|;
comment|/* # of 512 byte sectors per track */
name|uint16_t
name|dkl_obs3
decl_stmt|;
comment|/* obsolete */
name|uint16_t
name|dkl_obs4
decl_stmt|;
comment|/* obsolete */
name|struct
name|dk_map32
name|dkl_map
index|[
name|NDKMAP
index|]
decl_stmt|;
comment|/* logical partition headers */
else|#
directive|else
error|#
directive|error
literal|"No VTOC format defined."
endif|#
directive|endif
name|uint16_t
name|dkl_magic
decl_stmt|;
comment|/* identifies this label format */
name|uint16_t
name|dkl_cksum
decl_stmt|;
comment|/* xor checksum of sector */
block|}
struct|;
if|#
directive|if
name|defined
argument_list|(
name|_SUNOS_VTOC_16
argument_list|)
define|#
directive|define
name|dkl_asciilabel
value|dkl_vtoc.v_asciilabel
define|#
directive|define
name|v_timestamp
value|timestamp
elif|#
directive|elif
name|defined
argument_list|(
name|_SUNOS_VTOC_8
argument_list|)
comment|/*  * These defines are for historic compatibility with old drivers.  */
define|#
directive|define
name|dkl_gap1
value|dkl_obs1
comment|/* used to be gap1 */
define|#
directive|define
name|dkl_gap2
value|dkl_obs2
comment|/* used to be gap2 */
define|#
directive|define
name|dkl_bhead
value|dkl_obs3
comment|/* used to be label head offset */
define|#
directive|define
name|dkl_ppart
value|dkl_obs4
comment|/* used to by physical partition */
else|#
directive|else
error|#
directive|error
literal|"No VTOC format defined."
endif|#
directive|endif
struct|struct
name|fk_label
block|{
comment|/* DOS floppy label */
name|uchar_t
name|fkl_type
decl_stmt|;
name|uchar_t
name|fkl_magich
decl_stmt|;
name|uchar_t
name|fkl_magicl
decl_stmt|;
name|uchar_t
name|filler
decl_stmt|;
block|}
struct|;
comment|/*  * Layout of stored fabricated device id  (on-disk)  */
define|#
directive|define
name|DK_DEVID_BLKSIZE
value|(512)
define|#
directive|define
name|DK_DEVID_SIZE
value|(DK_DEVID_BLKSIZE - ((sizeof (uchar_t) * 7)))
define|#
directive|define
name|DK_DEVID_REV_MSB
value|(0)
define|#
directive|define
name|DK_DEVID_REV_LSB
value|(1)
struct|struct
name|dk_devid
block|{
name|uchar_t
name|dkd_rev_hi
decl_stmt|;
comment|/* revision (MSB) */
name|uchar_t
name|dkd_rev_lo
decl_stmt|;
comment|/* revision (LSB) */
name|uchar_t
name|dkd_flags
decl_stmt|;
comment|/* flags (not used yet) */
name|uchar_t
name|dkd_devid
index|[
name|DK_DEVID_SIZE
index|]
decl_stmt|;
comment|/* devid stored here */
name|uchar_t
name|dkd_checksum3
decl_stmt|;
comment|/* checksum (MSB) */
name|uchar_t
name|dkd_checksum2
decl_stmt|;
name|uchar_t
name|dkd_checksum1
decl_stmt|;
name|uchar_t
name|dkd_checksum0
decl_stmt|;
comment|/* checksum (LSB) */
block|}
struct|;
define|#
directive|define
name|DKD_GETCHKSUM
parameter_list|(
name|dkd
parameter_list|)
value|((dkd)->dkd_checksum3<< 24) + \ 				((dkd)->dkd_checksum2<< 16) + \ 				((dkd)->dkd_checksum1<< 8)  + \ 				((dkd)->dkd_checksum0)
define|#
directive|define
name|DKD_FORMCHKSUM
parameter_list|(
name|c
parameter_list|,
name|dkd
parameter_list|)
value|(dkd)->dkd_checksum3 = hibyte(hiword((c))); \ 				(dkd)->dkd_checksum2 = lobyte(hiword((c))); \ 				(dkd)->dkd_checksum1 = hibyte(loword((c))); \ 				(dkd)->dkd_checksum0 = lobyte(loword((c)));
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DKLABEL_H */
end_comment

end_unit

