begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Include file for the Kerberos library.  *  *	from: krb.h,v 4.26 89/08/08 17:55:25 jtkohl Exp $  *	$Id: krb.h,v 1.11 1997/02/22 14:36:42 peter Exp $  */
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

begin_comment
comment|/* Need some defs from des.h	 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

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
name|char
modifier|*
name|krb_err_txt
index|[
name|MAX_KRB_ERRORS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are not defined for at least SunOS 3.3 and Ultrix 2.2 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ULTRIX022
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|SunOS
argument_list|)
operator|&&
name|SunOS
operator|<
literal|40
operator|)
end_if

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|((p)->fds_bits[0] = 0)
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0] |= (1<< (n)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]& (1<< (n)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ULTRIX022 || SunOS */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|NO_UIDGID_T
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_UIDGID_T */
end_comment

begin_comment
comment|/*  * Kerberos specific definitions  *  * KRBLOG is the log file for the kerberos master server. KRB_CONF is  * the configuration file where different host machines running master  * and slave servers can be found. KRB_MASTER is the name of the  * machine with the master database.  The admin_server runs on this  * machine, and all changes to the db (as opposed to read-only  * requests, which can go to slaves) must go to it. KRB_HOST is the  * default machine * when looking for a kerberos slave server.  Other  * possibilities are * in the KRB_CONF file. KRB_REALM is the name of  * the realm.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_expr_stmt
name|this
name|is
name|server
operator|-
name|only
operator|,
name|does
name|not
name|belong
name|here
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|KRBLOG
value|"/etc/kerberosIV/kerberos.log"
end_define

begin_expr_stmt
name|are
name|these
name|used
name|anyplace
literal|'?'
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VX_KRB_HSTFILE
value|"/etc/krbhst"
end_define

begin_define
define|#
directive|define
name|PC_KRB_HSTFILE
value|"\\kerberos\\krbhst"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB_CONF
value|"/etc/kerberosIV/krb.conf"
end_define

begin_define
define|#
directive|define
name|KRB_RLM_TRANS
value|"/etc/kerberosIV/krb.realms"
end_define

begin_define
define|#
directive|define
name|KRB_MASTER
value|"kerberos"
end_define

begin_define
define|#
directive|define
name|KRB_HOST
value|KRB_MASTER
end_define

begin_define
define|#
directive|define
name|KRB_REALM
value|"ATHENA.MIT.EDU"
end_define

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
comment|/* include space for '.' and '@' */
end_comment

begin_define
define|#
directive|define
name|MAX_K_NAME_SZ
value|(ANAME_SZ + INST_SZ + REALM_SZ + 2)
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

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_TKT_LIFE
end_ifndef

begin_comment
comment|/* allow compile-time override */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TKT_LIFE
value|96
end_define

begin_comment
comment|/* default lifetime for krb_mk_req& co., 8 hrs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|unsigned
name|long
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
comment|/* Definitions for cl_get_tgt */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|CL_GTGT_INIT_FILE
value|"\\kerberos\\k_in_tkts"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CL_GTGT_INIT_FILE
value|"/etc/k_in_tkts"
end_define

begin_endif
endif|#
directive|endif
endif|PC
end_endif

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

begin_define
define|#
directive|define
name|KEYFILE
value|"/etc/kerberosIV/srvtab"
end_define

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
name|unsigned
name|long
name|checksum
decl_stmt|;
comment|/* Data checksum (opt) */
name|C_Block
name|session
decl_stmt|;
comment|/* Session Key */
name|int
name|life
decl_stmt|;
comment|/* Life of ticket */
name|unsigned
name|long
name|time_sec
decl_stmt|;
comment|/* Time ticket issued */
name|unsigned
name|long
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
name|C_Block
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
name|long
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
name|unsigned
name|long
name|app_length
decl_stmt|;
comment|/* length of appl data */
name|unsigned
name|long
name|hash
decl_stmt|;
comment|/* hash to lookup replay */
name|int
name|swap
decl_stmt|;
comment|/* swap bytes? */
name|long
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

