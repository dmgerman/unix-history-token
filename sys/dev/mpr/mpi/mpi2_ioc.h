begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_ioc.h  *          Title:  MPI IOC, Port, Event, FW Download, and FW Upload messages  *  Creation Date:  October 11, 2006  *  *  mpi2_ioc.h Version:  02.00.30  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  06-04-07  02.00.01  In IOCFacts Reply structure, renamed MaxDevices to  *                      MaxTargets.  *                      Added TotalImageSize field to FWDownload Request.  *                      Added reserved words to FWUpload Request.  *  06-26-07  02.00.02  Added IR Configuration Change List Event.  *  08-31-07  02.00.03  Removed SystemReplyQueueDepth field from the IOCInit  *                      request and replaced it with  *                      ReplyDescriptorPostQueueDepth and ReplyFreeQueueDepth.  *                      Replaced the MinReplyQueueDepth field of the IOCFacts  *                      reply with MaxReplyDescriptorPostQueueDepth.  *                      Added MPI2_RDPQ_DEPTH_MIN define to specify the minimum  *                      depth for the Reply Descriptor Post Queue.  *                      Added SASAddress field to Initiator Device Table  *                      Overflow Event data.  *  10-31-07  02.00.04  Added ReasonCode MPI2_EVENT_SAS_INIT_RC_NOT_RESPONDING  *                      for SAS Initiator Device Status Change Event data.  *                      Modified Reason Code defines for SAS Topology Change  *                      List Event data, including adding a bit for PHY Vacant  *                      status, and adding a mask for the Reason Code.  *                      Added define for  *                      MPI2_EVENT_SAS_TOPO_ES_DELAY_NOT_RESPONDING.  *                      Added define for MPI2_EXT_IMAGE_TYPE_MEGARAID.  *  12-18-07  02.00.05  Added Boot Status defines for the IOCExceptions field of  *                      the IOCFacts Reply.  *                      Removed MPI2_IOCFACTS_CAPABILITY_EXTENDED_BUFFER define.  *                      Moved MPI2_VERSION_UNION to mpi2.h.  *                      Changed MPI2_EVENT_NOTIFICATION_REQUEST to use masks  *                      instead of enables, and added SASBroadcastPrimitiveMasks  *                      field.  *                      Added Log Entry Added Event and related structure.  *  02-29-08  02.00.06  Added define MPI2_IOCFACTS_CAPABILITY_INTEGRATED_RAID.  *                      Removed define MPI2_IOCFACTS_PROTOCOL_SMP_TARGET.  *                      Added MaxVolumes and MaxPersistentEntries fields to  *                      IOCFacts reply.  *                      Added ProtocalFlags and IOCCapabilities fields to  *                      MPI2_FW_IMAGE_HEADER.  *                      Removed MPI2_PORTENABLE_FLAGS_ENABLE_SINGLE_PORT.  *  03-03-08  02.00.07  Fixed MPI2_FW_IMAGE_HEADER by changing Reserved26 to  *                      a U16 (from a U32).  *                      Removed extra 's' from EventMasks name.  *  06-27-08  02.00.08  Fixed an offset in a comment.  *  10-02-08  02.00.09  Removed SystemReplyFrameSize from MPI2_IOC_INIT_REQUEST.  *                      Removed CurReplyFrameSize from MPI2_IOC_FACTS_REPLY and  *                      renamed MinReplyFrameSize to ReplyFrameSize.  *                      Added MPI2_IOCFACTS_EXCEPT_IR_FOREIGN_CONFIG_MAX.  *                      Added two new RAIDOperation values for Integrated RAID  *                      Operations Status Event data.  *                      Added four new IR Configuration Change List Event data  *                      ReasonCode values.  *                      Added two new ReasonCode defines for SAS Device Status  *                      Change Event data.  *                      Added three new DiscoveryStatus bits for the SAS  *                      Discovery event data.  *                      Added Multiplexing Status Change bit to the PhyStatus  *                      field of the SAS Topology Change List event data.  *                      Removed define for MPI2_INIT_IMAGE_BOOTFLAGS_XMEMCOPY.  *                      BootFlags are now product-specific.  *                      Added defines for the indivdual signature bytes  *                      for MPI2_INIT_IMAGE_FOOTER.  *  01-19-09  02.00.10  Added MPI2_IOCFACTS_CAPABILITY_EVENT_REPLAY define.  *                      Added MPI2_EVENT_SAS_DISC_DS_DOWNSTREAM_INITIATOR  *                      define.  *                      Added MPI2_EVENT_SAS_DEV_STAT_RC_SATA_INIT_FAILURE  *                      define.  *                      Removed MPI2_EVENT_SAS_DISC_DS_SATA_INIT_FAILURE define.  *  05-06-09  02.00.11  Added MPI2_IOCFACTS_CAPABILITY_RAID_ACCELERATOR define.  *                      Added MPI2_IOCFACTS_CAPABILITY_MSI_X_INDEX define.  *                      Added two new reason codes for SAS Device Status Change  *                      Event.  *                      Added new event: SAS PHY Counter.  *  07-30-09  02.00.12  Added GPIO Interrupt event define and structure.  *                      Added MPI2_IOCFACTS_CAPABILITY_EXTENDED_BUFFER define.  *                      Added new product id family for 2208.  *  10-28-09  02.00.13  Added HostMSIxVectors field to MPI2_IOC_INIT_REQUEST.  *                      Added MaxMSIxVectors field to MPI2_IOC_FACTS_REPLY.  *                      Added MinDevHandle field to MPI2_IOC_FACTS_REPLY.  *                      Added MPI2_IOCFACTS_CAPABILITY_HOST_BASED_DISCOVERY.  *                      Added MPI2_EVENT_HOST_BASED_DISCOVERY_PHY define.  *                      Added MPI2_EVENT_SAS_TOPO_ES_NO_EXPANDER define.  *                      Added Host Based Discovery Phy Event data.  *                      Added defines for ProductID Product field  *                      (MPI2_FW_HEADER_PID_).  *                      Modified values for SAS ProductID Family  *                      (MPI2_FW_HEADER_PID_FAMILY_).  *  02-10-10  02.00.14  Added SAS Quiesce Event structure and defines.  *                      Added PowerManagementControl Request structures and  *                      defines.  *  05-12-10  02.00.15  Marked Task Set Full Event as obsolete.  *                      Added MPI2_EVENT_SAS_TOPO_LR_UNSUPPORTED_PHY define.  *  11-10-10  02.00.16  Added MPI2_FW_DOWNLOAD_ITYPE_MIN_PRODUCT_SPECIFIC.  *  02-23-11  02.00.17  Added SAS NOTIFY Primitive event, and added  *                      SASNotifyPrimitiveMasks field to  *                      MPI2_EVENT_NOTIFICATION_REQUEST.  *                      Added Temperature Threshold Event.  *                      Added Host Message Event.  *                      Added Send Host Message request and reply.  *  05-25-11  02.00.18  For Extended Image Header, added  *                      MPI2_EXT_IMAGE_TYPE_MIN_PRODUCT_SPECIFIC and  *                      MPI2_EXT_IMAGE_TYPE_MAX_PRODUCT_SPECIFIC defines.  *                      Deprecated MPI2_EXT_IMAGE_TYPE_MAX define.  *  08-24-11  02.00.19  Added PhysicalPort field to  *                      MPI2_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE structure.  *                      Marked MPI2_PM_CONTROL_FEATURE_PCIE_LINK as obsolete.  *  11-18-11  02.00.20  Incorporating additions for MPI v2.5.  *  03-29-12  02.00.21  Added a product specific range to event values.  *  07-26-12  02.00.22  Added MPI2_IOCFACTS_EXCEPT_PARTIAL_MEMORY_FAILURE.  *                      Added ElapsedSeconds field to  *                      MPI2_EVENT_DATA_IR_OPERATION_STATUS.  *  08-19-13  02.00.23  For IOCInit, added MPI2_IOCINIT_MSGFLAG_RDPQ_ARRAY_MODE  *                      and MPI2_IOC_INIT_RDPQ_ARRAY_ENTRY.  *                      Added MPI2_IOCFACTS_CAPABILITY_RDPQ_ARRAY_CAPABLE.  *                      Added MPI2_FW_DOWNLOAD_ITYPE_PUBLIC_KEY.  *                      Added Encrypted Hash Extended Image.  *  12-05-13  02.00.24  Added MPI25_HASH_IMAGE_TYPE_BIOS.  *  11-18-14  02.00.25  Updated copyright information.  *  03-16-15  02.00.26  Updated for MPI v2.6.  *                      Added MPI2_EVENT_ACTIVE_CABLE_EXCEPTION and  *                      MPI26_EVENT_DATA_ACTIVE_CABLE_EXCEPT.  *                      Added MPI2_EVENT_PCIE_LINK_COUNTER and  *                      MPI26_EVENT_DATA_PCIE_LINK_COUNTER.  *                      Added MPI26_CTRL_OP_SHUTDOWN.  *                      Added MPI26_CTRL_OP_LINK_CLEAR_ERROR_LOG  *                      Added MPI26_FW_HEADER_PID_FAMILY_3324_SAS and  *                      MPI26_FW_HEADER_PID_FAMILY_3516_SAS.  *  08-25-15  02.00.27  Added IC ARCH Class based signature defines.  *                      Added MPI26_EVENT_PCIE_ENUM_ES_RESOURCES_EXHAUSTED event.  *                      Added ConigurationFlags field to IOCInit message to  *                      support NVMe SGL format control.  *                      Added PCIe SRIOV support.  * 02-17-16   02.00.28  Added SAS 4 22.5 gbs speed support.  *                      Added PCIe 4 16.0 GT/sec speec support.  *                      Removed AHCI support.  *                      Removed SOP support.  * 07-01-16   02.00.29  Added Archclass for 4008 product.  *                      Added IOCException MPI2_IOCFACTS_EXCEPT_PCIE_DISABLED  * 08-23-16   02.00.30  Added new defines for the ImageType field of FWDownload  *                      Request Message.  *                      Added new defines for the ImageType field of FWUpload  *                      Request Message.  *                      Added new values for the RegionType field in the Layout  *                      Data sections of the FLASH Layout Extended Image Data.  *                      Added new defines for the ReasonCode field of  *                      Active Cable Exception Event.  *                      Added MPI2_EVENT_ENCL_DEVICE_STATUS_CHANGE and  *                      MPI26_EVENT_DATA_ENCL_DEV_STATUS_CHANGE.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IOC_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IOC_H
end_define

