begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          e500v2_ext.h   @Description   E500 external definitions prototypes                 This file is not included by the E500                 source file as it is an assembly file. It is used                 only for prototypes exposure, for inclusion                 by user and other modules. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__E500V2_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__E500V2_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/* Layer 1 Cache Manipulations  *==============================  * Should not be called directly by the user.  */
end_comment

begin_function_decl
name|void
name|L1DCache_Invalidate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1ICache_Invalidate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1DCache_Enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1ICache_Enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1DCache_Disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1ICache_Disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1DCache_Flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1ICache_Flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|L1ICache_IsEnabled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|L1DCache_IsEnabled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|uint32_t
name|L1DCache_LineLock
parameter_list|(
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|L1ICache_LineLock
parameter_list|(
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1Cache_BroadCastEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|L1Cache_BroadCastDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CORE_DCacheEnable
value|E500_DCacheEnable
end_define

begin_define
define|#
directive|define
name|CORE_ICacheEnable
value|E500_ICacheEnable
end_define

begin_define
define|#
directive|define
name|CORE_DCacheDisable
value|E500_DCacheDisable
end_define

begin_define
define|#
directive|define
name|CORE_ICacheDisable
value|E500_ICacheDisable
end_define

begin_define
define|#
directive|define
name|CORE_GetId
value|E500_GetId
end_define

begin_define
define|#
directive|define
name|CORE_TestAndSet
value|E500_TestAndSet
end_define

begin_define
define|#
directive|define
name|CORE_MemoryBarrier
value|E500_MemoryBarrier
end_define

begin_define
define|#
directive|define
name|CORE_InstructionSync
value|E500_InstructionSync
end_define

begin_define
define|#
directive|define
name|CORE_SetDozeMode
value|E500_SetDozeMode
end_define

begin_define
define|#
directive|define
name|CORE_SetNapMode
value|E500_SetNapMode
end_define

begin_define
define|#
directive|define
name|CORE_SetSleepMode
value|E500_SetSleepMode
end_define

begin_define
define|#
directive|define
name|CORE_SetJogMode
value|E500_SetJogMode
end_define

begin_define
define|#
directive|define
name|CORE_SetDeepSleepMode
value|E500_SetDeepSleepMode
end_define

begin_define
define|#
directive|define
name|CORE_RecoverDozeMode
value|E500_RecoverDozeMode
end_define

begin_define
define|#
directive|define
name|CORE_RecoverNapMode
value|E500_RecoverNapMode
end_define

begin_define
define|#
directive|define
name|CORE_RecoverSleepMode
value|E500_RecoverSleepMode
end_define

begin_define
define|#
directive|define
name|CORE_RecoverJogMode
value|E500_RecoverJogMode
end_define

begin_function_decl
name|void
name|E500_SetDozeMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_SetNapMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_SetSleepMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_SetJogMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|E500_SetDeepSleepMode
parameter_list|(
name|uint32_t
name|bptrAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_RecoverDozeMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_RecoverNapMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_RecoverSleepMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_RecoverJogMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         E500_id E500 Application Programming Interface   @Description   E500 API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         E500_init_grp E500 Initialization Unit   @Description   E500 initialization unit API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_DCacheEnable   @Description   Enables the data cache for memory pages that are                 not cache inhibited.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_DCacheEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_ICacheEnable   @Description   Enables the instruction cache for memory pages that are                 not cache inhibited.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_ICacheEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_DCacheDisable   @Description   Disables the data cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_DCacheDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_ICacheDisable   @Description   Disables the instruction cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_ICacheDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_DCacheFlush   @Description   Flushes the data cache   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_DCacheFlush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_ICacheFlush   @Description   Flushes the instruction cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_ICacheFlush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_DCacheSetStashId   @Description   Set Stash Id for data cache   @Param[in]     stashId     the stash id to be set.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_DCacheSetStashId
parameter_list|(
name|uint8_t
name|stashId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   E500mc L2 Cache Operation Mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_E500mcL2CacheMode
block|{
name|e_L2_CACHE_MODE_DATA_ONLY
init|=
literal|0x00000001
block|,
comment|/**< Cache data only */
name|e_L2_CACHE_MODE_INST_ONLY
init|=
literal|0x00000002
block|,
comment|/**< Cache instructions only */
name|e_L2_CACHE_MODE_DATA_AND_INST
init|=
literal|0x00000003
comment|/**< Cache data and instructions */
block|}
name|e_E500mcL2CacheMode
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CORE_E500MC
argument_list|)
operator|||
name|defined
argument_list|(
name|CORE_E5500
argument_list|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_L2CacheEnable   @Description   Enables the cache for memory pages that are not cache inhibited.   @param[in]     mode - L2 cache mode: data only, instruction only or instruction and data.   @Return        None.   @Cautions      This routine must be call only ONCE for both caches. I.e. it is                 not possible to call this routine for i-cache and than to call                 again for d-cache; The second call will override the first one. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_L2CacheEnable
parameter_list|(
name|e_E500mcL2CacheMode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_L2CacheDisable   @Description   Disables the cache (data instruction or both).   @Return        None.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_L2CacheDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_L2CacheFlush   @Description   Flushes the cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_L2CacheFlush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_L2SetStashId   @Description   Set Stash Id   @Param[in]     stashId     the stash id to be set.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_L2SetStashId
parameter_list|(
name|uint8_t
name|stashId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CORE_E500MC) || defined(CORE_E5500) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CORE_E6500
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E6500_L2CacheEnable   @Description   Enables the cache for memory pages that are not cache inhibited.   @param[in]     mode - L2 cache mode: support data& instruction only.   @Return        None.   @Cautions      This routine must be call only ONCE for both caches. I.e. it is                 not possible to call this routine for i-cache and than to call                 again for d-cache; The second call will override the first one. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E6500_L2CacheEnable
parameter_list|(
name|uintptr_t
name|clusterBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E6500_L2CacheDisable   @Description   Disables the cache (data instruction or both).   @Return        None.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E6500_L2CacheDisable
parameter_list|(
name|uintptr_t
name|clusterBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E6500_L2CacheFlush   @Description   Flushes the cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E6500_L2CacheFlush
parameter_list|(
name|uintptr_t
name|clusterBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E6500_L2SetStashId   @Description   Set Stash Id   @Param[in]     stashId     the stash id to be set.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E6500_L2SetStashId
parameter_list|(
name|uintptr_t
name|clusterBase
parameter_list|,
name|uint8_t
name|stashId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E6500_GetCcsrBase   @Description   Obtain SoC CCSR base address   @Param[in]     None.   @Return        Physical CCSR base address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|physAddress_t
name|E6500_GetCcsrBase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CORE_E6500 */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_AddressBusStreamingEnable   @Description   Enables address bus streaming on the CCB.                  This setting, along with the ECM streaming configuration                 parameters, enables address bus streaming on the CCB.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_AddressBusStreamingEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_AddressBusStreamingDisable   @Description   Disables address bus streaming on the CCB.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_AddressBusStreamingDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_AddressBroadcastEnable   @Description   Enables address broadcast.                  The e500 broadcasts cache management instructions (dcbst, dcblc                 (CT = 1), icblc (CT = 1), dcbf, dcbi, mbar, msync, tlbsync, icbi)                 based on ABE. ABE must be set to allow management of external                 L2 caches.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_AddressBroadcastEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_AddressBroadcastDisable   @Description   Disables address broadcast.                  The e500 broadcasts cache management instructions (dcbst, dcblc                 (CT = 1), icblc (CT = 1), dcbf, dcbi, mbar, msync, tlbsync, icbi)                 based on ABE. ABE must be set to allow management of external                 L2 caches.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_AddressBroadcastDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_IsTaskletSupported   @Description   Checks if tasklets are supported by the e500 interrupt handler.   @Retval        TRUE    - Tasklets are supported.  @Retval        FALSE   - Tasklets are not supported. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|bool
name|E500_IsTaskletSupported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_EnableTimeBase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_DisableTimeBase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|E500_GetTimeBaseTime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|E500_GenericIntrInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|E500_SetIntr
parameter_list|(
name|int
name|ppcIntrSrc
parameter_list|,
name|void
function_decl|(
modifier|*
name|Isr
function_decl|)
parameter_list|(
name|t_Handle
name|handle
parameter_list|)
parameter_list|,
name|t_Handle
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|E500_ClearIntr
parameter_list|(
name|int
name|ppcIntrSrc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_GenericIntrHandler   @Description   This is the general e500 interrupt handler.                  It is called by the main assembly interrupt handler                 when an exception occurs and no other function has been                 assigned to this exception.   @Param         intrEntry   - (In) The exception interrupt vector entry. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|E500_GenericIntrHandler
parameter_list|(
name|uint32_t
name|intrEntry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CriticalIntr   @Description   This is the specific critical e500 interrupt handler.                  It is called by the main assembly interrupt handler                 when an critical interrupt.   @Param         intrEntry   - (In) The exception interrupt vector entry. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CriticalIntr
parameter_list|(
name|uint32_t
name|intrEntry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_GetId   @Description   Returns the core ID in the system.   @Return        Core ID. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|E500_GetId
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_TestAndSet   @Description   This routine tries to atomically test-and-set an integer                 in memory to a non-zero value.                  The memory will be set only if it is tested as zero, in which                 case the routine returns the new non-zero value; otherwise the                 routine returns zero.   @Param[in]     p - pointer to a volatile int in memory, on which test-and-set                     operation should be made.   @Retval        Zero        - Operation failed - memory was already set.  @Retval        Non-zero    - Operation succeeded - memory has been set. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|E500_TestAndSet
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_MemoryBarrier   @Description   This routine will cause the core to stop executing any commands                 until all previous memory read/write commands are completely out                 of the core's pipeline.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|E500_MemoryBarrier
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|CORE_E500V2
asm|__asm__ ("mbar 1");
else|#
directive|else
comment|/* CORE_E500V2 */
comment|/**** ERRATA WORK AROUND START ****/
comment|/* ERRATA num:  CPU1 */
comment|/* Description: "mbar MO = 1" instruction fails to order caching-inhibited                     guarded loads and stores. */
comment|/* "msync" instruction is used instead */
asm|__asm__ ("msync");
comment|/**** ERRATA WORK AROUND END ****/
endif|#
directive|endif
comment|/* CORE_E500V2 */
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      E500_InstructionSync   @Description   This routine will cause the core to wait for previous instructions                 (including any interrupts they generate) to complete before the                 synchronization command executes, which purges all instructions                 from the processor's pipeline and refetches the next instruction.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|E500_InstructionSync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__ ("isync");
block|}
end_function

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of E500_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of E500_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __E500V2_EXT_H */
end_comment

end_unit

