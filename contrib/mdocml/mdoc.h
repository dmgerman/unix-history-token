begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mdoc.h,v 1.144 2015/11/07 14:01:16 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|MDOC_Ap
value|0
end_define

begin_define
define|#
directive|define
name|MDOC_Dd
value|1
end_define

begin_define
define|#
directive|define
name|MDOC_Dt
value|2
end_define

begin_define
define|#
directive|define
name|MDOC_Os
value|3
end_define

begin_define
define|#
directive|define
name|MDOC_Sh
value|4
end_define

begin_define
define|#
directive|define
name|MDOC_Ss
value|5
end_define

begin_define
define|#
directive|define
name|MDOC_Pp
value|6
end_define

begin_define
define|#
directive|define
name|MDOC_D1
value|7
end_define

begin_define
define|#
directive|define
name|MDOC_Dl
value|8
end_define

begin_define
define|#
directive|define
name|MDOC_Bd
value|9
end_define

begin_define
define|#
directive|define
name|MDOC_Ed
value|10
end_define

begin_define
define|#
directive|define
name|MDOC_Bl
value|11
end_define

begin_define
define|#
directive|define
name|MDOC_El
value|12
end_define

begin_define
define|#
directive|define
name|MDOC_It
value|13
end_define

begin_define
define|#
directive|define
name|MDOC_Ad
value|14
end_define

begin_define
define|#
directive|define
name|MDOC_An
value|15
end_define

begin_define
define|#
directive|define
name|MDOC_Ar
value|16
end_define

begin_define
define|#
directive|define
name|MDOC_Cd
value|17
end_define

begin_define
define|#
directive|define
name|MDOC_Cm
value|18
end_define

begin_define
define|#
directive|define
name|MDOC_Dv
value|19
end_define

begin_define
define|#
directive|define
name|MDOC_Er
value|20
end_define

begin_define
define|#
directive|define
name|MDOC_Ev
value|21
end_define

begin_define
define|#
directive|define
name|MDOC_Ex
value|22
end_define

begin_define
define|#
directive|define
name|MDOC_Fa
value|23
end_define

begin_define
define|#
directive|define
name|MDOC_Fd
value|24
end_define

begin_define
define|#
directive|define
name|MDOC_Fl
value|25
end_define

begin_define
define|#
directive|define
name|MDOC_Fn
value|26
end_define

begin_define
define|#
directive|define
name|MDOC_Ft
value|27
end_define

begin_define
define|#
directive|define
name|MDOC_Ic
value|28
end_define

begin_define
define|#
directive|define
name|MDOC_In
value|29
end_define

begin_define
define|#
directive|define
name|MDOC_Li
value|30
end_define

begin_define
define|#
directive|define
name|MDOC_Nd
value|31
end_define

begin_define
define|#
directive|define
name|MDOC_Nm
value|32
end_define

begin_define
define|#
directive|define
name|MDOC_Op
value|33
end_define

begin_define
define|#
directive|define
name|MDOC_Ot
value|34
end_define

begin_define
define|#
directive|define
name|MDOC_Pa
value|35
end_define

begin_define
define|#
directive|define
name|MDOC_Rv
value|36
end_define

begin_define
define|#
directive|define
name|MDOC_St
value|37
end_define

begin_define
define|#
directive|define
name|MDOC_Va
value|38
end_define

begin_define
define|#
directive|define
name|MDOC_Vt
value|39
end_define

begin_define
define|#
directive|define
name|MDOC_Xr
value|40
end_define

begin_define
define|#
directive|define
name|MDOC__A
value|41
end_define

begin_define
define|#
directive|define
name|MDOC__B
value|42
end_define

begin_define
define|#
directive|define
name|MDOC__D
value|43
end_define

begin_define
define|#
directive|define
name|MDOC__I
value|44
end_define

begin_define
define|#
directive|define
name|MDOC__J
value|45
end_define

begin_define
define|#
directive|define
name|MDOC__N
value|46
end_define

begin_define
define|#
directive|define
name|MDOC__O
value|47
end_define

begin_define
define|#
directive|define
name|MDOC__P
value|48
end_define

begin_define
define|#
directive|define
name|MDOC__R
value|49
end_define

