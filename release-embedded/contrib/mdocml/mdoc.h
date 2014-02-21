begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mdoc.h,v 1.125 2013/12/24 19:11:45 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MDOC_H
end_ifndef

begin_define
define|#
directive|define
name|MDOC_H
end_define

begin_enum
enum|enum
name|mdoct
block|{
name|MDOC_Ap
init|=
literal|0
block|,
name|MDOC_Dd
block|,
name|MDOC_Dt
block|,
name|MDOC_Os
block|,
name|MDOC_Sh
block|,
name|MDOC_Ss
block|,
name|MDOC_Pp
block|,
name|MDOC_D1
block|,
name|MDOC_Dl
block|,
name|MDOC_Bd
block|,
name|MDOC_Ed
block|,
name|MDOC_Bl
block|,
name|MDOC_El
block|,
name|MDOC_It
block|,
name|MDOC_Ad
block|,
name|MDOC_An
block|,
name|MDOC_Ar
block|,
name|MDOC_Cd
block|,
name|MDOC_Cm
block|,
name|MDOC_Dv
block|,
name|MDOC_Er
block|,
name|MDOC_Ev
block|,
name|MDOC_Ex
block|,
name|MDOC_Fa
block|,
name|MDOC_Fd
block|,
name|MDOC_Fl
block|,
name|MDOC_Fn
block|,
name|MDOC_Ft
block|,
name|MDOC_Ic
block|,
name|MDOC_In
block|,
name|MDOC_Li
block|,
name|MDOC_Nd
block|,
name|MDOC_Nm
block|,
name|MDOC_Op
block|,
name|MDOC_Ot
block|,
name|MDOC_Pa
block|,
name|MDOC_Rv
block|,
name|MDOC_St
block|,
name|MDOC_Va
block|,
name|MDOC_Vt
block|,
name|MDOC_Xr
block|,
name|MDOC__A
block|,
name|MDOC__B
block|,
name|MDOC__D
block|,
name|MDOC__I
block|,
name|MDOC__J
block|,
name|MDOC__N
block|,
name|MDOC__O
block|,
name|MDOC__P
block|,
name|MDOC__R
block|,
name|MDOC__T
block|,
name|MDOC__V
block|,
name|MDOC_Ac
block|,
name|MDOC_Ao
block|,
name|MDOC_Aq
block|,
name|MDOC_At
block|,
name|MDOC_Bc
block|,
name|MDOC_Bf
block|,
name|MDOC_Bo
block|,
name|MDOC_Bq
block|,
name|MDOC_Bsx
block|,
name|MDOC_Bx
block|,
name|MDOC_Db
block|,
name|MDOC_Dc
block|,
name|MDOC_Do
block|,
name|MDOC_Dq
block|,
name|MDOC_Ec
block|,
name|MDOC_Ef
block|,
name|MDOC_Em
block|,
name|MDOC_Eo
block|,
name|MDOC_Fx
block|,
name|MDOC_Ms
block|,
name|MDOC_No
block|,
name|MDOC_Ns
block|,
name|MDOC_Nx
block|,
name|MDOC_Ox
block|,
name|MDOC_Pc
block|,
name|MDOC_Pf
block|,
name|MDOC_Po
block|,
name|MDOC_Pq
block|,
name|MDOC_Qc
block|,
name|MDOC_Ql
block|,
name|MDOC_Qo
block|,
name|MDOC_Qq
block|,
name|MDOC_Re
block|,
name|MDOC_Rs
block|,
name|MDOC_Sc
block|,
name|MDOC_So
block|,
name|MDOC_Sq
block|,
name|MDOC_Sm
block|,
name|MDOC_Sx
block|,
name|MDOC_Sy
block|,
name|MDOC_Tn
block|,
name|MDOC_Ux
block|,
name|MDOC_Xc
block|,
name|MDOC_Xo
block|,
name|MDOC_Fo
block|,
name|MDOC_Fc
block|,
name|MDOC_Oo
block|,
name|MDOC_Oc
block|,
name|MDOC_Bk
block|,
name|MDOC_Ek
block|,
name|MDOC_Bt
block|,
name|MDOC_Hf
block|,
name|MDOC_Fr
block|,
name|MDOC_Ud
block|,
name|MDOC_Lb
block|,
name|MDOC_Lp
block|,
name|MDOC_Lk
block|,
name|MDOC_Mt
block|,
name|MDOC_Brq
block|,
name|MDOC_Bro
block|,
name|MDOC_Brc
block|,
name|MDOC__C
block|,
name|MDOC_Es
block|,
name|MDOC_En
block|,
name|MDOC_Dx
block|,
name|MDOC__Q
block|,
name|MDOC_br
block|,
name|MDOC_sp
block|,
name|MDOC__U
block|,
name|MDOC_Ta
block|,
name|MDOC_MAX
block|}
enum|;
end_enum

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

