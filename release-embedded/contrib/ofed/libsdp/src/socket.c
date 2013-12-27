begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   This software is available to you under a choice of one of two   licenses.  You may choose to be licensed under the terms of the GNU   General Public License (GPL) Version 2, available at<http://www.fsf.org/copyleft/gpl.html>, or the OpenIB.org BSD   license, available in the LICENSE.TXT file accompanying this   software.  These details are also available at<http://openib.org/license.html>.    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   SOFTWARE.    Copyright (c) 2004 Topspin Communications.  All rights reserved.   Copyright (c) 2005 Mellanox Technologies Ltd.  All rights reserved.    $Id$ */
end_comment

begin_comment
comment|/*  * system includes  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_comment
comment|/*   For non-i386 systems, we pass socket() through to library code using   dlsym() instead of trying to make the system call directly.  This   may cause problems if this library is LD_PRELOADed before the real C   library is available.  Eventually we may want to add the same type   of system call assembly code as i386 has for IA64 and AMD64, but for   now.... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|i386
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* Get RTLD_NEXT */
end_comment

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * SDP specific includes  */
end_comment

begin_include
include|#
directive|include
file|"linux/sdp_inet.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|_SDP_VERBOSE_PRELOAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOCKOP_socket
value|1
end_define

begin_define
define|#
directive|define
name|SOCKOP_bind
value|2
end_define

begin_define
define|#
directive|define
name|SOCKOP_connect
value|3
end_define

begin_define
define|#
directive|define
name|SOCKOP_listen
value|4
end_define

begin_define
define|#
directive|define
name|SOCKOP_accept
value|5
end_define

begin_define
define|#
directive|define
name|SOCKOP_getsockname
value|6
end_define

begin_define
define|#
directive|define
name|SOCKOP_getpeername
value|7
end_define

begin_define
define|#
directive|define
name|SOCKOP_socketpair
value|8
end_define

begin_define
define|#
directive|define
name|SOCKOP_send
value|9
end_define

begin_define
define|#
directive|define
name|SOCKOP_recv
value|10
end_define

begin_define
define|#
directive|define
name|SOCKOP_sendto
value|11
end_define

begin_define
define|#
directive|define
name|SOCKOP_recvfrom
value|12
end_define

begin_define
define|#
directive|define
name|SOCKOP_shutdown
value|13
end_define

begin_define
define|#
directive|define
name|SOCKOP_setsockopt
value|14
end_define

begin_define
define|#
directive|define
name|SOCKOP_getsockopt
value|15
end_define

begin_define
define|#
directive|define
name|SOCKOP_sendmsg
value|16
end_define

begin_define
define|#
directive|define
name|SOCKOP_recvmsg
value|17
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_invocation_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_invocation_short_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
specifier|const
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ========================================================================= */
end_comment

begin_comment
comment|/*..socket -- replacment socket call. */
end_comment

begin_function
name|int
name|socket
parameter_list|(
name|int
name|domain
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|protocol
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|i386
name|long
name|__ret
decl_stmt|;
name|void
modifier|*
name|__scratch
decl_stmt|;
name|int
name|call
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
name|test
decl_stmt|;
name|char
modifier|*
name|inet
decl_stmt|;
name|char
modifier|*
modifier|*
name|tenviron
decl_stmt|;
ifdef|#
directive|ifdef
name|_SDP_VERBOSE_PRELOAD
name|FILE
modifier|*
name|fd
decl_stmt|;
endif|#
directive|endif
comment|/*    * check for magic enviroment variable    */
if|if
condition|(
operator|(
name|AF_INET
operator|==
name|domain
operator|||
name|AF_INET6
operator|==
name|domain
operator|)
operator|&&
name|SOCK_STREAM
operator|==
name|type
condition|)
block|{
if|if
condition|(
name|environ
condition|)
block|{
name|tenviron
operator|=
name|environ
expr_stmt|;
for|for
control|(
name|test
operator|=
operator|*
name|tenviron
init|;
name|NULL
operator|!=
name|test
condition|;
name|test
operator|=
operator|*
operator|++
name|tenviron
control|)
block|{
name|inet
operator|=
name|AF_INET_STR
expr_stmt|;
while|while
condition|(
operator|*
name|inet
operator|==
operator|*
name|test
operator|&&
literal|'\0'
operator|!=
operator|*
name|inet
condition|)
block|{
name|inet
operator|++
expr_stmt|;
name|test
operator|++
expr_stmt|;
block|}
comment|/* while */
if|if
condition|(
literal|'\0'
operator|==
operator|*
name|inet
operator|&&
literal|'='
operator|==
operator|*
name|test
condition|)
block|{
name|domain
operator|=
name|AF_INET_SDP
expr_stmt|;
break|break;
block|}
comment|/* if */
block|}
comment|/* for */
block|}
comment|/* if */
block|}
comment|/* if */
ifdef|#
directive|ifdef
name|_SDP_VERBOSE_PRELOAD
name|fd
operator|=
name|fopen
argument_list|(
literal|"/tmp/libsdp.log.txt"
argument_list|,
literal|"a+"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"SOCKET:<%s> domain<%d> type<%d> protocol<%d>\n"
argument_list|,
name|program_invocation_short_name
argument_list|,
name|domain
argument_list|,
name|type
argument_list|,
name|protocol
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|i386
comment|/* Make the socket() system call directly, as described above */
name|call
index|[
literal|0
index|]
operator|=
name|domain
expr_stmt|;
name|call
index|[
literal|1
index|]
operator|=
name|type
expr_stmt|;
name|call
index|[
literal|2
index|]
operator|=
name|protocol
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|("movl %%ebx, %1\n"
comment|/* save %ebx */
asm|"movl %3, %%ebx\n"
comment|/* put sockopt in %ebx as arg */
asm|"int $0x80\n"
comment|/* do syscall */
asm|"movl %1, %%ebx\n"
comment|/* restore %ebx */
asm|: "=a" (__ret), "=r" (__scratch)                        : "0" (__NR_socketcall), 		       "g" (SOCKOP_socket), 		       "c" (call));
return|return
name|__ret
return|;
else|#
directive|else
comment|/* i386 */
comment|/* Use the standard library socket() to pass through the call */
block|{
specifier|static
name|int
function_decl|(
modifier|*
name|orig_socket
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
if|if
condition|(
operator|!
name|orig_socket
condition|)
block|{
name|orig_socket
operator|=
name|dlsym
argument_list|(
name|RTLD_NEXT
argument_list|,
literal|"socket"
argument_list|)
expr_stmt|;
block|}
return|return
name|orig_socket
argument_list|(
name|domain
argument_list|,
name|type
argument_list|,
name|protocol
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|/* i386 */
block|}
end_function

begin_comment
comment|/* socket */
end_comment

end_unit