begin_define
define|#
directive|define
name|MDOC__T
value|50
end_define

begin_define
define|#
directive|define
name|MDOC__V
value|51
end_define

begin_define
define|#
directive|define
name|MDOC_Ac
value|52
end_define

begin_define
define|#
directive|define
name|MDOC_Ao
value|53
end_define

begin_define
define|#
directive|define
name|MDOC_Aq
value|54
end_define

begin_define
define|#
directive|define
name|MDOC_At
value|55
end_define

begin_define
define|#
directive|define
name|MDOC_Bc
value|56
end_define

begin_define
define|#
directive|define
name|MDOC_Bf
value|57
end_define

begin_define
define|#
directive|define
name|MDOC_Bo
value|58
end_define

begin_define
define|#
directive|define
name|MDOC_Bq
value|59
end_define

begin_define
define|#
directive|define
name|MDOC_Bsx
value|60
end_define

begin_define
define|#
directive|define
name|MDOC_Bx
value|61
end_define

begin_define
define|#
directive|define
name|MDOC_Db
value|62
end_define

begin_define
define|#
directive|define
name|MDOC_Dc
value|63
end_define

begin_define
define|#
directive|define
name|MDOC_Do
value|64
end_define

begin_define
define|#
directive|define
name|MDOC_Dq
value|65
end_define

begin_define
define|#
directive|define
name|MDOC_Ec
value|66
end_define

begin_define
define|#
directive|define
name|MDOC_Ef
value|67
end_define

begin_define
define|#
directive|define
name|MDOC_Em
value|68
end_define

begin_define
define|#
directive|define
name|MDOC_Eo
value|69
end_define

begin_define
define|#
directive|define
name|MDOC_Fx
value|70
end_define

begin_define
define|#
directive|define
name|MDOC_Ms
value|71
end_define

begin_define
define|#
directive|define
name|MDOC_No
value|72
end_define

begin_define
define|#
directive|define
name|MDOC_Ns
value|73
end_define

begin_define
define|#
directive|define
name|MDOC_Nx
value|74
end_define

begin_define
define|#
directive|define
name|MDOC_Ox
value|75
end_define

begin_define
define|#
directive|define
name|MDOC_Pc
value|76
end_define

begin_define
define|#
directive|define
name|MDOC_Pf
value|77
end_define

begin_define
define|#
directive|define
name|MDOC_Po
value|78
end_define

begin_define
define|#
directive|define
name|MDOC_Pq
value|79
end_define

begin_define
define|#
directive|define
name|MDOC_Qc
value|80
end_define

begin_define
define|#
directive|define
name|MDOC_Ql
value|81
end_define

begin_define
define|#
directive|define
name|MDOC_Qo
value|82
end_define

begin_define
define|#
directive|define
name|MDOC_Qq
value|83
end_define

begin_define
define|#
directive|define
name|MDOC_Re
value|84
end_define

begin_define
define|#
directive|define
name|MDOC_Rs
value|85
end_define

begin_define
define|#
directive|define
name|MDOC_Sc
value|86
end_define

begin_define
define|#
directive|define
name|MDOC_So
value|87
end_define

begin_define
define|#
directive|define
name|MDOC_Sq
value|88
end_define

begin_define
define|#
directive|define
name|MDOC_Sm
value|89
end_define

begin_define
define|#
directive|define
name|MDOC_Sx
value|90
end_define

begin_define
define|#
directive|define
name|MDOC_Sy
value|91
end_define

begin_define
define|#
directive|define
name|MDOC_Tn
value|92
end_define

begin_define
define|#
directive|define
name|MDOC_Ux
value|93
end_define

begin_define
define|#
directive|define
name|MDOC_Xc
value|94
end_define

begin_define
define|#
directive|define
name|MDOC_Xo
value|95
end_define

begin_define
define|#
directive|define
name|MDOC_Fo
value|96
end_define

begin_define
define|#
directive|define
name|MDOC_Fc
value|97
end_define

begin_define
define|#
directive|define
name|MDOC_Oo
value|98
end_define

begin_define
define|#
directive|define
name|MDOC_Oc
value|99
end_define

