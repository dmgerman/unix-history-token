begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Hardware structure definitions for the Adaptec 174X CAM SCSI device driver.  *  * Copyright (c) 1998 Justin T. Gibbs  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Resource Constatns */
end_comment

begin_define
define|#
directive|define
name|AHB_NECB
value|64
end_define

begin_define
define|#
directive|define
name|AHB_NSEG
value|32
end_define

begin_comment
comment|/* AHA1740 EISA ID, IO port range size, and offset from slot base */
end_comment

begin_define
define|#
directive|define
name|EISA_DEVICE_ID_ADAPTEC_1740
value|0x04900000
end_define

begin_define
define|#
directive|define
name|AHB_EISA_IOSIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AHB_EISA_SLOT_OFFSET
value|0xc00
end_define

begin_comment
comment|/* AHA1740 EISA board control registers (Offset from slot base) */
end_comment

begin_define
define|#
directive|define
name|EBCTRL
value|0x084
end_define

begin_define
define|#
directive|define
name|CDEN
value|0x01
end_define

begin_comment
comment|/*  * AHA1740 EISA board mode registers (Offset from slot base)  */
end_comment

begin_define
define|#
directive|define
name|PORTADDR
value|0x0C0
end_define

begin_define
define|#
directive|define
name|PORTADDR_ENHANCED
value|0x80
end_define

begin_define
define|#
directive|define
name|BIOSADDR
value|0x0C1
end_define

begin_define
define|#
directive|define
name|INTDEF
value|0x0C2
end_define

begin_define
define|#
directive|define
name|INT9
value|0x00
end_define

begin_define
define|#
directive|define
name|INT10
value|0x01
end_define

begin_define
define|#
directive|define
name|INT11
value|0x02
end_define

begin_define
define|#
directive|define
name|INT12
value|0x03
end_define

begin_define
define|#
directive|define
name|INT14
value|0x05
end_define

begin_define
define|#
directive|define
name|INT15
value|0x06
end_define

begin_define
define|#
directive|define
name|INTLEVEL
value|0x08
end_define

begin_define
define|#
directive|define
name|INTEN
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSIDEF
value|0x0C3
end_define

begin_define
define|#
directive|define
name|HSCSIID
value|0x0F
end_define

begin_comment
comment|/* our SCSI ID */
end_comment

begin_define
define|#
directive|define
name|RSTBUS
value|0x10
end_define

begin_define
define|#
directive|define
name|BUSDEF
value|0x0C4
end_define

begin_define
define|#
directive|define
name|B0uS
value|0x00
end_define

begin_comment
comment|/* give up bus immediatly */
end_comment

begin_define
define|#
directive|define
name|B4uS
value|0x01
end_define

begin_comment
comment|/* delay 4uSec. */
end_comment

begin_define
define|#
directive|define
name|B8uS
value|0x02
end_define

begin_comment
comment|/* delay 8uSec. */
end_comment

begin_define
define|#
directive|define
name|RESV0
value|0x0C5
end_define

begin_define
define|#
directive|define
name|RESV1
value|0x0C6
end_define

begin_define
define|#
directive|define
name|EXTENDED_TRANS
value|0x01
end_define

begin_define
define|#
directive|define
name|RESV2
value|0x0C7
end_define

begin_comment
comment|/*  * AHA1740 ENHANCED mode mailbox control regs (Offset from slot base)  */
end_comment

begin_define
define|#
directive|define
name|MBOXOUT0
value|0x0D0
end_define

begin_define
define|#
directive|define
name|MBOXOUT1
value|0x0D1
end_define

begin_define
define|#
directive|define
name|MBOXOUT2
value|0x0D2
end_define

begin_define
define|#
directive|define
name|MBOXOUT3
value|0x0D3
end_define

begin_define
define|#
directive|define
name|ATTN
value|0x0D4
end_define

begin_define
define|#
directive|define
name|ATTN_TARGMASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|ATTN_IMMED
value|0x10
end_define

begin_define
define|#
directive|define
name|ATTN_STARTECB
value|0x40
end_define

begin_define
define|#
directive|define
name|ATTN_ABORTECB
value|0x50
end_define

begin_define
define|#
directive|define
name|ATTN_TARG_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|CONTROL
value|0x0D5
end_define

begin_define
define|#
directive|define
name|CNTRL_SET_HRDY
value|0x20
end_define

begin_define
define|#
directive|define
name|CNTRL_CLRINT
value|0x40
end_define

begin_define
define|#
directive|define
name|CNTRL_HARD_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|INTSTAT
value|0x0D6
end_define

begin_define
define|#
directive|define
name|INTSTAT_TARGET_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|INTSTAT_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|INTSTAT_ECB_OK
value|0x10
end_define

begin_comment
comment|/* ECB Completed w/out error */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_ECB_CMPWRETRY
value|0x50
end_define

begin_comment
comment|/* ECB Completed w/retries */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_HW_ERR
value|0x70
end_define

begin_comment
comment|/* Adapter Hardware Failure */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_IMMED_OK
value|0xA0
end_define

