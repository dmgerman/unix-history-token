begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: extern.h,v 10.2 86/02/01 16:01:53 tony Rel $ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Cursor
name|iconCursor
decl_stmt|,
name|wmCursor
decl_stmt|,
name|textCursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frameWidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Font
name|iconfont
decl_stmt|,
name|sizefont
decl_stmt|,
name|menufont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screen_width
decl_stmt|,
name|screen_height
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Pixmap
name|gray
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Window
name|focus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WindowInfo
name|focusInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Status
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|freeze
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|popup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bgColor
decl_stmt|,
name|fgColor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Pixmap
name|bgPixmap
decl_stmt|,
name|fgPixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cursorFunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iconifyDelta
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Cursor
name|XCreateCursor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Bitmap
name|XStoreBitmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Pixmap
name|XMakePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Font
name|XGetFont
parameter_list|()
function_decl|;
end_function_decl

end_unit

