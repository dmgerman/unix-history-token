begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	From: @(#)lp.h	8.2 (Berkeley) 4/28/95  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * All this information used to be in global static variables shared  * mysteriously by various parts of the lpr/lpd suite.  * This structure attempts to centralize all these declarations in the  * hope that they can later be made more dynamic.  */
end_comment

begin_enum
enum|enum
name|lpd_filters
block|{
name|LPF_CIFPLOT
block|,
name|LPF_DVI
block|,
name|LPF_GRAPH
block|,
name|LPF_INPUT
block|,
name|LPF_DITROFF
block|,
name|LPF_OUTPUT
block|,
name|LPF_FORTRAN
block|,
name|LPF_TROFF
block|,
name|LPF_RASTER
block|,
name|LPF_COUNT
block|}
enum|;
end_enum

begin_comment
comment|/* NB: there is a table in common.c giving the mapping from capability names */
end_comment

begin_struct
struct|struct
name|printer
block|{
name|char
modifier|*
name|printer
decl_stmt|;
comment|/* printer name */
name|int
name|remote
decl_stmt|;
comment|/* true if RM points to a remote host */
name|int
name|tof
decl_stmt|;
comment|/* true if we are at top-of-form */
comment|/* ------------------------------------------------------ */
name|char
modifier|*
name|acct_file
decl_stmt|;
comment|/* AF: accounting file */
name|long
name|baud_rate
decl_stmt|;
comment|/* BR: baud rate if lp is a tty */
name|char
modifier|*
name|filters
index|[
name|LPF_COUNT
index|]
decl_stmt|;
comment|/* CF, DF, GF, IF, NF, OF, RF, TF, VF */
name|long
name|conn_timeout
decl_stmt|;
comment|/* CT: TCP connection timeout */
name|long
name|daemon_user
decl_stmt|;
comment|/* DU: daemon user id -- XXX belongs ???? */
name|char
modifier|*
name|form_feed
decl_stmt|;
comment|/* FF: form feed */
name|long
name|header_last
decl_stmt|;
comment|/* HL: print header last */
name|char
modifier|*
name|log_file
decl_stmt|;
comment|/* LF: log file */
name|char
modifier|*
name|lock_file
decl_stmt|;
comment|/* LO: lock file */
name|char
modifier|*
name|lp
decl_stmt|;
comment|/* LP: device name or network address */
name|long
name|max_copies
decl_stmt|;
comment|/* MC: maximum number of copies allowed */
name|long
name|max_blocks
decl_stmt|;
comment|/* MX: maximum number of blocks to copy */
name|long
name|price100
decl_stmt|;
comment|/* PC: price per 100 units of output */
name|long
name|page_length
decl_stmt|;
comment|/* PL: page length */
name|long
name|page_width
decl_stmt|;
comment|/* PW: page width */
name|long
name|page_pwidth
decl_stmt|;
comment|/* PX: page width in pixels */
name|long
name|page_plength
decl_stmt|;
comment|/* PY: page length in pixels */
name|char
modifier|*
name|restrict_grp
decl_stmt|;
comment|/* RG: restricted group */
name|char
modifier|*
name|remote_host
decl_stmt|;
comment|/* RM: remote machine name */
name|char
modifier|*
name|remote_queue
decl_stmt|;
comment|/* RP: remote printer name */
name|long
name|restricted
decl_stmt|;
comment|/* RS: restricted to those with local accts */
name|long
name|rw
decl_stmt|;
comment|/* RW: open LP for reading and writing */
name|long
name|short_banner
decl_stmt|;
comment|/* SB: short banner */
name|long
name|no_copies
decl_stmt|;
comment|/* SC: suppress multiple copies */
name|char
modifier|*
name|spool_dir
decl_stmt|;
comment|/* SD: spool directory */
name|long
name|no_formfeed
decl_stmt|;
comment|/* SF: suppress FF on each print job */
name|long
name|no_header
decl_stmt|;
comment|/* SH: suppress header page */
name|char
modifier|*
name|status_file
decl_stmt|;
comment|/* ST: status file name */
name|char
modifier|*
name|trailer
decl_stmt|;
comment|/* TR: trailer string send when Q empties */
name|char
modifier|*
name|mode_set
decl_stmt|;
comment|/* MS: mode set, a la stty */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Lists of user names and job numbers, for the benefit of the structs  * defined below.  We use TAILQs so that requests don't get mysteriously  * reversed in process.  */
end_comment

begin_struct
struct|struct
name|req_user
block|{
name|TAILQ_ENTRY
argument_list|(
argument|req_user
argument_list|)
name|ru_link
expr_stmt|;
comment|/* macro glue */
name|char
name|ru_uname
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of user */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|req_user_head
argument_list|,
name|req_user
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|req_file
block|{
name|TAILQ_ENTRY
argument_list|(
argument|req_file
argument_list|)
name|rf_link
expr_stmt|;
comment|/* macro glue */
name|char
name|rf_type
decl_stmt|;
comment|/* type (lowercase cf file letter) of file */
name|char
modifier|*
name|rf_prettyname
decl_stmt|;
comment|/* user-visible name of file */
name|char
name|rf_fname
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of file */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|req_file_head
argument_list|,
name|req_file
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|req_jobid
block|{
name|TAILQ_ENTRY
argument_list|(
argument|req_jobid
argument_list|)
name|rj_link
expr_stmt|;
comment|/* macro glue */
name|int
name|rj_job
decl_stmt|;
comment|/* job number */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|req_jobid_head
argument_list|,
name|req_jobid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Encapsulate all the information relevant to a request in the  * lpr/lpd protocol.  */
end_comment

begin_enum
enum|enum
name|req_type
block|{
name|REQ_START
block|,
name|REQ_RECVJOB
block|,
name|REQ_LIST
block|,
name|REQ_DELETE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|request
block|{
name|enum
name|req_type
name|type
decl_stmt|;
comment|/* what sort of request is this? */
name|struct
name|printer
name|prtr
decl_stmt|;
comment|/* which printer is it for? */
name|int
name|remote
decl_stmt|;
comment|/* did request arrive over network? */
name|char
modifier|*
name|logname
decl_stmt|;
comment|/* login name of requesting user */
name|char
modifier|*
name|authname
decl_stmt|;
comment|/* authenticated identity of requesting user */
name|char
modifier|*
name|prettyname
decl_stmt|;
comment|/* ``pretty'' name of requesting user */
name|int
name|privileged
decl_stmt|;
comment|/* was the request from a privileged user? */
name|void
modifier|*
name|authinfo
decl_stmt|;
comment|/* authentication information */
name|int
name|authentic
decl_stmt|;
comment|/* was the request securely authenticated? */
comment|/* Information for queries and deletes... */
name|int
name|nusers
decl_stmt|;
comment|/* length of following list... */
name|struct
name|req_user_head
name|users
decl_stmt|;
comment|/* list of users to query/delete */
name|int
name|njobids
decl_stmt|;
comment|/* length of following list... */
name|struct
name|req_jobid_head
name|jobids
decl_stmt|;
comment|/* list of jobids to query/delete */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global definitions for the line printer system.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_comment
comment|/* host machine name */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|from
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client's machine name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|requ
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* job number of spool entries */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|requests
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of spool requests */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|user
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* users to process */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|users
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of users in user array */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|person
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of person doing lprm */
end_comment

begin_comment
comment|/*  * Structure used for building a sorted list of control files.  */
end_comment

begin_struct
struct|struct
name|queue
block|{
name|time_t
name|q_time
decl_stmt|;
comment|/* modification time */
name|char
name|q_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* control file name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error codes for our mini printcap library.  */
end_comment

begin_define
define|#
directive|define
name|PCAPERR_TCLOOP
value|(-3)
end_define

begin_define
define|#
directive|define
name|PCAPERR_OSERR
value|(-2)
end_define

begin_define
define|#
directive|define
name|PCAPERR_NOTFOUND
value|(-1)
end_define

begin_define
define|#
directive|define
name|PCAPERR_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|PCAPERR_TCOPEN
value|1
end_define

begin_comment
comment|/*  * File modes for the various status files maintained by lpd.  */
end_comment

begin_define
define|#
directive|define
name|LOCK_FILE_MODE
value|(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
end_define

begin_define
define|#
directive|define
name|LFM_PRINT_DIS
value|(S_IXUSR)
end_define

begin_define
define|#
directive|define
name|LFM_QUEUE_DIS
value|(S_IXGRP)
end_define

begin_define
define|#
directive|define
name|LFM_RESET_QUE
value|(S_IXOTH)
end_define

begin_define
define|#
directive|define
name|STAT_FILE_MODE
value|(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
end_define

begin_define
define|#
directive|define
name|LOG_FILE_MODE
value|(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
end_define

begin_define
define|#
directive|define
name|TEMP_FILE_MODE
value|(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
end_define

begin_comment
comment|/*  * Command codes used in the protocol.  */
end_comment

begin_define
define|#
directive|define
name|CMD_CHECK_QUE
value|'\1'
end_define

begin_define
define|#
directive|define
name|CMD_TAKE_THIS
value|'\2'
end_define

begin_define
define|#
directive|define
name|CMD_SHOWQ_SHORT
value|'\3'
end_define

begin_define
define|#
directive|define
name|CMD_SHOWQ_LONG
value|'\4'
end_define

begin_define
define|#
directive|define
name|CMD_RMJOB
value|'\5'
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|blankfill
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|checkremote
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chk
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|closeallfds
name|__P
argument_list|(
operator|(
name|int
name|start
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|delay
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
name|displayq
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|,
name|int
name|format
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dump
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
specifier|const
name|char
operator|*
name|fmp
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|firstprinter
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|,
name|int
operator|*
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_printer
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_request
name|__P
argument_list|(
operator|(
expr|struct
name|request
operator|*
name|rp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getline
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getport
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getprintcap
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|printer
operator|,
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getq
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
operator|,
expr|struct
name|queue
operator|*
operator|(
operator|*
index|[]
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|header
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|inform
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
name|char
operator|*
name|cf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_printer
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_request
name|__P
argument_list|(
operator|(
expr|struct
name|request
operator|*
name|rp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inlist
name|__P
argument_list|(
operator|(
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
name|int
name|iscf
name|__P
argument_list|(
operator|(
expr|struct
name|dirent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isowner
name|__P
argument_list|(
operator|(
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
name|void
name|ldump
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lastprinter
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lockchk
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
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
name|lock_file_name
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
name|char
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nextprinter
name|__P
argument_list|(
operator|(
expr|struct
name|printer
operator|*
name|pp
operator|,
name|int
operator|*
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|pcaperr
name|__P
argument_list|(
operator|(
name|int
name|error
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prank
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
name|process
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rmjob
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|printer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rmremote
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setprintcap
name|__P
argument_list|(
operator|(
name|char
operator|*
name|newprintcap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|startdaemon
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|status_file_name
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|printer
operator|*
name|pp
operator|,
name|char
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|writel
name|__P
argument_list|(
operator|(
name|int
name|s
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

