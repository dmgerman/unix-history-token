begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_define
define|#
directive|define
name|SA
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|int arr##n[(c) ? 1 : -1] = {}
end_define

begin_decl_stmt
specifier|const
name|int
name|AA
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f1
argument_list|(
expr|enum
block|{
name|AA
block|,
name|BB
block|}
name|E
argument_list|)
block|{
comment|// expected-warning {{will not be visible outside of this function}}
name|SA
argument_list|(
literal|1
argument_list|,
name|AA
operator|==
literal|0
argument_list|)
expr_stmt|;
name|SA
argument_list|(
literal|2
argument_list|,
name|BB
operator|==
literal|1
argument_list|)
expr_stmt|;
return|return
name|BB
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|f2
argument_list|(
expr|enum
block|{
name|AA
operator|=
literal|7
block|,
name|BB
block|}
name|E
argument_list|)
block|{
comment|// expected-warning {{will not be visible outside of this function}}
name|SA
argument_list|(
literal|1
argument_list|,
name|AA
operator|==
literal|7
argument_list|)
expr_stmt|;
name|SA
argument_list|(
literal|2
argument_list|,
name|BB
operator|==
literal|8
argument_list|)
expr_stmt|;
return|return
name|AA
return|;
block|}
end_decl_stmt

begin_struct
struct|struct
name|a
block|{ }
struct|;
end_struct

begin_decl_stmt
name|int
name|f3
argument_list|(
expr|struct
name|a
block|{ }
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{will not be visible outside of this function}}
end_comment

begin_struct
struct|struct
name|A
block|{
struct|struct
name|b
block|{
name|int
name|j
decl_stmt|;
block|}
name|t
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|f4
argument_list|(
expr|struct
name|A
block|{ struct
name|b
block|{
name|int
name|j
block|; }
name|t
block|; }
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{declaration of 'struct A' will not be visible outside of this function}} expected-warning {{redefinition of 'b' will not be visible outside of this function}}
end_comment

begin_struct
struct|struct
name|aA
block|{
struct|struct
name|ab
block|{
comment|// expected-note {{previous definition is here}} expected-note {{previous definition is here}}
name|int
name|j
decl_stmt|;
block|}
name|b
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|f5
argument_list|(
expr|struct
name|aA
block|{ struct
name|ab
block|{
name|int
name|j
block|; }
name|b
block|; struct
name|ab
block|{
name|char
name|glorx
block|; }
name|glorx
block|; }
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{declaration of 'struct aA' will not be visible}} expected-warning {{redefinition of 'ab' will not be visible}} expected-warning {{redefinition of 'ab' will not be visible}}
end_comment

begin_decl_stmt
name|void
name|f6
argument_list|(
expr|struct
name|z
block|{
name|int
name|b
block|;}
name|c
argument_list|)
block|{
comment|// expected-warning {{declaration of 'struct z' will not be visible outside of this function}}
name|struct
name|z
name|d
decl_stmt|;
name|d
operator|.
name|b
operator|=
literal|4
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|pr19018_1
argument_list|(
expr|enum
name|e19018
block|{
name|qq
block|}
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{declaration of 'enum e19018' will not be visible outside of this function}}
end_comment

begin_decl_stmt
name|enum
name|e19018
name|qq
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{tentative definition has type 'enum e19018' that is never completed}} \
end_comment

begin_comment
comment|//expected-note{{forward declaration of 'enum e19018'}}
end_comment

begin_comment
comment|// Only warn once, even if we create two declarations.
end_comment

begin_decl_stmt
name|void
name|f
argument_list|(
expr|struct
name|q
operator|*
argument_list|,
expr|struct
name|__attribute__
argument_list|(
argument|(aligned(
literal|4
argument|))
argument_list|)
name|q
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{will not be visible outside}}
end_comment

begin_comment
comment|// This enum inside the function pointer parameter shouldn't leak into the
end_comment

begin_comment
comment|// function.
end_comment

begin_enum
enum|enum
block|{
name|BB
init|=
literal|0
block|}
enum|;
end_enum

begin_decl_stmt
name|void
name|enum_in_fun_in_fun
argument_list|(
name|void
argument_list|(
operator|*
name|fp
argument_list|)
argument_list|(
expr|enum
block|{
name|AA
block|,
name|BB
block|}
name|e
argument_list|)
argument_list|)
block|{
comment|// expected-warning {{will not be visible}}
name|SA
argument_list|(
literal|1
argument_list|,
name|AA
operator|==
literal|5
argument_list|)
expr_stmt|;
name|SA
argument_list|(
literal|2
argument_list|,
name|BB
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|f7
parameter_list|()
block|{
specifier|extern
name|void
name|ext
argument_list|(
expr|struct
name|S
block|{ enum
name|E7
block|{
name|a
block|,
name|b
block|}
name|o
block|; }
name|p
argument_list|)
decl_stmt|;
comment|// expected-warning 2 {{will not be visible}}
name|ext
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier}}
block|}
end_function

begin_decl_stmt
name|int
name|f8
argument_list|(
expr|struct
name|S
block|{ enum
name|E8
block|{
name|a
block|,
name|b
block|}
name|o
block|; }
name|p
argument_list|)
block|{
comment|// expected-warning 2 {{will not be visible}}
name|struct
name|S
name|o
decl_stmt|;
name|enum
name|E8
name|x
decl_stmt|;
return|return
name|a
operator|+
name|b
return|;
block|}
end_decl_stmt

begin_comment
comment|// expected-note@+1 {{forward declaration}}
end_comment

begin_decl_stmt
name|struct
name|S
name|o
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'struct S' that is never completed}}
end_comment

begin_comment
comment|// expected-note@+1 {{forward declaration}}
end_comment

begin_decl_stmt
name|enum
name|E8
name|x
init|=
name|a
operator|+
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error 2 {{undeclared identifier}} expected-error {{incomplete type 'enum E8'}}
end_comment

begin_decl_stmt
name|int
name|f9
argument_list|(
expr|struct
block|{ enum
name|e
block|{
name|a
operator|=
literal|1
block|}
name|b
block|; }
name|c
argument_list|)
block|{
comment|// expected-warning {{will not be visible}}
return|return
name|a
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|f10
argument_list|(
expr|struct
name|S
block|{
comment|// expected-warning {{will not be visible}}
block|enum
name|E10
block|{
name|a
block|,
name|b
block|,
name|c
block|}
name|f
block|;
comment|// expected-warning {{will not be visible}}
block|}
name|e
argument_list|)
block|{
return|return
name|a
operator|==
name|b
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|f11
argument_list|(
expr|struct
name|S
block|{
comment|// expected-warning {{will not be visible}}
block|enum
name|E11
block|{
comment|// expected-warning {{will not be visible}}
name|a
block|,
name|b
block|,
name|c
block|}
comment|// expected-warning {{expected ';' at end of declaration list}}
block|}
comment|// expected-error {{expected member name or ';'}}
name|e
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f12
parameter_list|()
block|{
specifier|extern
name|int
name|ext12
argument_list|(
expr|struct
name|S12
block|{ }
name|e
comment|// expected-warning {{will not be visible}}
argument_list|)
decl_stmt|;
name|struct
name|S12
name|o
decl_stmt|;
comment|// expected-error {{incomplete type}} expected-note {{forward declaration}}
block|}
end_function

end_unit

