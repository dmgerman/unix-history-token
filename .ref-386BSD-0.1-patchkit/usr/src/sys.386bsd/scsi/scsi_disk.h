begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * HISTORY  * $Log: scsi_disk.h,v $  * Revision 1.2  1992/10/13  03:14:21  julian  * added the load-eject field in 'start/stop' for removable devices.  *  * Revision 1.1  1992/09/26  22:11:29  julian  * Initial revision  *  *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         1       00098  * --------------------         -----   ----------------------  *  * 16 Feb 93	Julian Elischer		ADDED for SCSI system  *   */
end_comment

begin_comment
comment|/*  * SCSI interface description  */
end_comment

begin_comment
comment|/*  * Some lines of this file comes from a file of the name "scsi.h"  * distributed by OSF as part of mach2.5,  *  so the following disclaimer has been kept.  *  * Copyright 1990 by Open Software Foundation,  * Grenoble, FRANCE  *  * 		All Rights Reserved  *   *   Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both the copyright notice and this permission notice appear in  * supporting documentation, and that the name of OSF or Open Software  * Foundation not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission.  *   *   OSF DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS,  * IN NO EVENT SHALL OSF BE LIABLE FOR ANY SPECIAL, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT,  * NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Largely written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with   * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  */
end_comment

begin_comment
comment|/*  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  */
end_comment

begin_comment
comment|/*  * SCSI command format  */
end_comment

begin_struct
struct|struct
name|scsi_reassign_blocks
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
label|:
literal|5
expr_stmt|;
name|u_char
name|lun
range|:
literal|3
decl_stmt|;
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|link
range|:
literal|1
decl_stmt|;
name|u_char
name|flag
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_rw
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|addr_2
range|:
literal|5
decl_stmt|;
comment|/* Most significant */
name|u_char
name|lun
range|:
literal|3
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* least significant */
name|u_char
name|length
decl_stmt|;
name|u_char
name|link
range|:
literal|1
decl_stmt|;
name|u_char
name|flag
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_rw_big
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|rel_addr
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|4
expr_stmt|;
comment|/* Most significant */
name|u_char
name|lun
range|:
literal|3
decl_stmt|;
name|u_char
name|addr_3
decl_stmt|;
name|u_char
name|addr_2
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* least significant */
name|u_char
name|reserved
decl_stmt|;
empty_stmt|;
name|u_char
name|length2
decl_stmt|;
name|u_char
name|length1
decl_stmt|;
name|u_char
name|link
range|:
literal|1
decl_stmt|;
name|u_char
name|flag
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|4
expr_stmt|;
name|u_char
name|vendor
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_capacity
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
label|:
literal|5
expr_stmt|;
name|u_char
name|lun
range|:
literal|3
decl_stmt|;
name|u_char
name|addr_3
decl_stmt|;
comment|/* Most Significant */
name|u_char
name|addr_2
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* Least Significant */
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|link
range|:
literal|1
decl_stmt|;
name|u_char
name|flag
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_start_stop
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
label|:
literal|5
expr_stmt|;
name|u_char
name|lun
range|:
literal|3
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|start
range|:
literal|1
decl_stmt|;
name|u_char
name|loej
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
name|u_char
name|link
range|:
literal|1
decl_stmt|;
name|u_char
name|flag
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|READ_COMMAND
value|0x08
end_define

begin_define
define|#
directive|define
name|WRITE_COMMAND
value|0x0a
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
name|START_STOP
value|0x1b
end_define

begin_define
define|#
directive|define
name|PREVENT_ALLOW
value|0x1e
end_define

begin_define
define|#
directive|define
name|READ_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|READ_BIG
value|0x28
end_define

begin_define
define|#
directive|define
name|WRITE_BIG
value|0x2a
end_define

