begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2003  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Include the appropriate OS header files on Windows and various flavors  * of UNIX, include various non-OS header files on Windows, and define  * various items as needed, to isolate most of tcpdump's platform  * differences to this one file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tcpdump_stdinc_h
end_ifndef

begin_define
define|#
directive|define
name|tcpdump_stdinc_h
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|"bittypes.h"
end_include

begin_comment
comment|/* in wpcap's Win32/include */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/netdb.h>
end_include

begin_comment
comment|/* in wpcap's Win32/include */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|uint8_t
end_ifndef

begin_define
define|#
directive|define
name|uint8_t
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|int8_t
end_ifndef

begin_define
define|#
directive|define
name|int8_t
value|signed char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|uint16_t
end_ifndef

begin_define
define|#
directive|define
name|uint16_t
value|unsigned short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|int16_t
end_ifndef

begin_define
define|#
directive|define
name|int16_t
value|signed short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|uint32_t
end_ifndef

begin_define
define|#
directive|define
name|uint32_t
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|int32_t
end_ifndef

begin_define
define|#
directive|define
name|int32_t
value|signed int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_EXTENSIONS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|uint64_t
end_ifndef

begin_define
define|#
directive|define
name|uint64_t
value|unsigned _int64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|int64_t
end_ifndef

begin_define
define|#
directive|define
name|int64_t
value|_int64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRId64
end_ifndef

begin_define
define|#
directive|define
name|PRId64
value|"I64d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIo64
end_ifndef

begin_define
define|#
directive|define
name|PRIo64
value|"I64o"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu64
end_ifndef

begin_define
define|#
directive|define
name|PRIu64
value|"I64u"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx64
end_ifndef

begin_define
define|#
directive|define
name|PRIx64
value|"I64x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _MSC_EXTENSIONS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|uint64_t
end_ifndef

begin_define
define|#
directive|define
name|uint64_t
value|unsigned long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|int64_t
end_ifndef

begin_define
define|#
directive|define
name|int64_t
value|long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRId64
end_ifndef

begin_define
define|#
directive|define
name|PRId64
value|"lld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIo64
end_ifndef

begin_define
define|#
directive|define
name|PRIo64
value|"llo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu64
end_ifndef

begin_define
define|#
directive|define
name|PRIu64
value|"llu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx64
end_ifndef

begin_define
define|#
directive|define
name|PRIx64
value|"llx"
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
comment|/* _MSC_EXTENSIONS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|stat
value|_stat
end_define

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|fstat
value|_fstat
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_comment
comment|/* Protos for missing/x.c functions (ideally<missing/addrinfo.h>  * should be used, but it clashes with<ws2tcpip.h>).  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inet_pton
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * With MSVC, for C, __inline is used to make a function an inline.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* It is in MSVC's<errno.h>, but not defined in MingW+Watcom.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAFNOSUPPORT
end_ifndef

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|WSAEAFNOSUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|caddr_t
end_ifndef

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* caddr_t */
end_comment

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_define
define|#
directive|define
name|vsnprintf
value|_vsnprintf
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WIN32 */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_elif
elif|#
directive|elif
name|HAVE_STDINT_H
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* concession to AIX */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Used to declare a structure unaligned, so that the C compiler,  * if necessary, generates code that doesn't assume alignment.  * This is required because there is no guarantee that the packet  * data we get from libpcap/WinPcap is properly aligned.  *  * This assumes that, for all compilers that support __attribute__:  *  *	1) they support __attribute__((packed));  *  *	2) for all instruction set architectures requiring strict  *	   alignment, declaring a structure with that attribute  *	   causes the compiler to generate code that handles  *	   misaligned 2-byte, 4-byte, and 8-byte integral  *	   quantities.  *  * It does not (yet) handle compilers where you can get the compiler  * to generate code of that sort by some other means.  *  * This is required in order to, for example, keep the compiler from  * generating, for  *  *	if (bp->bp_htype == 1&& bp->bp_hlen == 6&& bp->bp_op == BOOTPREQUEST) {  *  * in print-bootp.c, code that loads the first 4-byte word of a  * "struct bootp", masking out the bp_hops field, and comparing the result  * against 0x01010600.  *  * Note: this also requires that padding be put into the structure,  * at least for compilers where it's implemented as __attribute__((packed)).  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|UNALIGNED
argument_list|)
operator|)
end_if

begin_comment
comment|/* MSVC may have its own macro defined with the same name and purpose. */
end_comment

begin_undef
undef|#
directive|undef
name|UNALIGNED
end_undef

