begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Map logical line numbers to (source file, line number) pairs.    Copyright (C) 2001, 2003, 2004    Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBCPP_LINE_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|LIBCPP_LINE_MAP_H
end_define

begin_comment
comment|/* Reason for adding a line change with add_line_map ().  LC_ENTER is    when including a new file, e.g. a #include directive in C.    LC_LEAVE is when reaching a file's end.  LC_RENAME is when a file    name or line number changes for neither of the above reasons    (e.g. a #line directive in C).  */
end_comment

begin_enum
enum|enum
name|lc_reason
block|{
name|LC_ENTER
init|=
literal|0
block|,
name|LC_LEAVE
block|,
name|LC_RENAME
block|}
enum|;
end_enum

begin_comment
comment|/* A logical line/column number, i.e. an "index" into a line_map.  */
end_comment

begin_comment
comment|/* Long-term, we want to use this to replace struct location_s (in input.h),    and effectively typedef source_location location_t.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|source_location
typedef|;
end_typedef

begin_comment
comment|/* Physical source file TO_FILE at line TO_LINE at column 0 is represented    by the logical START_LOCATION.  TO_LINE+L at column C is represented by    START_LOCATION+(L*(1<<column_bits))+C, as long as C<(1<<column_bits),    and the result_location is less than the next line_map's start_location.    (The top line is line 1 and the leftmost column is column 1; line/column 0    means "entire file/line" or "unknown line/column" or "not applicable".)    INCLUDED_FROM is an index into the set that gives the line mapping    at whose end the current one was included.  File(s) at the bottom    of the include stack have this set to -1.  REASON is the reason for    creation of this line map, SYSP is one for a system header, two for    a C system header file that therefore needs to be extern "C"    protected in C++, and zero otherwise.  */
end_comment

begin_struct
struct|struct
name|line_map
block|{
specifier|const
name|char
modifier|*
name|to_file
decl_stmt|;
name|unsigned
name|int
name|to_line
decl_stmt|;
name|source_location
name|start_location
decl_stmt|;
name|int
name|included_from
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|lc_reason
argument_list|)
name|reason
label|:
name|CHAR_BIT
expr_stmt|;
comment|/* The sysp field isn't really needed now that it's in cpp_buffer.  */
name|unsigned
name|char
name|sysp
decl_stmt|;
comment|/* Number of the low-order source_location bits used for a column number.  */
name|unsigned
name|int
name|column_bits
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A set of chronological line_map structures.  */
end_comment

