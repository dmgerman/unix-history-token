begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)bug.h	1.1 (Berkeley) 11/25/86  */
end_comment

begin_define
define|#
directive|define
name|BUGS_HOME
value|"owner-bugs@ucbvax.BERKELEY.EDU"
end_define

begin_define
define|#
directive|define
name|BUGS_ID
value|"bugs"
end_define

begin_define
define|#
directive|define
name|MAIL_CMD
value|"/usr/lib/sendmail -i -t -F \"Bugs Bunny\" -f owner-bugs@ucbvax.BERKELEY.EDU"
end_define

begin_comment
comment|/*  * the METOO definition has the bugfiler exit with an error (-1) status  * if there's a problem.  Sendmail then mails off a copy of the problem  * mail to "owner-bugs".  This is great if you would have otherwise lost  * the bug report.  It's not so great if you get a whole bunch of mail  * that you really don't want.  */
end_comment

begin_define
define|#
directive|define
name|METOO
end_define

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_define
define|#
directive|define
name|GET_LOCK
value|{ \ 	if (flock(lfd,LOCK_EX)) { \ 		perror(LOCK_FILE); \ 		exit(ERR); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|REL_LOCK
value|{ \ 	if (flock(lfd,LOCK_UN)) { \ 		perror(LOCK_FILE); \ 		exit(ERR); \ 	} \ }
end_define

begin_comment
comment|/* files */
end_comment

begin_define
define|#
directive|define
name|ACK_FILE
value|".ack"
end_define

begin_comment
comment|/* acknowledge file */
end_comment

begin_define
define|#
directive|define
name|DEF_DIR
value|"mail"
end_define

begin_comment
comment|/* top-level directory */
end_comment

begin_define
define|#
directive|define
name|DIST_FILE
value|".redist"
end_define

begin_comment
comment|/* redistribution file */
end_comment

begin_define
define|#
directive|define
name|ERROR_FILE
value|"log"
end_define

begin_comment
comment|/* error file */
end_comment

begin_define
define|#
directive|define
name|LOCK_FILE
value|"bug:lock"
end_define

begin_comment
comment|/* lock file name */
end_comment

begin_define
define|#
directive|define
name|SUMMARY_FILE
value|"summary"
end_define

begin_comment
comment|/* summary file */
end_comment

begin_define
define|#
directive|define
name|TMP_BUG
value|"errors/BUG_XXXXXX"
end_define

begin_comment
comment|/* tmp bug report */
end_comment

begin_define
define|#
directive|define
name|TMP_FILE
value|"/tmp/BUG_XXXXXX"
end_define

begin_comment
comment|/* tmp file name */
end_comment

begin_comment
comment|/* permissions */
end_comment

begin_define
define|#
directive|define
name|DIR_MODE
value|0750
end_define

begin_comment
comment|/* directory creation mode */
end_comment

begin_define
define|#
directive|define
name|FILE_MODE
value|0644
end_define

begin_comment
comment|/* file creation mode */
end_comment

begin_define
define|#
directive|define
name|CHN
value|(char *)NULL
end_define

begin_comment
comment|/* null arg string */
end_comment

begin_define
define|#
directive|define
name|COMMENT
value|'#'
end_define

begin_comment
comment|/* comment in redist file */
end_comment

begin_define
define|#
directive|define
name|EOS
value|(char)NULL
end_define

begin_comment
comment|/* end of string */
end_comment

begin_define
define|#
directive|define
name|ERR
value|-1
end_define

begin_comment
comment|/* error return */
end_comment

begin_define
define|#
directive|define
name|MAXLINELEN
value|200
end_define

begin_comment
comment|/* max line length in message */
end_comment

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_comment
comment|/* no/false */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_comment
comment|/* okay return */
end_comment

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_comment
comment|/* yes/true */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|found
decl_stmt|,
comment|/* line number if found */
name|redist
decl_stmt|;
comment|/* if part of redist headers */
name|int
function_decl|(
modifier|*
name|valid
function_decl|)
parameter_list|()
function_decl|;
comment|/* validation routine */
name|short
name|len
decl_stmt|;
comment|/* length of tag */
name|char
modifier|*
name|tag
decl_stmt|,
comment|/* leading tag */
modifier|*
name|line
decl_stmt|;
comment|/* actual line */
block|}
name|HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DATE_TAG
value|0
end_define

begin_comment
comment|/* "Date:" offset */
end_comment

begin_define
define|#
directive|define
name|FROM_TAG
value|1
end_define

begin_comment
comment|/* "From " offset */
end_comment

begin_define
define|#
directive|define
name|CFROM_TAG
value|2
end_define

begin_comment
comment|/* "From:" offset */
end_comment

begin_define
define|#
directive|define
name|INDX_TAG
value|3
end_define

begin_comment
comment|/* "Index:" offset */
end_comment

begin_define
define|#
directive|define
name|MSG_TAG
value|4
end_define

begin_comment
comment|/* "Message-Id:" offset */
end_comment

begin_define
define|#
directive|define
name|RPLY_TAG
value|5
end_define

begin_comment
comment|/* "Reply-To:" offset */
end_comment

begin_define
define|#
directive|define
name|RET_TAG
value|6
end_define

begin_comment
comment|/* "Return-Path:" offset */
end_comment

begin_define
define|#
directive|define
name|SUBJ_TAG
value|7
end_define

begin_comment
comment|/* "Subject:" offset */
end_comment

begin_define
define|#
directive|define
name|TO_TAG
value|8
end_define

begin_comment
comment|/* "To:" offset */
end_comment

begin_comment
comment|/* so sizeof doesn't return 0 */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|bfr
index|[
name|MAXBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general I/O buffer */
end_comment

end_unit

