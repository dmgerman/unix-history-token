begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 Jason R. Thorpe<thorpej@and.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgements:  *	This product includes software developed by Jason R. Thorpe  *	for And Communications, http://www.and.com/  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CHIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CHIO_H_
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
comment|/*  * Element types.  Used as "to" and "from" type indicators in move  * and exchange operations.  *  * Note that code in sys/scsi/ch.c relies on these values (uses them  * as offsets in an array, and other evil), so don't muck with them  * unless you know what you're doing.  */
end_comment

begin_define
define|#
directive|define
name|CHET_MT
value|0
end_define

begin_comment
comment|/* medium transport (picker) */
end_comment

begin_define
define|#
directive|define
name|CHET_ST
value|1
end_define

begin_comment
comment|/* storage transport (slot) */
end_comment

begin_define
define|#
directive|define
name|CHET_IE
value|2
end_define

begin_comment
comment|/* import/export (portal) */
end_comment

begin_define
define|#
directive|define
name|CHET_DT
value|3
end_define

begin_comment
comment|/* data transfer (drive) */
end_comment

begin_comment
comment|/*  * Maximum length of a volume identification string  */
end_comment

begin_define
define|#
directive|define
name|CH_VOLTAG_MAXLEN
value|32
end_define

begin_comment
comment|/*  * Structure used to execute a MOVE MEDIUM command.  */
end_comment

begin_struct
struct|struct
name|changer_move
block|{
name|u_int16_t
name|cm_fromtype
decl_stmt|;
comment|/* element type to move from */
name|u_int16_t
name|cm_fromunit
decl_stmt|;
comment|/* logical unit of from element */
name|u_int16_t
name|cm_totype
decl_stmt|;
comment|/* element type to move to */
name|u_int16_t
name|cm_tounit
decl_stmt|;
comment|/* logical unit of to element */
name|u_int16_t
name|cm_flags
decl_stmt|;
comment|/* misc. flags */
block|}
struct|;
end_struct

begin_comment
comment|/* cm_flags */
end_comment

begin_define
define|#
directive|define
name|CM_INVERT
value|0x01
end_define

begin_comment
comment|/* invert media */
end_comment

begin_comment
comment|/*  * Structure used to execute an EXCHANGE MEDIUM command.  In an  * exchange operation, the following steps occur:  *  *	- media from source is moved to first destination.  *  *	- media previously occupying first destination is moved  *	  to the second destination.  *  * The second destination may or may not be the same as the source.  * In the case of a simple exchange, the source and second destination  * are the same.  */
end_comment

begin_struct
struct|struct
name|changer_exchange
block|{
name|u_int16_t
name|ce_srctype
decl_stmt|;
comment|/* element type of source */
name|u_int16_t
name|ce_srcunit
decl_stmt|;
comment|/* logical unit of source */
name|u_int16_t
name|ce_fdsttype
decl_stmt|;
comment|/* element type of first destination */
name|u_int16_t
name|ce_fdstunit
decl_stmt|;
comment|/* logical unit of first destination */
name|u_int16_t
name|ce_sdsttype
decl_stmt|;
comment|/* element type of second destination */
name|u_int16_t
name|ce_sdstunit
decl_stmt|;
comment|/* logical unit of second destination */
name|u_int16_t
name|ce_flags
decl_stmt|;
comment|/* misc. flags */
block|}
struct|;
end_struct

begin_comment
comment|/* ce_flags */
end_comment

begin_define
define|#
directive|define
name|CE_INVERT1
value|0x01
end_define

begin_comment
comment|/* invert media 1 */
end_comment

begin_define
define|#
directive|define
name|CE_INVERT2
value|0x02
end_define

begin_comment
comment|/* invert media 2 */
end_comment

begin_comment
comment|/*  * Structure used to execute a POSITION TO ELEMENT command.  This  * moves the current picker in front of the specified element.  */
end_comment

begin_struct
struct|struct
name|changer_position
block|{
name|u_int16_t
name|cp_type
decl_stmt|;
comment|/* element type */
name|u_int16_t
name|cp_unit
decl_stmt|;
comment|/* logical unit of element */
name|u_int16_t
name|cp_flags
decl_stmt|;
comment|/* misc. flags */
block|}
struct|;
end_struct

begin_comment
comment|/* cp_flags */
end_comment

begin_define
define|#
directive|define
name|CP_INVERT
value|0x01
end_define

begin_comment
comment|/* invert picker */
end_comment

begin_comment
comment|/*  * Data returned by CHIOGPARAMS.  */
end_comment

