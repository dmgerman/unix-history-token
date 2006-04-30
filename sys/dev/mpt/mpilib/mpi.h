begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  MPI.H  *          Title:  MPI Message independent structures and definitions  *  Creation Date:  July 27, 2000  *  *    MPI.H Version:  01.02.11  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  05-24-00  00.10.02  Added MPI_IOCSTATUS_SCSI_RESIDUAL_MISMATCH definition.  *  06-06-00  01.00.01  Update MPI_VERSION_MAJOR and MPI_VERSION_MINOR.  *  06-22-00  01.00.02  Added MPI_IOCSTATUS_LAN_ definitions.  *                      Removed LAN_SUSPEND function definition.  *                      Added MPI_MSGFLAGS_CONTINUATION_REPLY definition.  *  06-30-00  01.00.03  Added MPI_CONTEXT_REPLY_TYPE_LAN definition.  *                      Added MPI_GET/SET_CONTEXT_REPLY_TYPE macros.  *  07-27-00  01.00.04  Added MPI_FAULT_ definitions.  *                      Removed MPI_IOCSTATUS_MSG/DATA_XFER_ERROR definitions.  *                      Added MPI_IOCSTATUS_INTERNAL_ERROR definition.  *                      Added MPI_IOCSTATUS_TARGET_XFER_COUNT_MISMATCH.  *  11-02-00  01.01.01  Original release for post 1.0 work.  *  12-04-00  01.01.02  Added new function codes.  *  01-09-01  01.01.03  Added more definitions to the system interface section  *                      Added MPI_IOCSTATUS_TARGET_STS_DATA_NOT_SENT.  *  01-25-01  01.01.04  Changed MPI_VERSION_MINOR from 0x00 to 0x01.  *  02-20-01  01.01.05  Started using MPI_POINTER.  *                      Fixed value for MPI_DIAG_RW_ENABLE.  *                      Added defines for MPI_DIAG_PREVENT_IOC_BOOT and  *                      MPI_DIAG_CLEAR_FLASH_BAD_SIG.  *                      Obsoleted MPI_IOCSTATUS_TARGET_FC_ defines.  *  02-27-01  01.01.06  Removed MPI_HOST_INDEX_REGISTER define.  *                      Added function codes for RAID.  *  04-09-01  01.01.07  Added alternate define for MPI_DOORBELL_ACTIVE,  *                      MPI_DOORBELL_USED, to better match the spec.  *  08-08-01  01.02.01  Original release for v1.2 work.  *                      Changed MPI_VERSION_MINOR from 0x01 to 0x02.  *                      Added define MPI_FUNCTION_TOOLBOX.  *  09-28-01  01.02.02  New function code MPI_SCSI_ENCLOSURE_PROCESSOR.  *  11-01-01  01.02.03  Changed name to MPI_FUNCTION_SCSI_ENCLOSURE_PROCESSOR.  *  03-14-02  01.02.04  Added MPI_HEADER_VERSION_ defines.  *  05-31-02  01.02.05  Bumped MPI_HEADER_VERSION_UNIT.  *  07-12-02  01.02.06  Added define for MPI_FUNCTION_MAILBOX.  *  09-16-02  01.02.07  Bumped value for MPI_HEADER_VERSION_UNIT.  *  11-15-02  01.02.08  Added define MPI_IOCSTATUS_TARGET_INVALID_IO_INDEX and  *                      obsoleted define MPI_IOCSTATUS_TARGET_INVALID_IOCINDEX.  *  04-01-03  01.02.09  New IOCStatus code: MPI_IOCSTATUS_FC_EXCHANGE_CANCELED  *  06-26-03  01.02.10  Bumped MPI_HEADER_VERSION_UNIT value.  *  01-16-04  01.02.11  Added define for MPI_IOCLOGINFO_TYPE_SHIFT.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_H
end_define

begin_comment
comment|/***************************************************************************** * *        M P I    V e r s i o n    D e f i n i t i o n s * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_VERSION_MAJOR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_MINOR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_MINOR_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION
value|((MPI_VERSION_MAJOR<< MPI_VERSION_MAJOR_SHIFT) |   \                                       MPI_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_01_00
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_01_01
value|(0x0101)
end_define

begin_define
define|#
directive|define
name|MPI_VERSION_01_02
value|(0x0102)
end_define

begin_comment
comment|/* Note: The major versions of 0xe0 through 0xff are reserved */
end_comment

