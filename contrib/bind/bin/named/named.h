begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: named.h,v 8.31 2002/02/01 00:05:38 marka Exp $  */
end_comment

begin_comment
comment|/* Options. Change them at your peril. */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_define
define|#
directive|define
name|ADDAUTH
end_define

begin_define
define|#
directive|define
name|STUBS
end_define

begin_define
define|#
directive|define
name|RETURNSOA
end_define

begin_define
define|#
directive|define
name|BOGUSNS
end_define

begin_define
define|#
directive|define
name|TRACEROOT
end_define

begin_define
define|#
directive|define
name|XFRNETS
end_define

begin_define
define|#
directive|define
name|QRYLOG
end_define

begin_undef
undef|#
directive|undef
name|YPKLUDGE
end_undef

begin_define
define|#
directive|define
name|RENICE
end_define

begin_define
define|#
directive|define
name|BIND_IXFR
end_define

begin_define
define|#
directive|define
name|BIND_NOTIFY
end_define

begin_define
define|#
directive|define
name|BIND_UPDATE
end_define

begin_define
define|#
directive|define
name|WANT_PIDFILE
end_define

begin_define
define|#
directive|define
name|FWD_LOOP
end_define

begin_define
define|#
directive|define
name|DOTTED_SERIAL
end_define

begin_define
define|#
directive|define
name|SENSIBLE_DOTS
end_define

begin_define
define|#
directive|define
name|ROUND_ROBIN
end_define

begin_define
define|#
directive|define
name|DNS_SECURITY
end_define

begin_undef
undef|#
directive|undef
name|RSAREF
end_undef

begin_undef
undef|#
directive|undef
name|BSAFE
end_undef

begin_define
define|#
directive|define
name|ALLOW_LONG_TXT_RDATA
end_define

begin_define
define|#
directive|define
name|STRICT_RFC2308
end_define

begin_undef
undef|#
directive|undef
name|BIND_ZXFR
end_undef

begin_undef
undef|#
directive|undef
name|LOG_TSIG_BUG
end_undef

begin_define
define|#
directive|define
name|NOADDITIONAL
end_define

begin_undef
undef|#
directive|undef
name|FORWARD_ALLOWS
end_undef

begin_comment
comment|/* enable allow-query for forward zones. */
end_comment

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_include
include|#
directive|include
file|<isc/ctl.h>
end_include

begin_include
include|#
directive|include
file|<res_update.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_include
include|#
directive|include
file|"ns_defs.h"
end_include

begin_include
include|#
directive|include
file|"db_defs.h"
end_include

begin_include
include|#
directive|include
file|"ns_glob.h"
end_include

begin_include
include|#
directive|include
file|"db_glob.h"
end_include

begin_include
include|#
directive|include
file|"ns_func.h"
end_include

begin_include
include|#
directive|include
file|"db_func.h"
end_include

end_unit

