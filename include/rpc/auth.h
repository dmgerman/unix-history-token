begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: auth.h,v 1.15 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)auth.h 1.17 88/02/08 SMI  *	from: @(#)auth.h	2.3 88/08/07 4.0 RPCSRC  *	from: @(#)auth.h	1.43 	98/02/02 SMI  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * auth.h, Authentication interface.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  *  * The data structures are completely opaque to the client.  The client  * is required to pass a AUTH * to routines that create rpc  * "sessions".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_AUTH_H
end_define

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<rpc/clnt_stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_define
define|#
directive|define
name|MAX_AUTH_BYTES
value|400
end_define

begin_define
define|#
directive|define
name|MAXNETNAMELEN
value|255
end_define

begin_comment
comment|/* maximum length of network user's name */
end_comment

begin_comment
comment|/*  *  Client side authentication/security data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sec_data
block|{
name|u_int
name|secmod
decl_stmt|;
comment|/* security mode number e.g. in nfssec.conf */
name|u_int
name|rpcflavor
decl_stmt|;
comment|/* rpc flavors:AUTH_UNIX,AUTH_DES,RPCSEC_GSS */
name|int
name|flags
decl_stmt|;
comment|/* AUTH_F_xxx flags */
name|caddr_t
name|data
decl_stmt|;
comment|/* opaque data per flavor */
block|}
name|sec_data_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SYSCALL32_IMPL
end_ifdef

begin_struct
struct|struct
name|sec_data32
block|{
name|uint32_t
name|secmod
decl_stmt|;
comment|/* security mode number e.g. in nfssec.conf */
name|uint32_t
name|rpcflavor
decl_stmt|;
comment|/* rpc flavors:AUTH_UNIX,AUTH_DES,RPCSEC_GSS */
name|int32_t
name|flags
decl_stmt|;
comment|/* AUTH_F_xxx flags */
name|caddr32_t
name|data
decl_stmt|;
comment|/* opaque data per flavor */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSCALL32_IMPL */
end_comment

begin_comment
comment|/*  * AUTH_DES flavor specific data from sec_data opaque data field.  * AUTH_KERB has the same structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|des_clnt_data
block|{
name|struct
name|netbuf
name|syncaddr
decl_stmt|;
comment|/* time sync addr */
name|struct
name|knetconfig
modifier|*
name|knconf
decl_stmt|;
comment|/* knetconfig info that associated */
comment|/* with the syncaddr. */
name|char
modifier|*
name|netname
decl_stmt|;
comment|/* server's netname */
name|int
name|netnamelen
decl_stmt|;
comment|/* server's netname len */
block|}
name|dh_k4_clntdata_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SYSCALL32_IMPL
end_ifdef

begin_struct
struct|struct
name|des_clnt_data32
block|{
name|struct
name|netbuf32
name|syncaddr
decl_stmt|;
comment|/* time sync addr */
name|caddr32_t
name|knconf
decl_stmt|;
comment|/* knetconfig info that associated */
comment|/* with the syncaddr. */
name|caddr32_t
name|netname
decl_stmt|;
comment|/* server's netname */
name|int32_t
name|netnamelen
decl_stmt|;
comment|/* server's netname len */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSCALL32_IMPL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERBEROS
end_ifdef

begin_comment
comment|/*  * flavor specific data to hold the data for AUTH_DES/AUTH_KERB(v4)  * in sec_data->data opaque field.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|krb4_svc_data
block|{
name|int
name|window
decl_stmt|;
comment|/* window option value */
block|}
name|krb4_svcdata_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb4_svc_data
name|des_svcdata_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERBEROS */
end_comment

begin_comment
comment|/*  * authentication/security specific flags  */
end_comment

begin_define
define|#
directive|define
name|AUTH_F_RPCTIMESYNC
value|0x001
end_define

begin_comment
comment|/* use RPC to do time sync */
end_comment

begin_define
define|#
directive|define
name|AUTH_F_TRYNONE
value|0x002
end_define

begin_comment
comment|/* allow fall back to AUTH_NONE */
end_comment

begin_comment
comment|/*  * Status returned from authentication check  */
end_comment