begin_comment
comment|/* versioning for this MPI header set */
end_comment

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_UNIT
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_DEV
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION_DEV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_HEADER_VERSION
value|((MPI_HEADER_VERSION_UNIT<< 8) | MPI_HEADER_VERSION_DEV)
end_define

begin_comment
comment|/***************************************************************************** * *        I O C    S t a t e    D e f i n i t i o n s * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOC_STATE_RESET
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOC_STATE_READY
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOC_STATE_OPERATIONAL
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOC_STATE_FAULT
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOC_STATE_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOC_STATE_SHIFT
value|(28)
end_define

begin_comment
comment|/* Fault state codes (product independent range 0x8000-0xFFFF) */
end_comment

begin_define
define|#
directive|define
name|MPI_FAULT_REQUEST_MESSAGE_PCI_PARITY_ERROR
value|(0x8111)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_REQUEST_MESSAGE_PCI_BUS_FAULT
value|(0x8112)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_REPLY_MESSAGE_PCI_PARITY_ERROR
value|(0x8113)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_REPLY_MESSAGE_PCI_BUS_FAULT
value|(0x8114)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_DATA_SEND_PCI_PARITY_ERROR
value|(0x8115)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_DATA_SEND_PCI_BUS_FAULT
value|(0x8116)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_DATA_RECEIVE_PCI_PARITY_ERROR
value|(0x8117)
end_define

begin_define
define|#
directive|define
name|MPI_FAULT_DATA_RECEIVE_PCI_BUS_FAULT
value|(0x8118)
end_define

begin_comment
comment|/***************************************************************************** * *        P C I    S y s t e m    I n t e r f a c e    R e g i s t e r s * *****************************************************************************/
end_comment

begin_comment
comment|/* S y s t e m    D o o r b e l l */
end_comment

begin_define
define|#
directive|define
name|MPI_DOORBELL_OFFSET
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_ACTIVE
value|(0x08000000)
end_define

begin_comment
comment|/* DoorbellUsed */
end_comment

begin_define
define|#
directive|define
name|MPI_DOORBELL_USED
value|(MPI_DOORBELL_ACTIVE)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_ACTIVE_SHIFT
value|(27)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_WHO_INIT_MASK
value|(0x07000000)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_WHO_INIT_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_FUNCTION_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_FUNCTION_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_ADD_DWORDS_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_ADD_DWORDS_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_DOORBELL_DATA_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_WRITE_SEQUENCE_OFFSET
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_KEY_VALUE_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_1ST_KEY_VALUE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_2ND_KEY_VALUE
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_3RD_KEY_VALUE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_4TH_KEY_VALUE
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_WRSEQ_5TH_KEY_VALUE
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_DIAGNOSTIC_OFFSET
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_CLEAR_FLASH_BAD_SIG
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_PREVENT_IOC_BOOT
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_DRWE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_FLASH_BAD_SIG
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_RESET_HISTORY
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_RW_ENABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_RESET_ADAPTER
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_DISABLE_ARM
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_MEM_ENABLE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_TEST_BASE_ADDRESS_OFFSET
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_RW_DATA_OFFSET
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_RW_ADDRESS_OFFSET
value|(0x00000014)
end_define

begin_define
define|#
directive|define
name|MPI_HOST_INTERRUPT_STATUS_OFFSET
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_HIS_IOP_DOORBELL_STATUS
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_HIS_REPLY_MESSAGE_INTERRUPT
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_HIS_DOORBELL_INTERRUPT
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_HOST_INTERRUPT_MASK_OFFSET
value|(0x00000034)
end_define

begin_define
define|#
directive|define
name|MPI_HIM_RIM
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_HIM_DIM
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_REQUEST_QUEUE_OFFSET
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_REQUEST_POST_FIFO_OFFSET
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_REPLY_QUEUE_OFFSET
value|(0x00000044)
end_define

begin_define
define|#
directive|define
name|MPI_REPLY_POST_FIFO_OFFSET
value|(0x00000044)
end_define

begin_define
define|#
directive|define
name|MPI_REPLY_FREE_FIFO_OFFSET
value|(0x00000044)
end_define

