begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Map logical line numbers to (source file, line number) pairs.    Copyright (C) 2001    Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LINE_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LINE_MAP_H
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
comment|/* The logical line FROM_LINE maps to physical source file TO_FILE at    line TO_LINE, and subsequently one-to-one until the next line_map    structure in the set.  INCLUDED_FROM is an index into the set that    gives the line mapping at whose end the current one was included.    File(s) at the bottom of the include stack have this set to -1.    REASON is the reason for creation of this line map, SYSP is one for    a system header, two for a C system header file that therefore    needs to be extern "C" protected in C++, and zero otherwise.  */
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
name|unsigned
name|int
name|from_line
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
name|unsigned
name|char
name|sysp
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
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize a line map set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_line_maps
name|PARAMS
argument_list|(
operator|(
expr|struct
name|line_maps
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a line map set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free_line_maps
name|PARAMS
argument_list|(
operator|(
expr|struct
name|line_maps
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a mapping of logical source line to physical source file and    line number.  The text pointed to by TO_FILE must have a lifetime    at least as long as the line maps.  If reason is LC_LEAVE, and    TO_FILE is NULL, then TO_FILE, TO_LINE and SYSP are given their    natural values considering the file we are returning to.     FROM_LINE should be monotonic increasing across calls to this    function.  A call to this function can relocate the previous set of    maps, so any stored line_map pointers should not be used.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|line_map
modifier|*
name|add_line_map
name|PARAMS
argument_list|(
operator|(
expr|struct
name|line_maps
operator|*
operator|,
expr|enum
name|lc_reason
operator|,
name|unsigned
name|int
name|sysp
operator|,
name|unsigned
name|int
name|from_line
operator|,
specifier|const
name|char
operator|*
name|to_file
operator|,
name|unsigned
name|int
name|to_line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a logical line, returns the map from which the corresponding    (source file, line) pair can be deduced.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|line_map
modifier|*
name|lookup_line
name|PARAMS
argument_list|(
operator|(
expr|struct
name|line_maps
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print the file names and line numbers of the #include commands    which led to the map MAP, if any, to stderr.  Nothing is output if    the most recently listed stack is the same as the current one.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_containing_files
name|PARAMS
argument_list|(
operator|(
expr|struct
name|line_maps
operator|*
operator|,
specifier|const
expr|struct
name|line_map
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Converts a map and logical line to source line.  */
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
value|((LINE) + (MAP)->to_line - (MAP)->from_line)
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
value|SOURCE_LINE ((MAP), (MAP)[1].from_line - 1)
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
comment|/* Non-zero if the map is at the bottom of the include stack.  */
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
comment|/* The current line map.  Saves a call to lookup_line if the caller is    sure he is in the scope of the current map.  */
end_comment

begin_define
define|#
directive|define
name|CURRENT_LINE_MAP
parameter_list|(
name|MAPS
parameter_list|)
value|((MAPS)->maps + (MAPS)->used - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !GCC_LINE_MAP_H  */
end_comment

end_unit

