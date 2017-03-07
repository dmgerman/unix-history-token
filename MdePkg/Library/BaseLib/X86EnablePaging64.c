begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 AsmEnablePaging64()    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Enables the 64-bit paging mode on the CPU.    Enables the 64-bit paging mode on the CPU. CR0, CR3, CR4, and the page tables   must be properly initialized prior to calling this service. This function   assumes the current execution mode is 32-bit protected mode with flat   descriptors. This function is only available on IA-32. After the 64-bit   paging mode is enabled, control is transferred to the function specified by   EntryPoint using the new stack specified by NewStack and passing in the   parameters specified by Context1 and Context2. Context1 and Context2 are   optional and may be 0. The function EntryPoint must never return.    If the current execution mode is not 32-bit protected mode with flat   descriptors, then ASSERT().   If EntryPoint is 0, then ASSERT().   If NewStack is 0, then ASSERT().    @param  Cs          The 16-bit selector to load in the CS before EntryPoint                       is called. The descriptor in the GDT that this selector                       references must be setup for long mode.   @param  EntryPoint  The 64-bit virtual address of the function to call with                       the new stack after paging is enabled.   @param  Context1    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the first parameter after                       paging is enabled.   @param  Context2    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the second parameter after                       paging is enabled.   @param  NewStack    The 64-bit virtual address of the new stack to use for                       the EntryPoint function after paging is enabled.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmEnablePaging64
parameter_list|(
name|IN
name|UINT16
name|Cs
parameter_list|,
name|IN
name|UINT64
name|EntryPoint
parameter_list|,
name|IN
name|UINT64
name|Context1
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|Context2
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|NewStack
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|EntryPoint
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|NewStack
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|InternalX86EnablePaging64
argument_list|(
name|Cs
argument_list|,
name|EntryPoint
argument_list|,
name|Context1
argument_list|,
name|Context2
argument_list|,
name|NewStack
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

