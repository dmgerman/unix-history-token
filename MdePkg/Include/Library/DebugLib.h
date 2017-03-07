begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to print debug and assert messages to a debug output device.      The Debug library supports debug print and asserts based on a combination of macros and code.   The debug library can be turned on and off so that the debug code does not increase the size of an image.    Note that a reserved macro named MDEPKG_NDEBUG is introduced for the intention   of size reduction when compiler optimization is disabled. If MDEPKG_NDEBUG is   defined, then debug and assert related macros wrapped by it are the NULL implementations.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEBUG_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEBUG_LIB_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Declare bits for PcdDebugPropertyMask
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_DEBUG_PRINT_ENABLED
value|0x02
end_define

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_DEBUG_CODE_ENABLED
value|0x04
end_define

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED
value|0x10
end_define

begin_define
define|#
directive|define
name|DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED
value|0x20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Declare bits for PcdDebugPrintErrorLevel and the ErrorLevel parameter of DebugPrint()
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|DEBUG_INIT
value|0x00000001
end_define

begin_comment
comment|// Initialization
end_comment

begin_define
define|#
directive|define
name|DEBUG_WARN
value|0x00000002
end_define

begin_comment
comment|// Warnings
end_comment

begin_define
define|#
directive|define
name|DEBUG_LOAD
value|0x00000004
end_define

begin_comment
comment|// Load events
end_comment

begin_define
define|#
directive|define
name|DEBUG_FS
value|0x00000008
end_define

begin_comment
comment|// EFI File system
end_comment

begin_define
define|#
directive|define
name|DEBUG_POOL
value|0x00000010
end_define

begin_comment
comment|// Alloc& Free (pool)
end_comment

begin_define
define|#
directive|define
name|DEBUG_PAGE
value|0x00000020
end_define

begin_comment
comment|// Alloc& Free (page)
end_comment

begin_define
define|#
directive|define
name|DEBUG_INFO
value|0x00000040
end_define

begin_comment
comment|// Informational debug messages
end_comment

begin_define
define|#
directive|define
name|DEBUG_DISPATCH
value|0x00000080
end_define

begin_comment
comment|// PEI/DXE/SMM Dispatchers
end_comment

begin_define
define|#
directive|define
name|DEBUG_VARIABLE
value|0x00000100
end_define

begin_comment
comment|// Variable
end_comment

begin_define
define|#
directive|define
name|DEBUG_BM
value|0x00000400
end_define

begin_comment
comment|// Boot Manager
end_comment

begin_define
define|#
directive|define
name|DEBUG_BLKIO
value|0x00001000
end_define

begin_comment
comment|// BlkIo Driver
end_comment

begin_define
define|#
directive|define
name|DEBUG_NET
value|0x00004000
end_define

begin_comment
comment|// Network Io Driver
end_comment

begin_define
define|#
directive|define
name|DEBUG_UNDI
value|0x00010000
end_define

begin_comment
comment|// UNDI Driver
end_comment

begin_define
define|#
directive|define
name|DEBUG_LOADFILE
value|0x00020000
end_define

begin_comment
comment|// LoadFile
end_comment

begin_define
define|#
directive|define
name|DEBUG_EVENT
value|0x00080000
end_define

begin_comment
comment|// Event messages
end_comment

begin_define
define|#
directive|define
name|DEBUG_GCD
value|0x00100000
end_define

begin_comment
comment|// Global Coherency Database changes
end_comment

begin_define
define|#
directive|define
name|DEBUG_CACHE
value|0x00200000
end_define

begin_comment
comment|// Memory range cachability changes
end_comment

begin_define
define|#
directive|define
name|DEBUG_VERBOSE
value|0x00400000
end_define

begin_comment
comment|// Detailed debug messages that may
end_comment

begin_comment
comment|// significantly impact boot performance
end_comment

begin_define
define|#
directive|define
name|DEBUG_ERROR
value|0x80000000
end_define

