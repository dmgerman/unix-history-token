begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_H
end_ifndef

begin_define
define|#
directive|define
name|APR_H
end_define

begin_comment
comment|/* GENERATED FILE WARNING!  DO NOT EDIT apr.h  *  * You must modify apr.h.in instead.  *  * And please, make an effort to stub apr.hw and apr.hnw in the process.  */
end_comment

begin_comment
comment|/**  * @file apr.h  * @brief APR Platform Definitions  * @remark This is a generated header generated from include/apr.h.in by  * ./configure, or copied from include/apr.hw or include/apr.hnw   * for Win32 or Netware by those build environments, respectively.  */
end_comment

begin_comment
comment|/**  * @defgroup APR Apache Portability Runtime library  * @{  */
end_comment

begin_comment
comment|/**  * @defgroup apr_platform Platform Definitions  * @{  * @warning  *<strong><em>The actual values of macros and typedefs on this page<br>  * are platform specific and should NOT be relied upon!</em></strong>  */
end_comment

begin_comment
comment|/* So that we can use inline on some critical functions, and use  * GNUC attributes (such as to get -Wall warnings for printf-like  * functions).  Only do this in gcc 2.7 or later ... it may work  * on earlier stuff, but why chance it.  *  * We've since discovered that the gcc shipped with NeXT systems  * as "cc" is completely broken.  It claims to be __GNUC__ and so  * on, but it doesn't implement half of the things that __GNUC__  * means.  In particular it's missing inline and the __attribute__  * stuff.  So we hack around it.  PR#1613. -djg  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|<
literal|2
operator|||
expr|\
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|NEXT
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|__x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|APR_INLINE
end_define

begin_define
define|#
directive|define
name|APR_HAS_INLINE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APR_INLINE
value|__inline__
end_define

begin_define
define|#
directive|define
name|APR_HAS_INLINE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|APR_HAVE_ARPA_INET_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_CONIO_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_CRYPT_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_CTYPE_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_DIRENT_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_IO_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_NETDB_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_NETINET_IN_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_NETINET_SCTP_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_NETINET_SCTP_UIO_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_NETINET_TCP_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_PROCESS_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_PTHREAD_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SEMAPHORE_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SIGNAL_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STDARG_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STDIO_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_IOCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_SENDFILE_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_SIGNAL_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_SOCKET_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_SOCKIO_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_SYSLIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_UIO_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_UN_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_SYS_WAIT_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|APR_HAVE_WINDOWS_H
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAVE_WINSOCK2_H
value|0
end_define

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* We don't include our conditional headers within the doxyblocks   * or the extern "C" namespace   */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_WINDOWS_H
operator|&&
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/* If windows.h was already included, our preferences don't matter.  * If not, include a restricted set of windows headers to our tastes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINDOWS_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32_LEAN_AND_MEAN
end_ifndef

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WINNT
end_ifndef

begin_comment
comment|/* Restrict the server to a subset of Windows XP header files by default  */
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0501
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOUSER
end_ifndef

begin_define
define|#
directive|define
name|NOUSER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOMCX
end_ifndef

begin_define
define|#
directive|define
name|NOMCX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOIME
end_ifndef

begin_define
define|#
directive|define
name|NOIME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/*   * Add a _very_few_ declarations missing from the restricted set of headers  * (If this list becomes extensive, re-enable the required headers above!)  * winsock headers were excluded by WIN32_LEAN_AND_MEAN, so include them now  */
end_comment

begin_define
define|#
directive|define
name|SW_HIDE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_include
include|#
directive|include
file|<mswsock.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<winsock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _WINDOWS_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAVE_WINDOWS_H */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_SOCKET_H
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_comment
comment|/* C99 7.18.4 requires that stdint.h only exposes INT64_C   * and UINT64_C for C++ implementations if this is defined: */
end_comment

begin_define
define|#
directive|define
name|__STDC_CONSTANT_MACROS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_WAIT_H
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|INCL_DOS
end_define

begin_define
define|#
directive|define
name|INCL_DOSERRORS
end_define

