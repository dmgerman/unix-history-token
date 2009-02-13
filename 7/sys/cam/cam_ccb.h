begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Data structures and definitions for CAM Control Blocks (CCBs).  *  * Copyright (c) 1997, 1998 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_CCB_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_CCB_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_comment
comment|/* General allocation length definitions for CCB structures */
end_comment

begin_define
define|#
directive|define
name|IOCDBLEN
value|CAM_MAX_CDBLEN
end_define

begin_comment
comment|/* Space for CDB bytes/pointer */
end_comment

begin_define
define|#
directive|define
name|VUHBALEN
value|14
end_define

begin_comment
comment|/* Vendor Unique HBA length */
end_comment

begin_define
define|#
directive|define
name|SIM_IDLEN
value|16
end_define

begin_comment
comment|/* ASCII string len for SIM ID */
end_comment

begin_define
define|#
directive|define
name|HBA_IDLEN
value|16
end_define

begin_comment
comment|/* ASCII string len for HBA ID */
end_comment

begin_define
define|#
directive|define
name|DEV_IDLEN
value|16
end_define

begin_comment
comment|/* ASCII string len for device names */
end_comment

begin_define
define|#
directive|define
name|CCB_PERIPH_PRIV_SIZE
value|2
end_define

begin_comment
comment|/* size of peripheral private area */
end_comment

begin_define
define|#
directive|define
name|CCB_SIM_PRIV_SIZE
value|2
end_define

begin_comment
comment|/* size of sim private area */
end_comment

begin_comment
comment|/* Struct definitions for CAM control blocks */
end_comment

begin_comment
comment|/* Common CCB header */
end_comment

begin_comment
comment|/* CAM CCB flags */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_CDB_POINTER
init|=
literal|0x00000001
block|,
comment|/* The CDB field is a pointer    */
name|CAM_QUEUE_ENABLE
init|=
literal|0x00000002
block|,
comment|/* SIM queue actions are enabled */
name|CAM_CDB_LINKED
init|=
literal|0x00000004
block|,
comment|/* CCB contains a linked CDB     */
name|CAM_NEGOTIATE
init|=
literal|0x00000008
block|,
comment|/* 					      * Perform transport negotiation 					      * with this command. 					      */
name|CAM_SCATTER_VALID
init|=
literal|0x00000010
block|,
comment|/* Scatter/gather list is valid  */
name|CAM_DIS_AUTOSENSE
init|=
literal|0x00000020
block|,
comment|/* Disable autosense feature     */
name|CAM_DIR_RESV
init|=
literal|0x00000000
block|,
comment|/* Data direction (00:reserved)  */
name|CAM_DIR_IN
init|=
literal|0x00000040
block|,
comment|/* Data direction (01:DATA IN)   */
name|CAM_DIR_OUT
init|=
literal|0x00000080
block|,
comment|/* Data direction (10:DATA OUT)  */
name|CAM_DIR_NONE
init|=
literal|0x000000C0
block|,
comment|/* Data direction (11:no data)   */
name|CAM_DIR_MASK
init|=
literal|0x000000C0
block|,
comment|/* Data direction Mask	      */
name|CAM_SOFT_RST_OP
init|=
literal|0x00000100
block|,
comment|/* Use Soft reset alternative    */
name|CAM_ENG_SYNC
init|=
literal|0x00000200
block|,
comment|/* Flush resid bytes on complete */
name|CAM_DEV_QFRZDIS
init|=
literal|0x00000400
block|,
comment|/* Disable DEV Q freezing	      */
name|CAM_DEV_QFREEZE
init|=
literal|0x00000800
block|,
comment|/* Freeze DEV Q on execution     */
name|CAM_HIGH_POWER
init|=
literal|0x00001000
block|,
comment|/* Command takes a lot of power  */
name|CAM_SENSE_PTR
init|=
literal|0x00002000
block|,
comment|/* Sense data is a pointer	      */
name|CAM_SENSE_PHYS
init|=
literal|0x00004000
block|,
comment|/* Sense pointer is physical addr*/
name|CAM_TAG_ACTION_VALID
init|=
literal|0x00008000
block|,
comment|/* Use the tag action in this ccb*/
name|CAM_PASS_ERR_RECOVER
init|=
literal|0x00010000
block|,
comment|/* Pass driver does err. recovery*/
name|CAM_DIS_DISCONNECT
init|=
literal|0x00020000
block|,
comment|/* Disable disconnect	      */
name|CAM_SG_LIST_PHYS
init|=
literal|0x00040000
block|,
comment|/* SG list has physical addrs.   */
name|CAM_MSG_BUF_PHYS
init|=
literal|0x00080000
block|,
comment|/* Message buffer ptr is physical*/
name|CAM_SNS_BUF_PHYS
init|=
literal|0x00100000
block|,
comment|/* Autosense data ptr is physical*/
name|CAM_DATA_PHYS
init|=
literal|0x00200000
block|,
comment|/* SG/Buffer data ptrs are phys. */
name|CAM_CDB_PHYS
init|=
literal|0x00400000
block|,
comment|/* CDB poiner is physical	      */
name|CAM_ENG_SGLIST
init|=
literal|0x00800000
block|,
comment|/* SG list is for the HBA engine */
comment|/* Phase cognizant mode flags */
name|CAM_DIS_AUTOSRP
init|=
literal|0x01000000
block|,
comment|/* Disable autosave/restore ptrs */
name|CAM_DIS_AUTODISC
init|=
literal|0x02000000
block|,
comment|/* Disable auto disconnect	      */
name|CAM_TGT_CCB_AVAIL
init|=
literal|0x04000000
block|,
comment|/* Target CCB available	      */
name|CAM_TGT_PHASE_MODE
init|=
literal|0x08000000
block|,
comment|/* The SIM runs in phase mode    */
name|CAM_MSGB_VALID
init|=
literal|0x10000000
block|,
comment|/* Message buffer valid	      */
name|CAM_STATUS_VALID
init|=
literal|0x20000000
block|,
comment|/* Status buffer valid	      */
name|CAM_DATAB_VALID
init|=
literal|0x40000000
block|,
comment|/* Data buffer valid	      */
comment|/* Host target Mode flags */
name|CAM_SEND_SENSE
init|=
literal|0x08000000
block|,
comment|/* Send sense data with status   */
name|CAM_TERM_IO
init|=
literal|0x10000000
block|,
comment|/* Terminate I/O Message sup.    */
name|CAM_DISCONNECT
init|=
literal|0x20000000
block|,
comment|/* Disconnects are mandatory     */
name|CAM_SEND_STATUS
init|=
literal|0x40000000
comment|/* Send status after data phase  */
block|}
name|ccb_flags
typedef|;
end_typedef

