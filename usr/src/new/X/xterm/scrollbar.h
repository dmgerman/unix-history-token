begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/scrollbar.h,v $  *	$Header: scrollbar.h,v 10.100 86/12/01 14:40:30 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)scrollbar.h       X10/6.6B 12/26/86 */
end_comment

begin_define
define|#
directive|define
name|BARSTART
value|(2 * BUTTONHEIGHT)
end_define

begin_define
define|#
directive|define
name|BUTTONHEIGHT
value|SCROLLBARWIDTH
end_define

begin_define
define|#
directive|define
name|HILITED
value|1
end_define

begin_define
define|#
directive|define
name|MINSCROLLBARHEIGHT
value|(BARSTART + 32)
end_define

begin_define
define|#
directive|define
name|NBUTTONBITMAPS
value|(BUTTON_NORMAL / 2 + 1)
end_define

begin_define
define|#
directive|define
name|NSAVESTATES
value|2
end_define

begin_define
define|#
directive|define
name|PAUSETIME
value|(1000000L / 5)
end_define

begin_define
define|#
directive|define
name|SAVELINES
value|64
end_define

begin_define
define|#
directive|define
name|SCROLLBARWIDTH
value|20
end_define

begin_define
define|#
directive|define
name|STEPTIME
value|(1000000L / 10)
end_define

begin_comment
comment|/*  * the first four must be consecutive and at the bottom  */
end_comment

begin_define
define|#
directive|define
name|BUTTON_UPLINE
value|0
end_define

begin_define
define|#
directive|define
name|BUTTON_UPLINEHI
value|(BUTTON_UPLINE | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_DOWNLINE
value|(BUTTON_UPLINE + 2)
end_define

begin_define
define|#
directive|define
name|BUTTON_DOWNLINEHI
value|(BUTTON_DOWNLINE | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_UPPAGE
value|(BUTTON_DOWNLINE + 2)
end_define

begin_define
define|#
directive|define
name|BUTTON_UPPAGEHI
value|(BUTTON_UPPAGE | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_DOWNPAGE
value|(BUTTON_UPPAGE + 2)
end_define

begin_define
define|#
directive|define
name|BUTTON_DOWNPAGEHI
value|(BUTTON_DOWNPAGE | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_TOP
value|(BUTTON_DOWNPAGE + 2)
end_define

begin_define
define|#
directive|define
name|BUTTON_TOPHI
value|(BUTTON_TOP | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_BOTTOM
value|(BUTTON_TOP + 2)
end_define

begin_define
define|#
directive|define
name|BUTTON_BOTTOMHI
value|(BUTTON_BOTTOM | HILITED)
end_define

begin_define
define|#
directive|define
name|BUTTON_NORMAL
value|(BUTTON_BOTTOM + 2)
end_define

begin_define
define|#
directive|define
name|SAVE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|SAVE_ON
value|1
end_define

begin_define
define|#
directive|define
name|HIDE
value|1
end_define

begin_define
define|#
directive|define
name|NONE
value|0
end_define

begin_define
define|#
directive|define
name|SHOW
value|2
end_define

begin_define
define|#
directive|define
name|GetButtonState
parameter_list|(
name|sb
parameter_list|)
value|(sb->buttonset)
end_define

begin_define
define|#
directive|define
name|GetSaveState
parameter_list|(
name|sb
parameter_list|)
value|(sb->saveset)
end_define

begin_define
define|#
directive|define
name|GetScrollBarBottom
parameter_list|(
name|sb
parameter_list|)
value|(sb->set.bottomvalue)
end_define

begin_define
define|#
directive|define
name|GetScrollBarRegion
parameter_list|(
name|sb
parameter_list|)
value|(sb->set.regionheight)
end_define

begin_define
define|#
directive|define
name|GetScrollBarTop
parameter_list|(
name|sb
parameter_list|)
value|(sb->set.topvalue)
end_define

begin_define
define|#
directive|define
name|GetScrollBarValue
parameter_list|(
name|sb
parameter_list|)
value|(sb->set.value)
end_define

begin_define
define|#
directive|define
name|SetScrollBarBottom
parameter_list|(
name|sb
parameter_list|,
name|bot
parameter_list|)
value|sb->set.bottomvalue = (bot)
end_define

begin_define
define|#
directive|define
name|SetScrollBarRegion
parameter_list|(
name|sb
parameter_list|,
name|reg
parameter_list|)
value|sb->set.regionheight = (reg)
end_define

begin_define
define|#
directive|define
name|SetScrollBarTop
parameter_list|(
name|sb
parameter_list|,
name|top
parameter_list|)
value|sb->set.topvalue = (top)
end_define

begin_define
define|#
directive|define
name|SetScrollBarValue
parameter_list|(
name|sb
parameter_list|,
name|val
parameter_list|)
value|sb->set.value = (val)
end_define

begin_struct
struct|struct
name|scroll_region
block|{
name|int
name|value
decl_stmt|;
comment|/* value at top of region */
name|int
name|regionheight
decl_stmt|;
comment|/* region height below value */
name|int
name|topvalue
decl_stmt|;
comment|/* of scroll area */
name|int
name|bottomvalue
decl_stmt|;
comment|/* of scroll area */
name|int
name|height
decl_stmt|;
comment|/* of scroll area */
name|int
name|y
decl_stmt|;
comment|/* y position of region */
name|int
name|pixelheight
decl_stmt|;
comment|/* height in pixel of region */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|scroll_bar
block|{
name|int
name|visible
decl_stmt|;
comment|/* scrollbar visible */
name|int
name|buttonstate
decl_stmt|;
comment|/* current button state */
name|int
name|buttonset
decl_stmt|;
comment|/* requested button state */
name|int
name|savestate
decl_stmt|;
comment|/* current save state */
name|int
name|saveset
decl_stmt|;
comment|/* requested save state */
name|int
name|regionvisible
decl_stmt|;
comment|/* region visible */
name|int
name|action
decl_stmt|;
comment|/* state is changing */
name|Window
name|bar
decl_stmt|;
comment|/* main scrollbar window */
name|Window
name|button
decl_stmt|;
comment|/* button window */
name|Window
name|save
decl_stmt|;
comment|/* save state window */
name|Window
name|region
decl_stmt|;
comment|/* region window */
name|Cursor
name|cursor
decl_stmt|;
comment|/* scrollbar cursor */
name|short
modifier|*
name|buttonbits
index|[
name|NBUTTONBITMAPS
index|]
decl_stmt|;
comment|/* button state bitmaps */
name|short
modifier|*
name|savebits
index|[
name|NSAVESTATES
index|]
decl_stmt|;
comment|/* save state bitmaps */
name|int
name|fg
decl_stmt|;
comment|/* foreground color */
name|int
name|bg
decl_stmt|;
comment|/* background color */
name|struct
name|scroll_region
name|state
decl_stmt|;
comment|/* current region state */
name|struct
name|scroll_region
name|set
decl_stmt|;
comment|/* requested region state */
block|}
name|ScrollBar
typedef|;
end_typedef

begin_function_decl
name|ScrollBar
modifier|*
name|CreateScrollBar
parameter_list|()
function_decl|;
end_function_decl

end_unit

