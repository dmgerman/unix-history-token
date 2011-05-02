begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 5 local %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wdeprecated-declarations"
name|int
name|x
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: pragma-diag-reparse.c:7:7: VarDecl=x:7:7 (Definition) Extent=[7:3 - 7:8]
end_comment

end_unit

