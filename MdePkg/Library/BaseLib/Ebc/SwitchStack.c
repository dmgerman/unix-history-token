begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Switch Stack functions.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Transfers control to a function starting with a new stack.    Transfers control to the function specified by EntryPoint using the   new stack specified by NewStack and passing in the parameters specified   by Context1 and Context2.  Context1 and Context2 are optional and may   be NULL.  The function EntryPoint must never return.   Marker will be ignored on IA-32, x64, and EBC.   IPF CPUs expect one additional parameter of type VOID * that specifies   the new backing store pointer.    If EntryPoint is NULL, then ASSERT().   If NewStack is NULL, then ASSERT().    @param  EntryPoint  A pointer to function to call with the new stack.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function.   @param  Marker      A VA_LIST marker for the variable argument list.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalSwitchStack
parameter_list|(
name|IN
name|SWITCH_STACK_ENTRY_POINT
name|EntryPoint
parameter_list|,
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
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|NewStack
parameter_list|,
name|IN
name|VA_LIST
name|Marker
parameter_list|)
block|{
comment|//
comment|// This version of this function does not actually change the stack pointer
comment|// This is to support compilation of CPU types that do not support assemblers
comment|// such as EBC
comment|//
name|EntryPoint
argument_list|(
name|Context1
argument_list|,
name|Context2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

