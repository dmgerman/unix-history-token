begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB5_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB5_LOCL_H__
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MMAN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_IOCTL_H
argument_list|)
operator|&&
name|SunOS
operator|!=
literal|40
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_PTHREAD_SEMANTICS
end_undef

begin_comment
comment|/* This gets us the 5-arg getpwnam_r on Solaris 9.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
end_define

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET6_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_struct_decl
struct_decl|struct
name|ether_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_NAMESER_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<com_err.h>
end_include

begin_include
include|#
directive|include
file|<heimbase.h>
end_include

begin_define
define|#
directive|define
name|HEIMDAL_TEXTDOMAIN
value|"heimdal_krb5"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIBINTL
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|dgettext(HEIMDAL_TEXTDOMAIN, x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|package
parameter_list|,
name|localedir
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CRYPT_H
end_ifdef

begin_undef
undef|#
directive|undef
name|des_encrypt
end_undef

begin_define
define|#
directive|define
name|des_encrypt
value|wingless_pigs_mostly_fail_to_fly
end_define

begin_include
include|#
directive|include
file|<crypt.h>
end_include

begin_undef
undef|#
directive|undef
name|des_encrypt
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DOOR_CREATE
end_ifdef

begin_include
include|#
directive|include
file|<door.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<parse_time.h>
end_include

begin_include
include|#
directive|include
file|<base64.h>
end_include

begin_include
include|#
directive|include
file|<wind.h>
end_include

begin_define
define|#
directive|define
name|HC_DEPRECATED_CRYPTO
end_define

begin_include
include|#
directive|include
file|"crypto-headers.h"
end_include

begin_include
include|#
directive|include
file|<krb5_asn1.h>
end_include

begin_struct_decl
struct_decl|struct
name|send_to_kdc
struct_decl|;
end_struct_decl

begin_comment
comment|/* XXX glue for pkinit */
end_comment

begin_struct_decl
struct_decl|struct
name|hx509_certs_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_pk_identity
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_pk_cert
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ContentInfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|AlgorithmIdentifier
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_pk_init_ctx_data
modifier|*
name|krb5_pk_init_ctx
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_dh_moduli
struct_decl|;
end_struct_decl

begin_comment
comment|/* v4 glue */
end_comment

begin_struct_decl
struct_decl|struct
name|_krb5_krb_auth_data
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<der.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<krb5_err.h>
end_include

begin_include
include|#
directive|include
file|<asn1_err.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PKINIT
end_ifdef

begin_include
include|#
directive|include
file|<hx509.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"crypto.h"
end_include

begin_include
include|#
directive|include
file|<krb5-private.h>
end_include

begin_include
include|#
directive|include
file|"heim_threads.h"
end_include

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(X) = calloc((N), sizeof(*(X)))
end_define

begin_define
define|#
directive|define
name|ALLOC_SEQ
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|do { (X)->len = (N); ALLOC((X)->val, (N)); } while(0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__func__
end_ifndef

begin_define
define|#
directive|define
name|__func__
value|"unknown-function"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|krb5_einval
parameter_list|(
name|context
parameter_list|,
name|argnum
parameter_list|)
value|_krb5_einval((context), __func__, (argnum))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_SEP
end_ifndef

begin_define
define|#
directive|define
name|PATH_SEP
value|":"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* should this be public? */
end_comment

begin_define
define|#
directive|define
name|KEYTAB_DEFAULT
value|"FILE:" SYSCONFDIR "/krb5.keytab"
end_define

begin_define
define|#
directive|define
name|KEYTAB_DEFAULT_MODIFY
value|"FILE:" SYSCONFDIR "/krb5.keytab"
end_define

begin_define
define|#
directive|define
name|MODULI_FILE
value|SYSCONFDIR "/krb5.moduli"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|O_CLOEXEC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SOCK_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|SOCK_CLOEXEC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB5_BUFSIZ
value|2048
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|KRB5_INIT_CREDS_TRISTATE_UNSET
init|=
literal|0
block|,
name|KRB5_INIT_CREDS_TRISTATE_TRUE
block|,
name|KRB5_INIT_CREDS_TRISTATE_FALSE
block|}
name|krb5_get_init_creds_tristate
typedef|;
end_typedef

