begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Private includes and definitions for userspace use of XZ Embedded  *  * Author: Lasse Collin<lasse.collin@tukaani.org>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|XZ_CONFIG_H
end_define

begin_comment
comment|/* Uncomment to enable CRC64 support. */
end_comment

begin_comment
comment|/* #define XZ_USE_CRC64 */
end_comment

begin_comment
comment|/* Uncomment as needed to enable BCJ filter decoders. */
end_comment

begin_comment
comment|/* #define XZ_DEC_X86 */
end_comment

begin_comment
comment|/* #define XZ_DEC_POWERPC */
end_comment

begin_comment
comment|/* #define XZ_DEC_IA64 */
end_comment

begin_comment
comment|/* #define XZ_DEC_ARM */
end_comment

begin_comment
comment|/* #define XZ_DEC_ARMTHUMB */
end_comment

begin_comment
comment|/* #define XZ_DEC_SPARC */
end_comment

begin_comment
comment|/*  * MSVC doesn't support modern C but XZ Embedded is mostly C89  * so these are enough.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"xz.h"
end_include

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_define
define|#
directive|define
name|vmalloc
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|vfree
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_define
define|#
directive|define
name|memeq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|size
parameter_list|)
value|(memcmp(a, b, size) == 0)
end_define

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|memset(buf, 0, size)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|min(x, y)
end_define

begin_comment
comment|/*  * Some functions have been marked with __always_inline to keep the  * performance reasonable even when the compiler is optimizing for  * small code size. You may be able to save a few bytes by #defining  * __always_inline to plain inline, but don't complain if the code  * becomes slow.  *  * NOTE: System headers on GNU/Linux may #define this macro already,  * so if you want to change it, you need to #undef it first.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__always_inline
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__always_inline
define|\
value|inline __attribute__((__always_inline__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__always_inline
value|inline
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
comment|/* Inline functions to access unaligned unsigned 32-bit integers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|get_unaligned_le32
end_ifndef

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_unaligned_le32
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|0
index|]
operator||
operator|(
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|get_unaligned_be32
end_ifndef

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_unaligned_be32
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
return|return
call|(
name|uint32_t
call|)
argument_list|(
name|buf
index|[
literal|0
index|]
operator|<<
literal|24
argument_list|)
operator||
operator|(
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|1
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
name|uint32_t
operator|)
name|buf
index|[
literal|3
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|put_unaligned_le32
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|put_unaligned_le32
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
operator|(
name|uint8_t
operator|)
name|val
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|24
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|put_unaligned_be32
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|put_unaligned_be32
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|24
argument_list|)
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|val
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|=
operator|(
name|uint8_t
operator|)
name|val
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Use get_unaligned_le32() also for aligned access for simplicity. On  * little endian systems, #define get_le32(ptr) (*(const uint32_t *)(ptr))  * could save a few bytes in code size.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|get_le32
end_ifndef

begin_define
define|#
directive|define
name|get_le32
value|get_unaligned_le32
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

