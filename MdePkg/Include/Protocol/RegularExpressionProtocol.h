begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This section defines the Regular Expression Protocol. This protocol isused to match   Unicode strings against Regular Expression patterns.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REGULAR_EXPRESSION_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__REGULAR_EXPRESSION_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_REGULAR_EXPRESSION_PROTOCOL_GUID
define|\
value|{ \     0xB3F79D9A, 0x436C, 0xDC11, {0xB0, 0x52, 0xCD, 0x85, 0xDF, 0x52, 0x4C, 0xE6 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_REGEX_SYNTAX_TYPE_POSIX_EXTENDED_GUID
define|\
value|{ \     0x5F05B20F, 0x4A56, 0xC231, {0xFA, 0x0B, 0xA7, 0xB1, 0xF1, 0x10, 0x04, 0x1D } \   }
end_define

begin_define
define|#
directive|define
name|EFI_REGEX_SYNTAX_TYPE_PERL_GUID
define|\
value|{ \     0x63E60A51, 0x497D, 0xD427, {0xC4, 0xA5, 0xB8, 0xAB, 0xDC, 0x3A, 0xAE, 0xB6 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_REGEX_SYNTAX_TYPE_ECMA_262_GUID
define|\
value|{ \     0x9A473A4A, 0x4CEB, 0xB95A, {0x41, 0x5E, 0x5B, 0xA0, 0xBC, 0x63, 0x9B, 0x2E } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_REGULAR_EXPRESSION_PROTOCOL
name|EFI_REGULAR_EXPRESSION_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CONST
name|CHAR16
modifier|*
name|CapturePtr
decl_stmt|;
comment|// Pointer to the start of the captured sub-expression
comment|// within matched String.
name|UINTN
name|Length
decl_stmt|;
comment|// Length of captured sub-expression.
block|}
name|EFI_REGEX_CAPTURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_GUID
name|EFI_REGEX_SYNTAX_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol member functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Returns information about the regular expression syntax types supported   by the implementation.    This                     A pointer to the EFI_REGULAR_EXPRESSION_PROTOCOL                            instance.    RegExSyntaxTypeListSize  On input, the size in bytes of RegExSyntaxTypeList.                            On output with a return code of EFI_SUCCESS, the                            size in bytes of the data returned in                            RegExSyntaxTypeList. On output with a return code                            of EFI_BUFFER_TOO_SMALL, the size of                            RegExSyntaxTypeListrequired to obtain the list.    RegExSyntaxTypeList      A caller-allocated memory buffer filled by the                            driver with one EFI_REGEX_SYNTAX_TYPEelement                            for each supported Regular expression syntax                            type. The list must not change across multiple                            calls to the same driver. The first syntax                            type in the list is the default type for the                            driver.    @retval EFI_SUCCESS            The regular expression syntax types list                                  was returned successfully.   @retval EFI_UNSUPPORTED        The service is not supported by this driver.   @retval EFI_DEVICE_ERROR       The list of syntax types could not be                                  retrieved due to a hardware or firmware error.   @retval EFI_BUFFER_TOO_SMALL   The buffer RegExSyntaxTypeList is too small                                  to hold the result.   @retval EFI_INVALID_PARAMETER  RegExSyntaxTypeListSize is NULL  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REGULAR_EXPRESSION_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_REGULAR_EXPRESSION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|RegExSyntaxTypeListSize
parameter_list|,
name|OUT
name|EFI_REGEX_SYNTAX_TYPE
modifier|*
name|RegExSyntaxTypeList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Checks if the input string matches to the regular expression pattern.    This          A pointer to the EFI_REGULAR_EXPRESSION_PROTOCOL instance.                 Type EFI_REGULAR_EXPRESSION_PROTOCOL is defined in Section                 XYZ.    String        A pointer to a NULL terminated string to match against the                 regular expression string specified by Pattern.    Pattern       A pointer to a NULL terminated string that represents the                 regular expression.    SyntaxType    A pointer to the EFI_REGEX_SYNTAX_TYPE that identifies the                 regular expression syntax type to use. May be NULL in which                 case the function will use its default regular expression                 syntax type.    Result        On return, points to TRUE if String fully matches against                 the regular expression Pattern using the regular expression                 SyntaxType. Otherwise, points to FALSE.    Captures      A Pointer to an array of EFI_REGEX_CAPTURE objects to receive                 the captured groups in the event of a match. The full                 sub-string match is put in Captures[0], and the results of N                 capturing groups are put in Captures[1:N]. If Captures is                 NULL, then this function doesn't allocate the memory for the                 array and does not build up the elements. It only returns the                 number of matching patterns in CapturesCount. If Captures is                 not NULL, this function returns a pointer to an array and                 builds up the elements in the array. CapturesCount is also                 updated to the number of matching patterns found. It is the                 caller's responsibility to free the memory pool in Captures                 and in each CapturePtr in the array elements.    CapturesCount On output, CapturesCount is the number of matching patterns                 found in String. Zero means no matching patterns were found                 in the string.    @retval EFI_SUCCESS            The regular expression string matching                                  completed successfully.   @retval EFI_UNSUPPORTED        The regular expression syntax specified by                                  SyntaxTypeis not supported by this driver.   @retval EFI_DEVICE_ERROR       The regular expression string matching                                  failed due to a hardware or firmware error.   @retval EFI_INVALID_PARAMETER  String, Pattern, Result, or CapturesCountis                                  NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REGULAR_EXPRESSION_MATCH
function_decl|)
parameter_list|(
name|IN
name|EFI_REGULAR_EXPRESSION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|Pattern
parameter_list|,
name|IN
name|EFI_REGEX_SYNTAX_TYPE
modifier|*
name|SyntaxType
parameter_list|,
name|OPTIONAL
name|OUT
name|BOOLEAN
modifier|*
name|Result
parameter_list|,
name|OUT
name|EFI_REGEX_CAPTURE
modifier|*
modifier|*
name|Captures
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|CapturesCount
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_REGULAR_EXPRESSION_PROTOCOL
block|{
name|EFI_REGULAR_EXPRESSION_MATCH
name|MatchString
decl_stmt|;
name|EFI_REGULAR_EXPRESSION_GET_INFO
name|GetInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRegularExpressionProtocolGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// For regular expression rules specified in the POSIX Extended Regular
end_comment

begin_comment
comment|// Expression (ERE) Syntax:
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRegexSyntaxTypePosixExtendedGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// For regular expression rules specifiedin the ECMA 262 Specification
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRegexSyntaxTypeEcma262Guid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// For regular expression rules specified in the Perl standard:
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRegexSyntaxTypePerlGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

