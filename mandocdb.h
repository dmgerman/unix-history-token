begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $Id: mandocdb.h,v 1.6.2.1 2013/09/18 00:54:20 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MANDOCDB_H
end_ifndef

begin_define
define|#
directive|define
name|MANDOCDB_H
end_define

begin_define
define|#
directive|define
name|MANDOC_DB
value|"mandoc.db"
end_define

begin_define
define|#
directive|define
name|MANDOC_IDX
value|"mandoc.index"
end_define

begin_define
define|#
directive|define
name|TYPE_An
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ar
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|TYPE_At
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Bsx
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Bx
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Cd
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Cm
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Dv
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Dx
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Em
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Er
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ev
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fa
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fl
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fn
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ft
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fx
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ic
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_In
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Lb
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Li
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Lk
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ms
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Mt
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nd
value|0x0000000001000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nm
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nx
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ox
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Pa
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Rs
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Sh
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ss
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_St
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Sy
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Tn
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Va
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Vt
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Xr
value|0x0000002000000000ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!MANDOCDB_H */
end_comment

end_unit

