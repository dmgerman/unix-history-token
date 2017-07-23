begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012-2013 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NVME_H__
end_ifndef

begin_define
define|#
directive|define
name|__NVME_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|NVME_PASSTHROUGH_CMD
value|_IOWR('n', 0, struct nvme_pt_command)
end_define

begin_define
define|#
directive|define
name|NVME_RESET_CONTROLLER
value|_IO('n', 1)
end_define

begin_define
define|#
directive|define
name|NVME_IO_TEST
value|_IOWR('n', 100, struct nvme_io_test)
end_define

begin_define
define|#
directive|define
name|NVME_BIO_TEST
value|_IOWR('n', 101, struct nvme_io_test)
end_define

begin_comment
comment|/*  * Use to mark a command to apply to all namespaces, or to retrieve global  *  log pages.  */
end_comment

begin_define
define|#
directive|define
name|NVME_GLOBAL_NAMESPACE_TAG
value|((uint32_t)0xFFFFFFFF)
end_define

begin_comment
comment|/* Cap nvme to 1MB transfers driver explodes with larger sizes */
end_comment

begin_define
define|#
directive|define
name|NVME_MAX_XFER_SIZE
value|(MAXPHYS< (1<<20) ? MAXPHYS : (1<<20))
end_define

begin_union
union|union
name|cap_lo_register
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
comment|/** maximum queue entries supported */
name|uint32_t
name|mqes
range|:
literal|16
decl_stmt|;
comment|/** contiguous queues required */
name|uint32_t
name|cqr
range|:
literal|1
decl_stmt|;
comment|/** arbitration mechanism supported */
name|uint32_t
name|ams
range|:
literal|2
decl_stmt|;
name|uint32_t
name|reserved1
range|:
literal|5
decl_stmt|;
comment|/** timeout */
name|uint32_t
name|to
range|:
literal|8
decl_stmt|;
block|}
name|bits
name|__packed
struct|;
block|}
name|__packed
union|;
end_union

begin_union
union|union
name|cap_hi_register
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
comment|/** doorbell stride */
name|uint32_t
name|dstrd
range|:
literal|4
decl_stmt|;
name|uint32_t
name|reserved3
range|:
literal|1
decl_stmt|;
comment|/** command sets supported */
name|uint32_t
name|css_nvm
range|:
literal|1
decl_stmt|;
name|uint32_t
name|css_reserved
range|:
literal|3
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|7
decl_stmt|;
comment|/** memory page size minimum */
name|uint32_t
name|mpsmin
range|:
literal|4
decl_stmt|;
comment|/** memory page size maximum */
name|uint32_t
name|mpsmax
range|:
literal|4
decl_stmt|;
name|uint32_t
name|reserved1
range|:
literal|8
decl_stmt|;
block|}
name|bits
name|__packed
struct|;
block|}
name|__packed
union|;
end_union

begin_union
union|union
name|cc_register
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
comment|/** enable */
name|uint32_t
name|en
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved1
range|:
literal|3
decl_stmt|;
comment|/** i/o command set selected */
name|uint32_t
name|css
range|:
literal|3
decl_stmt|;
comment|/** memory page size */
name|uint32_t
name|mps
range|:
literal|4
decl_stmt|;
comment|/** arbitration mechanism selected */
name|uint32_t
name|ams
range|:
literal|3
decl_stmt|;
comment|/** shutdown notification */
name|uint32_t
name|shn
range|:
literal|2
decl_stmt|;
comment|/** i/o submission queue entry size */
name|uint32_t
name|iosqes
range|:
literal|4
decl_stmt|;
comment|/** i/o completion queue entry size */
name|uint32_t
name|iocqes
range|:
literal|4
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|8
decl_stmt|;
block|}
name|bits
name|__packed
struct|;
block|}
name|__packed
union|;
end_union

begin_enum
enum|enum
name|shn_value
block|{
name|NVME_SHN_NORMAL
init|=
literal|0x1
block|,
name|NVME_SHN_ABRUPT
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_union
union|union
name|csts_register
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
comment|/** ready */
name|uint32_t
name|rdy
range|:
literal|1
decl_stmt|;
comment|/** controller fatal status */
name|uint32_t
name|cfs
range|:
literal|1
decl_stmt|;
comment|/** shutdown status */
name|uint32_t
name|shst
range|:
literal|2
decl_stmt|;
name|uint32_t
name|reserved1
range|:
literal|28
decl_stmt|;
block|}
name|bits
name|__packed
struct|;
block|}
name|__packed
union|;
end_union

begin_enum
enum|enum
name|shst_value
block|{
name|NVME_SHST_NORMAL
init|=
literal|0x0
block|,
name|NVME_SHST_OCCURRING
init|=
literal|0x1
block|,
name|NVME_SHST_COMPLETE
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_union
union|union
name|aqa_register
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
comment|/** admin submission queue size */
name|uint32_t
name|asqs
range|:
literal|12
decl_stmt|;
name|uint32_t
name|reserved1
range|:
literal|4
decl_stmt|;
comment|/** admin completion queue size */
name|uint32_t
name|acqs
range|:
literal|12
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|4
decl_stmt|;
block|}
name|bits
name|__packed
struct|;
block|}
name|__packed
union|;
end_union

