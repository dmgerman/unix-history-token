begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	From: @(#)lp.h	8.2 (Berkeley) 4/28/95  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
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
name|rp_matches_local
decl_stmt|;
comment|/* true if rp has same name as us */
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
name|stat_recv
decl_stmt|;
comment|/* SR: statistics file, receiving jobs */
name|char
modifier|*
name|stat_send
decl_stmt|;
comment|/* SS: statistics file, sending jobs */
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
comment|/* variables used by trstat*() to keep statistics on file transfers */
define|#
directive|define
name|JOBNUM_SIZE
value|8
name|char
name|jobnum
index|[
name|JOBNUM_SIZE
index|]
decl_stmt|;
name|long
name|jobdfnum
decl_stmt|;
comment|/* current datafile number within job */
name|struct
name|timespec
name|tr_start
decl_stmt|,
name|tr_done
decl_stmt|;
define|#
directive|define
name|TIMESTR_SIZE
value|40
comment|/* holds result from LPD_TIMESTAMP_PATTERN */
name|char
name|tr_timestr
index|[
name|TIMESTR_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|DIFFTIME_TS
parameter_list|(
name|endTS
parameter_list|,
name|startTS
parameter_list|)
define|\
value|((double)(endTS.tv_sec - startTS.tv_sec) \ 		+ (endTS.tv_nsec - startTS.tv_nsec) * 1.0e-9)
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
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name (lpr, lpq, etc) */
end_comment

begin_comment
comment|/*      * 'local_host' is the name of the machine that lpd (lpr, whatever)      * is actually running on.      *      * 'from_host' will point to the 'host' variable when receiving a job      * from a user on the same host, or "somewhere else" when receiving a      * job from a remote host.  If 'from_host != local_host', then 'from_ip'      * is the character representation of the IP address of from_host (note      * that string could be an IPv6 address).      *      * Also note that when 'from_host' is not pointing at 'local_host', the      * string it is pointing at may be as long as NI_MAXHOST (which is very      * likely to be much longer than MAXHOSTNAMELEN).      */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|local_host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|from_host
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client's machine name */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|from_ip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client machine's IP address */
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

begin_decl_stmt
specifier|extern
name|u_char
name|family
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address family */
end_comment

begin_comment
comment|/*  * Structure used for building a sorted list of control files.  */
end_comment

begin_struct
struct|struct
name|jobqueue
block|{
name|time_t
name|job_time
decl_stmt|;
comment|/* last-mod time of cf-file */
name|char
name|job_cfname
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
comment|/* lpr/lpd generates readable timestamps for logfiles, etc.  Have all those  * timestamps be in the same format wrt strftime().  This is ISO 8601 format,  * with the addition of an easy-readable day-of-the-week field.  Note that  * '%T' = '%H:%M:%S', and that '%z' is not available on all platforms.  */
end_comment

begin_define
define|#
directive|define
name|LPD_TIMESTAMP_PATTERN
value|"%Y-%m-%dT%T%z %a"
end_define

begin_comment
comment|/*  * Codes to indicate which statistic records trstat_write should write.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TR_SENDING
block|,
name|TR_RECVING
block|,
name|TR_PRINTING
block|}
name|tr_sendrecv
typedef|;
end_typedef

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

begin_function_decl
name|void
name|blankfill
parameter_list|(
name|int
name|_tocol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|checkremote
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chk
parameter_list|(
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closeallfds
parameter_list|(
name|int
name|_start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delay
parameter_list|(
name|int
name|_millisec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|displayq
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|int
name|_format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump
parameter_list|(
specifier|const
name|char
modifier|*
name|_nfile
parameter_list|,
specifier|const
name|char
modifier|*
name|_datafile
parameter_list|,
name|int
name|_copies
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
specifier|const
name|char
modifier|*
name|_msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|firstprinter
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|int
modifier|*
name|_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_printer
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_request
parameter_list|(
name|struct
name|request
modifier|*
name|_rp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getline
parameter_list|(
name|FILE
modifier|*
name|_cfp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getport
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
specifier|const
name|char
modifier|*
name|_rhost
parameter_list|,
name|int
name|_rport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getprintcap
parameter_list|(
specifier|const
name|char
modifier|*
name|_printer
parameter_list|,
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|getq
argument_list|(
specifier|const
expr|struct
name|printer
operator|*
name|_pp
argument_list|,
expr|struct
name|jobqueue
operator|*
operator|(
operator|*
name|_namelist
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|header
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inform
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|char
modifier|*
name|_cf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_printer
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_request
parameter_list|(
name|struct
name|request
modifier|*
name|_rp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inlist
parameter_list|(
name|char
modifier|*
name|_uname
parameter_list|,
name|char
modifier|*
name|_cfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iscf
parameter_list|(
name|struct
name|dirent
modifier|*
name|_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isowner
parameter_list|(
name|char
modifier|*
name|_owner
parameter_list|,
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ldump
parameter_list|(
specifier|const
name|char
modifier|*
name|_nfile
parameter_list|,
specifier|const
name|char
modifier|*
name|_datafile
parameter_list|,
name|int
name|_copies
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lastprinter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockchk
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|char
modifier|*
name|_slockf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lock_file_name
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lpd_gettime
parameter_list|(
name|struct
name|timespec
modifier|*
name|_tsp
parameter_list|,
name|char
modifier|*
name|_strp
parameter_list|,
name|size_t
name|_strsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nextprinter
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|int
modifier|*
name|_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pcaperr
parameter_list|(
name|int
name|_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prank
parameter_list|(
name|int
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmjob
parameter_list|(
specifier|const
name|char
modifier|*
name|_printer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmremote
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setprintcap
parameter_list|(
name|char
modifier|*
name|_newfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show
parameter_list|(
specifier|const
name|char
modifier|*
name|_nfile
parameter_list|,
specifier|const
name|char
modifier|*
name|_datafile
parameter_list|,
name|int
name|_copies
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|startdaemon
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|status_file_name
parameter_list|(
specifier|const
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trstat_init
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
specifier|const
name|char
modifier|*
name|_fname
parameter_list|,
name|int
name|_filenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trstat_write
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|,
name|tr_sendrecv
name|_sendrecv
parameter_list|,
name|size_t
name|_bytecnt
parameter_list|,
specifier|const
name|char
modifier|*
name|_userid
parameter_list|,
specifier|const
name|char
modifier|*
name|_otherhost
parameter_list|,
specifier|const
name|char
modifier|*
name|_orighost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|writel
parameter_list|(
name|int
name|_strm
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

