begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM Periodic SMI Library.    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiSmm.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SmmPeriodicTimerDispatch2.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/SynchronizationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/TimerLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmmServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmmPeriodicSmiLib.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define the number of periodic SMI handler entries that should be allocated to the list
end_comment

begin_comment
comment|/// of free periodic SMI handlers when the list of free periodic SMI handlers is empty.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PERIODIC_SMI_LIBRARY_ALLOCATE_SIZE
value|0x08
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signature for a PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT structure
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_SIGNATURE
value|SIGNATURE_32 ('P', 'S', 'M', 'I')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure that contains state information for an enabled periodic SMI handler
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Signature value that must be set to PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_SIGNATURE
comment|///
name|UINT32
name|Signature
decl_stmt|;
comment|///
comment|/// The link entry to be inserted to the list of periodic SMI handlers.
comment|///
name|LIST_ENTRY
name|Link
decl_stmt|;
comment|///
comment|/// The dispatch function to called to invoke an enabled periodic SMI handler.
comment|///
name|PERIODIC_SMI_LIBRARY_HANDLER
name|DispatchFunction
decl_stmt|;
comment|///
comment|/// The context to pass into DispatchFunction
comment|///
name|VOID
modifier|*
name|Context
decl_stmt|;
comment|///
comment|/// The tick period in 100 ns units that DispatchFunction should be called.
comment|///
name|UINT64
name|TickPeriod
decl_stmt|;
comment|///
comment|/// The Cpu number that is required to execute DispatchFunction.  If Cpu is
comment|/// set to PERIODIC_SMI_LIBRARY_ANY_CPU, then DispatchFunction may be executed
comment|/// on any CPU.
comment|///
name|UINTN
name|Cpu
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the stack allocated for a periodic SMI handler.
comment|/// This value must be a multiple of EFI_PAGE_SIZE.
comment|///
name|UINTN
name|StackSize
decl_stmt|;
comment|///
comment|/// A pointer to the stack allocated using AllocatePages().  This field will
comment|/// be NULL if StackSize is 0.
comment|///
name|VOID
modifier|*
name|Stack
decl_stmt|;
comment|///
comment|/// Spin lock used to wait for an AP to complete the execution of a periodic SMI handler
comment|///
name|SPIN_LOCK
name|DispatchLock
decl_stmt|;
comment|///
comment|/// The rate in Hz of the performance counter that is used to measure the
comment|/// amount of time that a periodic SMI handler executes.
comment|///
name|UINT64
name|PerfomanceCounterRate
decl_stmt|;
comment|///
comment|/// The start count value of the performance counter that is used to measure
comment|/// the amount of time that a periodic SMI handler executes.
comment|///
name|UINT64
name|PerfomanceCounterStartValue
decl_stmt|;
comment|///
comment|/// The end count value of the performance counter that is used to measure
comment|/// the amount of time that a periodic SMI handler executes.
comment|///
name|UINT64
name|PerfomanceCounterEndValue
decl_stmt|;
comment|///
comment|/// The context record passed into the Register() function of the SMM Periodic
comment|/// Timer Dispatch Protocol when a periodic SMI handler is enabled.
comment|///
name|EFI_SMM_PERIODIC_TIMER_REGISTER_CONTEXT
name|RegisterContext
decl_stmt|;
comment|///
comment|/// The handle returned from the Register() function of the SMM Periodic
comment|/// Timer Dispatch Protocol when a periodic SMI handler is enabled.
comment|///
name|EFI_HANDLE
name|DispatchHandle
decl_stmt|;
comment|///
comment|/// The total number of performance counter ticks that the periodic SMI handler
comment|/// has been executing in its current invocation.
comment|///
name|UINT64
name|DispatchTotalTime
decl_stmt|;
comment|///
comment|/// The performance counter value that was captured the last time that the
comment|/// periodic SMI handler called PeriodcSmiExecutionTime().  This allows the
comment|/// time value returned by PeriodcSmiExecutionTime() to be accurate even when
comment|/// the performance counter rolls over.
comment|///
name|UINT64
name|DispatchCheckPointTime
decl_stmt|;
comment|///
comment|/// Buffer used to save the context when control is transfer from this library
comment|/// to an enabled periodic SMI handler.  This saved context is used when the
comment|/// periodic SMI handler exits or yields.
comment|///
name|BASE_LIBRARY_JUMP_BUFFER
name|DispatchJumpBuffer
decl_stmt|;
comment|///
comment|/// Flag that is set to TRUE when a periodic SMI handler requests to yield
comment|/// using PeriodicSmiYield().  When this flag IS TRUE, YieldJumpBuffer is
comment|/// valid.  When this flag is FALSE, YieldJumpBuffer is not valid.
comment|///
name|BOOLEAN
name|YieldFlag
decl_stmt|;
comment|///
comment|/// Buffer used to save the context when a periodic SMI handler requests to
comment|/// yield using PeriodicSmiYield().  This context is used to resume the
comment|/// execution of a periodic SMI handler the next time control is transferd
comment|/// to the periodic SMI handler that yielded.
comment|///
name|BASE_LIBRARY_JUMP_BUFFER
name|YieldJumpBuffer
decl_stmt|;
comment|///
comment|/// The amount of time, in 100 ns units, that have elapsed since the last
comment|/// time the periodic SMI handler was invoked.
comment|///
name|UINT64
name|ElapsedTime
decl_stmt|;
block|}
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/**  Macro that returns a pointer to a PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT   structure based on a pointer to a RegisterContext field.  **/
end_comment

