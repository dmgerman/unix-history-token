begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$OpenBSD: tests.c,v 1.1 2014/04/30 05:32:00 djm Exp $ */
end_comment

begin_comment
comment|/*  * Regress test for sshbuf.h buffer API  *  * Placed in the public domain  */
end_comment

begin_include
include|#
directive|include
file|"../test_helper/test_helper.h"
end_include

begin_function_decl
name|void
name|sshbuf_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_getput_basic_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_getput_crypto_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_misc_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_fuzz_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_getput_fuzz_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sshbuf_fixed
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
name|sshbuf_tests
argument_list|()
expr_stmt|;
name|sshbuf_getput_basic_tests
argument_list|()
expr_stmt|;
name|sshbuf_getput_crypto_tests
argument_list|()
expr_stmt|;
name|sshbuf_misc_tests
argument_list|()
expr_stmt|;
name|sshbuf_fuzz_tests
argument_list|()
expr_stmt|;
name|sshbuf_getput_fuzz_tests
argument_list|()
expr_stmt|;
name|sshbuf_fixed
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

