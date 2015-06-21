begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{missing a nullability type specifier}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_decl_stmt
specifier|extern
name|void
modifier|*
modifier|*
name|blah
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning 2{{missing a nullability type specifier}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
end_pragma

end_unit