begin_comment
comment|// Error
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Aliases of debug message mask bits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_D_INIT
value|DEBUG_INIT
end_define

begin_define
define|#
directive|define
name|EFI_D_WARN
value|DEBUG_WARN
end_define

begin_define
define|#
directive|define
name|EFI_D_LOAD
value|DEBUG_LOAD
end_define

begin_define
define|#
directive|define
name|EFI_D_FS
value|DEBUG_FS
end_define

begin_define
define|#
directive|define
name|EFI_D_POOL
value|DEBUG_POOL
end_define

begin_define
define|#
directive|define
name|EFI_D_PAGE
value|DEBUG_PAGE
end_define

begin_define
define|#
directive|define
name|EFI_D_INFO
value|DEBUG_INFO
end_define

begin_define
define|#
directive|define
name|EFI_D_DISPATCH
value|DEBUG_DISPATCH
end_define

begin_define
define|#
directive|define
name|EFI_D_VARIABLE
value|DEBUG_VARIABLE
end_define

begin_define
define|#
directive|define
name|EFI_D_BM
value|DEBUG_BM
end_define

begin_define
define|#
directive|define
name|EFI_D_BLKIO
value|DEBUG_BLKIO
end_define

begin_define
define|#
directive|define
name|EFI_D_NET
value|DEBUG_NET
end_define

begin_define
define|#
directive|define
name|EFI_D_UNDI
value|DEBUG_UNDI
end_define

begin_define
define|#
directive|define
name|EFI_D_LOADFILE
value|DEBUG_LOADFILE
end_define

begin_define
define|#
directive|define
name|EFI_D_EVENT
value|DEBUG_EVENT
end_define

begin_define
define|#
directive|define
name|EFI_D_VERBOSE
value|DEBUG_VERBOSE
end_define

begin_define
define|#
directive|define
name|EFI_D_ERROR
value|DEBUG_ERROR
end_define

begin_comment
comment|/**   Prints a debug message to the debug output device if the specified error level is enabled.    If any bit in ErrorLevel is also set in DebugPrintErrorLevelLib function    GetDebugPrintErrorLevel (), then print the message specified by Format and the    associated variable argument list to the debug output device.    If Format is NULL, then ASSERT().    @param  ErrorLevel  The error level of the debug message.   @param  Format      The format string for the debug message to print.   @param  ...         The variable argument list whose contents are accessed                        based on the format string specified by Format.  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Prints an assert message containing a filename, line number, and description.     This may be followed by a breakpoint or a dead loop.    Print a message of the form "ASSERT<FileName>(<LineNumber>):<Description>\n"   to the debug output device.  If DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED bit of    PcdDebugProperyMask is set then CpuBreakpoint() is called. Otherwise, if    DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED bit of PcdDebugProperyMask is set then    CpuDeadLoop() is called.  If neither of these bits are set, then this function    returns immediately after the message is printed to the debug output device.   DebugAssert() must actively prevent recursion.  If DebugAssert() is called while   processing another DebugAssert(), then DebugAssert() must return immediately.    If FileName is NULL, then a<FileName> string of "(NULL) Filename" is printed.   If Description is NULL, then a<Description> string of "(NULL) Description" is printed.    @param  FileName     The pointer to the name of the source file that generated the assert condition.   @param  LineNumber   The line number in the source file that generated the assert condition   @param  Description  The pointer to the description of the assert condition.  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills a target buffer with PcdDebugClearMemoryValue, and returns the target buffer.    This function fills Length bytes of Buffer with the value specified by    PcdDebugClearMemoryValue, and returns Buffer.    If Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param   Buffer  The pointer to the target buffer to be filled with PcdDebugClearMemoryValue.   @param   Length  The number of bytes in Buffer to fill with zeros PcdDebugClearMemoryValue.     @return  Buffer  The pointer to the target buffer filled with PcdDebugClearMemoryValue.  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if ASSERT() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise, FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|DebugAssertEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**     Returns TRUE if DEBUG() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise, FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|DebugPrintEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**     Returns TRUE if DEBUG_CODE() macros are enabled.    This function returns TRUE if the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise, FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|DebugCodeEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**     Returns TRUE if DEBUG_CLEAR_MEMORY() macro is enabled.    This function returns TRUE if the DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of    PcdDebugProperyMask is set.  Otherwise, FALSE is returned.    @retval  TRUE    The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is set.   @retval  FALSE   The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|DebugClearMemoryEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if any one of the bit is set both in ErrorLevel and PcdFixedDebugPrintErrorLevel.    This function compares the bit mask of ErrorLevel and PcdFixedDebugPrintErrorLevel.    @retval  TRUE    Current ErrorLevel is supported.   @retval  FALSE   Current ErrorLevel is not supported.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|DebugPrintLevelEnabled
parameter_list|(
name|IN
name|CONST
name|UINTN
name|ErrorLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**     Internal worker macro that calls DebugAssert().    This macro calls DebugAssert(), passing in the filename, line number, and an   expression that evaluated to FALSE.    @param  Expression  Boolean expression that evaluated to FALSE  **/
end_comment

