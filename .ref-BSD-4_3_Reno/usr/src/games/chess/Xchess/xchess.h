begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file contains code for X-CHESS.    Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of X-CHESS.  X-CHESS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the X-CHESS General Public License for full details.  Everyone is granted permission to copy, modify and redistribute X-CHESS, but only under the conditions described in the X-CHESS General Public License.   A copy of this license is supposed to have been given to you along with X-CHESS so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* RCS Info: $Revision: 1.5 $ on $Date: 86/11/26 12:11:39 $  *           $Source: /users/faustus/xchess/RCS/xchess.h,v $  * Copyright (c) 1986 Wayne A. Christopher, U. C. Berkeley CAD Group  *	Permission is granted to do anything with this code except sell it  *	or remove this message.  *  * Definitions for the X chess program.  */
end_comment

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|"scrollText/scrollText.h"
end_include

begin_define
define|#
directive|define
name|SIZE
value|8
end_define

begin_typedef
typedef|typedef
enum|enum
name|piecetype
block|{
name|PAWN
block|,
name|ROOK
block|,
name|KNIGHT
block|,
name|BISHOP
block|,
name|QUEEN
block|,
name|KING
block|}
name|piecetype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|movetype
block|{
name|MOVE
block|,
name|QCASTLE
block|,
name|KCASTLE
block|,
name|CAPTURE
block|}
name|movetype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|color
block|{
name|WHITE
block|,
name|BLACK
block|,
name|NONE
block|}
name|color
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|piece
block|{
name|enum
name|piecetype
name|type
decl_stmt|;
name|enum
name|color
name|color
decl_stmt|;
block|}
name|piece
typedef|;
end_typedef

begin_comment
comment|/* The board has y=0 and black at the top...  This probably isn't the best  * place to keep track of who can castle, but it's part of the game state...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|board
block|{
name|piece
name|square
index|[
name|SIZE
index|]
index|[
name|SIZE
index|]
decl_stmt|;
name|bool
name|white_cant_castle_k
decl_stmt|;
name|bool
name|white_cant_castle_q
decl_stmt|;
name|bool
name|black_cant_castle_k
decl_stmt|;
name|bool
name|black_cant_castle_q
decl_stmt|;
block|}
name|board
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|move
block|{
name|movetype
name|type
decl_stmt|;
name|piece
name|piece
decl_stmt|;
name|piece
name|taken
decl_stmt|;
name|int
name|fromx
decl_stmt|,
name|fromy
decl_stmt|;
name|int
name|tox
decl_stmt|,
name|toy
decl_stmt|;
name|struct
name|move
modifier|*
name|next
decl_stmt|;
name|bool
name|enpassant
decl_stmt|;
name|bool
name|check
decl_stmt|;
block|}
name|move
typedef|;
end_typedef

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|win
parameter_list|,
name|i
parameter_list|,
name|j
parameter_list|)
value|(!(((i) + (j)) % 2))
end_define

begin_comment
comment|/* Stuff for the display. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|windata
block|{
name|Display
modifier|*
name|display
decl_stmt|;
name|Window
name|basewin
decl_stmt|;
name|Window
name|boardwin
decl_stmt|;
name|Window
name|recwin
decl_stmt|;
name|Window
name|wclockwin
decl_stmt|;
name|Window
name|bclockwin
decl_stmt|;
name|Window
name|messagewin
decl_stmt|;
name|Window
name|buttonwin
decl_stmt|;
name|Window
name|jailwin
decl_stmt|;
name|Window
name|icon
decl_stmt|;
name|Pixmap
name|iconpixmap
decl_stmt|;
name|XColor
name|blackpiece
decl_stmt|;
name|XColor
name|whitepiece
decl_stmt|;
name|XColor
name|blacksquare
decl_stmt|;
name|XColor
name|whitesquare
decl_stmt|;
name|XColor
name|border
decl_stmt|;
name|XColor
name|textcolor
decl_stmt|;
name|XColor
name|textback
decl_stmt|;
name|XColor
name|errortext
decl_stmt|;
name|XColor
name|playertext
decl_stmt|;
name|XColor
name|cursorcolor
decl_stmt|;
name|XFontStruct
modifier|*
name|small
decl_stmt|;
name|XFontStruct
modifier|*
name|medium
decl_stmt|;
name|XFontStruct
modifier|*
name|large
decl_stmt|;
name|bool
name|bnw
decl_stmt|;
name|color
name|color
decl_stmt|;
name|bool
name|flipped
decl_stmt|;
name|double
name|whitehands
index|[
literal|3
index|]
decl_stmt|;
name|double
name|blackhands
index|[
literal|3
index|]
decl_stmt|;
name|char
modifier|*
name|txtassoc
decl_stmt|;
block|}
name|windata
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SMALL_FONT
value|"6x10"
end_define

begin_define
define|#
directive|define
name|MEDIUM_FONT
value|"8x13"
end_define

begin_define
define|#
directive|define
name|LARGE_FONT
value|"9x15"
end_define

begin_define
define|#
directive|define
name|JAIL_FONT
value|"6x10"
end_define

begin_define
define|#
directive|define
name|SQUARE_WIDTH
value|80
end_define

begin_define
define|#
directive|define
name|SQUARE_HEIGHT
value|80
end_define

begin_define
define|#
directive|define
name|BORDER_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|BOARD_WIDTH
value|8 * SQUARE_WIDTH + 7 * BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|BOARD_HEIGHT
value|8 * SQUARE_HEIGHT + 7 * BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|BOARD_XPOS
value|0
end_define

begin_define
define|#
directive|define
name|BOARD_YPOS
value|0
end_define

begin_define
define|#
directive|define
name|RECORD_WIDTH
value|265
end_define

begin_comment
comment|/* 40 chars * 6 pixels / character. */
end_comment

