begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/menu.h,v $  *	$Header: menu.h,v 10.100 86/12/01 14:40:05 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)menu.h       X10/6.6B 12/26/86 */
end_comment

begin_comment
comment|/*  * Menu items are constructed as follows, starting from the left side:  *  *	menuItemPad  *	space for check mark  *	menuItemPad  *	text + padding  *	menuItemPad  *  * The padding for the text is that amount that this text is narrower than the  * widest text.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_menuItem
block|{
name|int
name|itemHeight
decl_stmt|;
comment|/* total height of this item */
name|int
name|itemFlags
decl_stmt|;
comment|/* flags of item */
define|#
directive|define
name|itemDisabled
value|0x0001
comment|/* item is disabled */
define|#
directive|define
name|itemChecked
value|0x0002
comment|/* item has check mark */
define|#
directive|define
name|itemStateMask
value|0x0003
comment|/* mask for current state */
define|#
directive|define
name|itemSetDisabled
value|0x0004
comment|/* item wants to be disabled */
define|#
directive|define
name|itemSetChecked
value|0x0008
comment|/* item wants check mark */
define|#
directive|define
name|itemSetMask
value|0x000c
comment|/* mask for desired state */
define|#
directive|define
name|itemSetMaskShift
value|2
comment|/* for comparison with actual */
define|#
directive|define
name|itemChanged
value|0x0010
comment|/* item desires change */
name|char
modifier|*
name|itemText
decl_stmt|;
comment|/* text of item */
name|int
name|itemTextWidth
decl_stmt|;
comment|/* width of text */
name|int
name|itemTextLength
decl_stmt|;
comment|/* length of text */
name|struct
name|_menuItem
modifier|*
name|nextItem
decl_stmt|;
comment|/* next item in chain */
block|}
name|MenuItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_menu
block|{
name|int
name|menuWidth
decl_stmt|;
comment|/* full width of menu */
name|int
name|menuHeight
decl_stmt|;
comment|/* full height of menu */
name|int
name|menuFlags
decl_stmt|;
comment|/* flags of this menu */
define|#
directive|define
name|menuChanged
value|0x0001
comment|/* menu changed, must redraw */
define|#
directive|define
name|menuItemChanged
value|0x0002
comment|/* item changed, must redraw */
define|#
directive|define
name|menuMapped
value|0x0004
comment|/* menu is now mapped */
define|#
directive|define
name|menuFreeze
value|0x0008
comment|/* freeze when doing menu */
define|#
directive|define
name|menuSaveMenu
value|0x0010
comment|/* save copy of menu */
name|int
name|menuMaxTextWidth
decl_stmt|;
comment|/* width of widest text */
name|int
name|menuInitialItem
decl_stmt|;
comment|/*< 0 none,>= 0 initial item */
name|int
name|menuBorderWidth
decl_stmt|;
comment|/* width of border */
name|int
name|menuBgColor
decl_stmt|;
comment|/* background color */
name|int
name|menuFgColor
decl_stmt|;
comment|/* foreground color */
name|Pixmap
name|menuBgTile
decl_stmt|;
comment|/* backgroud tile */
name|FontInfo
modifier|*
name|menuFontInfo
decl_stmt|;
comment|/* fontinfo for menu font */
name|int
name|menuItemPad
decl_stmt|;
comment|/* pad amount */
name|Window
name|menuWindow
decl_stmt|;
comment|/* window of menu */
name|int
function_decl|(
modifier|*
name|menuEventHandler
function_decl|)
parameter_list|()
function_decl|;
comment|/* external event handler */
name|Cursor
name|menuCursor
decl_stmt|;
comment|/* cursor used in menu */
name|Pixmap
name|menuSaved
decl_stmt|;
comment|/* copy of menu */
name|Pixmap
name|menuSavedImage
decl_stmt|;
comment|/* copy of image under menu */
name|int
name|menuSavedImageX
decl_stmt|;
comment|/* X coordinate of the saved image */
name|int
name|menuSavedImageY
decl_stmt|;
comment|/* Y coordinate of the saved image */
name|MenuItem
modifier|*
name|menuItems
decl_stmt|;
comment|/* head of menu item chain */
name|char
modifier|*
name|menuTitle
decl_stmt|;
comment|/* title of menu */
name|int
name|menuTitleWidth
decl_stmt|;
comment|/* width of title */
name|int
name|menuTitleLength
decl_stmt|;
comment|/* length of title */
name|int
name|menuItemTop
decl_stmt|;
comment|/* position of top of first item */
block|}
name|Menu
typedef|;
end_typedef

begin_define
define|#
directive|define
name|checkMarkWidth
value|9
end_define

begin_define
define|#
directive|define
name|checkMarkHeight
value|8
end_define

begin_define
define|#
directive|define
name|defaultCursorWidth
value|16
end_define

begin_define
define|#
directive|define
name|defaultCursorHeight
value|16
end_define

begin_define
define|#
directive|define
name|defaultCursorX
value|1
end_define

begin_define
define|#
directive|define
name|defaultCursorY
value|1
end_define

begin_define
define|#
directive|define
name|grayHeight
value|16
end_define

begin_define
define|#
directive|define
name|grayWidth
value|16
end_define

begin_define
define|#
directive|define
name|lineSeparatorHeight
value|9
end_define

begin_define
define|#
directive|define
name|CheckItem
parameter_list|(
name|menu
parameter_list|,
name|item
parameter_list|)
value|SetItemCheck(menu,item,1)
end_define

begin_define
define|#
directive|define
name|DisableItem
parameter_list|(
name|menu
parameter_list|,
name|item
parameter_list|)
value|SetItemDisable(menu,item,1)
end_define

begin_define
define|#
directive|define
name|EnableItem
parameter_list|(
name|menu
parameter_list|,
name|item
parameter_list|)
value|SetItemDisable(menu,item,0)
end_define

begin_define
define|#
directive|define
name|SetMenuEventHandler
parameter_list|(
name|menu
parameter_list|,
name|f
parameter_list|)
value|menu->menuEventHandler = f
end_define

begin_define
define|#
directive|define
name|UncheckItem
parameter_list|(
name|menu
parameter_list|,
name|item
parameter_list|)
value|SetItemCheck(menu,item,0)
end_define

begin_function_decl
specifier|extern
name|Menu
modifier|*
name|NewMenu
parameter_list|()
function_decl|;
end_function_decl

end_unit

