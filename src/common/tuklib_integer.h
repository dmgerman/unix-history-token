begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_integer.h
end_comment

begin_comment
comment|/// \brief      Various integer and bit operations
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file provides macros or functions to do some basic integer and bit
end_comment

begin_comment
comment|/// operations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Endianness related integer operations (XX = 16, 32, or 64; Y = b or l):
end_comment

begin_comment
comment|///   - Byte swapping: bswapXX(num)
end_comment

begin_comment
comment|///   - Byte order conversions to/from native: convXXYe(num)
end_comment

begin_comment
comment|///   - Aligned reads: readXXYe(ptr)
end_comment

begin_comment
comment|///   - Aligned writes: writeXXYe(ptr, num)
end_comment

begin_comment
comment|///   - Unaligned reads (16/32-bit only): unaligned_readXXYe(ptr)
end_comment

begin_comment
comment|///   - Unaligned writes (16/32-bit only): unaligned_writeXXYe(ptr, num)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Since they can macros, the arguments should have no side effects since
end_comment

begin_comment
comment|/// they may be evaluated more than once.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \todo       PowerPC and possibly some other architectures support
end_comment

begin_comment
comment|///             byte swapping load and store instructions. This file
end_comment

begin_comment
comment|///             doesn't take advantage of those instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Bit scan operations for non-zero 32-bit integers:
end_comment

begin_comment
comment|///   - Bit scan reverse (find highest non-zero bit): bsr32(num)
end_comment

begin_comment
comment|///   - Count leading zeros: clz32(num)
end_comment

begin_comment
comment|///   - Count trailing zeros: ctz32(num)
end_comment

begin_comment
comment|///   - Bit scan forward (simply an alias for ctz32()): bsf32(num)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The above bit scan operations return 0-31. If num is zero,
end_comment

begin_comment
comment|/// the result is undefined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Authors:    Lasse Collin
end_comment

begin_comment
comment|//              Joachim Henke
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
name|TUKLIB_INTEGER_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_INTEGER_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// Operating system specific features //
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BYTESWAP_H
argument_list|)
end_if

begin_comment
comment|// glibc, uClibc, dietlibc
end_comment

begin_include
include|#
directive|include
file|<byteswap.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSWAP_16
end_ifdef

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|num
parameter_list|)
value|bswap_16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSWAP_32
end_ifdef

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|num
parameter_list|)
value|bswap_32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSWAP_64
end_ifdef

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|num
parameter_list|)
value|bswap_64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_ENDIAN_H
argument_list|)
end_elif

begin_comment
comment|// *BSDs and Darwin
end_comment

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_BYTEORDER_H
argument_list|)
end_elif

begin_comment
comment|// Solaris
end_comment

begin_include
include|#
directive|include
file|<sys/byteorder.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSWAP_16
end_ifdef

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|num
parameter_list|)
value|BSWAP_16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSWAP_32
end_ifdef

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|num
parameter_list|)
value|BSWAP_32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSWAP_64
end_ifdef

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|num
parameter_list|)
value|BSWAP_64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BE_16
end_ifdef

begin_define
define|#
directive|define
name|conv16be
parameter_list|(
name|num
parameter_list|)
value|BE_16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BE_32
end_ifdef

begin_define
define|#
directive|define
name|conv32be
parameter_list|(
name|num
parameter_list|)
value|BE_32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BE_64
end_ifdef

begin_define
define|#
directive|define
name|conv64be
parameter_list|(
name|num
parameter_list|)
value|BE_64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LE_16
end_ifdef

begin_define
define|#
directive|define
name|conv16le
parameter_list|(
name|num
parameter_list|)
value|LE_16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LE_32
end_ifdef

begin_define
define|#
directive|define
name|conv32le
parameter_list|(
name|num
parameter_list|)
value|LE_32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LE_64
end_ifdef

begin_define
define|#
directive|define
name|conv64le
parameter_list|(
name|num
parameter_list|)
value|LE_64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///////////////////
end_comment

begin_comment
comment|// Byte swapping //
end_comment

