begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: vis.h,v 1.11 1999/11/25 16:55:50 wennmach Exp $	*/
end_comment

begin_comment
comment|/*	$Id: vis.hin 19341 2006-12-15 11:53:09Z lha $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vis.h	8.1 (Berkeley) 6/2/93  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|ROKEN_LIB_FUNCTION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
value|_stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* use \[nrft0..] where appropiate */
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

begin_function_decl
name|char
name|ROKEN_LIB_FUNCTION
modifier|*
name|rk_vis
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
name|char
name|ROKEN_LIB_FUNCTION
modifier|*
name|rk_svis
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|rk_strvis
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
name|ROKEN_LIB_FUNCTION
name|rk_strsvis
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|rk_strvisx
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
name|ROKEN_LIB_FUNCTION
name|rk_strsvisx
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
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|rk_strunvis
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
name|ROKEN_LIB_FUNCTION
name|rk_unvis
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

begin_undef
undef|#
directive|undef
name|vis
end_undef

begin_define
define|#
directive|define
name|vis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|rk_vis(a,b,c,d)
end_define

begin_undef
undef|#
directive|undef
name|svis
end_undef

begin_define
define|#
directive|define
name|svis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|rk_svis(a,b,c,d,e)
end_define

begin_undef
undef|#
directive|undef
name|strvis
end_undef

begin_define
define|#
directive|define
name|strvis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|rk_strvis(a,b,c)
end_define

begin_undef
undef|#
directive|undef
name|strsvis
end_undef

begin_define
define|#
directive|define
name|strsvis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|rk_strsvis(a,b,c,d)
end_define

begin_undef
undef|#
directive|undef
name|strvisx
end_undef

begin_define
define|#
directive|define
name|strvisx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|rk_strvisx(a,b,c,d)
end_define

begin_undef
undef|#
directive|undef
name|strsvisx
end_undef

begin_define
define|#
directive|define
name|strsvisx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|rk_strsvisx(a,b,c,d,e)
end_define

begin_undef
undef|#
directive|undef
name|strunvis
end_undef

begin_define
define|#
directive|define
name|strunvis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|rk_strunvis(a,b)
end_define

begin_undef
undef|#
directive|undef
name|unvis
end_undef

begin_define
define|#
directive|define
name|unvis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|rk_unvis(a,b,c,d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VIS_H_ */
end_comment

end_unit

