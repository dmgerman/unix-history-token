begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992/3 Theo de Raadt<deraadt@fsa.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ypclnt.h,v 1.9 1997/05/28 04:38:25 wpaul Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSVC_YPCLNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPCSVC_YPCLNT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|YPERR_BADARGS
value|1
end_define

begin_comment
comment|/* args to function are bad */
end_comment

begin_define
define|#
directive|define
name|YPERR_RPC
value|2
end_define

begin_comment
comment|/* RPC failure */
end_comment

begin_define
define|#
directive|define
name|YPERR_DOMAIN
value|3
end_define

begin_comment
comment|/* can't bind to a server for domain */
end_comment

begin_define
define|#
directive|define
name|YPERR_MAP
value|4
end_define

begin_comment
comment|/* no such map in server's domain */
end_comment

begin_define
define|#
directive|define
name|YPERR_KEY
value|5
end_define

begin_comment
comment|/* no such key in map */
end_comment

begin_define
define|#
directive|define
name|YPERR_YPERR
value|6
end_define

begin_comment
comment|/* some internal YP server or client error */
end_comment

begin_define
define|#
directive|define
name|YPERR_RESRC
value|7
end_define

begin_comment
comment|/* local resource allocation failure */
end_comment

begin_define
define|#
directive|define
name|YPERR_NOMORE
value|8
end_define

begin_comment
comment|/* no more records in map database */
end_comment

begin_define
define|#
directive|define
name|YPERR_PMAP
value|9
end_define

begin_comment
comment|/* can't communicate with portmapper */
end_comment

begin_define
define|#
directive|define
name|YPERR_YPBIND
value|10
end_define

begin_comment
comment|/* can't communicate with ypbind */
end_comment

begin_define
define|#
directive|define
name|YPERR_YPSERV
value|11
end_define

begin_comment
comment|/* can't communicate with ypserv */
end_comment

begin_define
define|#
directive|define
name|YPERR_NODOM
value|12
end_define

begin_comment
comment|/* local domain name not set */
end_comment

begin_define
define|#
directive|define
name|YPERR_BADDB
value|13
end_define

begin_comment
comment|/* YP data base is bad */
end_comment

begin_define
define|#
directive|define
name|YPERR_VERS
value|14
end_define

begin_comment
comment|/* YP version mismatch */
end_comment

begin_define
define|#
directive|define
name|YPERR_ACCESS
value|15
end_define

begin_comment
comment|/* access violation */
end_comment

begin_define
define|#
directive|define
name|YPERR_BUSY
value|16
end_define

begin_comment
comment|/* database is busy */
end_comment

begin_comment
comment|/*  * Types of update operations  */
end_comment

begin_define
define|#
directive|define
name|YPOP_CHANGE
value|1
end_define

begin_comment
comment|/* change, do not add */
end_comment

begin_define
define|#
directive|define
name|YPOP_INSERT
value|2
end_define

begin_comment
comment|/* add, do not change */
end_comment

begin_define
define|#
directive|define
name|YPOP_DELETE
value|3
end_define

begin_comment
comment|/* delete this entry */
end_comment

begin_define
define|#
directive|define
name|YPOP_STORE
value|4
end_define

begin_comment
comment|/* add, or change */
end_comment

begin_struct
struct|struct
name|ypall_callback
block|{
comment|/* return non-0 to stop getting called */
name|int
argument_list|(
argument|*foreach
argument_list|)
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
comment|/* opaque pointer for use of callback fn */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|dom_binding
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|yp_bind
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_yp_dobind
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dom
operator|,
expr|struct
name|dom_binding
operator|*
operator|*
name|ypdb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|yp_unbind
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_get_default_domain
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|domp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_match
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
specifier|const
name|char
operator|*
name|inkey
operator|,
name|int
name|inkeylen
operator|,
name|char
operator|*
operator|*
name|outval
operator|,
name|int
operator|*
name|outvallen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_first
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
name|char
operator|*
operator|*
name|outkey
operator|,
name|int
operator|*
name|outkeylen
operator|,
name|char
operator|*
operator|*
name|outval
operator|,
name|int
operator|*
name|outvallen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_next
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
name|char
operator|*
name|inkey
operator|,
name|int
name|inkeylen
operator|,
name|char
operator|*
operator|*
name|outkey
operator|,
name|int
operator|*
name|outkeylen
operator|,
name|char
operator|*
operator|*
name|outval
operator|,
name|int
operator|*
name|outvallen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_master
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
name|char
operator|*
operator|*
name|outname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_order
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
name|int
operator|*
name|outorder
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yp_all
name|__P
argument_list|(
operator|(
name|char
operator|*
name|indomain
operator|,
name|char
operator|*
name|inmap
operator|,
expr|struct
name|ypall_callback
operator|*
name|incallback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|yperr_string
name|__P
argument_list|(
operator|(
name|int
name|incode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ypbinderr_string
name|__P
argument_list|(
operator|(
name|int
name|incode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ypprot_err
name|__P
argument_list|(
operator|(
name|unsigned
name|int
name|incode
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
comment|/* _RPCSVC_YPCLNT_H_ */
end_comment

end_unit

