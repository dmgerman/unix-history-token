begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/msg/priv.h,v 1.4 2003/10/10 14:50:05 hbb Exp $  *  * Private definitions for the IE code file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|unimsg_priv_h
end_ifndef

begin_define
define|#
directive|define
name|unimsg_priv_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|X
parameter_list|)
value|panic X
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|X
parameter_list|)
value|abort()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define a structure for the declaration of information elements.  * For each coding scheme a quadrupel of check, print, encode and  * decode functions must be defined. A structure of the same format  * is used for messages.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uni_print_f
function_decl|)
parameter_list|(
specifier|const
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_check_f
function_decl|)
parameter_list|(
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_encode_f
function_decl|)
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_decode_f
function_decl|)
parameter_list|(
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uni_msg_print_f
function_decl|)
parameter_list|(
specifier|const
name|union
name|uni_msgall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_msg_check_f
function_decl|)
parameter_list|(
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_msg_encode_f
function_decl|)
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|union
name|uni_msgall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uni_msg_decode_f
function_decl|)
parameter_list|(
name|union
name|uni_msgall
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|enum
name|uni_ietype
parameter_list|,
name|struct
name|uni_iehdr
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|iedecl
block|{
name|u_int
name|flags
decl_stmt|;
comment|/* information element flags */
name|u_int
name|maxlen
decl_stmt|;
comment|/* maximum size */
name|uni_print_f
name|print
decl_stmt|;
name|uni_check_f
name|check
decl_stmt|;
name|uni_encode_f
name|encode
decl_stmt|;
name|uni_decode_f
name|decode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msgdecl
block|{
name|u_int
name|flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uni_msg_print_f
name|print
decl_stmt|;
name|uni_msg_check_f
name|check
decl_stmt|;
name|uni_msg_encode_f
name|encode
decl_stmt|;
name|uni_msg_decode_f
name|decode
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|UNIFL_DEFAULT
init|=
literal|0x0001
block|,
name|UNIFL_ACCESS
init|=
literal|0x0002
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iedecl
modifier|*
name|uni_ietable
index|[
literal|256
index|]
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|msgdecl
modifier|*
name|uni_msgtable
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Need to check range here because declaring a variable as a enum does not  * guarantee that the values will be legal.  */
end_comment

begin_define
define|#
directive|define
name|GET_IEDECL
parameter_list|(
name|IE
parameter_list|,
name|CODING
parameter_list|)
define|\
value|({									\ 	const struct iedecl *_decl = NULL;				\ 									\ 	if((CODING)<= 3&& (IE)<= 255)				\ 	    if((_decl = uni_ietable[IE][CODING]) != NULL)		\ 		if((_decl->flags& UNIFL_DEFAULT) != 0)			\ 		    if((_decl = uni_ietable[IE][0]) == NULL)		\ 			PANIC(("IE %02x,%02x -- no default", CODING,IE));\ 	_decl;								\ })
end_define

begin_enum
enum|enum
block|{
name|DEC_OK
block|,
name|DEC_ILL
block|,
name|DEC_ERR
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|uni_print_ie_internal
parameter_list|(
name|enum
name|uni_ietype
parameter_list|,
specifier|const
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

