begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/unimsg.h,v 1.4 2004/07/08 08:21:46 brandt Exp $  *  * This defines the structure of messages as handled by this library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_UNIMSG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_UNIMSG_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|uni_msg
block|{
name|u_char
modifier|*
name|b_wptr
decl_stmt|;
comment|/* tail pointer */
name|u_char
modifier|*
name|b_rptr
decl_stmt|;
comment|/* head pointer */
name|u_char
modifier|*
name|b_buf
decl_stmt|;
comment|/* data buffer */
name|u_char
modifier|*
name|b_lim
decl_stmt|;
comment|/* end of data buffer */
block|}
struct|;
end_struct

begin_comment
comment|/* return the current length of the message */
end_comment

begin_define
define|#
directive|define
name|uni_msg_len
parameter_list|(
name|M
parameter_list|)
value|((size_t)((M)->b_wptr - (M)->b_rptr))
end_define

begin_comment
comment|/* return the number of space behind the message */
end_comment

begin_define
define|#
directive|define
name|uni_msg_space
parameter_list|(
name|M
parameter_list|)
value|((size_t)((M)->b_lim - (M)->b_wptr))
end_define

begin_comment
comment|/* return the amount of leading free space */
end_comment

begin_define
define|#
directive|define
name|uni_msg_leading
parameter_list|(
name|M
parameter_list|)
value|((size_t)((M)->b_rptr - (M)->b_buf))
end_define

begin_comment
comment|/* return the maximum size of the message (length plus free space) */
end_comment

begin_define
define|#
directive|define
name|uni_msg_size
parameter_list|(
name|M
parameter_list|)
value|((size_t)((M)->b_lim - (M)->b_buf));
end_define

begin_comment
comment|/* ensure that there is space for another S bytes. If reallocation fails  * free message and return -1 */
end_comment

begin_define
define|#
directive|define
name|uni_msg_ensure
parameter_list|(
name|M
parameter_list|,
name|S
parameter_list|)
define|\
value|((uni_msg_space(M)>= (S)) ? 0 : uni_msg_extend(M, S))
end_define

begin_function_decl
name|int
name|uni_msg_append
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_msg_extend
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|uni_msg_rptr
parameter_list|(
name|MSG
parameter_list|,
name|TYPE
parameter_list|)
value|((TYPE)(void *)(MSG)->b_rptr)
end_define

begin_define
define|#
directive|define
name|uni_msg_wptr
parameter_list|(
name|MSG
parameter_list|,
name|TYPE
parameter_list|)
value|((TYPE)(void *)(MSG)->b_wptr)
end_define

begin_function_decl
name|int
name|uni_msg_prepend
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|uni_msg_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|uni_msg_build
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_msg_destroy
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|uni_msg_strip32
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|uni_msg_get32
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_msg_append32
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_msg_append8
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|uni_msg_trail32
parameter_list|(
specifier|const
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|uni_msg_dup
parameter_list|(
specifier|const
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

