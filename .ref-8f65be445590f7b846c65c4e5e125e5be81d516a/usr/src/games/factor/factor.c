begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Landon Curt Noll.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)factor.c	4.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * factor - factor a number into primes  *  * By: Landon Curt Noll   chongo@toad.com,   ...!{sun,tolsoft}!hoptoad!chongo  *  *   chongo<for a good prime call: 391581 * 2^216193 - 1> /\oo/\  *  * usage:  *	factor [number] ...  *  * The form of the output is:  *  *	number: factor1 factor1 factor2 factor3 factor3 factor3 ...  *  * where factor1< factor2< factor3< ...  *  * If no args are given, the list of numbers are read from stdin.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"primes.h"
end_include

begin_comment
comment|/*  * prime[i] is the (i-1)th prime.  *  * We are able to sieve 2^32-1 because this byte table yields all primes   * up to 65537 and 65537^2> 2^32-1.  */
end_comment

begin_decl_stmt
specifier|extern
name|ubig
name|prime
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ubig
modifier|*
name|pr_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest prime in the prime array */
end_comment

begin_define
define|#
directive|define
name|MAX_LINE
value|255
end_define

begin_comment
comment|/* max line allowed on stdin */
end_comment

begin_function_decl
name|void
name|pr_fact
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print factors of a value */
end_comment

begin_function_decl
name|long
name|small_fact
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find smallest factor of a value */
end_comment

