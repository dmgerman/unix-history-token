begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: krb.h,v 1.99 1999/11/16 14:02:47 bg Exp $  * $FreeBSD$  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   *  * Include file for the Kerberos library.   */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB_H__
end_define

begin_comment
comment|/* XXX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BEGIN_DECLS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__END_DECLS
value|};
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* Need some defs from des.h	 */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NOPROTO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
define|#
directive|define
name|NOPROTO
endif|#
directive|endif
include|#
directive|include
file|<openssl/des.h>
comment|/* CNS compatibility ahead! */
ifndef|#
directive|ifndef
name|KRB_INT32
define|#
directive|define
name|KRB_INT32
value|int32_t
endif|#
directive|endif
ifndef|#
directive|ifndef
name|KRB_UINT32
define|#
directive|define
name|KRB_UINT32
value|u_int32_t
endif|#
directive|endif
comment|/* Global library variables. */
specifier|extern
name|int
name|krb_ignore_ip_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* To turn off IP address comparison */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|krb_no_long_lifetimes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* To disable AFS compatible lifetimes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|krbONE
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|(* (char *)&krbONE)
end_define

begin_comment
comment|/* Debug variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|krb_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|krb_ap_req_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|krb_dns_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text describing error codes */
end_comment

begin_define
define|#
directive|define
name|MAX_KRB_ERRORS
value|256
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|krb_err_txt
index|[
name|MAX_KRB_ERRORS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General definitions */
end_comment

begin_define
define|#
directive|define
name|KSUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|KFAILURE
value|255
end_define

begin_comment
comment|/*  * Kerberos specific definitions   *  * KRBLOG is the log file for the kerberos master server. KRB_CONF is  * the configuration file where different host machines running master  * and slave servers can be found. KRB_MASTER is the name of the  * machine with the master database.  The admin_server runs on this  * machine, and all changes to the db (as opposed to read-only  * requests, which can go to slaves) must go to it. KRB_HOST is the  * default machine * when looking for a kerberos slave server.  Other  * possibilities are * in the KRB_CONF file. KRB_REALM is the name of  * the realm.   */
end_comment

begin_comment
comment|/* /etc/kerberosIV is only for backwards compatibility, don't use it! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_CONF
end_ifndef

begin_define
define|#
directive|define
name|KRB_CONF
value|"/etc/kerberosIV/krb.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_RLM_TRANS
end_ifndef

begin_define
define|#
directive|define
name|KRB_RLM_TRANS
value|"/etc/kerberosIV/krb.realms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_CNF_FILES
end_ifndef

begin_define
define|#
directive|define
name|KRB_CNF_FILES
value|{ KRB_CONF,   "/etc/krb.conf", 0}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_RLM_FILES
end_ifndef

begin_define
define|#
directive|define
name|KRB_RLM_FILES
value|{ KRB_RLM_TRANS, "/etc/krb.realms", 0}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_EQUIV
end_ifndef

begin_define
define|#
directive|define
name|KRB_EQUIV
value|"/etc/kerberosIV/krb.equiv"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB_MASTER
value|"kerberos"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_REALM
end_ifndef

begin_define
define|#
directive|define
name|KRB_REALM
value|(krb_get_default_realm())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The maximum sizes for aname, realm, sname, and instance +1 */
end_comment

begin_define
define|#
directive|define
name|ANAME_SZ
value|40
end_define

begin_define
define|#
directive|define
name|REALM_SZ
value|40
end_define

begin_define
define|#
directive|define
name|SNAME_SZ
value|40
end_define

begin_define
define|#
directive|define
name|INST_SZ
value|40
end_define

begin_comment
comment|/* Leave space for quoting */
end_comment

begin_define
define|#
directive|define
name|MAX_K_NAME_SZ
value|(2*ANAME_SZ + 2*INST_SZ + 2*REALM_SZ - 3)
end_define

begin_define
define|#
directive|define
name|KKEY_SZ
value|100
end_define

begin_define
define|#
directive|define
name|VERSION_SZ
value|1
end_define

begin_define
define|#
directive|define
name|MSG_TYPE_SZ
value|1
end_define

begin_define
define|#
directive|define
name|DATE_SZ
value|26
end_define

begin_comment
comment|/* RTI date output */
end_comment

begin_define
define|#
directive|define
name|MAX_HSTNM
value|100
end_define

begin_comment
comment|/* for compatibility */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|krb_principal
block|{
name|char
name|name
index|[
name|ANAME_SZ
index|]
decl_stmt|;
name|char
name|instance
index|[
name|INST_SZ
index|]
decl_stmt|;
name|char
name|realm
index|[
name|REALM_SZ
index|]
decl_stmt|;
block|}
name|krb_principal
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_TKT_LIFE
end_ifndef

begin_comment
comment|/* allow compile-time override */
end_comment

begin_comment
comment|/* default lifetime for krb_mk_req& co., 10 hrs */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TKT_LIFE
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB_TICKET_GRANTING_TICKET
value|"krbtgt"
end_define

begin_comment
comment|/* Definition of text structure used to pass text around */
end_comment

begin_define
define|#
directive|define
name|MAX_KTXT_LEN
value|1250
end_define

begin_struct
struct|struct
name|ktext
block|{
name|unsigned
name|int
name|length
decl_stmt|;
comment|/* Length of the text */
name|unsigned
name|char
name|dat
index|[
name|MAX_KTXT_LEN
index|]
decl_stmt|;
comment|/* The data itself */
name|u_int32_t
name|mbz
decl_stmt|;
comment|/* zero to catch runaway strings */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ktext
modifier|*
name|KTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ktext
name|KTEXT_ST
typedef|;
end_typedef

begin_comment
comment|/* Definitions for send_to_kdc */
end_comment

begin_define
define|#
directive|define
name|CLIENT_KRB_TIMEOUT
value|4
end_define

begin_comment
comment|/* default time between retries */
end_comment

begin_define
define|#
directive|define
name|CLIENT_KRB_RETRY
value|5
end_define

begin_comment
comment|/* retry this many times */
end_comment

begin_define
define|#
directive|define
name|CLIENT_KRB_BUFLEN
value|512
end_define

begin_comment
comment|/* max unfragmented packet */
end_comment

begin_comment
comment|/* Definitions for ticket file utilities */
end_comment

begin_define
define|#
directive|define
name|R_TKT_FIL
value|0
end_define

begin_define
define|#
directive|define
name|W_TKT_FIL
value|1
end_define

begin_comment
comment|/* Parameters for rd_ap_req */
end_comment

begin_comment
comment|/* Maximum alloable clock skew in seconds */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SKEW
value|5*60
end_define

begin_comment
comment|/* Filename for readservkey */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KEYFILE
end_ifndef

begin_define
define|#
directive|define
name|KEYFILE
value|(krb_get_default_keyfile())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structure definition for rd_ap_req */
end_comment

begin_struct
struct|struct
name|auth_dat
block|{
name|unsigned
name|char
name|k_flags
decl_stmt|;
comment|/* Flags from ticket */
name|char
name|pname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Principal's name */
name|char
name|pinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* His Instance */
name|char
name|prealm
index|[
name|REALM_SZ
index|]
decl_stmt|;
comment|/* His Realm */
name|u_int32_t
name|checksum
decl_stmt|;
comment|/* Data checksum (opt) */
name|des_cblock
name|session
decl_stmt|;
comment|/* Session Key */
name|int
name|life
decl_stmt|;
comment|/* Life of ticket */
name|u_int32_t
name|time_sec
decl_stmt|;
comment|/* Time ticket issued */
name|u_int32_t
name|address
decl_stmt|;
comment|/* Address in ticket */
name|KTEXT_ST
name|reply
decl_stmt|;
comment|/* Auth reply (opt) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|auth_dat
name|AUTH_DAT
typedef|;
end_typedef

begin_comment
comment|/* Structure definition for credentials returned by get_cred */
end_comment

begin_struct
struct|struct
name|credentials
block|{
name|char
name|service
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Service name */
name|char
name|instance
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* Instance */
name|char
name|realm
index|[
name|REALM_SZ
index|]
decl_stmt|;
comment|/* Auth domain */
name|des_cblock
name|session
decl_stmt|;
comment|/* Session key */
name|int
name|lifetime
decl_stmt|;
comment|/* Lifetime */
name|int
name|kvno
decl_stmt|;
comment|/* Key version number */
name|KTEXT_ST
name|ticket_st
decl_stmt|;
comment|/* The ticket itself */
name|int32_t
name|issue_date
decl_stmt|;
comment|/* The issue time */
name|char
name|pname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Principal's name */
name|char
name|pinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* Principal's instance */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|credentials
name|CREDENTIALS
typedef|;
end_typedef

begin_comment
comment|/* Structure definition for rd_private_msg and rd_safe_msg */
end_comment

begin_struct
struct|struct
name|msg_dat
block|{
name|unsigned
name|char
modifier|*
name|app_data
decl_stmt|;
comment|/* pointer to appl data */
name|u_int32_t
name|app_length
decl_stmt|;
comment|/* length of appl data */
name|u_int32_t
name|hash
decl_stmt|;
comment|/* hash to lookup replay */
name|int
name|swap
decl_stmt|;
comment|/* swap bytes? */
name|int32_t
name|time_sec
decl_stmt|;
comment|/* msg timestamp seconds */
name|unsigned
name|char
name|time_5ms
decl_stmt|;
comment|/* msg timestamp 5ms units */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|msg_dat
name|MSG_DAT
typedef|;
end_typedef

begin_struct
struct|struct
name|krb_host
block|{
name|char
modifier|*
name|realm
decl_stmt|;
name|char
modifier|*
name|host
decl_stmt|;
enum|enum
name|krb_host_proto
block|{
name|PROTO_UDP
block|,
name|PROTO_TCP
block|,
name|PROTO_HTTP
block|}
name|proto
enum|;
name|int
name|port
decl_stmt|;
name|int
name|admin
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Location of ticket file for save_cred and get_cred */
end_comment

begin_define
define|#
directive|define
name|TKT_FILE
value|tkt_string()
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TKT_ROOT
end_ifndef

begin_define
define|#
directive|define
name|TKT_ROOT
value|(krb_get_default_tkt_root())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Error codes returned from the KDC */
end_comment

begin_define
define|#
directive|define
name|KDC_OK
value|0
end_define

begin_comment
comment|/* Request OK */
end_comment

begin_define
define|#
directive|define
name|KDC_NAME_EXP
value|1
end_define

begin_comment
comment|/* Principal expired */
end_comment

begin_define
define|#
directive|define
name|KDC_SERVICE_EXP
value|2
end_define

begin_comment
comment|/* Service expired */
end_comment

begin_define
define|#
directive|define
name|KDC_AUTH_EXP
value|3
end_define

begin_comment
comment|/* Auth expired */
end_comment

begin_define
define|#
directive|define
name|KDC_PKT_VER
value|4
end_define

begin_comment
comment|/* Protocol version unknown */
end_comment

begin_define
define|#
directive|define
name|KDC_P_MKEY_VER
value|5
end_define

begin_comment
comment|/* Wrong master key version */
end_comment

begin_define
define|#
directive|define
name|KDC_S_MKEY_VER
value|6
end_define

begin_comment
comment|/* Wrong master key version */
end_comment

begin_define
define|#
directive|define
name|KDC_BYTE_ORDER
value|7
end_define

begin_comment
comment|/* Byte order unknown */
end_comment

begin_define
define|#
directive|define
name|KDC_PR_UNKNOWN
value|8
end_define

begin_comment
comment|/* Principal unknown */
end_comment

begin_define
define|#
directive|define
name|KDC_PR_N_UNIQUE
value|9
end_define

begin_comment
comment|/* Principal not unique */
end_comment

begin_define
define|#
directive|define
name|KDC_NULL_KEY
value|10
end_define

begin_comment
comment|/* Principal has null key */
end_comment

begin_define
define|#
directive|define
name|KDC_GEN_ERR
value|20
end_define

begin_comment
comment|/* Generic error from KDC */
end_comment

begin_comment
comment|/* Values returned by get_credentials */
end_comment

begin_define
define|#
directive|define
name|GC_OK
value|0
end_define

begin_comment
comment|/* Retrieve OK */
end_comment

begin_define
define|#
directive|define
name|RET_OK
value|0
end_define

begin_comment
comment|/* Retrieve OK */
end_comment

begin_define
define|#
directive|define
name|GC_TKFIL
value|21
end_define

begin_comment
comment|/* Can't read ticket file */
end_comment

begin_define
define|#
directive|define
name|RET_TKFIL
value|21
end_define

begin_comment
comment|/* Can't read ticket file */
end_comment

begin_define
define|#
directive|define
name|GC_NOTKT
value|22
end_define

begin_comment
comment|/* Can't find ticket or TGT */
end_comment

begin_define
define|#
directive|define
name|RET_NOTKT
value|22
end_define

begin_comment
comment|/* Can't find ticket or TGT */
end_comment

begin_comment
comment|/* Values returned by mk_ap_req	 */
end_comment

begin_define
define|#
directive|define
name|MK_AP_OK
value|0
end_define

begin_comment
comment|/* Success */
end_comment

begin_define
define|#
directive|define
name|MK_AP_TGTEXP
value|26
end_define

begin_comment
comment|/* TGT Expired */
end_comment

begin_comment
comment|/* Values returned by rd_ap_req */
end_comment

begin_define
define|#
directive|define
name|RD_AP_OK
value|0
end_define

begin_comment
comment|/* Request authentic */
end_comment

begin_define
define|#
directive|define
name|RD_AP_UNDEC
value|31
end_define

begin_comment
comment|/* Can't decode authenticator */
end_comment

begin_define
define|#
directive|define
name|RD_AP_EXP
value|32
end_define

begin_comment
comment|/* Ticket expired */
end_comment

begin_define
define|#
directive|define
name|RD_AP_NYV
value|33
end_define

begin_comment
comment|/* Ticket not yet valid */
end_comment

begin_define
define|#
directive|define
name|RD_AP_REPEAT
value|34
end_define

begin_comment
comment|/* Repeated request */
end_comment

begin_define
define|#
directive|define
name|RD_AP_NOT_US
value|35
end_define

begin_comment
comment|/* The ticket isn't for us */
end_comment

begin_define
define|#
directive|define
name|RD_AP_INCON
value|36
end_define

begin_comment
comment|/* Request is inconsistent */
end_comment

begin_define
define|#
directive|define
name|RD_AP_TIME
value|37
end_define

begin_comment
comment|/* delta_t too big */
end_comment

begin_define
define|#
directive|define
name|RD_AP_BADD
value|38
end_define

begin_comment
comment|/* Incorrect net address */
end_comment

begin_define
define|#
directive|define
name|RD_AP_VERSION
value|39
end_define

begin_comment
comment|/* protocol version mismatch */
end_comment

begin_define
define|#
directive|define
name|RD_AP_MSG_TYPE
value|40
end_define

begin_comment
comment|/* invalid msg type */
end_comment

begin_define
define|#
directive|define
name|RD_AP_MODIFIED
value|41
end_define

begin_comment
comment|/* message stream modified */
end_comment

begin_define
define|#
directive|define
name|RD_AP_ORDER
value|42
end_define

begin_comment
comment|/* message out of order */
end_comment

begin_define
define|#
directive|define
name|RD_AP_UNAUTHOR
value|43
end_define

begin_comment
comment|/* unauthorized request */
end_comment

begin_comment
comment|/* Values returned by get_pw_tkt */
end_comment

begin_define
define|#
directive|define
name|GT_PW_OK
value|0
end_define

begin_comment
comment|/* Got password changing tkt */
end_comment

begin_define
define|#
directive|define
name|GT_PW_NULL
value|51
end_define

begin_comment
comment|/* Current PW is null */
end_comment

begin_define
define|#
directive|define
name|GT_PW_BADPW
value|52
end_define

begin_comment
comment|/* Incorrect current password */
end_comment

begin_define
define|#
directive|define
name|GT_PW_PROT
value|53
end_define

begin_comment
comment|/* Protocol Error */
end_comment

begin_define
define|#
directive|define
name|GT_PW_KDCERR
value|54
end_define

begin_comment
comment|/* Error returned by KDC */
end_comment

begin_define
define|#
directive|define
name|GT_PW_NULLTKT
value|55
end_define

begin_comment
comment|/* Null tkt returned by KDC */
end_comment

begin_comment
comment|/* Values returned by send_to_kdc */
end_comment

begin_define
define|#
directive|define
name|SKDC_OK
value|0
end_define

begin_comment
comment|/* Response received */
end_comment

begin_define
define|#
directive|define
name|SKDC_RETRY
value|56
end_define

begin_comment
comment|/* Retry count exceeded */
end_comment

begin_define
define|#
directive|define
name|SKDC_CANT
value|57
end_define

begin_comment
comment|/* Can't send request */
end_comment

begin_comment
comment|/*  * Values returned by get_intkt  * (can also return SKDC_* and KDC errors)  */
end_comment

begin_define
define|#
directive|define
name|INTK_OK
value|0
end_define

begin_comment
comment|/* Ticket obtained */
end_comment

begin_define
define|#
directive|define
name|INTK_W_NOTALL
value|61
end_define

begin_comment
comment|/* Not ALL tickets returned */
end_comment

begin_define
define|#
directive|define
name|INTK_BADPW
value|62
end_define

begin_comment
comment|/* Incorrect password */
end_comment

begin_define
define|#
directive|define
name|INTK_PROT
value|63
end_define

begin_comment
comment|/* Protocol Error */
end_comment

begin_define
define|#
directive|define
name|INTK_ERR
value|70
end_define

begin_comment
comment|/* Other error */
end_comment

begin_comment
comment|/* Values returned by get_adtkt */
end_comment

begin_define
define|#
directive|define
name|AD_OK
value|0
end_define

begin_comment
comment|/* Ticket Obtained */
end_comment

begin_define
define|#
directive|define
name|AD_NOTGT
value|71
end_define

begin_comment
comment|/* Don't have tgt */
end_comment

begin_define
define|#
directive|define
name|AD_INTR_RLM_NOTGT
value|72
end_define

begin_comment
comment|/* Can't get inter-realm tgt */
end_comment

begin_comment
comment|/* Error codes returned by ticket file utilities */
end_comment

begin_define
define|#
directive|define
name|NO_TKT_FIL
value|76
end_define

begin_comment
comment|/* No ticket file found */
end_comment

begin_define
define|#
directive|define
name|TKT_FIL_ACC
value|77
end_define

begin_comment
comment|/* Couldn't access tkt file */
end_comment

begin_define
define|#
directive|define
name|TKT_FIL_LCK
value|78
end_define

begin_comment
comment|/* Couldn't lock ticket file */
end_comment

begin_define
define|#
directive|define
name|TKT_FIL_FMT
value|79
end_define

begin_comment
comment|/* Bad ticket file format */
end_comment

begin_define
define|#
directive|define
name|TKT_FIL_INI
value|80
end_define

begin_comment
comment|/* tf_init not called first */
end_comment

begin_comment
comment|/* Error code returned by kparse_name */
end_comment

begin_define
define|#
directive|define
name|KNAME_FMT
value|81
end_define

begin_comment
comment|/* Bad Kerberos name format */
end_comment

begin_comment
comment|/* Error code returned by krb_mk_safe */
end_comment

begin_define
define|#
directive|define
name|SAFE_PRIV_ERROR
value|-1
end_define

begin_comment
comment|/* syscall error */
end_comment

begin_comment
comment|/* Defines for krb_sendauth and krb_recvauth */
end_comment

begin_define
define|#
directive|define
name|KOPT_DONT_MK_REQ
value|0x00000001
end_define

begin_comment
comment|/* don't call krb_mk_req */
end_comment

begin_define
define|#
directive|define
name|KOPT_DO_MUTUAL
value|0x00000002
end_define

begin_comment
comment|/* do mutual auth */
end_comment

begin_define
define|#
directive|define
name|KOPT_DONT_CANON
value|0x00000004
end_define

begin_comment
comment|/* 				     * don't canonicalize inst as 				     * a hostname 				     */
end_comment

begin_define
define|#
directive|define
name|KOPT_IGNORE_PROTOCOL
value|0x0008
end_define

begin_define
define|#
directive|define
name|KRB_SENDAUTH_VLEN
value|8
end_define

begin_comment
comment|/* length for version strings */
end_comment

begin_comment
comment|/* flags for krb_verify_user() */
end_comment

begin_define
define|#
directive|define
name|KRB_VERIFY_NOT_SECURE
value|0
end_define

begin_define
define|#
directive|define
name|KRB_VERIFY_SECURE
value|1
end_define

begin_define
define|#
directive|define
name|KRB_VERIFY_SECURE_FAIL
value|2
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|krb4_version
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*key_proc_t
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|instance
operator|,
comment|/* INOUT parameter */
specifier|const
name|char
operator|*
name|realm
operator|,
specifier|const
name|void
operator|*
name|password
operator|,
name|des_cblock
operator|*
name|key
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*decrypt_proc_t
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|instance
operator|,
specifier|const
name|char
operator|*
name|realm
operator|,
specifier|const
name|void
operator|*
name|arg
operator|,
name|key_proc_t
operator|,
name|KTEXT
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_include
include|#
directive|include
file|"krb-protos.h"
end_include

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KRB_H__ */
end_comment

end_unit

