begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/*	Copyright	Massachusetts Institute of Technology	1984, 1985 */
end_comment

begin_comment
comment|/* ptyx.h */
end_comment

begin_define
define|#
directive|define
name|MAX_COLS
value|200
end_define

begin_define
define|#
directive|define
name|MAX_ROWS
value|128
end_define

begin_comment
comment|/*  * The origin of a screen is 0, 0.  Therefore, the number of rows  * on a screen is screen->max_row + 1, and similarly for columns.  */
end_comment

begin_typedef
typedef|typedef
name|short
modifier|*
modifier|*
name|ScrnBuf
typedef|;
end_typedef

begin_comment
comment|/*  * ANSI emulation.  */
end_comment

begin_define
define|#
directive|define
name|INQ
value|0x05
end_define

begin_define
define|#
directive|define
name|FF
value|0x0C
end_define

begin_comment
comment|/* C0, C1 control names		*/
end_comment

begin_define
define|#
directive|define
name|LS1
value|0x0E
end_define

begin_define
define|#
directive|define
name|LS0
value|0x0F
end_define

begin_define
define|#
directive|define
name|CAN
value|0x18
end_define

begin_define
define|#
directive|define
name|SUB
value|0x1A
end_define

begin_define
define|#
directive|define
name|ESC
value|0x1B
end_define

begin_define
define|#
directive|define
name|US
value|0x1F
end_define

begin_define
define|#
directive|define
name|DEL
value|0x7F
end_define

begin_define
define|#
directive|define
name|SS2
value|0x8E
end_define

begin_define
define|#
directive|define
name|SS3
value|0x8F
end_define

begin_define
define|#
directive|define
name|DCS
value|0x90
end_define

begin_define
define|#
directive|define
name|OLDID
value|0x9A
end_define

begin_comment
comment|/* ESC Z			*/
end_comment

begin_define
define|#
directive|define
name|CSI
value|0x9B
end_define

begin_define
define|#
directive|define
name|ST
value|0x9C
end_define

begin_define
define|#
directive|define
name|OSC
value|0x9D
end_define

begin_define
define|#
directive|define
name|PM
value|0x9E
end_define

begin_define
define|#
directive|define
name|APC
value|0x9F
end_define

begin_define
define|#
directive|define
name|RDEL
value|0xFF
end_define

begin_define
define|#
directive|define
name|NPARAM
value|10
end_define

