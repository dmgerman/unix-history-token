begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   *   *           Name:  mpi_ioc.h  *          Title:  MPI IOC, Port, Event, FW Download, and FW Upload messages  *  Creation Date:  August 11, 2000  *  *    mpi_ioc.h Version:  01.05.10  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  05-24-00  00.10.02  Added _MSG_IOC_INIT_REPLY structure.  *  06-06-00  01.00.01  Added CurReplyFrameSize field to _MSG_IOC_FACTS_REPLY.  *  06-12-00  01.00.02  Added _MSG_PORT_ENABLE_REPLY structure.  *                      Added _MSG_EVENT_ACK_REPLY structure.  *                      Added _MSG_FW_DOWNLOAD_REPLY structure.  *                      Added _MSG_TOOLBOX_REPLY structure.  *  06-30-00  01.00.03  Added MaxLanBuckets to _PORT_FACT_REPLY structure.  *  07-27-00  01.00.04  Added _EVENT_DATA structure definitions for _SCSI,  *                      _LINK_STATUS, _LOOP_STATE and _LOGOUT.  *  08-11-00  01.00.05  Switched positions of MsgLength and Function fields in  *                      _MSG_EVENT_ACK_REPLY structure to match specification.  *  11-02-00  01.01.01  Original release for post 1.0 work.  *                      Added a value for Manufacturer to WhoInit.  *  12-04-00  01.01.02  Modified IOCFacts reply, added FWUpload messages, and  *                      removed toolbox message.  *  01-09-01  01.01.03  Added event enabled and disabled defines.  *                      Added structures for FwHeader and DataHeader.  *                      Added ImageType to FwUpload reply.  *  02-20-01  01.01.04  Started using MPI_POINTER.  *  02-27-01  01.01.05  Added event for RAID status change and its event data.  *                      Added IocNumber field to MSG_IOC_FACTS_REPLY.  *  03-27-01  01.01.06  Added defines for ProductId field of MPI_FW_HEADER.  *                      Added structure offset comments.  *  04-09-01  01.01.07  Added structure EVENT_DATA_EVENT_CHANGE.  *  08-08-01  01.02.01  Original release for v1.2 work.  *                      New format for FWVersion and ProductId in  *                      MSG_IOC_FACTS_REPLY and MPI_FW_HEADER.  *  08-31-01  01.02.02  Addded event MPI_EVENT_SCSI_DEVICE_STATUS_CHANGE and  *                      related structure and defines.  *                      Added event MPI_EVENT_ON_BUS_TIMER_EXPIRED.  *                      Added MPI_IOCINIT_FLAGS_DISCARD_FW_IMAGE.  *                      Replaced a reserved field in MSG_IOC_FACTS_REPLY with  *                      IOCExceptions and changed DataImageSize to reserved.  *                      Added MPI_FW_DOWNLOAD_ITYPE_NVSTORE_DATA and  *                      MPI_FW_UPLOAD_ITYPE_NVDATA.  *  09-28-01  01.02.03  Modified Event Data for Integrated RAID.  *  11-01-01  01.02.04  Added defines for MPI_EXT_IMAGE_HEADER ImageType field.  *  03-14-02  01.02.05  Added HeaderVersion field to MSG_IOC_FACTS_REPLY.  *  05-31-02  01.02.06  Added define for  *                      MPI_IOCFACTS_EXCEPT_RAID_CONFIG_INVALID.  *                      Added AliasIndex to EVENT_DATA_LOGOUT structure.  *  04-01-03  01.02.07  Added defines for MPI_FW_HEADER_SIGNATURE_.  *  06-26-03  01.02.08  Added new values to the product family defines.  *  04-29-04  01.02.09  Added IOCCapabilities field to MSG_IOC_FACTS_REPLY and  *                      added related defines.  *  05-11-04  01.03.01  Original release for MPI v1.3.  *  08-19-04  01.05.01  Added four new fields to MSG_IOC_INIT.  *                      Added three new fields to MSG_IOC_FACTS_REPLY.  *                      Defined four new bits for the IOCCapabilities field of  *                      the IOCFacts reply.  *                      Added two new PortTypes for the PortFacts reply.  *                      Added six new events along with their EventData  *                      structures.  *                      Added a new MsgFlag to the FwDownload request to  *                      indicate last segment.  *                      Defined a new image type of boot loader.  *                      Added FW family codes for SAS product families.  *  10-05-04  01.05.02  Added ReplyFifoHostSignalingAddr field to  *                      MSG_IOC_FACTS_REPLY.  *  12-07-04  01.05.03  Added more defines for SAS Discovery Error event.  *  12-09-04  01.05.04  Added Unsupported device to SAS Device event.  *  01-15-05  01.05.05  Added event data for SAS SES Event.  *  02-09-05  01.05.06  Added MPI_FW_UPLOAD_ITYPE_FW_BACKUP define.  *  02-22-05  01.05.07  Added Host Page Buffer Persistent flag to IOC Facts  *                      Reply and IOC Init Request.  *  03-11-05  01.05.08  Added family code for 1068E family.  *                      Removed IOCFacts Reply EEDP Capability bit.  *  06-24-05  01.05.09  Added 5 new IOCFacts Reply IOCCapabilities bits.  *                      Added Max SATA Targets to SAS Discovery Error event.  *  08-30-05  01.05.10  Added 4 new events and their event data structures.  *                      Added new ReasonCode value for SAS Device Status Change  *                      event.  *                      Added new family code for FC949E.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IOC_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_IOC_H
end_define

