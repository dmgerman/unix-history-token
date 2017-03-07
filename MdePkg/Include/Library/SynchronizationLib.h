begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides synchronization functions.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYNCHRONIZATION_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__SYNCHRONIZATION_LIB__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definitions for SPIN_LOCK
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|UINTN
name|SPIN_LOCK
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves the architecture-specific spin lock alignment requirements for   optimal spin lock performance.    This function retrieves the spin lock alignment requirements for optimal   performance on a given CPU architecture. The spin lock alignment is byte alignment.    It must be a power of two and is returned by this function. If there are no alignment   requirements, then 1 must be returned. The spin lock synchronization   functions must function correctly if the spin lock size and alignment values   returned by this function are not used at all. These values are hints to the   consumers of the spin lock synchronization functions to obtain optimal spin   lock performance.    @return The architecture-specific spin lock alignment.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|GetSpinLockProperties
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Initializes a spin lock to the released state and returns the spin lock.    This function initializes the spin lock specified by SpinLock to the released   state, and returns SpinLock. Optimal performance can be achieved by calling   GetSpinLockProperties() to determine the size and alignment requirements for   SpinLock.    If SpinLock is NULL, then ASSERT().    @param  SpinLock  A pointer to the spin lock to initialize to the released                     state.    @return SpinLock in release state.  **/
end_comment

begin_function_decl
name|SPIN_LOCK
modifier|*
name|EFIAPI
name|InitializeSpinLock
parameter_list|(
name|OUT
name|SPIN_LOCK
modifier|*
name|SpinLock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Waits until a spin lock can be placed in the acquired state.    This function checks the state of the spin lock specified by SpinLock. If   SpinLock is in the released state, then this function places SpinLock in the   acquired state and returns SpinLock. Otherwise, this function waits   indefinitely for the spin lock to be released, and then places it in the   acquired state and returns SpinLock. All state transitions of SpinLock must   be performed using MP safe mechanisms.    If SpinLock is NULL, then ASSERT().   If SpinLock was not initialized with InitializeSpinLock(), then ASSERT().   If PcdSpinLockTimeout is not zero, and SpinLock is can not be acquired in   PcdSpinLockTimeout microseconds, then ASSERT().    @param  SpinLock  A pointer to the spin lock to place in the acquired state.    @return SpinLock acquired lock.  **/
end_comment

begin_function_decl
name|SPIN_LOCK
modifier|*
name|EFIAPI
name|AcquireSpinLock
parameter_list|(
name|IN
name|OUT
name|SPIN_LOCK
modifier|*
name|SpinLock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Attempts to place a spin lock in the acquired state.    This function checks the state of the spin lock specified by SpinLock. If   SpinLock is in the released state, then this function places SpinLock in the   acquired state and returns TRUE. Otherwise, FALSE is returned. All state   transitions of SpinLock must be performed using MP safe mechanisms.    If SpinLock is NULL, then ASSERT().   If SpinLock was not initialized with InitializeSpinLock(), then ASSERT().    @param  SpinLock  A pointer to the spin lock to place in the acquired state.    @retval TRUE  SpinLock was placed in the acquired state.   @retval FALSE SpinLock could not be acquired.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|AcquireSpinLockOrFail
parameter_list|(
name|IN
name|OUT
name|SPIN_LOCK
modifier|*
name|SpinLock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Releases a spin lock.    This function places the spin lock specified by SpinLock in the release state   and returns SpinLock.    If SpinLock is NULL, then ASSERT().   If SpinLock was not initialized with InitializeSpinLock(), then ASSERT().    @param  SpinLock  A pointer to the spin lock to release.    @return SpinLock released lock.  **/
end_comment

begin_function_decl
name|SPIN_LOCK
modifier|*
name|EFIAPI
name|ReleaseSpinLock
parameter_list|(
name|IN
name|OUT
name|SPIN_LOCK
modifier|*
name|SpinLock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic increment of a 32-bit unsigned integer.    Performs an atomic increment of the 32-bit unsigned integer specified by   Value and returns the incremented value. The increment operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    If Value is NULL, then ASSERT().    @param  Value A pointer to the 32-bit value to increment.    @return The incremented value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InterlockedIncrement
parameter_list|(
name|IN
specifier|volatile
name|UINT32
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic decrement of a 32-bit unsigned integer.    Performs an atomic decrement of the 32-bit unsigned integer specified by   Value and returns the decremented value. The decrement operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    If Value is NULL, then ASSERT().    @param  Value A pointer to the 32-bit value to decrement.    @return The decremented value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InterlockedDecrement
parameter_list|(
name|IN
specifier|volatile
name|UINT32
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 16-bit unsigned integer.    Performs an atomic compare exchange operation on the 16-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.    If Value is NULL, then ASSERT().    @param  Value         A pointer to the 16-bit value for the compare exchange                         operation.   @param  CompareValue  16-bit value used in compare operation.   @param  ExchangeValue 16-bit value used in exchange operation.    @return The original *Value before exchange. **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|InterlockedCompareExchange16
parameter_list|(
name|IN
name|OUT
specifier|volatile
name|UINT16
modifier|*
name|Value
parameter_list|,
name|IN
name|UINT16
name|CompareValue
parameter_list|,
name|IN
name|UINT16
name|ExchangeValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 32-bit unsigned integer.    Performs an atomic compare exchange operation on the 32-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.    If Value is NULL, then ASSERT().    @param  Value         A pointer to the 32-bit value for the compare exchange                         operation.   @param  CompareValue  32-bit value used in compare operation.   @param  ExchangeValue 32-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InterlockedCompareExchange32
parameter_list|(
name|IN
name|OUT
specifier|volatile
name|UINT32
modifier|*
name|Value
parameter_list|,
name|IN
name|UINT32
name|CompareValue
parameter_list|,
name|IN
name|UINT32
name|ExchangeValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 64-bit unsigned integer.    Performs an atomic compare exchange operation on the 64-bit unsigned integer specified   by Value.  If Value is equal to CompareValue, then Value is set to ExchangeValue and   CompareValue is returned.  If Value is not equal to CompareValue, then Value is returned.   The compare exchange operation must be performed using MP safe mechanisms.    If Value is NULL, then ASSERT().    @param  Value         A pointer to the 64-bit value for the compare exchange                         operation.   @param  CompareValue  64-bit value used in compare operation.   @param  ExchangeValue 64-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|InterlockedCompareExchange64
parameter_list|(
name|IN
name|OUT
specifier|volatile
name|UINT64
modifier|*
name|Value
parameter_list|,
name|IN
name|UINT64
name|CompareValue
parameter_list|,
name|IN
name|UINT64
name|ExchangeValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an atomic compare exchange operation on a pointer value.    Performs an atomic compare exchange operation on the pointer value specified   by Value. If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned. If Value is not equal to   CompareValue, then Value is returned. The compare exchange operation must be   performed using MP safe mechanisms.    If Value is NULL, then ASSERT().    @param  Value         A pointer to the pointer value for the compare exchange                         operation.   @param  CompareValue  Pointer value used in compare operation.   @param  ExchangeValue Pointer value used in exchange operation.    @return The original *Value before exchange. **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InterlockedCompareExchangePointer
parameter_list|(
name|IN
name|OUT
name|VOID
modifier|*
specifier|volatile
modifier|*
name|Value
parameter_list|,
name|IN
name|VOID
modifier|*
name|CompareValue
parameter_list|,
name|IN
name|VOID
modifier|*
name|ExchangeValue
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

