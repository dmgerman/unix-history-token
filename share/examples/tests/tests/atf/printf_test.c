begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  *  * Copyright 2013 Google Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * * Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in the  *   documentation and/or other materials provided with the distribution.  * * Neither the name of Google Inc. nor the names of its contributors  *   may be used to endorse or promote products derived from this software  *   without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_comment
comment|/*  * INTRODUCTION  *  * This sample test program implements various test cases for the printf(3)  * family of functions in order to demonstrate the usage of the ATF C API  * (see atf-c-api(3)).  *  * Note that this test program is called printf_test because it is intended  * to validate various functions of the printf(3) family.  For this reason,  * each test is prefixed with the name of the function under test followed  * by a description of the specific condition being validated.  You should  * use a similar naming scheme for your own tests.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * This is the simplest form of a test case definition: a test case  * without a header.  *  * In most cases, this is the definition you will want to use.  However,  * make absolutely sure that the test case name is descriptive enough.  * Multi-word test case names are encouraged.  Keep in mind that these  * are exposed to the reader in the test reports, and the goal is for  * the combination of the test program plus the name of the test case to  * give a pretty clear idea of what specific condition the test is  * validating.  */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|snprintf__two_formatters
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|snprintf__two_formatters
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|buffer
index|[
literal|128
index|]
decl_stmt|;
comment|/* This first require-style check invokes the function we are 	 * interested in testing.  This will cause the test to fail if 	 * the condition provided to ATF_REQUIRE is not met. */
name|ATF_REQUIRE
argument_list|(
name|snprintf
argument_list|(
name|buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|,
literal|"%s, %s!"
argument_list|,
literal|"Hello"
argument_list|,
literal|"tests"
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|/* This second check-style check compares that the result of the 	 * snprintf call we performed above is correct.  We use a check 	 * instead of a require. */
name|ATF_CHECK_STREQ
argument_list|(
literal|"Hello, tests!"
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This is a more complex form of a test case definition: a test case  * with a header and a body.  You should always favor the simpler  * definition above unless you have to override specific metadata  * variables.  *  * See atf-test-case(4) and kyua-atf-interface(1) for details on all  * available properties.  */
end_comment

begin_expr_stmt
name|ATF_TC
argument_list|(
name|snprintf__overflow
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|snprintf__overflow
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
comment|/* In this specific case, we define a textual description for 	 * the test case, which is later exported to the reports for 	 * documentation purposes. 	 * 	 * However, note again that you should favor highly descriptive 	 * test case names to textual descriptions.  */
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"This test case validates the proper "
literal|"truncation of the output string from snprintf when it does not "
literal|"fit the provided buffer."
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|snprintf__overflow
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|buffer
index|[
literal|10
index|]
decl_stmt|;
comment|/* This is a similar test to the above, but in this case we do the 	 * test ourselves and forego the ATF_* macros.  Note that we use the 	 * atf_tc_fail() function instead of exit(2) or similar because we 	 * want Kyua to have access to the failure message. 	 * 	 * In general, prefer using the ATF_* macros wherever possible.  Only 	 * resort to manual tests when the macros are unsuitable (and consider 	 * filing a feature request to get a new macro if you think your case 	 * is generic enough). */
if|if
condition|(
name|snprintf
argument_list|(
name|buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|,
literal|"0123456789abcdef"
argument_list|)
operator|!=
literal|16
condition|)
name|atf_tc_fail
argument_list|(
literal|"snprintf did not return the expected number "
literal|"of characters"
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|strcmp
argument_list|(
name|buffer
argument_list|,
literal|"012345678"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Another simple test case, but this time with side-effects.  This  * particular test case modifies the contents of the current directory  * and does not clean up after itself, which is perfectly fine.  */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|fprintf__simple_string
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fprintf__simple_string
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
name|contents
init|=
literal|"This is a message\n"
decl_stmt|;
name|FILE
modifier|*
name|output
init|=
name|fopen
argument_list|(
literal|"test.txt"
argument_list|,
literal|"w"
argument_list|)
decl_stmt|;
name|ATF_REQUIRE
argument_list|(
name|fprintf
argument_list|(
name|output
argument_list|,
literal|"%s"
argument_list|,
name|contents
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|output
argument_list|)
expr_stmt|;
comment|/* The ATF C library provides more than just macros to verify the 	 * outcome of expressions.  It also includes various helper functions 	 * to work with files and processes.  Here is just a simple 	 * example. */
name|ATF_REQUIRE
argument_list|(
name|atf_utils_compare_file
argument_list|(
literal|"test.txt"
argument_list|,
name|contents
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Of special note here is that we are NOT deleting the 	 * temporary files we created in this test.  Kyua takes care of 	 * this cleanup automatically and tests can (and should) rely on 	 * this behavior. */
block|}
end_block

begin_comment
comment|/*  * Lastly, we tell ATF which test cases exist in this program.  This  * function should not do anything other than this registration.  */
end_comment

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|snprintf__two_formatters
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|snprintf__overflow
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fprintf__simple_string
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

