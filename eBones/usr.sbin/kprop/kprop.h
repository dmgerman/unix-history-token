begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 1987 by the Massachusetts Institute of Technology.  *  * For copying and distribution information,  * please see the file<mit-copyright.h>.  *  */
end_comment

begin_define
define|#
directive|define
name|KPROP_SERVICE_NAME
value|"rcmd"
end_define

begin_define
define|#
directive|define
name|KPROP_SRVTAB
value|"/etc/kerberosIV/srvtab"
end_define

begin_define
define|#
directive|define
name|TGT_SERVICE_NAME
value|"krbtgt"
end_define

begin_define
define|#
directive|define
name|KPROP_PROT_VERSION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|KPROP_PROT_VERSION
value|"kprop01"
end_define

begin_define
define|#
directive|define
name|KPROP_TRANSFER_PRIVATE
value|1
end_define

begin_define
define|#
directive|define
name|KPROP_TRANSFER_SAFE
value|2
end_define

begin_define
define|#
directive|define
name|KPROP_TRANSFER_CLEAR
value|3
end_define

begin_define
define|#
directive|define
name|KPROP_BUFSIZ
value|32768
end_define

begin_define
define|#
directive|define
name|KPROP_KDB_UTIL
value|"/usr/sbin/kdb_util"
end_define

end_unit

