begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Yahoo!, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD userland interface  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011-2014 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPR_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPR_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<dev/mpr/mpi/mpi2_type.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpr/mpi/mpi2.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpr/mpi/mpi2_cnfg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpr/mpi/mpi2_sas.h>
end_include

begin_comment
comment|/*  * For the read header requests, the header should include the page  * type or extended page type, page number, and page version.  The  * buffer and length are unused.  The completed header is returned in  * the 'header' member.  *  * For the read page and write page requests, 'buf' should point to a  * buffer of 'len' bytes which holds the entire page (including the  * header).  *  * All requests specify the page address in 'page_address'.  */
end_comment

begin_struct
struct|struct
name|mpr_cfg_page_req
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpr_ext_cfg_page_req
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpr_raid_action
block|{
name|uint8_t
name|action
decl_stmt|;
name|uint8_t
name|volume_bus
decl_stmt|;
name|uint8_t
name|volume_id
decl_stmt|;
name|uint8_t
name|phys_disk_num
decl_stmt|;
name|uint32_t
name|action_data_word
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint32_t
name|volume_status
decl_stmt|;
name|uint32_t
name|action_data
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|action_status
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
name|uint8_t
name|write
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpr_usr_command
block|{
name|void
modifier|*
name|req
decl_stmt|;
name|uint32_t
name|req_len
decl_stmt|;
name|void
modifier|*
name|rpl
decl_stmt|;
name|uint32_t
name|rpl_len
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|mpr_pci_bits
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|DeviceNumber
range|:
literal|5
decl_stmt|;
name|uint32_t
name|FunctionNumber
range|:
literal|3
decl_stmt|;
name|uint32_t
name|BusNumber
range|:
literal|24
decl_stmt|;
block|}
name|bits
struct|;
name|uint32_t
name|AsDWORD
decl_stmt|;
block|}
name|u
union|;
name|uint32_t
name|PciSegmentId
decl_stmt|;
block|}
name|mpr_pci_bits_t
typedef|;
end_typedef

begin_comment
comment|/*  *  The following is the MPRIOCTL_GET_ADAPTER_DATA data structure.  This data  *  structure is setup so that we hopefully are properly aligned for both  *  32-bit and 64-bit mode applications.  *  *  Adapter Type - Value = 6 = SCSI Protocol through SAS-3 adapter  *  *  MPI Port Number - The PCI Function number for this device  *  *  PCI Device HW Id - The PCI device number for this device  *  */
end_comment

begin_define
define|#
directive|define
name|MPRIOCTL_ADAPTER_TYPE_SAS3
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_adapter_data
block|{
name|uint32_t
name|StructureLength
decl_stmt|;
name|uint32_t
name|AdapterType
decl_stmt|;
name|uint32_t
name|MpiPortNumber
decl_stmt|;
name|uint32_t
name|PCIDeviceHwId
decl_stmt|;
name|uint32_t
name|PCIDeviceHwRev
decl_stmt|;
name|uint32_t
name|SubSystemId
decl_stmt|;
name|uint32_t
name|SubsystemVendorId
decl_stmt|;
name|uint32_t
name|Reserved1
decl_stmt|;
name|uint32_t
name|MpiFirmwareVersion
decl_stmt|;
name|uint32_t
name|BiosVersion
decl_stmt|;
name|uint8_t
name|DriverVersion
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|Reserved2
decl_stmt|;
name|uint8_t
name|ScsiId
decl_stmt|;
name|uint16_t
name|Reserved3
decl_stmt|;
name|mpr_pci_bits_t
name|PciInformation
decl_stmt|;
block|}
name|mpr_adapter_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_update_flash
block|{
name|uint64_t
name|PtrBuffer
decl_stmt|;
name|uint32_t
name|ImageChecksum
decl_stmt|;
name|uint32_t
name|ImageOffset
decl_stmt|;
name|uint32_t
name|ImageSize
decl_stmt|;
name|uint32_t
name|ImageType
decl_stmt|;
block|}
name|mpr_update_flash_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPR_PASS_THRU_DIRECTION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MPR_PASS_THRU_DIRECTION_READ
value|1
end_define

