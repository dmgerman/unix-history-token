begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmMonitor function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Sets up a monitor buffer that is used by AsmMwait().    Executes a MONITOR instruction with the register state specified by Eax, Ecx   and Edx. Returns Eax. This function is only available on IA-32 and x64.    @param  RegisterEax The value to load into EAX or RAX before executing the MONITOR                       instruction.   @param  RegisterEcx The value to load into ECX or RCX before executing the MONITOR                       instruction.   @param  RegisterEdx The value to load into EDX or RDX before executing the MONITOR                       instruction.    @return RegisterEax  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmMonitor
parameter_list|(
name|IN
name|UINTN
name|RegisterEax
parameter_list|,
name|IN
name|UINTN
name|RegisterEcx
parameter_list|,
name|IN
name|UINTN
name|RegisterEdx
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|RegisterEax
name|mov
name|ecx
decl_stmt|,
name|RegisterEcx
name|mov
name|edx
decl_stmt|,
name|RegisterEdx
name|_emit
decl|0x0f
comment|// monitor
name|_emit
decl|0x01
name|_emit
decl|0xc8
block|}
block|}
end_function

end_unit