begin_comment
comment|///////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bswap16
end_ifndef

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|num
parameter_list|)
define|\
value|(((uint16_t)(num)<< 8) | ((uint16_t)(num)>> 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bswap32
end_ifndef

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|num
parameter_list|)
define|\
value|( (((uint32_t)(num)<< 24)                       ) \ 		| (((uint32_t)(num)<<  8)& UINT32_C(0x00FF0000)) \ 		| (((uint32_t)(num)>>  8)& UINT32_C(0x0000FF00)) \ 		| (((uint32_t)(num)>> 24)                       ) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bswap64
end_ifndef

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|num
parameter_list|)
define|\
value|( (((uint64_t)(num)<< 56)                               ) \ 		| (((uint64_t)(num)<< 40)& UINT64_C(0x00FF000000000000)) \ 		| (((uint64_t)(num)<< 24)& UINT64_C(0x0000FF0000000000)) \ 		| (((uint64_t)(num)<<  8)& UINT64_C(0x000000FF00000000)) \ 		| (((uint64_t)(num)>>  8)& UINT64_C(0x00000000FF000000)) \ 		| (((uint64_t)(num)>> 24)& UINT64_C(0x0000000000FF0000)) \ 		| (((uint64_t)(num)>> 40)& UINT64_C(0x000000000000FF00)) \ 		| (((uint64_t)(num)>> 56)                               ) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Define conversion macros using the basic byte swapping macros.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|conv16be
end_ifndef

begin_define
define|#
directive|define
name|conv16be
parameter_list|(
name|num
parameter_list|)
value|((uint16_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv32be
end_ifndef

begin_define
define|#
directive|define
name|conv32be
parameter_list|(
name|num
parameter_list|)
value|((uint32_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv64be
end_ifndef

begin_define
define|#
directive|define
name|conv64be
parameter_list|(
name|num
parameter_list|)
value|((uint64_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv16le
end_ifndef

begin_define
define|#
directive|define
name|conv16le
parameter_list|(
name|num
parameter_list|)
value|bswap16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv32le
end_ifndef

begin_define
define|#
directive|define
name|conv32le
parameter_list|(
name|num
parameter_list|)
value|bswap32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv64le
end_ifndef

begin_define
define|#
directive|define
name|conv64le
parameter_list|(
name|num
parameter_list|)
value|bswap64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|conv16be
end_ifndef

begin_define
define|#
directive|define
name|conv16be
parameter_list|(
name|num
parameter_list|)
value|bswap16(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv32be
end_ifndef

begin_define
define|#
directive|define
name|conv32be
parameter_list|(
name|num
parameter_list|)
value|bswap32(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv64be
end_ifndef

begin_define
define|#
directive|define
name|conv64be
parameter_list|(
name|num
parameter_list|)
value|bswap64(num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv16le
end_ifndef

begin_define
define|#
directive|define
name|conv16le
parameter_list|(
name|num
parameter_list|)
value|((uint16_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv32le
end_ifndef

begin_define
define|#
directive|define
name|conv32le
parameter_list|(
name|num
parameter_list|)
value|((uint32_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|conv64le
end_ifndef

begin_define
define|#
directive|define
name|conv64le
parameter_list|(
name|num
parameter_list|)
value|((uint64_t)(num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//////////////////////////////
end_comment

begin_comment
comment|// Aligned reads and writes //
end_comment

begin_comment
comment|//////////////////////////////
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|read16be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint16_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint16_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv16be
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|read16le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint16_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint16_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv16le
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|read32be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint32_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv32be
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|read32le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint32_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv32le
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|read64be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint64_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint64_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv64be
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|read64le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint64_t
name|num
init|=
operator|*
operator|(
specifier|const
name|uint64_t
operator|*
operator|)
name|buf
decl_stmt|;
return|return
name|conv64le
argument_list|(
name|num
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// NOTE: Possible byte swapping must be done in a macro to allow GCC
end_comment

begin_comment
comment|// to optimize byte swapping of constants when using glibc's or *BSD's
end_comment

begin_comment
comment|// byte swapping macros. The actual write is done in an inline function
end_comment

begin_comment
comment|// to make type checking of the buf pointer possible similarly to readXXYe()
end_comment

begin_comment
comment|// functions.
end_comment

begin_define
define|#
directive|define
name|write16be
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write16ne((buf), conv16be(num))
end_define

begin_define
define|#
directive|define
name|write16le
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write16ne((buf), conv16le(num))
end_define

begin_define
define|#
directive|define
name|write32be
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write32ne((buf), conv32be(num))
end_define

begin_define
define|#
directive|define
name|write32le
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write32ne((buf), conv32le(num))
end_define

begin_define
define|#
directive|define
name|write64be
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write64ne((buf), conv64be(num))
end_define

begin_define
define|#
directive|define
name|write64le
parameter_list|(
name|buf
parameter_list|,
name|num
parameter_list|)
value|write64ne((buf), conv64le(num))
end_define

begin_function
specifier|static
specifier|inline
name|void
name|write16ne
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint16_t
name|num
parameter_list|)
block|{
operator|*
operator|(
name|uint16_t
operator|*
operator|)
name|buf
operator|=
name|num
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|write32ne
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|num
parameter_list|)
block|{
operator|*
operator|(
name|uint32_t
operator|*
operator|)
name|buf
operator|=
name|num
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|write64ne
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint64_t
name|num
parameter_list|)
block|{
operator|*
operator|(
name|uint64_t
operator|*
operator|)
name|buf
operator|=
name|num
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|////////////////////////////////
end_comment

begin_comment
comment|// Unaligned reads and writes //
end_comment

begin_comment
comment|////////////////////////////////
end_comment

begin_comment
comment|// NOTE: TUKLIB_FAST_UNALIGNED_ACCESS indicates only support for 16-bit and
end_comment

begin_comment
comment|// 32-bit unaligned integer loads and stores. It's possible that 64-bit
end_comment

begin_comment
comment|// unaligned access doesn't work or is slower than byte-by-byte access.
end_comment

begin_comment
comment|// Since unaligned 64-bit is probably not needed as often as 16-bit or
end_comment

begin_comment
comment|// 32-bit, we simply don't support 64-bit unaligned access for now.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TUKLIB_FAST_UNALIGNED_ACCESS
end_ifdef

begin_define
define|#
directive|define
name|unaligned_read16be
value|read16be
end_define

begin_define
define|#
directive|define
name|unaligned_read16le
value|read16le
end_define

begin_define
define|#
directive|define
name|unaligned_read32be
value|read32be
end_define

begin_define
define|#
directive|define
name|unaligned_read32le
value|read32le
end_define

begin_define
define|#
directive|define
name|unaligned_write16be
value|write16be
end_define

begin_define
define|#
directive|define
name|unaligned_write16le
value|write16le
end_define

begin_define
define|#
directive|define
name|unaligned_write32be
value|write32be
end_define

begin_define
define|#
directive|define
name|unaligned_write32le
value|write32le
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|uint16_t
name|unaligned_read16be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint16_t
name|num
init|=
operator|(
operator|(
name|uint16_t
operator|)
name|buf
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
name|uint16_t
operator|)
name|buf
index|[
literal|1
index|]
decl_stmt|;
return|return
name|num
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|unaligned_read16le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint16_t
name|num
init|=
operator|(
operator|(
name|uint16_t
operator|)
name|buf
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
name|uint16_t
operator|)
name|buf
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
decl_stmt|;
return|return
name|num
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|unaligned_read32be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint32_t
name|num
init|=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|0
index|]
operator|<<
literal|24
decl_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|1
index|]
operator|<<
literal|16
expr_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|2
index|]
operator|<<
literal|8
expr_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|3
index|]
expr_stmt|;
return|return
name|num
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|unaligned_read32le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint32_t
name|num
init|=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|0
index|]
decl_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|1
index|]
operator|<<
literal|8
expr_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|2
index|]
operator|<<
literal|16
expr_stmt|;
name|num
operator||=
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|3
index|]
operator|<<
literal|24
expr_stmt|;
return|return
name|num
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|unaligned_write16be
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint16_t
name|num
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
name|num
operator|>>
literal|8
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|num
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|unaligned_write16le
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint16_t
name|num
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
name|num
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|num
operator|>>
literal|8
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|unaligned_write32be
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|num
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
name|num
operator|>>
literal|24
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|num
operator|>>
literal|16
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
name|num
operator|>>
literal|8
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|=
name|num
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|unaligned_write32le
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|num
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
name|num
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|num
operator|>>
literal|8
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
name|num
operator|>>
literal|16
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|=
name|num
operator|>>
literal|24
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|uint32_t
name|bsr32
parameter_list|(
name|uint32_t
name|n
parameter_list|)
block|{
comment|// Check for ICC first, since it tends to define __GNUC__ too.
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
return|return
name|_bit_scan_reverse
argument_list|(
name|n
argument_list|)
return|;
elif|#
directive|elif
name|TUKLIB_GNUC_REQ
argument_list|(
literal|3
operator|,
literal|4
argument_list|)
operator|&&
name|UINT_MAX
operator|==
name|UINT32_MAX
comment|// GCC>= 3.4 has __builtin_clz(), which gives good results on
comment|// multiple architectures. On x86, __builtin_clz() ^ 31U becomes
comment|// either plain BSR (so the XOR gets optimized away) or LZCNT and
comment|// XOR (if -march indicates that SSE4a instructions are supported).
return|return
name|__builtin_clz
argument_list|(
name|n
argument_list|)
operator|^
literal|31U
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
name|uint32_t
name|i
decl_stmt|;
asm|__asm__("bsrl %1, %0" : "=r" (i) : "rm" (n));
return|return
name|i
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
comment|// MSVC isn't supported by tuklib, but since this code exists,
comment|// it doesn't hurt to have it here anyway.
name|uint32_t
name|i
decl_stmt|;
name|_BitScanReverse
argument_list|(
operator|(
name|DWORD
operator|*
operator|)
operator|&
name|i
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|i
return|;
else|#
directive|else
name|uint32_t
name|i
init|=
literal|31
decl_stmt|;
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xFFFF0000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|16
expr_stmt|;
name|i
operator|=
literal|15
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xFF000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|8
expr_stmt|;
name|i
operator|-=
literal|8
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xF0000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|4
expr_stmt|;
name|i
operator|-=
literal|4
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xC0000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|2
expr_stmt|;
name|i
operator|-=
literal|2
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x80000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
operator|--
name|i
expr_stmt|;
return|return
name|i
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|clz32
parameter_list|(
name|uint32_t
name|n
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
return|return
name|_bit_scan_reverse
argument_list|(
name|n
argument_list|)
operator|^
literal|31U
return|;
elif|#
directive|elif
name|TUKLIB_GNUC_REQ
argument_list|(
literal|3
operator|,
literal|4
argument_list|)
operator|&&
name|UINT_MAX
operator|==
name|UINT32_MAX
return|return
name|__builtin_clz
argument_list|(
name|n
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
name|uint32_t
name|i
decl_stmt|;
asm|__asm__("bsrl %1, %0\n\t" 		"xorl $31, %0" 		: "=r" (i) : "rm" (n));
return|return
name|i
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
name|uint32_t
name|i
decl_stmt|;
name|_BitScanReverse
argument_list|(
operator|(
name|DWORD
operator|*
operator|)
operator|&
name|i
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|i
operator|^
literal|31U
return|;
else|#
directive|else
name|uint32_t
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xFFFF0000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|16
expr_stmt|;
name|i
operator|=
literal|16
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xFF000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|8
expr_stmt|;
name|i
operator|+=
literal|8
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xF0000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|4
expr_stmt|;
name|i
operator|+=
literal|4
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0xC0000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|<<=
literal|2
expr_stmt|;
name|i
operator|+=
literal|2
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x80000000
argument_list|)
operator|)
operator|==
literal|0
condition|)
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|ctz32
parameter_list|(
name|uint32_t
name|n
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
return|return
name|_bit_scan_forward
argument_list|(
name|n
argument_list|)
return|;
elif|#
directive|elif
name|TUKLIB_GNUC_REQ
argument_list|(
literal|3
operator|,
literal|4
argument_list|)
operator|&&
name|UINT_MAX
operator|>=
name|UINT32_MAX
return|return
name|__builtin_ctz
argument_list|(
name|n
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
name|uint32_t
name|i
decl_stmt|;
asm|__asm__("bsfl %1, %0" : "=r" (i) : "rm" (n));
return|return
name|i
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
name|uint32_t
name|i
decl_stmt|;
name|_BitScanForward
argument_list|(
operator|(
name|DWORD
operator|*
operator|)
operator|&
name|i
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|i
return|;
else|#
directive|else
name|uint32_t
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x0000FFFF
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|>>=
literal|16
expr_stmt|;
name|i
operator|=
literal|16
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x000000FF
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|>>=
literal|8
expr_stmt|;
name|i
operator|+=
literal|8
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x0000000F
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|>>=
literal|4
expr_stmt|;
name|i
operator|+=
literal|4
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x00000003
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|>>=
literal|2
expr_stmt|;
name|i
operator|+=
literal|2
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|n
operator|&
name|UINT32_C
argument_list|(
literal|0x00000001
argument_list|)
operator|)
operator|==
literal|0
condition|)
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|bsf32
value|ctz32
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

