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
comment|// Functions and constants used in libc++ that
end_comment

begin_comment
comment|// are missing from the Windows C library.
end_comment

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
file|<cstdarg>
end_include

begin_comment
comment|// va_ macros
end_comment

begin_comment
comment|// "builtins" not implemented here for Clang or GCC as they provide
end_comment

begin_comment
comment|// implementations. Assuming required for elsewhere else, certainly MSVC.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_COMPILER_MSVC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|NOMINMAX
end_ifndef

begin_define
define|#
directive|define
name|NOMINMAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The mingw headers already define these as static.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MINGW32__
end_ifndef

begin_extern
extern|extern
literal|"C"
block|{
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
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __MINGW32__
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_COMPILER_MSVC
argument_list|)
end_if

begin_comment
comment|// Bit builtin's make these assumptions when calling _BitScanForward/Reverse
end_comment

begin_comment
comment|// etc. These assumptions are expected to be true for Win32/Win64 which this
end_comment

begin_comment
comment|// file supports.
end_comment

begin_expr_stmt
name|static_assert
argument_list|(
expr|sizeof
operator|(
name|unsigned
name|long
name|long
operator|)
operator|==
literal|8
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
expr|sizeof
operator|(
name|unsigned
name|int
operator|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_popcount
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
comment|// Binary: 0101...
specifier|static
specifier|const
name|unsigned
name|int
name|m1
init|=
literal|0x55555555
decl_stmt|;
comment|// Binary: 00110011..
specifier|static
specifier|const
name|unsigned
name|int
name|m2
init|=
literal|0x33333333
decl_stmt|;
comment|// Binary:  4 zeros,  4 ones ...
specifier|static
specifier|const
name|unsigned
name|int
name|m4
init|=
literal|0x0f0f0f0f
decl_stmt|;
comment|// The sum of 256 to the power of 0,1,2,3...
specifier|static
specifier|const
name|unsigned
name|int
name|h01
init|=
literal|0x01010101
decl_stmt|;
comment|// Put count of each 2 bits into those 2 bits.
name|x
operator|-=
operator|(
name|x
operator|>>
literal|1
operator|)
operator|&
name|m1
expr_stmt|;
comment|// Put count of each 4 bits into those 4 bits.
name|x
operator|=
operator|(
name|x
operator|&
name|m2
operator|)
operator|+
operator|(
operator|(
name|x
operator|>>
literal|2
operator|)
operator|&
name|m2
operator|)
expr_stmt|;
comment|// Put count of each 8 bits into those 8 bits.
name|x
operator|=
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|4
operator|)
operator|)
operator|&
name|m4
expr_stmt|;
comment|// Returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24).
return|return
operator|(
name|x
operator|*
name|h01
operator|)
operator|>>
literal|24
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_popcountl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
name|__builtin_popcount
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
name|__builtin_popcountll
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
comment|// Binary: 0101...
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|m1
init|=
literal|0x5555555555555555
decl_stmt|;
comment|// Binary: 00110011..
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|m2
init|=
literal|0x3333333333333333
decl_stmt|;
comment|// Binary:  4 zeros,  4 ones ...
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|m4
init|=
literal|0x0f0f0f0f0f0f0f0f
decl_stmt|;
comment|// The sum of 256 to the power of 0,1,2,3...
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|h01
init|=
literal|0x0101010101010101
decl_stmt|;
comment|// Put count of each 2 bits into those 2 bits.
name|x
operator|-=
operator|(
name|x
operator|>>
literal|1
operator|)
operator|&
name|m1
expr_stmt|;
comment|// Put count of each 4 bits into those 4 bits.
name|x
operator|=
operator|(
name|x
operator|&
name|m2
operator|)
operator|+
operator|(
operator|(
name|x
operator|>>
literal|2
operator|)
operator|&
name|m2
operator|)
expr_stmt|;
comment|// Put count of each 8 bits into those 8 bits.
name|x
operator|=
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|4
operator|)
operator|)
operator|&
name|m4
expr_stmt|;
comment|// Returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
operator|(
name|x
operator|*
name|h01
operator|)
operator|>>
literal|56
operator|)
return|;
block|}
end_function

begin_comment
comment|// Returns the number of trailing 0-bits in x, starting at the least significant
end_comment

