begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iextern - external definitions for inews.  */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
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
literal|"@(#)iextern.c	2.18	9/24/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_include
include|#
directive|include
file|"iparams.h"
end_include

begin_decl_stmt
name|int
name|uid
decl_stmt|,
name|gid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real user/group I.D. */
end_comment

begin_decl_stmt
name|int
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
name|SigTrap
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
name|char
name|filename
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general-use file name */
end_comment

begin_decl_stmt
name|char
name|not_here
index|[
name|SBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of system not to xmit to */
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
name|is_ctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true for a control message */
end_comment

begin_decl_stmt
name|char
name|is_mod
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains newsgroup if moderated */
end_comment

end_unit

