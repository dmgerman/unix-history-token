begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/ptyx.h,v $  *	$Header: ptyx.h,v 10.101 86/12/01 16:57:15 swick Rel $  */
end_comment

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

begin_comment
comment|/* @(#)ptyx.h	1.4 (Berkeley/CSRG) 9/17/87 */
end_comment

begin_comment
comment|/* @(#)ptyx.h       X10/6.6B 12/26/86 */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

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
name|char
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
name|HTS
value|('H'+0x40)
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
name|NBOX
value|5
end_define

begin_comment
comment|/* Number of Vertices in box	*/
end_comment

begin_define
define|#
directive|define
name|NPARAM
value|10
end_define

begin_comment
comment|/* Max. parameters		*/
end_comment

begin_define
define|#
directive|define
name|MINHILITE
value|32
end_define

begin_define
define|#
directive|define
name|TITLEPAD
value|4
end_define

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
name|char
name|curgl
decl_stmt|;
name|char
name|curgr
decl_stmt|;
name|char
name|gsets
index|[
literal|4
index|]
decl_stmt|;
block|}
name|SavedCursor
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TEKNUMFONTS
value|5
end_define

begin_comment
comment|/* Actually there are 5 types of lines, but four are non-solid lines */
end_comment

begin_define
define|#
directive|define
name|TEKNUMLINES
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|fontsize
decl_stmt|;
name|int
name|linetype
decl_stmt|;
block|}
name|Tmodes
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|Twidth
decl_stmt|;
name|int
name|Theight
decl_stmt|;
block|}
name|T_fontsize
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Window
name|tbar
decl_stmt|;
comment|/* major window			*/
name|Window
name|left
decl_stmt|;
comment|/* left hilited window		*/
name|Window
name|right
decl_stmt|;
comment|/* right hilited window		*/
name|int
name|hilited
decl_stmt|;
comment|/* in hilite state		*/
name|int
name|x
decl_stmt|;
comment|/* x position of title		*/
name|int
name|y
decl_stmt|;
comment|/* y position of title		*/
name|int
name|fullwidth
decl_stmt|;
comment|/* full width of title		*/
name|int
name|width
decl_stmt|;
comment|/* width of visible part of title */
block|}
name|TitleBar
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
modifier|*
name|bits
decl_stmt|;
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
block|}
name|BitmapBits
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* These parameters apply to both windows */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* X display for screen		*/
name|int
name|respond
decl_stmt|;
comment|/* socket for responses 					   (position report, etc.)	*/
name|long
name|pid
decl_stmt|;
comment|/* pid of process on far side   */
name|int
name|uid
decl_stmt|;
comment|/* user id of actual person	*/
name|int
name|gid
decl_stmt|;
comment|/* group id of actual person	*/
name|int
name|color
decl_stmt|;
comment|/* colors used			*/
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
name|bgndtile
decl_stmt|;
comment|/* background tile pixmap	*/
name|int
name|border
decl_stmt|;
comment|/* inner border			*/
name|int
name|borderwidth
decl_stmt|;
comment|/* outer border	    	    	*/
name|Pixmap
name|bordertile
decl_stmt|;
comment|/* tile pixmap for border	*/
name|Pixmap
name|graybordertile
decl_stmt|;
comment|/* tile pixmap for border when 						window is unselected	*/
name|Cursor
name|arrow
decl_stmt|;
comment|/* arrow cursor			*/
name|int
name|send_mouse_pos
decl_stmt|;
comment|/* user wants mouse transition  */
comment|/* and position information	*/
name|int
name|select
decl_stmt|;
comment|/* xterm selected		*/
name|struct
name|timeval
modifier|*
name|timeout
decl_stmt|;
comment|/* timeout value for select	*/
name|FontInfo
modifier|*
name|titlefont
decl_stmt|;
comment|/* font info for title font	*/
name|int
name|titleheight
decl_stmt|;
comment|/* height of title		*/
name|int
name|title_n_size
decl_stmt|;
comment|/* width on 'n' in title font	*/
name|Pixmap
name|hilitetile
decl_stmt|;
comment|/* tile pixmap for title hilite	*/
name|int
name|autoraise
decl_stmt|;
comment|/* auto raise window mode	*/
name|Window
name|autowindow
decl_stmt|;
comment|/* the window to autoraise	*/
name|int
name|timer
decl_stmt|;
comment|/* timer function		*/
name|int
name|holdoff
decl_stmt|;
comment|/* delay select and unselects	*/
name|int
name|audiblebell
decl_stmt|;
comment|/* audible bell mode		*/
name|int
name|visualbell
decl_stmt|;
comment|/* visual bell mode		*/
name|int
name|visbelldelay
decl_stmt|;
comment|/* visual bell delay		*/
name|int
name|icon_show
decl_stmt|;
comment|/* icon currently showing	*/
name|int
name|textundericon
decl_stmt|;
comment|/* text under icon              */
name|int
name|bitmapwidth
decl_stmt|;
comment|/* width of icon bitmap         */
name|int
name|bitmapheight
decl_stmt|;
comment|/* height of icon bitmap        */
name|int
name|icon_text_x
decl_stmt|;
comment|/* x position of text           */
name|int
name|icon_text_y
decl_stmt|;
comment|/* y position of text           */
name|BitmapBits
name|iconbitmap
decl_stmt|;
comment|/* bitmap for icon		*/
name|int
name|iconinput
decl_stmt|;
comment|/* got input while iconified    */
name|int
name|active_icon
decl_stmt|;
comment|/* icon is miniature copy	*/
name|int
name|deiconwarp
decl_stmt|;
comment|/* warp mouse on deiconify	*/
name|int
name|logging
decl_stmt|;
comment|/* logging mode			*/
name|int
name|logfd
decl_stmt|;
comment|/* file descriptor of log	*/
name|char
modifier|*
name|logfile
decl_stmt|;
comment|/* log file name		*/
name|char
modifier|*
name|logstart
decl_stmt|;
comment|/* current start of log buffer	*/
name|int
name|inhibit
decl_stmt|;
comment|/* flags for inhibiting changes	*/
comment|/* VT window parameters */
name|int
name|show
decl_stmt|;
comment|/* window showing		*/
name|int
name|iconunmap
decl_stmt|;
comment|/* unmapped because of icon	*/
struct|struct
block|{
name|Window
name|window
decl_stmt|;
comment|/* X window id			*/
name|int
name|width
decl_stmt|;
comment|/* width of columns		*/
name|int
name|height
decl_stmt|;
comment|/* height of rows		*/
name|int
name|fullwidth
decl_stmt|;
comment|/* full width of window		*/
name|int
name|fullheight
decl_stmt|;
comment|/* full height of window	*/
name|int
name|f_width
decl_stmt|;
comment|/* width of fonts in pixels	*/
name|int
name|f_height
decl_stmt|;
comment|/* height of fonts in pixels	*/
name|int
name|titlebar
decl_stmt|;
comment|/* title bar(s) showing		*/
block|}
name|fullVwin
struct|,
name|iconVwin
struct|,
modifier|*
name|mappedVwin
struct|;
name|Font
name|fnt_icon
decl_stmt|;
comment|/* icon font			*/
name|int
name|minrows
decl_stmt|;
comment|/* minimun number of rows to 						accommodate scrollbar	*/
name|Cursor
name|curs
decl_stmt|;
comment|/* cursor resource from X	*/
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
name|enbolden
decl_stmt|;
comment|/* overstrike for bold font	*/
name|Vertex
modifier|*
name|box
decl_stmt|;
comment|/* draw unselected cursor	*/
name|int
name|cursor_state
decl_stmt|;
comment|/* ON or OFF			*/
name|int
name|cursor_set
decl_stmt|;
comment|/* requested state		*/
name|int
name|cursor_col
decl_stmt|;
comment|/* previous cursor column	*/
name|int
name|cursor_row
decl_stmt|;
comment|/* previous cursor row		*/
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
name|int
name|scrollbar
decl_stmt|;
comment|/* if> 0, width of scrollbar, and 						scrollbar showing	*/
name|int
name|topline
decl_stmt|;
comment|/* line number of top,<= 0	*/
name|int
name|savelines
decl_stmt|;
comment|/* number of lines off top to save */
name|int
name|scrollinput
decl_stmt|;
comment|/* scroll to bottom on input	*/
name|int
name|scrollkey
decl_stmt|;
comment|/* scroll to bottom on key	*/
name|ScrnBuf
name|buf
decl_stmt|;
comment|/* screen buffer (main)		*/
name|ScrnBuf
name|allbuf
decl_stmt|;
comment|/* screen buffer (may include 					   lines scrolled off top	*/
name|ScrnBuf
name|altbuf
decl_stmt|;
comment|/* alternate screen buffer	*/
name|int
name|alternate
decl_stmt|;
comment|/* true if using alternate buf	*/
name|ScrollBar
modifier|*
name|sb
decl_stmt|;
comment|/* pointer to scrollbar struct	*/
name|int
name|do_wrap
decl_stmt|;
comment|/* true if cursor in last column 					   and character just output    */
name|int
name|incopy
decl_stmt|;
comment|/* 0 if no RasterCopy exposure 					   event processed since last 					   RasterCopy			*/
name|int
name|c132
decl_stmt|;
comment|/* allow change to 132 columns	*/
name|int
name|curses
decl_stmt|;
comment|/* cludge-ups for more and vi	*/
name|int
name|marginbell
decl_stmt|;
comment|/* true if margin bell on	*/
name|int
name|nmarginbell
decl_stmt|;
comment|/* columns from right margin	*/
name|int
name|bellarmed
decl_stmt|;
comment|/* cursor below bell margin	*/
ifdef|#
directive|ifdef
name|CROCKSCROLL
name|int
name|scrollincr
decl_stmt|;
comment|/* scroll increment		*/
endif|#
directive|endif
name|int
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
name|TitleBar
name|title
decl_stmt|;
comment|/* title bar			*/
name|int
name|statusline
decl_stmt|;
comment|/* status line showing		*/
name|int
name|statusheight
decl_stmt|;
comment|/* status line height		*/
name|int
name|instatus
decl_stmt|;
comment|/* cursor in status line	*/
name|SavedCursor
name|statussc
decl_stmt|;
comment|/* status line restore cursor	*/
name|int
name|reversestatus
decl_stmt|;
comment|/* status line reversed		*/
name|char
modifier|*
name|winname
decl_stmt|;
comment|/* name of window (and icons)	*/
name|int
name|winnamelen
decl_stmt|;
comment|/* length of window name	*/
name|int
name|save_modes
index|[
literal|19
index|]
decl_stmt|;
comment|/* save dec private modes	*/
name|int
name|pagemode
decl_stmt|;
comment|/* true if page mode		*/
name|int
name|pagecnt
decl_stmt|;
comment|/* count of lines in page mode	*/
name|int
name|pageoverlap
decl_stmt|;
comment|/* lines to overlap (less one)	*/
comment|/* Improved VT100 emulation stuff.				*/
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
comment|/* Tektronix window parameters */
name|int
name|Tforeground
decl_stmt|;
comment|/* foreground color		*/
name|int
name|Tbackground
decl_stmt|;
comment|/* Background color		*/
name|int
name|Tcursorcolor
decl_stmt|;
comment|/* Cursor color			*/
name|Pixmap
name|Tbgndtile
decl_stmt|;
comment|/* background tile pixmap	*/
name|int
name|Tcolor
decl_stmt|;
comment|/* colors used			*/
name|int
name|planeused
decl_stmt|;
comment|/* is xorplane being used	*/
name|int
name|cellsused
decl_stmt|;
comment|/* are color cells being used	*/
name|Color
name|colorcells
index|[
literal|3
index|]
decl_stmt|;
comment|/* color cells for Tek		*/
name|int
name|Tshow
decl_stmt|;
comment|/* Tek window showing		*/
name|int
name|Ticonunmap
decl_stmt|;
comment|/* unmapped because of icon	*/
name|int
name|waitrefresh
decl_stmt|;
comment|/* postpone refresh		*/
struct|struct
block|{
name|Window
name|window
decl_stmt|;
comment|/* X window id			*/
name|int
name|width
decl_stmt|;
comment|/* width of columns		*/
name|int
name|height
decl_stmt|;
comment|/* height of rows		*/
name|int
name|fullwidth
decl_stmt|;
comment|/* full width of window		*/
name|int
name|fullheight
decl_stmt|;
comment|/* full height of window	*/
name|int
name|titlebar
decl_stmt|;
comment|/* title bar(s) showing		*/
name|double
name|tekscale
decl_stmt|;
comment|/* scale factor Tek -> vs100	*/
block|}
name|fullTwin
struct|,
name|iconTwin
struct|,
modifier|*
name|mappedTwin
struct|;
name|BitmapBits
name|Ticonbitmap
decl_stmt|;
comment|/* bitmap for icon		*/
name|Vertex
modifier|*
modifier|*
name|Tbox
decl_stmt|;
comment|/* draw unselected cursor	*/
name|int
name|xorplane
decl_stmt|;
comment|/* z plane for inverts		*/
name|Pattern
name|linepat
index|[
name|TEKNUMLINES
index|]
decl_stmt|;
comment|/* line patterns		*/
name|Font
name|Tfont
index|[
name|TEKNUMFONTS
index|]
decl_stmt|;
comment|/* Tek fonts		*/
name|int
name|tobaseline
index|[
name|TEKNUMFONTS
index|]
decl_stmt|;
comment|/* top to baseline for 							each font	*/
name|int
name|TekEmu
decl_stmt|;
comment|/* true if Tektronix emulation	*/
name|int
name|cur_X
decl_stmt|;
comment|/* current x			*/
name|int
name|cur_Y
decl_stmt|;
comment|/* current y			*/
name|Tmodes
name|cur
decl_stmt|;
comment|/* current tek modes		*/
name|Tmodes
name|page
decl_stmt|;
comment|/* starting tek modes on page	*/
name|int
name|margin
decl_stmt|;
comment|/* 0 -> margin 1, 1 -> margin 2	*/
name|int
name|pen
decl_stmt|;
comment|/* current Tektronix pen 0=up, 1=dn */
name|char
modifier|*
name|TekGIN
decl_stmt|;
comment|/* nonzero if Tektronix GIN mode*/
name|TitleBar
name|Ttitle
decl_stmt|;
comment|/* title bar			*/
name|char
modifier|*
name|Twinname
decl_stmt|;
comment|/* name of window		*/
name|int
name|Twinnamelen
decl_stmt|;
comment|/* length of window name	*/
block|}
name|Screen
typedef|;
end_typedef

