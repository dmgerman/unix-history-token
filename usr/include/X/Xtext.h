begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: Xtext.h,v 10.4 86/04/23 12:04:49 jg Rel $ */
end_comment

begin_comment
comment|/* Include file for X text window package.  An application using this    package modifies any of the fields at its own risk! */
end_comment

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_TextWindow
block|{
name|struct
name|_TextWindow
modifier|*
name|next
decl_stmt|;
comment|/* for linked list of TextWindows */
name|Window
name|w
decl_stmt|;
comment|/* Window to use */
name|FontInfo
modifier|*
name|font
decl_stmt|;
comment|/* Font to use for text */
name|int
name|fgpixel
decl_stmt|;
comment|/* Pixel value of foreground */
name|int
name|bgpixel
decl_stmt|;
comment|/* Pixel value of background */
name|short
name|num_lines
decl_stmt|;
comment|/* Number of lines in the window */
name|short
name|num_chars
decl_stmt|;
comment|/* The length of each line */
name|short
name|mapped
decl_stmt|;
comment|/* Whether or not the window is mapped */
name|short
name|height
decl_stmt|;
comment|/* Height of window in pixels */
name|short
name|width
decl_stmt|;
comment|/* Width of window in pixels */
name|short
name|first_line
decl_stmt|;
comment|/* The index of the first line */
name|char
modifier|*
modifier|*
name|lines
decl_stmt|;
comment|/* Ptr to array of text lines */
name|short
modifier|*
name|line_length
decl_stmt|;
comment|/* Ptr to array of line lengths (in pixels) */
name|short
modifier|*
name|line_chars
decl_stmt|;
comment|/* Ptr to array of line lengths in chars */
name|short
name|last_line
decl_stmt|;
comment|/* Which line is the last */
name|short
name|last_char
decl_stmt|;
comment|/* Length of the last line */
name|short
name|next_x
decl_stmt|;
comment|/* X-coord for next character */
name|short
name|next_y
decl_stmt|;
comment|/* Y-coord for next character */
name|unsigned
name|int
name|eventmask
decl_stmt|;
comment|/* List of events we're interested in */
name|char
modifier|*
name|scroll_history
decl_stmt|;
comment|/* Ptr to list of scroll amounts */
name|short
name|scroll_count
decl_stmt|;
comment|/* Number of outstanding scrolls */
name|short
name|scroll_start
decl_stmt|;
comment|/* Where in the history the history starts */
name|short
name|old_scrolls
decl_stmt|;
comment|/* Number of ignorable outstanting scrolls */
name|short
name|fastscroll
decl_stmt|;
comment|/* Whether or not to use fast scrolling */
block|}
name|TextWindow
typedef|;
end_typedef

begin_function_decl
name|TextWindow
modifier|*
name|TextCreate
parameter_list|()
function_decl|;
end_function_decl

end_unit

