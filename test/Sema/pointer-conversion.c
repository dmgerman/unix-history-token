begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|char
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
modifier|*
name|c2
init|=
operator|&
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{initializing, 'char const **' and 'char **' have different qualifiers in nested pointer types}}
end_comment

begin_typedef
typedef|typedef
name|char
name|dchar
typedef|;
end_typedef

begin_decl_stmt
name|dchar
modifier|*
modifier|*
modifier|*
name|c3
init|=
operator|&
name|c2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{initializing, 'dchar ***' and 'char const ***' have different qualifiers in nested pointer types}}
end_comment

begin_decl_stmt
specifier|volatile
name|char
modifier|*
name|c4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|c5
init|=
operator|&
name|c4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{initializing, 'char **' and 'char volatile **' have different qualifiers in nested pointer types}}
end_comment

end_unit