begin_define
define|#
directive|define
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_REGISTER_CONTEXT
parameter_list|(
name|a
parameter_list|)
define|\
value|CR (                                                                \     a,                                                                \     PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT,                             \     RegisterContext,                                                  \     PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_SIGNATURE                    \     )
end_define

begin_comment
comment|/**  Macro that returns a pointer to a PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT   structure based on a pointer to a Link field.  **/
end_comment

begin_define
define|#
directive|define
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_LINK
parameter_list|(
name|a
parameter_list|)
define|\
value|CR (                                                                \     a,                                                                \     PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT,                             \     Link,                                                             \     PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_SIGNATURE                    \     )
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pointer to the SMM Periodic Timer Disatch Protocol that was located in the constuctor.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
modifier|*
name|gSmmPeriodicTimerDispatch2
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pointer to a table of supported periodic SMI tick periods in 100 ns units
end_comment

begin_comment
comment|/// sorted from largest to smallest terminated by a tick period value of 0.
end_comment

begin_comment
comment|/// This table is allocated using AllocatePool() in the constructor and filled
end_comment

begin_comment
comment|/// in based on the values returned from the SMM Periodic Timer Dispatch 2 Protocol
end_comment

begin_comment
comment|/// function GetNextShorterInterval().
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|UINT64
modifier|*
name|gSmiTickPeriodTable
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Linked list of free periodic SMI handlers that this library can use.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|LIST_ENTRY
name|gFreePeriodicSmiLibraryHandlers
init|=
name|INITIALIZE_LIST_HEAD_VARIABLE
argument_list|(
name|gFreePeriodicSmiLibraryHandlers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Linked list of periodic SMI handlers that this library is currently managing.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|LIST_ENTRY
name|gPeriodicSmiLibraryHandlers
init|=
name|INITIALIZE_LIST_HEAD_VARIABLE
argument_list|(
name|gPeriodicSmiLibraryHandlers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pointer to the periodic SMI handler that is currently being executed.
end_comment

begin_comment
comment|/// Is set to NULL if no periodic SMI handler is currently being executed.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|gActivePeriodicSmiLibraryHandler
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   Internal worker function that returns a pointer to the    PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT structure associated with the periodic    SMI handler that is currently being executed.  If a periodic SMI handler is    not currently being executed, the NULL is returned.      @retval  NULL   A periodic SMI handler is not currently being executed.   @retval  other  Pointer to the PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT                   associated with the active periodic SMI handler.    **/
end_comment

begin_function
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|GetActivePeriodicSmiLibraryHandler
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|gActivePeriodicSmiLibraryHandler
return|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that returns a pointer to the    PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT structure associated with the    DispatchHandle that was returned when the periodic SMI handler was enabled   with PeriodicSmiEnable().  If DispatchHandle is NULL, then the active    periodic SMI handler is returned.  If DispatchHandle is NULL and there is   no active periodic SMI handler, then NULL is returned.      @param[in] DispatchHandle  DispatchHandle that was returned when the periodic                               SMI handler was enabled with PeriodicSmiEnable().                                This is an optional parameter that may be NULL.                              If this parameter is NULL, then the active periodic                              SMI handler is returned.      @retval  NULL   DispatchHandle is NULL and there is no active periodic SMI                    handler.   @retval  NULL   DispatchHandle does not match any of the periodic SMI handlers                   that have been enabled with PeriodicSmiEnable().   @retval  other  Pointer to the PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT                   associated with the DispatchHandle.    **/
end_comment

begin_function
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|LookupPeriodicSmiLibraryHandler
parameter_list|(
name|IN
name|EFI_HANDLE
name|DispatchHandle
name|OPTIONAL
parameter_list|)
block|{
name|LIST_ENTRY
modifier|*
name|Link
decl_stmt|;
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// If DispatchHandle is NULL, then return the active periodic SMI handler
comment|//
if|if
condition|(
name|DispatchHandle
operator|==
name|NULL
condition|)
block|{
return|return
name|GetActivePeriodicSmiLibraryHandler
argument_list|()
return|;
block|}
comment|//
comment|// Search the periodic SMI handler entries for a a matching DispatchHandle
comment|//
for|for
control|(
name|Link
operator|=
name|GetFirstNode
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|)
init|;
operator|!
name|IsNull
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|,
name|Link
argument_list|)
condition|;
name|Link
operator|=
name|GetNextNode
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|,
name|Link
argument_list|)
control|)
block|{
name|PeriodicSmiLibraryHandler
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_LINK
argument_list|(
name|Link
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|==
name|DispatchHandle
condition|)
block|{
return|return
name|PeriodicSmiLibraryHandler
return|;
block|}
block|}
comment|//
comment|// No entries match DispatchHandle, so return NULL
comment|//
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that sets that active periodic SMI handler based on    the Context used when the periodic SMI handler was registered with the    SMM Periodic Timer Dispatch 2 Protocol.  If Context is NULL, then the    state is updated to show that there is not active periodic SMI handler.   A pointer to the active PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT structure    is returned.      @retval  NULL   Context is NULL.   @retval  other  Pointer to the PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT                   associated with Context.    **/
end_comment