begin_comment
comment|/* meaning of bits in screen.select flag */
end_comment

begin_define
define|#
directive|define
name|INWINDOW
value|01
end_define

begin_comment
comment|/* the mouse is in one of the windows */
end_comment

begin_define
define|#
directive|define
name|FOCUS
value|02
end_define

begin_comment
comment|/* one of the windows is the focus window */
end_comment

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
name|N_MARGINBELL
value|10
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
name|Keyboard
name|keyboard
decl_stmt|;
comment|/* terminal keyboard		*/
name|Screen
name|screen
decl_stmt|;
comment|/* terminal screeen		*/
name|unsigned
name|flags
decl_stmt|;
comment|/* mode flags			*/
name|unsigned
name|initflags
decl_stmt|;
comment|/* initial mode flags		*/
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
name|UNDERLINE
value|0x02
end_define

begin_comment
comment|/* true if underlining */
end_comment

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

begin_define
define|#
directive|define
name|AUTOREPEAT
value|0x100
end_define

begin_comment
comment|/* true if in autorepeat mode */
end_comment

begin_define
define|#
directive|define
name|IN132COLUMNS
value|0x200
end_define

begin_comment
comment|/* true if in 132 column mode */
end_comment

begin_define
define|#
directive|define
name|LINEFEED
value|0x400
end_define

