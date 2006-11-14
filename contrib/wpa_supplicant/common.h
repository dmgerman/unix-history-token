begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd / common helper functions, etc.  * Copyright (c) 2002-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * $FreeBSD$  */
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
comment|/* defined(__FreeBSD__) || defined(__NetBSD__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NATIVE_WINDOWS
end_ifdef

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_function
specifier|static
specifier|inline
name|int
name|daemon
parameter_list|(
name|int
name|nochdir
parameter_list|,
name|int
name|noclose
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Windows - daemon() not supported yet\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sleep
parameter_list|(
name|int
name|seconds
parameter_list|)
block|{
name|Sleep
argument_list|(
name|seconds
operator|*
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|usleep
parameter_list|(
name|unsigned
name|long
name|usec
parameter_list|)
block|{
name|Sleep
argument_list|(
name|usec
operator|/
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|timersub
end_ifndef

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|res
parameter_list|)
value|do { \ 	(res)->tv_sec = (a)->tv_sec - (b)->tv_sec; \ 	(res)->tv_usec = (a)->tv_usec - (b)->tv_usec; \ 	if ((res)->tv_usec< 0) { \ 		(res)->tv_sec--; \ 		(res)->tv_usec += 1000000; \ 	} \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|timezone
block|{
name|int
name|tz_minuteswest
decl_stmt|;
name|int
name|tz_dsttime
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|timezone
modifier|*
name|tz
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|long
name|int
name|random
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|rand
argument_list|()
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|gid_t
typedef|;
end_typedef

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

begin_include
include|#
directive|include
file|<stdint.h>
end_include

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

begin_function_decl
name|int
name|hostapd_get_rand
parameter_list|(
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
name|hostapd_hexdump
parameter_list|(
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
name|char
modifier|*
name|rel2abs_path
parameter_list|(
specifier|const
name|char
modifier|*
name|rel_path
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
name|print_char
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fprint_char
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Debugging function - conditional printf and hex dump. Driver wrappers can  *  use these for debugging purposes. */
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
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_key
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_hexdump_ascii_key
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

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
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMON_H */
end_comment

end_unit

