begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_UTIL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_UTIL_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/util.h    Common convenience functions for cross-platform portability and   related socket manipulations.   */
end_comment

begin_include
include|#
directive|include
file|<event2/visibility.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<event2/event-config.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TIME_H
include|#
directive|include
file|<sys/time.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_STDINT_H
include|#
directive|include
file|<stdint.h>
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT__HAVE_INTTYPES_H
argument_list|)
include|#
directive|include
file|<inttypes.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TYPES_H
include|#
directive|include
file|<sys/types.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_STDDEF_H
include|#
directive|include
file|<stddef.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_MSC_VER
include|#
directive|include
file|<BaseTsd.h>
endif|#
directive|endif
include|#
directive|include
file|<stdarg.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_NETDB_H
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_GNU_SOURCE
argument_list|)
define|#
directive|define
name|_GNU_SOURCE
endif|#
directive|endif
include|#
directive|include
file|<netdb.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_WIN32
include|#
directive|include
file|<winsock2.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_GETADDRINFO
comment|/* for EAI_* definitions. */
include|#
directive|include
file|<ws2tcpip.h>
endif|#
directive|endif
else|#
directive|else
include|#
directive|include
file|<sys/socket.h>
endif|#
directive|endif
comment|/* Some openbsd autoconf versions get the name of this macro wrong. */
if|#
directive|if
name|defined
argument_list|(
name|EVENT__SIZEOF_VOID__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EVENT__SIZEOF_VOID_P
argument_list|)
define|#
directive|define
name|EVENT__SIZEOF_VOID_P
value|EVENT__SIZEOF_VOID__
endif|#
directive|endif
comment|/**  * @name Standard integer types.  *  * Integer type definitions for types that are supposed to be defined in the  * C99-specified stdint.h.  Shamefully, some platforms do not include  * stdint.h, so we need to replace it.  (If you are on a platform like this,  * your C headers are now over 10 years out of date.  You should bug them to  * do something about this.)  *  * We define:  *  *<dl>  *<dt>ev_uint64_t, ev_uint32_t, ev_uint16_t, ev_uint8_t</dt>  *<dd>unsigned integer types of exactly 64, 32, 16, and 8 bits  *          respectively.</dd>  *<dt>ev_int64_t, ev_int32_t, ev_int16_t, ev_int8_t</dt>  *<dd>signed integer types of exactly 64, 32, 16, and 8 bits  *          respectively.</dd>  *<dt>ev_uintptr_t, ev_intptr_t</dt>  *<dd>unsigned/signed integers large enough  *      to hold a pointer without loss of bits.</dd>  *<dt>ev_ssize_t</dt>  *<dd>A signed type of the same size as size_t</dd>  *<dt>ev_off_t</dt>  *<dd>A signed type typically used to represent offsets within a  *      (potentially large) file</dd>  *  * @{  */
ifdef|#
directive|ifdef
name|EVENT__HAVE_UINT64_T
define|#
directive|define
name|ev_uint64_t
value|uint64_t
define|#
directive|define
name|ev_int64_t
value|int64_t
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
define|#
directive|define
name|ev_uint64_t
value|unsigned __int64
define|#
directive|define
name|ev_int64_t
value|signed __int64
elif|#
directive|elif
name|EVENT__SIZEOF_LONG_LONG
operator|==
literal|8
define|#
directive|define
name|ev_uint64_t
value|unsigned long long
define|#
directive|define
name|ev_int64_t
value|long long
elif|#
directive|elif
name|EVENT__SIZEOF_LONG
operator|==
literal|8
define|#
directive|define
name|ev_uint64_t
value|unsigned long
define|#
directive|define
name|ev_int64_t
value|long
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_uint64_t
value|...
define|#
directive|define
name|ev_int64_t
value|...
else|#
directive|else
error|#
directive|error
literal|"No way to define ev_uint64_t"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_UINT32_T
define|#
directive|define
name|ev_uint32_t
value|uint32_t
define|#
directive|define
name|ev_int32_t
value|int32_t
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
define|#
directive|define
name|ev_uint32_t
value|unsigned int
define|#
directive|define
name|ev_int32_t
value|signed int
elif|#
directive|elif
name|EVENT__SIZEOF_LONG
operator|==
literal|4
define|#
directive|define
name|ev_uint32_t
value|unsigned long
define|#
directive|define
name|ev_int32_t
value|signed long
elif|#
directive|elif
name|EVENT__SIZEOF_INT
operator|==
literal|4
define|#
directive|define
name|ev_uint32_t
value|unsigned int
define|#
directive|define
name|ev_int32_t
value|signed int
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_uint32_t
value|...
define|#
directive|define
name|ev_int32_t
value|...
else|#
directive|else
error|#
directive|error
literal|"No way to define ev_uint32_t"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_UINT16_T
define|#
directive|define
name|ev_uint16_t
value|uint16_t
define|#
directive|define
name|ev_int16_t
value|int16_t
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
define|#
directive|define
name|ev_uint16_t
value|unsigned short
define|#
directive|define
name|ev_int16_t
value|signed short
elif|#
directive|elif
name|EVENT__SIZEOF_INT
operator|==
literal|2
define|#
directive|define
name|ev_uint16_t
value|unsigned int
define|#
directive|define
name|ev_int16_t
value|signed int
elif|#
directive|elif
name|EVENT__SIZEOF_SHORT
operator|==
literal|2
define|#
directive|define
name|ev_uint16_t
value|unsigned short
define|#
directive|define
name|ev_int16_t
value|signed short
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_uint16_t
value|...
define|#
directive|define
name|ev_int16_t
value|...
else|#
directive|else
error|#
directive|error
literal|"No way to define ev_uint16_t"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_UINT8_T
define|#
directive|define
name|ev_uint8_t
value|uint8_t
define|#
directive|define
name|ev_int8_t
value|int8_t
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_uint8_t
value|...
define|#
directive|define
name|ev_int8_t
value|...
else|#
directive|else
define|#
directive|define
name|ev_uint8_t
value|unsigned char
define|#
directive|define
name|ev_int8_t
value|signed char
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_UINTPTR_T
define|#
directive|define
name|ev_uintptr_t
value|uintptr_t
define|#
directive|define
name|ev_intptr_t
value|intptr_t
elif|#
directive|elif
name|EVENT__SIZEOF_VOID_P
operator|<=
literal|4
define|#
directive|define
name|ev_uintptr_t
value|ev_uint32_t
define|#
directive|define
name|ev_intptr_t
value|ev_int32_t
elif|#
directive|elif
name|EVENT__SIZEOF_VOID_P
operator|<=
literal|8
define|#
directive|define
name|ev_uintptr_t
value|ev_uint64_t
define|#
directive|define
name|ev_intptr_t
value|ev_int64_t
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_uintptr_t
value|...
define|#
directive|define
name|ev_intptr_t
value|...
else|#
directive|else
error|#
directive|error
literal|"No way to define ev_uintptr_t"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__ssize_t
define|#
directive|define
name|ev_ssize_t
value|EVENT__ssize_t
else|#
directive|else
define|#
directive|define
name|ev_ssize_t
value|ssize_t
endif|#
directive|endif
comment|/* Note that we define ev_off_t based on the compile-time size of off_t that  * we used to build Libevent, and not based on the current size of off_t.  * (For example, we don't define ev_off_t to off_t.).  We do this because  * some systems let you build your software with different off_t sizes  * at runtime, and so putting in any dependency on off_t would risk API  * mismatch.  */
ifdef|#
directive|ifdef
name|_WIN32
define|#
directive|define
name|ev_off_t
value|ev_int64_t
elif|#
directive|elif
name|EVENT__SIZEOF_OFF_T
operator|==
literal|8
define|#
directive|define
name|ev_off_t
value|ev_int64_t
elif|#
directive|elif
name|EVENT__SIZEOF_OFF_T
operator|==
literal|4
define|#
directive|define
name|ev_off_t
value|ev_int32_t
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|ev_off_t
value|...
else|#
directive|else
define|#
directive|define
name|ev_off_t
value|off_t
endif|#
directive|endif
comment|/**@}*/
comment|/* Limits for integer types.     We're making two assumptions here:      - The compiler does constant folding properly.      - The platform does signed arithmetic in two's complement. */
comment|/**    @name Limits for integer types     These macros hold the largest or smallest values possible for the    ev_[u]int*_t types.     @{ */
define|#
directive|define
name|EV_UINT64_MAX
value|((((ev_uint64_t)0xffffffffUL)<< 32) | 0xffffffffUL)
define|#
directive|define
name|EV_INT64_MAX
value|((((ev_int64_t) 0x7fffffffL)<< 32) | 0xffffffffL)
define|#
directive|define
name|EV_INT64_MIN
value|((-EV_INT64_MAX) - 1)
define|#
directive|define
name|EV_UINT32_MAX
value|((ev_uint32_t)0xffffffffUL)
define|#
directive|define
name|EV_INT32_MAX
value|((ev_int32_t) 0x7fffffffL)
define|#
directive|define
name|EV_INT32_MIN
value|((-EV_INT32_MAX) - 1)
define|#
directive|define
name|EV_UINT16_MAX
value|((ev_uint16_t)0xffffUL)
define|#
directive|define
name|EV_INT16_MAX
value|((ev_int16_t) 0x7fffL)
define|#
directive|define
name|EV_INT16_MIN
value|((-EV_INT16_MAX) - 1)
define|#
directive|define
name|EV_UINT8_MAX
value|255
define|#
directive|define
name|EV_INT8_MAX
value|127
define|#
directive|define
name|EV_INT8_MIN
value|((-EV_INT8_MAX) - 1)
comment|/** @} */
comment|/**    @name Limits for SIZE_T and SSIZE_T     @{ */
if|#
directive|if
name|EVENT__SIZEOF_SIZE_T
operator|==
literal|8
define|#
directive|define
name|EV_SIZE_MAX
value|EV_UINT64_MAX
define|#
directive|define
name|EV_SSIZE_MAX
value|EV_INT64_MAX
elif|#
directive|elif
name|EVENT__SIZEOF_SIZE_T
operator|==
literal|4
define|#
directive|define
name|EV_SIZE_MAX
value|EV_UINT32_MAX
define|#
directive|define
name|EV_SSIZE_MAX
value|EV_INT32_MAX
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|EV_SIZE_MAX
value|...
define|#
directive|define
name|EV_SSIZE_MAX
value|...
else|#
directive|else
error|#
directive|error
literal|"No way to define SIZE_MAX"
endif|#
directive|endif
define|#
directive|define
name|EV_SSIZE_MIN
value|((-EV_SSIZE_MAX) - 1)
comment|/**@}*/
ifdef|#
directive|ifdef
name|_WIN32
define|#
directive|define
name|ev_socklen_t
value|int
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT__socklen_t
argument_list|)
define|#
directive|define
name|ev_socklen_t
value|EVENT__socklen_t
else|#
directive|else
define|#
directive|define
name|ev_socklen_t
value|socklen_t
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_STRUCT_SOCKADDR_STORAGE___SS_FAMILY
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVENT__HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|ss_family
argument_list|)
define|#
directive|define
name|ss_family
value|__ss_family
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * A type wide enough to hold the output of "socket()" or "accept()".  On  * Windows, this is an intptr_t; elsewhere, it is an int. */
ifdef|#
directive|ifdef
name|_WIN32
define|#
directive|define
name|evutil_socket_t
value|intptr_t
else|#
directive|else
define|#
directive|define
name|evutil_socket_t
value|int
endif|#
directive|endif
comment|/** Create two new sockets that are connected to each other.      On Unix, this simply calls socketpair().  On Windows, it uses the     loopback network interface on 127.0.0.1, and only     AF_INET,SOCK_STREAM are supported.      (This may fail on some Windows hosts where firewall software has cleverly     decided to keep 127.0.0.1 from talking to itself.)      Parameters and return values are as for socketpair() */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_socketpair
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|protocol
parameter_list|,
name|evutil_socket_t
name|sv
index|[
literal|2
index|]
parameter_list|)
function_decl|;
comment|/** Do platform-specific operations as needed to make a socket nonblocking.      @param sock The socket to make nonblocking     @return 0 on success, -1 on failure  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_make_socket_nonblocking
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
comment|/** Do platform-specific operations to make a listener socket reusable.      Specifically, we want to make sure that another program will be able     to bind this address right after we've closed the listener.      This differs from Windows's interpretation of "reusable", which     allows multiple listeners to bind the same address at the same time.      @param sock The socket to make reusable     @return 0 on success, -1 on failure  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_make_listen_socket_reuseable
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
comment|/** Do platform-specific operations as needed to close a socket upon a     successful execution of one of the exec*() functions.      @param sock The socket to be closed     @return 0 on success, -1 on failure  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_make_socket_closeonexec
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
comment|/** Do the platform-specific call needed to close a socket returned from     socket() or accept().      @param sock The socket to be closed     @return 0 on success, -1 on failure  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_closesocket
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
define|#
directive|define
name|EVUTIL_CLOSESOCKET
parameter_list|(
name|s
parameter_list|)
value|evutil_closesocket(s)
comment|/** Do platform-specific operations, if possible, to make a tcp listener  *  socket defer accept()s until there is data to read.  *    *  Not all platforms support this.  You don't want to do this for every  *  listener socket: only the ones that implement a protocol where the  *  client transmits before the server needs to respond.  *  *  @param sock The listening socket to to make deferred  *  @return 0 on success (whether the operation is supported or not),  *       -1 on failure */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_make_tcp_listen_socket_deferred
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|_WIN32
comment|/** Return the most recent socket error.  Not idempotent on all platforms. */
define|#
directive|define
name|EVUTIL_SOCKET_ERROR
parameter_list|()
value|WSAGetLastError()
comment|/** Replace the most recent socket error with errcode */
define|#
directive|define
name|EVUTIL_SET_SOCKET_ERROR
parameter_list|(
name|errcode
parameter_list|)
define|\
value|do { WSASetLastError(errcode); } while (0)
comment|/** Return the most recent socket error to occur on sock. */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_socket_geterror
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|)
function_decl|;
comment|/** Convert a socket error to a string. */
name|EVENT2_EXPORT_SYMBOL
specifier|const
name|char
modifier|*
name|evutil_socket_error_to_string
parameter_list|(
name|int
name|errcode
parameter_list|)
function_decl|;
elif|#
directive|elif
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
comment|/**    @name Socket error functions     These functions are needed for making programs compatible between    Windows and Unix-like platforms.     You see, Winsock handles socket errors differently from the rest of    the world.  Elsewhere, a socket error is like any other error and is    stored in errno.  But winsock functions require you to retrieve the    error with a special function, and don't let you use strerror for    the error codes.  And handling EWOULDBLOCK is ... different.     @{ */
comment|/** Return the most recent socket error.  Not idempotent on all platforms. */
define|#
directive|define
name|EVUTIL_SOCKET_ERROR
parameter_list|()
value|...
comment|/** Replace the most recent socket error with errcode */
define|#
directive|define
name|EVUTIL_SET_SOCKET_ERROR
parameter_list|(
name|errcode
parameter_list|)
value|...
comment|/** Return the most recent socket error to occur on sock. */
define|#
directive|define
name|evutil_socket_geterror
parameter_list|(
name|sock
parameter_list|)
value|...
comment|/** Convert a socket error to a string. */
define|#
directive|define
name|evutil_socket_error_to_string
parameter_list|(
name|errcode
parameter_list|)
value|...
comment|/**@}*/
else|#
directive|else
define|#
directive|define
name|EVUTIL_SOCKET_ERROR
parameter_list|()
value|(errno)
define|#
directive|define
name|EVUTIL_SET_SOCKET_ERROR
parameter_list|(
name|errcode
parameter_list|)
define|\
value|do { errno = (errcode); } while (0)
define|#
directive|define
name|evutil_socket_geterror
parameter_list|(
name|sock
parameter_list|)
value|(errno)
define|#
directive|define
name|evutil_socket_error_to_string
parameter_list|(
name|errcode
parameter_list|)
value|(strerror(errcode))
endif|#
directive|endif
comment|/**  * @name Manipulation macros for struct timeval.  *  * We define replacements  * for timeradd, timersub, timerclear, timercmp, and timerisset.  *  * @{  */
ifdef|#
directive|ifdef
name|EVENT__HAVE_TIMERADD
define|#
directive|define
name|evutil_timeradd
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
value|timeradd((tvp), (uvp), (vvp))
define|#
directive|define
name|evutil_timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
value|timersub((tvp), (uvp), (vvp))
else|#
directive|else
define|#
directive|define
name|evutil_timeradd
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;       \ 		if ((vvp)->tv_usec>= 1000000) {			\ 			(vvp)->tv_sec++;				\ 			(vvp)->tv_usec -= 1000000;			\ 		}							\ 	} while (0)
define|#
directive|define
name|evutil_timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_usec += 1000000;			\ 		}							\ 	} while (0)
endif|#
directive|endif
comment|/* !EVENT__HAVE_TIMERADD */
ifdef|#
directive|ifdef
name|EVENT__HAVE_TIMERCLEAR
define|#
directive|define
name|evutil_timerclear
parameter_list|(
name|tvp
parameter_list|)
value|timerclear(tvp)
else|#
directive|else
define|#
directive|define
name|evutil_timerclear
parameter_list|(
name|tvp
parameter_list|)
value|(tvp)->tv_sec = (tvp)->tv_usec = 0
endif|#
directive|endif
comment|/**@}*/
comment|/** Return true iff the tvp is related to uvp according to the relational  * operator cmp.  Recognized values for cmp are ==,<=,<,>=, and>. */
define|#
directive|define
name|evutil_timercmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?				\ 	 ((tvp)->tv_usec cmp (uvp)->tv_usec) :				\ 	 ((tvp)->tv_sec cmp (uvp)->tv_sec))
ifdef|#
directive|ifdef
name|EVENT__HAVE_TIMERISSET
define|#
directive|define
name|evutil_timerisset
parameter_list|(
name|tvp
parameter_list|)
value|timerisset(tvp)
else|#
directive|else
define|#
directive|define
name|evutil_timerisset
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec || (tvp)->tv_usec)
endif|#
directive|endif
comment|/** Replacement for offsetof on platforms that don't define it. */
ifdef|#
directive|ifdef
name|offsetof
define|#
directive|define
name|evutil_offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|offsetof(type, field)
else|#
directive|else
define|#
directive|define
name|evutil_offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((off_t)(&((type *)0)->field))
endif|#
directive|endif
comment|/* big-int related functions */
comment|/** Parse a 64-bit value from a string.  Arguments are as for strtol. */
name|EVENT2_EXPORT_SYMBOL
name|ev_int64_t
name|evutil_strtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
comment|/** Replacement for gettimeofday on platforms that lack it. */
ifdef|#
directive|ifdef
name|EVENT__HAVE_GETTIMEOFDAY
define|#
directive|define
name|evutil_gettimeofday
parameter_list|(
name|tv
parameter_list|,
name|tz
parameter_list|)
value|gettimeofday((tv), (tz))
else|#
directive|else
struct_decl|struct
name|timezone
struct_decl|;
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_gettimeofday
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
endif|#
directive|endif
comment|/** Replacement for snprintf to get consistent behavior on platforms for     which the return value of snprintf does not conform to C99.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_snprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
block|)
end_extern

begin_endif
unit|))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Replacement for vsnprintf to get consistent behavior on platforms for     which the return value of snprintf does not conform to C99.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_vsnprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Replacement for inet_ntop for platforms which lack it. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
specifier|const
name|char
modifier|*
name|evutil_inet_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Replacement for inet_pton for platforms which lack it. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_inet_pton
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_comment
comment|/** Parse an IPv4 or IPv6 address, with optional port, from a string.      Recognized formats are:     - [IPv6Address]:port     - [IPv6Address]     - IPv6Address     - IPv4Address:port     - IPv4Address      If no port is specified, the port in the output is set to 0.      @param str The string to parse.     @param out A struct sockaddr to hold the result.  This should probably be        a struct sockaddr_storage.     @param outlen A pointer to the number of bytes that that 'out' can safely        hold.  Set to the number of bytes used in 'out' on success.     @return -1 if the address is not well-formed, if the port is out of range,        or if out is not large enough to hold the result.  Otherwise returns        0 on success. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_parse_sockaddr_port
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|out
parameter_list|,
name|int
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Compare two sockaddrs; return 0 if they are equal, or less than 0 if sa1  * preceeds sa2, or greater than 0 if sa1 follows sa2.  If include_port is  * true, consider the port as well as the address.  Only implemented for  * AF_INET and AF_INET6 addresses. The ordering is not guaranteed to remain  * the same between Libevent versions. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_sockaddr_cmp
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa1
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa2
parameter_list|,
name|int
name|include_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** As strcasecmp, but always compares the characters in locale-independent     ASCII.  That's useful if you're handling data in ASCII-based protocols.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_ascii_strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** As strncasecmp, but always compares the characters in locale-independent     ASCII.  That's useful if you're handling data in ASCII-based protocols.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_ascii_strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Here we define evutil_addrinfo to the native addrinfo type, or redefine it  * if this system has no getaddrinfo(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT__HAVE_STRUCT_ADDRINFO
end_ifdef

begin_define
define|#
directive|define
name|evutil_addrinfo
value|addrinfo
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/** A definition of struct addrinfo for systems that lack it.      (This is just an alias for struct addrinfo if the system defines     struct addrinfo.) */
end_comment

