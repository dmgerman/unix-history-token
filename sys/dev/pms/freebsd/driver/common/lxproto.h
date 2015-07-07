begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************* Module Name:     lxproto.h Abstract:     PMC-Sierra initiator/target driver common function prototype definition Environment:     Kernel or loadable module   Notes:  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LX_PROTO_H__
end_ifndef

begin_define
define|#
directive|define
name|__LX_PROTO_H__
end_define

begin_function_decl
name|void
name|agtiapi_DelayMSec
parameter_list|(
name|U32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_DelaySec
parameter_list|(
name|U32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_DisplayRsc
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|agBOOLEAN
name|agtiapi_InitResource
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|agBOOLEAN
name|agtiapi_typhAlloc
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agtiapi_ScopeDMARes
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_ReleasePCIMem
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STATIC
name|agBOOLEAN
name|agtiapi_MemAlloc
parameter_list|(
name|ag_card_info_t
modifier|*
name|thisCardInst
parameter_list|,
name|void
modifier|*
modifier|*
name|VirtAlloc
parameter_list|,
name|vm_paddr_t
modifier|*
name|pDmaAddr
parameter_list|,
name|void
modifier|*
modifier|*
name|VirtAddr
parameter_list|,
name|U32
modifier|*
name|pPhysAddrUp
parameter_list|,
name|U32
modifier|*
name|pPhysAddrLow
parameter_list|,
name|U32
name|MemSize
parameter_list|,
name|U32
name|Type
parameter_list|,
name|U32
name|Align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_MemFree
parameter_list|(
name|ag_card_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|U32
name|agtiapi_PCIMemSize
parameter_list|(
name|device_t
parameter_list|,
name|U32
parameter_list|,
name|U32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_Probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agtiapi_ProbeCard
parameter_list|(
name|device_t
parameter_list|,
name|ag_card_info_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agtiapi_Setup
parameter_list|(
name|S08
modifier|*
parameter_list|,
name|S32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CHAR_DEVICE
end_ifdef

begin_comment
comment|//int        agtiapi_Open(struct inode *, struct file *);
end_comment

begin_comment
comment|//int        agtiapi_Close(struct inode *, struct file *);
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_INCLUDE_PROCS
end_ifdef

begin_function_decl
specifier|static
name|void
name|agtiapi_ProcDel
parameter_list|(
name|ag_card_info_t
modifier|*
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|agtiapi_ProcAdd
parameter_list|(
name|ag_card_info_t
modifier|*
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_DUMP_FCTRACE_BUFFER
end_ifdef

begin_if
if|#
directive|if
name|fcEnableTraceFunctions
operator|==
literal|1
end_if

begin_function_decl
specifier|static
name|void
name|agtiapi_DumpTraceBuffer
parameter_list|(
name|ag_card_info_t
modifier|*
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

