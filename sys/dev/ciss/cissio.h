begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Driver ioctl interface.  *  * Note that this interface is API-compatible with the Linux implementation  * except as noted, and thus this header bears a striking resemblance to   * the Linux driver's cciss_ioctl.h.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|bus
decl_stmt|;
name|u_int8_t
name|dev_fn
decl_stmt|;
name|u_int32_t
name|board_id
decl_stmt|;
block|}
name|cciss_pci_info_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|delay
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
block|}
name|cciss_coalint_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|NodeName_type
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Heartbeat_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CISS_PARSCSIU2
value|0x0001
end_define

begin_define
define|#
directive|define
name|CISS_PARCSCIU3
value|0x0002
end_define

begin_define
define|#
directive|define
name|CISS_FIBRE1G
value|0x0100
end_define

begin_define
define|#
directive|define
name|CISS_FIBRE2G
value|0x0200
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|BusTypes_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|FirmwareVer_type
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|DriverVer_type
typedef|;
end_typedef

begin_comment
comment|/* passthrough command definitions */
end_comment

begin_define
define|#
directive|define
name|SENSEINFOBYTES
value|32
end_define

begin_define
define|#
directive|define
name|CISS_MAX_LUN
value|16
end_define

begin_define
define|#
directive|define
name|LEVEL2LUN
value|1
end_define

begin_define
define|#
directive|define
name|LEVEL3LUN
value|0
end_define

begin_comment
comment|/* command status value */
end_comment

begin_define
define|#
directive|define
name|CMD_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|CMD_TARGET_STATUS
value|0x0001
end_define

begin_define
define|#
directive|define
name|CMD_DATA_UNDERRUN
value|0x0002
end_define

begin_define
define|#
directive|define
name|CMD_DATA_OVERRUN
value|0x0003
end_define

begin_define
define|#
directive|define
name|CMD_INVALID
value|0x0004
end_define

begin_define
define|#
directive|define
name|CMD_PROTOCOL_ERR
value|0x0005
end_define

begin_define
define|#
directive|define
name|CMD_HARDWARE_ERR
value|0x0006
end_define

begin_define
define|#
directive|define
name|CMD_CONNECTION_LOST
value|0x0007
end_define

begin_define
define|#
directive|define
name|CMD_ABORTED
value|0x0008
end_define

begin_define
define|#
directive|define
name|CMD_ABORT_FAILED
value|0x0009
end_define

begin_define
define|#
directive|define
name|CMD_UNSOLICITED_ABORT
value|0x000A
end_define

begin_define
define|#
directive|define
name|CMD_TIMEOUT
value|0x000B
end_define

begin_define
define|#
directive|define
name|CMD_UNABORTABLE
value|0x000C
end_define

begin_comment
comment|/* transfer direction */
end_comment

begin_define
define|#
directive|define
name|XFER_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|XFER_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|XFER_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|XFER_RSVD
value|0x03
end_define

begin_comment
comment|/* task attribute */
end_comment

begin_define
define|#
directive|define
name|ATTR_UNTAGGED
value|0x00
end_define

begin_define
define|#
directive|define
name|ATTR_SIMPLE
value|0x04
end_define

begin_define
define|#
directive|define
name|ATTR_HEADOFQUEUE
value|0x05
end_define

begin_define
define|#
directive|define
name|ATTR_ORDERED
value|0x06
end_define

begin_define
define|#
directive|define
name|ATTR_ACA
value|0x07
end_define

begin_comment
comment|/* CDB type */
end_comment

begin_define
define|#
directive|define
name|TYPE_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|TYPE_MSG
value|0x01
end_define

