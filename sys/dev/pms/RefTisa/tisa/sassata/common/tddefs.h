begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * The file contains defines and data structures for SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDDEFS_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|agTRUE
end_ifndef

begin_define
define|#
directive|define
name|agTRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|agFALSE
end_ifndef

begin_define
define|#
directive|define
name|agFALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|agNULL
end_ifndef

begin_define
define|#
directive|define
name|agNULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN
end_ifndef

begin_define
define|#
directive|define
name|IN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OUT
end_ifndef

begin_define
define|#
directive|define
name|OUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN_OUT
end_ifndef

begin_define
define|#
directive|define
name|IN_OUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_bit8
end_ifndef

begin_define
define|#
directive|define
name|os_bit8
value|bit8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_bit16
end_ifndef

begin_define
define|#
directive|define
name|os_bit16
value|bit16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_bit32
end_ifndef

begin_define
define|#
directive|define
name|os_bit32
value|bit32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFF
end_ifndef

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ON
end_ifndef

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TD_OPERATION_INITIATOR
value|0x1
end_define

begin_define
define|#
directive|define
name|TD_OPERATION_TARGET
value|0x2
end_define

begin_comment
comment|/* indices for mem_t structures */
end_comment

begin_define
define|#
directive|define
name|DEK_MEM_INDEX_1
value|15
end_define

begin_define
define|#
directive|define
name|DEK_MEM_INDEX_2
value|16
end_define

begin_comment
comment|/* some useful macros */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AG_ALIGNSIZE
end_ifndef

begin_define
define|#
directive|define
name|AG_ALIGNSIZE
parameter_list|(
name|count
parameter_list|,
name|alignment
parameter_list|)
value|(bit32) ( (bitptr)(count)+(bitptr)(alignment) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_KEY_BUFFER_SIZE
value|64
end_define

begin_comment
comment|/**< the default maximum number of phys */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FPGA_CARD
end_ifdef

begin_define
define|#
directive|define
name|TD_MAX_NUM_PHYS
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TD_MAX_NUM_PHYS
value|16
end_define

begin_define
define|#
directive|define
name|TD_MAX_CARD_NUM
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TD_CARD_ID_FREE
value|0
end_define

begin_define
define|#
directive|define
name|TD_CARD_ID_ALLOC
value|1
end_define

begin_define
define|#
directive|define
name|TD_CARD_ID_LEN
value|128
end_define

begin_comment
comment|/**< the maximum number of port context */
end_comment

begin_comment
comment|/* should be the number of phyical phys in chip + 1 */
end_comment

begin_define
define|#
directive|define
name|TD_MAX_PORT_CONTEXT
value|16
end_define

begin_comment
comment|/**< the maximum number of target device */
end_comment

begin_comment
comment|/* For Initiator and Target    this is initial value for MaxTargets in the configuration(adj) file */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAX_DEV
value|256
end_define

begin_comment
comment|/* the maximum number of interrupt coalesce context */
end_comment

begin_define
define|#
directive|define
name|TD_MAX_INT_COALESCE
value|512
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|MAX_OUTSTANDING_IO_PER_LUN
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_OUTSTANDING_IO_PER_LUN
value|254
end_define

begin_comment
comment|//64
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default values */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAX_ACTIVE_IOS
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_NUM_REG_CLIENTS
value|256
end_define

begin_define
define|#
directive|define
name|DEFAULT_NUM_INBOUND_QUEUE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_NUM_OUTBOUND_QUEUE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_INBOUND_QUEUE_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|DEFAULT_INBOUND_QUEUE_ELE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTBOUND_QUEUE_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTBOUND_QUEUE_ELE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTBOUND_QUEUE_INTERRUPT_DELAY
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTBOUND_QUEUE_INTERRUPT_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTBOUND_INTERRUPT_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_INBOUND_QUEUE_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_QUEUE_OPTION
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_FW_MAX_PORTS
value|8
end_define

begin_comment
comment|/* SAS device type definition. SAS spec(r.7) p206  */
end_comment

begin_define
define|#
directive|define
name|SAS_NO_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|SAS_END_DEVICE
value|1
end_define

begin_define
define|#
directive|define
name|SAS_EDGE_EXPANDER_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|SAS_FANOUT_EXPANDER_DEVICE
value|3
end_define

begin_comment
comment|/* routing attributes */
end_comment

begin_define
define|#
directive|define
name|SAS_ROUTING_DIRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|SAS_ROUTING_SUBTRACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|SAS_ROUTING_TABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_1_5G
value|0x08
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_3_0G
value|0x09
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_6_0G
value|0x0A
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_12_0G
value|0x0B
end_define

begin_comment
comment|/**< defines the maximum number of expanders */
end_comment

begin_define
define|#
directive|define
name|TD_MAX_EXPANDER_PHYS
value|256
end_define

begin_comment
comment|/**< the maximum number of expanders at TD */
end_comment

begin_define
define|#
directive|define
name|TD_MAX_EXPANDER
value|128
end_define

begin_comment
comment|/***************************************************************************** ** SCSI Operation Codes (first byte in CDB) *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSIOPC_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSIOPC_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SENSE_6
value|0x1A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SENSE_10
value|0x5A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_6
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSIOPC_START_STOP_UNIT
value|0x1B
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_CAPACITY_10
value|0x25
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_CAPACITY_16
value|0x9E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_6
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_10
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_12
value|0xA8
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_16
value|0x88
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_6
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_10
value|0x2A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_12
value|0xAA
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_16
value|0x8A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_VERIFY
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_10
value|0x2F
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_12
value|0xAF
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_16
value|0x8F
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REPORT_LUN
value|0xA0
end_define

begin_define
define|#
directive|define
name|SCSIOPC_FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SEND_DIAGNOSTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_SAME_10
value|0x41
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_SAME_16
value|0x93
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_BUFFER
value|0x3C
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_BUFFER
value|0x3B
end_define

begin_define
define|#
directive|define
name|SCSIOPC_GET_CONFIG
value|0x46
end_define

begin_define
define|#
directive|define
name|SCSIOPC_GET_EVENT_STATUS_NOTIFICATION
value|0x4a
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REPORT_KEY
value|0xA4
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SEND_KEY
value|0xA3
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_DVD_STRUCTURE
value|0xAD
end_define

begin_define
define|#
directive|define
name|SCSIOPC_TOC
value|0x43
end_define

begin_define
define|#
directive|define
name|SCSIOPC_PREVENT_ALLOW_MEDIUM_REMOVAL
value|0x1E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_VERIFY
value|0x42
end_define

begin_define
define|#
directive|define
name|SCSIOPC_LOG_SENSE
value|0x4D
end_define

begin_define
define|#
directive|define
name|SCSIOPC_LOG_SELECT
value|0x4C
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_6
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_10
value|0x55
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SYNCHRONIZE_CACHE_10
value|0x35
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SYNCHRONIZE_CACHE_16
value|0x91
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_10
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_12
value|0xAE
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_16
value|0x8E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_MEDIA_SERIAL_NUMBER
value|0xAB
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REASSIGN_BLOCKS
value|0x07
end_define

begin_comment
comment|/***************************************************************************** ** SCSI GENERIC 6 BYTE CDB *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CBD6_s
block|{
name|bit8
name|opcode
decl_stmt|;
name|bit8
name|rsv
decl_stmt|;
comment|/* not 100% correct */
name|bit8
name|lba
index|[
literal|2
index|]
decl_stmt|;
comment|/* not 100% correct */
name|bit8
name|len
decl_stmt|;
name|bit8
name|control
decl_stmt|;
block|}
name|CDB6_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** ** SCSI GENERIC 10 BYTE CDB *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CBD10_s
block|{
name|bit8
name|opcode
decl_stmt|;
name|bit8
name|rsv_service
decl_stmt|;
name|bit8
name|lba
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|rsv
decl_stmt|;
name|bit8
name|len
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|control
decl_stmt|;
block|}
name|CDB10_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** ** SCSI GENERIC 12 BYTE CDB *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CBD12_s
block|{
name|bit8
name|opcode
decl_stmt|;
name|bit8
name|rsv_service
decl_stmt|;
name|bit8
name|lba
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|len
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|rsv
decl_stmt|;
name|bit8
name|control
decl_stmt|;
block|}
name|CDB12_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** ** SCSI GENERIC 16 BYTE CDB *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CBD16_s
block|{
name|bit8
name|opcode
decl_stmt|;
name|bit8
name|rsv_service
decl_stmt|;
name|bit8
name|lba
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|add_cdb
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|len
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|rsv
decl_stmt|;
name|bit8
name|control
decl_stmt|;
block|}
name|CDB16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLOCK_BYTE_LENGTH
value|512
end_define