begin_struct
struct|struct
name|evutil_addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* canonical name for nodename */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* binary address */
name|struct
name|evutil_addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* next structure in linked list */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** @name evutil_getaddrinfo() error codes      These values are possible error codes for evutil_getaddrinfo() and     related functions.      @{ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_ADDRFAMILY
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_ADDRFAMILY
value|EAI_ADDRFAMILY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_ADDRFAMILY
value|-901
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_AGAIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_AGAIN
value|EAI_AGAIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_AGAIN
value|-902
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_BADFLAGS
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_BADFLAGS
value|EAI_BADFLAGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_BADFLAGS
value|-903
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_FAIL
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_FAIL
value|EAI_FAIL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_FAIL
value|-904
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_FAMILY
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_FAMILY
value|EAI_FAMILY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_FAMILY
value|-905
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_MEMORY
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_MEMORY
value|EAI_MEMORY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_MEMORY
value|-906
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This test is a bit complicated, since some MS SDKs decide to  * remove NODATA or redefine it to be the same as NONAME, in a  * fun interpretation of RFC 2553 and RFC 3493. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_NODATA
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|EAI_NONAME
argument_list|)
operator|||
name|EAI_NODATA
operator|!=
name|EAI_NONAME
operator|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_NODATA
value|EAI_NODATA
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_NODATA
value|-907
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_NONAME
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_NONAME
value|EAI_NONAME
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_NONAME
value|-908
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_SERVICE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_SERVICE
value|EAI_SERVICE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_SERVICE
value|-909
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_SOCKTYPE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_SOCKTYPE
value|EAI_SOCKTYPE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_SOCKTYPE
value|-910
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EAI_SYSTEM
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_EAI_SYSTEM
value|EAI_SYSTEM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_EAI_SYSTEM
value|-911
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EVUTIL_EAI_CANCEL
value|-90001
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_PASSIVE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_PASSIVE
value|AI_PASSIVE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_PASSIVE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_CANONNAME
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_CANONNAME
value|AI_CANONNAME
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_CANONNAME
value|0x2000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_NUMERICHOST
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_NUMERICHOST
value|AI_NUMERICHOST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_NUMERICHOST
value|0x4000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_NUMERICSERV
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_NUMERICSERV
value|AI_NUMERICSERV
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_NUMERICSERV
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_V4MAPPED
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_V4MAPPED
value|AI_V4MAPPED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_V4MAPPED
value|0x10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_ALL
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_ALL
value|AI_ALL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_ALL
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_ADDRCONFIG
argument_list|)
operator|&&
name|defined
argument_list|(
name|EVENT__HAVE_GETADDRINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVUTIL_AI_ADDRCONFIG
value|AI_ADDRCONFIG
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVUTIL_AI_ADDRCONFIG
value|0x40000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**@}*/
end_comment

