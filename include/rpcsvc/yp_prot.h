begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992/3 Theo de Raadt<deraadt@fsa.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSVC_YP_PROT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPCSVC_YP_PROT_H_
end_define

begin_comment
comment|/*  * YPSERV PROTOCOL:  *  * ypserv supports the following procedures:  *  * YPPROC_NULL		takes (void), returns (void).  * 			called to check if server is alive.  * YPPROC_DOMAIN	takes (char *), returns (bool_t).  * 			true if ypserv serves the named domain.  * YPPROC_DOMAIN_NOACK	takes (char *), returns (bool_t).  * 			true if ypserv serves the named domain.  *			used for broadcasts, does not ack if ypserv  *			doesn't handle named domain.  * YPPROC_MATCH		takes (struct ypreq_key), returns (struct ypresp_val)  * 			does a lookup.  * YPPROC_FIRST		takes (struct ypreq_nokey) returns (ypresp_key_val).  * 			gets the first key/datum from the map.  * YPPROC_NEXT		takes (struct ypreq_key) returns (ypresp_key_val).  * 			gets the next key/datum from the map.  * YPPROC_XFR		takes (struct ypreq_xfr), returns (void).  * 			tells ypserv to check if there is a new version of  *			the map.  * YPPROC_CLEAR		takes (void), returns (void).  * 			tells ypserv to flush it's file cache, so that  *			newly transferred files will get read.  * YPPROC_ALL		takes (struct ypreq_nokey), returns (bool_t and  *			struct ypresp_key_val).  * 			returns an array of data, with the bool_t being  * 			false on the last datum. read the source, it's  *			convoluted.  * YPPROC_MASTER	takes (struct ypreq_nokey), returns (ypresp_master).  * YPPROC_ORDER		takes (struct ypreq_nokey), returns (ypresp_order).  * YPPROC_MAPLIST	takes (char *), returns (struct ypmaplist *).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BOOL_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|u_int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BOOL_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Program and version symbols, magic numbers */
end_comment

begin_define
define|#
directive|define
name|YPPROG
value|((u_long)100004)
end_define

begin_define
define|#
directive|define
name|YPVERS
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|YPVERS_ORIG
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|YPMAXRECORD
value|((u_long)1024)
end_define

begin_define
define|#
directive|define
name|YPMAXDOMAIN
value|((u_long)64)
end_define

begin_define
define|#
directive|define
name|YPMAXMAP
value|((u_long)64)
end_define

begin_define
define|#
directive|define
name|YPMAXPEER
value|((u_long)256)
end_define

begin_comment
comment|/*  * I don't know if anything of sun's depends on this, or if they  * simply defined it so that their own code wouldn't try to send  * packets over the ethernet MTU. This YP code doesn't use it.  */
end_comment

