begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Storage (somewhat) used by checknews  */
end_comment

begin_include
include|#
directive|include
file|"iparams.h"
end_include

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

begin_decl_stmt
name|int
name|ROOTID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special users id # */
end_comment

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

end_unit

