begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config_file.c :  parsing configuration files  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|<apr_lib.h>
end_include

begin_include
include|#
directive|include
file|<apr_env.h>
end_include

begin_include
include|#
directive|include
file|"config_impl.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_dirent_uri.h"
end_include

begin_include
include|#
directive|include
file|"svn_auth.h"
end_include

begin_include
include|#
directive|include
file|"svn_subst.h"
end_include

begin_include
include|#
directive|include
file|"svn_utf.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_user.h"
end_include

begin_include
include|#
directive|include
file|"svn_ctype.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__HAIKU__
end_ifdef

begin_include
include|#
directive|include
file|<FindDirectory.h>
end_include

begin_include
include|#
directive|include
file|<StorageDefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Used to terminate lines in large multi-line string literals. */
end_comment

begin_define
define|#
directive|define
name|NL
value|APR_EOL_STR
end_define

begin_escape
end_escape

begin_comment
comment|/* File parsing context */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|parse_context_t
block|{
comment|/* This config struct */
name|svn_config_t
modifier|*
name|cfg
decl_stmt|;
comment|/* The stream struct */
name|svn_stream_t
modifier|*
name|stream
decl_stmt|;
comment|/* The current line in the file */
name|int
name|line
decl_stmt|;
comment|/* Emulate an ungetc */
name|int
name|ungotten_char
decl_stmt|;
comment|/* Temporary strings */
name|svn_stringbuf_t
modifier|*
name|section
decl_stmt|;
name|svn_stringbuf_t
modifier|*
name|option
decl_stmt|;
name|svn_stringbuf_t
modifier|*
name|value
decl_stmt|;
comment|/* Parser buffer for getc() to avoid call overhead into several libraries      for every character */
name|char
name|parser_buffer
index|[
name|SVN__STREAM_CHUNK_SIZE
index|]
decl_stmt|;
comment|/* Larger than most config files */
name|size_t
name|buffer_pos
decl_stmt|;
comment|/* Current position within parser_buffer */
name|size_t
name|buffer_size
decl_stmt|;
comment|/* parser_buffer contains this many bytes */
block|}
name|parse_context_t
typedef|;
end_typedef