begin_comment
comment|/***************************************************************************** ** SCSI STATUS BYTES *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_CHECK_CONDITION
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_COMMAND_TERMINATED
value|0x22
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_TASK_SET_FULL
value|0x28
end_define

begin_comment
comment|/***************************************************************************** ** SAS TM Function data present see SAS spec p311 Table 109 (Revision 7) *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NO_DATA
value|0
end_define

begin_define
define|#
directive|define
name|RESPONSE_DATA
value|1
end_define

begin_define
define|#
directive|define
name|SENSE_DATA
value|2
end_define

begin_comment
comment|/* 4 bytes, SAS spec p312 Table 110 (Revision 7) */
end_comment

begin_define
define|#
directive|define
name|RESPONSE_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SAS_CMND
value|0
end_define

begin_define
define|#
directive|define
name|SAS_TM
value|1
end_define

begin_comment
comment|/* SMP frame type */
end_comment

begin_define
define|#
directive|define
name|SMP_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|SMP_RESPONSE
value|0x41
end_define

begin_define
define|#
directive|define
name|SMP_INITIATOR
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_TARGET
value|0x02
end_define

begin_comment
comment|/* default SMP timeout: 0xFFFF is the Maximum Allowed */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SMP_TIMEOUT
value|0xFFFF
end_define

begin_comment
comment|/* SMP direct payload size limit: IOMB direct payload size = 48 */
end_comment

begin_define
define|#
directive|define
name|SMP_DIRECT_PAYLOAD_LIMIT
value|44
end_define

begin_comment
comment|/* SMP function */
end_comment

begin_define
define|#
directive|define
name|SMP_REPORT_GENERAL
value|0x00
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_MANUFACTURE_INFORMATION
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_READ_GPIO_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|SMP_DISCOVER
value|0x10
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_PHY_ERROR_LOG
value|0x11
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_PHY_SATA
value|0x12
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_ROUTING_INFORMATION
value|0x13
end_define

begin_define
define|#
directive|define
name|SMP_WRITE_GPIO_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|SMP_CONFIGURE_ROUTING_INFORMATION
value|0x90
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL
value|0x91
end_define

begin_define
define|#
directive|define
name|SMP_PHY_TEST_FUNCTION
value|0x92
end_define

begin_define
define|#
directive|define
name|SMP_PMC_SPECIFIC
value|0xC0
end_define

begin_comment
comment|/* SMP function results */
end_comment

begin_define
define|#
directive|define
name|SMP_FUNCTION_ACCEPTED
value|0x00
end_define

begin_define
define|#
directive|define
name|UNKNOWN_SMP_FUNCTION
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_FUNCTION_FAILED
value|0x02
end_define

begin_define
define|#
directive|define
name|INVALID_REQUEST_FRAME_LENGTH
value|0x03
end_define

begin_define
define|#
directive|define
name|INVALID_EXPANDER_CHANGE_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|SMP_FN_BUSY
value|0x05
end_define

begin_define
define|#
directive|define
name|INCOMPLETE_DESCRIPTOR_LIST
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_DOES_NOT_EXIST
value|0x10
end_define

begin_define
define|#
directive|define
name|INDEX_DOES_NOT_EXIST
value|0x11
end_define

begin_define
define|#
directive|define
name|PHY_DOES_NOT_SUPPORT_SATA
value|0x12
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_OPERATION
value|0x13
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_TEST_FUNCTION
value|0x14
end_define

begin_define
define|#
directive|define
name|PHY_TEST_FUNCTION_IN_PROGRESS
value|0x15
end_define

begin_define
define|#
directive|define
name|PHY_VACANT
value|0x16
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_EVENT_SOURCE
value|0x17
end_define

