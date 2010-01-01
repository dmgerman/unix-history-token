begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only %s
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g1
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g2
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g3
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'weak_import' attribute cannot be specified on a definition}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
name|g4
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
name|g5
argument_list|(
name|void
argument_list|)
block|{  }
end_decl_stmt

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
name|s0
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'weak' attribute only applies to variable and function types}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(weak_import)
argument_list|)
name|s1
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'weak_import' attribute only applies to variable and function types}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{weak declaration of 'x' must be public}}
end_comment

end_unit