begin_comment
comment|/***************************************************************************** * *               I O C    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  IOCInit message                                                         */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_IOC_INIT
block|{
name|U8
name|WhoInit
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Flags
decl_stmt|;
comment|/* 04h */
name|U8
name|MaxDevices
decl_stmt|;
comment|/* 05h */
name|U8
name|MaxBuses
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|ReplyFrameSize
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0Eh */
name|U32
name|HostMfaHighAddr
decl_stmt|;
comment|/* 10h */
name|U32
name|SenseBufferHighAddr
decl_stmt|;
comment|/* 14h */
name|U32
name|ReplyFifoHostSignalingAddr
decl_stmt|;
comment|/* 18h */
name|SGE_SIMPLE_UNION
name|HostPageBufferSGE
decl_stmt|;
comment|/* 1Ch */
name|U16
name|MsgVersion
decl_stmt|;
comment|/* 28h */
name|U16
name|HeaderVersion
decl_stmt|;
comment|/* 2Ah */
block|}
name|MSG_IOC_INIT
operator|,
name|MPI_POINTER
name|PTR_MSG_IOC_INIT
operator|,
name|IOCInit_t
operator|,
name|MPI_POINTER
name|pIOCInit_t
typedef|;
end_typedef

begin_comment
comment|/* WhoInit values */
end_comment

begin_define
define|#
directive|define
name|MPI_WHOINIT_NO_ONE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_WHOINIT_SYSTEM_BIOS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_WHOINIT_ROM_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_WHOINIT_PCI_PEER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_WHOINIT_HOST_DRIVER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_WHOINIT_MANUFACTURER
value|(0x05)
end_define

begin_comment
comment|/* Flags values */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCINIT_FLAGS_HOST_PAGE_BUFFER_PERSISTENT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_FLAGS_REPLY_FIFO_HOST_SIGNAL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_FLAGS_DISCARD_FW_IMAGE
value|(0x01)
end_define

begin_comment
comment|/* MsgVersion */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCINIT_MSGVERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_MSGVERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_MSGVERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_MSGVERSION_MINOR_SHIFT
value|(0)
end_define