begin_comment
comment|/* XPT Opcodes for xpt_action */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Function code flags are bits greater than 0xff */
name|XPT_FC_QUEUED
init|=
literal|0x100
block|,
comment|/* Non-immediate function code */
name|XPT_FC_USER_CCB
init|=
literal|0x200
block|,
name|XPT_FC_XPT_ONLY
init|=
literal|0x400
block|,
comment|/* Only for the transport layer device */
name|XPT_FC_DEV_QUEUED
init|=
literal|0x800
operator||
name|XPT_FC_QUEUED
block|,
comment|/* Passes through the device queues */
comment|/* Common function commands: 0x00->0x0F */
name|XPT_NOOP
init|=
literal|0x00
block|,
comment|/* Execute Nothing */
name|XPT_SCSI_IO
init|=
literal|0x01
operator||
name|XPT_FC_DEV_QUEUED
block|,
comment|/* Execute the requested I/O operation */
name|XPT_GDEV_TYPE
init|=
literal|0x02
block|,
comment|/* Get type information for specified device */
name|XPT_GDEVLIST
init|=
literal|0x03
block|,
comment|/* Get a list of peripheral devices */
name|XPT_PATH_INQ
init|=
literal|0x04
block|,
comment|/* Path routing inquiry */
name|XPT_REL_SIMQ
init|=
literal|0x05
block|,
comment|/* Release a frozen SIM queue */
name|XPT_SASYNC_CB
init|=
literal|0x06
block|,
comment|/* Set Asynchronous Callback Parameters */
name|XPT_SDEV_TYPE
init|=
literal|0x07
block|,
comment|/* Set device type information */
name|XPT_SCAN_BUS
init|=
literal|0x08
operator||
name|XPT_FC_QUEUED
operator||
name|XPT_FC_USER_CCB
operator||
name|XPT_FC_XPT_ONLY
block|,
comment|/* (Re)Scan the SCSI Bus */
name|XPT_DEV_MATCH
init|=
literal|0x09
operator||
name|XPT_FC_XPT_ONLY
block|,
comment|/* Get EDT entries matching the given pattern */
name|XPT_DEBUG
init|=
literal|0x0a
block|,
comment|/* Turn on debugging for a bus, target or lun */
name|XPT_PATH_STATS
init|=
literal|0x0b
block|,
comment|/* Path statistics (error counts, etc.) */
name|XPT_GDEV_STATS
init|=
literal|0x0c
block|,
comment|/* Device statistics (error counts, etc.) */
comment|/* SCSI Control Functions: 0x10->0x1F */
name|XPT_ABORT
init|=
literal|0x10
block|,
comment|/* Abort the specified CCB */
name|XPT_RESET_BUS
init|=
literal|0x11
operator||
name|XPT_FC_XPT_ONLY
block|,
comment|/* Reset the specified SCSI bus */
name|XPT_RESET_DEV
init|=
literal|0x12
operator||
name|XPT_FC_DEV_QUEUED
block|,
comment|/* Bus Device Reset the specified SCSI device */
name|XPT_TERM_IO
init|=
literal|0x13
block|,
comment|/* Terminate the I/O process */
name|XPT_SCAN_LUN
init|=
literal|0x14
operator||
name|XPT_FC_QUEUED
operator||
name|XPT_FC_USER_CCB
operator||
name|XPT_FC_XPT_ONLY
block|,
comment|/* Scan Logical Unit */
name|XPT_GET_TRAN_SETTINGS
init|=
literal|0x15
block|,
comment|/* 				 * Get default/user transfer settings 				 * for the target 				 */
name|XPT_SET_TRAN_SETTINGS
init|=
literal|0x16
block|,
comment|/* 				 * Set transfer rate/width 				 * negotiation settings 				 */
name|XPT_CALC_GEOMETRY
init|=
literal|0x17
block|,
comment|/* 				 * Calculate the geometry parameters for 				 * a device give the sector size and 				 * volume size. 				 */
comment|/* HBA engine commands 0x20->0x2F */
name|XPT_ENG_INQ
init|=
literal|0x20
operator||
name|XPT_FC_XPT_ONLY
block|,
comment|/* HBA engine feature inquiry */
name|XPT_ENG_EXEC
init|=
literal|0x21
operator||
name|XPT_FC_DEV_QUEUED
block|,
comment|/* HBA execute engine request */
comment|/* Target mode commands: 0x30->0x3F */
name|XPT_EN_LUN
init|=
literal|0x30
block|,
comment|/* Enable LUN as a target */
name|XPT_TARGET_IO
init|=
literal|0x31
operator||
name|XPT_FC_DEV_QUEUED
block|,
comment|/* Execute target I/O request */
name|XPT_ACCEPT_TARGET_IO
init|=
literal|0x32
operator||
name|XPT_FC_QUEUED
operator||
name|XPT_FC_USER_CCB
block|,
comment|/* Accept Host Target Mode CDB */
name|XPT_CONT_TARGET_IO
init|=
literal|0x33
operator||
name|XPT_FC_DEV_QUEUED
block|,
comment|/* Continue Host Target I/O Connection */
name|XPT_IMMED_NOTIFY
init|=
literal|0x34
operator||
name|XPT_FC_QUEUED
operator||
name|XPT_FC_USER_CCB
block|,
comment|/* Notify Host Target driver of event */
name|XPT_NOTIFY_ACK
init|=
literal|0x35
block|,
comment|/* Acknowledgement of event */
comment|/* Vendor Unique codes: 0x80->0x8F */
name|XPT_VUNIQUE
init|=
literal|0x80
block|}
name|xpt_opcode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XPT_FC_GROUP_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP
parameter_list|(
name|op
parameter_list|)
value|((op)& XPT_FC_GROUP_MASK)
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP_COMMON
value|0x00
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP_SCSI_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP_HBA_ENGINE
value|0x20
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP_TMODE
value|0x30
end_define

begin_define
define|#
directive|define
name|XPT_FC_GROUP_VENDOR_UNIQUE
value|0x80
end_define

begin_define
define|#
directive|define
name|XPT_FC_IS_DEV_QUEUED
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.func_code& XPT_FC_DEV_QUEUED) == XPT_FC_DEV_QUEUED)
end_define