begin_comment
comment|/* Location of ticket file for save_cred and get_cred */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|TKT_FILE
value|"\\kerberos\\ticket.ses"
end_define

begin_else
else|#
directive|else
end_else

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
value|"/tmp/tkt"
end_define

begin_endif
endif|#
directive|endif
endif|PC
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
comment|/* Error codes returned by get_local_addr and bind_local_addr */
end_comment

begin_define
define|#
directive|define
name|GT_LADDR_NOSOCK
value|82
end_define

begin_comment
comment|/* Can't open socket */
end_comment

begin_define
define|#
directive|define
name|GT_LADDR_IFLIST
value|83
end_define

begin_comment
comment|/* 					 * Can't retrieve local interface  					 * configuration list 					 */
end_comment

begin_define
define|#
directive|define
name|GT_LADDR_NVI
value|84
end_define

begin_comment
comment|/* No valid local interface found */
end_comment

begin_define
define|#
directive|define
name|BND_LADDR_BIND
value|85
end_define

begin_comment
comment|/* Can't bind local address */
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
comment|/*  * macros for byte swapping; also scratch space  * u_quad  0-->7, 1-->6, 2-->5, 3-->4, 4-->3, 5-->2, 6-->1, 7-->0  * u_long  0-->3, 1-->2, 2-->1, 3-->0  * u_short 0-->1, 1-->0  */
end_comment

begin_define
define|#
directive|define
name|swap_u_16
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned long   _krb_swap_tmp[4];\  swab(((char *) x) +0, ((char *)  _krb_swap_tmp) +14 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +12 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +8  ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +12,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +14,((char *)  _krb_swap_tmp) +0 ,2); \  bcopy((char *)_krb_swap_tmp,(char *)x,16);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_12
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned long   _krb_swap_tmp[4];\  swab(( char *) x,     ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +8 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +0 ,2); \  bcopy((char *)_krb_swap_tmp,(char *)x,12);\                             }
end_define

begin_define
define|#
directive|define
name|swap_C_Block
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned long   _krb_swap_tmp[4];\  swab(( char *) x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +6,((char *)  _krb_swap_tmp)    ,2); \  bcopy((char *)_krb_swap_tmp,(char *)x,8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_quad
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned long   _krb_swap_tmp[4];\  swab(( char *)&x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *)&x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +6,((char *)  _krb_swap_tmp)    ,2); \  bcopy((char *)_krb_swap_tmp,(char *)&x,8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_long
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned long   _krb_swap_tmp[4];\  swab((char *)&x,    ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp),2); \  x = _krb_swap_tmp[0];   \                            }
end_define

begin_define
define|#
directive|define
name|swap_u_short
parameter_list|(
name|x
parameter_list|)
value|{\  unsigned short	_krb_swap_sh_tmp; \  swab((char *)&x,    (&_krb_swap_sh_tmp) ,2); \  x = (unsigned short) _krb_swap_sh_tmp; \                             }
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

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_function_decl
name|char
modifier|*
name|tkt_string
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OLDNAMES
end_ifdef

begin_define
define|#
directive|define
name|krb_mk_req
value|mk_ap_req
end_define

begin_define
define|#
directive|define
name|krb_rd_req
value|rd_ap_req
end_define

begin_define
define|#
directive|define
name|krb_kntoln
value|an_to_ln
end_define

begin_define
define|#
directive|define
name|krb_set_key
value|set_serv_key
end_define

begin_define
define|#
directive|define
name|krb_get_cred
value|get_credentials
end_define

begin_define
define|#
directive|define
name|krb_mk_priv
value|mk_private_msg
end_define

begin_define
define|#
directive|define
name|krb_rd_priv
value|rd_private_msg
end_define

begin_define
define|#
directive|define
name|krb_mk_safe
value|mk_safe_msg
end_define

begin_define
define|#
directive|define
name|krb_rd_safe
value|rd_safe_msg
end_define

begin_define
define|#
directive|define
name|krb_mk_err
value|mk_appl_err_msg
end_define