begin_comment
comment|/* HeaderVersion */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCINIT_HEADERVERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_HEADERVERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_HEADERVERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_IOCINIT_HEADERVERSION_DEV_SHIFT
value|(0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MSG_IOC_INIT_REPLY
block|{
name|U8
name|WhoInit
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Flags
decl_stmt|;
comment|/* 04h */
name|U8
name|MaxDevices
decl_stmt|;
comment|/* 05h */
name|U8
name|MaxBuses
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_IOC_INIT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_IOC_INIT_REPLY
operator|,
name|IOCInitReply_t
operator|,
name|MPI_POINTER
name|pIOCInitReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  IOC Facts message                                                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_IOC_FACTS
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 01h */
name|U8
name|Function
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 03h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 04h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
block|}
name|MSG_IOC_FACTS
operator|,
name|MPI_POINTER
name|PTR_IOC_FACTS
operator|,
name|IOCFacts_t
operator|,
name|MPI_POINTER
name|pIOCFacts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_FW_VERSION_STRUCT
block|{
name|U8
name|Dev
decl_stmt|;
comment|/* 00h */
name|U8
name|Unit
decl_stmt|;
comment|/* 01h */
name|U8
name|Minor
decl_stmt|;
comment|/* 02h */
name|U8
name|Major
decl_stmt|;
comment|/* 03h */
block|}
name|MPI_FW_VERSION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI_FW_VERSION
block|{
name|MPI_FW_VERSION_STRUCT
name|Struct
decl_stmt|;
name|U32
name|Word
decl_stmt|;
block|}
name|MPI_FW_VERSION
typedef|;
end_typedef

begin_comment
comment|/* IOC Facts Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_IOC_FACTS_REPLY
block|{
name|U16
name|MsgVersion
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|HeaderVersion
decl_stmt|;
comment|/* 04h */
name|U8
name|IOCNumber
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|IOCExceptions
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U8
name|MaxChainDepth
decl_stmt|;
comment|/* 14h */
name|U8
name|WhoInit
decl_stmt|;
comment|/* 15h */
name|U8
name|BlockSize
decl_stmt|;
comment|/* 16h */
name|U8
name|Flags
decl_stmt|;
comment|/* 17h */
name|U16
name|ReplyQueueDepth
decl_stmt|;
comment|/* 18h */
name|U16
name|RequestFrameSize
decl_stmt|;
comment|/* 1Ah */
name|U16
name|Reserved_0101_FWVersion
decl_stmt|;
comment|/* 1Ch */
comment|/* obsolete 16-bit FWVersion */
name|U16
name|ProductID
decl_stmt|;
comment|/* 1Eh */
name|U32
name|CurrentHostMfaHighAddr
decl_stmt|;
comment|/* 20h */
name|U16
name|GlobalCredits
decl_stmt|;
comment|/* 24h */
name|U8
name|NumberOfPorts
decl_stmt|;
comment|/* 26h */
name|U8
name|EventState
decl_stmt|;
comment|/* 27h */
name|U32
name|CurrentSenseBufferHighAddr
decl_stmt|;
comment|/* 28h */
name|U16
name|CurReplyFrameSize
decl_stmt|;
comment|/* 2Ch */
name|U8
name|MaxDevices
decl_stmt|;
comment|/* 2Eh */
name|U8
name|MaxBuses
decl_stmt|;
comment|/* 2Fh */
name|U32
name|FWImageSize
decl_stmt|;
comment|/* 30h */
name|U32
name|IOCCapabilities
decl_stmt|;
comment|/* 34h */
name|MPI_FW_VERSION
name|FWVersion
decl_stmt|;
comment|/* 38h */
name|U16
name|HighPriorityQueueDepth
decl_stmt|;
comment|/* 3Ch */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 3Eh */
name|SGE_SIMPLE_UNION
name|HostPageBufferSGE
decl_stmt|;
comment|/* 40h */
name|U32
name|ReplyFifoHostSignalingAddr
decl_stmt|;
comment|/* 4Ch */
block|}
name|MSG_IOC_FACTS_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_IOC_FACTS_REPLY
operator|,
name|IOCFactsReply_t
operator|,
name|MPI_POINTER
name|pIOCFactsReply_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCFACTS_MSGVERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_MSGVERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_MSGVERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_MSGVERSION_MINOR_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_HDRVERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_HDRVERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_HDRVERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_HDRVERSION_DEV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EXCEPT_CONFIG_CHECKSUM_FAIL
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EXCEPT_RAID_CONFIG_INVALID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EXCEPT_FW_CHECKSUM_FAIL
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EXCEPT_PERSISTENT_TABLE_FULL
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_FLAGS_FW_DOWNLOAD_BOOT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_FLAGS_REPLY_FIFO_HOST_SIGNAL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_FLAGS_HOST_PAGE_BUFFER_PERSISTENT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EVENTSTATE_DISABLED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_EVENTSTATE_ENABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_HIGH_PRI_Q
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_REPLY_HOST_SIGNAL
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_QUEUE_FULL_HANDLING
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_DIAG_TRACE_BUFFER
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_SNAPSHOT_BUFFER
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_EXTENDED_BUFFER
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_EEDP
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_BIDIRECTIONAL
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_MULTICAST
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_SCSIIO32
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_IOCFACTS_CAPABILITY_NO_SCSIIO16
value|(0x00000400)
end_define

begin_comment
comment|/***************************************************************************** * *               P o r t    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Port Facts message and Reply                                            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_PORT_FACTS
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
block|}
name|MSG_PORT_FACTS
operator|,
name|MPI_POINTER
name|PTR_MSG_PORT_FACTS
operator|,
name|PortFacts_t
operator|,
name|MPI_POINTER
name|pPortFacts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_PORT_FACTS_REPLY
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 14h */
name|U8
name|PortType
decl_stmt|;
comment|/* 15h */
name|U16
name|MaxDevices
decl_stmt|;
comment|/* 16h */
name|U16
name|PortSCSIID
decl_stmt|;
comment|/* 18h */
name|U16
name|ProtocolFlags
decl_stmt|;
comment|/* 1Ah */
name|U16
name|MaxPostedCmdBuffers
decl_stmt|;
comment|/* 1Ch */
name|U16
name|MaxPersistentIDs
decl_stmt|;
comment|/* 1Eh */
name|U16
name|MaxLanBuckets
decl_stmt|;
comment|/* 20h */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 22h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 24h */
block|}
name|MSG_PORT_FACTS_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_PORT_FACTS_REPLY
operator|,
name|PortFactsReply_t
operator|,
name|MPI_POINTER
name|pPortFactsReply_t
typedef|;
end_typedef

begin_comment
comment|/* PortTypes values */
end_comment

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PORTTYPE_INACTIVE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PORTTYPE_SCSI
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PORTTYPE_FC
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PORTTYPE_ISCSI
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PORTTYPE_SAS
value|(0x30)
end_define

