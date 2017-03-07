begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Debug Print Error Level library instance that retrieves the current error    level from PcdDebugPrintErrorLevel.  This generic library instance does not    support the setting of the global debug print error level mask for the platform.    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugPrintErrorLevelLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PcdLib.h>
end_include

begin_comment
comment|/**   Returns the debug print error level mask for the current module.    @return  Debug print error level mask for the current module.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|GetDebugPrintErrorLevel
parameter_list|(
name|VOID
parameter_list|)
block|{
comment|//
comment|// Retrieve the current debug print error level mask from PcdDebugPrintErrorLevel.
comment|//
return|return
name|PcdGet32
argument_list|(
name|PcdDebugPrintErrorLevel
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Sets the global debug print error level mask fpr the entire platform.      @param   ErrorLevel     Global debug print error level.      @retval  TRUE           The debug print error level mask was sucessfully set.   @retval  FALSE          The debug print error level mask could not be set.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|SetDebugPrintErrorLevel
parameter_list|(
name|UINT32
name|ErrorLevel
parameter_list|)
block|{
comment|//
comment|// This library uinstance does not support setting the global debug print error
comment|// level mask.
comment|//
return|return
name|FALSE
return|;
block|}
end_function

end_unit

