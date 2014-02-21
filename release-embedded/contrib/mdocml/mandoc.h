begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mandoc.h,v 1.112 2013/12/30 18:30:32 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2012, 2013 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MANDOC_H
end_ifndef

begin_define
define|#
directive|define
name|MANDOC_H
end_define

begin_define
define|#
directive|define
name|ASCII_NBRSP
value|31
end_define

begin_comment
comment|/* non-breaking space */
end_comment

begin_define
define|#
directive|define
name|ASCII_HYPH
value|30
end_define

begin_comment
comment|/* breakable hyphen */
end_comment

begin_comment
comment|/*  * Status level.  This refers to both internal status (i.e., whilst  * running, when warnings/errors are reported) and an indicator of a  * threshold of when to halt (when said internal state exceeds the  * threshold).  */
end_comment

begin_enum
enum|enum
name|mandoclevel
block|{
name|MANDOCLEVEL_OK
init|=
literal|0
block|,
name|MANDOCLEVEL_RESERVED
block|,
name|MANDOCLEVEL_WARNING
block|,
comment|/* warnings: syntax, whitespace, etc. */
name|MANDOCLEVEL_ERROR
block|,
comment|/* input has been thrown away */
name|MANDOCLEVEL_FATAL
block|,
comment|/* input is borked */
name|MANDOCLEVEL_BADARG
block|,
comment|/* bad argument in invocation */
name|MANDOCLEVEL_SYSERR
block|,
comment|/* system error */
name|MANDOCLEVEL_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * All possible things that can go wrong within a parse, be it libroff,  * libmdoc, or libman.  */
end_comment

begin_enum
enum|enum
name|mandocerr
block|{
name|MANDOCERR_OK
block|,
name|MANDOCERR_WARNING
block|,
comment|/* ===== start of warnings ===== */
comment|/* related to the prologue */
name|MANDOCERR_NOTITLE
block|,
comment|/* no title in document */
name|MANDOCERR_UPPERCASE
block|,
comment|/* document title should be all caps */
name|MANDOCERR_BADMSEC
block|,
comment|/* unknown manual section */
name|MANDOCERR_BADVOLARCH
block|,
comment|/* unknown manual volume or arch */
name|MANDOCERR_NODATE
block|,
comment|/* date missing, using today's date */
name|MANDOCERR_BADDATE
block|,
comment|/* cannot parse date, using it verbatim */
name|MANDOCERR_PROLOGOOO
block|,
comment|/* prologue macros out of order */
name|MANDOCERR_PROLOGREP
block|,
comment|/* duplicate prologue macro */
name|MANDOCERR_BADPROLOG
block|,
comment|/* macro not allowed in prologue */
name|MANDOCERR_BADBODY
block|,
comment|/* macro not allowed in body */
comment|/* related to document structure */
name|MANDOCERR_SO
block|,
comment|/* .so is fragile, better use ln(1) */
name|MANDOCERR_NAMESECFIRST
block|,
comment|/* NAME section must come first */
name|MANDOCERR_BADNAMESEC
block|,
comment|/* bad NAME section contents */
name|MANDOCERR_SECOOO
block|,
comment|/* sections out of conventional order */
name|MANDOCERR_SECREP
block|,
comment|/* duplicate section name */
name|MANDOCERR_SECMSEC
block|,
comment|/* section header suited to sections ... */
comment|/* related to macros and nesting */
name|MANDOCERR_MACROOBS
block|,
comment|/* skipping obsolete macro */
name|MANDOCERR_IGNPAR
block|,
comment|/* skipping paragraph macro */
name|MANDOCERR_MOVEPAR
block|,
comment|/* moving paragraph macro out of list */
name|MANDOCERR_IGNNS
block|,
comment|/* skipping no-space macro */
name|MANDOCERR_SCOPENEST
block|,
comment|/* blocks badly nested */
name|MANDOCERR_CHILD
block|,
comment|/* child violates parent syntax */
name|MANDOCERR_NESTEDDISP
block|,
comment|/* nested displays are not portable */
name|MANDOCERR_SCOPEREP
block|,
comment|/* already in literal mode */
name|MANDOCERR_LINESCOPE
block|,
comment|/* line scope broken */
comment|/* related to missing macro arguments */
name|MANDOCERR_MACROEMPTY
block|,
comment|/* skipping empty macro */
name|MANDOCERR_ARGCWARN
block|,
comment|/* argument count wrong */
name|MANDOCERR_DISPTYPE
block|,
comment|/* missing display type */
name|MANDOCERR_LISTFIRST
block|,
comment|/* list type must come first */
name|MANDOCERR_NOWIDTHARG
block|,
comment|/* tag lists require a width argument */
name|MANDOCERR_FONTTYPE
block|,
comment|/* missing font type */
name|MANDOCERR_WNOSCOPE
block|,
comment|/* skipping end of block that is not open */
comment|/* related to bad macro arguments */
name|MANDOCERR_IGNARGV
block|,
comment|/* skipping argument */
name|MANDOCERR_ARGVREP
block|,
comment|/* duplicate argument */
name|MANDOCERR_DISPREP
block|,
comment|/* duplicate display type */
name|MANDOCERR_LISTREP
block|,
comment|/* duplicate list type */
name|MANDOCERR_BADATT
block|,
comment|/* unknown AT&T UNIX version */
name|MANDOCERR_BADBOOL
block|,
comment|/* bad Boolean value */
name|MANDOCERR_BADFONT
block|,
comment|/* unknown font */
name|MANDOCERR_BADSTANDARD
block|,
comment|/* unknown standard specifier */
name|MANDOCERR_BADWIDTH
block|,
comment|/* bad width argument */
comment|/* related to plain text */
name|MANDOCERR_NOBLANKLN
block|,
comment|/* blank line in non-literal context */
name|MANDOCERR_BADTAB
block|,
comment|/* tab in non-literal context */
name|MANDOCERR_EOLNSPACE
block|,
comment|/* end of line whitespace */
name|MANDOCERR_BADCOMMENT
block|,
comment|/* bad comment style */
name|MANDOCERR_BADESCAPE
block|,
comment|/* unknown escape sequence */
name|MANDOCERR_BADQUOTE
block|,
comment|/* unterminated quoted string */
comment|/* related to equations */
name|MANDOCERR_EQNQUOTE
block|,
comment|/* unexpected literal in equation */
name|MANDOCERR_ERROR
block|,
comment|/* ===== start of errors ===== */
comment|/* related to equations */
name|MANDOCERR_EQNNSCOPE
block|,
comment|/* unexpected equation scope closure*/
name|MANDOCERR_EQNSCOPE
block|,
comment|/* equation scope open on exit */
name|MANDOCERR_EQNBADSCOPE
block|,
comment|/* overlapping equation scopes */
name|MANDOCERR_EQNEOF
block|,
comment|/* unexpected end of equation */
name|MANDOCERR_EQNSYNT
block|,
comment|/* equation syntax error */
comment|/* related to tables */
name|MANDOCERR_TBL
block|,
comment|/* bad table syntax */
name|MANDOCERR_TBLOPT
block|,
comment|/* bad table option */
name|MANDOCERR_TBLLAYOUT
block|,
comment|/* bad table layout */
name|MANDOCERR_TBLNOLAYOUT
block|,
comment|/* no table layout cells specified */
name|MANDOCERR_TBLNODATA
block|,
comment|/* no table data cells specified */
name|MANDOCERR_TBLIGNDATA
block|,
comment|/* ignore data in cell */
name|MANDOCERR_TBLBLOCK
block|,
comment|/* data block still open */
name|MANDOCERR_TBLEXTRADAT
block|,
comment|/* ignoring extra data cells */
name|MANDOCERR_ROFFLOOP
block|,
comment|/* input stack limit exceeded, infinite loop? */
name|MANDOCERR_BADCHAR
block|,
comment|/* skipping bad character */
name|MANDOCERR_NAMESC
block|,
comment|/* escaped character not allowed in a name */
name|MANDOCERR_NONAME
block|,
comment|/* manual name not yet set */
name|MANDOCERR_NOTEXT
block|,
comment|/* skipping text before the first section header */
name|MANDOCERR_MACRO
block|,
comment|/* skipping unknown macro */
name|MANDOCERR_REQUEST
block|,
comment|/* NOT IMPLEMENTED: skipping request */
name|MANDOCERR_ARGCOUNT
block|,
comment|/* argument count wrong */
name|MANDOCERR_STRAYTA
block|,
comment|/* skipping column outside column list */
name|MANDOCERR_NOSCOPE
block|,
comment|/* skipping end of block that is not open */
name|MANDOCERR_SCOPEBROKEN
block|,
comment|/* missing end of block */
name|MANDOCERR_SCOPEEXIT
block|,
comment|/* scope open on exit */
name|MANDOCERR_UNAME
block|,
comment|/* uname(3) system call failed */
comment|/* FIXME: merge following with MANDOCERR_ARGCOUNT */
name|MANDOCERR_NOARGS
block|,
comment|/* macro requires line argument(s) */
name|MANDOCERR_NOBODY
block|,
comment|/* macro requires body argument(s) */
name|MANDOCERR_NOARGV
block|,
comment|/* macro requires argument(s) */
name|MANDOCERR_NUMERIC
block|,
comment|/* request requires a numeric argument */
name|MANDOCERR_LISTTYPE
block|,
comment|/* missing list type */
name|MANDOCERR_ARGSLOST
block|,
comment|/* line argument(s) will be lost */
name|MANDOCERR_BODYLOST
block|,
comment|/* body argument(s) will be lost */
name|MANDOCERR_FATAL
block|,
comment|/* ===== start of fatal errors ===== */
name|MANDOCERR_NOTMANUAL
block|,
comment|/* manual isn't really a manual */
name|MANDOCERR_COLUMNS
block|,
comment|/* column syntax is inconsistent */
name|MANDOCERR_BADDISP
block|,
comment|/* NOT IMPLEMENTED: .Bd -file */
name|MANDOCERR_SYNTARGVCOUNT
block|,
comment|/* argument count wrong, violates syntax */
name|MANDOCERR_SYNTCHILD
block|,
comment|/* child violates parent syntax */
name|MANDOCERR_SYNTARGCOUNT
block|,
comment|/* argument count wrong, violates syntax */
name|MANDOCERR_SOPATH
block|,
comment|/* NOT IMPLEMENTED: .so with absolute path or ".." */
name|MANDOCERR_NODOCBODY
block|,
comment|/* no document body */
name|MANDOCERR_NODOCPROLOG
block|,
comment|/* no document prologue */
name|MANDOCERR_MEM
block|,
comment|/* static buffer exhausted */
name|MANDOCERR_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|tbl_opts
block|{
name|char
name|tab
decl_stmt|;
comment|/* cell-separator */
name|char
name|decimal
decl_stmt|;
comment|/* decimal point */
name|int
name|linesize
decl_stmt|;
name|int
name|opts
decl_stmt|;
define|#
directive|define
name|TBL_OPT_CENTRE
value|(1<< 0)
define|#
directive|define
name|TBL_OPT_EXPAND
value|(1<< 1)
define|#
directive|define
name|TBL_OPT_BOX
value|(1<< 2)
define|#
directive|define
name|TBL_OPT_DBOX
value|(1<< 3)
define|#
directive|define
name|TBL_OPT_ALLBOX
value|(1<< 4)
define|#
directive|define
name|TBL_OPT_NOKEEP
value|(1<< 5)
define|#
directive|define
name|TBL_OPT_NOSPACE
value|(1<< 6)
name|int
name|cols
decl_stmt|;
comment|/* number of columns */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The head of a table specifies all of its columns.  When formatting a  * tbl_span, iterate over these and plug in data from the tbl_span when  * appropriate, using tbl_cell as a guide to placement.  */
end_comment

begin_struct
struct|struct
name|tbl_head
block|{
name|int
name|ident
decl_stmt|;
comment|/* 0<= unique id< cols */
name|int
name|vert
decl_stmt|;
comment|/* width of preceding vertical line */
name|struct
name|tbl_head
modifier|*
name|next
decl_stmt|;
name|struct
name|tbl_head
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|tbl_cellt
block|{
name|TBL_CELL_CENTRE
block|,
comment|/* c, C */
name|TBL_CELL_RIGHT
block|,
comment|/* r, R */
name|TBL_CELL_LEFT
block|,
comment|/* l, L */
name|TBL_CELL_NUMBER
block|,
comment|/* n, N */
name|TBL_CELL_SPAN
block|,
comment|/* s, S */
name|TBL_CELL_LONG
block|,
comment|/* a, A */
name|TBL_CELL_DOWN
block|,
comment|/* ^ */
name|TBL_CELL_HORIZ
block|,
comment|/* _, - */
name|TBL_CELL_DHORIZ
block|,
comment|/* = */
name|TBL_CELL_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * A cell in a layout row.  */
end_comment

begin_struct
struct|struct
name|tbl_cell
block|{
name|struct
name|tbl_cell
modifier|*
name|next
decl_stmt|;
name|int
name|vert
decl_stmt|;
comment|/* width of preceding vertical line */
name|enum
name|tbl_cellt
name|pos
decl_stmt|;
name|size_t
name|spacing
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|TBL_CELL_TALIGN
value|(1<< 0)
comment|/* t, T */
define|#
directive|define
name|TBL_CELL_BALIGN
value|(1<< 1)
comment|/* d, D */
define|#
directive|define
name|TBL_CELL_BOLD
value|(1<< 2)
comment|/* fB, B, b */
define|#
directive|define
name|TBL_CELL_ITALIC
value|(1<< 3)
comment|/* fI, I, i */
define|#
directive|define
name|TBL_CELL_EQUAL
value|(1<< 4)
comment|/* e, E */
define|#
directive|define
name|TBL_CELL_UP
value|(1<< 5)
comment|/* u, U */
define|#
directive|define
name|TBL_CELL_WIGN
value|(1<< 6)
comment|/* z, Z */
name|struct
name|tbl_head
modifier|*
name|head
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A layout row.  */
end_comment

begin_struct
struct|struct
name|tbl_row
block|{
name|struct
name|tbl_row
modifier|*
name|next
decl_stmt|;
name|struct
name|tbl_cell
modifier|*
name|first
decl_stmt|;
name|struct
name|tbl_cell
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|tbl_datt
block|{
name|TBL_DATA_NONE
block|,
comment|/* has no data */
name|TBL_DATA_DATA
block|,
comment|/* consists of data/string */
name|TBL_DATA_HORIZ
block|,
comment|/* horizontal line */
name|TBL_DATA_DHORIZ
block|,
comment|/* double-horizontal line */
name|TBL_DATA_NHORIZ
block|,
comment|/* squeezed horizontal line */
name|TBL_DATA_NDHORIZ
comment|/* squeezed double-horizontal line */
block|}
enum|;
end_enum

begin_comment
comment|/*  * A cell within a row of data.  The "string" field contains the actual  * string value that's in the cell.  The rest is layout.  */
end_comment

begin_struct
struct|struct
name|tbl_dat
block|{
name|struct
name|tbl_cell
modifier|*
name|layout
decl_stmt|;
comment|/* layout cell */
name|int
name|spans
decl_stmt|;
comment|/* how many spans follow */
name|struct
name|tbl_dat
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
comment|/* data (NULL if not TBL_DATA_DATA) */
name|enum
name|tbl_datt
name|pos
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|tbl_spant
block|{
name|TBL_SPAN_DATA
block|,
comment|/* span consists of data */
name|TBL_SPAN_HORIZ
block|,
comment|/* span is horizontal line */
name|TBL_SPAN_DHORIZ
comment|/* span is double horizontal line */
block|}
enum|;
end_enum

begin_comment
comment|/*  * A row of data in a table.  */
end_comment

begin_struct
struct|struct
name|tbl_span
block|{
name|struct
name|tbl_opts
modifier|*
name|opts
decl_stmt|;
name|struct
name|tbl_head
modifier|*
name|head
decl_stmt|;
name|struct
name|tbl_row
modifier|*
name|layout
decl_stmt|;
comment|/* layout row */
name|struct
name|tbl_dat
modifier|*
name|first
decl_stmt|;
name|struct
name|tbl_dat
modifier|*
name|last
decl_stmt|;
name|int
name|line
decl_stmt|;
comment|/* parse line */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|TBL_SPAN_FIRST
value|(1<< 0)
define|#
directive|define
name|TBL_SPAN_LAST
value|(1<< 1)
name|enum
name|tbl_spant
name|pos
decl_stmt|;
name|struct
name|tbl_span
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|eqn_boxt
block|{
name|EQN_ROOT
block|,
comment|/* root of parse tree */
name|EQN_TEXT
block|,
comment|/* text (number, variable, whatever) */
name|EQN_SUBEXPR
block|,
comment|/* nested `eqn' subexpression */
name|EQN_LIST
block|,
comment|/* subexpressions list */
name|EQN_MATRIX
comment|/* matrix subexpression */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|eqn_markt
block|{
name|EQNMARK_NONE
init|=
literal|0
block|,
name|EQNMARK_DOT
block|,
name|EQNMARK_DOTDOT
block|,
name|EQNMARK_HAT
block|,
name|EQNMARK_TILDE
block|,
name|EQNMARK_VEC
block|,
name|EQNMARK_DYAD
block|,
name|EQNMARK_BAR
block|,
name|EQNMARK_UNDER
block|,
name|EQNMARK__MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|eqn_fontt
block|{
name|EQNFONT_NONE
init|=
literal|0
block|,
name|EQNFONT_ROMAN
block|,
name|EQNFONT_BOLD
block|,
name|EQNFONT_FAT
block|,
name|EQNFONT_ITALIC
block|,
name|EQNFONT__MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|eqn_post
block|{
name|EQNPOS_NONE
init|=
literal|0
block|,
name|EQNPOS_OVER
block|,
name|EQNPOS_SUP
block|,
name|EQNPOS_SUB
block|,
name|EQNPOS_TO
block|,
name|EQNPOS_FROM
block|,
name|EQNPOS__MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|eqn_pilet
block|{
name|EQNPILE_NONE
init|=
literal|0
block|,
name|EQNPILE_PILE
block|,
name|EQNPILE_CPILE
block|,
name|EQNPILE_RPILE
block|,
name|EQNPILE_LPILE
block|,
name|EQNPILE_COL
block|,
name|EQNPILE_CCOL
block|,
name|EQNPILE_RCOL
block|,
name|EQNPILE_LCOL
block|,
name|EQNPILE__MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * A "box" is a parsed mathematical expression as defined by the eqn.7  * grammar.  */
end_comment

begin_struct
struct|struct
name|eqn_box
block|{
name|int
name|size
decl_stmt|;
comment|/* font size of expression */
define|#
directive|define
name|EQN_DEFSIZE
value|INT_MIN
name|enum
name|eqn_boxt
name|type
decl_stmt|;
comment|/* type of node */
name|struct
name|eqn_box
modifier|*
name|first
decl_stmt|;
comment|/* first child node */
name|struct
name|eqn_box
modifier|*
name|last
decl_stmt|;
comment|/* last child node */
name|struct
name|eqn_box
modifier|*
name|next
decl_stmt|;
comment|/* node sibling */
name|struct
name|eqn_box
modifier|*
name|parent
decl_stmt|;
comment|/* node sibling */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* text (or NULL) */
name|char
modifier|*
name|left
decl_stmt|;
name|char
modifier|*
name|right
decl_stmt|;
name|enum
name|eqn_post
name|pos
decl_stmt|;
comment|/* position of next box */
name|enum
name|eqn_markt
name|mark
decl_stmt|;
comment|/* a mark about the box */
name|enum
name|eqn_fontt
name|font
decl_stmt|;
comment|/* font of box */
name|enum
name|eqn_pilet
name|pile
decl_stmt|;
comment|/* equation piling */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An equation consists of a tree of expressions starting at a given  * line and position.   */
end_comment

begin_struct
struct|struct
name|eqn
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* identifier (or NULL) */
name|struct
name|eqn_box
modifier|*
name|root
decl_stmt|;
comment|/* root mathematical expression */
name|int
name|ln
decl_stmt|;
comment|/* invocation line */
name|int
name|pos
decl_stmt|;
comment|/* invocation position */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The type of parse sequence.  This value is usually passed via the  * mandoc(1) command line of -man and -mdoc.  It's almost exclusively  * -mandoc but the others have been retained for compatibility.  */
end_comment

begin_enum
enum|enum
name|mparset
block|{
name|MPARSE_AUTO
block|,
comment|/* magically determine the document type */
name|MPARSE_MDOC
block|,
comment|/* assume -mdoc */
name|MPARSE_MAN
comment|/* assume -man */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mandoc_esc
block|{
name|ESCAPE_ERROR
init|=
literal|0
block|,
comment|/* bail! unparsable escape */
name|ESCAPE_IGNORE
block|,
comment|/* escape to be ignored */
name|ESCAPE_SPECIAL
block|,
comment|/* a regular special character */
name|ESCAPE_FONT
block|,
comment|/* a generic font mode */
name|ESCAPE_FONTBOLD
block|,
comment|/* bold font mode */
name|ESCAPE_FONTITALIC
block|,
comment|/* italic font mode */
name|ESCAPE_FONTBI
block|,
comment|/* bold italic font mode */
name|ESCAPE_FONTROMAN
block|,
comment|/* roman font mode */
name|ESCAPE_FONTPREV
block|,
comment|/* previous font mode */
name|ESCAPE_NUMBERED
block|,
comment|/* a numbered glyph */
name|ESCAPE_UNICODE
block|,
comment|/* a unicode codepoint */
name|ESCAPE_NOSPACE
block|,
comment|/* suppress space if the last on a line */
name|ESCAPE_SKIPCHAR
comment|/* skip the next character */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mandocmsg
function_decl|)
parameter_list|(
name|enum
name|mandocerr
parameter_list|,
name|enum
name|mandoclevel
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|mparse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mchars
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mdoc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|man
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|void
modifier|*
name|mandoc_calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mandoc_esc
name|mandoc_escape
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mandoc_malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mandoc_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mandoc_strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mandoc_strndup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mchars
modifier|*
name|mchars_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mchars_free
parameter_list|(
name|struct
name|mchars
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|mchars_num2char
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mchars_num2uc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mchars_spec2cp
parameter_list|(
specifier|const
name|struct
name|mchars
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mchars_spec2str
parameter_list|(
specifier|const
name|struct
name|mchars
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mparse
modifier|*
name|mparse_alloc
parameter_list|(
name|enum
name|mparset
parameter_list|,
name|enum
name|mandoclevel
parameter_list|,
name|mandocmsg
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mparse_free
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mparse_keep
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mandoclevel
name|mparse_readfd
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mandoclevel
name|mparse_readmem
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mparse_reset
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mparse_result
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
name|struct
name|mdoc
modifier|*
modifier|*
parameter_list|,
name|struct
name|man
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mparse_getkeep
parameter_list|(
specifier|const
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mparse_strerror
parameter_list|(
name|enum
name|mandocerr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mparse_strlevel
parameter_list|(
name|enum
name|mandoclevel
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
comment|/*!MANDOC_H*/
end_comment

end_unit

