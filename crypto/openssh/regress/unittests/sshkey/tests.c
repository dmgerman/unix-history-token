begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$OpenBSD: tests.c,v 1.1 2014/06/24 01:14:18 djm Exp $ */
end_comment

begin_comment
comment|/*  * Regress test for sshbuf.h buffer API  *  * Placed in the public domain  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|"../test_helper/test_helper.h"
end_include

begin_function_decl
name|void
name|sshkey_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshkey_file_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshkey_fuzz_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|tests
parameter_list|(
name|void
parameter_list|)
block|{
name|OpenSSL_add_all_algorithms
argument_list|()
expr_stmt|;
name|ERR_load_CRYPTO_strings
argument_list|()
expr_stmt|;
name|sshkey_tests
argument_list|()
expr_stmt|;
name|sshkey_file_tests
argument_list|()
expr_stmt|;
name|sshkey_fuzz_tests
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

