begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: globals.c,v 10.2 86/02/01 16:01:58 tony Rel $ */
end_comment

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_decl_stmt
name|Cursor
name|iconCursor
decl_stmt|,
name|wmCursor
decl_stmt|,
name|textCursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|frameWidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Font
name|iconfont
decl_stmt|,
name|menufont
decl_stmt|,
name|sizefont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|screen_width
decl_stmt|,
name|screen_height
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|gray
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|focus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WindowInfo
name|focusInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Status
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|freeze
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|popup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bgColor
decl_stmt|,
name|fgColor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|bgPixmap
decl_stmt|,
name|fgPixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cursorFunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iconifyDelta
decl_stmt|;
end_decl_stmt

end_unit