begin_enum
enum|enum
name|auth_stat
block|{
name|AUTH_OK
init|=
literal|0
block|,
comment|/* 	 * failed at remote end 	 */
name|AUTH_BADCRED
init|=
literal|1
block|,
comment|/* bogus credentials (seal broken) */
name|AUTH_REJECTEDCRED
init|=
literal|2
block|,
comment|/* client should begin new session */
name|AUTH_BADVERF
init|=
literal|3
block|,
comment|/* bogus verifier (seal broken) */
name|AUTH_REJECTEDVERF
init|=
literal|4
block|,
comment|/* verifier expired or was replayed */
name|AUTH_TOOWEAK
init|=
literal|5
block|,
comment|/* rejected due to security reasons */
comment|/* 	 * failed locally 	*/
name|AUTH_INVALIDRESP
init|=
literal|6
block|,
comment|/* bogus response verifier */
name|AUTH_FAILED
init|=
literal|7
comment|/* some unknown reason */
ifdef|#
directive|ifdef
name|KERBEROS
comment|/* 	 * kerberos errors 	 */
block|,
name|AUTH_KERB_GENERIC
init|=
literal|8
block|,
comment|/* kerberos generic error */
name|AUTH_TIMEEXPIRE
init|=
literal|9
block|,
comment|/* time of credential expired */
name|AUTH_TKT_FILE
init|=
literal|10
block|,
comment|/* something wrong with ticket file */
name|AUTH_DECODE
init|=
literal|11
block|,
comment|/* can't decode authenticator */
name|AUTH_NET_ADDR
init|=
literal|12
comment|/* wrong net address in ticket */
endif|#
directive|endif
comment|/* KERBEROS */
block|}
enum|;
end_enum

begin_union
union|union
name|des_block
block|{
struct|struct
block|{
name|uint32_t
name|high
decl_stmt|;
name|uint32_t
name|low
decl_stmt|;
block|}
name|key
struct|;
name|char
name|c
index|[
literal|8
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|des_block
name|des_block
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_des_block
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Authentication info.  Opaque to client.  */
end_comment

begin_struct
struct|struct
name|opaque_auth
block|{
name|enum_t
name|oa_flavor
decl_stmt|;
comment|/* flavor of auth */
name|caddr_t
name|oa_base
decl_stmt|;
comment|/* address of more auth stuff */
name|u_int
name|oa_length
decl_stmt|;
comment|/* not to exceed MAX_AUTH_BYTES */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Auth handle, interface to client side authenticators.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__auth
block|{
name|struct
name|opaque_auth
name|ah_cred
decl_stmt|;
name|struct
name|opaque_auth
name|ah_verf
decl_stmt|;
name|union
name|des_block
name|ah_key
decl_stmt|;
struct|struct
name|auth_ops
block|{
name|void
function_decl|(
modifier|*
name|ah_nextverf
function_decl|)
parameter_list|(
name|struct
name|__auth
modifier|*
parameter_list|)
function_decl|;
comment|/* nextverf& serialize */
name|int
function_decl|(
modifier|*
name|ah_marshal
function_decl|)
parameter_list|(
name|struct
name|__auth
modifier|*
parameter_list|,
name|XDR
modifier|*
parameter_list|)
function_decl|;
comment|/* validate verifier */
name|int
function_decl|(
modifier|*
name|ah_validate
function_decl|)
parameter_list|(
name|struct
name|__auth
modifier|*
parameter_list|,
name|struct
name|opaque_auth
modifier|*
parameter_list|)
function_decl|;
comment|/* refresh credentials */
name|int
function_decl|(
modifier|*
name|ah_refresh
function_decl|)
parameter_list|(
name|struct
name|__auth
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* destroy this structure */
name|void
function_decl|(
modifier|*
name|ah_destroy
function_decl|)
parameter_list|(
name|struct
name|__auth
modifier|*
parameter_list|)
function_decl|;
block|}
modifier|*
name|ah_ops
struct|;
name|void
modifier|*
name|ah_private
decl_stmt|;
block|}
name|AUTH
typedef|;
end_typedef

begin_comment
comment|/*  * Authentication ops.  * The ops and the auth handle provide the interface to the authenticators.  *  * AUTH	*auth;  * XDR	*xdrs;  * struct opaque_auth verf;  */
end_comment

begin_define
define|#
directive|define
name|AUTH_NEXTVERF
parameter_list|(
name|auth
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_nextverf))(auth))
end_define

begin_define
define|#
directive|define
name|auth_nextverf
parameter_list|(
name|auth
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_nextverf))(auth))
end_define

begin_define
define|#
directive|define
name|AUTH_MARSHALL
parameter_list|(
name|auth
parameter_list|,
name|xdrs
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_marshal))(auth, xdrs))
end_define

begin_define
define|#
directive|define
name|auth_marshall
parameter_list|(
name|auth
parameter_list|,
name|xdrs
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_marshal))(auth, xdrs))
end_define

begin_define
define|#
directive|define
name|AUTH_VALIDATE
parameter_list|(
name|auth
parameter_list|,
name|verfp
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_validate))((auth), verfp))
end_define

begin_define
define|#
directive|define
name|auth_validate
parameter_list|(
name|auth
parameter_list|,
name|verfp
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_validate))((auth), verfp))
end_define

begin_define
define|#
directive|define
name|AUTH_REFRESH
parameter_list|(
name|auth
parameter_list|,
name|msg
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_refresh))(auth, msg))
end_define

