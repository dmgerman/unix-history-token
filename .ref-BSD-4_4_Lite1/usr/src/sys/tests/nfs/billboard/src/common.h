begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_comment
comment|/* ** We use the name bool_t to maintain consistency with the RPC headers. #ifdef  bool_t #undef  bool_t #endif typedef enum    { FALSE = 0, TRUE = 1 } bool_t;  */
end_comment

begin_comment
comment|/* ** These are the return code defenitions for the rpc interface calls. */
end_comment

begin_define
define|#
directive|define
name|BB_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|BB_FAILURE
value|(-1)
end_define

begin_define
define|#
directive|define
name|BB_BAD_CLIENT
value|(-2)
end_define

begin_define
define|#
directive|define
name|BB_BAD_SERVER
value|(-3)
end_define

begin_define
define|#
directive|define
name|BB_ALREADY_SET
value|(-4)
end_define

begin_define
define|#
directive|define
name|BB_ALREADY_UNSET
value|(-5)
end_define

begin_define
define|#
directive|define
name|BB_BAD_PASSWD
value|(-6)
end_define

begin_define
define|#
directive|define
name|BB_BAD_PHASE
value|(-7)
end_define

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_comment
comment|/* The null character.		*/
end_comment

begin_define
define|#
directive|define
name|BB_END_OF_FILE
value|(-2)
end_define

begin_define
define|#
directive|define
name|BB_MAX_LINE_LEN
value|200
end_define

begin_define
define|#
directive|define
name|BB_SYSLOG_UDP_CREATE
value|"Unable to create UDP transport."
end_define

begin_define
define|#
directive|define
name|BB_SYSLOG_SVC_REGISTER
value|"Unable to register the rpc service."
end_define

begin_define
define|#
directive|define
name|BB_SYSLOG_SVC_RUN
value|"The service run routine failed."
end_define

end_unit

