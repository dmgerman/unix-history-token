begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Configuration file name  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_FILE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_FILE
value|"/etc/ntp.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_define
define|#
directive|define
name|CONFIG_FILE
value|"%windir%\\system32\\drivers\\etc\\ntp.conf"
end_define

begin_define
define|#
directive|define
name|ALT_CONFIG_FILE
value|"%windir%\\ntp.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CONFIG_FILE */
end_comment

begin_comment
comment|/*  * Types of entries we understand.  */
end_comment

begin_define
define|#
directive|define
name|CONFIG_UNKNOWN
value|0
end_define

begin_comment
comment|/*  * Command keywords  */
end_comment

begin_define
define|#
directive|define
name|CONFIG_PEER
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_SERVER
value|2
end_define

begin_define
define|#
directive|define
name|CONFIG_AUTOMAX
value|3
end_define

begin_define
define|#
directive|define
name|CONFIG_DRIFTFILE
value|4
end_define

begin_define
define|#
directive|define
name|CONFIG_BROADCAST
value|5
end_define

begin_define
define|#
directive|define
name|CONFIG_BROADCASTCLIENT
value|6
end_define

begin_define
define|#
directive|define
name|CONFIG_AUTHENTICATE
value|7
end_define

begin_define
define|#
directive|define
name|CONFIG_KEYS
value|8
end_define

begin_define
define|#
directive|define
name|CONFIG_REVOKE
value|9
end_define

begin_define
define|#
directive|define
name|CONFIG_PPS
value|10
end_define

begin_define
define|#
directive|define
name|CONFIG_RESTRICT
value|11
end_define

begin_define
define|#
directive|define
name|CONFIG_BDELAY
value|12
end_define

begin_define
define|#
directive|define
name|CONFIG_TRUSTEDKEY
value|13
end_define

begin_define
define|#
directive|define
name|CONFIG_REQUESTKEY
value|14
end_define

begin_define
define|#
directive|define
name|CONFIG_CONTROLKEY
value|15
end_define

begin_define
define|#
directive|define
name|CONFIG_TRAP
value|16
end_define

begin_define
define|#
directive|define
name|CONFIG_FUDGE
value|17
end_define

begin_define
define|#
directive|define
name|CONFIG_TINKER
value|18
end_define

begin_define
define|#
directive|define
name|CONFIG_STATSDIR
value|19
end_define

begin_define
define|#
directive|define
name|CONFIG_FILEGEN
value|20
end_define

begin_define
define|#
directive|define
name|CONFIG_STATISTICS
value|21
end_define

begin_define
define|#
directive|define
name|CONFIG_PIDFILE
value|22
end_define

begin_define
define|#
directive|define
name|CONFIG_SETVAR
value|23
end_define

begin_define
define|#
directive|define
name|CONFIG_CLIENTLIMIT
value|24
end_define

begin_define
define|#
directive|define
name|CONFIG_CLIENTPERIOD
value|25
end_define

begin_define
define|#
directive|define
name|CONFIG_MULTICASTCLIENT
value|26
end_define

begin_define
define|#
directive|define
name|CONFIG_ENABLE
value|27
end_define

begin_define
define|#
directive|define
name|CONFIG_DISABLE
value|28
end_define

begin_define
define|#
directive|define
name|CONFIG_PHONE
value|29
end_define

begin_define
define|#
directive|define
name|CONFIG_LOGFILE
value|30
end_define

begin_define
define|#
directive|define
name|CONFIG_LOGCONFIG
value|31
end_define

begin_define
define|#
directive|define
name|CONFIG_MANYCASTCLIENT
value|32
end_define

begin_define
define|#
directive|define
name|CONFIG_MANYCASTSERVER
value|33
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_CRYPTO
value|34
end_define

begin_define
define|#
directive|define
name|CONFIG_KEYSDIR
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_define
define|#
directive|define
name|CONFIG_INCLUDEFILE
value|36
end_define

