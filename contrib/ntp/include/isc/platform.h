begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: platform.h.in,v 1.28 2001/11/19 03:08:26 mayer Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PLATFORM_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_USEDECLSPEC
end_ifndef

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBDNS_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBISCCC_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBISCCFG_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBBIND9_EXTERNAL_DATA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_USEDECLSPEC */
end_comment

begin_comment
comment|/*  * Tell emacs to use C mode for this file.  *  * Local Variables:  * mode: c  * End:  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_H */
end_comment

end_unit