begin_enum
enum|enum
name|mdoc_type
block|{
name|MDOC_TEXT
block|,
name|MDOC_ELEM
block|,
name|MDOC_HEAD
block|,
name|MDOC_TAIL
block|,
name|MDOC_BODY
block|,
name|MDOC_BLOCK
block|,
name|MDOC_TBL
block|,
name|MDOC_EQN
block|,
name|MDOC_ROOT
block|}
enum|;
end_enum

begin_comment
comment|/*   * Section (named/unnamed) of `Sh'.   Note that these appear in the  * conventional order imposed by mdoc.7.  In the case of SEC_NONE, no  * section has been invoked (this shouldn't happen).  SEC_CUSTOM refers  * to other sections.  */
end_comment

begin_enum
enum|enum
name|mdoc_sec
block|{
name|SEC_NONE
init|=
literal|0
block|,
name|SEC_NAME
block|,
comment|/* NAME */
name|SEC_LIBRARY
block|,
comment|/* LIBRARY */
name|SEC_SYNOPSIS
block|,
comment|/* SYNOPSIS */
name|SEC_DESCRIPTION
block|,
comment|/* DESCRIPTION */
name|SEC_IMPLEMENTATION
block|,
comment|/* IMPLEMENTATION NOTES */
name|SEC_RETURN_VALUES
block|,
comment|/* RETURN VALUES */
name|SEC_ENVIRONMENT
block|,
comment|/* ENVIRONMENT */
name|SEC_FILES
block|,
comment|/* FILES */
name|SEC_EXIT_STATUS
block|,
comment|/* EXIT STATUS */
name|SEC_EXAMPLES
block|,
comment|/* EXAMPLES */
name|SEC_DIAGNOSTICS
block|,
comment|/* DIAGNOSTICS */
name|SEC_COMPATIBILITY
block|,
comment|/* COMPATIBILITY */
name|SEC_ERRORS
block|,
comment|/* ERRORS */
name|SEC_SEE_ALSO
block|,
comment|/* SEE ALSO */
name|SEC_STANDARDS
block|,
comment|/* STANDARDS */
name|SEC_HISTORY
block|,
comment|/* HISTORY */
name|SEC_AUTHORS
block|,
comment|/* AUTHORS */
name|SEC_CAVEATS
block|,
comment|/* CAVEATS */
name|SEC_BUGS
block|,
comment|/* BUGS */
name|SEC_SECURITY
block|,
comment|/* SECURITY */
name|SEC_CUSTOM
block|,
name|SEC__MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mdoc_meta
block|{
name|char
modifier|*
name|msec
decl_stmt|;
comment|/* `Dt' section (1, 3p, etc.) */
name|char
modifier|*
name|vol
decl_stmt|;
comment|/* `Dt' volume (implied) */
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* `Dt' arch (i386, etc.) */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* `Dd' normalised date */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* `Dt' title (FOO, etc.) */
name|char
modifier|*
name|os
decl_stmt|;
comment|/* `Os' system (OpenBSD, etc.) */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* leading `Nm' name */
block|}
struct|;
end_struct

begin_comment
comment|/*   * An argument to a macro (multiple values = `-column xxx yyy').   */
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

begin_comment
comment|/*  * Indicates that a BODY's formatting has ended, but the scope is still  * open.  Used for syntax-broken blocks.  */
end_comment

begin_enum
enum|enum
name|mdoc_endbody
block|{
name|ENDBODY_NOT
init|=
literal|0
block|,
name|ENDBODY_SPACE
block|,
comment|/* is broken: append a space */
name|ENDBODY_NOSPACE
comment|/* is broken: don't append a space */
block|}
enum|;
end_enum

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
name|DISP_centred
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
name|mdoc_rs
name|Rs
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*   * Single node in tree-linked AST.   */
end_comment

begin_struct
struct|struct
name|mdoc_node
block|{
name|struct
name|mdoc_node
modifier|*
name|parent
decl_stmt|;
comment|/* parent AST node */
name|struct
name|mdoc_node
modifier|*
name|child
decl_stmt|;
comment|/* first child AST node */
name|struct
name|mdoc_node
modifier|*
name|last
decl_stmt|;
comment|/* last child AST node */
name|struct
name|mdoc_node
modifier|*
name|next
decl_stmt|;
comment|/* sibling AST node */
name|struct
name|mdoc_node
modifier|*
name|prev
decl_stmt|;
comment|/* prior sibling AST node */
name|int
name|nchild
decl_stmt|;
comment|/* number children */
name|int
name|line
decl_stmt|;
comment|/* parse line */
name|int
name|pos
decl_stmt|;
comment|/* parse column */
name|int
name|lastline
decl_stmt|;
comment|/* the node ends on this line */
name|enum
name|mdoct
name|tok
decl_stmt|;
comment|/* tok or MDOC__MAX if none */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|MDOC_VALID
value|(1<< 0)
comment|/* has been validated */
define|#
directive|define
name|MDOC_EOS
value|(1<< 2)
comment|/* at sentence boundary */
define|#
directive|define
name|MDOC_LINE
value|(1<< 3)
comment|/* first macro/text on line */
define|#
directive|define
name|MDOC_SYNPRETTY
value|(1<< 4)
comment|/* SYNOPSIS-style formatting */
define|#
directive|define
name|MDOC_ENDED
value|(1<< 5)
comment|/* rendering has been ended */
define|#
directive|define
name|MDOC_DELIMO
value|(1<< 6)
define|#
directive|define
name|MDOC_DELIMC
value|(1<< 7)
name|enum
name|mdoc_type
name|type
decl_stmt|;
comment|/* AST node type */
name|enum
name|mdoc_sec
name|sec
decl_stmt|;
comment|/* current named section */
name|union
name|mdoc_data
modifier|*
name|norm
decl_stmt|;
comment|/* normalised args */
specifier|const
name|void
modifier|*
name|prev_font
decl_stmt|;
comment|/* before entering this node */
comment|/* FIXME: these can be union'd to shave a few bytes. */
name|struct
name|mdoc_arg
modifier|*
name|args
decl_stmt|;
comment|/* BLOCK/ELEM */
name|struct
name|mdoc_node
modifier|*
name|pending
decl_stmt|;
comment|/* BLOCK */
name|struct
name|mdoc_node
modifier|*
name|head
decl_stmt|;
comment|/* BLOCK */
name|struct
name|mdoc_node
modifier|*
name|body
decl_stmt|;
comment|/* BLOCK */
name|struct
name|mdoc_node
modifier|*
name|tail
decl_stmt|;
comment|/* BLOCK */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* TEXT */
specifier|const
name|struct
name|tbl_span
modifier|*
name|span
decl_stmt|;
comment|/* TBL */
specifier|const
name|struct
name|eqn
modifier|*
name|eqn
decl_stmt|;
comment|/* EQN */
name|enum
name|mdoc_endbody
name|end
decl_stmt|;
comment|/* BODY */
block|}
struct|;
end_struct

begin_comment
comment|/* Names of macros.  Index is enum mdoct. */
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

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|mdoc
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|struct
name|mdoc_node
modifier|*
name|mdoc_node
parameter_list|(
specifier|const
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|mdoc_meta
modifier|*
name|mdoc_meta
parameter_list|(
specifier|const
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!MDOC_H*/
end_comment

end_unit

