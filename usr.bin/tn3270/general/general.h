begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)general.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Some general definitions.  */
end_comment

begin_define
define|#
directive|define
name|numberof
parameter_list|(
name|x
parameter_list|)
value|(sizeof x/sizeof x[0])
end_define

begin_define
define|#
directive|define
name|highestof
parameter_list|(
name|x
parameter_list|)
value|(numberof(x)-1)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_define
define|#
directive|define
name|ClearElement
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)&x, sizeof x)
end_define

begin_define
define|#
directive|define
name|ClearArray
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)x, sizeof x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_define
define|#
directive|define
name|ClearElement
parameter_list|(
name|x
parameter_list|)
value|memset((char *)&x, 0, sizeof x)
end_define

begin_define
define|#
directive|define
name|ClearArray
parameter_list|(
name|x
parameter_list|)
value|memset((char *)x, 0, sizeof x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_comment
comment|/* Define BSD equivalent mem* functions */
end_comment

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|bcopy(src,dest,n)
end_define

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|bcopy(src,dest,n)
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|if (c == 0) { \ 				    bzero(s,n); \ 				} else { \ 				    register char *src = (char *)s; \ 				    register int count = n; \ 					\ 				    while (count--) { \ 					*src++ = c; \ 				    } \ 				}
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcmp(s1,s2,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

end_unit

