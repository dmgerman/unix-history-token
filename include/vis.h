begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vis.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIS_H_
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * to select alternate encoding format  */
end_comment

begin_define
define|#
directive|define
name|VIS_OCTAL
value|0x01
end_define

begin_comment
comment|/* use octal \ddd format */
end_comment

begin_define
define|#
directive|define
name|VIS_CSTYLE
value|0x02
end_define

begin_comment
comment|/* use \[nrft0..] where appropriate */
end_comment

begin_comment
comment|/*  * to alter set of characters encoded (default is to encode all  * non-graphic except space, tab, and newline).  */
end_comment

begin_define
define|#
directive|define
name|VIS_SP
value|0x04
end_define

begin_comment
comment|/* also encode space */
end_comment

begin_define
define|#
directive|define
name|VIS_TAB
value|0x08
end_define

begin_comment
comment|/* also encode tab */
end_comment

begin_define
define|#
directive|define
name|VIS_NL
value|0x10
end_define

begin_comment
comment|/* also encode newline */
end_comment

begin_define
define|#
directive|define
name|VIS_WHITE
value|(VIS_SP | VIS_TAB | VIS_NL)
end_define

begin_define
define|#
directive|define
name|VIS_SAFE
value|0x20
end_define

begin_comment
comment|/* only encode "unsafe" characters */
end_comment

begin_comment
comment|/*  * other  */
end_comment

begin_define
define|#
directive|define
name|VIS_NOSLASH
value|0x40
end_define

begin_comment
comment|/* inhibit printing '\' */
end_comment

begin_define
define|#
directive|define
name|VIS_HTTPSTYLE
value|0x80
end_define

begin_comment
comment|/* http-style escape % HEX HEX */
end_comment

begin_comment
comment|/*  * unvis return codes  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_VALID
value|1
end_define

begin_comment
comment|/* character valid */
end_comment

begin_define
define|#
directive|define
name|UNVIS_VALIDPUSH
value|2
end_define

begin_comment
comment|/* character valid, push back passed char */
end_comment

begin_define
define|#
directive|define
name|UNVIS_NOCHAR
value|3
end_define

begin_comment
comment|/* valid sequence, no character produced */
end_comment

begin_define
define|#
directive|define
name|UNVIS_SYNBAD
value|-1
end_define

begin_comment
comment|/* unrecognized escape sequence */
end_comment

begin_define
define|#
directive|define
name|UNVIS_ERROR
value|-2
end_define

begin_comment
comment|/* decoder in unknown state (unrecoverable) */
end_comment

begin_comment
comment|/*  * unvis flags  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_END
value|1
end_define

begin_comment
comment|/* no more characters */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|vis
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strvis
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strvisx
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strunvis
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strunvisx
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unvis
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VIS_H_ */
end_comment

end_unit

