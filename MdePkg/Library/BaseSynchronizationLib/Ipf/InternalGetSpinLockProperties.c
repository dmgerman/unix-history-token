begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal function to get spin lock alignment.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Internal function to retrieve the architecture specific spin lock alignment   requirements for optimal spin lock performance.    @return The architecture specific spin lock alignment.    **/
end_comment

begin_function
name|UINTN
name|InternalGetSpinLockProperties
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
literal|32
return|;
block|}
end_function

end_unit

