begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: /var/src/sys/netiso/RCS/clnp_stat.h,v 5.1 89/02/09 16:20:42 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /var/src/sys/netiso/RCS/clnp_stat.h,v $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLNP_STAT__
end_ifndef

begin_define
define|#
directive|define
name|__CLNP_STAT__
end_define

begin_struct
struct|struct
name|clnp_stat
block|{
name|u_short
name|cns_total
decl_stmt|;
comment|/* total pkts received */
name|u_short
name|cns_toosmall
decl_stmt|;
comment|/* fixed part of header too small */
name|u_short
name|cns_badhlen
decl_stmt|;
comment|/* header length is not reasonable */
name|u_short
name|cns_badcsum
decl_stmt|;
comment|/* checksum on packet failed */
name|u_short
name|cns_badaddr
decl_stmt|;
comment|/* address fields were not reasonable */
name|u_short
name|cns_noseg
decl_stmt|;
comment|/* segment information forgotten */
name|u_short
name|cns_badid
decl_stmt|;
comment|/* incorrect protocol id */
name|u_short
name|cns_badvers
decl_stmt|;
comment|/* incorrect version */
name|u_short
name|cns_ttlexpired
decl_stmt|;
comment|/* ttl has expired */
name|u_short
name|cns_forward
decl_stmt|;
comment|/* forwarded packets */
name|u_short
name|cns_errcvd
decl_stmt|;
comment|/* ER packets received */
name|u_short
name|cns_frag
decl_stmt|;
comment|/* fragments generated */
name|u_short
name|cns_sent
decl_stmt|;
comment|/* total packets sent */
name|u_short
name|cns_cachemiss
decl_stmt|;
comment|/* cache misses */
name|u_short
name|cns_congest_set
decl_stmt|;
comment|/* congestion experienced bit set */
name|u_short
name|cns_congest_rcvd
decl_stmt|;
comment|/* congestion experienced bit received */
name|u_short
name|er_protoerr
decl_stmt|;
comment|/*	GEN_NOREAS 									GEN_PROTOERR 									GEN_HDRSYNTAX 									GEN_INCOMPLETE 									GEN_DUPOPT */
name|u_short
name|er_badcsum
decl_stmt|;
comment|/*	GEN_BADCSUM */
name|u_short
name|er_congest
decl_stmt|;
comment|/*	GEN_CONGEST */
name|u_short
name|er_segneeded
decl_stmt|;
comment|/*	GEN_SEGNEEDED */
name|u_short
name|er_reassfail
decl_stmt|;
comment|/*	REASS_INTERFERE */
name|u_short
name|er_dstunreach
decl_stmt|;
comment|/*	ADDR_DESTUNREACH 									ADDR_DESTUNKNOWN */
name|u_short
name|er_srcrterr
decl_stmt|;
comment|/*	SRCRT_UNSPECERR 									SRCRT_SYNTAX 									SRCRT_UNKNOWNADDR 									SRCRT_BADPATH */
name|u_short
name|er_ttlexpired
decl_stmt|;
comment|/*	TTL_EXPTRANSIT 									TTL_EXPREASS */
name|u_short
name|er_unsupported
decl_stmt|;
comment|/*	DISC_UNSUPPOPT 									DISC_UNSUPPVERS 									DISC_UNSUPPSECURE 									DISC_UNSUPPSRCRT 									DISC_UNSUPPRECRT */
block|}
name|clnp_stat
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INCSTAT
end_ifdef

begin_undef
undef|#
directive|undef
name|INCSTAT
end_undef

begin_endif
endif|#
directive|endif
endif|INCSTAT
end_endif

begin_define
define|#
directive|define
name|INCSTAT
parameter_list|(
name|x
parameter_list|)
value|clnp_stat.
comment|/**/
value|x
comment|/**/
value|++
end_define

begin_endif
endif|#
directive|endif
endif|__CLNP_STAT__
end_endif

end_unit