begin_comment
comment|/***************************************************************************** * *               IOC Messages * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  IOCInit message ****************************************************************************/
end_comment

begin_comment
comment|/* IOCInit Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_INIT_REQUEST
block|{
name|U8
name|WhoInit
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|MsgVersion
decl_stmt|;
comment|/* 0x0C */
name|U16
name|HeaderVersion
decl_stmt|;
comment|/* 0x0E */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|U16
name|ConfigurationFlags
decl_stmt|;
comment|/* 0x14 */
name|U8
name|HostPageSize
decl_stmt|;
comment|/* 0x16 */
name|U8
name|HostMSIxVectors
decl_stmt|;
comment|/* 0x17 */
name|U16
name|Reserved8
decl_stmt|;
comment|/* 0x18 */
name|U16
name|SystemRequestFrameSize
decl_stmt|;
comment|/* 0x1A */
name|U16
name|ReplyDescriptorPostQueueDepth
decl_stmt|;
comment|/* 0x1C */
name|U16
name|ReplyFreeQueueDepth
decl_stmt|;
comment|/* 0x1E */
name|U32
name|SenseBufferAddressHigh
decl_stmt|;
comment|/* 0x20 */
name|U32
name|SystemReplyAddressHigh
decl_stmt|;
comment|/* 0x24 */
name|U64
name|SystemRequestFrameBaseAddress
decl_stmt|;
comment|/* 0x28 */
name|U64
name|ReplyDescriptorPostQueueAddress
decl_stmt|;
comment|/* 0x30 */
name|U64
name|ReplyFreeQueueAddress
decl_stmt|;
comment|/* 0x38 */
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x40 */
block|}
name|MPI2_IOC_INIT_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_INIT_REQUEST
operator|,
name|Mpi2IOCInitRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCInitRequest_t
typedef|;
end_typedef

begin_comment
comment|/* WhoInit values */
end_comment

begin_define
define|#
directive|define
name|MPI2_WHOINIT_NOT_INITIALIZED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_SYSTEM_BIOS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_ROM_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_PCI_PEER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_HOST_DRIVER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_MANUFACTURER
value|(0x05)
end_define

begin_comment
comment|/* MsgFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCINIT_MSGFLAG_RDPQ_ARRAY_MODE
value|(0x01)
end_define

begin_comment
comment|/* MsgVersion */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCINIT_MSGVERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_MSGVERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_MSGVERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_MSGVERSION_MINOR_SHIFT
value|(0)
end_define

begin_comment
comment|/* HeaderVersion */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCINIT_HDRVERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_HDRVERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_HDRVERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCINIT_HDRVERSION_DEV_SHIFT
value|(0)
end_define

begin_comment
comment|/* ConfigurationFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_IOCINIT_CFGFLAGS_NVME_SGL_FORMAT
value|(0x0001)
end_define

begin_comment
comment|/* minimum depth for a Reply Descriptor Post Queue */
end_comment

begin_define
define|#
directive|define
name|MPI2_RDPQ_DEPTH_MIN
value|(16)
end_define

begin_comment
comment|/* Reply Descriptor Post Queue Array Entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_INIT_RDPQ_ARRAY_ENTRY
block|{
name|U64
name|RDPQBaseAddress
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_IOC_INIT_RDPQ_ARRAY_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_INIT_RDPQ_ARRAY_ENTRY
operator|,
name|Mpi2IOCInitRDPQArrayEntry
operator|,
name|MPI2_POINTER
name|pMpi2IOCInitRDPQArrayEntry
typedef|;
end_typedef

begin_comment
comment|/* IOCInit Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_INIT_REPLY
block|{
name|U8
name|WhoInit
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|MPI2_IOC_INIT_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_INIT_REPLY
operator|,
name|Mpi2IOCInitReply_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCInitReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IOCFacts message ****************************************************************************/
end_comment

begin_comment
comment|/* IOCFacts Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_FACTS_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
block|}
name|MPI2_IOC_FACTS_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_FACTS_REQUEST
operator|,
name|Mpi2IOCFactsRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCFactsRequest_t
typedef|;
end_typedef

begin_comment
comment|/* IOCFacts Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_FACTS_REPLY
block|{
name|U16
name|MsgVersion
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|HeaderVersion
decl_stmt|;
comment|/* 0x04 */
name|U8
name|IOCNumber
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
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U16
name|IOCExceptions
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
name|U8
name|MaxChainDepth
decl_stmt|;
comment|/* 0x14 */
name|U8
name|WhoInit
decl_stmt|;
comment|/* 0x15 */
name|U8
name|NumberOfPorts
decl_stmt|;
comment|/* 0x16 */
name|U8
name|MaxMSIxVectors
decl_stmt|;
comment|/* 0x17 */
name|U16
name|RequestCredit
decl_stmt|;
comment|/* 0x18 */
name|U16
name|ProductID
decl_stmt|;
comment|/* 0x1A */
name|U32
name|IOCCapabilities
decl_stmt|;
comment|/* 0x1C */
name|MPI2_VERSION_UNION
name|FWVersion
decl_stmt|;
comment|/* 0x20 */
name|U16
name|IOCRequestFrameSize
decl_stmt|;
comment|/* 0x24 */
name|U16
name|IOCMaxChainSegmentSize
decl_stmt|;
comment|/* 0x26 */
comment|/* MPI 2.5 only; Reserved in MPI 2.0 */
name|U16
name|MaxInitiators
decl_stmt|;
comment|/* 0x28 */
name|U16
name|MaxTargets
decl_stmt|;
comment|/* 0x2A */
name|U16
name|MaxSasExpanders
decl_stmt|;
comment|/* 0x2C */
name|U16
name|MaxEnclosures
decl_stmt|;
comment|/* 0x2E */
name|U16
name|ProtocolFlags
decl_stmt|;
comment|/* 0x30 */
name|U16
name|HighPriorityCredit
decl_stmt|;
comment|/* 0x32 */
name|U16
name|MaxReplyDescriptorPostQueueDepth
decl_stmt|;
comment|/* 0x34 */
name|U8
name|ReplyFrameSize
decl_stmt|;
comment|/* 0x36 */
name|U8
name|MaxVolumes
decl_stmt|;
comment|/* 0x37 */
name|U16
name|MaxDevHandle
decl_stmt|;
comment|/* 0x38 */
name|U16
name|MaxPersistentEntries
decl_stmt|;
comment|/* 0x3A */
name|U16
name|MinDevHandle
decl_stmt|;
comment|/* 0x3C */
name|U8
name|CurrentHostPageSize
decl_stmt|;
comment|/* 0x3E */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x3F */
name|U8
name|SGEModifierMask
decl_stmt|;
comment|/* 0x40 */
name|U8
name|SGEModifierValue
decl_stmt|;
comment|/* 0x41 */
name|U8
name|SGEModifierShift
decl_stmt|;
comment|/* 0x42 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x43 */
block|}
name|MPI2_IOC_FACTS_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_FACTS_REPLY
operator|,
name|Mpi2IOCFactsReply_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCFactsReply_t
typedef|;
end_typedef

begin_comment
comment|/* MsgVersion */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_MSGVERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_MSGVERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_MSGVERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_MSGVERSION_MINOR_SHIFT
value|(0)
end_define

begin_comment
comment|/* HeaderVersion */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_HDRVERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_HDRVERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_HDRVERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_HDRVERSION_DEV_SHIFT
value|(0)
end_define

begin_comment
comment|/* IOCExceptions */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_PCIE_DISABLED
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_PARTIAL_MEMORY_FAILURE
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_IR_FOREIGN_CONFIG_MAX
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_BOOTSTAT_MASK
value|(0x00E0)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_BOOTSTAT_GOOD
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_BOOTSTAT_BACKUP
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_BOOTSTAT_RESTORED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_BOOTSTAT_CORRUPT_BACKUP
value|(0x0060)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_METADATA_UNSUPPORTED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_MANUFACT_CHECKSUM_FAIL
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_FW_CHECKSUM_FAIL
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_RAID_CONFIG_INVALID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_EXCEPT_CONFIG_CHECKSUM_FAIL
value|(0x0001)
end_define

begin_comment
comment|/* defines for WhoInit field are after the IOCInit Request */
end_comment

begin_comment
comment|/* ProductID field uses MPI2_FW_HEADER_PID_ */
end_comment

begin_comment
comment|/* IOCCapabilities */
end_comment

begin_define
define|#
directive|define
name|MPI26_IOCFACTS_CAPABILITY_PCIE_SRIOV
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI26_IOCFACTS_CAPABILITY_ATOMIC_REQ
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_RDPQ_ARRAY_CAPABLE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOCFACTS_CAPABILITY_FAST_PATH_CAPABLE
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_HOST_BASED_DISCOVERY
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_MSI_X_INDEX
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_RAID_ACCELERATOR
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_EVENT_REPLAY
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_INTEGRATED_RAID
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_TLR
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_MULTICAST
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_BIDIRECTIONAL_TARGET
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_EEDP
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_EXTENDED_BUFFER
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_SNAPSHOT_BUFFER
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_DIAG_TRACE_BUFFER
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_CAPABILITY_TASK_SET_FULL_HANDLING
value|(0x00000004)
end_define

begin_comment
comment|/* ProtocolFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_PROTOCOL_NVME_DEVICES
value|(0x0008)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_PROTOCOL_SCSI_INITIATOR
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCFACTS_PROTOCOL_SCSI_TARGET
value|(0x0001)
end_define

begin_comment
comment|/**************************************************************************** *  PortFacts message ****************************************************************************/
end_comment

begin_comment
comment|/* PortFacts Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PORT_FACTS_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PortNumber
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
block|}
name|MPI2_PORT_FACTS_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PORT_FACTS_REQUEST
operator|,
name|Mpi2PortFactsRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2PortFactsRequest_t
typedef|;
end_typedef

begin_comment
comment|/* PortFacts Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PORT_FACTS_REPLY
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PortNumber
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
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x14 */
name|U8
name|PortType
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x16 */
name|U16
name|MaxPostedCmdBuffers
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Reserved7
decl_stmt|;
comment|/* 0x1A */
block|}
name|MPI2_PORT_FACTS_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PORT_FACTS_REPLY
operator|,
name|Mpi2PortFactsReply_t
operator|,
name|MPI2_POINTER
name|pMpi2PortFactsReply_t
typedef|;
end_typedef

