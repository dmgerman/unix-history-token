begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd / common helper functions, etc.  * Copyright (c) 2002-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

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
comment|/* defined(__FreeBSD__) || defined(__NetBSD__) || 	* defined(__DragonFly__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_TI_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1234
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__big_endian__
end_ifdef

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__LITTLE_ENDIAN
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
comment|/* CONFIG_TI_COMPILER */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __CYGWIN__ */
end_comment

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
value|bswap_16(n)
end_define

begin_define
define|#
directive|define
name|host_to_be16
parameter_list|(
name|n
parameter_list|)
value|bswap_16(n)
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
name|be_to_host32
parameter_list|(
name|n
parameter_list|)
value|bswap_32(n)
end_define

begin_define
define|#
directive|define
name|host_to_be32
parameter_list|(
name|n
parameter_list|)
value|bswap_32(n)
end_define

begin_define
define|#
directive|define
name|le_to_host64
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|host_to_le64
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|be_to_host64
parameter_list|(
name|n
parameter_list|)
value|bswap_64(n)
end_define

begin_define
define|#
directive|define
name|host_to_be64
parameter_list|(
name|n
parameter_list|)
value|bswap_64(n)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CYGWIN__ */
end_comment

begin_comment
comment|/* Macros for handling unaligned 16-bit variables */
end_comment

begin_define
define|#
directive|define
name|WPA_GET_BE16
parameter_list|(
name|a
parameter_list|)
value|((u16) (((a)[0]<< 8) | (a)[1]))
end_define

begin_define
define|#
directive|define
name|WPA_PUT_BE16
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\ 		(a)[0] = ((u16) (val))>> 8;	\ 		(a)[1] = ((u16) (val))& 0xff;	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WPA_GET_LE16
parameter_list|(
name|a
parameter_list|)
value|((u16) (((a)[1]<< 8) | (a)[0]))
end_define

begin_define
define|#
directive|define
name|WPA_PUT_LE16
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\ 		(a)[1] = ((u16) (val))>> 8;	\ 		(a)[0] = ((u16) (val))& 0xff;	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WPA_GET_BE24
parameter_list|(
name|a
parameter_list|)
value|((((u32) (a)[0])<< 16) | (((u32) (a)[1])<< 8) | \ 			 ((u32) (a)[2]))
end_define

