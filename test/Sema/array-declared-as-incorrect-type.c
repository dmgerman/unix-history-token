begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a1
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a2
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|float
name|a2
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'a2'}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a3
index|[]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a3
index|[
literal|1
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a4
index|[]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|a4
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'a4'}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a5
index|[
literal|1
index|]
index|[
literal|2
index|]
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|a5
index|[
literal|3
index|]
index|[
literal|2
index|]
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'a5'}}
end_comment

end_unit

