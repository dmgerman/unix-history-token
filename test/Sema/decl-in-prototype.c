begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

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

end_unit