begin_define
define|#
directive|define
name|XPT_FC_IS_QUEUED
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.func_code& XPT_FC_QUEUED) != 0)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PROTO_UNKNOWN
block|,
name|PROTO_UNSPECIFIED
block|,
name|PROTO_SCSI
block|,
comment|/* Small Computer System Interface */
name|PROTO_ATA
block|,
comment|/* AT Attachment */
name|PROTO_ATAPI
block|,
comment|/* AT Attachment Packetized Interface */
block|}
name|cam_proto
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XPORT_UNKNOWN
block|,
name|XPORT_UNSPECIFIED
block|,
name|XPORT_SPI
block|,
comment|/* SCSI Parallel Interface */
name|XPORT_FC
block|,
comment|/* Fiber Channel */
name|XPORT_SSA
block|,
comment|/* Serial Storage Architecture */
name|XPORT_USB
block|,
comment|/* Universal Serial Bus */
name|XPORT_PPB
block|,
comment|/* Parallel Port Bus */
name|XPORT_ATA
block|,
comment|/* AT Attachment */
name|XPORT_SAS
block|,
comment|/* Serial Attached SCSI */
block|}
name|cam_xport
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROTO_VERSION_UNKNOWN
value|(UINT_MAX - 1)
end_define

begin_define
define|#
directive|define
name|PROTO_VERSION_UNSPECIFIED
value|UINT_MAX
end_define

begin_define
define|#
directive|define
name|XPORT_VERSION_UNKNOWN
value|(UINT_MAX - 1)
end_define

begin_define
define|#
directive|define
name|XPORT_VERSION_UNSPECIFIED
value|UINT_MAX
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|LIST_ENTRY
argument_list|(
argument|ccb_hdr
argument_list|)
name|le
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ccb_hdr
argument_list|)
name|sle
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ccb_hdr
argument_list|)
name|tqe
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|ccb_hdr
argument_list|)
name|stqe
expr_stmt|;
block|}
name|camq_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|u_long
name|field
decl_stmt|;
name|u_int8_t
name|bytes
index|[
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
index|]
decl_stmt|;
block|}
name|ccb_priv_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ccb_priv_entry
name|entries
index|[
name|CCB_PERIPH_PRIV_SIZE
index|]
decl_stmt|;
name|u_int8_t
name|bytes
index|[
name|CCB_PERIPH_PRIV_SIZE
operator|*
sizeof|sizeof
argument_list|(
name|ccb_priv_entry
argument_list|)
index|]
decl_stmt|;
block|}
name|ccb_ppriv_area
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ccb_priv_entry
name|entries
index|[
name|CCB_SIM_PRIV_SIZE
index|]
decl_stmt|;
name|u_int8_t
name|bytes
index|[
name|CCB_SIM_PRIV_SIZE
operator|*
sizeof|sizeof
argument_list|(
name|ccb_priv_entry
argument_list|)
index|]
decl_stmt|;
block|}
name|ccb_spriv_area
typedef|;
end_typedef

begin_struct
struct|struct
name|ccb_hdr
block|{
name|cam_pinfo
name|pinfo
decl_stmt|;
comment|/* Info for priority scheduling */
name|camq_entry
name|xpt_links
decl_stmt|;
comment|/* For chaining in the XPT layer */
name|camq_entry
name|sim_links
decl_stmt|;
comment|/* For chaining in the SIM layer */
name|camq_entry
name|periph_links
decl_stmt|;
comment|/* For chaining in the type driver */
name|u_int32_t
name|retry_count
decl_stmt|;
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
function_decl|;
comment|/* Callback on completion function */
name|xpt_opcode
name|func_code
decl_stmt|;
comment|/* XPT function code */
name|u_int32_t
name|status
decl_stmt|;
comment|/* Status returned by CAM subsystem */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* Compiled path for this ccb */
name|path_id_t
name|path_id
decl_stmt|;
comment|/* Path ID for the request */
name|target_id_t
name|target_id
decl_stmt|;
comment|/* Target device ID */
name|lun_id_t
name|target_lun
decl_stmt|;
comment|/* Target LUN number */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* ccb_flags */
name|ccb_ppriv_area
name|periph_priv
decl_stmt|;
name|ccb_spriv_area
name|sim_priv
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
comment|/* Timeout value */
comment|/* 	 * Deprecated, only for use by non-MPSAFE SIMs.  All others must 	 * allocate and initialize their own callout storage. 	 */
name|struct
name|callout_handle
name|timeout_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Get Device Information CCB */
end_comment

begin_struct
struct|struct
name|ccb_getdev
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|struct
name|scsi_inquiry_data
name|inq_data
decl_stmt|;
name|u_int8_t
name|serial_num
index|[
literal|252
index|]
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|serial_num_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Device Statistics CCB */
end_comment

begin_struct
struct|struct
name|ccb_getdevstats
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|int
name|dev_openings
decl_stmt|;
comment|/* Space left for more work on device*/
name|int
name|dev_active
decl_stmt|;
comment|/* Transactions running on the device */
name|int
name|devq_openings
decl_stmt|;
comment|/* Space left for more queued work */
name|int
name|devq_queued
decl_stmt|;
comment|/* Transactions queued to be sent */
name|int
name|held
decl_stmt|;
comment|/* 				 * CCBs held by peripheral drivers 				 * for this device 				 */
name|int
name|maxtags
decl_stmt|;
comment|/* 				 * Boundary conditions for number of 				 * tagged operations 				 */
name|int
name|mintags
decl_stmt|;
name|struct
name|timeval
name|last_reset
decl_stmt|;
comment|/* Time of last bus reset/loop init */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_GDEVLIST_LAST_DEVICE
block|,
name|CAM_GDEVLIST_LIST_CHANGED
block|,
name|CAM_GDEVLIST_MORE_DEVS
block|,
name|CAM_GDEVLIST_ERROR
block|}
name|ccb_getdevlist_status_e
typedef|;
end_typedef

