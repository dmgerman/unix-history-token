begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Handles parsing the Options provided to the user.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This module provides a uniform interface to the various options available    to a user of the gperf hash function generator.  In addition to the    run-time options, found in the Option_Type below, there is also the    hash table Size and the Keys to be used in the hashing.    The overall design of this module was an experiment in using C++    classes as a mechanism to enhance centralization of option and    and error handling, which tend to get out of hand in a C program. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"std-err.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
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
comment|/* Enable debugging (prints diagnostics to Std_Err). */
name|ORDER
init|=
literal|02
block|,
comment|/* Apply ordering heuristic to speed-up search time. */
name|ANSI
init|=
literal|04
block|,
comment|/* Generate ANSI prototypes. */
name|ALLCHARS
init|=
literal|010
block|,
comment|/* Use all characters in hash function. */
name|GNU
init|=
literal|020
block|,
comment|/* Assume GNU extensions (primarily function inline). */
name|TYPE
init|=
literal|040
block|,
comment|/* Handle user-defined type structured keyword input. */
name|RANDOM
init|=
literal|0100
block|,
comment|/* Randomly initialize the associated values table. */
name|DEFAULTCHARS
init|=
literal|0200
block|,
comment|/* Make default char positions be 1,$ (end of keyword). */
name|SWITCH
init|=
literal|0400
block|,
comment|/* Generate switch output to save space. */
name|POINTER
init|=
literal|01000
block|,
comment|/* Have in_word_set function return pointer, not boolean. */
name|NOLENGTH
init|=
literal|02000
block|,
comment|/* Don't include keyword length in hash computations. */
name|LENTABLE
init|=
literal|04000
block|,
comment|/* Generate a length table for string comparison. */
name|DUP
init|=
literal|010000
block|,
comment|/* Handle duplicate hash values for keywords. */
name|FAST
init|=
literal|020000
block|,
comment|/* Generate the hash function ``fast.'' */
name|NOTYPE
init|=
literal|040000
block|,
comment|/* Don't include user-defined type definition in output -- it's already defined elsewhere. */
name|COMP
init|=
literal|0100000
block|,
comment|/* Generate strncmp rather than strcmp. */
name|GLOBAL
init|=
literal|0200000
block|,
comment|/* Make the keyword table a global variable. */
name|CONST
init|=
literal|0400000
block|,
comment|/* Make the generated tables readonly (const). */
name|CPLUSPLUS
init|=
literal|01000000
block|,
comment|/* Generate C++ code. */
name|C
init|=
literal|02000000
block|,
comment|/* Generate C code. */
name|ENUM
init|=
literal|04000000
block|,
comment|/* Use enum for constants. */
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
block|,
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
range|:
name|private
name|Std_Err
block|{
name|public
operator|:
name|Options
argument_list|(
name|void
argument_list|)
block|;
operator|~
name|Options
argument_list|(
name|void
argument_list|)
block|;
name|int
name|operator
index|[]
operator|(
name|Option_Type
name|option
operator|)
block|;
name|void
name|operator
argument_list|()
operator|(
name|int
name|argc
expr|,
name|char
operator|*
name|argv
index|[]
operator|)
block|;
name|void
name|operator
operator|=
operator|(
expr|enum
name|Option_Type
operator|)
block|;
name|void
name|operator
operator|!=
operator|(
expr|enum
name|Option_Type
operator|)
block|;
specifier|static
name|void
name|print_options
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|void
name|set_asso_max
argument_list|(
argument|int r
argument_list|)
block|;
specifier|static
name|int
name|get_asso_max
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|void
name|reset
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|int
name|get
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|int
name|get_iterations
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|int
name|get_max_keysig_size
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|void
name|set_keysig_size
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|get_jump
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|int
name|initial_value
argument_list|(
name|void
argument_list|)
block|;
specifier|static
name|int
name|get_total_switches
argument_list|(
name|void
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|get_function_name
argument_list|(
name|void
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|get_key_name
argument_list|(
name|void
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|get_class_name
argument_list|(
name|void
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|get_hash_name
argument_list|(
name|void
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|get_delimiter
argument_list|(
name|void
argument_list|)
block|;
name|private
operator|:
specifier|const
name|int
name|DEFAULT_JUMP_VALUE
operator|=
literal|5
block|;
comment|/* Size to jump on a collision. */
specifier|const
name|char
operator|*
specifier|const
name|DEFAULT_NAME
operator|=
literal|"in_word_set"
block|;
comment|/* Default name for generated lookup function. */
specifier|const
name|char
operator|*
specifier|const
name|DEFAULT_KEY
operator|=
literal|"name"
block|;
comment|/* Default name for the key component. */
specifier|const
name|char
operator|*
specifier|const
name|DEFAULT_CLASS_NAME
operator|=
literal|"Perfect_Hash"
block|;
comment|/* Default name for the generated class. */
specifier|const
name|char
operator|*
specifier|const
name|DEFAULT_HASH_NAME
operator|=
literal|"hash"
block|;
comment|/* Default name for generated hash function. */
specifier|const
name|char
operator|*
specifier|const
name|DEFAULT_DELIMITERS
operator|=
literal|",\n"
block|;
comment|/* Default delimiters that separate keywords from their attributes. */
specifier|static
name|int
name|option_word
block|;
comment|/* Holds the user-specified Options. */
specifier|static
name|int
name|total_switches
block|;
comment|/* Number of switch statements to generate. */
specifier|static
name|int
name|total_keysig_size
block|;
comment|/* Total number of distinct key_positions. */
specifier|static
name|int
name|size
block|;
comment|/* Range of the hash table. */
specifier|static
name|int
name|key_pos
block|;
comment|/* Tracks current key position for Iterator. */
specifier|static
name|int
name|jump
block|;
comment|/* Jump length when trying alternative values. */
specifier|static
name|int
name|initial_asso_value
block|;
comment|/* Initial value for asso_values table. */
specifier|static
name|int
name|argument_count
block|;
comment|/* Records count of command-line arguments. */
specifier|static
name|int
name|iterations
block|;
comment|/* Amount to iterate when a collision occurs. */
specifier|static
name|char
operator|*
operator|*
name|argument_vector
block|;
comment|/* Stores a pointer to command-line vector. */
specifier|static
specifier|const
name|char
operator|*
name|function_name
block|;
comment|/* Names used for generated lookup function. */
specifier|static
specifier|const
name|char
operator|*
name|key_name
block|;
comment|/* Name used for keyword key. */
specifier|static
specifier|const
name|char
operator|*
name|class_name
block|;
comment|/* Name used for generated C++ class. */
specifier|static
specifier|const
name|char
operator|*
name|hash_name
block|;
comment|/* Name used for generated hash function. */
specifier|static
specifier|const
name|char
operator|*
name|delimiters
block|;
comment|/* Separates keywords from other attributes. */
specifier|static
name|char
name|key_positions
index|[
name|MAX_KEY_POS
index|]
block|;
comment|/* Contains user-specified key choices. */
specifier|static
name|int
name|key_sort
argument_list|(
argument|char *base
argument_list|,
argument|int len
argument_list|)
block|;
comment|/* Sorts key positions in REVERSE order. */
specifier|static
name|void
name|usage
argument_list|(
name|void
argument_list|)
block|;
comment|/* Prints proper program usage. */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global option coordinator for the entire program. */
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

begin_expr_stmt
specifier|inline
name|int
name|Options
operator|::
name|operator
index|[]
operator|(
name|Option_Type
name|option
operator|)
comment|/* True if option enable, else false. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::operator[]"
argument|);
argument_list|)
return|return
name|option_word
operator|&
name|option
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Options
operator|::
name|operator
operator|=
operator|(
expr|enum
name|Option_Type
name|opt
operator|)
comment|/* Enables option OPT. */
block|{
name|option_word
operator||=
name|opt
block|; }
specifier|inline
name|void
name|Options
operator|::
name|operator
operator|!=
operator|(
expr|enum
name|Option_Type
name|opt
operator|)
comment|/* Disables option OPT. */
block|{
name|option_word
operator|&=
operator|~
name|opt
block|; }
specifier|inline
name|void
name|Options
operator|::
name|reset
argument_list|(
argument|void
argument_list|)
comment|/* Initializes the key Iterator. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::reset"
argument|);
argument_list|)
name|key_pos
operator|=
literal|0
block|; }
specifier|inline
name|int
name|Options
operator|::
name|get
argument_list|(
argument|void
argument_list|)
comment|/* Returns current key_position and advanced index. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get"
argument|);
argument_list|)
return|return
name|key_positions
index|[
name|key_pos
operator|++
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Options
operator|::
name|set_asso_max
argument_list|(
argument|int r
argument_list|)
comment|/* Sets the size of the table size. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::set_asso_max"
argument|);
argument_list|)
name|size
operator|=
name|r
block|; }
specifier|inline
name|int
name|Options
operator|::
name|get_asso_max
argument_list|(
argument|void
argument_list|)
comment|/* Returns the size of the table size. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_asso_max"
argument|);
argument_list|)
return|return
name|size
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Options
operator|::
name|get_max_keysig_size
argument_list|(
argument|void
argument_list|)
comment|/* Returns total distinct key positions. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_max_keysig_size"
argument|);
argument_list|)
return|return
name|total_keysig_size
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Options
operator|::
name|set_keysig_size
argument_list|(
argument|int size
argument_list|)
comment|/* Sets total distinct key positions. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::set_keysig_size"
argument|);
argument_list|)
name|total_keysig_size
operator|=
name|size
block|; }
specifier|inline
name|int
name|Options
operator|::
name|get_jump
argument_list|(
argument|void
argument_list|)
comment|/* Returns the jump value. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_jump"
argument|);
argument_list|)
return|return
name|jump
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|get_function_name
argument_list|(
argument|void
argument_list|)
comment|/* Returns the generated function name. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_function_name"
argument|);
argument_list|)
return|return
name|function_name
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|get_key_name
argument_list|(
argument|void
argument_list|)
comment|/* Returns the keyword key name. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_key_name"
argument|);
argument_list|)
return|return
name|key_name
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|get_hash_name
argument_list|(
argument|void
argument_list|)
comment|/* Returns the hash function name. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_hash_name"
argument|);
argument_list|)
return|return
name|hash_name
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|get_class_name
argument_list|(
argument|void
argument_list|)
comment|/* Returns the generated class name. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_class_name"
argument|);
argument_list|)
return|return
name|class_name
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Options
operator|::
name|initial_value
argument_list|(
argument|void
argument_list|)
comment|/* Returns the initial associated character value. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::initial_value"
argument|);
argument_list|)
return|return
name|initial_asso_value
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Options
operator|::
name|get_iterations
argument_list|(
argument|void
argument_list|)
comment|/* Returns the iterations value. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_iterations"
argument|);
argument_list|)
return|return
name|iterations
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|get_delimiter
argument_list|()
comment|/* Returns the string used to delimit keywords from other attributes. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_delimiter"
argument|);
argument_list|)
return|return
name|delimiters
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Options
operator|::
name|get_total_switches
argument_list|()
comment|/* Gets the total number of switch statements to generate. */
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Options::get_total_switches"
argument|);
argument_list|)
return|return
name|total_switches
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

