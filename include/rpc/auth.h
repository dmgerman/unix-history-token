begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)auth.h 1.17 88/02/08 SMI  *	from: @(#)auth.h	2.3 88/08/07 4.0 RPCSRC  * $FreeBSD$  */
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
block|}
enum|;
end_enum

begin_union
union|union
name|des_block
block|{
struct|struct
block|{
name|u_int32_t
name|high
decl_stmt|;
name|u_int32_t
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

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_des_block
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|__BEGIN_DECLS
name|bool_t
name|xdr_opaque_auth
name|__P
argument_list|(
operator|(
name|XDR
operator|*
name|xdrs
operator|,
expr|struct
name|opaque_auth
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Auth handle, interface to client side authenticators.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rpc_auth
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
argument_list|(
argument|*ah_nextverf
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_auth
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* nextverf& serialize */
name|int
argument_list|(
argument|*ah_marshal
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_auth
operator|*
operator|,
name|XDR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* validate verifier */
name|int
argument_list|(
argument|*ah_validate
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_auth
operator|*
operator|,
expr|struct
name|opaque_auth
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* refresh credentials */
name|int
argument_list|(
argument|*ah_refresh
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_auth
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* destroy this structure */
name|void
argument_list|(
argument|*ah_destroy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_auth
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|ah_ops
struct|;
name|caddr_t
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
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_refresh))(auth))
end_define

begin_define
define|#
directive|define
name|auth_refresh
parameter_list|(
name|auth
parameter_list|)
define|\
value|((*((auth)->ah_ops->ah_refresh))(auth))
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

begin_decl_stmt
specifier|extern
name|struct
name|opaque_auth
name|_null_auth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These are the various implementations of client side authenticators.  */
end_comment

begin_comment
comment|/*  * Unix style authentication  * AUTH *authunix_create(machname, uid, gid, len, aup_gids)  *	char *machname;  *	int uid;  *	int gid;  *	int len;  *	int *aup_gids;  */
end_comment

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|AUTH
modifier|*
name|authunix_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|AUTH
modifier|*
name|authunix_create_default
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|AUTH
modifier|*
name|authnone_create
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/* Forward compatibility with TI-RPC */
define|#
directive|define
name|authsys_create
value|authunix_create
define|#
directive|define
name|authsys_create_default
value|authunix_create_default
comment|/*  * DES style authentication  * AUTH *authdes_create(servername, window, timehost, ckey)  * 	char *servername;		- network name of server  *	u_int window;			- time to live  * 	struct sockaddr *timehost;	- optional hostname to sync with  * 	des_block *ckey;		- optional conversation key to use  */
name|__BEGIN_DECLS
specifier|extern
name|AUTH
modifier|*
name|authdes_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NOTYET
end_ifdef

begin_comment
comment|/*  * TI-RPC supports this call, but it requires the inclusion of  * NIS+-specific headers which would require the inclusion of other  * headers which would result in a tangled mess. For now, the NIS+  * code prototypes this routine internally.  */
end_comment

begin_decl_stmt
specifier|extern
name|AUTH
modifier|*
name|authdes_pk_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|netobj
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|des_block
operator|*
operator|,
name|nis_server
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__END_DECLS
comment|/*  * Netname manipulation routines.  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|netname2user
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|uid_t
operator|*
operator|,
name|gid_t
operator|*
operator|,
name|int
operator|*
operator|,
name|gid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netname2host
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
specifier|extern
name|int
name|getnetname
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
specifier|extern
name|int
name|user2netname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|uid_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|host2netname
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
specifier|extern
name|void
name|passwd2des
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

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Keyserv interface routines.  * XXX Should not be here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEXKEYBYTES
end_ifndef

begin_define
define|#
directive|define
name|HEXKEYBYTES
value|48
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|kbuf
index|[
name|HEXKEYBYTES
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|namestr
typedef|;
end_typedef

begin_struct
struct|struct
name|netstarg
block|{
name|kbuf
name|st_priv_key
decl_stmt|;
name|kbuf
name|st_pub_key
decl_stmt|;
name|namestr
name|st_netname
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|int
name|key_decryptsession
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_decryptsession_pk
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|netobj
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_encryptsession
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_encryptsession_pk
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|netobj
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_gendes
name|__P
argument_list|(
operator|(
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_setsecret
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
specifier|extern
name|int
name|key_secretkey_is_set
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_setnet
name|__P
argument_list|(
operator|(
expr|struct
name|netstarg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_get_conv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|des_block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Publickey routines.  */
name|__BEGIN_DECLS
specifier|extern
name|int
name|getpublickey
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
specifier|extern
name|int
name|getpublicandprivatekey
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
specifier|extern
name|int
name|getsecretkey
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
name|AUTH_UNIX
value|1
end_define

begin_comment
comment|/* unix style (uid, gids) */
end_comment

begin_define
define|#
directive|define
name|AUTH_SYS
value|1
end_define

begin_comment
comment|/* forward compatibility */
end_comment

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
name|AUTH_DES
value|3
end_define

begin_comment
comment|/* des style (encrypted timestamps) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_AUTH_H */
end_comment

end_unit

