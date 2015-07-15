begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: bind_registry.h,v 1.8 2007/06/19 23:47:20 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BINDREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BINDREGISTRY_H
end_define

begin_comment
comment|/*  * BIND makes use of the following Registry keys in various places, especially  * during startup and installation  */
end_comment

begin_define
define|#
directive|define
name|BIND_SUBKEY
value|"Software\\ISC\\BIND"
end_define

begin_define
define|#
directive|define
name|BIND_SESSION
value|"CurrentSession"
end_define

begin_define
define|#
directive|define
name|BIND_SESSION_SUBKEY
value|"Software\\ISC\\BIND\\CurrentSession"
end_define

begin_define
define|#
directive|define
name|BIND_UNINSTALL_SUBKEY
define|\
value|"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ISC BIND"
end_define

begin_define
define|#
directive|define
name|EVENTLOG_APP_SUBKEY
define|\
value|"SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application"
end_define

begin_define
define|#
directive|define
name|BIND_MESSAGE_SUBKEY
define|\
value|"SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application\\named"
end_define

begin_define
define|#
directive|define
name|BIND_MESSAGE_NAME
value|"named"
end_define

begin_define
define|#
directive|define
name|BIND_SERVICE_SUBKEY
define|\
value|"SYSTEM\\CurrentControlSet\\Services\\named"
end_define

begin_define
define|#
directive|define
name|BIND_CONFIGFILE
value|0
end_define

begin_define
define|#
directive|define
name|BIND_DEBUGLEVEL
value|1
end_define

begin_define
define|#
directive|define
name|BIND_QUERYLOG
value|2
end_define

begin_define
define|#
directive|define
name|BIND_FOREGROUND
value|3
end_define

begin_define
define|#
directive|define
name|BIND_PORT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BINDREGISTRY_H */
end_comment

end_unit

