begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   InterlockedCompareExchange16 function    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2015, Linaro Ltd. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Microsoft Visual Studio 7.1 Function Prototypes for I/O Intrinsics. **/
end_comment

begin_function_decl
name|__int16
name|_InterlockedCompareExchange16
parameter_list|(
name|__int16
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|__int16
name|Exchange
parameter_list|,
name|__int16
name|Comperand
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_InterlockedCompareExchange16
name|)
end_pragma

begin_comment
comment|/**   Performs an atomic compare exchange operation on a 16-bit unsigned integer.    Performs an atomic compare exchange operation on the 16-bit unsigned integer specified   by Value.  If Value is equal to CompareValue, then Value is set to ExchangeValue and   CompareValue is returned.  If Value is not equal to CompareValue, then Value is returned.   The compare exchange operation must be performed using MP safe mechanisms.    @param  Value         A pointer to the 16-bit value for the compare exchange                         operation.   @param  CompareValue  16-bit value used in compare operation.   @param  ExchangeValue 16-bit value used in exchange operation.    @return The original *Value before exchange.  **/
end_comment

begin_function
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
block|{
return|return
name|_InterlockedCompareExchange16
argument_list|(
name|Value
argument_list|,
name|ExchangeValue
argument_list|,
name|CompareValue
argument_list|)
return|;
block|}
end_function

end_unit

