begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: kdc.h,v 1.8 1997/04/01 03:59:05 assar Exp $  * $FreeBSD$  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   *  * Include file for the Kerberos Key Distribution Center.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KDC_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KDC_DEFS
end_define

begin_comment
comment|/* Don't depend on this! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MKEYFILE
end_ifndef

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|MKEYFILE
value|"/etc/kerberosIV/master-key"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MKEYFILE
value|"/.k"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|K_LOGFIL
end_ifndef

begin_define
define|#
directive|define
name|K_LOGFIL
value|"/var/log/kpropd.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ONE_MINUTE
value|60
end_define

begin_define
define|#
directive|define
name|FIVE_MINUTES
value|(5 * ONE_MINUTE)
end_define

begin_define
define|#
directive|define
name|ONE_HOUR
value|(60 * ONE_MINUTE)
end_define

begin_define
define|#
directive|define
name|ONE_DAY
value|(24 * ONE_HOUR)
end_define

begin_define
define|#
directive|define
name|THREE_DAYS
value|(3 * ONE_DAY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KDC_DEFS */
end_comment

end_unit

