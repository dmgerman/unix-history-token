begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * define path names  *  * $Id$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_VARRUN
value|"/etc/ppp/"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
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

begin_define
define|#
directive|define
name|_PATH_IPUP
value|"/etc/ppp/ip-up"
end_define

begin_define
define|#
directive|define
name|_PATH_IPDOWN
value|"/etc/ppp/ip-down"
end_define

begin_define
define|#
directive|define
name|_PATH_TTYOPT
value|"/etc/ppp/options."
end_define

begin_define
define|#
directive|define
name|_PATH_CONNERRS
value|"/etc/ppp/connect-errors"
end_define

begin_define
define|#
directive|define
name|_PATH_USEROPT
value|".ppprc"
end_define

end_unit