begin_struct
struct|struct
name|changer_params
block|{
name|u_int16_t
name|cp_npickers
decl_stmt|;
comment|/* number of pickers */
name|u_int16_t
name|cp_nslots
decl_stmt|;
comment|/* number of slots */
name|u_int16_t
name|cp_nportals
decl_stmt|;
comment|/* number of import/export portals */
name|u_int16_t
name|cp_ndrives
decl_stmt|;
comment|/* number of drives */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command used to get element status.  */
end_comment

begin_struct
struct|struct
name|changer_voltag
block|{
name|u_char
name|cv_volid
index|[
name|CH_VOLTAG_MAXLEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_int16_t
name|cv_serial
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|changer_voltag
name|changer_voltag_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags definitions for ces_status  * Not all flags have meaning for all element types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CES_STATUS_FULL
init|=
literal|0x001
block|,
comment|/* element is full */
name|CES_STATUS_IMPEXP
init|=
literal|0x002
block|,
comment|/* media deposited by operator */
name|CES_STATUS_EXCEPT
init|=
literal|0x004
block|,
comment|/* element in abnormal state */
name|CES_PICKER_MASK
init|=
literal|0x005
block|,
comment|/* flags valid for pickers */
name|CES_STATUS_ACCESS
init|=
literal|0x008
block|,
comment|/* media accessible by picker */
name|CES_SLOT_MASK
init|=
literal|0x00c
block|,
comment|/* flags valid for slots */
name|CES_DRIVE_MASK
init|=
literal|0x00c
block|,
comment|/* flags valid for drives */
name|CES_STATUS_EXENAB
init|=
literal|0x010
block|,
comment|/* element supports exporting */
name|CES_STATUS_INENAB
init|=
literal|0x020
block|,
comment|/* element supports importing */
name|CES_PORTAL_MASK
init|=
literal|0x03f
block|,
comment|/* flags valid for portals */
name|CES_INVERT
init|=
literal|0x040
block|,
comment|/* invert bit */
name|CES_SOURCE_VALID
init|=
literal|0x080
block|,
comment|/* source address (ces_source) valid */
name|CES_SCSIID_VALID
init|=
literal|0x100
block|,
comment|/* ces_scsi_id is valid */
name|CES_LUN_VALID
init|=
literal|0x200
comment|/* ces_scsi_lun is valid */
block|}
name|ces_status_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|changer_element_status
block|{
name|u_int8_t
name|ces_type
decl_stmt|;
comment|/* element type */
name|u_int16_t
name|ces_addr
decl_stmt|;
comment|/* logical element address */
name|u_int16_t
name|ces_int_addr
decl_stmt|;
comment|/* changer element address */
name|ces_status_flags
name|ces_flags
decl_stmt|;
comment|/*  						   * see CESTATUS definitions 						   * below  						   */
name|u_int8_t
name|ces_sensecode
decl_stmt|;
comment|/*  						   * additional sense 						   * code for element */
name|u_int8_t
name|ces_sensequal
decl_stmt|;
comment|/* 						   * additional sense 						   * code qualifier  						   */
name|u_int8_t
name|ces_source_type
decl_stmt|;
comment|/*  						   * element type of 						   * source address  						   */
name|u_int16_t
name|ces_source_addr
decl_stmt|;
comment|/*  						   * source address of medium 						   */
name|changer_voltag_t
name|ces_pvoltag
decl_stmt|;
comment|/* primary volume tag */
name|changer_voltag_t
name|ces_avoltag
decl_stmt|;
comment|/* alternate volume tag */
name|u_int8_t
name|ces_scsi_id
decl_stmt|;
comment|/* SCSI id of element */
name|u_int8_t
name|ces_scsi_lun
decl_stmt|;
comment|/* SCSI lun of element */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|changer_element_status_request
block|{
name|u_int16_t
name|cesr_element_type
decl_stmt|;
name|u_int16_t
name|cesr_element_base
decl_stmt|;
name|u_int16_t
name|cesr_element_count
decl_stmt|;
name|u_int16_t
name|cesr_flags
decl_stmt|;
define|#
directive|define
name|CESR_VOLTAGS
value|0x01
name|struct
name|changer_element_status
modifier|*
name|cesr_element_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|changer_set_voltag_request
block|{
name|u_int16_t
name|csvr_type
decl_stmt|;
name|u_int16_t
name|csvr_addr
decl_stmt|;
name|u_int16_t
name|csvr_flags
decl_stmt|;
define|#
directive|define
name|CSVR_MODE_MASK
value|0x0f
comment|/* mode mask, acceptable modes below: */
define|#
directive|define
name|CSVR_MODE_SET
value|0x00
comment|/* set volume tag if not set */
define|#
directive|define
name|CSVR_MODE_REPLACE
value|0x01
comment|/* unconditionally replace volume tag */
define|#
directive|define
name|CSVR_MODE_CLEAR
value|0x02
comment|/* clear volume tag */
define|#
directive|define
name|CSVR_ALTERNATE
value|0x10
comment|/* set to work with alternate voltag */
name|changer_voltag_t
name|csvr_voltag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CESTATUS_BITS
define|\
value|"\20\6INEAB\5EXENAB\4ACCESS\3EXCEPT\2IMPEXP\1FULL"
end_define

begin_define
define|#
directive|define
name|CHIOMOVE
value|_IOW('c', 0x01, struct changer_move)
end_define

begin_define
define|#
directive|define
name|CHIOEXCHANGE
value|_IOW('c', 0x02, struct changer_exchange)
end_define

begin_define
define|#
directive|define
name|CHIOPOSITION
value|_IOW('c', 0x03, struct changer_position)
end_define

begin_define
define|#
directive|define
name|CHIOGPICKER
value|_IOR('c', 0x04, int)
end_define

begin_define
define|#
directive|define
name|CHIOSPICKER
value|_IOW('c', 0x05, int)
end_define

begin_define
define|#
directive|define
name|CHIOGPARAMS
value|_IOR('c', 0x06, struct changer_params)
end_define

begin_define
define|#
directive|define
name|CHIOIELEM
value|_IOW('c', 0x07, u_int32_t)
end_define

begin_define
define|#
directive|define
name|CHIOGSTATUS
value|_IOW('c', 0x08, struct changer_element_status_request)
end_define

begin_define
define|#
directive|define
name|CHIOSETVOLTAG
value|_IOW('c', 0x09, struct changer_set_voltag_request)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CHIO_H_ */
end_comment

end_unit