begin_define
define|#
directive|define
name|RECORD_HEIGHT
value|433
end_define

begin_define
define|#
directive|define
name|RECORD_XPOS
value|BOARD_WIDTH + BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|RECORD_YPOS
value|0
end_define

begin_define
define|#
directive|define
name|JAIL_WIDTH
value|RECORD_WIDTH
end_define

begin_define
define|#
directive|define
name|JAIL_HEIGHT
value|163
end_define

begin_define
define|#
directive|define
name|JAIL_XPOS
value|RECORD_XPOS
end_define

begin_define
define|#
directive|define
name|JAIL_YPOS
value|RECORD_YPOS + RECORD_HEIGHT + BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|CLOCK_WIDTH
value|131
end_define

begin_define
define|#
directive|define
name|CLOCK_HEIGHT
value|131 + BORDER_WIDTH + 20
end_define

begin_define
define|#
directive|define
name|WCLOCK_XPOS
value|RECORD_XPOS
end_define

begin_define
define|#
directive|define
name|WCLOCK_YPOS
value|RECORD_HEIGHT + JAIL_HEIGHT + BORDER_WIDTH * 2
end_define

begin_define
define|#
directive|define
name|BCLOCK_XPOS
value|WCLOCK_XPOS + CLOCK_WIDTH + BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|BCLOCK_YPOS
value|WCLOCK_YPOS
end_define

begin_define
define|#
directive|define
name|MESS_WIDTH
value|329
end_define

begin_define
define|#
directive|define
name|MESS_HEIGHT
value|92
end_define

begin_define
define|#
directive|define
name|MESS_XPOS
value|0
end_define

begin_define
define|#
directive|define
name|MESS_YPOS
value|BOARD_HEIGHT + BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|BUTTON_WIDTH
value|MESS_WIDTH
end_define

begin_define
define|#
directive|define
name|BUTTON_HEIGHT
value|MESS_HEIGHT
end_define