begin_define
define|#
directive|define
name|MDOC_Bk
value|100
end_define

begin_define
define|#
directive|define
name|MDOC_Ek
value|101
end_define

begin_define
define|#
directive|define
name|MDOC_Bt
value|102
end_define

begin_define
define|#
directive|define
name|MDOC_Hf
value|103
end_define

begin_define
define|#
directive|define
name|MDOC_Fr
value|104
end_define

begin_define
define|#
directive|define
name|MDOC_Ud
value|105
end_define

begin_define
define|#
directive|define
name|MDOC_Lb
value|106
end_define

begin_define
define|#
directive|define
name|MDOC_Lp
value|107
end_define

begin_define
define|#
directive|define
name|MDOC_Lk
value|108
end_define

begin_define
define|#
directive|define
name|MDOC_Mt
value|109
end_define

begin_define
define|#
directive|define
name|MDOC_Brq
value|110
end_define

begin_define
define|#
directive|define
name|MDOC_Bro
value|111
end_define

begin_define
define|#
directive|define
name|MDOC_Brc
value|112
end_define

begin_define
define|#
directive|define
name|MDOC__C
value|113
end_define

begin_define
define|#
directive|define
name|MDOC_Es
value|114
end_define

begin_define
define|#
directive|define
name|MDOC_En
value|115
end_define

begin_define
define|#
directive|define
name|MDOC_Dx
value|116
end_define

begin_define
define|#
directive|define
name|MDOC__Q
value|117
end_define

begin_define
define|#
directive|define
name|MDOC_br
value|118
end_define

begin_define
define|#
directive|define
name|MDOC_sp
value|119
end_define

begin_define
define|#
directive|define
name|MDOC__U
value|120
end_define

begin_define
define|#
directive|define
name|MDOC_Ta
value|121
end_define

begin_define
define|#
directive|define
name|MDOC_ll
value|122
end_define

begin_define
define|#
directive|define
name|MDOC_MAX
value|123
end_define