begin_function_decl
name|char
modifier|*
name|read_num_buf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read a number buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|program
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of this program */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
comment|/* arg count */
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
comment|/* the args */
block|{
name|int
name|arg
decl_stmt|;
comment|/* which arg to factor */
name|long
name|val
decl_stmt|;
comment|/* the value to factor */
name|char
name|buf
index|[
name|MAX_LINE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* input buffer */
comment|/* parse args */
name|program
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|argc
operator|>=
literal|2
condition|)
block|{
comment|/* factor each arg */
for|for
control|(
name|arg
operator|=
literal|1
init|;
name|arg
operator|<
name|argc
condition|;
operator|++
name|arg
control|)
block|{
comment|/* process the buffer */
if|if
condition|(
name|read_num_buf
argument_list|(
name|NULL
argument_list|,
name|argv
index|[
name|arg
index|]
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* factor the argument */
if|if
condition|(
name|sscanf
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|,
literal|"%ld"
argument_list|,
operator|&
name|val
argument_list|)
operator|==
literal|1
condition|)
block|{
name|pr_fact
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* no args supplied, read numbers from stdin */
block|}
else|else
block|{
comment|/* 		 * read asciii numbers from input 		 */
while|while
condition|(
name|read_num_buf
argument_list|(
name|stdin
argument_list|,
name|buf
argument_list|)
operator|!=
name|NULL
condition|)
block|{
comment|/* factor the argument */
if|if
condition|(
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"%ld"
argument_list|,
operator|&
name|val
argument_list|)
operator|==
literal|1
condition|)
block|{
name|pr_fact
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * read_num_buf - read a number buffer from a stream  *  * Read a number on a line of the form:  *  *	^[ \t]*\([+-]?[0-9][0-9]\)*.*$  *  * where ? is a 1-or-0 operator and the number is within \( \).  *  * If does not match the above pattern, it is ignored and a new  * line is read.  If the number is too large or small, we will  * print ouch and read a new line.  *  * We have to be very careful on how we check the magnitude of the  * input.  We can not use numeric checks because of the need to  * check values against maximum numeric values.  *  * This routine will return a line containing a ascii number between  * NEG_SEMIBIG and SEMIBIG, or it will return NULL.  *  * If the stream is NULL then buf will be processed as if were  * a single line stream.  *  * returns:  *	char *	pointer to leading digit, + or -  *	NULL	EOF or error  */
end_comment

begin_function
name|char
modifier|*
name|read_num_buf
parameter_list|(
name|input
parameter_list|,
name|buf
parameter_list|)
name|FILE
modifier|*
name|input
decl_stmt|;
comment|/* input stream or NULL */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* input buffer */
block|{
specifier|static
name|char
name|limit
index|[
name|MAX_LINE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* ascii value of SEMIBIG */
specifier|static
name|int
name|limit_len
decl_stmt|;
comment|/* digit count of limit */
specifier|static
name|char
name|neg_limit
index|[
name|MAX_LINE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* value of NEG_SEMIBIG */
specifier|static
name|int
name|neg_limit_len
decl_stmt|;
comment|/* digit count of neg_limit */
name|int
name|len
decl_stmt|;
comment|/* digits in input (excluding +/-) */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* line start marker */
name|char
modifier|*
name|d
decl_stmt|;
comment|/* first digit, skip +/- */
name|char
modifier|*
name|p
decl_stmt|;
comment|/* scan pointer */
name|char
modifier|*
name|z
decl_stmt|;
comment|/* zero scan pointer */
comment|/* form the ascii value of SEMIBIG if needed */
if|if
condition|(
operator|!
name|isascii
argument_list|(
name|limit
index|[
literal|0
index|]
argument_list|)
operator|||
operator|!
name|isdigit
argument_list|(
name|limit
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|sprintf
argument_list|(
name|limit
argument_list|,
literal|"%ld"
argument_list|,
name|SEMIBIG
argument_list|)
expr_stmt|;
name|limit_len
operator|=
name|strlen
argument_list|(
name|limit
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|neg_limit
argument_list|,
literal|"%ld"
argument_list|,
name|NEG_SEMIBIG
argument_list|)
expr_stmt|;
name|neg_limit_len
operator|=
name|strlen
argument_list|(
name|neg_limit
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* exclude - */
block|}
comment|/* 	 * the search for a good line 	 */
if|if
condition|(
name|input
operator|!=
name|NULL
operator|&&
name|fgets
argument_list|(
name|buf
argument_list|,
name|MAX_LINE
argument_list|,
name|input
argument_list|)
operator|==
name|NULL
condition|)
block|{
comment|/* error or EOF */
return|return
name|NULL
return|;
block|}
do|do
block|{
comment|/* ignore leading whitespace */
for|for
control|(
name|s
operator|=
name|buf
init|;
operator|*
name|s
operator|&&
name|s
operator|<
name|buf
operator|+
name|MAX_LINE
condition|;
operator|++
name|s
control|)
block|{
if|if
condition|(
operator|!
name|isascii
argument_list|(
operator|*
name|s
argument_list|)
operator|||
operator|!
name|isspace
argument_list|(
operator|*
name|s
argument_list|)
condition|)
block|{
break|break;
block|}
block|}
comment|/* skip over any leading + or - */
if|if
condition|(
operator|*
name|s
operator|==
literal|'+'
operator|||
operator|*
name|s
operator|==
literal|'-'
condition|)
block|{
name|d
operator|=
name|s
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
name|d
operator|=
name|s
expr_stmt|;
block|}
comment|/* note leading zeros */
for|for
control|(
name|z
operator|=
name|d
init|;
operator|*
name|z
operator|&&
name|z
operator|<
name|buf
operator|+
name|MAX_LINE
condition|;
operator|++
name|z
control|)
block|{
if|if
condition|(
operator|*
name|z
operator|!=
literal|'0'
condition|)
block|{
break|break;
block|}
block|}
comment|/* scan for the first non-digit */
for|for
control|(
name|p
operator|=
name|d
init|;
operator|*
name|p
operator|&&
name|p
operator|<
name|buf
operator|+
name|MAX_LINE
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|!
name|isascii
argument_list|(
operator|*
name|p
argument_list|)
operator|||
operator|!
name|isdigit
argument_list|(
operator|*
name|p
argument_list|)
condition|)
block|{
break|break;
block|}
block|}
comment|/* ignore empty lines */
if|if
condition|(
name|p
operator|==
name|d
condition|)
block|{
continue|continue;
block|}
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* object if too many digits */
name|len
operator|=
name|strlen
argument_list|(
name|z
argument_list|)
expr_stmt|;
name|len
operator|=
operator|(
name|len
operator|<=
literal|0
operator|)
condition|?
literal|1
else|:
name|len
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'-'
condition|)
block|{
comment|/* accept if digit count is below limit */
if|if
condition|(
name|len
operator|<
name|neg_limit_len
condition|)
block|{
comment|/* we have good input */
return|return
name|s
return|;
comment|/* reject very large numbers */
block|}
elseif|else
if|if
condition|(
name|len
operator|>
name|neg_limit_len
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* carefully check against near limit numbers */
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|z
argument_list|,
name|neg_limit
operator|+
literal|1
argument_list|)
operator|>
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* number is near limit, but is under it */
return|return
name|s
return|;
block|}
else|else
block|{
comment|/* accept if digit count is below limit */
if|if
condition|(
name|len
operator|<
name|limit_len
condition|)
block|{
comment|/* we have good input */
return|return
name|s
return|;
comment|/* reject very large numbers */
block|}
elseif|else
if|if
condition|(
name|len
operator|>
name|limit_len
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* carefully check against near limit numbers */
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|z
argument_list|,
name|limit
argument_list|)
operator|>
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: ouch\n"
argument_list|,
name|program
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* number is near limit, but is under it */
return|return
name|s
return|;
block|}
block|}
do|while
condition|(
name|input
operator|!=
name|NULL
operator|&&
name|fgets
argument_list|(
name|buf
argument_list|,
name|MAX_LINE
argument_list|,
name|input
argument_list|)
operator|!=
name|NULL
condition|)
do|;
comment|/* error or EOF */
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*  * pr_fact - print the factors of a number  *  * If the number is 0 or 1, then print the number and return.  * If the number is< 0, print -1, negate the number and continue  * processing.  *  * Print the factors of the number, from the lowest to the highest.  * A factor will be printed numtiple times if it divides the value  * multiple times.  *  * Factors are printed with leading tabs.  */
end_comment

begin_function
name|void
name|pr_fact
parameter_list|(
name|val
parameter_list|)
name|long
name|val
decl_stmt|;
comment|/* factor this value */
block|{
name|ubig
modifier|*
name|fact
decl_stmt|;
comment|/* the factor found */
comment|/* firewall - catch 0 and 1 */
switch|switch
condition|(
name|val
condition|)
block|{
case|case
operator|-
literal|2147483648
case|:
comment|/* avoid negation problems */
name|puts
argument_list|(
literal|"-2147483648: -1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n"
argument_list|)
expr_stmt|;
return|return;
case|case
operator|-
literal|1
case|:
name|puts
argument_list|(
literal|"-1: -1\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|0
case|:
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|1
case|:
name|puts
argument_list|(
literal|"1: 1\n"
argument_list|)
expr_stmt|;
return|return;
default|default:
if|if
condition|(
name|val
operator|<
literal|0
condition|)
block|{
name|val
operator|=
operator|-
name|val
expr_stmt|;
name|printf
argument_list|(
literal|"%ld: -1"
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"%ld:"
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* 	 * factor value 	 */
name|fact
operator|=
operator|&
name|prime
index|[
literal|0
index|]
expr_stmt|;
while|while
condition|(
name|val
operator|>
literal|1
condition|)
block|{
comment|/* look for the smallest factor */
do|do
block|{
if|if
condition|(
name|val
operator|%
operator|(
name|long
operator|)
operator|*
name|fact
operator|==
literal|0
condition|)
block|{
break|break;
block|}
block|}
do|while
condition|(
operator|++
name|fact
operator|<=
name|pr_limit
condition|)
do|;
comment|/* watch for primes larger than the table */
if|if
condition|(
name|fact
operator|>
name|pr_limit
condition|)
block|{
name|printf
argument_list|(
literal|" %ld\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* divide factor out until none are left */
do|do
block|{
name|printf
argument_list|(
literal|" %ld"
argument_list|,
operator|*
name|fact
argument_list|)
expr_stmt|;
name|val
operator|/=
operator|(
name|long
operator|)
operator|*
name|fact
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|val
operator|%
operator|(
name|long
operator|)
operator|*
name|fact
operator|)
operator|==
literal|0
condition|)
do|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
operator|++
name|fact
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

