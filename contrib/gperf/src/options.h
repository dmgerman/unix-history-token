begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Handles parsing the Options provided to the user.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This module provides a uniform interface to the various Options available    to a user of the Perfect.hash function generator.  In addition to the    run-time Options, found in the Option_Type below, there is also the    hash table Size and the Keys to be used in the hashing.    The overall design of this module was an experiment in using C++    classes as a mechanism to enhance centralization of option and    and error handling, which tend to get out of hand in a C program. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_options_h
end_ifndef

begin_define
define|#
directive|define
name|_options_h
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"prototype.h"
end_include

begin_comment
comment|/* Enumerate the potential debugging Options. */
end_comment

begin_enum
enum|enum
name|option_type
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
comment|/* Don't include user-defined type definition                                    in output -- it's already defined elsewhere. */
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
block|}
enum|;
end_enum

begin_comment
comment|/* Define some useful constants. */
end_comment

begin_comment
comment|/* Max size of each word's key set. */
end_comment

begin_define
define|#
directive|define
name|MAX_KEY_POS
value|(128 - 1)
end_define

begin_comment
comment|/* Signals the start of a word. */
end_comment

begin_define
define|#
directive|define
name|WORD_START
value|1
end_define

begin_comment
comment|/* Signals the end of a word. */
end_comment

begin_define
define|#
directive|define
name|WORD_END
value|0
end_define

begin_comment
comment|/* Signals end of the key list. */
end_comment

begin_define
define|#
directive|define
name|EOS
value|MAX_KEY_POS
end_define

begin_comment
comment|/* Returns TRUE if option O is enabled. */
end_comment

begin_define
define|#
directive|define
name|OPTION_ENABLED
parameter_list|(
name|OW
parameter_list|,
name|O
parameter_list|)
value|(OW.option_word& (int)O)
end_define

begin_comment
comment|/* Enables option O in OPTION_WORD. */
end_comment

begin_define
define|#
directive|define
name|SET_OPTION
parameter_list|(
name|OW
parameter_list|,
name|O
parameter_list|)
value|(OW.option_word |= (int)O)
end_define

begin_comment
comment|/* Disable option O in OPTION_WORD. */
end_comment

begin_define
define|#
directive|define
name|UNSET_OPTION
parameter_list|(
name|OW
parameter_list|,
name|O
parameter_list|)
value|(OW.option_word&= ~(int)(O))
end_define

begin_comment
comment|/* Returns total distinct key positions. */
end_comment

begin_define
define|#
directive|define
name|GET_CHARSET_SIZE
parameter_list|(
name|O
parameter_list|)
value|(O.total_charset_size)
end_define

begin_comment
comment|/* Set the total distinct key positions. */
end_comment

begin_define
define|#
directive|define
name|SET_CHARSET_SIZE
parameter_list|(
name|O
parameter_list|,
name|S
parameter_list|)
value|(O.total_charset_size = (S))
end_define

begin_comment
comment|/* Initializes the key Iterator. */
end_comment

begin_define
define|#
directive|define
name|RESET
parameter_list|(
name|O
parameter_list|)
value|(O.key_pos = 0)
end_define

begin_comment
comment|/* Returns current key_position and advances index. */
end_comment

begin_define
define|#
directive|define
name|GET
parameter_list|(
name|O
parameter_list|)
value|(O.key_positions[O.key_pos++])
end_define

begin_comment
comment|/* Sets the size of the table size. */
end_comment

begin_define
define|#
directive|define
name|SET_ASSO_MAX
parameter_list|(
name|O
parameter_list|,
name|R
parameter_list|)
value|(O.size = (R))
end_define

begin_comment
comment|/* Returns the size of the table size. */
end_comment

begin_define
define|#
directive|define
name|GET_ASSO_MAX
parameter_list|(
name|O
parameter_list|)
value|(O.size)
end_define

begin_comment
comment|/* Returns the jump value. */
end_comment

