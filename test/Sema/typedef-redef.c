begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
specifier|const
name|int
name|x
typedef|;
end_typedef

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
specifier|extern
name|x
name|a
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|x
typedef|;
end_typedef

begin_comment
comment|// expected-error {{typedef redefinition with different types}}
end_comment

begin_decl_stmt
specifier|extern
name|x
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/6097585>
end_comment

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2 {{previous definition is here}}
end_comment

begin_decl_stmt
name|float
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'y' with a different type}}
end_comment

begin_decl_stmt
name|double
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'y' with a different type}}
end_comment

end_unit

