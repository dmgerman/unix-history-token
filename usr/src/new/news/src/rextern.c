begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rextern - external definitions for readnews  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)rextern.c	2.17	11/21/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"rparams.h"
end_include

begin_decl_stmt
name|int
name|uid
decl_stmt|,
name|gid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real user/group I.D.		*/
end_comment

begin_decl_stmt
name|int
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
name|SigTrap
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
name|int
name|ngrp
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
modifier|*
name|bitmap
decl_stmt|,
modifier|*
name|argvrc
index|[
name|LINES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bit
decl_stmt|,
name|obit
decl_stmt|,
name|last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|readmode
init|=
name|NEXT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|news
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Was there any news to read */
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
name|long
name|minartno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min article # in this newsgroup */
end_comment

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
modifier|*
name|PAGER
init|=
literal|""
decl_stmt|;
end_decl_stmt

end_unit

