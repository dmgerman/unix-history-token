begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* ** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** **     *   dm.h  * *   Abstract:   This module defines the contants, enum and #define definition used *               by Discovery Moduled (DM). *      ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DM_H
end_ifndef

begin_define
define|#
directive|define
name|DM_H
end_define

begin_comment
comment|/*************************************************  *   constants for type field in agsaMem_t  *************************************************/
end_comment

begin_define
define|#
directive|define
name|DM_CACHED_MEM
value|0x00
end_define

begin_comment
comment|/**< CACHED memory type */
end_comment

begin_define
define|#
directive|define
name|DM_DMA_MEM
value|0x01
end_define

begin_comment
comment|/**< DMA memory type */
end_comment

begin_define
define|#
directive|define
name|DM_CACHED_DMA_MEM
value|0x02
end_define

begin_comment
comment|/**< CACHED DMA memory type */
end_comment

begin_comment
comment|/*************************************************  *   constants for API return values  *************************************************/
end_comment

begin_define
define|#
directive|define
name|DM_RC_SUCCESS
value|0x00
end_define

begin_comment
comment|/**< Successful function return value */
end_comment

begin_define
define|#
directive|define
name|DM_RC_FAILURE
value|0x01
end_define

begin_comment
comment|/**< Failed function return value */
end_comment

begin_define
define|#
directive|define
name|DM_RC_BUSY
value|0x02
end_define

begin_comment
comment|/**< Busy function return value */
end_comment

begin_define
define|#
directive|define
name|DM_RC_VERSION_INCOMPATIBLE
value|0x03
end_define

begin_comment
comment|/**< Version miss match */
end_comment

begin_define
define|#
directive|define
name|DM_RC_VERSION_UNTESTED
value|0x04
end_define

begin_comment
comment|/**< Version not tested */
end_comment

begin_comment
comment|/*************************************************  *   Discovery option  *************************************************/
end_comment

begin_define
define|#
directive|define
name|DM_DISCOVERY_OPTION_FULL_START
value|0x00
end_define

begin_comment
comment|/**< Full discovery */
end_comment

begin_define
define|#
directive|define
name|DM_DISCOVERY_OPTION_INCREMENTAL_START
value|0x01
end_define

begin_comment
comment|/**< Incremental discovery */
end_comment

begin_define
define|#
directive|define
name|DM_DISCOVERY_OPTION_ABORT
value|0x02
end_define

begin_comment
comment|/**< Discovery abort */
end_comment

begin_comment
comment|/*************************************************  *   Discovery status  *************************************************/
end_comment

begin_enum
enum|enum
name|dmDiscoveryState_e
block|{
name|dmDiscCompleted
init|=
literal|0
block|,
name|dmDiscFailed
block|,
name|dmDiscAborted
block|,
name|dmDiscAbortFailed
block|,
name|dmDiscInProgress
block|,
name|dmDiscAbortInvalid
block|,
comment|/* no discovery to abort */
name|dmDiscAbortInProgress
block|,
comment|/* abort in progress */
block|}
enum|;
end_enum

begin_comment
comment|/*************************************************  *   Device status  *************************************************/
end_comment

begin_enum
enum|enum
name|dmDeviceState_e
block|{
name|dmDeviceNoChange
init|=
literal|0
block|,
name|dmDeviceArrival
block|,
name|dmDeviceRemoval
block|,
name|dmDeviceMCNChange
block|,
name|dmDeviceRateChange
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|dmContext_s
block|{
name|void
modifier|*
name|tdData
decl_stmt|;
name|void
modifier|*
name|dmData
decl_stmt|;
block|}
name|dmContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit16
name|smpTimeout
decl_stmt|;
name|bit16
name|it_NexusTimeout
decl_stmt|;
name|bit16
name|firstBurstSize
decl_stmt|;
name|bit8
name|flag
decl_stmt|;
name|bit8
name|devType_S_Rate
decl_stmt|;
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|initiator_ssp_stp_smp
decl_stmt|;
name|bit8
name|target_ssp_stp_smp
decl_stmt|;
comment|/* bit8 - bit14 are set by the user of DM such as TDM for directly attached expander            0 - 7; PhyID             8: non SMP or not            9 - 10: types of expander, valid only when bit8 is set                    10b (2): edge expander                    11b (3): fanout expander            11 - 14: MCN         */
name|bit16
name|ext
decl_stmt|;
name|bit8
name|sataDeviceType
decl_stmt|;
name|bit8
name|reserved
decl_stmt|;
block|}
name|dmDeviceInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|virtPtr
decl_stmt|;
name|void
modifier|*
name|osHandle
decl_stmt|;
name|bit32
name|physAddrUpper
decl_stmt|;
name|bit32
name|physAddrLower
decl_stmt|;
name|bit32
name|totalLength
decl_stmt|;
name|bit32
name|numElements
decl_stmt|;
name|bit32
name|singleElementLength
decl_stmt|;
name|bit32
name|alignment
decl_stmt|;
name|bit32
name|type
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
block|}
name|dmMem_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DM_NUM_MEM_CHUNKS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit32
name|count
decl_stmt|;
name|dmMem_t
name|dmMemory
index|[
name|DM_NUM_MEM_CHUNKS
index|]
decl_stmt|;
block|}
name|dmMemoryRequirement_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|dmContext_t
name|dmPortContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|dmContext_t
name|dmRoot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit32
name|numDevHandles
decl_stmt|;
name|bit32
name|tbd1
decl_stmt|;
name|bit32
name|tbd2
decl_stmt|;
ifdef|#
directive|ifdef
name|DM_DEBUG
name|bit32
name|DMDebugLevel
decl_stmt|;
endif|#
directive|endif
name|bit32
name|itNexusTimeout
decl_stmt|;
block|}
name|dmSwConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
name|sasRemoteAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasRemoteAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasLocalAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasLocalAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|flag
decl_stmt|;
block|}
name|dmPortInfo_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DM_H */
end_comment

end_unit