begin_include
include|#
directive|include
file|<os2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* header files for PATH_MAX, _POSIX_PATH_MAX */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|APR_HAVE_SYS_SYSLIMITS_H
end_if

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @addtogroup apr_platform  * @ingroup APR   * @{  */
define|#
directive|define
name|APR_HAVE_SHMEM_MMAP_TMP
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_MMAP_SHM
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_MMAP_ZERO
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_SHMGET_ANON
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_SHMGET
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_MMAP_ANON
value|1
define|#
directive|define
name|APR_HAVE_SHMEM_BEOS
value|0
define|#
directive|define
name|APR_USE_SHMEM_MMAP_TMP
value|0
define|#
directive|define
name|APR_USE_SHMEM_MMAP_SHM
value|0
define|#
directive|define
name|APR_USE_SHMEM_MMAP_ZERO
value|0
define|#
directive|define
name|APR_USE_SHMEM_SHMGET_ANON
value|0
define|#
directive|define
name|APR_USE_SHMEM_SHMGET
value|1
define|#
directive|define
name|APR_USE_SHMEM_MMAP_ANON
value|1
define|#
directive|define
name|APR_USE_SHMEM_BEOS
value|0
define|#
directive|define
name|APR_USE_FLOCK_SERIALIZE
value|1
define|#
directive|define
name|APR_USE_SYSVSEM_SERIALIZE
value|0
define|#
directive|define
name|APR_USE_POSIXSEM_SERIALIZE
value|0
define|#
directive|define
name|APR_USE_FCNTL_SERIALIZE
value|0
define|#
directive|define
name|APR_USE_PROC_PTHREAD_SERIALIZE
value|0
define|#
directive|define
name|APR_USE_PTHREAD_SERIALIZE
value|1
define|#
directive|define
name|APR_HAS_FLOCK_SERIALIZE
value|1
define|#
directive|define
name|APR_HAS_SYSVSEM_SERIALIZE
value|1
define|#
directive|define
name|APR_HAS_POSIXSEM_SERIALIZE
value|1
define|#
directive|define
name|APR_HAS_FCNTL_SERIALIZE
value|1
define|#
directive|define
name|APR_HAS_PROC_PTHREAD_SERIALIZE
value|0
define|#
directive|define
name|APR_PROCESS_LOCK_IS_GLOBAL
value|0
define|#
directive|define
name|APR_HAVE_CORKABLE_TCP
value|1
define|#
directive|define
name|APR_HAVE_GETRLIMIT
value|1
define|#
directive|define
name|APR_HAVE_IN_ADDR
value|1
define|#
directive|define
name|APR_HAVE_INET_ADDR
value|1
define|#
directive|define
name|APR_HAVE_INET_NETWORK
value|1
define|#
directive|define
name|APR_HAVE_IPV6
value|1
define|#
directive|define
name|APR_HAVE_MEMMOVE
value|1
define|#
directive|define
name|APR_HAVE_SETRLIMIT
value|1
define|#
directive|define
name|APR_HAVE_SIGACTION
value|1
define|#
directive|define
name|APR_HAVE_SIGSUSPEND
value|1
define|#
directive|define
name|APR_HAVE_SIGWAIT
value|1
define|#
directive|define
name|APR_HAVE_SA_STORAGE
value|1
define|#
directive|define
name|APR_HAVE_STRCASECMP
value|1
define|#
directive|define
name|APR_HAVE_STRDUP
value|1
define|#
directive|define
name|APR_HAVE_STRICMP
value|0
define|#
directive|define
name|APR_HAVE_STRNCASECMP
value|1
define|#
directive|define
name|APR_HAVE_STRNICMP
value|0
define|#
directive|define
name|APR_HAVE_STRSTR
value|1
define|#
directive|define
name|APR_HAVE_MEMCHR
value|1
define|#
directive|define
name|APR_HAVE_STRUCT_RLIMIT
value|1
define|#
directive|define
name|APR_HAVE_UNION_SEMUN
value|1
define|#
directive|define
name|APR_HAVE_SCTP
value|1
define|#
directive|define
name|APR_HAVE_IOVEC
value|1
comment|/*  APR Feature Macros */
define|#
directive|define
name|APR_HAS_SHARED_MEMORY
value|1
define|#
directive|define
name|APR_HAS_THREADS
value|1
define|#
directive|define
name|APR_HAS_SENDFILE
value|1
define|#
directive|define
name|APR_HAS_MMAP
value|1
define|#
directive|define
name|APR_HAS_FORK
value|1
define|#
directive|define
name|APR_HAS_RANDOM
value|1
define|#
directive|define
name|APR_HAS_OTHER_CHILD
value|1
define|#
directive|define
name|APR_HAS_DSO
value|0
define|#
directive|define
name|APR_HAS_SO_ACCEPTFILTER
value|1
define|#
directive|define
name|APR_HAS_UNICODE_FS
value|0
define|#
directive|define
name|APR_HAS_PROC_INVOKED
value|0
define|#
directive|define
name|APR_HAS_USER
value|1
define|#
directive|define
name|APR_HAS_LARGE_FILES
value|0
define|#
directive|define
name|APR_HAS_XTHREAD_FILES
value|0
define|#
directive|define
name|APR_HAS_OS_UUID
value|1
define|#
directive|define
name|APR_PROCATTR_USER_SET_REQUIRES_PASSWORD
value|0
comment|/* APR sets APR_FILES_AS_SOCKETS to 1 on systems where it is possible  * to poll on files/pipes.  */
define|#
directive|define
name|APR_FILES_AS_SOCKETS
value|1
comment|/* This macro indicates whether or not EBCDIC is the native character set.  */
define|#
directive|define
name|APR_CHARSET_EBCDIC
value|0
comment|/* If we have a TCP implementation that can be "corked", what flag  * do we use?  */
define|#
directive|define
name|APR_TCP_NOPUSH_FLAG
value|TCP_NOPUSH
comment|/* Is the TCP_NODELAY socket option inherited from listening sockets? */
define|#
directive|define
name|APR_TCP_NODELAY_INHERITED
value|1
comment|/* Is the O_NONBLOCK flag inherited from listening sockets? */
define|#
directive|define
name|APR_O_NONBLOCK_INHERITED
value|1
comment|/* Typedefs that APR needs. */
typedef|typedef
name|unsigned
name|char
name|apr_byte_t
typedef|;
typedef|typedef
name|short
name|apr_int16_t
typedef|;
typedef|typedef
name|unsigned
name|short
name|apr_uint16_t
typedef|;
typedef|typedef
name|int
name|apr_int32_t
typedef|;
typedef|typedef
name|unsigned
name|int
name|apr_uint32_t
typedef|;
include|#
directive|include
file|<sys/_types.h>
ifdef|#
directive|ifdef
name|__LP64__
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|8
else|#
directive|else
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|4
endif|#
directive|endif
comment|/*  * Darwin 10's default compiler (gcc42) builds for both 64 and  * 32 bit architectures unless specifically told not to.  * In those cases, we need to override types depending on how  * we're being built at compile time.  * NOTE: This is an ugly work-around for Darwin's  * concept of universal binaries, a single package  * (executable, lib, etc...) which contains both 32  * and 64 bit versions. The issue is that if APR is  * built universally, if something else is compiled  * against it, some bit sizes will depend on whether  * it is 32 or 64 bit. This is determined by the __LP64__  * flag. Since we need to support both, we have to  * handle OS X unqiuely.  */
ifdef|#
directive|ifdef
name|DARWIN_10
undef|#
directive|undef
name|APR_SIZEOF_VOIDP
undef|#
directive|undef
name|INT64_C
undef|#
directive|undef
name|UINT64_C
ifdef|#
directive|ifdef
name|__LP64__
typedef|typedef
name|long
name|apr_int64_t
typedef|;
typedef|typedef
name|unsigned
name|long
name|apr_uint64_t
typedef|;
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|8
define|#
directive|define
name|INT64_C
parameter_list|(
name|v
parameter_list|)
value|(v ## L)
define|#
directive|define
name|UINT64_C
parameter_list|(
name|v
parameter_list|)
value|(v ## UL)
else|#
directive|else
typedef|typedef
name|long
name|long
name|apr_int64_t
typedef|;
typedef|typedef
name|unsigned
name|long
name|long
name|apr_uint64_t
typedef|;
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|4
define|#
directive|define
name|INT64_C
parameter_list|(
name|v
parameter_list|)
value|(v ## LL)
define|#
directive|define
name|UINT64_C
parameter_list|(
name|v
parameter_list|)
value|(v ## ULL)
endif|#
directive|endif
else|#
directive|else
typedef|typedef
name|__int64_t
name|apr_int64_t
typedef|;
typedef|typedef
name|__uint64_t
name|apr_uint64_t
typedef|;
endif|#
directive|endif
typedef|typedef
name|size_t
name|apr_size_t
typedef|;
typedef|typedef
name|ssize_t
name|apr_ssize_t
typedef|;
typedef|typedef
name|off_t
name|apr_off_t
typedef|;
typedef|typedef
name|socklen_t
name|apr_socklen_t
typedef|;
typedef|typedef
name|unsigned
name|int
name|apr_ino_t
typedef|;
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|8
typedef|typedef
name|apr_uint64_t
name|apr_uintptr_t
typedef|;
else|#
directive|else
typedef|typedef
name|apr_uint32_t
name|apr_uintptr_t
typedef|;
endif|#
directive|endif
comment|/* Are we big endian? */
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
define|#
directive|define
name|APR_IS_BIGENDIAN
value|0
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
define|#
directive|define
name|APR_IS_BIGENDIAN
value|1
else|#
directive|else
error|#
directive|error
error|Unknown byte order.
endif|#
directive|endif
comment|/* Mechanisms to properly type numeric literals */
define|#
directive|define
name|APR_INT64_C
parameter_list|(
name|val
parameter_list|)
value|INT64_C(val)
define|#
directive|define
name|APR_UINT64_C
parameter_list|(
name|val
parameter_list|)
value|UINT64_C(val)
ifdef|#
directive|ifdef
name|INT16_MIN
define|#
directive|define
name|APR_INT16_MIN
value|INT16_MIN
else|#
directive|else
define|#
directive|define
name|APR_INT16_MIN
value|(-0x7fff - 1)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INT16_MAX
define|#
directive|define
name|APR_INT16_MAX
value|INT16_MAX
else|#
directive|else
define|#
directive|define
name|APR_INT16_MAX
value|(0x7fff)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UINT16_MAX
define|#
directive|define
name|APR_UINT16_MAX
value|UINT16_MAX
else|#
directive|else
define|#
directive|define
name|APR_UINT16_MAX
value|(0xffff)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INT32_MIN
define|#
directive|define
name|APR_INT32_MIN
value|INT32_MIN
else|#
directive|else
define|#
directive|define
name|APR_INT32_MIN
value|(-0x7fffffff - 1)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INT32_MAX
define|#
directive|define
name|APR_INT32_MAX
value|INT32_MAX
else|#
directive|else
define|#
directive|define
name|APR_INT32_MAX
value|0x7fffffff
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UINT32_MAX
define|#
directive|define
name|APR_UINT32_MAX
value|UINT32_MAX
else|#
directive|else
define|#
directive|define
name|APR_UINT32_MAX
value|(0xffffffffU)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INT64_MIN
define|#
directive|define
name|APR_INT64_MIN
value|INT64_MIN
else|#
directive|else
define|#
directive|define
name|APR_INT64_MIN
value|(APR_INT64_C(-0x7fffffffffffffff) - 1)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INT64_MAX
define|#
directive|define
name|APR_INT64_MAX
value|INT64_MAX
else|#
directive|else
define|#
directive|define
name|APR_INT64_MAX
value|APR_INT64_C(0x7fffffffffffffff)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UINT64_MAX
define|#
directive|define
name|APR_UINT64_MAX
value|UINT64_MAX
else|#
directive|else
define|#
directive|define
name|APR_UINT64_MAX
value|APR_UINT64_C(0xffffffffffffffff)
endif|#
directive|endif
define|#
directive|define
name|APR_SIZE_MAX
value|(~((apr_size_t)0))
comment|/* Definitions that APR programs need to work properly. */
comment|/**  * APR public API wrap for C++ compilers.  */
ifdef|#
directive|ifdef
name|__cplusplus
define|#
directive|define
name|APR_BEGIN_DECLS
value|extern "C" {
define|#
directive|define
name|APR_END_DECLS
value|}
else|#
directive|else
define|#
directive|define
name|APR_BEGIN_DECLS
define|#
directive|define
name|APR_END_DECLS
endif|#
directive|endif
comment|/**   * Thread callbacks from APR functions must be declared with APR_THREAD_FUNC,   * so that they follow the platform's calling convention.  *<PRE>  *  * void* APR_THREAD_FUNC my_thread_entry_fn(apr_thread_t *thd, void *data);  *  *</PRE>  */
define|#
directive|define
name|APR_THREAD_FUNC
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
comment|/**  * The public APR functions are declared with APR_DECLARE(), so they may  * use the most appropriate calling convention.  Public APR functions with   * variable arguments must use APR_DECLARE_NONSTD().  *  * @remark Both the declaration and implementations must use the same macro.  *  *<PRE>  * APR_DECLARE(rettype) apr_func(args)  *</PRE>  * @see APR_DECLARE_NONSTD @see APR_DECLARE_DATA  * @remark Note that when APR compiles the library itself, it passes the   * symbol -DAPR_DECLARE_EXPORT to the compiler on some platforms (e.g. Win32)   * to export public symbols from the dynamic library build.\n  * The user must define the APR_DECLARE_STATIC when compiling to target  * the static APR library on some platforms (e.g. Win32.)  The public symbols   * are neither exported nor imported when APR_DECLARE_STATIC is defined.\n  * By default, compiling an application and including the APR public  * headers, without defining APR_DECLARE_STATIC, will prepare the code to be  * linked to the dynamic library.  */
define|#
directive|define
name|APR_DECLARE
parameter_list|(
name|type
parameter_list|)
value|type
comment|/**  * The public APR functions using variable arguments are declared with   * APR_DECLARE_NONSTD(), as they must follow the C language calling convention.  * @see APR_DECLARE @see APR_DECLARE_DATA  * @remark Both the declaration and implementations must use the same macro.  *<PRE>  *  * APR_DECLARE_NONSTD(rettype) apr_func(args, ...);  *  *</PRE>  */
define|#
directive|define
name|APR_DECLARE_NONSTD
parameter_list|(
name|type
parameter_list|)
value|type
comment|/**  * The public APR variables are declared with AP_MODULE_DECLARE_DATA.  * This assures the appropriate indirection is invoked at compile time.  * @see APR_DECLARE @see APR_DECLARE_NONSTD  * @remark Note that the declaration and implementations use different forms,  * but both must include the macro.  *   *<PRE>  *  * extern APR_DECLARE_DATA type apr_variable;\n  * APR_DECLARE_DATA type apr_variable = value;  *  *</PRE>  */
define|#
directive|define
name|APR_DECLARE_DATA
elif|#
directive|elif
name|defined
argument_list|(
name|APR_DECLARE_STATIC
argument_list|)
define|#
directive|define
name|APR_DECLARE
parameter_list|(
name|type
parameter_list|)
value|type __stdcall
define|#
directive|define
name|APR_DECLARE_NONSTD
parameter_list|(
name|type
parameter_list|)
value|type __cdecl
define|#
directive|define
name|APR_DECLARE_DATA
elif|#
directive|elif
name|defined
argument_list|(
name|APR_DECLARE_EXPORT
argument_list|)
define|#
directive|define
name|APR_DECLARE
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllexport) type __stdcall
define|#
directive|define
name|APR_DECLARE_NONSTD
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllexport) type __cdecl
define|#
directive|define
name|APR_DECLARE_DATA
value|__declspec(dllexport)
else|#
directive|else
define|#
directive|define
name|APR_DECLARE
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllimport) type __stdcall
define|#
directive|define
name|APR_DECLARE_NONSTD
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllimport) type __cdecl
define|#
directive|define
name|APR_DECLARE_DATA
value|__declspec(dllimport)
endif|#
directive|endif
comment|/* Define APR_SSIZE_T_FMT.    * If ssize_t is an integer we define it to be "d",  * if ssize_t is a long int we define it to be "ld",  * if ssize_t is neither we declare an error here.  * I looked for a better way to define this here, but couldn't find one, so  * to find the logic for this definition search for "ssize_t_fmt" in  * configure.in.  */
ifdef|#
directive|ifdef
name|__LP64__
define|#
directive|define
name|APR_SSIZE_T_FMT
value|"ld"
comment|/* And APR_SIZE_T_FMT */
define|#
directive|define
name|APR_SIZE_T_FMT
value|"lu"
comment|/* And APR_OFF_T_FMT */
define|#
directive|define
name|APR_OFF_T_FMT
value|"ld"
comment|/* And APR_PID_T_FMT */
define|#
directive|define
name|APR_PID_T_FMT
value|"d"
comment|/* And APR_INT64_T_FMT */
define|#
directive|define
name|APR_INT64_T_FMT
value|"ld"
comment|/* And APR_UINT64_T_FMT */
define|#
directive|define
name|APR_UINT64_T_FMT
value|"lu"
comment|/* And APR_UINT64_T_HEX_FMT */
define|#
directive|define
name|APR_UINT64_T_HEX_FMT
value|"lx"
else|#
directive|else
define|#
directive|define
name|APR_SSIZE_T_FMT
value|"d"
define|#
directive|define
name|APR_SIZE_T_FMT
value|"u"
define|#
directive|define
name|APR_OFF_T_FMT
value|APR_INT64_T_FMT
define|#
directive|define
name|APR_PID_T_FMT
value|"d"
define|#
directive|define
name|APR_INT64_T_FMT
value|"lld"
define|#
directive|define
name|APR_UINT64_T_FMT
value|"llu"
define|#
directive|define
name|APR_UINT64_T_HEX_FMT
value|"llx"
endif|#
directive|endif
comment|/*  * Ensure we work with universal binaries on Darwin  */
ifdef|#
directive|ifdef
name|DARWIN_10
undef|#
directive|undef
name|APR_HAS_LARGE_FILES
undef|#
directive|undef
name|APR_SIZEOF_VOIDP
undef|#
directive|undef
name|APR_INT64_T_FMT
undef|#
directive|undef
name|APR_UINT64_T_FMT
undef|#
directive|undef
name|APR_UINT64_T_HEX_FMT
ifdef|#
directive|ifdef
name|__LP64__
define|#
directive|define
name|APR_HAS_LARGE_FILES
value|0
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|8
define|#
directive|define
name|APR_INT64_T_FMT
value|"ld"
define|#
directive|define
name|APR_UINT64_T_FMT
value|"lu"
define|#
directive|define
name|APR_UINT64_T_HEX_FMT
value|"lx"
else|#
directive|else
define|#
directive|define
name|APR_HAS_LARGE_FILES
value|1
define|#
directive|define
name|APR_SIZEOF_VOIDP
value|4
define|#
directive|define
name|APR_INT64_T_FMT
value|"lld"
define|#
directive|define
name|APR_UINT64_T_FMT
value|"llu"
define|#
directive|define
name|APR_UINT64_T_HEX_FMT
value|"llx"
endif|#
directive|endif
undef|#
directive|undef
name|APR_IS_BIGENDIAN
ifdef|#
directive|ifdef
name|__BIG_ENDIAN__
define|#
directive|define
name|APR_IS_BIGENDIAN
value|1
else|#
directive|else
define|#
directive|define
name|APR_IS_BIGENDIAN
value|0
endif|#
directive|endif
undef|#
directive|undef
name|APR_OFF_T_FMT
define|#
directive|define
name|APR_OFF_T_FMT
value|"lld"
endif|#
directive|endif
comment|/* DARWIN_10 */
comment|/* Does the proc mutex lock threads too */
define|#
directive|define
name|APR_PROC_MUTEX_IS_GLOBAL
value|0
comment|/* Local machine definition for console and log output. */
define|#
directive|define
name|APR_EOL_STR
value|"\n"
if|#
directive|if
name|APR_HAVE_SYS_WAIT_H
ifdef|#
directive|ifdef
name|WEXITSTATUS
define|#
directive|define
name|apr_wait_t
value|int
else|#
directive|else
define|#
directive|define
name|apr_wait_t
value|union wait
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|status
parameter_list|)
value|(int)((status).w_retcode)
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|status
parameter_list|)
value|(int)((status).w_termsig)
endif|#
directive|endif
comment|/* !WEXITSTATUS */
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
typedef|typedef
name|int
name|apr_wait_t
typedef|;
endif|#
directive|endif
comment|/* HAVE_SYS_WAIT_H */
if|#
directive|if
name|defined
argument_list|(
name|PATH_MAX
argument_list|)
define|#
directive|define
name|APR_PATH_MAX
value|PATH_MAX
elif|#
directive|elif
name|defined
argument_list|(
name|_POSIX_PATH_MAX
argument_list|)
define|#
directive|define
name|APR_PATH_MAX
value|_POSIX_PATH_MAX
else|#
directive|else
error|#
directive|error
error|no decision has been made on APR_PATH_MAX for your platform
endif|#
directive|endif
define|#
directive|define
name|APR_DSOPATH
value|"LD_LIBRARY_PATH"
comment|/** @} */
comment|/* Definitions that only Win32 programs need to compile properly. */
comment|/* XXX These simply don't belong here, perhaps in apr_portable.h  * based on some APR_HAVE_PID/GID/UID?  */
ifdef|#
directive|ifdef
name|__MINGW32__
ifndef|#
directive|ifndef
name|__GNUC__
typedef|typedef
name|int
name|pid_t
typedef|;
endif|#
directive|endif
typedef|typedef
name|int
name|uid_t
typedef|;
typedef|typedef
name|int
name|gid_t
typedef|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_H */
end_comment

end_unit

