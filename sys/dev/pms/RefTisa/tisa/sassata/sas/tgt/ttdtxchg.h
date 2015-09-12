begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * $RCSfile: ttdtxchg.h,v $  *  * Copyright 2006 PMC-Sierra, Inc.  *  *  * #define and data structures for SAS target in SAS/SATA TD layer  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sas_resp_s
block|{
name|agsaSSPResponseInfoUnit_t
name|agResp
decl_stmt|;
name|bit8
name|RespData
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|SenseData
index|[
literal|64
index|]
decl_stmt|;
block|}
name|sas_resp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smp_resp_s
block|{
name|bit8
name|RespData
index|[
literal|1024
index|]
decl_stmt|;
comment|/* SAS Spec */
block|}
name|smp_resp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
modifier|*
name|virtAddr
decl_stmt|;
name|bit32
name|phyAddrUpper
decl_stmt|;
name|bit32
name|phyAddrLower
decl_stmt|;
name|bit32
name|length
decl_stmt|;
block|}
name|ttdsaDmaMemoryArea_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|tdsaDeviceData_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* I/O structurre */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ttdsaXchg_s
block|{
name|tdIORequestBody_t
name|IORequestBody
decl_stmt|;
comment|/* has to be at the top */
name|tdssSMPRequestBody_t
name|SMPRequestBody
decl_stmt|;
comment|/* has to be at the second top */
name|tdList_t
name|XchgLinks
decl_stmt|;
comment|/* pointer to device(initiator) for which the I/O was initiated */
name|struct
name|tdsaDeviceData_s
modifier|*
name|DeviceData
decl_stmt|;
name|struct
name|ttdsaXchg_s
modifier|*
name|pTMResp
decl_stmt|;
name|bit32
name|oustandingIos
decl_stmt|;
name|bit32
name|isAborting
decl_stmt|;
name|bit32
name|oslayerAborting
decl_stmt|;
name|bit32
name|isTMRequest
decl_stmt|;
name|bit32
name|index
decl_stmt|;
comment|/* index of structure */
name|agsaSSPCmdInfoUnit_t
name|agSSPCmndIU
decl_stmt|;
name|agsaSSPScsiTaskMgntReq_t
name|agTMIU
decl_stmt|;
comment|/* SSPTargetRead/SSPTargetWrite             */
name|bit32
name|XchType
decl_stmt|;
name|bit32
name|FrameType
decl_stmt|;
comment|/* cmnd or TM */
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
name|tiRoot_t
modifier|*
name|tiRoot
decl_stmt|;
comment|/* indicates that at the completion of this data phase, this      exchange structure will be freed */
name|bit32
name|statusSent
decl_stmt|;
name|bit32
name|responseSent
decl_stmt|;
name|bit32
name|readRspCollapsed
range|:
literal|1
decl_stmt|;
name|bit32
name|wrtRspCollapsed
range|:
literal|1
decl_stmt|;
name|bit32
name|readWrtCollapsedRes
range|:
literal|30
decl_stmt|;
name|tiTargetScsiCmnd_t
name|tiTgtScsiCmnd
decl_stmt|;
comment|/* initiator tag a target received */
name|bit16
name|tag
decl_stmt|;
name|bit64
name|dataLen
decl_stmt|;
name|bit32
name|respLen
decl_stmt|;
name|bit32
name|smprespLen
decl_stmt|;
name|ttdsaDmaMemoryArea_t
name|resp
decl_stmt|;
comment|/* sas response */
name|ttdsaDmaMemoryArea_t
name|smpresp
decl_stmt|;
comment|/* sas smp response */
name|bit32
name|usedEsgl
decl_stmt|;
comment|/* for abort task io which is not founded in TD */
name|bit32
name|io_found
decl_stmt|;
comment|/* for debugging only */
name|bit32
name|id
decl_stmt|;
comment|/* PhyId for SMP*/
name|bit32
name|SMPphyId
decl_stmt|;
name|bit32
name|state
decl_stmt|;
name|bit32
name|TLR
decl_stmt|;
comment|/* Transport Layer Retransmit bits */
name|bit32
name|retries
decl_stmt|;
comment|/* retries */
name|tiIORequest_t
modifier|*
name|tiIOToBeAbortedRequest
decl_stmt|;
comment|/* IO to be aborted */
name|struct
name|ttdsaXchg_s
modifier|*
name|XchgToBeAborted
decl_stmt|;
comment|/* Xchg to be aborted */
block|}
name|ttdsaXchg_t
typedef|;
end_typedef

begin_comment
comment|/************************************************************************* ** now ttdssIOData_t and old tgtXchgData_t - **************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ttdsaXchgData_s
block|{
name|bit32
name|maxNumXchgs
decl_stmt|;
name|tdList_t
name|xchgFreeList
decl_stmt|;
name|tdList_t
name|xchgBusyList
decl_stmt|;
name|bit32
name|noUsed
decl_stmt|;
name|bit32
name|noFreed
decl_stmt|;
name|bit32
name|noCmdRcvd
decl_stmt|;
name|bit32
name|noStartIo
decl_stmt|;
name|bit32
name|noSendRsp
decl_stmt|;
name|bit32
name|noCompleted
decl_stmt|;
block|}
name|ttdsaXchgData_t
typedef|;
end_typedef

end_unit