begin_struct
struct|struct
name|ccb_getdevlist
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|char
name|periph_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|unsigned
name|int
name|generation
decl_stmt|;
name|u_int32_t
name|index
decl_stmt|;
name|ccb_getdevlist_status_e
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|PERIPH_MATCH_NONE
init|=
literal|0x000
block|,
name|PERIPH_MATCH_PATH
init|=
literal|0x001
block|,
name|PERIPH_MATCH_TARGET
init|=
literal|0x002
block|,
name|PERIPH_MATCH_LUN
init|=
literal|0x004
block|,
name|PERIPH_MATCH_NAME
init|=
literal|0x008
block|,
name|PERIPH_MATCH_UNIT
init|=
literal|0x010
block|,
name|PERIPH_MATCH_ANY
init|=
literal|0x01f
block|}
name|periph_pattern_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|periph_match_pattern
block|{
name|char
name|periph_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|lun_id_t
name|target_lun
decl_stmt|;
name|periph_pattern_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEV_MATCH_NONE
init|=
literal|0x000
block|,
name|DEV_MATCH_PATH
init|=
literal|0x001
block|,
name|DEV_MATCH_TARGET
init|=
literal|0x002
block|,
name|DEV_MATCH_LUN
init|=
literal|0x004
block|,
name|DEV_MATCH_INQUIRY
init|=
literal|0x008
block|,
name|DEV_MATCH_ANY
init|=
literal|0x00f
block|}
name|dev_pattern_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|device_match_pattern
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|lun_id_t
name|target_lun
decl_stmt|;
name|struct
name|scsi_static_inquiry_pattern
name|inq_pat
decl_stmt|;
name|dev_pattern_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|BUS_MATCH_NONE
init|=
literal|0x000
block|,
name|BUS_MATCH_PATH
init|=
literal|0x001
block|,
name|BUS_MATCH_NAME
init|=
literal|0x002
block|,
name|BUS_MATCH_UNIT
init|=
literal|0x004
block|,
name|BUS_MATCH_BUS_ID
init|=
literal|0x008
block|,
name|BUS_MATCH_ANY
init|=
literal|0x00f
block|}
name|bus_pattern_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|bus_match_pattern
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|char
name|dev_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|u_int32_t
name|bus_id
decl_stmt|;
name|bus_pattern_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|match_pattern
block|{
name|struct
name|periph_match_pattern
name|periph_pattern
decl_stmt|;
name|struct
name|device_match_pattern
name|device_pattern
decl_stmt|;
name|struct
name|bus_match_pattern
name|bus_pattern
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEV_MATCH_PERIPH
block|,
name|DEV_MATCH_DEVICE
block|,
name|DEV_MATCH_BUS
block|}
name|dev_match_type
typedef|;
end_typedef

begin_struct
struct|struct
name|dev_match_pattern
block|{
name|dev_match_type
name|type
decl_stmt|;
name|union
name|match_pattern
name|pattern
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|periph_match_result
block|{
name|char
name|periph_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|lun_id_t
name|target_lun
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEV_RESULT_NOFLAG
init|=
literal|0x00
block|,
name|DEV_RESULT_UNCONFIGURED
init|=
literal|0x01
block|}
name|dev_result_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|device_match_result
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|lun_id_t
name|target_lun
decl_stmt|;
name|struct
name|scsi_inquiry_data
name|inq_data
decl_stmt|;
name|dev_result_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bus_match_result
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|char
name|dev_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|u_int32_t
name|bus_id
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|match_result
block|{
name|struct
name|periph_match_result
name|periph_result
decl_stmt|;
name|struct
name|device_match_result
name|device_result
decl_stmt|;
name|struct
name|bus_match_result
name|bus_result
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|dev_match_result
block|{
name|dev_match_type
name|type
decl_stmt|;
name|union
name|match_result
name|result
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_DEV_MATCH_LAST
block|,
name|CAM_DEV_MATCH_MORE
block|,
name|CAM_DEV_MATCH_LIST_CHANGED
block|,
name|CAM_DEV_MATCH_SIZE_ERROR
block|,
name|CAM_DEV_MATCH_ERROR
block|}
name|ccb_dev_match_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_DEV_POS_NONE
init|=
literal|0x000
block|,
name|CAM_DEV_POS_BUS
init|=
literal|0x001
block|,
name|CAM_DEV_POS_TARGET
init|=
literal|0x002
block|,
name|CAM_DEV_POS_DEVICE
init|=
literal|0x004
block|,
name|CAM_DEV_POS_PERIPH
init|=
literal|0x008
block|,
name|CAM_DEV_POS_PDPTR
init|=
literal|0x010
block|,
name|CAM_DEV_POS_TYPEMASK
init|=
literal|0xf00
block|,
name|CAM_DEV_POS_EDT
init|=
literal|0x100
block|,
name|CAM_DEV_POS_PDRV
init|=
literal|0x200
block|}
name|dev_pos_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ccb_dm_cookie
block|{
name|void
modifier|*
name|bus
decl_stmt|;
name|void
modifier|*
name|target
decl_stmt|;
name|void
modifier|*
name|device
decl_stmt|;
name|void
modifier|*
name|periph
decl_stmt|;
name|void
modifier|*
name|pdrv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_dev_position
block|{
name|u_int
name|generations
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|CAM_BUS_GENERATION
value|0x00
define|#
directive|define
name|CAM_TARGET_GENERATION
value|0x01
define|#
directive|define
name|CAM_DEV_GENERATION
value|0x02
define|#
directive|define
name|CAM_PERIPH_GENERATION
value|0x03
name|dev_pos_type
name|position_type
decl_stmt|;
name|struct
name|ccb_dm_cookie
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_dev_match
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|ccb_dev_match_status
name|status
decl_stmt|;
name|u_int32_t
name|num_patterns
decl_stmt|;
name|u_int32_t
name|pattern_buf_len
decl_stmt|;
name|struct
name|dev_match_pattern
modifier|*
name|patterns
decl_stmt|;
name|u_int32_t
name|num_matches
decl_stmt|;
name|u_int32_t
name|match_buf_len
decl_stmt|;
name|struct
name|dev_match_result
modifier|*
name|matches
decl_stmt|;
name|struct
name|ccb_dev_position
name|pos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the path inquiry CCB fields.  */
end_comment

begin_define
define|#
directive|define
name|CAM_VERSION
value|0x15
end_define

begin_comment
comment|/* Hex value for current version */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PI_MDP_ABLE
init|=
literal|0x80
block|,
comment|/* Supports MDP message */
name|PI_WIDE_32
init|=
literal|0x40
block|,
comment|/* Supports 32 bit wide SCSI */
name|PI_WIDE_16
init|=
literal|0x20
block|,
comment|/* Supports 16 bit wide SCSI */
name|PI_SDTR_ABLE
init|=
literal|0x10
block|,
comment|/* Supports SDTR message */
name|PI_LINKED_CDB
init|=
literal|0x08
block|,
comment|/* Supports linked CDBs */
name|PI_TAG_ABLE
init|=
literal|0x02
block|,
comment|/* Supports tag queue messages */
name|PI_SOFT_RST
init|=
literal|0x01
comment|/* Supports soft reset alternative */
block|}
name|pi_inqflag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PIT_PROCESSOR
init|=
literal|0x80
block|,
comment|/* Target mode processor mode */
name|PIT_PHASE
init|=
literal|0x40
block|,
comment|/* Target mode phase cog. mode */
name|PIT_DISCONNECT
init|=
literal|0x20
block|,
comment|/* Disconnects supported in target mode */
name|PIT_TERM_IO
init|=
literal|0x10
block|,
comment|/* Terminate I/O message supported in TM */
name|PIT_GRP_6
init|=
literal|0x08
block|,
comment|/* Group 6 commands supported */
name|PIT_GRP_7
init|=
literal|0x04
comment|/* Group 7 commands supported */
block|}
name|pi_tmflag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PIM_SCANHILO
init|=
literal|0x80
block|,
comment|/* Bus scans from high ID to low ID */
name|PIM_NOREMOVE
init|=
literal|0x40
block|,
comment|/* Removeable devices not included in scan */
name|PIM_NOINITIATOR
init|=
literal|0x20
block|,
comment|/* Initiator role not supported. */
name|PIM_NOBUSRESET
init|=
literal|0x10
block|,
comment|/* User has disabled initial BUS RESET */
name|PIM_NO_6_BYTE
init|=
literal|0x08
block|,
comment|/* Do not send 6-byte commands */
name|PIM_SEQSCAN
init|=
literal|0x04
comment|/* Do bus scans sequentially, not in parallel */
block|}
name|pi_miscflag
typedef|;
end_typedef

