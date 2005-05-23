begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* makeinfo.h -- declarations for Makeinfo.    $Id: makeinfo.h,v 1.17 2004/11/30 02:03:23 karl Exp $     Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
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
comment|/* Number of lines in the output.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_line_number
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|node_line_number
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
comment|/* Nonzero means that we suppress the indentation of the first paragraph    following any section heading.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|do_first_par_indent
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
name|example_indentation_increment
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Amount by which @table, @defun, etc. indentation increases/decreases.  */
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
comment|/* Amount by which xml indentation increases/decreases.    Zero means unnecessary whitespace is compressed.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|xml_indentation_increment
argument_list|,
literal|2
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
comment|/* Nonzero means that we're generating HTML. (--html) */
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
comment|/* Nonzero means that we're generating XML. (--xml) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|xml
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means that we're generating DocBook. (--docbook) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|docbook
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means true 8-bit output for Info and plain text.    (--enable-encoding) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|enable_encoding
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

begin_comment
comment|/* Access key number for next menu entry to be generated (1 to 9, or 10 to    mean no access key)  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|next_menu_item_number
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* Nonzero if we have seen an @titlepage command.  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|titlepage_cmd_present
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* @copying ... @end copying. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|copying_text
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* @documentdescription ... @end documentdescription. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|document_description
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

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|toplevel_output_filename
argument_list|,
name|NULL
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
comment|/* Name of CSS file to include, if any.  (--css-include).  */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|css_include
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* Nonzero means that we process @docbook and @ifdocbook.  (--ifdocbook) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_docbook
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
comment|/* Positive means process @ifinfo (even if not generating Info);    zero means don't process @ifinfo (even if we are);    -1 means we don't know yet.  (--ifinfo) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_info
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Positive means process @ifplaintext (even if not generating plain text);    zero means we don't process @ifplaintext (even if we are);    -1 means we don't know yet.  (--ifplaintext) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_plaintext
argument_list|,
operator|-
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
comment|/* Nonzero means that we process @xml and @ifxml.  (--ifxml) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|process_xml
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
comment|/* Nonzero means prefix each @chapter, ... with a number like    1, 1.1, etc.  (--number-sections) */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|number_sections
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero means split size.  When zero, DEFAULT_SPLIT_SIZE is used. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|split_size
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

begin_comment
comment|/* These characters are not really HTML-safe (with strict XHTML),    and also there are possible collisions.  That's the whole reason we    designed a new conversion scheme in the first place.  But we    nevertheless need to generate the old names.  See    `add_escaped_anchor_name' in html.c.  */
end_comment

begin_define
define|#
directive|define
name|OLD_HTML_SAFE
value|"$-_.+!*'()"
end_define

begin_define
define|#
directive|define
name|OLD_URL_SAFE_CHAR
parameter_list|(
name|ch
parameter_list|)
value|(strchr (OLD_HTML_SAFE, ch))
end_define

begin_comment
comment|/* For the current/stable scheme.  */
end_comment

begin_define
define|#
directive|define
name|URL_SAFE_CHAR
parameter_list|(
name|ch
parameter_list|)
value|(isalnum (ch))
end_define

begin_define
define|#
directive|define
name|COMMAND_PREFIX
value|'@'
end_define

begin_define
define|#
directive|define
name|END_VERBATIM
value|"end verbatim"
end_define

begin_comment
comment|/* Stuff for splitting large files.  The numbers for Emacs    texinfo-format-buffer are much smaller, but memory capacities have    increased so much, 50k info files seem a bit tiny these days.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SPLIT_SIZE
value|300000
end_define

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

begin_comment
comment|/* Any list with a member named `next'.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|generic_list
block|{
name|struct
name|generic_list
modifier|*
name|next
decl_stmt|;
block|}
name|GENERIC_LIST
typedef|;
end_typedef

begin_comment
comment|/* Reverse the order of a list.  */
end_comment