begin_comment
comment|/* Emulate getc() because streams don't support it.  *  * In order to be able to ungetc(), use the CXT instead of the stream  * to be able to store the 'ungotton' character.  *  */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|parser_getc
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|int
modifier|*
name|c
parameter_list|)
block|{
do|do
block|{
if|if
condition|(
name|ctx
operator|->
name|ungotten_char
operator|!=
name|EOF
condition|)
block|{
operator|*
name|c
operator|=
name|ctx
operator|->
name|ungotten_char
expr_stmt|;
name|ctx
operator|->
name|ungotten_char
operator|=
name|EOF
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ctx
operator|->
name|buffer_pos
operator|<
name|ctx
operator|->
name|buffer_size
condition|)
block|{
operator|*
name|c
operator|=
operator|(
name|unsigned
name|char
operator|)
name|ctx
operator|->
name|parser_buffer
index|[
name|ctx
operator|->
name|buffer_pos
index|]
expr_stmt|;
name|ctx
operator|->
name|buffer_pos
operator|++
expr_stmt|;
block|}
else|else
block|{
name|ctx
operator|->
name|buffer_pos
operator|=
literal|0
expr_stmt|;
name|ctx
operator|->
name|buffer_size
operator|=
sizeof|sizeof
argument_list|(
name|ctx
operator|->
name|parser_buffer
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_stream_read
argument_list|(
name|ctx
operator|->
name|stream
argument_list|,
name|ctx
operator|->
name|parser_buffer
argument_list|,
operator|&
operator|(
name|ctx
operator|->
name|buffer_size
operator|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|buffer_pos
operator|<
name|ctx
operator|->
name|buffer_size
condition|)
block|{
operator|*
name|c
operator|=
operator|(
name|unsigned
name|char
operator|)
name|ctx
operator|->
name|parser_buffer
index|[
name|ctx
operator|->
name|buffer_pos
index|]
expr_stmt|;
name|ctx
operator|->
name|buffer_pos
operator|++
expr_stmt|;
block|}
else|else
operator|*
name|c
operator|=
name|EOF
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|*
name|c
operator|==
literal|'\r'
condition|)
do|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Simplified version of parser_getc() to be used inside skipping loops.  * It will not check for 'ungotton' chars and may or may not ignore '\r'.  *  * In a 'while(cond) getc();' loop, the first iteration must call  * parser_getc to handle all the special cases.  Later iterations should  * use parser_getc_plain for maximum performance.  */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|parser_getc_plain
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|int
modifier|*
name|c
parameter_list|)
block|{
if|if
condition|(
name|ctx
operator|->
name|buffer_pos
operator|<
name|ctx
operator|->
name|buffer_size
condition|)
block|{
operator|*
name|c
operator|=
operator|(
name|unsigned
name|char
operator|)
name|ctx
operator|->
name|parser_buffer
index|[
name|ctx
operator|->
name|buffer_pos
index|]
expr_stmt|;
name|ctx
operator|->
name|buffer_pos
operator|++
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
return|return
name|parser_getc
argument_list|(
name|ctx
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Emulate ungetc() because streams don't support it.  *  * Use CTX to store the ungotten character C.  */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|parser_ungetc
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|ctx
operator|->
name|ungotten_char
operator|=
name|c
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Eat chars from STREAM until encounter non-whitespace, newline, or EOF.    Set *PCOUNT to the number of characters eaten, not counting the    last one, and return the last char read (the one that caused the    break).  */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|skip_whitespace
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|int
modifier|*
name|c
parameter_list|,
name|int
modifier|*
name|pcount
parameter_list|)
block|{
name|int
name|ch
init|=
literal|0
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|svn_ctype_isspace
argument_list|(
name|ch
argument_list|)
operator|&&
name|ch
operator|!=
literal|'\n'
operator|&&
name|ch
operator|!=
name|EOF
condition|)
block|{
operator|++
name|count
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc_plain
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|*
name|pcount
operator|=
name|count
expr_stmt|;
operator|*
name|c
operator|=
name|ch
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Skip to the end of the line (or file).  Returns the char that ended    the line; the char is either EOF or newline. */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|skip_to_eoln
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|int
modifier|*
name|c
parameter_list|)
block|{
name|int
name|ch
decl_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|ch
operator|!=
literal|'\n'
operator|&&
name|ch
operator|!=
name|EOF
condition|)
name|SVN_ERR
argument_list|(
name|parser_getc_plain
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|c
operator|=
name|ch
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Skip a UTF-8 Byte Order Mark if found. */
end_comment

begin_function
specifier|static
name|APR_INLINE
name|svn_error_t
modifier|*
name|skip_bom
parameter_list|(
name|parse_context_t
modifier|*
name|ctx
parameter_list|)
block|{
name|int
name|ch
decl_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch
operator|==
literal|0xEF
condition|)
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|buf
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|ctx
operator|->
name|parser_buffer
decl_stmt|;
comment|/* This makes assumptions about the implementation of parser_getc and        * the use of skip_bom.  Specifically that parser_getc() will get all        * of the BOM characters into the parse_context_t buffer.  This can        * safely be assumed as long as we only try to use skip_bom() at the        * start of the stream and the buffer is longer than 3 characters. */
name|SVN_ERR_ASSERT
argument_list|(
name|ctx
operator|->
name|buffer_size
operator|>
name|ctx
operator|->
name|buffer_pos
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
index|[
name|ctx
operator|->
name|buffer_pos
index|]
operator|==
literal|0xBB
operator|&&
name|buf
index|[
name|ctx
operator|->
name|buffer_pos
operator|+
literal|1
index|]
operator|==
literal|0xBF
condition|)
name|ctx
operator|->
name|buffer_pos
operator|+=
literal|2
expr_stmt|;
else|else
name|SVN_ERR
argument_list|(
name|parser_ungetc
argument_list|(
name|ctx
argument_list|,
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|SVN_ERR
argument_list|(
name|parser_ungetc
argument_list|(
name|ctx
argument_list|,
name|ch
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Parse a single option value */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|parse_value
parameter_list|(
name|int
modifier|*
name|pch
parameter_list|,
name|parse_context_t
modifier|*
name|ctx
parameter_list|)
block|{
name|svn_boolean_t
name|end_of_val
init|=
name|FALSE
decl_stmt|;
name|int
name|ch
decl_stmt|;
comment|/* Read the first line of the value */
name|svn_stringbuf_setempty
argument_list|(
name|ctx
operator|->
name|value
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|ch
operator|!=
name|EOF
operator|&&
name|ch
operator|!=
literal|'\n'
condition|)
comment|/* last ch seen was ':' or '=' in parse_option. */
block|{
specifier|const
name|char
name|char_from_int
init|=
operator|(
name|char
operator|)
name|ch
decl_stmt|;
name|svn_stringbuf_appendbyte
argument_list|(
name|ctx
operator|->
name|value
argument_list|,
name|char_from_int
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Leading and trailing whitespace is ignored. */
name|svn_stringbuf_strip_whitespace
argument_list|(
name|ctx
operator|->
name|value
argument_list|)
expr_stmt|;
comment|/* Look for any continuation lines. */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|ch
operator|==
name|EOF
operator|||
name|end_of_val
condition|)
block|{
comment|/* At end of file. The value is complete, there can't be              any continuation lines. */
name|svn_config_set
argument_list|(
name|ctx
operator|->
name|cfg
argument_list|,
name|ctx
operator|->
name|section
operator|->
name|data
argument_list|,
name|ctx
operator|->
name|option
operator|->
name|data
argument_list|,
name|ctx
operator|->
name|value
operator|->
name|data
argument_list|)
expr_stmt|;
break|break;
block|}
else|else
block|{
name|int
name|count
decl_stmt|;
operator|++
name|ctx
operator|->
name|line
expr_stmt|;
name|SVN_ERR
argument_list|(
name|skip_whitespace
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|,
operator|&
name|count
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'\n'
case|:
comment|/* The next line was empty. Ergo, it can't be a                  continuation line. */
operator|++
name|ctx
operator|->
name|line
expr_stmt|;
name|end_of_val
operator|=
name|TRUE
expr_stmt|;
continue|continue;
case|case
name|EOF
case|:
comment|/* This is also an empty line. */
name|end_of_val
operator|=
name|TRUE
expr_stmt|;
continue|continue;
default|default:
if|if
condition|(
name|count
operator|==
literal|0
condition|)
block|{
comment|/* This line starts in the first column.  That means                      it's either a section, option or comment.  Put                      the char back into the stream, because it doesn't                      belong to us. */
name|SVN_ERR
argument_list|(
name|parser_ungetc
argument_list|(
name|ctx
argument_list|,
name|ch
argument_list|)
argument_list|)
expr_stmt|;
name|end_of_val
operator|=
name|TRUE
expr_stmt|;
block|}
else|else
block|{
comment|/* This is a continuation line. Read it. */
name|svn_stringbuf_appendbyte
argument_list|(
name|ctx
operator|->
name|value
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
while|while
condition|(
name|ch
operator|!=
name|EOF
operator|&&
name|ch
operator|!=
literal|'\n'
condition|)
block|{
specifier|const
name|char
name|char_from_int
init|=
operator|(
name|char
operator|)
name|ch
decl_stmt|;
name|svn_stringbuf_appendbyte
argument_list|(
name|ctx
operator|->
name|value
argument_list|,
name|char_from_int
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Trailing whitespace is ignored. */
name|svn_stringbuf_strip_whitespace
argument_list|(
name|ctx
operator|->
name|value
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
operator|*
name|pch
operator|=
name|ch
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Parse a single option */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|parse_option
parameter_list|(
name|int
modifier|*
name|pch
parameter_list|,
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
init|=
name|SVN_NO_ERROR
decl_stmt|;
name|int
name|ch
decl_stmt|;
name|svn_stringbuf_setempty
argument_list|(
name|ctx
operator|->
name|option
argument_list|)
expr_stmt|;
name|ch
operator|=
operator|*
name|pch
expr_stmt|;
comment|/* Yes, the first char is relevant. */
while|while
condition|(
name|ch
operator|!=
name|EOF
operator|&&
name|ch
operator|!=
literal|':'
operator|&&
name|ch
operator|!=
literal|'='
operator|&&
name|ch
operator|!=
literal|'\n'
condition|)
block|{
specifier|const
name|char
name|char_from_int
init|=
operator|(
name|char
operator|)
name|ch
decl_stmt|;
name|svn_stringbuf_appendbyte
argument_list|(
name|ctx
operator|->
name|option
argument_list|,
name|char_from_int
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ch
operator|!=
literal|':'
operator|&&
name|ch
operator|!=
literal|'='
condition|)
block|{
name|ch
operator|=
name|EOF
expr_stmt|;
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Option must end with ':' or '='"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Whitespace around the name separator is ignored. */
name|svn_stringbuf_strip_whitespace
argument_list|(
name|ctx
operator|->
name|option
argument_list|)
expr_stmt|;
name|err
operator|=
name|parse_value
argument_list|(
operator|&
name|ch
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
block|}
operator|*
name|pch
operator|=
name|ch
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* Read chars until enounter ']', then skip everything to the end of  * the line.  Set *PCH to the character that ended the line (either  * newline or EOF), and set CTX->section to the string of characters  * seen before ']'.  *  * This is meant to be called immediately after reading the '[' that  * starts a section name.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|parse_section_name
parameter_list|(
name|int
modifier|*
name|pch
parameter_list|,
name|parse_context_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
init|=
name|SVN_NO_ERROR
decl_stmt|;
name|int
name|ch
decl_stmt|;
name|svn_stringbuf_setempty
argument_list|(
name|ctx
operator|->
name|section
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|ch
operator|!=
name|EOF
operator|&&
name|ch
operator|!=
literal|']'
operator|&&
name|ch
operator|!=
literal|'\n'
condition|)
block|{
specifier|const
name|char
name|char_from_int
init|=
operator|(
name|char
operator|)
name|ch
decl_stmt|;
name|svn_stringbuf_appendbyte
argument_list|(
name|ctx
operator|->
name|section
argument_list|,
name|char_from_int
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|parser_getc
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ch
operator|!=
literal|']'
condition|)
block|{
name|ch
operator|=
name|EOF
expr_stmt|;
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Section header must end with ']'"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Everything from the ']' to the end of the line is ignored. */
name|SVN_ERR
argument_list|(
name|skip_to_eoln
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch
operator|!=
name|EOF
condition|)
operator|++
name|ctx
operator|->
name|line
expr_stmt|;
block|}
operator|*
name|pch
operator|=
name|ch
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_config__sys_config_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path_p
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
operator|*
name|path_p
operator|=
name|NULL
expr_stmt|;
comment|/* Note that even if fname is null, svn_dirent_join_many will DTRT. */
ifdef|#
directive|ifdef
name|WIN32
block|{
specifier|const
name|char
modifier|*
name|folder
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_config__win_config_path
argument_list|(
operator|&
name|folder
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|path_p
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|folder
argument_list|,
name|SVN_CONFIG__SUBDIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
block|{
name|char
name|folder
index|[
name|B_PATH_NAME_LENGTH
index|]
decl_stmt|;
name|status_t
name|error
init|=
name|find_directory
argument_list|(
name|B_COMMON_SETTINGS_DIRECTORY
argument_list|,
operator|-
literal|1
argument_list|,
name|false
argument_list|,
name|folder
argument_list|,
sizeof|sizeof
argument_list|(
name|folder
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
return|return
name|SVN_NO_ERROR
return|;
operator|*
name|path_p
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|folder
argument_list|,
name|SVN_CONFIG__SYS_DIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* ! WIN32&& !__HAIKU__ */
operator|*
name|path_p
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|SVN_CONFIG__SYS_DIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WIN32 */
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*** Exported interfaces. ***/
end_comment

begin_escape
end_escape

begin_function
name|svn_error_t
modifier|*
name|svn_config__parse_file
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|svn_boolean_t
name|must_exist
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
init|=
name|SVN_NO_ERROR
decl_stmt|;
name|svn_stream_t
modifier|*
name|stream
decl_stmt|;
name|apr_pool_t
modifier|*
name|scratch_pool
init|=
name|svn_pool_create
argument_list|(
name|result_pool
argument_list|)
decl_stmt|;
name|err
operator|=
name|svn_stream_open_readonly
argument_list|(
operator|&
name|stream
argument_list|,
name|file
argument_list|,
name|scratch_pool
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|must_exist
operator|&&
name|err
operator|&&
name|APR_STATUS_IS_ENOENT
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|svn_pool_destroy
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
else|else
name|SVN_ERR
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_config__parse_stream
argument_list|(
name|cfg
argument_list|,
name|stream
argument_list|,
name|result_pool
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|SVN_NO_ERROR
condition|)
block|{
comment|/* Add the filename to the error stack. */
name|err
operator|=
name|svn_error_createf
argument_list|(
name|err
operator|->
name|apr_err
argument_list|,
name|err
argument_list|,
literal|"Error while parsing config file: %s:"
argument_list|,
name|svn_dirent_local_style
argument_list|(
name|file
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Close the streams (and other cleanup): */
name|svn_pool_destroy
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_config__parse_stream
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
name|parse_context_t
modifier|*
name|ctx
decl_stmt|;
name|int
name|ch
decl_stmt|,
name|count
decl_stmt|;
name|ctx
operator|=
name|apr_palloc
argument_list|(
name|scratch_pool
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ctx
argument_list|)
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|cfg
operator|=
name|cfg
expr_stmt|;
name|ctx
operator|->
name|stream
operator|=
name|stream
expr_stmt|;
name|ctx
operator|->
name|line
operator|=
literal|1
expr_stmt|;
name|ctx
operator|->
name|ungotten_char
operator|=
name|EOF
expr_stmt|;
name|ctx
operator|->
name|section
operator|=
name|svn_stringbuf_create_empty
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|option
operator|=
name|svn_stringbuf_create_empty
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|value
operator|=
name|svn_stringbuf_create_empty
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|buffer_pos
operator|=
literal|0
expr_stmt|;
name|ctx
operator|->
name|buffer_size
operator|=
literal|0
expr_stmt|;
name|SVN_ERR
argument_list|(
name|skip_bom
argument_list|(
name|ctx
argument_list|)
argument_list|)
expr_stmt|;
do|do
block|{
name|SVN_ERR
argument_list|(
name|skip_whitespace
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|,
operator|&
name|count
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'['
case|:
comment|/* Start of section header */
if|if
condition|(
name|count
operator|==
literal|0
condition|)
name|SVN_ERR
argument_list|(
name|parse_section_name
argument_list|(
operator|&
name|ch
argument_list|,
name|ctx
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
else|else
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Section header"
literal|" must start in the first column"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
return|;
break|break;
case|case
literal|'#'
case|:
comment|/* Comment */
if|if
condition|(
name|count
operator|==
literal|0
condition|)
block|{
name|SVN_ERR
argument_list|(
name|skip_to_eoln
argument_list|(
name|ctx
argument_list|,
operator|&
name|ch
argument_list|)
argument_list|)
expr_stmt|;
operator|++
operator|(
name|ctx
operator|->
name|line
operator|)
expr_stmt|;
block|}
else|else
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Comment"
literal|" must start in the first column"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
return|;
break|break;
case|case
literal|'\n'
case|:
comment|/* Empty line */
operator|++
operator|(
name|ctx
operator|->
name|line
operator|)
expr_stmt|;
break|break;
case|case
name|EOF
case|:
comment|/* End of file or read error */
break|break;
default|default:
if|if
condition|(
name|svn_stringbuf_isempty
argument_list|(
name|ctx
operator|->
name|section
argument_list|)
condition|)
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Section header expected"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
return|;
elseif|else
if|if
condition|(
name|count
operator|!=
literal|0
condition|)
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|NULL
argument_list|,
literal|"line %d: Option expected"
argument_list|,
name|ctx
operator|->
name|line
argument_list|)
return|;
else|else
name|SVN_ERR
argument_list|(
name|parse_option
argument_list|(
operator|&
name|ch
argument_list|,
name|ctx
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
name|ch
operator|!=
name|EOF
condition|)
do|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Helper for ensure_auth_dirs: create SUBDIR under AUTH_DIR, iff    SUBDIR does not already exist, but ignore any errors.  Use POOL for    temporary allocation. */
end_comment

begin_function
specifier|static
name|void
name|ensure_auth_subdir
parameter_list|(
specifier|const
name|char
modifier|*
name|auth_dir
parameter_list|,
specifier|const
name|char
modifier|*
name|subdir
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
decl_stmt|;
specifier|const
name|char
modifier|*
name|subdir_full_path
decl_stmt|;
name|svn_node_kind_t
name|kind
decl_stmt|;
name|subdir_full_path
operator|=
name|svn_dirent_join
argument_list|(
name|auth_dir
argument_list|,
name|subdir
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|subdir_full_path
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|||
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|svn_error_clear
argument_list|(
name|svn_io_dir_make
argument_list|(
name|subdir_full_path
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Helper for svn_config_ensure:  see if ~/.subversion/auth/ and its    subdirs exist, try to create them, but don't throw errors on    failure.  PATH is assumed to be a path to the user's private config    directory. */
end_comment

begin_function
specifier|static
name|void
name|ensure_auth_dirs
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_node_kind_t
name|kind
decl_stmt|;
specifier|const
name|char
modifier|*
name|auth_dir
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
comment|/* Ensure ~/.subversion/auth/ */
name|auth_dir
operator|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_CONFIG__AUTH_SUBDIR
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|auth_dir
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|||
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
comment|/* 'chmod 700' permissions: */
name|err
operator|=
name|svn_io_dir_make
argument_list|(
name|auth_dir
argument_list|,
operator|(
name|APR_UREAD
operator||
name|APR_UWRITE
operator||
name|APR_UEXECUTE
operator|)
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* Don't try making subdirs if we can't make the top-level dir. */
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
comment|/* If a provider exists that wants to store credentials in      ~/.subversion, a subdirectory for the cred_kind must exist. */
name|ensure_auth_subdir
argument_list|(
name|auth_dir
argument_list|,
name|SVN_AUTH_CRED_SIMPLE
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|ensure_auth_subdir
argument_list|(
name|auth_dir
argument_list|,
name|SVN_AUTH_CRED_USERNAME
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|ensure_auth_subdir
argument_list|(
name|auth_dir
argument_list|,
name|SVN_AUTH_CRED_SSL_SERVER_TRUST
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|ensure_auth_subdir
argument_list|(
name|auth_dir
argument_list|,
name|SVN_AUTH_CRED_SSL_CLIENT_CERT_PW
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_config_ensure
parameter_list|(
specifier|const
name|char
modifier|*
name|config_dir
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|svn_node_kind_t
name|kind
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
comment|/* Ensure that the user-specific config directory exists.  */
name|SVN_ERR
argument_list|(
name|svn_config_get_user_config_path
argument_list|(
operator|&
name|path
argument_list|,
name|config_dir
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
condition|)
return|return
name|SVN_NO_ERROR
return|;
name|err
operator|=
name|svn_io_check_resolved_path
argument_list|(
name|path
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* Don't throw an error, but don't continue. */
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
if|if
condition|(
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|err
operator|=
name|svn_io_dir_make
argument_list|(
name|path
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* Don't throw an error, but don't continue. */
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|kind
operator|==
name|svn_node_file
condition|)
block|{
comment|/* Somebody put a file where the config directory should be.          Wacky.  Let's bail. */
return|return
name|SVN_NO_ERROR
return|;
block|}
comment|/* Else, there's a configuration directory. */
comment|/* If we get errors trying to do things below, just stop and return      success.  There's no _need_ to init a config directory if      something's preventing it. */
comment|/** If non-existent, try to create a number of auth/ subdirectories. */
name|ensure_auth_dirs
argument_list|(
name|path
argument_list|,
name|pool
argument_list|)
expr_stmt|;
comment|/** Ensure that the `README.txt' file exists. **/
name|SVN_ERR
argument_list|(
name|svn_config_get_user_config_path
argument_list|(
operator|&
name|path
argument_list|,
name|config_dir
argument_list|,
name|SVN_CONFIG__USR_README_FILE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
condition|)
comment|/* highly unlikely, since a previous call succeeded */
return|return
name|SVN_NO_ERROR
return|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|path
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
if|if
condition|(
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|apr_file_t
modifier|*
name|f
decl_stmt|;
specifier|const
name|char
modifier|*
name|contents
init|=
literal|"This directory holds run-time configuration information for Subversion"
name|NL
literal|"clients.  The configuration files all share the same syntax, but you"
name|NL
literal|"should examine a particular file to learn what configuration"
name|NL
literal|"directives are valid for that file."
name|NL
literal|""
name|NL
literal|"The syntax is standard INI format:"
name|NL
literal|""
name|NL
literal|"   - Empty lines, and lines starting with '#', are ignored."
name|NL
literal|"     The first significant line in a file must be a section header."
name|NL
literal|""
name|NL
literal|"   - A section starts with a section header, which must start in"
name|NL
literal|"     the first column:"
name|NL
literal|""
name|NL
literal|"       [section-name]"
name|NL
literal|""
name|NL
literal|"   - An option, which must always appear within a section, is a pair"
name|NL
literal|"     (name, value).  There are two valid forms for defining an"
name|NL
literal|"     option, both of which must start in the first column:"
name|NL
literal|""
name|NL
literal|"       name: value"
name|NL
literal|"       name = value"
name|NL
literal|""
name|NL
literal|"     Whitespace around the separator (:, =) is optional."
name|NL
literal|""
name|NL
literal|"   - Section and option names are case-insensitive, but case is"
name|NL
literal|"     preserved."
name|NL
literal|""
name|NL
literal|"   - An option's value may be broken into several lines.  The value"
name|NL
literal|"     continuation lines must start with at least one whitespace."
name|NL
literal|"     Trailing whitespace in the previous line, the newline character"
name|NL
literal|"     and the leading whitespace in the continuation line is compressed"
name|NL
literal|"     into a single space character."
name|NL
literal|""
name|NL
literal|"   - All leading and trailing whitespace around a value is trimmed,"
name|NL
literal|"     but the whitespace within a value is preserved, with the"
name|NL
literal|"     exception of whitespace around line continuations, as"
name|NL
literal|"     described above."
name|NL
literal|""
name|NL
literal|"   - When a value is a boolean, any of the following strings are"
name|NL
literal|"     recognised as truth values (case does not matter):"
name|NL
literal|""
name|NL
literal|"       true      false"
name|NL
literal|"       yes       no"
name|NL
literal|"       on        off"
name|NL
literal|"       1         0"
name|NL
literal|""
name|NL
literal|"   - When a value is a list, it is comma-separated.  Again, the"
name|NL
literal|"     whitespace around each element of the list is trimmed."
name|NL
literal|""
name|NL
literal|"   - Option values may be expanded within a value by enclosing the"
name|NL
literal|"     option name in parentheses, preceded by a percent sign and"
name|NL
literal|"     followed by an 's':"
name|NL
literal|""
name|NL
literal|"       %(name)s"
name|NL
literal|""
name|NL
literal|"     The expansion is performed recursively and on demand, during"
name|NL
literal|"     svn_option_get.  The name is first searched for in the same"
name|NL
literal|"     section, then in the special [DEFAULT] section. If the name"
name|NL
literal|"     is not found, the whole '%(name)s' placeholder is left"
name|NL
literal|"     unchanged."
name|NL
literal|""
name|NL
literal|"     Any modifications to the configuration data invalidate all"
name|NL
literal|"     previously expanded values, so that the next svn_option_get"
name|NL
literal|"     will take the modifications into account."
name|NL
literal|""
name|NL
literal|"The syntax of the configuration files is a subset of the one used by"
name|NL
literal|"Python's ConfigParser module; see"
name|NL
literal|""
name|NL
literal|"   http://www.python.org/doc/current/lib/module-ConfigParser.html"
name|NL
literal|""
name|NL
literal|"Configuration data in the Windows registry"
name|NL
literal|"=========================================="
name|NL
literal|""
name|NL
literal|"On Windows, configuration data may also be stored in the registry. The"
name|NL
literal|"functions svn_config_read and svn_config_merge will read from the"
name|NL
literal|"registry when passed file names of the form:"
name|NL
literal|""
name|NL
literal|"   REGISTRY:<hive>/path/to/config-key"
name|NL
literal|""
name|NL
literal|"The REGISTRY: prefix must be in upper case. The<hive> part must be"
name|NL
literal|"one of:"
name|NL
literal|""
name|NL
literal|"   HKLM for HKEY_LOCAL_MACHINE"
name|NL
literal|"   HKCU for HKEY_CURRENT_USER"
name|NL
literal|""
name|NL
literal|"The values in config-key represent the options in the [DEFAULT] section."
name|NL
literal|"The keys below config-key represent other sections, and their values"
name|NL
literal|"represent the options. Only values of type REG_SZ whose name doesn't"
name|NL
literal|"start with a '#' will be used; other values, as well as the keys'"
name|NL
literal|"default values, will be ignored."
name|NL
literal|""
name|NL
literal|""
name|NL
literal|"File locations"
name|NL
literal|"=============="
name|NL
literal|""
name|NL
literal|"Typically, Subversion uses two config directories, one for site-wide"
name|NL
literal|"configuration,"
name|NL
literal|""
name|NL
literal|"  Unix:"
name|NL
literal|"    /etc/subversion/servers"
name|NL
literal|"    /etc/subversion/config"
name|NL
literal|"    /etc/subversion/hairstyles"
name|NL
literal|"  Windows:"
name|NL
literal|"    %ALLUSERSPROFILE%\\Application Data\\Subversion\\servers"
name|NL
literal|"    %ALLUSERSPROFILE%\\Application Data\\Subversion\\config"
name|NL
literal|"    %ALLUSERSPROFILE%\\Application Data\\Subversion\\hairstyles"
name|NL
literal|"    REGISTRY:HKLM\\Software\\Tigris.org\\Subversion\\Servers"
name|NL
literal|"    REGISTRY:HKLM\\Software\\Tigris.org\\Subversion\\Config"
name|NL
literal|"    REGISTRY:HKLM\\Software\\Tigris.org\\Subversion\\Hairstyles"
name|NL
literal|""
name|NL
literal|"and one for per-user configuration:"
name|NL
literal|""
name|NL
literal|"  Unix:"
name|NL
literal|"    ~/.subversion/servers"
name|NL
literal|"    ~/.subversion/config"
name|NL
literal|"    ~/.subversion/hairstyles"
name|NL
literal|"  Windows:"
name|NL
literal|"    %APPDATA%\\Subversion\\servers"
name|NL
literal|"    %APPDATA%\\Subversion\\config"
name|NL
literal|"    %APPDATA%\\Subversion\\hairstyles"
name|NL
literal|"    REGISTRY:HKCU\\Software\\Tigris.org\\Subversion\\Servers"
name|NL
literal|"    REGISTRY:HKCU\\Software\\Tigris.org\\Subversion\\Config"
name|NL
literal|"    REGISTRY:HKCU\\Software\\Tigris.org\\Subversion\\Hairstyles"
name|NL
literal|""
name|NL
decl_stmt|;
name|err
operator|=
name|svn_io_file_open
argument_list|(
operator|&
name|f
argument_list|,
name|path
argument_list|,
operator|(
name|APR_WRITE
operator||
name|APR_CREATE
operator||
name|APR_EXCL
operator|)
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|contents
argument_list|,
name|strlen
argument_list|(
name|contents
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_close
argument_list|(
name|f
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
comment|/** Ensure that the `servers' file exists. **/
name|SVN_ERR
argument_list|(
name|svn_config_get_user_config_path
argument_list|(
operator|&
name|path
argument_list|,
name|config_dir
argument_list|,
name|SVN_CONFIG_CATEGORY_SERVERS
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
condition|)
comment|/* highly unlikely, since a previous call succeeded */
return|return
name|SVN_NO_ERROR
return|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|path
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
if|if
condition|(
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|apr_file_t
modifier|*
name|f
decl_stmt|;
specifier|const
name|char
modifier|*
name|contents
init|=
literal|"### This file specifies server-specific parameters,"
name|NL
literal|"### including HTTP proxy information, HTTP timeout settings,"
name|NL
literal|"### and authentication settings."
name|NL
literal|"###"
name|NL
literal|"### The currently defined server options are:"
name|NL
literal|"###   http-proxy-host            Proxy host for HTTP connection"
name|NL
literal|"###   http-proxy-port            Port number of proxy host service"
name|NL
literal|"###   http-proxy-username        Username for auth to proxy service"
name|NL
literal|"###   http-proxy-password        Password for auth to proxy service"
name|NL
literal|"###   http-proxy-exceptions      List of sites that do not use proxy"
name|NL
literal|"###   http-timeout               Timeout for HTTP requests in seconds"
name|NL
literal|"###   http-compression           Whether to compress HTTP requests"
name|NL
literal|"###   http-max-connections       Maximum number of parallel server"
name|NL
literal|"###                              connections to use for any given"
name|NL
literal|"###                              HTTP operation."
name|NL
literal|"###   http-chunked-requests      Whether to use chunked transfer"
name|NL
literal|"###                              encoding for HTTP requests body."
name|NL
literal|"###   neon-debug-mask            Debug mask for Neon HTTP library"
name|NL
literal|"###   ssl-authority-files        List of files, each of a trusted CA"
name|NL
literal|"###   ssl-trust-default-ca       Trust the system 'default' CAs"
name|NL
literal|"###   ssl-client-cert-file       PKCS#12 format client certificate file"
name|NL
literal|"###   ssl-client-cert-password   Client Key password, if needed."
name|NL
literal|"###   ssl-pkcs11-provider        Name of PKCS#11 provider to use."
name|NL
literal|"###   http-library               Which library to use for http/https"
name|NL
literal|"###                              connections."
name|NL
literal|"###   http-bulk-updates          Whether to request bulk update"
name|NL
literal|"###                              responses or to fetch each file"
name|NL
literal|"###                              in an individual request. "
name|NL
literal|"###   store-passwords            Specifies whether passwords used"
name|NL
literal|"###                              to authenticate against a"
name|NL
literal|"###                              Subversion server may be cached"
name|NL
literal|"###                              to disk in any way."
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"###   store-plaintext-passwords  Specifies whether passwords may"
name|NL
literal|"###                              be cached on disk unencrypted."
name|NL
endif|#
directive|endif
literal|"###   store-ssl-client-cert-pp   Specifies whether passphrase used"
name|NL
literal|"###                              to authenticate against a client"
name|NL
literal|"###                              certificate may be cached to disk"
name|NL
literal|"###                              in any way"
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"###   store-ssl-client-cert-pp-plaintext"
name|NL
literal|"###                              Specifies whether client cert"
name|NL
literal|"###                              passphrases may be cached on disk"
name|NL
literal|"###                              unencrypted (i.e., as plaintext)."
name|NL
endif|#
directive|endif
literal|"###   store-auth-creds           Specifies whether any auth info"
name|NL
literal|"###                              (passwords, server certs, etc.)"
name|NL
literal|"###                              may be cached to disk."
name|NL
literal|"###   username                   Specifies the default username."
name|NL
literal|"###"
name|NL
literal|"### Set store-passwords to 'no' to avoid storing passwords on disk"
name|NL
literal|"### in any way, including in password stores.  It defaults to"
name|NL
literal|"### 'yes', but Subversion will never save your password to disk in"
name|NL
literal|"### plaintext unless explicitly configured to do so."
name|NL
literal|"### Note that this option only prevents saving of *new* passwords;"
name|NL
literal|"### it doesn't invalidate existing passwords.  (To do that, remove"
name|NL
literal|"### the cache files by hand as described in the Subversion book.)"
name|NL
literal|"###"
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"### Set store-plaintext-passwords to 'no' to avoid storing"
name|NL
literal|"### passwords in unencrypted form in the auth/ area of your config"
name|NL
literal|"### directory. Set it to 'yes' to allow Subversion to store"
name|NL
literal|"### unencrypted passwords in the auth/ area.  The default is"
name|NL
literal|"### 'ask', which means that Subversion will ask you before"
name|NL
literal|"### saving a password to disk in unencrypted form.  Note that"
name|NL
literal|"### this option has no effect if either 'store-passwords' or "
name|NL
literal|"### 'store-auth-creds' is set to 'no'."
name|NL
literal|"###"
name|NL
endif|#
directive|endif
literal|"### Set store-ssl-client-cert-pp to 'no' to avoid storing ssl"
name|NL
literal|"### client certificate passphrases in the auth/ area of your"
name|NL
literal|"### config directory.  It defaults to 'yes', but Subversion will"
name|NL
literal|"### never save your passphrase to disk in plaintext unless"
name|NL
literal|"### explicitly configured to do so."
name|NL
literal|"###"
name|NL
literal|"### Note store-ssl-client-cert-pp only prevents the saving of *new*"
name|NL
literal|"### passphrases; it doesn't invalidate existing passphrases.  To do"
name|NL
literal|"### that, remove the cache files by hand as described in the"
name|NL
literal|"### Subversion book at http://svnbook.red-bean.com/nightly/en/\\"
name|NL
literal|"###                    svn.serverconfig.netmodel.html\\"
name|NL
literal|"###                    #svn.serverconfig.netmodel.credcache"
name|NL
literal|"###"
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"### Set store-ssl-client-cert-pp-plaintext to 'no' to avoid storing"
name|NL
literal|"### passphrases in unencrypted form in the auth/ area of your"
name|NL
literal|"### config directory.  Set it to 'yes' to allow Subversion to"
name|NL
literal|"### store unencrypted passphrases in the auth/ area.  The default"
name|NL
literal|"### is 'ask', which means that Subversion will prompt before"
name|NL
literal|"### saving a passphrase to disk in unencrypted form.  Note that"
name|NL
literal|"### this option has no effect if either 'store-auth-creds' or "
name|NL
literal|"### 'store-ssl-client-cert-pp' is set to 'no'."
name|NL
literal|"###"
name|NL
endif|#
directive|endif
literal|"### Set store-auth-creds to 'no' to avoid storing any Subversion"
name|NL
literal|"### credentials in the auth/ area of your config directory."
name|NL
literal|"### Note that this includes SSL server certificates."
name|NL
literal|"### It defaults to 'yes'.  Note that this option only prevents"
name|NL
literal|"### saving of *new* credentials;  it doesn't invalidate existing"
name|NL
literal|"### caches.  (To do that, remove the cache files by hand.)"
name|NL
literal|"###"
name|NL
literal|"### HTTP timeouts, if given, are specified in seconds.  A timeout"
name|NL
literal|"### of 0, i.e. zero, causes a builtin default to be used."
name|NL
literal|"###"
name|NL
literal|"### Most users will not need to explicitly set the http-library"
name|NL
literal|"### option, but valid values for the option include:"
name|NL
literal|"###    'serf': Serf-based module (Subversion 1.5 - present)"
name|NL
literal|"###    'neon': Neon-based module (Subversion 1.0 - 1.7)"
name|NL
literal|"### Availability of these modules may depend on your specific"
name|NL
literal|"### Subversion distribution."
name|NL
literal|"###"
name|NL
literal|"### The commented-out examples below are intended only to"
name|NL
literal|"### demonstrate how to use this file; any resemblance to actual"
name|NL
literal|"### servers, living or dead, is entirely coincidental."
name|NL
literal|""
name|NL
literal|"### In the 'groups' section, the URL of the repository you're"
name|NL
literal|"### trying to access is matched against the patterns on the right."
name|NL
literal|"### If a match is found, the server options are taken from the"
name|NL
literal|"### section with the corresponding name on the left."
name|NL
literal|""
name|NL
literal|"[groups]"
name|NL
literal|"# group1 = *.collab.net"
name|NL
literal|"# othergroup = repository.blarggitywhoomph.com"
name|NL
literal|"# thirdgroup = *.example.com"
name|NL
literal|""
name|NL
literal|"### Information for the first group:"
name|NL
literal|"# [group1]"
name|NL
literal|"# http-proxy-host = proxy1.some-domain-name.com"
name|NL
literal|"# http-proxy-port = 80"
name|NL
literal|"# http-proxy-username = blah"
name|NL
literal|"# http-proxy-password = doubleblah"
name|NL
literal|"# http-timeout = 60"
name|NL
literal|"# neon-debug-mask = 130"
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"# store-plaintext-passwords = no"
name|NL
endif|#
directive|endif
literal|"# username = harry"
name|NL
literal|""
name|NL
literal|"### Information for the second group:"
name|NL
literal|"# [othergroup]"
name|NL
literal|"# http-proxy-host = proxy2.some-domain-name.com"
name|NL
literal|"# http-proxy-port = 9000"
name|NL
literal|"# No username and password for the proxy, so use the defaults below."
name|NL
literal|""
name|NL
literal|"### You can set default parameters in the 'global' section."
name|NL
literal|"### These parameters apply if no corresponding parameter is set in"
name|NL
literal|"### a specifically matched group as shown above.  Thus, if you go"
name|NL
literal|"### through the same proxy server to reach every site on the"
name|NL
literal|"### Internet, you probably just want to put that server's"
name|NL
literal|"### information in the 'global' section and not bother with"
name|NL
literal|"### 'groups' or any other sections."
name|NL
literal|"###"
name|NL
literal|"### Most people might want to configure password caching"
name|NL
literal|"### parameters here, but you can also configure them per server"
name|NL
literal|"### group (per-group settings override global settings)."
name|NL
literal|"###"
name|NL
literal|"### If you go through a proxy for all but a few sites, you can"
name|NL
literal|"### list those exceptions under 'http-proxy-exceptions'.  This only"
name|NL
literal|"### overrides defaults, not explicitly matched server names."
name|NL
literal|"###"
name|NL
literal|"### 'ssl-authority-files' is a semicolon-delimited list of files,"
name|NL
literal|"### each pointing to a PEM-encoded Certificate Authority (CA) "
name|NL
literal|"### SSL certificate.  See details above for overriding security "
name|NL
literal|"### due to SSL."
name|NL
literal|"[global]"
name|NL
literal|"# http-proxy-exceptions = *.exception.com, www.internal-site.org"
name|NL
literal|"# http-proxy-host = defaultproxy.whatever.com"
name|NL
literal|"# http-proxy-port = 7000"
name|NL
literal|"# http-proxy-username = defaultusername"
name|NL
literal|"# http-proxy-password = defaultpassword"
name|NL
literal|"# http-compression = no"
name|NL
literal|"# No http-timeout, so just use the builtin default."
name|NL
literal|"# No neon-debug-mask, so neon debugging is disabled."
name|NL
literal|"# ssl-authority-files = /path/to/CAcert.pem;/path/to/CAcert2.pem"
name|NL
literal|"#"
name|NL
literal|"# Password / passphrase caching parameters:"
name|NL
literal|"# store-passwords = no"
name|NL
literal|"# store-ssl-client-cert-pp = no"
name|NL
ifndef|#
directive|ifndef
name|SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE
literal|"# store-plaintext-passwords = no"
name|NL
literal|"# store-ssl-client-cert-pp-plaintext = no"
name|NL
endif|#
directive|endif
decl_stmt|;
name|err
operator|=
name|svn_io_file_open
argument_list|(
operator|&
name|f
argument_list|,
name|path
argument_list|,
operator|(
name|APR_WRITE
operator||
name|APR_CREATE
operator||
name|APR_EXCL
operator|)
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|contents
argument_list|,
name|strlen
argument_list|(
name|contents
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_close
argument_list|(
name|f
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
comment|/** Ensure that the `config' file exists. **/
name|SVN_ERR
argument_list|(
name|svn_config_get_user_config_path
argument_list|(
operator|&
name|path
argument_list|,
name|config_dir
argument_list|,
name|SVN_CONFIG_CATEGORY_CONFIG
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
condition|)
comment|/* highly unlikely, since a previous call succeeded */
return|return
name|SVN_NO_ERROR
return|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|path
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
if|if
condition|(
name|kind
operator|==
name|svn_node_none
condition|)
block|{
name|apr_file_t
modifier|*
name|f
decl_stmt|;
specifier|const
name|char
modifier|*
name|contents
init|=
literal|"### This file configures various client-side behaviors."
name|NL
literal|"###"
name|NL
literal|"### The commented-out examples below are intended to demonstrate"
name|NL
literal|"### how to use this file."
name|NL
literal|""
name|NL
literal|"### Section for authentication and authorization customizations."
name|NL
literal|"[auth]"
name|NL
literal|"### Set password stores used by Subversion. They should be"
name|NL
literal|"### delimited by spaces or commas. The order of values determines"
name|NL
literal|"### the order in which password stores are used."
name|NL
literal|"### Valid password stores:"
name|NL
literal|"###   gnome-keyring        (Unix-like systems)"
name|NL
literal|"###   kwallet              (Unix-like systems)"
name|NL
literal|"###   gpg-agent            (Unix-like systems)"
name|NL
literal|"###   keychain             (Mac OS X)"
name|NL
literal|"###   windows-cryptoapi    (Windows)"
name|NL
ifdef|#
directive|ifdef
name|SVN_HAVE_KEYCHAIN_SERVICES
literal|"# password-stores = keychain"
name|NL
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
literal|"# password-stores = windows-cryptoapi"
name|NL
else|#
directive|else
literal|"# password-stores = gpg-agent,gnome-keyring,kwallet"
name|NL
endif|#
directive|endif
literal|"### To disable all password stores, use an empty list:"
name|NL
literal|"# password-stores ="
name|NL
ifdef|#
directive|ifdef
name|SVN_HAVE_KWALLET
literal|"###"
name|NL
literal|"### Set KWallet wallet used by Subversion. If empty or unset,"
name|NL
literal|"### then the default network wallet will be used."
name|NL
literal|"# kwallet-wallet ="
name|NL
literal|"###"
name|NL
literal|"### Include PID (Process ID) in Subversion application name when"
name|NL
literal|"### using KWallet. It defaults to 'no'."
name|NL
literal|"# kwallet-svn-application-name-with-pid = yes"
name|NL
endif|#
directive|endif
literal|"###"
name|NL
literal|"### Set ssl-client-cert-file-prompt to 'yes' to cause the client"
name|NL
literal|"### to prompt for a path to a client cert file when the server"
name|NL
literal|"### requests a client cert but no client cert file is found in the"
name|NL
literal|"### expected place (see the 'ssl-client-cert-file' option in the"
name|NL
literal|"### 'servers' configuration file). Defaults to 'no'."
name|NL
literal|"# ssl-client-cert-file-prompt = no"
name|NL
literal|"###"
name|NL
literal|"### The rest of the [auth] section in this file has been deprecated."
name|NL
literal|"### Both 'store-passwords' and 'store-auth-creds' can now be"
name|NL
literal|"### specified in the 'servers' file in your config directory"
name|NL
literal|"### and are documented there. Anything specified in this section "
name|NL
literal|"### is overridden by settings specified in the 'servers' file."
name|NL
literal|"# store-passwords = no"
name|NL
literal|"# store-auth-creds = no"
name|NL
literal|""
name|NL
literal|"### Section for configuring external helper applications."
name|NL
literal|"[helpers]"
name|NL
literal|"### Set editor-cmd to the command used to invoke your text editor."
name|NL
literal|"###   This will override the environment variables that Subversion"
name|NL
literal|"###   examines by default to find this information ($EDITOR, "
name|NL
literal|"###   et al)."
name|NL
literal|"# editor-cmd = editor (vi, emacs, notepad, etc.)"
name|NL
literal|"### Set diff-cmd to the absolute path of your 'diff' program."
name|NL
literal|"###   This will override the compile-time default, which is to use"
name|NL
literal|"###   Subversion's internal diff implementation."
name|NL
literal|"# diff-cmd = diff_program (diff, gdiff, etc.)"
name|NL
literal|"### Diff-extensions are arguments passed to an external diff"
name|NL
literal|"### program or to Subversion's internal diff implementation."
name|NL
literal|"### Set diff-extensions to override the default arguments ('-u')."
name|NL
literal|"# diff-extensions = -u -p"
name|NL
literal|"### Set diff3-cmd to the absolute path of your 'diff3' program."
name|NL
literal|"###   This will override the compile-time default, which is to use"
name|NL
literal|"###   Subversion's internal diff3 implementation."
name|NL
literal|"# diff3-cmd = diff3_program (diff3, gdiff3, etc.)"
name|NL
literal|"### Set diff3-has-program-arg to 'yes' if your 'diff3' program"
name|NL
literal|"###   accepts the '--diff-program' option."
name|NL
literal|"# diff3-has-program-arg = [yes | no]"
name|NL
literal|"### Set merge-tool-cmd to the command used to invoke your external"
name|NL
literal|"### merging tool of choice. Subversion will pass 5 arguments to"
name|NL
literal|"### the specified command: base theirs mine merged wcfile"
name|NL
literal|"# merge-tool-cmd = merge_command"
name|NL
literal|""
name|NL
literal|"### Section for configuring tunnel agents."
name|NL
literal|"[tunnels]"
name|NL
literal|"### Configure svn protocol tunnel schemes here.  By default, only"
name|NL
literal|"### the 'ssh' scheme is defined.  You can define other schemes to"
name|NL
literal|"### be used with 'svn+scheme://hostname/path' URLs.  A scheme"
name|NL
literal|"### definition is simply a command, optionally prefixed by an"
name|NL
literal|"### environment variable name which can override the command if it"
name|NL
literal|"### is defined.  The command (or environment variable) may contain"
name|NL
literal|"### arguments, using standard shell quoting for arguments with"
name|NL
literal|"### spaces.  The command will be invoked as:"
name|NL
literal|"###<command><hostname> svnserve -t"
name|NL
literal|"### (If the URL includes a username, then the hostname will be"
name|NL
literal|"### passed to the tunnel agent as<user>@<hostname>.)  If the"
name|NL
literal|"### built-in ssh scheme were not predefined, it could be defined"
name|NL
literal|"### as:"
name|NL
literal|"# ssh = $SVN_SSH ssh -q"
name|NL
literal|"### If you wanted to define a new 'rsh' scheme, to be used with"
name|NL
literal|"### 'svn+rsh:' URLs, you could do so as follows:"
name|NL
literal|"# rsh = rsh"
name|NL
literal|"### Or, if you wanted to specify a full path and arguments:"
name|NL
literal|"# rsh = /path/to/rsh -l myusername"
name|NL
literal|"### On Windows, if you are specifying a full path to a command,"
name|NL
literal|"### use a forward slash (/) or a paired backslash (\\\\) as the"
name|NL
literal|"### path separator.  A single backslash will be treated as an"
name|NL
literal|"### escape for the following character."
name|NL
literal|""
name|NL
literal|"### Section for configuring miscellaneous Subversion options."
name|NL
literal|"[miscellany]"
name|NL
literal|"### Set global-ignores to a set of whitespace-delimited globs"
name|NL
literal|"### which Subversion will ignore in its 'status' output, and"
name|NL
literal|"### while importing or adding files and directories."
name|NL
literal|"### '*' matches leading dots, e.g. '*.rej' matches '.foo.rej'."
name|NL
literal|"# global-ignores = "
name|SVN_CONFIG__DEFAULT_GLOBAL_IGNORES_LINE_1
name|NL
literal|"#   "
name|SVN_CONFIG__DEFAULT_GLOBAL_IGNORES_LINE_2
name|NL
literal|"### Set log-encoding to the default encoding for log messages"
name|NL
literal|"# log-encoding = latin1"
name|NL
literal|"### Set use-commit-times to make checkout/update/switch/revert"
name|NL
literal|"### put last-committed timestamps on every file touched."
name|NL
literal|"# use-commit-times = yes"
name|NL
literal|"### Set no-unlock to prevent 'svn commit' from automatically"
name|NL
literal|"### releasing locks on files."
name|NL
literal|"# no-unlock = yes"
name|NL
literal|"### Set mime-types-file to a MIME type registry file, used to"
name|NL
literal|"### provide hints to Subversion's MIME type auto-detection"
name|NL
literal|"### algorithm."
name|NL
literal|"# mime-types-file = /path/to/mime.types"
name|NL
literal|"### Set preserved-conflict-file-exts to a whitespace-delimited"
name|NL
literal|"### list of patterns matching file extensions which should be"
name|NL
literal|"### preserved in generated conflict file names.  By default,"
name|NL
literal|"### conflict files use custom extensions."
name|NL
literal|"# preserved-conflict-file-exts = doc ppt xls od?"
name|NL
literal|"### Set enable-auto-props to 'yes' to enable automatic properties"
name|NL
literal|"### for 'svn add' and 'svn import', it defaults to 'no'."
name|NL
literal|"### Automatic properties are defined in the section 'auto-props'."
name|NL
literal|"# enable-auto-props = yes"
name|NL
literal|"### Set interactive-conflicts to 'no' to disable interactive"
name|NL
literal|"### conflict resolution prompting.  It defaults to 'yes'."
name|NL
literal|"# interactive-conflicts = no"
name|NL
literal|"### Set memory-cache-size to define the size of the memory cache"
name|NL
literal|"### used by the client when accessing a FSFS repository via"
name|NL
literal|"### ra_local (the file:// scheme). The value represents the number"
name|NL
literal|"### of MB used by the cache."
name|NL
literal|"# memory-cache-size = 16"
name|NL
literal|""
name|NL
literal|"### Section for configuring automatic properties."
name|NL
literal|"[auto-props]"
name|NL
literal|"### The format of the entries is:"
name|NL
literal|"###   file-name-pattern = propname[=value][;propname[=value]...]"
name|NL
literal|"### The file-name-pattern can contain wildcards (such as '*' and"
name|NL
literal|"### '?').  All entries which match (case-insensitively) will be"
name|NL
literal|"### applied to the file.  Note that auto-props functionality"
name|NL
literal|"### must be enabled, which is typically done by setting the"
name|NL
literal|"### 'enable-auto-props' option."
name|NL
literal|"# *.c = svn:eol-style=native"
name|NL
literal|"# *.cpp = svn:eol-style=native"
name|NL
literal|"# *.h = svn:keywords=Author Date Id Rev URL;svn:eol-style=native"
name|NL
literal|"# *.dsp = svn:eol-style=CRLF"
name|NL
literal|"# *.dsw = svn:eol-style=CRLF"
name|NL
literal|"# *.sh = svn:eol-style=native;svn:executable"
name|NL
literal|"# *.txt = svn:eol-style=native;svn:keywords=Author Date Id Rev URL;"
name|NL
literal|"# *.png = svn:mime-type=image/png"
name|NL
literal|"# *.jpg = svn:mime-type=image/jpeg"
name|NL
literal|"# Makefile = svn:eol-style=native"
name|NL
literal|""
name|NL
literal|"### Section for configuring working copies."
name|NL
literal|"[working-copy]"
name|NL
literal|"### Set to a list of the names of specific clients that should use"
name|NL
literal|"### exclusive SQLite locking of working copies.  This increases the"
name|NL
literal|"### performance of the client but prevents concurrent access by"
name|NL
literal|"### other clients.  Third-party clients may also support this"
name|NL
literal|"### option."
name|NL
literal|"### Possible values:"
name|NL
literal|"###   svn                (the command line client)"
name|NL
literal|"# exclusive-locking-clients ="
name|NL
literal|"### Set to true to enable exclusive SQLite locking of working"
name|NL
literal|"### copies by all clients using the 1.8 APIs.  Enabling this may"
name|NL
literal|"### cause some clients to fail to work properly. This does not have"
name|NL
literal|"### to be set for exclusive-locking-clients to work."
name|NL
literal|"# exclusive-locking = false"
name|NL
decl_stmt|;
name|err
operator|=
name|svn_io_file_open
argument_list|(
operator|&
name|f
argument_list|,
name|path
argument_list|,
operator|(
name|APR_WRITE
operator||
name|APR_CREATE
operator||
name|APR_EXCL
operator|)
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|contents
argument_list|,
name|strlen
argument_list|(
name|contents
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_close
argument_list|(
name|f
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_config_get_user_config_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|config_dir
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
operator|*
name|path
operator|=
name|NULL
expr_stmt|;
comment|/* Note that even if fname is null, svn_dirent_join_many will DTRT. */
if|if
condition|(
name|config_dir
condition|)
block|{
operator|*
name|path
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|config_dir
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
ifdef|#
directive|ifdef
name|WIN32
block|{
specifier|const
name|char
modifier|*
name|folder
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_config__win_config_path
argument_list|(
operator|&
name|folder
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|path
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|folder
argument_list|,
name|SVN_CONFIG__SUBDIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
block|{
name|char
name|folder
index|[
name|B_PATH_NAME_LENGTH
index|]
decl_stmt|;
name|status_t
name|error
init|=
name|find_directory
argument_list|(
name|B_USER_SETTINGS_DIRECTORY
argument_list|,
operator|-
literal|1
argument_list|,
name|false
argument_list|,
name|folder
argument_list|,
sizeof|sizeof
argument_list|(
name|folder
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
return|return
name|SVN_NO_ERROR
return|;
operator|*
name|path
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|folder
argument_list|,
name|SVN_CONFIG__USR_DIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* ! WIN32&& !__HAIKU__ */
block|{
specifier|const
name|char
modifier|*
name|homedir
init|=
name|svn_user_get_homedir
argument_list|(
name|pool
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|homedir
condition|)
return|return
name|SVN_NO_ERROR
return|;
operator|*
name|path
operator|=
name|svn_dirent_join_many
argument_list|(
name|pool
argument_list|,
name|svn_dirent_canonicalize
argument_list|(
name|homedir
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_CONFIG__USR_DIRECTORY
argument_list|,
name|fname
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* WIN32 */
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

end_unit