begin_comment
comment|/* Path Inquiry CCB */
end_comment

begin_struct
struct|struct
name|ccb_pathinq_settings_spi
block|{
name|u_int8_t
name|ppr_options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_pathinq_settings_fc
block|{
name|u_int64_t
name|wwnn
decl_stmt|;
comment|/* world wide node name */
name|u_int64_t
name|wwpn
decl_stmt|;
comment|/* world wide port name */
name|u_int32_t
name|port
decl_stmt|;
comment|/* 24 bit port id, if known */
name|u_int32_t
name|bitrate
decl_stmt|;
comment|/* Mbps */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_pathinq_settings_sas
block|{
name|u_int32_t
name|bitrate
decl_stmt|;
comment|/* Mbps */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PATHINQ_SETTINGS_SIZE
value|128
end_define

begin_struct
struct|struct
name|ccb_pathinq
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int8_t
name|version_num
decl_stmt|;
comment|/* Version number for the SIM/HBA */
name|u_int8_t
name|hba_inquiry
decl_stmt|;
comment|/* Mimic of INQ byte 7 for the HBA */
name|u_int8_t
name|target_sprt
decl_stmt|;
comment|/* Flags for target mode support */
name|u_int8_t
name|hba_misc
decl_stmt|;
comment|/* Misc HBA features */
name|u_int16_t
name|hba_eng_cnt
decl_stmt|;
comment|/* HBA engine count */
comment|/* Vendor Unique capabilities */
name|u_int8_t
name|vuhba_flags
index|[
name|VUHBALEN
index|]
decl_stmt|;
name|u_int32_t
name|max_target
decl_stmt|;
comment|/* Maximum supported Target */
name|u_int32_t
name|max_lun
decl_stmt|;
comment|/* Maximum supported Lun */
name|u_int32_t
name|async_flags
decl_stmt|;
comment|/* Installed Async handlers */
name|path_id_t
name|hpath_id
decl_stmt|;
comment|/* Highest Path ID in the subsystem */
name|target_id_t
name|initiator_id
decl_stmt|;
comment|/* ID of the HBA on the SCSI bus */
name|char
name|sim_vid
index|[
name|SIM_IDLEN
index|]
decl_stmt|;
comment|/* Vendor ID of the SIM */
name|char
name|hba_vid
index|[
name|HBA_IDLEN
index|]
decl_stmt|;
comment|/* Vendor ID of the HBA */
name|char
name|dev_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
comment|/* Device name for SIM */
name|u_int32_t
name|unit_number
decl_stmt|;
comment|/* Unit number for SIM */
name|u_int32_t
name|bus_id
decl_stmt|;
comment|/* Bus ID for SIM */
name|u_int32_t
name|base_transfer_speed
decl_stmt|;
comment|/* Base bus speed in KB/sec */
name|cam_proto
name|protocol
decl_stmt|;
name|u_int
name|protocol_version
decl_stmt|;
name|cam_xport
name|transport
decl_stmt|;
name|u_int
name|transport_version
decl_stmt|;
union|union
block|{
name|struct
name|ccb_pathinq_settings_spi
name|spi
decl_stmt|;
name|struct
name|ccb_pathinq_settings_fc
name|fc
decl_stmt|;
name|struct
name|ccb_pathinq_settings_sas
name|sas
decl_stmt|;
name|char
name|ccb_pathinq_settings_opaque
index|[
name|PATHINQ_SETTINGS_SIZE
index|]
decl_stmt|;
block|}
name|xport_specific
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Path Statistics CCB */
end_comment

begin_struct
struct|struct
name|ccb_pathstats
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|struct
name|timeval
name|last_reset
decl_stmt|;
comment|/* Time of last bus reset/loop init */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
block|{
name|u_int8_t
modifier|*
name|sense_ptr
decl_stmt|;
comment|/* 					 * Pointer to storage 					 * for sense information 					 */
comment|/* Storage Area for sense information */
name|struct
name|scsi_sense_data
name|sense_buf
decl_stmt|;
block|}
name|sense_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|u_int8_t
modifier|*
name|cdb_ptr
decl_stmt|;
comment|/* Pointer to the CDB bytes to send */
comment|/* Area for the CDB send */
name|u_int8_t
name|cdb_bytes
index|[
name|IOCDBLEN
index|]
decl_stmt|;
block|}
name|cdb_t
typedef|;
end_typedef

begin_comment
comment|/*  * SCSI I/O Request CCB used for the XPT_SCSI_IO and XPT_CONT_TARGET_IO  * function codes.  */
end_comment

begin_struct
struct|struct
name|ccb_scsiio
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|union
name|ccb
modifier|*
name|next_ccb
decl_stmt|;
comment|/* Ptr for next CCB for action */
name|u_int8_t
modifier|*
name|req_map
decl_stmt|;
comment|/* Ptr to mapping info */
name|u_int8_t
modifier|*
name|data_ptr
decl_stmt|;
comment|/* Ptr to the data buf/SG list */
name|u_int32_t
name|dxfer_len
decl_stmt|;
comment|/* Data transfer length */
comment|/* Autosense storage */
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* Number of bytes to autosense */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* Number of bytes for the CDB */
name|u_int16_t
name|sglist_cnt
decl_stmt|;
comment|/* Number of SG list entries */
name|u_int8_t
name|scsi_status
decl_stmt|;
comment|/* Returned SCSI status */
name|u_int8_t
name|sense_resid
decl_stmt|;
comment|/* Autosense resid length: 2's comp */
name|u_int32_t
name|resid
decl_stmt|;
comment|/* Transfer residual length: 2's comp */
name|cdb_t
name|cdb_io
decl_stmt|;
comment|/* Union for CDB bytes/pointer */
name|u_int8_t
modifier|*
name|msg_ptr
decl_stmt|;
comment|/* Pointer to the message buffer */
name|u_int16_t
name|msg_len
decl_stmt|;
comment|/* Number of bytes for the Message */
name|u_int8_t
name|tag_action
decl_stmt|;
comment|/* What to do for tag queueing */
comment|/* 	 * The tag action should be either the define below (to send a 	 * non-tagged transaction) or one of the defined scsi tag messages 	 * from scsi_message.h. 	 */
define|#
directive|define
name|CAM_TAG_ACTION_NONE
value|0x00
name|u_int
name|tag_id
decl_stmt|;
comment|/* tag id from initator (target mode) */
name|u_int
name|init_id
decl_stmt|;
comment|/* initiator id of who selected */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_accept_tio
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|cdb_t
name|cdb_io
decl_stmt|;
comment|/* Union for CDB bytes/pointer */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* Number of bytes for the CDB */
name|u_int8_t
name|tag_action
decl_stmt|;
comment|/* What to do for tag queueing */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* Number of bytes of Sense Data */
name|u_int
name|tag_id
decl_stmt|;
comment|/* tag id from initator (target mode) */
name|u_int
name|init_id
decl_stmt|;
comment|/* initiator id of who selected */
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Release SIM Queue */
end_comment

begin_struct
struct|struct
name|ccb_relsim
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int32_t
name|release_flags
decl_stmt|;
define|#
directive|define
name|RELSIM_ADJUST_OPENINGS
value|0x01
define|#
directive|define
name|RELSIM_RELEASE_AFTER_TIMEOUT
value|0x02
define|#
directive|define
name|RELSIM_RELEASE_AFTER_CMDCMPLT
value|0x04
define|#
directive|define
name|RELSIM_RELEASE_AFTER_QEMPTY
value|0x08
name|u_int32_t
name|openings
decl_stmt|;
name|u_int32_t
name|release_timeout
decl_stmt|;
name|u_int32_t
name|qfrozen_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the asynchronous callback CCB fields.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AC_GETDEV_CHANGED
init|=
literal|0x800
block|,
comment|/* Getdev info might have changed */
name|AC_INQ_CHANGED
init|=
literal|0x400
block|,
comment|/* Inquiry info might have changed */
name|AC_TRANSFER_NEG
init|=
literal|0x200
block|,
comment|/* New transfer settings in effect */
name|AC_LOST_DEVICE
init|=
literal|0x100
block|,
comment|/* A device went away */
name|AC_FOUND_DEVICE
init|=
literal|0x080
block|,
comment|/* A new device was found */
name|AC_PATH_DEREGISTERED
init|=
literal|0x040
block|,
comment|/* A path has de-registered */
name|AC_PATH_REGISTERED
init|=
literal|0x020
block|,
comment|/* A new path has been registered */
name|AC_SENT_BDR
init|=
literal|0x010
block|,
comment|/* A BDR message was sent to target */
name|AC_SCSI_AEN
init|=
literal|0x008
block|,
comment|/* A SCSI AEN has been received */
name|AC_UNSOL_RESEL
init|=
literal|0x002
block|,
comment|/* Unsolicited reselection occurred */
name|AC_BUS_RESET
init|=
literal|0x001
comment|/* A SCSI bus reset occurred */
block|}
name|ac_code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ac_callback_t
parameter_list|(
name|void
modifier|*
name|softc
parameter_list|,
name|u_int32_t
name|code
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|void
modifier|*
name|args
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Set Asynchronous Callback CCB */
end_comment

begin_struct
struct|struct
name|ccb_setasync
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int32_t
name|event_enable
decl_stmt|;
comment|/* Async Event enables */
name|ac_callback_t
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|callback_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set Device Type CCB */
end_comment

begin_struct
struct|struct
name|ccb_setdev
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int8_t
name|dev_type
decl_stmt|;
comment|/* Value for dev type field in EDT */
block|}
struct|;
end_struct

begin_comment
comment|/* SCSI Control Functions */
end_comment

begin_comment
comment|/* Abort XPT request CCB */
end_comment

begin_struct
struct|struct
name|ccb_abort
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|union
name|ccb
modifier|*
name|abort_ccb
decl_stmt|;
comment|/* Pointer to CCB to abort */
block|}
struct|;
end_struct

