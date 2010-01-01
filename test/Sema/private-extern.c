begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only %s
end_comment

begin_decl_stmt
specifier|static
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition}}
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{non-static declaration of 'g0' follows static declaration}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|g2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|g2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|g3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{static declaration of 'g3' follows non-static declaration}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|g4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{static declaration of 'g4' follows non-static declaration}}
end_comment

begin_decl_stmt
name|__private_extern__
name|int
name|g5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|g5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{static declaration of 'g5' follows non-static declaration}}
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
comment|// FIXME: Diagnose this?
name|int
name|g6
decl_stmt|;
specifier|extern
name|int
name|g6
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|()
block|{
comment|// FIXME: Diagnose this?
name|int
name|g7
decl_stmt|;
name|__private_extern__
name|int
name|g7
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
specifier|extern
name|int
name|g8
decl_stmt|;
comment|// expected-note{{previous definition}}
comment|// FIXME: Improve this diagnostic.
name|int
name|g8
decl_stmt|;
comment|// expected-error{{redefinition of 'g8'}}
block|}
end_function

begin_function
name|void
name|f3
parameter_list|()
block|{
name|__private_extern__
name|int
name|g9
decl_stmt|;
comment|// expected-note{{previous definition}}
comment|// FIXME: Improve this diagnostic.
name|int
name|g9
decl_stmt|;
comment|// expected-error{{redefinition of 'g9'}}
block|}
end_function

begin_function
name|void
name|f4
parameter_list|()
block|{
specifier|extern
name|int
name|g10
decl_stmt|;
specifier|extern
name|int
name|g10
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f5
parameter_list|()
block|{
name|__private_extern__
name|int
name|g11
decl_stmt|;
name|__private_extern__
name|int
name|g11
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f6
parameter_list|()
block|{
comment|// FIXME: Diagnose
specifier|extern
name|int
name|g12
decl_stmt|;
name|__private_extern__
name|int
name|g12
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f7
parameter_list|()
block|{
comment|// FIXME: Diagnose
name|__private_extern__
name|int
name|g13
decl_stmt|;
specifier|extern
name|int
name|g13
decl_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|s0
struct_decl|;
end_struct_decl

begin_function
name|void
name|f8
parameter_list|()
block|{
specifier|extern
name|struct
name|s0
name|g14
decl_stmt|;
name|__private_extern__
name|struct
name|s0
name|g14
decl_stmt|;
block|}
end_function

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f9
parameter_list|()
block|{
specifier|extern
name|int
name|g15
init|=
literal|0
decl_stmt|;
comment|// expected-error{{'extern' variable cannot have an initializer}}
comment|// FIXME: linkage specifier in warning.
name|__private_extern__
name|int
name|g16
init|=
literal|0
decl_stmt|;
comment|// expected-error{{'extern' variable cannot have an initializer}}
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|g17
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g17
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g18
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'extern' variable has an initializer}}
end_comment

begin_decl_stmt
name|__private_extern__
name|int
name|g19
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g19
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|g20
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

