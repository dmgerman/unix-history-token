begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: dns_p.h,v 1.11 1999/06/03 20:50:36 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DNS_P_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_DNS_P_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|maybe_ok
parameter_list|(
name|res
parameter_list|,
name|nm
parameter_list|,
name|ok
parameter_list|)
value|(((res)->options& RES_NOCHECKNAME) != 0 || \ 			       (ok)(nm) != 0)
end_define

begin_define
define|#
directive|define
name|maybe_hnok
parameter_list|(
name|res
parameter_list|,
name|hn
parameter_list|)
value|maybe_ok((res), (hn), res_hnok)
end_define

begin_define
define|#
directive|define
name|maybe_dnok
parameter_list|(
name|res
parameter_list|,
name|dn
parameter_list|)
value|maybe_ok((res), (dn), res_dnok)
end_define

begin_comment
comment|/*  * Object state.  */
end_comment

begin_struct
struct|struct
name|dns_p
block|{
name|void
modifier|*
name|hes_ctx
decl_stmt|;
name|struct
name|__res_state
modifier|*
name|res
decl_stmt|;
name|void
argument_list|(
argument|*free_res
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Methods.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|irs_gr
modifier|*
name|irs_dns_gr
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_pw
modifier|*
name|irs_dns_pw
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_sv
modifier|*
name|irs_dns_sv
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_pr
modifier|*
name|irs_dns_pr
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_ho
modifier|*
name|irs_dns_ho
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_nw
modifier|*
name|irs_dns_nw
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DNS_P_H_INCLUDED*/
end_comment

end_unit