begin_struct
struct|struct
name|nvme_registers
block|{
comment|/** controller capabilities */
name|union
name|cap_lo_register
name|cap_lo
decl_stmt|;
name|union
name|cap_hi_register
name|cap_hi
decl_stmt|;
name|uint32_t
name|vs
decl_stmt|;
comment|/* version */
name|uint32_t
name|intms
decl_stmt|;
comment|/* interrupt mask set */
name|uint32_t
name|intmc
decl_stmt|;
comment|/* interrupt mask clear */
comment|/** controller configuration */
name|union
name|cc_register
name|cc
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
comment|/** controller status */
name|union
name|csts_register
name|csts
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
comment|/** admin queue attributes */
name|union
name|aqa_register
name|aqa
decl_stmt|;
name|uint64_t
name|asq
decl_stmt|;
comment|/* admin submission queue base addr */
name|uint64_t
name|acq
decl_stmt|;
comment|/* admin completion queue base addr */
name|uint32_t
name|reserved3
index|[
literal|0x3f2
index|]
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|sq_tdbl
decl_stmt|;
comment|/* submission queue tail doorbell */
name|uint32_t
name|cq_hdbl
decl_stmt|;
comment|/* completion queue head doorbell */
block|}
name|doorbell
index|[
literal|1
index|]
name|__packed
struct|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nvme_command
block|{
comment|/* dword 0 */
name|uint16_t
name|opc
range|:
literal|8
decl_stmt|;
comment|/* opcode */
name|uint16_t
name|fuse
range|:
literal|2
decl_stmt|;
comment|/* fused operation */
name|uint16_t
name|rsvd1
range|:
literal|6
decl_stmt|;
name|uint16_t
name|cid
decl_stmt|;
comment|/* command identifier */
comment|/* dword 1 */
name|uint32_t
name|nsid
decl_stmt|;
comment|/* namespace identifier */
comment|/* dword 2-3 */
name|uint32_t
name|rsvd2
decl_stmt|;
name|uint32_t
name|rsvd3
decl_stmt|;
comment|/* dword 4-5 */
name|uint64_t
name|mptr
decl_stmt|;
comment|/* metadata pointer */
comment|/* dword 6-7 */
name|uint64_t
name|prp1
decl_stmt|;
comment|/* prp entry 1 */
comment|/* dword 8-9 */
name|uint64_t
name|prp2
decl_stmt|;
comment|/* prp entry 2 */
comment|/* dword 10-15 */
name|uint32_t
name|cdw10
decl_stmt|;
comment|/* command-specific */
name|uint32_t
name|cdw11
decl_stmt|;
comment|/* command-specific */
name|uint32_t
name|cdw12
decl_stmt|;
comment|/* command-specific */
name|uint32_t
name|cdw13
decl_stmt|;
comment|/* command-specific */
name|uint32_t
name|cdw14
decl_stmt|;
comment|/* command-specific */
name|uint32_t
name|cdw15
decl_stmt|;
comment|/* command-specific */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nvme_status
block|{
name|uint16_t
name|p
range|:
literal|1
decl_stmt|;
comment|/* phase tag */
name|uint16_t
name|sc
range|:
literal|8
decl_stmt|;
comment|/* status code */
name|uint16_t
name|sct
range|:
literal|3
decl_stmt|;
comment|/* status code type */
name|uint16_t
name|rsvd2
range|:
literal|2
decl_stmt|;
name|uint16_t
name|m
range|:
literal|1
decl_stmt|;
comment|/* more */
name|uint16_t
name|dnr
range|:
literal|1
decl_stmt|;
comment|/* do not retry */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nvme_completion
block|{
comment|/* dword 0 */
name|uint32_t
name|cdw0
decl_stmt|;
comment|/* command-specific */
comment|/* dword 1 */
name|uint32_t
name|rsvd1
decl_stmt|;
comment|/* dword 2 */
name|uint16_t
name|sqhd
decl_stmt|;
comment|/* submission queue head pointer */
name|uint16_t
name|sqid
decl_stmt|;
comment|/* submission queue identifier */
comment|/* dword 3 */
name|uint16_t
name|cid
decl_stmt|;
comment|/* command identifier */
name|struct
name|nvme_status
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nvme_dsm_range
block|{
name|uint32_t
name|attributes
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint64_t
name|starting_lba
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* status code types */
end_comment

begin_enum
enum|enum
name|nvme_status_code_type
block|{
name|NVME_SCT_GENERIC
init|=
literal|0x0
block|,
name|NVME_SCT_COMMAND_SPECIFIC
init|=
literal|0x1
block|,
name|NVME_SCT_MEDIA_ERROR
init|=
literal|0x2
block|,
comment|/* 0x3-0x6 - reserved */
name|NVME_SCT_VENDOR_SPECIFIC
init|=
literal|0x7
block|, }
enum|;
end_enum

begin_comment
comment|/* generic command status codes */
end_comment

begin_enum
enum|enum
name|nvme_generic_command_status_code
block|{
name|NVME_SC_SUCCESS
init|=
literal|0x00
block|,
name|NVME_SC_INVALID_OPCODE
init|=
literal|0x01
block|,
name|NVME_SC_INVALID_FIELD
init|=
literal|0x02
block|,
name|NVME_SC_COMMAND_ID_CONFLICT
init|=
literal|0x03
block|,
name|NVME_SC_DATA_TRANSFER_ERROR
init|=
literal|0x04
block|,
name|NVME_SC_ABORTED_POWER_LOSS
init|=
literal|0x05
block|,
name|NVME_SC_INTERNAL_DEVICE_ERROR
init|=
literal|0x06
block|,
name|NVME_SC_ABORTED_BY_REQUEST
init|=
literal|0x07
block|,
name|NVME_SC_ABORTED_SQ_DELETION
init|=
literal|0x08
block|,
name|NVME_SC_ABORTED_FAILED_FUSED
init|=
literal|0x09
block|,
name|NVME_SC_ABORTED_MISSING_FUSED
init|=
literal|0x0a
block|,
name|NVME_SC_INVALID_NAMESPACE_OR_FORMAT
init|=
literal|0x0b
block|,
name|NVME_SC_COMMAND_SEQUENCE_ERROR
init|=
literal|0x0c
block|,
name|NVME_SC_LBA_OUT_OF_RANGE
init|=
literal|0x80
block|,
name|NVME_SC_CAPACITY_EXCEEDED
init|=
literal|0x81
block|,
name|NVME_SC_NAMESPACE_NOT_READY
init|=
literal|0x82
block|, }
enum|;
end_enum

begin_comment
comment|/* command specific status codes */
end_comment

begin_enum
enum|enum
name|nvme_command_specific_status_code
block|{
name|NVME_SC_COMPLETION_QUEUE_INVALID
init|=
literal|0x00
block|,
name|NVME_SC_INVALID_QUEUE_IDENTIFIER
init|=
literal|0x01
block|,
name|NVME_SC_MAXIMUM_QUEUE_SIZE_EXCEEDED
init|=
literal|0x02
block|,
name|NVME_SC_ABORT_COMMAND_LIMIT_EXCEEDED
init|=
literal|0x03
block|,
comment|/* 0x04 - reserved */
name|NVME_SC_ASYNC_EVENT_REQUEST_LIMIT_EXCEEDED
init|=
literal|0x05
block|,
name|NVME_SC_INVALID_FIRMWARE_SLOT
init|=
literal|0x06
block|,
name|NVME_SC_INVALID_FIRMWARE_IMAGE
init|=
literal|0x07
block|,
name|NVME_SC_INVALID_INTERRUPT_VECTOR
init|=
literal|0x08
block|,
name|NVME_SC_INVALID_LOG_PAGE
init|=
literal|0x09
block|,
name|NVME_SC_INVALID_FORMAT
init|=
literal|0x0a
block|,
name|NVME_SC_FIRMWARE_REQUIRES_RESET
init|=
literal|0x0b
block|,
name|NVME_SC_CONFLICTING_ATTRIBUTES
init|=
literal|0x80
block|,
name|NVME_SC_INVALID_PROTECTION_INFO
init|=
literal|0x81
block|,
name|NVME_SC_ATTEMPTED_WRITE_TO_RO_PAGE
init|=
literal|0x82
block|, }
enum|;
end_enum

begin_comment
comment|/* media error status codes */
end_comment

begin_enum
enum|enum
name|nvme_media_error_status_code
block|{
name|NVME_SC_WRITE_FAULTS
init|=
literal|0x80
block|,
name|NVME_SC_UNRECOVERED_READ_ERROR
init|=
literal|0x81
block|,
name|NVME_SC_GUARD_CHECK_ERROR
init|=
literal|0x82
block|,
name|NVME_SC_APPLICATION_TAG_CHECK_ERROR
init|=
literal|0x83
block|,
name|NVME_SC_REFERENCE_TAG_CHECK_ERROR
init|=
literal|0x84
block|,
name|NVME_SC_COMPARE_FAILURE
init|=
literal|0x85
block|,
name|NVME_SC_ACCESS_DENIED
init|=
literal|0x86
block|, }
enum|;
end_enum

begin_comment
comment|/* admin opcodes */
end_comment

begin_enum
enum|enum
name|nvme_admin_opcode
block|{
name|NVME_OPC_DELETE_IO_SQ
init|=
literal|0x00
block|,
name|NVME_OPC_CREATE_IO_SQ
init|=
literal|0x01
block|,
name|NVME_OPC_GET_LOG_PAGE
init|=
literal|0x02
block|,
comment|/* 0x03 - reserved */
name|NVME_OPC_DELETE_IO_CQ
init|=
literal|0x04
block|,
name|NVME_OPC_CREATE_IO_CQ
init|=
literal|0x05
block|,
name|NVME_OPC_IDENTIFY
init|=
literal|0x06
block|,
comment|/* 0x07 - reserved */
name|NVME_OPC_ABORT
init|=
literal|0x08
block|,
name|NVME_OPC_SET_FEATURES
init|=
literal|0x09
block|,
name|NVME_OPC_GET_FEATURES
init|=
literal|0x0a
block|,
comment|/* 0x0b - reserved */
name|NVME_OPC_ASYNC_EVENT_REQUEST
init|=
literal|0x0c
block|,
name|NVME_OPC_NAMESPACE_MANAGEMENT
init|=
literal|0x0d
block|,
comment|/* 0x0e-0x0f - reserved */
name|NVME_OPC_FIRMWARE_ACTIVATE
init|=
literal|0x10
block|,
name|NVME_OPC_FIRMWARE_IMAGE_DOWNLOAD
init|=
literal|0x11
block|,
name|NVME_OPC_NAMESPACE_ATTACHMENT
init|=
literal|0x15
block|,
name|NVME_OPC_FORMAT_NVM
init|=
literal|0x80
block|,
name|NVME_OPC_SECURITY_SEND
init|=
literal|0x81
block|,
name|NVME_OPC_SECURITY_RECEIVE
init|=
literal|0x82
block|, }
enum|;
end_enum

begin_comment
comment|/* nvme nvm opcodes */
end_comment

begin_enum
enum|enum
name|nvme_nvm_opcode
block|{
name|NVME_OPC_FLUSH
init|=
literal|0x00
block|,
name|NVME_OPC_WRITE
init|=
literal|0x01
block|,
name|NVME_OPC_READ
init|=
literal|0x02
block|,
comment|/* 0x03 - reserved */
name|NVME_OPC_WRITE_UNCORRECTABLE
init|=
literal|0x04
block|,
name|NVME_OPC_COMPARE
init|=
literal|0x05
block|,
comment|/* 0x06-0x07 - reserved */
name|NVME_OPC_DATASET_MANAGEMENT
init|=
literal|0x09
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|nvme_feature
block|{
comment|/* 0x00 - reserved */
name|NVME_FEAT_ARBITRATION
init|=
literal|0x01
block|,
name|NVME_FEAT_POWER_MANAGEMENT
init|=
literal|0x02
block|,
name|NVME_FEAT_LBA_RANGE_TYPE
init|=
literal|0x03
block|,
name|NVME_FEAT_TEMPERATURE_THRESHOLD
init|=
literal|0x04
block|,
name|NVME_FEAT_ERROR_RECOVERY
init|=
literal|0x05
block|,
name|NVME_FEAT_VOLATILE_WRITE_CACHE
init|=
literal|0x06
block|,
name|NVME_FEAT_NUMBER_OF_QUEUES
init|=
literal|0x07
block|,
name|NVME_FEAT_INTERRUPT_COALESCING
init|=
literal|0x08
block|,
name|NVME_FEAT_INTERRUPT_VECTOR_CONFIGURATION
init|=
literal|0x09
block|,
name|NVME_FEAT_WRITE_ATOMICITY
init|=
literal|0x0A
block|,
name|NVME_FEAT_ASYNC_EVENT_CONFIGURATION
init|=
literal|0x0B
block|,
comment|/* 0x0C-0x7F - reserved */
name|NVME_FEAT_SOFTWARE_PROGRESS_MARKER
init|=
literal|0x80
block|,
comment|/* 0x81-0xBF - command set specific (reserved) */
comment|/* 0xC0-0xFF - vendor specific */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nvme_dsm_attribute
block|{
name|NVME_DSM_ATTR_INTEGRAL_READ
init|=
literal|0x1
block|,
name|NVME_DSM_ATTR_INTEGRAL_WRITE
init|=
literal|0x2
block|,
name|NVME_DSM_ATTR_DEALLOCATE
init|=
literal|0x4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|nvme_activate_action
block|{
name|NVME_AA_REPLACE_NO_ACTIVATE
init|=
literal|0x0
block|,
name|NVME_AA_REPLACE_ACTIVATE
init|=
literal|0x1
block|,
name|NVME_AA_ACTIVATE
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|nvme_power_state
block|{
comment|/** Maximum Power */
name|uint16_t
name|mp
decl_stmt|;
comment|/* Maximum Power */
name|uint8_t
name|ps_rsvd1
decl_stmt|;
name|uint8_t
name|mps
range|:
literal|1
decl_stmt|;
comment|/* Max Power Scale */
name|uint8_t
name|nops
range|:
literal|1
decl_stmt|;
comment|/* Non-Operational State */
name|uint8_t
name|ps_rsvd2
range|:
literal|6
decl_stmt|;
name|uint32_t
name|enlat
decl_stmt|;
comment|/* Entry Latency */
name|uint32_t
name|exlat
decl_stmt|;
comment|/* Exit Latency */
name|uint8_t
name|rrt
range|:
literal|5
decl_stmt|;
comment|/* Relative Read Throughput */
name|uint8_t
name|ps_rsvd3
range|:
literal|3
decl_stmt|;
name|uint8_t
name|rrl
range|:
literal|5
decl_stmt|;
comment|/* Relative Read Latency */
name|uint8_t
name|ps_rsvd4
range|:
literal|3
decl_stmt|;
name|uint8_t
name|rwt
range|:
literal|5
decl_stmt|;
comment|/* Relative Write Throughput */
name|uint8_t
name|ps_rsvd5
range|:
literal|3
decl_stmt|;
name|uint8_t
name|rwl
range|:
literal|5
decl_stmt|;
comment|/* Relative Write Latency */
name|uint8_t
name|ps_rsvd6
range|:
literal|3
decl_stmt|;
name|uint16_t
name|idlp
decl_stmt|;
comment|/* Idle Power */
name|uint8_t
name|ps_rsvd7
range|:
literal|6
decl_stmt|;
name|uint8_t
name|ips
range|:
literal|2
decl_stmt|;
comment|/* Idle Power Scale */
name|uint8_t
name|ps_rsvd8
decl_stmt|;
name|uint16_t
name|actp
decl_stmt|;
comment|/* Active Power */
name|uint8_t
name|apw
range|:
literal|3
decl_stmt|;
comment|/* Active Power Workload */
name|uint8_t
name|ps_rsvd9
range|:
literal|3
decl_stmt|;
name|uint8_t
name|aps
range|:
literal|2
decl_stmt|;
comment|/* Active Power Scale */
name|uint8_t
name|ps_rsvd10
index|[
literal|9
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|NVME_SERIAL_NUMBER_LENGTH
value|20
end_define

begin_define
define|#
directive|define
name|NVME_MODEL_NUMBER_LENGTH
value|40
end_define

begin_define
define|#
directive|define
name|NVME_FIRMWARE_REVISION_LENGTH
value|8
end_define

begin_struct
struct|struct
name|nvme_controller_data
block|{
comment|/* bytes 0-255: controller capabilities and features */
comment|/** pci vendor id */
name|uint16_t
name|vid
decl_stmt|;
comment|/** pci subsystem vendor id */
name|uint16_t
name|ssvid
decl_stmt|;
comment|/** serial number */
name|uint8_t
name|sn
index|[
name|NVME_SERIAL_NUMBER_LENGTH
index|]
decl_stmt|;
comment|/** model number */
name|uint8_t
name|mn
index|[
name|NVME_MODEL_NUMBER_LENGTH
index|]
decl_stmt|;
comment|/** firmware revision */
name|uint8_t
name|fr
index|[
name|NVME_FIRMWARE_REVISION_LENGTH
index|]
decl_stmt|;
comment|/** recommended arbitration burst */
name|uint8_t
name|rab
decl_stmt|;
comment|/** ieee oui identifier */
name|uint8_t
name|ieee
index|[
literal|3
index|]
decl_stmt|;
comment|/** multi-interface capabilities */
name|uint8_t
name|mic
decl_stmt|;
comment|/** maximum data transfer size */
name|uint8_t
name|mdts
decl_stmt|;
comment|/** Controller ID */
name|uint16_t
name|ctrlr_id
decl_stmt|;
name|uint8_t
name|reserved1
index|[
literal|176
index|]
decl_stmt|;
comment|/* bytes 256-511: admin command set attributes */
comment|/** optional admin command support */
struct|struct
block|{
comment|/* supports security send/receive commands */
name|uint16_t
name|security
range|:
literal|1
decl_stmt|;
comment|/* supports format nvm command */
name|uint16_t
name|format
range|:
literal|1
decl_stmt|;
comment|/* supports firmware activate/download commands */
name|uint16_t
name|firmware
range|:
literal|1
decl_stmt|;
comment|/* supports namespace management commands */
name|uint16_t
name|nsmgmt
range|:
literal|1
decl_stmt|;
name|uint16_t
name|oacs_rsvd
range|:
literal|12
decl_stmt|;
block|}
name|__packed
name|oacs
struct|;
comment|/** abort command limit */
name|uint8_t
name|acl
decl_stmt|;
comment|/** asynchronous event request limit */
name|uint8_t
name|aerl
decl_stmt|;
comment|/** firmware updates */
struct|struct
block|{
comment|/* first slot is read-only */
name|uint8_t
name|slot1_ro
range|:
literal|1
decl_stmt|;
comment|/* number of firmware slots */
name|uint8_t
name|num_slots
range|:
literal|3
decl_stmt|;
name|uint8_t
name|frmw_rsvd
range|:
literal|4
decl_stmt|;
block|}
name|__packed
name|frmw
struct|;
comment|/** log page attributes */
struct|struct
block|{
comment|/* per namespace smart/health log page */
name|uint8_t
name|ns_smart
range|:
literal|1
decl_stmt|;
name|uint8_t
name|lpa_rsvd
range|:
literal|7
decl_stmt|;
block|}
name|__packed
name|lpa
struct|;
comment|/** error log page entries */
name|uint8_t
name|elpe
decl_stmt|;
comment|/** number of power states supported */
name|uint8_t
name|npss
decl_stmt|;
comment|/** admin vendor specific command configuration */
struct|struct
block|{
comment|/* admin vendor specific commands use spec format */
name|uint8_t
name|spec_format
range|:
literal|1
decl_stmt|;
name|uint8_t
name|avscc_rsvd
range|:
literal|7
decl_stmt|;
block|}
name|__packed
name|avscc
struct|;
name|uint8_t
name|reserved2
index|[
literal|15
index|]
decl_stmt|;
comment|/** Name space capabilities  */
struct|struct
block|{
comment|/* if nsmgmt, report tnvmcap and unvmcap */
name|uint8_t
name|tnvmcap
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|unvmcap
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
name|untncap
struct|;
name|uint8_t
name|reserved3
index|[
literal|200
index|]
decl_stmt|;
comment|/* bytes 512-703: nvm command set attributes */
comment|/** submission queue entry size */
struct|struct
block|{
name|uint8_t
name|min
range|:
literal|4
decl_stmt|;
name|uint8_t
name|max
range|:
literal|4
decl_stmt|;
block|}
name|__packed
name|sqes
struct|;
comment|/** completion queue entry size */
struct|struct
block|{
name|uint8_t
name|min
range|:
literal|4
decl_stmt|;
name|uint8_t
name|max
range|:
literal|4
decl_stmt|;
block|}
name|__packed
name|cqes
struct|;
name|uint8_t
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
comment|/** number of namespaces */
name|uint32_t
name|nn
decl_stmt|;
comment|/** optional nvm command support */
struct|struct
block|{
name|uint16_t
name|compare
range|:
literal|1
decl_stmt|;
name|uint16_t
name|write_unc
range|:
literal|1
decl_stmt|;
name|uint16_t
name|dsm
range|:
literal|1
decl_stmt|;
name|uint16_t
name|reserved
range|:
literal|13
decl_stmt|;
block|}
name|__packed
name|oncs
struct|;
comment|/** fused operation support */
name|uint16_t
name|fuses
decl_stmt|;
comment|/** format nvm attributes */
name|uint8_t
name|fna
decl_stmt|;
comment|/** volatile write cache */
struct|struct
block|{
name|uint8_t
name|present
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved
range|:
literal|7
decl_stmt|;
block|}
name|__packed
name|vwc
struct|;
comment|/* TODO: flesh out remaining nvm command set attributes */
name|uint8_t
name|reserved5
index|[
literal|178
index|]
decl_stmt|;
comment|/* bytes 704-2047: i/o command set attributes */
name|uint8_t
name|reserved6
index|[
literal|1344
index|]
decl_stmt|;
comment|/* bytes 2048-3071: power state descriptors */
name|struct
name|nvme_power_state
name|power_state
index|[
literal|32
index|]
decl_stmt|;
comment|/* bytes 3072-4095: vendor specific */
name|uint8_t
name|vs
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|nvme_namespace_data
block|{
comment|/** namespace size */
name|uint64_t
name|nsze
decl_stmt|;
comment|/** namespace capacity */
name|uint64_t
name|ncap
decl_stmt|;
comment|/** namespace utilization */
name|uint64_t
name|nuse
decl_stmt|;
comment|/** namespace features */
struct|struct
block|{
comment|/** thin provisioning */
name|uint8_t
name|thin_prov
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved1
range|:
literal|7
decl_stmt|;
block|}
name|__packed
name|nsfeat
struct|;
comment|/** number of lba formats */
name|uint8_t
name|nlbaf
decl_stmt|;
comment|/** formatted lba size */
struct|struct
block|{
name|uint8_t
name|format
range|:
literal|4
decl_stmt|;
name|uint8_t
name|extended
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved2
range|:
literal|3
decl_stmt|;
block|}
name|__packed
name|flbas
struct|;
comment|/** metadata capabilities */
struct|struct
block|{
comment|/* metadata can be transferred as part of data prp list */
name|uint8_t
name|extended
range|:
literal|1
decl_stmt|;
comment|/* metadata can be transferred with separate metadata pointer */
name|uint8_t
name|pointer
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved3
range|:
literal|6
decl_stmt|;
block|}
name|__packed
name|mc
struct|;
comment|/** end-to-end data protection capabilities */
struct|struct
block|{
comment|/* protection information type 1 */
name|uint8_t
name|pit1
range|:
literal|1
decl_stmt|;
comment|/* protection information type 2 */
name|uint8_t
name|pit2
range|:
literal|1
decl_stmt|;
comment|/* protection information type 3 */
name|uint8_t
name|pit3
range|:
literal|1
decl_stmt|;
comment|/* first eight bytes of metadata */
name|uint8_t
name|md_start
range|:
literal|1
decl_stmt|;
comment|/* last eight bytes of metadata */
name|uint8_t
name|md_end
range|:
literal|1
decl_stmt|;
block|}
name|__packed
name|dpc
struct|;
comment|/** end-to-end data protection type settings */
struct|struct
block|{
comment|/* protection information type */
name|uint8_t
name|pit
range|:
literal|3
decl_stmt|;
comment|/* 1 == protection info transferred at start of metadata */
comment|/* 0 == protection info transferred at end of metadata */
name|uint8_t
name|md_start
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved4
range|:
literal|4
decl_stmt|;
block|}
name|__packed
name|dps
struct|;
name|uint8_t
name|reserved5
index|[
literal|98
index|]
decl_stmt|;
comment|/** lba format support */
struct|struct
block|{
comment|/** metadata size */
name|uint32_t
name|ms
range|:
literal|16
decl_stmt|;
comment|/** lba data size */
name|uint32_t
name|lbads
range|:
literal|8
decl_stmt|;
comment|/** relative performance */
name|uint32_t
name|rp
range|:
literal|2
decl_stmt|;
name|uint32_t
name|reserved6
range|:
literal|6
decl_stmt|;
block|}
name|__packed
name|lbaf
index|[
literal|16
index|]
struct|;
name|uint8_t
name|reserved6
index|[
literal|192
index|]
decl_stmt|;
name|uint8_t
name|vendor_specific
index|[
literal|3712
index|]
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_enum
enum|enum
name|nvme_log_page
block|{
comment|/* 0x00 - reserved */
name|NVME_LOG_ERROR
init|=
literal|0x01
block|,
name|NVME_LOG_HEALTH_INFORMATION
init|=
literal|0x02
block|,
name|NVME_LOG_FIRMWARE_SLOT
init|=
literal|0x03
block|,
name|NVME_LOG_CHANGED_NAMESPACE
init|=
literal|0x04
block|,
name|NVME_LOG_COMMAND_EFFECT
init|=
literal|0x05
block|,
comment|/* 0x06-0x7F - reserved */
comment|/* 0x80-0xBF - I/O command set specific */
name|NVME_LOG_RES_NOTIFICATION
init|=
literal|0x80
block|,
comment|/* 0xC0-0xFF - vendor specific */
comment|/* 	 * The following are Intel Specific log pages, but they seem 	 * to be widely implemented. 	 */
name|INTEL_LOG_READ_LAT_LOG
init|=
literal|0xc1
block|,
name|INTEL_LOG_WRITE_LAT_LOG
init|=
literal|0xc2
block|,
name|INTEL_LOG_TEMP_STATS
init|=
literal|0xc5
block|,
name|INTEL_LOG_ADD_SMART
init|=
literal|0xca
block|,
name|INTEL_LOG_DRIVE_MKT_NAME
init|=
literal|0xdd
block|,
comment|/* 	 * HGST log page, with lots ofs sub pages. 	 */
name|HGST_INFO_LOG
init|=
literal|0xc1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|nvme_error_information_entry
block|{
name|uint64_t
name|error_count
decl_stmt|;
name|uint16_t
name|sqid
decl_stmt|;
name|uint16_t
name|cid
decl_stmt|;
name|struct
name|nvme_status
name|status
decl_stmt|;
name|uint16_t
name|error_location
decl_stmt|;
name|uint64_t
name|lba
decl_stmt|;
name|uint32_t
name|nsid
decl_stmt|;
name|uint8_t
name|vendor_specific
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|35
index|]
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_union
union|union
name|nvme_critical_warning_state
block|{
name|uint8_t
name|raw
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|available_spare
range|:
literal|1
decl_stmt|;
name|uint8_t
name|temperature
range|:
literal|1
decl_stmt|;
name|uint8_t
name|device_reliability
range|:
literal|1
decl_stmt|;
name|uint8_t
name|read_only
range|:
literal|1
decl_stmt|;
name|uint8_t
name|volatile_memory_backup
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved
range|:
literal|3
decl_stmt|;
block|}
name|__packed
name|bits
struct|;
block|}
name|__packed
union|;
end_union

begin_struct
struct|struct
name|nvme_health_information_page
block|{
name|union
name|nvme_critical_warning_state
name|critical_warning
decl_stmt|;
name|uint16_t
name|temperature
decl_stmt|;
name|uint8_t
name|available_spare
decl_stmt|;
name|uint8_t
name|available_spare_threshold
decl_stmt|;
name|uint8_t
name|percentage_used
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|26
index|]
decl_stmt|;
comment|/* 	 * Note that the following are 128-bit values, but are 	 *  defined as an array of 2 64-bit values. 	 */
comment|/* Data Units Read is always in 512-byte units. */
name|uint64_t
name|data_units_read
index|[
literal|2
index|]
decl_stmt|;
comment|/* Data Units Written is always in 512-byte units. */
name|uint64_t
name|data_units_written
index|[
literal|2
index|]
decl_stmt|;
comment|/* For NVM command set, this includes Compare commands. */
name|uint64_t
name|host_read_commands
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|host_write_commands
index|[
literal|2
index|]
decl_stmt|;
comment|/* Controller Busy Time is reported in minutes. */
name|uint64_t
name|controller_busy_time
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|power_cycles
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|power_on_hours
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|unsafe_shutdowns
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|media_errors
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|num_error_info_log_entries
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|warning_temp_time
decl_stmt|;
name|uint32_t
name|error_temp_time
decl_stmt|;
name|uint16_t
name|temp_sensor
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|296
index|]
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|nvme_firmware_page
block|{
struct|struct
block|{
name|uint8_t
name|slot
range|:
literal|3
decl_stmt|;
comment|/* slot for current FW */
name|uint8_t
name|reserved
range|:
literal|5
decl_stmt|;
block|}
name|__packed
name|afi
struct|;
name|uint8_t
name|reserved
index|[
literal|7
index|]
decl_stmt|;
name|uint64_t
name|revision
index|[
literal|7
index|]
decl_stmt|;
comment|/* revisions for 7 slots */
name|uint8_t
name|reserved2
index|[
literal|448
index|]
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|intel_log_temp_stats
block|{
name|uint64_t
name|current
decl_stmt|;
name|uint64_t
name|overtemp_flag_last
decl_stmt|;
name|uint64_t
name|overtemp_flag_life
decl_stmt|;
name|uint64_t
name|max_temp
decl_stmt|;
name|uint64_t
name|min_temp
decl_stmt|;
name|uint64_t
name|_rsvd
index|[
literal|5
index|]
decl_stmt|;
name|uint64_t
name|max_oper_temp
decl_stmt|;
name|uint64_t
name|min_oper_temp
decl_stmt|;
name|uint64_t
name|est_offset
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|NVME_TEST_MAX_THREADS
value|128
end_define

begin_struct
struct|struct
name|nvme_io_test
block|{
name|enum
name|nvme_nvm_opcode
name|opc
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|time
decl_stmt|;
comment|/* in seconds */
name|uint32_t
name|num_threads
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint64_t
name|io_completed
index|[
name|NVME_TEST_MAX_THREADS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|nvme_io_test_flags
block|{
comment|/* 	 * Specifies whether dev_refthread/dev_relthread should be 	 *  called during NVME_BIO_TEST.  Ignored for other test 	 *  types. 	 */
name|NVME_TEST_FLAG_REFTHREAD
init|=
literal|0x1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|nvme_pt_command
block|{
comment|/* 	 * cmd is used to specify a passthrough command to a controller or 	 *  namespace. 	 * 	 * The following fields from cmd may be specified by the caller: 	 *	* opc  (opcode) 	 *	* nsid (namespace id) - for admin commands only 	 *	* cdw10-cdw15 	 * 	 * Remaining fields must be set to 0 by the caller. 	 */
name|struct
name|nvme_command
name|cmd
decl_stmt|;
comment|/* 	 * cpl returns completion status for the passthrough command 	 *  specified by cmd. 	 * 	 * The following fields will be filled out by the driver, for 	 *  consumption by the caller: 	 *	* cdw0 	 *	* status (except for phase) 	 * 	 * Remaining fields will be set to 0 by the driver. 	 */
name|struct
name|nvme_completion
name|cpl
decl_stmt|;
comment|/* buf is the data buffer associated with this passthrough command. */
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* 	 * len is the length of the data buffer associated with this 	 *  passthrough command. 	 */
name|uint32_t
name|len
decl_stmt|;
comment|/* 	 * is_read = 1 if the passthrough command will read data into the 	 *  supplied buffer from the controller. 	 * 	 * is_read = 0 if the passthrough command will write data from the 	 *  supplied buffer to the controller. 	 */
name|uint32_t
name|is_read
decl_stmt|;
comment|/* 	 * driver_lock is used by the driver only.  It must be set to 0 	 *  by the caller. 	 */
name|struct
name|mtx
modifier|*
name|driver_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nvme_completion_is_error
parameter_list|(
name|cpl
parameter_list|)
define|\
value|((cpl)->status.sc != 0 || (cpl)->status.sct != 0)
end_define

begin_function_decl
name|void
name|nvme_strvis
parameter_list|(
name|uint8_t
modifier|*
name|dst
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|src
parameter_list|,
name|int
name|dstlen
parameter_list|,
name|int
name|srclen
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nvme_namespace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nvme_controller
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nvme_consumer
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nvme_cb_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|nvme_completion
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|nvme_cons_ns_fn_t
function_decl|)
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|nvme_cons_ctrlr_fn_t
function_decl|)
parameter_list|(
name|struct
name|nvme_controller
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nvme_cons_async_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|nvme_completion
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nvme_cons_fail_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
name|nvme_namespace_flags
block|{
name|NVME_NS_DEALLOCATE_SUPPORTED
init|=
literal|0x1
block|,
name|NVME_NS_FLUSH_SUPPORTED
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_function_decl
name|int
name|nvme_ctrlr_passthrough_cmd
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|,
name|struct
name|nvme_pt_command
modifier|*
name|pt
parameter_list|,
name|uint32_t
name|nsid
parameter_list|,
name|int
name|is_user_buffer
parameter_list|,
name|int
name|is_admin_cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Admin functions */
end_comment

begin_function_decl
name|void
name|nvme_ctrlr_cmd_set_feature
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|,
name|uint8_t
name|feature
parameter_list|,
name|uint32_t
name|cdw11
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint32_t
name|payload_size
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nvme_ctrlr_cmd_get_feature
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|,
name|uint8_t
name|feature
parameter_list|,
name|uint32_t
name|cdw11
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint32_t
name|payload_size
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nvme_ctrlr_cmd_get_log_page
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|,
name|uint8_t
name|log_page
parameter_list|,
name|uint32_t
name|nsid
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint32_t
name|payload_size
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NVM I/O functions */
end_comment

begin_function_decl
name|int
name|nvme_ns_cmd_write
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint64_t
name|lba
parameter_list|,
name|uint32_t
name|lba_count
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_cmd_write_bio
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_cmd_read
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint64_t
name|lba
parameter_list|,
name|uint32_t
name|lba_count
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_cmd_read_bio
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_cmd_deallocate
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint8_t
name|num_ranges
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_cmd_flush
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_dump
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|void
modifier|*
name|virt
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Registration functions */
end_comment

begin_function_decl
name|struct
name|nvme_consumer
modifier|*
name|nvme_register_consumer
parameter_list|(
name|nvme_cons_ns_fn_t
name|ns_fn
parameter_list|,
name|nvme_cons_ctrlr_fn_t
name|ctrlr_fn
parameter_list|,
name|nvme_cons_async_fn_t
name|async_fn
parameter_list|,
name|nvme_cons_fail_fn_t
name|fail_fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nvme_unregister_consumer
parameter_list|(
name|struct
name|nvme_consumer
modifier|*
name|consumer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Controller helper functions */
end_comment

begin_function_decl
name|device_t
name|nvme_ctrlr_get_device
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|nvme_controller_data
modifier|*
name|nvme_ctrlr_get_data
parameter_list|(
name|struct
name|nvme_controller
modifier|*
name|ctrlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Namespace helper functions */
end_comment

begin_function_decl
name|uint32_t
name|nvme_ns_get_max_io_xfer_size
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|nvme_ns_get_sector_size
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nvme_ns_get_num_sectors
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nvme_ns_get_size
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|nvme_ns_get_flags
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nvme_ns_get_serial_number
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nvme_ns_get_model_number
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|nvme_namespace_data
modifier|*
name|nvme_ns_get_data
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|nvme_ns_get_stripesize
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_ns_bio_process
parameter_list|(
name|struct
name|nvme_namespace
modifier|*
name|ns
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|nvme_cb_fn_t
name|cb_fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Command building helper functions -- shared with CAM */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|nvme_ns_flush_cmd
parameter_list|(
name|struct
name|nvme_command
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|nsid
parameter_list|)
block|{
name|cmd
operator|->
name|opc
operator|=
name|NVME_OPC_FLUSH
expr_stmt|;
name|cmd
operator|->
name|nsid
operator|=
name|nsid
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nvme_ns_rw_cmd
parameter_list|(
name|struct
name|nvme_command
modifier|*
name|cmd
parameter_list|,
name|uint32_t
name|rwcmd
parameter_list|,
name|uint16_t
name|nsid
parameter_list|,
name|uint64_t
name|lba
parameter_list|,
name|uint32_t
name|count
parameter_list|)
block|{
name|cmd
operator|->
name|opc
operator|=
name|rwcmd
expr_stmt|;
name|cmd
operator|->
name|nsid
operator|=
name|nsid
expr_stmt|;
name|cmd
operator|->
name|cdw10
operator|=
name|lba
operator|&
literal|0xffffffffu
expr_stmt|;
name|cmd
operator|->
name|cdw11
operator|=
name|lba
operator|>>
literal|32
expr_stmt|;
name|cmd
operator|->
name|cdw12
operator|=
name|count
operator|-
literal|1
expr_stmt|;
name|cmd
operator|->
name|cdw13
operator|=
literal|0
expr_stmt|;
name|cmd
operator|->
name|cdw14
operator|=
literal|0
expr_stmt|;
name|cmd
operator|->
name|cdw15
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nvme_ns_write_cmd
parameter_list|(
name|struct
name|nvme_command
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|nsid
parameter_list|,
name|uint64_t
name|lba
parameter_list|,
name|uint32_t
name|count
parameter_list|)
block|{
name|nvme_ns_rw_cmd
argument_list|(
name|cmd
argument_list|,
name|NVME_OPC_WRITE
argument_list|,
name|nsid
argument_list|,
name|lba
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nvme_ns_read_cmd
parameter_list|(
name|struct
name|nvme_command
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|nsid
parameter_list|,
name|uint64_t
name|lba
parameter_list|,
name|uint32_t
name|count
parameter_list|)
block|{
name|nvme_ns_rw_cmd
argument_list|(
name|cmd
argument_list|,
name|NVME_OPC_READ
argument_list|,
name|nsid
argument_list|,
name|lba
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nvme_ns_trim_cmd
parameter_list|(
name|struct
name|nvme_command
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|nsid
parameter_list|,
name|uint32_t
name|num_ranges
parameter_list|)
block|{
name|cmd
operator|->
name|opc
operator|=
name|NVME_OPC_DATASET_MANAGEMENT
expr_stmt|;
name|cmd
operator|->
name|nsid
operator|=
name|nsid
expr_stmt|;
name|cmd
operator|->
name|cdw10
operator|=
name|num_ranges
operator|-
literal|1
expr_stmt|;
name|cmd
operator|->
name|cdw11
operator|=
name|NVME_DSM_ATTR_DEALLOCATE
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NVME_H__ */
end_comment

end_unit

