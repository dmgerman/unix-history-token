begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rextern - external definitions for readnews  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)rextern.c	2.5	3/30/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"rparams.h"
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
value|"/xa/glickman/news/spool
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
value|"/xa/glickman/news/lib
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
comment|/* real user/group I.D.		*/
end_comment

begin_decl_stmt
name|unsigned
name|duid
decl_stmt|,
name|dgid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* effective user/group I.D.	*/
end_comment

begin_decl_stmt
name|int
name|sigtrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if signal trapped	*/
end_comment

begin_decl_stmt
name|int
name|savmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old umask			*/
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode of news program		*/
end_comment

begin_decl_stmt
name|struct
name|hbuf
name|header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general-use header structure	*/
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
comment|/* general-use scratch area	*/
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
comment|/* user's login name		*/
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
comment|/* user's home directory	*/
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
comment|/* spool directory		*/
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
comment|/* library directory		*/
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
comment|/* active newsgroups file	*/
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
comment|/* legal newsgroups file	*/
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
comment|/* system lock file		*/
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
comment|/* system sequence no. file	*/
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
comment|/* system subscriptions		*/
end_comment

begin_decl_stmt
name|char
name|USERS
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user file			*/
end_comment

begin_decl_stmt
name|char
name|HELPFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /bin/mail help		*/
end_comment

begin_decl_stmt
name|char
name|CAESAR
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* decryptor program		*/
end_comment

begin_decl_stmt
name|char
name|MAILPARSER
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail header parser mailer	*/
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
comment|/* special users id #		*/
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
comment|/* the user to tell		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|outfile
init|=
literal|"/tmp/M1XXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file for -M and -c	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|infile
init|=
literal|"/tmp/M2XXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -T output from Mail		*/
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
comment|/* system name			*/
end_comment

begin_decl_stmt
name|char
name|SYSNAME
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system name chopped at 8	*/
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
comment|/* list of articles on system	*/
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
comment|/* login name for netnews	*/
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
comment|/* group name for netnews	*/
end_comment

begin_decl_stmt
name|int
name|ngrp
decl_stmt|,
name|last
decl_stmt|,
name|line
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|filename
index|[
name|BUFLEN
index|]
decl_stmt|,
name|coptbuf
index|[
name|BUFLEN
index|]
decl_stmt|,
name|datebuf
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|titlebuf
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|afline
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|rcfp
decl_stmt|,
modifier|*
name|actfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|atime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|newsrc
index|[
name|BUFLEN
index|]
decl_stmt|,
name|groupdir
index|[
name|BUFLEN
index|]
decl_stmt|,
modifier|*
name|rcline
index|[
name|LINES
index|]
decl_stmt|,
name|rcbuf
index|[
name|LBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|bitmap
index|[
literal|1024
index|]
decl_stmt|,
modifier|*
name|argvrc
index|[
name|LINES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bit
decl_stmt|,
name|obit
decl_stmt|,
name|readmode
init|=
name|NEXT
decl_stmt|;
end_decl_stmt

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
name|actdirect
init|=
name|FORWARD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read direction in ACTIVE file */
end_comment

begin_decl_stmt
name|int
name|rcreadok
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NEWSRC has been read OK */
end_comment

begin_decl_stmt
name|int
name|zapng
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ! out this newsgroup on next updaterc */
end_comment

begin_decl_stmt
name|long
name|ngsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max article # in this newsgroup */
end_comment

begin_decl_stmt
name|struct
name|stat
name|statbuf
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|SHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAILER
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|MAILER
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|PAGER
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

end_unit

