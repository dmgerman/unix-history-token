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
name|KERNEL
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
comment|/*  * Structure used to execute a MOVE MEDIUM command.  */
end_comment

begin_struct
struct|struct
name|changer_move
block|{
name|int
name|cm_fromtype
decl_stmt|;
comment|/* element type to move from */
name|int
name|cm_fromunit
decl_stmt|;
comment|/* logical unit of from element */
name|int
name|cm_totype
decl_stmt|;
comment|/* element type to move to */
name|int
name|cm_tounit
decl_stmt|;
comment|/* logical unit of to element */
name|int
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
name|int
name|ce_srctype
decl_stmt|;
comment|/* element type of source */
name|int
name|ce_srcunit
decl_stmt|;
comment|/* logical unit of source */
name|int
name|ce_fdsttype
decl_stmt|;
comment|/* element type of first destination */
name|int
name|ce_fdstunit
decl_stmt|;
comment|/* logical unit of first destination */
name|int
name|ce_sdsttype
decl_stmt|;
comment|/* element type of second destination */
name|int
name|ce_sdstunit
decl_stmt|;
comment|/* logical unit of second destination */
name|int
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
name|int
name|cp_type
decl_stmt|;
comment|/* element type */
name|int
name|cp_unit
decl_stmt|;
comment|/* logical unit of element */
name|int
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
name|int
name|cp_curpicker
decl_stmt|;
comment|/* current picker */
name|int
name|cp_npickers
decl_stmt|;
comment|/* number of pickers */
name|int
name|cp_nslots
decl_stmt|;
comment|/* number of slots */
name|int
name|cp_nportals
decl_stmt|;
comment|/* number of import/export portals */
name|int
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
name|changer_element_status
block|{
name|int
name|ces_type
decl_stmt|;
comment|/* element type */
name|u_int8_t
modifier|*
name|ces_data
decl_stmt|;
comment|/* pre-allocated data storage */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data returned by CHIOGSTATUS is an array of flags bytes.  * Not all flags have meaning for all element types.  */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_FULL
value|0x01
end_define

begin_comment
comment|/* element is full */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_IMPEXP
value|0x02
end_define

begin_comment
comment|/* media deposited by operator */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_EXCEPT
value|0x04
end_define

begin_comment
comment|/* element in abnormal state */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_ACCESS
value|0x08
end_define

begin_comment
comment|/* media accessible by picker */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_EXENAB
value|0x10
end_define

begin_comment
comment|/* element supports exporting */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_INENAB
value|0x20
end_define

begin_comment
comment|/* element supports importing */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_PICKER_MASK
value|0x05
end_define

begin_comment
comment|/* flags valid for pickers */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_SLOT_MASK
value|0x0c
end_define

begin_comment
comment|/* flags valid for slots */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_PORTAL_MASK
value|0x3f
end_define

begin_comment
comment|/* flags valid for portals */
end_comment

begin_define
define|#
directive|define
name|CESTATUS_DRIVE_MASK
value|0x0c
end_define

begin_comment
comment|/* flags valid for drives */
end_comment

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
name|CHIOGSTATUS
value|_IOW('c', 0x08, struct changer_element_status)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CHIO_H_ */
end_comment

end_unit

