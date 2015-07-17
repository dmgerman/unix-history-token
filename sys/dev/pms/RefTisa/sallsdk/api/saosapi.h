begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file saosapi.h  *  \brief The file defines the declaration of OS APIs  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SSDKOSAPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__SSDKOSAPI_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LINUX
end_ifdef

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|18
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|FORCEINLINE
end_ifdef

begin_undef
undef|#
directive|undef
name|FORCEINLINE
end_undef

begin_define
define|#
directive|define
name|FORCEINLINE
end_define

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

begin_comment
comment|/***************************************************************************  * Definition of register access related functions start                   *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwRegRead
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|bit32
name|ossaHwRegRead
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|regOffset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwRegWrite
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaHwRegWrite
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|regOffset
parameter_list|,
name|bit32
name|regValue
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwRegReadExt
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|bit32
name|ossaHwRegReadExt
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|busBaseNumber
parameter_list|,
name|bit32
name|regOffset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwRegWriteExt
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaHwRegWriteExt
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|busBaseNumber
parameter_list|,
name|bit32
name|regOffset
parameter_list|,
name|bit32
name|regValue
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwRegReadConfig32
end_ifndef

begin_function_decl
name|osGLOBAL
name|bit32
name|ossaHwRegReadConfig32
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|regOffset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of register access related functions end                     *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of thread related functions start                            *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSingleThreadedEnter
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaSingleThreadedEnter
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|syncLockId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSingleThreadedLeave
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaSingleThreadedLeave
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|syncLockId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaStallThread
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaStallThread
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|microseconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of thread related functions end                              *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of interrupt related functions start                         *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDisableInterrupts
end_ifndef

begin_define
define|#
directive|define
name|ossaDisableInterrupts
parameter_list|(
name|agRoot
parameter_list|,
name|interruptVectorIndex
parameter_list|)
define|\
value|do                                                          \ {                                                           \   agsaLLRoot_t  *saROOT = (agsaLLRoot_t *)(agRoot->sdkData);\   saROOT->DisableInterrupts(agRoot, interruptVectorIndex); \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaReenableInterrupts
end_ifndef

begin_define
define|#
directive|define
name|ossaReenableInterrupts
parameter_list|(
name|agRoot
parameter_list|,
name|interruptVectorIndex
parameter_list|)
define|\
value|do                                                           \ {                                                            \   agsaLLRoot_t  *saROOT = (agsaLLRoot_t *)(agRoot->sdkData); \   saROOT->ReEnableInterrupts(agRoot, interruptVectorIndex); \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of interrupt related functions end                           *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of cache related functions start                             *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaCacheInvalidate
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaCacheInvalidate
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|void
modifier|*
name|osMemHandle
parameter_list|,
name|void
modifier|*
name|virtPtr
parameter_list|,
name|bit32
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaCacheFlush
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaCacheFlush
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|void
modifier|*
name|osMemHandle
parameter_list|,
name|void
modifier|*
name|virtPtr
parameter_list|,
name|bit32
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaCachePreFlush
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaCachePreFlush
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|void
modifier|*
name|osMemHandle
parameter_list|,
name|void
modifier|*
name|virtPtr
parameter_list|,
name|bit32
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of cache related functions end                               *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of hardware related functions start                          *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaHwCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|bit32
name|event
parameter_list|,
name|bit32
name|eventParm1
parameter_list|,
name|void
modifier|*
name|eventParm2
parameter_list|,
name|void
modifier|*
name|eventParm3
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaHwEventAckCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaHwEventAckCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of hardware related functions end                            *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of SATA related functions start                              *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSATACompleted
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSATACompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|void
modifier|*
name|agFirstDword
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSATAEvent
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSATAEvent
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|event
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSATAAbortCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSATAAbortCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|flag
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of SATA related functions end                                *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of SAS related functions start                               *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSSPEvent
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSSPEvent
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|event
parameter_list|,
name|bit16
name|sspTag
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|osGLOBAL
name|void
name|ossaSMPIoctlCompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSMPCompleted
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSMPCompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSMPReqReceived
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSMPReqReceived
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|,
name|bit32
name|agFrameLength
parameter_list|,
name|bit32
name|phyId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSSPCompleted
end_ifndef

begin_function_decl
name|GLOBAL
name|FORCEINLINE
name|void
name|ossaSSPCompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|,
name|bit16
name|sspTag
parameter_list|,
name|bit32
name|agOtherInfo
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
name|FAST_IO_TEST
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|ossaFastSSPCompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|cbArg
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|,
name|bit16
name|sspTag
parameter_list|,
name|bit32
name|agOtherInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSSPReqReceived
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSSPReqReceived
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|,
name|bit16
name|agInitiatorTag
parameter_list|,
name|bit32
name|parameter
parameter_list|,
name|bit32
name|agFrameLen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|osGLOBAL
name|void
name|ossaSSPIoctlCompleted
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|,
name|bit16
name|sspTag
parameter_list|,
name|bit32
name|agOtherInfo
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSSPAbortCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSSPAbortCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|flag
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSMPAbortCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSMPAbortCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|flag
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaReconfigSASParamsCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaReconfigSASParamsCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaSASReconfig_t
modifier|*
name|agSASConfig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of SAS related functions end                                 *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of Discovery related functions start                         *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDiscoverSataCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaDiscoverSataCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|bit32
name|event
parameter_list|,
name|void
modifier|*
name|pParm1
parameter_list|,
name|void
modifier|*
name|pParm2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDiscoverSasCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaDiscoverSasCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|bit32
name|event
parameter_list|,
name|void
modifier|*
name|pParm1
parameter_list|,
name|void
modifier|*
name|pParm2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDeviceHandleAccept
end_ifndef

begin_function_decl
name|GLOBAL
name|bit32
name|ossaDeviceHandleAccept
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|agsaSASDeviceInfo_t
modifier|*
name|agDeviceInfo
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|bit32
modifier|*
name|hostAssignedDeviceId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetDeviceHandlesCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetDeviceHandlesCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDev
index|[]
parameter_list|,
name|bit32
name|validDevs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetDeviceInfoCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetDeviceInfoCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|,
name|void
modifier|*
name|agInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDeviceHandleRemovedEvent
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaDeviceHandleRemovedEvent
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetDeviceStateCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetDeviceStateCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|deviceState
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSetDeviceInfoCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSetDeviceInfoCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|option
parameter_list|,
name|bit32
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSetDeviceStateCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSetDeviceStateCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|newDeviceState
parameter_list|,
name|bit32
name|previousDeviceState
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of Discovery related functions end                           *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of Misc. related functions start                             *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaTimeStamp
end_ifndef

begin_function_decl
name|GLOBAL
name|bit32
name|ossaTimeStamp
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ossaTimeStamp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaTimeStamp64
end_ifndef

begin_function_decl
name|GLOBAL
name|bit64
name|ossaTimeStamp64
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ossaTimeStamp64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLocalPhyControlCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLocalPhyControlCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|phyId
parameter_list|,
name|bit32
name|phyOperation
parameter_list|,
name|bit32
name|status
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetPhyProfileCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetPhyProfileCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|ppc
parameter_list|,
name|bit32
name|phyID
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSetPhyProfileCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSetPhyProfileCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|ppc
parameter_list|,
name|bit32
name|phyID
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaFwFlashUpdateCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaFwFlashUpdateCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaFlashExtExecuteCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaFlashExtExecuteCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|command
parameter_list|,
name|agsaFlashExtResponse_t
modifier|*
name|agFlashExtRsp
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
name|SPC_ENABLE_PROFILE
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|ossaFwProfileCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaEchoCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaEchoCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|void
modifier|*
name|echoPayload
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGpioResponseCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGpioResponseCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|gpioReadValue
parameter_list|,
name|agsaGpioPinSetupInfo_t
modifier|*
name|gpioPinSetupInfo
parameter_list|,
name|agsaGpioEventSetupInfo_t
modifier|*
name|gpioEventSetupInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGpioEvent
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGpioEvent
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|gpioEvent
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSASDiagExecuteCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSASDiagExecuteCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|command
parameter_list|,
name|bit32
name|reportData
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSASDiagStartEndCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSASDiagStartEndCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetTimeStampCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetTimeStampCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|timeStampLower
parameter_list|,
name|bit32
name|timeStampUpper
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaPortControlCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaPortControlCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaPortContext_t
modifier|*
name|agPortContext
parameter_list|,
name|bit32
name|portOperation
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGeneralEvent
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGeneralEvent
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetRegisterDumpCB
end_ifndef

begin_function_decl
name|void
name|ossaGetRegisterDumpCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|GLOBAL
name|void
name|ossaGetForensicDataCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaForensicData_t
modifier|*
name|forensicData
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetNVMDResponseCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetNVMDResponseCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit8
name|indirectPayload
parameter_list|,
name|bit32
name|agInfoLen
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSetNVMDResponseCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSetNVMDResponseCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaQueueProcessed
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SALLSDK_TEST_SET_OB_QUEUE
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|ossaQueueProcessed
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|queue
parameter_list|,
name|bit32
name|obpi
parameter_list|,
name|bit32
name|obci
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ossaQueueProcessed
parameter_list|(
name|agRoot
parameter_list|,
name|queue
parameter_list|,
name|obpi
parameter_list|,
name|obci
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSGpioCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSGpioCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaSGpioReqResponse_t
modifier|*
name|pSgpioResponse
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaPCIeDiagExecuteCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaPCIeDiagExecuteCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|command
parameter_list|,
name|agsaPCIeDiagResponse_t
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetDFEDataCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetDFEDataCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|agInfoLen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaVhistCaptureCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaVhistCaptureCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetIOErrorStatsCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetIOErrorStatsCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaIOErrorEventStats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetIOEventStatsCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetIOEventStatsCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaIOErrorEventStats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaOperatorManagementCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaOperatorManagementCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaEncryptSelftestExecuteCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaEncryptSelftestExecuteCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|type
parameter_list|,
name|bit32
name|length
parameter_list|,
name|void
modifier|*
name|TestResult
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaGetOperatorCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaGetOperatorCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|option
parameter_list|,
name|bit32
name|num
parameter_list|,
name|bit32
name|role
parameter_list|,
name|agsaID_t
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaSetOperatorCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaSetOperatorCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaDIFEncryptionOffloadStartCB
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaDIFEncryptionOffloadStartCB
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaOffloadDifDetails_t
modifier|*
name|agsaOffloadDifDetails
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of Misc related functions end                                *  ***************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  * Definition of Debug related functions start                             *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogTrace0
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogTrace0
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|traceCode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogTrace1
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogTrace1
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|traceCode
parameter_list|,
name|bit32
name|value1
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogTrace2
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogTrace2
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|traceCode
parameter_list|,
name|bit32
name|value1
parameter_list|,
name|bit32
name|value2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogTrace3
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogTrace3
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|traceCode
parameter_list|,
name|bit32
name|value1
parameter_list|,
name|bit32
name|value2
parameter_list|,
name|bit32
name|value3
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogTrace4
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogTrace4
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|traceCode
parameter_list|,
name|bit32
name|value1
parameter_list|,
name|bit32
name|value2
parameter_list|,
name|bit32
name|value3
parameter_list|,
name|bit32
name|value4
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ossaLogDebugString
end_ifndef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogDebugString
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|level
parameter_list|,
name|char
modifier|*
name|string
parameter_list|,
name|void
modifier|*
name|ptr1
parameter_list|,
name|void
modifier|*
name|ptr2
parameter_list|,
name|bit32
name|value1
parameter_list|,
name|bit32
name|value2
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
name|SALLSDK_OS_IOMB_LOG_ENABLE
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|ossaLogIomb
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|queueNum
parameter_list|,
name|agBOOLEAN
name|isInbound
parameter_list|,
name|void
modifier|*
name|pMsg
parameter_list|,
name|bit32
name|msgLength
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ossaLogIomb
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|osGLOBAL
name|void
name|ossaPCI_TRIGGER
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PERF_COUNT
end_ifdef

begin_function_decl
name|osGLOBAL
name|void
name|ossaEnter
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|int
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osGLOBAL
name|void
name|ossaLeave
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|int
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OSSA_INP_ENTER
parameter_list|(
name|root
parameter_list|)
value|ossaEnter(root, 0)
end_define

begin_define
define|#
directive|define
name|OSSA_INP_LEAVE
parameter_list|(
name|root
parameter_list|)
value|ossaLeave(root, 0)
end_define

begin_define
define|#
directive|define
name|OSSA_OUT_ENTER
parameter_list|(
name|root
parameter_list|)
value|ossaEnter(root, 1)
end_define

begin_define
define|#
directive|define
name|OSSA_OUT_LEAVE
parameter_list|(
name|root
parameter_list|)
value|ossaLeave(root, 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSSA_INP_ENTER
parameter_list|(
name|root
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSSA_INP_LEAVE
parameter_list|(
name|root
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSSA_OUT_ENTER
parameter_list|(
name|root
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSSA_OUT_LEAVE
parameter_list|(
name|root
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Definition of Debug related functions end                               *  ***************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SSDKOSAPI_H__ */
end_comment

end_unit

