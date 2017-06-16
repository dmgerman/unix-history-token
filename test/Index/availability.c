begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines below; this test is line- and column-sensitive.
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.5
parameter_list|,
name|obsoleted
init|=
literal|10.7
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|3.2
parameter_list|,
name|deprecated
init|=
literal|4.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_enum
enum|enum
block|{
name|old_enum
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
block|{
name|old_enum_plat
block|}
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|10.4
argument_list|,
name|deprecated
operator|=
literal|10.5
argument_list|,
name|obsoleted
operator|=
literal|10.7
argument_list|)
operator|)
argument_list|)
enum|;
end_enum

begin_function_decl
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|)
end_function_decl

begin_macro
unit|))
name|__attribute__
argument_list|(
argument|(availability(macosx,obsoleted=
literal|10.6
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(availability(ios,introduced=
literal|3.2
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|deprecated
operator|=
literal|10.5
argument_list|,
name|message
operator|=
literal|"use foobar"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|bar2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.5
parameter_list|,
name|obsoleted
init|=
literal|10.7
parameter_list|)
end_function_decl

begin_macro
unit|))
name|__attribute__
argument_list|(
argument|(availability(ios,introduced=
literal|3.2
argument|,deprecated=
literal|10.0
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macosx,introduced=
literal|10.4
argument|,deprecated=
literal|10.5
argument|,obsoleted=
literal|10.7
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|ios
argument_list|,
name|introduced
operator|=
literal|3.2
argument_list|,
name|deprecated
operator|=
literal|10.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: FunctionDecl=foo:3:6{{.*}}(ios, introduced=3.2, deprecated=4.1) (macos, introduced=10.4, deprecated=10.5, obsoleted=10.7)
end_comment

begin_comment
comment|// CHECK: EnumConstantDecl=old_enum:6:3 (Definition) (deprecated)
end_comment

begin_comment
comment|// CHECK: EnumConstantDecl=old_enum_plat:10:3 {{.*}} (macos, introduced=10.4, deprecated=10.5, obsoleted=10.7)
end_comment

begin_comment
comment|// CHECK: FunctionDecl=bar:13:6{{.*}}(ios, introduced=3.2) (macos, introduced=10.4, deprecated=10.5, obsoleted=10.6, message="use foobar")
end_comment

begin_comment
comment|// CHECK: FunctionDecl=bar2:15:6{{.*}}(ios, introduced=3.2, deprecated=10.0) (macos, introduced=10.4, deprecated=10.5, obsoleted=10.7)
end_comment

end_unit