begin_comment
comment|/* Max. parameters		*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|a_type
decl_stmt|;
name|unsigned
name|char
name|a_pintro
decl_stmt|;
name|unsigned
name|char
name|a_final
decl_stmt|;
name|unsigned
name|char
name|a_inters
decl_stmt|;
name|char
name|a_nparam
decl_stmt|;
comment|/* # of parameters		*/
name|char
name|a_dflt
index|[
name|NPARAM
index|]
decl_stmt|;
comment|/* Default value flags		*/
name|short
name|a_param
index|[
name|NPARAM
index|]
decl_stmt|;
comment|/* Parameters			*/
name|char
name|a_nastyf
decl_stmt|;
comment|/* Error flag			*/
block|}
name|ANSI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|row
decl_stmt|;
name|int
name|col
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
comment|/* Vt100 saves graphics rendition. Ugh! */
block|}
name|SavedCursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Window
name|window
decl_stmt|;
comment|/* X window for screen		*/
name|Window
name|iconwindow
decl_stmt|;
comment|/* window for icon		*/
name|Bitmap
name|iconmask
decl_stmt|;
comment|/* mask for icon outline	*/
name|int
name|border
decl_stmt|;
comment|/* inner border			*/
name|int
name|borderwidth
decl_stmt|;
comment|/* outer border	    	    	*/
name|int
name|width
decl_stmt|;
comment|/* width of window - borders (pixels)*/
name|int
name|height
decl_stmt|;
comment|/* height of window -borders (pixels)*/
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* X display for screen		*/
name|int
name|respond
decl_stmt|;
comment|/* socket for responses 					   (position report, etc.)	*/
comment|/* Terminal fonts must be of the same size and of fixed width */
name|Font
name|fnt_norm
decl_stmt|;
comment|/* normal font of terminal	*/
name|Font
name|fnt_bold
decl_stmt|;
comment|/* bold font of terminal	*/
name|int
name|f_width
decl_stmt|;
comment|/* width of fonts in pixels	*/
name|int
name|f_height
decl_stmt|;
comment|/* height of fonts in pixels	*/
name|int
name|cur_col
decl_stmt|;
comment|/* current cursor column	*/
name|int
name|cur_row
decl_stmt|;
comment|/* current cursor row		*/
name|int
name|max_col
decl_stmt|;
comment|/* rightmost column		*/
name|int
name|max_row
decl_stmt|;
comment|/* bottom row			*/
name|int
name|top_marg
decl_stmt|;
comment|/* top line of scrolling region */
name|int
name|bot_marg
decl_stmt|;
comment|/* bottom line of  "	    "	*/
name|ScrnBuf
name|buf
decl_stmt|;
comment|/* screen buffer		*/
name|Bitmap
name|cursor
decl_stmt|;
comment|/* cursor bits			*/
name|Bitmap
name|mask
decl_stmt|;
comment|/* mask cursor bits		*/
name|Cursor
name|curs
decl_stmt|;
comment|/* cursor resource from X	*/
name|Cursor
name|rcurs
decl_stmt|;
comment|/* reverse version of cursor	*/
name|int
name|foreground
decl_stmt|;
comment|/* foreground color		*/
name|int
name|background
decl_stmt|;
comment|/* Background color		*/
name|int
name|cursorcolor
decl_stmt|;
comment|/* Cursor color			*/
name|int
name|mousecolor
decl_stmt|;
comment|/* Mouse color			*/
name|Pixmap
name|bordertile
decl_stmt|;
comment|/* tile pixmap for border	*/
name|Pixmap
name|bgndtile
decl_stmt|;
comment|/* background tile pixmap	*/
name|unsigned
name|xorplane
decl_stmt|;
comment|/* z plane for inverts		*/
name|unsigned
name|short
name|do_wrap
decl_stmt|;
comment|/* true if cursor in last column 					   and character just output    */
name|short
name|incopy
decl_stmt|;
comment|/* 0 if no RasterCopy exposure 					   event processed since last 					   RasterCopy			*/
ifdef|#
directive|ifdef
name|CROCKSCROLL
name|short
name|scrollincr
decl_stmt|;
comment|/* scroll increment		*/
endif|#
directive|endif
name|unsigned
name|short
name|multiscroll
decl_stmt|;
comment|/* true if multi-scroll		*/
name|int
name|scrolls
decl_stmt|;
comment|/* outstanding scroll count	*/
name|SavedCursor
name|sc
decl_stmt|;
comment|/* data for restore cursor	*/
name|long
name|pid
decl_stmt|;
comment|/* pid of process on far side   */
comment|/* Improved VT100 emulation stuff.				*/
name|ANSI
name|ansi
decl_stmt|;
comment|/* ANSI parsing variables.	*/
name|char
name|gsets
index|[
literal|4
index|]
decl_stmt|;
comment|/* G0 through G3.		*/
name|char
name|curgl
decl_stmt|;
comment|/* Current GL setting.		*/
name|char
name|curgr
decl_stmt|;
comment|/* Current GR setting.		*/
name|char
name|curss
decl_stmt|;
comment|/* Current single shift.	*/
name|char
name|rx8bit
decl_stmt|;
comment|/* TRUE if Rx is 8 bit.		*/
name|char
name|tx8bit
decl_stmt|;
comment|/* TRUE if Tx is 8 bit.		*/
comment|/* Tektronix plotting information */
name|int
name|TekEmu
decl_stmt|;
comment|/* true if Tektronix emulation	*/
name|int
name|cur_X
decl_stmt|;
comment|/* current screen x		*/
name|int
name|cur_Y
decl_stmt|;
comment|/* current screen y		*/
name|int
name|cur_x
decl_stmt|;
comment|/* current Tektronix x		*/
name|int
name|cur_y
decl_stmt|;
comment|/* current Tektronix y		*/
name|int
name|pen
decl_stmt|;
comment|/* current Tektronix pen 0=up, 1=dn */
name|double
name|TekScale
decl_stmt|;
comment|/* scale factor Tek -> vs100	*/
name|int
name|TekGMode
decl_stmt|;
comment|/* plot mode switch		*/
name|int
name|TekAMode
decl_stmt|;
comment|/* alpha after plot mode switch */
name|int
name|TekIMode
decl_stmt|;
comment|/* incremental plot mode switch */
name|int
name|TekPMode
decl_stmt|;
comment|/* point plot mode switch	*/
ifdef|#
directive|ifdef
name|JUMPSCROLL
name|int
name|scroll_amt
decl_stmt|;
comment|/* amount to scroll		*/
name|int
name|refresh_amt
decl_stmt|;
comment|/* amount to refresh		*/
name|int
name|jumpscroll
decl_stmt|;
comment|/* whether we should jumpscroll */
endif|#
directive|endif
endif|JUMPSCROLL
name|int
function_decl|(
modifier|*
name|mode
function_decl|)
parameter_list|()
function_decl|;
comment|/* this will be THE mode	*/
name|unsigned
name|short
name|send_mouse_pos
decl_stmt|;
comment|/* user wants mouse transition  */
comment|/* and position information	*/
block|}
name|Screen
typedef|;
end_typedef

begin_comment
comment|/* meaning of bits for entries in screen buffer */
end_comment

begin_define
define|#
directive|define
name|CHAR
value|0177
end_define