begin_define
define|#
directive|define
name|YPMSGSZ
value|1600
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DATUM
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DATUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ypmap_parms
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|char
modifier|*
name|map
decl_stmt|;
name|u_long
name|ordernum
decl_stmt|;
name|char
modifier|*
name|owner
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypreq_key
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|char
modifier|*
name|map
decl_stmt|;
name|datum
name|keydat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypreq_nokey
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|char
modifier|*
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypreq_xfr
block|{
name|struct
name|ypmap_parms
name|map_parms
decl_stmt|;
name|u_long
name|transid
decl_stmt|;
name|u_long
name|proto
decl_stmt|;
name|u_short
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ypxfr_domain
value|map_parms.domain
end_define

begin_define
define|#
directive|define
name|ypxfr_map
value|map_parms.map
end_define

begin_define
define|#
directive|define
name|ypxfr_ordernum
value|map_parms.ordernum
end_define

begin_define
define|#
directive|define
name|ypxfr_owner
value|map_parms.owner
end_define

begin_struct
struct|struct
name|ypresp_val
block|{
name|u_long
name|status
decl_stmt|;
name|datum
name|valdat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypresp_key_val
block|{
name|u_long
name|status
decl_stmt|;
name|datum
name|keydat
decl_stmt|;
name|datum
name|valdat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypresp_master
block|{
name|u_long
name|status
decl_stmt|;
name|char
modifier|*
name|master
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypresp_order
block|{
name|u_long
name|status
decl_stmt|;
name|u_long
name|ordernum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypmaplist
block|{
name|char
name|ypml_name
index|[
name|YPMAXMAP
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|ypmaplist
modifier|*
name|ypml_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypresp_maplist
block|{
name|u_long
name|status
decl_stmt|;
name|struct
name|ypmaplist
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ypserv procedure numbers */
end_comment

begin_define
define|#
directive|define
name|YPPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|YPPROC_DOMAIN
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|YPPROC_DOMAIN_NONACK
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|YPPROC_MATCH
value|((u_long)3)
end_define

begin_define
define|#
directive|define
name|YPPROC_FIRST
value|((u_long)4)
end_define

begin_define
define|#
directive|define
name|YPPROC_NEXT
value|((u_long)5)
end_define

begin_define
define|#
directive|define
name|YPPROC_XFR
value|((u_long)6)
end_define

begin_define
define|#
directive|define
name|YPPROC_CLEAR
value|((u_long)7)
end_define

begin_define
define|#
directive|define
name|YPPROC_ALL
value|((u_long)8)
end_define

begin_define
define|#
directive|define
name|YPPROC_MASTER
value|((u_long)9)
end_define

begin_define
define|#
directive|define
name|YPPROC_ORDER
value|((u_long)10)
end_define

begin_define
define|#
directive|define
name|YPPROC_MAPLIST
value|((u_long)11)
end_define

begin_comment
comment|/* ypserv procedure return status values */
end_comment

begin_define
define|#
directive|define
name|YP_TRUE
value|((long)1)
end_define

begin_comment
comment|/* general purpose success code */
end_comment

begin_define
define|#
directive|define
name|YP_NOMORE
value|((long)2)
end_define

begin_comment
comment|/* no more entries in map */
end_comment

begin_define
define|#
directive|define
name|YP_FALSE
value|((long)0)
end_define

begin_comment
comment|/* general purpose failure code */
end_comment

begin_define
define|#
directive|define
name|YP_NOMAP
value|((long)-1)
end_define

begin_comment
comment|/* no such map in domain */
end_comment

begin_define
define|#
directive|define
name|YP_NODOM
value|((long)-2)
end_define

begin_comment
comment|/* domain not supported */
end_comment

begin_define
define|#
directive|define
name|YP_NOKEY
value|((long)-3)
end_define

begin_comment
comment|/* no such key in map */
end_comment

begin_define
define|#
directive|define
name|YP_BADOP
value|((long)-4)
end_define

begin_comment
comment|/* invalid operation */
end_comment

begin_define
define|#
directive|define
name|YP_BADDB
value|((long)-5)
end_define

begin_comment
comment|/* server data base is bad */
end_comment

begin_define
define|#
directive|define
name|YP_YPERR
value|((long)-6)
end_define

begin_comment
comment|/* YP server error */
end_comment

begin_define
define|#
directive|define
name|YP_BADARGS
value|((long)-7)
end_define

begin_comment
comment|/* request arguments bad */
end_comment

begin_define
define|#
directive|define
name|YP_VERS
value|((long)-8)
end_define

begin_comment
comment|/* YP server version mismatch */
end_comment

begin_comment
comment|/*  * Sun's header file says:  * "Domain binding data structure, used by ypclnt package and ypserv modules.  * Users of the ypclnt package (or of this protocol) don't HAVE to know about  * it, but it must be available to users because _yp_dobind is a public  * interface."  *  * This is totally bogus! Nowhere else does Sun state that _yp_dobind() is  * a public interface, and I don't know any reason anyone would want to call  * it. But, just in case anyone does actually expect it to be available..  * we provide this.. exactly as Sun wants it.  */
end_comment

begin_struct
struct|struct
name|dom_binding
block|{
name|struct
name|dom_binding
modifier|*
name|dom_pnext
decl_stmt|;
name|char
name|dom_domain
index|[
name|YPMAXDOMAIN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|sockaddr_in
name|dom_server_addr
decl_stmt|;
name|u_short
name|dom_server_port
decl_stmt|;
name|int
name|dom_socket
decl_stmt|;
name|CLIENT
modifier|*
name|dom_client
decl_stmt|;
name|u_short
name|dom_local_port
decl_stmt|;
name|long
name|dom_vers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * YPBIND PROTOCOL:  *  * ypbind supports the following procedures:  *  * YPBINDPROC_NULL	takes (void), returns (void).  *			to check if ypbind is running.  * YPBINDPROC_DOMAIN	takes (char *), returns (struct ypbind_resp).  *			requests that ypbind start to serve the  *			named domain (if it doesn't already)  * YPBINDPROC_SETDOM	takes (struct ypbind_setdom), returns (void).  *			used by ypset.  */
end_comment

begin_define
define|#
directive|define
name|YPBINDPROG
value|((u_long)100007)
end_define

begin_define
define|#
directive|define
name|YPBINDVERS
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|YPBINDVERS_ORIG
value|((u_long)1)
end_define

begin_comment
comment|/* ypbind procedure numbers */
end_comment

begin_define
define|#
directive|define
name|YPBINDPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|YPBINDPROC_DOMAIN
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|YPBINDPROC_SETDOM
value|((u_long)2)
end_define

begin_comment
comment|/* error code in ypbind_resp.ypbind_status */
end_comment

begin_enum
enum|enum
name|ypbind_resptype
block|{
name|YPBIND_SUCC_VAL
init|=
literal|1
block|,
name|YPBIND_FAIL_VAL
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* network order, of course */
end_comment

begin_struct
struct|struct
name|ypbind_binding
block|{
name|struct
name|in_addr
name|ypbind_binding_addr
decl_stmt|;
name|u_short
name|ypbind_binding_port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ypbind_resp
block|{
name|enum
name|ypbind_resptype
name|ypbind_status
decl_stmt|;
union|union
block|{
name|u_long
name|ypbind_error
decl_stmt|;
name|struct
name|ypbind_binding
name|ypbind_bindinfo
decl_stmt|;
block|}
name|ypbind_respbody
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* error code in ypbind_resp.ypbind_respbody.ypbind_error */
end_comment

begin_define
define|#
directive|define
name|YPBIND_ERR_ERR
value|1
end_define

begin_comment
comment|/* internal error */
end_comment

begin_define
define|#
directive|define
name|YPBIND_ERR_NOSERV
value|2
end_define

begin_comment
comment|/* no bound server for passed domain */
end_comment

begin_define
define|#
directive|define
name|YPBIND_ERR_RESC
value|3
end_define

begin_comment
comment|/* system resource allocation failure */
end_comment

begin_comment
comment|/*  * Request data structure for ypbind "Set domain" procedure.  */
end_comment

begin_struct
struct|struct
name|ypbind_setdom
block|{
name|char
name|ypsetdom_domain
index|[
name|YPMAXDOMAIN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|ypbind_binding
name|ypsetdom_binding
decl_stmt|;
name|u_short
name|ypsetdom_vers
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ypsetdom_addr
value|ypsetdom_binding.ypbind_binding_addr
end_define

begin_define
define|#
directive|define
name|ypsetdom_port
value|ypsetdom_binding.ypbind_binding_port
end_define

begin_comment
comment|/*  * YPPUSH PROTOCOL:  *  * Sun says:  * "Protocol between clients (ypxfr, only) and yppush  *  yppush speaks a protocol in the transient range, which  *  is supplied to ypxfr as a command-line parameter when it  *  is activated by ypserv."  *  * This protocol is not implemented, naturally, because this YP  * implementation only does the client side.  */
end_comment

begin_define
define|#
directive|define
name|YPPUSHVERS
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|YPPUSHVERS_ORIG
value|((u_long)1)
end_define

begin_comment
comment|/* yppush procedure numbers */
end_comment

begin_define
define|#
directive|define
name|YPPUSHPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|YPPUSHPROC_XFRRESP
value|((u_long)1)
end_define

begin_struct
struct|struct
name|yppushresp_xfr
block|{
name|u_long
name|transid
decl_stmt|;
name|u_long
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* yppush status value in yppushresp_xfr.status */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_SUCC
value|((long)1)
end_define

begin_comment
comment|/* Success */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_AGE
value|((long)2)
end_define

begin_comment
comment|/* Master's version not newer */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_NOMAP
value|((long)-1)
end_define

begin_comment
comment|/* Can't find server for map */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_NODOM
value|((long)-2)
end_define

begin_comment
comment|/* Domain not supported */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_RSRC
value|((long)-3)
end_define

begin_comment
comment|/* Local resource alloc failure */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_RPC
value|((long)-4)
end_define

begin_comment
comment|/* RPC failure talking to server */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_MADDR
value|((long)-5)
end_define

begin_comment
comment|/* Can't get master address */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_YPERR
value|((long)-6)
end_define

begin_comment
comment|/* YP server/map db error */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_BADARGS
value|((long)-7)
end_define

begin_comment
comment|/* Request arguments bad */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_DBM
value|((long)-8)
end_define

begin_comment
comment|/* Local dbm operation failed */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_FILE
value|((long)-9)
end_define

begin_comment
comment|/* Local file I/O operation failed */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_SKEW
value|((long)-10)
end_define

begin_comment
comment|/* Map version skew during transfer */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_CLEAR
value|((long)-11)
end_define

begin_comment
comment|/* Can't send "Clear" req to local ypserv */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_FORCE
value|((long)-12)
end_define

begin_comment
comment|/* No local order number in map - use -f */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_XFRERR
value|((long)-13)
end_define

begin_comment
comment|/* ypxfr error */
end_comment

begin_define
define|#
directive|define
name|YPPUSH_REFUSED
value|((long)-14)
end_define

begin_comment
comment|/* Transfer request refused by ypserv */
end_comment

begin_struct_decl
struct_decl|struct
name|inaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|bool_t
name|xdr_datum
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|datum
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypreq_key
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypreq_key
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypreq_nokey
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypreq_nokey
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypreq_xfr
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypreq_xfr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypresp_val
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypresp_val
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypresp_key_val
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypresp_key_val
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypbind_resp
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypbind_resp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypbind_setdom
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypbind_setdom
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_yp_inaddr
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|inaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypmap_parms
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypmap_parms
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_yppushresp_xfr
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|yppushresp_xfr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypresp_order
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypresp_order
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypresp_master
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypresp_master
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|xdr_ypresp_maplist
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|ypresp_maplist
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
comment|/* _RPCSVC_YP_PROT_H_ */
end_comment

end_unit

