begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|SIGQIT
value|3
end_define

begin_define
define|#
directive|define
name|SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_define
define|#
directive|define
name|SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|SIGTERM
value|15
end_define

begin_expr_stmt
name|int
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SIG_DFL
value|(int (*)())0
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|(int (*)())1
end_define

end_unit

