begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * This file is primarily maintained by<tytso@mit.edu> and<ghudson@mit.edu>.  */
end_comment

begin_comment
comment|/*  * $Id: hesiod_p.h,v 1.6 1996/11/18 09:09:32 vixie Exp $  */
end_comment

begin_comment
comment|/*  * hesiod_p.h -- private definitions for the hesiod library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HESIOD_P_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_HESIOD_P_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|DEF_RHS
value|".Athena.MIT.EDU"
end_define

begin_comment
comment|/* Defaults if HESIOD_CONF */
end_comment

begin_define
define|#
directive|define
name|DEF_LHS
value|".ns"
end_define

begin_comment
comment|/*    file is not */
end_comment

begin_comment
comment|/*    present. */
end_comment

begin_struct
struct|struct
name|hesiod_p
block|{
name|char
modifier|*
name|LHS
decl_stmt|;
comment|/* normally ".ns" */
name|char
modifier|*
name|RHS
decl_stmt|;
comment|/* AKA the default hesiod domain */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_HESRESP
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_HESIOD_P_H_INCLUDED*/
end_comment

end_unit

