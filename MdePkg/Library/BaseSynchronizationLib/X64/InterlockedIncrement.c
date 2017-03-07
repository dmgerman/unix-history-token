begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   InterLockedIncrement function    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Microsoft Visual Studio 7.1 Function Prototypes for I/O Intrinsics. **/
end_comment

begin_function_decl
name|long
name|_InterlockedIncrement
parameter_list|(
name|long
modifier|*
name|lpAddend
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_InterlockedIncrement
name|)
end_pragma

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
return|return
name|_InterlockedIncrement
argument_list|(
operator|(
name|long
operator|*
operator|)
call|(
name|UINTN
call|)
argument_list|(
name|Value
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

