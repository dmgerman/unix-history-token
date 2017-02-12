begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2003  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SOCKUTILS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SOCKUTILS_H__
end_define

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1000
end_if

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_comment
comment|/* Windows */
end_comment

begin_comment
comment|/*    * Prevents a compiler warning in case this was already defined (to    * avoid that windows.h includes winsock.h)    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WINSOCKAPI_
end_ifdef

begin_undef
undef|#
directive|undef
name|_WINSOCKAPI_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Need windef.h for defines used in winsock2.h under MingW32 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MINGW32__
end_ifdef

begin_include
include|#
directive|include
file|<windef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UN*X */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for memset() */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/* DNS lookup */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* close() */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* errno() */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* for sockaddr_in, in BSD at least */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/*!    * \brief In Winsock, a socket handle is of type SOCKET; in UN*X, it's    * a file descriptor, and therefore a signed integer.    * We define SOCKET to be a signed integer on UN*X, so that it can    * be used on both platforms.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKET
end_ifndef

begin_define
define|#
directive|define
name|SOCKET
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!    * \brief In Winsock, the error return if socket() fails is INVALID_SOCKET;    * in UN*X, it's -1.    * We define INVALID_SOCKET to be -1 on UN*X, so that it can be used on    * both platforms.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INVALID_SOCKET
end_ifndef

begin_define
define|#
directive|define
name|INVALID_SOCKET
value|-1
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
comment|/*  * MingW headers include this definition, but only for Windows XP and above.  * MSDN states that this function is available for most versions on Windows.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|)
operator|&&
operator|(
name|_WIN32_WINNT
operator|<
literal|0x0501
operator|)
operator|)
end_if

begin_function_decl
name|int
name|WSAAPI
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|DWORD
parameter_list|,
name|char
modifier|*
parameter_list|,
name|DWORD
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * \defgroup SockUtils Cross-platform socket utilities (IPv4-IPv6)  */
end_comment

begin_comment
comment|/*  * \addtogroup SockUtils  * \{  */
end_comment

begin_comment
comment|/*  * \defgroup ExportedStruct Exported Structures and Definitions  */
end_comment

begin_comment
comment|/*  * \addtogroup ExportedStruct  * \{  */
end_comment

begin_comment
comment|/*  * Some minor differences between UN*X sockets and and Winsock sockets.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_comment
comment|/*    * Winsock doesn't have these UN*X types; they're used in the UN*X    * sockets API.    *    * XXX - do we need to worry about UN*Xes so old that *they* don't    * have them, either?    */
end_comment

begin_typedef
typedef|typedef
name|int
name|socklen_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!    * \brief In Winsock, the close() call cannot be used on a socket;    * closesocket() must be used.    * We define closesocket() to be a wrapper around close() on UN*X,    * so that it can be used on both platforms.    */
end_comment

