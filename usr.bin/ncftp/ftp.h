begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftp.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ftp_h_
end_ifndef

begin_define
define|#
directive|define
name|_ftp_h_
end_define

begin_comment
comment|/*  $RCSfile: ftp.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/07/09 11:04:12 $  */
end_comment

begin_define
define|#
directive|define
name|IS_FILE
value|1
end_define

begin_define
define|#
directive|define
name|IS_STREAM
value|0
end_define

begin_define
define|#
directive|define
name|IS_PIPE
value|-1
end_define

begin_comment
comment|/* Progress-meter types. */
end_comment

begin_define
define|#
directive|define
name|pr_none
value|0
end_define

begin_define
define|#
directive|define
name|pr_percent
value|1
end_define

begin_define
define|#
directive|define
name|pr_philbar
value|2
end_define

begin_define
define|#
directive|define
name|pr_kbytes
value|3
end_define

begin_define
define|#
directive|define
name|pr_dots
value|4
end_define

begin_define
define|#
directive|define
name|pr_last
value|pr_dots
end_define

begin_comment
comment|/* Values sent to CommandWithFlags() to determine whether to read a reply  * from the remote host after sending the command.  */
end_comment

begin_define
define|#
directive|define
name|DONT_WAIT_FOR_REPLY
value|0
end_define

begin_define
define|#
directive|define
name|WAIT_FOR_REPLY
value|1
end_define

begin_comment
comment|/* Expect EOF values for getreply() */
end_comment

begin_define
define|#
directive|define
name|DONT_EXPECT_EOF
value|0
end_define

begin_define
define|#
directive|define
name|EXPECT_EOF
value|1
end_define

begin_function_decl
name|int
name|hookup
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Login
parameter_list|(
name|char
modifier|*
name|userNamePtr
parameter_list|,
name|char
modifier|*
name|passWordPtr
parameter_list|,
name|char
modifier|*
name|accountPtr
parameter_list|,
name|int
name|doInit
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|cmdabort
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|CommandWithFlags
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|command
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|command_noreply
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quiet_command
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verbose_command
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getreply
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_progress
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|progress_report
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|end_progress
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_file
parameter_list|(
name|FILE
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|abortsend
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|sendrequest
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|abortrecv
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|GetLSRemoteDir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AdjustLocalFileName
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SetToAsciiForLS
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|IssueCommand
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|OpenOutputFile
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Sig_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReceiveBinary
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddRedirLine
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReceiveAscii
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CloseOutputFile
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ResetOldType
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FileType
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CloseData
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recvrequest
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initconn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|dataconn
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ftp_h_ */
end_comment

begin_comment
comment|/* eof ftp.h */
end_comment

end_unit