begin_comment
comment|/* ProtocolFlags values */
end_comment

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PROTOCOL_LOGBUSADDR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PROTOCOL_LAN
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PROTOCOL_TARGET
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_PORTFACTS_PROTOCOL_INITIATOR
value|(0x08)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Port Enable Message                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_PORT_ENABLE
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
block|}
name|MSG_PORT_ENABLE
operator|,
name|MPI_POINTER
name|PTR_MSG_PORT_ENABLE
operator|,
name|PortEnable_t
operator|,
name|MPI_POINTER
name|pPortEnable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_PORT_ENABLE_REPLY
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 05h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_PORT_ENABLE_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_PORT_ENABLE_REPLY
operator|,
name|PortEnableReply_t
operator|,
name|MPI_POINTER
name|pPortEnableReply_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** * *               E v e n t    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Event Notification messages                                             */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EVENT_NOTIFY
block|{
name|U8
name|Switch
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
block|}
name|MSG_EVENT_NOTIFY
operator|,
name|MPI_POINTER
name|PTR_MSG_EVENT_NOTIFY
operator|,
name|EventNotification_t
operator|,
name|MPI_POINTER
name|pEventNotification_t
typedef|;
end_typedef

begin_comment
comment|/* Event Notification Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EVENT_NOTIFY_REPLY
block|{
name|U16
name|EventDataLength
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|AckRequired
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|Event
decl_stmt|;
comment|/* 14h */
name|U32
name|EventContext
decl_stmt|;
comment|/* 18h */
name|U32
name|Data
index|[
literal|1
index|]
decl_stmt|;
comment|/* 1Ch */
block|}
name|MSG_EVENT_NOTIFY_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_EVENT_NOTIFY_REPLY
operator|,
name|EventNotificationReply_t
operator|,
name|MPI_POINTER
name|pEventNotificationReply_t
typedef|;
end_typedef

begin_comment
comment|/* Event Acknowledge */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EVENT_ACK
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|Event
decl_stmt|;
comment|/* 0Ch */
name|U32
name|EventContext
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_EVENT_ACK
operator|,
name|MPI_POINTER
name|PTR_MSG_EVENT_ACK
operator|,
name|EventAck_t
operator|,
name|MPI_POINTER
name|pEventAck_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EVENT_ACK_REPLY
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_EVENT_ACK_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_EVENT_ACK_REPLY
operator|,
name|EventAckReply_t
operator|,
name|MPI_POINTER
name|pEventAckReply_t
typedef|;
end_typedef

begin_comment
comment|/* Switch */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_NOTIFICATION_SWITCH_OFF
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_NOTIFICATION_SWITCH_ON
value|(0x01)
end_define

begin_comment
comment|/* Event */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_NONE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOG_DATA
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_STATE_CHANGE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_UNIT_ATTENTION
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IOC_BUS_RESET
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_EXT_BUS_RESET
value|(0x00000005)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RESCAN
value|(0x00000006)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LINK_STATUS_CHANGE
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOOP_STATE_CHANGE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOGOUT
value|(0x00000009)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_EVENT_CHANGE
value|(0x0000000A)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_INTEGRATED_RAID
value|(0x0000000B)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SCSI_DEVICE_STATUS_CHANGE
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_ON_BUS_TIMER_EXPIRED
value|(0x0000000D)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_QUEUE_FULL
value|(0x0000000E)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEVICE_STATUS_CHANGE
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_SES
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_PERSISTENT_TABLE_FULL
value|(0x00000011)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PHY_LINK_STATUS
value|(0x00000012)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DISCOVERY_ERROR
value|(0x00000013)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR_RESYNC_UPDATE
value|(0x00000014)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2
value|(0x00000015)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DISCOVERY
value|(0x00000016)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOG_ENTRY_ADDED
value|(0x00000021)
end_define

begin_comment
comment|/* AckRequired field values */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_NOTIFICATION_ACK_NOT_REQUIRED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_NOTIFICATION_ACK_REQUIRED
value|(0x01)
end_define

begin_comment
comment|/* EventChange Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_EVENT_CHANGE
block|{
name|U8
name|EventState
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
block|}
name|EVENT_DATA_EVENT_CHANGE
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_EVENT_CHANGE
operator|,
name|EventDataEventChange_t
operator|,
name|MPI_POINTER
name|pEventDataEventChange_t
typedef|;
end_typedef

begin_comment
comment|/* LogEntryAdded Event data */
end_comment

