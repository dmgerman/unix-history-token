begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* Macintosh related things. K. Mitchum 2/88 */
end_comment

begin_define
define|#
directive|define
name|NMENUS
value|6
end_define

begin_define
define|#
directive|define
name|NMENUITEMS
value|40
end_define

begin_comment
comment|/* This has GOT to be enough! */
end_comment

begin_typedef
typedef|typedef
name|data_obj
modifier|*
name|menumap
index|[
name|NMENUITEMS
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|menu
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|int
name|menu_id
decl_stmt|;
name|MenuHandle
name|Mn
decl_stmt|;
name|menumap
name|m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stat
block|{
name|int
name|st_dev
decl_stmt|;
comment|/* volume number */
name|long
name|st_ino
decl_stmt|;
comment|/* file number on volume */
name|dev_t
name|st_rdev
decl_stmt|;
name|off_t
name|st_size
decl_stmt|;
comment|/* logical end of file */
name|int
name|st_mode
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
comment|/* last modified */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_IFDIR
value|2
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_dcl
value|va_list va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|l
parameter_list|)
value|{ (l) = (va_list)&va_alist; }
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|(((m*)((l) += sizeof(m)))[-1])
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|l
parameter_list|)
value|{ (l) = NULL; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_mac
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|menu
name|Menus
index|[
name|NMENUS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|EventRecord
name|the_Event
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keycodes (from Inside MacIntosh I-251). because of changes with the MacPlus, there are some duplicate codes between cursor keys and keypad keys. these can be deciphered by the corresponding character codes, which are different. this table simply translates a keycode into a character code that is appropriate. */
end_comment

begin_define
define|#
directive|define
name|NOKEY
value|(-1)
end_define

begin_define
define|#
directive|define
name|RET
value|0x0D
end_define

begin_define
define|#
directive|define
name|TAB
value|0x09
end_define

begin_define
define|#
directive|define
name|BACKSP
value|0x08
end_define

begin_define
define|#
directive|define
name|ENTERL
value|NOKEY
end_define

begin_comment
comment|/* left enter key absent on MacPlus */
end_comment

begin_define
define|#
directive|define
name|COMMAND
value|NOKEY
end_define

begin_comment
comment|/* will be no translation anyway for these */
end_comment

begin_define
define|#
directive|define
name|SHIFT
value|NOKEY
end_define

begin_define
define|#
directive|define
name|CAPSLOCK
value|NOKEY
end_define

begin_define
define|#
directive|define
name|OPTION
value|NOKEY
end_define

begin_define
define|#
directive|define
name|PADDOT
value|'.'
end_define

begin_comment
comment|/* PAD period */
end_comment

begin_define
define|#
directive|define
name|PAD0
value|'0'
end_define

begin_define
define|#
directive|define
name|PAD1
value|'1'
end_define

begin_define
define|#
directive|define
name|PAD2
value|'2'
end_define

begin_define
define|#
directive|define
name|PAD3
value|'3'
end_define

begin_define
define|#
directive|define
name|PAD4
value|'4'
end_define

begin_define
define|#
directive|define
name|PAD5
value|'5'
end_define

begin_define
define|#
directive|define
name|PAD6
value|'6'
end_define

begin_define
define|#
directive|define
name|PAD7
value|'7'
end_define

begin_define
define|#
directive|define
name|PAD8
value|'8'
end_define

begin_define
define|#
directive|define
name|PAD9
value|'9'
end_define

begin_define
define|#
directive|define
name|LEFTCURS
value|'B'
end_define

begin_comment
comment|/* jove only, make like commands */
end_comment

begin_define
define|#
directive|define
name|RIGHTCURS
value|'F'
end_define

begin_define
define|#
directive|define
name|UPCURS
value|'P'
end_define

begin_define
define|#
directive|define
name|DOWNCURS
value|'N'
end_define

begin_define
define|#
directive|define
name|PADENTER
value|RET
end_define

begin_define
define|#
directive|define
name|PADMINUS
value|'-'
end_define

begin_define
define|#
directive|define
name|CLEAR
value|0
end_define

begin_decl_stmt
specifier|static
name|char
name|nsh_keycodes
index|[]
init|=
block|{
literal|'a'
block|,
literal|'s'
block|,
literal|'d'
block|,
literal|'f'
block|,
literal|'h'
block|,
comment|/* 0 - 4 */
literal|'g'
block|,
literal|'z'
block|,
literal|'x'
block|,
literal|'c'
block|,
literal|'v'
block|,
comment|/* 5 - 9 */
name|NOKEY
block|,
literal|'b'
block|,
literal|'q'
block|,
literal|'w'
block|,
literal|'e'
block|,
comment|/* 10 - 14 */
literal|'r'
block|,
literal|'y'
block|,
literal|'t'
block|,
literal|'1'
block|,
literal|'2'
block|,
comment|/* 15 - 19 */
literal|'3'
block|,
literal|'4'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'='
block|,
comment|/* 20 - 24 */
literal|'9'
block|,
literal|'7'
block|,
literal|'-'
block|,
literal|'8'
block|,
literal|'0'
block|,
comment|/* 25 - 29 */
literal|']'
block|,
literal|'O'
block|,
literal|'u'
block|,
literal|'['
block|,
literal|'i'
block|,
comment|/* 30 - 34 */
literal|'p'
block|,
name|RET
block|,
literal|'l'
block|,
literal|'j'
block|,
literal|'\''
block|,
comment|/* 35 - 39 */
literal|'k'
block|,
literal|';'
block|,
literal|'\\'
block|,
literal|','
block|,
literal|'/'
block|,
comment|/* 40 - 44 */
literal|'n'
block|,
literal|'m'
block|,
literal|'.'
block|,
name|TAB
block|,
name|NOKEY
block|,
comment|/* 45 - 49 */
literal|'`'
block|,
name|BACKSP
block|,
name|ENTERL
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 50 - 54 */
name|COMMAND
block|,
name|SHIFT
block|,
name|CAPSLOCK
block|,
name|OPTION
block|,
name|NOKEY
block|,
comment|/* 55 - 59 */
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 60 - 64 */
name|PADDOT
block|,
name|RIGHTCURS
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 65 - 69 */
name|LEFTCURS
block|,
name|CLEAR
block|,
name|DOWNCURS
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 70 - 74 */
name|NOKEY
block|,
name|PADENTER
block|,
name|UPCURS
block|,
name|PADMINUS
block|,
name|NOKEY
block|,
comment|/* 75 - 79 */
name|NOKEY
block|,
name|NOKEY
block|,
name|PAD0
block|,
name|PAD1
block|,
name|PAD2
block|,
comment|/* 80 - 84 */
name|PAD3
block|,
name|PAD4
block|,
name|PAD5
block|,
name|PAD6
block|,
name|PAD7
block|,
comment|/* 85 - 89 */
name|NOKEY
block|,
name|PAD8
block|,
name|PAD9
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|sh_keycodes
index|[]
init|=
block|{
literal|'A'
block|,
literal|'S'
block|,
literal|'D'
block|,
literal|'F'
block|,
literal|'H'
block|,
comment|/* 0 - 4 */
literal|'G'
block|,
literal|'Z'
block|,
literal|'X'
block|,
literal|'C'
block|,
literal|'V'
block|,
comment|/* 5 - 9 */
name|NOKEY
block|,
literal|'B'
block|,
literal|'Q'
block|,
literal|'W'
block|,
literal|'E'
block|,
comment|/* 10 - 14 */
literal|'R'
block|,
literal|'Y'
block|,
literal|'T'
block|,
literal|'!'
block|,
literal|'@'
block|,
comment|/* 15 - 19 */
literal|'#'
block|,
literal|'$'
block|,
literal|'^'
block|,
literal|'%'
block|,
literal|'+'
block|,
comment|/* 20 - 24 */
literal|'('
block|,
literal|'&'
block|,
literal|'_'
block|,
literal|'*'
block|,
literal|')'
block|,
comment|/* 25 - 29 */
literal|'}'
block|,
literal|'O'
block|,
literal|'U'
block|,
literal|'{'
block|,
literal|'I'
block|,
comment|/* 30 - 34 */
literal|'P'
block|,
name|RET
block|,
literal|'L'
block|,
literal|'J'
block|,
literal|'\''
block|,
comment|/* 35 - 39 */
literal|'K'
block|,
literal|';'
block|,
literal|'|'
block|,
literal|'<'
block|,
literal|'?'
block|,
comment|/* 40 - 44 */
literal|'N'
block|,
literal|'M'
block|,
literal|'>'
block|,
name|TAB
block|,
name|NOKEY
block|,
comment|/* 45 - 49 */
literal|'~'
block|,
name|BACKSP
block|,
name|ENTERL
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 50 - 54 */
name|COMMAND
block|,
name|SHIFT
block|,
name|CAPSLOCK
block|,
name|OPTION
block|,
name|NOKEY
block|,
comment|/* 55 - 59 */
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 60 - 64 */
name|PADDOT
block|,
name|RIGHTCURS
block|,
name|NOKEY
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 65 - 69 */
name|LEFTCURS
block|,
name|CLEAR
block|,
name|DOWNCURS
block|,
name|NOKEY
block|,
name|NOKEY
block|,
comment|/* 70 - 74 */
name|NOKEY
block|,
name|PADENTER
block|,
name|UPCURS
block|,
name|PADMINUS
block|,
name|NOKEY
block|,
comment|/* 75 - 79 */
name|NOKEY
block|,
name|NOKEY
block|,
name|PAD0
block|,
name|PAD1
block|,
name|PAD2
block|,
comment|/* 80 - 84 */
name|PAD3
block|,
name|PAD4
block|,
name|PAD5
block|,
name|PAD6
block|,
name|PAD7
block|,
comment|/* 85 - 89 */
name|NOKEY
block|,
name|PAD8
block|,
name|PAD9
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tn.h Modified for variable screen size 11/21/87. K. Mitchum */
end_comment

begin_define
define|#
directive|define
name|SCREENSIZE
value|(wc->w_rows * ROWSIZE)
end_define

begin_define
define|#
directive|define
name|FONT
value|monaco
end_define

begin_define
define|#
directive|define
name|TEXTSIZE
value|9
end_define

begin_define
define|#
directive|define
name|HEIGHT
value|11
end_define

begin_define
define|#
directive|define
name|WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|DESCENT
value|2
end_define

begin_define
define|#
directive|define
name|TWIDTH
value|CO * WIDTH
end_define

begin_define
define|#
directive|define
name|THEIGHT
value|LI * HEIGHT
end_define

begin_comment
comment|/* window specs */
end_comment

begin_define
define|#
directive|define
name|SCROLLWIDTH
value|16
end_define

begin_comment
comment|/* width of scroll bar control in pixels */
end_comment

begin_define
define|#
directive|define
name|WINDWIDTH
value|(wc->w_width - SCROLLWIDTH + 1)
end_define

begin_comment
comment|/* local coordinates */
end_comment

begin_define
define|#
directive|define
name|WINDHEIGHT
value|(wc->w_height)
end_define

begin_comment
comment|/* local coordinates */
end_comment

begin_define
define|#
directive|define
name|MAXROW
value|(LI - 1)
end_define

begin_define
define|#
directive|define
name|MAXCOL
value|(CO - 1)
end_define

begin_comment
comment|/* for keyboard routines */
end_comment

begin_define
define|#
directive|define
name|MCHARS
value|32
end_define

begin_comment
comment|/* must be power of two */
end_comment

begin_define
define|#
directive|define
name|NMASK
value|MCHARS (-1)
end_define

begin_comment
comment|/* circular buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _mac */
end_comment

end_unit

