begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iextern - external definitions for inews.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)iextern.c	2.4	3/27/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"iparams.h"
end_include

begin_comment
comment|/*  * The following definitions are only effective if they are not previously  * defined in the makefile.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPOOLDIR
end_ifndef

begin_comment
comment|/* NOTE:  The following line does NOT have a trailing quote. */
end_comment

begin_define
define|#
directive|define
name|SPOOLDIR
value|"/usr/spool/news
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBDIR
end_ifndef

begin_comment
comment|/* NOTE:  The following line does NOT have a trailing quote. */
end_comment

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/lib/news
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEWSUSR
end_ifndef

begin_define
define|#
directive|define
name|NEWSUSR
value|"daemon"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEWSGRP
end_ifndef

begin_define
define|#
directive|define
name|NEWSGRP
value|"daemon"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|unsigned
name|uid
decl_stmt|,
name|gid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real user/group I.D. */
end_comment

begin_decl_stmt
name|unsigned
name|duid
decl_stmt|,
name|dgid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* effective user/group I.D. */
end_comment

begin_decl_stmt
name|int
name|sigtrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if signal trapped */
end_comment

begin_decl_stmt
name|int
name|savmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old umask */
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode of news program */
end_comment

begin_decl_stmt
name|int
name|lockcount
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no. of times we've called lock */
end_comment

begin_decl_stmt
name|struct
name|hbuf
name|header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general-use header structure */
end_comment

begin_decl_stmt
name|char
name|bfr
index|[
name|LBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general-use scratch area */
end_comment

begin_decl_stmt
name|char
name|filename
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general-use file name */
end_comment

begin_decl_stmt
name|char
name|username
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's login name */
end_comment

begin_decl_stmt
name|char
name|userhome
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's home directory */
end_comment

begin_decl_stmt
name|char
name|SPOOL
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spool directory */
end_comment

begin_decl_stmt
name|char
name|LIB
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* library directory */
end_comment

begin_decl_stmt
name|char
name|INFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* template for temp of stdin */
end_comment

begin_decl_stmt
name|char
name|LOCKFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system lock file */
end_comment

begin_decl_stmt
name|char
name|SEQFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system sequence no. file */
end_comment

begin_decl_stmt
name|char
name|ACTIVE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active newsgroups file */
end_comment

begin_decl_stmt
name|char
name|NGFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* legal newsgroups file */
end_comment

begin_decl_stmt
name|char
name|SUBFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system subscriptions */
end_comment

begin_decl_stmt
name|char
name|ARTFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all articles seen */
end_comment

begin_decl_stmt
name|char
name|ARTICLE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary article */
end_comment

begin_decl_stmt
name|char
name|STASH
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dir for un-recognized articles */
end_comment

begin_decl_stmt
name|char
name|logfname
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the log file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ROOTID
end_ifndef

begin_decl_stmt
name|int
name|ROOTID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special users id # */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOTIFY
end_ifdef

begin_decl_stmt
name|char
name|TELLFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* notify the user in this file */
end_comment

begin_decl_stmt
name|char
name|TELLME
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the user to tell */
end_comment

begin_endif
endif|#
directive|endif
endif|NOTIFY
end_endif

begin_decl_stmt
name|char
name|SYSNAME
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* truncated system name */
end_comment

begin_decl_stmt
name|char
name|FULLSYSNAME
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* full system name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|NEWSU
init|=
name|NEWSUSR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* login name for netnews */
end_comment

begin_decl_stmt
name|char
modifier|*
name|NEWSG
init|=
name|NEWSGRP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group name for netnews */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DFLTNG
init|=
literal|"general"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default newsgroup */
end_comment

begin_decl_stmt
name|char
name|whatever
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't ask:  kludge */
end_comment

begin_decl_stmt
name|char
name|nbuf
index|[
name|LBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local newsgroup buffer */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|infp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file-pointer */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|actfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active newsgroups file pointer */
end_comment

begin_decl_stmt
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if infp is a tty */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PARTIAL
init|=
literal|"dead.article"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place to save partial news */
end_comment

begin_decl_stmt
name|int
name|flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if at least one group O.K. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SHELL
init|=
literal|"/bin/sh"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell for inews to use	*/
end_comment

begin_decl_stmt
name|int
name|defexp
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if def. expiration date used */
end_comment

begin_decl_stmt
name|int
name|is_ctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true for a control message */
end_comment

end_unit

