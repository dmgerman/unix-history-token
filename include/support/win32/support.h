begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===----------------------- support/win32/support.h ----------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_SUPPORT_WIN32_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_WIN32_SUPPORT_H
end_define

begin_comment
comment|/*    Functions and constants used in libc++ that are missing from the Windows C library.   */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_comment
comment|// mbstate_t
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// _snwprintf
end_comment

begin_define
define|#
directive|define
name|swprintf
value|_snwprintf
end_define

begin_define
define|#
directive|define
name|vswprintf
value|_vsnwprintf
end_define

begin_define
define|#
directive|define
name|vfscnaf
value|fscanf
end_define

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|sptr
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|sptr
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//int vfscanf( FILE *__restrict stream, const char *__restrict format,
end_comment

begin_comment
comment|//             va_list arg);
end_comment

begin_function_decl
name|size_t
name|mbsnrtowcs
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|nmc
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcsnrtombs
parameter_list|(
name|char
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|wchar_t
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|nwc
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_include
include|#
directive|include
file|<xlocinfo.h>
end_include

begin_define
define|#
directive|define
name|atoll
value|_atoi64
end_define

begin_define
define|#
directive|define
name|strtoll
value|_strtoi64
end_define

begin_define
define|#
directive|define
name|strtoull
value|_strtoui64
end_define

begin_define
define|#
directive|define
name|wcstoll
value|_wcstoi64
end_define

begin_define
define|#
directive|define
name|wcstoull
value|_wcstoui64
end_define

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|float
name|strtof
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
block|{
return|return
name|_Stof
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|double
name|strtod
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
block|{
return|return
name|_Stod
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|long
name|double
name|strtold
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
block|{
return|return
name|_Stold
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_Exit
value|_exit
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__clang__
end_ifndef

begin_comment
comment|// MSVC-based Clang also defines _MSC_VER
end_comment

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_define
define|#
directive|define
name|__builtin_popcount
value|__popcnt
end_define

begin_define
define|#
directive|define
name|__builtin_popcountl
value|__popcnt
end_define

begin_define
define|#
directive|define
name|__builtin_popcountll
parameter_list|(
name|__i
parameter_list|)
value|static_cast<int>(__popcnt64(__i))
end_define

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctz
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|DWORD
name|r
init|=
literal|0
decl_stmt|;
name|_BitScanReverse
argument_list|(
operator|&
name|r
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_comment
comment|// sizeof(long) == sizeof(int) on Windows
end_comment

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctzl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
name|__builtin_ctz
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|x
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctzll
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
name|DWORD
name|r
init|=
literal|0
decl_stmt|;
name|_BitScanReverse64
argument_list|(
operator|&
name|r
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_clz
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|DWORD
name|r
init|=
literal|0
decl_stmt|;
name|_BitScanForward
argument_list|(
operator|&
name|r
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_comment
comment|// sizeof(long) == sizeof(int) on Windows
end_comment

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_clzl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
name|__builtin_clz
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|x
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_clzll
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
name|DWORD
name|r
init|=
literal|0
decl_stmt|;
name|_BitScanForward64
argument_list|(
operator|&
name|r
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !__clang__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_WIN32_SUPPORT_H
end_comment

end_unit