begin_define
define|#
directive|define
name|_ASSERT
parameter_list|(
name|Expression
parameter_list|)
value|DebugAssert (__FILE__, __LINE__, #Expression)
end_define

begin_comment
comment|/**     Internal worker macro that calls DebugPrint().    This macro calls DebugPrint() passing in the debug error level, a format    string, and a variable argument list.   __VA_ARGS__ is not supported by EBC compiler, Microsoft Visual Studio .NET 2003   and Microsoft Windows Server 2003 Driver Development Kit (Microsoft WINDDK) version 3790.1830.    @param  Expression  Expression containing an error level, a format string,                        and a variable argument list based on the format string.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|_MSC_VER
operator|>
literal|1400
operator|)
end_if

begin_define
define|#
directive|define
name|_DEBUG_PRINT
parameter_list|(
name|PrintLevel
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                             \       if (DebugPrintLevelEnabled (PrintLevel)) {     \         DebugPrint (PrintLevel, ##__VA_ARGS__);      \       }                                              \     } while (FALSE)
end_define

begin_define
define|#
directive|define
name|_DEBUG
parameter_list|(
name|Expression
parameter_list|)
value|_DEBUG_PRINT Expression
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_DEBUG
parameter_list|(
name|Expression
parameter_list|)
value|DebugPrint Expression
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**     Macro that calls DebugAssert() if an expression evaluates to FALSE.    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED    bit of PcdDebugProperyMask is set, then this macro evaluates the Boolean    expression specified by Expression.  If Expression evaluates to FALSE, then    DebugAssert() is called passing in the source filename, source line number,    and Expression.    @param  Expression  Boolean expression.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|Expression
parameter_list|)
define|\
value|do {                            \       if (DebugAssertEnabled ()) {  \         if (!(Expression)) {        \           _ASSERT (Expression);     \           ANALYZER_UNREACHABLE ();  \         }                           \       }                             \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|Expression
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**     Macro that calls DebugPrint().    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_PRINT_ENABLED    bit of PcdDebugProperyMask is set, then this macro passes Expression to    DebugPrint().    @param  Expression  Expression containing an error level, a format string,                        and a variable argument list based on the format string.     **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|Expression
parameter_list|)
define|\
value|do {                           \       if (DebugPrintEnabled ()) {  \         _DEBUG (Expression);       \       }                            \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|Expression
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**     Macro that calls DebugAssert() if an EFI_STATUS evaluates to an error code.    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED    bit of PcdDebugProperyMask is set, then this macro evaluates the EFI_STATUS    value specified by StatusParameter.  If StatusParameter is an error code,    then DebugAssert() is called passing in the source filename, source line    number, and StatusParameter.    @param  StatusParameter  EFI_STATUS value to evaluate.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASSERT_EFI_ERROR
parameter_list|(
name|StatusParameter
parameter_list|)
define|\
value|do {                                                                                 \       if (DebugAssertEnabled ()) {                                                       \         if (EFI_ERROR (StatusParameter)) {                                               \           DEBUG ((EFI_D_ERROR, "\nASSERT_EFI_ERROR (Status = %r)\n", StatusParameter));  \           _ASSERT (!EFI_ERROR (StatusParameter));                                        \         }                                                                                \       }                                                                                  \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_EFI_ERROR
parameter_list|(
name|StatusParameter
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Macro that calls DebugAssert() if a RETURN_STATUS evaluates to an error code.    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED   bit of PcdDebugProperyMask is set, then this macro evaluates the   RETURN_STATUS value specified by StatusParameter.  If StatusParameter is an   error code, then DebugAssert() is called passing in the source filename,   source line number, and StatusParameter.    @param  StatusParameter  RETURN_STATUS value to evaluate.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASSERT_RETURN_ERROR
parameter_list|(
name|StatusParameter
parameter_list|)
define|\
value|do {                                                                \       if (DebugAssertEnabled ()) {                                      \         if (RETURN_ERROR (StatusParameter)) {                           \           DEBUG ((DEBUG_ERROR, "\nASSERT_RETURN_ERROR (Status = %r)\n", \             StatusParameter));                                          \           _ASSERT (!RETURN_ERROR (StatusParameter));                    \         }                                                               \       }                                                                 \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_RETURN_ERROR
parameter_list|(
name|StatusParameter
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**     Macro that calls DebugAssert() if a protocol is already installed in the    handle database.    If MDEPKG_NDEBUG is defined or the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit    of PcdDebugProperyMask is clear, then return.    If Handle is NULL, then a check is made to see if the protocol specified by Guid    is present on any handle in the handle database.  If Handle is not NULL, then    a check is made to see if the protocol specified by Guid is present on the    handle specified by Handle.  If the check finds the protocol, then DebugAssert()    is called passing in the source filename, source line number, and Guid.    If Guid is NULL, then ASSERT().    @param  Handle  The handle to check for the protocol.  This is an optional                    parameter that may be NULL.  If it is NULL, then the entire                    handle database is searched.    @param  Guid    The pointer to a protocol GUID.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASSERT_PROTOCOL_ALREADY_INSTALLED
parameter_list|(
name|Handle
parameter_list|,
name|Guid
parameter_list|)
define|\
value|do {                                                                                \       if (DebugAssertEnabled ()) {                                                      \         VOID  *Instance;                                                                \         ASSERT (Guid != NULL);                                                          \         if (Handle == NULL) {                                                           \           if (!EFI_ERROR (gBS->LocateProtocol ((EFI_GUID *)Guid, NULL,&Instance))) {   \             _ASSERT (Guid already installed in database);                               \           }                                                                             \         } else {                                                                        \           if (!EFI_ERROR (gBS->HandleProtocol (Handle, (EFI_GUID *)Guid,&Instance))) { \             _ASSERT (Guid already installed on Handle);                                 \           }                                                                             \         }                                                                               \       }                                                                                 \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_PROTOCOL_ALREADY_INSTALLED
parameter_list|(
name|Handle
parameter_list|,
name|Guid
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Macro that marks the beginning of debug source code.    If the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set,    then this macro marks the beginning of source code that is included in a module.   Otherwise, the source lines between DEBUG_CODE_BEGIN() and DEBUG_CODE_END()    are not included in a module.  **/
end_comment

begin_define
define|#
directive|define
name|DEBUG_CODE_BEGIN
parameter_list|()
value|do { if (DebugCodeEnabled ()) { UINT8  __DebugCodeLocal
end_define

begin_comment
comment|/**     The macro that marks the end of debug source code.    If the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set,    then this macro marks the end of source code that is included in a module.     Otherwise, the source lines between DEBUG_CODE_BEGIN() and DEBUG_CODE_END()    are not included in a module.  **/
end_comment

begin_define
define|#
directive|define
name|DEBUG_CODE_END
parameter_list|()
value|__DebugCodeLocal = 0; __DebugCodeLocal++; } } while (FALSE)
end_define

begin_comment
comment|/**     The macro that declares a section of debug source code.    If the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set,    then the source code specified by Expression is included in a module.     Otherwise, the source specified by Expression is not included in a module.  **/
end_comment

begin_define
define|#
directive|define
name|DEBUG_CODE
parameter_list|(
name|Expression
parameter_list|)
define|\
value|DEBUG_CODE_BEGIN ();          \   Expression                    \   DEBUG_CODE_END ()
end_define

begin_comment
comment|/**     The macro that calls DebugClearMemory() to clear a buffer to a default value.    If the DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is set,    then this macro calls DebugClearMemory() passing in Address and Length.    @param  Address  The pointer to a buffer.   @param  Length   The number of bytes in the buffer to set.  **/
end_comment

begin_define
define|#
directive|define
name|DEBUG_CLEAR_MEMORY
parameter_list|(
name|Address
parameter_list|,
name|Length
parameter_list|)
define|\
value|do {                                       \     if (DebugClearMemoryEnabled ()) {        \       DebugClearMemory (Address, Length);    \     }                                        \   } while (FALSE)
end_define

begin_comment
comment|/**   Macro that calls DebugAssert() if the containing record does not have a    matching signature.  If the signatures matches, then a pointer to the data    structure that contains a specified field of that data structure is returned.     This is a lightweight method hide information by placing a public data    structure inside a larger private data structure and using a pointer to the    public data structure to retrieve a pointer to the private data structure.    If MDEPKG_NDEBUG is defined or the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit    of PcdDebugProperyMask is clear, then this macro computes the offset, in bytes,   of the field specified by Field from the beginning of the data structure specified    by TYPE.  This offset is subtracted from Record, and is used to return a pointer    to a data structure of the type specified by TYPE.    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit   of PcdDebugProperyMask is set, then this macro computes the offset, in bytes,    of field specified by Field from the beginning of the data structure specified    by TYPE.  This offset is subtracted from Record, and is used to compute a pointer   to a data structure of the type specified by TYPE.  The Signature field of the    data structure specified by TYPE is compared to TestSignature.  If the signatures    match, then a pointer to the pointer to a data structure of the type specified by    TYPE is returned.  If the signatures do not match, then DebugAssert() is called    with a description of "CR has a bad signature" and Record is returned.      If the data type specified by TYPE does not contain the field specified by Field,    then the module will not compile.    If TYPE does not contain a field called Signature, then the module will not    compile.    @param  Record         The pointer to the field specified by Field within a data                           structure of type TYPE.    @param  TYPE           The name of the data structure type to return  This                           data structure must contain the field specified by Field.     @param  Field          The name of the field in the data structure specified                           by TYPE to which Record points.    @param  TestSignature  The 32-bit signature value to match.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|CR
parameter_list|(
name|Record
parameter_list|,
name|TYPE
parameter_list|,
name|Field
parameter_list|,
name|TestSignature
parameter_list|)
define|\
value|(DebugAssertEnabled ()&& (BASE_CR (Record, TYPE, Field)->Signature != TestSignature)) ?  \     (TYPE *) (_ASSERT (CR has Bad Signature), Record) :                                       \     BASE_CR (Record, TYPE, Field)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CR
parameter_list|(
name|Record
parameter_list|,
name|TYPE
parameter_list|,
name|Field
parameter_list|,
name|TestSignature
parameter_list|)
define|\
value|BASE_CR (Record, TYPE, Field)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

