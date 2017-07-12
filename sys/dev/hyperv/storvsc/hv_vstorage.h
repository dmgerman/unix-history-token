begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HV_VSTORAGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__HV_VSTORAGE_H__
end_define

begin_comment
comment|/*  * Major/minor macros.  Minor version is in LSB, meaning that earlier flat  * version numbers will be interpreted as "0.x" (i.e., 1 becomes 0.1).  */
end_comment

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_MAJOR
parameter_list|(
name|VERSION_
parameter_list|)
value|(((VERSION_)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_MINOR
parameter_list|(
name|VERSION_
parameter_list|)
value|(((VERSION_)     )& 0xff)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION
parameter_list|(
name|MAJOR_
parameter_list|,
name|MINOR_
parameter_list|)
value|((((MAJOR_)& 0xff)<< 8) | \                                                  (((MINOR_)& 0xff)     ))
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_WIN6
value|VMSTOR_PROTOCOL_VERSION(2, 0)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_WIN7
value|VMSTOR_PROTOCOL_VERSION(4, 2)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_WIN8
value|VMSTOR_PROTOCOL_VERSION(5, 1)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_WIN8_1
value|VMSTOR_PROTOCOL_VERSION(6, 0)
end_define

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_WIN10
value|VMSTOR_PROTOCOL_VERSION(6, 2)
end_define

begin_comment
comment|/*  * Invalid version.  */
end_comment

begin_define
define|#
directive|define
name|VMSTOR_INVALID_PROTOCOL_VERSION
value|-1
end_define

begin_comment
comment|/*  * Version history:  * V1 Beta                    0.1  * V1 RC< 2008/1/31          1.0  * V1 RC> 2008/1/31          2.0  * Win7: 4.2  * Win8: 5.1  */
end_comment

begin_define
define|#
directive|define
name|VMSTOR_PROTOCOL_VERSION_CURRENT
value|VMSTOR_PROTOCOL_VERSION(5, 1)
end_define

begin_comment
comment|/**  *  Packet structure ops describing virtual storage requests.  */
end_comment

begin_enum
enum|enum
name|vstor_packet_ops
block|{
name|VSTOR_OPERATION_COMPLETEIO
init|=
literal|1
block|,
name|VSTOR_OPERATION_REMOVEDEVICE
init|=
literal|2
block|,
name|VSTOR_OPERATION_EXECUTESRB
init|=
literal|3
block|,
name|VSTOR_OPERATION_RESETLUN
init|=
literal|4
block|,
name|VSTOR_OPERATION_RESETADAPTER
init|=
literal|5
block|,
name|VSTOR_OPERATION_RESETBUS
init|=
literal|6
block|,
name|VSTOR_OPERATION_BEGININITIALIZATION
init|=
literal|7
block|,
name|VSTOR_OPERATION_ENDINITIALIZATION
init|=
literal|8
block|,
name|VSTOR_OPERATION_QUERYPROTOCOLVERSION
init|=
literal|9
block|,
name|VSTOR_OPERATION_QUERYPROPERTIES
init|=
literal|10
block|,
name|VSTOR_OPERATION_ENUMERATE_BUS
init|=
literal|11
block|,
name|VSTOR_OPERATION_FCHBA_DATA
init|=
literal|12
block|,
name|VSTOR_OPERATION_CREATE_MULTI_CHANNELS
init|=
literal|13
block|,
name|VSTOR_OPERATION_MAXIMUM
init|=
literal|13
block|}
enum|;
end_enum

begin_comment
comment|/*  *  Platform neutral description of a scsi request -  *  this remains the same across the write regardless of 32/64 bit  *  note: it's patterned off the Windows DDK SCSI_PASS_THROUGH structure  */
end_comment

begin_define
define|#
directive|define
name|CDB16GENERIC_LENGTH
value|0x10
end_define

begin_define
define|#
directive|define
name|SENSE_BUFFER_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|MAX_DATA_BUFFER_LENGTH_WITH_PADDING
value|0x14
end_define

begin_define
define|#
directive|define
name|POST_WIN7_STORVSC_SENSE_BUFFER_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|PRE_WIN8_STORVSC_SENSE_BUFFER_SIZE
value|0x12
end_define

begin_struct
struct|struct
name|vmscsi_win8_extension
block|{
comment|/* 	 * The following were added in Windows 8 	 */
name|uint16_t
name|reserve
decl_stmt|;
name|uint8_t
name|queue_tag
decl_stmt|;
name|uint8_t
name|queue_action
decl_stmt|;
name|uint32_t
name|srb_flags
decl_stmt|;
name|uint32_t
name|time_out_value
decl_stmt|;
name|uint32_t
name|queue_sort_ey
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmscsi_req
block|{
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|srb_status
decl_stmt|;
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* HBA number, set to the order number detected by initiator. */
name|uint8_t
name|port
decl_stmt|;
comment|/* SCSI bus number or bus_id, different from CAM's path_id. */
name|uint8_t
name|path_id
decl_stmt|;
name|uint8_t
name|target_id
decl_stmt|;
name|uint8_t
name|lun
decl_stmt|;
name|uint8_t
name|cdb_len
decl_stmt|;
name|uint8_t
name|sense_info_len
decl_stmt|;
name|uint8_t
name|data_in
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint32_t
name|transfer_len
decl_stmt|;
union|union
block|{
name|uint8_t
name|cdb
index|[
name|CDB16GENERIC_LENGTH
index|]
decl_stmt|;
name|uint8_t
name|sense_data
index|[
name|SENSE_BUFFER_SIZE
index|]
decl_stmt|;
name|uint8_t
name|reserved_array
index|[
name|MAX_DATA_BUFFER_LENGTH_WITH_PADDING
index|]
decl_stmt|;
block|}
name|u
union|;
comment|/* 	 * The following was added in win8. 	 */
name|struct
name|vmscsi_win8_extension
name|win8_extension
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  *  This structure is sent during the initialization phase to get the different  *  properties of the channel.  */
end_comment

begin_struct
struct|struct
name|vmstor_chan_props
block|{
name|uint16_t
name|proto_ver
decl_stmt|;
name|uint8_t
name|path_id
decl_stmt|;
name|uint8_t
name|target_id
decl_stmt|;
name|uint16_t
name|max_channel_cnt
decl_stmt|;
comment|/** 	 * Note: port number is only really known on the client side 	 */
name|uint16_t
name|port
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|max_transfer_bytes
decl_stmt|;
comment|/** 	 *  This id is unique for each channel and will correspond with 	 *  vendor specific data in the inquiry_ata 	 */
name|uint64_t
name|unique_id
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  *  This structure is sent during the storage protocol negotiations.  */
end_comment

begin_struct
struct|struct
name|vmstor_proto_ver
block|{
comment|/** 	 * Major (MSW) and minor (LSW) version numbers. 	 */
name|uint16_t
name|major_minor
decl_stmt|;
name|uint16_t
name|revision
decl_stmt|;
comment|/* always zero */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * Channel Property Flags  */
end_comment

begin_define
define|#
directive|define
name|STORAGE_CHANNEL_REMOVABLE_FLAG
value|0x1
end_define

begin_define
define|#
directive|define
name|STORAGE_CHANNEL_EMULATED_IDE_FLAG
value|0x2
end_define

begin_struct
struct|struct
name|vstor_packet
block|{
comment|/** 	 * Requested operation type 	 */
name|enum
name|vstor_packet_ops
name|operation
decl_stmt|;
comment|/* 	 * Flags - see below for values 	 */
name|uint32_t
name|flags
decl_stmt|;
comment|/** 	 * Status of the request returned from the server side. 	 */
name|uint32_t
name|status
decl_stmt|;
union|union
block|{
comment|/** 	     * Structure used to forward SCSI commands from the client to 	     * the server. 	     */
name|struct
name|vmscsi_req
name|vm_srb
decl_stmt|;
comment|/** 	     * Structure used to query channel properties. 	     */
name|struct
name|vmstor_chan_props
name|chan_props
decl_stmt|;
comment|/** 	     * Used during version negotiations. 	     */
name|struct
name|vmstor_proto_ver
name|version
decl_stmt|;
comment|/**              * Number of multichannels to create 	     */
name|uint16_t
name|multi_channels_cnt
decl_stmt|;
block|}
name|u
union|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * SRB (SCSI Request Block) Status Codes  */
end_comment

begin_define
define|#
directive|define
name|SRB_STATUS_PENDING
value|0x00
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_SUCCESS
value|0x01
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_ABORTED
value|0x02
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_ABORT_FAILED
value|0x03
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_BUSY
value|0x05
end_define

begin_comment
comment|/**  * SRB Status Masks (can be combined with above status codes)  */
end_comment

begin_define
define|#
directive|define
name|SRB_STATUS_QUEUE_FROZEN
value|0x40
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_AUTOSENSE_VALID
value|0x80
end_define

begin_define
define|#
directive|define
name|SRB_STATUS_INVALID_LUN
value|0X20
end_define

begin_comment
comment|/**  *  Packet flags  */
end_comment

begin_comment
comment|/**  *  This flag indicates that the server should send back a completion for this  *  packet.  */
end_comment

begin_define
define|#
directive|define
name|REQUEST_COMPLETION_FLAG
value|0x1
end_define

begin_comment
comment|/**  *  This is the set of flags that the vsc can set in any packets it sends  */
end_comment

begin_define
define|#
directive|define
name|VSC_LEGAL_FLAGS
value|(REQUEST_COMPLETION_FLAG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HV_VSTORAGE_H__ */
end_comment

end_unit