begin_define
define|#
directive|define
name|UNKNOWN_DESCRIPTOT_TYPE
value|0x18
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_FILETER
value|0x19
end_define

begin_define
define|#
directive|define
name|AFFILIATION_VIOLATION
value|0x1A
end_define

begin_define
define|#
directive|define
name|SMP_ZONE_VIOLATION
value|0x20
end_define

begin_define
define|#
directive|define
name|NO_MANAGEMENT_ACCESS_RIGHTS
value|0x21
end_define

begin_define
define|#
directive|define
name|UNKNOWN_ENABLE_DISABLE_ZONING_VALUE
value|0x22
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK_VIOLATION
value|0x23
end_define

begin_define
define|#
directive|define
name|NOT_ACTIVATED
value|0x24
end_define

begin_define
define|#
directive|define
name|ZONE_GROUP_OUT_OF_RANGE
value|0x25
end_define

begin_define
define|#
directive|define
name|NO_PHYSICAL_PRESENCE
value|0x26
end_define

begin_define
define|#
directive|define
name|SAVING_NOT_SUPPORTED
value|0x27
end_define

begin_define
define|#
directive|define
name|SOURCE_ZONE_GROUP_DOES_NOT_EXIST
value|0x28
end_define

begin_define
define|#
directive|define
name|DISABLED_PASSWORD_NOT_SUPPORTED
value|0x29
end_define

begin_comment
comment|/* SMP PHY CONTROL OPERATION */
end_comment

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_LINK_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_HARD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_DISABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_ERROR_LOG
value|0x05
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_AFFILIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_XMIT_SATA_PS_SIGNAL
value|0x07
end_define

begin_define
define|#
directive|define
name|IT_NEXUS_TIMEOUT
value|0x7D0
end_define

begin_comment
comment|/* 2000 ms; old value was 0xFFFF */
end_comment

begin_define
define|#
directive|define
name|PORT_RECOVERY_TIMEOUT
value|((IT_NEXUS_TIMEOUT/100) + 30)
end_define

begin_comment
comment|/* 5000 ms; in 100ms; should be large than IT_NEXUS_TIMEOUT */
end_comment

begin_define
define|#
directive|define
name|STP_IDLE_TIME
value|5
end_define

begin_comment
comment|/* 5 us; the defaulf of the controller */
end_comment

begin_define
define|#
directive|define
name|SET_ESGL_EXTEND
parameter_list|(
name|val
parameter_list|)
define|\
value|((val) = (val) | 0x80000000)
end_define

begin_define
define|#
directive|define
name|CLEAR_ESGL_EXTEND
parameter_list|(
name|val
parameter_list|)
define|\
value|((val) = (val)& 0x7FFFFFFF)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressHi)
end_define

begin_comment
comment|/* this macro is based on SAS spec, not sTSDK 0xC0 */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_GET_DEVICETTYPE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->devType_S_Rate& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_LINKRATE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|((devInfo)->devType_S_Rate& 0x0F)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_EXT_MCN
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->ext& 0x7800)>> 11)
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_SMPTO
parameter_list|(
name|devInfo
parameter_list|,
name|smpto
parameter_list|)
define|\
value|((devInfo)->smpTimeout) = smpto
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_ITNEXUSTO
parameter_list|(
name|devInfo
parameter_list|,
name|itnexusto
parameter_list|)
define|\
value|((devInfo)->it_NexusTimeout) = itnexusto
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_FBS
parameter_list|(
name|devInfo
parameter_list|,
name|fbs
parameter_list|)
define|\
value|((devInfo)->firstBurstSize) = fbs
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_FLAG
parameter_list|(
name|devInfo
parameter_list|,
name|tlr
parameter_list|)
define|\
value|((devInfo)->flag) = tlr
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_DEV_S_RATE
parameter_list|(
name|devInfo
parameter_list|,
name|dev_s_rate
parameter_list|)
define|\
value|((devInfo)->devType_S_Rate) = dev_s_rate
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressLo) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressHi) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|DEVICE_SSP_BIT
value|0x8
end_define

begin_comment
comment|/* SSP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_STP_BIT
value|0x4
end_define

begin_comment
comment|/* STP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_SMP_BIT
value|0x2
end_define

begin_comment
comment|/* SMP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_SATA_BIT
value|0x1
end_define

begin_comment
comment|/* SATA device, valid in the discovery response only */
end_comment

begin_define
define|#
directive|define
name|DEVICE_IS_SSP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_SSP_BIT) == DEVICE_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_STP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_STP_BIT) == DEVICE_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SMP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_SMP_BIT) == DEVICE_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SSP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SSP_BIT) == DEVICE_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_STP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_STP_BIT) == DEVICE_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SMP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SMP_BIT) == DEVICE_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SATA_DEVICE
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SATA_BIT) == DEVICE_SATA_BIT)
end_define

begin_comment
comment|/* Negotiated Phyical Link Rate #define Phy_ENABLED_UNKNOWN */
end_comment

begin_comment
comment|/* old SMP header definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdssSMPFrameHeader_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* The first byte of SMP frame represents the SMP FRAME TYPE */
name|bit8
name|smpFunction
decl_stmt|;
comment|/* The second byte of the SMP frame represents the SMP FUNCTION */
name|bit8
name|smpFunctionResult
decl_stmt|;
comment|/* The third byte of SMP frame represents FUNCTION RESULT of the SMP response. */
name|bit8
name|smpReserved
decl_stmt|;
comment|/* reserved */
block|}
name|tdssSMPFrameHeader_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report general request  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportGeneral_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpReqReportGeneral_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report general response  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|REPORT_GENERAL_CONFIGURING_BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_CONFIGURABLE_BIT
value|0x1
end_define

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportGeneral_s
block|{
name|bit8
name|expanderChangeCount16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndexes16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved1
decl_stmt|;
name|bit8
name|numOfPhys
decl_stmt|;
name|bit8
name|configuring_configurable
decl_stmt|;
comment|/* B7-2 : reserved */
comment|/* B1   : configuring */
comment|/* B0   : configurable */
name|bit8
name|reserved4
index|[
literal|17
index|]
decl_stmt|;
block|}
name|smpRespReportGeneral_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REPORT_GENERAL_IS_CONFIGURING
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& REPORT_GENERAL_CONFIGURING_BIT) == \       REPORT_GENERAL_CONFIGURING_BIT)
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_IS_CONFIGURABLE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& REPORT_GENERAL_CONFIGURABLE_BIT) == \       REPORT_GENERAL_CONFIGURABLE_BIT)
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_GET_ROUTEINDEXES
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT16_TO_BIT16(*(bit16 *)((pResp)->expanderRouteIndexes16))
end_define

