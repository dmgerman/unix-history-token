begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mansearch.h,v 1.15 2014/07/24 20:30:45 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2013, 2014 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MANSEARCH_H
end_ifndef

begin_define
define|#
directive|define
name|MANSEARCH_H
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
name|TYPE_arch
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|TYPE_sec
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Xr
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ar
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fa
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fl
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Dv
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fn
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ic
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Pa
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Cm
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Li
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Em
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Cd
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Va
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
name|TYPE_Tn
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Er
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ev
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Sy
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Sh
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_In
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ss
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ox
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_An
value|0x0000000001000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Mt
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_St
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Bx
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_At
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nx
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Fx
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Lk
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Ms
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Bsx
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Dx
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Rs
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
name|TYPE_Lb
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nm
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|TYPE_Nd
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|NAME_SYN
value|0x0000004000000001ULL
end_define

begin_define
define|#
directive|define
name|NAME_FILE
value|0x0000004000000002ULL
end_define

begin_define
define|#
directive|define
name|NAME_TITLE
value|0x000000400000000cULL
end_define

begin_define
define|#
directive|define
name|NAME_FIRST
value|0x0000004000000008ULL
end_define

begin_define
define|#
directive|define
name|NAME_HEAD
value|0x0000004000000010ULL
end_define

begin_define
define|#
directive|define
name|NAME_MASK
value|0x000000000000001fULL
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct
struct|struct
name|manpage
block|{
name|char
modifier|*
name|file
decl_stmt|;
comment|/* to be prefixed by manpath */
name|char
modifier|*
name|names
decl_stmt|;
comment|/* a list of names with sections */
name|char
modifier|*
name|output
decl_stmt|;
comment|/* user-defined additional output */
name|int
name|sec
decl_stmt|;
comment|/* section number, 10 means invalid */
name|int
name|form
decl_stmt|;
comment|/* 0 == catpage */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mansearch
block|{
specifier|const
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* architecture/NULL */
specifier|const
name|char
modifier|*
name|sec
decl_stmt|;
comment|/* mansection/NULL */
name|uint64_t
name|deftype
decl_stmt|;
comment|/* type if no key  */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|MANSEARCH_WHATIS
value|0x01
comment|/* whatis(1) mode: whole words, no keys */
define|#
directive|define
name|MANSEARCH_MAN
value|0x02
comment|/* man(1) mode: string equality, no keys */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mansearch_setup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mansearch
parameter_list|(
specifier|const
name|struct
name|mansearch
modifier|*
name|cfg
parameter_list|,
comment|/* options */
specifier|const
name|struct
name|manpaths
modifier|*
name|paths
parameter_list|,
comment|/* manpaths */
name|int
name|argc
parameter_list|,
comment|/* size of argv */
name|char
modifier|*
name|argv
index|[]
parameter_list|,
comment|/* search terms */
specifier|const
name|char
modifier|*
name|outkey
parameter_list|,
comment|/* name of additional output key */
name|struct
name|manpage
modifier|*
modifier|*
name|res
parameter_list|,
comment|/* results */
name|size_t
modifier|*
name|ressz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* results returned */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!MANSEARCH_H*/
end_comment

end_unit

