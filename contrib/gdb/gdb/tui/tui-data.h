begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TUI data manipulation routines.     Copyright 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_DATA_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_DATA_H
end_define

begin_include
include|#
directive|include
file|"tui/tui.h"
end_include

begin_comment
comment|/* For enum tui_win_type.  */
end_comment

begin_include
include|#
directive|include
file|"gdb_curses.h"
end_include

begin_comment
comment|/* For WINDOW.  */
end_comment

begin_comment
comment|/* This is a point definition.  */
end_comment

begin_struct
struct|struct
name|tui_point
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Generic window information */
end_comment

begin_struct
struct|struct
name|tui_gen_win_info
block|{
name|WINDOW
modifier|*
name|handle
decl_stmt|;
comment|/* window handle */
name|enum
name|tui_win_type
name|type
decl_stmt|;
comment|/* type of window */
name|int
name|width
decl_stmt|;
comment|/* window width */
name|int
name|height
decl_stmt|;
comment|/* window height */
name|struct
name|tui_point
name|origin
decl_stmt|;
comment|/* origin of window */
name|void
modifier|*
modifier|*
name|content
decl_stmt|;
comment|/* content of window */
name|int
name|content_size
decl_stmt|;
comment|/* Size of content (# of elements) */
name|int
name|content_in_use
decl_stmt|;
comment|/* Can it be used, or is it already used? */
name|int
name|viewport_height
decl_stmt|;
comment|/* viewport height */
name|int
name|last_visible_line
decl_stmt|;
comment|/* index of last visible line */
name|int
name|is_visible
decl_stmt|;
comment|/* whether the window is visible or not */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* Window title to display.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Constant definitions */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TAB_LEN
value|8
end_define

begin_define
define|#
directive|define
name|NO_SRC_STRING
value|"[ No Source Available ]"
end_define

begin_define
define|#
directive|define
name|NO_DISASSEM_STRING
value|"[ No Assembly Available ]"
end_define

begin_define
define|#
directive|define
name|NO_REGS_STRING
value|"[ Register Values Unavailable ]"
end_define

begin_define
define|#
directive|define
name|NO_DATA_STRING
value|"[ No Data Values Displayed ]"
end_define

begin_define
define|#
directive|define
name|MAX_CONTENT_COUNT
value|100
end_define

begin_define
define|#
directive|define
name|SRC_NAME
value|"SRC"
end_define

begin_define
define|#
directive|define
name|CMD_NAME
value|"CMD"
end_define

begin_define
define|#
directive|define
name|DATA_NAME
value|"REGS"
end_define

begin_define
define|#
directive|define
name|DISASSEM_NAME
value|"ASM"
end_define

begin_define
define|#
directive|define
name|TUI_NULL_STR
value|""
end_define

begin_define
define|#
directive|define
name|DEFAULT_HISTORY_COUNT
value|25
end_define

begin_define
define|#
directive|define
name|BOX_WINDOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DONT_BOX_WINDOW
value|FALSE
end_define

begin_define
define|#
directive|define
name|HILITE
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_HILITE
value|FALSE
end_define

begin_define
define|#
directive|define
name|WITH_LOCATOR
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_LOCATOR
value|FALSE
end_define

begin_define
define|#
directive|define
name|EMPTY_SOURCE_PROMPT
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_EMPTY_SOURCE_PROMPT
value|FALSE
end_define

begin_define
define|#
directive|define
name|UNDEFINED_ITEM
value|-1
end_define

begin_define
define|#
directive|define
name|MIN_WIN_HEIGHT
value|3
end_define

begin_define
define|#
directive|define
name|MIN_CMD_WIN_HEIGHT
value|3
end_define

begin_comment
comment|/* Strings to display in the TUI status line.  */
end_comment

begin_define
define|#
directive|define
name|PROC_PREFIX
value|"In: "
end_define

begin_define
define|#
directive|define
name|LINE_PREFIX
value|"Line: "
end_define

begin_define
define|#
directive|define
name|PC_PREFIX
value|"PC: "
end_define

begin_define
define|#
directive|define
name|SINGLE_KEY
value|"(SingleKey)"
end_define

begin_comment
comment|/* Minimum/Maximum length of some fields displayed in the TUI status line.  */
end_comment

begin_define
define|#
directive|define
name|MIN_LINE_WIDTH
value|4
end_define

begin_comment
comment|/* Use at least 4 digits for line numbers.  */
end_comment

begin_define
define|#
directive|define
name|MIN_PROC_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MAX_TARGET_WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|MAX_PID_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|TUI_FLOAT_REGS_NAME
value|"$FREGS"
end_define

begin_define
define|#
directive|define
name|TUI_FLOAT_REGS_NAME_LOWER
value|"$fregs"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_REGS_NAME
value|"$GREGS"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_REGS_NAME_LOWER
value|"$gregs"
end_define

begin_define
define|#
directive|define
name|TUI_SPECIAL_REGS_NAME
value|"$SREGS"
end_define

begin_define
define|#
directive|define
name|TUI_SPECIAL_REGS_NAME_LOWER
value|"$sregs"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_SPECIAL_REGS_NAME
value|"$REGS"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_SPECIAL_REGS_NAME_LOWER
value|"$regs"
end_define

begin_comment
comment|/* Scroll direction enum.  */
end_comment

begin_enum
enum|enum
name|tui_scroll_direction
block|{
name|FORWARD_SCROLL
block|,
name|BACKWARD_SCROLL
block|,
name|LEFT_SCROLL
block|,
name|RIGHT_SCROLL
block|}
enum|;
end_enum

begin_comment
comment|/* General list struct.  */
end_comment

begin_struct
struct|struct
name|tui_list
block|{
name|void
modifier|*
modifier|*
name|list
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The kinds of layouts available */
end_comment

begin_enum
enum|enum
name|tui_layout_type
block|{
name|SRC_COMMAND
block|,
name|DISASSEM_COMMAND
block|,
name|SRC_DISASSEM_COMMAND
block|,
name|SRC_DATA_COMMAND
block|,
name|DISASSEM_DATA_COMMAND
block|,
name|UNDEFINED_LAYOUT
block|}
enum|;
end_enum

begin_comment
comment|/* Basic data types that can be displayed in the data window. */
end_comment

begin_enum
enum|enum
name|tui_data_type
block|{
name|TUI_REGISTER
block|,
name|TUI_SCALAR
block|,
name|TUI_COMPLEX
block|,
name|TUI_STRUCT
block|}
enum|;
end_enum

begin_comment
comment|/* Types of register displays */
end_comment

begin_enum
enum|enum
name|tui_register_display_type
block|{
name|TUI_UNDEFINED_REGS
block|,
name|TUI_GENERAL_REGS
block|,
name|TUI_SFLOAT_REGS
block|,
name|TUI_DFLOAT_REGS
block|,
name|TUI_SPECIAL_REGS
block|,
name|TUI_GENERAL_AND_SPECIAL_REGS
block|}
enum|;
end_enum

begin_comment
comment|/* Structure describing source line or line address */
end_comment

begin_union
union|union
name|tui_line_or_address
block|{
name|int
name|line_no
decl_stmt|;
name|CORE_ADDR
name|addr
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Current Layout definition */
end_comment

begin_struct
struct|struct
name|tui_layout_def
block|{
name|enum
name|tui_win_type
name|display_mode
decl_stmt|;
name|int
name|split
decl_stmt|;
name|enum
name|tui_register_display_type
name|regs_display_type
decl_stmt|;
name|enum
name|tui_register_display_type
name|float_regs_display_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the Source/Disassembly Window */
end_comment

begin_struct
struct|struct
name|tui_source_element
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|union
name|tui_line_or_address
name|line_or_addr
decl_stmt|;
name|int
name|is_exec_point
decl_stmt|;
name|int
name|has_break
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the data display window content */
end_comment

begin_struct
struct|struct
name|tui_data_element
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|item_no
decl_stmt|;
comment|/* the register number, or data display number */
name|enum
name|tui_data_type
name|type
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
name|int
name|highlight
decl_stmt|;
name|char
modifier|*
name|content
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the command window content */
end_comment

begin_struct
struct|struct
name|tui_command_element
block|{
name|char
modifier|*
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_LOCATOR_ELEMENT_LEN
value|100
end_define

begin_comment
comment|/* Elements in the locator window content */
end_comment

begin_struct
struct|struct
name|tui_locator_element
block|{
name|char
name|file_name
index|[
name|MAX_LOCATOR_ELEMENT_LEN
index|]
decl_stmt|;
name|char
name|proc_name
index|[
name|MAX_LOCATOR_ELEMENT_LEN
index|]
decl_stmt|;
name|int
name|line_no
decl_stmt|;
name|CORE_ADDR
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags to tell what kind of breakpoint is at current line.  */
end_comment

begin_define
define|#
directive|define
name|TUI_BP_ENABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|TUI_BP_DISABLED
value|0x02
end_define

begin_define
define|#
directive|define
name|TUI_BP_HIT
value|0x04
end_define

begin_define
define|#
directive|define
name|TUI_BP_CONDITIONAL
value|0x08
end_define

begin_define
define|#
directive|define
name|TUI_BP_HARDWARE
value|0x10
end_define

begin_comment
comment|/* Position of breakpoint markers in the exec info string.  */
end_comment

begin_define
define|#
directive|define
name|TUI_BP_HIT_POS
value|0
end_define

begin_define
define|#
directive|define
name|TUI_BP_BREAK_POS
value|1
end_define

begin_define
define|#
directive|define
name|TUI_EXEC_POS
value|2
end_define

begin_define
define|#
directive|define
name|TUI_EXECINFO_SIZE
value|4
end_define

begin_typedef
typedef|typedef
name|char
name|tui_exec_info_content
index|[
name|TUI_EXECINFO_SIZE
index|]
typedef|;
end_typedef

begin_comment
comment|/* An content element in a window */
end_comment

begin_union
union|union
name|tui_which_element
block|{
name|struct
name|tui_source_element
name|source
decl_stmt|;
comment|/* the source elements */
name|struct
name|tui_gen_win_info
name|data_window
decl_stmt|;
comment|/* data display elements */
name|struct
name|tui_data_element
name|data
decl_stmt|;
comment|/* elements of data_window */
name|struct
name|tui_command_element
name|command
decl_stmt|;
comment|/* command elements */
name|struct
name|tui_locator_element
name|locator
decl_stmt|;
comment|/* locator elements */
name|tui_exec_info_content
name|simple_string
decl_stmt|;
comment|/* simple char based elements */
block|}
union|;
end_union

begin_struct
struct|struct
name|tui_win_element
block|{
name|int
name|highlight
decl_stmt|;
name|union
name|tui_which_element
name|which_element
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This describes the content of the window. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|tui_win_element
modifier|*
modifier|*
name|tui_win_content
typedef|;
end_typedef

begin_comment
comment|/* This struct defines the specific information about a data display window */
end_comment

begin_struct
struct|struct
name|tui_data_info
block|{
name|tui_win_content
name|data_content
decl_stmt|;
comment|/* start of data display content */
name|int
name|data_content_count
decl_stmt|;
name|tui_win_content
name|regs_content
decl_stmt|;
comment|/* start of regs display content */
name|int
name|regs_content_count
decl_stmt|;
name|enum
name|tui_register_display_type
name|regs_display_type
decl_stmt|;
name|int
name|regs_column_count
decl_stmt|;
name|int
name|display_regs
decl_stmt|;
comment|/* Should regs be displayed at all? */
name|struct
name|reggroup
modifier|*
name|current_group
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tui_source_info
block|{
name|int
name|has_locator
decl_stmt|;
comment|/* Does locator belongs to this window? */
comment|/* Execution information window.  */
name|struct
name|tui_gen_win_info
modifier|*
name|execution_info
decl_stmt|;
name|int
name|horizontal_offset
decl_stmt|;
comment|/* used for horizontal scroll */
name|union
name|tui_line_or_address
name|start_line_or_addr
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tui_command_info
block|{
name|int
name|cur_line
decl_stmt|;
comment|/* The current line position */
name|int
name|curch
decl_stmt|;
comment|/* The current cursor position */
name|int
name|start_line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This defines information about each logical window */
end_comment

begin_struct
struct|struct
name|tui_win_info
block|{
name|struct
name|tui_gen_win_info
name|generic
decl_stmt|;
comment|/* general window information */
union|union
block|{
name|struct
name|tui_source_info
name|source_info
decl_stmt|;
name|struct
name|tui_data_info
name|data_display_info
decl_stmt|;
name|struct
name|tui_command_info
name|command_info
decl_stmt|;
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|detail
union|;
name|int
name|can_highlight
decl_stmt|;
comment|/* Can this window ever be highlighted? */
name|int
name|is_highlighted
decl_stmt|;
comment|/* Is this window highlighted? */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|tui_win_is_source_type
parameter_list|(
name|enum
name|tui_win_type
name|win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_win_is_auxillary
parameter_list|(
name|enum
name|tui_win_type
name|win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_win_has_locator
parameter_list|(
name|struct
name|tui_win_info
modifier|*
name|win_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_win_highlight
parameter_list|(
name|struct
name|tui_win_info
modifier|*
name|win_info
parameter_list|,
name|int
name|highlight
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global Data */
end_comment

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
function_decl|(
name|tui_win_list
function_decl|[
name|MAX_MAJOR_WINDOWS
function_decl|]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|TUI_SRC_WIN
value|tui_win_list[SRC_WIN]
end_define

begin_define
define|#
directive|define
name|TUI_DISASM_WIN
value|tui_win_list[DISASSEM_WIN]
end_define

begin_define
define|#
directive|define
name|TUI_DATA_WIN
value|tui_win_list[DATA_WIN]
end_define

begin_define
define|#
directive|define
name|TUI_CMD_WIN
value|tui_win_list[CMD_WIN]
end_define

begin_comment
comment|/* Data Manipulation Functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_initialize_static_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_gen_win_info
modifier|*
name|tui_alloc_generic_win_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_alloc_win_info
parameter_list|(
name|enum
name|tui_win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_init_generic_part
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_init_win_info
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tui_win_content
name|tui_alloc_content
parameter_list|(
name|int
parameter_list|,
name|enum
name|tui_win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_add_content_elements
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_init_content_element
parameter_list|(
name|struct
name|tui_win_element
modifier|*
parameter_list|,
name|enum
name|tui_win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_free_window
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_free_win_content
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_free_data_content
parameter_list|(
name|tui_win_content
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_free_all_source_wins_content
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_del_window
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_del_data_windows
parameter_list|(
name|tui_win_content
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_partial_win_by_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tui_win_name
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|tui_layout_type
name|tui_current_layout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_current_layout_to
parameter_list|(
name|enum
name|tui_layout_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_term_height
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_term_height_to
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_term_width
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_term_width_to
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_gen_win_origin
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_gen_win_info
modifier|*
name|tui_locator_win_info_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_gen_win_info
modifier|*
name|tui_source_exec_info_win_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_gen_win_info
modifier|*
name|tui_disassem_exec_info_win_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_list
modifier|*
name|tui_source_windows
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_clear_source_windows
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_clear_source_windows_detail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_clear_win_detail
parameter_list|(
name|struct
name|tui_win_info
modifier|*
name|win_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_add_to_source_windows
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_default_tab_len
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_default_tab_len
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_win_with_focus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_win_with_focus
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_layout_def
modifier|*
name|tui_layout_def
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_win_resized
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_win_resized_to
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_next_win
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_prev_win
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_add_to_source_windows
parameter_list|(
name|struct
name|tui_win_info
modifier|*
name|win_info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TUI_DATA_H */
end_comment

end_unit