begin_comment
comment|/****************************************************************  *            report manufacturer info response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportManufactureInfo_s
block|{
name|bit8
name|reserved1
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|vendorIdentification
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|productIdentification
index|[
literal|16
index|]
decl_stmt|;
name|bit8
name|productRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|20
index|]
decl_stmt|;
block|}
name|smpRespReportManufactureInfo_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqDiscover_s
block|{
name|bit32
name|reserved1
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|ignored
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
block|}
name|smpReqDiscover_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespDiscover_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|attachedDeviceType
decl_stmt|;
comment|/* B7   : reserved */
comment|/* B6-4 : attachedDeviceType */
comment|/* B3-0 : reserved */
name|bit8
name|negotiatedPhyLinkRate
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3-0 : negotiatedPhyLinkRate */
name|bit8
name|attached_Ssp_Stp_Smp_Sata_Initiator
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3   : attachedSspInitiator */
comment|/* B2   : attachedStpInitiator */
comment|/* B1   : attachedSmpInitiator */
comment|/* B0   : attachedSataHost */
name|bit8
name|attached_SataPS_Ssp_Stp_Smp_Sata_Target
decl_stmt|;
comment|/* B7   : attachedSataPortSelector */
comment|/* B6-4 : reserved */
comment|/* B3   : attachedSspTarget */
comment|/* B2   : attachedStpTarget */
comment|/* B1   : attachedSmpTarget */
comment|/* B0   : attachedSatadevice */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedPhyIdentifier
decl_stmt|;
name|bit8
name|reserved9
index|[
literal|7
index|]
decl_stmt|;
name|bit8
name|programmedAndHardware_MinPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMinPhyLinkRate */
comment|/* B3-0 : hardwareMinPhyLinkRate */
name|bit8
name|programmedAndHardware_MaxPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMaxPhyLinkRate */
comment|/* B3-0 : hardwareMaxPhyLinkRate */
name|bit8
name|phyChangeCount
decl_stmt|;
name|bit8
name|virtualPhy_partialPathwayTimeout
decl_stmt|;
comment|/* B7   : virtualPhy*/
comment|/* B6-4 : reserved */
comment|/* B3-0 : partialPathwayTimeout */
name|bit8
name|routingAttribute
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3-0 : routingAttribute */
name|bit8
name|reserved13
index|[
literal|5
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpRespDiscover_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DISCRSP_SSP_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|DISCRSP_STP_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DISCRSP_SMP_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|DISCRSP_SATA_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|DISCRSP_SATA_PS_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_DEVTYPE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attachedDeviceType& 0x70)>> 4)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_LINKRATE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((bit8)((pResp)->negotiatedPhyLinkRate& 0x0F))
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SSP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_STP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SMP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_HOST
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SSP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_STP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SMP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_DEVICE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_PORTSELECTOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_PS_BIT) == DISCRSP_SATA_PS_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressHi)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressLo)
end_define

begin_define
define|#
directive|define
name|DISCRSP_VIRTUALPHY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_VIRTUALPHY
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->virtualPhy_partialPathwayTimeout& DISCRSP_VIRTUALPHY_BIT) == DISCRSP_VIRTUALPHY_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ROUTINGATTRIB
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((bit8)((pResp)->routingAttribute& 0x0F))
end_define

begin_comment
comment|/****************************************************************  *            report route table request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpReqReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report route response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabled
decl_stmt|;
comment|/* B7   : expander route entry disabled */
comment|/* B6-0 : reserved */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|smpRespReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route information request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqConfigureRouteInformation_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabledBit_reserved4
decl_stmt|;
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|smpReqConfigureRouteInformation_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespConfigureRouteInformation_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespConfigureRouteInformation_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report Phy Sata request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpReqReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report Phy Sata response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
name|bit8
name|affiliations_sup_valid
decl_stmt|;
comment|/* b7-2 : reserved */
comment|/* b1   : Affiliations supported */
comment|/* b0   : Affiliation valid */
name|bit8
name|reserved5
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|regDevToHostFis
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
block|}
name|smpRespReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqPhyControl_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|phyOperation
decl_stmt|;
name|bit8
name|updatePartialPathwayTOValue
decl_stmt|;
comment|/* b7-1 : reserved */
comment|/* b0   : update partial pathway timeout value */
name|bit8
name|reserved3
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|programmedMinPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Minimum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|programmedMaxPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Maximum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|partialPathwayTOValue
decl_stmt|;
comment|/* b7-4 : reserved */
comment|/* b3-0 : partial Pathway TO Value */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
block|}
name|smpReqPhyControl_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespPhyControl_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespPhyControl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************** ** SCSI SENSE KEY VALUES *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_SNSKEY_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_NOT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_MEDIUM_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_HARDWARE_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_ILLEGAL_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_UNIT_ATTENTION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_DATA_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_ABORTED_COMMAND
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_MISCOMPARE
value|0x0E
end_define

