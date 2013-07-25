begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_comment
comment|/* configuration data */
end_comment

begin_comment
comment|/**  * @file apr_want.h  * @brief APR Standard Headers Support  *  *<PRE>  * Features:  *  *   APR_WANT_STRFUNC:  strcmp, strcat, strcpy, etc  *   APR_WANT_MEMFUNC:  memcmp, memcpy, etc  *   APR_WANT_STDIO:<stdio.h> and related bits  *   APR_WANT_IOVEC:    struct iovec  *   APR_WANT_BYTEFUNC: htons, htonl, ntohl, ntohs  *  * Typical usage:  *  *   \#define APR_WANT_STRFUNC  *   \#define APR_WANT_MEMFUNC  *   \#include "apr_want.h"  *  * The appropriate headers will be included.  *  * Note: it is safe to use this in a header (it won't interfere with other  *       headers' or source files' use of apr_want.h)  *</PRE>  */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_WANT_STRFUNC
end_ifdef

begin_if
if|#
directive|if
name|APR_HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STRINGS_H
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|APR_WANT_STRFUNC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_WANT_MEMFUNC
end_ifdef

begin_if
if|#
directive|if
name|APR_HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|APR_WANT_MEMFUNC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_WANT_STDIO
end_ifdef

begin_if
if|#
directive|if
name|APR_HAVE_STDIO_H
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|APR_WANT_STDIO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_WANT_IOVEC
end_ifdef

begin_if
if|#
directive|if
name|APR_HAVE_IOVEC
end_if

begin_if
if|#
directive|if
name|APR_HAVE_SYS_UIO_H
end_if

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|APR_IOVEC_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|APR_IOVEC_DEFINED
end_define

begin_struct
struct|struct
name|iovec
block|{
name|void
modifier|*
name|iov_base
decl_stmt|;
name|size_t
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_IOVEC_DEFINED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAVE_IOVEC */
end_comment

begin_undef
undef|#
directive|undef
name|APR_WANT_IOVEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_WANT_BYTEFUNC
end_ifdef

begin_comment
comment|/* Single Unix says they are in arpa/inet.h.  Linux has them in  * netinet/in.h.  FreeBSD has them in arpa/inet.h but requires that  * netinet/in.h be included first.  */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_IN_H
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_ARPA_INET_H
end_if

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|APR_WANT_BYTEFUNC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

end_unit

