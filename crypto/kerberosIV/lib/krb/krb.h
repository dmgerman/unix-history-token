begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   *  * Include file for the Kerberos library.   */
end_comment

begin_comment
comment|/* Only one time, please */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KRB_DEFS
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|__P
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
endif|#
directive|endif
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
file|<des.h>
comment|/* Don't use these guys, they are only for compatibility with CNS. */
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
comment|/* Use this function rather than indexing in krb_err_txt */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|krb_get_err_text
name|__P
argument_list|(
operator|(
name|int
name|code
operator|)
argument_list|)
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

begin_comment
comment|/* FreeBSD wants to maintain backwards compatibility */
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
comment|/* time between retries */
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
value|"/etc/kerberosIV/srvtab"
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
name|int
name|proto
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|admin
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|krb_host
modifier|*
name|krb_get_host
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of ticket file for save_cred and get_cred */
end_comment

begin_define
define|#
directive|define
name|TKT_FILE
value|tkt_string()
end_define

begin_define
define|#
directive|define
name|TKT_ROOT
value|"/tmp/tkt_"
end_define

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
comment|/*  * macros for byte swapping; also scratch space  * u_quad  0-->7, 1-->6, 2-->5, 3-->4, 4-->3, 5-->2, 6-->1, 7-->0  * u_int32_t  0-->3, 1-->2, 2-->1, 3-->0  * u_int16_t 0-->1, 1-->0  */
end_comment

begin_define
define|#
directive|define
name|swap_u_16
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(((char *) x) +0, ((char *)  _krb_swap_tmp) +14 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +12 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +8  ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +12,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +14,((char *)  _krb_swap_tmp) +0 ,2); \  memcpy(x, _krb_swap_tmp, 16);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_12
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *) x,     ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +8 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +0 ,2); \  memcpy(x, _krb_swap_tmp, 12);\                             }
end_define

begin_define
define|#
directive|define
name|swap_C_Block
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *) x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +6,((char *)  _krb_swap_tmp)    ,2); \  memcpy(x, _krb_swap_tmp, 8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_quad
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *)&x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *)&x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +6,((char *)  _krb_swap_tmp)    ,2); \  memcpy(x, _krb_swap_tmp, 8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_long
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab((char *)&x,    ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp),2); \  x = _krb_swap_tmp[0];   \                            }
end_define

begin_define
define|#
directive|define
name|swap_u_short
parameter_list|(
name|x
parameter_list|)
value|{\  u_int16_t	_krb_swap_sh_tmp; \  swab((char *)&x,    (&_krb_swap_sh_tmp) ,2); \  x = (u_int16_t) _krb_swap_sh_tmp; \                             }
end_define

begin_comment
comment|/* Kerberos ticket flag field bit definitions */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_ORDER
value|0
end_define

begin_comment
comment|/* bit 0 --> lsb */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_1
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_2
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_3
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_4
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_5
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_6
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_7
end_define

begin_comment
comment|/* reserved, bit 7 --> msb */
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
name|KRB_SENDAUTH_VLEN
value|8
end_define

begin_comment
comment|/* length for version strings */
end_comment

begin_comment
comment|/* File locking */
end_comment

begin_define
define|#
directive|define
name|K_LOCK_SH
value|1
end_define

begin_comment
comment|/* Shared lock */
end_comment

begin_define
define|#
directive|define
name|K_LOCK_EX
value|2
end_define

begin_comment
comment|/* Exclusive lock */
end_comment

begin_define
define|#
directive|define
name|K_LOCK_NB
value|4
end_define

begin_comment
comment|/* Don't block when locking */
end_comment

begin_define
define|#
directive|define
name|K_LOCK_UN
value|8
end_define

begin_comment
comment|/* Unlock */
end_comment

begin_decl_stmt
name|int
name|k_flock
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|int
name|operation
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tm
modifier|*
name|k_localtime
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_getsockinst
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|inst
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_getportbyname
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|service
operator|,
specifier|const
name|char
operator|*
name|proto
operator|,
name|int
name|default_port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|krb4_version
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|k_get_all_addrs
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|*
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Host address comparison */
end_comment

begin_decl_stmt
name|int
name|krb_equiv
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Password conversion */
end_comment

begin_decl_stmt
name|void
name|mit_string_to_key
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|char
operator|*
name|cell
operator|,
name|des_cblock
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|afs_string_to_key
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|char
operator|*
name|cell
operator|,
name|des_cblock
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lifetime conversion */
end_comment

