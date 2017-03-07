begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmDisablePaging32 function.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Disables the 32-bit paging mode on the CPU.    Disables the 32-bit paging mode on the CPU and returns to 32-bit protected   mode. This function assumes the current execution mode is 32-paged protected   mode. This function is only available on IA-32. After the 32-bit paging mode   is disabled, control is transferred to the function specified by EntryPoint   using the new stack specified by NewStack and passing in the parameters   specified by Context1 and Context2. Context1 and Context2 are optional and   may be NULL. The function EntryPoint must never return.    There are a number of constraints that must be followed before calling this   function:   1)  Interrupts must be disabled.   2)  The caller must be in 32-bit paged mode.   3)  CR0, CR3, and CR4 must be compatible with 32-bit paged mode.   4)  CR3 must point to valid page tables that guarantee that the pages for       this function and the stack are identity mapped.    @param  EntryPoint  A pointer to function to call with the new stack after                       paging is disabled.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function as the first parameter after paging is disabled.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function as the second parameter after paging is                       disabled.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function after paging is disabled.  **/
end_comment

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

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
name|_asm
block|{
name|push
name|ebp
name|mov
name|ebp
decl_stmt|,
name|esp
name|mov
name|ebx
decl_stmt|,
name|EntryPoint
name|mov
name|ecx
decl_stmt|,
name|Context1
name|mov
name|edx
decl_stmt|,
name|Context2
name|pushfd
name|pop
name|edi
comment|// save EFLAGS to edi
name|cli
name|mov
name|eax
decl_stmt|,
name|cr0
name|btr
name|eax
decl_stmt|, 31
name|mov
name|esp
decl_stmt|,
name|NewStack
name|mov
name|cr0
decl_stmt|,
name|eax
name|push
name|edi
name|popfd
comment|// restore EFLAGS from edi
name|push
name|edx
name|push
name|ecx
name|call
name|ebx
name|jmp
name|$
comment|// EntryPoint() should not return
block|}
block|}
end_function

end_unit