begin_comment
comment|/***************************************************************************** * *        M e s s a g e    F r a m e    D e s c r i p t o r s * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_REQ_MF_DESCRIPTOR_NB_MASK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_REQ_MF_DESCRIPTOR_F_BIT
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_REQ_MF_DESCRIPTOR_ADDRESS_MASK
value|(0xFFFFFFF8)
end_define

begin_define
define|#
directive|define
name|MPI_ADDRESS_REPLY_A_BIT
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_ADDRESS_REPLY_ADDRESS_MASK
value|(0x7FFFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_A_BIT
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_TYPE_MASK
value|(0x60000000)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_TYPE_SCSI_INIT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_TYPE_SCSI_TARGET
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_TYPE_LAN
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_TYPE_SHIFT
value|(29)
end_define

begin_define
define|#
directive|define
name|MPI_CONTEXT_REPLY_CONTEXT_MASK
value|(0x1FFFFFFF)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Context Reply macros                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_GET_CONTEXT_REPLY_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& MPI_CONTEXT_REPLY_TYPE_MASK) \>> MPI_CONTEXT_REPLY_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_SET_CONTEXT_REPLY_TYPE
parameter_list|(
name|x
parameter_list|,
name|typ
parameter_list|)
define|\
value|((x) = ((x)& ~MPI_CONTEXT_REPLY_TYPE_MASK) |                   \                             (((typ)<< MPI_CONTEXT_REPLY_TYPE_SHIFT)&      \                                         MPI_CONTEXT_REPLY_TYPE_MASK))
end_define

begin_comment
comment|/***************************************************************************** * *        M e s s a g e    F u n c t i o n s *              0x80 -> 0x8F reserved for private message use per product * * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_FUNCTION_SCSI_IO_REQUEST
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_SCSI_TASK_MGMT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_IOC_INIT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_IOC_FACTS
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_CONFIG
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_PORT_FACTS
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_PORT_ENABLE
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_EVENT_NOTIFICATION
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_EVENT_ACK
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FW_DOWNLOAD
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_CMD_BUFFER_POST
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_ASSIST
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_STATUS_SEND
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_MODE_ABORT
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_FC_BUF_POST_LINK_SRVC
value|(0x0E)
end_define

begin_comment
comment|/* obsolete name */
end_comment

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_FC_RSP_LINK_SRVC
value|(0x0F)
end_define

begin_comment
comment|/* obsolete name */
end_comment

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_FC_EX_SEND_LINK_SRVC
value|(0x10)
end_define

begin_comment
comment|/* obsolete name */
end_comment

begin_define
define|#
directive|define
name|MPI_FUNCTION_TARGET_FC_ABORT
value|(0x11)
end_define

begin_comment
comment|/* obsolete name */
end_comment

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_LINK_SRVC_BUF_POST
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_LINK_SRVC_RSP
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_EX_LINK_SRVC_SEND
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_ABORT
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FW_UPLOAD
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_COMMON_TRANSPORT_SEND
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_FC_PRIMITIVE_SEND
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_RAID_ACTION
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_RAID_SCSI_IO_PASSTHROUGH
value|(0x16)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_TOOLBOX
value|(0x17)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_SCSI_ENCLOSURE_PROCESSOR
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_MAILBOX
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_LAN_SEND
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_LAN_RECEIVE
value|(0x21)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_LAN_RESET
value|(0x22)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_IOC_MESSAGE_UNIT_RESET
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_IO_UNIT_RESET
value|(0x41)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_HANDSHAKE
value|(0x42)
end_define

begin_define
define|#
directive|define
name|MPI_FUNCTION_REPLY_FRAME_REMOVAL
value|(0x43)
end_define

