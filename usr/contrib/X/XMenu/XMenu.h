begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenu.h,v 10.18 86/02/01 16:14:03 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenu.h -	Include file for the MIT Project Athena  *			XMenu X window system menu package.  *			  *	Author:		Tony Della Fera, DEC  *			August, 1984  */
end_comment

begin_define
define|#
directive|define
name|FAILURE
value|-1
end_define

begin_define
define|#
directive|define
name|SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|POST_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|NO_SELECTION
value|-1
end_define

begin_define
define|#
directive|define
name|XM_FAILURE
value|-1
end_define

begin_define
define|#
directive|define
name|XM_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|XM_NO_SELECT
value|2
end_define

begin_define
define|#
directive|define
name|XM_IA_SELECT
value|3
end_define

begin_define
define|#
directive|define
name|XME_CODE_COUNT
value|17
end_define

begin_define
define|#
directive|define
name|XME_NO_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|XME_NOT_INIT
value|1
end_define

begin_define
define|#
directive|define
name|XME_ARG_BOUNDS
value|2
end_define

begin_define
define|#
directive|define
name|XME_P_NOT_FOUND
value|3
end_define

begin_define
define|#
directive|define
name|XME_S_NOT_FOUND
value|4
end_define

begin_define
define|#
directive|define
name|XME_STYLE_PARAM
value|5
end_define

begin_define
define|#
directive|define
name|XME_GRAB_MOUSE
value|6
end_define

begin_define
define|#
directive|define
name|XME_INTERP_LOC
value|7
end_define

begin_define
define|#
directive|define
name|XME_CALLOC
value|8
end_define

begin_define
define|#
directive|define
name|XME_CREATE_ASSOC
value|9
end_define

begin_define
define|#
directive|define
name|XME_STORE_BITMAP
value|10
end_define

begin_define
define|#
directive|define
name|XME_MAKE_TILES
value|11
end_define

begin_define
define|#
directive|define
name|XME_MAKE_PIXMAP
value|12
end_define

begin_define
define|#
directive|define
name|XME_CREATE_CURSOR
value|13
end_define

begin_define
define|#
directive|define
name|XME_OPEN_FONT
value|14
end_define

begin_define
define|#
directive|define
name|XME_CREATE_WINDOW
value|15
end_define

begin_define
define|#
directive|define
name|XME_CREATE_TRANSP
value|16
end_define

