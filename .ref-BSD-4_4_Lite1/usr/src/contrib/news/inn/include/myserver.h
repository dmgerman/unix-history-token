begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** **  Replacement "server.h" file for remote rn. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NNTP_CLASS_OK
argument_list|)
end_if

begin_comment
comment|/* **  These are defined in INN<nntp.h>.  Rather then require this file **  to include that file, we duplicate the relevent lines here. */
end_comment

begin_define
define|#
directive|define
name|NNTP_NOSUCHGROUP_VAL
value|411
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
name|NNTP_CLASS_ERROR
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
name|NNTP_SYNTAX_VAL
value|501
end_define

begin_define
define|#
directive|define
name|NNTP_STRLEN
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NNTP_CLASS_OK) */
end_comment

begin_define
define|#
directive|define
name|CHAR_OK
value|NNTP_CLASS_OK
end_define

begin_define
define|#
directive|define
name|CHAR_ERR
value|NNTP_CLASS_ERROR
end_define

begin_define
define|#
directive|define
name|CHAR_FATAL
value|NNTP_CLASS_FATAL
end_define

begin_define
define|#
directive|define
name|ERR_NOGROUP
value|NNTP_NOSUCHGROUP_VAL
end_define

begin_define
define|#
directive|define
name|ERR_CMDSYN
value|NNTP_SYNTAX_VAL
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|getserverbyfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_server
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|server_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_server
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_server
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|ser_line
index|[
name|NNTP_STRLEN
index|]
decl_stmt|;
end_decl_stmt

end_unit

