begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CTYPE_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__CTYPE_EXT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCSW_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|NCSW_FREEBSD
argument_list|)
end_if

begin_comment
comment|/*  * NOTE! This ctype does not handle EOF like the standard C  * library is required to.  */
end_comment

begin_define
define|#
directive|define
name|_U
value|0x01
end_define

begin_comment
comment|/* upper */
end_comment

begin_define
define|#
directive|define
name|_L
value|0x02
end_define

begin_comment
comment|/* lower */
end_comment

begin_define
define|#
directive|define
name|_D
value|0x04
end_define

begin_comment
comment|/* digit */
end_comment

begin_define
define|#
directive|define
name|_C
value|0x08
end_define

begin_comment
comment|/* cntrl */
end_comment

begin_define
define|#
directive|define
name|_P
value|0x10
end_define

begin_comment
comment|/* punct */
end_comment

begin_define
define|#
directive|define
name|_S
value|0x20
end_define

begin_comment
comment|/* white space (space/lf/tab) */
end_comment

begin_define
define|#
directive|define
name|_X
value|0x40
end_define

begin_comment
comment|/* hex digit */
end_comment

begin_define
define|#
directive|define
name|_SP
value|0x80
end_define

begin_comment
comment|/* hard space (0x20) */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_ctype
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__ismask
parameter_list|(
name|x
parameter_list|)
value|(_ctype[(int)(unsigned char)(x)])
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_U|_L|_D)) != 0)
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_U|_L)) != 0)
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_C)) != 0)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_D)) != 0)
end_define

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_P|_U|_L|_D)) != 0)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_L)) != 0)
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_P|_U|_L|_D|_SP)) != 0)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_P)) != 0)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_S)) != 0)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_U)) != 0)
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|((__ismask(c)&(_D|_X)) != 0)
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|(((unsigned char)(c))<=0x7f)
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|(((unsigned char)(c))&0x7f)
end_define

begin_function
specifier|static
name|__inline__
name|unsigned
name|char
name|__tolower
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|-=
literal|'A'
operator|-
literal|'a'
expr_stmt|;
return|return
name|c
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|char
name|__toupper
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
name|islower
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|-=
literal|'a'
operator|-
literal|'A'
expr_stmt|;
return|return
name|c
return|;
block|}
end_function

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|__tolower(c)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|__toupper(c)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NCSW_LINUX)&& defined(__KERNEL__) || defined(NCSW_FREEBSD) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CTYPE_EXT_H */
end_comment

end_unit

