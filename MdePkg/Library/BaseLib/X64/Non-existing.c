begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Non-existing BaseLib functions on x64    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

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

begin_comment
comment|/**   Enables the 32-bit paging mode on the CPU.    Enables the 32-bit paging mode on the CPU. CR0, CR3, CR4, and the page tables   must be properly initialized prior to calling this service. This function   assumes the current execution mode is 32-bit protected mode. This function is   only available on IA-32. After the 32-bit paging mode is enabled, control is   transferred to the function specified by EntryPoint using the new stack   specified by NewStack and passing in the parameters specified by Context1 and   Context2. Context1 and Context2 are optional and may be NULL. The function   EntryPoint must never return.    There are a number of constraints that must be followed before calling this   function:   1)  Interrupts must be disabled.   2)  The caller must be in 32-bit protected mode with flat descriptors. This       means all descriptors must have a base of 0 and a limit of 4GB.   3)  CR0 and CR4 must be compatible with 32-bit protected mode with flat       descriptors.   4)  CR3 must point to valid page tables that will be used once the transition       is complete, and those page tables must guarantee that the pages for this       function and the stack are identity mapped.    @param  EntryPoint  A pointer to function to call with the new stack after                       paging is enabled.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function as the first parameter after paging is enabled.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function as the second parameter after paging is enabled.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function after paging is enabled.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86EnablePaging32
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
parameter_list|)
block|{
comment|//
comment|// This function cannot work on x64 platform
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Disables the 32-bit paging mode on the CPU.    Disables the 32-bit paging mode on the CPU and returns to 32-bit protected   mode. This function assumes the current execution mode is 32-paged protected   mode. This function is only available on IA-32. After the 32-bit paging mode   is disabled, control is transferred to the function specified by EntryPoint   using the new stack specified by NewStack and passing in the parameters   specified by Context1 and Context2. Context1 and Context2 are optional and   may be NULL. The function EntryPoint must never return.    There are a number of constraints that must be followed before calling this   function:   1)  Interrupts must be disabled.   2)  The caller must be in 32-bit paged mode.   3)  CR0, CR3, and CR4 must be compatible with 32-bit paged mode.   4)  CR3 must point to valid page tables that guarantee that the pages for       this function and the stack are identity mapped.    @param  EntryPoint  A pointer to function to call with the new stack after                       paging is disabled.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function as the first parameter after paging is disabled.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function as the second parameter after paging is                       disabled.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function after paging is disabled.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86DisablePaging32
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
parameter_list|)
block|{
comment|//
comment|// This function cannot work on x64 platform
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Enables the 64-bit paging mode on the CPU.    Enables the 64-bit paging mode on the CPU. CR0, CR3, CR4, and the page tables   must be properly initialized prior to calling this service. This function   assumes the current execution mode is 32-bit protected mode with flat   descriptors. This function is only available on IA-32. After the 64-bit   paging mode is enabled, control is transferred to the function specified by   EntryPoint using the new stack specified by NewStack and passing in the   parameters specified by Context1 and Context2. Context1 and Context2 are   optional and may be 0. The function EntryPoint must never return.    @param  Cs          The 16-bit selector to load in the CS before EntryPoint                       is called. The descriptor in the GDT that this selector                       references must be setup for long mode.   @param  EntryPoint  The 64-bit virtual address of the function to call with                       the new stack after paging is enabled.   @param  Context1    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the first parameter after                       paging is enabled.   @param  Context2    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the second parameter after                       paging is enabled.   @param  NewStack    The 64-bit virtual address of the new stack to use for                       the EntryPoint function after paging is enabled.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86EnablePaging64
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
comment|//
comment|// This function cannot work on x64 platform.
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

