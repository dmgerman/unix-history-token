begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DKIO_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DKIO_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/* SunOS-4.0 5.19 */
end_comment

begin_include
include|#
directive|include
file|<sys/dklabel.h>
end_include

begin_comment
comment|/* Needed for NDKMAP define */
end_comment

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
comment|/*  * Structures and definitions for disk io control commands  */
comment|/*  * Structures used as data by ioctl calls.  */
define|#
directive|define
name|DK_DEVLEN
value|16
comment|/* device name max length, including */
comment|/* unit #& NULL (ie - "xyc1") */
comment|/*  * Used for controller info  */
struct|struct
name|dk_cinfo
block|{
name|char
name|dki_cname
index|[
name|DK_DEVLEN
index|]
decl_stmt|;
comment|/* controller name (no unit #) */
name|ushort_t
name|dki_ctype
decl_stmt|;
comment|/* controller type */
name|ushort_t
name|dki_flags
decl_stmt|;
comment|/* flags */
name|ushort_t
name|dki_cnum
decl_stmt|;
comment|/* controller number */
name|uint_t
name|dki_addr
decl_stmt|;
comment|/* controller address */
name|uint_t
name|dki_space
decl_stmt|;
comment|/* controller bus type */
name|uint_t
name|dki_prio
decl_stmt|;
comment|/* interrupt priority */
name|uint_t
name|dki_vec
decl_stmt|;
comment|/* interrupt vector */
name|char
name|dki_dname
index|[
name|DK_DEVLEN
index|]
decl_stmt|;
comment|/* drive name (no unit #) */
name|uint_t
name|dki_unit
decl_stmt|;
comment|/* unit number */
name|uint_t
name|dki_slave
decl_stmt|;
comment|/* slave number */
name|ushort_t
name|dki_partition
decl_stmt|;
comment|/* partition number */
name|ushort_t
name|dki_maxtransfer
decl_stmt|;
comment|/* max. transfer size in DEV_BSIZE */
block|}
struct|;
comment|/*  * Controller types  */
define|#
directive|define
name|DKC_UNKNOWN
value|0
define|#
directive|define
name|DKC_CDROM
value|1
comment|/* CD-ROM, SCSI or otherwise */
define|#
directive|define
name|DKC_WDC2880
value|2
define|#
directive|define
name|DKC_XXX_0
value|3
comment|/* unassigned */
define|#
directive|define
name|DKC_XXX_1
value|4
comment|/* unassigned */
define|#
directive|define
name|DKC_DSD5215
value|5
define|#
directive|define
name|DKC_ACB4000
value|7
define|#
directive|define
name|DKC_MD21
value|8
define|#
directive|define
name|DKC_XXX_2
value|9
comment|/* unassigned */
define|#
directive|define
name|DKC_NCRFLOPPY
value|10
define|#
directive|define
name|DKC_SMSFLOPPY
value|12
define|#
directive|define
name|DKC_SCSI_CCS
value|13
comment|/* SCSI CCS compatible */
define|#
directive|define
name|DKC_INTEL82072
value|14
comment|/* native floppy chip */
define|#
directive|define
name|DKC_MD
value|16
comment|/* meta-disk (virtual-disk) driver */
define|#
directive|define
name|DKC_INTEL82077
value|19
comment|/* 82077 floppy disk controller */
define|#
directive|define
name|DKC_DIRECT
value|20
comment|/* Intel direct attached device i.e. IDE */
define|#
directive|define
name|DKC_PCMCIA_MEM
value|21
comment|/* PCMCIA memory disk-like type */
define|#
directive|define
name|DKC_PCMCIA_ATA
value|22
comment|/* PCMCIA AT Attached type */
comment|/*  * Sun reserves up through 1023  */
define|#
directive|define
name|DKC_CUSTOMER_BASE
value|1024
comment|/*  * Flags  */
define|#
directive|define
name|DKI_BAD144
value|0x01
comment|/* use DEC std 144 bad sector fwding */
define|#
directive|define
name|DKI_MAPTRK
value|0x02
comment|/* controller does track mapping */
define|#
directive|define
name|DKI_FMTTRK
value|0x04
comment|/* formats only full track at a time */
define|#
directive|define
name|DKI_FMTVOL
value|0x08
comment|/* formats only full volume at a time */
define|#
directive|define
name|DKI_FMTCYL
value|0x10
comment|/* formats only full cylinders at a time */
define|#
directive|define
name|DKI_HEXUNIT
value|0x20
comment|/* unit number is printed as 3 hex digits */
define|#
directive|define
name|DKI_PCMCIA_PFD
value|0x40
comment|/* PCMCIA pseudo-floppy memory card */
comment|/*  * Used for all partitions  */
struct|struct
name|dk_allmap
block|{
name|struct
name|dk_map
name|dka_map
index|[
name|NDKMAP
index|]
decl_stmt|;
block|}
struct|;
if|#
directive|if
name|defined
argument_list|(
name|_SYSCALL32
argument_list|)
struct|struct
name|dk_allmap32
block|{
name|struct
name|dk_map32
name|dka_map
index|[
name|NDKMAP
index|]
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
comment|/*  * Definition of a disk's geometry  */
struct|struct
name|dk_geom
block|{
name|unsigned
name|short
name|dkg_ncyl
decl_stmt|;
comment|/* # of data cylinders */
name|unsigned
name|short
name|dkg_acyl
decl_stmt|;
comment|/* # of alternate cylinders */
name|unsigned
name|short
name|dkg_bcyl
decl_stmt|;
comment|/* cyl offset (for fixed head area) */
name|unsigned
name|short
name|dkg_nhead
decl_stmt|;
comment|/* # of heads */
name|unsigned
name|short
name|dkg_obs1
decl_stmt|;
comment|/* obsolete */
name|unsigned
name|short
name|dkg_nsect
decl_stmt|;
comment|/* # of data sectors per track */
name|unsigned
name|short
name|dkg_intrlv
decl_stmt|;
comment|/* interleave factor */
name|unsigned
name|short
name|dkg_obs2
decl_stmt|;
comment|/* obsolete */
name|unsigned
name|short
name|dkg_obs3
decl_stmt|;
comment|/* obsolete */
name|unsigned
name|short
name|dkg_apc
decl_stmt|;
comment|/* alternates per cyl (SCSI only) */
name|unsigned
name|short
name|dkg_rpm
decl_stmt|;
comment|/* revolutions per minute */
name|unsigned
name|short
name|dkg_pcyl
decl_stmt|;
comment|/* # of physical cylinders */
name|unsigned
name|short
name|dkg_write_reinstruct
decl_stmt|;
comment|/* # sectors to skip, writes */
name|unsigned
name|short
name|dkg_read_reinstruct
decl_stmt|;
comment|/* # sectors to skip, reads */
name|unsigned
name|short
name|dkg_extra
index|[
literal|7
index|]
decl_stmt|;
comment|/* for compatible expansion */
block|}
struct|;
comment|/*  * These defines are for historic compatibility with old drivers.  */
define|#
directive|define
name|dkg_bhead
value|dkg_obs1
comment|/* used to be head offset */
define|#
directive|define
name|dkg_gap1
value|dkg_obs2
comment|/* used to be gap1 */
define|#
directive|define
name|dkg_gap2
value|dkg_obs3
comment|/* used to be gap2 */
comment|/*  * Disk io control commands  * Warning: some other ioctls with the DIOC prefix exist elsewhere.  * The Generic DKIOC numbers are from	0   -  50.  *	The Floppy Driver uses		51  - 100.  *	The Hard Disk (except SCSI)	101 - 106.	(these are obsolete)  *	The CDROM Driver		151 - 200.  *	The USCSI ioctl			201 - 250.  */
define|#
directive|define
name|DKIOC
value|(0x04<< 8)
comment|/*  * The following ioctls are generic in nature and need to be  * suported as appropriate by all disk drivers  */
define|#
directive|define
name|DKIOCGGEOM
value|(DKIOC|1)
comment|/* Get geometry */
define|#
directive|define
name|DKIOCINFO
value|(DKIOC|3)
comment|/* Get info */
define|#
directive|define
name|DKIOCEJECT
value|(DKIOC|6)
comment|/* Generic 'eject' */
define|#
directive|define
name|DKIOCGVTOC
value|(DKIOC|11)
comment|/* Get VTOC */
define|#
directive|define
name|DKIOCSVTOC
value|(DKIOC|12)
comment|/* Set VTOC& Write to Disk */
comment|/*  * Disk Cache Controls.  These ioctls should be supported by  * all disk drivers.  *  * DKIOCFLUSHWRITECACHE when used from user-mode ignores the ioctl  * argument, but it should be passed as NULL to allow for future  * reinterpretation.  From user-mode, this ioctl request is synchronous.  *  * When invoked from within the kernel, the arg can be NULL to indicate  * a synchronous request or can be the address of a struct dk_callback  * to request an asynchronous callback when the flush request is complete.  * In this case, the flag to the ioctl must include FKIOCTL and the  * dkc_callback field of the pointed to struct must be non-null or the  * request is made synchronously.  *  * In the callback case: if the ioctl returns 0, a callback WILL be performed.  * If the ioctl returns non-zero, a callback will NOT be performed.  * NOTE: In some cases, the callback may be done BEFORE the ioctl call  * returns.  The caller's locking strategy should be prepared for this case.  */
define|#
directive|define
name|DKIOCFLUSHWRITECACHE
value|(DKIOC|34)
comment|/* flush cache to phys medium */
struct|struct
name|dk_callback
block|{
name|void
function_decl|(
modifier|*
name|dkc_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|dkc_cookie
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
name|void
modifier|*
name|dkc_cookie
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|DKIOCGETWCE
value|(DKIOC|36)
comment|/* Get current write cache */
comment|/* enablement status */
define|#
directive|define
name|DKIOCSETWCE
value|(DKIOC|37)
comment|/* Enable/Disable write cache */
comment|/*  * The following ioctls are used by Sun drivers to communicate  * with their associated format routines. Support of these ioctls  * is not required of foreign drivers  */
define|#
directive|define
name|DKIOCSGEOM
value|(DKIOC|2)
comment|/* Set geometry */
define|#
directive|define
name|DKIOCSAPART
value|(DKIOC|4)
comment|/* Set all partitions */
define|#
directive|define
name|DKIOCGAPART
value|(DKIOC|5)
comment|/* Get all partitions */
define|#
directive|define
name|DKIOCG_PHYGEOM
value|(DKIOC|32)
comment|/* get physical geometry */
define|#
directive|define
name|DKIOCG_VIRTGEOM
value|(DKIOC|33)
comment|/* get virtual geometry */
comment|/*  * The following ioctl's are removable media support  */
define|#
directive|define
name|DKIOCLOCK
value|(DKIOC|7)
comment|/* Generic 'lock' */
define|#
directive|define
name|DKIOCUNLOCK
value|(DKIOC|8)
comment|/* Generic 'unlock' */
define|#
directive|define
name|DKIOCSTATE
value|(DKIOC|13)
comment|/* Inquire insert/eject state */
define|#
directive|define
name|DKIOCREMOVABLE
value|(DKIOC|16)
comment|/* is media removable */
comment|/*  * ioctl for hotpluggable devices  */
define|#
directive|define
name|DKIOCHOTPLUGGABLE
value|(DKIOC|35)
comment|/* is hotpluggable */
comment|/*  * Ioctl to force driver to re-read the alternate partition and rebuild  * the internal defect map.  */
define|#
directive|define
name|DKIOCADDBAD
value|(DKIOC|20)
comment|/* Re-read the alternate map (IDE) */
define|#
directive|define
name|DKIOCGETDEF
value|(DKIOC|21)
comment|/* read defect list (IDE)	   */
comment|/*  * Used by applications to get disk defect information from IDE  * drives.  */
ifdef|#
directive|ifdef
name|_SYSCALL32
struct|struct
name|defect_header32
block|{
name|int
name|head
decl_stmt|;
name|caddr32_t
name|buffer
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
struct|struct
name|defect_header
block|{
name|int
name|head
decl_stmt|;
name|caddr_t
name|buffer
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|DKIOCPARTINFO
value|(DKIOC|22)
comment|/* Get partition or slice parameters */
comment|/*  * Used by applications to get partition or slice information  */
ifdef|#
directive|ifdef
name|_SYSCALL32
struct|struct
name|part_info32
block|{
name|daddr32_t
name|p_start
decl_stmt|;
name|int
name|p_length
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
struct|struct
name|part_info
block|{
name|daddr_t
name|p_start
decl_stmt|;
name|int
name|p_length
decl_stmt|;
block|}
struct|;
comment|/* The following ioctls are for Optical Memory Device */
define|#
directive|define
name|DKIOC_EBP_ENABLE
value|(DKIOC|40)
comment|/* enable by pass erase on write */
define|#
directive|define
name|DKIOC_EBP_DISABLE
value|(DKIOC|41)
comment|/* disable by pass erase on write */
comment|/*  * This state enum is the argument passed to the DKIOCSTATE ioctl.  */
enum|enum
name|dkio_state
block|{
name|DKIO_NONE
block|,
name|DKIO_EJECTED
block|,
name|DKIO_INSERTED
block|,
name|DKIO_DEV_GONE
block|}
enum|;
define|#
directive|define
name|DKIOCGMEDIAINFO
value|(DKIOC|42)
comment|/* get information about the media */
comment|/*  * ioctls to read/write mboot info.  */
define|#
directive|define
name|DKIOCGMBOOT
value|(DKIOC|43)
comment|/* get mboot info */
define|#
directive|define
name|DKIOCSMBOOT
value|(DKIOC|44)
comment|/* set mboot info */
comment|/*  * ioctl to get the device temperature.  */
define|#
directive|define
name|DKIOCGTEMPERATURE
value|(DKIOC|45)
comment|/* get temperature */
comment|/*  * Used for providing the temperature.  */
struct|struct
name|dk_temperature
block|{
name|uint_t
name|dkt_flags
decl_stmt|;
comment|/* Flags */
name|short
name|dkt_cur_temp
decl_stmt|;
comment|/* Current disk temperature */
name|short
name|dkt_ref_temp
decl_stmt|;
comment|/* reference disk temperature */
block|}
struct|;
define|#
directive|define
name|DKT_BYPASS_PM
value|0x1
define|#
directive|define
name|DKT_INVALID_TEMP
value|0xFFFF
comment|/*  * Used for Media info or the current profile info  */
struct|struct
name|dk_minfo
block|{
name|uint_t
name|dki_media_type
decl_stmt|;
comment|/* Media type or profile info */
name|uint_t
name|dki_lbsize
decl_stmt|;
comment|/* Logical blocksize of media */
name|diskaddr_t
name|dki_capacity
decl_stmt|;
comment|/* Capacity as # of dki_lbsize blks */
block|}
struct|;
comment|/*  * Media types or profiles known  */
define|#
directive|define
name|DK_UNKNOWN
value|0x00
comment|/* Media inserted - type unknown */
comment|/*  * SFF 8090 Specification Version 3, media types 0x01 - 0xfffe are retained to  * maintain compatibility with SFF8090.  The following define the  * optical media type.  */
define|#
directive|define
name|DK_REMOVABLE_DISK
value|0x02
comment|/* Removable Disk */
define|#
directive|define
name|DK_MO_ERASABLE
value|0x03
comment|/* MO Erasable */
define|#
directive|define
name|DK_MO_WRITEONCE
value|0x04
comment|/* MO Write once */
define|#
directive|define
name|DK_AS_MO
value|0x05
comment|/* AS MO */
define|#
directive|define
name|DK_CDROM
value|0x08
comment|/* CDROM */
define|#
directive|define
name|DK_CDR
value|0x09
comment|/* CD-R */
define|#
directive|define
name|DK_CDRW
value|0x0A
comment|/* CD-RW */
define|#
directive|define
name|DK_DVDROM
value|0x10
comment|/* DVD-ROM */
define|#
directive|define
name|DK_DVDR
value|0x11
comment|/* DVD-R */
define|#
directive|define
name|DK_DVDRAM
value|0x12
comment|/* DVD_RAM or DVD-RW */
comment|/*  * Media types for other rewritable magnetic media  */
define|#
directive|define
name|DK_FIXED_DISK
value|0x10001
comment|/* Fixed disk SCSI or otherwise */
define|#
directive|define
name|DK_FLOPPY
value|0x10002
comment|/* Floppy media */
define|#
directive|define
name|DK_ZIP
value|0x10003
comment|/* IOMEGA ZIP media */
define|#
directive|define
name|DK_JAZ
value|0x10004
comment|/* IOMEGA JAZ media */
define|#
directive|define
name|DKIOCSETEFI
value|(DKIOC|17)
comment|/* Set EFI info */
define|#
directive|define
name|DKIOCGETEFI
value|(DKIOC|18)
comment|/* Get EFI info */
define|#
directive|define
name|DKIOCPARTITION
value|(DKIOC|9)
comment|/* Get partition info */
comment|/*  * Ioctls to get/set volume capabilities related to Logical Volume Managers.  * They include the ability to get/set capabilities and to issue a read to a  * specific underlying device of a replicated device.  */
define|#
directive|define
name|DKIOCGETVOLCAP
value|(DKIOC | 25)
comment|/* Get volume capabilities */
define|#
directive|define
name|DKIOCSETVOLCAP
value|(DKIOC | 26)
comment|/* Set volume capabilities */
define|#
directive|define
name|DKIOCDMR
value|(DKIOC | 27)
comment|/* Issue a directed read */
typedef|typedef
name|uint_t
name|volcapinfo_t
typedef|;
typedef|typedef
name|uint_t
name|volcapset_t
typedef|;
define|#
directive|define
name|DKV_ABR_CAP
value|0x00000001
comment|/* Support Appl.Based Recovery */
define|#
directive|define
name|DKV_DMR_CAP
value|0x00000002
comment|/* Support Directed  Mirror Read */
typedef|typedef
struct|struct
name|volcap
block|{
name|volcapinfo_t
name|vc_info
decl_stmt|;
comment|/* Capabilities available */
name|volcapset_t
name|vc_set
decl_stmt|;
comment|/* Capabilities set */
block|}
name|volcap_t
typedef|;
define|#
directive|define
name|VOL_SIDENAME
value|256
typedef|typedef
struct|struct
name|vol_directed_rd
block|{
name|int
name|vdr_flags
decl_stmt|;
name|offset_t
name|vdr_offset
decl_stmt|;
name|size_t
name|vdr_nbytes
decl_stmt|;
name|size_t
name|vdr_bytesread
decl_stmt|;
name|void
modifier|*
name|vdr_data
decl_stmt|;
name|int
name|vdr_side
decl_stmt|;
name|char
name|vdr_side_name
index|[
name|VOL_SIDENAME
index|]
decl_stmt|;
block|}
name|vol_directed_rd_t
typedef|;
define|#
directive|define
name|DKV_SIDE_INIT
value|(-1)
define|#
directive|define
name|DKV_DMR_NEXT_SIDE
value|0x00000001
define|#
directive|define
name|DKV_DMR_DONE
value|0x00000002
define|#
directive|define
name|DKV_DMR_ERROR
value|0x00000004
define|#
directive|define
name|DKV_DMR_SUCCESS
value|0x00000008
define|#
directive|define
name|DKV_DMR_SHORT
value|0x00000010
ifdef|#
directive|ifdef
name|_MULTI_DATAMODEL
if|#
directive|if
name|_LONG_LONG_ALIGNMENT
operator|==
literal|8
operator|&&
name|_LONG_LONG_ALIGNMENT_32
operator|==
literal|4
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
endif|#
directive|endif
typedef|typedef
struct|struct
name|vol_directed_rd32
block|{
name|int32_t
name|vdr_flags
decl_stmt|;
name|offset_t
name|vdr_offset
decl_stmt|;
comment|/* 64-bit element on 32-bit alignment */
name|size32_t
name|vdr_nbytes
decl_stmt|;
name|size32_t
name|vdr_bytesread
decl_stmt|;
name|caddr32_t
name|vdr_data
decl_stmt|;
name|int32_t
name|vdr_side
decl_stmt|;
name|char
name|vdr_side_name
index|[
name|VOL_SIDENAME
index|]
decl_stmt|;
block|}
name|vol_directed_rd32_t
typedef|;
if|#
directive|if
name|_LONG_LONG_ALIGNMENT
operator|==
literal|8
operator|&&
name|_LONG_LONG_ALIGNMENT_32
operator|==
literal|4
pragma|#
directive|pragma
name|pack
name|(
name|)
endif|#
directive|endif
endif|#
directive|endif
comment|/* _MULTI_DATAMODEL */
comment|/*  * The ioctl is used to fetch disk's device type, vendor ID,  * model number/product ID, firmware revision and serial number together.  *  * Currently there are two device types - DKD_ATA_TYPE which means the  * disk is driven by cmdk/ata or dad/uata driver, and DKD_SCSI_TYPE  * which means the disk is driven by sd/scsi hba driver.  */
define|#
directive|define
name|DKIOC_GETDISKID
value|(DKIOC|46)
comment|/* These two labels are for dkd_dtype of dk_disk_id_t */
define|#
directive|define
name|DKD_ATA_TYPE
value|0x01
comment|/* ATA disk or legacy mode SATA disk */
define|#
directive|define
name|DKD_SCSI_TYPE
value|0x02
comment|/* SCSI disk or native mode SATA disk */
define|#
directive|define
name|DKD_ATA_MODEL
value|40
comment|/* model number length */
define|#
directive|define
name|DKD_ATA_FWVER
value|8
comment|/* firmware revision length */
define|#
directive|define
name|DKD_ATA_SERIAL
value|20
comment|/* serial number length */
define|#
directive|define
name|DKD_SCSI_VENDOR
value|8
comment|/* vendor ID length */
define|#
directive|define
name|DKD_SCSI_PRODUCT
value|16
comment|/* product ID length */
define|#
directive|define
name|DKD_SCSI_REVLEVEL
value|4
comment|/* revision level length */
define|#
directive|define
name|DKD_SCSI_SERIAL
value|12
comment|/* serial number length */
comment|/*  * The argument type for DKIOC_GETDISKID ioctl.  */
typedef|typedef
struct|struct
name|dk_disk_id
block|{
name|uint_t
name|dkd_dtype
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|char
name|dkd_amodel
index|[
name|DKD_ATA_MODEL
index|]
decl_stmt|;
comment|/* 40 bytes */
name|char
name|dkd_afwver
index|[
name|DKD_ATA_FWVER
index|]
decl_stmt|;
comment|/* 8 bytes */
name|char
name|dkd_aserial
index|[
name|DKD_ATA_SERIAL
index|]
decl_stmt|;
comment|/* 20 bytes */
block|}
name|ata_disk_id
struct|;
struct|struct
block|{
name|char
name|dkd_svendor
index|[
name|DKD_SCSI_VENDOR
index|]
decl_stmt|;
comment|/* 8 bytes */
name|char
name|dkd_sproduct
index|[
name|DKD_SCSI_PRODUCT
index|]
decl_stmt|;
comment|/* 16 bytes */
name|char
name|dkd_sfwver
index|[
name|DKD_SCSI_REVLEVEL
index|]
decl_stmt|;
comment|/* 4 bytes */
name|char
name|dkd_sserial
index|[
name|DKD_SCSI_SERIAL
index|]
decl_stmt|;
comment|/* 12 bytes */
block|}
name|scsi_disk_id
struct|;
block|}
name|disk_id
union|;
block|}
name|dk_disk_id_t
typedef|;
comment|/*  * The ioctl is used to update the firmware of device.  */
define|#
directive|define
name|DKIOC_UPDATEFW
value|(DKIOC|47)
comment|/* The argument type for DKIOC_UPDATEFW ioctl */
typedef|typedef
struct|struct
name|dk_updatefw
block|{
name|caddr_t
name|dku_ptrbuf
decl_stmt|;
comment|/* pointer to firmware buf */
name|uint_t
name|dku_size
decl_stmt|;
comment|/* firmware buf length */
name|uint8_t
name|dku_type
decl_stmt|;
comment|/* firmware update type */
block|}
name|dk_updatefw_t
typedef|;
ifdef|#
directive|ifdef
name|_SYSCALL32
typedef|typedef
struct|struct
name|dk_updatefw_32
block|{
name|caddr32_t
name|dku_ptrbuf
decl_stmt|;
comment|/* pointer to firmware buf */
name|uint_t
name|dku_size
decl_stmt|;
comment|/* firmware buf length */
name|uint8_t
name|dku_type
decl_stmt|;
comment|/* firmware update type */
block|}
name|dk_updatefw_32_t
typedef|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
comment|/*  * firmware update type - temporary or permanent use  */
define|#
directive|define
name|FW_TYPE_TEMP
value|0x0
comment|/* temporary use */
define|#
directive|define
name|FW_TYPE_PERM
value|0x1
comment|/* permanent use */
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
comment|/* _SYS_DKIO_H */
end_comment

end_unit

