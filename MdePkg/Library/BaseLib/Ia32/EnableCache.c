begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmEnableCache function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Perform a WBINVD and clear both the CD and NW bits of CR0.    Enables the caches by executing a WBINVD instruction and then clear both the CD and NW   bits of CR0 to 0.  This function is only available on IA-32 and x64.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmEnableCache
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_asm
block|{
name|wbinvd
name|mov
name|eax
decl_stmt|,
name|cr0
name|btr
name|eax
decl_stmt|, 30
name|btr
name|eax
decl_stmt|, 29
name|mov
name|cr0
decl_stmt|,
name|eax
block|}
block|}
end_function

end_unit

