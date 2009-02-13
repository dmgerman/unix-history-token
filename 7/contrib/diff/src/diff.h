begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared definitions for GNU DIFF     Copyright (C) 1988, 1989, 1991, 1992, 1993, 1994, 1995, 1998, 2001,    2002, 2004 Free Software Foundation, Inc.     This file is part of GNU DIFF.     GNU DIFF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU DIFF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unlocked-io.h>
end_include

begin_comment
comment|/* What kind of changes a hunk contains.  */
end_comment

begin_enum
enum|enum
name|changes
block|{
comment|/* No changes: lines common to both files.  */
name|UNCHANGED
block|,
comment|/* Deletes only: lines taken from just the first file.  */
name|OLD
block|,
comment|/* Inserts only: lines taken from just the second file.  */
name|NEW
block|,
comment|/* Both deletes and inserts: a hunk containing both old and new lines.  */
name|CHANGED
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Variables for command line options */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDIFF_MAIN
end_ifndef

begin_define
define|#
directive|define
name|XTERN
value|extern
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XTERN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|output_style
block|{
comment|/* No output style specified.  */
name|OUTPUT_UNSPECIFIED
block|,
comment|/* Default output style.  */
name|OUTPUT_NORMAL
block|,
comment|/* Output the differences with lines of context before and after (-c).  */
name|OUTPUT_CONTEXT
block|,
comment|/* Output the differences in a unified context diff format (-u).  */
name|OUTPUT_UNIFIED
block|,
comment|/* Output the differences as commands suitable for `ed' (-e).  */
name|OUTPUT_ED
block|,
comment|/* Output the diff as a forward ed script (-f).  */
name|OUTPUT_FORWARD_ED
block|,
comment|/* Like -f, but output a count of changed lines in each "command" (-n).  */
name|OUTPUT_RCS
block|,
comment|/* Output merged #ifdef'd file (-D).  */
name|OUTPUT_IFDEF
block|,
comment|/* Output sdiff style (-y).  */
name|OUTPUT_SDIFF
block|}
enum|;
end_enum

begin_comment
comment|/* True for output styles that are robust,    i.e. can handle a file that ends in a non-newline.  */
end_comment

begin_define
define|#
directive|define
name|ROBUST_OUTPUT_STYLE
parameter_list|(
name|S
parameter_list|)
value|((S) != OUTPUT_ED&& (S) != OUTPUT_FORWARD_ED)
end_define

begin_decl_stmt
name|XTERN
name|enum
name|output_style
name|output_style
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if output cannot be generated for identical files.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|no_diff_means_no_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines of context to show in each set of diffs.    This is zero when context is not to be shown.  */
end_comment

begin_decl_stmt
name|XTERN
name|lin
name|context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Consider all files as text files (-a).    Don't interpret codes over 0177 as implying a "binary file".  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|text
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines to keep in identical prefix and suffix.  */
end_comment

begin_decl_stmt
name|XTERN
name|lin
name|horizon_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The significance of white space during comparisons.  */
end_comment

begin_decl_stmt
name|XTERN
name|enum
type|{
comment|/* All white space is significant (the default).  */
name|IGNORE_NO_WHITE_SPACE
decl_stmt|,
comment|/* Ignore changes due to tab expansion (-E).  */
name|IGNORE_TAB_EXPANSION
decl_stmt|,
comment|/* Ignore changes in horizontal white space (-b).  */
name|IGNORE_SPACE_CHANGE
decl_stmt|,
comment|/* Ignore all horizontal white space (-w).  */
name|IGNORE_ALL_SPACE
end_decl_stmt

begin_empty_stmt
unit|} ignore_white_space
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Ignore changes that affect only blank lines (-B).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|ignore_blank_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Files can be compared byte-by-byte, as if they were binary.    This depends on various options.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|files_can_be_treated_as_binary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore differences in case of letters (-i).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|ignore_case
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore differences in case of letters in file names.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|ignore_file_name_case
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File labels for `-c' output headers (--label).  */
end_comment

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|file_label
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Regexp to identify function-header lines (-F).  */
end_comment

begin_decl_stmt
name|XTERN
name|struct
name|re_pattern_buffer
name|function_regexp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore changes that affect only lines matching this regexp (-I).  */
end_comment

begin_decl_stmt
name|XTERN
name|struct
name|re_pattern_buffer
name|ignore_regexp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Say only whether files differ, not how (-q).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|brief
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand tabs in the output so the text lines up properly    despite the characters added to the front of each line (-t).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|expand_tabs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of columns between tab stops.  */
end_comment

begin_decl_stmt
name|XTERN
name|size_t
name|tabsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use a tab in the output, rather than a space, before the text of an    input line, so as to keep the proper alignment in the input line    without changing the characters in it (-T).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|initial_tab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove trailing carriage returns from input.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|strip_trailing_cr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In directory comparison, specify file to start with (-S).    This is used for resuming an aborted comparison.    All file names less than this name are ignored.  */
end_comment

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|starting_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pipe each file's output through pr (-l).  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|paginate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line group formats for unchanged, old, new, and changed groups.  */
end_comment

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|group_format
index|[
name|CHANGED
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line formats for unchanged, old, and new lines.  */
end_comment

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|line_format
index|[
name|NEW
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If using OUTPUT_SDIFF print extra information to help the sdiff filter.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|sdiff_merge_assist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell OUTPUT_SDIFF to show only the left version of common lines.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|left_column
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell OUTPUT_SDIFF to not show common lines.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|suppress_common_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The half line width and column 2 offset for OUTPUT_SDIFF.  */
end_comment

begin_decl_stmt
name|XTERN
name|size_t
name|sdiff_half_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XTERN
name|size_t
name|sdiff_column2_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String containing all the command options diff received,    with spaces between and at the beginning but none at the end.    If there were no options given, this string is empty.  */
end_comment

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|switch_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use heuristics for better speed with large files with a small    density of changes.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|speed_large_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Patterns that match file names to be excluded.  */
end_comment

begin_decl_stmt
name|XTERN
name|struct
name|exclude
modifier|*
name|excluded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't discard lines.  This makes things slower (sometimes much    slower) but will find a guaranteed minimal set of changes.  */
end_comment

begin_decl_stmt
name|XTERN
name|bool
name|minimal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of program the user invoked (for error messages).  */
end_comment

begin_decl_stmt
name|XTERN
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The strftime format to use for time strings.  */
end_comment

begin_decl_stmt
name|XTERN
name|char
specifier|const
modifier|*
name|time_format
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The result of comparison is an "edit script": a chain of `struct change'.    Each `struct change' represents one place where some lines are deleted    and some are inserted.     LINE0 and LINE1 are the first affected lines in the two files (origin 0).    DELETED is the number of lines deleted here from file 0.    INSERTED is the number of lines inserted here in file 1.     If DELETED is 0 then LINE0 is the number of the line before    which the insertion was done; vice versa for INSERTED and LINE1.  */
end_comment

begin_struct
struct|struct
name|change
block|{
name|struct
name|change
modifier|*
name|link
decl_stmt|;
comment|/* Previous or next edit command  */
name|lin
name|inserted
decl_stmt|;
comment|/* # lines of file 1 changed here.  */
name|lin
name|deleted
decl_stmt|;
comment|/* # lines of file 0 changed here.  */
name|lin
name|line0
decl_stmt|;
comment|/* Line number of 1st deleted line.  */
name|lin
name|line1
decl_stmt|;
comment|/* Line number of 1st inserted line.  */
name|bool
name|ignore
decl_stmt|;
comment|/* Flag used in context.c.  */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Structures that describe the input files.  */
end_comment

begin_comment
comment|/* Data on one input file being compared.  */
end_comment

begin_struct
struct|struct
name|file_data
block|{
name|int
name|desc
decl_stmt|;
comment|/* File descriptor  */
name|char
specifier|const
modifier|*
name|name
decl_stmt|;
comment|/* File name  */
name|struct
name|stat
name|stat
decl_stmt|;
comment|/* File status */
comment|/* Buffer in which text of file is read.  */
name|word
modifier|*
name|buffer
decl_stmt|;
comment|/* Allocated size of buffer, in bytes.  Always a multiple of        sizeof *buffer.  */
name|size_t
name|bufsize
decl_stmt|;
comment|/* Number of valid bytes now in the buffer.  */
name|size_t
name|buffered
decl_stmt|;
comment|/* Array of pointers to lines in the file.  */
name|char
specifier|const
modifier|*
modifier|*
name|linbuf
decl_stmt|;
comment|/* linbuf_base<= buffered_lines<= valid_lines<= alloc_lines.        linebuf[linbuf_base ... buffered_lines - 1] are possibly differing.        linebuf[linbuf_base ... valid_lines - 1] contain valid data.        linebuf[linbuf_base ... alloc_lines - 1] are allocated.  */
name|lin
name|linbuf_base
decl_stmt|,
name|buffered_lines
decl_stmt|,
name|valid_lines
decl_stmt|,
name|alloc_lines
decl_stmt|;
comment|/* Pointer to end of prefix of this file to ignore when hashing.  */
name|char
specifier|const
modifier|*
name|prefix_end
decl_stmt|;
comment|/* Count of lines in the prefix.        There are this many lines in the file before linbuf[0].  */
name|lin
name|prefix_lines
decl_stmt|;
comment|/* Pointer to start of suffix of this file to ignore when hashing.  */
name|char
specifier|const
modifier|*
name|suffix_begin
decl_stmt|;
comment|/* Vector, indexed by line number, containing an equivalence code for        each line.  It is this vector that is actually compared with that        of another file to generate differences.  */
name|lin
modifier|*
name|equivs
decl_stmt|;
comment|/* Vector, like the previous one except that        the elements for discarded lines have been squeezed out.  */
name|lin
modifier|*
name|undiscarded
decl_stmt|;
comment|/* Vector mapping virtual line numbers (not counting discarded lines)        to real ones (counting those lines).  Both are origin-0.  */
name|lin
modifier|*
name|realindexes
decl_stmt|;
comment|/* Total number of nondiscarded lines.  */
name|lin
name|nondiscarded_lines
decl_stmt|;
comment|/* Vector, indexed by real origin-0 line number,        containing 1 for a line that is an insertion or a deletion.        The results of comparison are stored here.  */
name|char
modifier|*
name|changed
decl_stmt|;
comment|/* 1 if file ends in a line with no final newline.  */
name|bool
name|missing_newline
decl_stmt|;
comment|/* 1 if at end of file.  */
name|bool
name|eof
decl_stmt|;
comment|/* 1 more than the maximum equivalence value used for this or its        sibling file.  */
name|lin
name|equiv_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The file buffer, considered as an array of bytes rather than    as an array of words.  */
end_comment

begin_define
define|#
directive|define
name|FILE_BUFFER
parameter_list|(
name|f
parameter_list|)
value|((char *) (f)->buffer)
end_define

begin_comment
comment|/* Data on two input files being compared.  */
end_comment

begin_struct
struct|struct
name|comparison
block|{
name|struct
name|file_data
name|file
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|comparison
specifier|const
modifier|*
name|parent
decl_stmt|;
comment|/* parent, if a recursive comparison */
block|}
struct|;
end_struct

begin_comment
comment|/* Describe the two files currently being compared.  */
end_comment

begin_decl_stmt
name|XTERN
name|struct
name|file_data
name|files
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Stdio stream to output diffs to.  */
end_comment

begin_decl_stmt
name|XTERN
name|FILE
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Declare various functions.  */
end_comment

begin_comment
comment|/* analyze.c */
end_comment

begin_function_decl
name|int
name|diff_2_files
parameter_list|(
name|struct
name|comparison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* context.c */
end_comment

begin_function_decl
name|void
name|print_context_header
parameter_list|(
name|struct
name|file_data
type|[]
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_context_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dir.c */
end_comment

begin_function_decl
name|int
name|diff_dirs
parameter_list|(
name|struct
name|comparison
specifier|const
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|comparison
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ed.c */
end_comment

begin_function_decl
name|void
name|print_ed_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pr_forward_ed_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ifdef.c */
end_comment

begin_function_decl
name|void
name|print_ifdef_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* io.c */
end_comment

begin_function_decl
name|void
name|file_block_read
parameter_list|(
name|struct
name|file_data
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|read_files
parameter_list|(
name|struct
name|file_data
type|[]
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* normal.c */
end_comment

begin_function_decl
name|void
name|print_normal_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rcs.c */
end_comment

begin_function_decl
name|void
name|print_rcs_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* side.c */
end_comment

begin_function_decl
name|void
name|print_sdiff_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|change_letter
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|pr_program
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|concat
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dir_file_pathname
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|lines_differ
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lin
name|translate_line_number
parameter_list|(
name|struct
name|file_data
specifier|const
modifier|*
parameter_list|,
name|lin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|change
modifier|*
name|find_change
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|change
modifier|*
name|find_reverse_change
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|zalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|changes
name|analyze_hunk
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|,
name|lin
modifier|*
parameter_list|,
name|lin
modifier|*
parameter_list|,
name|lin
modifier|*
parameter_list|,
name|lin
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|begin_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_script
parameter_list|(
name|struct
name|change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|finish_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|message
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|message5
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|output_1_line
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror_with_name
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfatal_with_name
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|print_1_line
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_message_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_number_range
parameter_list|(
name|char
parameter_list|,
name|struct
name|file_data
modifier|*
parameter_list|,
name|lin
parameter_list|,
name|lin
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|print_script
argument_list|(
expr|struct
name|change
operator|*
argument_list|,
expr|struct
name|change
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|change
operator|*
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|change
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setup_output
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|translate_range
parameter_list|(
name|struct
name|file_data
specifier|const
modifier|*
parameter_list|,
name|lin
parameter_list|,
name|lin
parameter_list|,
name|long
name|int
modifier|*
parameter_list|,
name|long
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