begin_define
define|#
directive|define
name|closesocket
parameter_list|(
name|a
parameter_list|)
value|close(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * \brief DEBUG facility: it prints an error message on the screen (stderr)  *  * This macro prints the error on the standard error stream (stderr);  * if we are working in debug mode (i.e. there is no NDEBUG defined) and we are in  * Microsoft Visual C++, the error message will appear on the MSVC console as well.  *  * When NDEBUG is defined, this macro is empty.  *  * \param msg: the message you want to print.  *  * \param expr: 'false' if you want to abort the program, 'true' it you want  * to print the message and continue.  *  * \return No return values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|SOCK_ASSERT
parameter_list|(
name|msg
parameter_list|,
name|expr
parameter_list|)
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<crtdbg.h>
end_include

begin_comment
comment|/* for _CrtDbgReport */
end_comment

begin_comment
comment|/* Use MessageBox(NULL, msg, "warning", MB_OK)' instead of the other calls if you want to debug a Win32 service */
end_comment

begin_comment
comment|/* Remember to activate the 'allow service to interact with desktop' flag of the service */
end_comment

begin_define
define|#
directive|define
name|SOCK_ASSERT
parameter_list|(
name|msg
parameter_list|,
name|expr
parameter_list|)
value|{ _CrtDbgReport(_CRT_WARN, NULL, 0, NULL, "%s\n", msg); fprintf(stderr, "%s\n", msg); assert(expr); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SOCK_ASSERT
parameter_list|(
name|msg
parameter_list|,
name|expr
parameter_list|)
value|{ fprintf(stderr, "%s\n", msg); assert(expr); }
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
comment|/****************************************************  *                                                  *  * Exported functions / definitions                 *  *                                                  *  ****************************************************/
end_comment

begin_comment
comment|/* 'checkonly' flag, into the rpsock_bufferize() */
end_comment

begin_define
define|#
directive|define
name|SOCKBUF_CHECKONLY
value|1
end_define

begin_comment
comment|/* no 'checkonly' flag, into the rpsock_bufferize() */
end_comment

begin_define
define|#
directive|define
name|SOCKBUF_BUFFERIZE
value|0
end_define

begin_comment
comment|/* no 'server' flag; it opens a client socket */
end_comment

begin_define
define|#
directive|define
name|SOCKOPEN_CLIENT
value|0
end_define

begin_comment
comment|/* 'server' flag; it opens a server socket */
end_comment

begin_define
define|#
directive|define
name|SOCKOPEN_SERVER
value|1
end_define

begin_comment
comment|/* Changes the behaviour of the sock_recv(); it does not wait to receive all data */
end_comment

begin_define
define|#
directive|define
name|SOCK_RECEIVEALL_NO
value|0
end_define

begin_comment
comment|/* Changes the behaviour of the sock_recv(); it waits to receive all data */
end_comment

begin_define
define|#
directive|define
name|SOCK_RECEIVEALL_YES
value|1
end_define

begin_comment
comment|/*  * \}  */
end_comment

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
comment|/*  * \defgroup ExportedFunc Exported Functions  */
comment|/*  * \addtogroup ExportedFunc  * \{  */
name|int
name|sock_init
parameter_list|(
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|void
name|sock_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* It is 'public' because there are calls (like accept() ) which are not managed from inside the sockutils files */
name|void
name|sock_geterror
parameter_list|(
specifier|const
name|char
modifier|*
name|caller
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbufsize
parameter_list|)
function_decl|;
name|int
name|sock_initaddress
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
specifier|const
name|char
modifier|*
name|port
parameter_list|,
name|struct
name|addrinfo
modifier|*
name|hints
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
name|addrinfo
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_recv
parameter_list|(
name|SOCKET
name|socket
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|receiveall
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|SOCKET
name|sock_open
parameter_list|(
name|struct
name|addrinfo
modifier|*
name|addrinfo
parameter_list|,
name|int
name|server
parameter_list|,
name|int
name|nconn
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_close
parameter_list|(
name|SOCKET
name|sock
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_send
parameter_list|(
name|SOCKET
name|socket
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_bufferize
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|char
modifier|*
name|tempbuf
parameter_list|,
name|int
modifier|*
name|offset
parameter_list|,
name|int
name|totsize
parameter_list|,
name|int
name|checkonly
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_discard
parameter_list|(
name|SOCKET
name|socket
parameter_list|,
name|int
name|size
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_check_hostlist
parameter_list|(
name|char
modifier|*
name|hostlist
parameter_list|,
specifier|const
name|char
modifier|*
name|sep
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_cmpaddr
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|first
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|second
parameter_list|)
function_decl|;
name|int
name|sock_getmyinfo
parameter_list|(
name|SOCKET
name|sock
parameter_list|,
name|char
modifier|*
name|address
parameter_list|,
name|int
name|addrlen
parameter_list|,
name|char
modifier|*
name|port
parameter_list|,
name|int
name|portlen
parameter_list|,
name|int
name|flags
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_getascii_addrport
parameter_list|(
specifier|const
name|struct
name|sockaddr_storage
modifier|*
name|sockaddr
parameter_list|,
name|char
modifier|*
name|address
parameter_list|,
name|int
name|addrlen
parameter_list|,
name|char
modifier|*
name|port
parameter_list|,
name|int
name|portlen
parameter_list|,
name|int
name|flags
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
name|int
name|sock_present2network
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|sockaddr
parameter_list|,
name|int
name|addr_family
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
name|errbuflen
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * \}  */
end_comment

begin_comment
comment|/*  * \}  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