begin_struct
struct|struct
name|_krb5_get_init_creds_opt_private
block|{
name|int
name|refcount
decl_stmt|;
comment|/* ENC_TIMESTAMP */
specifier|const
name|char
modifier|*
name|password
decl_stmt|;
name|krb5_s2k_proc
name|key_proc
decl_stmt|;
comment|/* PA_PAC_REQUEST */
name|krb5_get_init_creds_tristate
name|req_pac
decl_stmt|;
comment|/* PKINIT */
name|krb5_pk_init_ctx
name|pk_init_ctx
decl_stmt|;
name|krb5_get_init_creds_tristate
name|addressless
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|KRB5_INIT_CREDS_CANONICALIZE
value|1
define|#
directive|define
name|KRB5_INIT_CREDS_NO_C_CANON_CHECK
value|2
define|#
directive|define
name|KRB5_INIT_CREDS_NO_C_NO_EKU_CHECK
value|4
struct|struct
block|{
name|krb5_gic_process_last_req
name|func
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|}
name|lr
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint32_t
name|krb5_enctype_set
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_context_data
block|{
name|krb5_enctype
modifier|*
name|etypes
decl_stmt|;
name|krb5_enctype
modifier|*
name|etypes_des
decl_stmt|;
comment|/* deprecated */
name|krb5_enctype
modifier|*
name|as_etypes
decl_stmt|;
name|krb5_enctype
modifier|*
name|tgs_etypes
decl_stmt|;
name|krb5_enctype
modifier|*
name|permitted_enctypes
decl_stmt|;
name|char
modifier|*
modifier|*
name|default_realms
decl_stmt|;
name|time_t
name|max_skew
decl_stmt|;
name|time_t
name|kdc_timeout
decl_stmt|;
name|unsigned
name|max_retries
decl_stmt|;
name|int32_t
name|kdc_sec_offset
decl_stmt|;
name|int32_t
name|kdc_usec_offset
decl_stmt|;
name|krb5_config_section
modifier|*
name|cf
decl_stmt|;
name|struct
name|et_list
modifier|*
name|et_list
decl_stmt|;
name|struct
name|krb5_log_facility
modifier|*
name|warn_dest
decl_stmt|;
name|struct
name|krb5_log_facility
modifier|*
name|debug_dest
decl_stmt|;
specifier|const
name|krb5_cc_ops
modifier|*
modifier|*
name|cc_ops
decl_stmt|;
name|int
name|num_cc_ops
decl_stmt|;
specifier|const
name|char
modifier|*
name|http_proxy
decl_stmt|;
specifier|const
name|char
modifier|*
name|time_fmt
decl_stmt|;
name|krb5_boolean
name|log_utc
decl_stmt|;
specifier|const
name|char
modifier|*
name|default_keytab
decl_stmt|;
specifier|const
name|char
modifier|*
name|default_keytab_modify
decl_stmt|;
name|krb5_boolean
name|use_admin_kdc
decl_stmt|;
name|krb5_addresses
modifier|*
name|extra_addresses
decl_stmt|;
name|krb5_boolean
name|scan_interfaces
decl_stmt|;
comment|/* `ifconfig -a' */
name|krb5_boolean
name|srv_lookup
decl_stmt|;
comment|/* do SRV lookups */
name|krb5_boolean
name|srv_try_txt
decl_stmt|;
comment|/* try TXT records also */
name|int32_t
name|fcache_vno
decl_stmt|;
comment|/* create cache files w/ this                                            version */
name|int
name|num_kt_types
decl_stmt|;
comment|/* # of registered keytab types */
name|struct
name|krb5_keytab_data
modifier|*
name|kt_types
decl_stmt|;
comment|/* registered keytab types */
specifier|const
name|char
modifier|*
name|date_fmt
decl_stmt|;
name|char
modifier|*
name|error_string
decl_stmt|;
name|krb5_error_code
name|error_code
decl_stmt|;
name|krb5_addresses
modifier|*
name|ignore_addresses
decl_stmt|;
name|char
modifier|*
name|default_cc_name
decl_stmt|;
name|char
modifier|*
name|default_cc_name_env
decl_stmt|;
name|int
name|default_cc_name_set
decl_stmt|;
name|void
modifier|*
name|mutex
decl_stmt|;
comment|/* protects error_string/error_buf */
name|int
name|large_msg_size
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|KRB5_CTX_F_DNS_CANONICALIZE_HOSTNAME
value|1
define|#
directive|define
name|KRB5_CTX_F_CHECK_PAC
value|2
define|#
directive|define
name|KRB5_CTX_F_HOMEDIR_ACCESS
value|4
define|#
directive|define
name|KRB5_CTX_F_SOCKETS_INITIALIZED
value|8
define|#
directive|define
name|KRB5_CTX_F_RD_REQ_IGNORE
value|16
name|struct
name|send_to_kdc
modifier|*
name|send_to_kdc
decl_stmt|;
ifdef|#
directive|ifdef
name|PKINIT
name|hx509_context
name|hx509ctx
decl_stmt|;
endif|#
directive|endif
block|}
name|krb5_context_data
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_USE_PATH_TOKENS
end_ifndef

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCNAME_FILE
value|"FILE:/tmp/krb5cc_%{uid}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCNAME_FILE
value|"FILE:%{TEMP}/krb5cc_%{uid}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCNAME_API
value|"API:"
end_define

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCNAME_KCM_KCM
value|"KCM:%{uid}"
end_define

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCNAME_KCM_API
value|"API:%{uid}"
end_define

begin_define
define|#
directive|define
name|EXTRACT_TICKET_ALLOW_CNAME_MISMATCH
value|1
end_define

begin_define
define|#
directive|define
name|EXTRACT_TICKET_ALLOW_SERVER_MISMATCH
value|2
end_define

begin_define
define|#
directive|define
name|EXTRACT_TICKET_MATCH_REALM
value|4
end_define

begin_define
define|#
directive|define
name|EXTRACT_TICKET_AS_REQ
value|8
end_define

begin_define
define|#
directive|define
name|EXTRACT_TICKET_TIMESYNC
value|16
end_define

begin_comment
comment|/*  * Configurable options  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_DEFAULT_CCTYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCTYPE
value|(&krb5_acc_ops)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCTYPE
value|(&krb5_fcc_ops)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_ADDRESSLESS_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|KRB5_ADDRESSLESS_DEFAULT
value|TRUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_FORWARDABLE_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|KRB5_FORWARDABLE_DEFAULT
value|TRUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PKINIT
end_ifdef

begin_struct
struct|struct
name|krb5_pk_identity
block|{
name|hx509_verify_ctx
name|verify_ctx
decl_stmt|;
name|hx509_certs
name|certs
decl_stmt|;
name|hx509_cert
name|cert
decl_stmt|;
name|hx509_certs
name|anchors
decl_stmt|;
name|hx509_certs
name|certpool
decl_stmt|;
name|hx509_revoke_ctx
name|revokectx
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|PKINIT_BTMM
value|1
block|}
struct|;
end_struct

begin_enum
enum|enum
name|krb5_pk_type
block|{
name|PKINIT_WIN2K
init|=
literal|1
block|,
name|PKINIT_27
init|=
literal|2
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PKINIT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KRB5_LOCL_H__ */
end_comment

end_unit

