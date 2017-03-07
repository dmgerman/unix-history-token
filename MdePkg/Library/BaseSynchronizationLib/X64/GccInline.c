begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GCC inline implementation of BaseSynchronizationLib processor specific functions.      Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Performs an atomic increment of an 32-bit unsigned integer.    Performs an atomic increment of the 32-bit unsigned integer specified by   Value and returns the incremented value. The increment operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    @param  Value A pointer to the 32-bit value to increment.    @return The incremented value.  **/
end_comment

begin_function
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
block|{
name|UINT32
name|Result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "lock               \n\t"     "incl    %2         \n\t"     "mov     %2, %%eax      "     : "=a" (Result),
comment|// %0
asm|"=m" (*Value)
comment|// %1
asm|: "m"  (*Value)
comment|// %2
asm|: "memory",       "cc"     );
return|return
name|Result
return|;
block|}
end_function

begin_comment
comment|/**   Performs an atomic decrement of an 32-bit unsigned integer.    Performs an atomic decrement of the 32-bit unsigned integer specified by   Value and returns the decremented value. The decrement operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    @param  Value A pointer to the 32-bit value to decrement.    @return The decremented value.  **/
end_comment

begin_function
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
block|{
name|UINT32
name|Result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "lock               \n\t"     "decl    %2         \n\t"     "mov     %2, %%eax      "     : "=a" (Result),
comment|// %0
asm|"=m" (*Value)
comment|// %1
asm|: "m"  (*Value)
comment|// %2
asm|: "memory",       "cc"     );
return|return
name|Result
return|;
block|}
end_function

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 16-bit unsigned integer.    Performs an atomic compare exchange operation on the 16-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.     @param  Value         A pointer to the 16-bit value for the compare exchange                         operation.   @param  CompareValue  16-bit value used in compare operation.   @param  ExchangeValue 16-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|InternalSyncCompareExchange16
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
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lock                 \n\t"     "cmpxchgw    %3, %1       "     : "=a" (CompareValue),       "=m" (*Value)     : "a"  (CompareValue),       "r"  (ExchangeValue),       "m"  (*Value)     : "memory",       "cc"     );
return|return
name|CompareValue
return|;
block|}
end_function

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 32-bit unsigned integer.    Performs an atomic compare exchange operation on the 32-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.     @param  Value         A pointer to the 32-bit value for the compare exchange                         operation.   @param  CompareValue  32-bit value used in compare operation.   @param  ExchangeValue 32-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|InternalSyncCompareExchange32
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
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lock                 \n\t"     "cmpxchgl    %3, %1       "     : "=a" (CompareValue),
comment|// %0
asm|"=m" (*Value)
comment|// %1
asm|: "a"  (CompareValue),
comment|// %2
asm|"r"  (ExchangeValue),
comment|// %3
asm|"m"  (*Value)     : "memory",       "cc"     );
return|return
name|CompareValue
return|;
block|}
end_function

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 64-bit unsigned integer.    Performs an atomic compare exchange operation on the 64-bit unsigned integer specified   by Value.  If Value is equal to CompareValue, then Value is set to ExchangeValue and   CompareValue is returned.  If Value is not equal to CompareValue, then Value is returned.   The compare exchange operation must be performed using MP safe mechanisms.     @param  Value         A pointer to the 64-bit value for the compare exchange                         operation.   @param  CompareValue  64-bit value used in compare operation.   @param  ExchangeValue 64-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|InternalSyncCompareExchange64
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
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lock                 \n\t"     "cmpxchgq    %3, %1       "     : "=a" (CompareValue),
comment|// %0
asm|"=m" (*Value)
comment|// %1
asm|: "a"  (CompareValue),
comment|// %2
asm|"r"  (ExchangeValue),
comment|// %3
asm|"m"  (*Value)     : "memory",       "cc"     );
return|return
name|CompareValue
return|;
block|}
end_function

end_unit