begin_function
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|SetActivePeriodicSmiLibraryHandler
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|)
block|{
if|if
condition|(
name|Context
operator|==
name|NULL
condition|)
block|{
name|gActivePeriodicSmiLibraryHandler
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|gActivePeriodicSmiLibraryHandler
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_REGISTER_CONTEXT
argument_list|(
name|Context
argument_list|)
expr_stmt|;
block|}
return|return
name|gActivePeriodicSmiLibraryHandler
return|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that moves the specified periodic SMI handler from the   list of managed periodic SMI handlers to the list of free periodic SMI handlers.    @param[in] PeriodicSmiLibraryHandler  Pointer to the periodic SMI handler to be reclaimed. **/
end_comment

begin_function
name|VOID
name|ReclaimPeriodicSmiLibraryHandler
parameter_list|(
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|==
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|!=
name|NULL
condition|)
block|{
name|FreePages
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
argument_list|,
name|EFI_SIZE_TO_PAGES
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
argument_list|)
argument_list|)
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|=
name|NULL
expr_stmt|;
block|}
name|RemoveEntryList
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|Link
argument_list|)
expr_stmt|;
name|InsertHeadList
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|Link
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Add the additional entries to the list of free periodic SMI handlers.   The function is assumed to be called only when the list of free periodic SMI   handlers is empty.    @retval TRUE  The additional entries were added.   @retval FALSE There was no available resource for the additional entries. **/
end_comment

begin_function
name|BOOLEAN
name|EnlargeFreePeriodicSmiLibraryHandlerList
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Index
decl_stmt|;
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// Add the entries to the list
comment|//
for|for
control|(
name|Index
operator|=
literal|0
init|;
name|Index
operator|<
name|PERIODIC_SMI_LIBRARY_ALLOCATE_SIZE
condition|;
name|Index
operator|++
control|)
block|{
name|PeriodicSmiLibraryHandler
operator|=
name|AllocatePool
argument_list|(
sizeof|sizeof
argument_list|(
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
break|break;
block|}
name|PeriodicSmiLibraryHandler
operator|->
name|Signature
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_SIGNATURE
expr_stmt|;
name|InsertHeadList
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|Link
argument_list|)
expr_stmt|;
block|}
return|return
call|(
name|BOOLEAN
call|)
argument_list|(
name|Index
operator|>
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that returns a free entry for a new periodic   SMI handler.  If no free entries are available, then additional   entries are allocated.      @retval  NULL   There are not enough resources available to to allocate a free entry.   @retval  other  Pointer to a free PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT structure.    **/
end_comment

begin_function
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|FindFreePeriodicSmiLibraryHandler
parameter_list|(
name|VOID
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
if|if
condition|(
name|IsListEmpty
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|EnlargeFreePeriodicSmiLibraryHandlerList
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
block|}
comment|//
comment|// Get one from the list of free periodic SMI handlers.
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_LINK
argument_list|(
name|GetFirstNode
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|)
argument_list|)
expr_stmt|;
name|RemoveEntryList
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|Link
argument_list|)
expr_stmt|;
name|InsertTailList
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|Link
argument_list|)
expr_stmt|;
return|return
name|PeriodicSmiLibraryHandler
return|;
block|}
end_function

begin_comment
comment|/**   This function returns a pointer to a table of supported periodic   SMI tick periods in 100 ns units sorted from largest to smallest.     The table contains a array of UINT64 values terminated by a tick    period value of 0.  The returned table must be treated as read-only   data and must not be freed.      @return  A pointer to a table of UINT64 tick period values in             100ns units sorted from largest to smallest terminated             by a tick period of 0.    **/
end_comment

begin_function
name|UINT64
modifier|*
name|EFIAPI
name|PeriodicSmiSupportedTickPeriod
parameter_list|(
name|VOID
parameter_list|)
block|{
comment|//
comment|// Return the table allocated and populated by SmmPeriodicSmiLibConstructor()
comment|//
return|return
name|gSmiTickPeriodTable
return|;
block|}
end_function

