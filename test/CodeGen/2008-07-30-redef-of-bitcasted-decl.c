begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s
end_comment

begin_comment
comment|//<rdar://problem/6108358>
end_comment

begin_comment
comment|/* For posterity, the issue here begins initial "char []" decl for  * s. This is a tentative definition and so a global was being  * emitted, however the mapping in GlobalDeclMap referred to a bitcast  * of this global.  *  * The problem was that later when the correct definition for s is  * emitted we were doing a RAUW on the old global which was destroying  * the bitcast in the GlobalDeclMap (since it cannot be replaced  * properly), leaving a dangling pointer.  *  * The purpose of bar is just to trigger a use of the old decl  * sometime after the dangling pointer has been introduced.  */
end_comment

begin_decl_stmt
name|char
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|bar
parameter_list|(
name|void
modifier|*
name|db
parameter_list|)
block|{
name|eek
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|char
name|s
index|[
literal|5
index|]
init|=
literal|"hi"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
name|bar
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