begin_comment
comment|/* Immediate command complete */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_ECB_CMPWERR
value|0xC0
end_define

begin_comment
comment|/* ECB Completed w/error */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_AEN_OCCURED
value|0xD0
end_define

begin_comment
comment|/* Async Event Notification */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_IMMED_ERR
value|0xE0
end_define

begin_comment
comment|/* Immediate command failed */
end_comment

begin_define
define|#
directive|define
name|HOSTSTAT
value|0x0D7
end_define

begin_define
define|#
directive|define
name|HOSTSTAT_MBOX_EMPTY
value|0x04
end_define

begin_define
define|#
directive|define
name|HOSTSTAT_INTPEND
value|0x02
end_define

begin_define
define|#
directive|define
name|HOSTSTAT_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|MBOXIN0
value|0x0D8
end_define

begin_define
define|#
directive|define
name|MBOXIN1
value|0x0D9
end_define

begin_define
define|#
directive|define
name|MBOXIN2
value|0x0DA
end_define

begin_define
define|#
directive|define
name|MBOXIN3
value|0x0DB
end_define

begin_define
define|#
directive|define
name|STATUS2
value|0x0DC
end_define

begin_define
define|#
directive|define
name|STATUS2_HOST_READY
value|0x01
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|IMMED_RESET
init|=
literal|0x000080
block|,
name|IMMED_DEVICE_CLEAR_QUEUE
init|=
literal|0x000480
block|,
name|IMMED_ADAPTER_CLEAR_QUEUE
init|=
literal|0x000880
block|,
name|IMMED_RESUME
init|=
literal|0x200090
block|}
name|immed_cmd
typedef|;
end_typedef

begin_struct
struct|struct
name|ecb_status
block|{
comment|/* Status Flags */
name|u_int16_t
name|no_error
range|:
literal|1
decl_stmt|,
comment|/* Completed with no error */
name|data_underrun
range|:
literal|1
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|ha_queue_full
range|:
literal|1
decl_stmt|,
name|spec_check
range|:
literal|1
decl_stmt|,
name|data_overrun
range|:
literal|1
decl_stmt|,
name|chain_halted
range|:
literal|1
decl_stmt|,
name|intr_issued
range|:
literal|1
decl_stmt|,
name|status_avail
range|:
literal|1
decl_stmt|,
comment|/* status bytes 14-31 are valid */
name|sense_stored
range|:
literal|1
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|init_requied
range|:
literal|1
decl_stmt|,
name|major_error
range|:
literal|1
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|extended_ca
range|:
literal|1
decl_stmt|,
range|:
literal|1
decl_stmt|;
comment|/* Host Status */
name|u_int8_t
name|ha_status
decl_stmt|;
name|u_int8_t
name|scsi_status
decl_stmt|;
name|int32_t
name|resid_count
decl_stmt|;
name|u_int32_t
name|resid_addr
decl_stmt|;
name|u_int16_t
name|addit_status
decl_stmt|;
name|u_int8_t
name|sense_len
decl_stmt|;
name|u_int8_t
name|unused
index|[
literal|9
index|]
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|HS_OK
init|=
literal|0x00
block|,
name|HS_CMD_ABORTED_HOST
init|=
literal|0x04
block|,
name|HS_CMD_ABORTED_ADAPTER
init|=
literal|0x05
block|,
name|HS_FIRMWARE_LOAD_REQ
init|=
literal|0x08
block|,
name|HS_TARGET_NOT_ASSIGNED
init|=
literal|0x0A
block|,
name|HS_SEL_TIMEOUT
init|=
literal|0x11
block|,
name|HS_DATA_RUN_ERR
init|=
literal|0x12
block|,
name|HS_UNEXPECTED_BUSFREE
init|=
literal|0x13
block|,
name|HS_INVALID_PHASE
init|=
literal|0x14
block|,
name|HS_INVALID_OPCODE
init|=
literal|0x16
block|,
name|HS_INVALID_CMD_LINK
init|=
literal|0x17
block|,
name|HS_INVALID_ECB_PARAM
init|=
literal|0x18
block|,
name|HS_DUP_TCB_RECEIVED
init|=
literal|0x19
block|,
name|HS_REQUEST_SENSE_FAILED
init|=
literal|0x1A
block|,
name|HS_TAG_MSG_REJECTED
init|=
literal|0x1C
block|,
name|HS_HARDWARE_ERR
init|=
literal|0x20
block|,
name|HS_ATN_TARGET_FAILED
init|=
literal|0x21
block|,
name|HS_SCSI_RESET_ADAPTER
init|=
literal|0x22
block|,
name|HS_SCSI_RESET_INCOMING
init|=
literal|0x23
block|,
name|HS_PROGRAM_CKSUM_ERROR
init|=
literal|0x80
block|}
name|host_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ECBOP_NOP
init|=
literal|0x00
block|,
name|ECBOP_INITIATOR_SCSI_CMD
init|=
literal|0x01
block|,
name|ECBOP_RUN_DIAGNOSTICS
init|=
literal|0x05
block|,
name|ECBOP_INITIALIZE_SCSI
init|=
literal|0x06
block|,
comment|/* Set syncrate/disc/parity */
name|ECBOP_READ_SENSE
init|=
literal|0x08
block|,
name|ECBOP_DOWNLOAD_FIRMWARE
init|=
literal|0x09
block|,
name|ECBOP_READ_HA_INQDATA
init|=
literal|0x0a
block|,
name|ECBOP_TARGET_SCSI_CMD
init|=
literal|0x10
block|}
name|ecb_op
typedef|;
end_typedef

