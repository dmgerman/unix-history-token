begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$OpenBSD: tests.c,v 1.1 2015/02/16 22:18:34 djm Exp $ */
end_comment

begin_comment
comment|/*  * Regress test for known_hosts-related API.  *  * Placed in the public domain  */
end_comment

begin_function_decl
name|void
name|tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_iterate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* test_iterate.c */
end_comment

begin_function
name|void
name|tests
parameter_list|(
name|void
parameter_list|)
block|{
name|test_iterate
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