begin_define
define|#
directive|define
name|REVERSEWRAP
value|0x800
end_define

begin_comment
comment|/* true if reverse wraparound mode */
end_comment

begin_define
define|#
directive|define
name|ICONINPUT
value|0x1000
end_define

begin_comment
comment|/* true if mini icon accepts kbd input */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTES
value|0x07
end_define

begin_comment
comment|/* attributes mask */
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
name|VWindow
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->window)
end_define

begin_define
define|#
directive|define
name|TWindow
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->window)
end_define

begin_define
define|#
directive|define
name|Width
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->width)
end_define

begin_define
define|#
directive|define
name|Height
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->height)
end_define

begin_define
define|#
directive|define
name|FullWidth
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->fullwidth)
end_define

begin_define
define|#
directive|define
name|FullHeight
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->fullheight)
end_define

begin_define
define|#
directive|define
name|FontWidth
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->f_width)
end_define

begin_define
define|#
directive|define
name|FontHeight
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->f_height)
end_define

begin_define
define|#
directive|define
name|TWidth
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->width)
end_define

begin_define
define|#
directive|define
name|THeight
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->height)
end_define

begin_define
define|#
directive|define
name|TFullWidth
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->fullwidth)
end_define

begin_define
define|#
directive|define
name|TFullHeight
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->fullheight)
end_define

