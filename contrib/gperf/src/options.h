begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Handles parsing the Options provided to the user.     Copyright (C) 1989-1998, 2000 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_comment
comment|/* This module provides a uniform interface to the various options available    to a user of the gperf hash function generator.  In addition to the    run-time options, found in the Option_Type below, there is also the    hash table Size and the Keys to be used in the hashing.    The overall design of this module was an experiment in using C++    classes as a mechanism to enhance centralization of option and    and error handling, which tend to get out of hand in a C program. */
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

begin_comment
comment|/* Enumerate the potential debugging Options. */
end_comment

begin_enum
enum|enum
name|Option_Type
block|{
name|DEBUG
init|=
literal|01
block|,
comment|/* Enable debugging (prints diagnostics to stderr). */
name|ORDER
init|=
literal|02
block|,
comment|/* Apply ordering heuristic to speed-up search time. */
name|ALLCHARS
init|=
literal|04
block|,
comment|/* Use all characters in hash function. */
name|TYPE
init|=
literal|010
block|,
comment|/* Handle user-defined type structured keyword input. */
name|RANDOM
init|=
literal|020
block|,
comment|/* Randomly initialize the associated values table. */
name|DEFAULTCHARS
init|=
literal|040
block|,
comment|/* Make default char positions be 1,$ (end of keyword). */
name|SWITCH
init|=
literal|0100
block|,
comment|/* Generate switch output to save space. */
name|NOLENGTH
init|=
literal|0200
block|,
comment|/* Don't include keyword length in hash computations. */
name|LENTABLE
init|=
literal|0400
block|,
comment|/* Generate a length table for string comparison. */
name|DUP
init|=
literal|01000
block|,
comment|/* Handle duplicate hash values for keywords. */
name|FAST
init|=
literal|02000
block|,
comment|/* Generate the hash function ``fast.'' */
name|NOTYPE
init|=
literal|04000
block|,
comment|/* Don't include user-defined type definition in output -- it's already defined elsewhere. */
name|COMP
init|=
literal|010000
block|,
comment|/* Generate strncmp rather than strcmp. */
name|GLOBAL
init|=
literal|020000
block|,
comment|/* Make the keyword table a global variable. */
name|CONST
init|=
literal|040000
block|,
comment|/* Make the generated tables readonly (const). */
name|KRC
init|=
literal|0100000
block|,
comment|/* Generate K&R C code: no prototypes, no const. */
name|C
init|=
literal|0200000
block|,
comment|/* Generate C code: no prototypes, but const (user can #define it away). */
name|ANSIC
init|=
literal|0400000
block|,
comment|/* Generate ISO/ANSI C code: prototypes and const, but no class. */
name|CPLUSPLUS
init|=
literal|01000000
block|,
comment|/* Generate C++ code: prototypes, const, class, inline, enum. */
name|ENUM
init|=
literal|02000000
block|,
comment|/* Use enum for constants. */
name|INCLUDE
init|=
literal|04000000
block|,
comment|/* Generate #include statements. */
name|SEVENBIT
init|=
literal|010000000
comment|/* Assume 7-bit, not 8-bit, characters. */
block|}
enum|;
end_enum

begin_comment
comment|/* Define some useful constants (these don't really belong here, but I'm    not sure where else to put them!).  These should be consts, but g++    doesn't seem to do the right thing with them at the moment... ;-( */
end_comment

begin_enum
enum|enum
block|{
name|MAX_KEY_POS
init|=
literal|128
operator|-
literal|1
block|,
comment|/* Max size of each word's key set. */
name|WORD_START
init|=
literal|1
block|,
comment|/* Signals the start of a word. */
name|WORD_END
init|=
literal|0
block|,
comment|/* Signals the end of a word. */
name|EOS
init|=
name|MAX_KEY_POS
comment|/* Signals end of the key list. */
block|}
enum|;
end_enum

begin_comment
comment|/* Class manager for gperf program Options. */
end_comment