begin_define
define|#
directive|define
name|MPR_PASS_THRU_DIRECTION_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|MPR_PASS_THRU_DIRECTION_BOTH
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_pass_thru
block|{
name|uint64_t
name|PtrRequest
decl_stmt|;
name|uint64_t
name|PtrReply
decl_stmt|;
name|uint64_t
name|PtrData
decl_stmt|;
name|uint32_t
name|RequestSize
decl_stmt|;
name|uint32_t
name|ReplySize
decl_stmt|;
name|uint32_t
name|DataSize
decl_stmt|;
name|uint32_t
name|DataDirection
decl_stmt|;
name|uint64_t
name|PtrDataOut
decl_stmt|;
name|uint32_t
name|DataOutSize
decl_stmt|;
name|uint32_t
name|Timeout
decl_stmt|;
block|}
name|mpr_pass_thru_t
typedef|;
end_typedef

begin_comment
comment|/*  * Event queue defines  */
end_comment

begin_define
define|#
directive|define
name|MPR_EVENT_QUEUE_SIZE
value|(50)
end_define

begin_comment
comment|/* Max Events stored in driver */
end_comment

begin_define
define|#
directive|define
name|MPR_MAX_EVENT_DATA_LENGTH
value|(48)
end_define

begin_comment
comment|/* Size of each event in Dwords */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mpr_event_query
block|{
name|uint16_t
name|Entries
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
name|uint32_t
name|Types
index|[
literal|4
index|]
decl_stmt|;
block|}
name|mpr_event_query_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_event_enable
block|{
name|uint32_t
name|Types
index|[
literal|4
index|]
decl_stmt|;
block|}
name|mpr_event_enable_t
typedef|;
end_typedef

begin_comment
comment|/*  * Event record entry for ioctl.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mpr_event_entry
block|{
name|uint32_t
name|Type
decl_stmt|;
name|uint32_t
name|Number
decl_stmt|;
name|uint32_t
name|Data
index|[
name|MPR_MAX_EVENT_DATA_LENGTH
index|]
decl_stmt|;
block|}
name|mpr_event_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_event_report
block|{
name|uint32_t
name|Size
decl_stmt|;
name|uint64_t
name|PtrEvents
decl_stmt|;
block|}
name|mpr_event_report_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_pci_info
block|{
name|uint32_t
name|BusNumber
decl_stmt|;
name|uint8_t
name|DeviceNumber
decl_stmt|;
name|uint8_t
name|FunctionNumber
decl_stmt|;
name|uint16_t
name|InterruptVector
decl_stmt|;
name|uint8_t
name|PciHeader
index|[
literal|256
index|]
decl_stmt|;
block|}
name|mpr_pci_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_diag_action
block|{
name|uint32_t
name|Action
decl_stmt|;
name|uint32_t
name|Length
decl_stmt|;
name|uint64_t
name|PtrDiagAction
decl_stmt|;
name|uint32_t
name|ReturnCode
decl_stmt|;
block|}
name|mpr_diag_action_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPR_FW_DIAGNOSTIC_UID_NOT_FOUND
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_NEW
value|(0x806E6577)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_TYPE_REGISTER
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_TYPE_UNREGISTER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_TYPE_QUERY
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_TYPE_READ_BUFFER
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_TYPE_RELEASE
value|(0x00000005)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_INVALID_UID
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPR_DIAG_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|MPR_DIAG_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_SUCCESS
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_FAILURE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_INVALID_PARAMETER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_POST_FAILED
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_INVALID_UID
value|(0x00000011)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_RELEASE_FAILED
value|(0x00000012)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_NO_BUFFER
value|(0x00000013)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_ERROR_ALREADY_RELEASED
value|(0x00000014)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_fw_diag_register
block|{
name|uint8_t
name|ExtendedType
decl_stmt|;
name|uint8_t
name|BufferType
decl_stmt|;
name|uint16_t
name|ApplicationFlags
decl_stmt|;
name|uint32_t
name|DiagnosticFlags
decl_stmt|;
name|uint32_t
name|ProductSpecific
index|[
literal|23
index|]
decl_stmt|;
name|uint32_t
name|RequestedBufferSize
decl_stmt|;
name|uint32_t
name|UniqueId
decl_stmt|;
block|}
name|mpr_fw_diag_register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_fw_diag_unregister
block|{
name|uint32_t
name|UniqueId
decl_stmt|;
block|}
name|mpr_fw_diag_unregister_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPR_FW_DIAG_FLAG_APP_OWNED
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_FLAG_BUFFER_VALID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_FLAG_FW_BUFFER_ACCESS
value|(0x0004)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_fw_diag_query
block|{
name|uint8_t
name|ExtendedType
decl_stmt|;
name|uint8_t
name|BufferType
decl_stmt|;
name|uint16_t
name|ApplicationFlags
decl_stmt|;
name|uint32_t
name|DiagnosticFlags
decl_stmt|;
name|uint32_t
name|ProductSpecific
index|[
literal|23
index|]
decl_stmt|;
name|uint32_t
name|TotalBufferSize
decl_stmt|;
name|uint32_t
name|DriverAddedBufferSize
decl_stmt|;
name|uint32_t
name|UniqueId
decl_stmt|;
block|}
name|mpr_fw_diag_query_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_fw_diag_release
block|{
name|uint32_t
name|UniqueId
decl_stmt|;
block|}
name|mpr_fw_diag_release_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPR_FW_DIAG_FLAG_REREGISTER
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPR_FW_DIAG_FLAG_FORCE_RELEASE
value|(0x0002)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_diag_read_buffer
block|{
name|uint8_t
name|Status
decl_stmt|;
name|uint8_t
name|Reserved
decl_stmt|;
name|uint16_t
name|Flags
decl_stmt|;
name|uint32_t
name|StartingOffset
decl_stmt|;
name|uint32_t
name|BytesToRead
decl_stmt|;
name|uint32_t
name|UniqueId
decl_stmt|;
name|uint64_t
name|PtrDataBuffer
decl_stmt|;
block|}
name|mpr_diag_read_buffer_t
typedef|;
end_typedef

begin_comment
comment|/*  * Register Access  */
end_comment

