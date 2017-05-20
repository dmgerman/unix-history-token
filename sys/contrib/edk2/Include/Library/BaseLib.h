begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides string functions, linked list functions, math functions, synchronization   functions, file path functions, and CPU architecture-specific functions.  Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR> Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_LIB__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for architecture-specific types
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// The IA-32 architecture context buffer used by SetJump() and LongJump().
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Ebx
decl_stmt|;
name|UINT32
name|Esi
decl_stmt|;
name|UINT32
name|Edi
decl_stmt|;
name|UINT32
name|Ebp
decl_stmt|;
name|UINT32
name|Esp
decl_stmt|;
name|UINT32
name|Eip
decl_stmt|;
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_IA32)
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IPF
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Itanium architecture context buffer used by SetJump() and LongJump().
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|F2
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F3
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F4
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F5
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F16
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F17
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F18
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F19
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F20
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F21
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F22
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F23
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F24
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F25
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F26
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F27
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F28
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F29
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F30
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|F31
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|R4
decl_stmt|;
name|UINT64
name|R5
decl_stmt|;
name|UINT64
name|R6
decl_stmt|;
name|UINT64
name|R7
decl_stmt|;
name|UINT64
name|SP
decl_stmt|;
name|UINT64
name|BR0
decl_stmt|;
name|UINT64
name|BR1
decl_stmt|;
name|UINT64
name|BR2
decl_stmt|;
name|UINT64
name|BR3
decl_stmt|;
name|UINT64
name|BR4
decl_stmt|;
name|UINT64
name|BR5
decl_stmt|;
name|UINT64
name|InitialUNAT
decl_stmt|;
name|UINT64
name|AfterSpillUNAT
decl_stmt|;
name|UINT64
name|PFS
decl_stmt|;
name|UINT64
name|BSP
decl_stmt|;
name|UINT64
name|Predicates
decl_stmt|;
name|UINT64
name|LoopCount
decl_stmt|;
name|UINT64
name|FPSR
decl_stmt|;
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_IPF)
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// The x64 architecture context buffer used by SetJump() and LongJump().
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Rbx
decl_stmt|;
name|UINT64
name|Rsp
decl_stmt|;
name|UINT64
name|Rbp
decl_stmt|;
name|UINT64
name|Rdi
decl_stmt|;
name|UINT64
name|Rsi
decl_stmt|;
name|UINT64
name|R12
decl_stmt|;
name|UINT64
name|R13
decl_stmt|;
name|UINT64
name|R14
decl_stmt|;
name|UINT64
name|R15
decl_stmt|;
name|UINT64
name|Rip
decl_stmt|;
name|UINT64
name|MxCsr
decl_stmt|;
name|UINT8
name|XmmBuffer
index|[
literal|160
index|]
decl_stmt|;
comment|///< XMM6-XMM15.
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_X64)
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EBC context buffer used by SetJump() and LongJump().
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|R0
decl_stmt|;
name|UINT64
name|R1
decl_stmt|;
name|UINT64
name|R2
decl_stmt|;
name|UINT64
name|R3
decl_stmt|;
name|UINT64
name|IP
decl_stmt|;
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_EBC)
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_ARM
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|R3
decl_stmt|;
comment|///< A copy of R13.
name|UINT32
name|R4
decl_stmt|;
name|UINT32
name|R5
decl_stmt|;
name|UINT32
name|R6
decl_stmt|;
name|UINT32
name|R7
decl_stmt|;
name|UINT32
name|R8
decl_stmt|;
name|UINT32
name|R9
decl_stmt|;
name|UINT32
name|R10
decl_stmt|;
name|UINT32
name|R11
decl_stmt|;
name|UINT32
name|R12
decl_stmt|;
name|UINT32
name|R14
decl_stmt|;
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_ARM)
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_AARCH64
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// GP regs
name|UINT64
name|X19
decl_stmt|;
name|UINT64
name|X20
decl_stmt|;
name|UINT64
name|X21
decl_stmt|;
name|UINT64
name|X22
decl_stmt|;
name|UINT64
name|X23
decl_stmt|;
name|UINT64
name|X24
decl_stmt|;
name|UINT64
name|X25
decl_stmt|;
name|UINT64
name|X26
decl_stmt|;
name|UINT64
name|X27
decl_stmt|;
name|UINT64
name|X28
decl_stmt|;
name|UINT64
name|FP
decl_stmt|;
name|UINT64
name|LR
decl_stmt|;
name|UINT64
name|IP0
decl_stmt|;
comment|// FP regs
name|UINT64
name|D8
decl_stmt|;
name|UINT64
name|D9
decl_stmt|;
name|UINT64
name|D10
decl_stmt|;
name|UINT64
name|D11
decl_stmt|;
name|UINT64
name|D12
decl_stmt|;
name|UINT64
name|D13
decl_stmt|;
name|UINT64
name|D14
decl_stmt|;
name|UINT64
name|D15
decl_stmt|;
block|}
name|BASE_LIBRARY_JUMP_BUFFER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined (MDE_CPU_AARCH64)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// String Services
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Returns the length of a Null-terminated Unicode string.    This function is similar as strlen_s defined in C11.    If String is not aligned on a 16-bit boundary, then ASSERT().    @param  String   A pointer to a Null-terminated Unicode string.   @param  MaxSize  The maximum number of Destination Unicode                    char, including terminating null char.    @retval 0        If String is NULL.   @retval MaxSize  If there is no null character in the first MaxSize characters of String.   @return The number of characters that percede the terminating null character.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrnLenS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|MaxSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the size of a Null-terminated Unicode string in bytes, including the   Null terminator.    This function returns the size of the Null-terminated Unicode string   specified by String in bytes, including the Null terminator.    If String is not aligned on a 16-bit boundary, then ASSERT().    @param  String   A pointer to a Null-terminated Unicode string.   @param  MaxSize  The maximum number of Destination Unicode                    char, including the Null terminator.    @retval 0  If String is NULL.   @retval (sizeof (CHAR16) * (MaxSize + 1))              If there is no Null terminator in the first MaxSize characters of              String.   @return The size of the Null-terminated Unicode string in bytes, including           the Null terminator.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrnSizeS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|MaxSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies the string pointed to by Source (including the terminating null char)   to the array pointed to by Destination.    This function is similar as strcpy_s defined in C11.    If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Unicode string.   @param  DestMax                  The maximum number of Destination Unicode                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Unicode string.    @retval RETURN_SUCCESS           String is copied.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumUnicodeStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrCpyS
parameter_list|(
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies not more than Length successive char from the string pointed to by   Source to the array pointed to by Destination. If no null char is copied from   Source, then Destination[Length] is always set to null.    This function is similar as strncpy_s defined in C11.    If Length> 0 and Destination is not aligned on a 16-bit boundary, then ASSERT().   If Length> 0 and Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Unicode string.   @param  DestMax                  The maximum number of Destination Unicode                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Unicode string.   @param  Length                   The maximum number of Unicode characters to copy.    @retval RETURN_SUCCESS           String is copied.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than                                     MIN(StrLen(Source), Length).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumUnicodeStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrnCpyS
parameter_list|(
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Appends a copy of the string pointed to by Source (including the terminating   null char) to the end of the string pointed to by Destination.    This function is similar as strcat_s defined in C11.    If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Unicode string.   @param  DestMax                  The maximum number of Destination Unicode                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Unicode string.    @retval RETURN_SUCCESS           String is appended.   @retval RETURN_BAD_BUFFER_SIZE   If DestMax is NOT greater than                                     StrLen(Destination).   @retval RETURN_BUFFER_TOO_SMALL  If (DestMax - StrLen(Destination)) is NOT                                    greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumUnicodeStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrCatS
parameter_list|(
name|IN
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Appends not more than Length successive char from the string pointed to by   Source to the end of the string pointed to by Destination. If no null char is   copied from Source, then Destination[StrLen(Destination) + Length] is always   set to null.    This function is similar as strncat_s defined in C11.    If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Unicode string.   @param  DestMax                  The maximum number of Destination Unicode                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Unicode string.   @param  Length                   The maximum number of Unicode characters to copy.    @retval RETURN_SUCCESS           String is appended.   @retval RETURN_BAD_BUFFER_SIZE   If DestMax is NOT greater than                                    StrLen(Destination).   @retval RETURN_BUFFER_TOO_SMALL  If (DestMax - StrLen(Destination)) is NOT                                    greater than MIN(StrLen(Source), Length).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumUnicodeStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrnCatS
parameter_list|(
name|IN
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode decimal string to a value of type UINTN.    This function outputs a value of type UINTN by interpreting the contents of   the Unicode string specified by String as a decimal number. The format of the   input Unicode string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before   [decimal digits]. The running zero in the beginning of [decimal digits] will   be ignored. Then, the function stops at the first character that is a not a   valid decimal character or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If String has no valid decimal digits in the above format, then 0 is stored   at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINTN, then   MAX_UINTN is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   decimal digits right after the optional pad spaces, the value of String is   stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumUnicodeStringLength is not                                    zero, and String contains more than                                    PcdMaximumUnicodeStringLength Unicode                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINTN.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrDecimalToUintnS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode decimal string to a value of type UINT64.    This function outputs a value of type UINT64 by interpreting the contents of   the Unicode string specified by String as a decimal number. The format of the   input Unicode string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before   [decimal digits]. The running zero in the beginning of [decimal digits] will   be ignored. Then, the function stops at the first character that is a not a   valid decimal character or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If String has no valid decimal digits in the above format, then 0 is stored   at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINT64, then   MAX_UINT64 is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   decimal digits right after the optional pad spaces, the value of String is   stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumUnicodeStringLength is not                                    zero, and String contains more than                                    PcdMaximumUnicodeStringLength Unicode                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINT64.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrDecimalToUint64S
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT64
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode hexadecimal string to a value of type   UINTN.    This function outputs a value of type UINTN by interpreting the contents of   the Unicode string specified by String as a hexadecimal number. The format of   the input Unicode string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix.   If "x" appears in the input string, it must be prefixed with at least one 0.   The function will ignore the pad space, which includes spaces or tab   characters, before [zeros], [x] or [hexadecimal digit]. The running zero   before [x] or [hexadecimal digit] will be ignored. Then, the decoding starts   after [x] or the first valid hexadecimal digit. Then, the function stops at   the first character that is a not a valid hexadecimal character or NULL,   whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If String has no valid hexadecimal digits in the above format, then 0 is   stored at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINTN, then   MAX_UINTN is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   hexadecimal digits right after the optional pad spaces, the value of String   is stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumUnicodeStringLength is not                                    zero, and String contains more than                                    PcdMaximumUnicodeStringLength Unicode                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINTN.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrHexToUintnS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode hexadecimal string to a value of type   UINT64.    This function outputs a value of type UINT64 by interpreting the contents of   the Unicode string specified by String as a hexadecimal number. The format of   the input Unicode string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix.   If "x" appears in the input string, it must be prefixed with at least one 0.   The function will ignore the pad space, which includes spaces or tab   characters, before [zeros], [x] or [hexadecimal digit]. The running zero   before [x] or [hexadecimal digit] will be ignored. Then, the decoding starts   after [x] or the first valid hexadecimal digit. Then, the function stops at   the first character that is a not a valid hexadecimal character or NULL,   whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If String has no valid hexadecimal digits in the above format, then 0 is   stored at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINT64, then   MAX_UINT64 is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   hexadecimal digits right after the optional pad spaces, the value of String   is stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumUnicodeStringLength is not                                    zero, and String contains more than                                    PcdMaximumUnicodeStringLength Unicode                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINT64.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrHexToUint64S
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT64
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the length of a Null-terminated Ascii string.    This function is similar as strlen_s defined in C11.    @param  String   A pointer to a Null-terminated Ascii string.   @param  MaxSize  The maximum number of Destination Ascii                    char, including terminating null char.    @retval 0        If String is NULL.   @retval MaxSize  If there is no null character in the first MaxSize characters of String.   @return The number of characters that percede the terminating null character.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrnLenS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|MaxSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the size of a Null-terminated Ascii string in bytes, including the   Null terminator.    This function returns the size of the Null-terminated Ascii string specified   by String in bytes, including the Null terminator.    @param  String   A pointer to a Null-terminated Ascii string.   @param  MaxSize  The maximum number of Destination Ascii                    char, including the Null terminator.    @retval 0  If String is NULL.   @retval (sizeof (CHAR8) * (MaxSize + 1))              If there is no Null terminator in the first MaxSize characters of              String.   @return The size of the Null-terminated Ascii string in bytes, including the           Null terminator.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrnSizeS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|MaxSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies the string pointed to by Source (including the terminating null char)   to the array pointed to by Destination.    This function is similar as strcpy_s defined in C11.    If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Ascii string.   @param  DestMax                  The maximum number of Destination Ascii                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Ascii string.    @retval RETURN_SUCCESS           String is copied.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumAsciiStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrCpyS
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies not more than Length successive char from the string pointed to by   Source to the array pointed to by Destination. If no null char is copied from   Source, then Destination[Length] is always set to null.    This function is similar as strncpy_s defined in C11.    If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Ascii string.   @param  DestMax                  The maximum number of Destination Ascii                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Ascii string.   @param  Length                   The maximum number of Ascii characters to copy.    @retval RETURN_SUCCESS           String is copied.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than                                     MIN(StrLen(Source), Length).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumAsciiStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrnCpyS
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Appends a copy of the string pointed to by Source (including the terminating   null char) to the end of the string pointed to by Destination.    This function is similar as strcat_s defined in C11.    If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Ascii string.   @param  DestMax                  The maximum number of Destination Ascii                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Ascii string.    @retval RETURN_SUCCESS           String is appended.   @retval RETURN_BAD_BUFFER_SIZE   If DestMax is NOT greater than                                     StrLen(Destination).   @retval RETURN_BUFFER_TOO_SMALL  If (DestMax - StrLen(Destination)) is NOT                                    greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumAsciiStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrCatS
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Appends not more than Length successive char from the string pointed to by   Source to the end of the string pointed to by Destination. If no null char is   copied from Source, then Destination[StrLen(Destination) + Length] is always   set to null.    This function is similar as strncat_s defined in C11.    If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Destination              A pointer to a Null-terminated Ascii string.   @param  DestMax                  The maximum number of Destination Ascii                                    char, including terminating null char.   @param  Source                   A pointer to a Null-terminated Ascii string.   @param  Length                   The maximum number of Ascii characters to copy.    @retval RETURN_SUCCESS           String is appended.   @retval RETURN_BAD_BUFFER_SIZE   If DestMax is NOT greater than                                    StrLen(Destination).   @retval RETURN_BUFFER_TOO_SMALL  If (DestMax - StrLen(Destination)) is NOT                                    greater than MIN(StrLen(Source), Length).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                      PcdMaximumAsciiStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrnCatS
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Ascii decimal string to a value of type UINTN.    This function outputs a value of type UINTN by interpreting the contents of   the Ascii string specified by String as a decimal number. The format of the   input Ascii string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before   [decimal digits]. The running zero in the beginning of [decimal digits] will   be ignored. Then, the function stops at the first character that is a not a   valid decimal character or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength Ascii characters, not including the   Null-terminator, then ASSERT().    If String has no valid decimal digits in the above format, then 0 is stored   at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINTN, then   MAX_UINTN is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   decimal digits right after the optional pad spaces, the value of String is   stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Ascii string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                    and String contains more than                                    PcdMaximumAsciiStringLength Ascii                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINTN.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrDecimalToUintnS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Ascii decimal string to a value of type UINT64.    This function outputs a value of type UINT64 by interpreting the contents of   the Ascii string specified by String as a decimal number. The format of the   input Ascii string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before   [decimal digits]. The running zero in the beginning of [decimal digits] will   be ignored. Then, the function stops at the first character that is a not a   valid decimal character or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength Ascii characters, not including the   Null-terminator, then ASSERT().    If String has no valid decimal digits in the above format, then 0 is stored   at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINT64, then   MAX_UINT64 is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   decimal digits right after the optional pad spaces, the value of String is   stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Ascii string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                    and String contains more than                                    PcdMaximumAsciiStringLength Ascii                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINT64.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrDecimalToUint64S
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT64
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Ascii hexadecimal string to a value of type UINTN.    This function outputs a value of type UINTN by interpreting the contents of   the Ascii string specified by String as a hexadecimal number. The format of   the input Ascii string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix. If   "x" appears in the input string, it must be prefixed with at least one 0. The   function will ignore the pad space, which includes spaces or tab characters,   before [zeros], [x] or [hexadecimal digits]. The running zero before [x] or   [hexadecimal digits] will be ignored. Then, the decoding starts after [x] or   the first valid hexadecimal digit. Then, the function stops at the first   character that is a not a valid hexadecimal character or Null-terminator,   whichever on comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength Ascii characters, not including the   Null-terminator, then ASSERT().    If String has no valid hexadecimal digits in the above format, then 0 is   stored at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINTN, then   MAX_UINTN is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   hexadecimal digits right after the optional pad spaces, the value of String   is stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Ascii string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                    and String contains more than                                    PcdMaximumAsciiStringLength Ascii                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINTN.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrHexToUintnS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Ascii hexadecimal string to a value of type UINT64.    This function outputs a value of type UINT64 by interpreting the contents of   the Ascii string specified by String as a hexadecimal number. The format of   the input Ascii string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix. If   "x" appears in the input string, it must be prefixed with at least one 0. The   function will ignore the pad space, which includes spaces or tab characters,   before [zeros], [x] or [hexadecimal digits]. The running zero before [x] or   [hexadecimal digits] will be ignored. Then, the decoding starts after [x] or   the first valid hexadecimal digit. Then, the function stops at the first   character that is a not a valid hexadecimal character or Null-terminator,   whichever on comes first.    If String is NULL, then ASSERT().   If Data is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength Ascii characters, not including the   Null-terminator, then ASSERT().    If String has no valid hexadecimal digits in the above format, then 0 is   stored at the location pointed to by Data.   If the number represented by String exceeds the range defined by UINT64, then   MAX_UINT64 is stored at the location pointed to by Data.    If EndPointer is not NULL, a pointer to the character that stopped the scan   is stored at the location pointed to by EndPointer. If String has no valid   hexadecimal digits right after the optional pad spaces, the value of String   is stored at the location pointed to by EndPointer.    @param  String                   Pointer to a Null-terminated Ascii string.   @param  EndPointer               Pointer to character that stops scan.   @param  Data                     Pointer to the converted value.    @retval RETURN_SUCCESS           Value is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                    and String contains more than                                    PcdMaximumAsciiStringLength Ascii                                    characters, not including the                                    Null-terminator.   @retval RETURN_UNSUPPORTED       If the number represented by String exceeds                                    the range defined by UINT64.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrHexToUint64S
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT64
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Copies one Null-terminated Unicode string to another Null-terminated Unicode   string and returns the new Unicode string.    This function copies the contents of the Unicode string Source to the Unicode   string Destination, and returns Destination. If Source and Destination   overlap, then the results are undefined.    If Destination is NULL, then ASSERT().   If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is NULL, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Source contains more than   PcdMaximumUnicodeStringLength Unicode characters not including the   Null-terminator, then ASSERT().    @param  Destination The pointer to a Null-terminated Unicode string.   @param  Source      The pointer to a Null-terminated Unicode string.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|StrCpy
parameter_list|(
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Copies up to a specified length from one Null-terminated Unicode string to    another Null-terminated Unicode string and returns the new Unicode string.    This function copies the contents of the Unicode string Source to the Unicode   string Destination, and returns Destination. At most, Length Unicode   characters are copied from Source to Destination. If Length is 0, then   Destination is returned unmodified. If Length is greater that the number of   Unicode characters in Source, then Destination is padded with Null Unicode   characters. If Source and Destination overlap, then the results are   undefined.    If Length> 0 and Destination is NULL, then ASSERT().   If Length> 0 and Destination is not aligned on a 16-bit boundary, then ASSERT().   If Length> 0 and Source is NULL, then ASSERT().   If Length> 0 and Source is not aligned on a 16-bit boundary, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Length is greater than    PcdMaximumUnicodeStringLength, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Source contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the Null-terminator,   then ASSERT().    @param  Destination The pointer to a Null-terminated Unicode string.   @param  Source      The pointer to a Null-terminated Unicode string.   @param  Length      The maximum number of Unicode characters to copy.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|StrnCpy
parameter_list|(
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Returns the length of a Null-terminated Unicode string.    This function returns the number of Unicode characters in the Null-terminated   Unicode string specified by String.    If String is NULL, then ASSERT().   If String is not aligned on a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters not including the   Null-terminator, then ASSERT().    @param  String  Pointer to a Null-terminated Unicode string.    @return The length of String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrLen
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the size of a Null-terminated Unicode string in bytes, including the   Null terminator.    This function returns the size, in bytes, of the Null-terminated Unicode string    specified by String.    If String is NULL, then ASSERT().   If String is not aligned on a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters not including the   Null-terminator, then ASSERT().    @param  String  The pointer to a Null-terminated Unicode string.    @return The size of String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrSize
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Compares two Null-terminated Unicode strings, and returns the difference   between the first mismatched Unicode characters.    This function compares the Null-terminated Unicode string FirstString to the   Null-terminated Unicode string SecondString. If FirstString is identical to   SecondString, then 0 is returned. Otherwise, the value returned is the first   mismatched Unicode character in SecondString subtracted from the first   mismatched Unicode character in FirstString.    If FirstString is NULL, then ASSERT().   If FirstString is not aligned on a 16-bit boundary, then ASSERT().   If SecondString is NULL, then ASSERT().   If SecondString is not aligned on a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and FirstString contains more   than PcdMaximumUnicodeStringLength Unicode characters not including the   Null-terminator, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and SecondString contains more   than PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    @param  FirstString   The pointer to a Null-terminated Unicode string.   @param  SecondString  The pointer to a Null-terminated Unicode string.    @retval 0      FirstString is identical to SecondString.   @return others FirstString is not identical to SecondString.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|StrCmp
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FirstString
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|SecondString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Compares up to a specified length the contents of two Null-terminated Unicode strings,   and returns the difference between the first mismatched Unicode characters.      This function compares the Null-terminated Unicode string FirstString to the   Null-terminated Unicode string SecondString. At most, Length Unicode   characters will be compared. If Length is 0, then 0 is returned. If   FirstString is identical to SecondString, then 0 is returned. Otherwise, the   value returned is the first mismatched Unicode character in SecondString   subtracted from the first mismatched Unicode character in FirstString.    If Length> 0 and FirstString is NULL, then ASSERT().   If Length> 0 and FirstString is not aligned on a 16-bit boundary, then ASSERT().   If Length> 0 and SecondString is NULL, then ASSERT().   If Length> 0 and SecondString is not aligned on a 16-bit boundary, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Length is greater than   PcdMaximumUnicodeStringLength, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and FirstString contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the Null-terminator,   then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and SecondString contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the Null-terminator,   then ASSERT().    @param  FirstString   The pointer to a Null-terminated Unicode string.   @param  SecondString  The pointer to a Null-terminated Unicode string.   @param  Length        The maximum number of Unicode characters to compare.    @retval 0      FirstString is identical to SecondString.   @return others FirstString is not identical to SecondString.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|StrnCmp
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FirstString
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|SecondString
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Concatenates one Null-terminated Unicode string to another Null-terminated   Unicode string, and returns the concatenated Unicode string.    This function concatenates two Null-terminated Unicode strings. The contents   of Null-terminated Unicode string Source are concatenated to the end of   Null-terminated Unicode string Destination. The Null-terminated concatenated   Unicode String is returned. If Source and Destination overlap, then the   results are undefined.    If Destination is NULL, then ASSERT().   If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is NULL, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Destination contains more   than PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Source contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and concatenating Destination   and Source results in a Unicode string with more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    @param  Destination The pointer to a Null-terminated Unicode string.   @param  Source      The pointer to a Null-terminated Unicode string.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|StrCat
parameter_list|(
name|IN
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Concatenates up to a specified length one Null-terminated Unicode to the end    of another Null-terminated Unicode string, and returns the concatenated    Unicode string.    This function concatenates two Null-terminated Unicode strings. The contents   of Null-terminated Unicode string Source are concatenated to the end of   Null-terminated Unicode string Destination, and Destination is returned. At   most, Length Unicode characters are concatenated from Source to the end of   Destination, and Destination is always Null-terminated. If Length is 0, then   Destination is returned unmodified. If Source and Destination overlap, then   the results are undefined.    If Destination is NULL, then ASSERT().   If Length> 0 and Destination is not aligned on a 16-bit boundary, then ASSERT().   If Length> 0 and Source is NULL, then ASSERT().   If Length> 0 and Source is not aligned on a 16-bit boundary, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Length is greater than    PcdMaximumUnicodeStringLength, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Destination contains more   than PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Source contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and concatenating Destination   and Source results in a Unicode string with more than PcdMaximumUnicodeStringLength   Unicode characters, not including the Null-terminator, then ASSERT().    @param  Destination The pointer to a Null-terminated Unicode string.   @param  Source      The pointer to a Null-terminated Unicode string.   @param  Length      The maximum number of Unicode characters to concatenate from                       Source.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|StrnCat
parameter_list|(
name|IN
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Returns the first occurrence of a Null-terminated Unicode sub-string   in a Null-terminated Unicode string.    This function scans the contents of the Null-terminated Unicode string   specified by String and returns the first occurrence of SearchString.   If SearchString is not found in String, then NULL is returned.  If   the length of SearchString is zero, then String is returned.    If String is NULL, then ASSERT().   If String is not aligned on a 16-bit boundary, then ASSERT().   If SearchString is NULL, then ASSERT().   If SearchString is not aligned on a 16-bit boundary, then ASSERT().    If PcdMaximumUnicodeStringLength is not zero, and SearchString   or String contains more than PcdMaximumUnicodeStringLength Unicode   characters, not including the Null-terminator, then ASSERT().    @param  String          The pointer to a Null-terminated Unicode string.   @param  SearchString    The pointer to a Null-terminated Unicode string to search for.    @retval NULL            If the SearchString does not appear in String.   @return others          If there is a match.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|StrStr
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|SearchString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode decimal string to a value of   type UINTN.    This function returns a value of type UINTN by interpreting the contents   of the Unicode string specified by String as a decimal number. The format   of the input Unicode string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The   function will ignore the pad space, which includes spaces or   tab characters, before [decimal digits]. The running zero in the   beginning of [decimal digits] will be ignored. Then, the function   stops at the first character that is a not a valid decimal character   or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If String has only pad spaces, then 0 is returned.   If String has no pad spaces or valid decimal digits,   then 0 is returned.   If the number represented by String overflows according   to the range defined by UINTN, then MAX_UINTN is returned.    If PcdMaximumUnicodeStringLength is not zero, and String contains   more than PcdMaximumUnicodeStringLength Unicode characters not including   the Null-terminator, then ASSERT().    @param  String      The pointer to a Null-terminated Unicode string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrDecimalToUintn
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode decimal string to a value of   type UINT64.    This function returns a value of type UINT64 by interpreting the contents   of the Unicode string specified by String as a decimal number. The format   of the input Unicode string String is:                    [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The   function will ignore the pad space, which includes spaces or   tab characters, before [decimal digits]. The running zero in the   beginning of [decimal digits] will be ignored. Then, the function   stops at the first character that is a not a valid decimal character   or a Null-terminator, whichever one comes first.    If String is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If String has only pad spaces, then 0 is returned.   If String has no pad spaces or valid decimal digits,   then 0 is returned.   If the number represented by String overflows according   to the range defined by UINT64, then MAX_UINT64 is returned.    If PcdMaximumUnicodeStringLength is not zero, and String contains   more than PcdMaximumUnicodeStringLength Unicode characters not including   the Null-terminator, then ASSERT().    @param  String          The pointer to a Null-terminated Unicode string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|StrDecimalToUint64
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode hexadecimal string to a value of type UINTN.    This function returns a value of type UINTN by interpreting the contents   of the Unicode string specified by String as a hexadecimal number.   The format of the input Unicode string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix.   If "x" appears in the input string, it must be prefixed with at least one 0.   The function will ignore the pad space, which includes spaces or tab characters,   before [zeros], [x] or [hexadecimal digit]. The running zero before [x] or   [hexadecimal digit] will be ignored. Then, the decoding starts after [x] or the   first valid hexadecimal digit. Then, the function stops at the first character    that is a not a valid hexadecimal character or NULL, whichever one comes first.    If String is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If String has only pad spaces, then zero is returned.   If String has no leading pad spaces, leading zeros or valid hexadecimal digits,   then zero is returned.   If the number represented by String overflows according to the range defined by   UINTN, then MAX_UINTN is returned.    If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters not including the Null-terminator,   then ASSERT().    @param  String          The pointer to a Null-terminated Unicode string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|StrHexToUintn
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode hexadecimal string to a value of type UINT64.    This function returns a value of type UINT64 by interpreting the contents   of the Unicode string specified by String as a hexadecimal number.   The format of the input Unicode string String is                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix.   If "x" appears in the input string, it must be prefixed with at least one 0.   The function will ignore the pad space, which includes spaces or tab characters,   before [zeros], [x] or [hexadecimal digit]. The running zero before [x] or   [hexadecimal digit] will be ignored. Then, the decoding starts after [x] or the   first valid hexadecimal digit. Then, the function stops at the first character that is   a not a valid hexadecimal character or NULL, whichever one comes first.    If String is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().   If String has only pad spaces, then zero is returned.   If String has no leading pad spaces, leading zeros or valid hexadecimal digits,   then zero is returned.   If the number represented by String overflows according to the range defined by   UINT64, then MAX_UINT64 is returned.    If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters not including the Null-terminator,   then ASSERT().    @param  String          The pointer to a Null-terminated Unicode string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|StrHexToUint64
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode string to IPv6 address and prefix length.    This function outputs a value of type IPv6_ADDRESS and may output a value   of type UINT8 by interpreting the contents of the Unicode string specified   by String. The format of the input Unicode string String is as follows:                    X:X:X:X:X:X:X:X[/P]    X contains one to four hexadecimal digit characters in the range [0-9], [a-f] and   [A-F]. X is converted to a value of type UINT16, whose low byte is stored in low   memory address and high byte is stored in high memory address. P contains decimal   digit characters in the range [0-9]. The running zero in the beginning of P will   be ignored. /P is optional.    When /P is not in the String, the function stops at the first character that is   not a valid hexadecimal digit character after eight X's are converted.    When /P is in the String, the function stops at the first character that is not   a valid decimal digit character after P is converted.    "::" can be used to compress one or more groups of X when X contains only 0.   The "::" can only appear once in the String.    If String is NULL, then ASSERT().    If Address is NULL, then ASSERT().    If String is not aligned in a 16-bit boundary, then ASSERT().    If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If EndPointer is not NULL and Address is translated from String, a pointer   to the character that stopped the scan is stored at the location pointed to   by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Address                  Pointer to the converted IPv6 address.   @param  PrefixLength             Pointer to the converted IPv6 address prefix                                    length. MAX_UINT8 is returned when /P is                                    not in the String.    @retval RETURN_SUCCESS           Address is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If X contains more than four hexadecimal                                     digit characters.                                    If String contains "::" and number of X                                     is not less than 8.                                    If P starts with character that is not a                                     valid decimal digit character.                                    If the decimal number converted from P                                     exceeds 128.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrToIpv6Address
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|IPv6_ADDRESS
modifier|*
name|Address
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PrefixLength
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode string to IPv4 address and prefix length.    This function outputs a value of type IPv4_ADDRESS and may output a value   of type UINT8 by interpreting the contents of the Unicode string specified   by String. The format of the input Unicode string String is as follows:                    D.D.D.D[/P]    D and P are decimal digit characters in the range [0-9]. The running zero in   the beginning of D and P will be ignored. /P is optional.    When /P is not in the String, the function stops at the first character that is   not a valid decimal digit character after four D's are converted.    When /P is in the String, the function stops at the first character that is not   a valid decimal digit character after P is converted.    If String is NULL, then ASSERT().    If Address is NULL, then ASSERT().    If String is not aligned in a 16-bit boundary, then ASSERT().    If PcdMaximumUnicodeStringLength is not zero, and String contains more than   PcdMaximumUnicodeStringLength Unicode characters, not including the   Null-terminator, then ASSERT().    If EndPointer is not NULL and Address is translated from String, a pointer   to the character that stopped the scan is stored at the location pointed to   by EndPointer.    @param  String                   Pointer to a Null-terminated Unicode string.   @param  EndPointer               Pointer to character that stops scan.   @param  Address                  Pointer to the converted IPv4 address.   @param  PrefixLength             Pointer to the converted IPv4 address prefix                                    length. MAX_UINT8 is returned when /P is                                    not in the String.    @retval RETURN_SUCCESS           Address is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If String is not in the correct format.                                    If any decimal number converted from D                                     exceeds 255.                                    If the decimal number converted from P                                     exceeds 32.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrToIpv4Address
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|IPv4_ADDRESS
modifier|*
name|Address
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PrefixLength
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GUID_STRING_LENGTH
value|36
end_define

begin_comment
comment|/**   Convert a Null-terminated Unicode GUID string to a value of type   EFI_GUID.    This function outputs a GUID value by interpreting the contents of   the Unicode string specified by String. The format of the input   Unicode string String consists of 36 characters, as follows:                    aabbccdd-eeff-gghh-iijj-kkllmmnnoopp    The pairs aa - pp are two characters in the range [0-9], [a-f] and   [A-F], with each pair representing a single byte hexadecimal value.    The mapping between String and the EFI_GUID structure is as follows:                   aa          Data1[24:31]                   bb          Data1[16:23]                   cc          Data1[8:15]                   dd          Data1[0:7]                   ee          Data2[8:15]                   ff          Data2[0:7]                   gg          Data3[8:15]                   hh          Data3[0:7]                   ii          Data4[0:7]                   jj          Data4[8:15]                   kk          Data4[16:23]                   ll          Data4[24:31]                   mm          Data4[32:39]                   nn          Data4[40:47]                   oo          Data4[48:55]                   pp          Data4[56:63]    If String is NULL, then ASSERT().   If Guid is NULL, then ASSERT().   If String is not aligned in a 16-bit boundary, then ASSERT().    @param  String                   Pointer to a Null-terminated Unicode string.   @param  Guid                     Pointer to the converted GUID.    @retval RETURN_SUCCESS           Guid is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If String is not as the above format.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrToGuid
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OUT
name|GUID
modifier|*
name|Guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated Unicode hexadecimal string to a byte array.    This function outputs a byte array by interpreting the contents of   the Unicode string specified by String in hexadecimal format. The format of   the input Unicode string String is:                    [XX]*    X is a hexadecimal digit character in the range [0-9], [a-f] and [A-F].   The function decodes every two hexadecimal digit characters as one byte. The   decoding stops after Length of characters and outputs Buffer containing   (Length / 2) bytes.    If String is not aligned in a 16-bit boundary, then ASSERT().    If String is NULL, then ASSERT().    If Buffer is NULL, then ASSERT().    If Length is not multiple of 2, then ASSERT().    If PcdMaximumUnicodeStringLength is not zero and Length is greater than   PcdMaximumUnicodeStringLength, then ASSERT().    If MaxBufferSize is less than (Length / 2), then ASSERT().    @param  String                   Pointer to a Null-terminated Unicode string.   @param  Length                   The number of Unicode characters to decode.   @param  Buffer                   Pointer to the converted bytes array.   @param  MaxBufferSize            The maximum size of Buffer.    @retval RETURN_SUCCESS           Buffer is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If Length is not multiple of 2.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and Length is greater than                                     PcdMaximumUnicodeStringLength.   @retval RETURN_UNSUPPORTED       If Length of characters from String contain                                     a character that is not valid hexadecimal                                     digit characters, or a Null-terminator.   @retval RETURN_BUFFER_TOO_SMALL  If MaxBufferSize is less than (Length / 2). **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StrHexToBytes
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|MaxBufferSize
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Convert a Null-terminated Unicode string to a Null-terminated   ASCII string and returns the ASCII string.    This function converts the content of the Unicode string Source   to the ASCII string Destination by copying the lower 8 bits of   each Unicode character. It returns Destination.    The caller is responsible to make sure Destination points to a buffer with size   equal or greater than ((StrLen (Source) + 1) * sizeof (CHAR8)) in bytes.    If any Unicode characters in Source contain non-zero value in   the upper 8 bits, then ASSERT().    If Destination is NULL, then ASSERT().   If Source is NULL, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If Source and Destination overlap, then ASSERT().    If PcdMaximumUnicodeStringLength is not zero, and Source contains   more than PcdMaximumUnicodeStringLength Unicode characters not including   the Null-terminator, then ASSERT().    If PcdMaximumAsciiStringLength is not zero, and Source contains more   than PcdMaximumAsciiStringLength Unicode characters not including the   Null-terminator, then ASSERT().    @param  Source        The pointer to a Null-terminated Unicode string.   @param  Destination   The pointer to a Null-terminated ASCII string.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|UnicodeStrToAsciiStr
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Convert a Null-terminated Unicode string to a Null-terminated   ASCII string.    This function is similar to AsciiStrCpyS.    This function converts the content of the Unicode string Source   to the ASCII string Destination by copying the lower 8 bits of   each Unicode character. The function terminates the ASCII string   Destination by appending a Null-terminator character at the end.    The caller is responsible to make sure Destination points to a buffer with size   equal or greater than ((StrLen (Source) + 1) * sizeof (CHAR8)) in bytes.    If any Unicode characters in Source contain non-zero value in   the upper 8 bits, then ASSERT().    If Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Source        The pointer to a Null-terminated Unicode string.   @param  Destination   The pointer to a Null-terminated ASCII string.   @param  DestMax       The maximum number of Destination Ascii                         char, including terminating null char.    @retval RETURN_SUCCESS           String is converted.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                     PcdMaximumAsciiStringLength.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                     PcdMaximumUnicodeStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|UnicodeStrToAsciiStrS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert not more than Length successive characters from a Null-terminated   Unicode string to a Null-terminated Ascii string. If no null char is copied   from Source, then Destination[Length] is always set to null.    This function converts not more than Length successive characters from the   Unicode string Source to the Ascii string Destination by copying the lower 8   bits of each Unicode character. The function terminates the Ascii string   Destination by appending a Null-terminator character at the end.    The caller is responsible to make sure Destination points to a buffer with size   equal or greater than ((StrLen (Source) + 1) * sizeof (CHAR8)) in bytes.    If any Unicode characters in Source contain non-zero value in the upper 8   bits, then ASSERT().   If Source is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Source             The pointer to a Null-terminated Unicode string.   @param  Length             The maximum number of Unicode characters to                              convert.   @param  Destination        The pointer to a Null-terminated Ascii string.   @param  DestMax            The maximum number of Destination Ascii                              char, including terminating null char.   @param  DestinationLength  The number of Unicode characters converted.    @retval RETURN_SUCCESS            String is converted.   @retval RETURN_INVALID_PARAMETER  If Destination is NULL.                                     If Source is NULL.                                     If DestinationLength is NULL.                                     If PcdMaximumAsciiStringLength is not zero,                                     and Length or DestMax is greater than                                     PcdMaximumAsciiStringLength.                                     If PcdMaximumUnicodeStringLength is not                                     zero, and Length or DestMax is greater than                                     PcdMaximumUnicodeStringLength.                                     If DestMax is 0.   @retval RETURN_BUFFER_TOO_SMALL   If DestMax is NOT greater than                                     MIN(StrLen(Source), Length).   @retval RETURN_ACCESS_DENIED      If Source and Destination overlap.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|UnicodeStrnToAsciiStrS
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DestinationLength
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Copies one Null-terminated ASCII string to another Null-terminated ASCII   string and returns the new ASCII string.    This function copies the contents of the ASCII string Source to the ASCII   string Destination, and returns Destination. If Source and Destination   overlap, then the results are undefined.    If Destination is NULL, then ASSERT().   If Source is NULL, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and Source contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().    @param  Destination The pointer to a Null-terminated ASCII string.   @param  Source      The pointer to a Null-terminated ASCII string.    @return Destination  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|AsciiStrCpy
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Copies up to a specified length one Null-terminated ASCII string to another    Null-terminated ASCII string and returns the new ASCII string.    This function copies the contents of the ASCII string Source to the ASCII   string Destination, and returns Destination. At most, Length ASCII characters   are copied from Source to Destination. If Length is 0, then Destination is   returned unmodified. If Length is greater that the number of ASCII characters   in Source, then Destination is padded with Null ASCII characters. If Source   and Destination overlap, then the results are undefined.    If Destination is NULL, then ASSERT().   If Source is NULL, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Length is greater than    PcdMaximumAsciiStringLength, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Source contains more than   PcdMaximumAsciiStringLength ASCII characters, not including the Null-terminator,   then ASSERT().    @param  Destination The pointer to a Null-terminated ASCII string.   @param  Source      The pointer to a Null-terminated ASCII string.   @param  Length      The maximum number of ASCII characters to copy.    @return Destination  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|AsciiStrnCpy
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Returns the length of a Null-terminated ASCII string.    This function returns the number of ASCII characters in the Null-terminated   ASCII string specified by String.    If Length> 0 and Destination is NULL, then ASSERT().   If Length> 0 and Source is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and String contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().    @param  String  The pointer to a Null-terminated ASCII string.    @return The length of String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrLen
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the size of a Null-terminated ASCII string in bytes, including the   Null terminator.    This function returns the size, in bytes, of the Null-terminated ASCII string   specified by String.    If String is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and String contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().    @param  String  The pointer to a Null-terminated ASCII string.    @return The size of String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrSize
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Compares two Null-terminated ASCII strings, and returns the difference   between the first mismatched ASCII characters.    This function compares the Null-terminated ASCII string FirstString to the   Null-terminated ASCII string SecondString. If FirstString is identical to   SecondString, then 0 is returned. Otherwise, the value returned is the first   mismatched ASCII character in SecondString subtracted from the first   mismatched ASCII character in FirstString.    If FirstString is NULL, then ASSERT().   If SecondString is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and FirstString contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero and SecondString contains more   than PcdMaximumAsciiStringLength ASCII characters not including the   Null-terminator, then ASSERT().    @param  FirstString   The pointer to a Null-terminated ASCII string.   @param  SecondString  The pointer to a Null-terminated ASCII string.    @retval ==0      FirstString is identical to SecondString.   @retval !=0      FirstString is not identical to SecondString.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|AsciiStrCmp
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|FirstString
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SecondString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a case insensitive comparison of two Null-terminated ASCII strings,   and returns the difference between the first mismatched ASCII characters.    This function performs a case insensitive comparison of the Null-terminated   ASCII string FirstString to the Null-terminated ASCII string SecondString. If   FirstString is identical to SecondString, then 0 is returned. Otherwise, the   value returned is the first mismatched lower case ASCII character in   SecondString subtracted from the first mismatched lower case ASCII character   in FirstString.    If FirstString is NULL, then ASSERT().   If SecondString is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and FirstString contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero and SecondString contains more   than PcdMaximumAsciiStringLength ASCII characters not including the   Null-terminator, then ASSERT().    @param  FirstString   The pointer to a Null-terminated ASCII string.   @param  SecondString  The pointer to a Null-terminated ASCII string.    @retval ==0    FirstString is identical to SecondString using case insensitive                  comparisons.   @retval !=0    FirstString is not identical to SecondString using case                  insensitive comparisons.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|AsciiStriCmp
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|FirstString
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SecondString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Compares two Null-terminated ASCII strings with maximum lengths, and returns   the difference between the first mismatched ASCII characters.    This function compares the Null-terminated ASCII string FirstString to the   Null-terminated ASCII  string SecondString. At most, Length ASCII characters   will be compared. If Length is 0, then 0 is returned. If FirstString is   identical to SecondString, then 0 is returned. Otherwise, the value returned   is the first mismatched ASCII character in SecondString subtracted from the   first mismatched ASCII character in FirstString.    If Length> 0 and FirstString is NULL, then ASSERT().   If Length> 0 and SecondString is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Length is greater than    PcdMaximumAsciiStringLength, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and FirstString contains more than   PcdMaximumAsciiStringLength ASCII characters, not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and SecondString contains more than   PcdMaximumAsciiStringLength ASCII characters, not including the Null-terminator,   then ASSERT().    @param  FirstString   The pointer to a Null-terminated ASCII string.   @param  SecondString  The pointer to a Null-terminated ASCII string.   @param  Length        The maximum number of ASCII characters for compare.      @retval ==0       FirstString is identical to SecondString.   @retval !=0       FirstString is not identical to SecondString.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|AsciiStrnCmp
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|FirstString
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SecondString
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Concatenates one Null-terminated ASCII string to another Null-terminated   ASCII string, and returns the concatenated ASCII string.    This function concatenates two Null-terminated ASCII strings. The contents of   Null-terminated ASCII string Source are concatenated to the end of Null-   terminated ASCII string Destination. The Null-terminated concatenated ASCII   String is returned.    If Destination is NULL, then ASSERT().   If Source is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero and Destination contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero and Source contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero and concatenating Destination and   Source results in a ASCII string with more than PcdMaximumAsciiStringLength   ASCII characters, then ASSERT().    @param  Destination The pointer to a Null-terminated ASCII string.   @param  Source      The pointer to a Null-terminated ASCII string.    @return Destination  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|AsciiStrCat
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Concatenates up to a specified length one Null-terminated ASCII string to    the end of another Null-terminated ASCII string, and returns the    concatenated ASCII string.    This function concatenates two Null-terminated ASCII strings. The contents   of Null-terminated ASCII string Source are concatenated to the end of Null-   terminated ASCII string Destination, and Destination is returned. At most,   Length ASCII characters are concatenated from Source to the end of   Destination, and Destination is always Null-terminated. If Length is 0, then   Destination is returned unmodified. If Source and Destination overlap, then   the results are undefined.    If Length> 0 and Destination is NULL, then ASSERT().   If Length> 0 and Source is NULL, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Length is greater than   PcdMaximumAsciiStringLength, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Destination contains more than   PcdMaximumAsciiStringLength ASCII characters, not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Source contains more than   PcdMaximumAsciiStringLength ASCII characters, not including the Null-terminator,   then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and concatenating Destination and   Source results in a ASCII string with more than PcdMaximumAsciiStringLength   ASCII characters, not including the Null-terminator, then ASSERT().    @param  Destination The pointer to a Null-terminated ASCII string.   @param  Source      The pointer to a Null-terminated ASCII string.   @param  Length      The maximum number of ASCII characters to concatenate from                       Source.    @return Destination  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|AsciiStrnCat
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Returns the first occurrence of a Null-terminated ASCII sub-string   in a Null-terminated ASCII string.    This function scans the contents of the ASCII string specified by String   and returns the first occurrence of SearchString. If SearchString is not   found in String, then NULL is returned. If the length of SearchString is zero,   then String is returned.    If String is NULL, then ASSERT().   If SearchString is NULL, then ASSERT().    If PcdMaximumAsciiStringLength is not zero, and SearchString or   String contains more than PcdMaximumAsciiStringLength Unicode characters   not including the Null-terminator, then ASSERT().    @param  String          The pointer to a Null-terminated ASCII string.   @param  SearchString    The pointer to a Null-terminated ASCII string to search for.    @retval NULL            If the SearchString does not appear in String.   @retval others          If there is a match return the first occurrence of SearchingString.                           If the length of SearchString is zero,return String.  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|AsciiStrStr
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SearchString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII decimal string to a value of type   UINTN.    This function returns a value of type UINTN by interpreting the contents   of the ASCII string String as a decimal number. The format of the input   ASCII string String is:                      [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before the digits.   The running zero in the beginning of [decimal digits] will be ignored. Then, the   function stops at the first character that is a not a valid decimal character or   Null-terminator, whichever on comes first.    If String has only pad spaces, then 0 is returned.   If String has no pad spaces or valid decimal digits, then 0 is returned.   If the number represented by String overflows according to the range defined by   UINTN, then MAX_UINTN is returned.   If String is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().    @param  String          The pointer to a Null-terminated ASCII string.    @retval The value translated from String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrDecimalToUintn
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII decimal string to a value of type   UINT64.    This function returns a value of type UINT64 by interpreting the contents   of the ASCII string String as a decimal number. The format of the input   ASCII string String is:                      [spaces] [decimal digits].    The valid decimal digit character is in the range [0-9]. The function will   ignore the pad space, which includes spaces or tab characters, before the digits.   The running zero in the beginning of [decimal digits] will be ignored. Then, the   function stops at the first character that is a not a valid decimal character or   Null-terminator, whichever on comes first.    If String has only pad spaces, then 0 is returned.   If String has no pad spaces or valid decimal digits, then 0 is returned.   If the number represented by String overflows according to the range defined by   UINT64, then MAX_UINT64 is returned.   If String is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and String contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().    @param  String          The pointer to a Null-terminated ASCII string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsciiStrDecimalToUint64
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII hexadecimal string to a value of type UINTN.    This function returns a value of type UINTN by interpreting the contents of   the ASCII string String as a hexadecimal number. The format of the input ASCII   string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix. If "x"   appears in the input string, it must be prefixed with at least one 0. The function   will ignore the pad space, which includes spaces or tab characters, before [zeros],   [x] or [hexadecimal digits]. The running zero before [x] or [hexadecimal digits]   will be ignored. Then, the decoding starts after [x] or the first valid hexadecimal   digit. Then, the function stops at the first character that is a not a valid   hexadecimal character or Null-terminator, whichever on comes first.    If String has only pad spaces, then 0 is returned.   If String has no leading pad spaces, leading zeros or valid hexadecimal digits, then   0 is returned.    If the number represented by String overflows according to the range defined by UINTN,   then MAX_UINTN is returned.   If String is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero,   and String contains more than PcdMaximumAsciiStringLength ASCII characters not including   the Null-terminator, then ASSERT().    @param  String          The pointer to a Null-terminated ASCII string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiStrHexToUintn
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII hexadecimal string to a value of type UINT64.    This function returns a value of type UINT64 by interpreting the contents of   the ASCII string String as a hexadecimal number. The format of the input ASCII   string String is:                    [spaces][zeros][x][hexadecimal digits].    The valid hexadecimal digit character is in the range [0-9], [a-f] and [A-F].   The prefix "0x" is optional. Both "x" and "X" is allowed in "0x" prefix. If "x"   appears in the input string, it must be prefixed with at least one 0. The function   will ignore the pad space, which includes spaces or tab characters, before [zeros],   [x] or [hexadecimal digits]. The running zero before [x] or [hexadecimal digits]   will be ignored. Then, the decoding starts after [x] or the first valid hexadecimal   digit. Then, the function stops at the first character that is a not a valid   hexadecimal character or Null-terminator, whichever on comes first.    If String has only pad spaces, then 0 is returned.   If String has no leading pad spaces, leading zeros or valid hexadecimal digits, then   0 is returned.    If the number represented by String overflows according to the range defined by UINT64,   then MAX_UINT64 is returned.   If String is NULL, then ASSERT().   If PcdMaximumAsciiStringLength is not zero,   and String contains more than PcdMaximumAsciiStringLength ASCII characters not including   the Null-terminator, then ASSERT().    @param  String          The pointer to a Null-terminated ASCII string.    @retval Value translated from String.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsciiStrHexToUint64
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII string to IPv6 address and prefix length.    This function outputs a value of type IPv6_ADDRESS and may output a value   of type UINT8 by interpreting the contents of the ASCII string specified   by String. The format of the input ASCII string String is as follows:                    X:X:X:X:X:X:X:X[/P]    X contains one to four hexadecimal digit characters in the range [0-9], [a-f] and   [A-F]. X is converted to a value of type UINT16, whose low byte is stored in low   memory address and high byte is stored in high memory address. P contains decimal   digit characters in the range [0-9]. The running zero in the beginning of P will   be ignored. /P is optional.    When /P is not in the String, the function stops at the first character that is   not a valid hexadecimal digit character after eight X's are converted.    When /P is in the String, the function stops at the first character that is not   a valid decimal digit character after P is converted.    "::" can be used to compress one or more groups of X when X contains only 0.   The "::" can only appear once in the String.    If String is NULL, then ASSERT().    If Address is NULL, then ASSERT().    If EndPointer is not NULL and Address is translated from String, a pointer   to the character that stopped the scan is stored at the location pointed to   by EndPointer.    @param  String                   Pointer to a Null-terminated ASCII string.   @param  EndPointer               Pointer to character that stops scan.   @param  Address                  Pointer to the converted IPv6 address.   @param  PrefixLength             Pointer to the converted IPv6 address prefix                                    length. MAX_UINT8 is returned when /P is                                    not in the String.    @retval RETURN_SUCCESS           Address is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If X contains more than four hexadecimal                                     digit characters.                                    If String contains "::" and number of X                                     is not less than 8.                                    If P starts with character that is not a                                     valid decimal digit character.                                    If the decimal number converted from P                                     exceeds 128.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrToIpv6Address
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|IPv6_ADDRESS
modifier|*
name|Address
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PrefixLength
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII string to IPv4 address and prefix length.    This function outputs a value of type IPv4_ADDRESS and may output a value   of type UINT8 by interpreting the contents of the ASCII string specified   by String. The format of the input ASCII string String is as follows:                    D.D.D.D[/P]    D and P are decimal digit characters in the range [0-9]. The running zero in   the beginning of D and P will be ignored. /P is optional.    When /P is not in the String, the function stops at the first character that is   not a valid decimal digit character after four D's are converted.    When /P is in the String, the function stops at the first character that is not   a valid decimal digit character after P is converted.    If String is NULL, then ASSERT().    If Address is NULL, then ASSERT().    If EndPointer is not NULL and Address is translated from String, a pointer   to the character that stopped the scan is stored at the location pointed to   by EndPointer.    @param  String                   Pointer to a Null-terminated ASCII string.   @param  EndPointer               Pointer to character that stops scan.   @param  Address                  Pointer to the converted IPv4 address.   @param  PrefixLength             Pointer to the converted IPv4 address prefix                                    length. MAX_UINT8 is returned when /P is                                    not in the String.    @retval RETURN_SUCCESS           Address is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If String is not in the correct format.                                    If any decimal number converted from D                                     exceeds 255.                                    If the decimal number converted from P                                     exceeds 32.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrToIpv4Address
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|CHAR8
modifier|*
modifier|*
name|EndPointer
parameter_list|,
name|OPTIONAL
name|OUT
name|IPv4_ADDRESS
modifier|*
name|Address
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PrefixLength
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII GUID string to a value of type   EFI_GUID.    This function outputs a GUID value by interpreting the contents of   the ASCII string specified by String. The format of the input   ASCII string String consists of 36 characters, as follows:                    aabbccdd-eeff-gghh-iijj-kkllmmnnoopp    The pairs aa - pp are two characters in the range [0-9], [a-f] and   [A-F], with each pair representing a single byte hexadecimal value.    The mapping between String and the EFI_GUID structure is as follows:                   aa          Data1[24:31]                   bb          Data1[16:23]                   cc          Data1[8:15]                   dd          Data1[0:7]                   ee          Data2[8:15]                   ff          Data2[0:7]                   gg          Data3[8:15]                   hh          Data3[0:7]                   ii          Data4[0:7]                   jj          Data4[8:15]                   kk          Data4[16:23]                   ll          Data4[24:31]                   mm          Data4[32:39]                   nn          Data4[40:47]                   oo          Data4[48:55]                   pp          Data4[56:63]    If String is NULL, then ASSERT().   If Guid is NULL, then ASSERT().    @param  String                   Pointer to a Null-terminated ASCII string.   @param  Guid                     Pointer to the converted GUID.    @retval RETURN_SUCCESS           Guid is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.   @retval RETURN_UNSUPPORTED       If String is not as the above format.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrToGuid
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|OUT
name|GUID
modifier|*
name|Guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert a Null-terminated ASCII hexadecimal string to a byte array.    This function outputs a byte array by interpreting the contents of   the ASCII string specified by String in hexadecimal format. The format of   the input ASCII string String is:                    [XX]*    X is a hexadecimal digit character in the range [0-9], [a-f] and [A-F].   The function decodes every two hexadecimal digit characters as one byte. The   decoding stops after Length of characters and outputs Buffer containing   (Length / 2) bytes.    If String is NULL, then ASSERT().    If Buffer is NULL, then ASSERT().    If Length is not multiple of 2, then ASSERT().    If PcdMaximumAsciiStringLength is not zero and Length is greater than   PcdMaximumAsciiStringLength, then ASSERT().    If MaxBufferSize is less than (Length / 2), then ASSERT().    @param  String                   Pointer to a Null-terminated ASCII string.   @param  Length                   The number of ASCII characters to decode.   @param  Buffer                   Pointer to the converted bytes array.   @param  MaxBufferSize            The maximum size of Buffer.    @retval RETURN_SUCCESS           Buffer is translated from String.   @retval RETURN_INVALID_PARAMETER If String is NULL.                                    If Data is NULL.                                    If Length is not multiple of 2.                                    If PcdMaximumAsciiStringLength is not zero,                                     and Length is greater than                                     PcdMaximumAsciiStringLength.   @retval RETURN_UNSUPPORTED       If Length of characters from String contain                                     a character that is not valid hexadecimal                                     digit characters, or a Null-terminator.   @retval RETURN_BUFFER_TOO_SMALL  If MaxBufferSize is less than (Length / 2). **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrHexToBytes
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|MaxBufferSize
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function is deprecated for security reason.    Convert one Null-terminated ASCII string to a Null-terminated   Unicode string and returns the Unicode string.    This function converts the contents of the ASCII string Source to the Unicode   string Destination, and returns Destination.  The function terminates the   Unicode string Destination by appending a Null-terminator character at the end.   The caller is responsible to make sure Destination points to a buffer with size   equal or greater than ((AsciiStrLen (Source) + 1) * sizeof (CHAR16)) in bytes.    If Destination is NULL, then ASSERT().   If Destination is not aligned on a 16-bit boundary, then ASSERT().   If Source is NULL, then ASSERT().   If Source and Destination overlap, then ASSERT().   If PcdMaximumAsciiStringLength is not zero, and Source contains more than   PcdMaximumAsciiStringLength ASCII characters not including the Null-terminator,   then ASSERT().   If PcdMaximumUnicodeStringLength is not zero, and Source contains more than   PcdMaximumUnicodeStringLength ASCII characters not including the   Null-terminator, then ASSERT().    @param  Source        The pointer to a Null-terminated ASCII string.   @param  Destination   The pointer to a Null-terminated Unicode string.    @return Destination.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|AsciiStrToUnicodeStr
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Convert one Null-terminated ASCII string to a Null-terminated   Unicode string.    This function is similar to StrCpyS.    This function converts the contents of the ASCII string Source to the Unicode   string Destination. The function terminates the Unicode string Destination by   appending a Null-terminator character at the end.    The caller is responsible to make sure Destination points to a buffer with size   equal or greater than ((AsciiStrLen (Source) + 1) * sizeof (CHAR16)) in bytes.    If Destination is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then the Destination is unmodified.    @param  Source        The pointer to a Null-terminated ASCII string.   @param  Destination   The pointer to a Null-terminated Unicode string.   @param  DestMax       The maximum number of Destination Unicode                         char, including terminating null char.    @retval RETURN_SUCCESS           String is converted.   @retval RETURN_BUFFER_TOO_SMALL  If DestMax is NOT greater than StrLen(Source).   @retval RETURN_INVALID_PARAMETER If Destination is NULL.                                    If Source is NULL.                                    If PcdMaximumUnicodeStringLength is not zero,                                     and DestMax is greater than                                     PcdMaximumUnicodeStringLength.                                    If PcdMaximumAsciiStringLength is not zero,                                     and DestMax is greater than                                     PcdMaximumAsciiStringLength.                                    If DestMax is 0.   @retval RETURN_ACCESS_DENIED     If Source and Destination overlap.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrToUnicodeStrS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert not more than Length successive characters from a Null-terminated   Ascii string to a Null-terminated Unicode string. If no null char is copied   from Source, then Destination[Length] is always set to null.    This function converts not more than Length successive characters from the   Ascii string Source to the Unicode string Destination. The function   terminates the Unicode string Destination by appending a Null-terminator   character at the end.    The caller is responsible to make sure Destination points to a buffer with   size not smaller than   ((MIN(AsciiStrLen(Source), Length) + 1) * sizeof (CHAR8)) in bytes.    If Destination is not aligned on a 16-bit boundary, then ASSERT().   If an error would be returned, then the function will also ASSERT().    If an error is returned, then Destination and DestinationLength are   unmodified.    @param  Source             The pointer to a Null-terminated Ascii string.   @param  Length             The maximum number of Ascii characters to convert.   @param  Destination        The pointer to a Null-terminated Unicode string.   @param  DestMax            The maximum number of Destination Unicode char,                              including terminating null char.   @param  DestinationLength  The number of Ascii characters converted.    @retval RETURN_SUCCESS            String is converted.   @retval RETURN_INVALID_PARAMETER  If Destination is NULL.                                     If Source is NULL.                                     If DestinationLength is NULL.                                     If PcdMaximumUnicodeStringLength is not                                     zero, and Length or DestMax is greater than                                     PcdMaximumUnicodeStringLength.                                     If PcdMaximumAsciiStringLength is not zero,                                     and Length or DestMax is greater than                                     PcdMaximumAsciiStringLength.                                     If DestMax is 0.   @retval RETURN_BUFFER_TOO_SMALL   If DestMax is NOT greater than                                     MIN(AsciiStrLen(Source), Length).   @retval RETURN_ACCESS_DENIED      If Source and Destination overlap.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|AsciiStrnToUnicodeStrS
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|CHAR16
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINTN
name|DestMax
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DestinationLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Converts an 8-bit value to an 8-bit BCD value.    Converts the 8-bit value specified by Value to BCD. The BCD value is   returned.    If Value>= 100, then ASSERT().    @param  Value The 8-bit value to convert to BCD. Range 0..99.    @return The BCD value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|DecimalToBcd8
parameter_list|(
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Converts an 8-bit BCD value to an 8-bit value.    Converts the 8-bit BCD value specified by Value to an 8-bit value. The 8-bit   value is returned.    If Value>= 0xA0, then ASSERT().   If (Value& 0x0F)>= 0x0A, then ASSERT().    @param  Value The 8-bit BCD value to convert to an 8-bit value.    @return The 8-bit value is returned.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BcdToDecimal8
parameter_list|(
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|//  File Path Manipulation Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Removes the last directory or file entry in a path.    @param[in, out] Path    The pointer to the path to modify.    @retval FALSE     Nothing was found to remove.   @retval TRUE      A directory or file was removed. **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|PathRemoveLastItem
parameter_list|(
name|IN
name|OUT
name|CHAR16
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to clean up paths.     - Single periods in the path are removed.     - Double periods in the path are removed along with a single parent directory.     - Forward slashes L'/' are converted to backward slashes L'\'.    This will be done inline and the existing buffer may be larger than required   upon completion.    @param[in] Path       The pointer to the string containing the path.    @return       Returns Path, otherwise returns NULL to indicate that an error has occurred. **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|PathCleanUpDirectories
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// Linked List Functions and Macros
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Initializes the head node of a doubly linked list that is declared as a   global variable in a module.    Initializes the forward and backward links of a new linked list. After   initializing a linked list with this macro, the other linked list functions   may be used to add and remove nodes from the linked list. This macro results   in smaller executables by initializing the linked list in the data section,   instead if calling the InitializeListHead() function to perform the   equivalent operation.    @param  ListHead  The head note of a list to initialize.  **/
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_LIST_HEAD_VARIABLE
parameter_list|(
name|ListHead
parameter_list|)
value|{&(ListHead),&(ListHead)}
end_define

begin_comment
comment|/**   Initializes the head node of a doubly linked list, and returns the pointer to   the head node of the doubly linked list.    Initializes the forward and backward links of a new linked list. After   initializing a linked list with this function, the other linked list   functions may be used to add and remove nodes from the linked list. It is up   to the caller of this function to allocate the memory for ListHead.    If ListHead is NULL, then ASSERT().    @param  ListHead  A pointer to the head node of a new doubly linked list.    @return ListHead  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|InitializeListHead
parameter_list|(
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|ListHead
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a node to the beginning of a doubly linked list, and returns the pointer   to the head node of the doubly linked list.    Adds the node Entry at the beginning of the doubly linked list denoted by   ListHead, and returns ListHead.    If ListHead is NULL, then ASSERT().   If Entry is NULL, then ASSERT().   If ListHead was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or   InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and prior to insertion the number   of nodes in ListHead, including the ListHead node, is greater than or   equal to PcdMaximumLinkedListLength, then ASSERT().    @param  ListHead  A pointer to the head node of a doubly linked list.   @param  Entry     A pointer to a node that is to be inserted at the beginning                     of a doubly linked list.    @return ListHead  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|InsertHeadList
parameter_list|(
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|ListHead
parameter_list|,
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a node to the end of a doubly linked list, and returns the pointer to   the head node of the doubly linked list.    Adds the node Entry to the end of the doubly linked list denoted by ListHead,   and returns ListHead.    If ListHead is NULL, then ASSERT().   If Entry is NULL, then ASSERT().   If ListHead was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or    InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and prior to insertion the number   of nodes in ListHead, including the ListHead node, is greater than or   equal to PcdMaximumLinkedListLength, then ASSERT().    @param  ListHead  A pointer to the head node of a doubly linked list.   @param  Entry     A pointer to a node that is to be added at the end of the                     doubly linked list.    @return ListHead  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|InsertTailList
parameter_list|(
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|ListHead
parameter_list|,
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the first node of a doubly linked list.    Returns the first node of a doubly linked list.  List must have been    initialized with INTIALIZE_LIST_HEAD_VARIABLE() or InitializeListHead().   If List is empty, then List is returned.    If List is NULL, then ASSERT().   If List was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or    InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes   in List, including the List node, is greater than or equal to   PcdMaximumLinkedListLength, then ASSERT().    @param  List  A pointer to the head node of a doubly linked list.    @return The first node of a doubly linked list.   @retval List  The list is empty.  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|GetFirstNode
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|List
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the next node of a doubly linked list.    Returns the node of a doubly linked list that follows Node.     List must have been initialized with INTIALIZE_LIST_HEAD_VARIABLE()   or InitializeListHead().  If List is empty, then List is returned.    If List is NULL, then ASSERT().   If Node is NULL, then ASSERT().   If List was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or    InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and List contains more than   PcdMaximumLinkedListLength nodes, then ASSERT().   If PcdVerifyNodeInList is TRUE and Node is not a node in List, then ASSERT().    @param  List  A pointer to the head node of a doubly linked list.   @param  Node  A pointer to a node in the doubly linked list.    @return The pointer to the next node if one exists. Otherwise List is returned.  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|GetNextNode
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|List
parameter_list|,
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the previous node of a doubly linked list.     Returns the node of a doubly linked list that precedes Node.     List must have been initialized with INTIALIZE_LIST_HEAD_VARIABLE()   or InitializeListHead().  If List is empty, then List is returned.     If List is NULL, then ASSERT().   If Node is NULL, then ASSERT().   If List was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or    InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and List contains more than   PcdMaximumLinkedListLength nodes, then ASSERT().   If PcdVerifyNodeInList is TRUE and Node is not a node in List, then ASSERT().     @param  List  A pointer to the head node of a doubly linked list.   @param  Node  A pointer to a node in the doubly linked list.     @return The pointer to the previous node if one exists. Otherwise List is returned.   **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|GetPreviousNode
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|List
parameter_list|,
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Checks to see if a doubly linked list is empty or not.    Checks to see if the doubly linked list is empty. If the linked list contains   zero nodes, this function returns TRUE. Otherwise, it returns FALSE.    If ListHead is NULL, then ASSERT().   If ListHead was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or    InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes   in List, including the List node, is greater than or equal to   PcdMaximumLinkedListLength, then ASSERT().    @param  ListHead  A pointer to the head node of a doubly linked list.    @retval TRUE  The linked list is empty.   @retval FALSE The linked list is not empty.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsListEmpty
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|ListHead
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if a node in a doubly linked list is the head node of a the same   doubly linked list.  This function is typically used to terminate a loop that   traverses all the nodes in a doubly linked list starting with the head node.    Returns TRUE if Node is equal to List.  Returns FALSE if Node is one of the   nodes in the doubly linked list specified by List.  List must have been   initialized with INTIALIZE_LIST_HEAD_VARIABLE() or InitializeListHead().    If List is NULL, then ASSERT().   If Node is NULL, then ASSERT().   If List was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or InitializeListHead(),    then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes   in List, including the List node, is greater than or equal to   PcdMaximumLinkedListLength, then ASSERT().   If PcdVerifyNodeInList is TRUE and Node is not a node in List the and Node is not equal    to List, then ASSERT().    @param  List  A pointer to the head node of a doubly linked list.   @param  Node  A pointer to a node in the doubly linked list.    @retval TRUE  Node is the head of the doubly-linked list pointed by List.   @retval FALSE Node is not the head of the doubly-linked list pointed by List.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsNull
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|List
parameter_list|,
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if a node the last node in a doubly linked list.    Returns TRUE if Node is the last node in the doubly linked list specified by   List. Otherwise, FALSE is returned. List must have been initialized with   INTIALIZE_LIST_HEAD_VARIABLE() or InitializeListHead().    If List is NULL, then ASSERT().   If Node is NULL, then ASSERT().   If List was not initialized with INTIALIZE_LIST_HEAD_VARIABLE() or   InitializeListHead(), then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes   in List, including the List node, is greater than or equal to   PcdMaximumLinkedListLength, then ASSERT().   If PcdVerifyNodeInList is TRUE and Node is not a node in List, then ASSERT().    @param  List  A pointer to the head node of a doubly linked list.   @param  Node  A pointer to a node in the doubly linked list.    @retval TRUE  Node is the last node in the linked list.   @retval FALSE Node is not the last node in the linked list.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsNodeAtEnd
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|List
parameter_list|,
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Swaps the location of two nodes in a doubly linked list, and returns the   first node after the swap.    If FirstEntry is identical to SecondEntry, then SecondEntry is returned.   Otherwise, the location of the FirstEntry node is swapped with the location   of the SecondEntry node in a doubly linked list. SecondEntry must be in the   same double linked list as FirstEntry and that double linked list must have   been initialized with INTIALIZE_LIST_HEAD_VARIABLE() or InitializeListHead().    SecondEntry is returned after the nodes are swapped.    If FirstEntry is NULL, then ASSERT().   If SecondEntry is NULL, then ASSERT().   If PcdVerifyNodeInList is TRUE and SecondEntry and FirstEntry are not in the    same linked list, then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes in the   linked list containing the FirstEntry and SecondEntry nodes, including   the FirstEntry and SecondEntry nodes, is greater than or equal to   PcdMaximumLinkedListLength, then ASSERT().    @param  FirstEntry  A pointer to a node in a linked list.   @param  SecondEntry A pointer to another node in the same linked list.      @return SecondEntry.  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|SwapListEntries
parameter_list|(
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|FirstEntry
parameter_list|,
name|IN
name|OUT
name|LIST_ENTRY
modifier|*
name|SecondEntry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Removes a node from a doubly linked list, and returns the node that follows   the removed node.    Removes the node Entry from a doubly linked list. It is up to the caller of   this function to release the memory used by this node if that is required. On   exit, the node following Entry in the doubly linked list is returned. If   Entry is the only node in the linked list, then the head node of the linked   list is returned.    If Entry is NULL, then ASSERT().   If Entry is the head node of an empty list, then ASSERT().   If PcdMaximumLinkedListLength is not zero, and the number of nodes in the   linked list containing Entry, including the Entry node, is greater than   or equal to PcdMaximumLinkedListLength, then ASSERT().    @param  Entry A pointer to a node in a linked list.    @return Entry.  **/
end_comment

begin_function_decl
name|LIST_ENTRY
modifier|*
name|EFIAPI
name|RemoveEntryList
parameter_list|(
name|IN
name|CONST
name|LIST_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// Math Services
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Shifts a 64-bit integer left between 0 and 63 bits. The low bits are filled   with zeros. The shifted value is returned.    This function shifts the 64-bit value Operand to the left by Count bits. The   low Count bits are set to zero. The shifted value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to shift left.   @param  Count   The number of bits to shift left.    @return Operand<< Count.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|LShiftU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Shifts a 64-bit integer right between 0 and 63 bits. This high bits are   filled with zeros. The shifted value is returned.    This function shifts the 64-bit value Operand to the right by Count bits. The   high Count bits are set to zero. The shifted value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to shift right.   @param  Count   The number of bits to shift right.    @return Operand>> Count  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|RShiftU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Shifts a 64-bit integer right between 0 and 63 bits. The high bits are filled   with original integer's bit 63. The shifted value is returned.    This function shifts the 64-bit value Operand to the right by Count bits. The   high Count bits are set to bit 63 of Operand.  The shifted value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to shift right.   @param  Count   The number of bits to shift right.    @return Operand>> Count  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|ARShiftU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Rotates a 32-bit integer left between 0 and 31 bits, filling the low bits   with the high bits that were rotated.    This function rotates the 32-bit value Operand to the left by Count bits. The   low Count bits are fill with the high Count bits of Operand. The rotated   value is returned.    If Count is greater than 31, then ASSERT().    @param  Operand The 32-bit operand to rotate left.   @param  Count   The number of bits to rotate left.    @return Operand<< Count  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|LRotU32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Rotates a 32-bit integer right between 0 and 31 bits, filling the high bits   with the low bits that were rotated.    This function rotates the 32-bit value Operand to the right by Count bits.   The high Count bits are fill with the low Count bits of Operand. The rotated   value is returned.    If Count is greater than 31, then ASSERT().    @param  Operand The 32-bit operand to rotate right.   @param  Count   The number of bits to rotate right.    @return Operand>> Count  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|RRotU32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Rotates a 64-bit integer left between 0 and 63 bits, filling the low bits   with the high bits that were rotated.    This function rotates the 64-bit value Operand to the left by Count bits. The   low Count bits are fill with the high Count bits of Operand. The rotated   value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to rotate left.   @param  Count   The number of bits to rotate left.    @return Operand<< Count  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|LRotU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Rotates a 64-bit integer right between 0 and 63 bits, filling the high bits   with the high low bits that were rotated.    This function rotates the 64-bit value Operand to the right by Count bits.   The high Count bits are fill with the low Count bits of Operand. The rotated   value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to rotate right.   @param  Count   The number of bits to rotate right.    @return Operand>> Count  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|RRotU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the bit position of the lowest bit set in a 32-bit value.    This function computes the bit position of the lowest bit set in the 32-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 31 is returned.    @param  Operand The 32-bit operand to evaluate.    @retval 0..31  The lowest bit set in Operand was found.   @retval -1    Operand is zero.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|LowBitSet32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the bit position of the lowest bit set in a 64-bit value.    This function computes the bit position of the lowest bit set in the 64-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 63 is returned.    @param  Operand The 64-bit operand to evaluate.    @retval 0..63  The lowest bit set in Operand was found.   @retval -1    Operand is zero.   **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|LowBitSet64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the bit position of the highest bit set in a 32-bit value. Equivalent   to log2(x).    This function computes the bit position of the highest bit set in the 32-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 31 is returned.    @param  Operand The 32-bit operand to evaluate.    @retval 0..31  Position of the highest bit set in Operand if found.   @retval -1    Operand is zero.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|HighBitSet32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the bit position of the highest bit set in a 64-bit value. Equivalent   to log2(x).    This function computes the bit position of the highest bit set in the 64-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 63 is returned.    @param  Operand The 64-bit operand to evaluate.    @retval 0..63   Position of the highest bit set in Operand if found.   @retval -1     Operand is zero.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|HighBitSet64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the value of the highest bit set in a 32-bit value. Equivalent to   1<< log2(x).    This function computes the value of the highest bit set in the 32-bit value   specified by Operand. If Operand is zero, then zero is returned.    @param  Operand The 32-bit operand to evaluate.    @return 1<< HighBitSet32(Operand)   @retval 0 Operand is zero.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|GetPowerOfTwo32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the value of the highest bit set in a 64-bit value. Equivalent to   1<< log2(x).    This function computes the value of the highest bit set in the 64-bit value   specified by Operand. If Operand is zero, then zero is returned.    @param  Operand The 64-bit operand to evaluate.    @return 1<< HighBitSet64(Operand)   @retval 0 Operand is zero.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|GetPowerOfTwo64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Switches the endianness of a 16-bit integer.    This function swaps the bytes in a 16-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Value A 16-bit unsigned value.    @return The byte swapped Value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|SwapBytes16
parameter_list|(
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Switches the endianness of a 32-bit integer.    This function swaps the bytes in a 32-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Value A 32-bit unsigned value.    @return The byte swapped Value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|SwapBytes32
parameter_list|(
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Switches the endianness of a 64-bit integer.    This function swaps the bytes in a 64-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Value A 64-bit unsigned value.    @return The byte swapped Value.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|SwapBytes64
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Multiples a 64-bit unsigned integer by a 32-bit unsigned integer and   generates a 64-bit unsigned result.    This function multiples the 64-bit unsigned value Multiplicand by the 32-bit   unsigned value Multiplier and generates a 64-bit unsigned result. This 64-   bit unsigned result is returned.    @param  Multiplicand  A 64-bit unsigned value.   @param  Multiplier    A 32-bit unsigned value.    @return Multiplicand * Multiplier  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MultU64x32
parameter_list|(
name|IN
name|UINT64
name|Multiplicand
parameter_list|,
name|IN
name|UINT32
name|Multiplier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Multiples a 64-bit unsigned integer by a 64-bit unsigned integer and   generates a 64-bit unsigned result.    This function multiples the 64-bit unsigned value Multiplicand by the 64-bit   unsigned value Multiplier and generates a 64-bit unsigned result. This 64-   bit unsigned result is returned.    @param  Multiplicand  A 64-bit unsigned value.   @param  Multiplier    A 64-bit unsigned value.    @return Multiplicand * Multiplier.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MultU64x64
parameter_list|(
name|IN
name|UINT64
name|Multiplicand
parameter_list|,
name|IN
name|UINT64
name|Multiplier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Multiples a 64-bit signed integer by a 64-bit signed integer and generates a   64-bit signed result.    This function multiples the 64-bit signed value Multiplicand by the 64-bit   signed value Multiplier and generates a 64-bit signed result. This 64-bit   signed result is returned.    @param  Multiplicand  A 64-bit signed value.   @param  Multiplier    A 64-bit signed value.    @return Multiplicand * Multiplier  **/
end_comment

begin_function_decl
name|INT64
name|EFIAPI
name|MultS64x64
parameter_list|(
name|IN
name|INT64
name|Multiplicand
parameter_list|,
name|IN
name|INT64
name|Multiplier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Divides a 64-bit unsigned integer by a 32-bit unsigned integer and generates   a 64-bit unsigned result.    This function divides the 64-bit unsigned value Dividend by the 32-bit   unsigned value Divisor and generates a 64-bit unsigned quotient. This   function returns the 64-bit unsigned quotient.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 32-bit unsigned value.    @return Dividend / Divisor.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|DivU64x32
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT32
name|Divisor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Divides a 64-bit unsigned integer by a 32-bit unsigned integer and generates   a 32-bit unsigned remainder.    This function divides the 64-bit unsigned value Dividend by the 32-bit   unsigned value Divisor and generates a 32-bit remainder. This function   returns the 32-bit unsigned remainder.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 32-bit unsigned value.    @return Dividend % Divisor.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|ModU64x32
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT32
name|Divisor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Divides a 64-bit unsigned integer by a 32-bit unsigned integer and generates   a 64-bit unsigned result and an optional 32-bit unsigned remainder.    This function divides the 64-bit unsigned value Dividend by the 32-bit   unsigned value Divisor and generates a 64-bit unsigned quotient. If Remainder   is not NULL, then the 32-bit unsigned remainder is returned in Remainder.   This function returns the 64-bit unsigned quotient.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 32-bit unsigned value.   @param  Remainder A pointer to a 32-bit unsigned value. This parameter is                     optional and may be NULL.    @return Dividend / Divisor.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|DivU64x32Remainder
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT32
name|Divisor
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Remainder
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Divides a 64-bit unsigned integer by a 64-bit unsigned integer and generates   a 64-bit unsigned result and an optional 64-bit unsigned remainder.    This function divides the 64-bit unsigned value Dividend by the 64-bit   unsigned value Divisor and generates a 64-bit unsigned quotient. If Remainder   is not NULL, then the 64-bit unsigned remainder is returned in Remainder.   This function returns the 64-bit unsigned quotient.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 64-bit unsigned value.   @param  Remainder A pointer to a 64-bit unsigned value. This parameter is                     optional and may be NULL.    @return Dividend / Divisor.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|DivU64x64Remainder
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT64
name|Divisor
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Remainder
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Divides a 64-bit signed integer by a 64-bit signed integer and generates a   64-bit signed result and a optional 64-bit signed remainder.    This function divides the 64-bit signed value Dividend by the 64-bit signed   value Divisor and generates a 64-bit signed quotient. If Remainder is not   NULL, then the 64-bit signed remainder is returned in Remainder. This   function returns the 64-bit signed quotient.    It is the caller's responsibility to not call this function with a Divisor of 0.   If Divisor is 0, then the quotient and remainder should be assumed to be    the largest negative integer.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit signed value.   @param  Divisor   A 64-bit signed value.   @param  Remainder A pointer to a 64-bit signed value. This parameter is                     optional and may be NULL.    @return Dividend / Divisor.  **/
end_comment

begin_function_decl
name|INT64
name|EFIAPI
name|DivS64x64Remainder
parameter_list|(
name|IN
name|INT64
name|Dividend
parameter_list|,
name|IN
name|INT64
name|Divisor
parameter_list|,
name|OUT
name|INT64
modifier|*
name|Remainder
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit value from memory that may be unaligned.    This function returns the 16-bit value pointed to by Buffer. The function   guarantees that the read operation does not produce an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 16-bit value that may be unaligned.    @return The 16-bit value read from Buffer.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|ReadUnaligned16
parameter_list|(
name|IN
name|CONST
name|UINT16
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit value to memory that may be unaligned.    This function writes the 16-bit value specified by Value to Buffer. Value is   returned. The function guarantees that the write operation does not produce   an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 16-bit value that may be unaligned.   @param  Value   16-bit value to write to Buffer.    @return The 16-bit value to write to Buffer.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|WriteUnaligned16
parameter_list|(
name|OUT
name|UINT16
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 24-bit value from memory that may be unaligned.    This function returns the 24-bit value pointed to by Buffer. The function   guarantees that the read operation does not produce an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 24-bit value that may be unaligned.    @return The 24-bit value read from Buffer.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|ReadUnaligned24
parameter_list|(
name|IN
name|CONST
name|UINT32
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 24-bit value to memory that may be unaligned.    This function writes the 24-bit value specified by Value to Buffer. Value is   returned. The function guarantees that the write operation does not produce   an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 24-bit value that may be unaligned.   @param  Value   24-bit value to write to Buffer.    @return The 24-bit value to write to Buffer.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|WriteUnaligned24
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit value from memory that may be unaligned.    This function returns the 32-bit value pointed to by Buffer. The function   guarantees that the read operation does not produce an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 32-bit value that may be unaligned.    @return The 32-bit value read from Buffer.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|ReadUnaligned32
parameter_list|(
name|IN
name|CONST
name|UINT32
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit value to memory that may be unaligned.    This function writes the 32-bit value specified by Value to Buffer. Value is   returned. The function guarantees that the write operation does not produce   an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 32-bit value that may be unaligned.   @param  Value   32-bit value to write to Buffer.    @return The 32-bit value to write to Buffer.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|WriteUnaligned32
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit value from memory that may be unaligned.    This function returns the 64-bit value pointed to by Buffer. The function   guarantees that the read operation does not produce an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 64-bit value that may be unaligned.    @return The 64-bit value read from Buffer.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|ReadUnaligned64
parameter_list|(
name|IN
name|CONST
name|UINT64
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit value to memory that may be unaligned.    This function writes the 64-bit value specified by Value to Buffer. Value is   returned. The function guarantees that the write operation does not produce   an alignment fault.    If the Buffer is NULL, then ASSERT().    @param  Buffer  The pointer to a 64-bit value that may be unaligned.   @param  Value   64-bit value to write to Buffer.    @return The 64-bit value to write to Buffer.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|WriteUnaligned64
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit Field Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Returns a bit field from an 8-bit value.    Returns the bitfield specified by the StartBit and the EndBit from Operand.    If 8-bit operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.    @return The bit field read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BitFieldRead8
parameter_list|(
name|IN
name|UINT8
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an 8-bit value, and returns the result.    Writes Value to the bit field specified by the StartBit and the EndBit in   Operand. All other bits in Operand are preserved. The new 8-bit value is   returned.    If 8-bit operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  Value     New value of the bit field.    @return The new 8-bit value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BitFieldWrite8
parameter_list|(
name|IN
name|UINT8
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from an 8-bit value, performs a bitwise OR, and returns the   result.    Performs a bitwise OR between the bit field specified by StartBit   and EndBit in Operand and the value specified by OrData. All other bits in   Operand are preserved. The new 8-bit value is returned.    If 8-bit operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  OrData    The value to OR with the read value from the value    @return The new 8-bit value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BitFieldOr8
parameter_list|(
name|IN
name|UINT8
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from an 8-bit value, performs a bitwise AND, and returns   the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData. All other bits in Operand are   preserved. The new 8-bit value is returned.    If 8-bit operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the read value from the value.    @return The new 8-bit value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BitFieldAnd8
parameter_list|(
name|IN
name|UINT8
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from an 8-bit value, performs a bitwise AND followed by a   bitwise OR, and returns the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData, followed by a bitwise    OR with value specified by OrData. All other bits in Operand are   preserved. The new 8-bit value is returned.    If 8-bit operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the read value from the value.   @param  OrData    The value to OR with the result of the AND operation.    @return The new 8-bit value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|BitFieldAndThenOr8
parameter_list|(
name|IN
name|UINT8
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a bit field from a 16-bit value.    Returns the bitfield specified by the StartBit and the EndBit from Operand.    If 16-bit operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.    @return The bit field read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|BitFieldRead16
parameter_list|(
name|IN
name|UINT16
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a 16-bit value, and returns the result.    Writes Value to the bit field specified by the StartBit and the EndBit in   Operand. All other bits in Operand are preserved. The new 16-bit value is   returned.    If 16-bit operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  Value     New value of the bit field.    @return The new 16-bit value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|BitFieldWrite16
parameter_list|(
name|IN
name|UINT16
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 16-bit value, performs a bitwise OR, and returns the   result.    Performs a bitwise OR between the bit field specified by StartBit   and EndBit in Operand and the value specified by OrData. All other bits in   Operand are preserved. The new 16-bit value is returned.    If 16-bit operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  OrData    The value to OR with the read value from the value    @return The new 16-bit value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|BitFieldOr16
parameter_list|(
name|IN
name|UINT16
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 16-bit value, performs a bitwise AND, and returns   the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData. All other bits in Operand are   preserved. The new 16-bit value is returned.    If 16-bit operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with the read value from the value    @return The new 16-bit value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|BitFieldAnd16
parameter_list|(
name|IN
name|UINT16
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 16-bit value, performs a bitwise AND followed by a   bitwise OR, and returns the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData, followed by a bitwise    OR with value specified by OrData. All other bits in Operand are   preserved. The new 16-bit value is returned.    If 16-bit operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with the read value from the value.   @param  OrData    The value to OR with the result of the AND operation.    @return The new 16-bit value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|BitFieldAndThenOr16
parameter_list|(
name|IN
name|UINT16
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a bit field from a 32-bit value.    Returns the bitfield specified by the StartBit and the EndBit from Operand.    If 32-bit operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.    @return The bit field read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|BitFieldRead32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a 32-bit value, and returns the result.    Writes Value to the bit field specified by the StartBit and the EndBit in   Operand. All other bits in Operand are preserved. The new 32-bit value is   returned.    If 32-bit operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  Value     New value of the bit field.    @return The new 32-bit value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|BitFieldWrite32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 32-bit value, performs a bitwise OR, and returns the   result.    Performs a bitwise OR between the bit field specified by StartBit   and EndBit in Operand and the value specified by OrData. All other bits in   Operand are preserved. The new 32-bit value is returned.    If 32-bit operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  OrData    The value to OR with the read value from the value.    @return The new 32-bit value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|BitFieldOr32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 32-bit value, performs a bitwise AND, and returns   the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData. All other bits in Operand are   preserved. The new 32-bit value is returned.    If 32-bit operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the value    @return The new 32-bit value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|BitFieldAnd32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 32-bit value, performs a bitwise AND followed by a   bitwise OR, and returns the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData, followed by a bitwise    OR with value specified by OrData. All other bits in Operand are   preserved. The new 32-bit value is returned.    If 32-bit operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the value.   @param  OrData    The value to OR with the result of the AND operation.    @return The new 32-bit value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|BitFieldAndThenOr32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a bit field from a 64-bit value.    Returns the bitfield specified by the StartBit and the EndBit from Operand.    If 64-bit operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.    @return The bit field read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|BitFieldRead64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a 64-bit value, and returns the result.    Writes Value to the bit field specified by the StartBit and the EndBit in   Operand. All other bits in Operand are preserved. The new 64-bit value is   returned.    If 64-bit operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  Value     New value of the bit field.    @return The new 64-bit value.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|BitFieldWrite64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 64-bit value, performs a bitwise OR, and returns the   result.    Performs a bitwise OR between the bit field specified by StartBit   and EndBit in Operand and the value specified by OrData. All other bits in   Operand are preserved. The new 64-bit value is returned.    If 64-bit operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  OrData    The value to OR with the read value from the value    @return The new 64-bit value.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|BitFieldOr64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 64-bit value, performs a bitwise AND, and returns   the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData. All other bits in Operand are   preserved. The new 64-bit value is returned.    If 64-bit operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the value    @return The new 64-bit value.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|BitFieldAnd64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field from a 64-bit value, performs a bitwise AND followed by a   bitwise OR, and returns the result.    Performs a bitwise AND between the bit field specified by StartBit and EndBit   in Operand and the value specified by AndData, followed by a bitwise    OR with value specified by OrData. All other bits in Operand are   preserved. The new 64-bit value is returned.    If 64-bit operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Operand   Operand on which to perform the bitfield operation.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the value.   @param  OrData    The value to OR with the result of the AND operation.    @return The new 64-bit value.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|BitFieldAndThenOr64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// Base Library Checksum Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Returns the sum of all elements in a buffer in unit of UINT8.   During calculation, the carry bits are dropped.    This function calculates the sum of all elements in a buffer   in unit of UINT8. The carry bits in result of addition are dropped.   The result is returned as UINT8. If Length is Zero, then Zero is   returned.    If Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the sum operation.   @param  Length      The size, in bytes, of Buffer.    @return Sum         The sum of Buffer with carry bits dropped during additions.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|CalculateSum8
parameter_list|(
name|IN
name|CONST
name|UINT8
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
comment|/**   Returns the two's complement checksum of all elements in a buffer   of 8-bit values.    This function first calculates the sum of the 8-bit values in the   buffer specified by Buffer and Length.  The carry bits in the result   of addition are dropped. Then, the two's complement of the sum is   returned.  If Length is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the checksum operation.   @param  Length      The size, in bytes, of Buffer.    @return Checksum    The two's complement checksum of Buffer.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|CalculateCheckSum8
parameter_list|(
name|IN
name|CONST
name|UINT8
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
comment|/**   Returns the sum of all elements in a buffer of 16-bit values.  During   calculation, the carry bits are dropped.    This function calculates the sum of the 16-bit values in the buffer   specified by Buffer and Length. The carry bits in result of addition are dropped.   The 16-bit result is returned.  If Length is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-bit boundary, then ASSERT().   If Length is not aligned on a 16-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the sum operation.   @param  Length      The size, in bytes, of Buffer.    @return Sum         The sum of Buffer with carry bits dropped during additions.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|CalculateSum16
parameter_list|(
name|IN
name|CONST
name|UINT16
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
comment|/**   Returns the two's complement checksum of all elements in a buffer of   16-bit values.    This function first calculates the sum of the 16-bit values in the buffer   specified by Buffer and Length.  The carry bits in the result of addition   are dropped. Then, the two's complement of the sum is returned.  If Length   is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-bit boundary, then ASSERT().   If Length is not aligned on a 16-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the checksum operation.   @param  Length      The size, in bytes, of Buffer.    @return Checksum    The two's complement checksum of Buffer.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|CalculateCheckSum16
parameter_list|(
name|IN
name|CONST
name|UINT16
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
comment|/**   Returns the sum of all elements in a buffer of 32-bit values. During   calculation, the carry bits are dropped.    This function calculates the sum of the 32-bit values in the buffer   specified by Buffer and Length. The carry bits in result of addition are dropped.   The 32-bit result is returned. If Length is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 32-bit boundary, then ASSERT().   If Length is not aligned on a 32-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the sum operation.   @param  Length      The size, in bytes, of Buffer.    @return Sum         The sum of Buffer with carry bits dropped during additions.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|CalculateSum32
parameter_list|(
name|IN
name|CONST
name|UINT32
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
comment|/**   Returns the two's complement checksum of all elements in a buffer of   32-bit values.    This function first calculates the sum of the 32-bit values in the buffer   specified by Buffer and Length.  The carry bits in the result of addition   are dropped. Then, the two's complement of the sum is returned.  If Length   is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 32-bit boundary, then ASSERT().   If Length is not aligned on a 32-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the checksum operation.   @param  Length      The size, in bytes, of Buffer.    @return Checksum    The two's complement checksum of Buffer.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|CalculateCheckSum32
parameter_list|(
name|IN
name|CONST
name|UINT32
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
comment|/**   Returns the sum of all elements in a buffer of 64-bit values.  During   calculation, the carry bits are dropped.    This function calculates the sum of the 64-bit values in the buffer   specified by Buffer and Length. The carry bits in result of addition are dropped.   The 64-bit result is returned.  If Length is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 64-bit boundary, then ASSERT().   If Length is not aligned on a 64-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the sum operation.   @param  Length      The size, in bytes, of Buffer.    @return Sum         The sum of Buffer with carry bits dropped during additions.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|CalculateSum64
parameter_list|(
name|IN
name|CONST
name|UINT64
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
comment|/**   Returns the two's complement checksum of all elements in a buffer of   64-bit values.    This function first calculates the sum of the 64-bit values in the buffer   specified by Buffer and Length.  The carry bits in the result of addition   are dropped. Then, the two's complement of the sum is returned.  If Length   is 0, then 0 is returned.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 64-bit boundary, then ASSERT().   If Length is not aligned on a 64-bit boundary, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to carry out the checksum operation.   @param  Length      The size, in bytes, of Buffer.    @return Checksum    The two's complement checksum of Buffer.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|CalculateCheckSum64
parameter_list|(
name|IN
name|CONST
name|UINT64
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
comment|//
end_comment

begin_comment
comment|// Base Library CPU Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Function entry point used when a stack switch is requested with SwitchStack()    @param  Context1        Context1 parameter passed into SwitchStack().   @param  Context2        Context2 parameter passed into SwitchStack().  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|SWITCH_STACK_ENTRY_POINT
function_decl|)
parameter_list|(
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
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to serialize load and store operations.    All loads and stores that proceed calls to this function are guaranteed to be   globally visible when this function returns.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|MemoryFence
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Saves the current CPU context that can be restored with a call to LongJump()   and returns 0.    Saves the current CPU context in the buffer specified by JumpBuffer and   returns 0. The initial call to SetJump() must always return 0. Subsequent   calls to LongJump() cause a non-zero value to be returned by SetJump().    If JumpBuffer is NULL, then ASSERT().   For Itanium processors, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().      NOTE: The structure BASE_LIBRARY_JUMP_BUFFER is CPU architecture specific.   The same structure must never be used for more than one CPU architecture context.   For example, a BASE_LIBRARY_JUMP_BUFFER allocated by an IA-32 module must never be used from an x64 module.    SetJump()/LongJump() is not currently supported for the EBC processor type.       @param  JumpBuffer  A pointer to CPU context buffer.    @retval 0 Indicates a return from SetJump().  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SetJump
parameter_list|(
name|OUT
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Restores the CPU context that was saved with SetJump().    Restores the CPU context from the buffer specified by JumpBuffer. This   function never returns to the caller. Instead is resumes execution based on   the state of JumpBuffer.    If JumpBuffer is NULL, then ASSERT().   For Itanium processors, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().   If Value is 0, then ASSERT().    @param  JumpBuffer  A pointer to CPU context buffer.   @param  Value       The value to return when the SetJump() context is                       restored and must be non-zero.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|LongJump
parameter_list|(
name|IN
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|,
name|IN
name|UINTN
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Enables CPU interrupts.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EnableInterrupts
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Disables CPU interrupts.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|DisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Disables CPU interrupts and returns the interrupt state prior to the disable   operation.    @retval TRUE  CPU interrupts were enabled on entry to this call.   @retval FALSE CPU interrupts were disabled on entry to this call.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|SaveAndDisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Enables CPU interrupts for the smallest window required to capture any   pending interrupts.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EnableDisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the current CPU interrupt state.    Returns TRUE if interrupts are currently enabled. Otherwise   returns FALSE.    @retval TRUE  CPU interrupts are enabled.   @retval FALSE CPU interrupts are disabled.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|GetInterruptState
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the current CPU interrupt state.    Sets the current CPU interrupt state to the state specified by   InterruptState. If InterruptState is TRUE, then interrupts are enabled. If   InterruptState is FALSE, then interrupts are disabled. InterruptState is   returned.    @param  InterruptState  TRUE if interrupts should enabled. FALSE if                           interrupts should be disabled.    @return InterruptState  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|SetInterruptState
parameter_list|(
name|IN
name|BOOLEAN
name|InterruptState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Requests CPU to pause for a short period of time.    Requests CPU to pause for a short period of time. Typically used in MP   systems to prevent memory starvation while waiting for a spin lock.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CpuPause
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Transfers control to a function starting with a new stack.    Transfers control to the function specified by EntryPoint using the   new stack specified by NewStack and passing in the parameters specified   by Context1 and Context2.  Context1 and Context2 are optional and may   be NULL.  The function EntryPoint must never return.  This function   supports a variable number of arguments following the NewStack parameter.   These additional arguments are ignored on IA-32, x64, and EBC architectures.   Itanium processors expect one additional parameter of type VOID * that specifies   the new backing store pointer.    If EntryPoint is NULL, then ASSERT().   If NewStack is NULL, then ASSERT().    @param  EntryPoint  A pointer to function to call with the new stack.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function.   @param  ...         This variable argument list is ignored for IA-32, x64, and                        EBC architectures.  For Itanium processors, this variable                        argument list is expected to contain a single parameter of                        type VOID * that specifies the new backing store pointer.   **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|SwitchStack
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
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a breakpoint on the CPU.    Generates a breakpoint on the CPU. The breakpoint must be implemented such   that code can resume normal execution after the breakpoint.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CpuBreakpoint
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an infinite loop.    Forces the CPU to execute an infinite loop. A debugger may be used to skip   past the loop and the code that follows the loop must execute properly. This   implies that the infinite loop must not cause the code that follow it to be   optimized away.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CpuDeadLoop
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IPF
argument_list|)
end_if

begin_comment
comment|/**   Flush a range of  cache lines in the cache coherency domain of the calling   CPU.    Flushes the cache lines specified by Address and Length.  If Address is not aligned    on a cache line boundary, then entire cache line containing Address is flushed.     If Address + Length is not aligned on a cache line boundary, then the entire cache    line containing Address + Length - 1 is flushed.  This function may choose to flush    the entire cache if that is more efficient than flushing the specified range.  If    Length is 0, the no cache lines are flushed.  Address is returned.      This function is only available on Itanium processors.    If Length is greater than (MAX_ADDRESS - Address + 1), then ASSERT().    @param  Address The base address of the instruction lines to invalidate. If                   the CPU is in a physical addressing mode, then Address is a                   physical address. If the CPU is in a virtual addressing mode,                   then Address is a virtual address.    @param  Length  The number of bytes to invalidate from the instruction cache.    @return Address.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AsmFlushCacheRange
parameter_list|(
name|IN
name|VOID
modifier|*
name|Address
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an FC instruction.   Executes an FC instruction on the cache line specified by Address.   The cache line size affected is at least 32-bytes (aligned on a 32-byte boundary).   An implementation may flush a larger region.  This function is only available on Itanium processors.    @param Address    The Address of cache line to be flushed.    @return The address of FC instruction executed.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmFc
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an FC.I instruction.   Executes an FC.I instruction on the cache line specified by Address.   The cache line size affected is at least 32-bytes (aligned on a 32-byte boundary).   An implementation may flush a larger region.  This function is only available on Itanium processors.    @param Address    The Address of cache line to be flushed.    @return The address of the FC.I instruction executed.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmFci
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of a Processor Identifier Register (CPUID).      Reads and returns the current value of Processor Identifier Register specified by Index.    The Index of largest implemented CPUID (One less than the number of implemented CPUID   registers) is determined by CPUID [3] bits {7:0}.   No parameter checking is performed on Index.  If the Index value is beyond the   implemented CPUID register range, a Reserved Register/Field fault may occur.  The caller   must either guarantee that Index is valid, or the caller must set up fault handlers to   catch the faults.  This function is only available on Itanium processors.    @param Index    The 8-bit Processor Identifier Register index to read.    @return The current value of Processor Identifier Register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadCpuid
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Processor Status Register (PSR).   This function is only available on Itanium processors.    @return The current value of PSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPsr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Processor Status Register (PSR).    No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of PSR must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults. This function is only available on Itanium processors.    @param Value    The 64-bit value to write to PSR.    @return The 64-bit value written to the PSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWritePsr
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #0 (KR0).      Reads and returns the current value of KR0.    This function is only available on Itanium processors.    @return The current value of KR0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #1 (KR1).    Reads and returns the current value of KR1.    This function is only available on Itanium processors.    @return The current value of KR1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr1
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #2 (KR2).    Reads and returns the current value of KR2.    This function is only available on Itanium processors.    @return The current value of KR2.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr2
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #3 (KR3).    Reads and returns the current value of KR3.    This function is only available on Itanium processors.    @return The current value of KR3.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr3
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #4 (KR4).    Reads and returns the current value of KR4.    This function is only available on Itanium processors.      @return The current value of KR4.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr4
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #5 (KR5).    Reads and returns the current value of KR5.    This function is only available on Itanium processors.    @return The current value of KR5.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr5
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #6 (KR6).    Reads and returns the current value of KR6.    This function is only available on Itanium processors.    @return The current value of KR6.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr6
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Kernel Register #7 (KR7).    Reads and returns the current value of KR7.    This function is only available on Itanium processors.    @return The current value of KR7.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadKr7
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #0 (KR0).      Writes the current value of KR0.  The 64-bit value written to    the KR0 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR0.    @return The 64-bit value written to the KR0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr0
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #1 (KR1).    Writes the current value of KR1.  The 64-bit value written to    the KR1 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR1.    @return The 64-bit value written to the KR1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr1
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #2 (KR2).    Writes the current value of KR2.  The 64-bit value written to    the KR2 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR2.    @return The 64-bit value written to the KR2.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr2
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #3 (KR3).    Writes the current value of KR3.  The 64-bit value written to    the KR3 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR3.    @return The 64-bit value written to the KR3.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr3
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #4 (KR4).    Writes the current value of KR4.  The 64-bit value written to    the KR4 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR4.    @return The 64-bit value written to the KR4.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr4
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #5 (KR5).    Writes the current value of KR5.  The 64-bit value written to    the KR5 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR5.    @return The 64-bit value written to the KR5.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr5
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #6 (KR6).    Writes the current value of KR6.  The 64-bit value written to    the KR6 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR6.    @return The 64-bit value written to the KR6.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr6
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Kernel Register #7 (KR7).    Writes the current value of KR7.  The 64-bit value written to    the KR7 is returned. This function is only available on Itanium processors.    @param  Value   The 64-bit value to write to KR7.    @return The 64-bit value written to the KR7.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteKr7
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Interval Timer Counter Register (ITC).      Reads and returns the current value of ITC.   This function is only available on Itanium processors.    @return The current value of ITC.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadItc
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Interval Timer Vector Register (ITV).      Reads and returns the current value of ITV.    This function is only available on Itanium processors.    @return The current value of ITV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadItv
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Interval Timer Match Register (ITM).      Reads and returns the current value of ITM.   This function is only available on Itanium processors.    @return The current value of ITM. **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadItm
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Interval Timer Counter Register (ITC).      Writes the current value of ITC.  The 64-bit value written to the ITC is returned.    This function is only available on Itanium processors.    @param Value    The 64-bit value to write to ITC.    @return The 64-bit value written to the ITC.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteItc
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Interval Timer Match Register (ITM).      Writes the current value of ITM.  The 64-bit value written to the ITM is returned.    This function is only available on Itanium processors.    @param Value    The 64-bit value to write to ITM.    @return The 64-bit value written to the ITM.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteItm
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Interval Timer Vector Register (ITV).      Writes the current value of ITV.  The 64-bit value written to the ITV is returned.     No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of ITV must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to ITV.    @return The 64-bit value written to the ITV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteItv
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Default Control Register (DCR).      Reads and returns the current value of DCR.  This function is only available on Itanium processors.    @return The current value of DCR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadDcr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Interruption Vector Address Register (IVA).      Reads and returns the current value of IVA.  This function is only available on Itanium processors.    @return The current value of IVA. **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIva
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Page Table Address Register (PTA).      Reads and returns the current value of PTA.  This function is only available on Itanium processors.    @return The current value of PTA.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPta
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Default Control Register (DCR).      Writes the current value of DCR.  The 64-bit value written to the DCR is returned.    No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of DCR must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to DCR.    @return The 64-bit value written to the DCR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteDcr
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Interruption Vector Address Register (IVA).      Writes the current value of IVA.  The 64-bit value written to the IVA is returned.     The size of vector table is 32 K bytes and is 32 K bytes aligned   the low 15 bits of Value is ignored when written.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to IVA.    @return The 64-bit value written to the IVA.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteIva
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Page Table Address Register (PTA).      Writes the current value of PTA.  The 64-bit value written to the PTA is returned.    No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of DCR must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to PTA.    @return The 64-bit value written to the PTA. **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWritePta
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Local Interrupt ID Register (LID).      Reads and returns the current value of LID.  This function is only available on Itanium processors.    @return The current value of LID.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadLid
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of External Interrupt Vector Register (IVR).      Reads and returns the current value of IVR.  This function is only available on Itanium processors.     @return The current value of IVR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIvr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Task Priority Register (TPR).      Reads and returns the current value of TPR.  This function is only available on Itanium processors.     @return The current value of TPR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadTpr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of External Interrupt Request Register #0 (IRR0).      Reads and returns the current value of IRR0.  This function is only available on Itanium processors.      @return The current value of IRR0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIrr0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of External Interrupt Request Register #1 (IRR1).      Reads and returns the current value of IRR1.  This function is only available on Itanium processors.     @return The current value of IRR1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIrr1
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of External Interrupt Request Register #2 (IRR2).      Reads and returns the current value of IRR2.  This function is only available on Itanium processors.    @return The current value of IRR2.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIrr2
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of External Interrupt Request Register #3 (IRR3).      Reads and returns the current value of IRR3.  This function is only available on Itanium processors.      @return The current value of IRR3.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIrr3
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Performance Monitor Vector Register (PMV).      Reads and returns the current value of PMV.  This function is only available on Itanium processors.     @return The current value of PMV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPmv
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Corrected Machine Check Vector Register (CMCV).      Reads and returns the current value of CMCV.  This function is only available on Itanium processors.    @return The current value of CMCV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadCmcv
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Local Redirection Register #0 (LRR0).      Reads and returns the current value of LRR0.  This function is only available on Itanium processors.     @return The current value of LRR0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadLrr0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Local Redirection Register #1 (LRR1).      Reads and returns the current value of LRR1.  This function is only available on Itanium processors.    @return The current value of LRR1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadLrr1
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Page Local Interrupt ID Register (LID).      Writes the current value of LID.  The 64-bit value written to the LID is returned.     No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of LID must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to LID.    @return The 64-bit value written to the LID.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteLid
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Task Priority Register (TPR).      Writes the current value of TPR.  The 64-bit value written to the TPR is returned.    No parameter checking is performed on Value.  All bits of Value corresponding to   reserved fields of TPR must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to TPR.    @return The 64-bit value written to the TPR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteTpr
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a write operation on End OF External Interrupt Register (EOI).      Writes a value of 0 to the EOI Register.  This function is only available on Itanium processors.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteEoi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Performance Monitor Vector Register (PMV).      Writes the current value of PMV.  The 64-bit value written to the PMV is returned.     No parameter checking is performed on Value.  All bits of Value corresponding   to reserved fields of PMV must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to PMV.    @return The 64-bit value written to the PMV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWritePmv
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Corrected Machine Check Vector Register (CMCV).      Writes the current value of CMCV.  The 64-bit value written to the CMCV is returned.    No parameter checking is performed on Value.  All bits of Value corresponding   to reserved fields of CMCV must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to CMCV.    @return The 64-bit value written to the CMCV.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteCmcv
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Local Redirection Register #0 (LRR0).      Writes the current value of LRR0.  The 64-bit value written to the LRR0 is returned.     No parameter checking is performed on Value.  All bits of Value corresponding   to reserved fields of LRR0 must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to LRR0.    @return The 64-bit value written to the LRR0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteLrr0
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Local Redirection Register #1 (LRR1).      Writes the current value of LRR1.  The 64-bit value written to the LRR1 is returned.    No parameter checking is performed on Value.  All bits of Value corresponding   to reserved fields of LRR1 must be 0 or a Reserved Register/Field fault may occur.   The caller must either guarantee that Value is valid, or the caller must   set up fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Value    The 64-bit value to write to LRR1.    @return The 64-bit value written to the LRR1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteLrr1
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Instruction Breakpoint Register (IBR).      The Instruction Breakpoint Registers are used in pairs.  The even numbered   registers contain breakpoint addresses, and the odd numbered registers contain   breakpoint mask conditions.  At least four instruction registers pairs are implemented   on all processor models.   Implemented registers are contiguous starting with   register 0.  No parameter checking is performed on Index, and if the Index value   is beyond the implemented IBR register range, a Reserved Register/Field fault may   occur.  The caller must either guarantee that Index is valid, or the caller must   set up fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Index    The 8-bit Instruction Breakpoint Register index to read.    @return The current value of Instruction Breakpoint Register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadIbr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Data Breakpoint Register (DBR).    The Data Breakpoint Registers are used in pairs.  The even numbered registers   contain breakpoint addresses, and odd numbered registers contain breakpoint   mask conditions.  At least four data registers pairs are implemented on all processor   models.  Implemented registers are contiguous starting with register 0.   No parameter checking is performed on Index.  If the Index value is beyond   the implemented DBR register range, a Reserved Register/Field fault may occur.   The caller must either guarantee that Index is valid, or the caller must set up   fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Index    The 8-bit Data Breakpoint Register index to read.    @return The current value of Data Breakpoint Register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadDbr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Performance Monitor Configuration Register (PMC).    All processor implementations provide at least four performance counters   (PMC/PMD [4]...PMC/PMD [7] pairs), and four performance monitor counter overflow   status registers (PMC [0]... PMC [3]).  Processor implementations may provide   additional implementation-dependent PMC and PMD to increase the number of   'generic' performance counters (PMC/PMD pairs).  The remainder of PMC and PMD   register set is implementation dependent.  No parameter checking is performed   on Index.  If the Index value is beyond the implemented PMC register range,   zero value will be returned.   This function is only available on Itanium processors.    @param Index    The 8-bit Performance Monitor Configuration Register index to read.    @return   The current value of Performance Monitor Configuration Register             specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPmc
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Performance Monitor Data Register (PMD).    All processor implementations provide at least 4 performance counters   (PMC/PMD [4]...PMC/PMD [7] pairs), and 4 performance monitor counter   overflow status registers (PMC [0]... PMC [3]).  Processor implementations may   provide additional implementation-dependent PMC and PMD to increase the number   of 'generic' performance counters (PMC/PMD pairs).  The remainder of PMC and PMD   register set is implementation dependent.  No parameter checking is performed   on Index.  If the Index value is beyond the implemented PMD register range,   zero value will be returned.   This function is only available on Itanium processors.    @param Index    The 8-bit Performance Monitor Data Register index to read.    @return The current value of Performance Monitor Data Register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPmd
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Instruction Breakpoint Register (IBR).    Writes current value of Instruction Breakpoint Register specified by Index.   The Instruction Breakpoint Registers are used in pairs.  The even numbered   registers contain breakpoint addresses, and odd numbered registers contain   breakpoint mask conditions.  At least four instruction registers pairs are implemented   on all processor models.  Implemented registers are contiguous starting with   register 0.  No parameter checking is performed on Index.  If the Index value   is beyond the implemented IBR register range, a Reserved Register/Field fault may   occur.  The caller must either guarantee that Index is valid, or the caller must   set up fault handlers to catch the faults.   This function is only available on Itanium processors.    @param Index    The 8-bit Instruction Breakpoint Register index to write.   @param Value    The 64-bit value to write to IBR.    @return The 64-bit value written to the IBR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteIbr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Data Breakpoint Register (DBR).    Writes current value of Data Breakpoint Register specified by Index.   The Data Breakpoint Registers are used in pairs.  The even numbered registers   contain breakpoint addresses, and odd numbered registers contain breakpoint   mask conditions.  At least four data registers pairs are implemented on all processor   models.  Implemented registers are contiguous starting with register 0.  No parameter   checking is performed on Index.  If the Index value is beyond the implemented   DBR register range, a Reserved Register/Field fault may occur.  The caller must   either guarantee that Index is valid, or the caller must set up fault handlers to   catch the faults.   This function is only available on Itanium processors.    @param Index    The 8-bit Data Breakpoint Register index to write.   @param Value    The 64-bit value to write to DBR.    @return The 64-bit value written to the DBR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteDbr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Performance Monitor Configuration Register (PMC).    Writes current value of Performance Monitor Configuration Register specified by Index.   All processor implementations provide at least four performance counters   (PMC/PMD [4]...PMC/PMD [7] pairs), and four performance monitor counter overflow status   registers (PMC [0]... PMC [3]).  Processor implementations may provide additional   implementation-dependent PMC and PMD to increase the number of 'generic' performance   counters (PMC/PMD pairs).  The remainder of PMC and PMD register set is implementation   dependent.  No parameter checking is performed on Index.  If the Index value is   beyond the implemented PMC register range, the write is ignored.   This function is only available on Itanium processors.    @param Index    The 8-bit Performance Monitor Configuration Register index to write.   @param Value    The 64-bit value to write to PMC.    @return The 64-bit value written to the PMC.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWritePmc
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit Performance Monitor Data Register (PMD).    Writes current value of Performance Monitor Data Register specified by Index.   All processor implementations provide at least four performance counters   (PMC/PMD [4]...PMC/PMD [7] pairs), and four performance monitor counter overflow   status registers (PMC [0]... PMC [3]).  Processor implementations may provide   additional implementation-dependent PMC and PMD to increase the number of 'generic'   performance counters (PMC/PMD pairs).  The remainder of PMC and PMD register set   is implementation dependent.  No parameter checking is performed on Index.  If the   Index value is beyond the implemented PMD register range, the write is ignored.   This function is only available on Itanium processors.    @param Index    The 8-bit Performance Monitor Data Register index to write.   @param Value    The 64-bit value to write to PMD.    @return The 64-bit value written to the PMD.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWritePmd
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Global Pointer (GP).    Reads and returns the current value of GP.   This function is only available on Itanium processors.    @return The current value of GP.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadGp
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the current value of 64-bit Global Pointer (GP).    Writes the current value of GP. The 64-bit value written to the GP is returned.   No parameter checking is performed on Value.   This function is only available on Itanium processors.    @param Value  The 64-bit value to write to GP.    @return The 64-bit value written to the GP.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteGp
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit Stack Pointer (SP).    Reads and returns the current value of SP.   This function is only available on Itanium processors.    @return The current value of SP.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadSp
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///
end_comment

begin_comment
comment|/// Valid Index value for AsmReadControlRegister().
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_DCR
value|0
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_ITM
value|1
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IVA
value|2
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_PTA
value|8
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IPSR
value|16
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_ISR
value|17
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IIP
value|19
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IFA
value|20
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_ITIR
value|21
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IIPA
value|22
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IFS
value|23
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IIM
value|24
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IHA
value|25
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_LID
value|64
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IVR
value|65
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_TPR
value|66
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_EOI
value|67
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IRR0
value|68
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IRR1
value|69
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IRR2
value|70
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_IRR3
value|71
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_ITV
value|72
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_PMV
value|73
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_CMCV
value|74
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_LRR0
value|80
end_define

begin_define
define|#
directive|define
name|IPF_CONTROL_REGISTER_LRR1
value|81
end_define

begin_comment
comment|/**   Reads a 64-bit control register.    Reads and returns the control register specified by Index. The valid Index valued    are defined above in "Related Definitions".   If Index is invalid then 0xFFFFFFFFFFFFFFFF is returned.  This function is only    available on Itanium processors.    @param  Index                     The index of the control register to read.    @return The control register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadControlRegister
parameter_list|(
name|IN
name|UINT64
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///
end_comment

begin_comment
comment|/// Valid Index value for AsmReadApplicationRegister().
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K0
value|0
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K1
value|1
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K2
value|2
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K3
value|3
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K4
value|4
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K5
value|5
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K6
value|6
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_K7
value|7
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_RSC
value|16
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_BSP
value|17
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_BSPSTORE
value|18
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_RNAT
value|19
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_FCR
value|21
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_EFLAG
value|24
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_CSD
value|25
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_SSD
value|26
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_CFLG
value|27
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_FSR
value|28
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_FIR
value|29
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_FDR
value|30
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_CCV
value|32
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_UNAT
value|36
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_FPSR
value|40
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_ITC
value|44
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_PFS
value|64
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_LC
value|65
end_define

begin_define
define|#
directive|define
name|IPF_APPLICATION_REGISTER_EC
value|66
end_define

begin_comment
comment|/**   Reads a 64-bit application register.    Reads and returns the application register specified by Index. The valid Index    valued are defined above in "Related Definitions".   If Index is invalid then 0xFFFFFFFFFFFFFFFF is returned.  This function is only    available on Itanium processors.    @param  Index                     The index of the application register to read.    @return The application register specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadApplicationRegister
parameter_list|(
name|IN
name|UINT64
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of a Machine Specific Register (MSR).    Reads and returns the current value of the Machine Specific Register specified by Index.  No   parameter checking is performed on Index, and if the Index value is beyond the implemented MSR   register range, a Reserved Register/Field fault may occur.  The caller must either guarantee that   Index is valid, or the caller must set up fault handlers to catch the faults.  This function is   only available on Itanium processors.    @param  Index                     The 8-bit Machine Specific Register index to read.    @return The current value of the Machine Specific Register specified by Index.    **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMsr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of a Machine Specific Register (MSR).    Writes Value to the Machine Specific Register specified by Index.  Value is returned.  No   parameter checking is performed on Index, and if the Index value is beyond the implemented MSR   register range, a Reserved Register/Field fault may occur.  The caller must either guarantee that   Index is valid, or the caller must set up fault handlers to catch the faults.  This function is   only available on Itanium processors.    @param  Index                     The 8-bit Machine Specific Register index to write.   @param  Value                     The 64-bit value to write to the Machine Specific Register.    @return The 64-bit value to write to the Machine Specific Register.    **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteMsr
parameter_list|(
name|IN
name|UINT8
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if the CPU is currently executing in virtual, physical, or mixed mode.    Determines the current execution mode of the CPU.   If the CPU is in virtual mode(PSR.RT=1, PSR.DT=1, PSR.IT=1), then 1 is returned.   If the CPU is in physical mode(PSR.RT=0, PSR.DT=0, PSR.IT=0), then 0 is returned.   If the CPU is not in physical mode or virtual mode, then it is in mixed mode,   and -1 is returned.   This function is only available on Itanium processors.    @retval  1  The CPU is in virtual mode.   @retval  0  The CPU is in physical mode.   @retval -1  The CPU is in mixed mode.  **/
end_comment

begin_function_decl
name|INT64
name|EFIAPI
name|AsmCpuVirtual
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Makes a PAL procedure call.    This is a wrapper function to make a PAL procedure call.  Based on the Index   value this API will make static or stacked PAL call.  The following table   describes the usage of PAL Procedure Index Assignment. Architected procedures   may be designated as required or optional.  If a PAL procedure is specified   as optional, a unique return code of 0xFFFFFFFFFFFFFFFF is returned in the   Status field of the PAL_CALL_RETURN structure.   This indicates that the procedure is not present in this PAL implementation.   It is the caller's responsibility to check for this return code after calling   any optional PAL procedure.   No parameter checking is performed on the 5 input parameters, but there are   some common rules that the caller should follow when making a PAL call.  Any   address passed to PAL as buffers for return parameters must be 8-byte aligned.   Unaligned addresses may cause undefined results.  For those parameters defined   as reserved or some fields defined as reserved must be zero filled or the invalid   argument return value may be returned or undefined result may occur during the   execution of the procedure.  If the PalEntryPoint  does not point to a valid   PAL entry point then the system behavior is undefined.  This function is only   available on Itanium processors.    @param PalEntryPoint  The PAL procedure calls entry point.   @param Index          The PAL procedure Index number.   @param Arg2           The 2nd parameter for PAL procedure calls.   @param Arg3           The 3rd parameter for PAL procedure calls.   @param Arg4           The 4th parameter for PAL procedure calls.    @return structure returned from the PAL Call procedure, including the status and return value.  **/
end_comment

begin_function_decl
name|PAL_CALL_RETURN
name|EFIAPI
name|AsmPalCall
parameter_list|(
name|IN
name|UINT64
name|PalEntryPoint
parameter_list|,
name|IN
name|UINT64
name|Index
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
operator|||
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32 and x64 Specific Functions.
end_comment

begin_comment
comment|/// Byte packed structure for 16-bit Real Mode EFLAGS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|CF
range|:
literal|1
decl_stmt|;
comment|///< Carry Flag.
name|UINT32
name|Reserved_0
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|PF
range|:
literal|1
decl_stmt|;
comment|///< Parity Flag.
name|UINT32
name|Reserved_1
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|AF
range|:
literal|1
decl_stmt|;
comment|///< Auxiliary Carry Flag.
name|UINT32
name|Reserved_2
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|ZF
range|:
literal|1
decl_stmt|;
comment|///< Zero Flag.
name|UINT32
name|SF
range|:
literal|1
decl_stmt|;
comment|///< Sign Flag.
name|UINT32
name|TF
range|:
literal|1
decl_stmt|;
comment|///< Trap Flag.
name|UINT32
name|IF
range|:
literal|1
decl_stmt|;
comment|///< Interrupt Enable Flag.
name|UINT32
name|DF
range|:
literal|1
decl_stmt|;
comment|///< Direction Flag.
name|UINT32
name|OF
range|:
literal|1
decl_stmt|;
comment|///< Overflow Flag.
name|UINT32
name|IOPL
range|:
literal|2
decl_stmt|;
comment|///< I/O Privilege Level.
name|UINT32
name|NT
range|:
literal|1
decl_stmt|;
comment|///< Nested Task.
name|UINT32
name|Reserved_3
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
block|}
name|Bits
struct|;
name|UINT16
name|Uint16
decl_stmt|;
block|}
name|IA32_FLAGS16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for EFLAGS/RFLAGS.
end_comment

begin_comment
comment|/// 32-bits on IA-32.
end_comment

begin_comment
comment|/// 64-bits on x64.  The upper 32-bits on x64 are reserved.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|CF
range|:
literal|1
decl_stmt|;
comment|///< Carry Flag.
name|UINT32
name|Reserved_0
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|PF
range|:
literal|1
decl_stmt|;
comment|///< Parity Flag.
name|UINT32
name|Reserved_1
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|AF
range|:
literal|1
decl_stmt|;
comment|///< Auxiliary Carry Flag.
name|UINT32
name|Reserved_2
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|ZF
range|:
literal|1
decl_stmt|;
comment|///< Zero Flag.
name|UINT32
name|SF
range|:
literal|1
decl_stmt|;
comment|///< Sign Flag.
name|UINT32
name|TF
range|:
literal|1
decl_stmt|;
comment|///< Trap Flag.
name|UINT32
name|IF
range|:
literal|1
decl_stmt|;
comment|///< Interrupt Enable Flag.
name|UINT32
name|DF
range|:
literal|1
decl_stmt|;
comment|///< Direction Flag.
name|UINT32
name|OF
range|:
literal|1
decl_stmt|;
comment|///< Overflow Flag.
name|UINT32
name|IOPL
range|:
literal|2
decl_stmt|;
comment|///< I/O Privilege Level.
name|UINT32
name|NT
range|:
literal|1
decl_stmt|;
comment|///< Nested Task.
name|UINT32
name|Reserved_3
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|RF
range|:
literal|1
decl_stmt|;
comment|///< Resume Flag.
name|UINT32
name|VM
range|:
literal|1
decl_stmt|;
comment|///< Virtual 8086 Mode.
name|UINT32
name|AC
range|:
literal|1
decl_stmt|;
comment|///< Alignment Check.
name|UINT32
name|VIF
range|:
literal|1
decl_stmt|;
comment|///< Virtual Interrupt Flag.
name|UINT32
name|VIP
range|:
literal|1
decl_stmt|;
comment|///< Virtual Interrupt Pending.
name|UINT32
name|ID
range|:
literal|1
decl_stmt|;
comment|///< ID Flag.
name|UINT32
name|Reserved_4
range|:
literal|10
decl_stmt|;
comment|///< Reserved.
block|}
name|Bits
struct|;
name|UINTN
name|UintN
decl_stmt|;
block|}
name|IA32_EFLAGS32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for Control Register 0 (CR0).
end_comment

begin_comment
comment|/// 32-bits on IA-32.
end_comment

begin_comment
comment|/// 64-bits on x64.  The upper 32-bits on x64 are reserved.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|PE
range|:
literal|1
decl_stmt|;
comment|///< Protection Enable.
name|UINT32
name|MP
range|:
literal|1
decl_stmt|;
comment|///< Monitor Coprocessor.
name|UINT32
name|EM
range|:
literal|1
decl_stmt|;
comment|///< Emulation.
name|UINT32
name|TS
range|:
literal|1
decl_stmt|;
comment|///< Task Switched.
name|UINT32
name|ET
range|:
literal|1
decl_stmt|;
comment|///< Extension Type.
name|UINT32
name|NE
range|:
literal|1
decl_stmt|;
comment|///< Numeric Error.
name|UINT32
name|Reserved_0
range|:
literal|10
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|WP
range|:
literal|1
decl_stmt|;
comment|///< Write Protect.
name|UINT32
name|Reserved_1
range|:
literal|1
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|AM
range|:
literal|1
decl_stmt|;
comment|///< Alignment Mask.
name|UINT32
name|Reserved_2
range|:
literal|10
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|NW
range|:
literal|1
decl_stmt|;
comment|///< Mot Write-through.
name|UINT32
name|CD
range|:
literal|1
decl_stmt|;
comment|///< Cache Disable.
name|UINT32
name|PG
range|:
literal|1
decl_stmt|;
comment|///< Paging.
block|}
name|Bits
struct|;
name|UINTN
name|UintN
decl_stmt|;
block|}
name|IA32_CR0
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for Control Register 4 (CR4).
end_comment

begin_comment
comment|/// 32-bits on IA-32.
end_comment

begin_comment
comment|/// 64-bits on x64.  The upper 32-bits on x64 are reserved.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|VME
range|:
literal|1
decl_stmt|;
comment|///< Virtual-8086 Mode Extensions.
name|UINT32
name|PVI
range|:
literal|1
decl_stmt|;
comment|///< Protected-Mode Virtual Interrupts.
name|UINT32
name|TSD
range|:
literal|1
decl_stmt|;
comment|///< Time Stamp Disable.
name|UINT32
name|DE
range|:
literal|1
decl_stmt|;
comment|///< Debugging Extensions.
name|UINT32
name|PSE
range|:
literal|1
decl_stmt|;
comment|///< Page Size Extensions.
name|UINT32
name|PAE
range|:
literal|1
decl_stmt|;
comment|///< Physical Address Extension.
name|UINT32
name|MCE
range|:
literal|1
decl_stmt|;
comment|///< Machine Check Enable.
name|UINT32
name|PGE
range|:
literal|1
decl_stmt|;
comment|///< Page Global Enable.
name|UINT32
name|PCE
range|:
literal|1
decl_stmt|;
comment|///< Performance Monitoring Counter
comment|///< Enable.
name|UINT32
name|OSFXSR
range|:
literal|1
decl_stmt|;
comment|///< Operating System Support for
comment|///< FXSAVE and FXRSTOR instructions
name|UINT32
name|OSXMMEXCPT
range|:
literal|1
decl_stmt|;
comment|///< Operating System Support for
comment|///< Unmasked SIMD Floating Point
comment|///< Exceptions.
name|UINT32
name|Reserved_0
range|:
literal|2
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|VMXE
range|:
literal|1
decl_stmt|;
comment|///< VMX Enable
name|UINT32
name|Reserved_1
range|:
literal|18
decl_stmt|;
comment|///< Reserved.
block|}
name|Bits
struct|;
name|UINTN
name|UintN
decl_stmt|;
block|}
name|IA32_CR4
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for a segment descriptor in a GDT/LDT.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|LimitLow
range|:
literal|16
decl_stmt|;
name|UINT32
name|BaseLow
range|:
literal|16
decl_stmt|;
name|UINT32
name|BaseMid
range|:
literal|8
decl_stmt|;
name|UINT32
name|Type
range|:
literal|4
decl_stmt|;
name|UINT32
name|S
range|:
literal|1
decl_stmt|;
name|UINT32
name|DPL
range|:
literal|2
decl_stmt|;
name|UINT32
name|P
range|:
literal|1
decl_stmt|;
name|UINT32
name|LimitHigh
range|:
literal|4
decl_stmt|;
name|UINT32
name|AVL
range|:
literal|1
decl_stmt|;
name|UINT32
name|L
range|:
literal|1
decl_stmt|;
name|UINT32
name|DB
range|:
literal|1
decl_stmt|;
name|UINT32
name|G
range|:
literal|1
decl_stmt|;
name|UINT32
name|BaseHigh
range|:
literal|8
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT64
name|Uint64
decl_stmt|;
block|}
name|IA32_SEGMENT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for an IDTR, GDTR, LDTR descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Limit
decl_stmt|;
name|UINTN
name|Base
decl_stmt|;
block|}
name|IA32_DESCRIPTOR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|IA32_IDT_GATE_TYPE_TASK
value|0x85
end_define

begin_define
define|#
directive|define
name|IA32_IDT_GATE_TYPE_INTERRUPT_16
value|0x86
end_define

begin_define
define|#
directive|define
name|IA32_IDT_GATE_TYPE_TRAP_16
value|0x87
end_define

begin_define
define|#
directive|define
name|IA32_IDT_GATE_TYPE_INTERRUPT_32
value|0x8E
end_define

begin_define
define|#
directive|define
name|IA32_IDT_GATE_TYPE_TRAP_32
value|0x8F
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for an IA-32 Interrupt Gate Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|OffsetLow
range|:
literal|16
decl_stmt|;
comment|///< Offset bits 15..0.
name|UINT32
name|Selector
range|:
literal|16
decl_stmt|;
comment|///< Selector.
name|UINT32
name|Reserved_0
range|:
literal|8
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|GateType
range|:
literal|8
decl_stmt|;
comment|///< Gate Type.  See #defines above.
name|UINT32
name|OffsetHigh
range|:
literal|16
decl_stmt|;
comment|///< Offset bits 31..16.
block|}
name|Bits
struct|;
name|UINT64
name|Uint64
decl_stmt|;
block|}
name|IA32_IDT_GATE_DESCRIPTOR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for an x64 Interrupt Gate Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|OffsetLow
range|:
literal|16
decl_stmt|;
comment|///< Offset bits 15..0.
name|UINT32
name|Selector
range|:
literal|16
decl_stmt|;
comment|///< Selector.
name|UINT32
name|Reserved_0
range|:
literal|8
decl_stmt|;
comment|///< Reserved.
name|UINT32
name|GateType
range|:
literal|8
decl_stmt|;
comment|///< Gate Type.  See #defines above.
name|UINT32
name|OffsetHigh
range|:
literal|16
decl_stmt|;
comment|///< Offset bits 31..16.
name|UINT32
name|OffsetUpper
range|:
literal|32
decl_stmt|;
comment|///< Offset bits 63..32.
name|UINT32
name|Reserved_1
range|:
literal|32
decl_stmt|;
comment|///< Reserved.
block|}
name|Bits
struct|;
struct|struct
block|{
name|UINT64
name|Uint64
decl_stmt|;
name|UINT64
name|Uint64_1
decl_stmt|;
block|}
name|Uint128
struct|;
block|}
name|IA32_IDT_GATE_DESCRIPTOR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for an FP/SSE/SSE2 context.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Buffer
index|[
literal|512
index|]
decl_stmt|;
block|}
name|IA32_FX_BUFFER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structures for the 16-bit real mode thunks.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Reserved1
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT32
name|Reserved3
decl_stmt|;
name|UINT32
name|Reserved4
decl_stmt|;
name|UINT8
name|BL
decl_stmt|;
name|UINT8
name|BH
decl_stmt|;
name|UINT16
name|Reserved5
decl_stmt|;
name|UINT8
name|DL
decl_stmt|;
name|UINT8
name|DH
decl_stmt|;
name|UINT16
name|Reserved6
decl_stmt|;
name|UINT8
name|CL
decl_stmt|;
name|UINT8
name|CH
decl_stmt|;
name|UINT16
name|Reserved7
decl_stmt|;
name|UINT8
name|AL
decl_stmt|;
name|UINT8
name|AH
decl_stmt|;
name|UINT16
name|Reserved8
decl_stmt|;
block|}
name|IA32_BYTE_REGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|DI
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT16
name|SI
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
name|UINT16
name|BP
decl_stmt|;
name|UINT16
name|Reserved3
decl_stmt|;
name|UINT16
name|SP
decl_stmt|;
name|UINT16
name|Reserved4
decl_stmt|;
name|UINT16
name|BX
decl_stmt|;
name|UINT16
name|Reserved5
decl_stmt|;
name|UINT16
name|DX
decl_stmt|;
name|UINT16
name|Reserved6
decl_stmt|;
name|UINT16
name|CX
decl_stmt|;
name|UINT16
name|Reserved7
decl_stmt|;
name|UINT16
name|AX
decl_stmt|;
name|UINT16
name|Reserved8
decl_stmt|;
block|}
name|IA32_WORD_REGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|EDI
decl_stmt|;
name|UINT32
name|ESI
decl_stmt|;
name|UINT32
name|EBP
decl_stmt|;
name|UINT32
name|ESP
decl_stmt|;
name|UINT32
name|EBX
decl_stmt|;
name|UINT32
name|EDX
decl_stmt|;
name|UINT32
name|ECX
decl_stmt|;
name|UINT32
name|EAX
decl_stmt|;
name|UINT16
name|DS
decl_stmt|;
name|UINT16
name|ES
decl_stmt|;
name|UINT16
name|FS
decl_stmt|;
name|UINT16
name|GS
decl_stmt|;
name|IA32_EFLAGS32
name|EFLAGS
decl_stmt|;
name|UINT32
name|Eip
decl_stmt|;
name|UINT16
name|CS
decl_stmt|;
name|UINT16
name|SS
decl_stmt|;
block|}
name|IA32_DWORD_REGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|IA32_DWORD_REGS
name|E
decl_stmt|;
name|IA32_WORD_REGS
name|X
decl_stmt|;
name|IA32_BYTE_REGS
name|H
decl_stmt|;
block|}
name|IA32_REGISTER_SET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Byte packed structure for an 16-bit real mode thunks.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|IA32_REGISTER_SET
modifier|*
name|RealModeState
decl_stmt|;
name|VOID
modifier|*
name|RealModeBuffer
decl_stmt|;
name|UINT32
name|RealModeBufferSize
decl_stmt|;
name|UINT32
name|ThunkAttributes
decl_stmt|;
block|}
name|THUNK_CONTEXT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|THUNK_ATTRIBUTE_BIG_REAL_MODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|THUNK_ATTRIBUTE_DISABLE_A20_MASK_INT_15
value|0x00000002
end_define

begin_define
define|#
directive|define
name|THUNK_ATTRIBUTE_DISABLE_A20_MASK_KBD_CTRL
value|0x00000004
end_define

begin_comment
comment|/**   Retrieves CPUID information.    Executes the CPUID instruction with EAX set to the value specified by Index.   This function always returns Index.   If Eax is not NULL, then the value of EAX after CPUID is returned in Eax.   If Ebx is not NULL, then the value of EBX after CPUID is returned in Ebx.   If Ecx is not NULL, then the value of ECX after CPUID is returned in Ecx.   If Edx is not NULL, then the value of EDX after CPUID is returned in Edx.   This function is only available on IA-32 and x64.    @param  Index The 32-bit value to load into EAX prior to invoking the CPUID                 instruction.   @param  Eax   The pointer to the 32-bit EAX value returned by the CPUID                 instruction. This is an optional parameter that may be NULL.   @param  Ebx   The pointer to the 32-bit EBX value returned by the CPUID                 instruction. This is an optional parameter that may be NULL.   @param  Ecx   The pointer to the 32-bit ECX value returned by the CPUID                 instruction. This is an optional parameter that may be NULL.   @param  Edx   The pointer to the 32-bit EDX value returned by the CPUID                 instruction. This is an optional parameter that may be NULL.    @return Index.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmCpuid
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Eax
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Ebx
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Ecx
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Edx
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves CPUID information using an extended leaf identifier.    Executes the CPUID instruction with EAX set to the value specified by Index   and ECX set to the value specified by SubIndex. This function always returns   Index. This function is only available on IA-32 and x64.    If Eax is not NULL, then the value of EAX after CPUID is returned in Eax.   If Ebx is not NULL, then the value of EBX after CPUID is returned in Ebx.   If Ecx is not NULL, then the value of ECX after CPUID is returned in Ecx.   If Edx is not NULL, then the value of EDX after CPUID is returned in Edx.    @param  Index     The 32-bit value to load into EAX prior to invoking the                     CPUID instruction.   @param  SubIndex  The 32-bit value to load into ECX prior to invoking the                     CPUID instruction.   @param  Eax       The pointer to the 32-bit EAX value returned by the CPUID                     instruction. This is an optional parameter that may be                     NULL.   @param  Ebx       The pointer to the 32-bit EBX value returned by the CPUID                     instruction. This is an optional parameter that may be                     NULL.   @param  Ecx       The pointer to the 32-bit ECX value returned by the CPUID                     instruction. This is an optional parameter that may be                     NULL.   @param  Edx       The pointer to the 32-bit EDX value returned by the CPUID                     instruction. This is an optional parameter that may be                     NULL.    @return Index.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmCpuidEx
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT32
name|SubIndex
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Eax
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Ebx
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Ecx
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|Edx
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set CD bit and clear NW bit of CR0 followed by a WBINVD.    Disables the caches by setting the CD bit of CR0 to 1, clearing the NW bit of CR0 to 0,   and executing a WBINVD instruction.  This function is only available on IA-32 and x64.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmDisableCache
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Perform a WBINVD and clear both the CD and NW bits of CR0.    Enables the caches by executing a WBINVD instruction and then clear both the CD and NW   bits of CR0 to 0.  This function is only available on IA-32 and x64.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmEnableCache
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the lower 32-bits of a Machine Specific Register(MSR).    Reads and returns the lower 32-bits of the MSR specified by Index.   No parameter checking is performed on Index, and some Index values may cause   CPU exceptions. The caller must either guarantee that Index is valid, or the   caller must set up exception handlers to catch the exceptions. This function   is only available on IA-32 and x64.    @param  Index The 32-bit MSR index to read.    @return The lower 32 bits of the MSR identified by Index.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmReadMsr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit value to a Machine Specific Register(MSR), and returns the value.   The upper 32-bits of the MSR are set to zero.    Writes the 32-bit value specified by Value to the MSR specified by Index. The   upper 32-bits of the MSR write are set to zero. The 32-bit value written to   the MSR is returned. No parameter checking is performed on Index or Value,   and some of these may cause CPU exceptions. The caller must either guarantee   that Index and Value are valid, or the caller must establish proper exception   handlers. This function is only available on IA-32 and x64.    @param  Index The 32-bit MSR index to write.   @param  Value The 32-bit value to write to the MSR.    @return Value  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmWriteMsr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise OR on the lower 32-bits, and   writes the result back to the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise OR   between the lower 32-bits of the read result and the value specified by   OrData, and writes the result to the 64-bit MSR specified by Index. The lower   32-bits of the value written to the MSR is returned. No parameter checking is   performed on Index or OrData, and some of these may cause CPU exceptions. The   caller must either guarantee that Index and OrData are valid, or the caller   must establish proper exception handlers. This function is only available on   IA-32 and x64.    @param  Index   The 32-bit MSR index to write.   @param  OrData  The value to OR with the read value from the MSR.    @return The lower 32-bit value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrOr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise AND on the lower 32-bits, and writes   the result back to the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between the   lower 32-bits of the read result and the value specified by AndData, and   writes the result to the 64-bit MSR specified by Index. The lower 32-bits of   the value written to the MSR is returned. No parameter checking is performed   on Index or AndData, and some of these may cause CPU exceptions. The caller   must either guarantee that Index and AndData are valid, or the caller must   establish proper exception handlers. This function is only available on IA-32   and x64.    @param  Index   The 32-bit MSR index to write.   @param  AndData The value to AND with the read value from the MSR.    @return The lower 32-bit value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrAnd32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise AND followed by a bitwise OR   on the lower 32-bits, and writes the result back to the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between the   lower 32-bits of the read result and the value specified by AndData   preserving the upper 32-bits, performs a bitwise OR between the   result of the AND operation and the value specified by OrData, and writes the   result to the 64-bit MSR specified by Address. The lower 32-bits of the value   written to the MSR is returned. No parameter checking is performed on Index,   AndData, or OrData, and some of these may cause CPU exceptions. The caller   must either guarantee that Index, AndData, and OrData are valid, or the   caller must establish proper exception handlers. This function is only   available on IA-32 and x64.    @param  Index   The 32-bit MSR index to write.   @param  AndData The value to AND with the read value from the MSR.   @param  OrData  The value to OR with the result of the AND operation.    @return The lower 32-bit value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrAndThenOr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an MSR.    Reads the bit field in the lower 32-bits of a 64-bit MSR. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned. The caller must either guarantee that Index is valid, or the caller   must set up exception handlers to catch the exceptions. This function is only   available on IA-32 and x64.    If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Index     The 32-bit MSR index to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.    @return The bit field read from the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrBitFieldRead32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an MSR.    Writes Value to a bit field in the lower 32-bits of a 64-bit MSR. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination MSR are preserved. The lower 32-bits of the MSR written is   returned. The caller must either guarantee that Index and the data written    is valid, or the caller must set up exception handlers to catch the exceptions.    This function is only available on IA-32 and x64.    If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  Value     New value of the bit field.    @return The lower 32-bit of the value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrBitFieldWrite32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise OR, and writes the   result back to the bit field in the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit MSR specified by Index. The lower 32-bits of the value   written to the MSR are returned. Extra left bits in OrData are stripped. The   caller must either guarantee that Index and the data written is valid, or   the caller must set up exception handlers to catch the exceptions. This   function is only available on IA-32 and x64.    If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  OrData    The value to OR with the read value from the MSR.    @return The lower 32-bit of the value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrBitFieldOr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise AND, and writes the   result back to the bit field in the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between the   read result and the value specified by AndData, and writes the result to the   64-bit MSR specified by Index. The lower 32-bits of the value written to the   MSR are returned. Extra left bits in AndData are stripped. The caller must   either guarantee that Index and the data written is valid, or the caller must   set up exception handlers to catch the exceptions. This function is only   available on IA-32 and x64.    If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the MSR.    @return The lower 32-bit of the value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrBitFieldAnd32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND followed by a   bitwise OR between the read result and the value specified by   AndData, and writes the result to the 64-bit MSR specified by Index. The   lower 32-bits of the value written to the MSR are returned. Extra left bits   in both AndData and OrData are stripped. The caller must either guarantee   that Index and the data written is valid, or the caller must set up exception   handlers to catch the exceptions. This function is only available on IA-32   and x64.    If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the MSR.   @param  OrData    The value to OR with the result of the AND operation.    @return The lower 32-bit of the value written to the MSR.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|AsmMsrBitFieldAndThenOr32
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a 64-bit Machine Specific Register(MSR).    Reads and returns the 64-bit MSR specified by Index. No parameter checking is   performed on Index, and some Index values may cause CPU exceptions. The   caller must either guarantee that Index is valid, or the caller must set up   exception handlers to catch the exceptions. This function is only available   on IA-32 and x64.    @param  Index The 32-bit MSR index to read.    @return The value of the MSR identified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMsr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit value to a Machine Specific Register(MSR), and returns the   value.    Writes the 64-bit value specified by Value to the MSR specified by Index. The   64-bit value written to the MSR is returned. No parameter checking is   performed on Index or Value, and some of these may cause CPU exceptions. The   caller must either guarantee that Index and Value are valid, or the caller   must establish proper exception handlers. This function is only available on   IA-32 and x64.    @param  Index The 32-bit MSR index to write.   @param  Value The 64-bit value to write to the MSR.    @return Value  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmWriteMsr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise OR, and writes the result   back to the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit MSR specified by Index. The value written to the MSR is   returned. No parameter checking is performed on Index or OrData, and some of   these may cause CPU exceptions. The caller must either guarantee that Index   and OrData are valid, or the caller must establish proper exception handlers.   This function is only available on IA-32 and x64.    @param  Index   The 32-bit MSR index to write.   @param  OrData  The value to OR with the read value from the MSR.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrOr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise AND, and writes the result back to the   64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between the   read result and the value specified by OrData, and writes the result to the   64-bit MSR specified by Index. The value written to the MSR is returned. No   parameter checking is performed on Index or OrData, and some of these may   cause CPU exceptions. The caller must either guarantee that Index and OrData   are valid, or the caller must establish proper exception handlers. This   function is only available on IA-32 and x64.    @param  Index   The 32-bit MSR index to write.   @param  AndData The value to AND with the read value from the MSR.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrAnd64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MSR, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between read   result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 64-bit MSR specified by Index. The value written   to the MSR is returned. No parameter checking is performed on Index, AndData,   or OrData, and some of these may cause CPU exceptions. The caller must either   guarantee that Index, AndData, and OrData are valid, or the caller must   establish proper exception handlers. This function is only available on IA-32   and x64.    @param  Index   The 32-bit MSR index to write.   @param  AndData The value to AND with the read value from the MSR.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrAndThenOr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an MSR.    Reads the bit field in the 64-bit MSR. The bit field is specified by the   StartBit and the EndBit. The value of the bit field is returned. The caller   must either guarantee that Index is valid, or the caller must set up   exception handlers to catch the exceptions. This function is only available   on IA-32 and x64.    If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Index     The 32-bit MSR index to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.    @return The value read from the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrBitFieldRead64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an MSR.    Writes Value to a bit field in a 64-bit MSR. The bit field is specified by   the StartBit and the EndBit. All other bits in the destination MSR are   preserved. The MSR written is returned. The caller must either guarantee    that Index and the data written is valid, or the caller must set up exception    handlers to catch the exceptions. This function is only available on IA-32 and x64.    If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  Value     New value of the bit field.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrBitFieldWrite64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise OR, and   writes the result back to the bit field in the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit MSR specified by Index. The value written to the MSR is   returned. Extra left bits in OrData are stripped. The caller must either   guarantee that Index and the data written is valid, or the caller must set up   exception handlers to catch the exceptions. This function is only available   on IA-32 and x64.    If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  OrData    The value to OR with the read value from the bit field.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrBitFieldOr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise AND, and writes the   result back to the bit field in the 64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND between the   read result and the value specified by AndData, and writes the result to the   64-bit MSR specified by Index. The value written to the MSR is returned.   Extra left bits in AndData are stripped. The caller must either guarantee   that Index and the data written is valid, or the caller must set up exception   handlers to catch the exceptions. This function is only available on IA-32   and x64.    If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the bit field.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrBitFieldAnd64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MSR, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   64-bit MSR.    Reads the 64-bit MSR specified by Index, performs a bitwise AND followed by   a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 64-bit MSR specified by Index. The   value written to the MSR is returned. Extra left bits in both AndData and   OrData are stripped. The caller must either guarantee that Index and the data   written is valid, or the caller must set up exception handlers to catch the   exceptions. This function is only available on IA-32 and x64.    If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Index     The 32-bit MSR index to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the bit field.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the MSR.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmMsrBitFieldAndThenOr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of the EFLAGS register.    Reads and returns the current value of the EFLAGS register. This function is   only available on IA-32 and x64. This returns a 32-bit value on IA-32 and a   64-bit value on x64.    @return EFLAGS on IA-32 or RFLAGS on x64.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadEflags
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of the Control Register 0 (CR0).    Reads and returns the current value of CR0. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of the Control Register 0 (CR0).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadCr0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of the Control Register 2 (CR2).    Reads and returns the current value of CR2. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of the Control Register 2 (CR2).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadCr2
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of the Control Register 3 (CR3).    Reads and returns the current value of CR3. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of the Control Register 3 (CR3).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadCr3
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of the Control Register 4 (CR4).    Reads and returns the current value of CR4. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of the Control Register 4 (CR4).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadCr4
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Control Register 0 (CR0).    Writes and returns a new value to CR0. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Cr0 The value to write to CR0.    @return The value written to CR0.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteCr0
parameter_list|(
name|UINTN
name|Cr0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Control Register 2 (CR2).    Writes and returns a new value to CR2. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Cr2 The value to write to CR2.    @return The value written to CR2.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteCr2
parameter_list|(
name|UINTN
name|Cr2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Control Register 3 (CR3).    Writes and returns a new value to CR3. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Cr3 The value to write to CR3.    @return The value written to CR3.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteCr3
parameter_list|(
name|UINTN
name|Cr3
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Control Register 4 (CR4).    Writes and returns a new value to CR4. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Cr4 The value to write to CR4.    @return The value written to CR4.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteCr4
parameter_list|(
name|UINTN
name|Cr4
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 0 (DR0).    Reads and returns the current value of DR0. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 0 (DR0).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 1 (DR1).    Reads and returns the current value of DR1. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 1 (DR1).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr1
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 2 (DR2).    Reads and returns the current value of DR2. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 2 (DR2).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr2
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 3 (DR3).    Reads and returns the current value of DR3. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 3 (DR3).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr3
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 4 (DR4).    Reads and returns the current value of DR4. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 4 (DR4).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr4
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 5 (DR5).    Reads and returns the current value of DR5. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 5 (DR5).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr5
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 6 (DR6).    Reads and returns the current value of DR6. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 6 (DR6).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr6
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Debug Register 7 (DR7).    Reads and returns the current value of DR7. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 7 (DR7).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmReadDr7
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 0 (DR0).    Writes and returns a new value to DR0. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr0 The value to write to Dr0.    @return The value written to Debug Register 0 (DR0).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr0
parameter_list|(
name|UINTN
name|Dr0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 1 (DR1).    Writes and returns a new value to DR1. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr1 The value to write to Dr1.    @return The value written to Debug Register 1 (DR1).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr1
parameter_list|(
name|UINTN
name|Dr1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 2 (DR2).    Writes and returns a new value to DR2. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr2 The value to write to Dr2.    @return The value written to Debug Register 2 (DR2).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr2
parameter_list|(
name|UINTN
name|Dr2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 3 (DR3).    Writes and returns a new value to DR3. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr3 The value to write to Dr3.    @return The value written to Debug Register 3 (DR3).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr3
parameter_list|(
name|UINTN
name|Dr3
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 4 (DR4).    Writes and returns a new value to DR4. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr4 The value to write to Dr4.    @return The value written to Debug Register 4 (DR4).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr4
parameter_list|(
name|UINTN
name|Dr4
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 5 (DR5).    Writes and returns a new value to DR5. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr5 The value to write to Dr5.    @return The value written to Debug Register 5 (DR5).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr5
parameter_list|(
name|UINTN
name|Dr5
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 6 (DR6).    Writes and returns a new value to DR6. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr6 The value to write to Dr6.    @return The value written to Debug Register 6 (DR6).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr6
parameter_list|(
name|UINTN
name|Dr6
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a value to Debug Register 7 (DR7).    Writes and returns a new value to DR7. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Dr7 The value to write to Dr7.    @return The value written to Debug Register 7 (DR7).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmWriteDr7
parameter_list|(
name|UINTN
name|Dr7
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Code Segment Register (CS).    Reads and returns the current value of CS. This function is only available on   IA-32 and x64.    @return The current value of CS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadCs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Data Segment Register (DS).    Reads and returns the current value of DS. This function is only available on   IA-32 and x64.    @return The current value of DS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadDs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Extra Segment Register (ES).    Reads and returns the current value of ES. This function is only available on   IA-32 and x64.    @return The current value of ES.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadEs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of FS Data Segment Register (FS).    Reads and returns the current value of FS. This function is only available on   IA-32 and x64.    @return The current value of FS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadFs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of GS Data Segment Register (GS).    Reads and returns the current value of GS. This function is only available on   IA-32 and x64.    @return The current value of GS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadGs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Stack Segment Register (SS).    Reads and returns the current value of SS. This function is only available on   IA-32 and x64.    @return The current value of SS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadSs
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Task Register (TR).    Reads and returns the current value of TR. This function is only available on   IA-32 and x64.    @return The current value of TR.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadTr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current Global Descriptor Table Register(GDTR) descriptor.    Reads and returns the current GDTR descriptor and returns it in Gdtr. This   function is only available on IA-32 and x64.    If Gdtr is NULL, then ASSERT().    @param  Gdtr  The pointer to a GDTR descriptor.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmReadGdtr
parameter_list|(
name|OUT
name|IA32_DESCRIPTOR
modifier|*
name|Gdtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current Global Descriptor Table Register (GDTR) descriptor.    Writes and the current GDTR descriptor specified by Gdtr. This function is   only available on IA-32 and x64.    If Gdtr is NULL, then ASSERT().    @param  Gdtr  The pointer to a GDTR descriptor.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteGdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Gdtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current Interrupt Descriptor Table Register(IDTR) descriptor.    Reads and returns the current IDTR descriptor and returns it in Idtr. This   function is only available on IA-32 and x64.    If Idtr is NULL, then ASSERT().    @param  Idtr  The pointer to a IDTR descriptor.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmReadIdtr
parameter_list|(
name|OUT
name|IA32_DESCRIPTOR
modifier|*
name|Idtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current Interrupt Descriptor Table Register(IDTR) descriptor.    Writes the current IDTR descriptor and returns it in Idtr. This function is   only available on IA-32 and x64.    If Idtr is NULL, then ASSERT().    @param  Idtr  The pointer to a IDTR descriptor.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteIdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Idtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current Local Descriptor Table Register(LDTR) selector.    Reads and returns the current 16-bit LDTR descriptor value. This function is   only available on IA-32 and x64.    @return The current selector of LDT.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|AsmReadLdtr
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current Local Descriptor Table Register (LDTR) selector.    Writes and the current LDTR descriptor specified by Ldtr. This function is   only available on IA-32 and x64.    @param  Ldtr  16-bit LDTR selector value.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteLdtr
parameter_list|(
name|IN
name|UINT16
name|Ldtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Save the current floating point/SSE/SSE2 context to a buffer.    Saves the current floating point/SSE/SSE2 state to the buffer specified by   Buffer. Buffer must be aligned on a 16-byte boundary. This function is only   available on IA-32 and x64.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-byte boundary, then ASSERT().    @param  Buffer  The pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmFxSave
parameter_list|(
name|OUT
name|IA32_FX_BUFFER
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Restores the current floating point/SSE/SSE2 context from a buffer.    Restores the current floating point/SSE/SSE2 state from the buffer specified   by Buffer. Buffer must be aligned on a 16-byte boundary. This function is   only available on IA-32 and x64.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-byte boundary, then ASSERT().   If Buffer was not saved with AsmFxSave(), then ASSERT().    @param  Buffer  The pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmFxRestore
parameter_list|(
name|IN
name|CONST
name|IA32_FX_BUFFER
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #0 (MM0).    Reads and returns the current value of MM0. This function is only available   on IA-32 and x64.    @return The current value of MM0.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm0
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #1 (MM1).    Reads and returns the current value of MM1. This function is only available   on IA-32 and x64.    @return The current value of MM1.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm1
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #2 (MM2).    Reads and returns the current value of MM2. This function is only available   on IA-32 and x64.    @return The current value of MM2.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm2
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #3 (MM3).    Reads and returns the current value of MM3. This function is only available   on IA-32 and x64.    @return The current value of MM3.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm3
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #4 (MM4).    Reads and returns the current value of MM4. This function is only available   on IA-32 and x64.    @return The current value of MM4.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm4
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #5 (MM5).    Reads and returns the current value of MM5. This function is only available   on IA-32 and x64.    @return The current value of MM5.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm5
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #6 (MM6).    Reads and returns the current value of MM6. This function is only available   on IA-32 and x64.    @return The current value of MM6.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm6
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #7 (MM7).    Reads and returns the current value of MM7. This function is only available   on IA-32 and x64.    @return The current value of MM7.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadMm7
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #0 (MM0).    Writes the current value of MM0. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM0.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm0
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #1 (MM1).    Writes the current value of MM1. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM1.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm1
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #2 (MM2).    Writes the current value of MM2. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM2.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm2
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #3 (MM3).    Writes the current value of MM3. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM3.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm3
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #4 (MM4).    Writes the current value of MM4. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM4.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm4
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #5 (MM5).    Writes the current value of MM5. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM5.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm5
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #6 (MM6).    Writes the current value of MM6. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM6.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm6
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #7 (MM7).    Writes the current value of MM7. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM7.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWriteMm7
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of Time Stamp Counter (TSC).    Reads and returns the current value of TSC. This function is only available   on IA-32 and x64.    @return The current value of TSC  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadTsc
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the current value of a Performance Counter (PMC).    Reads and returns the current value of performance counter specified by   Index. This function is only available on IA-32 and x64.    @param  Index The 32-bit Performance Counter index to read.    @return The value of the PMC specified by Index.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|AsmReadPmc
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sets up a monitor buffer that is used by AsmMwait().    Executes a MONITOR instruction with the register state specified by Eax, Ecx   and Edx. Returns Eax. This function is only available on IA-32 and x64.    @param  Eax The value to load into EAX or RAX before executing the MONITOR               instruction.   @param  Ecx The value to load into ECX or RCX before executing the MONITOR               instruction.   @param  Edx The value to load into EDX or RDX before executing the MONITOR               instruction.    @return Eax  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmMonitor
parameter_list|(
name|IN
name|UINTN
name|Eax
parameter_list|,
name|IN
name|UINTN
name|Ecx
parameter_list|,
name|IN
name|UINTN
name|Edx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an MWAIT instruction.    Executes an MWAIT instruction with the register state specified by Eax and   Ecx. Returns Eax. This function is only available on IA-32 and x64.    @param  Eax The value to load into EAX or RAX before executing the MONITOR               instruction.   @param  Ecx The value to load into ECX or RCX before executing the MONITOR               instruction.    @return Eax  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsmMwait
parameter_list|(
name|IN
name|UINTN
name|Eax
parameter_list|,
name|IN
name|UINTN
name|Ecx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes a WBINVD instruction.    Executes a WBINVD instruction. This function is only available on IA-32 and   x64.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmWbinvd
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes a INVD instruction.    Executes a INVD instruction. This function is only available on IA-32 and   x64.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmInvd
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Flushes a cache line from all the instruction and data caches within the   coherency domain of the CPU.    Flushed the cache line specified by LinearAddress, and returns LinearAddress.   This function is only available on IA-32 and x64.    @param  LinearAddress The address of the cache line to flush. If the CPU is                         in a physical addressing mode, then LinearAddress is a                         physical address. If the CPU is in a virtual                         addressing mode, then LinearAddress is a virtual                         address.    @return LinearAddress. **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AsmFlushCacheLine
parameter_list|(
name|IN
name|VOID
modifier|*
name|LinearAddress
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Enables the 32-bit paging mode on the CPU.    Enables the 32-bit paging mode on the CPU. CR0, CR3, CR4, and the page tables   must be properly initialized prior to calling this service. This function   assumes the current execution mode is 32-bit protected mode. This function is   only available on IA-32. After the 32-bit paging mode is enabled, control is   transferred to the function specified by EntryPoint using the new stack   specified by NewStack and passing in the parameters specified by Context1 and   Context2. Context1 and Context2 are optional and may be NULL. The function   EntryPoint must never return.    If the current execution mode is not 32-bit protected mode, then ASSERT().   If EntryPoint is NULL, then ASSERT().   If NewStack is NULL, then ASSERT().    There are a number of constraints that must be followed before calling this   function:   1)  Interrupts must be disabled.   2)  The caller must be in 32-bit protected mode with flat descriptors. This       means all descriptors must have a base of 0 and a limit of 4GB.   3)  CR0 and CR4 must be compatible with 32-bit protected mode with flat       descriptors.   4)  CR3 must point to valid page tables that will be used once the transition       is complete, and those page tables must guarantee that the pages for this       function and the stack are identity mapped.    @param  EntryPoint  A pointer to function to call with the new stack after                       paging is enabled.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function as the first parameter after paging is enabled.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function as the second parameter after paging is enabled.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function after paging is enabled.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmEnablePaging32
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Disables the 32-bit paging mode on the CPU.    Disables the 32-bit paging mode on the CPU and returns to 32-bit protected   mode. This function assumes the current execution mode is 32-paged protected   mode. This function is only available on IA-32. After the 32-bit paging mode   is disabled, control is transferred to the function specified by EntryPoint   using the new stack specified by NewStack and passing in the parameters   specified by Context1 and Context2. Context1 and Context2 are optional and   may be NULL. The function EntryPoint must never return.    If the current execution mode is not 32-bit paged mode, then ASSERT().   If EntryPoint is NULL, then ASSERT().   If NewStack is NULL, then ASSERT().    There are a number of constraints that must be followed before calling this   function:   1)  Interrupts must be disabled.   2)  The caller must be in 32-bit paged mode.   3)  CR0, CR3, and CR4 must be compatible with 32-bit paged mode.   4)  CR3 must point to valid page tables that guarantee that the pages for       this function and the stack are identity mapped.    @param  EntryPoint  A pointer to function to call with the new stack after                       paging is disabled.   @param  Context1    A pointer to the context to pass into the EntryPoint                       function as the first parameter after paging is disabled.   @param  Context2    A pointer to the context to pass into the EntryPoint                       function as the second parameter after paging is                       disabled.   @param  NewStack    A pointer to the new stack to use for the EntryPoint                       function after paging is disabled.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmDisablePaging32
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Enables the 64-bit paging mode on the CPU.    Enables the 64-bit paging mode on the CPU. CR0, CR3, CR4, and the page tables   must be properly initialized prior to calling this service. This function   assumes the current execution mode is 32-bit protected mode with flat   descriptors. This function is only available on IA-32. After the 64-bit   paging mode is enabled, control is transferred to the function specified by   EntryPoint using the new stack specified by NewStack and passing in the   parameters specified by Context1 and Context2. Context1 and Context2 are   optional and may be 0. The function EntryPoint must never return.    If the current execution mode is not 32-bit protected mode with flat   descriptors, then ASSERT().   If EntryPoint is 0, then ASSERT().   If NewStack is 0, then ASSERT().    @param  Cs          The 16-bit selector to load in the CS before EntryPoint                       is called. The descriptor in the GDT that this selector                       references must be setup for long mode.   @param  EntryPoint  The 64-bit virtual address of the function to call with                       the new stack after paging is enabled.   @param  Context1    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the first parameter after                       paging is enabled.   @param  Context2    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the second parameter after                       paging is enabled.   @param  NewStack    The 64-bit virtual address of the new stack to use for                       the EntryPoint function after paging is enabled.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmEnablePaging64
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Disables the 64-bit paging mode on the CPU.    Disables the 64-bit paging mode on the CPU and returns to 32-bit protected   mode. This function assumes the current execution mode is 64-paging mode.   This function is only available on x64. After the 64-bit paging mode is   disabled, control is transferred to the function specified by EntryPoint   using the new stack specified by NewStack and passing in the parameters   specified by Context1 and Context2. Context1 and Context2 are optional and   may be 0. The function EntryPoint must never return.    If the current execution mode is not 64-bit paged mode, then ASSERT().   If EntryPoint is 0, then ASSERT().   If NewStack is 0, then ASSERT().    @param  Cs          The 16-bit selector to load in the CS before EntryPoint                       is called. The descriptor in the GDT that this selector                       references must be setup for 32-bit protected mode.   @param  EntryPoint  The 64-bit virtual address of the function to call with                       the new stack after paging is disabled.   @param  Context1    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the first parameter after                       paging is disabled.   @param  Context2    The 64-bit virtual address of the context to pass into                       the EntryPoint function as the second parameter after                       paging is disabled.   @param  NewStack    The 64-bit virtual address of the new stack to use for                       the EntryPoint function after paging is disabled.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmDisablePaging64
parameter_list|(
name|IN
name|UINT16
name|Cs
parameter_list|,
name|IN
name|UINT32
name|EntryPoint
parameter_list|,
name|IN
name|UINT32
name|Context1
parameter_list|,
name|OPTIONAL
name|IN
name|UINT32
name|Context2
parameter_list|,
name|OPTIONAL
name|IN
name|UINT32
name|NewStack
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// 16-bit thunking services
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Retrieves the properties for 16-bit thunk functions.    Computes the size of the buffer and stack below 1MB required to use the   AsmPrepareThunk16(), AsmThunk16() and AsmPrepareAndThunk16() functions. This   buffer size is returned in RealModeBufferSize, and the stack size is returned   in ExtraStackSize. If parameters are passed to the 16-bit real mode code,   then the actual minimum stack size is ExtraStackSize plus the maximum number   of bytes that need to be passed to the 16-bit real mode code.      If RealModeBufferSize is NULL, then ASSERT().   If ExtraStackSize is NULL, then ASSERT().    @param  RealModeBufferSize  A pointer to the size of the buffer below 1MB                               required to use the 16-bit thunk functions.   @param  ExtraStackSize      A pointer to the extra size of stack below 1MB                               that the 16-bit thunk functions require for                               temporary storage in the transition to and from                               16-bit real mode.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmGetThunk16Properties
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|RealModeBufferSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ExtraStackSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prepares all structures a code required to use AsmThunk16().    Prepares all structures and code required to use AsmThunk16().      This interface is limited to be used in either physical mode or virtual modes with paging enabled where the   virtual to physical mappings for ThunkContext.RealModeBuffer is mapped 1:1.    If ThunkContext is NULL, then ASSERT().    @param  ThunkContext  A pointer to the context structure that describes the                         16-bit real mode code to call.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmPrepareThunk16
parameter_list|(
name|IN
name|OUT
name|THUNK_CONTEXT
modifier|*
name|ThunkContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Transfers control to a 16-bit real mode entry point and returns the results.    Transfers control to a 16-bit real mode entry point and returns the results.   AsmPrepareThunk16() must be called with ThunkContext before this function is used.   This function must be called with interrupts disabled.    The register state from the RealModeState field of ThunkContext is restored just prior    to calling the 16-bit real mode entry point.  This includes the EFLAGS field of RealModeState,    which is used to set the interrupt state when a 16-bit real mode entry point is called.   Control is transferred to the 16-bit real mode entry point specified by the CS and Eip fields of RealModeState.   The stack is initialized to the SS and ESP fields of RealModeState.  Any parameters passed to    the 16-bit real mode code must be populated by the caller at SS:ESP prior to calling this function.     The 16-bit real mode entry point is invoked with a 16-bit CALL FAR instruction,   so when accessing stack contents, the 16-bit real mode code must account for the 16-bit segment    and 16-bit offset of the return address that were pushed onto the stack. The 16-bit real mode entry    point must exit with a RETF instruction. The register state is captured into RealModeState immediately    after the RETF instruction is executed.      If EFLAGS specifies interrupts enabled, or any of the 16-bit real mode code enables interrupts,    or any of the 16-bit real mode code makes a SW interrupt, then the caller is responsible for making sure    the IDT at address 0 is initialized to handle any HW or SW interrupts that may occur while in 16-bit real mode.       If EFLAGS specifies interrupts enabled, or any of the 16-bit real mode code enables interrupts,    then the caller is responsible for making sure the 8259 PIC is in a state compatible with 16-bit real mode.     This includes the base vectors, the interrupt masks, and the edge/level trigger mode.      If THUNK_ATTRIBUTE_BIG_REAL_MODE is set in the ThunkAttributes field of ThunkContext, then the user code    is invoked in big real mode.  Otherwise, the user code is invoked in 16-bit real mode with 64KB segment limits.      If neither THUNK_ATTRIBUTE_DISABLE_A20_MASK_INT_15 nor THUNK_ATTRIBUTE_DISABLE_A20_MASK_KBD_CTRL are set in    ThunkAttributes, then it is assumed that the user code did not enable the A20 mask, and no attempt is made to    disable the A20 mask.      If THUNK_ATTRIBUTE_DISABLE_A20_MASK_INT_15 is set and THUNK_ATTRIBUTE_DISABLE_A20_MASK_KBD_CTRL is clear in    ThunkAttributes, then attempt to use the INT 15 service to disable the A20 mask.  If this INT 15 call fails,    then attempt to disable the A20 mask by directly accessing the 8042 keyboard controller I/O ports.      If THUNK_ATTRIBUTE_DISABLE_A20_MASK_INT_15 is clear and THUNK_ATTRIBUTE_DISABLE_A20_MASK_KBD_CTRL is set in    ThunkAttributes, then attempt to disable the A20 mask by directly accessing the 8042 keyboard controller I/O ports.        If ThunkContext is NULL, then ASSERT().   If AsmPrepareThunk16() was not previously called with ThunkContext, then ASSERT().   If both THUNK_ATTRIBUTE_DISABLE_A20_MASK_INT_15 and THUNK_ATTRIBUTE_DISABLE_A20_MASK_KBD_CTRL are set in    ThunkAttributes, then ASSERT().    This interface is limited to be used in either physical mode or virtual modes with paging enabled where the   virtual to physical mappings for ThunkContext.RealModeBuffer are mapped 1:1.    @param  ThunkContext  A pointer to the context structure that describes the                         16-bit real mode code to call.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmThunk16
parameter_list|(
name|IN
name|OUT
name|THUNK_CONTEXT
modifier|*
name|ThunkContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prepares all structures and code for a 16-bit real mode thunk, transfers   control to a 16-bit real mode entry point, and returns the results.    Prepares all structures and code for a 16-bit real mode thunk, transfers   control to a 16-bit real mode entry point, and returns the results. If the   caller only need to perform a single 16-bit real mode thunk, then this   service should be used. If the caller intends to make more than one 16-bit   real mode thunk, then it is more efficient if AsmPrepareThunk16() is called   once and AsmThunk16() can be called for each 16-bit real mode thunk.    This interface is limited to be used in either physical mode or virtual modes with paging enabled where the   virtual to physical mappings for ThunkContext.RealModeBuffer is mapped 1:1.    See AsmPrepareThunk16() and AsmThunk16() for the detailed description and ASSERT() conditions.    @param  ThunkContext  A pointer to the context structure that describes the                         16-bit real mode code to call.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|AsmPrepareAndThunk16
parameter_list|(
name|IN
name|OUT
name|THUNK_CONTEXT
modifier|*
name|ThunkContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 16-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.   **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|AsmRdRand16
parameter_list|(
name|OUT
name|UINT16
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 32-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|AsmRdRand32
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 64-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|AsmRdRand64
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