begin_decl_stmt
name|class
name|Options
block|{
name|public
label|:
name|Options
argument_list|(
name|void
argument_list|)
expr_stmt|;
operator|~
name|Options
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|int
name|operator
function_decl|[]
parameter_list|(
name|Option_Type
name|option
parameter_list|)
function_decl|;
name|void
name|operator
argument_list|()
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
expr|enum
name|Option_Type
operator|)
decl_stmt|;
name|void
name|operator
operator|!=
operator|(
expr|enum
name|Option_Type
operator|)
expr_stmt|;
specifier|static
name|void
name|print_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|set_asso_max
parameter_list|(
name|int
name|r
parameter_list|)
function_decl|;
specifier|static
name|int
name|get_asso_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|int
name|get
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|int
name|get_iterations
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|int
name|get_max_keysig_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|set_keysig_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|static
name|int
name|get_jump
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|int
name|initial_value
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|int
name|get_total_switches
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_function_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_key_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_initializer_suffix
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_class_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_hash_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_wordlist_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|get_delimiter
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|int
name|option_word
decl_stmt|;
comment|/* Holds the user-specified Options. */
specifier|static
name|int
name|total_switches
decl_stmt|;
comment|/* Number of switch statements to generate. */
specifier|static
name|int
name|total_keysig_size
decl_stmt|;
comment|/* Total number of distinct key_positions. */
specifier|static
name|int
name|size
decl_stmt|;
comment|/* Range of the hash table. */
specifier|static
name|int
name|key_pos
decl_stmt|;
comment|/* Tracks current key position for Iterator. */
specifier|static
name|int
name|jump
decl_stmt|;
comment|/* Jump length when trying alternative values. */
specifier|static
name|int
name|initial_asso_value
decl_stmt|;
comment|/* Initial value for asso_values table. */
specifier|static
name|int
name|argument_count
decl_stmt|;
comment|/* Records count of command-line arguments. */
specifier|static
name|int
name|iterations
decl_stmt|;
comment|/* Amount to iterate when a collision occurs. */
specifier|static
name|char
modifier|*
modifier|*
name|argument_vector
decl_stmt|;
comment|/* Stores a pointer to command-line vector. */
specifier|static
specifier|const
name|char
modifier|*
name|function_name
decl_stmt|;
comment|/* Names used for generated lookup function. */
specifier|static
specifier|const
name|char
modifier|*
name|key_name
decl_stmt|;
comment|/* Name used for keyword key. */
specifier|static
specifier|const
name|char
modifier|*
name|initializer_suffix
decl_stmt|;
comment|/* Suffix for empty struct initializers. */
specifier|static
specifier|const
name|char
modifier|*
name|class_name
decl_stmt|;
comment|/* Name used for generated C++ class. */
specifier|static
specifier|const
name|char
modifier|*
name|hash_name
decl_stmt|;
comment|/* Name used for generated hash function. */
specifier|static
specifier|const
name|char
modifier|*
name|wordlist_name
decl_stmt|;
comment|/* Name used for hash table array. */
specifier|static
specifier|const
name|char
modifier|*
name|delimiters
decl_stmt|;
comment|/* Separates keywords from other attributes. */
specifier|static
name|char
name|key_positions
index|[
name|MAX_KEY_POS
index|]
decl_stmt|;
comment|/* Contains user-specified key choices. */
specifier|static
name|int
name|key_sort
parameter_list|(
name|char
modifier|*
name|base
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Sorts key positions in REVERSE order. */
specifier|static
name|void
name|short_usage
parameter_list|(
name|FILE
modifier|*
name|strm
parameter_list|)
function_decl|;
comment|/* Prints proper program usage. */
specifier|static
name|void
name|long_usage
parameter_list|(
name|FILE
modifier|*
name|strm
parameter_list|)
function_decl|;
comment|/* Prints proper program usage. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Global option coordinator for the entire program. */
end_comment

begin_decl_stmt
specifier|extern
name|Options
name|option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 1 if your want to stack-allocate some large arrays.    This requires compiler support for variable-size arrays on the stack    (not ANSI). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LARGE_STACK_ARRAYS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUG__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LARGE_STACK_ARRAYS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LARGE_STACK_ARRAYS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set to 1 if the stack is large enough for holding a text line. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LARGE_STACK
end_ifndef

begin_define
define|#
directive|define
name|LARGE_STACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_include
include|#
directive|include
file|"trace.h"
end_include

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