begin_function_decl
specifier|extern
name|GENERIC_LIST
modifier|*
name|reverse_list
parameter_list|(
name|GENERIC_LIST
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Possibly return Local Variables trailer for Info output.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|info_trailer
argument_list|(
name|void
argument_list|)
decl_stmt|,
modifier|*
name|expansion
argument_list|(
name|char
operator|*
name|str
argument_list|,
name|int
name|implicit_code
argument_list|)
decl_stmt|,
modifier|*
name|text_expansion
argument_list|(
name|char
operator|*
name|str
argument_list|)
decl_stmt|,
modifier|*
name|maybe_escaped_expansion
argument_list|(
name|char
operator|*
name|str
argument_list|,
name|int
name|implicit_code
argument_list|,
name|int
name|do_escape_html
argument_list|)
decl_stmt|,
modifier|*
name|full_expansion
argument_list|(
name|char
operator|*
name|str
argument_list|,
name|int
name|implicit_code
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_and_clear
argument_list|(
name|char
operator|*
operator|*
name|pointer
argument_list|)
decl_stmt|,
name|add_word
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|add_char
argument_list|(
name|int
name|character
argument_list|)
decl_stmt|,
name|add_meta_char
argument_list|(
name|int
name|character
argument_list|)
decl_stmt|,
name|close_single_paragraph
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|insert_string
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|,
name|insert
argument_list|(
name|int
name|character
argument_list|)
decl_stmt|,
name|get_rest_of_line
argument_list|(
name|int
name|expand
argument_list|,
name|char
operator|*
operator|*
name|string
argument_list|)
decl_stmt|,
name|add_html_block_elt
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|get_until_in_braces
argument_list|(
name|char
operator|*
name|match
argument_list|,
name|char
operator|*
operator|*
name|string
argument_list|)
decl_stmt|,
name|get_until_in_line
argument_list|(
name|int
name|expand
argument_list|,
name|char
operator|*
name|match
argument_list|,
name|char
operator|*
operator|*
name|string
argument_list|)
decl_stmt|,
name|canon_white
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|discard_until
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|indent
argument_list|(
name|int
name|amount
argument_list|)
decl_stmt|,
name|kill_self_indent
argument_list|(
name|int
name|count
argument_list|)
decl_stmt|,
name|backup_input_pointer
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|inhibit_output_flushing
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|uninhibit_output_flushing
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|flush_output
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|start_paragraph
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|close_paragraph
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|close_insertion_paragraph
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_paragraph
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|ignore_blank_line
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|reader_loop
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|discard_braces
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|replace_with_expansion
argument_list|(
name|int
name|from
argument_list|,
name|int
operator|*
name|to
argument_list|)
decl_stmt|,
name|fix_whitespace
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|add_html_elt
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_until
argument_list|(
name|char
operator|*
name|match
argument_list|,
name|char
operator|*
operator|*
name|string
argument_list|)
decl_stmt|,
name|set_paragraph_indent
argument_list|(
name|char
operator|*
name|string
argument_list|)
decl_stmt|,
name|self_delimiting
argument_list|(
name|int
name|character
argument_list|)
decl_stmt|,
name|search_forward
argument_list|(
name|char
operator|*
name|string
argument_list|,
name|int
name|from
argument_list|)
decl_stmt|,
name|search_forward_until_pos
argument_list|(
name|char
operator|*
name|string
argument_list|,
name|int
name|from
argument_list|,
name|int
name|end_pos
argument_list|)
decl_stmt|,
name|next_nonwhitespace_character
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|fs_error
argument_list|(
name|char
operator|*
name|filename
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VA_FPRINTF
argument_list|)
operator|&&
name|__STDC__
end_if

begin_comment
comment|/* Unfortunately we must use prototypes if we are to use<stdarg.h>.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_word_args
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|add_html_block_elt_args
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|execute_string
argument_list|(
name|char
operator|*
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|warning
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|error
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|line_error
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
decl_stmt|,
name|file_line_error
argument_list|(
name|char
operator|*
name|infile
argument_list|,
name|int
name|lno
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|add_word_args
argument_list|()
decl_stmt|,
name|add_html_block_elt_args
argument_list|()
decl_stmt|,
name|execute_string
argument_list|()
decl_stmt|,
name|warning
argument_list|()
decl_stmt|,
name|error
argument_list|()
decl_stmt|,
name|line_error
argument_list|()
decl_stmt|,
name|file_line_error
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no prototypes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MAKEINFO_H */
end_comment

end_unit