begin_define
define|#
directive|define
name|TekScale
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->tekscale)
end_define

begin_define
define|#
directive|define
name|Titlebar
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedVwin->titlebar)
end_define

begin_define
define|#
directive|define
name|TTitlebar
parameter_list|(
name|screen
parameter_list|)
value|(screen->mappedTwin->titlebar)
end_define

begin_define
define|#
directive|define
name|ActiveIcon
parameter_list|(
name|screen
parameter_list|)
value|(screen->active_icon&& \ 				(screen->mappedVwin ==&screen->iconVwin))
end_define

begin_define
define|#
directive|define
name|TActiveIcon
parameter_list|(
name|screen
parameter_list|)
value|(screen->active_icon&& \ 				(screen->mappedTwin ==&screen->iconTwin))
end_define

begin_define
define|#
directive|define
name|CursorX
parameter_list|(
name|screen
parameter_list|,
name|col
parameter_list|)
value|((col) * FontWidth(screen) + screen->border)
end_define

begin_define
define|#
directive|define
name|CursorY
parameter_list|(
name|screen
parameter_list|,
name|row
parameter_list|)
value|((screen->instatus ? \ 			((row) * FontHeight(screen) + 1)\ 			: (((row) - screen->topline) * FontHeight(screen))) +\ 			screen->border + Titlebar(screen))
end_define