begin_define
define|#
directive|define
name|BUTTON_XPOS
value|MESS_WIDTH + BORDER_WIDTH
end_define

begin_define
define|#
directive|define
name|BUTTON_YPOS
value|MESS_YPOS
end_define

begin_define
define|#
directive|define
name|BASE_WIDTH
value|BOARD_WIDTH + RECORD_WIDTH + BORDER_WIDTH * 3
end_define

begin_define
define|#
directive|define
name|BASE_HEIGHT
value|BOARD_HEIGHT + MESS_HEIGHT + BORDER_WIDTH * 3
end_define

begin_define
define|#
directive|define
name|BASE_XPOS
value|50
end_define

begin_define
define|#
directive|define
name|BASE_YPOS
value|50
end_define

begin_define
define|#
directive|define
name|BLACK_PIECE_COLOR
value|"#202020"
end_define

begin_define
define|#
directive|define
name|WHITE_PIECE_COLOR
value|"#FFFFCC"
end_define

begin_define
define|#
directive|define
name|BLACK_SQUARE_COLOR
value|"#77A26D"
end_define

begin_define
define|#
directive|define
name|WHITE_SQUARE_COLOR
value|"#C8C365"
end_define

begin_define
define|#
directive|define
name|BORDER_COLOR
value|"#902E39"
end_define

begin_define
define|#
directive|define
name|TEXT_COLOR
value|"#006D6D"
end_define

begin_define
define|#
directive|define
name|TEXT_BACK
value|"#FFFFDD"
end_define

begin_define
define|#
directive|define
name|ERROR_TEXT
value|"Red"
end_define

begin_define
define|#
directive|define
name|PLAYER_TEXT
value|"Blue"
end_define

begin_define
define|#
directive|define
name|CURSOR_COLOR
value|"#FF606F"
end_define

begin_define
define|#
directive|define
name|DEF_RECORD_FILE
value|"xchess.game"
end_define

begin_define
define|#
directive|define
name|NUM_FLASHES
value|5
end_define

begin_define
define|#
directive|define
name|FLASH_SIZE
value|10
end_define

begin_comment
comment|/* xchess.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|proghost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|piecenames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|colornames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|movetypenames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dispname1
decl_stmt|,
modifier|*
name|dispname2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|oneboard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|bnwflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|progflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|blackflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|quickflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_flashes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flash_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|black_piece_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|white_piece_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|black_square_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|white_square_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|border_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|text_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|text_back
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|error_text
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|player_text
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cursor_color
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* board.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|board_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|board_drawall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|board_move
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|board
modifier|*
name|chessboard
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|board_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* window.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|win_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_redraw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_restart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_drawboard
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_drawpiece
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_erasepiece
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_process
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|win_flash
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|windata
modifier|*
name|win1
decl_stmt|,
modifier|*
name|win2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|win_flashmove
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* control.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|button_pressed
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|button_released
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|move_piece
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prog_move
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|move
modifier|*
name|moves
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|move
modifier|*
name|foremoves
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|color
name|nexttomove
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|replay
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restart
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|noisyflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* valid.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|valid_move
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* record.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|record_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_reset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_back
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_end
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|record_english
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|record_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|movenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|saveflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* message.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|message_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|message_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|message_send
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clock.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|clock_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clock_draw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clock_update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clock_switch
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|clock_started
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|movesperunit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timeunit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|whiteseconds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|blackseconds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* button.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|button_draw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|button_service
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* jail.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|jail_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|jail_draw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|jail_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|jail_remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* program.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|program_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|program_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|program_send
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|program_undo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|move
modifier|*
name|program_get
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* parse.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|load_game
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|move
modifier|*
name|parse_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|move
modifier|*
name|parse_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|move
modifier|*
name|parse_imove
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|loading_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|loading_paused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* popup.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|pop_question
parameter_list|()
function_decl|;
end_function_decl

end_unit