begin_define
define|#
directive|define
name|krb_rd_err
value|rd_appl_err_msg
end_define

begin_define
define|#
directive|define
name|krb_ck_repl
value|check_replay
end_define

begin_define
define|#
directive|define
name|krb_get_pw_in_tkt
value|get_in_tkt
end_define

begin_define
define|#
directive|define
name|krb_get_svc_in_tkt
value|get_svc_in_tkt
end_define

begin_define
define|#
directive|define
name|krb_get_pw_tkt
value|get_pw_tkt
end_define

begin_define
define|#
directive|define
name|krb_realmofhost
value|krb_getrealm
end_define

begin_define
define|#
directive|define
name|krb_get_phost
value|get_phost
end_define

begin_define
define|#
directive|define
name|krb_get_krbhst
value|get_krbhst
end_define

begin_define
define|#
directive|define
name|krb_get_lrealm
value|get_krbrlm
end_define

begin_endif
endif|#
directive|endif
endif|OLDNAMES
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|ATHENA_COMPAT
end_ifdef

begin_define
define|#
directive|define
name|KOPT_DO_OLDSTYLE
value|0x00000008
end_define

begin_comment
comment|/* use the old-style protocol */
end_comment

begin_endif
endif|#
directive|endif
endif|ATHENA_COMPAT
end_endif

begin_comment
comment|/* libacl */
end_comment

