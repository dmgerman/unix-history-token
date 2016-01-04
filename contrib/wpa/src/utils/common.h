begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd / common helper functions, etc.  * Copyright (c) 2002-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|COMMON_H
end_define

begin_include
include|#
directive|include
file|"os.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_include
include|#
directive|include
file|<byteswap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|bswap_16
value|swap16
end_define

begin_define
define|#
directive|define
name|bswap_32
value|swap32
end_define

begin_define
define|#
directive|define
name|bswap_64
value|swap64
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_define
define|#
directive|define
name|bswap_16
value|bswap16
end_define

begin_define
define|#
directive|define
name|bswap_32
value|bswap32
end_define

begin_define
define|#
directive|define
name|bswap_64
value|bswap64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__) || defined(__NetBSD__) || 	* defined(__DragonFly__) || defined(__OpenBSD__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|short
name|bswap_16
parameter_list|(
name|unsigned
name|short
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|v
operator|>>
literal|8
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|bswap_32
parameter_list|(
name|unsigned
name|int
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|v
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|v
operator|&
literal|0xff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
name|v
operator|>>
literal|24
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __APPLE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NATIVE_WINDOWS
end_ifdef

begin_include
include|#
directive|include
file|<winsock.h>
end_include

begin_typedef
typedef|typedef
name|int
name|socklen_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_DONTWAIT
end_ifndef

begin_define
define|#
directive|define
name|MSG_DONTWAIT
value|0
end_define

begin_comment
comment|/* not supported */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NATIVE_WINDOWS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_undef
undef|#
directive|undef
name|vsnprintf
end_undef

begin_define
define|#
directive|define
name|vsnprintf
value|_vsnprintf
end_define

begin_undef
undef|#
directive|undef
name|close
end_undef

begin_define
define|#
directive|define
name|close
value|closesocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_comment
comment|/* Define platform specific integer types */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_typedef
typedef|typedef
name|UINT64
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT64
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT32
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT16
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT8
name|s8
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WPA_TYPES_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__vxworks
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT32
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT16
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT8
name|s8
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WPA_TYPES_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __vxworks */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_TYPES_DEFINED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_USE_INTTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|s8
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WPA_TYPES_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WPA_TYPES_DEFINED */
end_comment

begin_comment
comment|/* Define platform specific byte swapping macros */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|||
name|defined
argument_list|(
name|CONFIG_NATIVE_WINDOWS
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|unsigned
name|short
name|wpa_swap_16
parameter_list|(
name|unsigned
name|short
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|v
operator|>>
literal|8
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|wpa_swap_32
parameter_list|(
name|unsigned
name|int
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|v
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|v
operator|&
literal|0xff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
name|v
operator|>>
literal|24
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|le_to_host16
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_le16
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|be_to_host16
parameter_list|(
name|n
parameter_list|)
value|wpa_swap_16(n)
end_define

begin_define
define|#
directive|define
name|host_to_be16
parameter_list|(
name|n
parameter_list|)
value|wpa_swap_16(n)
end_define

begin_define
define|#
directive|define
name|le_to_host32
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_le32
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|be_to_host32
parameter_list|(
name|n
parameter_list|)
value|wpa_swap_32(n)
end_define

begin_define
define|#
directive|define
name|host_to_be32
parameter_list|(
name|n
parameter_list|)
value|wpa_swap_32(n)
end_define

begin_define
define|#
directive|define
name|WPA_BYTE_SWAP_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CYGWIN__ || CONFIG_NATIVE_WINDOWS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_BYTE_SWAP_DEFINED
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__BYTE_ORDER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__LITTLE_ENDIAN
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|4321
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
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
comment|/* __BIG_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BYTE_ORDER */
end_comment

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|le_to_host16
parameter_list|(
name|n
parameter_list|)
value|((__force u16) (le16) (n))
end_define

begin_define
define|#
directive|define
name|host_to_le16
parameter_list|(
name|n
parameter_list|)
value|((__force le16) (u16) (n))
end_define

begin_define
define|#
directive|define
name|be_to_host16
parameter_list|(
name|n
parameter_list|)
value|bswap_16((__force u16) (be16) (n))
end_define

begin_define
define|#
directive|define
name|host_to_be16
parameter_list|(
name|n
parameter_list|)
value|((__force be16) bswap_16((n)))
end_define

begin_define
define|#
directive|define
name|le_to_host32
parameter_list|(
name|n
parameter_list|)
value|((__force u32) (le32) (n))
end_define

begin_define
define|#
directive|define
name|host_to_le32
parameter_list|(
name|n
parameter_list|)
value|((__force le32) (u32) (n))
end_define

begin_define
define|#
directive|define
name|be_to_host32
parameter_list|(
name|n
parameter_list|)
value|bswap_32((__force u32) (be32) (n))
end_define

begin_define
define|#
directive|define
name|host_to_be32
parameter_list|(
name|n
parameter_list|)
value|((__force be32) bswap_32((n)))
end_define

begin_define
define|#
directive|define
name|le_to_host64
parameter_list|(
name|n
parameter_list|)
value|((__force u64) (le64) (n))
end_define

begin_define
define|#
directive|define
name|host_to_le64
parameter_list|(
name|n
parameter_list|)
value|((__force le64) (u64) (n))
end_define

begin_define
define|#
directive|define
name|be_to_host64
parameter_list|(
name|n
parameter_list|)
value|bswap_64((__force u64) (be64) (n))
end_define

begin_define
define|#
directive|define
name|host_to_be64
parameter_list|(
name|n
parameter_list|)
value|((__force be64) bswap_64((n)))
end_define

begin_elif
elif|#
directive|elif
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|le_to_host16
parameter_list|(
name|n
parameter_list|)
value|bswap_16(n)
end_define

begin_define
define|#
directive|define
name|host_to_le16
parameter_list|(
name|n
parameter_list|)
value|bswap_16(n)
end_define

begin_define
define|#
directive|define
name|be_to_host16
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_be16
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|le_to_host32
parameter_list|(
name|n
parameter_list|)
value|bswap_32(n)
end_define

begin_define
define|#
directive|define
name|host_to_le32
parameter_list|(
name|n
parameter_list|)
value|bswap_32(n)
end_define

begin_define
define|#
directive|define
name|be_to_host32
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_be32
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|le_to_host64
parameter_list|(
name|n
parameter_list|)
value|bswap_64(n)
end_define

begin_define
define|#
directive|define
name|host_to_le64
parameter_list|(
name|n
parameter_list|)
value|bswap_64(n)
end_define

begin_define
define|#
directive|define
name|be_to_host64
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_be64
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIGENDIAN
end_ifndef

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Could not determine CPU byte order
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WPA_BYTE_SWAP_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WPA_BYTE_SWAP_DEFINED */
end_comment

begin_comment
comment|/* Macros for handling unaligned memory accesses */
end_comment

begin_function
specifier|static
specifier|inline
name|u16
name|WPA_GET_BE16
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
name|a
index|[
literal|1
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_BE16
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u16
name|val
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
name|val
operator|>>
literal|8
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u16
name|WPA_GET_LE16
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_LE16
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u16
name|val
parameter_list|)
block|{
name|a
index|[
literal|1
index|]
operator|=
name|val
operator|>>
literal|8
expr_stmt|;
name|a
index|[
literal|0
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|WPA_GET_BE24
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|0
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|a
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|a
index|[
literal|2
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_BE24
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u32
name|val
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
operator|(
name|val
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|2
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|WPA_GET_BE32
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
operator|(
name|u32
operator|)
name|a
index|[
literal|0
index|]
operator|<<
literal|24
operator|)
operator||
operator|(
name|a
index|[
literal|1
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|a
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator||
name|a
index|[
literal|3
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_BE32
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u32
name|val
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
operator|(
name|val
operator|>>
literal|24
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
operator|(
name|val
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|2
index|]
operator|=
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|3
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|WPA_GET_LE32
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
operator|(
name|u32
operator|)
name|a
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
operator||
operator|(
name|a
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|a
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_LE32
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u32
name|val
parameter_list|)
block|{
name|a
index|[
literal|3
index|]
operator|=
operator|(
name|val
operator|>>
literal|24
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|2
index|]
operator|=
operator|(
name|val
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|a
index|[
literal|0
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u64
name|WPA_GET_BE64
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|0
index|]
operator|)
operator|<<
literal|56
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|1
index|]
operator|)
operator|<<
literal|48
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|2
index|]
operator|)
operator|<<
literal|40
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|3
index|]
operator|)
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|4
index|]
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|5
index|]
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|6
index|]
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|7
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_BE64
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u64
name|val
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
name|val
operator|>>
literal|56
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
name|val
operator|>>
literal|48
expr_stmt|;
name|a
index|[
literal|2
index|]
operator|=
name|val
operator|>>
literal|40
expr_stmt|;
name|a
index|[
literal|3
index|]
operator|=
name|val
operator|>>
literal|32
expr_stmt|;
name|a
index|[
literal|4
index|]
operator|=
name|val
operator|>>
literal|24
expr_stmt|;
name|a
index|[
literal|5
index|]
operator|=
name|val
operator|>>
literal|16
expr_stmt|;
name|a
index|[
literal|6
index|]
operator|=
name|val
operator|>>
literal|8
expr_stmt|;
name|a
index|[
literal|7
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u64
name|WPA_GET_LE64
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|7
index|]
operator|)
operator|<<
literal|56
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|6
index|]
operator|)
operator|<<
literal|48
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|5
index|]
operator|)
operator|<<
literal|40
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|4
index|]
operator|)
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|3
index|]
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|2
index|]
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|1
index|]
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|u64
operator|)
name|a
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WPA_PUT_LE64
parameter_list|(
name|u8
modifier|*
name|a
parameter_list|,
name|u64
name|val
parameter_list|)
block|{
name|a
index|[
literal|7
index|]
operator|=
name|val
operator|>>
literal|56
expr_stmt|;
name|a
index|[
literal|6
index|]
operator|=
name|val
operator|>>
literal|48
expr_stmt|;
name|a
index|[
literal|5
index|]
operator|=
name|val
operator|>>
literal|40
expr_stmt|;
name|a
index|[
literal|4
index|]
operator|=
name|val
operator|>>
literal|32
expr_stmt|;
name|a
index|[
literal|3
index|]
operator|=
name|val
operator|>>
literal|24
expr_stmt|;
name|a
index|[
literal|2
index|]
operator|=
name|val
operator|>>
literal|16
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
name|val
operator|>>
literal|8
expr_stmt|;
name|a
index|[
literal|0
index|]
operator|=
name|val
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_ALEN
end_ifndef

begin_define
define|#
directive|define
name|ETH_ALEN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_HLEN
end_ifndef

begin_define
define|#
directive|define
name|ETH_HLEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFNAMSIZ
end_ifndef

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_ALL
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_ALL
value|0x0003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_80211_ENCAP
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_80211_ENCAP
value|0x890d
end_define

begin_comment
comment|/* TDLS comes under this category */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_PAE
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_PAE
value|0x888E
end_define

begin_comment
comment|/* Port Access Entity (IEEE 802.1X) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_PAE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_EAPOL
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_EAPOL
value|ETH_P_PAE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_EAPOL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_RSN_PREAUTH
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_RSN_PREAUTH
value|0x88c7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_RSN_PREAUTH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_RRB
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_RRB
value|0x890D
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_RRB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|PRINTF_FORMAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__attribute__ ((format (printf, (a), (b))))
end_define

begin_define
define|#
directive|define
name|STRUCT_PACKED
value|__attribute__ ((packed))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINTF_FORMAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|STRUCT_PACKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ANSI_C_EXTRA
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|_MSC_VER
operator|<
literal|1400
end_if

begin_comment
comment|/* snprintf - used in number of places; sprintf() is _not_ a good replacement  * due to possible buffer overflow; see, e.g.,  * http://www.ijs.si/software/snprintf/ for portable implementation of  * snprintf. */
end_comment

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vsnprintf - only used for wpa_msg() in wpa_supplicant.c */
end_comment

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_MSC_VER) || _MSC_VER< 1400 */
end_comment

