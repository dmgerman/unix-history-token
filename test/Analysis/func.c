begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -verify %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|p
operator|=
name|f
expr_stmt|;
name|p
operator|=
operator|&
name|f
expr_stmt|;
name|p
argument_list|()
expr_stmt|;
call|(
modifier|*
name|p
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f2
parameter_list|()
block|{
name|g
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