begin_comment
comment|/* this structure matches MPI_LOG_0_ENTRY in mpi_cnfg.h */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_DATA_LOG_ENTRY_DATA_LENGTH
value|(0x1C)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_LOG_ENTRY
block|{
name|U32
name|TimeStamp
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U16
name|LogSequence
decl_stmt|;
comment|/* 08h */
name|U16
name|LogEntryQualifier
decl_stmt|;
comment|/* 0Ah */
name|U8
name|LogData
index|[
name|MPI_EVENT_DATA_LOG_ENTRY_DATA_LENGTH
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|EVENT_DATA_LOG_ENTRY
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_LOG_ENTRY
operator|,
name|MpiEventDataLogEntry_t
operator|,
name|MPI_POINTER
name|pMpiEventDataLogEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_LOG_ENTRY_ADDED
block|{
name|U16
name|LogSequence
decl_stmt|;
comment|/* 00h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|EVENT_DATA_LOG_ENTRY
name|LogEntry
decl_stmt|;
comment|/* 08h */
block|}
name|EVENT_DATA_LOG_ENTRY_ADDED
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_LOG_ENTRY_ADDED
operator|,
name|MpiEventDataLogEntryAdded_t
operator|,
name|MPI_POINTER
name|pMpiEventDataLogEntryAdded_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI Event data for Port, Bus and Device forms */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SCSI
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|BusPort
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
block|}
name|EVENT_DATA_SCSI
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SCSI
operator|,
name|EventDataScsi_t
operator|,
name|MPI_POINTER
name|pEventDataScsi_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI Device Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SCSI_DEVICE_STATUS_CHANGE
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 02h */
name|U8
name|LUN
decl_stmt|;
comment|/* 03h */
name|U8
name|ASC
decl_stmt|;
comment|/* 04h */
name|U8
name|ASCQ
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 06h */
block|}
name|EVENT_DATA_SCSI_DEVICE_STATUS_CHANGE
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SCSI_DEVICE_STATUS_CHANGE
operator|,
name|MpiEventDataScsiDeviceStatusChange_t
operator|,
name|MPI_POINTER
name|pMpiEventDataScsiDeviceStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* MPI SCSI Device Status Change Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_SCSI_DEV_STAT_RC_ADDED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SCSI_DEV_STAT_RC_NOT_RESPONDING
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SCSI_DEV_STAT_RC_SMART_DATA
value|(0x05)
end_define

begin_comment
comment|/* SAS Device Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 03h */
name|U8
name|ASC
decl_stmt|;
comment|/* 04h */
name|U8
name|ASCQ
decl_stmt|;
comment|/* 05h */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 06h */
name|U32
name|DeviceInfo
decl_stmt|;
comment|/* 08h */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0Ch */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0Eh */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0Fh */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 10h */
block|}
name|EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
operator|,
name|MpiEventDataSasDeviceStatusChange_t
operator|,
name|MPI_POINTER
name|pMpiEventDataSasDeviceStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* MPI SAS Device Status Change Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_ADDED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_NOT_RESPONDING
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_SMART_DATA
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_NO_PERSIST_ADDED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_UNSUPPORTED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DEV_STAT_RC_INTERNAL_DEVICE_RESET
value|(0x08)
end_define

begin_comment
comment|/* SCSI Event data for Queue Full event */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_QUEUE_FULL
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U16
name|CurrentDepth
decl_stmt|;
comment|/* 02h */
block|}
name|EVENT_DATA_QUEUE_FULL
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_QUEUE_FULL
operator|,
name|EventDataQueueFull_t
operator|,
name|MPI_POINTER
name|pEventDataQueueFull_t
typedef|;
end_typedef

begin_comment
comment|/* MPI Integrated RAID Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_RAID
block|{
name|U8
name|VolumeID
decl_stmt|;
comment|/* 00h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 01h */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 02h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 03h */
name|U8
name|ASC
decl_stmt|;
comment|/* 04h */
name|U8
name|ASCQ
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 06h */
name|U32
name|SettingsStatus
decl_stmt|;
comment|/* 08h */
block|}
name|EVENT_DATA_RAID
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_RAID
operator|,
name|MpiEventDataRaid_t
operator|,
name|MPI_POINTER
name|pMpiEventDataRaid_t
typedef|;
end_typedef

begin_comment
comment|/* MPI Integrated RAID Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_VOLUME_CREATED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_VOLUME_DELETED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_VOLUME_SETTINGS_CHANGED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_VOLUME_STATUS_CHANGED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_VOLUME_PHYSDISK_CHANGED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_PHYSDISK_CREATED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_PHYSDISK_DELETED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_PHYSDISK_SETTINGS_CHANGED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_PHYSDISK_STATUS_CHANGED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_DOMAIN_VAL_NEEDED
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_SMART_DATA
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_RAID_RC_REPLACE_ACTION_STARTED
value|(0x0B)
end_define

begin_comment
comment|/* MPI Integrated RAID Resync Update Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_EVENT_DATA_IR_RESYNC_UPDATE
block|{
name|U8
name|VolumeID
decl_stmt|;
comment|/* 00h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 01h */
name|U8
name|ResyncComplete
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 03h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
block|}
name|MPI_EVENT_DATA_IR_RESYNC_UPDATE
operator|,
name|MPI_POINTER
name|PTR_MPI_EVENT_DATA_IR_RESYNC_UPDATE
operator|,
name|MpiEventDataIrResyncUpdate_t
operator|,
name|MPI_POINTER
name|pMpiEventDataIrResyncUpdate_t
typedef|;
end_typedef

begin_comment
comment|/* MPI IR2 Event data */
end_comment

