begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VARS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VARS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_struct
struct|struct
name|confdesc
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|myside
decl_stmt|,
name|hisside
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CONF_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|CONF_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|CONF_DENY
value|0
end_define

begin_define
define|#
directive|define
name|CONF_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|ConfVjcomp
value|0
end_define

begin_define
define|#
directive|define
name|ConfLqr
value|1
end_define

begin_define
define|#
directive|define
name|ConfChap
value|2
end_define

begin_define
define|#
directive|define
name|ConfPap
value|3
end_define

begin_define
define|#
directive|define
name|ConfAcfcomp
value|4
end_define

begin_define
define|#
directive|define
name|ConfProtocomp
value|5
end_define

begin_define
define|#
directive|define
name|ConfPred1
value|6
end_define

begin_define
define|#
directive|define
name|ConfProxy
value|7
end_define

begin_define
define|#
directive|define
name|MAXCONFS
value|8
end_define

begin_define
define|#
directive|define
name|Enabled
parameter_list|(
name|x
parameter_list|)
value|(pppConfs[x].myside& CONF_ENABLE)
end_define

begin_define
define|#
directive|define
name|Acceptable
parameter_list|(
name|x
parameter_list|)
value|(pppConfs[x].hisside& CONF_ACCEPT)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|confdesc
name|pppConfs
index|[
name|MAXCONFS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|pppvars
block|{
name|u_long
name|var_mru
decl_stmt|;
comment|/* Initial MRU value */
name|int
name|var_accmap
decl_stmt|;
comment|/* Initial ACCMAP value */
name|int
name|modem_speed
decl_stmt|;
comment|/* Current modem speed */
name|int
name|modem_parity
decl_stmt|;
comment|/* Parity setting */
name|int
name|idle_timeout
decl_stmt|;
comment|/* Idle timeout value */
name|int
name|lqr_timeout
decl_stmt|;
comment|/* LQR timeout value */
name|int
name|retry_timeout
decl_stmt|;
comment|/* Retry timeout value */
name|int
name|redial_timeout
decl_stmt|;
comment|/* Redial timeout value */
name|int
name|dial_tries
decl_stmt|;
comment|/* Dial attempts before giving up, 0 == forever */
name|char
name|modem_dev
index|[
literal|20
index|]
decl_stmt|;
comment|/* Name of device */
name|int
name|open_mode
decl_stmt|;
comment|/* LCP open mode */
define|#
directive|define
name|LOCAL_AUTH
value|0x01
define|#
directive|define
name|LOCAL_NO_AUTH
value|0x02
name|u_char
name|lauth
decl_stmt|;
comment|/* Local Authorized status */
define|#
directive|define
name|DIALUP_REQ
value|0x01
define|#
directive|define
name|DIALUP_DONE
value|0x02
name|char
name|dial_script
index|[
literal|200
index|]
decl_stmt|;
comment|/* Dial script */
name|char
name|login_script
index|[
literal|200
index|]
decl_stmt|;
comment|/* Login script */
name|char
name|auth_key
index|[
literal|50
index|]
decl_stmt|;
comment|/* PAP/CHAP key */
name|char
name|auth_name
index|[
literal|50
index|]
decl_stmt|;
comment|/* PAP/CHAP system name */
name|char
name|phone_number
index|[
literal|50
index|]
decl_stmt|;
comment|/* Telephone Number */
name|char
name|shostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* Local short Host Name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VarAccmap
value|pppVars.var_accmap
end_define

begin_define
define|#
directive|define
name|VarMRU
value|pppVars.var_mru
end_define

begin_define
define|#
directive|define
name|VarDevice
value|pppVars.modem_dev
end_define

begin_define
define|#
directive|define
name|VarSpeed
value|pppVars.modem_speed
end_define

begin_define
define|#
directive|define
name|VarParity
value|pppVars.modem_parity
end_define

begin_define
define|#
directive|define
name|VarOpenMode
value|pppVars.open_mode
end_define

begin_define
define|#
directive|define
name|VarLocalAuth
value|pppVars.lauth
end_define

begin_define
define|#
directive|define
name|VarDialScript
value|pppVars.dial_script
end_define

begin_define
define|#
directive|define
name|VarLoginScript
value|pppVars.login_script
end_define

begin_define
define|#
directive|define
name|VarIdleTimeout
value|pppVars.idle_timeout
end_define

begin_define
define|#
directive|define
name|VarLqrTimeout
value|pppVars.lqr_timeout
end_define

begin_define
define|#
directive|define
name|VarRetryTimeout
value|pppVars.retry_timeout
end_define

begin_define
define|#
directive|define
name|VarAuthKey
value|pppVars.auth_key
end_define

begin_define
define|#
directive|define
name|VarAuthName
value|pppVars.auth_name
end_define

begin_define
define|#
directive|define
name|VarPhone
value|pppVars.phone_number
end_define

begin_define
define|#
directive|define
name|VarShortHost
value|pppVars.shostname
end_define

begin_define
define|#
directive|define
name|VarRedialTimeout
value|pppVars.redial_timeout
end_define

begin_define
define|#
directive|define
name|VarDialTries
value|pppVars.dial_tries
end_define

begin_define
define|#
directive|define
name|DEV_IS_SYNC
value|(VarSpeed == 0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|pppvars
name|pppVars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipInOctets
decl_stmt|,
name|ipOutOctets
decl_stmt|,
name|ipKeepAlive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipConnectSecs
decl_stmt|,
name|ipIdleSecs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

