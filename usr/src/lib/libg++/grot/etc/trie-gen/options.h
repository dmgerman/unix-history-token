begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Handles parsing the Options provided to the user.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU TRIE-GEN.  GNU TRIE-GEN is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU TRIE-GEN is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU TRIE-GEN; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This module provides a uniform interface to the various options available    to a user of the minimal-prefix trie generator.    The overall design of this module was an experiment in using C++    classes as a mechanism to enhance centralization of option and    and error handling, which tend to get out of hand in a C program. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

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
comment|/* Enable debugging option. */
name|COMPACT
init|=
literal|02
block|,
comment|/* Compact the output tables. */
name|FULL
init|=
literal|04
block|,
comment|/* Generate a full table. */
name|CONST
init|=
literal|010
block|,
comment|/* Make the generated tables readonly (const). */
block|}
enum|;
end_enum

begin_comment
comment|/* Class manager for program options. */
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
specifier|const
name|char
modifier|*
name|program_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
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
name|private
label|:
specifier|static
name|int
name|option_word
decl_stmt|;
comment|/* Holds the user-specified Options. */
specifier|static
name|int
name|argument_count
decl_stmt|;
specifier|static
name|char
modifier|*
modifier|*
name|argument_vector
decl_stmt|;
specifier|static
name|void
name|usage
parameter_list|(
name|void
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

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|Options
operator|::
name|program_name
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|argument_vector
index|[
literal|0
index|]
return|;
block|}
end_expr_stmt

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
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