begin_define
define|#
directive|define
name|UNALIGNED
value|__attribute__((packed))
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
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FOPEN_READ_TXT
value|"rt"
end_define

begin_define
define|#
directive|define
name|FOPEN_READ_BIN
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_TXT
value|"wt"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_BIN
value|"wb"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FOPEN_READ_TXT
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_READ_BIN
value|FOPEN_READ_TXT
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_TXT
value|"w"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_BIN
value|FOPEN_WRITE_TXT
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
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ntohl
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|ntohl
end_undef

begin_undef
undef|#
directive|undef
name|ntohs
end_undef

begin_undef
undef|#
directive|undef
name|htonl
end_undef

begin_undef
undef|#
directive|undef
name|htons
end_undef

begin_function_decl
specifier|static
name|__inline__
name|unsigned
name|long
name|__ntohl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline__
name|unsigned
name|short
name|__ntohs
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|__ntohl(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|__ntohs(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|__ntohl(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|__ntohs(x)
end_define

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|__ntohl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
asm|__asm__ ("xchgb %b0, %h0\n\t"
comment|/* swap lower bytes  */
asm|"rorl  $16, %0\n\t"
comment|/* swap words        */
asm|"xchgb %b0, %h0"
comment|/* swap higher bytes */
asm|: "=q" (x) : "0" (x));
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|short
name|__ntohs
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|)
block|{
asm|__asm__ ("xchgb %b0, %h0"
comment|/* swap bytes */
asm|: "=q" (x) : "0" (x));
return|return
operator|(
name|x
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
name|INET_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET_ADDRSTRLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The Apple deprecation workaround macros below were adopted from the  * FreeRADIUS server code under permission of Alan DeKok and Arran Cudbard-Bell.  */
end_comment

begin_define
define|#
directive|define
name|XSTRINGIFY
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_comment
comment|/*  *	Macros for controlling warnings in GCC>= 4.2 and clang>= 2.8  */
end_comment

begin_define
define|#
directive|define
name|DIAG_JOINSTR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|XSTRINGIFY(x ## y)
end_define

begin_define
define|#
directive|define
name|DIAG_DO_PRAGMA
parameter_list|(
name|x
parameter_list|)
value|_Pragma (#x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
operator|(
name|__GNUC__
operator|*
literal|100
operator|)
operator|+
name|__GNUC_MINOR__
operator|)
operator|>=
literal|402
end_if

begin_define
define|#
directive|define
name|DIAG_PRAGMA
parameter_list|(
name|x
parameter_list|)
value|DIAG_DO_PRAGMA(GCC diagnostic x)
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|__GNUC__
operator|*
literal|100
operator|)
operator|+
name|__GNUC_MINOR__
operator|)
operator|>=
literal|406
end_if

begin_define
define|#
directive|define
name|DIAG_OFF
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(push) DIAG_PRAGMA(ignored DIAG_JOINSTR(-W,x))
end_define

begin_define
define|#
directive|define
name|DIAG_ON
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(pop)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIAG_OFF
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(ignored DIAG_JOINSTR(-W,x))
end_define

begin_define
define|#
directive|define
name|DIAG_ON
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(warning DIAG_JOINSTR(-W,x))
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
name|__clang__
argument_list|)
operator|&&
operator|(
operator|(
name|__clang_major__
operator|*
literal|100
operator|)
operator|+
name|__clang_minor__
operator|>=
literal|208
operator|)
end_elif

begin_define
define|#
directive|define
name|DIAG_PRAGMA
parameter_list|(
name|x
parameter_list|)
value|DIAG_DO_PRAGMA(clang diagnostic x)
end_define

begin_define
define|#
directive|define
name|DIAG_OFF
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(push) DIAG_PRAGMA(ignored DIAG_JOINSTR(-W,x))
end_define

begin_define
define|#
directive|define
name|DIAG_ON
parameter_list|(
name|x
parameter_list|)
value|DIAG_PRAGMA(pop)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIAG_OFF
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DIAG_ON
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	For dealing with APIs which are only deprecated in OSX (like the OpenSSL API)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|USES_APPLE_DEPRECATED_API
value|DIAG_OFF(deprecated-declarations)
end_define

begin_define
define|#
directive|define
name|USES_APPLE_RST
value|DIAG_ON(deprecated-declarations)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USES_APPLE_DEPRECATED_API
end_define

begin_define
define|#
directive|define
name|USES_APPLE_RST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * end of Apple deprecation workaround macros  */
end_comment

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
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b)>(a)?(b):(a))
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
comment|/* tcpdump_stdinc_h */
end_comment

end_unit

