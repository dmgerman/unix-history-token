begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Handles parsing the Options provided to the user.     Copyright (C) 1989-1998, 2000, 2002-2004 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This module provides a uniform interface to the various options available    to a user of the gperf hash function generator.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|options_h
end_ifndef

begin_define
define|#
directive|define
name|options_h
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"positions.h"
end_include

begin_comment
comment|/* Enumeration of the possible boolean options.  */
end_comment

begin_enum
enum|enum
name|Option_Type
block|{
comment|/* --- Input file interpretation --- */
comment|/* Handle user-defined type structured keyword input.  */
name|TYPE
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* Ignore case of ASCII characters.  */
name|UPPERLOWER
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* --- Language for the output code --- */
comment|/* Generate K&R C code: no prototypes, no const.  */
name|KRC
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* Generate C code: no prototypes, but const (user can #define it away).  */
name|C
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* Generate ISO/ANSI C code: prototypes and const, but no class.  */
name|ANSIC
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* Generate C++ code: prototypes, const, class, inline, enum.  */
name|CPLUSPLUS
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* --- Details in the output code --- */
comment|/* Assume 7-bit, not 8-bit, characters.  */
name|SEVENBIT
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* Generate a length table for string comparison.  */
name|LENTABLE
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* Generate strncmp rather than strcmp.  */
name|COMP
init|=
literal|1
operator|<<
literal|8
block|,
comment|/* Make the generated tables readonly (const).  */
name|CONST
init|=
literal|1
operator|<<
literal|9
block|,
comment|/* Use enum for constants.  */
name|ENUM
init|=
literal|1
operator|<<
literal|10
block|,
comment|/* Generate #include statements.  */
name|INCLUDE
init|=
literal|1
operator|<<
literal|11
block|,
comment|/* Make the keyword table a global variable.  */
name|GLOBAL
init|=
literal|1
operator|<<
literal|12
block|,
comment|/* Use NULL strings instead of empty strings for empty table entries.  */
name|NULLSTRINGS
init|=
literal|1
operator|<<
literal|13
block|,
comment|/* Optimize for position-independent code.  */
name|SHAREDLIB
init|=
literal|1
operator|<<
literal|14
block|,
comment|/* Generate switch output to save space.  */
name|SWITCH
init|=
literal|1
operator|<<
literal|15
block|,
comment|/* Don't include user-defined type definition in output -- it's already      defined elsewhere.  */
name|NOTYPE
init|=
literal|1
operator|<<
literal|16
block|,
comment|/* --- Algorithm employed by gperf --- */
comment|/* Use the given key positions.  */
name|POSITIONS
init|=
literal|1
operator|<<
literal|17
block|,
comment|/* Handle duplicate hash values for keywords.  */
name|DUP
init|=
literal|1
operator|<<
literal|18
block|,
comment|/* Don't include keyword length in hash computations.  */
name|NOLENGTH
init|=
literal|1
operator|<<
literal|19
block|,
comment|/* Randomly initialize the associated values table.  */
name|RANDOM
init|=
literal|1
operator|<<
literal|20
block|,
comment|/* --- Informative output --- */
comment|/* Enable debugging (prints diagnostics to stderr).  */
name|DEBUG
init|=
literal|1
operator|<<
literal|21
block|}
enum|;
end_enum

begin_comment
comment|/* Class manager for gperf program Options.  */
end_comment

begin_decl_stmt
name|class
name|Options
block|{
name|public
label|:
comment|/* Constructor.  */
name|Options
argument_list|()
expr_stmt|;
comment|/* Destructor.  */
operator|~
name|Options
argument_list|()
expr_stmt|;
comment|/* Parses the options given in the command-line arguments.  */
name|void
name|parse_options
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
comment|/* Prints the given options.  */
name|void
name|print_options
argument_list|()
specifier|const
expr_stmt|;
comment|/* Accessors.  */
comment|/* Tests a given boolean option.  Returns true if set, false otherwise.  */
name|bool
name|operator
index|[]
argument_list|(
name|Option_Type
name|option
argument_list|)
decl|const
decl_stmt|;
comment|/* Sets a given boolean option.  */
name|void
name|set
parameter_list|(
name|Option_Type
name|option
parameter_list|)
function_decl|;
comment|/* Returns the input file name.  */
specifier|const
name|char
operator|*
name|get_input_file_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Returns the output file name.  */
specifier|const
name|char
operator|*
name|get_output_file_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the output language, if not already set.  */
name|void
name|set_language
parameter_list|(
specifier|const
name|char
modifier|*
name|language
parameter_list|)
function_decl|;
comment|/* Returns the jump value.  */
name|int
name|get_jump
argument_list|()
specifier|const
expr_stmt|;
comment|/* Returns the initial associated character value.  */
name|int
name|get_initial_asso_value
argument_list|()
specifier|const
expr_stmt|;
comment|/* Returns the number of iterations for finding good asso_values.  */
name|int
name|get_asso_iterations
argument_list|()
specifier|const
expr_stmt|;
comment|/* Returns the total number of switch statements to generate.  */
name|int
name|get_total_switches
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the total number of switch statements, if not already set.  */
name|void
name|set_total_switches
parameter_list|(
name|int
name|total_switches
parameter_list|)
function_decl|;
comment|/* Returns the factor by which to multiply the generated table's size.  */
name|float
name|get_size_multiple
argument_list|()
specifier|const
expr_stmt|;
comment|/* Returns the generated function name.  */
specifier|const
name|char
operator|*
name|get_function_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the generated function name, if not already set.  */
name|void
name|set_function_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the keyword key name.  */
specifier|const
name|char
operator|*
name|get_slot_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the keyword key name, if not already set.  */
name|void
name|set_slot_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the struct initializer suffix.  */
specifier|const
name|char
operator|*
name|get_initializer_suffix
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the struct initializer suffix, if not already set.  */
name|void
name|set_initializer_suffix
parameter_list|(
specifier|const
name|char
modifier|*
name|initializers
parameter_list|)
function_decl|;
comment|/* Returns the generated class name.  */
specifier|const
name|char
operator|*
name|get_class_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the generated class name, if not already set.  */
name|void
name|set_class_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the hash function name.  */
specifier|const
name|char
operator|*
name|get_hash_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the hash function name, if not already set.  */
name|void
name|set_hash_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the hash table array name.  */
specifier|const
name|char
operator|*
name|get_wordlist_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the hash table array name, if not already set.  */
name|void
name|set_wordlist_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the length table array name.  */
specifier|const
name|char
operator|*
name|get_lengthtable_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the length table array name, if not already set.  */
name|void
name|set_lengthtable_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the string pool name.  */
specifier|const
name|char
operator|*
name|get_stringpool_name
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the string pool name, if not already set.  */
name|void
name|set_stringpool_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Returns the string used to delimit keywords from other attributes.  */
specifier|const
name|char
operator|*
name|get_delimiters
argument_list|()
specifier|const
expr_stmt|;
comment|/* Sets the delimiters string, if not already set.  */
name|void
name|set_delimiters
parameter_list|(
specifier|const
name|char
modifier|*
name|delimiters
parameter_list|)
function_decl|;
comment|/* Returns key positions.  */
specifier|const
name|Positions
operator|&
name|get_key_positions
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/* Prints program usage to given stream.  */
specifier|static
name|void
name|short_usage
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Prints program usage to given stream.  */
specifier|static
name|void
name|long_usage
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Records count of command-line arguments.  */
name|int
name|_argument_count
decl_stmt|;
comment|/* Stores a pointer to command-line argument vector.  */
name|char
modifier|*
modifier|*
name|_argument_vector
decl_stmt|;
comment|/* Holds the boolean options.  */
name|int
name|_option_word
decl_stmt|;
comment|/* Name of input file.  */
name|char
modifier|*
name|_input_file_name
decl_stmt|;
comment|/* Name of output file.  */
name|char
modifier|*
name|_output_file_name
decl_stmt|;
comment|/* The output language.  */
specifier|const
name|char
modifier|*
name|_language
decl_stmt|;
comment|/* Jump length when trying alternative values.  */
name|int
name|_jump
decl_stmt|;
comment|/* Initial value for asso_values table.  */
name|int
name|_initial_asso_value
decl_stmt|;
comment|/* Number of attempts at finding good asso_values.  */
name|int
name|_asso_iterations
decl_stmt|;
comment|/* Number of switch statements to generate.  */
name|int
name|_total_switches
decl_stmt|;
comment|/* Factor by which to multiply the generated table's size.  */
name|float
name|_size_multiple
decl_stmt|;
comment|/* Names used for generated lookup function.  */
specifier|const
name|char
modifier|*
name|_function_name
decl_stmt|;
comment|/* Name used for keyword key.  */
specifier|const
name|char
modifier|*
name|_slot_name
decl_stmt|;
comment|/* Suffix for empty struct initializers.  */
specifier|const
name|char
modifier|*
name|_initializer_suffix
decl_stmt|;
comment|/* Name used for generated C++ class.  */
specifier|const
name|char
modifier|*
name|_class_name
decl_stmt|;
comment|/* Name used for generated hash function.  */
specifier|const
name|char
modifier|*
name|_hash_name
decl_stmt|;
comment|/* Name used for hash table array.  */
specifier|const
name|char
modifier|*
name|_wordlist_name
decl_stmt|;
comment|/* Name used for length table array.  */
specifier|const
name|char
modifier|*
name|_lengthtable_name
decl_stmt|;
comment|/* Name used for the string pool.  */
specifier|const
name|char
modifier|*
name|_stringpool_name
decl_stmt|;
comment|/* Separates keywords from other attributes.  */
specifier|const
name|char
modifier|*
name|_delimiters
decl_stmt|;
comment|/* Contains user-specified key choices.  */
name|Positions
name|_key_positions
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Global option coordinator for the entire program.  */
end_comment

begin_decl_stmt
specifier|extern
name|Options
name|option
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_include
include|#
directive|include
file|"options.icc"
end_include

begin_undef
undef|#
directive|undef
name|INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

