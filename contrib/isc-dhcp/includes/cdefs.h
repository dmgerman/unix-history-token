begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cdefs.h     Standard C definitions... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 The Internet Software Consortium.  * All Rights Reserved.  * Copyright (c) 1995 RadioMail Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RadioMail Corporation, the Internet Software  *    Consortium nor the names of its contributors may be used to endorse  *    or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RADIOMAIL CORPORATION, THE INTERNET  * SOFTWARE CONSORTIUM AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL RADIOMAIL CORPORATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software was written for RadioMail Corporation by Ted Lemon  * under a contract with Vixie Enterprises.   Further modifications have  * been made for the Internet Software Consortium under a contract  * with Vixie Laboratories.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|BROKEN_ANSI
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|KandR
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ANSI_DECL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
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
name|PROTO
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|KandR
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ANSI_DECL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ || __STDC__ */
end_comment

end_unit

