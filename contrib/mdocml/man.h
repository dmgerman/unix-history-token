begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: man.h,v 1.77 2015/11/07 14:01:16 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|MAN_br
value|0
end_define

begin_define
define|#
directive|define
name|MAN_TH
value|1
end_define

begin_define
define|#
directive|define
name|MAN_SH
value|2
end_define

begin_define
define|#
directive|define
name|MAN_SS
value|3
end_define

begin_define
define|#
directive|define
name|MAN_TP
value|4
end_define

begin_define
define|#
directive|define
name|MAN_LP
value|5
end_define

begin_define
define|#
directive|define
name|MAN_PP
value|6
end_define

begin_define
define|#
directive|define
name|MAN_P
value|7
end_define

begin_define
define|#
directive|define
name|MAN_IP
value|8
end_define

begin_define
define|#
directive|define
name|MAN_HP
value|9
end_define

begin_define
define|#
directive|define
name|MAN_SM
value|10
end_define

begin_define
define|#
directive|define
name|MAN_SB
value|11
end_define

begin_define
define|#
directive|define
name|MAN_BI
value|12
end_define

begin_define
define|#
directive|define
name|MAN_IB
value|13
end_define

begin_define
define|#
directive|define
name|MAN_BR
value|14
end_define

begin_define
define|#
directive|define
name|MAN_RB
value|15
end_define

begin_define
define|#
directive|define
name|MAN_R
value|16
end_define

begin_define
define|#
directive|define
name|MAN_B
value|17
end_define

begin_define
define|#
directive|define
name|MAN_I
value|18
end_define

begin_define
define|#
directive|define
name|MAN_IR
value|19
end_define

begin_define
define|#
directive|define
name|MAN_RI
value|20
end_define

begin_define
define|#
directive|define
name|MAN_sp
value|21
end_define

begin_define
define|#
directive|define
name|MAN_nf
value|22
end_define

begin_define
define|#
directive|define
name|MAN_fi
value|23
end_define

begin_define
define|#
directive|define
name|MAN_RE
value|24
end_define

begin_define
define|#
directive|define
name|MAN_RS
value|25
end_define

begin_define
define|#
directive|define
name|MAN_DT
value|26
end_define

begin_define
define|#
directive|define
name|MAN_UC
value|27
end_define

begin_define
define|#
directive|define
name|MAN_PD
value|28
end_define

begin_define
define|#
directive|define
name|MAN_AT
value|29
end_define

begin_define
define|#
directive|define
name|MAN_in
value|30
end_define

begin_define
define|#
directive|define
name|MAN_ft
value|31
end_define

begin_define
define|#
directive|define
name|MAN_OP
value|32
end_define

begin_define
define|#
directive|define
name|MAN_EX
value|33
end_define

begin_define
define|#
directive|define
name|MAN_EE
value|34
end_define

begin_define
define|#
directive|define
name|MAN_UR
value|35
end_define

begin_define
define|#
directive|define
name|MAN_UE
value|36
end_define

begin_define
define|#
directive|define
name|MAN_ll
value|37
end_define

begin_define
define|#
directive|define
name|MAN_MAX
value|38
end_define

begin_comment
comment|/* Names of macros. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|man_macronames
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|roff_man
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|struct
name|mparse
modifier|*
name|man_mparse
parameter_list|(
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