begin_struct
struct|struct
name|ha_inquiry_data
block|{
name|struct
name|scsi_inquiry_data
name|scsi_data
decl_stmt|;
name|u_int8_t
name|release_date
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|release_time
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|firmware_cksum
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int16_t
name|target_data
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hardware_ecb
block|{
name|u_int16_t
name|opcode
decl_stmt|;
name|u_int16_t
name|flag_word1
decl_stmt|;
define|#
directive|define
name|FW1_LINKED_CMD
value|0x0001
define|#
directive|define
name|FW1_DISABLE_INTR
value|0x0080
define|#
directive|define
name|FW1_SUPPRESS_URUN_ERR
value|0x0400
define|#
directive|define
name|FW1_SG_ECB
value|0x1000
define|#
directive|define
name|FW1_ERR_STATUS_BLK_ONLY
value|0x4000
define|#
directive|define
name|FW1_AUTO_REQUEST_SENSE
value|0x8000
name|u_int16_t
name|flag_word2
decl_stmt|;
define|#
directive|define
name|FW2_LUN_MASK
value|0x0007
define|#
directive|define
name|FW2_TAG_ENB
value|0x0008
define|#
directive|define
name|FW2_TAG_TYPE
value|0x0030
define|#
directive|define
name|FW2_TAG_TYPE_SHIFT
value|4
define|#
directive|define
name|FW2_DISABLE_DISC
value|0x0040
define|#
directive|define
name|FW2_CHECK_DATA_DIR
value|0x0100
define|#
directive|define
name|FW2_DATA_DIR_IN
value|0x0200
define|#
directive|define
name|FW2_SUPRESS_TRANSFER
value|0x0400
define|#
directive|define
name|FW2_CALC_CKSUM
value|0x0800
define|#
directive|define
name|FW2_RECOVERY_ECB
value|0x4000
define|#
directive|define
name|FW2_NO_RETRY_ON_BUSY
value|0x8000
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|data_ptr
decl_stmt|;
name|u_int32_t
name|data_len
decl_stmt|;
name|u_int32_t
name|status_ptr
decl_stmt|;
name|u_int32_t
name|link_ptr
decl_stmt|;
name|u_int32_t
name|reserved2
decl_stmt|;
name|u_int32_t
name|sense_ptr
decl_stmt|;
name|u_int8_t
name|sense_len
decl_stmt|;
name|u_int8_t
name|cdb_len
decl_stmt|;
name|u_int16_t
name|cksum
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
block|}
name|ahb_sg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ECB_FREE
init|=
literal|0x0
block|,
name|ECB_ACTIVE
init|=
literal|0x1
block|,
name|ECB_DEVICE_RESET
init|=
literal|0x2
block|,
name|ECB_SCSIBUS_RESET
init|=
literal|0x4
block|,
name|ECB_RELEASE_SIMQ
init|=
literal|0x8
block|}
name|ecb_state
typedef|;
end_typedef

begin_struct
struct|struct
name|ecb
block|{
name|struct
name|hardware_ecb
name|hecb
decl_stmt|;
name|struct
name|ecb_status
name|status
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense
decl_stmt|;
name|ahb_sg_t
name|sg_list
index|[
name|AHB_NSEG
index|]
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ecb
argument_list|)
name|links
expr_stmt|;
name|ecb_state
name|state
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahb_softc
block|{
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|ecb
argument_list|)
name|free_ecbs
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
name|struct
name|ecb
modifier|*
name|ecb_array
decl_stmt|;
name|u_int32_t
name|ecb_physbase
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
name|bus_dma_tag_t
name|ecb_dmat
decl_stmt|;
comment|/* dmat for our ecb array */
name|bus_dmamap_t
name|ecb_dmamap
decl_stmt|;
specifier|volatile
name|u_int32_t
name|immed_cmd
decl_stmt|;
name|struct
name|ecb
modifier|*
name|immed_ecb
decl_stmt|;
name|struct
name|ha_inquiry_data
modifier|*
name|ha_inq_data
decl_stmt|;
name|u_int32_t
name|ha_inq_physbase
decl_stmt|;
name|u_long
name|unit
decl_stmt|;
name|u_int
name|init_level
decl_stmt|;
name|u_int
name|scsi_id
decl_stmt|;
name|u_int
name|num_ecbs
decl_stmt|;
name|u_int
name|extended_trans
decl_stmt|;
name|u_int8_t
name|disc_permitted
decl_stmt|;
name|u_int8_t
name|tags_permitted
decl_stmt|;
block|}
struct|;
end_struct

end_unit

