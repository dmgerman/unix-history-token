begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: pathnames.h,v 1.7 1999/01/08 19:25:10 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_IRS_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_IRS_CONF
value|"/etc/irs.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NETWORKS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NETWORKS
value|"/etc/networks"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_GROUP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_GROUP
value|"/etc/group"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NETGROUP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NETGROUP
value|"/etc/netgroup"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SERVICES
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SERVICES
value|"/etc/services"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IRS_LCL_SV_DB
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SERVICES_DB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SERVICES_DB
value|_PATH_SERVICES ".db"
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
name|_PATH_HESIOD_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HESIOD_CONF
value|"/etc/hesiod.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