begin_struct
struct|struct
name|line_maps
block|{
name|struct
name|line_map
modifier|*
name|maps
decl_stmt|;
name|unsigned
name|int
name|allocated
decl_stmt|;
name|unsigned
name|int
name|used
decl_stmt|;
name|unsigned
name|int
name|cache
decl_stmt|;
comment|/* The most recently listed include stack, if any, starts with      LAST_LISTED as the topmost including file.  -1 indicates nothing      has been listed yet.  */
name|int
name|last_listed
decl_stmt|;
comment|/* Depth of the include stack, including the current file.  */
name|unsigned
name|int
name|depth
decl_stmt|;
comment|/* If true, prints an include trace a la -H.  */
name|bool
name|trace_includes
decl_stmt|;
comment|/* Highest source_location "given out".  */
name|source_location
name|highest_location
decl_stmt|;
comment|/* Start of line of highest source_location "given out".  */
name|source_location
name|highest_line
decl_stmt|;
comment|/* The maximum column number we can quickly allocate.  Higher numbers      may require allocating a new line_map.  */
name|unsigned
name|int
name|max_column_hint
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize a line map set.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|linemap_init
parameter_list|(
name|struct
name|line_maps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a line map set.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|linemap_free
parameter_list|(
name|struct
name|line_maps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check for and warn about line_maps entered but not exited.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|linemap_check_files_exited
parameter_list|(
name|struct
name|line_maps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a source_location for the start (i.e. column==0) of    (physical) line TO_LINE in the current source file (as in the    most recent linemap_add).   MAX_COLUMN_HINT is the highest column    number we expect to use in this line (but it does not change    the highest_location).  */
end_comment

begin_function_decl
specifier|extern
name|source_location
name|linemap_line_start
parameter_list|(
name|struct
name|line_maps
modifier|*
name|set
parameter_list|,
name|unsigned
name|int
name|to_line
parameter_list|,
name|unsigned
name|int
name|max_column_hint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a mapping of logical source line to physical source file and    line number.     The text pointed to by TO_FILE must have a lifetime    at least as long as the final call to lookup_line ().  An empty    TO_FILE means standard input.  If reason is LC_LEAVE, and    TO_FILE is NULL, then TO_FILE, TO_LINE and SYSP are given their    natural values considering the file we are returning to.     A call to this function can relocate the previous set of    maps, so any stored line_map pointers should not be used.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|line_map
modifier|*
name|linemap_add
argument_list|(
expr|struct
name|line_maps
operator|*
argument_list|,
expr|enum
name|lc_reason
argument_list|,
name|unsigned
name|int
name|sysp
argument_list|,
specifier|const
name|char
operator|*
name|to_file
argument_list|,
name|unsigned
name|int
name|to_line
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a logical line, returns the map from which the corresponding    (source file, line) pair can be deduced.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|line_map
modifier|*
name|linemap_lookup
parameter_list|(
name|struct
name|line_maps
modifier|*
parameter_list|,
name|source_location
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print the file names and line numbers of the #include commands    which led to the map MAP, if any, to stderr.  Nothing is output if    the most recently listed stack is the same as the current one.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|linemap_print_containing_files
parameter_list|(
name|struct
name|line_maps
modifier|*
parameter_list|,
specifier|const
name|struct
name|line_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a map and a source_location to source line.  */
end_comment

begin_define
define|#
directive|define
name|SOURCE_LINE
parameter_list|(
name|MAP
parameter_list|,
name|LINE
parameter_list|)
define|\
value|((((LINE) - (MAP)->start_location)>> (MAP)->column_bits) + (MAP)->to_line)
end_define

begin_define
define|#
directive|define
name|SOURCE_COLUMN
parameter_list|(
name|MAP
parameter_list|,
name|LINE
parameter_list|)
define|\
value|(((LINE) - (MAP)->start_location)& ((1<< (MAP)->column_bits) - 1))
end_define

begin_comment
comment|/* Returns the last source line within a map.  This is the (last) line    of the #include, or other directive, that caused a map change.  */
end_comment

begin_define
define|#
directive|define
name|LAST_SOURCE_LINE
parameter_list|(
name|MAP
parameter_list|)
define|\
value|SOURCE_LINE (MAP, LAST_SOURCE_LINE_LOCATION (MAP))
end_define

begin_define
define|#
directive|define
name|LAST_SOURCE_LINE_LOCATION
parameter_list|(
name|MAP
parameter_list|)
define|\
value|((((MAP)[1].start_location - 1 - (MAP)->start_location) \& ~((1<< (MAP)->column_bits) - 1))			  \    + (MAP)->start_location)
end_define

begin_comment
comment|/* Returns the map a given map was included from.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_FROM
parameter_list|(
name|SET
parameter_list|,
name|MAP
parameter_list|)
value|(&(SET)->maps[(MAP)->included_from])
end_define

begin_comment
comment|/* Nonzero if the map is at the bottom of the include stack.  */
end_comment

begin_define
define|#
directive|define
name|MAIN_FILE_P
parameter_list|(
name|MAP
parameter_list|)
value|((MAP)->included_from< 0)
end_define

begin_comment
comment|/* Set LOC to a source position that is the same line as the most recent    linemap_line_start, but with the specified TO_COLUMN column number.  */
end_comment

begin_define
define|#
directive|define
name|LINEMAP_POSITION_FOR_COLUMN
parameter_list|(
name|LOC
parameter_list|,
name|SET
parameter_list|,
name|TO_COLUMN
parameter_list|)
value|{ \   unsigned int to_column = (TO_COLUMN); \   struct line_maps *set = (SET); \   if (__builtin_expect (to_column>= set->max_column_hint, 0)) \     (LOC) = linemap_position_for_column (set, to_column); \   else { \     source_location r = set->highest_line; \     r = r + to_column; \     if (r>= set->highest_location) \       set->highest_location = r; \     (LOC) = r;			 \   }}
end_define

begin_function_decl
specifier|extern
name|source_location
name|linemap_position_for_column
parameter_list|(
name|struct
name|line_maps
modifier|*
name|set
parameter_list|,
name|unsigned
name|int
name|to_column
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LIBCPP_LINE_MAP_H  */
end_comment

end_unit