begin_comment
comment|/**   This function returns the time in 100ns units since the periodic SMI   handler function was called.  If the periodic SMI handler was resumed   through PeriodicSmiYield(), then the time returned is the time in   100ns units since PeriodicSmiYield() returned.    @return  The actual time in 100ns units that the periodic SMI handler            has been executing.  If this function is not called from within            an enabled periodic SMI handler, then 0 is returned.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|PeriodicSmiExecutionTime
parameter_list|(
name|VOID
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
name|UINT64
name|Current
decl_stmt|;
name|UINT64
name|Count
decl_stmt|;
comment|//
comment|// If there is no active periodic SMI handler, then return 0
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|GetActivePeriodicSmiLibraryHandler
argument_list|()
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|//
comment|// Get the current performance counter value
comment|//
name|Current
operator|=
name|GetPerformanceCounter
argument_list|()
expr_stmt|;
comment|//
comment|// Count the number of performance counter ticks since the periodic SMI handler
comment|// was dispatched or the last time this function was called.
comment|//
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterEndValue
operator|>
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterStartValue
condition|)
block|{
comment|//
comment|// The performance counter counts up.  Check for roll over condition.
comment|//
if|if
condition|(
name|Current
operator|>
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
condition|)
block|{
name|Count
operator|=
name|Current
operator|-
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
expr_stmt|;
block|}
else|else
block|{
name|Count
operator|=
operator|(
name|Current
operator|-
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterStartValue
operator|)
operator|+
operator|(
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterEndValue
operator|-
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|//
comment|// The performance counter counts down.  Check for roll over condition.
comment|//
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|>
name|Current
condition|)
block|{
name|Count
operator|=
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|-
name|Current
expr_stmt|;
block|}
else|else
block|{
name|Count
operator|=
operator|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|-
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterEndValue
operator|)
operator|+
operator|(
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterStartValue
operator|-
name|Current
operator|)
expr_stmt|;
block|}
block|}
comment|//
comment|// Accumulate the total number of performance counter ticks since the periodic
comment|// SMI handler was dispatched or resumed.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchTotalTime
operator|+=
name|Count
expr_stmt|;
comment|//
comment|// Update the checkpoint value to the current performance counter value
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|=
name|Current
expr_stmt|;
comment|//
comment|// Convert the total number of performance counter ticks to 100 ns units
comment|//
return|return
name|DivU64x64Remainder
argument_list|(
name|MultU64x32
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchTotalTime
argument_list|,
literal|10000000
argument_list|)
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterRate
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   This function returns control back to the SMM Foundation.  When the next    periodic SMI for the currently executing handler is triggered, the periodic   SMI handler will restarted from its registered DispatchFunction entry point.   If this function is not called from within an enabled periodic SMI handler,    then control is returned to the calling function.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeriodicSmiExit
parameter_list|(
name|VOID
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// If there is no active periodic SMI handler, then return
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|GetActivePeriodicSmiLibraryHandler
argument_list|()
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return;
block|}
comment|//
comment|// Perform a long jump back to the point when the currently executing dispatch
comment|// function was dispatched.
comment|//
name|LongJump
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchJumpBuffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|//
comment|// Must never return
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|CpuDeadLoop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   This function yields control back to the SMM Foundation.  When the next    periodic SMI for the currently executing handler is triggered, the periodic   SMI handler will be resumed and this function will return.  Use of this    function requires a seperate stack for the periodic SMI handler.  A non zero   stack size must be specified in PeriodicSmiEnable() for this function to be    used.        If the stack size passed into PeriodicSmiEnable() was zero, the 0 is returned.      If this function is not called from within an enabled periodic SMI handler,    then 0 is returned.    @return  The actual time in 100ns units elapsed since this function was            called.  A value of 0 indicates an unknown amount of time.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|PeriodicSmiYield
parameter_list|(
name|VOID
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
name|UINTN
name|SetJumpFlag
decl_stmt|;
comment|//
comment|// If there is no active periodic SMI handler, then return
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|GetActivePeriodicSmiLibraryHandler
argument_list|()
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|//
comment|// If PeriodicSmiYield() is called without an allocated stack, then just return
comment|// immediately with an elapsed time of 0.
comment|//
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|==
name|NULL
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|//
comment|// Set a flag so the next periodic SMI event will resume at where SetJump()
comment|// is called below.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|YieldFlag
operator|=
name|TRUE
expr_stmt|;
comment|//
comment|// Save context in YieldJumpBuffer
comment|//
name|SetJumpFlag
operator|=
name|SetJump
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|YieldJumpBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|SetJumpFlag
operator|==
literal|0
condition|)
block|{
comment|//
comment|// The intial call to SetJump() always returns 0.
comment|// If this is the initial call, then exit the current periodic SMI handler
comment|//
name|PeriodicSmiExit
argument_list|()
expr_stmt|;
block|}
comment|//
comment|// We get here when a LongJump is performed from PeriodicSmiDispatchFunctionOnCpu()
comment|// to resume a periodic SMI handler that called PeriodicSmiYield() on the
comment|// previous time this periodic SMI handler was dispatched.
comment|//
comment|// Clear the flag so the next periodic SMI dispatch will not resume.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|YieldFlag
operator|=
name|FALSE
expr_stmt|;
comment|//
comment|// Return the amount elapsed time that occured while yielded
comment|//
return|return
name|PeriodicSmiLibraryHandler
operator|->
name|ElapsedTime
return|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that transfers control to an enabled periodic SMI    handler.  If the enabled periodic SMI handler was allocated its own stack,    then this function is called on that allocated stack through the BaseLin    function SwitchStack().    @param[in] Context1  Context1 parameter passed into SwitchStack().   @param[in] Context2  Context2 parameter passed into SwitchStack().  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeriodicSmiDispatchFunctionSwitchStack
parameter_list|(
name|IN
name|VOID
modifier|*
name|Context1
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|Context2
name|OPTIONAL
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// Convert Context1 to PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT *
comment|//
name|PeriodicSmiLibraryHandler
operator|=
operator|(
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
operator|*
operator|)
name|Context1
expr_stmt|;
comment|//
comment|// Dispatch the registered handler passing in the context that was registered
comment|// and the amount of time that has elapsed since the previous time this
comment|// periodic SMI handler was dispacthed.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchFunction
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|Context
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|ElapsedTime
argument_list|)
expr_stmt|;
comment|//
comment|// If this DispatchFunction() returns, then unconditially call PeriodicSmiExit()
comment|// to perform a LongJump() back to PeriodicSmiDispatchFunctionOnCpu(). The
comment|// LongJump() will resume exection on the original stack.
comment|//
name|PeriodicSmiExit
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that transfers control to an enabled periodic SMI    handler on the specified logial CPU.  This function determines if the periodic    SMI handler yielded and needs to be resumed.  It also and switches to an    allocated stack if one was allocated in PeriodicSmiEnable().    @param[in] PeriodicSmiLibraryHandler  A pointer to the context for the periodic                                         SMI handler to execute.    **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeriodicSmiDispatchFunctionOnCpu
parameter_list|(
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
parameter_list|)
block|{
comment|//
comment|// Save context in DispatchJumpBuffer.  The intial call to SetJump() always
comment|// returns 0.  If this is the initial call, then either resume from a prior
comment|// call to PeriodicSmiYield() or call the DispatchFunction registerd in
comment|// PeriodicSmiEnable() using an allocated stack if one was specified.
comment|//
if|if
condition|(
name|SetJump
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchJumpBuffer
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return;
block|}
comment|//
comment|// Capture the performance counter value just before the periodic SMI handler
comment|// is resumed so the amount of time the periodic SMI handler executes can be
comment|// calculated.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchTotalTime
operator|=
literal|0
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchCheckPointTime
operator|=
name|GetPerformanceCounter
argument_list|()
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|YieldFlag
condition|)
block|{
comment|//
comment|// Perform a long jump back to the point where the previously dispatched
comment|// function called PeriodicSmiYield().
comment|//
name|LongJump
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|YieldJumpBuffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|==
name|NULL
condition|)
block|{
comment|//
comment|// If Stack is NULL then call DispatchFunction using current stack passing
comment|// in the context that was registered and the amount of time that has
comment|// elapsed since the previous time this periodic SMI handler was dispacthed.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchFunction
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|Context
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|ElapsedTime
argument_list|)
expr_stmt|;
comment|//
comment|// If this DispatchFunction() returns, then unconditially call PeriodicSmiExit()
comment|// to perform a LongJump() back to this function.
comment|//
name|PeriodicSmiExit
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|//
comment|// If Stack is not NULL then call DispatchFunction switching to the allocated stack
comment|//
name|SwitchStack
argument_list|(
name|PeriodicSmiDispatchFunctionSwitchStack
argument_list|,
name|PeriodicSmiLibraryHandler
argument_list|,
name|NULL
argument_list|,
operator|(
name|UINT8
operator|*
operator|)
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|+
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Must never return
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|CpuDeadLoop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that transfers control to an enabled periodic SMI    handler on the specified logial CPU.  This worker function is only called    using the SMM Services Table function SmmStartupThisAp() to execute the    periodic SMI handler on a logical CPU that is different than the one that is    running the SMM Foundation.  When the periodic SMI handler returns, a lock is   released to notify the CPU that is running the SMM Foundation that the periodic   SMI handler execution has finished its execution.    @param[in, out] Buffer  A pointer to the context for the periodic SMI handler.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeriodicSmiDispatchFunctionWithLock
parameter_list|(
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// Get context
comment|//
name|PeriodicSmiLibraryHandler
operator|=
operator|(
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
operator|*
operator|)
name|Buffer
expr_stmt|;
comment|//
comment|// Execute dispatch function on the currently excuting logical CPU
comment|//
name|PeriodicSmiDispatchFunctionOnCpu
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
comment|//
comment|// Release the dispatch spin lock
comment|//
name|ReleaseSpinLock
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchLock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Internal worker function that transfers control to a periodic SMI handler that   was enabled using PeriodicSmiEnable().    @param[in]     DispatchHandle  The unique handle assigned to this handler by                                   SmiHandlerRegister().   @param[in]     Context         Points to an optional handler context which was                                   specified when the handler was registered.   @param[in, out] CommBuffer     A pointer to a collection of data in memory that                                  will be conveyed from a non-SMM environment into                                   an SMM environment.   @param[in, out] CommBufferSize The size of the CommBuffer.    @retval EFI_SUCCESS                         The interrupt was handled and quiesced.                                               No other handlers should still be called.   @retval EFI_WARN_INTERRUPT_SOURCE_QUIESCED  The interrupt has been quiesced but other                                               handlers should still be called.   @retval EFI_WARN_INTERRUPT_SOURCE_PENDING   The interrupt is still pending and other                                               handlers should still be called.   @retval EFI_INTERRUPT_PENDING               The interrupt could not be quiesced.    **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|PeriodicSmiDispatchFunction
parameter_list|(
name|IN
name|EFI_HANDLE
name|DispatchHandle
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|CommBuffer
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CommBufferSize
name|OPTIONAL
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
name|EFI_SMM_PERIODIC_TIMER_CONTEXT
modifier|*
name|TimerContext
decl_stmt|;
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// Set the active periodic SMI handler
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|SetActivePeriodicSmiLibraryHandler
argument_list|(
name|Context
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return
name|EFI_NOT_FOUND
return|;
block|}
comment|//
comment|// Retrieve the elapsed time since the last time this periodic SMI handler was called
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|ElapsedTime
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|CommBuffer
operator|!=
name|NULL
condition|)
block|{
name|TimerContext
operator|=
operator|(
name|EFI_SMM_PERIODIC_TIMER_CONTEXT
operator|*
operator|)
name|CommBuffer
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|ElapsedTime
operator|=
name|TimerContext
operator|->
name|ElapsedTime
expr_stmt|;
block|}
comment|//
comment|// Dispatch the periodic SMI handler
comment|//
if|if
condition|(
operator|(
name|PeriodicSmiLibraryHandler
operator|->
name|Cpu
operator|==
name|PERIODIC_SMI_LIBRARY_ANY_CPU
operator|)
operator|||
operator|(
name|PeriodicSmiLibraryHandler
operator|->
name|Cpu
operator|==
name|gSmst
operator|->
name|CurrentlyExecutingCpu
operator|)
condition|)
block|{
comment|//
comment|// Dispatch on the currently execution CPU if the CPU specified in PeriodicSmiEnable()
comment|// was PERIODIC_SMI_LIBARRY_ANY_CPU or the currently executing CPU matches the CPU
comment|// that was specified in PeriodicSmiEnable().
comment|//
name|PeriodicSmiDispatchFunctionOnCpu
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|//
comment|// Acquire spin lock for ths periodic SMI handler.  The AP will release the
comment|// spin lock when it is done executing the periodic SMI handler.
comment|//
name|AcquireSpinLock
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchLock
argument_list|)
expr_stmt|;
comment|//
comment|// Execute the periodic SMI handler on the CPU that was specified in
comment|// PeriodicSmiEnable().
comment|//
name|Status
operator|=
name|gSmst
operator|->
name|SmmStartupThisAp
argument_list|(
name|PeriodicSmiDispatchFunctionWithLock
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|Cpu
argument_list|,
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|EFI_ERROR
argument_list|(
name|Status
argument_list|)
condition|)
block|{
comment|//
comment|// Wait for the AP to release the spin lock.
comment|//
while|while
condition|(
operator|!
name|AcquireSpinLockOrFail
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchLock
argument_list|)
condition|)
block|{
name|CpuPause
argument_list|()
expr_stmt|;
block|}
block|}
comment|//
comment|// Release the spin lock for the periodic SMI handler.
comment|//
name|ReleaseSpinLock
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchLock
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Reclaim the active periodic SMI handler if it was disabled during the current dispatch.
comment|//
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|==
name|NULL
condition|)
block|{
name|ReclaimPeriodicSmiLibraryHandler
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Update state to show that there is no active periodic SMI handler
comment|//
name|SetActivePeriodicSmiLibraryHandler
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   This function enables a periodic SMI handler.      @param[in, out] DispatchHandle   A pointer to the handle associated with the                                     enabled periodic SMI handler.  This is an                                     optional parameter that may be NULL.  If it is                                     NULL, then the handle will not be returned,                                     which means that the periodic SMI handler can                                     never be disabled.   @param[in]     DispatchFunction  A pointer to a periodic SMI handler function.   @param[in]     Context           Optional content to pass into DispatchFunction.   @param[in]     TickPeriod        The requested tick period in 100ns units that                                     control should be givien to the periodic SMI                                    handler.  Must be one of the supported values                                    returned by PeriodicSmiSupportedPickPeriod().   @param[in]     Cpu               Specifies the CPU that is required to execute                                    the periodic SMI handler.  If Cpu is                                     PERIODIC_SMI_LIBRARY_ANY_CPU, then the periodic                                     SMI handler will always be executed on the SMST                                     CurrentlyExecutingCpu, which may vary across                                     periodic SMIs.  If Cpu is between 0 and the SMST                                     NumberOfCpus, then the periodic SMI will always                                    be executed on the requested CPU.   @param[in]     StackSize         The size, in bytes, of the stack to allocate for                                    use by the periodic SMI handler.  If 0, then the                                    default stack will be used.                                @retval EFI_INVALID_PARAMETER  DispatchFunction is NULL.   @retval EFI_UNSUPPORTED        TickPeriod is not a supported tick period.  The                                   supported tick periods can be retrieved using                                   PeriodicSmiSupportedTickPeriod().   @retval EFI_INVALID_PARAMETER  Cpu is not PERIODIC_SMI_LIBRARY_ANY_CPU or in                                   the range 0 to SMST NumberOfCpus.   @retval EFI_OUT_OF_RESOURCES   There are not enough resources to enable the                                   periodic SMI handler.   @retval EFI_OUT_OF_RESOURCES   There are not enough resources to allocate the                                   stack speficied by StackSize.   @retval EFI_SUCCESS            The periodic SMI handler was enabled.    **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|PeriodicSmiEnable
parameter_list|(
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|DispatchHandle
parameter_list|,
name|OPTIONAL
name|IN
name|PERIODIC_SMI_LIBRARY_HANDLER
name|DispatchFunction
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Context
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|TickPeriod
parameter_list|,
name|IN
name|UINTN
name|Cpu
parameter_list|,
name|IN
name|UINTN
name|StackSize
parameter_list|)
block|{
name|EFI_STATUS
name|Status
decl_stmt|;
name|UINTN
name|Index
decl_stmt|;
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// Make sure all the input parameters are valid
comment|//
if|if
condition|(
name|DispatchFunction
operator|==
name|NULL
condition|)
block|{
return|return
name|EFI_INVALID_PARAMETER
return|;
block|}
for|for
control|(
name|Index
operator|=
literal|0
init|;
name|gSmiTickPeriodTable
index|[
name|Index
index|]
operator|!=
literal|0
condition|;
name|Index
operator|++
control|)
block|{
if|if
condition|(
name|gSmiTickPeriodTable
index|[
name|Index
index|]
operator|==
name|TickPeriod
condition|)
block|{
break|break;
block|}
block|}
if|if
condition|(
name|gSmiTickPeriodTable
index|[
name|Index
index|]
operator|==
literal|0
condition|)
block|{
return|return
name|EFI_UNSUPPORTED
return|;
block|}
if|if
condition|(
name|Cpu
operator|!=
name|PERIODIC_SMI_LIBRARY_ANY_CPU
operator|&&
name|Cpu
operator|>=
name|gSmst
operator|->
name|NumberOfCpus
condition|)
block|{
return|return
name|EFI_INVALID_PARAMETER
return|;
block|}
comment|//
comment|// Find a free periodic SMI handler entry
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|FindFreePeriodicSmiLibraryHandler
argument_list|()
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return
name|EFI_OUT_OF_RESOURCES
return|;
block|}
comment|//
comment|// Initialize a new periodic SMI handler entry
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|YieldFlag
operator|=
name|FALSE
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|=
name|NULL
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchFunction
operator|=
name|DispatchFunction
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|Context
operator|=
operator|(
name|VOID
operator|*
operator|)
name|Context
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|Cpu
operator|=
name|Cpu
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
operator|=
name|ALIGN_VALUE
argument_list|(
name|StackSize
argument_list|,
name|EFI_PAGE_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
operator|>
literal|0
condition|)
block|{
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|=
name|AllocatePages
argument_list|(
name|EFI_SIZE_TO_PAGES
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|==
name|NULL
condition|)
block|{
return|return
name|EFI_OUT_OF_RESOURCES
return|;
block|}
name|ZeroMem
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|StackSize
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|PeriodicSmiLibraryHandler
operator|->
name|Stack
operator|=
name|NULL
expr_stmt|;
block|}
name|InitializeSpinLock
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchLock
argument_list|)
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterRate
operator|=
name|GetPerformanceCounterProperties
argument_list|(
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterStartValue
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|PerfomanceCounterEndValue
argument_list|)
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|RegisterContext
operator|.
name|Period
operator|=
name|TickPeriod
expr_stmt|;
name|PeriodicSmiLibraryHandler
operator|->
name|RegisterContext
operator|.
name|SmiTickInterval
operator|=
name|TickPeriod
expr_stmt|;
name|Status
operator|=
name|gSmmPeriodicTimerDispatch2
operator|->
name|Register
argument_list|(
name|gSmmPeriodicTimerDispatch2
argument_list|,
name|PeriodicSmiDispatchFunction
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|RegisterContext
argument_list|,
operator|&
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
argument_list|)
expr_stmt|;
if|if
condition|(
name|EFI_ERROR
argument_list|(
name|Status
argument_list|)
condition|)
block|{
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|=
name|NULL
expr_stmt|;
name|ReclaimPeriodicSmiLibraryHandler
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
return|return
name|EFI_OUT_OF_RESOURCES
return|;
block|}
comment|//
comment|// Return the registered handle if the optional DispatchHandle parameter is not NULL
comment|//
if|if
condition|(
name|DispatchHandle
operator|!=
name|NULL
condition|)
block|{
operator|*
name|DispatchHandle
operator|=
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
expr_stmt|;
block|}
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   This function disables a periodic SMI handler that has been previously   enabled with PeriodicSmiEnable().      @param[in] DispatchHandle  A handle associated with a previously enabled periodic                               SMI handler.  This is an optional parameter that may                              be NULL.  If it is NULL, then the active periodic SMI                              handlers is disabled.    @retval FALSE  DispatchHandle is NULL and there is no active periodic SMI handler.   @retval FALSE  The periodic SMI handler specified by DispatchHandle has                   not been enabled with PeriodicSmiEnable().   @retval TRUE   The periodic SMI handler specified by DispatchHandle has                   been disabled.  If DispatchHandle is NULL, then the active                  periodic SMI handler has been disabled.    **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|PeriodicSmiDisable
parameter_list|(
name|IN
name|EFI_HANDLE
name|DispatchHandle
name|OPTIONAL
parameter_list|)
block|{
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// Lookup the periodic SMI handler specified by DispatchHandle
comment|//
name|PeriodicSmiLibraryHandler
operator|=
name|LookupPeriodicSmiLibraryHandler
argument_list|(
name|DispatchHandle
argument_list|)
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|==
name|NULL
condition|)
block|{
return|return
name|FALSE
return|;
block|}
comment|//
comment|// Unregister the periodic SMI handler from the SMM Periodic Timer Dispatch 2 Protocol
comment|//
name|Status
operator|=
name|gSmmPeriodicTimerDispatch2
operator|->
name|UnRegister
argument_list|(
name|gSmmPeriodicTimerDispatch2
argument_list|,
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
argument_list|)
expr_stmt|;
if|if
condition|(
name|EFI_ERROR
argument_list|(
name|Status
argument_list|)
condition|)
block|{
return|return
name|FALSE
return|;
block|}
comment|//
comment|// Mark the entry for the disabled periodic SMI handler as free, and
comment|// call ReclaimPeriodicSmiLibraryHandler to move it to the list of free
comment|// periodic SMI handlers.
comment|//
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|PeriodicSmiLibraryHandler
operator|!=
name|GetActivePeriodicSmiLibraryHandler
argument_list|()
condition|)
block|{
name|ReclaimPeriodicSmiLibraryHandler
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/**   This constructor function caches the pointer to the SMM Periodic Timer    Dispatch 2 Protocol and collects the list SMI tick rates that the hardware   supports.    @param[in] ImageHandle  The firmware allocated handle for the EFI image.   @param[in] SystemTable  A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|SmmPeriodicSmiLibConstructor
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
block|{
name|EFI_STATUS
name|Status
decl_stmt|;
name|UINT64
modifier|*
name|SmiTickInterval
decl_stmt|;
name|UINTN
name|Count
decl_stmt|;
comment|//
comment|// Locate the SMM Periodic Timer Dispatch 2 Protocol
comment|//
name|Status
operator|=
name|gSmst
operator|->
name|SmmLocateProtocol
argument_list|(
operator|&
name|gEfiSmmPeriodicTimerDispatch2ProtocolGuid
argument_list|,
name|NULL
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|gSmmPeriodicTimerDispatch2
argument_list|)
expr_stmt|;
name|ASSERT_EFI_ERROR
argument_list|(
name|Status
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|gSmmPeriodicTimerDispatch2
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// Count the number of periodic SMI tick intervals that the SMM Periodic Timer
comment|// Dipatch 2 Protocol supports.
comment|//
name|SmiTickInterval
operator|=
name|NULL
expr_stmt|;
name|Count
operator|=
literal|0
expr_stmt|;
do|do
block|{
name|Status
operator|=
name|gSmmPeriodicTimerDispatch2
operator|->
name|GetNextShorterInterval
argument_list|(
name|gSmmPeriodicTimerDispatch2
argument_list|,
operator|&
name|SmiTickInterval
argument_list|)
expr_stmt|;
name|Count
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|SmiTickInterval
operator|!=
name|NULL
condition|)
do|;
comment|//
comment|// Allocate a buffer for the table of supported periodic SMI tick periods.
comment|//
name|gSmiTickPeriodTable
operator|=
name|AllocateZeroPool
argument_list|(
name|Count
operator|*
sizeof|sizeof
argument_list|(
name|UINT64
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|gSmiTickPeriodTable
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// Fill in the table of supported periodic SMI tick periods.
comment|//
name|SmiTickInterval
operator|=
name|NULL
expr_stmt|;
name|Count
operator|=
literal|0
expr_stmt|;
do|do
block|{
name|gSmiTickPeriodTable
index|[
name|Count
index|]
operator|=
literal|0
expr_stmt|;
name|Status
operator|=
name|gSmmPeriodicTimerDispatch2
operator|->
name|GetNextShorterInterval
argument_list|(
name|gSmmPeriodicTimerDispatch2
argument_list|,
operator|&
name|SmiTickInterval
argument_list|)
expr_stmt|;
if|if
condition|(
name|SmiTickInterval
operator|!=
name|NULL
condition|)
block|{
name|gSmiTickPeriodTable
index|[
name|Count
index|]
operator|=
operator|*
name|SmiTickInterval
expr_stmt|;
block|}
name|Count
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|SmiTickInterval
operator|!=
name|NULL
condition|)
do|;
comment|//
comment|// Allocate buffer for initial set of periodic SMI handlers
comment|//
name|EnlargeFreePeriodicSmiLibraryHandlerList
argument_list|()
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   The constructor function caches the pointer to the SMM Periodic Timer Dispatch 2    Protocol and collects the list SMI tick rates that the hardware supports.    @param[in] ImageHandle  The firmware allocated handle for the EFI image.   @param[in] SystemTable  A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|SmmPeriodicSmiLibDestructor
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
block|{
name|LIST_ENTRY
modifier|*
name|Link
decl_stmt|;
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT
modifier|*
name|PeriodicSmiLibraryHandler
decl_stmt|;
comment|//
comment|// Free the table of supported periodic SMI tick rates
comment|//
if|if
condition|(
name|gSmiTickPeriodTable
operator|!=
name|NULL
condition|)
block|{
name|FreePool
argument_list|(
name|gSmiTickPeriodTable
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Disable all periodic SMI handlers
comment|//
for|for
control|(
name|Link
operator|=
name|GetFirstNode
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|)
init|;
operator|!
name|IsNull
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|,
name|Link
argument_list|)
condition|;
control|)
block|{
name|PeriodicSmiLibraryHandler
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_LINK
argument_list|(
name|Link
argument_list|)
expr_stmt|;
name|Link
operator|=
name|GetNextNode
argument_list|(
operator|&
name|gPeriodicSmiLibraryHandlers
argument_list|,
name|Link
argument_list|)
expr_stmt|;
name|PeriodicSmiDisable
argument_list|(
name|PeriodicSmiLibraryHandler
operator|->
name|DispatchHandle
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Free all the periodic SMI handler entries
comment|//
for|for
control|(
name|Link
operator|=
name|GetFirstNode
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|)
init|;
operator|!
name|IsNull
argument_list|(
operator|&
name|gFreePeriodicSmiLibraryHandlers
argument_list|,
name|Link
argument_list|)
condition|;
control|)
block|{
name|PeriodicSmiLibraryHandler
operator|=
name|PERIODIC_SMI_LIBRARY_HANDLER_CONTEXT_FROM_LINK
argument_list|(
name|Link
argument_list|)
expr_stmt|;
name|Link
operator|=
name|RemoveEntryList
argument_list|(
name|Link
argument_list|)
expr_stmt|;
name|FreePool
argument_list|(
name|PeriodicSmiLibraryHandler
argument_list|)
expr_stmt|;
block|}
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

end_unit