begin_comment
comment|/*  * XMenu error code and error list definitions.>  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_XMErrorCode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_XMErrorList
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define the XMWindow datatypes.  *  * An XMWindow is either an XMPane or an XMSelect.  *  * XMWindow is wrapper used to identify the constant window  * information that makes up XMPane and XMSelect objects.  *  * An XMPane is a menu pane made up of one or more XMSelect and a label.  *  * An XMSelect is a menu selection object with a label and a data pointer.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_xmwintype
block|{
name|PANE
block|,
name|SELECTION
block|,
name|PL_HEADER
block|,
name|SL_HEADER
block|}
name|XMWType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_xmwindow
block|{
name|struct
name|_xmwindow
modifier|*
name|next
decl_stmt|;
comment|/* Next obj pointer (for insque). */
name|struct
name|_xmwindow
modifier|*
name|prev
decl_stmt|;
comment|/* Prev obj pointer (for insque). */
name|XMWType
name|type
decl_stmt|;
comment|/* Type of window. */
name|Window
name|window
decl_stmt|;
comment|/* X Window Id. */
name|int
name|window_x
decl_stmt|;
comment|/* Window upper left X coordinate. */
name|int
name|window_y
decl_stmt|;
comment|/* Window upper left y coordinate. */
name|int
name|window_w
decl_stmt|;
comment|/* Window width. */
name|int
name|window_h
decl_stmt|;
comment|/* Window height. */
name|int
name|active
decl_stmt|;
comment|/* Window active? */
name|int
name|activated
decl_stmt|;
comment|/* Window activated? */
name|int
name|pad_l1
decl_stmt|;
comment|/* ---- */
name|char
modifier|*
name|pad_l2
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l3
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l4
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l5
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l6
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l7
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l8
decl_stmt|;
comment|/* ---- */
name|struct
name|_xmwindow
modifier|*
name|pad_l9
decl_stmt|;
comment|/* ---- */
name|char
modifier|*
name|pad_l10
decl_stmt|;
comment|/* ---- */
name|struct
name|_xmwindow
modifier|*
name|pad_l11
decl_stmt|;
comment|/* ---- */
block|}
name|XMWindow
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_xmpane
block|{
name|struct
name|_xmpane
modifier|*
name|next
decl_stmt|;
comment|/* Next obj pointer (for insque). */
name|struct
name|_xmpane
modifier|*
name|prev
decl_stmt|;
comment|/* Prev obj pointer (for insque). */
name|XMWType
name|type
decl_stmt|;
comment|/* Type of window. */
name|Window
name|window
decl_stmt|;
comment|/* X Window Id. */
name|int
name|window_x
decl_stmt|;
comment|/* Window upper left X coordinate. */
name|int
name|window_y
decl_stmt|;
comment|/* Window upper left y coordinate. */
name|int
name|window_w
decl_stmt|;
comment|/* Window width. */
name|int
name|window_h
decl_stmt|;
comment|/* Window height. */
name|int
name|active
decl_stmt|;
comment|/* Window active? */
name|int
name|activated
decl_stmt|;
comment|/* Window activated? */
name|int
name|serial
decl_stmt|;
comment|/* -- Pane serial number. */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* -- Pane label. */
name|int
name|label_width
decl_stmt|;
comment|/* -- Pane label width in pixels. */
name|int
name|label_length
decl_stmt|;
comment|/* -- Pane label length in chars. */
name|int
name|label_x
decl_stmt|;
comment|/* -- Pane label X offset. */
name|int
name|label_uy
decl_stmt|;
comment|/* -- Pane label upper Y offset. */
name|int
name|label_ly
decl_stmt|;
comment|/* -- Pane label lower Y offset. */
name|int
name|s_count
decl_stmt|;
comment|/* -- Selections in this pane. */
name|struct
name|_xmselect
modifier|*
name|s_list
decl_stmt|;
comment|/* -- Selection  window list. */
name|char
modifier|*
name|pad_l10
decl_stmt|;
comment|/* ---- */
name|struct
name|_xmwindow
modifier|*
name|pad_l11
decl_stmt|;
comment|/* ---- */
block|}
name|XMPane
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_xmselect
block|{
name|struct
name|_xmselect
modifier|*
name|next
decl_stmt|;
comment|/* Next obj pointer (for insque). */
name|struct
name|_xmselect
modifier|*
name|prev
decl_stmt|;
comment|/* Prev obj pointer (for insque). */
name|XMWType
name|type
decl_stmt|;
comment|/* Type of window. */
name|Window
name|window
decl_stmt|;
comment|/* X Window Id. */
name|Window
name|parent
decl_stmt|;
comment|/* X Window id of parent window. */
name|int
name|window_x
decl_stmt|;
comment|/* Window upper left X coordinate. */
name|int
name|window_y
decl_stmt|;
comment|/* Window upper left y coordinate. */
name|int
name|window_w
decl_stmt|;
comment|/* Window width. */
name|int
name|window_h
decl_stmt|;
comment|/* Window height. */
name|int
name|active
decl_stmt|;
comment|/* Window active? */
name|int
name|activated
decl_stmt|;
comment|/* Window activated? */
name|int
name|serial
decl_stmt|;
comment|/* -- Selection serial number. */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* -- Selection label. */
name|int
name|label_width
decl_stmt|;
comment|/* -- Selection label width in pixels. */
name|int
name|label_length
decl_stmt|;
comment|/* -- Selection label length in chars. */
name|int
name|label_x
decl_stmt|;
comment|/* -- Selection label X offset. */
name|int
name|label_y
decl_stmt|;
comment|/* -- Selection label Y offset. */
name|int
name|pad_l7
decl_stmt|;
comment|/* ---- */
name|int
name|pad_l8
decl_stmt|;
comment|/* ---- */
name|struct
name|_xmwindow
modifier|*
name|pad_l9
decl_stmt|;
comment|/* ---- */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* -- Selection data pointer. */
name|struct
name|_xmpane
modifier|*
name|parent_p
decl_stmt|;
comment|/* -- Selection parent pane structure. */
block|}
name|XMSelect
typedef|;
end_typedef

begin_comment
comment|/*  * Define the XMStyle datatype.  *  * Menu presentation style information.  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_xmstyle
block|{
name|LEFT
block|,
comment|/* Left oriented obejct. */
name|RIGHT
block|,
comment|/* Right oriented obejct. */
name|CENTER
comment|/* Center oriented object. */
block|}
name|XMStyle
typedef|;
end_typedef

begin_comment
comment|/*  * Define the XMMode datatype.  *  * Menu presentation mode information.  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_xmmode
block|{
name|BOX
block|,
comment|/* BOXed graphic rendition. */
name|INVERT
block|,
comment|/* INVERTed graphic rendition. */
block|}
name|XMMode
typedef|;
end_typedef

