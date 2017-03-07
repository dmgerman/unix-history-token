begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmReadTr function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Reads the current value of Task Register (TR).    Reads and returns the current value of TR. This function is only available on   IA-32 and x64.    @return The current value of TR.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadTr
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_asm
block|{
name|str
name|ax
block|}
block|}
end_function

end_unit