begin_comment
comment|/* Reset SCSI Bus CCB */
end_comment

begin_struct
struct|struct
name|ccb_resetbus
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Reset SCSI Device CCB */
end_comment

begin_struct
struct|struct
name|ccb_resetdev
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Terminate I/O Process Request CCB */
end_comment

begin_struct
struct|struct
name|ccb_termio
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|union
name|ccb
modifier|*
name|termio_ccb
decl_stmt|;
comment|/* Pointer to CCB to terminate */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTS_TYPE_CURRENT_SETTINGS
block|,
name|CTS_TYPE_USER_SETTINGS
block|}
name|cts_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ccb_trans_settings_scsi
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
define|#
directive|define
name|CTS_SCSI_VALID_TQ
value|0x01
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|CTS_SCSI_FLAGS_TAG_ENB
value|0x01
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_trans_settings_spi
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
define|#
directive|define
name|CTS_SPI_VALID_SYNC_RATE
value|0x01
define|#
directive|define
name|CTS_SPI_VALID_SYNC_OFFSET
value|0x02
define|#
directive|define
name|CTS_SPI_VALID_BUS_WIDTH
value|0x04
define|#
directive|define
name|CTS_SPI_VALID_DISC
value|0x08
define|#
directive|define
name|CTS_SPI_VALID_PPR_OPTIONS
value|0x10
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|CTS_SPI_FLAGS_DISC_ENB
value|0x01
name|u_int
name|sync_period
decl_stmt|;
name|u_int
name|sync_offset
decl_stmt|;
name|u_int
name|bus_width
decl_stmt|;
name|u_int
name|ppr_options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_trans_settings_fc
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
define|#
directive|define
name|CTS_FC_VALID_WWNN
value|0x8000
define|#
directive|define
name|CTS_FC_VALID_WWPN
value|0x4000
define|#
directive|define
name|CTS_FC_VALID_PORT
value|0x2000
define|#
directive|define
name|CTS_FC_VALID_SPEED
value|0x1000
name|u_int64_t
name|wwnn
decl_stmt|;
comment|/* world wide node name */
name|u_int64_t
name|wwpn
decl_stmt|;
comment|/* world wide port name */
name|u_int32_t
name|port
decl_stmt|;
comment|/* 24 bit port id, if known */
name|u_int32_t
name|bitrate
decl_stmt|;
comment|/* Mbps */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_trans_settings_sas
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
define|#
directive|define
name|CTS_SAS_VALID_SPEED
value|0x1000
name|u_int32_t
name|bitrate
decl_stmt|;
comment|/* Mbps */
block|}
struct|;
end_struct

