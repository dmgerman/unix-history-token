begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: nntpclient.h,v 3.0 1992/12/14 00:14:55 davison Trn $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NNTP
end_ifdef

begin_decl_stmt
name|int
name|server_init
name|_
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
name|nntp_connect
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nntp_command
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|nntp_check
name|_
argument_list|(
operator|(
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nntp_gets
name|_
argument_list|(
operator|(
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
name|nntp_close
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RFC 977 defines these, so don't change them */
end_comment

begin_define
define|#
directive|define
name|NNTP_CLASS_INF
value|'1'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_OK
value|'2'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_CONT
value|'3'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_ERR
value|'4'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_FATAL
value|'5'
end_define

begin_define
define|#
directive|define
name|NNTP_POSTOK_VAL
value|200
end_define

begin_comment
comment|/* Hello -- you can post */
end_comment

begin_define
define|#
directive|define
name|NNTP_NOPOSTOK_VAL
value|201
end_define

begin_comment
comment|/* Hello -- you can't post */
end_comment

begin_define
define|#
directive|define
name|NNTP_GOODBYE_VAL
value|400
end_define

begin_comment
comment|/* Have to hang up for some reason */
end_comment

begin_define
define|#
directive|define
name|NNTP_NOSUCHGROUP_VAL
value|411
end_define

begin_comment
comment|/* No such newsgroup */
end_comment

begin_define
define|#
directive|define
name|NNTP_AUTH_NEEDED_VAL
value|480
end_define

begin_comment
comment|/* Authorization Failed */
end_comment

begin_define
define|#
directive|define
name|NNTP_AUTH_REJECT_VAL
value|482
end_define

begin_comment
comment|/* Authorization data rejected */
end_comment

begin_define
define|#
directive|define
name|NNTP_BAD_COMMAND_VAL
value|500
end_define

begin_comment
comment|/* Command not recognized */
end_comment

begin_define
define|#
directive|define
name|NNTP_SYNTAX_VAL
value|501
end_define

begin_comment
comment|/* Command syntax error */
end_comment

begin_define
define|#
directive|define
name|NNTP_ACCESS_VAL
value|502
end_define

begin_comment
comment|/* Access to server denied */
end_comment

begin_define
define|#
directive|define
name|NNTP_TMPERR_VAL
value|503
end_define

begin_comment
comment|/* Program fault, command not performed */
end_comment

begin_define
define|#
directive|define
name|NNTP_AUTH_BAD_VAL
value|580
end_define

begin_comment
comment|/* Authorization Failed */
end_comment

begin_define
define|#
directive|define
name|NNTP_STRLEN
value|512
end_define

begin_function_decl
name|EXT
name|FILE
modifier|*
name|ser_rd_fp
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|FILE
modifier|*
name|ser_wr_fp
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|ser_line
index|[
name|NNTP_STRLEN
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_NNTP */
end_comment

end_unit