begin_define
define|#
directive|define
name|WPA_PUT_BE24
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
define|\
value|do {						\ 		(a)[0] = (u8) (((u32) (val))>> 16);	\ 		(a)[1] = (u8) (((u32) (val))>> 8);	\ 		(a)[2] = (u8) (((u32) (val))& 0xff);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WPA_GET_BE32
parameter_list|(
name|a
parameter_list|)
value|((((u32) (a)[0])<< 24) | (((u32) (a)[1])<< 16) | \ 			 (((u32) (a)[2])<< 8) | ((u32) (a)[3]))
end_define

begin_define
define|#
directive|define
name|WPA_PUT_BE32
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
define|\
value|do {						\ 		(a)[0] = (u8) (((u32) (val))>> 24);	\ 		(a)[1] = (u8) (((u32) (val))>> 16);	\ 		(a)[2] = (u8) (((u32) (val))>> 8);	\ 		(a)[3] = (u8) (((u32) (val))& 0xff);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WPA_PUT_BE64
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
define|\
value|do {						\ 		(a)[0] = (u8) (((u64) (val))>> 56);	\ 		(a)[1] = (u8) (((u64) (val))>> 48);	\ 		(a)[2] = (u8) (((u64) (val))>> 40);	\ 		(a)[3] = (u8) (((u64) (val))>> 32);	\ 		(a)[4] = (u8) (((u64) (val))>> 24);	\ 		(a)[5] = (u8) (((u64) (val))>> 16);	\ 		(a)[6] = (u8) (((u64) (val))>> 8);	\ 		(a)[7] = (u8) (((u64) (val))& 0xff);	\ 	} while (0)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_TI_COMPILER
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_LLONG_AVAILABLE
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * TODO: 64-bit variable not available. Using long as a workaround to test the  * build, but this will likely not work for all operations.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
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
comment|/* CONFIG_TI_COMPILER */
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

begin_define
define|#
directive|define
name|hostapd_get_rand
value|os_get_random
end_define

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

begin_comment
comment|/* Debugging function - conditional printf and hex dump. Driver wrappers can  * use these for debugging purposes. */
end_comment

begin_enum
enum|enum
block|{
name|MSG_MSGDUMP
block|,
name|MSG_DEBUG
block|,
name|MSG_INFO
block|,
name|MSG_WARNING
block|,
name|MSG_ERROR
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_STDOUT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|wpa_debug_print_timestamp
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_printf
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_key
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii_key
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|,
name|le
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_debug_open_file
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_debug_close_file
parameter_list|()
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_function_decl
name|int
name|wpa_debug_open_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_debug_close_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_debug_printf_timestamp - Print timestamp for debug output  *  * This function prints a timestamp in<seconds from 1970>.<microsoconds>  * format if debug output has been configured to include timestamps in debug  * messages.  */
end_comment

begin_function_decl
name|void
name|wpa_debug_print_timestamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_printf - conditional printf  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
end_comment

begin_function_decl
name|void
name|wpa_printf
parameter_list|(
name|int
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * wpa_hexdump - conditional hex dump  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_hexdump_key - conditional hex dump, hide keys  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump. This works  * like wpa_hexdump(), but by default, does not include secret keys (passwords,  * etc.) in debug output.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_key
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_hexdump_ascii - conditional hex dump  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump with both  * the hex numbers and ASCII characters (for printable range) are shown. 16  * bytes per line will be shown.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_ascii
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_hexdump_ascii_key - conditional hex dump, hide keys  * @level: priority level (MSG_*) of the message  * @title: title of for the message  * @buf: data buffer to be dumped  * @len: length of the buf  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. The contents of buf is printed out has hex dump with both  * the hex numbers and ASCII characters (for printable range) are shown. 16  * bytes per line will be shown. This works like wpa_hexdump_ascii(), but by  * default, does not include secret keys (passwords, etc.) in debug output.  */
end_comment

begin_function_decl
name|void
name|wpa_hexdump_ascii_key
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_WPA_MSG
end_ifdef

begin_define
define|#
directive|define
name|wpa_msg
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_msg_register_cb
parameter_list|(
name|f
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_WPA_MSG */
end_comment

begin_comment
comment|/**  * wpa_msg - Conditional printf for default target and ctrl_iface monitors  * @ctx: Pointer to context data; this is the ctx variable registered  *	with struct wpa_driver_ops::init()  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. This function is like wpa_printf(), but it also sends the  * same message to all attached ctrl_iface monitors.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
end_comment

begin_function_decl
name|void
name|wpa_msg
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|wpa_msg_cb_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * wpa_msg_register_cb - Register callback function for wpa_msg() messages  * @func: Callback function (%NULL to unregister)  */
end_comment

begin_function_decl
name|void
name|wpa_msg_register_cb
parameter_list|(
name|wpa_msg_cb_func
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_WPA_MSG */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|EAPOL_TEST
end_ifdef

begin_define
define|#
directive|define
name|WPA_ASSERT
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							       \ 		if (!(a)) {					       \ 			printf("WPA_ASSERT FAILED '" #a "' "	       \ 			       "%s %s:%d\n",			       \ 			       __FUNCTION__, __FILE__, __LINE__);      \ 			exit(1);				       \ 		}						       \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WPA_ASSERT
parameter_list|(
name|a
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

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

begin_define
define|#
directive|define
name|wpa_zalloc
parameter_list|(
name|s
parameter_list|)
value|os_zalloc((s))
end_define

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
specifier|const
name|char
modifier|*
name|wpa_ssid_txt
parameter_list|(
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|u32
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u64
name|__be64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMON_H */
end_comment

end_unit