begin_comment
comment|/* getopt - only used in main.c */
end_comment

begin_function_decl
name|int
name|getopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|optstring
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NO_SOCKLEN_T_TYPEDEF
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__socklen_t_defined
end_ifndef

begin_typedef
typedef|typedef
name|int
name|socklen_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inline - define as __inline or just define it to be empty, if needed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_INLINE
end_ifdef

begin_define
define|#
directive|define
name|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__func__
end_ifndef

begin_define
define|#
directive|define
name|__func__
value|"__func__ not defined"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bswap_16
end_ifndef

begin_define
define|#
directive|define
name|bswap_16
parameter_list|(
name|a
parameter_list|)
value|((((u16) (a)<< 8)& 0xff00) | (((u16) (a)>> 8)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bswap_32
end_ifndef

begin_define
define|#
directive|define
name|bswap_32
parameter_list|(
name|a
parameter_list|)
value|((((u32) (a)<< 24)& 0xff000000) | \ 		     (((u32) (a)<< 8)& 0xff0000) | \      		     (((u32) (a)>> 8)& 0xff00) | \      		     (((u32) (a)>> 24)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_DONTWAIT
end_ifndef

begin_define
define|#
directive|define
name|MSG_DONTWAIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef

begin_function_decl
name|void
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32_WCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_ANSI_C_EXTRA */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAC2STR
end_ifndef

begin_define
define|#
directive|define
name|MAC2STR
parameter_list|(
name|a
parameter_list|)
value|(a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
end_define

begin_define
define|#
directive|define
name|MACSTR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_comment
comment|/*  * Compact form for string representation of MAC address  * To be used, e.g., for constructing dbus paths for P2P Devices  */
end_comment

begin_define
define|#
directive|define
name|COMPACT_MACSTR
value|"%02x%02x%02x%02x%02x%02x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT
end_ifndef

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1U<< (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for sparse validation  * (http://kernel.org/pub/linux/kernel/people/josh/sparse/)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CHECKER__
end_ifdef

begin_define
define|#
directive|define
name|__force
value|__attribute__((force))
end_define

begin_define
define|#
directive|define
name|__bitwise
value|__attribute__((bitwise))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__force
end_define

begin_define
define|#
directive|define
name|__bitwise
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|u16
name|__bitwise
name|be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u16
name|__bitwise
name|le16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u32
name|__bitwise
name|be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u32
name|__bitwise
name|le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u64
name|__bitwise
name|be64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u64
name|__bitwise
name|le64
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__must_check
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|__must_check
value|__attribute__((__warn_unused_result__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__must_check
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __must_check */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__maybe_unused
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|__maybe_unused
value|__attribute__((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__maybe_unused
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __must_check */
end_comment

begin_function_decl
name|int
name|hwaddr_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hwaddr_masked_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
modifier|*
name|mask
parameter_list|,
name|u8
name|maskable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hwaddr_compact_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hwaddr_aton2
parameter_list|(
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hex2byte
parameter_list|(
specifier|const
name|char
modifier|*
name|hex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hexstr2bin
parameter_list|(
specifier|const
name|char
modifier|*
name|hex
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inc_byte_array
parameter_list|(
name|u8
modifier|*
name|counter
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_get_ntp_timestamp
parameter_list|(
name|u8
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_scnprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_snprintf_hex_sep
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|char
name|sep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_snprintf_hex
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_snprintf_hex_uppercase
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hwaddr_mask_txt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NATIVE_WINDOWS
end_ifdef

begin_function_decl
name|void
name|wpa_unicode2ascii_inplace
parameter_list|(
name|TCHAR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TCHAR
modifier|*
name|wpa_strdup_tchar
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NATIVE_WINDOWS */
end_comment

begin_define
define|#
directive|define
name|wpa_unicode2ascii_inplace
parameter_list|(
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_strdup_tchar
parameter_list|(
name|s
parameter_list|)
value|strdup((s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NATIVE_WINDOWS */
end_comment

begin_function_decl
name|void
name|printf_encode
parameter_list|(
name|char
modifier|*
name|txt
parameter_list|,
name|size_t
name|maxlen
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|printf_decode
parameter_list|(
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|maxlen
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|wpa_ssid_txt
parameter_list|(
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|wpa_config_parse_string
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_hex
parameter_list|(
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|merge_byte_arrays
parameter_list|(
name|u8
modifier|*
name|res
parameter_list|,
name|size_t
name|res_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|src1
parameter_list|,
name|size_t
name|src1_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|src2
parameter_list|,
name|size_t
name|src2_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dup_binstr
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|is_zero_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|!
operator|(
name|a
index|[
literal|0
index|]
operator||
name|a
index|[
literal|1
index|]
operator||
name|a
index|[
literal|2
index|]
operator||
name|a
index|[
literal|3
index|]
operator||
name|a
index|[
literal|4
index|]
operator||
name|a
index|[
literal|5
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_broadcast_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|0
index|]
operator|&
name|a
index|[
literal|1
index|]
operator|&
name|a
index|[
literal|2
index|]
operator|&
name|a
index|[
literal|3
index|]
operator|&
name|a
index|[
literal|4
index|]
operator|&
name|a
index|[
literal|5
index|]
operator|)
operator|==
literal|0xff
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_multicast_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
index|[
literal|0
index|]
operator|&
literal|0x01
return|;
block|}
end_function

begin_define
define|#
directive|define
name|broadcast_ether_addr
value|(const u8 *) "\xff\xff\xff\xff\xff\xff"
end_define

begin_include
include|#
directive|include
file|"wpa_debug.h"
end_include

begin_struct
struct|struct
name|wpa_freq_range_list
block|{
struct|struct
name|wpa_freq_range
block|{
name|unsigned
name|int
name|min
decl_stmt|;
name|unsigned
name|int
name|max
decl_stmt|;
block|}
modifier|*
name|range
struct|;
name|unsigned
name|int
name|num
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|freq_range_list_parse
parameter_list|(
name|struct
name|wpa_freq_range_list
modifier|*
name|res
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freq_range_list_includes
parameter_list|(
specifier|const
name|struct
name|wpa_freq_range_list
modifier|*
name|list
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|freq_range_list_str
parameter_list|(
specifier|const
name|struct
name|wpa_freq_range_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|int_array_len
parameter_list|(
specifier|const
name|int
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|int_array_concat
parameter_list|(
name|int
modifier|*
modifier|*
name|res
parameter_list|,
specifier|const
name|int
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|int_array_sort_unique
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|int_array_add_unique
parameter_list|(
name|int
modifier|*
modifier|*
name|res
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof((a)[0]))
end_define

begin_function_decl
name|void
name|str_clear_free
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bin_clear_free
parameter_list|(
name|void
modifier|*
name|bin
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_mac_addr
parameter_list|(
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_mac_addr_keep_oui
parameter_list|(
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|cstr_token
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_token
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|,
name|char
modifier|*
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|utf8_escape
parameter_list|(
specifier|const
name|char
modifier|*
name|inp
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
name|out_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|utf8_unescape
parameter_list|(
specifier|const
name|char
modifier|*
name|inp
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
name|out_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_ctrl_char
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * gcc 4.4 ends up generating strict-aliasing warnings about some very common  * networking socket uses that do not really result in a real problem and  * cannot be easily avoided with union-based type-punning due to struct  * definitions including another struct in system header files. To avoid having  * to fully disable strict-aliasing warnings, provide a mechanism to hide the  * typecast from aliasing for now. A cleaner solution will hopefully be found  * in the future to handle these cases.  */
end_comment

begin_function_decl
name|void
modifier|*
name|__hide_aliasing_typecast
parameter_list|(
name|void
modifier|*
name|foo
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|aliasing_hide_typecast
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|(t *) __hide_aliasing_typecast((a))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_VALGRIND
end_ifdef

begin_include
include|#
directive|include
file|<valgrind/memcheck.h>
end_include

begin_define
define|#
directive|define
name|WPA_MEM_DEFINED
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|VALGRIND_MAKE_MEM_DEFINED((ptr), (len))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_VALGRIND */
end_comment

begin_define
define|#
directive|define
name|WPA_MEM_DEFINED
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_VALGRIND */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMON_H */
end_comment

end_unit

