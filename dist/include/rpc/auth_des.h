begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)auth_des.h	2.2 88/07/29 4.0 RPCSRC; from 1.3 88/02/08 SMI */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * auth_des.h, Protocol for DES style authentication for RPC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUTH_DES_
end_ifndef

begin_define
define|#
directive|define
name|_AUTH_DES_
end_define

begin_comment
comment|/*  * There are two kinds of "names": fullnames and nicknames  */
end_comment

begin_enum
enum|enum
name|authdes_namekind
block|{
name|ADN_FULLNAME
block|,
name|ADN_NICKNAME
block|}
enum|;
end_enum

begin_comment
comment|/*  * A fullname contains the network name of the client,   * a conversation key and the window  */
end_comment

begin_struct
struct|struct
name|authdes_fullname
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* network name of client, up to MAXNETNAMELEN */
name|des_block
name|key
decl_stmt|;
comment|/* conversation key */
name|u_long
name|window
decl_stmt|;
comment|/* associated window */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A credential   */
end_comment

begin_struct
struct|struct
name|authdes_cred
block|{
name|enum
name|authdes_namekind
name|adc_namekind
decl_stmt|;
name|struct
name|authdes_fullname
name|adc_fullname
decl_stmt|;
name|u_long
name|adc_nickname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A des authentication verifier   */
end_comment

begin_struct
struct|struct
name|authdes_verf
block|{
union|union
block|{
name|struct
name|timeval
name|adv_ctime
decl_stmt|;
comment|/* clear time */
name|des_block
name|adv_xtime
decl_stmt|;
comment|/* crypt time */
block|}
name|adv_time_u
union|;
name|u_long
name|adv_int_u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * des authentication verifier: client variety  *  * adv_timestamp is the current time.  * adv_winverf is the credential window + 1.  * Both are encrypted using the conversation key.  */
end_comment

begin_define
define|#
directive|define
name|adv_timestamp
value|adv_time_u.adv_ctime
end_define

begin_define
define|#
directive|define
name|adv_xtimestamp
value|adv_time_u.adv_xtime
end_define

begin_define
define|#
directive|define
name|adv_winverf
value|adv_int_u
end_define

begin_comment
comment|/*  * des authentication verifier: server variety  *  * adv_timeverf is the client's timestamp + client's window  * adv_nickname is the server's nickname for the client.  * adv_timeverf is encrypted using the conversation key.  */
end_comment

begin_define
define|#
directive|define
name|adv_timeverf
value|adv_time_u.adv_ctime
end_define

begin_define
define|#
directive|define
name|adv_xtimeverf
value|adv_time_u.adv_xtime
end_define

begin_define
define|#
directive|define
name|adv_nickname
value|adv_int_u
end_define

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|int
name|authdes_getucred
name|__P
argument_list|(
operator|(
expr|struct
name|authdes_cred
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _AUTH_DES_ */
end_comment

end_unit

