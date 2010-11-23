begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_mstr.h
end_comment

begin_comment
comment|/// \brief      Utility functions for handling multibyte strings
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If not enough multibyte string support is available in the C library,
end_comment

begin_comment
comment|/// these functions keep working with the assumption that all strings
end_comment

begin_comment
comment|/// are in a single-byte character set without combining characters, e.g.
end_comment

begin_comment
comment|/// US-ASCII or ISO-8859-*.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_MBSTR_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_MBSTR_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_function_decl
name|TUKLIB_DECLS_BEGIN
define|#
directive|define
name|tuklib_mbstr_width
value|TUKLIB_SYMBOL(tuklib_mbstr_width)
specifier|extern
name|size_t
name|tuklib_mbstr_width
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///<
end_comment

begin_comment
comment|/// \brief      Get the number of columns needed for the multibyte string
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is somewhat similar to wcswidth() but works on multibyte strings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      str         String whose width is to be calculated. If the
end_comment

begin_comment
comment|///                         current locale uses a multibyte character set
end_comment

begin_comment
comment|///                         that has shift states, the string must begin
end_comment

begin_comment
comment|///                         and end in the initial shift state.
end_comment

begin_comment
comment|/// \param      bytes       If this is not NULL, *bytes is set to the
end_comment

begin_comment
comment|///                         value returned by strlen(str) (even if an
end_comment

begin_comment
comment|///                         error occurs when calculating the width).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     On success, the number of columns needed to display the
end_comment

begin_comment
comment|///             string e.g. in a terminal emulator is returned. On error,
end_comment

begin_comment
comment|///             (size_t)-1 is returned. Possible errors include invalid,
end_comment

begin_comment
comment|///             partial, or non-printable multibyte character in str, or
end_comment

begin_comment
comment|///             that str doesn't end in the initial shift state.
end_comment

begin_define
define|#
directive|define
name|tuklib_mbstr_fw
value|TUKLIB_SYMBOL(tuklib_mbstr_fw)
end_define

begin_function_decl
specifier|extern
name|int
name|tuklib_mbstr_fw
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|columns_min
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///<
end_comment

begin_comment
comment|/// \brief      Get the field width for printf() e.g. to align table columns
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Printing simple tables to a terminal can be done using the field field
end_comment

begin_comment
comment|/// feature in the printf() format string, but it works only with single-byte
end_comment

begin_comment
comment|/// character sets. To do the same with multibyte strings, tuklib_mbstr_fw()
end_comment

begin_comment
comment|/// can be used to calculate appropriate field width.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The behavior of this function is undefined, if
end_comment

begin_comment
comment|///   - str is NULL or not terminated with '\0';
end_comment

begin_comment
comment|///   - columns_min<= 0; or
end_comment

begin_comment
comment|///   - the calculated field width exceeds INT_MAX.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     If tuklib_mbstr_width(str, NULL) fails, -1 is returned.
end_comment

begin_comment
comment|///             If str needs more columns than columns_min, zero is returned.
end_comment

begin_comment
comment|///             Otherwise a positive integer is returned, which can be
end_comment

begin_comment
comment|///             used as the field width, e.g. printf("%*s", fw, str).
end_comment

begin_macro
name|TUKLIB_DECLS_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

