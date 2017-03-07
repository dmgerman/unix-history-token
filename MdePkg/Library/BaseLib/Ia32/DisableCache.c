begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmDisableCache function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Set CD bit and clear NW bit of CR0 followed by a WBINVD.    Disables the caches by setting the CD bit of CR0 to 1, clearing the NW bit of CR0 to 0,   and executing a WBINVD instruction.  This function is only available on IA-32 and x64.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmDisableCache
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|cr0
name|bts
name|eax
decl_stmt|, 30
name|btr
name|eax
decl_stmt|, 29
name|mov
name|cr0
decl_stmt|,
name|eax
name|wbinvd
block|}
block|}
end_function

end_unit

