begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Null Base Debug Library instance with empty functions.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|/**   Prints a debug message to the debug output device if the specified error level is enabled.    If any bit in ErrorLevel is also set in DebugPrintErrorLevelLib function    GetDebugPrintErrorLevel (), then print the message specified by Format and the    associated variable argument list to the debug output device.    If Format is NULL, then ASSERT().    @param  ErrorLevel  The error level of the debug message.   @param  Format      Format string for the debug message to print.   @param  ...         Variable argument list whose contents are accessed                        based on the format string specified by Format.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|DebugPrint
parameter_list|(
name|IN
name|UINTN
name|ErrorLevel
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
block|{ }
end_function

begin_comment
comment|/**   Prints an assert message containing a filename, line number, and description.     This may be followed by a breakpoint or a dead loop.    Print a message of the form "ASSERT<FileName>(<LineNumber>):<Description>\n"   to the debug output device.  If DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED bit of    PcdDebugProperyMask is set then CpuBreakpoint() is called. Otherwise, if    DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED bit of PcdDebugProperyMask is set then    CpuDeadLoop() is called.  If neither of these bits are set, then this function    returns immediately after the message is printed to the debug output device.   DebugAssert() must actively prevent recursion.  If DebugAssert() is called while   processing another DebugAssert(), then DebugAssert() must return immediately.    If FileName is NULL, then a<FileName> string of "(NULL) Filename" is printed.   If Description is NULL, then a<Description> string of "(NULL) Description" is printed.    @param  FileName     The pointer to the name of the source file that generated the assert condition.   @param  LineNumber   The line number in the source file that generated the assert condition   @param  Description  The pointer to the description of the assert condition.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|DebugAssert
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|FileName
parameter_list|,
name|IN
name|UINTN
name|LineNumber
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Description
parameter_list|)
block|{ }
end_function

begin_comment
comment|/**   Fills a target buffer with PcdDebugClearMemoryValue, and returns the target buffer.    This function fills Length bytes of Buffer with the value specified by    PcdDebugClearMemoryValue, and returns Buffer.    If Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param   Buffer  The pointer to the target buffer to be filled with PcdDebugClearMemoryValue.   @param   Length  The number of bytes in Buffer to fill with zeros PcdDebugClearMemoryValue.     @return  Buffer  The pointer to the target buffer filled with PcdDebugClearMemoryValue.  **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|DebugClearMemory
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
block|{
return|return
name|Buffer
return|;
block|}
end_function

begin_comment
comment|/**   Returns TRUE if ASSERT() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|DebugAssertEnabled
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**     Returns TRUE if DEBUG() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|DebugPrintEnabled
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**     Returns TRUE if DEBUG_CODE() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|DebugCodeEnabled
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**     Returns TRUE if DEBUG_CLEAR_MEMORY() macro is enabled.    This function returns TRUE if the DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|DebugClearMemoryEnabled
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Returns TRUE if any one of the bit is set both in ErrorLevel and PcdFixedDebugPrintErrorLevel.    This function compares the bit mask of ErrorLevel and PcdFixedDebugPrintErrorLevel.    @retval  TRUE    Current ErrorLevel is supported.   @retval  FALSE   Current ErrorLevel is not supported.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|DebugPrintLevelEnabled
parameter_list|(
name|IN
name|CONST
name|UINTN
name|ErrorLevel
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

end_unit