begin_comment
comment|/* MPI_LD_STATE or MPI_PD_STATE */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IR2_STATE_CHANGED
block|{
name|U16
name|PreviousState
decl_stmt|;
comment|/* 00h */
name|U16
name|NewState
decl_stmt|;
comment|/* 02h */
block|}
name|IR2_STATE_CHANGED
operator|,
name|MPI_POINTER
name|PTR_IR2_STATE_CHANGED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IR2_PD_INFO
block|{
name|U16
name|DeviceHandle
decl_stmt|;
comment|/* 00h */
name|U8
name|TruncEnclosureHandle
decl_stmt|;
comment|/* 02h */
name|U8
name|TruncatedSlot
decl_stmt|;
comment|/* 03h */
block|}
name|IR2_PD_INFO
operator|,
name|MPI_POINTER
name|PTR_IR2_PD_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI_IR2_RC_EVENT_DATA
block|{
name|IR2_STATE_CHANGED
name|StateChanged
decl_stmt|;
name|U32
name|Lba
decl_stmt|;
name|IR2_PD_INFO
name|PdInfo
decl_stmt|;
block|}
name|MPI_IR2_RC_EVENT_DATA
operator|,
name|MPI_POINTER
name|PTR_MPI_IR2_RC_EVENT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_EVENT_DATA_IR2
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 02h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 03h */
name|MPI_IR2_RC_EVENT_DATA
name|IR2EventData
decl_stmt|;
comment|/* 04h */
block|}
name|MPI_EVENT_DATA_IR2
operator|,
name|MPI_POINTER
name|PTR_MPI_EVENT_DATA_IR2
operator|,
name|MpiEventDataIR2_t
operator|,
name|MPI_POINTER
name|pMpiEventDataIR2_t
typedef|;
end_typedef

begin_comment
comment|/* MPI IR2 Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_LD_STATE_CHANGED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_PD_STATE_CHANGED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_BAD_BLOCK_TABLE_FULL
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_PD_INSERTED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_PD_REMOVED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_FOREIGN_CFG_DETECTED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_IR2_RC_REBUILD_MEDIUM_ERROR
value|(0x07)
end_define

begin_comment
comment|/* defines for logical disk states */
end_comment

begin_define
define|#
directive|define
name|MPI_LD_STATE_OPTIMAL
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_LD_STATE_DEGRADED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_LD_STATE_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_LD_STATE_MISSING
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_LD_STATE_OFFLINE
value|(0x04)
end_define

begin_comment
comment|/* defines for physical disk states */
end_comment

begin_define
define|#
directive|define
name|MPI_PD_STATE_ONLINE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_MISSING
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_NOT_COMPATIBLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_FAILED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_INITIALIZING
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_OFFLINE_AT_HOST_REQUEST
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_FAILED_AT_HOST_REQUEST
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_PD_STATE_OFFLINE_FOR_ANOTHER_REASON
value|(0xFF)
end_define

begin_comment
comment|/* MPI Link Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_LINK_STATUS
block|{
name|U8
name|State
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Port
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 06h */
block|}
name|EVENT_DATA_LINK_STATUS
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_LINK_STATUS
operator|,
name|EventDataLinkStatus_t
operator|,
name|MPI_POINTER
name|pEventDataLinkStatus_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_EVENT_LINK_STATUS_FAILURE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LINK_STATUS_ACTIVE
value|(0x00000001)
end_define

begin_comment
comment|/* MPI Loop State Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_LOOP_STATE
block|{
name|U8
name|Character4
decl_stmt|;
comment|/* 00h */
name|U8
name|Character3
decl_stmt|;
comment|/* 01h */
name|U8
name|Type
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Port
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
block|}
name|EVENT_DATA_LOOP_STATE
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_LOOP_STATE
operator|,
name|EventDataLoopState_t
operator|,
name|MPI_POINTER
name|pEventDataLoopState_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_EVENT_LOOP_STATE_CHANGE_LIP
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOOP_STATE_CHANGE_LPE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_LOOP_STATE_CHANGE_LPB
value|(0x0003)
end_define

begin_comment
comment|/* MPI LOGOUT Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_LOGOUT
block|{
name|U32
name|NPortID
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasIndex
decl_stmt|;
comment|/* 04h */
name|U8
name|Port
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 06h */
block|}
name|EVENT_DATA_LOGOUT
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_LOGOUT
operator|,
name|EventDataLogout_t
operator|,
name|MPI_POINTER
name|pEventDataLogout_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_EVENT_LOGOUT_ALL_ALIASES
value|(0xFF)
end_define