begin_struct_decl
struct_decl|struct
name|evutil_addrinfo
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * This function clones getaddrinfo for systems that don't have it.  For full  * details, see RFC 3493, section 6.1.  *  * Limitations:  * - When the system has no getaddrinfo, we fall back to gethostbyname_r or  *   gethostbyname, with their attendant issues.  * - The AI_V4MAPPED and AI_ALL flags are not currently implemented.  *  * For a nonblocking variant, see evdns_getaddrinfo.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|nodename
parameter_list|,
specifier|const
name|char
modifier|*
name|servname
parameter_list|,
specifier|const
name|struct
name|evutil_addrinfo
modifier|*
name|hints_in
parameter_list|,
name|struct
name|evutil_addrinfo
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Release storage allocated by evutil_getaddrinfo or evdns_getaddrinfo. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|void
name|evutil_freeaddrinfo
parameter_list|(
name|struct
name|evutil_addrinfo
modifier|*
name|ai
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
specifier|const
name|char
modifier|*
name|evutil_gai_strerror
parameter_list|(
name|int
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Generate n bytes of secure pseudorandom data, and store them in buf.  *  * Current versions of Libevent use an ARC4-based random number generator,  * seeded using the platform's entropy source (/dev/urandom on Unix-like  * systems; CryptGenRandom on Windows).  This is not actually as secure as it  * should be: ARC4 is a pretty lousy cipher, and the current implementation  * provides only rudimentary prediction- and backtracking-resistance.  Don't  * use this for serious cryptographic applications.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|void
name|evutil_secure_rng_get_bytes
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Seed the secure random number generator if needed, and return 0 on  * success or -1 on failure.  *  * It is okay to call this function more than once; it will still return  * 0 if the RNG has been successfully seeded and -1 if it can't be  * seeded.  *  * Ordinarily you don't need to call this function from your own code;  * Libevent will seed the RNG itself the first time it needs good random  * numbers.  You only need to call it if (a) you want to double-check  * that one of the seeding methods did succeed, or (b) you plan to drop  * the capability to seed (by chrooting, or dropping capabilities, or  * whatever), and you want to make sure that seeding happens before your  * program loses the ability to do it.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_secure_rng_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set a filename to use in place of /dev/urandom for seeding the secure  * PRNG. Return 0 on success, -1 on failure.  *  * Call this function BEFORE calling any other initialization or RNG  * functions.  *  * (This string will _NOT_ be copied internally. Do not free it while any  * user of the secure RNG might be running. Don't pass anything other than a  * real /dev/...random device file here, or you might lose security.)  *  * This API is unstable, and might change in a future libevent version.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evutil_secure_rng_set_urandom_device_file
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Seed the random number generator with extra random bytes.      You should almost never need to call this function; it should be     sufficient to invoke evutil_secure_rng_init(), or let Libevent take     care of calling evutil_secure_rng_init() on its own.      If you call this function as a _replacement_ for the regular     entropy sources, then you need to be sure that your input     contains a fairly large amount of strong entropy.  Doing so is     notoriously hard: most people who try get it wrong.  Watch out!      @param dat a buffer full of a strong source of random numbers     @param datlen the number of bytes to read from datlen  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|void
name|evutil_secure_rng_add_bytes
parameter_list|(
specifier|const
name|char
modifier|*
name|dat
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT1_EVUTIL_H_INCLUDED_ */
end_comment

end_unit

