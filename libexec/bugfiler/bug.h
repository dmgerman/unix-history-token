begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)bug.h	8.1 (Berkeley) 6/4/93  */
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