begin_enum
enum|enum
name|mdocargt
block|{
name|MDOC_Split
block|,
comment|/* -split */
name|MDOC_Nosplit
block|,
comment|/* -nospli */
name|MDOC_Ragged
block|,
comment|/* -ragged */
name|MDOC_Unfilled
block|,
comment|/* -unfilled */
name|MDOC_Literal
block|,
comment|/* -literal */
name|MDOC_File
block|,
comment|/* -file */
name|MDOC_Offset
block|,
comment|/* -offset */
name|MDOC_Bullet
block|,
comment|/* -bullet */
name|MDOC_Dash
block|,
comment|/* -dash */
name|MDOC_Hyphen
block|,
comment|/* -hyphen */
name|MDOC_Item
block|,
comment|/* -item */
name|MDOC_Enum
block|,
comment|/* -enum */
name|MDOC_Tag
block|,
comment|/* -tag */
name|MDOC_Diag
block|,
comment|/* -diag */
name|MDOC_Hang
block|,
comment|/* -hang */
name|MDOC_Ohang
block|,
comment|/* -ohang */
name|MDOC_Inset
block|,
comment|/* -inset */
name|MDOC_Column
block|,
comment|/* -column */
name|MDOC_Width
block|,
comment|/* -width */
name|MDOC_Compact
block|,
comment|/* -compact */
name|MDOC_Std
block|,
comment|/* -std */
name|MDOC_Filled
block|,
comment|/* -filled */
name|MDOC_Words
block|,
comment|/* -words */
name|MDOC_Emphasis
block|,
comment|/* -emphasis */
name|MDOC_Symbolic
block|,
comment|/* -symbolic */
name|MDOC_Nested
block|,
comment|/* -nested */
name|MDOC_Centred
block|,
comment|/* -centered */
name|MDOC_ARG_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * An argument to a macro (multiple values = `-column xxx yyy').  */
end_comment

begin_struct
struct|struct
name|mdoc_argv
block|{
name|enum
name|mdocargt
name|arg
decl_stmt|;
comment|/* type of argument */
name|int
name|line
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
comment|/* elements in "value" */
name|char
modifier|*
modifier|*
name|value
decl_stmt|;
comment|/* argument strings */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reference-counted macro arguments.  These are refcounted because  * blocks have multiple instances of the same arguments spread across  * the HEAD, BODY, TAIL, and BLOCK node types.  */
end_comment

begin_struct
struct|struct
name|mdoc_arg
block|{
name|size_t
name|argc
decl_stmt|;
name|struct
name|mdoc_argv
modifier|*
name|argv
decl_stmt|;
name|unsigned
name|int
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mdoc_list
block|{
name|LIST__NONE
init|=
literal|0
block|,
name|LIST_bullet
block|,
comment|/* -bullet */
name|LIST_column
block|,
comment|/* -column */
name|LIST_dash
block|,
comment|/* -dash */
name|LIST_diag
block|,
comment|/* -diag */
name|LIST_enum
block|,
comment|/* -enum */
name|LIST_hang
block|,
comment|/* -hang */
name|LIST_hyphen
block|,
comment|/* -hyphen */
name|LIST_inset
block|,
comment|/* -inset */
name|LIST_item
block|,
comment|/* -item */
name|LIST_ohang
block|,
comment|/* -ohang */
name|LIST_tag
block|,
comment|/* -tag */
name|LIST_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_disp
block|{
name|DISP__NONE
init|=
literal|0
block|,
name|DISP_centered
block|,
comment|/* -centered */
name|DISP_ragged
block|,
comment|/* -ragged */
name|DISP_unfilled
block|,
comment|/* -unfilled */
name|DISP_filled
block|,
comment|/* -filled */
name|DISP_literal
comment|/* -literal */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_auth
block|{
name|AUTH__NONE
init|=
literal|0
block|,
name|AUTH_split
block|,
comment|/* -split */
name|AUTH_nosplit
comment|/* -nosplit */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_font
block|{
name|FONT__NONE
init|=
literal|0
block|,
name|FONT_Em
block|,
comment|/* Em, -emphasis */
name|FONT_Li
block|,
comment|/* Li, -literal */
name|FONT_Sy
comment|/* Sy, -symbolic */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mdoc_bd
block|{
specifier|const
name|char
modifier|*
name|offs
decl_stmt|;
comment|/* -offset */
name|enum
name|mdoc_disp
name|type
decl_stmt|;
comment|/* -ragged, etc. */
name|int
name|comp
decl_stmt|;
comment|/* -compact */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_bl
block|{
specifier|const
name|char
modifier|*
name|width
decl_stmt|;
comment|/* -width */
specifier|const
name|char
modifier|*
name|offs
decl_stmt|;
comment|/* -offset */
name|enum
name|mdoc_list
name|type
decl_stmt|;
comment|/* -tag, -enum, etc. */
name|int
name|comp
decl_stmt|;
comment|/* -compact */
name|size_t
name|ncols
decl_stmt|;
comment|/* -column arg count */
specifier|const
name|char
modifier|*
modifier|*
name|cols
decl_stmt|;
comment|/* -column val ptr */
name|int
name|count
decl_stmt|;
comment|/* -enum counter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_bf
block|{
name|enum
name|mdoc_font
name|font
decl_stmt|;
comment|/* font */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_an
block|{
name|enum
name|mdoc_auth
name|auth
decl_stmt|;
comment|/* -split, etc. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_rs
block|{
name|int
name|quote_T
decl_stmt|;
comment|/* whether to quote %T */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Consists of normalised node arguments.  These should be used instead  * of iterating through the mdoc_arg pointers of a node: defaults are  * provided, etc.  */
end_comment

begin_union
union|union
name|mdoc_data
block|{
name|struct
name|mdoc_an
name|An
decl_stmt|;
name|struct
name|mdoc_bd
name|Bd
decl_stmt|;
name|struct
name|mdoc_bf
name|Bf
decl_stmt|;
name|struct
name|mdoc_bl
name|Bl
decl_stmt|;
name|struct
name|roff_node
modifier|*
name|Es
decl_stmt|;
name|struct
name|mdoc_rs
name|Rs
decl_stmt|;
block|}
union|;
end_union

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
name|mdoc_macronames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Names of macro args.  Index is enum mdocargt. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|mdoc_argnames
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mdoc_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

