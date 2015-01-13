begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: extern.h,v 1.39 2014/04/24 17:22:41 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_include
include|#
directive|include
file|"mtree.h"
end_include

begin_if
if|#
directive|if
name|HAVE_NBTOOL_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_FLAGS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|<util.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_if
if|#
directive|if
name|HAVE_NETDB_H
end_if

begin_comment
comment|/* For MAXHOSTNAMELEN on some platforms. */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|flavor
block|{
name|F_MTREE
block|,
name|F_FREEBSD9
block|,
name|F_NETBSD6
block|}
enum|;
end_enum

begin_function_decl
name|void
name|addtag
parameter_list|(
name|slist_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_excludes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compare
parameter_list|(
name|NODE
modifier|*
parameter_list|,
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crc
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cwalk
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_nodes
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|NODE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_excludes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|matchtags
parameter_list|(
name|NODE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__dead
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|void
name|mtree_err
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|nodetype
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|parsekey
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parsetags
parameter_list|(
name|slist_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|parsetype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_excludes_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|rlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_only
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|find_only
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|bflag
decl_stmt|,
name|dflag
decl_stmt|,
name|eflag
decl_stmt|,
name|iflag
decl_stmt|,
name|jflag
decl_stmt|,
name|lflag
decl_stmt|,
name|mflag
decl_stmt|,
name|nflag
decl_stmt|,
name|qflag
decl_stmt|,
name|rflag
decl_stmt|,
name|sflag
decl_stmt|,
name|tflag
decl_stmt|,
name|uflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mtree_Mflag
decl_stmt|,
name|mtree_Sflag
decl_stmt|,
name|mtree_Wflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|mtree_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|flavor
name|flavor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|crc_total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftsoptions
decl_stmt|,
name|keys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|fullpath
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|slist_t
name|includetags
decl_stmt|,
name|excludetags
decl_stmt|;
end_decl_stmt

end_unit

