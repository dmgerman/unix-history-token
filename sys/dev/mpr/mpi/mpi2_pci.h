begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_pci.h  *          Title:  MPI PCIe Attached Devices structures and definitions.  *  Creation Date:  October 9, 2012  *  *  mpi2_pci.h Version:  02.00.02  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  03-16-15  02.00.00  Initial version.  *  02-17-16  02.00.01  Removed AHCI support.  *                      Removed SOP support.  *  07-01-16  02.00.02  Added MPI26_NVME_FLAGS_FORCE_ADMIN_ERR_RESP to  *                      NVME Encapsulated Request.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_PCI_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_PCI_H
end_define

begin_comment
comment|/*  * Values for the PCIe DeviceInfo field used in PCIe Device Status Change Event  * data and PCIe Configuration pages.  */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVINFO_DIRECT_ATTACH
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVINFO_MASK_DEVICE_TYPE
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVINFO_NO_DEVICE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVINFO_PCI_SWITCH
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVINFO_NVME
value|(0x00000003)
end_define

begin_comment
comment|/**************************************************************************** *  NVMe Encapsulated message ****************************************************************************/
end_comment

begin_comment
comment|/* NVME Encapsulated Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_NVME_ENCAPSULATED_REQUEST
block|{
name|U16
name|DevHandle
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
name|EncapsulatedCommandLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
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
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U64
name|ErrorResponseBaseAddress
decl_stmt|;
comment|/* 0x10 */
name|U16
name|ErrorResponseAllocationLength
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x1A */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|U8
name|NVMe_Command
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x20 */
comment|/* variable length */
block|}
name|MPI26_NVME_ENCAPSULATED_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI26_NVME_ENCAPSULATED_REQUEST
operator|,
name|Mpi26NVMeEncapsulatedRequest_t
operator|,
name|MPI2_POINTER
name|pMpi26NVMeEncapsulatedRequest_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_FORCE_ADMIN_ERR_RESP
value|(0x0020)
end_define

begin_comment
comment|/* Submission Queue Type*/
end_comment

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_SUBMISSIONQ_MASK
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_SUBMISSIONQ_IO
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_SUBMISSIONQ_ADMIN
value|(0x0010)
end_define

begin_comment
comment|/* Error Response Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_MASK_ERROR_RSP_ADDR
value|(0x000C)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_SYSTEM_RSP_ADDR
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_IOCPLB_RSP_ADDR
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_IOCPLBNTA_RSP_ADDR
value|(0x000C)
end_define

begin_comment
comment|/* Data Direction*/
end_comment

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_DATADIRECTION_MASK
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_NODATATRANSFER
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_WRITE
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_READ
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI26_NVME_FLAGS_BIDIRECTIONAL
value|(0x0003)
end_define

begin_comment
comment|/* NVMe Encapuslated Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_NVME_ENCAPSULATED_ERROR_REPLY
block|{
name|U16
name|DevHandle
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
name|EncapsulatedCommandLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
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
name|ErrorResponseCount
decl_stmt|;
comment|/* 0x14 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x16 */
block|}
name|MPI26_NVME_ENCAPSULATED_ERROR_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI26_NVME_ENCAPSULATED_ERROR_REPLY
operator|,
name|Mpi26NVMeEncapsulatedErrorReply_t
operator|,
name|MPI2_POINTER
name|pMpi26NVMeEncapsulatedErrorReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