begin_comment
comment|/***************************************************************************** ** SCSI Additional Sense Codes and Qualifiers combo two-bytes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_SNSCODE_NO_ADDITIONAL_INFO
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LUN_CRC_ERROR_DETECTED
value|0x0803
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_COMMAND
value|0x2000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_BLOCK_OUT
value|0x2100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_FIELD_IN_CDB
value|0x2400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_NOT_SUPPORTED
value|0x2500
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_POWERON_RESET
value|0x2900
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_EVERLAPPED_CMDS
value|0x4e00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INTERNAL_TARGET_FAILURE
value|0x4400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_MEDIUM_NOT_PRESENT
value|0x3a00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_UNRECOVERED_READ_ERROR
value|0x1100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_RECORD_NOT_FOUND
value|0x1401
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_NOT_READY_TO_READY_CHANGE
value|0x2800
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_OPERATOR_MEDIUM_REMOVAL_REQUEST
value|0x5a01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INFORMATION_UNIT_CRC_ERROR
value|0x4703
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_FORMAT_IN_PROGRESS
value|0x0404
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_HARDWARE_IMPENDING_FAILURE
value|0x5d10
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOW_POWER_CONDITION_ON
value|0x5e00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_INIT_REQUIRED
value|0x0402
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_FIELD_PARAMETER_LIST
value|0x2600
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_ATA_DEVICE_FAILED_SET_FEATURES
value|0x4471
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_ATA_DEVICE_FEATURE_NOT_ENABLED
value|0x670B
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_FAILED_SELF_TEST
value|0x3E03
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_COMMAND_SEQUENCE_ERROR
value|0x2C00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE
value|0x2100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_FAILURE
value|0x3E01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_MEDIA_LOAD_OR_EJECT_FAILED
value|0x5300
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_INITIALIZING_COMMAND_REQUIRED
value|0x0402
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_CAUSE_NOT_REPORTABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_DOES_NOT_RESPOND_TO_SELECTION
value|0x0500
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_DIAGNOSTIC_FAILURE_ON_COMPONENT_NN
value|0x4000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_COMMANDS_CLEARED_BY_ANOTHER_INITIATOR
value|0x2F00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_WRITE_ERROR_AUTO_REALLOCATION_FAILED
value|0x0C02
end_define

begin_comment
comment|/***************************************************************************** ** SCSI Additional Sense Codes and Qualifiers saparate bytes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_ASC_NOTREADY_INIT_CMD_REQ
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_NOTREADY_INIT_CMD_REQ
value|0x02
end_define

begin_comment
comment|/***************************************************************************** ** Inquiry command fields and response sizes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSIOP_INQUIRY_CMDDT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSIOP_INQUIRY_EVPD
value|0x01
end_define

begin_define
define|#
directive|define
name|STANDARD_INQUIRY_SIZE
value|36
end_define

begin_define
define|#
directive|define
name|SATA_PAGE83_INQUIRY_WWN_SIZE
value|16
end_define

begin_comment
comment|/* SAT, revision8, Table81, p78, 12 + 4 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE83_INQUIRY_NO_WWN_SIZE
value|76
end_define

begin_comment
comment|/* SAT, revision8, Table81, p78, 72 + 4 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE89_INQUIRY_SIZE
value|572
end_define

begin_comment
comment|/* SAT, revision8, Table87, p84 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE0_INQUIRY_SIZE
value|8
end_define

begin_comment
comment|/* SPC-4, 7.6.9   Table331, p345 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE80_INQUIRY_SIZE
value|24
end_define

begin_comment
comment|/* SAT, revision8, Table79, p77 */
end_comment

begin_comment
comment|/* not sure here */
end_comment

begin_comment
comment|/* define byte swap macro */
end_comment

begin_define
define|#
directive|define
name|AGSA_FLIP_2_BYTES
parameter_list|(
name|_x
parameter_list|)
value|((bit16)(((((bit16)(_x))&0x00FF)<<8)|  \                                      ((((bit16)(_x))&0xFF00)>>8)))
end_define

begin_define
define|#
directive|define
name|AGSA_FLIP_4_BYTES
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(((((bit32)(_x))&0x000000FF)<<24)|  \                                      ((((bit32)(_x))&0x0000FF00)<<8)|   \                                      ((((bit32)(_x))&0x00FF0000)>>8)|   \                                      ((((bit32)(_x))&0xFF000000)>>24)))
end_define

begin_comment
comment|/********************************************************************* ** BUFFER CONVERTION MACROS *********************************************************************/
end_comment

begin_comment
comment|/********************************************************************* * CPU buffer access macro                                            * *                                                                    * */
end_comment

begin_define
define|#
directive|define
name|OSSA_OFFSET_OF
parameter_list|(
name|STRUCT_TYPE
parameter_list|,
name|FEILD
parameter_list|)
define|\
value|(bitptr)&(((STRUCT_TYPE *)0)->FEILD)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit16)VALUE16)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit32)VALUE32)>>24)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>16)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR32)+3)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR32)+2)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*(bit8 *)(((bit8 *)ADDR32)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*(bit8 *)(((bit8 *)ADDR32)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit16)VALUE16)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)((((bit32)VALUE32)>>24)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>16)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)ADDR32)+3))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*((bit8 *)(((bit8 *)ADDR32)+2))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*((bit8 *)(((bit8 *)ADDR32)+1))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*((bit8 *)(((bit8 *)ADDR32))))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|(Host CPU endianess undefined!!)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No definition of SA_CPU_BIG_ENDIAN or SA_CPU_LITTLE_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TargetUnknown
value|0
end_define

begin_define
define|#
directive|define
name|TargetRead
value|1
end_define

begin_define
define|#
directive|define
name|TargetWrite
value|2
end_define

begin_define
define|#
directive|define
name|CDB_GRP_MASK
value|0xE0
end_define

begin_comment
comment|/* 1110 0000 */
end_comment

begin_define
define|#
directive|define
name|CDB_6BYTE
value|0x00
end_define

begin_define
define|#
directive|define
name|CDB_10BYTE1
value|0x20
end_define

begin_define
define|#
directive|define
name|CDB_10BYTE2
value|0x40
end_define

begin_define
define|#
directive|define
name|CDB_12BYTE
value|0xA0
end_define

begin_define
define|#
directive|define
name|CDB_16BYTE
value|0x80
end_define

begin_comment
comment|/* ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATA_DEVICE
value|0x01
end_define

begin_comment
comment|/**< ATA ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATAPI_DEVICE
value|0x02
end_define

begin_comment
comment|/**< ATA ATAPI device type */
end_comment

begin_define
define|#
directive|define
name|SATA_PM_DEVICE
value|0x03
end_define

begin_comment
comment|/**< ATA PM device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_DEVICE
value|0x04
end_define

begin_comment
comment|/**< ATA SEMB device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_WO_SEP_DEVICE
value|0x05
end_define

begin_comment
comment|/**< ATA SEMB without SEP device type */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_DEVICE
value|0xFF
end_define

