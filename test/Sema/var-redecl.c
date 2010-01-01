begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|outer1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outer2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|outer4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|outer4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|outer5
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|outer6
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_function_decl
name|int
name|outer7
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|outer_test
parameter_list|()
block|{
specifier|extern
name|float
name|outer1
decl_stmt|;
comment|// expected-error{{redefinition of 'outer1' with a different type}}
specifier|extern
name|float
name|outer2
decl_stmt|;
comment|// expected-error{{redefinition of 'outer2' with a different type}}
specifier|extern
name|float
name|outer3
decl_stmt|;
comment|// expected-note{{previous definition is here}}
name|double
name|outer4
decl_stmt|;
specifier|extern
name|int
name|outer5
decl_stmt|;
comment|// expected-note{{previous definition is here}}
specifier|extern
name|int
name|outer6
decl_stmt|;
comment|// expected-error{{redefinition of 'outer6' as different kind of symbol}}
name|int
name|outer7
decl_stmt|;
specifier|extern
name|int
name|outer8
decl_stmt|;
comment|// expected-note{{previous definition is here}}
specifier|extern
name|int
name|outer9
decl_stmt|;
block|{
specifier|extern
name|int
name|outer9
decl_stmt|;
comment|// expected-note{{previous definition is here}}
block|}
block|}
end_function

begin_decl_stmt
name|int
name|outer3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'outer3' with a different type}}
end_comment

begin_decl_stmt
name|float
name|outer4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'outer4' with a different type}}
end_comment

begin_decl_stmt
name|float
name|outer5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'outer5' with a different type}}
end_comment

begin_function_decl
name|int
name|outer8
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{redefinition of 'outer8' as different kind of symbol}}
end_comment

begin_decl_stmt
name|float
name|outer9
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'outer9' with a different type}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outer13
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_function
name|void
name|outer_shadowing_test
parameter_list|()
block|{
specifier|extern
name|int
name|outer10
decl_stmt|;
specifier|extern
name|int
name|outer11
decl_stmt|;
comment|// expected-note{{previous definition is here}}
specifier|extern
name|int
name|outer12
decl_stmt|;
comment|// expected-note{{previous definition is here}}
block|{
name|float
name|outer10
decl_stmt|;
name|float
name|outer11
decl_stmt|;
name|float
name|outer12
decl_stmt|;
block|{
specifier|extern
name|int
name|outer10
decl_stmt|;
comment|// okay
specifier|extern
name|float
name|outer11
decl_stmt|;
comment|// expected-error{{redefinition of 'outer11' with a different type}}
specifier|static
name|double
name|outer12
decl_stmt|;
block|{
specifier|extern
name|float
name|outer12
decl_stmt|;
comment|// expected-error{{redefinition of 'outer12' with a different type}}
specifier|extern
name|float
name|outer13
decl_stmt|;
comment|// expected-error{{redefinition of 'outer13' with a different type}}
block|}
block|}
block|}
block|}
end_function

begin_function
name|void
name|g18
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|g19
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|int
modifier|*
name|p
init|=
operator|&
name|g19
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{use of undeclared identifier 'g19'}} \
end_comment

begin_comment
comment|// expected-warning{{incompatible pointer types}}
end_comment

begin_comment
comment|// PR3645
end_comment

begin_decl_stmt
specifier|static
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

end_unit