begin_define
define|#
directive|define
name|REG_IO_READ
value|1
end_define

begin_define
define|#
directive|define
name|REG_IO_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|REG_MEM_READ
value|3
end_define

begin_define
define|#
directive|define
name|REG_MEM_WRITE
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|mpr_reg_access
block|{
name|uint32_t
name|Command
decl_stmt|;
name|uint32_t
name|RegOffset
decl_stmt|;
name|uint32_t
name|RegData
decl_stmt|;
block|}
name|mpr_reg_access_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpr_btdh_mapping
block|{
name|uint16_t
name|TargetID
decl_stmt|;
name|uint16_t
name|Bus
decl_stmt|;
name|uint16_t
name|DevHandle
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
block|}
name|mpr_btdh_mapping_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPRIO_MPR_COMMAND_FLAG_VERBOSE
value|0x01
end_define

begin_define
define|#
directive|define
name|MPRIO_MPR_COMMAND_FLAG_DEBUG
value|0x02
end_define

begin_define
define|#
directive|define
name|MPRIO_READ_CFG_HEADER
value|_IOWR('M', 200, struct mpr_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPRIO_READ_CFG_PAGE
value|_IOWR('M', 201, struct mpr_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPRIO_READ_EXT_CFG_HEADER
value|_IOWR('M', 202, struct mpr_ext_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPRIO_READ_EXT_CFG_PAGE
value|_IOWR('M', 203, struct mpr_ext_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPRIO_WRITE_CFG_PAGE
value|_IOWR('M', 204, struct mpr_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPRIO_RAID_ACTION
value|_IOWR('M', 205, struct mpr_raid_action)
end_define

begin_define
define|#
directive|define
name|MPRIO_MPR_COMMAND
value|_IOWR('M', 210, struct mpr_usr_command)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL
value|('I')
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_GET_ADAPTER_DATA
value|_IOWR(MPTIOCTL, 1,\     struct mpr_adapter_data)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_UPDATE_FLASH
value|_IOWR(MPTIOCTL, 2,\     struct mpr_update_flash)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_RESET_ADAPTER
value|_IO(MPTIOCTL, 3)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_PASS_THRU
value|_IOWR(MPTIOCTL, 4,\     struct mpr_pass_thru)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_EVENT_QUERY
value|_IOWR(MPTIOCTL, 5,\     struct mpr_event_query)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_EVENT_ENABLE
value|_IOWR(MPTIOCTL, 6,\     struct mpr_event_enable)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_EVENT_REPORT
value|_IOWR(MPTIOCTL, 7,\     struct mpr_event_report)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_GET_PCI_INFO
value|_IOWR(MPTIOCTL, 8,\     struct mpr_pci_info)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_DIAG_ACTION
value|_IOWR(MPTIOCTL, 9,\     struct mpr_diag_action)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_REG_ACCESS
value|_IOWR(MPTIOCTL, 10,\     struct mpr_reg_access)
end_define

begin_define
define|#
directive|define
name|MPTIOCTL_BTDH_MAPPING
value|_IOWR(MPTIOCTL, 11,\     struct mpr_btdh_mapping)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MPR_IOCTL_H_ */
end_comment

end_unit

