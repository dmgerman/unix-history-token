begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mandoc.h,v 1.171 2014/11/28 18:09:01 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010, 2011, 2014 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2010-2014 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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

begin_define
define|#
directive|define
name|ASCII_BREAK
value|29
end_define

begin_comment
comment|/* breakable zero-width space */
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
name|MANDOCERR_DT_NOTITLE
block|,
comment|/* missing manual title, using UNTITLED: line */
name|MANDOCERR_TH_NOTITLE
block|,
comment|/* missing manual title, using "": [macro] */
name|MANDOCERR_TITLE_CASE
block|,
comment|/* lower case character in document title */
name|MANDOCERR_MSEC_MISSING
block|,
comment|/* missing manual section, using "": macro */
name|MANDOCERR_MSEC_BAD
block|,
comment|/* unknown manual section: Dt ... section */
name|MANDOCERR_DATE_MISSING
block|,
comment|/* missing date, using today's date */
name|MANDOCERR_DATE_BAD
block|,
comment|/* cannot parse date, using it verbatim: date */
name|MANDOCERR_OS_MISSING
block|,
comment|/* missing Os macro, using "" */
name|MANDOCERR_PROLOG_REP
block|,
comment|/* duplicate prologue macro: macro */
name|MANDOCERR_PROLOG_LATE
block|,
comment|/* late prologue macro: macro */
name|MANDOCERR_DT_LATE
block|,
comment|/* skipping late title macro: Dt args */
name|MANDOCERR_PROLOG_ORDER
block|,
comment|/* prologue macros out of order: macros */
comment|/* related to document structure */
name|MANDOCERR_SO
block|,
comment|/* .so is fragile, better use ln(1): so path */
name|MANDOCERR_DOC_EMPTY
block|,
comment|/* no document body */
name|MANDOCERR_SEC_BEFORE
block|,
comment|/* content before first section header: macro */
name|MANDOCERR_NAMESEC_FIRST
block|,
comment|/* first section is not NAME: Sh title */
name|MANDOCERR_NAMESEC_BAD
block|,
comment|/* bad NAME section contents: macro */
name|MANDOCERR_SEC_ORDER
block|,
comment|/* sections out of conventional order: Sh title */
name|MANDOCERR_SEC_REP
block|,
comment|/* duplicate section title: Sh title */
name|MANDOCERR_SEC_MSEC
block|,
comment|/* unexpected section: Sh title for ... only */
name|MANDOCERR_XR_ORDER
block|,
comment|/* unusual Xr order: ... after ... */
name|MANDOCERR_XR_PUNCT
block|,
comment|/* unusual Xr punctuation: ... after ... */
name|MANDOCERR_AN_MISSING
block|,
comment|/* AUTHORS section without An macro */
comment|/* related to macros and nesting */
name|MANDOCERR_MACRO_OBS
block|,
comment|/* obsolete macro: macro */
name|MANDOCERR_PAR_SKIP
block|,
comment|/* skipping paragraph macro: macro ... */
name|MANDOCERR_PAR_MOVE
block|,
comment|/* moving paragraph macro out of list: macro */
name|MANDOCERR_NS_SKIP
block|,
comment|/* skipping no-space macro */
name|MANDOCERR_BLK_NEST
block|,
comment|/* blocks badly nested: macro ... */
name|MANDOCERR_BD_NEST
block|,
comment|/* nested displays are not portable: macro ... */
name|MANDOCERR_BL_MOVE
block|,
comment|/* moving content out of list: macro */
name|MANDOCERR_VT_CHILD
block|,
comment|/* .Vt block has child macro: macro */
name|MANDOCERR_FI_SKIP
block|,
comment|/* fill mode already enabled, skipping: fi */
name|MANDOCERR_NF_SKIP
block|,
comment|/* fill mode already disabled, skipping: nf */
name|MANDOCERR_BLK_LINE
block|,
comment|/* line scope broken: macro breaks macro */
comment|/* related to missing arguments */
name|MANDOCERR_REQ_EMPTY
block|,
comment|/* skipping empty request: request */
name|MANDOCERR_COND_EMPTY
block|,
comment|/* conditional request controls empty scope */
name|MANDOCERR_MACRO_EMPTY
block|,
comment|/* skipping empty macro: macro */
name|MANDOCERR_ARG_EMPTY
block|,
comment|/* empty argument, using 0n: macro arg */
name|MANDOCERR_ARGCWARN
block|,
comment|/* argument count wrong */
name|MANDOCERR_BD_NOTYPE
block|,
comment|/* missing display type, using -ragged: Bd */
name|MANDOCERR_BL_LATETYPE
block|,
comment|/* list type is not the first argument: Bl arg */
name|MANDOCERR_BL_NOWIDTH
block|,
comment|/* missing -width in -tag list, using 8n */
name|MANDOCERR_EX_NONAME
block|,
comment|/* missing utility name, using "": Ex */
name|MANDOCERR_IT_NOHEAD
block|,
comment|/* empty head in list item: Bl -type It */
name|MANDOCERR_IT_NOBODY
block|,
comment|/* empty list item: Bl -type It */
name|MANDOCERR_BF_NOFONT
block|,
comment|/* missing font type, using \fR: Bf */
name|MANDOCERR_BF_BADFONT
block|,
comment|/* unknown font type, using \fR: Bf font */
name|MANDOCERR_ARG_STD
block|,
comment|/* missing -std argument, adding it: macro */
name|MANDOCERR_EQN_NOBOX
block|,
comment|/* missing eqn box, using "": op */
comment|/* related to bad arguments */
name|MANDOCERR_ARG_QUOTE
block|,
comment|/* unterminated quoted argument */
name|MANDOCERR_ARG_REP
block|,
comment|/* duplicate argument: macro arg */
name|MANDOCERR_AN_REP
block|,
comment|/* skipping duplicate argument: An -arg */
name|MANDOCERR_BD_REP
block|,
comment|/* skipping duplicate display type: Bd -type */
name|MANDOCERR_BL_REP
block|,
comment|/* skipping duplicate list type: Bl -type */
name|MANDOCERR_BL_SKIPW
block|,
comment|/* skipping -width argument: Bl -type */
name|MANDOCERR_AT_BAD
block|,
comment|/* unknown AT&T UNIX version: At version */
name|MANDOCERR_FA_COMMA
block|,
comment|/* comma in function argument: arg */
name|MANDOCERR_FN_PAREN
block|,
comment|/* parenthesis in function name: arg */
name|MANDOCERR_RS_BAD
block|,
comment|/* invalid content in Rs block: macro */
name|MANDOCERR_SM_BAD
block|,
comment|/* invalid Boolean argument: macro arg */
name|MANDOCERR_FT_BAD
block|,
comment|/* unknown font, skipping request: ft font */
comment|/* related to plain text */
name|MANDOCERR_FI_BLANK
block|,
comment|/* blank line in fill mode, using .sp */
name|MANDOCERR_FI_TAB
block|,
comment|/* tab in filled text */
name|MANDOCERR_SPACE_EOL
block|,
comment|/* whitespace at end of input line */
name|MANDOCERR_COMMENT_BAD
block|,
comment|/* bad comment style */
name|MANDOCERR_ESC_BAD
block|,
comment|/* invalid escape sequence: esc */
name|MANDOCERR_STR_UNDEF
block|,
comment|/* undefined string, using "": name */
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
comment|/* related to document structure and macros */
name|MANDOCERR_ROFFLOOP
block|,
comment|/* input stack limit exceeded, infinite loop? */
name|MANDOCERR_BADCHAR
block|,
comment|/* skipping bad character: number */
name|MANDOCERR_MACRO
block|,
comment|/* skipping unknown macro: macro */
name|MANDOCERR_IT_STRAY
block|,
comment|/* skipping item outside list: It ... */
name|MANDOCERR_TA_STRAY
block|,
comment|/* skipping column outside column list: Ta */
name|MANDOCERR_BLK_NOTOPEN
block|,
comment|/* skipping end of block that is not open */
name|MANDOCERR_BLK_BROKEN
block|,
comment|/* inserting missing end of block: macro ... */
name|MANDOCERR_BLK_NOEND
block|,
comment|/* appending missing end of block: macro */
comment|/* related to request and macro arguments */
name|MANDOCERR_NAMESC
block|,
comment|/* escaped character not allowed in a name: name */
name|MANDOCERR_ARGCOUNT
block|,
comment|/* argument count wrong */
name|MANDOCERR_BD_FILE
block|,
comment|/* NOT IMPLEMENTED: Bd -file */
name|MANDOCERR_BL_NOTYPE
block|,
comment|/* missing list type, using -item: Bl */
name|MANDOCERR_NM_NONAME
block|,
comment|/* missing manual name, using "": Nm */
name|MANDOCERR_OS_UNAME
block|,
comment|/* uname(3) system call failed, using UNKNOWN */
name|MANDOCERR_ST_BAD
block|,
comment|/* unknown standard specifier: St standard */
name|MANDOCERR_IT_NONUM
block|,
comment|/* skipping request without numeric argument */
name|MANDOCERR_ARG_SKIP
block|,
comment|/* skipping all arguments: macro args */
name|MANDOCERR_ARG_EXCESS
block|,
comment|/* skipping excess arguments: macro ... args */
name|MANDOCERR_DIVZERO
block|,
comment|/* divide by zero */
name|MANDOCERR_FATAL
block|,
comment|/* ===== start of fatal errors ===== */
name|MANDOCERR_TOOLARGE
block|,
comment|/* input too large */
name|MANDOCERR_SO_PATH
block|,
comment|/* NOT IMPLEMENTED: .so with absolute path or ".." */
name|MANDOCERR_SO_FAIL
block|,
comment|/* .so request failed */
comment|/* ===== system errors ===== */
name|MANDOCERR_SYSDUP
block|,
comment|/* cannot dup file descriptor */
name|MANDOCERR_SYSEXEC
block|,
comment|/* cannot exec */
name|MANDOCERR_SYSEXIT
block|,
comment|/* gunzip failed with code */
name|MANDOCERR_SYSFORK
block|,
comment|/* cannot fork */
name|MANDOCERR_SYSOPEN
block|,
comment|/* cannot open file */
name|MANDOCERR_SYSPIPE
block|,
comment|/* cannot open pipe */
name|MANDOCERR_SYSREAD
block|,
comment|/* cannot read file */
name|MANDOCERR_SYSSIG
block|,
comment|/* gunzip died from signal */
name|MANDOCERR_SYSSTAT
block|,
comment|/* cannot stat file */
name|MANDOCERR_SYSWAIT
block|,
comment|/* wait failed */
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
define|#
directive|define
name|TBL_CELL_WMAX
value|(1<< 7)
comment|/* x, X */
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
name|int
name|vert
decl_stmt|;
comment|/* trailing vertical line */
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
comment|/* list (braces, etc.) */
name|EQN_LISTONE
block|,
comment|/* singleton list */
name|EQN_PILE
block|,
comment|/* vertical pile */
name|EQN_MATRIX
comment|/* pile of piles */
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
name|EQNPOS_SUP
block|,
name|EQNPOS_SUBSUP
block|,
name|EQNPOS_SUB
block|,
name|EQNPOS_TO
block|,
name|EQNPOS_FROM
block|,
name|EQNPOS_FROMTO
block|,
name|EQNPOS_OVER
block|,
name|EQNPOS_SQRT
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
name|prev
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
comment|/* fence left-hand */
name|char
modifier|*
name|right
decl_stmt|;
comment|/* fence right-hand */
name|char
modifier|*
name|top
decl_stmt|;
comment|/* expression over-symbol */
name|char
modifier|*
name|bottom
decl_stmt|;
comment|/* expression under-symbol */
name|size_t
name|args
decl_stmt|;
comment|/* arguments in parent */
name|size_t
name|expectargs
decl_stmt|;
comment|/* max arguments in parent */
name|enum
name|eqn_post
name|pos
decl_stmt|;
comment|/* position of next box */
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
comment|/*  * An equation consists of a tree of expressions starting at a given  * line and position.  */
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
comment|/*  * Parse options.  */
end_comment

