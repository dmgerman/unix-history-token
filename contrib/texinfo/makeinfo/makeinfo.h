begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* makeinfo.h -- declarations for Makeinfo.    $Id: makeinfo.h,v 1.25 1999/09/18 18:09:22 karl Exp $     Copyright (C) 1996, 97, 98, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAKEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MAKEINFO_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COMPILING_MAKEINFO
end_ifdef

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|,
name|init
parameter_list|)
value|type var = init
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|,
name|init
parameter_list|)
value|extern type var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hardcoded per GNU standards, not dependent on argv[0].  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|progname
argument_list|,
literal|"makeinfo"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|reftype
block|{
name|menu_reference
block|,
name|followed_reference
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_xref_token
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Nonzero means a string is in execution, as opposed to a file. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|executing_string
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means to inhibit writing macro expansions to the output    stream, because it has already been written. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|me_inhibit_expansion
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|expansion
argument_list|()
decl_stmt|,
modifier|*
name|text_expansion
argument_list|()
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Current output stream. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|FILE
operator|*
argument_list|,
name|output_stream
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|pretty_output_filename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Current output file name.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|current_output_filename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Output paragraph buffer. */
end_comment

begin_macro
name|DECLARE
argument_list|(
argument|unsigned char *
argument_list|,
argument|output_paragraph
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Offset into OUTPUT_PARAGRAPH. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_paragraph_offset
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The output paragraph "cursor" horizontal position. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_column
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Position in the output file. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_position
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The offset into OUTPUT_PARAGRAPH where we have a meta character    produced by a markup such as @code or @dfn.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|meta_char_pos
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means output_paragraph contains text. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|paragraph_is_open
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that `start_paragraph' MUST be called before we pay    any attention to `close_paragraph' calls. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|must_start_paragraph
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we have seen "@top" once already. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|top_node_seen
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we have seen a non-"@top" node already. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|non_top_node_seen
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero indicates that indentation is temporarily turned off. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|no_indent
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero indicates that filling a line also indents the new line. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|indented_fill
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means forcing output text to be flushright. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|force_flush_right
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The amount of indentation to apply at the start of each line. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|current_indent
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The column at which long lines are broken. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|fill_column
argument_list|,
literal|72
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that words are not to be split, even in long lines.  This    gets changed for cm_w (). */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|non_splitting_words
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Amount by which @example indentation increases/decreases. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|default_indentation_increment
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we are currently hacking the insides of an    insertion which would use a fixed width font. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|in_fixed_width_font
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero if we are currently processing a multitable command */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|multitable_active
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we're generating HTML. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|html
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means escape characters in HTML output. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|escape_html
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|escape_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* do HTML escapes */
end_comment

begin_comment
comment|/* Nonzero means that the use of paragraph_start_indent is inhibited.    @example uses this to line up the left columns of the example text.    A negative value for this variable is incremented each time it is used.    @noindent uses this to inhibit indentation for a single paragraph.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|inhibit_paragraph_indentation
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero indicates that filling will take place on long lines. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|filling_enabled
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The current node's node name. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|current_node
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Command name in the process of being hacked. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|command
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero if the last character inserted has the syntax class of NEWLINE. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|last_char_was_newline
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The current input file state. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|input_filename
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|input_text
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|input_text_length
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|input_text_offset
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|line_number
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|curchar
parameter_list|()
value|input_text[input_text_offset]
end_define

begin_escape
end_escape

begin_comment
comment|/* A colon separated list of directories to search for files included    with @include.  This can be controlled with the `-I' option to makeinfo. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|include_files_path
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The filename of the current input file.  This is never freed. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|node_filename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* Nonzero means do not output "Node: Foo" for node separations, that    is, generate plain text.  (--no-headers) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|no_headers
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we process @html and @rawhtml even when not    generating HTML.  (--ifhtml) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_html
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we process @ifinfo even when generating HTML.    (--ifinfo) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we process @tex and @iftex.  (--iftex) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_tex
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Maximum number of references to a single node before complaining.    (--reference-limit) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|reference_warning_limit
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Default is to check node references.  (--no-validate) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|validating
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means print information about what is going on.  (--verbose) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|verbose_mode
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means prefix each @chapter, ... with a number like 1. (--number-sections) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|number_sections
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means expand node names and references while validating.    This will avoid errors when the Texinfo document uses features    like @@ and @value inconsistently in node names, but will slow    the program by about 80%.  You HAVE been warned.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|expensive_validation
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* C's standard macros don't check to make sure that the characters being    changed are within range.  So I have to check explicitly. */
end_comment

begin_define
define|#
directive|define
name|coerce_to_upper
parameter_list|(
name|c
parameter_list|)
value|((islower(c) ? toupper(c) : (c)))
end_define

begin_define
define|#
directive|define
name|coerce_to_lower
parameter_list|(
name|c
parameter_list|)
value|((isupper(c) ? tolower(c) : (c)))
end_define

begin_define
define|#
directive|define
name|control_character_bit
value|0x40
end_define

begin_comment
comment|/* %01000000, must be off. */
end_comment

begin_define
define|#
directive|define
name|meta_character_bit
value|0x080
end_define

begin_comment
comment|/* %10000000, must be on.  */
end_comment

begin_define
define|#
directive|define
name|CTL
parameter_list|(
name|c
parameter_list|)
value|((c)& (~control_character_bit))
end_define

begin_define
define|#
directive|define
name|UNCTL
parameter_list|(
name|c
parameter_list|)
value|coerce_to_upper(((c)|control_character_bit))
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | (meta_character_bit))
end_define

begin_define
define|#
directive|define
name|UNMETA
parameter_list|(
name|c
parameter_list|)
value|((c)& (~meta_character_bit))
end_define

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|((c) == '\t' || (c) == ' ')
end_define

begin_define
define|#
directive|define
name|sentence_ender
parameter_list|(
name|c
parameter_list|)
value|((c) == '.'  || (c) == '?' || (c) == '!')
end_define

begin_define
define|#
directive|define
name|cr_or_whitespace
parameter_list|(
name|c
parameter_list|)
value|(whitespace(c) || (c) == '\r' || (c) == '\n')
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|isletter
end_ifndef

begin_define
define|#
directive|define
name|isletter
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 'A'&& (c)<= 'Z') || ((c)>= 'a'&& (c)<= 'z'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isupper
end_ifndef

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isdigit
end_ifndef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|digit_value
end_ifndef

begin_define
define|#
directive|define
name|digit_value
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HTML_SAFE
value|"$-_.+!*'()"
end_define

begin_define
define|#
directive|define
name|URL_SAFE_CHAR
parameter_list|(
name|ch
parameter_list|)
value|(isalnum (ch) || strchr (HTML_SAFE, ch))
end_define

begin_define
define|#
directive|define
name|COMMAND_PREFIX
value|'@'
end_define

begin_comment
comment|/* Stuff for splitting large files. */
end_comment

begin_define
define|#
directive|define
name|SPLIT_SIZE_THRESHOLD
value|70000
end_define

begin_comment
comment|/* What's good enough for Stallman... */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SPLIT_SIZE
value|50000
end_define

begin_comment
comment|/* Is probably good enough for me. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|splitting
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Defaults to true for now. */
end_comment

begin_define
define|#
directive|define
name|command_char
parameter_list|(
name|c
parameter_list|)
value|(!cr_or_whitespace(c) \&& (c) != '{' \&& (c) != '}' \&& (c) != '=')
end_define

begin_define
define|#
directive|define
name|skip_whitespace
parameter_list|()
define|\
value|while ((input_text_offset != input_text_length)&& \              whitespace (curchar())) \        input_text_offset++
end_define

begin_define
define|#
directive|define
name|skip_whitespace_and_newlines
parameter_list|()
define|\
value|do { \    while (input_text_offset != input_text_length \&& cr_or_whitespace (curchar ())) \       { \          if (curchar () == '\n') \            line_number++; \          input_text_offset++; \       } \    } while (0)
end_define

begin_comment
comment|/* Return nonzero if STRING is the text at input_text + input_text_offset,    else zero. */
end_comment

begin_define
define|#
directive|define
name|looking_at
parameter_list|(
name|string
parameter_list|)
define|\
value|(strncmp (input_text + input_text_offset, string, strlen (string)) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MAKEINFO_H */
end_comment

end_unit

