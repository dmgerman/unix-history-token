begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 McAfee, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mac.h>
end_include

begin_include
include|#
directive|include
file|<security/mac_bsdextended/mac_bsdextended.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<ugidfw.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Starting point for a regression test for mac_bsdextended(4) and the  * supporting libugidfw(3).  */
end_comment

begin_function
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"test_ugidfw\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This section of the regression test passes some test cases through the  * rule<->string routines to confirm they work approximately as desired.  */
end_comment

begin_comment
comment|/*  * List of users and groups we must check exists before we can begin, since  * they are used in the string test rules.  We use users and groups that will  * always exist in a default install used for regression testing.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|test_users
index|[]
init|=
block|{
literal|"root"
block|,
literal|"daemon"
block|,
literal|"operator"
block|,
literal|"bin"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|test_users_len
init|=
sizeof|sizeof
argument_list|(
name|test_users
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|test_groups
index|[]
init|=
block|{
literal|"wheel"
block|,
literal|"daemon"
block|,
literal|"operator"
block|,
literal|"bin"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|test_groups_len
init|=
sizeof|sizeof
argument_list|(
name|test_groups
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * List of test strings that must go in (and come out) of libugidfw intact.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|test_strings
index|[]
init|=
block|{
comment|/* Variations on subject and object uids. */
literal|"subject uid root object uid root mode n"
block|,
literal|"subject uid root object uid daemon mode n"
block|,
literal|"subject uid daemon object uid root mode n"
block|,
literal|"subject uid daemon object uid daemon mode n"
block|,
comment|/* Variations on mode. */
literal|"subject uid root object uid root mode a"
block|,
literal|"subject uid root object uid root mode r"
block|,
literal|"subject uid root object uid root mode s"
block|,
literal|"subject uid root object uid root mode w"
block|,
literal|"subject uid root object uid root mode x"
block|,
literal|"subject uid root object uid root mode arswx"
block|,
comment|/* Variations on subject and object gids. */
literal|"subject gid wheel object gid wheel mode n"
block|,
literal|"subject gid wheel object gid daemon mode n"
block|,
literal|"subject gid daemon object gid wheel mode n"
block|,
literal|"subject gid daemon object gid daemon mode n"
block|,
comment|/* Subject uids and subject gids. */
literal|"subject uid bin gid daemon object uid operator gid wheel mode n"
block|,
comment|/* Not */
literal|"subject not uid operator object uid bin mode n"
block|,
literal|"subject uid bin object not uid operator mode n"
block|,
literal|"subject not uid daemon object not uid operator mode n"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|test_strings_len
init|=
sizeof|sizeof
argument_list|(
name|test_strings
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|test_libugidfw_strings
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|mac_bsdextended_rule
name|rule
decl_stmt|;
name|char
name|errorstr
index|[
literal|128
index|]
decl_stmt|;
name|char
name|rulestr
index|[
literal|128
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|error
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|test_users_len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|getpwnam
argument_list|(
name|test_users
index|[
name|i
index|]
argument_list|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"test_libugidfw_strings: getpwnam: %s"
argument_list|,
name|test_users
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|test_groups_len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|getgrnam
argument_list|(
name|test_groups
index|[
name|i
index|]
argument_list|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"test_libugidfw_strings: getgrnam: %s"
argument_list|,
name|test_groups
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|test_strings_len
condition|;
name|i
operator|++
control|)
block|{
name|error
operator|=
name|bsde_parse_rule_string
argument_list|(
name|test_strings
index|[
name|i
index|]
argument_list|,
operator|&
name|rule
argument_list|,
literal|128
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
operator|-
literal|1
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"bsde_parse_rule_string: '%s' (%d): %s"
argument_list|,
name|test_strings
index|[
name|i
index|]
argument_list|,
name|i
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
name|error
operator|=
name|bsde_rule_to_string
argument_list|(
operator|&
name|rule
argument_list|,
name|rulestr
argument_list|,
literal|128
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|<
literal|0
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"bsde_rule_to_string: rule for '%s' "
literal|"returned %d"
argument_list|,
name|test_strings
index|[
name|i
index|]
argument_list|,
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|test_strings
index|[
name|i
index|]
argument_list|,
name|rulestr
argument_list|)
operator|!=
literal|0
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"test_libugidfw: '%s' in, '%s' out"
argument_list|,
name|test_strings
index|[
name|i
index|]
argument_list|,
name|rulestr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|char
name|errorstr
index|[
literal|128
index|]
decl_stmt|;
name|int
name|count
decl_stmt|,
name|slots
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
comment|/* Print an error if a non-root user attemps to run the tests. */
if|if
condition|(
name|getuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error!  Only root may run this utility\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EXIT_FAILURE
operator|)
return|;
block|}
comment|/* 	 * We can test some parts of the library without the MAC Framework 	 * and policy loaded, so run those tests before calling 	 * mac_is_present(). 	 */
name|test_libugidfw_strings
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|mac_is_present
argument_list|(
literal|"bsdextended"
argument_list|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"mac_is_present"
argument_list|)
expr_stmt|;
case|case
literal|1
case|:
break|break;
case|case
literal|0
case|:
default|default:
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"mac_bsdextended not loaded"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Some simple up-front checks to see if we're able to query the 	 * policy for basic state.  We want the rule count to be 0 before 	 * starting, but "slots" is a property of prior runs and so we ignore 	 * the return value. 	 */
name|count
operator|=
name|bsde_get_rule_count
argument_list|(
literal|128
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|==
operator|-
literal|1
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"bsde_get_rule_count: %s"
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|!=
literal|0
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"bsde_get_rule_count: %d rules"
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|slots
operator|=
name|bsde_get_rule_slots
argument_list|(
literal|128
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
if|if
condition|(
name|slots
operator|==
operator|-
literal|1
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"bsde_get_rule_slots: %s"
argument_list|,
name|errorstr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

