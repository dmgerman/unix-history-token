begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /afs/athena.mit.edu/astaff/project/kerberos/src/kadmin/RCS/kadm_server.h,v $  * $Author: jtkohl $  * Header: /afs/athena.mit.edu/astaff/project/kerberos/src/kadmin/RCS/kadm_server.h,v 4.1 89/12/21 17:46:51 jtkohl Exp   *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  * Copyright.MIT.  *  * Definitions for Kerberos administration server& client  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KADM_SERVER_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KADM_SERVER_DEFS
end_define

begin_comment
comment|/*  * kadm_server.h  * Header file for the fourth attempt at an admin server  * Doug Church, December 28, 1989, MIT Project Athena  *    ps. Yes that means this code belongs to athena etc...  *        as part of our ongoing attempt to copyright all greek names  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<kerberosIV/krb.h>
end_include

begin_include
include|#
directive|include
file|<kerberosIV/des.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|sockaddr_in
name|admin_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|recv_addr
decl_stmt|;
name|int
name|recv_addr_len
decl_stmt|;
name|int
name|admin_fd
decl_stmt|;
comment|/* our link to clients */
name|char
name|sname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
name|char
name|sinst
index|[
name|INST_SZ
index|]
decl_stmt|;
name|char
name|krbrlm
index|[
name|REALM_SZ
index|]
decl_stmt|;
name|C_Block
name|master_key
decl_stmt|;
name|C_Block
name|session_key
decl_stmt|;
name|Key_schedule
name|master_key_schedule
decl_stmt|;
name|long
name|master_key_version
decl_stmt|;
block|}
name|Kadm_Server
typedef|;
end_typedef

begin_comment
comment|/* the default syslog file */
end_comment

begin_define
define|#
directive|define
name|KADM_SYSLOG
value|"/var/log/kadmind.syslog"
end_define

begin_define
define|#
directive|define
name|DEFAULT_ACL_DIR
value|"/etc/kerberosIV"
end_define

begin_define
define|#
directive|define
name|ADD_ACL_FILE
value|"/admin_acl.add"
end_define

begin_define
define|#
directive|define
name|GET_ACL_FILE
value|"/admin_acl.get"
end_define

begin_define
define|#
directive|define
name|MOD_ACL_FILE
value|"/admin_acl.mod"
end_define

begin_endif
endif|#
directive|endif
endif|KADM_SERVER_DEFS
end_endif

end_unit

