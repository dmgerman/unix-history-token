begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Id: pathtemplate.h,v 8.6 2000/04/21 06:54:15 vixie Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CONF
value|"%DESTETC%/named.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEBUG
value|"named.run"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DUMPFILE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DUMPFILE
value|"named_dump.db"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NAMED
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NAMED
value|"%DESTSBIN%/named"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PIDFILE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"%DESTRUN%/named.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NDCSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SECURE_DIRECTORY
end_ifdef

begin_define
define|#
directive|define
name|_PATH_NDCSOCK
value|"%DESTRUN%/ndc.d/ndc"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_NDCSOCK
value|"%DESTRUN%/ndc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_STATS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_STATS
value|"named.stats"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_MEMSTATS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_MEMSTATS
value|"named.memstats"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TMPXFER
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TMPXFER
value|"xfer.ddt.XXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFER
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"%DESTEXEC%/named-xfer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFERTRACE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XFERTRACE
value|"xfer.trace"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFERDDT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XFERDDT
value|"xfer.ddt"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

