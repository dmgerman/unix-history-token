begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * define path names  *  * $Id: pathnames.h,v 1.1 1993/11/11 03:54:25 paulus Exp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/etc/ppp"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/var/run"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_UPAPFILE
value|"/etc/ppp/pap-secrets"
end_define

begin_define
define|#
directive|define
name|_PATH_CHAPFILE
value|"/etc/ppp/chap-secrets"
end_define

begin_define
define|#
directive|define
name|_PATH_SYSOPTIONS
value|"/etc/ppp/options"
end_define

end_unit