begin_comment
comment|/****************************************************************  *            SATA Specification related defines                *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|SATA_MAX_QUEUED_COMMANDS
value|32
end_define

begin_define
define|#
directive|define
name|SATA_MAX_PM_PORTS
value|15
end_define

begin_comment
comment|/* PMC IOCTL signature */
end_comment

begin_define
define|#
directive|define
name|PMC_IOCTL_SIGNATURE
value|0x1234
end_define

begin_comment
comment|/*  *  FIS type  */
end_comment

begin_define
define|#
directive|define
name|PIO_SETUP_DEV_TO_HOST_FIS
value|0x5F
end_define

begin_define
define|#
directive|define
name|REG_DEV_TO_HOST_FIS
value|0x34
end_define

begin_define
define|#
directive|define
name|SET_DEV_BITS_FIS
value|0xA1
end_define

begin_define
define|#
directive|define
name|TD_ASSERT
value|OS_ASSERT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TD_DISCOVER
end_ifdef

begin_define
define|#
directive|define
name|TDSA_DISCOVERY_OPTION_FULL_START
value|0
end_define

begin_define
define|#
directive|define
name|TDSA_DISCOVERY_OPTION_INCREMENTAL_START
value|1
end_define

begin_define
define|#
directive|define
name|TDSA_DISCOVERY_OPTION_ABORT
value|2
end_define

begin_define
define|#
directive|define
name|TDSA_DISCOVERY_TYPE_SAS
value|0
end_define

begin_define
define|#
directive|define
name|TDSA_DISCOVERY_TYPE_SATA
value|1
end_define

begin_define
define|#
directive|define
name|DISCOVERY_TIMER_VALUE
value|(2 * 1000 * 1000)
end_define

begin_comment
comment|/* 2 seconds */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|CONFIGURE_ROUTE_TIMER_VALUE
value|(1 * 1000 * 1000)
end_define

begin_comment
comment|/* 1 seconds */
end_comment

begin_define
define|#
directive|define
name|DEVICE_REGISTRATION_TIMER_VALUE
value|(2 * 1000 * 1000)
end_define

begin_comment
comment|/* 2 seconds */
end_comment

begin_define
define|#
directive|define
name|SMP_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|SMP_BUSY_TIMER_VALUE
value|(1 * 1000 * 1000)
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|SMP_BUSY_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|SATA_ID_DEVICE_DATA_TIMER_VALUE
value|(3 * 1000 * 1000)
end_define

begin_comment
comment|/* 3 second */
end_comment

begin_define
define|#
directive|define
name|SATA_ID_DEVICE_DATA_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|BC_TIMER_VALUE
value|(5 * 1000 * 1000 )
end_define

begin_comment
comment|/* 5 second */
end_comment

begin_define
define|#
directive|define
name|SMP_TIMER_VALUE
value|(10 * 1000 * 1000)
end_define

begin_comment
comment|/* 10 second */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STP_DEVICE_TYPE
value|0
end_define

begin_comment
comment|/* SATA behind expander 00*/
end_comment

begin_define
define|#
directive|define
name|SAS_DEVICE_TYPE
value|1
end_define

begin_comment
comment|/* SSP or SMP 01 */
end_comment

begin_define
define|#
directive|define
name|SATA_DEVICE_TYPE
value|2
end_define

begin_comment
comment|/* direct SATA 10 */
end_comment

begin_define
define|#
directive|define
name|ATAPI_DEVICE_FLAG
value|0x200000
end_define

begin_comment
comment|/* ATAPI device flag*/
end_comment

begin_define
define|#
directive|define
name|TD_INTERNAL_TM_RESET
value|0xFF
end_define

begin_comment
comment|/* in terms of Kbytes*/
end_comment

begin_define
define|#
directive|define
name|HOST_EVENT_LOG_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_EVENT_LOG_OPTION
value|3
end_define

begin_comment
comment|/* Device state */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_NORMAL
value|0
end_define

begin_comment
comment|/* Normal */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_IN_RECOVERY
value|1
end_define

begin_comment
comment|/* SAT in recovery mode */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_FORMAT_IN_PROGRESS
value|2
end_define

begin_comment
comment|/* Format unit in progress */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_SMART_THRESHOLD
value|3
end_define

begin_comment
comment|/* SMART Threshold Exceeded Condition*/
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_LOW_POWER
value|4
end_define

begin_comment
comment|/* Low Power State*/
end_comment

begin_define
define|#
directive|define
name|TD_GET_PHY_ID
parameter_list|(
name|input
parameter_list|)
value|(input& 0x0F)
end_define

begin_define
define|#
directive|define
name|TD_GET_PHY_NUMS
parameter_list|(
name|input
parameter_list|)
value|((input& 0xF0)>> 4)
end_define

begin_define
define|#
directive|define
name|TD_GET_LINK_RATE
parameter_list|(
name|input
parameter_list|)
value|((input& 0xFF00)>> 8)
end_define

begin_define
define|#
directive|define
name|TD_GET_PORT_STATE
parameter_list|(
name|input
parameter_list|)
value|((input& 0xF0000)>> 16)
end_define

begin_define
define|#
directive|define
name|TD_GET_PHY_STATUS
parameter_list|(
name|input
parameter_list|)
value|((input& 0xFF00)>> 8)
end_define

begin_define
define|#
directive|define
name|TD_GET_RESET_STATUS
parameter_list|(
name|input
parameter_list|)
value|((input& 0xFF00)>> 8)
end_define

begin_define
define|#
directive|define
name|TD_MAX_NUM_NOTIFY_SPINUP
value|20
end_define

begin_define
define|#
directive|define
name|SPC_VPD_SIGNATURE
value|0xFEDCBA98
end_define

begin_define
define|#
directive|define
name|TD_GET_FRAME_TYPE
parameter_list|(
name|input
parameter_list|)
value|(input& 0xFF)
end_define

begin_define
define|#
directive|define
name|TD_GET_TLR
parameter_list|(
name|input
parameter_list|)
value|((input& 0x300)>> 8)
end_define

begin_comment
comment|/* PORT RESET TMO is in 100ms */
end_comment

