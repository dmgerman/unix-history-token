begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: unistd.h,v 1.10 2009/07/17 23:47:41 tbox Exp $ */
end_comment

begin_comment
comment|/* None of these are defined in NT, so define them for our use */
end_comment

begin_define
define|#
directive|define
name|O_NONBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

begin_comment
comment|/*  * fcntl() commands  */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|0
end_define

begin_define
define|#
directive|define
name|F_GETFL
value|1
end_define

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|F_GETFD
value|3
end_define

begin_comment
comment|/*  * Enough problems not having full fcntl() without worrying about this!  */
end_comment

begin_undef
undef|#
directive|undef
name|F_DUPFD
end_undef

begin_function_decl
name|int
name|fcntl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * access() related definitions for winXP  */
end_comment

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_OK
end_ifndef

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|access
value|_access
end_define

begin_include
include|#
directive|include
file|<process.h>
end_include

end_unit

