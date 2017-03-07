begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Print Library instance Internal Functions definition.    Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PRINT_LIB_INTERNAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__PRINT_LIB_INTERNAL_H__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/PrintLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PcdLib.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Print primitives
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PREFIX_SIGN
value|BIT1
end_define

begin_define
define|#
directive|define
name|PREFIX_BLANK
value|BIT2
end_define

begin_define
define|#
directive|define
name|LONG_TYPE
value|BIT4
end_define

begin_define
define|#
directive|define
name|OUTPUT_UNICODE
value|BIT6
end_define

begin_define
define|#
directive|define
name|FORMAT_UNICODE
value|BIT8
end_define

begin_define
define|#
directive|define
name|PAD_TO_WIDTH
value|BIT9
end_define

begin_define
define|#
directive|define
name|ARGUMENT_UNICODE
value|BIT10
end_define

begin_define
define|#
directive|define
name|PRECISION
value|BIT11
end_define

begin_define
define|#
directive|define
name|ARGUMENT_REVERSED
value|BIT12
end_define

begin_define
define|#
directive|define
name|COUNT_ONLY_NO_PRINT
value|BIT13
end_define

begin_define
define|#
directive|define
name|UNSIGNED_TYPE
value|BIT14
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Record date and time information
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Year
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
name|UINT8
name|Hour
decl_stmt|;
name|UINT8
name|Minute
decl_stmt|;
name|UINT8
name|Second
decl_stmt|;
name|UINT8
name|Pad1
decl_stmt|;
name|UINT32
name|Nanosecond
decl_stmt|;
name|INT16
name|TimeZone
decl_stmt|;
name|UINT8
name|Daylight
decl_stmt|;
name|UINT8
name|Pad2
decl_stmt|;
block|}
name|TIME
typedef|;
end_typedef

begin_comment
comment|/**   Worker function that produces a Null-terminated string in an output buffer    based on a Null-terminated format string and a VA_LIST argument list.    VSPrint function to process format and place the results in Buffer. Since a    VA_LIST is used this routine allows the nesting of Vararg routines. Thus    this is the main print working routine.    If COUNT_ONLY_NO_PRINT is set in Flags, Buffer will not be modified at all.    @param[out] Buffer          The character buffer to print the results of the                                parsing of Format into.   @param[in]  BufferSize      The maximum number of characters to put into                                buffer.   @param[in]  Flags           Initial flags value.                               Can only have FORMAT_UNICODE, OUTPUT_UNICODE,                                and COUNT_ONLY_NO_PRINT set.   @param[in]  Format          A Null-terminated format string.   @param[in]  VaListMarker    VA_LIST style variable argument list consumed by                               processing Format.   @param[in]  BaseListMarker  BASE_LIST style variable argument list consumed                               by processing Format.    @return The number of characters printed not including the Null-terminator.           If COUNT_ONLY_NO_PRINT was set returns the same, but without any           modification to Buffer.  **/
end_comment

