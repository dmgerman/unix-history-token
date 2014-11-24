begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-output=html -analyzer-checker=core -o %t %s
end_comment

begin_comment
comment|// RUN: cat %t/*.html | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: staticanalyzer
end_comment

begin_comment
comment|// Because of the glob (*.html)
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// CHECK:<h3>Annotated Source Code</h3>
end_comment

begin_comment
comment|// Without tweaking expr, the expr would hit to the line below
end_comment

begin_comment
comment|// emitted to the output as comment.
end_comment

begin_comment
comment|// CHECK: {{[D]ereference of null pointer}}
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|p
init|=
operator|&
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|>
literal|10
condition|)
block|{
if|if
condition|(
name|x
operator|==
literal|22
condition|)
name|p
operator|=
literal|0
expr_stmt|;
block|}
operator|*
name|p
operator|=
literal|10
expr_stmt|;
block|}
end_function

end_unit