begin_define
define|#
directive|define
name|SAS_PORT_RESET_TMO
value|3
end_define

begin_comment
comment|/* 300 ms */
end_comment

begin_define
define|#
directive|define
name|SATA_PORT_RESET_TMO
value|80
end_define

begin_comment
comment|/* 8000 ms = 8 sec */
end_comment

begin_define
define|#
directive|define
name|SAS_12G_PORT_RESET_TMO
value|8
end_define

begin_comment
comment|/* 800 ms */
end_comment

begin_comment
comment|/* task attribute based on sTSDK API */
end_comment

begin_define
define|#
directive|define
name|TD_TASK_SIMPLE
value|0x0
end_define

begin_comment
comment|/* Simple        */
end_comment

begin_define
define|#
directive|define
name|TD_TASK_ORDERED
value|0x2
end_define

begin_comment
comment|/* Ordered       */
end_comment

begin_define
define|#
directive|define
name|TD_TASK_HEAD_OF_QUEUE
value|0x1
end_define

begin_comment
comment|/* Head of Queue */
end_comment

begin_define
define|#
directive|define
name|TD_TASK_ACA
value|0x4
end_define

begin_comment
comment|/* ACA           */
end_comment

begin_comment
comment|/* compiler flag for direct smp */
end_comment

begin_define
define|#
directive|define
name|DIRECT_SMP
end_define

begin_comment
comment|//#undef DIRECT_SMP
end_comment

begin_define
define|#
directive|define
name|CONFIGURE_FW_MAX_PORTS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NO_ACK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|OPEN_RETRY_RETRIES
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_CTL
end_ifdef

begin_comment
comment|/* scsi command/page */
end_comment

begin_define
define|#
directive|define
name|MODE_SELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|PAGE_FORMAT
value|0x10
end_define

begin_define
define|#
directive|define
name|DR_MODE_PG_SZ
value|16
end_define

begin_define
define|#
directive|define
name|DR_MODE_PG_CODE
value|0x02
end_define

begin_define
define|#
directive|define
name|DR_MODE_PG_LENGTH
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AGTIAPI_CTL */
end_comment

