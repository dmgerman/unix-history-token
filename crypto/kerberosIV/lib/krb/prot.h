begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: prot.h,v 1.9 1999/11/30 18:57:46 bg Exp $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Include file with authentication protocol information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROT_DEFS
end_ifndef

begin_define
define|#
directive|define
name|PROT_DEFS
end_define

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_define
define|#
directive|define
name|KRB_SERVICE
value|"kerberos-iv"
end_define

begin_define
define|#
directive|define
name|KRB_PORT
value|750
end_define

begin_comment
comment|/* PC's don't have 						 * /etc/services */
end_comment

begin_define
define|#
directive|define
name|KRB_PROT_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|MAX_PKT_LEN
value|1000
end_define

begin_define
define|#
directive|define
name|MAX_TXT_LEN
value|1000
end_define

begin_comment
comment|/* Routines to create and read packets may be found in prot.c */
end_comment

begin_function_decl
name|KTEXT
name|create_auth_reply
parameter_list|(
name|char
modifier|*
name|pname
parameter_list|,
name|char
modifier|*
name|pinst
parameter_list|,
name|char
modifier|*
name|prealm
parameter_list|,
name|int32_t
name|time_ws
parameter_list|,
name|int
name|n
parameter_list|,
name|u_int32_t
name|x_date
parameter_list|,
name|int
name|kvno
parameter_list|,
name|KTEXT
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
name|KTEXT
name|krb_create_death_packet
parameter_list|(
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Message types , always leave lsb for byte order */
end_comment

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REQUEST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REPLY
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST_MUTUAL
value|(4<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_ERR_REPLY
value|(5<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_PRIVATE
value|(6<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_SAFE
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_ERR
value|(8<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_FORWARD
value|(9<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_RENEW
value|(10<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_DIE
value|(63<<1)
end_define

begin_comment
comment|/* values for kerb error codes */
end_comment

begin_define
define|#
directive|define
name|KERB_ERR_OK
value|0
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NAME_EXP
value|1
end_define

begin_define
define|#
directive|define
name|KERB_ERR_SERVICE_EXP
value|2
end_define

begin_define
define|#
directive|define
name|KERB_ERR_AUTH_EXP
value|3
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PKT_VER
value|4
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NAME_MAST_KEY_VER
value|5
end_define

begin_define
define|#
directive|define
name|KERB_ERR_SERV_MAST_KEY_VER
value|6
end_define

begin_define
define|#
directive|define
name|KERB_ERR_BYTE_ORDER
value|7
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PRINCIPAL_UNKNOWN
value|8
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PRINCIPAL_NOT_UNIQUE
value|9
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NULL_KEY
value|10
end_define

begin_define
define|#
directive|define
name|KERB_ERR_TIMEOUT
value|11
end_define

begin_comment
comment|/* sendauth - recvauth */
end_comment

begin_comment
comment|/*  * If the protocol changes, you will need to change the version string  * be sure to support old versions of krb_sendauth!  */
end_comment

begin_define
define|#
directive|define
name|KRB_SENDAUTH_VERS
value|"AUTHV0.1"
end_define

begin_comment
comment|/* MUST be KRB_SENDAUTH_VLEN chars */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROT_DEFS */
end_comment

end_unit