begin_comment
comment|/* PortType values */
end_comment

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_INACTIVE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_FC
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_ISCSI
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_SAS_PHYSICAL
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_SAS_VIRTUAL
value|(0x31)
end_define

begin_define
define|#
directive|define
name|MPI2_PORTFACTS_PORTTYPE_TRI_MODE
value|(0x40)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_comment
comment|/**************************************************************************** *  PortEnable message ****************************************************************************/
end_comment

begin_comment
comment|/* PortEnable Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PORT_ENABLE_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
block|}
name|MPI2_PORT_ENABLE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PORT_ENABLE_REQUEST
operator|,
name|Mpi2PortEnableRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2PortEnableRequest_t
typedef|;
end_typedef

begin_comment
comment|/* PortEnable Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PORT_ENABLE_REPLY
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|MPI2_PORT_ENABLE_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PORT_ENABLE_REPLY
operator|,
name|Mpi2PortEnableReply_t
operator|,
name|MPI2_POINTER
name|pMpi2PortEnableReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  EventNotification message ****************************************************************************/
end_comment

begin_comment
comment|/* EventNotification Request message */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFY_EVENTMASK_WORDS
value|(4)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_NOTIFICATION_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x10 */
name|U32
name|EventMasks
index|[
name|MPI2_EVENT_NOTIFY_EVENTMASK_WORDS
index|]
decl_stmt|;
comment|/* 0x14 */
name|U16
name|SASBroadcastPrimitiveMasks
decl_stmt|;
comment|/* 0x24 */
name|U16
name|SASNotifyPrimitiveMasks
decl_stmt|;
comment|/* 0x26 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x28 */
block|}
name|MPI2_EVENT_NOTIFICATION_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_NOTIFICATION_REQUEST
operator|,
name|Mpi2EventNotificationRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2EventNotificationRequest_t
typedef|;
end_typedef

begin_comment
comment|/* EventNotification Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_NOTIFICATION_REPLY
block|{
name|U16
name|EventDataLength
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|AckRequired
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved3
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
name|U16
name|Event
decl_stmt|;
comment|/* 0x14 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x16 */
name|U32
name|EventContext
decl_stmt|;
comment|/* 0x18 */
name|U32
name|EventData
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_EVENT_NOTIFICATION_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_NOTIFICATION_REPLY
operator|,
name|Mpi2EventNotificationReply_t
operator|,
name|MPI2_POINTER
name|pMpi2EventNotificationReply_t
typedef|;
end_typedef

begin_comment
comment|/* AckRequired */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFICATION_ACK_NOT_REQUIRED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFICATION_ACK_REQUIRED
value|(0x01)
end_define

