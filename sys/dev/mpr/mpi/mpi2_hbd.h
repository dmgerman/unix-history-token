begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2009-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_hbd.h  *          Title:  MPI Host Based Discovery messages and structures  *  Creation Date:  October 21, 2009  *  *  mpi2_hbd.h Version:  02.00.04  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  10-28-09  02.00.00  Initial version.  *  08-11-10  02.00.01  Removed PortGroups, DmaGroup, and ControlGroup from  *                      HBD Action request, replaced by AdditionalInfo field.  *  11-18-11  02.00.02  Incorporating additions for MPI v2.5.  *  11-18-14  02.00.03  Updated copyright information.  *  02-17-16  02.00.04  Added SAS 4 22.5 gbs speed support.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_HBD_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_HBD_H
end_define

begin_comment
comment|/**************************************************************************** *  Host Based Discovery Action messages ****************************************************************************/
end_comment

begin_comment
comment|/* Host Based Discovery Action Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_HBD_ACTION_REQUEST
block|{
name|U8
name|Operation
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x18 */
name|U32
name|HbdDeviceInfo
decl_stmt|;
comment|/* 0x1C */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0x20 */
name|U16
name|MaxQDepth
decl_stmt|;
comment|/* 0x22 */
name|U8
name|FirstPhyIdentifier
decl_stmt|;
comment|/* 0x24 */
name|U8
name|Port
decl_stmt|;
comment|/* 0x25 */
name|U8
name|MaxConnections
decl_stmt|;
comment|/* 0x26 */
name|U8
name|MaxRate
decl_stmt|;
comment|/* 0x27 */
name|U32
name|AdditionalInfo
decl_stmt|;
comment|/* 0x28 */
name|U16
name|InitialAWT
decl_stmt|;
comment|/* 0x2C */
name|U16
name|Reserved7
decl_stmt|;
comment|/* 0x2E */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_HBD_ACTION_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_HBD_ACTION_REQUEST
operator|,
name|Mpi2HbdActionRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2HbdActionRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Operation field */
end_comment

begin_define
define|#
directive|define
name|MPI2_HBD_OP_ADD_DEVICE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_OP_REMOVE_DEVICE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_OP_UPDATE_DEVICE
value|(0x03)
end_define

begin_comment
comment|/* values for the HbdDeviceInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_VIRTUAL_DEVICE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_ATAPI_DEVICE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_DIRECT_ATTACH
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SSP_TARGET
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_STP_TARGET
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SMP_TARGET
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SATA_DEVICE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SSP_INITIATOR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_STP_INITIATOR
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SMP_INITIATOR
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_SATA_HOST
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_MASK_DEVICE_TYPE
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_NO_DEVICE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_END_DEVICE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_EDGE_EXPANDER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_DEVICE_INFO_FANOUT_EXPANDER
value|(0x00000003)
end_define

begin_comment
comment|/* values for the MaxRate field */
end_comment

begin_define
define|#
directive|define
name|MPI2_HBD_MAX_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_MAX_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_MAX_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_HBD_MAX_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_HBD_MAX_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_HBD_MAX_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/* Host Based Discovery Action Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_HBD_ACTION_REPLY
block|{
name|U8
name|Operation
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_HBD_ACTION_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_HBD_ACTION_REPLY
operator|,
name|Mpi2HbdActionReply_t
operator|,
name|MPI2_POINTER
name|pMpi2HbdActionReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

