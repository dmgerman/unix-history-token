begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared definitions for GNU DIFF    Copyright (C) 1988, 89, 91, 92, 93, 97 Free Software Foundation, Inc.  This file is part of GNU DIFF.  GNU DIFF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU DIFF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU DIFF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"regex.h"
end_include

begin_define
define|#
directive|define
name|TAB_WIDTH
value|8
end_define

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
name|EXTERN
value|extern
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|output_style
block|{
comment|/* Default output style.  */
name|OUTPUT_NORMAL
block|,
comment|/* Output the differences with lines of context before and after (-c).  */
name|OUTPUT_CONTEXT
block|,
comment|/* Output the differences in a unified context diff format (-u). */
name|OUTPUT_UNIFIED
block|,
comment|/* Output the differences as commands suitable for `ed' (-e).  */
name|OUTPUT_ED
block|,
comment|/* Output the diff as a forward ed script (-f).  */
name|OUTPUT_FORWARD_ED
block|,
comment|/* Like -f, but output a count of changed lines in each "command" (-n). */
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
name|EXTERN
name|enum
name|output_style
name|output_style
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if output cannot be generated for identical files.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|no_diff_means_no_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines of context to show in each set of diffs.    This is zero when context is not to be shown.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Consider all files as text files (-a).    Don't interpret codes over 0177 as implying a "binary file".  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|always_text_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines to keep in identical prefix and suffix.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|horizon_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore changes in horizontal white space (-b).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_space_change_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore all horizontal white space (-w).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_all_space_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore changes that affect only blank lines (-B).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_blank_lines_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if lines may match even if their contents do not match exactly.    This depends on various options.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_some_line_changes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if files may match even if their contents are not byte-for-byte identical.    This depends on various options.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_some_changes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore differences in case of letters (-i).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ignore_case_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File labels for `-c' output headers (-L).  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|file_label
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|regexp_list
block|{
name|struct
name|re_pattern_buffer
name|buf
decl_stmt|;
name|struct
name|regexp_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Regexp to identify function-header lines (-F).  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|regexp_list
modifier|*
name|function_regexp_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore changes that affect only lines matching this regexp (-I).  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|regexp_list
modifier|*
name|ignore_regexp_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Say only whether files differ, not how (-q).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|no_details_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report files compared that match (-s).    Normally nothing is output when that happens.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|print_file_same_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output the differences with exactly 8 columns added to each line    so that any tabs in the text line up properly (-T).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|tab_align_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand tabs in the output so the text lines up properly    despite the characters added to the front of each line (-t).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|tab_expand_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In directory comparison, specify file to start with (-S).    All file names less than this name are ignored.  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|dir_start_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If a file is new (appears in only one dir)    include its entire contents (-N).    Then `patch' would create the file with appropriate contents.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|entire_new_file_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If a file is new (appears in only the second dir)    include its entire contents (-P).    Then `patch' would create the file with appropriate contents.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|unidirectional_new_file_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pipe each file's output through pr (-l).  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|paginate_flag
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|line_class
block|{
comment|/* Lines taken from just the first file.  */
name|OLD
block|,
comment|/* Lines taken from just the second file.  */
name|NEW
block|,
comment|/* Lines common to both files.  */
name|UNCHANGED
block|,
comment|/* A hunk containing both old and new lines (line groups only).  */
name|CHANGED
block|}
enum|;
end_enum

begin_comment
comment|/* Line group formats for old, new, unchanged, and changed groups.  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
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
comment|/* Line formats for old, new, and unchanged lines.  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|line_format
index|[
name|UNCHANGED
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If using OUTPUT_SDIFF print extra information to help the sdiff filter. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|sdiff_help_sdiff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell OUTPUT_SDIFF to show only the left version of common lines. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|sdiff_left_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell OUTPUT_SDIFF to not show common lines. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|sdiff_skip_common_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The half line width and column 2 offset for OUTPUT_SDIFF.  */
end_comment

begin_decl_stmt
name|EXTERN
name|unsigned
name|sdiff_half_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|unsigned
name|sdiff_column2_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String containing all the command options diff received,    with spaces between and at the beginning but none at the end.    If there were no options given, this string is empty.  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|switch_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means use heuristics for better speed.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|heuristic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of program the user invoked (for error messages).  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|diff_program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Jump buffer for nonlocal exits. */
end_comment

begin_decl_stmt
name|EXTERN
name|jmp_buf
name|diff_abort_buf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DIFF_ABORT
parameter_list|(
name|retval
parameter_list|)
value|longjmp(diff_abort_buf, retval)
end_define

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
name|int
name|inserted
decl_stmt|;
comment|/* # lines of file 1 changed here.  */
name|int
name|deleted
decl_stmt|;
comment|/* # lines of file 0 changed here.  */
name|int
name|line0
decl_stmt|;
comment|/* Line number of 1st deleted line.  */
name|int
name|line1
decl_stmt|;
comment|/* Line number of 1st inserted line.  */
name|char
name|ignore
decl_stmt|;
comment|/* Flag used in context.c */
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
comment|/* File status from fstat()  */
name|int
name|dir_p
decl_stmt|;
comment|/* nonzero if file is a directory  */
comment|/* Buffer in which text of file is read.  */
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Allocated size of buffer.  */
name|size_t
name|bufsize
decl_stmt|;
comment|/* Number of valid characters now in the buffer. */
name|size_t
name|buffered_chars
decl_stmt|;
comment|/* Array of pointers to lines in the file.  */
name|char
specifier|const
modifier|*
modifier|*
name|linbuf
decl_stmt|;
comment|/* linbuf_base<= buffered_lines<= valid_lines<= alloc_lines.        linebuf[linbuf_base ... buffered_lines - 1] are possibly differing.        linebuf[linbuf_base ... valid_lines - 1] contain valid data.        linebuf[linbuf_base ... alloc_lines - 1] are allocated.  */
name|int
name|linbuf_base
decl_stmt|,
name|buffered_lines
decl_stmt|,
name|valid_lines
decl_stmt|,
name|alloc_lines
decl_stmt|;
comment|/* Pointer to end of prefix of this file to ignore when hashing. */
name|char
specifier|const
modifier|*
name|prefix_end
decl_stmt|;
comment|/* Count of lines in the prefix.        There are this many lines in the file before linbuf[0].  */
name|int
name|prefix_lines
decl_stmt|;
comment|/* Pointer to start of suffix of this file to ignore when hashing. */
name|char
specifier|const
modifier|*
name|suffix_begin
decl_stmt|;
comment|/* Vector, indexed by line number, containing an equivalence code for        each line.  It is this vector that is actually compared with that        of another file to generate differences. */
name|int
modifier|*
name|equivs
decl_stmt|;
comment|/* Vector, like the previous one except that        the elements for discarded lines have been squeezed out.  */
name|int
modifier|*
name|undiscarded
decl_stmt|;
comment|/* Vector mapping virtual line numbers (not counting discarded lines)        to real ones (counting those lines).  Both are origin-0.  */
name|int
modifier|*
name|realindexes
decl_stmt|;
comment|/* Total number of nondiscarded lines. */
name|int
name|nondiscarded_lines
decl_stmt|;
comment|/* Vector, indexed by real origin-0 line number,        containing 1 for a line that is an insertion or a deletion.        The results of comparison are stored here.  */
name|char
modifier|*
name|changed_flag
decl_stmt|;
comment|/* 1 if file ends in a line with no final newline. */
name|int
name|missing_newline
decl_stmt|;
comment|/* 1 more than the maximum equivalence value used for this or its        sibling file. */
name|int
name|equiv_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Describe the two files currently being compared.  */
end_comment

begin_decl_stmt
name|EXTERN
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
name|EXTERN
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

begin_decl_stmt
name|int
name|diff_2_files
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* context.c */
end_comment

begin_decl_stmt
name|void
name|print_context_header
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_context_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diff.c */
end_comment

begin_decl_stmt
name|int
name|excluded_filename
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dir.c */
end_comment

begin_decl_stmt
name|int
name|diff_dirs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
specifier|const
index|[]
operator|,
name|int
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ed.c */
end_comment

begin_decl_stmt
name|void
name|print_ed_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pr_forward_ed_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ifdef.c */
end_comment

begin_decl_stmt
name|void
name|print_ifdef_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* io.c */
end_comment

begin_decl_stmt
name|int
name|read_files
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sip
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|slurp
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* normal.c */
end_comment

begin_decl_stmt
name|void
name|print_normal_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcs.c */
end_comment

begin_decl_stmt
name|void
name|print_rcs_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* side.c */
end_comment

begin_decl_stmt
name|void
name|print_sdiff_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
name|VOID
modifier|*
name|xmalloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
modifier|*
name|xrealloc
name|PARAMS
argument_list|(
operator|(
name|VOID
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|concat
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dir_file_pathname
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|change_letter
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line_cmp
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|translate_line_number
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|change
modifier|*
name|find_change
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|change
modifier|*
name|find_reverse_change
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|analyze_hunk
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|begin_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|debug_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|diff_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|finish_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|message
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|message5
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|output_1_line
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|perror_with_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pfatal_with_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_1_line
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_message_queue
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_number_range
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_data
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_script
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|,
expr|struct
name|change
operator|*
operator|(
operator|*
operator|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|change
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setup_output
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|translate_range
name|PARAMS
argument_list|(
operator|(
expr|struct
name|file_data
specifier|const
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* version.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|diff_version_string
index|[]
decl_stmt|;
end_decl_stmt

end_unit