begin_comment
comment|/* SAS SES Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SAS_SES
block|{
name|U8
name|PhyNum
decl_stmt|;
comment|/* 00h */
name|U8
name|Port
decl_stmt|;
comment|/* 01h */
name|U8
name|PortWidth
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 04h */
block|}
name|EVENT_DATA_SAS_SES
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SAS_SES
operator|,
name|MpiEventDataSasSes_t
operator|,
name|MPI_POINTER
name|pMpiEventDataSasSes_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Phy Link Status Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SAS_PHY_LINK_STATUS
block|{
name|U8
name|PhyNum
decl_stmt|;
comment|/* 00h */
name|U8
name|LinkRates
decl_stmt|;
comment|/* 01h */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 02h */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 04h */
block|}
name|EVENT_DATA_SAS_PHY_LINK_STATUS
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SAS_PHY_LINK_STATUS
operator|,
name|MpiEventDataSasPhyLinkStatus_t
operator|,
name|MPI_POINTER
name|pMpiEventDataSasPhyLinkStatus_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the LinkRates field of the SAS PHY Link Status event */
end_comment

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_CURRENT_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_CURRENT_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_PREVIOUS_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_PREVIOUS_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_FAILED_SPEED_NEGOTIATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_SATA_OOB_COMPLETE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_PLS_LR_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* SAS Discovery Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_SAS_DISCOVERY
block|{
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
block|}
name|EVENT_DATA_SAS_DISCOVERY
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_SAS_DISCOVERY
operator|,
name|EventDataSasDiscovery_t
operator|,
name|MPI_POINTER
name|pEventDataSasDiscovery_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DSCVRY_COMPLETE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DSCVRY_IN_PROGRESS
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DSCVRY_PHY_BITS_MASK
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_SAS_DSCVRY_PHY_BITS_SHIFT
value|(16)
end_define

begin_comment
comment|/* SAS Discovery Errror Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EVENT_DATA_DISCOVERY_ERROR
block|{
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 00h */
name|U8
name|Port
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
block|}
name|EVENT_DATA_DISCOVERY_ERROR
operator|,
name|MPI_POINTER
name|PTR_EVENT_DATA_DISCOVERY_ERROR
operator|,
name|EventDataDiscoveryError_t
operator|,
name|MPI_POINTER
name|pEventDataDiscoveryError_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_EXPANDER_ERR
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_MULTPL_SUBTRACTIVE
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_TABLE_TO_TABLE
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_MULTPL_PATHS
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI_EVENT_DSCVRY_ERR_DS_MAX_SATA_TARGETS
value|(0x00001000)
end_define

begin_comment
comment|/***************************************************************************** * *               F i r m w a r e    L o a d    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Firmware Download message and associated structures                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FW_DOWNLOAD
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|SGE_MPI_UNION
name|SGL
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_FW_DOWNLOAD
operator|,
name|MPI_POINTER
name|PTR_MSG_FW_DOWNLOAD
operator|,
name|FWDownload_t
operator|,
name|MPI_POINTER
name|pFWDownload_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_MSGFLGS_LAST_SEGMENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_ITYPE_RESERVED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_ITYPE_FW
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_ITYPE_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_ITYPE_NVDATA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FW_DOWNLOAD_ITYPE_BOOTLOADER
value|(0x04)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_FWDownloadTCSGE
block|{
name|U8
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|ContextSize
decl_stmt|;
comment|/* 01h */
name|U8
name|DetailsLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Flags
decl_stmt|;
comment|/* 03h */
name|U32
name|Reserved_0100_Checksum
decl_stmt|;
comment|/* 04h */
comment|/* obsolete Checksum */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 08h */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0Ch */
block|}
name|FW_DOWNLOAD_TCSGE
operator|,
name|MPI_POINTER
name|PTR_FW_DOWNLOAD_TCSGE
operator|,
name|FWDownloadTCSGE_t
operator|,
name|MPI_POINTER
name|pFWDownloadTCSGE_t
typedef|;
end_typedef

begin_comment
comment|/* Firmware Download reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FW_DOWNLOAD_REPLY
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_FW_DOWNLOAD_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_FW_DOWNLOAD_REPLY
operator|,
name|FWDownloadReply_t
operator|,
name|MPI_POINTER
name|pFWDownloadReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Firmware Upload message and associated structures                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FW_UPLOAD
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|SGE_MPI_UNION
name|SGL
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_FW_UPLOAD
operator|,
name|MPI_POINTER
name|PTR_MSG_FW_UPLOAD
operator|,
name|FWUpload_t
operator|,
name|MPI_POINTER
name|pFWUpload_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_FW_IOC_MEM
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_FW_FLASH
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_BIOS_FLASH
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_NVDATA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_BOOTLOADER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FW_UPLOAD_ITYPE_FW_BACKUP
value|(0x05)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_FWUploadTCSGE
block|{
name|U8
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|ContextSize
decl_stmt|;
comment|/* 01h */
name|U8
name|DetailsLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Flags
decl_stmt|;
comment|/* 03h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 08h */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0Ch */
block|}
name|FW_UPLOAD_TCSGE
operator|,
name|MPI_POINTER
name|PTR_FW_UPLOAD_TCSGE
operator|,
name|FWUploadTCSGE_t
operator|,
name|MPI_POINTER
name|pFWUploadTCSGE_t
typedef|;
end_typedef

