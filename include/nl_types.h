begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1990, by Alfalfa Software Incorporated, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that Alfalfa's name not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  ALPHALPHA DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL ALPHALPHA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  If you make any modifications, bugfixes or other changes to this software we'd appreciate it if you could send a copy to us so we can keep things up-to-date.  Many thanks. 				Kee Hinckley 				Alfalfa Software, Inc. 				267 Allston St., #3 				Cambridge, MA 02139  USA 				nazgul@alfalfa.com  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NL_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_NL_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|NL_SETD
value|0
end_define

begin_define
define|#
directive|define
name|NL_CAT_LOCALE
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|nl_item
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|nl_catd
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|nl_catd
name|catopen
parameter_list|(
name|__const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|catgets
parameter_list|(
name|nl_catd
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|__const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|catclose
parameter_list|(
name|nl_catd
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
comment|/* _NL_TYPES_H_ */
end_comment

end_unit

