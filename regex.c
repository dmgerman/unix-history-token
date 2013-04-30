begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** regex - regular expression functions related to POSIX regex lib. */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_include
include|#
directive|include
file|"flexdef.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|REGEXP_LINEDIR
init|=
literal|"^#line ([[:digit:]]+) \"(.*)\""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|REGEXP_BLANK_LINE
init|=
literal|"^[[:space:]]*$"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|regex_t
name|regex_linedir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**< matches line directives */
end_comment

begin_decl_stmt
name|regex_t
name|regex_blank_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**< matches blank lines */
end_comment

begin_comment
comment|/** Initialize the regular expressions.  * @return true upon success.  */
end_comment

begin_function
name|bool
name|flex_init_regex
parameter_list|(
name|void
parameter_list|)
block|{
name|flex_regcomp
argument_list|(
operator|&
name|regex_linedir
argument_list|,
name|REGEXP_LINEDIR
argument_list|,
name|REG_EXTENDED
argument_list|)
expr_stmt|;
name|flex_regcomp
argument_list|(
operator|&
name|regex_blank_line
argument_list|,
name|REGEXP_BLANK_LINE
argument_list|,
name|REG_EXTENDED
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/** Compiles a regular expression or dies trying.  * @param preg  Same as for regcomp().  * @param regex Same as for regcomp().  * @param cflags Same as for regcomp().  */
end_comment

begin_function
name|void
name|flex_regcomp
parameter_list|(
name|regex_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
name|int
name|cflags
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|memset
argument_list|(
name|preg
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|regex_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|err
operator|=
name|regcomp
argument_list|(
name|preg
argument_list|,
name|regex
argument_list|,
name|cflags
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
specifier|const
name|int
name|errbuf_sz
init|=
literal|200
decl_stmt|;
name|char
modifier|*
name|errbuf
decl_stmt|,
modifier|*
name|rxerr
decl_stmt|;
name|errbuf
operator|=
operator|(
name|char
operator|*
operator|)
name|flex_alloc
argument_list|(
name|errbuf_sz
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|errbuf
condition|)
name|flexfatal
argument_list|(
name|_
argument_list|(
literal|"Unable to allocate buffer to report regcomp"
argument_list|)
argument_list|)
expr_stmt|;
name|rxerr
operator|=
operator|(
name|char
operator|*
operator|)
name|flex_alloc
argument_list|(
name|errbuf_sz
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rxerr
condition|)
name|flexfatal
argument_list|(
name|_
argument_list|(
literal|"Unable to allocate buffer for regerror"
argument_list|)
argument_list|)
expr_stmt|;
name|regerror
argument_list|(
name|err
argument_list|,
name|preg
argument_list|,
name|rxerr
argument_list|,
name|errbuf_sz
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|errbuf_sz
argument_list|,
literal|"regcomp for \"%s\" failed: %s"
argument_list|,
name|regex
argument_list|,
name|rxerr
argument_list|)
expr_stmt|;
name|flexfatal
argument_list|(
name|errbuf
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|errbuf
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|rxerr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/** Extract a copy of the match, or NULL if no match.  * @param m A match as returned by regexec().  * @param src The source string that was passed to regexec().  * @return The allocated string.  */
end_comment

begin_function
name|char
modifier|*
name|regmatch_dup
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|int
name|len
decl_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|m
operator|->
name|rm_so
operator|<
literal|0
condition|)
return|return
name|NULL
return|;
name|len
operator|=
name|m
operator|->
name|rm_eo
operator|-
name|m
operator|->
name|rm_so
expr_stmt|;
name|str
operator|=
operator|(
name|char
operator|*
operator|)
name|flex_alloc
argument_list|(
operator|(
name|len
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
condition|)
name|flexfatal
argument_list|(
name|_
argument_list|(
literal|"Unable to allocate a copy of the match"
argument_list|)
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|str
argument_list|,
name|src
operator|+
name|m
operator|->
name|rm_so
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|str
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|str
return|;
block|}
end_function

begin_comment
comment|/** Copy the match.  * @param m A match as returned by regexec().  * @param dest The destination buffer.  * @param src The source string that was passed to regexec().  * @return dest  */
end_comment

begin_function
name|char
modifier|*
name|regmatch_cpy
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|m
operator|->
name|rm_so
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|dest
condition|)
name|dest
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|dest
return|;
block|}
name|snprintf
argument_list|(
name|dest
argument_list|,
name|regmatch_len
argument_list|(
name|m
argument_list|)
argument_list|,
literal|"%s"
argument_list|,
name|src
operator|+
name|m
operator|->
name|rm_so
argument_list|)
expr_stmt|;
return|return
name|dest
return|;
block|}
end_function

begin_comment
comment|/** Get the length in characters of the match.  * @param m A match as returned by regexec().  * @param src The source string that was passed to regexec().  * @return The length of the match.  */
end_comment

begin_function
name|int
name|regmatch_len
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|m
operator|->
name|rm_so
operator|<
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
name|m
operator|->
name|rm_eo
operator|-
name|m
operator|->
name|rm_so
return|;
block|}
end_function

begin_comment
comment|/** Convert a regmatch_t object to an integer using the strtol() function.  * @param m A match as returned by regexec().  * @param src The source string that was passed to regexec().  * @param endptr Same as the second argument to strtol().  * @param base   Same as the third argument to strtol().  * @return The converted integer or error (Return value is the same as for strtol()).  */
end_comment

begin_function
name|int
name|regmatch_strtol
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
define|#
directive|define
name|bufsz
value|20
name|char
name|buf
index|[
name|bufsz
index|]
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|m
operator|->
name|rm_so
operator|<
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|regmatch_len
argument_list|(
name|m
argument_list|)
operator|<
name|bufsz
condition|)
name|s
operator|=
name|regmatch_cpy
argument_list|(
name|m
argument_list|,
name|buf
argument_list|,
name|src
argument_list|)
expr_stmt|;
else|else
name|s
operator|=
name|regmatch_dup
argument_list|(
name|m
argument_list|,
name|src
argument_list|)
expr_stmt|;
name|n
operator|=
name|strtol
argument_list|(
name|s
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|buf
condition|)
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|/** Check for empty or non-existent match.  * @param m A match as returned by regexec().  * @return false if match length is non-zero.  * Note that reg_empty returns true even if match did not occur at all.  */
end_comment

begin_function
name|bool
name|regmatch_empty
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|)
block|{
return|return
operator|(
name|m
operator|==
name|NULL
operator|||
name|m
operator|->
name|rm_so
operator|<
literal|0
operator|||
name|m
operator|->
name|rm_so
operator|==
name|m
operator|->
name|rm_eo
operator|)
return|;
block|}
end_function

begin_comment
comment|/* vim:set expandtab cindent tabstop=4 softtabstop=4 shiftwidth=4 textwidth=0: */
end_comment

end_unit