begin_define
define|#
directive|define
name|GET_JUMP
parameter_list|(
name|O
parameter_list|)
value|(O.jump)
end_define

begin_comment
comment|/* Returns the iteration value. */
end_comment

begin_define
define|#
directive|define
name|GET_ITERATIONS
parameter_list|(
name|O
parameter_list|)
value|(O.iterations)
end_define

begin_comment
comment|/* Returns the lookup function name. */
end_comment

begin_define
define|#
directive|define
name|GET_FUNCTION_NAME
parameter_list|(
name|O
parameter_list|)
value|(O.function_name)
end_define

begin_comment
comment|/* Returns the keyword key name. */
end_comment

begin_define
define|#
directive|define
name|GET_KEY_NAME
parameter_list|(
name|O
parameter_list|)
value|(O.key_name)
end_define

begin_comment
comment|/* Returns the hash function name. */
end_comment

begin_define
define|#
directive|define
name|GET_HASH_NAME
parameter_list|(
name|O
parameter_list|)
value|(O.hash_name)
end_define

begin_comment
comment|/* Returns the initial associated character value. */
end_comment

begin_define
define|#
directive|define
name|INITIAL_VALUE
parameter_list|(
name|O
parameter_list|)
value|(O.initial_asso_value)
end_define

begin_comment
comment|/* Returns the string used to delimit keywords from other attributes. */
end_comment

begin_define
define|#
directive|define
name|GET_DELIMITER
parameter_list|(
name|O
parameter_list|)
value|(O.delimiters)
end_define

begin_comment
comment|/* Sets the keyword/attribute delimiters with value of D. */
end_comment

begin_define
define|#
directive|define
name|SET_DELIMITERS
parameter_list|(
name|O
parameter_list|,
name|D
parameter_list|)
value|(O.delimiters = (D))
end_define

begin_comment
comment|/* Gets the total number of switch statements to generate. */
end_comment

begin_define
define|#
directive|define
name|GET_TOTAL_SWITCHES
parameter_list|(
name|O
parameter_list|)
value|(O.total_switches)
end_define

begin_comment
comment|/* Class manager for gperf program options. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|options
block|{
name|int
name|option_word
decl_stmt|;
comment|/* Holds the user-specified Options. */
name|int
name|total_charset_size
decl_stmt|;
comment|/* Total number of distinct key_positions. */
name|int
name|size
decl_stmt|;
comment|/* Range of the hash table. */
name|int
name|key_pos
decl_stmt|;
comment|/* Tracks current key position for Iterator. */
name|int
name|jump
decl_stmt|;
comment|/* Jump length when trying alternative values. */
name|int
name|initial_asso_value
decl_stmt|;
comment|/* Initial value for asso_values table. */
name|int
name|argument_count
decl_stmt|;
comment|/* Records count of command-line arguments. */
name|int
name|iterations
decl_stmt|;
comment|/* Amount to iterate when a collision occurs. */
name|int
name|total_switches
decl_stmt|;
comment|/* Number of switch statements to generate. */
name|char
modifier|*
modifier|*
name|argument_vector
decl_stmt|;
comment|/* Stores a pointer to command-line vector. */
name|char
modifier|*
name|function_name
decl_stmt|;
comment|/* Name used for generated lookup function. */
name|char
modifier|*
name|key_name
decl_stmt|;
comment|/* Name used for keyword key. */
name|char
modifier|*
name|hash_name
decl_stmt|;
comment|/* Name used for generated hash function. */
name|char
modifier|*
name|delimiters
decl_stmt|;
comment|/* Separates keywords from other attributes. */
name|char
name|key_positions
index|[
name|MAX_KEY_POS
index|]
decl_stmt|;
comment|/* Contains user-specified key choices. */
block|}
name|OPTIONS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|options_init
name|P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|options_destroy
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OPTIONS
name|option
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _options_h */
end_comment

end_unit

