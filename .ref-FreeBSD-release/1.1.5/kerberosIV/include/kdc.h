begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/include/RCS/kdc.h,v $  * $Author: kfall $  * $Header: /usr/src/kerberosIV/include/RCS/kdc.h,v 4.2 90/06/25 20:49:40 kfall Exp $  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   *  * Include file for the Kerberos Key Distribution Center.   */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

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

begin_define
define|#
directive|define
name|S_AD_SZ
value|sizeof(struct sockaddr_in)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a>b ? a : b)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a<b ? a : b)
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|MKEYFILE
value|"/etc/kerberosIV/master_key"
end_define

begin_define
define|#
directive|define
name|K_LOGFIL
value|"/var/log/kpropd.log"
end_define

begin_define
define|#
directive|define
name|KS_LOGFIL
value|"/var/log/kerberos_slave.log"
end_define

begin_define
define|#
directive|define
name|KRB_ACL
value|"/etc/kerberosIV/kerberos.acl"
end_define

begin_define
define|#
directive|define
name|KRB_PROG
value|"./kerberos"
end_define

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