begin_comment
comment|/*   * Define the XMenu datatype.   *  * All dimensions are in pixels unless otherwise noted.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xmenu
block|{
comment|/* -------------------- Menu data -------------------- */
name|XMStyle
name|menu_style
decl_stmt|;
comment|/* Menu display style. */
name|XMMode
name|menu_mode
decl_stmt|;
comment|/* Menu display mode. */
name|int
name|freeze
decl_stmt|;
comment|/* Freeze server. */
name|int
name|recompute
decl_stmt|;
comment|/* Recompute menu dependecies? */
name|Window
name|parent
decl_stmt|;
comment|/* Menu's parent window. */
name|int
name|width
decl_stmt|;
comment|/* Overall menu width. */
name|int
name|height
decl_stmt|;
comment|/* Overall menu height. */
name|Cursor
name|mouse_cursor
decl_stmt|;
comment|/* Mouse cursor raster. */
name|XAssocTable
modifier|*
name|assoc_tab
decl_stmt|;
comment|/* XMWindow association table. */
name|XMPane
modifier|*
name|p_list
decl_stmt|;
comment|/* List of XMPanes. */
comment|/* -------------------- Pane window data -------------------- */
name|XMStyle
name|p_style
decl_stmt|;
comment|/* Pane display style. */
name|int
name|p_events
decl_stmt|;
comment|/* Pane window X events. */
name|FontInfo
modifier|*
name|p_fnt_info
decl_stmt|;
comment|/* Flag font info structure. */
name|int
name|p_fnt_pad
decl_stmt|;
comment|/* Fixed flag font padding in pixels. */
name|double
name|p_spread
decl_stmt|;
comment|/* Pane spread in flag height fractions. */
name|int
name|p_bdr_width
decl_stmt|;
comment|/* Pane border width. */
name|int
name|flag_height
decl_stmt|;
comment|/* Flag height. */
name|int
name|p_width
decl_stmt|;
comment|/* Menu pane width. */
name|int
name|p_height
decl_stmt|;
comment|/* Menu pane height. */
name|int
name|p_x_off
decl_stmt|;
comment|/* Pane window X offset. */
name|int
name|p_y_off
decl_stmt|;
comment|/* Pane window Y offset. */
name|int
name|p_count
decl_stmt|;
comment|/* Number of panes per menu. */
comment|/* -------------------- Selection window data -------------------- */
name|XMStyle
name|s_style
decl_stmt|;
comment|/* Selection display style. */
name|int
name|s_events
decl_stmt|;
comment|/* Selection window X events. */
name|FontInfo
modifier|*
name|s_fnt_info
decl_stmt|;
comment|/* Body font info structure. */
name|int
name|s_fnt_pad
decl_stmt|;
comment|/* Fixed body font padding in pixels. */
name|double
name|s_spread
decl_stmt|;
comment|/* Select spread in line height fractions. */
name|int
name|s_bdr_width
decl_stmt|;
comment|/* Select border width. */
name|int
name|s_width
decl_stmt|;
comment|/* Selection window width. */
name|int
name|s_height
decl_stmt|;
comment|/* Selection window height. */
name|int
name|s_x_off
decl_stmt|;
comment|/* Selection window X offset. */
name|int
name|s_y_off
decl_stmt|;
comment|/* Selection window Y offset. */
name|int
name|s_count
decl_stmt|;
comment|/* Maximum number of selections per pane. */
comment|/* -------------------- Color data -------------------- */
name|int
name|p_bdr_color
decl_stmt|;
comment|/* Color of pane border pixmap. */
name|int
name|s_bdr_color
decl_stmt|;
comment|/* Color of selection border pixmap. */
name|int
name|p_frg_color
decl_stmt|;
comment|/* Color of pane foreground pixmap. */
name|int
name|s_frg_color
decl_stmt|;
comment|/* Color of selection pixmap. */
name|int
name|bkgnd_color
decl_stmt|;
comment|/* Color of menu background pixmap. */
comment|/* -------------------- Pixmap data -------------------- */
name|Pixmap
name|p_bdr_pixmap
decl_stmt|;
comment|/* Pane border pixmap. */
name|Pixmap
name|s_bdr_pixmap
decl_stmt|;
comment|/* Selection border pixmap. */
name|Pixmap
name|p_frg_pixmap
decl_stmt|;
comment|/* Pane foreground pixmap. */
name|Pixmap
name|s_frg_pixmap
decl_stmt|;
comment|/* Selection foreground pixmap. */
name|Pixmap
name|bkgnd_pixmap
decl_stmt|;
comment|/* Menu background pixmap. */
name|Pixmap
name|inact_pixmap
decl_stmt|;
comment|/* Menu inactive pixmap. */
block|}
name|XMenu
typedef|;
end_typedef

begin_comment
comment|/*  * XMenu library routine declarations.  */
end_comment

begin_function_decl
name|XMenu
modifier|*
name|XMenuCreate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuAddPane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuAddSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuInsertPane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuInsertSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuFindPane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuFindSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuChangePane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuChangeSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuSetPane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuSetSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuRecompute
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuEventHandler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|XMenuLocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuSetFreeze
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|XMenuActivate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XMenuPost
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuDeletePane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuDeleteSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XMenuDestroy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|char
modifier|*
name|XMenuError
parameter_list|()
function_decl|;
end_function_decl

end_unit

