begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: irs_p.h,v 1.8 1999/01/08 19:24:42 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IRS_P_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_IRS_P_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_define
define|#
directive|define
name|IRS_SV_MAXALIASES
value|35
end_define

begin_struct
struct|struct
name|lcl_sv
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
name|line
index|[
name|BUFSIZ
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|servent
name|serv
decl_stmt|;
name|char
modifier|*
name|serv_aliases
index|[
name|IRS_SV_MAXALIASES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|irs_nul_ng
value|__irs_nul_ng
end_define

begin_define
define|#
directive|define
name|map_v4v6_address
value|__map_v4v6_address
end_define

begin_define
define|#
directive|define
name|make_group_list
value|__make_group_list
end_define

begin_define
define|#
directive|define
name|irs_lclsv_fnxt
value|__irs_lclsv_fnxt
end_define

begin_function_decl
specifier|extern
name|void
name|map_v4v6_address
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|make_group_list
parameter_list|(
name|struct
name|irs_gr
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|irs_ng
modifier|*
name|irs_nul_ng
parameter_list|(
name|struct
name|irs_acc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|servent
modifier|*
name|irs_lclsv_fnxt
parameter_list|(
name|struct
name|lcl_sv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

