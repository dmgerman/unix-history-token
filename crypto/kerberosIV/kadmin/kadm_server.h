begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Copyright (C) 1989 by the Massachusetts Institute of Technology     Export of this software from the United States of America is assumed    to require a specific license from the United States Government.    It is the responsibility of any person or organization contemplating    export to obtain such a license before exporting.  WITHIN THAT CONSTRAINT, permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.    */
end_comment

begin_comment
comment|/* $Id: kadm_server.h,v 1.10 1997/05/11 04:08:26 assar Exp $ */
end_comment

begin_comment
comment|/*  * Definitions for Kerberos administration server& client  */
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
name|des_cblock
name|master_key
decl_stmt|;
name|des_cblock
name|session_key
decl_stmt|;
name|des_key_schedule
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

begin_ifndef
ifndef|#
directive|ifndef
name|KADM_SYSLOG
end_ifndef

begin_define
define|#
directive|define
name|KADM_SYSLOG
value|"/var/log/admin_server.syslog"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KADM_SYSLOG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_ACL_DIR
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_ACL_DIR
value|"/var/kerberos"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFAULT_ACL_DIR */
end_comment

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

begin_define
define|#
directive|define
name|DEL_ACL_FILE
value|"/admin_acl.del"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KADM_SERVER_DEFS */
end_comment

end_unit