begin_comment
comment|/***************************************************************************** * *        S c a t t e r    G a t h e r    E l e m e n t s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Simple element structures                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_SIMPLE32
block|{
name|U32
name|FlagsLength
decl_stmt|;
name|U32
name|Address
decl_stmt|;
block|}
name|SGE_SIMPLE32
operator|,
name|MPI_POINTER
name|PTR_SGE_SIMPLE32
operator|,
name|SGESimple32_t
operator|,
name|MPI_POINTER
name|pSGESimple32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_SIMPLE64
block|{
name|U32
name|FlagsLength
decl_stmt|;
name|U64
name|Address
decl_stmt|;
block|}
name|SGE_SIMPLE64
operator|,
name|MPI_POINTER
name|PTR_SGE_SIMPLE64
operator|,
name|SGESimple64_t
operator|,
name|MPI_POINTER
name|pSGESimple64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_SIMPLE_UNION
block|{
name|U32
name|FlagsLength
decl_stmt|;
union|union
block|{
name|U32
name|Address32
decl_stmt|;
name|U64
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|SGESimpleUnion_t
operator|,
name|MPI_POINTER
name|pSGESimpleUnion_t
operator|,
name|SGE_SIMPLE_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_SIMPLE_UNION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Chain element structures                                                */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_CHAIN32
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|Address
decl_stmt|;
block|}
name|SGE_CHAIN32
operator|,
name|MPI_POINTER
name|PTR_SGE_CHAIN32
operator|,
name|SGEChain32_t
operator|,
name|MPI_POINTER
name|pSGEChain32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_CHAIN64
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U64
name|Address
decl_stmt|;
block|}
name|SGE_CHAIN64
operator|,
name|MPI_POINTER
name|PTR_SGE_CHAIN64
operator|,
name|SGEChain64_t
operator|,
name|MPI_POINTER
name|pSGEChain64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_CHAIN_UNION
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
union|union
block|{
name|U32
name|Address32
decl_stmt|;
name|U64
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|SGE_CHAIN_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_CHAIN_UNION
operator|,
name|SGEChainUnion_t
operator|,
name|MPI_POINTER
name|pSGEChainUnion_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Transaction Context element                                             */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANSACTION32
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SGE_TRANSACTION32
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANSACTION32
operator|,
name|SGETransaction32_t
operator|,
name|MPI_POINTER
name|pSGETransaction32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANSACTION64
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|2
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SGE_TRANSACTION64
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANSACTION64
operator|,
name|SGETransaction64_t
operator|,
name|MPI_POINTER
name|pSGETransaction64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANSACTION96
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|3
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SGE_TRANSACTION96
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANSACTION96
operator|,
name|SGETransaction96_t
operator|,
name|MPI_POINTER
name|pSGETransaction96_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANSACTION128
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|4
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SGE_TRANSACTION128
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANSACTION128
operator|,
name|SGETransaction_t128
operator|,
name|MPI_POINTER
name|pSGETransaction_t128
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANSACTION_UNION
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
union|union
block|{
name|U32
name|TransactionContext32
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|TransactionContext64
index|[
literal|2
index|]
decl_stmt|;
name|U32
name|TransactionContext96
index|[
literal|3
index|]
decl_stmt|;
name|U32
name|TransactionContext128
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SGE_TRANSACTION_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANSACTION_UNION
operator|,
name|SGETransactionUnion_t
operator|,
name|MPI_POINTER
name|pSGETransactionUnion_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SGE IO types union  for IO SGL's                                        */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_IO_UNION
block|{
union|union
block|{
name|SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|SGE_CHAIN_UNION
name|Chain
decl_stmt|;
block|}
name|u
union|;
block|}
name|SGE_IO_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_IO_UNION
operator|,
name|SGEIOUnion_t
operator|,
name|MPI_POINTER
name|pSGEIOUnion_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SGE union for SGL's with Simple and Transaction elements                */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_TRANS_SIMPLE_UNION
block|{
union|union
block|{
name|SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|SGE_TRANSACTION_UNION
name|Transaction
decl_stmt|;
block|}
name|u
union|;
block|}
name|SGE_TRANS_SIMPLE_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_TRANS_SIMPLE_UNION
operator|,
name|SGETransSimpleUnion_t
operator|,
name|MPI_POINTER
name|pSGETransSimpleUnion_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  All SGE types union                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGE_MPI_UNION
block|{
union|union
block|{
name|SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|SGE_CHAIN_UNION
name|Chain
decl_stmt|;
name|SGE_TRANSACTION_UNION
name|Transaction
decl_stmt|;
block|}
name|u
union|;
block|}
name|SGE_MPI_UNION
operator|,
name|MPI_POINTER
name|PTR_SGE_MPI_UNION
operator|,
name|MPI_SGE_UNION_t
operator|,
name|MPI_POINTER
name|pMPI_SGE_UNION_t
operator|,
name|SGEAllUnion_t
operator|,
name|MPI_POINTER
name|pSGEAllUnion_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SGE field definition and masks                                          */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Flags field bit definitions */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_LAST_ELEMENT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_END_OF_BUFFER
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_ELEMENT_TYPE_MASK
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_LOCAL_ADDRESS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_DIRECTION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_ADDRESS_SIZE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_END_OF_LIST
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_LENGTH_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_CHAIN_LENGTH_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* Element Type */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_TRANSACTION_ELEMENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_SIMPLE_ELEMENT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_CHAIN_ELEMENT
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_ELEMENT_MASK
value|(0x30)
end_define

begin_comment
comment|/* Address location */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_SYSTEM_ADDRESS
value|(0x00)
end_define

begin_comment
comment|/* Direction */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_IOC_TO_HOST
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_HOST_TO_IOC
value|(0x04)
end_define

begin_comment
comment|/* Address Size */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_32_BIT_ADDRESSING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_64_BIT_ADDRESSING
value|(0x02)
end_define

begin_comment
comment|/* Context Size */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_32_BIT_CONTEXT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_64_BIT_CONTEXT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_96_BIT_CONTEXT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_FLAGS_128_BIT_CONTEXT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_CHAIN_OFFSET_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_CHAIN_OFFSET_SHIFT
value|(16)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SGE operation Macros                                                    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SIMPLE FlagsLength manipulations... */
end_comment

begin_define
define|#
directive|define
name|MPI_SGE_SET_FLAGS
parameter_list|(
name|f
parameter_list|)
value|((U32)(f)<< MPI_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_GET_FLAGS
parameter_list|(
name|fl
parameter_list|)
value|(((fl)& ~MPI_SGE_LENGTH_MASK)>> MPI_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_LENGTH
parameter_list|(
name|fl
parameter_list|)
value|((fl)& MPI_SGE_LENGTH_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_CHAIN_LENGTH
parameter_list|(
name|fl
parameter_list|)
value|((fl)& MPI_SGE_CHAIN_LENGTH_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_SGE_SET_FLAGS_LENGTH
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|(MPI_SGE_SET_FLAGS(f) | MPI_SGE_LENGTH(l))
end_define

begin_define
define|#
directive|define
name|MPI_pSGE_GET_FLAGS
parameter_list|(
name|psg
parameter_list|)
value|MPI_SGE_GET_FLAGS((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI_pSGE_GET_LENGTH
parameter_list|(
name|psg
parameter_list|)
value|MPI_SGE_LENGTH((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI_pSGE_SET_FLAGS_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength = MPI_SGE_SET_FLAGS_LENGTH(f,l)
end_define

begin_comment
comment|/* CAUTION - The following are READ-MODIFY-WRITE! */
end_comment

begin_define
define|#
directive|define
name|MPI_pSGE_SET_FLAGS
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|)
value|(psg)->FlagsLength |= MPI_SGE_SET_FLAGS(f)
end_define

begin_define
define|#
directive|define
name|MPI_pSGE_SET_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength |= MPI_SGE_LENGTH(l)
end_define

begin_define
define|#
directive|define
name|MPI_GET_CHAIN_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x&MPI_SGE_CHAIN_OFFSET_MASK)>>MPI_SGE_CHAIN_OFFSET_SHIFT)
end_define

begin_comment
comment|/***************************************************************************** * *        S t a n d a r d    M e s s a g e    S t r u c t u r e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Standard message request header for all request messages                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_REQUEST_HEADER
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* function specific */
name|U8
name|ChainOffset
decl_stmt|;
name|U8
name|Function
decl_stmt|;
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* function specific */
name|U8
name|MsgFlags
decl_stmt|;
name|U32
name|MsgContext
decl_stmt|;
block|}
name|MSG_REQUEST_HEADER
operator|,
name|MPI_POINTER
name|PTR_MSG_REQUEST_HEADER
operator|,
name|MPIHeader_t
operator|,
name|MPI_POINTER
name|pMPIHeader_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Default Reply                                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_DEFAULT_REPLY
block|{
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* function specific */
name|U8
name|MsgLength
decl_stmt|;
name|U8
name|Function
decl_stmt|;
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* function specific */
name|U8
name|MsgFlags
decl_stmt|;
name|U32
name|MsgContext
decl_stmt|;
name|U8
name|Reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* function specific */
name|U16
name|IOCStatus
decl_stmt|;
name|U32
name|IOCLogInfo
decl_stmt|;
block|}
name|MSG_DEFAULT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_DEFAULT_REPLY
operator|,
name|MPIDefaultReply_t
operator|,
name|MPI_POINTER
name|pMPIDefaultReply_t
typedef|;
end_typedef

begin_comment
comment|/* MsgFlags definition for all replies */
end_comment

begin_define
define|#
directive|define
name|MPI_MSGFLAGS_CONTINUATION_REPLY
value|(0x80)
end_define

begin_comment
comment|/***************************************************************************** * *               I O C    S t a t u s   V a l u e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Common IOCStatus values for all replies                                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SUCCESS
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INVALID_FUNCTION
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_BUSY
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INVALID_SGL
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INTERNAL_ERROR
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_RESERVED
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INSUFFICIENT_RESOURCES
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INVALID_FIELD
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_INVALID_STATE
value|(0x0008)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Config IOCStatus values                                                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_INVALID_ACTION
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_INVALID_TYPE
value|(0x0021)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_INVALID_PAGE
value|(0x0022)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_INVALID_DATA
value|(0x0023)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_NO_DEFAULTS
value|(0x0024)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_CONFIG_CANT_COMMIT
value|(0x0025)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSIIO Reply (SPI& FCP) initiator values                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_RECOVERED_ERROR
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_INVALID_BUS
value|(0x0041)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_INVALID_TARGETID
value|(0x0042)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_DEVICE_NOT_THERE
value|(0x0043)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_DATA_OVERRUN
value|(0x0044)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_DATA_UNDERRUN
value|(0x0045)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_IO_DATA_ERROR
value|(0x0046)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_PROTOCOL_ERROR
value|(0x0047)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_TASK_TERMINATED
value|(0x0048)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_RESIDUAL_MISMATCH
value|(0x0049)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_TASK_MGMT_FAILED
value|(0x004A)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_IOC_TERMINATED
value|(0x004B)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_SCSI_EXT_TERMINATED
value|(0x004C)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSI (SPI& FCP) target values                                          */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_PRIORITY_IO
value|(0x0060)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_INVALID_PORT
value|(0x0061)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_INVALID_IOCINDEX
value|(0x0062)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_INVALID_IO_INDEX
value|(0x0062)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_ABORTED
value|(0x0063)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_NO_CONN_RETRYABLE
value|(0x0064)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_NO_CONNECTION
value|(0x0065)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_XFER_COUNT_MISMATCH
value|(0x006A)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_STS_DATA_NOT_SENT
value|(0x006B)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Additional FCP target values                                            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_FC_ABORTED
value|(0x0066)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_FC_RX_ID_INVALID
value|(0x0067)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_FC_DID_INVALID
value|(0x0068)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_TARGET_FC_NODE_LOGGED_OUT
value|(0x0069)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Fibre Channel Direct Access values                                      */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FC_ABORTED
value|(0x0066)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FC_RX_ID_INVALID
value|(0x0067)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FC_DID_INVALID
value|(0x0068)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FC_NODE_LOGGED_OUT
value|(0x0069)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FC_EXCHANGE_CANCELED
value|(0x006C)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  LAN values                                                              */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_DEVICE_NOT_FOUND
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_DEVICE_FAILURE
value|(0x0081)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_TRANSMIT_ERROR
value|(0x0082)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_TRANSMIT_ABORTED
value|(0x0083)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_RECEIVE_ERROR
value|(0x0084)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_RECEIVE_ABORTED
value|(0x0085)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_PARTIAL_PACKET
value|(0x0086)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_LAN_CANCELED
value|(0x0087)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  IOCStatus flag to indicate that log info is available                   */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_FLAG_LOG_INFO_AVAILABLE
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCSTATUS_MASK
value|(0x7FFF)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  LogInfo Types                                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_TYPE_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_TYPE_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_TYPE_NONE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_TYPE_SCSI
value|(0x1)
end_define

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_TYPE_FC
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPI_IOCLOGINFO_LOG_DATA_MASK
value|(0x0FFFFFFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

