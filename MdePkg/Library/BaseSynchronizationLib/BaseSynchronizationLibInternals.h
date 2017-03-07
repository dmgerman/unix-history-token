begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Declaration of internal functions in BaseSynchronizationLib.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_SYNCHRONIZATION_LIB_INTERNALS__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_SYNCHRONIZATION_LIB_INTERNALS__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/SynchronizationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
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
file|<Library/PcdLib.h>
end_include

begin_comment
comment|/**   Performs an atomic increment of an 32-bit unsigned integer.    Performs an atomic increment of the 32-bit unsigned integer specified by   Value and returns the incremented value. The increment operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    @param  Value A pointer to the 32-bit value to increment.    @return The incremented value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InternalSyncIncrement
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
comment|/**   Performs an atomic decrement of an 32-bit unsigned integer.    Performs an atomic decrement of the 32-bit unsigned integer specified by   Value and returns the decrement value. The decrement operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    @param  Value A pointer to the 32-bit value to decrement.    @return The decrement value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InternalSyncDecrement
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
comment|/**   Performs an atomic compare exchange operation on a 16-bit unsigned integer.    Performs an atomic compare exchange operation on the 16-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.    @param  Value         A pointer to the 16-bit value for the compare exchange                         operation.   @param  CompareValue  A 16-bit value used in compare operation.   @param  ExchangeValue A 16-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|InternalSyncCompareExchange16
parameter_list|(
name|IN
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
comment|/**   Performs an atomic compare exchange operation on a 32-bit unsigned integer.    Performs an atomic compare exchange operation on the 32-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.    @param  Value         A pointer to the 32-bit value for the compare exchange                         operation.   @param  CompareValue  A 32-bit value used in compare operation.   @param  ExchangeValue A 32-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|InternalSyncCompareExchange32
parameter_list|(
name|IN
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
comment|/**   Performs an atomic compare exchange operation on a 64-bit unsigned integer.    Performs an atomic compare exchange operation on the 64-bit unsigned integer specified   by Value.  If Value is equal to CompareValue, then Value is set to ExchangeValue and   CompareValue is returned.  If Value is not equal to CompareValue, then Value is returned.   The compare exchange operation must be performed using MP safe mechanisms.    @param  Value         A pointer to the 64-bit value for the compare exchange                         operation.   @param  CompareValue  A 64-bit value used in compare operation.   @param  ExchangeValue A 64-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|InternalSyncCompareExchange64
parameter_list|(
name|IN
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
comment|/**   Internal function to retrieve the architecture specific spin lock alignment   requirements for optimal spin lock performance.    @return The architecture specific spin lock alignment.    **/
end_comment

begin_function_decl
name|UINTN
name|InternalGetSpinLockProperties
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