begin_define
define|#
directive|define
name|BOLDbit
value|0200
end_define

begin_define
define|#
directive|define
name|INVERSEbit
value|0400
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|offset
decl_stmt|;
comment|/* status of shift, control, meta */
define|#
directive|define
name|SHIFT
value|0x0001
define|#
directive|define
name|META
value|0x0002
define|#
directive|define
name|CONTROL
value|0x0004
name|unsigned
name|flags
decl_stmt|;
block|}
name|Keyboard
typedef|;
end_typedef

begin_comment
comment|/* define masks for flags */
end_comment

begin_define
define|#
directive|define
name|CAPS_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|KYPD_APL
value|0x02
end_define

begin_define
define|#
directive|define
name|CURSOR_APL
value|0x04
end_define

begin_define
define|#
directive|define
name|MAX_TABS
value|320
end_define

begin_define
define|#
directive|define
name|TAB_ARRAY_SIZE
value|10
end_define

begin_comment
comment|/* number of ints to provide MAX_TABS bits */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|Tabs
index|[
name|TAB_ARRAY_SIZE
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUF_SIZE
value|4096
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cnt
decl_stmt|;
comment|/* count of char's left in buf	*/
name|unsigned
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* pointer to next char in buf	*/
name|unsigned
name|char
name|buf
index|[
name|BUF_SIZE
index|]
decl_stmt|;
comment|/* buffer			*/
name|int
name|fildes
decl_stmt|;
comment|/* file descriptor to read from	*/
block|}
name|Buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Keyboard
name|keyboard
decl_stmt|;
comment|/* terminal keyboard		*/
name|Screen
name|screen
decl_stmt|;
comment|/* terminal screeen		*/
name|Buffer
name|buf
decl_stmt|;
comment|/* buffer for data to process	*/
name|unsigned
name|flags
decl_stmt|;
comment|/* mode flags			*/
name|Tabs
name|tabs
decl_stmt|;
comment|/* tabstops of the terminal	*/
block|}
name|Terminal
typedef|;
end_typedef

begin_comment
comment|/* masks for terminal flags */
end_comment

begin_define
define|#
directive|define
name|INVERSE
value|0x01
end_define

begin_comment
comment|/* invert the characters to be output */
end_comment

begin_define
define|#
directive|define
name|LINEFEED
value|0x02
end_define

begin_define
define|#
directive|define
name|BOLD
value|0x04
end_define

begin_define
define|#
directive|define
name|WRAPAROUND
value|0x08
end_define

begin_define
define|#
directive|define
name|REVERSE_VIDEO
value|0x10
end_define

begin_comment
comment|/* true if screen white on black */
end_comment

begin_define
define|#
directive|define
name|ORIGIN
value|0x20
end_define

begin_comment
comment|/* true if in origin mode */
end_comment

begin_define
define|#
directive|define
name|INSERT
value|0x40
end_define

begin_comment
comment|/* true if in insert mode */
end_comment

begin_define
define|#
directive|define
name|SMOOTHSCROLL
value|0x80
end_define

begin_comment
comment|/* true if in smooth scroll mode */
end_comment

begin_comment
comment|/* must be a power of two */
end_comment

begin_define
define|#
directive|define
name|TEK_LINK_BLOCK_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
name|_TekLink
block|{
name|struct
name|_TekLink
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next TekLink in list 				   NULL<=> this is last TekLink */
name|unsigned
name|char
name|data
index|[
name|TEK_LINK_BLOCK_SIZE
index|]
decl_stmt|;
block|}
name|TekLink
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TekBufPut
parameter_list|(
name|chr
parameter_list|)
define|\
comment|/* if out of memory malloc some more */
define|\
value|{							\ 		if (tb_end& TEK_LINK_BLOCK_SIZE)		\ 			TekBufExtend ();			\ 		tb_end_link->data [tb_end++] = chr;		\ 	}
end_define

begin_define
define|#
directive|define
name|CursorX
parameter_list|(
name|screen
parameter_list|)
value|(screen->cur_col * screen->f_width + screen->border)
end_define

begin_define
define|#
directive|define
name|CursorY
parameter_list|(
name|screen
parameter_list|)
value|(screen->cur_row * screen->f_height + screen->border)
end_define

begin_comment
comment|/*  * To handle Tektronix plotting well, add graphics cursor position  * to get correct position for characters on the screen.  * screen->border is taken into account in screen->cur[XY]  */
end_comment

begin_define
define|#
directive|define
name|TCursorX
parameter_list|(
name|screen
parameter_list|)
value|(screen->cur_X)
end_define

begin_define
define|#
directive|define
name|TCursorY
parameter_list|(
name|screen
parameter_list|)
value|(screen->cur_Y - screen->f_height)
end_define

begin_function_decl
name|int
name|ANSInormal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ANSIparse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ANSIstring
parameter_list|()
function_decl|;
end_function_decl

end_unit