begin_comment
comment|/* command list structure */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|Dev
decl_stmt|;
name|u_int8_t
name|Bus
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|Mode
range|:
literal|2
decl_stmt|;
block|}
name|PeripDev
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
struct|struct
block|{
name|u_int8_t
name|DevLSB
decl_stmt|;
name|u_int8_t
name|DevMSB
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|Mode
range|:
literal|2
decl_stmt|;
block|}
name|LogDev
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
struct|struct
block|{
name|u_int8_t
name|Dev
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|Bus
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|Targ
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|Mode
range|:
literal|2
decl_stmt|;
block|}
name|LogUnit
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
block|}
name|SCSI3Addr_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|TargetId
range|:
literal|24
decl_stmt|;
name|u_int32_t
name|Bus
range|:
literal|6
decl_stmt|;
name|u_int32_t
name|Mode
range|:
literal|2
decl_stmt|;
name|SCSI3Addr_struct
name|Target
index|[
literal|2
index|]
decl_stmt|;
block|}
name|PhysDevAddr_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|VolId
range|:
literal|30
decl_stmt|;
name|u_int32_t
name|Mode
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|LogDevAddr_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|u_int8_t
name|LunAddrBytes
index|[
literal|8
index|]
decl_stmt|;
name|SCSI3Addr_struct
name|SCSI3Lun
index|[
literal|4
index|]
decl_stmt|;
name|PhysDevAddr_struct
name|PhysDev
decl_stmt|;
name|LogDevAddr_struct
name|LogDev
decl_stmt|;
block|}
name|LUNAddr_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|CDBLen
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|Type
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|Attribute
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|Direction
range|:
literal|2
decl_stmt|;
block|}
name|Type
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
name|u_int16_t
name|Timeout
decl_stmt|;
name|u_int8_t
name|CDB
index|[
literal|16
index|]
decl_stmt|;
block|}
name|RequestBlock_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|Type
decl_stmt|;
name|u_int32_t
name|ErrorInfo
decl_stmt|;
block|}
name|Common_Info
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
struct|struct
block|{
name|u_int8_t
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|offense_size
decl_stmt|;
name|u_int8_t
name|offense_num
decl_stmt|;
name|u_int32_t
name|offense_value
decl_stmt|;
block|}
name|Invalid_Cmd
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
block|}
name|MoreErrInfo_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ScsiStatus
decl_stmt|;
name|u_int8_t
name|SenseLen
decl_stmt|;
name|u_int16_t
name|CommandStatus
decl_stmt|;
name|u_int32_t
name|ResidualCnt
decl_stmt|;
name|MoreErrInfo_struct
name|MoreErrInfo
decl_stmt|;
name|u_int8_t
name|SenseInfo
index|[
name|SENSEINFOBYTES
index|]
decl_stmt|;
block|}
name|ErrorInfo_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|LUNAddr_struct
name|LUN_info
decl_stmt|;
comment|/* 8 */
name|RequestBlock_struct
name|Request
decl_stmt|;
comment|/* 20 */
name|ErrorInfo_struct
name|error_info
decl_stmt|;
comment|/* 48 */
name|u_int16_t
name|buf_size
decl_stmt|;
comment|/* 2 */
name|u_int8_t
modifier|*
name|buf
decl_stmt|;
comment|/* 4 */
block|}
name|IOCTL_Command_struct
name|__attribute__
typedef|((
name|__packed__
typedef|));
end_typedef

begin_comment
comment|/*  * Note that we'd normally pass the struct in directly, but  * this code is trying to be compatible with other drivers.  */
end_comment

begin_define
define|#
directive|define
name|CCISS_GETPCIINFO
value|_IOR ('C', 200, cciss_pci_info_struct)
end_define

begin_define
define|#
directive|define
name|CCISS_GETINTINFO
value|_IOR ('C', 201, cciss_coalint_struct)
end_define

begin_define
define|#
directive|define
name|CCISS_SETINTINFO
value|_IOW ('C', 202, cciss_coalint_struct)
end_define

begin_define
define|#
directive|define
name|CCISS_GETNODENAME
value|_IOR ('C', 203, NodeName_type)
end_define

begin_define
define|#
directive|define
name|CCISS_SETNODENAME
value|_IOW ('C', 204, NodeName_type)
end_define

begin_define
define|#
directive|define
name|CCISS_GETHEARTBEAT
value|_IOR ('C', 205, Heartbeat_type)
end_define

begin_define
define|#
directive|define
name|CCISS_GETBUSTYPES
value|_IOR ('C', 206, BusTypes_type)
end_define

begin_define
define|#
directive|define
name|CCISS_GETFIRMVER
value|_IOR ('C', 207, FirmwareVer_type)
end_define

begin_define
define|#
directive|define
name|CCISS_GETDRIVERVER
value|_IOR ('C', 208, DriverVer_type)
end_define

begin_define
define|#
directive|define
name|CCISS_REVALIDVOLS
value|_IO  ('C', 209)
end_define

begin_define
define|#
directive|define
name|CCISS_PASSTHRU
value|_IOWR ('C', 210, IOCTL_Command_struct)
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

end_unit

