begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997, 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	gtagsop.h				23-Dec-97  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GTOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_GTOP_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"dbop.h"
end_include

begin_include
include|#
directive|include
file|"gparam.h"
end_include

begin_include
include|#
directive|include
file|"strbuf.h"
end_include

begin_define
define|#
directive|define
name|VERSIONKEY
value|" __.VERSION"
end_define

begin_define
define|#
directive|define
name|COMPACTKEY
value|" __.COMPACT"
end_define

begin_define
define|#
directive|define
name|PATHINDEXKEY
value|" __.PATHINDEX"
end_define

begin_define
define|#
directive|define
name|GTAGS
value|0
end_define

begin_define
define|#
directive|define
name|GRTAGS
value|1
end_define

begin_define
define|#
directive|define
name|GSYMS
value|2
end_define

begin_define
define|#
directive|define
name|GTAGLIM
value|3
end_define

begin_define
define|#
directive|define
name|GTAGS_READ
value|0
end_define

begin_define
define|#
directive|define
name|GTAGS_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|GTAGS_MODIFY
value|2
end_define

begin_comment
comment|/* gtagsopen() */
end_comment

begin_define
define|#
directive|define
name|GTAGS_STANDARD
value|0
end_define

begin_comment
comment|/* standard format */
end_comment

begin_define
define|#
directive|define
name|GTAGS_COMPACT
value|1
end_define

begin_comment
comment|/* compact format */
end_comment

begin_define
define|#
directive|define
name|GTAGS_PATHINDEX
value|2
end_define

begin_comment
comment|/* use path index */
end_comment

begin_comment
comment|/* gtagsadd() */
end_comment

begin_define
define|#
directive|define
name|GTAGS_UNIQUE
value|1
end_define

begin_comment
comment|/* compress duplicate lines */
end_comment

begin_define
define|#
directive|define
name|GTAGS_EXTRACTMETHOD
value|2
end_define

begin_comment
comment|/* extract method from class definition */
end_comment

begin_comment
comment|/* gtagsfirst() */
end_comment

begin_define
define|#
directive|define
name|GTOP_KEY
value|1
end_define

begin_comment
comment|/* read key part */
end_comment

begin_define
define|#
directive|define
name|GTOP_PREFIX
value|2
end_define

begin_comment
comment|/* prefixed read */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|DBOP
modifier|*
name|dbop
decl_stmt|;
comment|/* descripter of DBOP */
name|int
name|format_version
decl_stmt|;
comment|/* format version */
name|int
name|format
decl_stmt|;
comment|/* GTAGS_STANDARD, GTAGS_COMPACT */
name|int
name|mode
decl_stmt|;
comment|/* mode */
name|int
name|db
decl_stmt|;
comment|/* 0:GTAGS, 1:GRTAGS, 2:GSYMS */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|char
name|root
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* root directory of source tree */
comment|/* 	 * Stuff for compact format 	 */
name|int
name|opened
decl_stmt|;
comment|/* wether or not file opened */
name|char
modifier|*
name|line
decl_stmt|;
comment|/* current record */
name|char
name|tag
index|[
name|IDENTLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* current tag */
name|char
name|prev_tag
index|[
name|IDENTLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* previous tag */
name|char
name|path
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* current path */
name|char
name|prev_path
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* previous path */
name|STRBUF
modifier|*
name|sb
decl_stmt|;
comment|/* string buffer */
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* descriptor of 'path' */
name|char
modifier|*
name|lnop
decl_stmt|;
comment|/* current line number */
name|int
name|lno
decl_stmt|;
comment|/* integer value of 'lnop' */
block|}
name|GTOP
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dbname
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makecommand
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|STRBUF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|formatcheck
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GTOP
modifier|*
name|gtagsopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gtagsput
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gtagsget
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gtagsadd
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gtagsdelete
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gtagsfirst
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gtagsnext
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gtagsclose
name|__P
argument_list|(
operator|(
name|GTOP
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _GTOP_H_ */
end_comment

end_unit

