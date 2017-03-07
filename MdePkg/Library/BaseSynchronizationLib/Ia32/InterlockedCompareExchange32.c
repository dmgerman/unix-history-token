begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   InterlockedCompareExchange32 function    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 32-bit unsigned integer.    Performs an atomic compare exchange operation on the 32-bit unsigned integer   specified by Value.  If Value is equal to CompareValue, then Value is set to   ExchangeValue and CompareValue is returned.  If Value is not equal to CompareValue,   then Value is returned.  The compare exchange operation must be performed using   MP safe mechanisms.    @param  Value         A pointer to the 32-bit value for the compare exchange                         operation.   @param  CompareValue  32-bit value used in compare operation.   @param  ExchangeValue 32-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function
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
block|{
name|_asm
block|{
name|mov
name|ecx
decl_stmt|,
name|Value
name|mov
name|eax
decl_stmt|,
name|CompareValue
name|mov
name|edx
decl_stmt|,
name|ExchangeValue
name|lock
name|cmpxchg
index|[
name|ecx
index|]
decl_stmt|,
name|edx
block|}
block|}
end_function

end_unit