begin_define
define|#
directive|define
name|TICONWINDOWEVENTS
value|(ExposeWindow | ButtonPressed)
end_define

begin_define
define|#
directive|define
name|ICONWINDOWEVENTS
value|(TICONWINDOWEVENTS | ExposeRegion | ExposeCopy)
end_define

begin_define
define|#
directive|define
name|ICONINPUTEVENTS
value|(KeyPressed | EnterWindow | LeaveWindow | FocusChange)
end_define

begin_define
define|#
directive|define
name|TWINDOWEVENTS
value|(KeyPressed | ExposeWindow | ButtonPressed |\ 			 ButtonReleased | UnmapWindow | EnterWindow |\ 			 LeaveWindow | FocusChange)
end_define

begin_define
define|#
directive|define
name|WINDOWEVENTS
value|(TWINDOWEVENTS | ExposeRegion | ExposeCopy)
end_define

begin_define
define|#
directive|define
name|TEK_LINK_BLOCK_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
name|Tek_Link
block|{
name|struct
name|Tek_Link
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next TekLink in list 				   NULL<=> this is last TekLink */
name|short
name|count
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
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

begin_comment
comment|/* flags for cursors */
end_comment

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|TOGGLE
value|1
end_define

begin_comment
comment|/* flags for color */
end_comment

begin_define
define|#
directive|define
name|C_FOREGROUND
value|0x01
end_define

begin_define
define|#
directive|define
name|C_BACKGROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|C_FBMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|C_CURSOR
value|0x04
end_define

begin_define
define|#
directive|define
name|C_MOUSE
value|0x08
end_define

begin_define
define|#
directive|define
name|C_BORDER
value|0x10
end_define

begin_comment
comment|/* flags for inhibit */
end_comment

begin_define
define|#
directive|define
name|I_LOG
value|0x01
end_define

begin_define
define|#
directive|define
name|I_SIGNAL
value|0x02
end_define

begin_define
define|#
directive|define
name|I_TEK
value|0x04
end_define

begin_function_decl
specifier|extern
name|Bitmap
name|make_icon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|make_tcross
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|make_xterm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|make_wait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|make_arrow
parameter_list|()
function_decl|;
end_function_decl

end_unit

