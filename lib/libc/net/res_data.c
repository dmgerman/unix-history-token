begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995,1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"res_config.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_res_opcodes
index|[]
init|=
block|{
literal|"QUERY"
block|,
literal|"IQUERY"
block|,
literal|"CQUERYM"
block|,
literal|"CQUERYU"
block|,
comment|/* experimental */
literal|"NOTIFY"
block|,
comment|/* experimental */
literal|"UPDATE"
block|,
literal|"6"
block|,
literal|"7"
block|,
literal|"8"
block|,
literal|"9"
block|,
literal|"10"
block|,
literal|"11"
block|,
literal|"12"
block|,
literal|"13"
block|,
literal|"ZONEINIT"
block|,
literal|"ZONEREF"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_res_resultcodes
index|[]
init|=
block|{
literal|"NOERROR"
block|,
literal|"FORMERR"
block|,
literal|"SERVFAIL"
block|,
literal|"NXDOMAIN"
block|,
literal|"NOTIMP"
block|,
literal|"REFUSED"
block|,
literal|"YXDOMAIN"
block|,
literal|"YXRRSET"
block|,
literal|"NXRRSET"
block|,
literal|"NOTAUTH"
block|,
literal|"ZONEERR"
block|,
literal|"11"
block|,
literal|"12"
block|,
literal|"13"
block|,
literal|"14"
block|,
literal|"NOCHANGE"
block|, }
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_res_sectioncodes
index|[]
init|=
block|{
literal|"ZONE"
block|,
literal|"PREREQUISITES"
block|,
literal|"UPDATE"
block|,
literal|"ADDITIONAL"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

