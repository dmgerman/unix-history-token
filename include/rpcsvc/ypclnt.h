begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992/3 Theo de Raadt<deraadt@fsa.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
function_decl|(
modifier|*
name|foreach
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
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

begin_function_decl
name|__BEGIN_DECLS
name|int
name|yp_bind
parameter_list|(
name|char
modifier|*
name|dom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_yp_dobind
parameter_list|(
name|char
modifier|*
name|dom
parameter_list|,
name|struct
name|dom_binding
modifier|*
modifier|*
name|ypdb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yp_unbind
parameter_list|(
name|char
modifier|*
name|dom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_get_default_domain
parameter_list|(
name|char
modifier|*
modifier|*
name|domp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_match
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
specifier|const
name|char
modifier|*
name|inkey
parameter_list|,
name|int
name|inkeylen
parameter_list|,
name|char
modifier|*
modifier|*
name|outval
parameter_list|,
name|int
modifier|*
name|outvallen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_first
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
name|char
modifier|*
modifier|*
name|outkey
parameter_list|,
name|int
modifier|*
name|outkeylen
parameter_list|,
name|char
modifier|*
modifier|*
name|outval
parameter_list|,
name|int
modifier|*
name|outvallen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_next
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
name|char
modifier|*
name|inkey
parameter_list|,
name|int
name|inkeylen
parameter_list|,
name|char
modifier|*
modifier|*
name|outkey
parameter_list|,
name|int
modifier|*
name|outkeylen
parameter_list|,
name|char
modifier|*
modifier|*
name|outval
parameter_list|,
name|int
modifier|*
name|outvallen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_master
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
name|char
modifier|*
modifier|*
name|outname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_order
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
name|int
modifier|*
name|outorder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_all
parameter_list|(
name|char
modifier|*
name|indomain
parameter_list|,
name|char
modifier|*
name|inmap
parameter_list|,
name|struct
name|ypall_callback
modifier|*
name|incallback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|yperr_string
parameter_list|(
name|int
name|incode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ypbinderr_string
parameter_list|(
name|int
name|incode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ypprot_err
parameter_list|(
name|unsigned
name|int
name|incode
parameter_list|)
function_decl|;
end_function_decl

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