begin_decl_stmt
name|u_int32_t
name|krb_life_to_time
name|__P
argument_list|(
operator|(
name|u_int32_t
name|start
operator|,
name|int
name|life
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_time_to_life
name|__P
argument_list|(
operator|(
name|u_int32_t
name|start
operator|,
name|u_int32_t
name|end
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_life_to_atime
name|__P
argument_list|(
operator|(
name|int
name|life
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_atime_to_life
name|__P
argument_list|(
operator|(
name|char
operator|*
name|atime
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ticket manipulation */
end_comment

begin_decl_stmt
name|int
name|tf_get_cred
name|__P
argument_list|(
operator|(
name|CREDENTIALS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_get_pinst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_get_pname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_put_pinst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_put_pname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_init
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_save_cred
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|KTEXT
name|ticket
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tf_close
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_setup
name|__P
argument_list|(
operator|(
name|CREDENTIALS
operator|*
name|cred
operator|,
name|char
operator|*
name|pname
operator|,
name|char
operator|*
name|pinst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private communication */
end_comment

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int32_t
name|krb_mk_priv
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int32_t
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int32_t
name|krb_rd_priv
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_int32_t
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Misc */
end_comment

begin_decl_stmt
name|KTEXT
name|create_auth_reply
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int32_t
operator|,
name|int
operator|,
name|u_int32_t
operator|,
name|int
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_get_phost
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_realmofhost
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tkt_string
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|create_ciph
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|unsigned
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int32_t
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|u_int32_t
operator|,
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|decomp_ticket
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|unsigned
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dest_tkt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_ad_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_pw_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_request
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_gethostname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isinst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isrealm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kname_parse
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_parse_name
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|krb_principal
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_unparse_name
name|__P
argument_list|(
operator|(
name|krb_principal
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_unparse_name_r
name|__P
argument_list|(
operator|(
name|krb_principal
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_unparse_name_long
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_unparse_name_long_r
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|char
operator|*
name|fullname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_create_ticket
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|unsigned
name|char
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int32_t
operator|,
name|void
operator|*
operator|,
name|int16_t
operator|,
name|int32_t
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_admhst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_cred
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|CREDENTIALS
operator|*
operator|)
argument_list|)
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
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|des_cblock
operator|*
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
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|key_proc_t
operator|,
name|KTEXT
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|krb_get_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|key_proc_t
operator|,
name|decrypt_proc_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|srvtab_to_key
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|passwd_to_key
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|passwd_to_afskey
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_krbhst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_lrealm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_get_default_realm
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_pw_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_svc_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_tf_fullname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_tf_realm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_kntoln
name|__P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_mk_req
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_net_read
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_net_write
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_rd_err
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32_t
operator|,
name|int32_t
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_rd_req
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int32_t
operator|,
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_recvauth
name|__P
argument_list|(
operator|(
name|int32_t
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_sendauth
name|__P
argument_list|(
operator|(
name|int32_t
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int32_t
operator|,
name|MSG_DAT
operator|*
operator|,
name|CREDENTIALS
operator|*
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_mk_auth
name|__P
argument_list|(
operator|(
name|int32_t
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int32_t
operator|,
name|char
operator|*
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_check_auth
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|u_int32_t
operator|,
name|MSG_DAT
operator|*
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|des_ks_struct
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_set_key
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_set_lifetime
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_kuserok
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|inst
operator|,
name|char
operator|*
name|realm
operator|,
name|char
operator|*
name|luser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kuserok
name|__P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_service_key
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|save_credentials
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|send_to_kdc
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int32_t
name|krb_mk_err
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int32_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int32_t
name|krb_mk_safe
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int32_t
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int32_t
name|krb_rd_safe
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_int32_t
operator|,
name|des_cblock
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ad_print
name|__P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cr_err_reply
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|extract_ticket
name|__P
argument_list|(
operator|(
name|KTEXT
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|krb_set_tkt_string
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_default_principal
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_realm_parse
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_verify_user
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logging.c */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|krb_log_func_t
function_decl|)
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb_log_func_t
name|krb_warnfn_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb_log_facility
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|krb_vlogger
name|__P
argument_list|(
operator|(
expr|struct
name|krb_log_facility
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_logger
name|__P
argument_list|(
operator|(
expr|struct
name|krb_log_facility
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_openlog
name|__P
argument_list|(
operator|(
expr|struct
name|krb_log_facility
operator|*
operator|,
name|char
operator|*
operator|,
name|FILE
operator|*
operator|,
name|krb_log_func_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|krb_set_warnfn
name|__P
argument_list|(
operator|(
name|krb_warnfn_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb_warnfn_t
name|krb_get_warnfn
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|krb_warning
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kset_logfile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|krb_log
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|klog
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getst
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|month_sname
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|krb_stime
name|__P
argument_list|(
operator|(
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_check_tm
name|__P
argument_list|(
operator|(
expr|struct
name|tm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_int
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|u_int32_t
operator|*
name|to
operator|,
name|int
name|size
operator|,
name|int
name|lsb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_put_int
name|__P
argument_list|(
operator|(
name|u_int32_t
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_address
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|u_int32_t
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_put_address
name|__P
argument_list|(
operator|(
name|u_int32_t
name|addr
operator|,
name|void
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_put_string
name|__P
argument_list|(
operator|(
name|char
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_string
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_get_nir
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_put_nir
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|void
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB_DEFS */
end_comment

end_unit

