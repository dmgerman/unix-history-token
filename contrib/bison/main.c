begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Top level entry point of bison,    Copyright (C) 1984, 1986, 1989, 1992, 1995 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_comment
comment|/* for MAXSHORT */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verboseflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means failure has been detected; don't write a parser file.  */
end_comment

begin_decl_stmt
name|int
name|failure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The name this program was run with, for messages.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|getargs
argument_list|()
decl_stmt|,
name|openfiles
argument_list|()
decl_stmt|,
name|reader
argument_list|()
decl_stmt|,
name|reduce_grammar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_derives
argument_list|()
decl_stmt|,
name|set_nullable
argument_list|()
decl_stmt|,
name|generate_states
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lalr
argument_list|()
decl_stmt|,
name|initialize_conflicts
argument_list|()
decl_stmt|,
name|verbose
argument_list|()
decl_stmt|,
name|terse
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output
argument_list|()
decl_stmt|,
name|done
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VMS complained about using `int'.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|program_name
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|failure
operator|=
literal|0
expr_stmt|;
name|lineno
operator|=
literal|0
expr_stmt|;
name|getargs
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|openfiles
argument_list|()
expr_stmt|;
comment|/* read the input.  Copy some parts of it to fguard, faction, ftable and fattrs.      In file reader.c.      The other parts are recorded in the grammar; see gram.h.  */
name|reader
argument_list|()
expr_stmt|;
if|if
condition|(
name|failure
condition|)
name|done
argument_list|(
name|failure
argument_list|)
expr_stmt|;
comment|/* find useless nonterminals and productions and reduce the grammar.  In      file reduce.c */
name|reduce_grammar
argument_list|()
expr_stmt|;
comment|/* record other info about the grammar.  In files derives and nullable.  */
name|set_derives
argument_list|()
expr_stmt|;
name|set_nullable
argument_list|()
expr_stmt|;
comment|/* convert to nondeterministic finite state machine.  In file LR0.      See state.h for more info.  */
name|generate_states
argument_list|()
expr_stmt|;
comment|/* make it deterministic.  In file lalr.  */
name|lalr
argument_list|()
expr_stmt|;
comment|/* Find and record any conflicts: places where one token of lookahead is not      enough to disambiguate the parsing.  In file conflicts.      Also resolve s/r conflicts based on precedence declarations.  */
name|initialize_conflicts
argument_list|()
expr_stmt|;
comment|/* print information about results, if requested.  In file print. */
if|if
condition|(
name|verboseflag
condition|)
name|verbose
argument_list|()
expr_stmt|;
else|else
name|terse
argument_list|()
expr_stmt|;
comment|/* output the tables and the parser to ftable.  In file output. */
name|output
argument_list|()
expr_stmt|;
name|done
argument_list|(
name|failure
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* functions to report errors which prevent a parser from being generated */
end_comment

begin_comment
comment|/* Return a string containing a printable version of C:    either C itself, or the corresponding \DDD code.  */
end_comment

begin_function
name|char
modifier|*
name|printable_version
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|10
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|<
literal|' '
operator|||
name|c
operator|>=
literal|'\177'
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"\\%o"
argument_list|,
name|c
argument_list|)
expr_stmt|;
else|else
block|{
name|buf
index|[
literal|0
index|]
operator|=
name|c
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/* Generate a string from the integer I.    Return a ptr to internal memory containing the string.  */
end_comment

begin_function
name|char
modifier|*
name|int_to_string
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|20
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/* Print the message S for a fatal error.  */
end_comment

begin_function
name|void
name|fatal
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|infile
decl_stmt|;
if|if
condition|(
name|infile
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"fatal error: %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\"%s\", line %d: %s\n"
argument_list|,
name|infile
argument_list|,
name|lineno
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Print a message for a fatal error.  Use FMT to construct the message    and incorporate string X1.  */
end_comment

begin_function
name|void
name|fatals
parameter_list|(
name|fmt
parameter_list|,
name|x1
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|,
decl|*
name|x1
decl_stmt|;
end_function

begin_block
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Print a warning message S.  */
end_comment

begin_function
name|void
name|warn
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|infile
decl_stmt|;
if|if
condition|(
name|infile
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error: %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"(\"%s\", line %d) error: %s\n"
argument_list|,
name|infile
argument_list|,
name|lineno
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|failure
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Print a warning message containing the string for the integer X1.    The message is given by the format FMT.  */
end_comment

begin_function
name|void
name|warni
parameter_list|(
name|fmt
parameter_list|,
name|x1
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
name|int
name|x1
decl_stmt|;
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|warn
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Print a warning message containing the string X1.    The message is given by the format FMT.  */
end_comment

begin_function
name|void
name|warns
parameter_list|(
name|fmt
parameter_list|,
name|x1
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|,
decl|*
name|x1
decl_stmt|;
end_function

begin_block
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|warn
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Print a warning message containing the two strings X1 and X2. 	The message is given by the format FMT.  */
end_comment

begin_function
name|void
name|warnss
parameter_list|(
name|fmt
parameter_list|,
name|x1
parameter_list|,
name|x2
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|,
decl|*
name|x1
decl_stmt|,
modifier|*
name|x2
decl_stmt|;
end_function

begin_block
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|x1
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|warn
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Print a warning message containing the 3 strings X1, X2, X3.    The message is given by the format FMT.  */
end_comment

begin_function
name|void
name|warnsss
parameter_list|(
name|fmt
parameter_list|,
name|x1
parameter_list|,
name|x2
parameter_list|,
name|x3
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|,
decl|*
name|x1
decl_stmt|,
modifier|*
name|x2
decl_stmt|,
modifier|*
name|x3
decl_stmt|;
end_function

begin_block
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|x1
argument_list|,
name|x2
argument_list|,
name|x3
argument_list|)
expr_stmt|;
name|warn
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Print a message for the fatal occurence of more than MAXSHORT    instances of whatever is denoted by the string S.  */
end_comment

begin_function
name|void
name|toomany
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"limit of %d exceeded, too many %s"
argument_list|,
name|MAXSHORT
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Abort for an internal error denoted by string S.  */
end_comment

begin_function
name|void
name|berror
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"internal error, %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

