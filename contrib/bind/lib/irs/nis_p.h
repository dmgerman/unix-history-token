begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: nis_p.h,v 1.6 1999/01/08 19:25:03 vixie Exp $  */
end_comment

begin_comment
comment|/*  * nis_p.h - private include file for the NIS functions.  */
end_comment

begin_comment
comment|/*  * Object state.  */
end_comment

begin_struct
struct|struct
name|nis_p
block|{
name|char
modifier|*
name|domain
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
name|irs_nis_gr
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
name|irs_nis_pw
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
name|irs_nis_sv
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
name|irs_nis_pr
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
name|irs_nis_ho
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
name|irs_nis_nw
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
name|irs_ng
modifier|*
name|irs_nis_ng
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

end_unit