begin_comment
comment|/* Event */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_LOG_DATA
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_STATE_CHANGE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_HARD_RESET_RECEIVED
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_EVENT_CHANGE
value|(0x000A)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_TASK_SET_FULL
value|(0x000E)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEVICE_STATUS_CHANGE
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_OPERATION_STATUS
value|(0x0014)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISCOVERY
value|(0x0016)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_BROADCAST_PRIMITIVE
value|(0x0017)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_INIT_DEVICE_STATUS_CHANGE
value|(0x0018)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_INIT_TABLE_OVERFLOW
value|(0x0019)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPOLOGY_CHANGE_LIST
value|(0x001C)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_ENCL_DEVICE_STATUS_CHANGE
value|(0x001D)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_ENCL_DEVICE_STATUS_CHANGE
value|(0x001D)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_VOLUME
value|(0x001E)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_PHYSICAL_DISK
value|(0x001F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CONFIGURATION_CHANGE_LIST
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_LOG_ENTRY_ADDED
value|(0x0021)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_PHY_COUNTER
value|(0x0022)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_GPIO_INTERRUPT
value|(0x0023)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_HOST_BASED_DISCOVERY_PHY
value|(0x0024)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_QUIESCE
value|(0x0025)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_NOTIFY_PRIMITIVE
value|(0x0026)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_TEMP_THRESHOLD
value|(0x0027)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_HOST_MESSAGE
value|(0x0028)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_POWER_PERFORMANCE_CHANGE
value|(0x0029)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PCIE_DEVICE_STATUS_CHANGE
value|(0x0030)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_PCIE_ENUMERATION
value|(0x0031)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_PCIE_TOPOLOGY_CHANGE_LIST
value|(0x0032)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_PCIE_LINK_COUNTER
value|(0x0033)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_ACTIVE_CABLE_EXCEPTION
value|(0x0034)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_MIN_PRODUCT_SPECIFIC
value|(0x006E)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_MAX_PRODUCT_SPECIFIC
value|(0x007F)
end_define

begin_comment
comment|/* Log Entry Added Event data */
end_comment

begin_comment
comment|/* the following structure matches MPI2_LOG_0_ENTRY in mpi2_cnfg.h */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_DATA_LOG_DATA_LENGTH
value|(0x1C)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_LOG_ENTRY_ADDED
block|{
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U16
name|LogSequence
decl_stmt|;
comment|/* 0x0C */
name|U16
name|LogEntryQualifier
decl_stmt|;
comment|/* 0x0E */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x10 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x12 */
name|U8
name|LogData
index|[
name|MPI2_EVENT_DATA_LOG_DATA_LENGTH
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_EVENT_DATA_LOG_ENTRY_ADDED
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_LOG_ENTRY_ADDED
operator|,
name|Mpi2EventDataLogEntryAdded_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataLogEntryAdded_t
typedef|;
end_typedef

begin_comment
comment|/* GPIO Interrupt Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_GPIO_INTERRUPT
block|{
name|U8
name|GPIONum
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_EVENT_DATA_GPIO_INTERRUPT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_GPIO_INTERRUPT
operator|,
name|Mpi2EventDataGpioInterrupt_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataGpioInterrupt_t
typedef|;
end_typedef

begin_comment
comment|/* Temperature Threshold Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_TEMPERATURE
block|{
name|U16
name|Status
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SensorNum
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U16
name|CurrentTemperature
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_EVENT_DATA_TEMPERATURE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_TEMPERATURE
operator|,
name|Mpi2EventDataTemperature_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataTemperature_t
typedef|;
end_typedef

begin_comment
comment|/* Temperature Threshold Event data Status bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_TEMPERATURE3_EXCEEDED
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_TEMPERATURE2_EXCEEDED
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_TEMPERATURE1_EXCEEDED
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_TEMPERATURE0_EXCEEDED
value|(0x0001)
end_define

begin_comment
comment|/* Host Message Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_HOST_MESSAGE
block|{
name|U8
name|SourceVF_ID
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x04 */
name|U32
name|HostData
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_DATA_HOST_MESSAGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_HOST_MESSAGE
operator|,
name|Mpi2EventDataHostMessage_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataHostMessage_t
typedef|;
end_typedef

begin_comment
comment|/* Power Performance Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_POWER_PERF_CHANGE
block|{
name|U8
name|CurrentPowerMode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PreviousPowerMode
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_EVENT_DATA_POWER_PERF_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_POWER_PERF_CHANGE
operator|,
name|Mpi2EventDataPowerPerfChange_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataPowerPerfChange_t
typedef|;
end_typedef

begin_comment
comment|/* defines for CurrentPowerMode and PreviousPowerMode fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_INIT_MASK
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_INIT_UNAVAILABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_INIT_HOST
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_INIT_IO_UNIT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_INIT_PCIE_DPA
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_MASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_UNAVAILABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_UNKNOWN
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_FULL_POWER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_REDUCED_POWER
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PM_MODE_STANDBY
value|(0x06)
end_define

begin_comment
comment|/* Active Cable Exception Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_DATA_ACTIVE_CABLE_EXCEPT
block|{
name|U32
name|ActiveCablePowerRequirement
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ReceptacleID
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI26_EVENT_DATA_ACTIVE_CABLE_EXCEPT
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_ACTIVE_CABLE_EXCEPT
operator|,
name|Mpi26EventDataActiveCableExcept_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataActiveCableExcept_t
typedef|;
end_typedef

begin_comment
comment|/* defines for ReasonCode field */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_ACTIVE_CABLE_INSUFFICIENT_POWER
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_ACTIVE_CABLE_PRESENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_ACTIVE_CABLE_DEGRADED
value|(0x02)
end_define

begin_comment
comment|/* Hard Reset Received Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_HARD_RESET_RECEIVED
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Port
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_EVENT_DATA_HARD_RESET_RECEIVED
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_HARD_RESET_RECEIVED
operator|,
name|Mpi2EventDataHardResetReceived_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataHardResetReceived_t
typedef|;
end_typedef

begin_comment
comment|/* Task Set Full Event data */
end_comment

begin_comment
comment|/*   this event is obsolete */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_TASK_SET_FULL
block|{
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|CurrentDepth
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_EVENT_DATA_TASK_SET_FULL
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_TASK_SET_FULL
operator|,
name|Mpi2EventDataTaskSetFull_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataTaskSetFull_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Device Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
block|{
name|U16
name|TaskTag
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x03 */
name|U8
name|ASC
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ASCQ
decl_stmt|;
comment|/* 0x05 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x0C */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_DEVICE_STATUS_CHANGE
operator|,
name|Mpi2EventDataSasDeviceStatusChange_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasDeviceStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Device Status Change Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_SMART_DATA
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_UNSUPPORTED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_INTERNAL_DEVICE_RESET
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_TASK_ABORT_INTERNAL
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_ABORT_TASK_SET_INTERNAL
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_CLEAR_TASK_SET_INTERNAL
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_QUERY_TASK_INTERNAL
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_ASYNC_NOTIFICATION
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_CMP_INTERNAL_DEV_RESET
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_CMP_TASK_ABORT_INTERNAL
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_SATA_INIT_FAILURE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_EXPANDER_REDUCED_FUNCTIONALITY
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DEV_STAT_RC_CMP_EXPANDER_REDUCED_FUNCTIONALITY
value|(0x12)
end_define

begin_comment
comment|/* Integrated RAID Operation Status Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_IR_OPERATION_STATUS
block|{
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U8
name|RAIDOperation
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PercentComplete
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U32
name|ElapsedSeconds
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_DATA_IR_OPERATION_STATUS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_IR_OPERATION_STATUS
operator|,
name|Mpi2EventDataIrOperationStatus_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataIrOperationStatus_t
typedef|;
end_typedef

begin_comment
comment|/* Integrated RAID Operation Status Event data RAIDOperation values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_RAIDOP_RESYNC
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_RAIDOP_ONLINE_CAP_EXPANSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_RAIDOP_CONSISTENCY_CHECK
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_RAIDOP_BACKGROUND_INIT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_RAIDOP_MAKE_DATA_CONSISTENT
value|(0x04)
end_define

begin_comment
comment|/* Integrated RAID Volume Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_IR_VOLUME
block|{
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U32
name|NewValue
decl_stmt|;
comment|/* 0x04 */
name|U32
name|PreviousValue
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_DATA_IR_VOLUME
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_IR_VOLUME
operator|,
name|Mpi2EventDataIrVolume_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataIrVolume_t
typedef|;
end_typedef

begin_comment
comment|/* Integrated RAID Volume Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_VOLUME_RC_SETTINGS_CHANGED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_VOLUME_RC_STATUS_FLAGS_CHANGED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_VOLUME_RC_STATE_CHANGED
value|(0x03)
end_define

begin_comment
comment|/* Integrated RAID Physical Disk Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_IR_PHYSICAL_DISK
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x03 */
name|U16
name|PhysDiskDevHandle
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x08 */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x0A */
name|U32
name|NewValue
decl_stmt|;
comment|/* 0x0C */
name|U32
name|PreviousValue
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_EVENT_DATA_IR_PHYSICAL_DISK
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_IR_PHYSICAL_DISK
operator|,
name|Mpi2EventDataIrPhysicalDisk_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataIrPhysicalDisk_t
typedef|;
end_typedef

begin_comment
comment|/* Integrated RAID Physical Disk Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_PHYSDISK_RC_SETTINGS_CHANGED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_PHYSDISK_RC_STATUS_FLAGS_CHANGED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_PHYSDISK_RC_STATE_CHANGED
value|(0x03)
end_define

begin_comment
comment|/* Integrated RAID Configuration Change List Event data */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumElements at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_EVENT_IR_CONFIG_ELEMENT_COUNT
end_ifndef

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CONFIG_ELEMENT_COUNT
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_IR_CONFIG_ELEMENT
block|{
name|U16
name|ElementFlags
decl_stmt|;
comment|/* 0x00 */
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x02 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x05 */
name|U16
name|PhysDiskDevHandle
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_EVENT_IR_CONFIG_ELEMENT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_IR_CONFIG_ELEMENT
operator|,
name|Mpi2EventIrConfigElement_t
operator|,
name|MPI2_POINTER
name|pMpi2EventIrConfigElement_t
typedef|;
end_typedef

begin_comment
comment|/* IR Configuration Change List Event data ElementFlags values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_EFLAGS_ELEMENT_TYPE_MASK
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_EFLAGS_VOLUME_ELEMENT
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_EFLAGS_VOLPHYSDISK_ELEMENT
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_EFLAGS_HOTSPARE_ELEMENT
value|(0x0002)
end_define

begin_comment
comment|/* IR Configuration Change List Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_REMOVED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_NO_CHANGE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_HIDE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_UNHIDE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_VOLUME_CREATED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_VOLUME_DELETED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_PD_CREATED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_RC_PD_DELETED
value|(0x09)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_IR_CONFIG_CHANGE_LIST
block|{
name|U8
name|NumElements
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U8
name|ConfigNum
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|MPI2_EVENT_IR_CONFIG_ELEMENT
name|ConfigElement
index|[
name|MPI2_EVENT_IR_CONFIG_ELEMENT_COUNT
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_DATA_IR_CONFIG_CHANGE_LIST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_IR_CONFIG_CHANGE_LIST
operator|,
name|Mpi2EventDataIrConfigChangeList_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataIrConfigChangeList_t
typedef|;
end_typedef

begin_comment
comment|/* IR Configuration Change List Event data Flags values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_IR_CHANGE_FLAGS_FOREIGN_CONFIG
value|(0x00000001)
end_define

begin_comment
comment|/* SAS Discovery Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_DISCOVERY
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_EVENT_DATA_SAS_DISCOVERY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_DISCOVERY
operator|,
name|Mpi2EventDataSasDiscovery_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasDiscovery_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Discovery Event data Flags values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DEVICE_CHANGE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_IN_PROGRESS
value|(0x01)
end_define

begin_comment
comment|/* SAS Discovery Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_RC_STARTED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_RC_COMPLETED
value|(0x02)
end_define

begin_comment
comment|/* SAS Discovery Event data DiscoveryStatus values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MAX_ENCLOSURES_EXCEED
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MAX_EXPANDERS_EXCEED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MAX_DEVICES_EXCEED
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MAX_TOPO_PHYS_EXCEED
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_DOWNSTREAM_INITIATOR
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MULTI_SUBTRACTIVE_SUBTRACTIVE
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_EXP_MULTI_SUBTRACTIVE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MULTI_PORT_DOMAIN
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_TABLE_TO_SUBTRACTIVE_LINK
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_UNSUPPORTED_DEVICE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_TABLE_LINK
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_SUBTRACTIVE_LINK
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_DISC_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_comment
comment|/* SAS Broadcast Primitive Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_BROADCAST_PRIMITIVE
block|{
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Port
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PortWidth
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Primitive
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_EVENT_DATA_SAS_BROADCAST_PRIMITIVE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_BROADCAST_PRIMITIVE
operator|,
name|Mpi2EventDataSasBroadcastPrimitive_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasBroadcastPrimitive_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Primitive field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_CHANGE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_SES
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_EXPANDER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_ASYNCHRONOUS_EVENT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_RESERVED3
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_RESERVED4
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_CHANGE0_RESERVED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_PRIMITIVE_CHANGE1_RESERVED
value|(0x08)
end_define

begin_comment
comment|/* SAS Notify Primitive Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_NOTIFY_PRIMITIVE
block|{
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Port
decl_stmt|;
comment|/* 0x01 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Primitive
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_EVENT_DATA_SAS_NOTIFY_PRIMITIVE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_NOTIFY_PRIMITIVE
operator|,
name|Mpi2EventDataSasNotifyPrimitive_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasNotifyPrimitive_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Primitive field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFY_ENABLE_SPINUP
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFY_POWER_LOSS_EXPECTED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFY_RESERVED1
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_NOTIFY_RESERVED2
value|(0x04)
end_define

begin_comment
comment|/* SAS Initiator Device Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_INIT_DEV_STATUS_CHANGE
block|{
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x01 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x02 */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_EVENT_DATA_SAS_INIT_DEV_STATUS_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_INIT_DEV_STATUS_CHANGE
operator|,
name|Mpi2EventDataSasInitDevStatusChange_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasInitDevStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Initiator Device Status Change event ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_INIT_RC_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_INIT_RC_NOT_RESPONDING
value|(0x02)
end_define

begin_comment
comment|/* SAS Initiator Device Table Overflow Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_INIT_TABLE_OVERFLOW
block|{
name|U16
name|MaxInit
decl_stmt|;
comment|/* 0x00 */
name|U16
name|CurrentInit
decl_stmt|;
comment|/* 0x02 */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_EVENT_DATA_SAS_INIT_TABLE_OVERFLOW
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_INIT_TABLE_OVERFLOW
operator|,
name|Mpi2EventDataSasInitTableOverflow_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasInitTableOverflow_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Topology Change List Event data */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumEntries at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_EVENT_SAS_TOPO_PHY_COUNT
end_ifndef

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_PHY_COUNT
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_SAS_TOPO_PHY_ENTRY
block|{
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x00 */
name|U8
name|LinkRate
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhyStatus
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_EVENT_SAS_TOPO_PHY_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_SAS_TOPO_PHY_ENTRY
operator|,
name|Mpi2EventSasTopoPhyEntry_t
operator|,
name|MPI2_POINTER
name|pMpi2EventSasTopoPhyEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_TOPOLOGY_CHANGE_LIST
block|{
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|ExpanderDevHandle
decl_stmt|;
comment|/* 0x02 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|NumEntries
decl_stmt|;
comment|/* 0x08 */
name|U8
name|StartPhyNum
decl_stmt|;
comment|/* 0x09 */
name|U8
name|ExpStatus
decl_stmt|;
comment|/* 0x0A */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x0B */
name|MPI2_EVENT_SAS_TOPO_PHY_ENTRY
name|PHY
index|[
name|MPI2_EVENT_SAS_TOPO_PHY_COUNT
index|]
decl_stmt|;
comment|/* 0x0C*/
block|}
name|MPI2_EVENT_DATA_SAS_TOPOLOGY_CHANGE_LIST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_TOPOLOGY_CHANGE_LIST
operator|,
name|Mpi2EventDataSasTopologyChangeList_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasTopologyChangeList_t
typedef|;
end_typedef

begin_comment
comment|/* values for the ExpStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_ES_NO_EXPANDER
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_ES_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_ES_NOT_RESPONDING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_ES_RESPONDING
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_ES_DELAY_NOT_RESPONDING
value|(0x04)
end_define

begin_comment
comment|/* defines for the LinkRate field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_CURRENT_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_CURRENT_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_PREV_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_PREV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_UNKNOWN_LINK_RATE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_NEGOTIATION_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_SATA_OOB_COMPLETE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_PORT_SELECTOR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_SMP_RESET_IN_PROGRESS
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_UNSUPPORTED_PHY
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_LR_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_EVENT_SAS_TOPO_LR_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_SAS_TOPO_LR_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/* values for the PhyStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_PHYSTATUS_VACANT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_PS_MULTIPLEX_CHANGE
value|(0x10)
end_define

begin_comment
comment|/* values for the PhyStatus ReasonCode sub-field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_TARG_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_TARG_NOT_RESPONDING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_PHY_CHANGED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_NO_CHANGE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_TOPO_RC_DELAY_NOT_RESPONDING
value|(0x05)
end_define

begin_comment
comment|/* SAS Enclosure Device Status Change Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_ENCL_DEV_STATUS_CHANGE
block|{
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x03 */
name|U64
name|EnclosureLogicalID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|NumSlots
decl_stmt|;
comment|/* 0x0C */
name|U16
name|StartSlot
decl_stmt|;
comment|/* 0x0E */
name|U32
name|PhyBits
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_EVENT_DATA_SAS_ENCL_DEV_STATUS_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_ENCL_DEV_STATUS_CHANGE
operator|,
name|Mpi2EventDataSasEnclDevStatusChange_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasEnclDevStatusChange_t
operator|,
name|MPI26_EVENT_DATA_ENCL_DEV_STATUS_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_ENCL_DEV_STATUS_CHANGE
operator|,
name|Mpi26EventDataEnclDevStatusChange_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataEnclDevStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Enclosure Device Status Change event ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_ENCL_RC_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_ENCL_RC_NOT_RESPONDING
value|(0x02)
end_define

begin_comment
comment|/* Enclosure Device Status Change event ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_ENCL_RC_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_ENCL_RC_NOT_RESPONDING
value|(0x02)
end_define

begin_comment
comment|/* SAS PHY Counter Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_PHY_COUNTER
block|{
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|PhyEventCode
decl_stmt|;
comment|/* 0x0C */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0E */
name|U32
name|PhyEventInfo
decl_stmt|;
comment|/* 0x10 */
name|U8
name|CounterType
decl_stmt|;
comment|/* 0x14 */
name|U8
name|ThresholdWindow
decl_stmt|;
comment|/* 0x15 */
name|U8
name|TimeUnits
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|EventThreshold
decl_stmt|;
comment|/* 0x18 */
name|U16
name|ThresholdFlags
decl_stmt|;
comment|/* 0x1C */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI2_EVENT_DATA_SAS_PHY_COUNTER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_PHY_COUNTER
operator|,
name|Mpi2EventDataSasPhyCounter_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasPhyCounter_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_SASPHY3_EVENT_CODE_ values from mpi2_cnfg.h for the PhyEventCode field */
end_comment

begin_comment
comment|/* use MPI2_SASPHY3_COUNTER_TYPE_ values from mpi2_cnfg.h for the CounterType field */
end_comment

begin_comment
comment|/* use MPI2_SASPHY3_TIME_UNITS_ values from mpi2_cnfg.h for the TimeUnits field */
end_comment

begin_comment
comment|/* use MPI2_SASPHY3_TFLAGS_ values from mpi2_cnfg.h for the ThresholdFlags field */
end_comment

begin_comment
comment|/* SAS Quiesce Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_SAS_QUIESCE
block|{
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_EVENT_DATA_SAS_QUIESCE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_SAS_QUIESCE
operator|,
name|Mpi2EventDataSasQuiesce_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataSasQuiesce_t
typedef|;
end_typedef

begin_comment
comment|/* SAS Quiesce Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_QUIESCE_RC_STARTED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_SAS_QUIESCE_RC_COMPLETED
value|(0x02)
end_define

begin_comment
comment|/* Host Based Discovery Phy Event data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_HBD_PHY_SAS
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|InitialFrame
index|[
literal|28
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_HBD_PHY_SAS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_HBD_PHY_SAS
operator|,
name|Mpi2EventHbdPhySas_t
operator|,
name|MPI2_POINTER
name|pMpi2EventHbdPhySas_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_HBD_SAS_FLAGS_FRAME_VALID
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_EVENT_HBD_SAS_FLAGS_SATA_FRAME
value|(0x01)
end_define

begin_comment
comment|/* use MPI2_SAS_NEG_LINK_RATE_ defines from mpi2_cnfg.h for the NegotiatedLinkRate field */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_EVENT_HBD_DESCRIPTOR
block|{
name|MPI2_EVENT_HBD_PHY_SAS
name|Sas
decl_stmt|;
block|}
name|MPI2_EVENT_HBD_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_HBD_DESCRIPTOR
operator|,
name|Mpi2EventHbdDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2EventHbdDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_DATA_HBD_PHY
block|{
name|U8
name|DescriptorType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x04 */
name|MPI2_EVENT_HBD_DESCRIPTOR
name|Descriptor
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_EVENT_DATA_HBD_PHY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_DATA_HBD_PHY
operator|,
name|Mpi2EventDataHbdPhy_t
operator|,
name|MPI2_POINTER
name|pMpi2EventDataMpi2EventDataHbdPhy_t
typedef|;
end_typedef

begin_comment
comment|/* values for the DescriptorType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EVENT_HBD_DT_SAS
value|(0x01)
end_define

begin_comment
comment|/* PCIe Device Status Change Event data (MPI v2.6 and later) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_DATA_PCIE_DEVICE_STATUS_CHANGE
block|{
name|U16
name|TaskTag
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x03 */
name|U8
name|ASC
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ASCQ
decl_stmt|;
comment|/* 0x05 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U64
name|WWID
decl_stmt|;
comment|/* 0x0C */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI26_EVENT_DATA_PCIE_DEVICE_STATUS_CHANGE
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_PCIE_DEVICE_STATUS_CHANGE
operator|,
name|Mpi26EventDataPCIeDeviceStatusChange_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataPCIeDeviceStatusChange_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Device Status Change Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_SMART_DATA
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_UNSUPPORTED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_INTERNAL_DEVICE_RESET
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_TASK_ABORT_INTERNAL
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_ABORT_TASK_SET_INTERNAL
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_CLEAR_TASK_SET_INTERNAL
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_QUERY_TASK_INTERNAL
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_ASYNC_NOTIFICATION
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_CMP_INTERNAL_DEV_RESET
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_CMP_TASK_ABORT_INTERNAL
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIDEV_STAT_RC_DEV_INIT_FAILURE
value|(0x10)
end_define

begin_comment
comment|/* PCIe Enumeration Event data (MPI v2.6 and later) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_DATA_PCIE_ENUMERATION
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ReasonCode
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U32
name|EnumerationStatus
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI26_EVENT_DATA_PCIE_ENUMERATION
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_PCIE_ENUMERATION
operator|,
name|Mpi26EventDataPCIeEnumeration_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataPCIeEnumeration_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Enumeration Event data Flags values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_DEVICE_CHANGE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_IN_PROGRESS
value|(0x01)
end_define

begin_comment
comment|/* PCIe Enumeration Event data ReasonCode values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_RC_STARTED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_RC_COMPLETED
value|(0x02)
end_define

begin_comment
comment|/* PCIe Enumeration Event data EnumerationStatus values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_ES_MAX_SWITCHES_EXCEED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_ES_MAX_DEVICES_EXCEED
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_ENUM_ES_RESOURCES_EXHAUSTED
value|(0x10000000)
end_define

begin_comment
comment|/* PCIe Topology Change List Event data (MPI v2.6 and later) */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumEntries at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_EVENT_PCIE_TOPO_PORT_COUNT
end_ifndef

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PORT_COUNT
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_PCIE_TOPO_PORT_ENTRY
block|{
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PortStatus
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U8
name|CurrentPortInfo
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x05 */
name|U8
name|PreviousPortInfo
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x07 */
block|}
name|MPI26_EVENT_PCIE_TOPO_PORT_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_PCIE_TOPO_PORT_ENTRY
operator|,
name|Mpi26EventPCIeTopoPortEntry_t
operator|,
name|MPI2_POINTER
name|pMpi26EventPCIeTopoPortEntry_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Topology Change List Event data PortStatus values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PS_DEV_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PS_NOT_RESPONDING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PS_PORT_CHANGED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PS_NO_CHANGE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PS_DELAY_NOT_RESPONDING
value|(0x05)
end_define

begin_comment
comment|/* PCIe Topology Change List Event data defines for CurrentPortInfo and PreviousPortInfo */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_LANE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_LANES_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_1_LANE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_2_LANES
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_4_LANES
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_8_LANES
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_2_5
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_5_0
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_8_0
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_PI_RATE_16_0
value|(0x05)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_DATA_PCIE_TOPOLOGY_CHANGE_LIST
block|{
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|SwitchDevHandle
decl_stmt|;
comment|/* 0x02 */
name|U8
name|NumPorts
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|NumEntries
decl_stmt|;
comment|/* 0x08 */
name|U8
name|StartPortNum
decl_stmt|;
comment|/* 0x09 */
name|U8
name|SwitchStatus
decl_stmt|;
comment|/* 0x0A */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x0B */
name|MPI26_EVENT_PCIE_TOPO_PORT_ENTRY
name|PortEntry
index|[
name|MPI26_EVENT_PCIE_TOPO_PORT_COUNT
index|]
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI26_EVENT_DATA_PCIE_TOPOLOGY_CHANGE_LIST
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_PCIE_TOPOLOGY_CHANGE_LIST
operator|,
name|Mpi26EventDataPCIeTopologyChangeList_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataPCIeTopologyChangeList_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Topology Change List Event data SwitchStatus values */
end_comment

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_SS_NO_PCIE_SWITCH
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_SS_ADDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_SS_NOT_RESPONDING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_SS_RESPONDING
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI26_EVENT_PCIE_TOPO_SS_DELAY_NOT_RESPONDING
value|(0x04)
end_define

begin_comment
comment|/* PCIe Link Counter Event data (MPI v2.6 and later) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_EVENT_DATA_PCIE_LINK_COUNTER
block|{
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|LinkEventCode
decl_stmt|;
comment|/* 0x0C */
name|U8
name|LinkNum
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0E */
name|U32
name|LinkEventInfo
decl_stmt|;
comment|/* 0x10 */
name|U8
name|CounterType
decl_stmt|;
comment|/* 0x14 */
name|U8
name|ThresholdWindow
decl_stmt|;
comment|/* 0x15 */
name|U8
name|TimeUnits
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|EventThreshold
decl_stmt|;
comment|/* 0x18 */
name|U16
name|ThresholdFlags
decl_stmt|;
comment|/* 0x1C */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI26_EVENT_DATA_PCIE_LINK_COUNTER
operator|,
name|MPI2_POINTER
name|PTR_MPI26_EVENT_DATA_PCIE_LINK_COUNTER
operator|,
name|Mpi26EventDataPcieLinkCounter_t
operator|,
name|MPI2_POINTER
name|pMpi26EventDataPcieLinkCounter_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI26_PCIELINK3_EVTCODE_ values from mpi2_cnfg.h for the LinkEventCode field */
end_comment

begin_comment
comment|/* use MPI26_PCIELINK3_COUNTER_TYPE_ values from mpi2_cnfg.h for the CounterType field */
end_comment

begin_comment
comment|/* use MPI26_PCIELINK3_TIME_UNITS_ values from mpi2_cnfg.h for the TimeUnits field */
end_comment

begin_comment
comment|/* use MPI26_PCIELINK3_TFLAGS_ values from mpi2_cnfg.h for the ThresholdFlags field */
end_comment

begin_comment
comment|/**************************************************************************** *  EventAck message ****************************************************************************/
end_comment

begin_comment
comment|/* EventAck Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_ACK_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Event
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x0E */
name|U32
name|EventContext
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_EVENT_ACK_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_ACK_REQUEST
operator|,
name|Mpi2EventAckRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2EventAckRequest_t
typedef|;
end_typedef

begin_comment
comment|/* EventAck Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EVENT_ACK_REPLY
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|MPI2_EVENT_ACK_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EVENT_ACK_REPLY
operator|,
name|Mpi2EventAckReply_t
operator|,
name|MPI2_POINTER
name|pMpi2EventAckReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  SendHostMessage message ****************************************************************************/
end_comment

begin_comment
comment|/* SendHostMessage Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SEND_HOST_MESSAGE_REQUEST
block|{
name|U16
name|HostDataLength
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved1
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
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|U8
name|DestVF_ID
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x0E */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 0x20 */
name|U32
name|HostData
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x24 */
block|}
name|MPI2_SEND_HOST_MESSAGE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SEND_HOST_MESSAGE_REQUEST
operator|,
name|Mpi2SendHostMessageRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SendHostMessageRequest_t
typedef|;
end_typedef

begin_comment
comment|/* SendHostMessage Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SEND_HOST_MESSAGE_REPLY
block|{
name|U16
name|HostDataLength
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved1
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
name|MPI2_SEND_HOST_MESSAGE_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SEND_HOST_MESSAGE_REPLY
operator|,
name|Mpi2SendHostMessageReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SendHostMessageReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  FWDownload message ****************************************************************************/
end_comment

begin_comment
comment|/* MPI v2.0 FWDownload Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_DOWNLOAD_REQUEST
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U32
name|TotalImageSize
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|MPI2_MPI_SGE_UNION
name|SGL
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_FW_DOWNLOAD_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_DOWNLOAD_REQUEST
operator|,
name|Mpi2FWDownloadRequest
operator|,
name|MPI2_POINTER
name|pMpi2FWDownloadRequest
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_MSGFLGS_LAST_SEGMENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_FW
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_MANUFACTURING
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_CONFIG_1
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_CONFIG_2
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_MEGARAID
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_COMPLETE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_COMMON_BOOT_BLOCK
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_PUBLIC_KEY
value|(0x0C)
end_define

begin_comment
comment|/* MPI v2.5 and newer */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_SBR
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_SBR_BACKUP
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_HIIM
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_HIIA
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_CTLR
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_IMR_FIRMWARE
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_MR_NVDATA
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_DOWNLOAD_ITYPE_MIN_PRODUCT_SPECIFIC
value|(0xF0)
end_define

begin_comment
comment|/* MPI v2.0 FWDownload TransactionContext Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_DOWNLOAD_TCSGE
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ContextSize
decl_stmt|;
comment|/* 0x01 */
name|U8
name|DetailsLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 0x08 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_FW_DOWNLOAD_TCSGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_DOWNLOAD_TCSGE
operator|,
name|Mpi2FWDownloadTCSGE_t
operator|,
name|MPI2_POINTER
name|pMpi2FWDownloadTCSGE_t
typedef|;
end_typedef

begin_comment
comment|/* MPI v2.5 FWDownload Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_FW_DOWNLOAD_REQUEST
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U32
name|TotalImageSize
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x14 */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 0x18 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x1C */
name|MPI25_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI25_FW_DOWNLOAD_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI25_FW_DOWNLOAD_REQUEST
operator|,
name|Mpi25FWDownloadRequest
operator|,
name|MPI2_POINTER
name|pMpi25FWDownloadRequest
typedef|;
end_typedef

begin_comment
comment|/* FWDownload Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_DOWNLOAD_REPLY
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|MPI2_FW_DOWNLOAD_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_DOWNLOAD_REPLY
operator|,
name|Mpi2FWDownloadReply_t
operator|,
name|MPI2_POINTER
name|pMpi2FWDownloadReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  FWUpload message ****************************************************************************/
end_comment

begin_comment
comment|/* MPI v2.0 FWUpload Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_UPLOAD_REQUEST
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x10 */
name|MPI2_MPI_SGE_UNION
name|SGL
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_FW_UPLOAD_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_UPLOAD_REQUEST
operator|,
name|Mpi2FWUploadRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2FWUploadRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_FW_CURRENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_FW_FLASH
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_BIOS_FLASH
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_FW_BACKUP
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_MANUFACTURING
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_CONFIG_1
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_CONFIG_2
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_MEGARAID
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_COMPLETE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_COMMON_BOOT_BLOCK
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_CBB_BACKUP
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_SBR
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_SBR_BACKUP
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_HIIM
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_HIIA
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_CTLR
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_IMR_FIRMWARE
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_UPLOAD_ITYPE_MR_NVDATA
value|(0x14)
end_define

begin_comment
comment|/* MPI v2.0 FWUpload TransactionContext Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_UPLOAD_TCSGE
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ContextSize
decl_stmt|;
comment|/* 0x01 */
name|U8
name|DetailsLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 0x08 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_FW_UPLOAD_TCSGE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_UPLOAD_TCSGE
operator|,
name|Mpi2FWUploadTCSGE_t
operator|,
name|MPI2_POINTER
name|pMpi2FWUploadTCSGE_t
typedef|;
end_typedef

begin_comment
comment|/* MPI v2.5 FWUpload Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_FW_UPLOAD_REQUEST
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x14 */
name|U32
name|ImageOffset
decl_stmt|;
comment|/* 0x18 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x1C */
name|MPI25_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI25_FW_UPLOAD_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI25_FW_UPLOAD_REQUEST
operator|,
name|Mpi25FWUploadRequest_t
operator|,
name|MPI2_POINTER
name|pMpi25FWUploadRequest_t
typedef|;
end_typedef

begin_comment
comment|/* FWUpload Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_UPLOAD_REPLY
block|{
name|U8
name|ImageType
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|U32
name|ActualImageSize
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_FW_UPLOAD_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_UPLOAD_REPLY
operator|,
name|Mpi2FWUploadReply_t
operator|,
name|MPI2_POINTER
name|pMPi2FWUploadReply_t
typedef|;
end_typedef

begin_comment
comment|/* FW Image Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FW_IMAGE_HEADER
block|{
name|U32
name|Signature
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Signature0
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Signature1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Signature2
decl_stmt|;
comment|/* 0x0C */
name|MPI2_VERSION_UNION
name|MPIVersion
decl_stmt|;
comment|/* 0x10 */
name|MPI2_VERSION_UNION
name|FWVersion
decl_stmt|;
comment|/* 0x14 */
name|MPI2_VERSION_UNION
name|NVDATAVersion
decl_stmt|;
comment|/* 0x18 */
name|MPI2_VERSION_UNION
name|PackageVersion
decl_stmt|;
comment|/* 0x1C */
name|U16
name|VendorID
decl_stmt|;
comment|/* 0x20 */
name|U16
name|ProductID
decl_stmt|;
comment|/* 0x22 */
name|U16
name|ProtocolFlags
decl_stmt|;
comment|/* 0x24 */
name|U16
name|Reserved26
decl_stmt|;
comment|/* 0x26 */
name|U32
name|IOCCapabilities
decl_stmt|;
comment|/* 0x28 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x2C */
name|U32
name|NextImageHeaderOffset
decl_stmt|;
comment|/* 0x30 */
name|U32
name|Checksum
decl_stmt|;
comment|/* 0x34 */
name|U32
name|Reserved38
decl_stmt|;
comment|/* 0x38 */
name|U32
name|Reserved3C
decl_stmt|;
comment|/* 0x3C */
name|U32
name|Reserved40
decl_stmt|;
comment|/* 0x40 */
name|U32
name|Reserved44
decl_stmt|;
comment|/* 0x44 */
name|U32
name|Reserved48
decl_stmt|;
comment|/* 0x48 */
name|U32
name|Reserved4C
decl_stmt|;
comment|/* 0x4C */
name|U32
name|Reserved50
decl_stmt|;
comment|/* 0x50 */
name|U32
name|Reserved54
decl_stmt|;
comment|/* 0x54 */
name|U32
name|Reserved58
decl_stmt|;
comment|/* 0x58 */
name|U32
name|Reserved5C
decl_stmt|;
comment|/* 0x5C */
name|U32
name|BootFlags
decl_stmt|;
comment|/* 0x60 */
comment|/* reserved in  MPI v2.5 and earlier */
name|U32
name|FirmwareVersionNameWhat
decl_stmt|;
comment|/* 0x64 */
name|U8
name|FirmwareVersionName
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x68 */
name|U32
name|VendorNameWhat
decl_stmt|;
comment|/* 0x88 */
name|U8
name|VendorName
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x8C */
name|U32
name|PackageNameWhat
decl_stmt|;
comment|/* 0x88 */
name|U8
name|PackageName
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x8C */
name|U32
name|ReservedD0
decl_stmt|;
comment|/* 0xD0 */
name|U32
name|ReservedD4
decl_stmt|;
comment|/* 0xD4 */
name|U32
name|ReservedD8
decl_stmt|;
comment|/* 0xD8 */
name|U32
name|ReservedDC
decl_stmt|;
comment|/* 0xDC */
name|U32
name|ReservedE0
decl_stmt|;
comment|/* 0xE0 */
name|U32
name|ReservedE4
decl_stmt|;
comment|/* 0xE4 */
name|U32
name|ReservedE8
decl_stmt|;
comment|/* 0xE8 */
name|U32
name|ReservedEC
decl_stmt|;
comment|/* 0xEC */
name|U32
name|ReservedF0
decl_stmt|;
comment|/* 0xF0 */
name|U32
name|ReservedF4
decl_stmt|;
comment|/* 0xF4 */
name|U32
name|ReservedF8
decl_stmt|;
comment|/* 0xF8 */
name|U32
name|ReservedFC
decl_stmt|;
comment|/* 0xFC */
block|}
name|MPI2_FW_IMAGE_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FW_IMAGE_HEADER
operator|,
name|Mpi2FWImageHeader_t
operator|,
name|MPI2_POINTER
name|pMpi2FWImageHeader_t
typedef|;
end_typedef

begin_comment
comment|/* Signature field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE_OFFSET
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE
value|(0xEA000000)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE
value|(0xEB000000)
end_define

begin_comment
comment|/* Signature0 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE0_OFFSET
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE0
value|(0x5AFAA55A)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_BASE
value|(0x5AEAA500)
end_define

begin_comment
comment|/* Last byte is defined by architecture */
end_comment

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_ARC_0
value|(0x5A)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_ARC_1
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_ARC_2
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_ARC_3
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0
value|(MPI26_FW_HEADER_SIGNATURE0_BASE+MPI26_FW_HEADER_SIGNATURE0_ARC_0)
end_define

begin_comment
comment|// legacy (0x5AEAA55A)
end_comment

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_3516
value|(MPI26_FW_HEADER_SIGNATURE0_BASE+MPI26_FW_HEADER_SIGNATURE0_ARC_1)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE0_4008
value|(MPI26_FW_HEADER_SIGNATURE0_BASE+MPI26_FW_HEADER_SIGNATURE0_ARC_3)
end_define

begin_comment
comment|/* Signature1 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE1_OFFSET
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE1
value|(0xA55AFAA5)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE1
value|(0xA55AEAA5)
end_define

begin_comment
comment|/* Signature2 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE2_OFFSET
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIGNATURE2
value|(0x5AA55AFA)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_SIGNATURE2
value|(0x5AA55AEA)
end_define

begin_comment
comment|/* defines for using the ProductID field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_TYPE_MASK
value|(0xF000)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_TYPE_SAS
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_PROD_MASK
value|(0x0F00)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_PROD_A
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_PROD_TARGET_INITIATOR_SCSI
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_PROD_IR_SCSI
value|(0x0700)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_FAMILY_MASK
value|(0x00FF)
end_define

begin_comment
comment|/* SAS ProductID Family bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_FAMILY_2108_SAS
value|(0x0013)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_PID_FAMILY_2208_SAS
value|(0x0014)
end_define

begin_define
define|#
directive|define
name|MPI25_FW_HEADER_PID_FAMILY_3108_SAS
value|(0x0021)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_PID_FAMILY_3324_SAS
value|(0x0028)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_PID_FAMILY_3516_SAS
value|(0x0031)
end_define

begin_comment
comment|/* use MPI2_IOCFACTS_PROTOCOL_ defines for ProtocolFlags field */
end_comment

begin_comment
comment|/* use MPI2_IOCFACTS_CAPABILITY_ defines for IOCCapabilities field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_IMAGESIZE_OFFSET
value|(0x2C)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_NEXTIMAGE_OFFSET
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI26_FW_HEADER_BOOTFLAGS_OFFSET
value|(0x60)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_VERNMHWAT_OFFSET
value|(0x64)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_WHAT_SIGNATURE
value|(0x29232840)
end_define

begin_define
define|#
directive|define
name|MPI2_FW_HEADER_SIZE
value|(0x100)
end_define

begin_comment
comment|/* Extended Image Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_EXT_IMAGE_HEADER
block|{
name|U8
name|ImageType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Checksum
decl_stmt|;
comment|/* 0x04 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x08 */
name|U32
name|NextImageHeaderOffset
decl_stmt|;
comment|/* 0x0C */
name|U32
name|PackageVersion
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x1C */
name|U8
name|IdentifyString
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI2_EXT_IMAGE_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_EXT_IMAGE_HEADER
operator|,
name|Mpi2ExtImageHeader_t
operator|,
name|MPI2_POINTER
name|pMpi2ExtImageHeader_t
typedef|;
end_typedef

begin_comment
comment|/* useful offsets */
end_comment

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_IMAGETYPE_OFFSET
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_IMAGESIZE_OFFSET
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_NEXTIMAGE_OFFSET
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_HEADER_SIZE
value|(0x40)
end_define

begin_comment
comment|/* defines for the ImageType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_UNSPECIFIED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_FW
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_NVDATA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_BOOTLOADER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_INITIALIZATION
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_FLASH_LAYOUT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_SUPPORTED_DEVICES
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_MEGARAID
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_ENCRYPTED_HASH
value|(0x09)
end_define

begin_comment
comment|/* MPI v2.5 and newer */
end_comment

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_MIN_PRODUCT_SPECIFIC
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_MAX_PRODUCT_SPECIFIC
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPI2_EXT_IMAGE_TYPE_MAX
value|(MPI2_EXT_IMAGE_TYPE_MAX_PRODUCT_SPECIFIC)
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_comment
comment|/* FLASH Layout Extended Image Data */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check RegionsPerLayout at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_FLASH_NUMBER_OF_REGIONS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_FLASH_NUMBER_OF_REGIONS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumberOfLayouts at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_FLASH_NUMBER_OF_LAYOUTS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_FLASH_NUMBER_OF_LAYOUTS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FLASH_REGION
block|{
name|U8
name|RegionType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|RegionOffset
decl_stmt|;
comment|/* 0x04 */
name|U32
name|RegionSize
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_FLASH_REGION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FLASH_REGION
operator|,
name|Mpi2FlashRegion_t
operator|,
name|MPI2_POINTER
name|pMpi2FlashRegion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FLASH_LAYOUT
block|{
name|U32
name|FlashSize
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|MPI2_FLASH_REGION
name|Region
index|[
name|MPI2_FLASH_NUMBER_OF_REGIONS
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_FLASH_LAYOUT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FLASH_LAYOUT
operator|,
name|Mpi2FlashLayout_t
operator|,
name|MPI2_POINTER
name|pMpi2FlashLayout_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_FLASH_LAYOUT_DATA
block|{
name|U8
name|ImageRevision
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|SizeOfRegion
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x03 */
name|U16
name|NumberOfLayouts
decl_stmt|;
comment|/* 0x04 */
name|U16
name|RegionsPerLayout
decl_stmt|;
comment|/* 0x06 */
name|U16
name|MinimumSectorAlignment
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|MPI2_FLASH_LAYOUT
name|Layout
index|[
name|MPI2_FLASH_NUMBER_OF_LAYOUTS
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_FLASH_LAYOUT_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_FLASH_LAYOUT_DATA
operator|,
name|Mpi2FlashLayoutData_t
operator|,
name|MPI2_POINTER
name|pMpi2FlashLayoutData_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the RegionType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_UNUSED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_FIRMWARE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_NVDATA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_FIRMWARE_BACKUP
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_MFG_INFORMATION
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_CONFIG_1
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_CONFIG_2
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_MEGARAID
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_COMMON_BOOT_BLOCK
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_INIT
value|(MPI2_FLASH_REGION_COMMON_BOOT_BLOCK)
end_define

begin_comment
comment|/* older name */
end_comment

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_CBB_BACKUP
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_SBR
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_SBR_BACKUP
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_HIIM
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_HIIA
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_CTLR
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_IMR_FIRMWARE
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_FLASH_REGION_MR_NVDATA
value|(0x14)
end_define

begin_comment
comment|/* ImageRevision */
end_comment

begin_define
define|#
directive|define
name|MPI2_FLASH_LAYOUT_IMAGE_REVISION
value|(0x00)
end_define

begin_comment
comment|/* Supported Devices Extended Image Data */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumberOfDevices at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SUPPORTED_DEVICES_IMAGE_NUM_DEVICES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SUPPORTED_DEVICES_IMAGE_NUM_DEVICES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SUPPORTED_DEVICE
block|{
name|U16
name|DeviceID
decl_stmt|;
comment|/* 0x00 */
name|U16
name|VendorID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|DeviceIDMask
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
name|U8
name|LowPCIRev
decl_stmt|;
comment|/* 0x08 */
name|U8
name|HighPCIRev
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_SUPPORTED_DEVICE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SUPPORTED_DEVICE
operator|,
name|Mpi2SupportedDevice_t
operator|,
name|MPI2_POINTER
name|pMpi2SupportedDevice_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SUPPORTED_DEVICES_DATA
block|{
name|U8
name|ImageRevision
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|NumberOfDevices
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x04 */
name|MPI2_SUPPORTED_DEVICE
name|SupportedDevice
index|[
name|MPI2_SUPPORTED_DEVICES_IMAGE_NUM_DEVICES
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_SUPPORTED_DEVICES_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SUPPORTED_DEVICES_DATA
operator|,
name|Mpi2SupportedDevicesData_t
operator|,
name|MPI2_POINTER
name|pMpi2SupportedDevicesData_t
typedef|;
end_typedef

begin_comment
comment|/* ImageRevision */
end_comment

begin_define
define|#
directive|define
name|MPI2_SUPPORTED_DEVICES_IMAGE_REVISION
value|(0x00)
end_define

begin_comment
comment|/* Init Extended Image Data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_INIT_IMAGE_FOOTER
block|{
name|U32
name|BootFlags
decl_stmt|;
comment|/* 0x00 */
name|U32
name|ImageSize
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Signature0
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Signature1
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Signature2
decl_stmt|;
comment|/* 0x10 */
name|U32
name|ResetVector
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_INIT_IMAGE_FOOTER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_INIT_IMAGE_FOOTER
operator|,
name|Mpi2InitImageFooter_t
operator|,
name|MPI2_POINTER
name|pMpi2InitImageFooter_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the BootFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_BOOTFLAGS_OFFSET
value|(0x00)
end_define

begin_comment
comment|/* defines for the ImageSize field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_IMAGESIZE_OFFSET
value|(0x04)
end_define

begin_comment
comment|/* defines for the Signature0 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE0_OFFSET
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE0
value|(0x5AA55AEA)
end_define

begin_comment
comment|/* defines for the Signature1 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE1_OFFSET
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE1
value|(0xA55AEAA5)
end_define

begin_comment
comment|/* defines for the Signature2 field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE2_OFFSET
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE2
value|(0x5AEAA55A)
end_define

begin_comment
comment|/* Signature fields as individual bytes */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_0
value|(0xEA)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_1
value|(0x5A)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_2
value|(0xA5)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_3
value|(0x5A)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_4
value|(0xA5)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_5
value|(0xEA)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_6
value|(0x5A)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_7
value|(0xA5)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_8
value|(0x5A)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_9
value|(0xA5)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_A
value|(0xEA)
end_define

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_SIGNATURE_BYTE_B
value|(0x5A)
end_define

begin_comment
comment|/* defines for the ResetVector field */
end_comment

begin_define
define|#
directive|define
name|MPI2_INIT_IMAGE_RESETVECTOR_OFFSET
value|(0x14)
end_define

begin_comment
comment|/* Encrypted Hash Extended Image Data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_ENCRYPTED_HASH_ENTRY
block|{
name|U8
name|HashImageType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|HashAlgorithm
decl_stmt|;
comment|/* 0x01 */
name|U8
name|EncryptionAlgorithm
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U32
name|EncryptedHash
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x08 */
comment|/* variable length */
block|}
name|MPI25_ENCRYPTED_HASH_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI25_ENCRYPTED_HASH_ENTRY
operator|,
name|Mpi25EncryptedHashEntry_t
operator|,
name|MPI2_POINTER
name|pMpi25EncryptedHashEntry_t
typedef|;
end_typedef

begin_comment
comment|/* values for HashImageType */
end_comment

begin_define
define|#
directive|define
name|MPI25_HASH_IMAGE_TYPE_UNUSED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_HASH_IMAGE_TYPE_FIRMWARE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI25_HASH_IMAGE_TYPE_BIOS
value|(0x02)
end_define

begin_comment
comment|/* values for HashAlgorithm */
end_comment

begin_define
define|#
directive|define
name|MPI25_HASH_ALGORITHM_UNUSED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_HASH_ALGORITHM_SHA256
value|(0x01)
end_define

begin_comment
comment|/* values for EncryptionAlgorithm */
end_comment

begin_define
define|#
directive|define
name|MPI25_ENCRYPTION_ALG_UNUSED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_ENCRYPTION_ALG_RSA256
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_ENCRYPTED_HASH_DATA
block|{
name|U8
name|ImageVersion
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumHash
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|MPI25_ENCRYPTED_HASH_ENTRY
name|EncryptedHashEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x08 */
comment|/* variable number of entries */
block|}
name|MPI25_ENCRYPTED_HASH_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI25_ENCRYPTED_HASH_DATA
operator|,
name|Mpi25EncryptedHashData_t
operator|,
name|MPI2_POINTER
name|pMpi25EncryptedHashData_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  PowerManagementControl message ****************************************************************************/
end_comment

begin_comment
comment|/* PowerManagementControl Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PWR_MGMT_CONTROL_REQUEST
block|{
name|U8
name|Feature
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Parameter1
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Parameter2
decl_stmt|;
comment|/* 0x0D */
name|U8
name|Parameter3
decl_stmt|;
comment|/* 0x0E */
name|U8
name|Parameter4
decl_stmt|;
comment|/* 0x0F */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_PWR_MGMT_CONTROL_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PWR_MGMT_CONTROL_REQUEST
operator|,
name|Mpi2PwrMgmtControlRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2PwrMgmtControlRequest_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Feature field */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_DA_PHY_POWER_COND
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_PORT_WIDTH_MODULATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_PCIE_LINK
value|(0x03)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_IOC_SPEED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_GLOBAL_PWR_MGMT_MODE
value|(0x05)
end_define

begin_comment
comment|/* reserved in MPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_MIN_PRODUCT_SPECIFIC
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_FEATURE_MAX_PRODUCT_SPECIFIC
value|(0xFF)
end_define

begin_comment
comment|/* parameter usage for the MPI2_PM_CONTROL_FEATURE_DA_PHY_POWER_COND Feature */
end_comment

begin_comment
comment|/* Parameter1 contains a PHY number */
end_comment

begin_comment
comment|/* Parameter2 indicates power condition action using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_PARTIAL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_SLUMBER
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_EXIT_PWR_MGMT
value|(0x03)
end_define

begin_comment
comment|/* Parameter3 and Parameter4 are reserved */
end_comment

begin_comment
comment|/* parameter usage for the MPI2_PM_CONTROL_FEATURE_PORT_WIDTH_MODULATION Feature */
end_comment

begin_comment
comment|/* Parameter1 contains SAS port width modulation group number */
end_comment

begin_comment
comment|/* Parameter2 indicates IOC action using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_REQUEST_OWNERSHIP
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_CHANGE_MODULATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_RELINQUISH_OWNERSHIP
value|(0x03)
end_define

begin_comment
comment|/* Parameter3 indicates desired modulation level using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM3_25_PERCENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM3_50_PERCENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM3_75_PERCENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM3_100_PERCENT
value|(0x03)
end_define

begin_comment
comment|/* Parameter4 is reserved */
end_comment

begin_comment
comment|/* this next set (_PCIE_LINK) is obsolete */
end_comment

begin_comment
comment|/* parameter usage for the MPI2_PM_CONTROL_FEATURE_PCIE_LINK Feature */
end_comment

begin_comment
comment|/* Parameter1 indicates desired PCIe link speed using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_PCIE_2_5_GBPS
value|(0x00)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_PCIE_5_0_GBPS
value|(0x01)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_PCIE_8_0_GBPS
value|(0x02)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* Parameter2 indicates desired PCIe link width using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_WIDTH_X1
value|(0x01)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_WIDTH_X2
value|(0x02)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_WIDTH_X4
value|(0x04)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_WIDTH_X8
value|(0x08)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* Parameter3 and Parameter4 are reserved */
end_comment

begin_comment
comment|/* parameter usage for the MPI2_PM_CONTROL_FEATURE_IOC_SPEED Feature */
end_comment

begin_comment
comment|/* Parameter1 indicates desired IOC hardware clock speed using these defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_FULL_IOC_SPEED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_HALF_IOC_SPEED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_QUARTER_IOC_SPEED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_EIGHTH_IOC_SPEED
value|(0x08)
end_define

begin_comment
comment|/* Parameter2, Parameter3, and Parameter4 are reserved */
end_comment

begin_comment
comment|/* parameter usage for the MPI2_PM_CONTROL_FEATURE_GLOBAL_PWR_MGMT_MODE Feature */
end_comment

begin_comment
comment|/* Parameter1 indicates host action regarding global power management mode */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_TAKE_CONTROL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_CHANGE_GLOBAL_MODE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM1_RELEASE_CONTROL
value|(0x03)
end_define

begin_comment
comment|/* Parameter2 indicates the requested global power management mode */
end_comment

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_FULL_PWR_PERF
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_REDUCED_PWR_PERF
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_PM_CONTROL_PARAM2_STANDBY
value|(0x40)
end_define

begin_comment
comment|/* Parameter3 and Parameter4 are reserved */
end_comment

begin_comment
comment|/* PowerManagementControl Reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_PWR_MGMT_CONTROL_REPLY
block|{
name|U8
name|Feature
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
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved5
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
name|MPI2_PWR_MGMT_CONTROL_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_PWR_MGMT_CONTROL_REPLY
operator|,
name|Mpi2PwrMgmtControlReply_t
operator|,
name|MPI2_POINTER
name|pMpi2PwrMgmtControlReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IO Unit Control messages (MPI v2.6 and later only.) ****************************************************************************/
end_comment

begin_comment
comment|/* IO Unit Control Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_IOUNIT_CONTROL_REQUEST
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
name|IOCParameter
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
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x0E */
name|U8
name|PrimFlags
decl_stmt|;
comment|/* 0x0F */
name|U32
name|Primitive
decl_stmt|;
comment|/* 0x10 */
name|U8
name|LookupMethod
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x15 */
name|U16
name|SlotNumber
decl_stmt|;
comment|/* 0x16 */
name|U64
name|LookupAddress
decl_stmt|;
comment|/* 0x18 */
name|U32
name|IOCParameterValue
decl_stmt|;
comment|/* 0x20 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x24 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x28 */
block|}
name|MPI26_IOUNIT_CONTROL_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI26_IOUNIT_CONTROL_REQUEST
operator|,
name|Mpi26IoUnitControlRequest_t
operator|,
name|MPI2_POINTER
name|pMpi26IoUnitControlRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Operation field */
end_comment

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_CLEAR_ALL_PERSISTENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_SAS_PHY_LINK_RESET
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_SAS_PHY_HARD_RESET
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_PHY_CLEAR_ERROR_LOG
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_LINK_CLEAR_ERROR_LOG
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_SAS_SEND_PRIMITIVE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_FORCE_FULL_DISCOVERY
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_REMOVE_DEVICE
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_LOOKUP_MAPPING
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_SET_IOC_PARAMETER
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_ENABLE_FP_DEVICE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DISABLE_FP_DEVICE
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_ENABLE_FP_ALL
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DISABLE_FP_ALL
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DEV_ENABLE_NCQ
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DEV_DISABLE_NCQ
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_SHUTDOWN
value|(0x16)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DEV_ENABLE_PERSIST_CONNECTION
value|(0x17)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DEV_DISABLE_PERSIST_CONNECTION
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DEV_CLOSE_PERSIST_CONNECTION
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_ENABLE_NVME_SGL_FORMAT
value|(0x1A)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_DISABLE_NVME_SGL_FORMAT
value|(0x1B)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_OP_PRODUCT_SPECIFIC_MIN
value|(0x80)
end_define

begin_comment
comment|/* values for the PrimFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_CTRL_PRIMFLAGS_SINGLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_PRIMFLAGS_TRIPLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_PRIMFLAGS_REDUNDANT
value|(0x01)
end_define

begin_comment
comment|/* values for the LookupMethod field */
end_comment

begin_define
define|#
directive|define
name|MPI26_CTRL_LOOKUP_METHOD_WWID_ADDRESS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_LOOKUP_METHOD_ENCLOSURE_SLOT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_CTRL_LOOKUP_METHOD_SAS_DEVICE_NAME
value|(0x03)
end_define

begin_comment
comment|/* IO Unit Control Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_IOUNIT_CONTROL_REPLY
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
name|IOCParameter
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
name|MPI26_IOUNIT_CONTROL_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI26_IOUNIT_CONTROL_REPLY
operator|,
name|Mpi26IoUnitControlReply_t
operator|,
name|MPI2_POINTER
name|pMpi26IoUnitControlReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

