begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structures and definitions for SCSI commands to Direct Access Devices  */
end_comment

begin_comment
comment|/*  * Some lines of this file come from a file of the name "scsi.h"  * distributed by OSF as part of mach2.5,  *  so the following disclaimer has been kept.  *  * Copyright 1990 by Open Software Foundation,  * Grenoble, FRANCE  *  * 		All Rights Reserved  *  *   Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both the copyright notice and this permission notice appear in  * supporting documentation, and that the name of OSF or Open Software  * Foundation not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission.  *  *   OSF DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS,  * IN NO EVENT SHALL OSF BE LIABLE FOR ANY SPECIAL, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT,  * NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Largely written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_DA_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_DA_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct
struct|struct
name|scsi_rezero_unit
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|SRZU_LUN_MASK
value|0xE0
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE:  The lower three bits of byte2 of the format CDB are the same as  * the lower three bits of byte2 of the read defect data CDB, below.  */
end_comment

begin_struct
struct|struct
name|scsi_format_unit
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|FU_FORMAT_MASK
value|SRDD10_DLIST_FORMAT_MASK
define|#
directive|define
name|FU_BLOCK_FORMAT
value|SRDD10_BLOCK_FORMAT
define|#
directive|define
name|FU_BFI_FORMAT
value|SRDD10_BYTES_FROM_INDEX_FORMAT
define|#
directive|define
name|FU_PHYS_FORMAT
value|SRDD10_PHYSICAL_SECTOR_FORMAT
define|#
directive|define
name|FU_CMPLST
value|0x08
define|#
directive|define
name|FU_FMT_DATA
value|0x10
name|u_int8_t
name|vendor_specific
decl_stmt|;
name|u_int8_t
name|interleave
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_reassign_blocks
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_defect_data_10
block|{
name|u_int8_t
name|opcode
decl_stmt|;
comment|/*  	 * The most significant 3 bits are the LUN, the other 5 are 	 * reserved. 	 */
define|#
directive|define
name|SRDD10_LUN_MASK
value|0xE0
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|SRDD10_GLIST
value|0x08
define|#
directive|define
name|SRDD10_PLIST
value|0x10
define|#
directive|define
name|SRDD10_DLIST_FORMAT_MASK
value|0x07
define|#
directive|define
name|SRDD10_BLOCK_FORMAT
value|0x00
define|#
directive|define
name|SRDD10_BYTES_FROM_INDEX_FORMAT
value|0x04
define|#
directive|define
name|SRDD10_PHYSICAL_SECTOR_FORMAT
value|0x05
name|u_int8_t
name|format
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|alloc_length
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_defect_data_12
block|{
name|u_int8_t
name|opcode
decl_stmt|;
comment|/*  	 * The most significant 3 bits are the LUN, the other 5 are 	 * reserved. 	 */
define|#
directive|define
name|SRDD12_LUN_MASK
value|0xE0
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|SRDD12_GLIST
value|0x08
define|#
directive|define
name|SRDD12_PLIST
value|0x10
define|#
directive|define
name|SRDD12_DLIST_FORMAT_MASK
value|0x07
define|#
directive|define
name|SRDD12_BLOCK_FORMAT
value|0x00
define|#
directive|define
name|SRDD12_BYTES_FROM_INDEX_FORMAT
value|0x04
define|#
directive|define
name|SRDD12_PHYSICAL_SECTOR_FORMAT
value|0x05
name|u_int8_t
name|format
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|alloc_length
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|REZERO_UNIT
value|0x01
end_define

begin_define
define|#
directive|define
name|FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|MODE_SELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|MODE_SENSE
value|0x1a
end_define

begin_define
define|#
directive|define
name|READ_DEFECT_DATA_10
value|0x37
end_define

begin_define
define|#
directive|define
name|READ_DEFECT_DATA_12
value|0xb7
end_define

begin_struct
struct|struct
name|format_defect_list_header
block|{
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|FU_DLH_VS
value|0x01
define|#
directive|define
name|FU_DLH_IMMED
value|0x02
define|#
directive|define
name|FU_DLH_DSP
value|0x04
define|#
directive|define
name|FU_DLH_IP
value|0x08
define|#
directive|define
name|FU_DLH_STPF
value|0x10
define|#
directive|define
name|FU_DLH_DCRT
value|0x20
define|#
directive|define
name|FU_DLH_DPRY
value|0x40
define|#
directive|define
name|FU_DLH_FOV
value|0x80
name|u_int8_t
name|defect_list_length
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|format_ipat_descriptor
block|{
name|u_int8_t
name|byte1
decl_stmt|;
define|#
directive|define
name|FU_INIT_NO_HDR
value|0x00
define|#
directive|define
name|FU_INIT_LBA_MSB
value|0x40
define|#
directive|define
name|FU_INIT_LBA_EACH
value|0x80
define|#
directive|define
name|FU_INIT_SI
value|0x20
name|u_int8_t
name|pattern_type
decl_stmt|;
define|#
directive|define
name|FU_INIT_PAT_DEFAULT
value|0x00
define|#
directive|define
name|FU_INIT_PAT_REPEAT
value|0x01
name|u_int8_t
name|pat_length
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_reassign_blocks_data
block|{
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|length
index|[
literal|2
index|]
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|dlbaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* defect logical block address */
block|}
name|defect_descriptor
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the list header for the READ DEFECT DATA(10) command above.  * It may be a bit wrong to append the 10 at the end of the data structure,  * since it's only 4 bytes but it does tie it to the 10 byte command.  */
end_comment

begin_struct
struct|struct
name|scsi_read_defect_data_hdr_10
block|{
name|u_int8_t
name|reserved
decl_stmt|;
define|#
directive|define
name|SRDDH10_GLIST
value|0x08
define|#
directive|define
name|SRDDH10_PLIST
value|0x10
define|#
directive|define
name|SRDDH10_DLIST_FORMAT_MASK
value|0x07
define|#
directive|define
name|SRDDH10_BLOCK_FORMAT
value|0x00
define|#
directive|define
name|SRDDH10_BYTES_FROM_INDEX_FORMAT
value|0x04
define|#
directive|define
name|SRDDH10_PHYSICAL_SECTOR_FORMAT
value|0x05
name|u_int8_t
name|format
decl_stmt|;
name|u_int8_t
name|length
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_defect_desc_block
block|{
name|u_int8_t
name|address
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_defect_desc_bytes_from_index
block|{
name|u_int8_t
name|cylinder
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|head
decl_stmt|;
name|u_int8_t
name|bytes_from_index
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_defect_desc_phys_sector
block|{
name|u_int8_t
name|cylinder
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|head
decl_stmt|;
name|u_int8_t
name|sector
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_defect_data_hdr_12
block|{
name|u_int8_t
name|reserved
decl_stmt|;
define|#
directive|define
name|SRDDH12_GLIST
value|0x08
define|#
directive|define
name|SRDDH12_PLIST
value|0x10
define|#
directive|define
name|SRDDH12_DLIST_FORMAT_MASK
value|0x07
define|#
directive|define
name|SRDDH12_BLOCK_FORMAT
value|0x00
define|#
directive|define
name|SRDDH12_BYTES_FROM_INDEX_FORMAT
value|0x04
define|#
directive|define
name|SRDDH12_PHYSICAL_SECTOR_FORMAT
value|0x05
name|u_int8_t
name|format
decl_stmt|;
name|u_int8_t
name|length
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|disk_pages
comment|/* this is the structure copied from osf */
block|{
struct|struct
name|format_device_page
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (should be 3)	      */
define|#
directive|define
name|SMS_FORMAT_DEVICE_PAGE
value|0x03
comment|/* only 6 bits valid */
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length (should be 0x16)	      */
define|#
directive|define
name|SMS_FORMAT_DEVICE_PLEN
value|0x16
name|u_int8_t
name|trk_z_1
decl_stmt|;
comment|/* tracks per zone (MSB)	      */
name|u_int8_t
name|trk_z_0
decl_stmt|;
comment|/* tracks per zone (LSB)	      */
name|u_int8_t
name|alt_sec_1
decl_stmt|;
comment|/* alternate sectors per zone (MSB)   */
name|u_int8_t
name|alt_sec_0
decl_stmt|;
comment|/* alternate sectors per zone (LSB)   */
name|u_int8_t
name|alt_trk_z_1
decl_stmt|;
comment|/* alternate tracks per zone (MSB)    */
name|u_int8_t
name|alt_trk_z_0
decl_stmt|;
comment|/* alternate tracks per zone (LSB)    */
name|u_int8_t
name|alt_trk_v_1
decl_stmt|;
comment|/* alternate tracks per volume (MSB)  */
name|u_int8_t
name|alt_trk_v_0
decl_stmt|;
comment|/* alternate tracks per volume (LSB)  */
name|u_int8_t
name|ph_sec_t_1
decl_stmt|;
comment|/* physical sectors per track (MSB)   */
name|u_int8_t
name|ph_sec_t_0
decl_stmt|;
comment|/* physical sectors per track (LSB)   */
name|u_int8_t
name|bytes_s_1
decl_stmt|;
comment|/* bytes per sector (MSB)	      */
name|u_int8_t
name|bytes_s_0
decl_stmt|;
comment|/* bytes per sector (LSB)	      */
name|u_int8_t
name|interleave_1
decl_stmt|;
comment|/* interleave (MSB)		      */
name|u_int8_t
name|interleave_0
decl_stmt|;
comment|/* interleave (LSB)		      */
name|u_int8_t
name|trk_skew_1
decl_stmt|;
comment|/* track skew factor (MSB)	      */
name|u_int8_t
name|trk_skew_0
decl_stmt|;
comment|/* track skew factor (LSB)	      */
name|u_int8_t
name|cyl_skew_1
decl_stmt|;
comment|/* cylinder skew (MSB)		      */
name|u_int8_t
name|cyl_skew_0
decl_stmt|;
comment|/* cylinder skew (LSB)		      */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* various */
define|#
directive|define
name|DISK_FMT_SURF
value|0x10
define|#
directive|define
name|DISK_FMT_RMB
value|0x20
define|#
directive|define
name|DISK_FMT_HSEC
value|0x40
define|#
directive|define
name|DISK_FMT_SSEC
value|0x80
name|u_int8_t
name|reserved21
decl_stmt|;
name|u_int8_t
name|reserved22
decl_stmt|;
name|u_int8_t
name|reserved23
decl_stmt|;
block|}
name|format_device
struct|;
struct|struct
name|rigid_geometry_page
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (should be 4)	      */
define|#
directive|define
name|SMS_RIGID_GEOMETRY_PAGE
value|0x04
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length (should be 0x16)	      */
define|#
directive|define
name|SMS_RIGID_GEOMETRY_PLEN
value|0x16
name|u_int8_t
name|ncyl_2
decl_stmt|;
comment|/* number of cylinders (MSB)	      */
name|u_int8_t
name|ncyl_1
decl_stmt|;
comment|/* number of cylinders 		      */
name|u_int8_t
name|ncyl_0
decl_stmt|;
comment|/* number of cylinders (LSB)	      */
name|u_int8_t
name|nheads
decl_stmt|;
comment|/* number of heads 		      */
name|u_int8_t
name|st_cyl_wp_2
decl_stmt|;
comment|/* starting cyl., write precomp (MSB) */
name|u_int8_t
name|st_cyl_wp_1
decl_stmt|;
comment|/* starting cyl., write precomp	      */
name|u_int8_t
name|st_cyl_wp_0
decl_stmt|;
comment|/* starting cyl., write precomp (LSB) */
name|u_int8_t
name|st_cyl_rwc_2
decl_stmt|;
comment|/* starting cyl., red. write cur (MSB)*/
name|u_int8_t
name|st_cyl_rwc_1
decl_stmt|;
comment|/* starting cyl., red. write cur      */
name|u_int8_t
name|st_cyl_rwc_0
decl_stmt|;
comment|/* starting cyl., red. write cur (LSB)*/
name|u_int8_t
name|driv_step_1
decl_stmt|;
comment|/* drive step rate (MSB)	      */
name|u_int8_t
name|driv_step_0
decl_stmt|;
comment|/* drive step rate (LSB)	      */
name|u_int8_t
name|land_zone_2
decl_stmt|;
comment|/* landing zone cylinder (MSB)	      */
name|u_int8_t
name|land_zone_1
decl_stmt|;
comment|/* landing zone cylinder 	      */
name|u_int8_t
name|land_zone_0
decl_stmt|;
comment|/* landing zone cylinder (LSB)	      */
name|u_int8_t
name|rpl
decl_stmt|;
comment|/* rotational position locking (2 bits) */
name|u_int8_t
name|rot_offset
decl_stmt|;
comment|/* rotational offset */
name|u_int8_t
name|reserved19
decl_stmt|;
name|u_int8_t
name|medium_rot_rate_1
decl_stmt|;
comment|/* medium rotation rate (RPM) (MSB) */
name|u_int8_t
name|medium_rot_rate_0
decl_stmt|;
comment|/* medium rotation rate (RPM) (LSB) */
name|u_int8_t
name|reserved22
decl_stmt|;
name|u_int8_t
name|reserved23
decl_stmt|;
block|}
name|rigid_geometry
struct|;
struct|struct
name|flexible_disk_page
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (should be 5)	      */
define|#
directive|define
name|SMS_FLEXIBLE_GEOMETRY_PAGE
value|0x05
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length (should be 0x1E)	      */
define|#
directive|define
name|SMS_FLEXIBLE_GEOMETRY_PLEN
value|0x1E
name|u_int8_t
name|xfr_rate_1
decl_stmt|;
comment|/* transfer rate (MSB)		      */
name|u_int8_t
name|xfr_rate_0
decl_stmt|;
comment|/* transfer rate (LSB)		      */
name|u_int8_t
name|nheads
decl_stmt|;
comment|/* number of heads 		      */
name|u_int8_t
name|sec_per_track
decl_stmt|;
comment|/* Sectors per track		      */
name|u_int8_t
name|bytes_s_1
decl_stmt|;
comment|/* bytes per sector (MSB)	      */
name|u_int8_t
name|bytes_s_0
decl_stmt|;
comment|/* bytes per sector (LSB)	      */
name|u_int8_t
name|ncyl_1
decl_stmt|;
comment|/* number of cylinders (MSB)	      */
name|u_int8_t
name|ncyl_0
decl_stmt|;
comment|/* number of cylinders (LSB)	      */
name|u_int8_t
name|st_cyl_wp_1
decl_stmt|;
comment|/* starting cyl., write precomp (MSB) */
name|u_int8_t
name|st_cyl_wp_0
decl_stmt|;
comment|/* starting cyl., write precomp (LSB) */
name|u_int8_t
name|st_cyl_rwc_1
decl_stmt|;
comment|/* starting cyl., red. write cur (MSB)*/
name|u_int8_t
name|st_cyl_rwc_0
decl_stmt|;
comment|/* starting cyl., red. write cur (LSB)*/
name|u_int8_t
name|driv_step_1
decl_stmt|;
comment|/* drive step rate (MSB)	      */
name|u_int8_t
name|driv_step_0
decl_stmt|;
comment|/* drive step rate (LSB)	      */
name|u_int8_t
name|driv_step_pw
decl_stmt|;
comment|/* drive step pulse width	      */
name|u_int8_t
name|head_stl_del_1
decl_stmt|;
comment|/* Head settle delay (MSB)	      */
name|u_int8_t
name|head_stl_del_0
decl_stmt|;
comment|/* Head settle delay (LSB)	      */
name|u_int8_t
name|motor_on_del
decl_stmt|;
comment|/* Motor on delay		      */
name|u_int8_t
name|motor_off_del
decl_stmt|;
comment|/* Motor off delay		      */
name|u_int8_t
name|trdy_ssn_mo
decl_stmt|;
comment|/* XXX ??? */
name|u_int8_t
name|spc
decl_stmt|;
comment|/* XXX ??? */
name|u_int8_t
name|write_comp
decl_stmt|;
comment|/* Write compensation */
name|u_int8_t
name|head_load_del
decl_stmt|;
comment|/* Head load delay */
name|u_int8_t
name|head_uload_del
decl_stmt|;
comment|/* Head un-load delay */
name|u_int8_t
name|pin32_pin2
decl_stmt|;
name|u_int8_t
name|pin4_pint1
decl_stmt|;
name|u_int8_t
name|medium_rot_rate_1
decl_stmt|;
comment|/* medium rotation rate (RPM) (MSB) */
name|u_int8_t
name|medium_rot_rate_0
decl_stmt|;
comment|/* medium rotation rate (RPM) (LSB) */
name|u_int8_t
name|reserved30
decl_stmt|;
name|u_int8_t
name|reserved31
decl_stmt|;
block|}
name|flexible_disk
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|scsi_da_rw_recovery_page
block|{
name|u_int8_t
name|page_code
decl_stmt|;
define|#
directive|define
name|SMS_RW_ERROR_RECOVERY_PAGE
value|0x01
name|u_int8_t
name|page_length
decl_stmt|;
name|u_int8_t
name|byte3
decl_stmt|;
define|#
directive|define
name|SMS_RWER_AWRE
value|0x80
define|#
directive|define
name|SMS_RWER_ARRE
value|0x40
define|#
directive|define
name|SMS_RWER_TB
value|0x20
define|#
directive|define
name|SMS_RWER_RC
value|0x10
define|#
directive|define
name|SMS_RWER_EER
value|0x08
define|#
directive|define
name|SMS_RWER_PER
value|0x04
define|#
directive|define
name|SMS_RWER_DTE
value|0x02
define|#
directive|define
name|SMS_RWER_DCR
value|0x01
name|u_int8_t
name|read_retry_count
decl_stmt|;
name|u_int8_t
name|correction_span
decl_stmt|;
name|u_int8_t
name|head_offset_count
decl_stmt|;
name|u_int8_t
name|data_strobe_offset_cnt
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|write_retry_count
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|recovery_time_limit
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * XXX This is only left out of the kernel build to silence warnings.  If,  * for some reason this function is used in the kernel, the ifdefs should  * be moved so it is included both in the kernel and userland.  */
ifndef|#
directive|ifndef
name|_KERNEL
name|void
name|scsi_format_unit
parameter_list|(
name|struct
name|ccb_scsiio
modifier|*
name|csio
parameter_list|,
name|u_int32_t
name|retries
parameter_list|,
name|void
function_decl|(
modifier|*
name|cbfcnp
function_decl|)
parameter_list|(
name|struct
name|cam_periph
modifier|*
parameter_list|,
name|union
name|ccb
modifier|*
parameter_list|)
parameter_list|,
name|u_int8_t
name|tag_action
parameter_list|,
name|u_int8_t
name|byte2
parameter_list|,
name|u_int16_t
name|ileave
parameter_list|,
name|u_int8_t
modifier|*
name|data_ptr
parameter_list|,
name|u_int32_t
name|dxfer_len
parameter_list|,
name|u_int8_t
name|sense_len
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_SCSI_DA_H */
end_comment

end_unit