begin_struct
struct|struct
name|scsi_read_cap_data
block|{
name|u_char
name|addr_3
decl_stmt|;
comment|/* Most significant */
name|u_char
name|addr_2
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* Least significant */
name|u_char
name|length_3
decl_stmt|;
comment|/* Most significant */
name|u_char
name|length_2
decl_stmt|;
name|u_char
name|length_1
decl_stmt|;
name|u_char
name|length_0
decl_stmt|;
comment|/* Least significant */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_reassign_blocks_data
block|{
name|u_char
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|length_msb
decl_stmt|;
name|u_char
name|length_lsb
decl_stmt|;
struct|struct
block|{
name|u_char
name|dlbaddr_3
decl_stmt|;
comment|/* defect logical block address (MSB) */
name|u_char
name|dlbaddr_2
decl_stmt|;
name|u_char
name|dlbaddr_1
decl_stmt|;
name|u_char
name|dlbaddr_0
decl_stmt|;
comment|/* defect logical block address (LSB) */
block|}
name|defect_descriptor
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_union
union|union
name|disk_pages
comment|/* this is the structure copied from osf */
block|{
struct|struct
name|page_disk_format
block|{
name|u_char
name|pg_code
range|:
literal|6
decl_stmt|;
comment|/* page code (should be 3)	      */
name|u_char
label|:
literal|2
expr_stmt|;
name|u_char
name|pg_length
decl_stmt|;
comment|/* page length (should be 0x16)	      */
name|u_char
name|trk_z_1
decl_stmt|;
comment|/* tracks per zone (MSB)	      */
name|u_char
name|trk_z_0
decl_stmt|;
comment|/* tracks per zone (LSB)	      */
name|u_char
name|alt_sec_1
decl_stmt|;
comment|/* alternate sectors per zone (MSB)   */
name|u_char
name|alt_sec_0
decl_stmt|;
comment|/* alternate sectors per zone (LSB)   */
name|u_char
name|alt_trk_z_1
decl_stmt|;
comment|/* alternate tracks per zone (MSB)    */
name|u_char
name|alt_trk_z_0
decl_stmt|;
comment|/* alternate tracks per zone (LSB)    */
name|u_char
name|alt_trk_v_1
decl_stmt|;
comment|/* alternate tracks per volume (MSB)  */
name|u_char
name|alt_trk_v_0
decl_stmt|;
comment|/* alternate tracks per volume (LSB)  */
name|u_char
name|ph_sec_t_1
decl_stmt|;
comment|/* physical sectors per track (MSB)   */
name|u_char
name|ph_sec_t_0
decl_stmt|;
comment|/* physical sectors per track (LSB)   */
name|u_char
name|bytes_s_1
decl_stmt|;
comment|/* bytes per sector (MSB)	      */
name|u_char
name|bytes_s_0
decl_stmt|;
comment|/* bytes per sector (LSB)	      */
name|u_char
name|interleave_1
decl_stmt|;
comment|/* interleave (MSB)		      */
name|u_char
name|interleave_0
decl_stmt|;
comment|/* interleave (LSB)		      */
name|u_char
name|trk_skew_1
decl_stmt|;
comment|/* track skew factor (MSB)	      */
name|u_char
name|trk_skew_0
decl_stmt|;
comment|/* track skew factor (LSB)	      */
name|u_char
name|cyl_skew_1
decl_stmt|;
comment|/* cylinder skew (MSB)		      */
name|u_char
name|cyl_skew_0
decl_stmt|;
comment|/* cylinder skew (LSB)		      */
name|u_char
name|reserved1
range|:
literal|4
decl_stmt|;
name|u_char
name|surf
range|:
literal|1
decl_stmt|;
name|u_char
name|rmb
range|:
literal|1
decl_stmt|;
name|u_char
name|hsec
range|:
literal|1
decl_stmt|;
name|u_char
name|ssec
range|:
literal|1
decl_stmt|;
name|u_char
name|reserved2
decl_stmt|;
name|u_char
name|reserved3
decl_stmt|;
block|}
name|disk_format
struct|;
struct|struct
name|page_rigid_geometry
block|{
name|u_char
name|pg_code
range|:
literal|7
decl_stmt|;
comment|/* page code (should be 4)	      */
name|u_char
name|mbone
range|:
literal|1
decl_stmt|;
comment|/* must be one			      */
name|u_char
name|pg_length
decl_stmt|;
comment|/* page length (should be 0x16)	      */
name|u_char
name|ncyl_2
decl_stmt|;
comment|/* number of cylinders (MSB)	      */
name|u_char
name|ncyl_1
decl_stmt|;
comment|/* number of cylinders 		      */
name|u_char
name|ncyl_0
decl_stmt|;
comment|/* number of cylinders (LSB)	      */
name|u_char
name|nheads
decl_stmt|;
comment|/* number of heads 		      */
name|u_char
name|st_cyl_wp_2
decl_stmt|;
comment|/* starting cyl., write precomp (MSB) */
name|u_char
name|st_cyl_wp_1
decl_stmt|;
comment|/* starting cyl., write precomp	      */
name|u_char
name|st_cyl_wp_0
decl_stmt|;
comment|/* starting cyl., write precomp (LSB) */
name|u_char
name|st_cyl_rwc_2
decl_stmt|;
comment|/* starting cyl., red. write cur (MSB)*/
name|u_char
name|st_cyl_rwc_1
decl_stmt|;
comment|/* starting cyl., red. write cur      */
name|u_char
name|st_cyl_rwc_0
decl_stmt|;
comment|/* starting cyl., red. write cur (LSB)*/
name|u_char
name|driv_step_1
decl_stmt|;
comment|/* drive step rate (MSB)	      */
name|u_char
name|driv_step_0
decl_stmt|;
comment|/* drive step rate (LSB)	      */
name|u_char
name|land_zone_2
decl_stmt|;
comment|/* landing zone cylinder (MSB)	      */
name|u_char
name|land_zone_1
decl_stmt|;
comment|/* landing zone cylinder 	      */
name|u_char
name|land_zone_0
decl_stmt|;
comment|/* landing zone cylinder (LSB)	      */
name|u_char
name|reserved1
decl_stmt|;
name|u_char
name|reserved2
decl_stmt|;
name|u_char
name|reserved3
decl_stmt|;
block|}
name|rigid_geometry
struct|;
block|}
union|;
end_union

end_unit

