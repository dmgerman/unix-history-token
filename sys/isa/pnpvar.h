begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISA_PNPVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISA_PNPVAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|void    pnp_write(int d, u_char r);
comment|/* used by Luigi's sound driver */
end_comment

begin_comment
unit|u_char  pnp_read(int d);
comment|/* currently unused, but who knows... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PNP_HEXTONUM
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'		\ 			 ? (c) - 'a' + 10	\ 			 : ((c)>= 'A'		\ 			    ? (c) - 'A' + 10	\ 			    : (c) - '0'))
end_define

begin_define
define|#
directive|define
name|PNP_EISAID
parameter_list|(
name|s
parameter_list|)
define|\
value|((((s[0] - '@')& 0x1f)<< 2)		\ 	 | (((s[1] - '@')& 0x18)>> 3)		\ 	 | (((s[1] - '@')& 0x07)<< 13)	\ 	 | (((s[2] - '@')& 0x1f)<< 8)		\ 	 | (PNP_HEXTONUM(s[4])<< 16)		\ 	 | (PNP_HEXTONUM(s[3])<< 20)		\ 	 | (PNP_HEXTONUM(s[6])<< 24)		\ 	 | (PNP_HEXTONUM(s[5])<< 28))
end_define

begin_function_decl
name|char
modifier|*
name|pnp_eisaformat
parameter_list|(
name|u_int32_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pnp_parse_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
modifier|*
name|resources
parameter_list|,
name|int
name|len
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

begin_comment
comment|/* !_ISA_PNPVAR_H_ */
end_comment

end_unit

