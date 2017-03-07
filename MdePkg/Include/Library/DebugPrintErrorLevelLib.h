begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Debug Print Error Level Library class    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG_PRINT_ERROR_LEVEL_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEBUG_PRINT_ERROR_LEVEL_LIB_H_
end_define

begin_comment
comment|/**   Returns the debug print error level mask for the current module.    @return  Debug print error level mask for the current module.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|GetDebugPrintErrorLevel
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sets the global debug print error level mask fpr the entire platform.      @param   ErrorLevel     Global debug print error level      @retval  TRUE           The debug print error level mask was successfully set.   @retval  FALSE          The debug print error level mask could not be set.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|SetDebugPrintErrorLevel
parameter_list|(
name|UINT32
name|ErrorLevel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

