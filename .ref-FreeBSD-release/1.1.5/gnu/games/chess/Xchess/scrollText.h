begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Scrollable Text Window Header File  *  * David Harrison  * University of California,  Berkeley  * 1986  *  * This file contains definitions for a scrollable text window  * with scroll bar support.  */
end_comment

begin_function_decl
name|int
name|TxtGrab
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Take hold of a previously created window */
end_comment

begin_define
define|#
directive|define
name|TXT_NO_COLOR
value|-1
end_define

begin_function_decl
name|int
name|TxtAddFont
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Loads a new font for use later */
end_comment

begin_function_decl
name|int
name|TxtWinP
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Returns non-zero value if the window is text window */
end_comment

begin_function_decl
name|int
name|TxtClear
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Clears text window and resets text buffer */
end_comment

begin_function_decl
name|int
name|TxtWriteStr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Writes a string to window with immediate update */
end_comment

begin_function_decl
name|int
name|TxtJamStr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Write a string without causing update to screen */
end_comment

begin_function_decl
name|int
name|TxtRepaint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Repaints entire scrollable text window */
end_comment

begin_function_decl
name|int
name|TxtFilter
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Handles events related to text window */
end_comment

end_unit

