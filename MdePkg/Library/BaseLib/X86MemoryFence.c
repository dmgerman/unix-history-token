begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 MemoryFence().    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Used to serialize load and store operations.    All loads and stores that proceed calls to this function are guaranteed to be   globally visible when this function returns.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|MemoryFence
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

