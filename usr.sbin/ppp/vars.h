begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: vars.h,v 1.26 1997/09/04 00:38:22 brian Exp $  *  *	TODO:  */
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
name|ConfMSExt
value|8
end_define

begin_define
define|#
directive|define
name|ConfPasswdAuth
value|9
end_define

begin_define
define|#
directive|define
name|MAXCONFS
value|10
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
name|u_long
name|pref_mtu
decl_stmt|;
comment|/* Preferred MTU value */
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
name|modem_ctsrts
decl_stmt|;
comment|/* Use CTS/RTS on modem port? (boolean) */
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
name|reconnect_timer
decl_stmt|;
comment|/* Timeout before reconnect on carrier loss */
name|int
name|reconnect_tries
decl_stmt|;
comment|/* Attempt reconnect on carrier loss */
name|int
name|redial_timeout
decl_stmt|;
comment|/* Redial timeout value */
name|int
name|redial_next_timeout
decl_stmt|;
comment|/* Redial next timeout value */
name|int
name|dial_tries
decl_stmt|;
comment|/* Dial attempts before giving up, 0 == inf */
name|int
name|loopback
decl_stmt|;
comment|/* Turn around packets addressed to me */
name|char
name|modem_dev
index|[
literal|40
index|]
decl_stmt|;
comment|/* Name of device / host:port */
name|char
modifier|*
name|base_modem_dev
decl_stmt|;
comment|/* Pointer to base of modem_dev */
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
define|#
directive|define
name|LOCAL_DENY
value|0x03
name|u_char
name|lauth
decl_stmt|;
comment|/* Local Authorized status */
name|FILE
modifier|*
name|termfp
decl_stmt|;
comment|/* The terminal */
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
name|int
name|enc_MD4
decl_stmt|;
comment|/* Use MD4 for CHAP encryption */
name|char
name|phone_numbers
index|[
literal|200
index|]
decl_stmt|;
comment|/* Telephone Numbers */
name|char
name|phone_copy
index|[
literal|200
index|]
decl_stmt|;
comment|/* copy for strsep() */
name|char
modifier|*
name|next_phone
decl_stmt|;
comment|/* Next phone from the list */
name|char
modifier|*
name|alt_phone
decl_stmt|;
comment|/* Next phone from the list */
name|char
name|shostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* Local short Host Name */
name|char
name|hangup_script
index|[
literal|200
index|]
decl_stmt|;
comment|/* Hangup script before modem is closed */
name|struct
name|aliasHandlers
name|handler
decl_stmt|;
comment|/* Alias function pointers */
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
name|VarPrefMTU
value|pppVars.pref_mtu
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
name|VarBaseDevice
value|pppVars.base_modem_dev
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
name|VarCtsRts
value|pppVars.modem_ctsrts
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
name|VarHangupScript
value|pppVars.hangup_script
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
name|VarEncMD4
value|pppVars.enc_MD4
end_define

begin_define
define|#
directive|define
name|VarPhoneList
value|pppVars.phone_numbers
end_define

begin_define
define|#
directive|define
name|VarPhoneCopy
value|pppVars.phone_copy
end_define

begin_define
define|#
directive|define
name|VarNextPhone
value|pppVars.next_phone
end_define

begin_define
define|#
directive|define
name|VarAltPhone
value|pppVars.alt_phone
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
name|VarReconnectTimer
value|pppVars.reconnect_timer
end_define

begin_define
define|#
directive|define
name|VarReconnectTries
value|pppVars.reconnect_tries
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
name|VarRedialNextTimeout
value|pppVars.redial_next_timeout
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
name|VarLoopback
value|pppVars.loopback
end_define

begin_define
define|#
directive|define
name|VarTerm
value|pppVars.termfp
end_define

begin_define
define|#
directive|define
name|VarAliasHandlers
value|pppVars.handler
end_define

begin_define
define|#
directive|define
name|VarPacketAliasGetFragment
value|(*pppVars.handler.PacketAliasGetFragment)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasGetFragment
value|(*pppVars.handler.PacketAliasGetFragment)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasInit
value|(*pppVars.handler.PacketAliasInit)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasIn
value|(*pppVars.handler.PacketAliasIn)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasOut
value|(*pppVars.handler.PacketAliasOut)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasRedirectAddr
value|(*pppVars.handler.PacketAliasRedirectAddr)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasRedirectPort
value|(*pppVars.handler.PacketAliasRedirectPort)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasSaveFragment
value|(*pppVars.handler.PacketAliasSaveFragment)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasSetAddress
value|(*pppVars.handler.PacketAliasSetAddress)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasSetMode
value|(*pppVars.handler.PacketAliasSetMode)
end_define

begin_define
define|#
directive|define
name|VarPacketAliasFragmentIn
value|(*pppVars.handler.PacketAliasFragmentIn)
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

begin_define
define|#
directive|define
name|RECON_TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|RECON_FALSE
value|(2)
end_define

begin_define
define|#
directive|define
name|RECON_UNKNOWN
value|(3)
end_define

begin_define
define|#
directive|define
name|RECON_ENVOKED
value|(3)
end_define

begin_define
define|#
directive|define
name|reconnect
parameter_list|(
name|x
parameter_list|)
define|\
value|do                                          \     if (reconnectState == RECON_UNKNOWN) { \       reconnectState = x;                  \       if (x == RECON_FALSE)                   \         reconnectCount = 0;                   \     }                                         \   while(0)
end_define

begin_decl_stmt
name|int
name|reconnectState
decl_stmt|,
name|reconnectCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is the logic behind the reconnect variables:  * We have four reconnect "states".  We start off not requiring anything  * from the reconnect code (reconnectState == RECON_UNKNOWN).  If the  * line is brought down (via LcpClose() or LcpDown()), we have to decide  * whether to set to RECON_TRUE or RECON_FALSE.  It's only here that we  * know the correct action.  Once we've decided, we don't want that  * decision to be overridden (hence the above reconnect() macro) - If we  * call LcpClose, the ModemTimeout() still gets to "notice" that the line  * is down.  When it "notice"s, it should only set RECON_TRUE if a decision  * hasn't already been made.  *  * In main.c, when we notice we have RECON_TRUE, we must only action  * it once.  The fourth "state" is where we're bringing the line up,  * but if we call LcpClose for any reason (failed PAP/CHAP etc) we  * don't want to set to RECON_{TRUE,FALSE}.  *  * If we get a connection or give up dialing, we go back to RECON_UNKNOWN.  * If we get give up dialing or reconnecting or if we chose to down the  * connection, we set reconnectCount back to zero.  *  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

