begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Unicode Collation protocol that follows the UEFI 2.0 specification.   This protocol is used to allow code running in the boot services environment    to perform lexical comparison functions on Unicode strings for given languages.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UNICODE_COLLATION_H__
end_ifndef

begin_define
define|#
directive|define
name|__UNICODE_COLLATION_H__
end_define

begin_define
define|#
directive|define
name|EFI_UNICODE_COLLATION_PROTOCOL_GUID
define|\
value|{ \     0x1d85cd7f, 0xf43d, 0x11d2, {0x9a, 0xc, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_UNICODE_COLLATION_PROTOCOL2_GUID
define|\
value|{ \     0xa4c751fc, 0x23ae, 0x4c3e, {0x92, 0xe9, 0x49, 0x64, 0xcf, 0x63, 0xf3, 0x49 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_UNICODE_COLLATION_PROTOCOL
name|EFI_UNICODE_COLLATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|UNICODE_COLLATION_PROTOCOL
value|EFI_UNICODE_COLLATION_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_UNICODE_COLLATION_PROTOCOL
name|UNICODE_COLLATION_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol data structures and defines
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_UNICODE_BYTE_ORDER_MARK
value|(CHAR16) (0xfeff)
end_define

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
comment|/**   Performs a case-insensitive comparison of two Null-terminated strings.    @param  This A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  Str1 A pointer to a Null-terminated string.   @param  Str2 A pointer to a Null-terminated string.    @retval 0   Str1 is equivalent to Str2.   @retval>0  Str1 is lexically greater than Str2.   @retval<0  Str1 is lexically less than Str2.  **/
end_comment

begin_typedef
typedef|typedef
name|INTN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_STRICOLL
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|Str1
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|Str2
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Performs a case-insensitive comparison of a Null-terminated    pattern string and a Null-terminated string.    @param  This    A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  String  A pointer to a Null-terminated string.   @param  Pattern A pointer to a Null-terminated pattern string.    @retval TRUE    Pattern was found in String.   @retval FALSE   Pattern was not found in String.  **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_METAIMATCH
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts all the characters in a Null-terminated string to    lower case characters.    @param  This   A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  String A pointer to a Null-terminated string.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_STRLWR
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|CHAR16
modifier|*
name|Str
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts all the characters in a Null-terminated string to upper   case characters.    @param  This   A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  String A pointer to a Null-terminated string.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_STRUPR
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|CHAR16
modifier|*
name|Str
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts an 8.3 FAT file name in an OEM character set to a Null-terminated    string.    @param  This    A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  FatSize The size of the string Fat in bytes.   @param  Fat     A pointer to a Null-terminated string that contains an 8.3 file                   name using an 8-bit OEM character set.   @param  String  A pointer to a Null-terminated string. The string must                   be allocated in advance to hold FatSize characters.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_FATTOSTR
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|FatSize
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|Fat
parameter_list|,
name|OUT
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts a Null-terminated string to legal characters in a FAT    filename using an OEM character set.     @param  This    A pointer to the EFI_UNICODE_COLLATION_PROTOCOL instance.   @param  String  A pointer to a Null-terminated string.   @param  FatSize The size of the string Fat in bytes.   @param  Fat     A pointer to a string that contains the converted version of                    String using legal FAT characters from an OEM character set.    @retval TRUE    One or more conversions failed and were substituted with '_'   @retval FALSE   None of the conversions failed.  **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNICODE_COLLATION_STRTOFAT
function_decl|)
parameter_list|(
name|IN
name|EFI_UNICODE_COLLATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|,
name|IN
name|UINTN
name|FatSize
parameter_list|,
name|OUT
name|CHAR8
modifier|*
name|Fat
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_UNICODE_COLLATION_PROTOCOL is used to perform case-insensitive
end_comment

begin_comment
comment|/// comparisons of strings.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_UNICODE_COLLATION_PROTOCOL
block|{
name|EFI_UNICODE_COLLATION_STRICOLL
name|StriColl
decl_stmt|;
name|EFI_UNICODE_COLLATION_METAIMATCH
name|MetaiMatch
decl_stmt|;
name|EFI_UNICODE_COLLATION_STRLWR
name|StrLwr
decl_stmt|;
name|EFI_UNICODE_COLLATION_STRUPR
name|StrUpr
decl_stmt|;
comment|//
comment|// for supporting fat volumes
comment|//
name|EFI_UNICODE_COLLATION_FATTOSTR
name|FatToStr
decl_stmt|;
name|EFI_UNICODE_COLLATION_STRTOFAT
name|StrToFat
decl_stmt|;
comment|///
comment|/// A Null-terminated ASCII string array that contains one or more language codes.
comment|/// When this field is used for UnicodeCollation2, it is specified in RFC 4646 format.
comment|/// When it is used for UnicodeCollation, it is specified in ISO 639-2 format.
comment|///
name|CHAR8
modifier|*
name|SupportedLanguages
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUnicodeCollationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUnicodeCollation2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

