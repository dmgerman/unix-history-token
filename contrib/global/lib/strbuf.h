begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997, 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	strbuf.h					5-Jul-98  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_STRBUF_H
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|INITIALSIZE
value|80
end_define

begin_define
define|#
directive|define
name|EXPANDSIZE
value|80
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|sbuf
decl_stmt|;
name|char
modifier|*
name|endp
decl_stmt|;
name|char
modifier|*
name|curp
decl_stmt|;
name|int
name|sbufsize
decl_stmt|;
block|}
name|STRBUF
typedef|;
end_typedef

begin_define
define|#
directive|define
name|strputc
parameter_list|(
name|sb
parameter_list|,
name|c
parameter_list|)
value|do {\ 	if (sb->curp + 1> sb->endp)\ 		expandbuf(sb, 0);\ 	*sb->curp++ = c;\ } while (0)
end_define

begin_define
define|#
directive|define
name|strunputc
parameter_list|(
name|sb
parameter_list|,
name|c
parameter_list|)
value|do {\ 	if (sb->curp> sb->sbuf&& *(sb->curp - 1) == c)\ 		sb->curp--;\ } while (0)
end_define

begin_define
define|#
directive|define
name|strnputs
parameter_list|(
name|sb
parameter_list|,
name|s
parameter_list|,
name|len
parameter_list|)
value|do {\ 	unsigned int _length = len;\ 	if (sb->curp + _length> sb->endp)\ 		expandbuf(sb, _length);\ 	strncpy(sb->curp, s, _length);\ 	sb->curp += _length;\ } while (0)
end_define

begin_define
define|#
directive|define
name|strputs
parameter_list|(
name|sb
parameter_list|,
name|s
parameter_list|)
value|strnputs(sb, s, strlen(s))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|expandbuf
name|__P
argument_list|(
operator|(
name|STRBUF
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRBUF
modifier|*
name|stropen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|strstart
name|__P
argument_list|(
operator|(
name|STRBUF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strbuflen
name|__P
argument_list|(
operator|(
name|STRBUF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strvalue
name|__P
argument_list|(
operator|(
name|STRBUF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|strclose
name|__P
argument_list|(
operator|(
name|STRBUF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _STRBUF_H */
end_comment

end_unit