begin_define
define|#
directive|define
name|MPARSE_MDOC
value|1
end_define

begin_comment
comment|/* assume -mdoc */
end_comment

begin_define
define|#
directive|define
name|MPARSE_MAN
value|2
end_define

begin_comment
comment|/* assume -man */
end_comment

begin_define
define|#
directive|define
name|MPARSE_SO
value|4
end_define

begin_comment
comment|/* honour .so requests */
end_comment

begin_define
define|#
directive|define
name|MPARSE_QUICK
value|8
end_define

begin_comment
comment|/* abort the parse early */
end_comment

begin_define
define|#
directive|define
name|MPARSE_UTF8
value|16
end_define

begin_comment
comment|/* accept UTF-8 input */
end_comment

begin_define
define|#
directive|define
name|MPARSE_LATIN1
value|32
end_define

begin_comment
comment|/* accept ISO-LATIN-1 input */
end_comment

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
name|int
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
specifier|const
name|char
modifier|*
name|mchars_uc2str
parameter_list|(
name|int
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
name|int
parameter_list|,
name|enum
name|mandoclevel
parameter_list|,
name|mandocmsg
parameter_list|,
specifier|const
name|struct
name|mchars
modifier|*
parameter_list|,
specifier|const
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
name|mparse_open
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
name|int
modifier|*
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
parameter_list|,
name|char
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

begin_function_decl
name|enum
name|mandoclevel
name|mparse_wait
parameter_list|(
name|struct
name|mparse
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
comment|/*!MANDOC_H*/
end_comment

end_unit