begin_comment
comment|/* Get/Set transfer rate/width/disconnection/tag queueing settings */
end_comment

begin_struct
struct|struct
name|ccb_trans_settings
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|cts_type
name|type
decl_stmt|;
comment|/* Current or User settings */
name|cam_proto
name|protocol
decl_stmt|;
name|u_int
name|protocol_version
decl_stmt|;
name|cam_xport
name|transport
decl_stmt|;
name|u_int
name|transport_version
decl_stmt|;
union|union
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
name|struct
name|ccb_trans_settings_scsi
name|scsi
decl_stmt|;
block|}
name|proto_specific
union|;
union|union
block|{
name|u_int
name|valid
decl_stmt|;
comment|/* Which fields to honor */
name|struct
name|ccb_trans_settings_spi
name|spi
decl_stmt|;
name|struct
name|ccb_trans_settings_fc
name|fc
decl_stmt|;
name|struct
name|ccb_trans_settings_sas
name|sas
decl_stmt|;
block|}
name|xport_specific
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Calculate the geometry parameters for a device  * give the block size and volume size in blocks.  */
end_comment

begin_struct
struct|struct
name|ccb_calc_geometry
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int32_t
name|block_size
decl_stmt|;
name|u_int64_t
name|volume_size
decl_stmt|;
name|u_int32_t
name|cylinders
decl_stmt|;
name|u_int8_t
name|heads
decl_stmt|;
name|u_int8_t
name|secs_per_track
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Rescan the given bus, or bus/target/lun  */
end_comment

begin_struct
struct|struct
name|ccb_rescan
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|cam_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Turn on debugging for the given bus, bus/target, or bus/target/lun.  */
end_comment

begin_struct
struct|struct
name|ccb_debug
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|cam_debug_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Target mode structures. */
end_comment

begin_struct
struct|struct
name|ccb_en_lun
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int16_t
name|grp6_len
decl_stmt|;
comment|/* Group 6 VU CDB length */
name|u_int16_t
name|grp7_len
decl_stmt|;
comment|/* Group 7 VU CDB length */
name|u_int8_t
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_immed_notify
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* Number of bytes in sense buffer */
name|u_int8_t
name|initiator_id
decl_stmt|;
comment|/* Id of initiator that selected */
name|u_int8_t
name|message_args
index|[
literal|7
index|]
decl_stmt|;
comment|/* Message Arguments */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_notify_ack
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int16_t
name|seq_id
decl_stmt|;
comment|/* Sequence identifier */
name|u_int8_t
name|event
decl_stmt|;
comment|/* Event flags */
block|}
struct|;
end_struct

begin_comment
comment|/* HBA engine structures. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EIT_BUFFER
block|,
comment|/* Engine type: buffer memory */
name|EIT_LOSSLESS
block|,
comment|/* Engine type: lossless compression */
name|EIT_LOSSY
block|,
comment|/* Engine type: lossy compression */
name|EIT_ENCRYPT
comment|/* Engine type: encryption */
block|}
name|ei_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EAD_VUNIQUE
block|,
comment|/* Engine algorithm ID: vendor unique */
name|EAD_LZ1V1
block|,
comment|/* Engine algorithm ID: LZ1 var.1 */
name|EAD_LZ2V1
block|,
comment|/* Engine algorithm ID: LZ2 var.1 */
name|EAD_LZ2V2
comment|/* Engine algorithm ID: LZ2 var.2 */
block|}
name|ei_algo
typedef|;
end_typedef

begin_struct
struct|struct
name|ccb_eng_inq
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int16_t
name|eng_num
decl_stmt|;
comment|/* The engine number for this inquiry */
name|ei_type
name|eng_type
decl_stmt|;
comment|/* Returned engine type */
name|ei_algo
name|eng_algo
decl_stmt|;
comment|/* Returned engine algorithm type */
name|u_int32_t
name|eng_memeory
decl_stmt|;
comment|/* Returned engine memory size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_eng_exec
block|{
comment|/* This structure must match SCSIIO size */
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
name|u_int8_t
modifier|*
name|pdrv_ptr
decl_stmt|;
comment|/* Ptr used by the peripheral driver */
name|u_int8_t
modifier|*
name|req_map
decl_stmt|;
comment|/* Ptr for mapping info on the req. */
name|u_int8_t
modifier|*
name|data_ptr
decl_stmt|;
comment|/* Pointer to the data buf/SG list */
name|u_int32_t
name|dxfer_len
decl_stmt|;
comment|/* Data transfer length */
name|u_int8_t
modifier|*
name|engdata_ptr
decl_stmt|;
comment|/* Pointer to the engine buffer data */
name|u_int16_t
name|sglist_cnt
decl_stmt|;
comment|/* Num of scatter gather list entries */
name|u_int32_t
name|dmax_len
decl_stmt|;
comment|/* Destination data maximum length */
name|u_int32_t
name|dest_len
decl_stmt|;
comment|/* Destination data length */
name|int32_t
name|src_resid
decl_stmt|;
comment|/* Source residual length: 2's comp */
name|u_int32_t
name|timeout
decl_stmt|;
comment|/* Timeout value */
name|u_int16_t
name|eng_num
decl_stmt|;
comment|/* Engine number for this request */
name|u_int16_t
name|vu_flags
decl_stmt|;
comment|/* Vendor Unique flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the timeout field in the SCSI I/O CCB.  */
end_comment