begin_function_decl
name|UINTN
name|BasePrintLibSPrintMarker
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|UINTN
name|Flags
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Format
parameter_list|,
name|IN
name|VA_LIST
name|VaListMarker
parameter_list|,
name|OPTIONAL
name|IN
name|BASE_LIST
name|BaseListMarker
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Worker function that produces a Null-terminated string in an output buffer    based on a Null-terminated format string and variable argument list.    VSPrint function to process format and place the results in Buffer. Since a    VA_LIST is used this routine allows the nesting of Vararg routines. Thus    this is the main print working routine    @param  StartOfBuffer The character buffer to print the results of the parsing                         of Format into.   @param  BufferSize    The maximum number of characters to put into buffer.                         Zero means no limit.   @param  Flags         Initial flags value.                         Can only have FORMAT_UNICODE and OUTPUT_UNICODE set   @param  FormatString  Null-terminated format string.   @param  ...           The variable argument list.    @return The number of characters printed.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|BasePrintLibSPrint
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|StartOfBuffer
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|UINTN
name|Flags
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|FormatString
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Internal function that places the character into the Buffer.    Internal function that places ASCII or Unicode character into the Buffer.    @param  Buffer      Buffer to place the Unicode or ASCII string.   @param  EndBuffer   The end of the input Buffer. No characters will be                       placed after that.    @param  Length      The count of character to be placed into Buffer.                       (Negative value indicates no buffer fill.)   @param  Character   The character to be placed into Buffer.   @param  Increment   The character increment in Buffer.    @return Buffer      Buffer filled with the input Character.  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|BasePrintLibFillBuffer
parameter_list|(
name|OUT
name|CHAR8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|EndBuffer
parameter_list|,
name|IN
name|INTN
name|Length
parameter_list|,
name|IN
name|UINTN
name|Character
parameter_list|,
name|IN
name|INTN
name|Increment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Internal function that convert a number to a string in Buffer.    Print worker function that converts a decimal or hexadecimal number to an ASCII string in Buffer.    @param  Buffer    Location to place the ASCII string of Value.   @param  Value     The value to convert to a Decimal or Hexadecimal string in Buffer.   @param  Radix     Radix of the value    @return A pointer to the end of buffer filled with ASCII string.  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|BasePrintLibValueToString
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|INT64
name|Value
parameter_list|,
name|IN
name|UINTN
name|Radix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Internal function that converts a decimal value to a Null-terminated string.      Converts the decimal number specified by Value to a Null-terminated     string specified by Buffer containing at most Width characters.   If Width is 0 then a width of  MAXIMUM_VALUE_CHARACTERS is assumed.   The total number of characters placed in Buffer is returned.   If the conversion contains more than Width characters, then only the first   Width characters are returned, and the total number of characters    required to perform the conversion is returned.   Additional conversion parameters are specified in Flags.     The Flags bit LEFT_JUSTIFY is always ignored.   All conversions are left justified in Buffer.   If Width is 0, PREFIX_ZERO is ignored in Flags.   If COMMA_TYPE is set in Flags, then PREFIX_ZERO is ignored in Flags, and commas   are inserted every 3rd digit starting from the right.   If Value is< 0, then the fist character in Buffer is a '-'.   If PREFIX_ZERO is set in Flags and PREFIX_ZERO is not being ignored,    then Buffer is padded with '0' characters so the combination of the optional '-'    sign character, '0' characters, digit characters for Value, and the Null-terminator   add up to Width characters.    If Buffer is NULL, then ASSERT().   If unsupported bits are set in Flags, then ASSERT().   If Width>= MAXIMUM_VALUE_CHARACTERS, then ASSERT()    @param  Buffer    The pointer to the output buffer for the produced Null-terminated                     string.   @param  Flags     The bitmask of flags that specify left justification, zero pad,                     and commas.   @param  Value     The 64-bit signed value to convert to a string.   @param  Width     The maximum number of characters to place in Buffer, not including                     the Null-terminator.   @param  Increment Character increment in Buffer.      @return Total number of characters required to perform the conversion.  **/
end_comment

begin_function_decl
name|UINTN
name|BasePrintLibConvertValueToString
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Flags
parameter_list|,
name|IN
name|INT64
name|Value
parameter_list|,
name|IN
name|UINTN
name|Width
parameter_list|,
name|IN
name|UINTN
name|Increment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Internal function that converts a decimal value to a Null-terminated string.    Converts the decimal number specified by Value to a Null-terminated string   specified by Buffer containing at most Width characters. If Width is 0 then a   width of MAXIMUM_VALUE_CHARACTERS is assumed. If the conversion contains more   than Width characters, then only the first Width characters are placed in   Buffer. Additional conversion parameters are specified in Flags.   The Flags bit LEFT_JUSTIFY is always ignored.   All conversions are left justified in Buffer.   If Width is 0, PREFIX_ZERO is ignored in Flags.   If COMMA_TYPE is set in Flags, then PREFIX_ZERO is ignored in Flags, and   commas are inserted every 3rd digit starting from the right.   If Value is< 0, then the fist character in Buffer is a '-'.   If PREFIX_ZERO is set in Flags and PREFIX_ZERO is not being ignored,   then Buffer is padded with '0' characters so the combination of the optional   '-' sign character, '0' characters, digit characters for Value, and the   Null-terminator add up to Width characters.    If an error would be returned, the function will ASSERT().    @param  Buffer      The pointer to the output buffer for the produced                       Null-terminated string.   @param  BufferSize  The size of Buffer in bytes, including the                       Null-terminator.   @param  Flags       The bitmask of flags that specify left justification,                       zero pad, and commas.   @param  Value       The 64-bit signed value to convert to a string.   @param  Width       The maximum number of characters to place in Buffer,                       not including the Null-terminator.   @param  Increment   The character increment in Buffer.    @retval RETURN_SUCCESS           The decimal value is converted.   @retval RETURN_BUFFER_TOO_SMALL  If BufferSize cannot hold the converted                                    value.   @retval RETURN_INVALID_PARAMETER If Buffer is NULL.                                    If Increment is 1 and                                    PcdMaximumAsciiStringLength is not zero,                                    BufferSize is greater than                                    PcdMaximumAsciiStringLength.                                    If Increment is not 1 and                                    PcdMaximumUnicodeStringLength is not zero,                                    BufferSize is greater than                                    (PcdMaximumUnicodeStringLength *                                    sizeof (CHAR16) + 1).                                    If unsupported bits are set in Flags.                                    If both COMMA_TYPE and RADIX_HEX are set in                                    Flags.                                    If Width>= MAXIMUM_VALUE_CHARACTERS.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|BasePrintLibConvertValueToStringS
parameter_list|(
name|IN
name|OUT
name|CHAR8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|UINTN
name|Flags
parameter_list|,
name|IN
name|INT64
name|Value
parameter_list|,
name|IN
name|UINTN
name|Width
parameter_list|,
name|IN
name|UINTN
name|Increment
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