begin_comment
comment|/*  * "peer", "server", "broadcast" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_MOD_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|CONF_MOD_KEY
value|2
end_define

begin_define
define|#
directive|define
name|CONF_MOD_MINPOLL
value|3
end_define

begin_define
define|#
directive|define
name|CONF_MOD_MAXPOLL
value|4
end_define

begin_define
define|#
directive|define
name|CONF_MOD_PREFER
value|5
end_define

begin_define
define|#
directive|define
name|CONF_MOD_BURST
value|6
end_define

begin_define
define|#
directive|define
name|CONF_MOD_IBURST
value|7
end_define

begin_define
define|#
directive|define
name|CONF_MOD_SKEY
value|8
end_define

begin_define
define|#
directive|define
name|CONF_MOD_TTL
value|9
end_define

begin_define
define|#
directive|define
name|CONF_MOD_MODE
value|10
end_define

begin_define
define|#
directive|define
name|CONF_MOD_NOSELECT
value|11
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_define
define|#
directive|define
name|CONF_MOD_PUBLICKEY
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_comment
comment|/*  * "restrict" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_RES_MASK
value|1
end_define

begin_define
define|#
directive|define
name|CONF_RES_IGNORE
value|2
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOSERVE
value|3
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOTRUST
value|4
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOQUERY
value|5
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOMODIFY
value|6
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOPEER
value|7
end_define

begin_define
define|#
directive|define
name|CONF_RES_NOTRAP
value|8
end_define

begin_define
define|#
directive|define
name|CONF_RES_LPTRAP
value|9
end_define

begin_define
define|#
directive|define
name|CONF_RES_NTPPORT
value|10
end_define

begin_define
define|#
directive|define
name|CONF_RES_LIMITED
value|11
end_define

begin_define
define|#
directive|define
name|CONF_RES_VERSION
value|12
end_define

begin_define
define|#
directive|define
name|CONF_RES_DEMOBILIZE
value|13
end_define

begin_comment
comment|/*  * "trap" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_TRAP_PORT
value|1
end_define

begin_define
define|#
directive|define
name|CONF_TRAP_INTERFACE
value|2
end_define

begin_comment
comment|/*  * "fudge" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_FDG_TIME1
value|1
end_define

begin_define
define|#
directive|define
name|CONF_FDG_TIME2
value|2
end_define

begin_define
define|#
directive|define
name|CONF_FDG_STRATUM
value|3
end_define

begin_define
define|#
directive|define
name|CONF_FDG_REFID
value|4
end_define

begin_define
define|#
directive|define
name|CONF_FDG_FLAG1
value|5
end_define

begin_define
define|#
directive|define
name|CONF_FDG_FLAG2
value|6
end_define

begin_define
define|#
directive|define
name|CONF_FDG_FLAG3
value|7
end_define

begin_define
define|#
directive|define
name|CONF_FDG_FLAG4
value|8
end_define

begin_comment
comment|/*  * "filegen" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_FGEN_FILE
value|1
end_define

begin_define
define|#
directive|define
name|CONF_FGEN_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|CONF_FGEN_FLAG_LINK
value|3
end_define

begin_define
define|#
directive|define
name|CONF_FGEN_FLAG_NOLINK
value|4
end_define

begin_define
define|#
directive|define
name|CONF_FGEN_FLAG_ENABLE
value|5
end_define

begin_define
define|#
directive|define
name|CONF_FGEN_FLAG_DISABLE
value|6
end_define

begin_comment
comment|/*  * "pps" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_PPS_ASSERT
value|1
end_define

begin_define
define|#
directive|define
name|CONF_PPS_CLEAR
value|2
end_define

begin_define
define|#
directive|define
name|CONF_PPS_HARDPPS
value|3
end_define

begin_comment
comment|/*  * "tinker" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_CLOCK_MAX
value|1
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_PANIC
value|2
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_PHI
value|3
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_MINSTEP
value|4
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_MINPOLL
value|5
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_ALLAN
value|6
end_define

begin_define
define|#
directive|define
name|CONF_CLOCK_HUFFPUFF
value|7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_comment
comment|/*  * "crypto" modifier keywords  */
end_comment

begin_define
define|#
directive|define
name|CONF_CRYPTO_DH
value|1
end_define

begin_define
define|#
directive|define
name|CONF_CRYPTO_PRIVATEKEY
value|2
end_define

begin_define
define|#
directive|define
name|CONF_CRYPTO_PUBLICKEY
value|3
end_define

begin_define
define|#
directive|define
name|CONF_CRYPTO_LEAP
value|4
end_define

begin_define
define|#
directive|define
name|CONF_CRYPTO_FLAGS
value|5
end_define

begin_define
define|#
directive|define
name|CONF_CRYPTO_CERT
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

end_unit