begin_enum
enum|enum
name|td_locks_e
block|{
comment|/* for tdsaAllShared->FreeDeviceList, tdsaAllShared->MainDeviceList,     oneDeviceData->MainLink, oneDeviceData->FreeLink */
name|TD_DEVICE_LOCK
block|,
comment|/* for tdsaAllShared->FreePortContextList, tdsaAllShared->MainPortContextList,     onePortContext->MainLink, onePortContext->FreeLink */
name|TD_PORT_LOCK
block|,
comment|/* for onePortContext->discovery.discoveringExpanderList,     onePortContext->discovery.UpdiscoveringExpanderList,     tdsaAllShared->freeExpanderList */
name|TD_DISC_LOCK
block|,
comment|/* for onePortContext->discovery.DiscoverySMPTimer,    oneDeviceData->SATAIDDeviceTimer, discovery->discoveryTimer,    discovery->SMPBusyTimer, discovery->BCTimer,    discovery->deviceRegistrationTimer, discovery->configureRouteTimer,    tdsaAllShared->itdsaIni->timerlist, tdsaAllShared->timerlist */
name|TD_TIMER_LOCK
block|,
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
comment|/* for     tdsaAllShared->pEsglAllInfo->freelist     tdsaAllShared->pEsglAllInfo->NumFreeEsglPages     tdsaAllShared->pEsglPageInfo->tdlist */
name|TD_ESGL_LOCK
block|,
comment|/* for satIOContext->pSatDevData->satVerifyState,     satIOContext->pSatDevData->satSectorDone,     satIOContext->pSatDevData->satPendingNCQIO,     satIOContext->pSatDevData->satPendingIO,     satIOContext->pSatDevData->satPendingNONNCQIO,     satIOContext->pSatDevData->satFreeIntIoLinkList,     satIOContext->pSatDevData->satActiveIntIoLinkList,     satIOContext->pSatDevData->freeSATAFDMATagBitmap,     satIOContext->satIoContextLink,     oneDeviceData->satDevData.satIoLinkList */
name|TD_SATA_LOCK
block|,
ifdef|#
directive|ifdef
name|TD_INT_COALESCE
comment|/* for tdsaIntCoalCxt->FreeLink, tdsaIntCoalCxt->MainLink,     tdsaIntCoalCxtHead->FreeLink, tdsaIntCoalCxtHead->MainLink */
name|TD_INTCOAL_LOCK
block|,
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TARGET_DRIVER
comment|/* for tdsaAllShared->ttdsaTgt->ttdsaXchgData.xchgFreeList,     tdsaAllShared->ttdsaTgt->ttdsaXchgData.xchgBusyList */
name|TD_TGT_LOCK
block|,
endif|#
directive|endif
name|TD_MAX_LOCKS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|TD_GET_SAS_ADDRESSLO
parameter_list|(
name|sasAddressLo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressLo)
end_define

begin_define
define|#
directive|define
name|TD_GET_SAS_ADDRESSHI
parameter_list|(
name|sasAddressHi
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressHi)
end_define

begin_define
define|#
directive|define
name|TD_XFER_RDY_PRIORTY_DEVICE_FLAG
value|(1<< 22)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_DM
end_ifdef

begin_comment
comment|/* bit32 -> bit8 array[4] */
end_comment

begin_define
define|#
directive|define
name|PORTINFO_PUT_SAS_LOCAL_ADDRESSLO
parameter_list|(
name|portInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((portInfo)->sasLocalAddressLo) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|PORTINFO_PUT_SAS_LOCAL_ADDRESSHI
parameter_list|(
name|portInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((portInfo)->sasLocalAddressHi) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_comment
comment|/* bit32 -> bit8 array[4] */
end_comment

begin_define
define|#
directive|define
name|PORTINFO_PUT_SAS_REMOTE_ADDRESSLO
parameter_list|(
name|portInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((portInfo)->sasRemoteAddressLo) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|PORTINFO_PUT_SAS_REMOTE_ADDRESSHI
parameter_list|(
name|portInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((portInfo)->sasRemoteAddressHi) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FDS_DM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_SM
end_ifdef

begin_comment
comment|/* this applies to ID data and all other SATA IOs */
end_comment

begin_define
define|#
directive|define
name|SM_RETRIES
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TI_TIROOT_TO_tdsaRoot
parameter_list|(
name|t_r
parameter_list|)
value|(((tdsaRoot_t *)((tiRoot_t *)t_r)->tdData) )
end_define

begin_define
define|#
directive|define
name|TI_TIROOT_TO_tdsaAllShared
parameter_list|(
name|t_r1
parameter_list|)
value|(tdsaContext_t *)&(t_r1->tdsaAllShared)
end_define

begin_define
define|#
directive|define
name|TI_TIROOT_TO_agroot
parameter_list|(
name|t_r2
parameter_list|)
value|(agsaRoot_t *)&((t_r2)->agRootNonInt)
end_define

begin_define
define|#
directive|define
name|TI_TIROOT_TO_AGROOT
parameter_list|(
name|t_root
parameter_list|)
value|(TI_TIROOT_TO_agroot(TI_TIROOT_TO_tdsaAllShared(TI_TIROOT_TO_tdsaRoot(t_root)) ))
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC
value|0x80010000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCADAP
value|0x80810000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCv
value|0x80080000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCve
value|0x80090000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCvplus
value|0x80180000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCveplus
value|0x80190000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCADAPvplus
value|0x80880000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPCADAPveplus
value|0x80890000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12Gv
value|0x80700000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12Gve
value|0x80710000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12Gvplus
value|0x80720000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12Gveplus
value|0x80730000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_9015
value|0x90150000
end_define

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12ADP
value|0x80740000
end_define

begin_comment
comment|/* 8 ports KBP added*/
end_comment

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12ADPP
value|0x80760000
end_define

begin_comment
comment|/* 16 ports  */
end_comment

begin_define
define|#
directive|define
name|TI_VEN_DEV_SPC12SATA
value|0x80060000
end_define

begin_comment
comment|/* SATA HBA */
end_comment

begin_define
define|#
directive|define
name|TI_VEN_DEV_9060
value|0x90600000
end_define

begin_define
define|#
directive|define
name|tIsSPC
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC           == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|tIsSPCHIL
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCADAP       == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|tIsSPCv
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCv          == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|tIsSPCve
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCve         == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve */
end_comment

begin_define
define|#
directive|define
name|tIsSPCvplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCvplus      == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPCveplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCveplus     == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPCADAPvplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCADAPvplus  == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPCADAPveplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPCADAPveplus == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPC12Gv
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12Gv       == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gv */
end_comment

begin_define
define|#
directive|define
name|tIsSPC12Gve
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12Gve      == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gve */
end_comment

begin_define
define|#
directive|define
name|tIsSPC12Gvplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12Gvplus   == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gv+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPC12Gveplus
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12Gveplus  == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gve+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPC9015
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_9015          == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gve+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPC9060
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_9060          == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12Gve+ */
end_comment

begin_define
define|#
directive|define
name|tIsSPC12ADP
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12ADP      == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|tIsSPC12ADPP
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12ADPP     == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|tIsSPC12SATA
parameter_list|(
name|agr
parameter_list|)
value|(TI_VEN_DEV_SPC12SATA     == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|tiIS_SPC
parameter_list|(
name|agr
parameter_list|)
value|(( tIsSPC((agr))    == 1) ? 1 : \                        ( tIsSPCHIL((agr)) == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tiIS_HIL
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPCHIL ((agr))       == 1) ? 1 : \                        (tIsSPCADAPvplus((agr))  == 1) ? 1 : \                        (tIsSPCADAPveplus((agr)) == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tiIS_SPC6V
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPCv((agr))          == 1) ? 1 : \                          (tIsSPCve((agr))         == 1) ? 1 : \                          (tIsSPCvplus((agr))      == 1) ? 1 : \                          (tIsSPCveplus((agr))     == 1) ? 1 : \                          (tIsSPCADAPvplus((agr))  == 1) ? 1 : \                          (tIsSPCADAPveplus((agr)) == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tIsSPCV12G
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPC12Gv(agr) == 1)     ? 1 : \                            (tIsSPC12Gve(agr) == 1)    ? 1 : \                            (tIsSPC12Gvplus(agr)== 1)  ? 1 : \                            (tIsSPC12Gveplus(agr)== 1) ? 1 : \                            (tIsSPC9015(agr)== 1)      ? 1 : \                            (tIsSPC12ADP(agr)== 1)     ? 1 : \                            (tIsSPC12ADPP(agr)== 1)    ? 1 : \                            (tIsSPC12SATA(agr)   == 1) ? 1 : \                            (tIsSPC9060(agr)     == 1) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|tiIS_8PHY
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPCv((agr))     == 1) ? 1 : \                         (tIsSPCve((agr))    == 1) ? 1 : \                         (tIsSPC12Gv((agr))  == 1) ? 1 : \                         (tIsSPC12Gve((agr)) == 1) ? 1 : \                         (tIsSPC12ADP(agr)   == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tiIS_16PHY
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPCvplus((agr))      == 1) ? 1 : \                          (tIsSPCveplus((agr))     == 1) ? 1 : \                          (tIsSPCADAPvplus((agr))  == 1) ? 1 : \                          (tIsSPCADAPveplus((agr)) == 1) ? 1 : \                          (tIsSPC12ADPP(agr)       == 1) ? 1 : \                          (tIsSPC12SATA(agr)       == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tiIS_SPC_ENC
parameter_list|(
name|agr
parameter_list|)
value|((tIsSPCve((agr))         == 1) ? 1 : \                           (tIsSPCveplus((agr))     == 1) ? 1 : \                           (tIsSPCADAPveplus((agr)) == 1) ? 1 : 0 )
end_define

begin_define
define|#
directive|define
name|tIsSPCV12or6G
parameter_list|(
name|agr
parameter_list|)
value|((tiIS_SPC6V(agr) == 1) ? 1 : \                              (tIsSPCV12G(agr) == 1) ? 1 :  0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TDDEFS_H__ */
end_comment

end_unit

