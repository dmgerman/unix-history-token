begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xge-os-pal.h  *  *  Description:  top-level header file. works just like switching between  *                os-depndent parts  *  *  Created:      6st May 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_OS_PAL_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_OS_PAL_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-defs.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*--------------------------- platform switch ------------------------------*/
end_comment

begin_comment
comment|/* platform specific header */
end_comment

begin_include
include|#
directive|include
file|<dev/nxge/xge-osdep.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|XGEHAL_RNIC
end_ifdef

begin_define
define|#
directive|define
name|IN
end_define

begin_define
define|#
directive|define
name|OUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XGE_OS_PLATFORM_64BIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XGE_OS_PLATFORM_32BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"either 32bit or 64bit switch must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XGE_OS_HOST_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XGE_OS_HOST_LITTLE_ENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"either little endian or big endian switch must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XGE_OS_PLATFORM_64BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_DEADCODE_PAT
value|0x5a5a5a5a5a5a5a5a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_DEADCODE_PAT
value|0x5a5a5a5a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XGE_OS_TRACE_MSGBUF_MAX
value|512
end_define

begin_typedef
typedef|typedef
struct|struct
name|xge_os_tracebuf_t
block|{
name|int
name|wrapped_once
decl_stmt|;
comment|/* circular buffer been wrapped */
name|int
name|timestamp
decl_stmt|;
comment|/* whether timestamps are enabled */
specifier|volatile
name|int
name|offset
decl_stmt|;
comment|/* offset within the tracebuf */
name|int
name|size
decl_stmt|;
comment|/* total size of trace buffer */
name|char
name|msg
index|[
name|XGE_OS_TRACE_MSGBUF_MAX
index|]
decl_stmt|;
comment|/* each individual buffer */
name|int
name|msgbuf_max
decl_stmt|;
comment|/* actual size of msg buffer */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data buffer */
block|}
name|xge_os_tracebuf_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|xge_os_tracebuf_t
modifier|*
name|g_xge_os_tracebuf
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_TRACE_INTO_CIRCULAR_ARR
end_ifdef

begin_decl_stmt
specifier|extern
name|xge_os_tracebuf_t
modifier|*
name|g_xge_os_tracebuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dmesg_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Calculate the size of the msg and copy it into the global buffer */
end_comment

begin_define
define|#
directive|define
name|__xge_trace
parameter_list|(
name|tb
parameter_list|)
value|{ \ 	int msgsize = xge_os_strlen(tb->msg) + 2; \ 	int offset = tb->offset; \ 	if (msgsize != 2&& msgsize< tb->msgbuf_max) { \ 		int leftsize =  tb->size - offset; \ 		if ((msgsize + tb->msgbuf_max)> leftsize) { \ 			xge_os_memzero(tb->data + offset, leftsize); \ 			offset = 0; \ 			tb->wrapped_once = 1; \ 		} \ 		xge_os_memcpy(tb->data + offset, tb->msg, msgsize-1); \ 		*(tb->data + offset + msgsize-1) = '\n'; \ 		*(tb->data + offset + msgsize) = 0; \ 		offset += msgsize; \ 		tb->offset = offset; \ 		dmesg_start = tb->data + offset; \ 		*tb->msg = 0; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|xge_os_vatrace
parameter_list|(
name|tb
parameter_list|,
name|fmt
parameter_list|)
value|{ \ 	if (tb != NULL) { \ 		char *_p = tb->msg; \ 		if (tb->timestamp) { \ 			xge_os_timestamp(tb->msg); \ 			_p = tb->msg + xge_os_strlen(tb->msg); \ 		} \ 		xge_os_vasprintf(_p, fmt); \ 		__xge_trace(tb); \ 	} \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|xge_os_trace
parameter_list|(
name|tb
parameter_list|,
name|fmt
modifier|...
parameter_list|)
value|{ \ 	if (tb != NULL) { \ 		if (tb->timestamp) { \ 			xge_os_timestamp(tb->msg); \ 		} \ 		xge_os_sprintf(tb->msg + xge_os_strlen(tb->msg), fmt); \ 		__xge_trace(tb); \ 	} \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_os_vatrace
parameter_list|(
name|tb
parameter_list|,
name|fmt
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|xge_os_trace
parameter_list|(
name|tb
parameter_list|,
name|fmt
modifier|...
parameter_list|)
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

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_OS_PAL_H */
end_comment

end_unit

