begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          xx_ext.h   @Description   Prototypes, externals and typedefs for system-supplied                 (external) routines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XX_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__XX_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"xx_common.h"
end_include

begin_include
include|#
directive|include
file|"part_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         xx_id  XX Interface (System call hooks)   @Description   Prototypes, externals and typedefs for system-supplied                 (external) routines   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_XX_MALLOC
end_ifdef

begin_function_decl
name|void
modifier|*
name|XX_MallocDebug
parameter_list|(
name|uint32_t
name|size
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|XX_MallocSmartDebug
parameter_list|(
name|uint32_t
name|size
parameter_list|,
name|int
name|memPartitionId
parameter_list|,
name|uint32_t
name|alignment
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XX_Malloc
parameter_list|(
name|sz
parameter_list|)
define|\
value|XX_MallocDebug((sz), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|XX_MallocSmart
parameter_list|(
name|sz
parameter_list|,
name|memt
parameter_list|,
name|al
parameter_list|)
define|\
value|XX_MallocSmartDebug((sz), (memt), (al), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG_XX_MALLOC */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_Malloc   @Description   allocates contiguous block of memory.   @Param[in]     size - Number of bytes to allocate.   @Return        The address of the newly allocated block on success, NULL on failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
modifier|*
name|XX_Malloc
parameter_list|(
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_MallocSmart   @Description   Allocates contiguous block of memory in a specified                 alignment and from the specified segment.   @Param[in]     size            - Number of bytes to allocate.  @Param[in]     memPartitionId  - Memory partition ID; The value zero must                                   be mapped to the default heap partition.  @Param[in]     alignment       - Required memory alignment (in bytes).   @Return        The address of the newly allocated block on success, NULL on failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
modifier|*
name|XX_MallocSmart
parameter_list|(
name|uint32_t
name|size
parameter_list|,
name|int
name|memPartitionId
parameter_list|,
name|uint32_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XX_MallocSmartInit
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
comment|/* not DEBUG_XX_MALLOC */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FreeSmart   @Description   Frees the memory block pointed to by "p".                 Only for memory allocated by XX_MallocSmart   @Param[in]     p_Memory - pointer to the memory block.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_FreeSmart
parameter_list|(
name|void
modifier|*
name|p_Memory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_Free   @Description   frees the memory block pointed to by "p".   @Param[in]     p_Memory - pointer to the memory block.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_Free
parameter_list|(
name|void
modifier|*
name|p_Memory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_Print   @Description   print a string.   @Param[in]     str - string to print.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_Print
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_SetIntr   @Description   Set an interrupt service routine for a specific interrupt source.   @Param[in]     irq     - Interrupt ID (system-specific number).  @Param[in]     f_Isr   - Callback routine that will be called when the interrupt occurs.  @Param[in]     handle  - The argument for the user callback routine.   @Return        E_OK on success; error code otherwise.. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_SetIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|,
name|t_Isr
modifier|*
name|f_Isr
parameter_list|,
name|t_Handle
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FreeIntr   @Description   Free a specific interrupt and a specific callback routine.   @Param[in]     irq - Interrupt ID (system-specific number).   @Return        E_OK on success; error code otherwise.. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_FreeIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_EnableIntr   @Description   Enable a specific interrupt.   @Param[in]     irq - Interrupt ID (system-specific number).   @Return        E_OK on success; error code otherwise.. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_EnableIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_DisableIntr   @Description   Disable a specific interrupt.   @Param[in]     irq - Interrupt ID (system-specific number).   @Return        E_OK on success; error code otherwise.. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_DisableIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_DisableAllIntr   @Description   Disable all interrupts by masking them at the CPU.   @Return        A value that represents the interrupts state before the                 operation, and should be passed to the matching                 XX_RestoreAllIntr() call. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|XX_DisableAllIntr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_RestoreAllIntr   @Description   Restore previous state of interrupts level at the CPU.   @Param[in]     flags - A value that represents the interrupts state to restore,                         as returned by the matching call for XX_DisableAllIntr().   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_RestoreAllIntr
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|XX_PreallocAndBindIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|,
name|unsigned
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|XX_DeallocIntr
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_Exit   @Description   Stop execution and report status (where it is applicable)   @Param[in]     status - exit status */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_Exit
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                        Tasklet Service Routines                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|t_Handle
name|t_TaskletHandle
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_InitTasklet   @Description   Create and initialize a tasklet object.   @Param[in]     routine - A routine to be ran as a tasklet.  @Param[in]     data    - An argument to pass to the tasklet.   @Return        Tasklet handle is returned on success. NULL is returned otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_TaskletHandle
name|XX_InitTasklet
parameter_list|(
name|void
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FreeTasklet   @Description   Free a tasklet object.   @Param[in]     h_Tasklet - A handle to a tasklet to be free.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_FreeTasklet
parameter_list|(
name|t_TaskletHandle
name|h_Tasklet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_ScheduleTask   @Description   Schedule a tasklet object.   @Param[in]     h_Tasklet - A handle to a tasklet to be scheduled.  @Param[in]     immediate - Indicate whether to schedule this tasklet on                             the immediate queue or on the delayed one.   @Return        0 - on success. Error code - otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|XX_ScheduleTask
parameter_list|(
name|t_TaskletHandle
name|h_Tasklet
parameter_list|,
name|int
name|immediate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FlushScheduledTasks   @Description   Flush all tasks there are in the scheduled tasks queue.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_FlushScheduledTasks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_TaskletIsQueued   @Description   Check if task is queued.   @Param[in]     h_Tasklet - A handle to a tasklet to be scheduled.   @Return        1 - task is queued. 0 - otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|XX_TaskletIsQueued
parameter_list|(
name|t_TaskletHandle
name|h_Tasklet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_SetTaskletData   @Description   Set data to a scheduled task. Used to change data of already                 scheduled task.   @Param[in]     h_Tasklet - A handle to a tasklet to be scheduled.  @Param[in]     data      - Data to be set. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_SetTaskletData
parameter_list|(
name|t_TaskletHandle
name|h_Tasklet
parameter_list|,
name|t_Handle
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_GetTaskletData   @Description   Get the data of scheduled task.   @Param[in]     h_Tasklet - A handle to a tasklet to be scheduled.   @Return        handle to the data of the task. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|XX_GetTaskletData
parameter_list|(
name|t_TaskletHandle
name|h_Tasklet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_BottomHalf   @Description   Bottom half implementation, invoked by the interrupt handler.                  This routine handles all bottom-half tasklets with interrupts                 enabled.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_BottomHalf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                        Spinlock Service Routines                          */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_InitSpinlock   @Description   Creates a spinlock.   @Return        Spinlock handle is returned on success; NULL otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|XX_InitSpinlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FreeSpinlock   @Description   Frees the memory allocated for the spinlock creation.   @Param[in]     h_Spinlock - A handle to a spinlock.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_FreeSpinlock
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_LockSpinlock   @Description   Locks a spinlock.   @Param[in]     h_Spinlock - A handle to a spinlock.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_LockSpinlock
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_UnlockSpinlock   @Description   Unlocks a spinlock.   @Param[in]     h_Spinlock - A handle to a spinlock.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_UnlockSpinlock
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_LockIntrSpinlock   @Description   Locks a spinlock (interrupt safe).   @Param[in]     h_Spinlock - A handle to a spinlock.   @Return        A value that represents the interrupts state before the                 operation, and should be passed to the matching                 XX_UnlockIntrSpinlock() call. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|XX_LockIntrSpinlock
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_UnlockIntrSpinlock   @Description   Unlocks a spinlock (interrupt safe).   @Param[in]     h_Spinlock  - A handle to a spinlock.  @Param[in]     intrFlags   - A value that represents the interrupts state to                               restore, as returned by the matching call for                               XX_LockIntrSpinlock().   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_UnlockIntrSpinlock
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|,
name|uint32_t
name|intrFlags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                        Timers Service Routines                            */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_CurrentTime   @Description   Returns current system time.   @Return        Current system time (in milliseconds). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|XX_CurrentTime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_CreateTimer   @Description   Creates a timer.   @Return        Timer handle is returned on success; NULL otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|XX_CreateTimer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_FreeTimer   @Description   Frees the memory allocated for the timer creation.   @Param[in]     h_Timer - A handle to a timer.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_FreeTimer
parameter_list|(
name|t_Handle
name|h_Timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_StartTimer   @Description   Starts a timer.                  The user can select to start the timer as periodic timer or as                 one-shot timer. The user should provide a callback routine that                 will be called when the timer expires.   @Param[in]     h_Timer         - A handle to a timer.  @Param[in]     msecs           - Timer expiration period (in milliseconds).  @Param[in]     periodic        - TRUE for a periodic timer;                                   FALSE for a one-shot timer..  @Param[in]     f_TimerExpired  - A callback routine to be called when the                                   timer expires.  @Param[in]     h_Arg           - The argument to pass in the timer-expired                                   callback routine.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_StartTimer
parameter_list|(
name|t_Handle
name|h_Timer
parameter_list|,
name|uint32_t
name|msecs
parameter_list|,
name|bool
name|periodic
parameter_list|,
name|void
function_decl|(
modifier|*
name|f_TimerExpired
function_decl|)
parameter_list|(
name|t_Handle
name|h_Arg
parameter_list|)
parameter_list|,
name|t_Handle
name|h_Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_StopTimer   @Description   Frees the memory allocated for the timer creation.   @Param[in]     h_Timer - A handle to a timer.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_StopTimer
parameter_list|(
name|t_Handle
name|h_Timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_ModTimer   @Description   Updates the expiration time of a timer.                  This routine adds the given time to the current system time,                 and sets this value as the new expiration time of the timer.   @Param[in]     h_Timer - A handle to a timer.  @Param[in]     msecs   - The new interval until timer expiration                           (in milliseconds).   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_ModTimer
parameter_list|(
name|t_Handle
name|h_Timer
parameter_list|,
name|uint32_t
name|msecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_Sleep   @Description   Non-busy wait until the desired time (in milliseconds) has passed.   @Param[in]     msecs - The requested sleep time (in milliseconds).   @Return        Zero if the requested time has elapsed; Otherwise, the value                 returned will be the unslept amount) in milliseconds.   @Cautions      This routine enables interrupts during its wait time. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|XX_Sleep
parameter_list|(
name|uint32_t
name|msecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_UDelay   @Description   Busy-wait until the desired time (in microseconds) has passed.   @Param[in]     usecs - The requested delay time (in microseconds).   @Return        None.   @Cautions      It is highly unrecommended to call this routine during interrupt                 time, because the system time may not be updated properly during                 the delay loop. The behavior of this routine during interrupt                 time is unexpected. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|XX_UDelay
parameter_list|(
name|uint32_t
name|usecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                         Other Service Routines                            */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_PhysToVirt   @Description   Translates a physical address to the matching virtual address.   @Param[in]     addr - The physical address to translate.   @Return        Virtual address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
modifier|*
name|XX_PhysToVirt
parameter_list|(
name|physAddress_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_VirtToPhys   @Description   Translates a virtual address to the matching physical address.   @Param[in]     addr - The virtual address to translate.   @Return        Physical address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|physAddress_t
name|XX_VirtToPhys
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         xx_ipc  XX Inter-Partition-Communication API   @Description   The following API is to be used when working with multiple                 partitions configuration.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|XX_IPC_MAX_ADDR_NAME_LENGTH
value|16
end_define

begin_comment
comment|/**< Maximum length of an endpoint name string;                                                     The IPC service can use this constant to limit                                                     the storage space for IPC endpoint names. */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_IpcMsgCompletion   @Description   Callback function used upon IPC non-blocking transaction completion                 to return message buffer to the caller and to forward reply if available.                  This callback function may be attached by the source endpoint to any outgoing                 IPC message to indicate a non-blocking send (see also XX_IpcSendMessage() routine).                 Upon completion of an IPC transaction (consisting of a message and an optional reply),                 the IPC service invokes this callback routine to return the message buffer to the sender                 and to provide the received reply, if requested.                  User provides this function. Driver invokes it.   @Param[in]     h_Module        - Abstract handle to the sending module -  the same handle as was passed                                   in the XX_IpcSendMessage() function; This handle is typically used to point                                   to the internal data structure of the source endpoint.  @Param[in]     p_Msg           - Pointer to original (sent) message buffer;                                   The source endpoint can free (or reuse) this buffer when message                                   completion callback is called.  @Param[in]     p_Reply         - Pointer to (received) reply buffer;                                   This pointer is the same as was provided by the source endpoint in                                   XX_IpcSendMessage().  @Param[in]     replyLength     - Length (in bytes) of actual data in the reply buffer.  @Param[in]     status          - Completion status - E_OK or failure indication, e.g. IPC transaction completion                                   timeout.   @Return        None  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_IpcMsgCompletion
function_decl|)
parameter_list|(
name|t_Handle
name|h_Module
parameter_list|,
name|uint8_t
modifier|*
name|p_Msg
parameter_list|,
name|uint8_t
modifier|*
name|p_Reply
parameter_list|,
name|uint32_t
name|replyLength
parameter_list|,
name|t_Error
name|status
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_IpcMsgHandler   @Description   Callback function used as IPC message handler.                  The IPC service invokes message handlers for each IPC message received.                 The actual function pointer should be registered by each destination endpoint                 via the XX_IpcRegisterMsgHandler() routine.                  User provides this function. Driver invokes it.   @Param[in]     h_Module        - Abstract handle to the message handling module -  the same handle as                                   was passed in the XX_IpcRegisterMsgHandler() function; this handle is                                   typically used to point to the internal data structure of the destination                                   endpoint.  @Param[in]     p_Msg           - Pointer to message buffer with data received from peer.  @Param[in]     msgLength       - Length (in bytes) of message data.  @Param[in]     p_Reply         - Pointer to reply buffer, to be filled by the message handler and then sent                                   by the IPC service;                                   The reply buffer is allocated by the IPC service with size equals to the                                   replyLength parameter provided in message handler registration (see                                   XX_IpcRegisterMsgHandler() function);                                   If replyLength was initially specified as zero during message handler registration,                                   the IPC service may set this pointer to NULL and assume that a reply is not needed;                                   The IPC service is also responsible for freeing the reply buffer after the                                   reply has been sent or dismissed.  @Param[in,out] p_ReplyLength   - Pointer to reply length, which has a dual role in this function:                                   [In] equals the replyLength parameter provided in message handler                                   registration (see XX_IpcRegisterMsgHandler() function), and                                   [Out] should be updated by message handler to the actual reply length; if                                   this value is set to zero, the IPC service must assume that a reply should                                   not be sent;                                   Note: If p_Reply is not NULL, p_ReplyLength must not be NULL as well.   @Return        E_OK on success; Error code otherwise.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|t_Error
function_decl|(
name|t_IpcMsgHandler
function_decl|)
parameter_list|(
name|t_Handle
name|h_Module
parameter_list|,
name|uint8_t
modifier|*
name|p_Msg
parameter_list|,
name|uint32_t
name|msgLength
parameter_list|,
name|uint8_t
modifier|*
name|p_Reply
parameter_list|,
name|uint32_t
modifier|*
name|p_ReplyLength
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_IpcRegisterMsgHandler   @Description   IPC mailbox registration.                  This function is used for registering an IPC message handler in the IPC service.                 This function is called by each destination endpoint to indicate that it is ready                 to handle incoming messages. The IPC service invokes the message handler upon receiving                 a message addressed to the specified destination endpoint.   @Param[in]     addr                - The address name string associated with the destination endpoint;                                       This address must be unique across the IPC service domain to ensure                                       correct message routing.  @Param[in]     f_MsgHandler        - Pointer to the message handler callback for processing incoming                                       message; invoked by the IPC service upon receiving a message                                       addressed to the destination endpoint specified by the addr                                       parameter.  @Param[in]     h_Module            - Abstract handle to the message handling module, passed unchanged                                       to f_MsgHandler callback function.  @Param[in]     replyLength         - The maximal data length (in bytes) of any reply that the specified message handler                                       may generate; the IPC service provides the message handler with buffer                                       for reply according to the length specified here (refer also to the description                                       of #t_IpcMsgHandler callback function type);                                       This size shall be zero if the message handler never generates replies.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_IpcRegisterMsgHandler
parameter_list|(
name|char
name|addr
index|[
name|XX_IPC_MAX_ADDR_NAME_LENGTH
index|]
parameter_list|,
name|t_IpcMsgHandler
modifier|*
name|f_MsgHandler
parameter_list|,
name|t_Handle
name|h_Module
parameter_list|,
name|uint32_t
name|replyLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_IpcUnregisterMsgHandler   @Description   Release IPC mailbox routine.                   This function is used for unregistering an IPC message handler from the IPC service.                  This function is called by each destination endpoint to indicate that it is no longer                  capable of handling incoming messages.   @Param[in]     addr          - The address name string associated with the destination endpoint;                                 This address is the same as was used when the message handler was                                 registered via XX_IpcRegisterMsgHandler().   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_IpcUnregisterMsgHandler
parameter_list|(
name|char
name|addr
index|[
name|XX_IPC_MAX_ADDR_NAME_LENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_IpcInitSession   @Description   This function is used for creating an IPC session between the source endpoint                 and the destination endpoint.                  The actual implementation and representation of a session is left for the IPC service.                 The function returns an abstract handle to the created session. This handle shall be used                 by the source endpoint in subsequent calls to XX_IpcSendMessage().                 The IPC service assumes that before this function is called, no messages are sent from                 the specified source endpoint to the specified destination endpoint.                  The IPC service may use a connection-oriented approach or a connectionless approach (or both)                 as described below.                  @par Connection-Oriented Approach                  The IPC service may implement a session in a connection-oriented approach -  when this function is called,                 the IPC service should take the necessary steps to bring up a source-to-destination channel for messages                 and a destination-to-source channel for replies. The returned handle should represent the internal                 representation of these channels.                  @par Connectionless Approach                  The IPC service may implement a session in a connectionless approach -  when this function is called, the                 IPC service should not perform any particular steps, but it must store the pair of source and destination                 addresses in some session representation and return it as a handle. When XX_IpcSendMessage() shall be                 called, the IPC service may use this handle to provide the necessary identifiers for routing the messages                 through the connectionless medium.   @Param[in]     destAddr      - The address name string associated with the destination endpoint.  @Param[in]     srcAddr       - The address name string associated with the source endpoint.   @Return        Abstract handle to the initialized session, or NULL on error. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|XX_IpcInitSession
parameter_list|(
name|char
name|destAddr
index|[
name|XX_IPC_MAX_ADDR_NAME_LENGTH
index|]
parameter_list|,
name|char
name|srcAddr
index|[
name|XX_IPC_MAX_ADDR_NAME_LENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_IpcFreeSession   @Description   This function is used for terminating an existing IPC session between a source endpoint                 and a destination endpoint.                  The IPC service assumes that after this function is called, no messages shall be sent from                 the associated source endpoint to the associated destination endpoint.   @Param[in]     h_Session      - Abstract handle to the IPC session -  the same handle as was originally                                  returned by the XX_IpcInitSession() function.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_IpcFreeSession
parameter_list|(
name|t_Handle
name|h_Session
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      XX_IpcSendMessage   @Description   IPC message send routine.                  This function may be used by a source endpoint to send an IPC message to a destination                 endpoint. The source endpoint cannot send a message to the destination endpoint without                 first initiating a session with that destination endpoint via XX_IpcInitSession() routine.                  The source endpoint must provide the buffer pointer and length of the outgoing message.                 Optionally, it may also provide a buffer for an expected reply. In the latter case, the                 transaction is not considered complete by the IPC service until the reply has been received.                 If the source endpoint does not provide a reply buffer, the transaction is considered                 complete after the message has been sent. The source endpoint must keep the message (and                 optional reply) buffers valid until the transaction is complete.                  @par Non-blocking mode                  The source endpoint may request a non-blocking send by providing a non-NULL pointer to a message                 completion callback function (f_Completion). Upon completion of the IPC transaction (consisting of a                 message and an optional reply), the IPC service invokes this callback routine to return the message                 buffer to the sender and to provide the received reply, if requested.                  @par Blocking mode                  The source endpoint may request a blocking send by setting f_Completion to NULL. The function is                 expected to block until the IPC transaction is complete -  either the reply has been received or (if no reply                 was requested) the message has been sent.   @Param[in]     h_Session       - Abstract handle to the IPC session -  the same handle as was originally                                   returned by the XX_IpcInitSession() function.  @Param[in]     p_Msg           - Pointer to message buffer to send.  @Param[in]     msgLength       - Length (in bytes) of actual data in the message buffer.  @Param[in]     p_Reply         - Pointer to reply buffer -  if this buffer is not NULL, the IPC service                                   fills this buffer with the received reply data;                                   In blocking mode, the reply data must be valid when the function returns;                                   In non-blocking mode, the reply data is valid when f_Completion is called;                                   If this pointer is NULL, no reply is expected.  @Param[in,out] p_ReplyLength   - Pointer to reply length, which has a dual role in this function:                                   [In] specifies the maximal length (in bytes) of the reply buffer pointed by                                   p_Reply, and                                   [Out] in non-blocking mode this value is updated by the IPC service to the                                   actual reply length (in bytes).  @Param[in]     f_Completion    - Pointer to a completion callback to be used in non-blocking send mode;                                   The completion callback is invoked by the IPC service upon                                   completion of the IPC transaction (consisting of a message and an optional                                   reply);                                   If this pointer is NULL, the function is expected to block until the IPC                                   transaction is complete.  @Param[in]     h_Arg           - Abstract handle to the sending module; passed unchanged to the f_Completion                                   callback function as the first argument.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|XX_IpcSendMessage
parameter_list|(
name|t_Handle
name|h_Session
parameter_list|,
name|uint8_t
modifier|*
name|p_Msg
parameter_list|,
name|uint32_t
name|msgLength
parameter_list|,
name|uint8_t
modifier|*
name|p_Reply
parameter_list|,
name|uint32_t
modifier|*
name|p_ReplyLength
parameter_list|,
name|t_IpcMsgCompletion
modifier|*
name|f_Completion
parameter_list|,
name|t_Handle
name|h_Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of xx_ipc group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of xx_id group */
end_comment

begin_function_decl
name|void
name|XX_PortalSetInfo
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XX_FmanFixIntr
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XX_EXT_H */
end_comment

end_unit

