begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * This file is primarily maintained by<tytso@mit.edu> and<ghudson@mit.edu>.  */
end_comment

begin_comment
comment|/*  * $Id: hesiod.h,v 1.7 1999/01/08 19:22:45 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HESIOD_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_HESIOD_H_INCLUDED
end_define

begin_decl_stmt
name|int
name|hesiod_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|*
name|context
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hesiod_end
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hesiod_to_bind
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|hesiod_resolve
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hesiod_free_list
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|,
name|char
operator|*
operator|*
name|list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|__res_state
modifier|*
name|__hesiod_res_get
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__hesiod_res_set
name|__P
argument_list|(
operator|(
name|void
operator|*
name|context
operator|,
expr|struct
name|__res_state
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_HESIOD_H_INCLUDED*/
end_comment

end_unit

