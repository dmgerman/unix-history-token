begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)bug.h	5.7 (Berkeley) 6/29/88  */
end_comment

begin_define
define|#
directive|define
name|BUGS_HOME
value|"owner-bugs@ucbvax.Berkeley.EDU"
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
value|"/usr/lib/sendmail -i -t -F \"Bugs Bunny\" -f owner-bugs"
end_define

begin_comment
comment|/*  * the METOO definition has the bugfiler exit with an error (-1) status  * if there's a problem.  This causes sendmail to send off a copy of the  * report (as failed mail) to the "owner" of the mail alias that executed  * the bugfiler.  This is great if you would have otherwise lost the bug  * report.  It's not so great if you get a whole bunch of mail that you  * really don't want.  */
end_comment

begin_define
define|#
directive|define
name|METOO
end_define

begin_comment
comment|/* files */
end_comment

begin_define
define|#
directive|define
name|ACK_FILE
value|"bug:ack"
end_define

begin_comment
comment|/* acknowledge file */
end_comment

begin_define
define|#
directive|define
name|DIST_FILE
value|"bug:redist"
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
name|TMP_DIR
value|"errors"
end_define

begin_comment
comment|/* tmp directory */
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

begin_decl_stmt
specifier|extern
name|HEADER
name|mailhead
index|[]
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|APPAR_TO_TAG
value|9
end_define

begin_comment
comment|/* "Apparently-To:" offset */
end_comment

begin_comment
comment|/* so sizeof doesn't return 0 */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|bfr
index|[
name|MAXBSIZE
index|]
decl_stmt|,
comment|/* general I/O buffer */
name|dir
index|[
name|MAXNAMLEN
index|]
decl_stmt|,
comment|/* subject and folder */
name|folder
index|[
name|MAXNAMLEN
index|]
decl_stmt|,
name|tmpname
index|[
sizeof|sizeof
argument_list|(
name|TMP_BUG
argument_list|)
operator|+
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temp bug file */
end_comment

end_unit