begin_comment
comment|// bit position. If x is 0, the result is undefined.
end_comment

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctzll
parameter_list|(
name|unsigned
name|long
name|long
name|mask
parameter_list|)
block|{
name|unsigned
name|long
name|where
decl_stmt|;
comment|// Search from LSB to MSB for first set bit.
comment|// Returns zero if no set bit is found.
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_HAS_BITSCAN64
argument_list|)
operator|(
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
if|if
condition|(
name|_BitScanForward64
argument_list|(
operator|&
name|where
argument_list|,
name|mask
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|where
operator|)
return|;
else|#
directive|else
comment|// Win32 doesn't have _BitScanForward64 so emulate it with two 32 bit calls.
comment|// Scan the Low Word.
if|if
condition|(
name|_BitScanForward
argument_list|(
argument|&where
argument_list|,
argument|static_cast<unsigned long>(mask)
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|where
operator|)
return|;
comment|// Scan the High Word.
if|if
condition|(
name|_BitScanForward
argument_list|(
argument|&where
argument_list|,
argument|static_cast<unsigned long>(mask>>
literal|32
argument|)
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|where
operator|+
literal|32
operator|)
return|;
comment|// Create a bit offset from the LSB.
endif|#
directive|endif
return|return
literal|64
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctzl
parameter_list|(
name|unsigned
name|long
name|mask
parameter_list|)
block|{
name|unsigned
name|long
name|where
decl_stmt|;
comment|// Search from LSB to MSB for first set bit.
comment|// Returns zero if no set bit is found.
if|if
condition|(
name|_BitScanForward
argument_list|(
operator|&
name|where
argument_list|,
name|mask
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|where
operator|)
return|;
return|return
literal|32
return|;
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_ctz
parameter_list|(
name|unsigned
name|int
name|mask
parameter_list|)
block|{
comment|// Win32 and Win64 expectations.
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|mask
argument_list|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|static_assert
argument_list|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
expr_stmt|;
return|return
name|__builtin_ctzl
argument_list|(
argument|static_cast<unsigned long>(mask)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Returns the number of leading 0-bits in x, starting at the most significant
end_comment

begin_comment
comment|// bit position. If x is 0, the result is undefined.
end_comment

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_clzll
parameter_list|(
name|unsigned
name|long
name|long
name|mask
parameter_list|)
block|{
name|unsigned
name|long
name|where
decl_stmt|;
comment|// BitScanReverse scans from MSB to LSB for first set bit.
comment|// Returns 0 if no set bit is found.
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_HAS_BITSCAN64
argument_list|)
if|if
condition|(
name|_BitScanReverse64
argument_list|(
operator|&
name|where
argument_list|,
name|mask
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|63
operator|-
name|where
operator|)
return|;
else|#
directive|else
comment|// Scan the high 32 bits.
if|if
condition|(
name|_BitScanReverse
argument_list|(
argument|&where
argument_list|,
argument|static_cast<unsigned long>(mask>>
literal|32
argument|)
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|63
operator|-
operator|(
name|where
operator|+
literal|32
operator|)
operator|)
return|;
comment|// Create a bit offset from the MSB.
comment|// Scan the low 32 bits.
if|if
condition|(
name|_BitScanReverse
argument_list|(
argument|&where
argument_list|,
argument|static_cast<unsigned long>(mask)
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|63
operator|-
name|where
operator|)
return|;
endif|#
directive|endif
return|return
literal|64
return|;
comment|// Undefined Behavior.
block|}
end_function

begin_function
name|_LIBCPP_ALWAYS_INLINE
name|int
name|__builtin_clzl
parameter_list|(
name|unsigned
name|long
name|mask
parameter_list|)
block|{
name|unsigned
name|long
name|where
decl_stmt|;
comment|// Search from LSB to MSB for first set bit.
comment|// Returns zero if no set bit is found.
if|if
condition|(
name|_BitScanReverse
argument_list|(
operator|&
name|where
argument_list|,
name|mask
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|31
operator|-
name|where
operator|)
return|;
return|return
literal|32
return|;
comment|// Undefined Behavior.
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
return|return
name|__builtin_clzl
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_MSVC
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_WIN32_SUPPORT_H
end_comment

end_unit