begin_comment
comment|/* Firmware Upload reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FW_UPLOAD_REPLY
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|ActualImageSize
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_FW_UPLOAD_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_FW_UPLOAD_REPLY
operator|,
name|FWUploadReply_t
operator|,
name|MPI_POINTER
name|pFWUploadReply_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_FW_HEADER
block|{
name|U32
name|ArmBranchInstruction0
decl_stmt|;
comment|/* 00h */
name|U32
name|Signature0
decl_stmt|;
comment|/* 04h */
name|U32
name|Signature1
decl_stmt|;
comment|/* 08h */
name|U32
name|Signature2
decl_stmt|;
comment|/* 0Ch */
name|U32
name|ArmBranchInstruction1
decl_stmt|;
comment|/* 10h */
name|U32
name|ArmBranchInstruction2
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved
decl_stmt|;
comment|/* 18h */
name|U32
name|Checksum
decl_stmt|;
comment|/* 1Ch */
name|U16
name|VendorId
decl_stmt|;
comment|/* 20h */
name|U16
name|ProductId
decl_stmt|;
comment|/* 22h */
name|MPI_FW_VERSION
name|FWVersion
decl_stmt|;
comment|/* 24h */
name|U32
name|SeqCodeVersion
decl_stmt|;
comment|/* 28h */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 2Ch */
name|U32
name|NextImageHeaderOffset
decl_stmt|;
comment|/* 30h */
name|U32
name|LoadStartAddress
decl_stmt|;
comment|/* 34h */
name|U32
name|IopResetVectorValue
decl_stmt|;
comment|/* 38h */
name|U32
name|IopResetRegAddr
decl_stmt|;
comment|/* 3Ch */
name|U32
name|VersionNameWhat
decl_stmt|;
comment|/* 40h */
name|U8
name|VersionName
index|[
literal|32
index|]
decl_stmt|;
comment|/* 44h */
name|U32
name|VendorNameWhat
decl_stmt|;
comment|/* 64h */
name|U8
name|VendorName
index|[
literal|32
index|]
decl_stmt|;
comment|/* 68h */
block|}
name|MPI_FW_HEADER
operator|,
name|MPI_POINTER
name|PTR_MPI_FW_HEADER
operator|,
name|MpiFwHeader_t
operator|,
name|MPI_POINTER
name|pMpiFwHeader_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FW_HEADER_WHAT_SIGNATURE
value|(0x29232840)
end_define

begin_comment
comment|/* defines for using the ProductId field */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_TYPE_MASK
value|(0xF000)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_TYPE_SCSI
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_TYPE_FC
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_TYPE_SAS
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_SIGNATURE_0
value|(0x5AEAA55A)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_SIGNATURE_1
value|(0xA55AEAA5)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_SIGNATURE_2
value|(0x5AA55AEA)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_MASK
value|(0x0F00)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_INITIATOR_SCSI
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_TARGET_INITIATOR_SCSI
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_TARGET_SCSI
value|(0x0300)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_IM_SCSI
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_IS_SCSI
value|(0x0500)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_CTX_SCSI
value|(0x0600)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_PROD_IR_SCSI
value|(0x0700)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_MASK
value|(0x00FF)
end_define

begin_comment
comment|/* SCSI */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1030A0_SCSI
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1030B0_SCSI
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1030B1_SCSI
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1030C0_SCSI
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1020A0_SCSI
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1020B0_SCSI
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1020B1_SCSI
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1020C0_SCSI
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1035A0_SCSI
value|(0x0009)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1035B0_SCSI
value|(0x000A)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1030TA0_SCSI
value|(0x000B)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1020TA0_SCSI
value|(0x000C)
end_define

begin_comment
comment|/* Fibre Channel */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_909_FC
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_919_FC
value|(0x0001)
end_define

begin_comment
comment|/* 919 and 929     */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_919X_FC
value|(0x0002)
end_define

begin_comment
comment|/* 919X and 929X   */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_919XL_FC
value|(0x0003)
end_define

begin_comment
comment|/* 919XL and 929XL */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_939X_FC
value|(0x0004)
end_define

begin_comment
comment|/* 939X and 949X   */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_959_FC
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_949E_FC
value|(0x0006)
end_define

begin_comment
comment|/* SAS */
end_comment

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1064_SAS
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1068_SAS
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_1078_SAS
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI_FW_HEADER_PID_FAMILY_106xE_SAS
value|(0x0004)
end_define

begin_comment
comment|/* 1068E, 1066E, and 1064E */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_EXT_IMAGE_HEADER
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
name|U32
name|Checksum
decl_stmt|;
comment|/* 04h */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 08h */
name|U32
name|NextImageHeaderOffset
decl_stmt|;
comment|/* 0Ch */
name|U32
name|LoadStartAddress
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 14h */
block|}
name|MPI_EXT_IMAGE_HEADER
operator|,
name|MPI_POINTER
name|PTR_MPI_EXT_IMAGE_HEADER
operator|,
name|MpiExtImageHeader_t
operator|,
name|MPI_POINTER
name|pMpiExtImageHeader_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the ImageType field */
end_comment

begin_define
define|#
directive|define
name|MPI_EXT_IMAGE_TYPE_UNSPECIFIED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_EXT_IMAGE_TYPE_FW
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_EXT_IMAGE_TYPE_NVDATA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_EXT_IMAGE_TYPE_BOOTLOADER
value|(0x04)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

