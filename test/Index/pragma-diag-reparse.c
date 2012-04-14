begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wtautological-compare"
end_pragma

begin_include
include|#
directive|include
file|"pragma_disable_warning.h"
end_include

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
init|=
literal|0
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|b
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|b
operator|==
name|b
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_FAILONERROR=1 c-index-test -test-load-source-reparse 5 local \
end_comment

begin_comment
comment|// RUN: -I%S/Inputs \
end_comment

begin_comment
comment|// RUN:   %s -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// CHECK: pragma-diag-reparse.c:8:7: VarDecl=x:8:7 (Definition) Extent=[8:3 - 8:10]
end_comment

end_unit

