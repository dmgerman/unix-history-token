begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Include file for the Kerberos administration server.  *  *	from: admin_server.h,v 4.7 89/01/11 11:59:42 steiner Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ADMIN_SERVER_DEFS
end_ifndef

begin_define
define|#
directive|define
name|ADMIN_SERVER_DEFS
end_define

begin_define
define|#
directive|define
name|PW_SRV_VERSION
value|2
end_define

begin_comment
comment|/* version number */
end_comment

begin_define
define|#
directive|define
name|INSTALL_NEW_PW
value|(1<<0)
end_define

begin_comment
comment|/* 					 * ver, cmd, name, password, 					 * old_pass, crypt_pass, uid 					 */
end_comment

begin_define
define|#
directive|define
name|ADMIN_NEW_PW
value|(2<<1)
end_define

begin_comment
comment|/* 					 * ver, cmd, name, passwd, 					 * old_pass 					 * (grot), crypt_pass (grot) 					 */
end_comment

begin_define
define|#
directive|define
name|ADMIN_SET_KDC_PASSWORD
value|(3<<1)
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|ADMIN_ADD_NEW_KEY
value|(4<<1)
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|ADMIN_ADD_NEW_KEY_ATTR
value|(5<<1)
end_define

begin_comment
comment|/* 					 * ver, cmd, name, passwd, 					 * inst, attr (grot) 					 */
end_comment

begin_define
define|#
directive|define
name|INSTALL_REPLY
value|(1<<1)
end_define

begin_comment
comment|/* ver, cmd, name, password */
end_comment

begin_define
define|#
directive|define
name|RETRY_LIMIT
value|1
end_define

begin_define
define|#
directive|define
name|TIME_OUT
value|30
end_define

begin_define
define|#
directive|define
name|USER_TIMEOUT
value|90
end_define

begin_define
define|#
directive|define
name|MAX_KPW_LEN
value|40
end_define

begin_define
define|#
directive|define
name|KADM
value|"changepw"
end_define

begin_comment
comment|/* service name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ADMIN_SERVER_DEFS */
end_comment

end_unit

