begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: PEXErr.h,v 5.1 91/02/16 09:47:05 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright (c) 1988,1989,1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEXERRS_H
end_ifndef

begin_define
define|#
directive|define
name|PEXERRS_H
end_define

begin_typedef
typedef|typedef
name|int
name|ErrorCode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PEXNOERR
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Success
end_ifndef

begin_define
define|#
directive|define
name|Success
value|PEXNOERR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Success */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEXNYI
end_ifndef

begin_define
define|#
directive|define
name|PEXNYI
value|BadImplementation
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEXNYI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEXERRS_H */
end_comment

end_unit

