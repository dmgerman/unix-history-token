begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 1987 by the Massachusetts Institute of Technology.  *  * For copying and distribution information,  * please see the file<mit-copyright.h>.  *  * $Revision: 1.1.1.1 $  * $Date: 1995/08/03 07:36:18 $  * $State: Exp $  * $Source: /usr/cvs/src/eBones/kprop/kprop.h,v $  * $Author: mark $  * $Locker:  $  *  * $Log: kprop.h,v $  * Revision 1.1.1.1  1995/08/03  07:36:18  mark  * Import an updated revision of the MIT kprop program for distributing  * kerberos databases to slave servers.  *  * NOTE: This method was abandoned by MIT long ago, this code is close to  *       garbage,  but it is slightly more secure than using rdist.  *       There is no documentation available on how to use it, and  *       it should -not- be built by default.  *  * Obtained from:	MIT Project Athena  *  * Revision 1.1.1.1  1995/08/02  22:11:44  pst  * Import an updated revision of the MIT kprop program for distributing  * kerberos databases to slave servers.  *  * NOTE: This method was abandoned by MIT long ago, this code is close to  *       garbage,  but it is slightly more secure than using rdist.  *       There is no documentation available on how to use it, and  *       it should -not- be built by default.  *  * Obtained from:	MIT Project Athena  *  * Revision 4.1  92/10/23  15:45:13  tytso  * Change the location of KPROP_KDBUTIL to be /kerberos/bin/kdb_util.  *   * Revision 4.0  89/01/24  18:44:46  wesommer  * Original version; programmer: wesommer  * auditor: jon  *   */
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

