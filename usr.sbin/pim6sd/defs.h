begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 LSIIT Laboratory.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|DEFS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|ELSE
value|else
end_define

begin_comment
comment|/* To make emacs cc-mode happy */
end_comment

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( ( a )<( b )?( b ):( a ) )
end_define

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ihfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fd_set
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*cfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|register_input_handler
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|ihfunc_t
name|func
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  CONFIGCONFIGCONFIGCONFIG */
end_comment

begin_define
define|#
directive|define
name|HAVE_ROUTING_SOCKETS
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_define
define|#
directive|define
name|RANDOM
parameter_list|()
value|random()
end_define

begin_define
define|#
directive|define
name|PRINTF
value|printf
end_define

begin_define
define|#
directive|define
name|ALL_MCAST_GROUPS_LENGTH
value|8
end_define

begin_typedef
typedef|typedef
name|u_int
name|u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|u_int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|u_int8
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
name|configfilename
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

