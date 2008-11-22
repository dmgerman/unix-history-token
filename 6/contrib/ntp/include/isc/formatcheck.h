begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: formatcheck.h,v 1.6 2001/01/09 21:56:55 bwelling Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_FORMATCHECK_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_FORMATCHECK_H
value|1
end_define

begin_comment
comment|/*  * fmt is the location of the format string parameter.  * args is the location of the first argument (or 0 for no argument checking).  * Note: the first parameter is 1, not 0.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ISC_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
value|__attribute__((__format__(__printf__, fmt, args)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
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
comment|/* ISC_FORMATCHECK_H */
end_comment

end_unit