begin_decl_stmt
name|void
name|acl_canonicalize_principal
name|__P
argument_list|(
operator|(
name|char
operator|*
name|principal
operator|,
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acl_check
name|__P
argument_list|(
operator|(
name|char
operator|*
name|acl
operator|,
name|char
operator|*
name|principal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acl_exact_match
name|__P
argument_list|(
operator|(
name|char
operator|*
name|acl
operator|,
name|char
operator|*
name|principal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acl_add
name|__P
argument_list|(
operator|(
name|char
operator|*
name|acl
operator|,
name|char
operator|*
name|principal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acl_delete
name|__P
argument_list|(
operator|(
name|char
operator|*
name|acl
operator|,
name|char
operator|*
name|principal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acl_initialize
name|__P
argument_list|(
operator|(
name|char
operator|*
name|acl_file
operator|,
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* libkrb - krb.3 */
end_comment

begin_decl_stmt
name|int
name|krb_mk_req
name|__P
argument_list|(
operator|(
name|KTEXT
name|authent
operator|,
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|long
name|checksum
operator|)
argument_list|;
name|int
name|krb_rd_req
name|__P
argument_list|(
operator|(
name|KTEXT
name|authent
operator|,
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|long
name|from_addr
operator|,
name|AUTH_DAT
operator|*
name|ad
operator|,
name|char
operator|*
name|fn
operator|)
argument_list|)
argument_list|;
name|int
name|krb_kntoln
name|__P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
name|ad
operator|,
name|char
operator|*
name|lname
operator|)
argument_list|)
argument_list|;
name|int
name|krb_set_key
name|__P
argument_list|(
operator|(
name|char
operator|*
name|key
operator|,
name|int
name|cvt
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_cred
name|__P
argument_list|(
operator|(
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|CREDENTIALS
operator|*
name|c
operator|)
argument_list|)
argument_list|;
name|long
name|krb_mk_priv
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|in
operator|,
name|u_char
operator|*
name|out
operator|,
name|u_long
name|in_length
operator|,
name|des_key_schedule
name|schedule
operator|,
name|des_cblock
name|key
operator|,
expr|struct
name|sockaddr_in
operator|*
name|sender
operator|,
expr|struct
name|sockaddr_in
operator|*
name|receiver
operator|)
argument_list|)
argument_list|;
name|long
name|krb_rd_priv
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|in
operator|,
name|u_long
name|in_length
operator|,
name|Key_schedule
name|schedule
operator|,
name|des_cblock
name|key
operator|,
expr|struct
name|sockaddr_in
operator|*
name|sender
operator|,
expr|struct
name|sockaddr_in
operator|*
name|receiver
operator|,
name|MSG_DAT
operator|*
name|msg_data
operator|)
argument_list|)
argument_list|;
name|long
name|krb_mk_safe
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|in
operator|,
name|u_char
operator|*
name|out
operator|,
name|u_long
name|in_length
operator|,
name|des_cblock
operator|*
name|key
operator|,
expr|struct
name|sockaddr_in
operator|*
name|sender
operator|,
expr|struct
name|sockaddr_in
operator|*
name|receiver
operator|)
argument_list|)
argument_list|;
name|long
name|krb_rd_safe
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|in
operator|,
name|u_long
name|length
operator|,
name|des_cblock
operator|*
name|key
operator|,
expr|struct
name|sockaddr_in
operator|*
name|sender
operator|,
expr|struct
name|sockaddr_in
operator|*
name|receiver
operator|,
name|MSG_DAT
operator|*
name|msg_data
operator|)
argument_list|)
argument_list|;
name|long
name|krb_mk_err
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|out
operator|,
name|long
name|code
operator|,
name|char
operator|*
name|string
operator|)
argument_list|)
argument_list|;
name|int
name|krb_rd_err
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|in
operator|,
name|u_long
name|in_length
operator|,
name|long
operator|*
name|code
operator|,
name|MSG_DAT
operator|*
name|m_data
operator|)
argument_list|)
argument_list|;
comment|/* libkrb - krb_sendauth.3 */
name|int
name|krb_sendauth
name|__P
argument_list|(
operator|(
name|long
name|options
operator|,
name|int
name|fd
operator|,
name|KTEXT
name|ticket
operator|,
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|inst
operator|,
name|char
operator|*
name|realm
operator|,
name|u_long
name|checksum
operator|,
name|MSG_DAT
operator|*
name|msg_data
operator|,
name|CREDENTIALS
operator|*
name|cred
operator|,
name|Key_schedule
name|schedule
operator|,
expr|struct
name|sockaddr_in
operator|*
name|laddr
operator|,
expr|struct
name|sockaddr_in
operator|*
name|faddr
operator|,
name|char
operator|*
name|version
operator|)
argument_list|)
argument_list|;
name|int
name|krb_recvauth
name|__P
argument_list|(
operator|(
name|long
name|options
operator|,
name|int
name|fd
operator|,
name|KTEXT
name|ticket
operator|,
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
expr|struct
name|sockaddr_in
operator|*
name|faddr
operator|,
expr|struct
name|sockaddr_in
operator|*
name|laddr
operator|,
name|AUTH_DAT
operator|*
name|kdata
operator|,
name|char
operator|*
name|filename
operator|,
name|Key_schedule
name|schedule
operator|,
name|char
operator|*
name|version
operator|)
argument_list|)
argument_list|;
name|int
name|krb_net_write
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
argument_list|;
name|int
name|krb_net_read
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
argument_list|;
comment|/* libkrb - krb_realmofhost.3 */
name|char
operator|*
name|krb_realmofhost
name|__P
argument_list|(
operator|(
name|char
operator|*
name|host
operator|)
argument_list|)
argument_list|;
name|char
operator|*
name|krb_get_phost
name|__P
argument_list|(
operator|(
name|char
operator|*
name|alias
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_krbhst
name|__P
argument_list|(
operator|(
name|char
operator|*
name|h
operator|,
name|char
operator|*
name|r
operator|,
name|int
name|n
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_admhst
name|__P
argument_list|(
operator|(
name|char
operator|*
name|h
operator|,
name|char
operator|*
name|r
operator|,
name|int
name|n
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_lrealm
name|__P
argument_list|(
operator|(
name|char
operator|*
name|r
operator|,
name|int
name|n
operator|)
argument_list|)
argument_list|;
comment|/* libkrb - krb_set_tkt_string.3 */
name|void
name|krb_set_tkt_string
argument_list|(
name|char
operator|*
name|val
argument_list|)
argument_list|;
comment|/* libkrb - kuserok.3 */
name|int
name|kuserok
name|__P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
name|authdata
operator|,
name|char
operator|*
name|localuser
operator|)
argument_list|)
argument_list|;
comment|/* libkrb - tf_util.3 */
name|int
name|tf_init
name|__P
argument_list|(
operator|(
name|char
operator|*
name|tf_name
operator|,
name|int
name|rw
operator|)
argument_list|)
argument_list|;
name|int
name|tf_get_pname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|p
operator|)
argument_list|)
argument_list|;
name|int
name|tf_get_pinst
name|__P
argument_list|(
operator|(
name|char
operator|*
name|inst
operator|)
argument_list|)
argument_list|;
name|int
name|tf_get_cred
name|__P
argument_list|(
operator|(
name|CREDENTIALS
operator|*
name|c
operator|)
argument_list|)
argument_list|;
name|void
name|tf_close
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
argument_list|;
comment|/* Internal routines */
name|int
name|des_set_key_krb
name|__P
argument_list|(
operator|(
name|des_cblock
operator|*
name|inkey
operator|,
name|des_key_schedule
name|insched
operator|)
argument_list|)
argument_list|;
name|void
name|des_clear_key_krb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
argument_list|;
name|int
name|des_read
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
argument_list|;
name|int
name|des_write
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_tf_realm
name|__P
argument_list|(
operator|(
name|char
operator|*
name|ticket_file
operator|,
name|char
operator|*
name|realm
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|user
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
name|service
operator|,
name|char
operator|*
name|sinstance
operator|,
name|int
name|life
operator|,
name|int
argument_list|(
operator|*
name|key_proc
argument_list|)
argument_list|()
operator|,
name|int
argument_list|(
operator|*
name|decrypt_proc
argument_list|)
argument_list|()
operator|,
name|char
operator|*
name|arg
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_pw_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|user
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
name|service
operator|,
name|char
operator|*
name|sinstance
operator|,
name|int
name|life
operator|,
name|char
operator|*
name|password
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_svc_in_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|user
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
name|service
operator|,
name|char
operator|*
name|sinstance
operator|,
name|int
name|life
operator|,
name|char
operator|*
name|srvtab
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_tf_fullname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|ticket_file
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
argument_list|;
name|int
name|save_credentials
name|__P
argument_list|(
operator|(
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|des_cblock
name|session
operator|,
name|int
name|lifetime
operator|,
name|int
name|kvno
operator|,
name|KTEXT
name|ticket
operator|,
name|long
name|issue_date
operator|)
argument_list|)
argument_list|;
name|int
name|read_service_key
name|__P
argument_list|(
operator|(
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|int
name|kvno
operator|,
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|key
operator|)
argument_list|)
argument_list|;
name|int
name|get_ad_tkt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|sinstance
operator|,
name|char
operator|*
name|realm
operator|,
name|int
name|lifetime
operator|)
argument_list|)
argument_list|;
name|int
name|send_to_kdc
name|__P
argument_list|(
operator|(
name|KTEXT
name|pkt
operator|,
name|KTEXT
name|rpkt
operator|,
name|char
operator|*
name|realm
operator|)
argument_list|)
argument_list|;
name|int
name|krb_bind_local_addr
name|__P
argument_list|(
operator|(
name|int
name|s
operator|)
argument_list|)
argument_list|;
name|int
name|krb_get_local_addr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
name|returned_addr
operator|)
argument_list|)
argument_list|;
name|int
name|krb_create_ticket
name|__P
argument_list|(
operator|(
name|KTEXT
name|tkt
operator|,
name|unsigned
name|char
name|flags
operator|,
name|char
operator|*
name|pname
operator|,
name|char
operator|*
name|pinstance
operator|,
name|char
operator|*
name|prealm
operator|,
name|long
name|paddress
operator|,
name|char
operator|*
name|session
operator|,
name|short
name|life
operator|,
name|long
name|time_sec
operator|,
name|char
operator|*
name|sname
operator|,
name|char
operator|*
name|sinstance
operator|,
name|C_Block
name|key
operator|)
argument_list|)
argument_list|;
name|int
name|decomp_ticket
name|__P
argument_list|(
operator|(
name|KTEXT
name|tkt
operator|,
name|unsigned
name|char
operator|*
name|flags
operator|,
name|char
operator|*
name|pname
operator|,
name|char
operator|*
name|pinstance
operator|,
name|char
operator|*
name|prealm
operator|,
name|unsigned
name|long
operator|*
name|paddress
operator|,
name|des_cblock
name|session
operator|,
name|int
operator|*
name|life
operator|,
name|unsigned
name|long
operator|*
name|time_sec
operator|,
name|char
operator|*
name|sname
operator|,
name|char
operator|*
name|sinstance
operator|,
name|des_cblock
name|key
operator|,
name|des_key_schedule
name|key_s
operator|)
argument_list|)
argument_list|;
name|int
name|create_ciph
name|__P
argument_list|(
operator|(
name|KTEXT
name|c
operator|,
name|C_Block
name|session
operator|,
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|unsigned
name|long
name|life
operator|,
name|int
name|kvno
operator|,
name|KTEXT
name|tkt
operator|,
name|unsigned
name|long
name|kdc_time
operator|,
name|C_Block
name|key
operator|)
argument_list|)
argument_list|;
name|int
name|kname_parse
name|__P
argument_list|(
operator|(
name|char
operator|*
name|np
operator|,
name|char
operator|*
name|ip
operator|,
name|char
operator|*
name|rp
operator|,
name|char
operator|*
name|fullname
operator|)
argument_list|)
argument_list|;
name|int
name|tf_save_cred
name|__P
argument_list|(
operator|(
name|char
operator|*
name|service
operator|,
name|char
operator|*
name|instance
operator|,
name|char
operator|*
name|realm
operator|,
name|des_cblock
name|session
operator|,
name|int
name|lifetime
operator|,
name|int
name|kvno
operator|,
name|KTEXT
name|ticket
operator|,
name|long
name|issue_date
operator|)
argument_list|)
argument_list|;
name|int
name|getst
argument_list|(
argument|int fd
argument_list|,
argument|char *s
argument_list|,
argument|int n
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pkt_clen
name|__P
argument_list|(
operator|(
name|KTEXT
name|pkt
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
name|pname
operator|,
name|char
operator|*
name|pinst
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
name|char
modifier|*
name|month_sname
name|__P
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|log
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actually VARARGS - markm */
end_comment

begin_decl_stmt
name|void
name|kset_logfile
name|__P
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_logfile
name|__P
argument_list|(
operator|(
name|char
operator|*
name|filename
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
name|s
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
name|s
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
name|s
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
name|name
operator|,
name|int
name|namelen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kerb_init
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
name|kerb_fini
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
name|kerb_db_set_name
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kerb_db_set_lockmode
name|__P
argument_list|(
operator|(
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kerb_db_create
name|__P
argument_list|(
operator|(
name|char
operator|*
name|db_name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kerb_db_iterate
name|__P
argument_list|(
operator|(
name|int
argument_list|(
operator|*
name|func
argument_list|)
argument_list|()
operator|,
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kerb_db_rename
name|__P
argument_list|(
operator|(
name|char
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
name|long
name|kerb_get_db_age
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|stime
name|__P
argument_list|(
operator|(
name|long
operator|*
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|kdb_get_master_key
name|__P
argument_list|(
operator|(
name|int
name|prompt
operator|,
name|C_Block
name|master_key
operator|,
name|Key_schedule
name|master_key_sched
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|kdb_verify_master_key
name|__P
argument_list|(
operator|(
name|C_Block
name|master_key
operator|,
name|Key_schedule
name|master_key_sched
operator|,
name|FILE
operator|*
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdb_encrypt_key
name|__P
argument_list|(
operator|(
name|C_Block
name|in
operator|,
name|C_Block
name|out
operator|,
name|C_Block
name|master_key
operator|,
name|Key_schedule
name|master_key_sched
operator|,
name|int
name|e_d_flag
operator|)
argument_list|)
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
name|krb_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|KRB_DEFS
end_endif

end_unit

