begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -Wmissing-prototypes -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -Wmissing-prototypes -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{no previous prototype for function 'f'}}
end_comment

begin_function
specifier|static
name|int
name|g
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|h
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{no previous prototype for function 'h'}}
end_comment

begin_function_decl
specifier|static
name|int
name|g2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|g2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function_decl
name|void
name|test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|h3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|h4
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|h4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|h2
argument_list|(
name|int
name|x
argument_list|)
decl_stmt|;
name|int
name|h3
argument_list|(
name|int
name|x
argument_list|)
decl_stmt|;
name|int
name|h4
parameter_list|()
function_decl|;
block|}
end_function

begin_function
name|int
name|h2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{no previous prototype for function 'h2'}}
end_comment

begin_function
name|int
name|h3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{no previous prototype for function 'h3'}}
end_comment

begin_function
name|int
name|h4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function_decl
name|int
name|f2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|f2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|f2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// rdar://6759522
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|void
name|not_a_prototype_test
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{this declaration is not a prototype; add 'void' to make it a prototype for a zero-parameter function}}
end_comment

begin_function
name|void
name|not_a_prototype_test
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning{{no previous prototype for function 'not_a_prototype_test'}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{40:27-40:27}:"void"
end_comment

end_unit