begin_define
define|#
directive|define
name|CAM_TIME_DEFAULT
value|0x00000000
end_define

begin_comment
comment|/* Use SIM default value */
end_comment

begin_define
define|#
directive|define
name|CAM_TIME_INFINITY
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Infinite timeout */
end_comment

begin_define
define|#
directive|define
name|CAM_SUCCESS
value|0
end_define

begin_comment
comment|/* For signaling general success */
end_comment

begin_define
define|#
directive|define
name|CAM_FAILURE
value|1
end_define

begin_comment
comment|/* For signaling general failure */
end_comment

begin_define
define|#
directive|define
name|CAM_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|CAM_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|XPT_CCB_INVALID
value|-1
end_define

begin_comment
comment|/* for signaling a bad CCB to free */
end_comment

begin_comment
comment|/*  * Union of all CCB types for kernel space allocation.  This union should  * never be used for manipulating CCBs - its only use is for the allocation  * and deallocation of raw CCB space and is the return type of xpt_ccb_alloc  * and the argument to xpt_ccb_free.  */
end_comment

begin_union
union|union
name|ccb
block|{
name|struct
name|ccb_hdr
name|ccb_h
decl_stmt|;
comment|/* For convenience */
name|struct
name|ccb_scsiio
name|csio
decl_stmt|;
name|struct
name|ccb_getdev
name|cgd
decl_stmt|;
name|struct
name|ccb_getdevlist
name|cgdl
decl_stmt|;
name|struct
name|ccb_pathinq
name|cpi
decl_stmt|;
name|struct
name|ccb_relsim
name|crs
decl_stmt|;
name|struct
name|ccb_setasync
name|csa
decl_stmt|;
name|struct
name|ccb_setdev
name|csd
decl_stmt|;
name|struct
name|ccb_pathstats
name|cpis
decl_stmt|;
name|struct
name|ccb_getdevstats
name|cgds
decl_stmt|;
name|struct
name|ccb_dev_match
name|cdm
decl_stmt|;
name|struct
name|ccb_trans_settings
name|cts
decl_stmt|;
name|struct
name|ccb_calc_geometry
name|ccg
decl_stmt|;
name|struct
name|ccb_abort
name|cab
decl_stmt|;
name|struct
name|ccb_resetbus
name|crb
decl_stmt|;
name|struct
name|ccb_resetdev
name|crd
decl_stmt|;
name|struct
name|ccb_termio
name|tio
decl_stmt|;
name|struct
name|ccb_accept_tio
name|atio
decl_stmt|;
name|struct
name|ccb_scsiio
name|ctio
decl_stmt|;
name|struct
name|ccb_en_lun
name|cel
decl_stmt|;
name|struct
name|ccb_immed_notify
name|cin
decl_stmt|;
name|struct
name|ccb_notify_ack
name|cna
decl_stmt|;
name|struct
name|ccb_eng_inq
name|cei
decl_stmt|;
name|struct
name|ccb_eng_exec
name|cee
decl_stmt|;
name|struct
name|ccb_rescan
name|crcn
decl_stmt|;
name|struct
name|ccb_debug
name|cdbg
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|__BEGIN_DECLS
specifier|static
name|__inline
name|void
name|cam_fill_csio
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
name|u_int32_t
name|flags
parameter_list|,
name|u_int8_t
name|tag_action
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
name|u_int8_t
name|cdb_len
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|cam_fill_ctio
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
name|u_int32_t
name|flags
parameter_list|,
name|u_int
name|tag_action
parameter_list|,
name|u_int
name|tag_id
parameter_list|,
name|u_int
name|init_id
parameter_list|,
name|u_int
name|scsi_status
parameter_list|,
name|u_int8_t
modifier|*
name|data_ptr
parameter_list|,
name|u_int32_t
name|dxfer_len
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|cam_fill_csio
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
name|u_int32_t
name|flags
parameter_list|,
name|u_int8_t
name|tag_action
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
name|u_int8_t
name|cdb_len
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|)
block|{
name|csio
operator|->
name|ccb_h
operator|.
name|func_code
operator|=
name|XPT_SCSI_IO
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|retry_count
operator|=
name|retries
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|cbfcnp
operator|=
name|cbfcnp
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|timeout
operator|=
name|timeout
expr_stmt|;
name|csio
operator|->
name|data_ptr
operator|=
name|data_ptr
expr_stmt|;
name|csio
operator|->
name|dxfer_len
operator|=
name|dxfer_len
expr_stmt|;
name|csio
operator|->
name|sense_len
operator|=
name|sense_len
expr_stmt|;
name|csio
operator|->
name|cdb_len
operator|=
name|cdb_len
expr_stmt|;
name|csio
operator|->
name|tag_action
operator|=
name|tag_action
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|cam_fill_ctio
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
name|u_int32_t
name|flags
parameter_list|,
name|u_int
name|tag_action
parameter_list|,
name|u_int
name|tag_id
parameter_list|,
name|u_int
name|init_id
parameter_list|,
name|u_int
name|scsi_status
parameter_list|,
name|u_int8_t
modifier|*
name|data_ptr
parameter_list|,
name|u_int32_t
name|dxfer_len
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|)
block|{
name|csio
operator|->
name|ccb_h
operator|.
name|func_code
operator|=
name|XPT_CONT_TARGET_IO
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|retry_count
operator|=
name|retries
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|cbfcnp
operator|=
name|cbfcnp
expr_stmt|;
name|csio
operator|->
name|ccb_h
operator|.
name|timeout
operator|=
name|timeout
expr_stmt|;
name|csio
operator|->
name|data_ptr
operator|=
name|data_ptr
expr_stmt|;
name|csio
operator|->
name|dxfer_len
operator|=
name|dxfer_len
expr_stmt|;
name|csio
operator|->
name|scsi_status
operator|=
name|scsi_status
expr_stmt|;
name|csio
operator|->
name|tag_action
operator|=
name|tag_action
expr_stmt|;
name|csio
operator|->
name|tag_id
operator|=
name|tag_id
expr_stmt|;
name|csio
operator|->
name|init_id
operator|=
name|init_id
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|cam_calc_geometry
parameter_list|(
name|struct
name|ccb_calc_geometry
modifier|*
name|ccg
parameter_list|,
name|int
name|extended
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

begin_comment
comment|/* _CAM_CAM_CCB_H */
end_comment

end_unit