begin_define
define|#
directive|define
name|auth_refresh
parameter_list|(
name|auth
parameter_list|,
name|msg
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_refresh))(auth, msg))
end_define

begin_define
define|#
directive|define
name|AUTH_DESTROY
parameter_list|(
name|auth
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_destroy))(auth))
end_define

begin_define
define|#
directive|define
name|auth_destroy
parameter_list|(
name|auth
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_destroy))(auth))
end_define

begin_expr_stmt
name|__BEGIN_DECLS
specifier|extern
expr|struct
name|opaque_auth
name|_null_auth
expr_stmt|;
end_expr_stmt

begin_function_decl
name|__END_DECLS
comment|/*  * These are the various implementations of client side authenticators.  */
comment|/*  * System style authentication  * AUTH *authunix_create(machname, uid, gid, len, aup_gids)  *	char *machname;  *	int uid;  *	int gid;  *	int len;  *	int *aup_gids;  */
name|__BEGIN_DECLS
specifier|extern
name|AUTH
modifier|*
name|authunix_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|AUTH
modifier|*
name|authunix_create_default
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* takes no parameters */
end_comment

begin_function_decl
specifier|extern
name|AUTH
modifier|*
name|authnone_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* takes no parameters */
end_comment

begin_function_decl
name|__END_DECLS
comment|/*  * DES style authentication  * AUTH *authsecdes_create(servername, window, timehost, ckey)  * 	char *servername;		- network name of server  *	u_int window;			- time to live  * 	const char *timehost;			- optional hostname to sync with  * 	des_block *ckey;		- optional conversation key to use  */
name|__BEGIN_DECLS
specifier|extern
name|AUTH
modifier|*
name|authdes_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|AUTH
modifier|*
name|authdes_seccreate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_opaque_auth
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|opaque_auth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
define|#
directive|define
name|authsys_create
parameter_list|(
name|c
parameter_list|,
name|i1
parameter_list|,
name|i2
parameter_list|,
name|i3
parameter_list|,
name|ip
parameter_list|)
value|authunix_create((c),(i1),(i2),(i3),(ip))
define|#
directive|define
name|authsys_create_default
parameter_list|()
value|authunix_create_default()
comment|/*  * Netname manipulation routines.  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|getnetname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|host2netname
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|user2netname
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|uid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|netname2user
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|netname2host
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|passwd2des
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  *  * These routines interface to the keyserv daemon  *  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|key_decryptsession
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_encryptsession
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_gendes
parameter_list|(
name|des_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_setsecret
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_secretkey_is_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Publickey routines.  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|getpublickey
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getpublicandprivatekey
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getsecretkey
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
ifdef|#
directive|ifdef
name|KERBEROS
comment|/*  * Kerberos style authentication  * AUTH *authkerb_seccreate(service, srv_inst, realm, window, timehost, status)  *	const char *service;			- service name  *	const char *srv_inst;			- server instance  *	const char *realm;			- server realm  *	const u_int window;			- time to live  *	const char *timehost;			- optional hostname to sync with  *	int *status;				- kerberos status returned  */
name|__BEGIN_DECLS
specifier|extern
name|AUTH
modifier|*
name|authkerb_seccreate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Map a kerberos credential into a unix cred.  *  *	authkerb_getucred(rqst, uid, gid, grouplen, groups)  *	const struct svc_req *rqst;		- request pointer  *	uid_t *uid;  *	gid_t *gid;  *	short *grouplen;  *	int *groups;  *  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|authkerb_getucred
parameter_list|(
comment|/* struct svc_req *, uid_t *, gid_t *, 		    short *, int * */
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__END_DECLS
endif|#
directive|endif
comment|/* KERBEROS */
name|__BEGIN_DECLS
expr|struct
name|svc_req
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|rpc_msg
struct_decl|;
end_struct_decl

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_null
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_short
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_unix
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|AUTH_NONE
value|0
end_define

begin_comment
comment|/* no authentication */
end_comment

begin_define
define|#
directive|define
name|AUTH_NULL
value|0
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_define
define|#
directive|define
name|AUTH_SYS
value|1
end_define

begin_comment
comment|/* unix style (uid, gids) */
end_comment

begin_define
define|#
directive|define
name|AUTH_UNIX
value|AUTH_SYS
end_define

begin_define
define|#
directive|define
name|AUTH_SHORT
value|2
end_define

begin_comment
comment|/* short hand unix style */
end_comment

begin_define
define|#
directive|define
name|AUTH_DH
value|3
end_define

begin_comment
comment|/* for Diffie-Hellman mechanism */
end_comment

begin_define
define|#
directive|define
name|AUTH_DES
value|AUTH_DH
end_define

begin_comment
comment|/* for backward compatibility */
end_comment

begin_define
define|#
directive|define
name|AUTH_KERB
value|4
end_define

begin_comment
comment|/* kerberos style */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_AUTH_H */
end_comment

end_unit

