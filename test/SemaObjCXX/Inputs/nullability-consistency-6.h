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

begin_comment
comment|// expected-note@-1{{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2{{insert '_Nonnull' if the pointer should never be null}}
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

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|ClassWithWeakProperties
expr|@
name|property
argument_list|(
argument|readonly
argument_list|,
argument|weak
argument_list|)
name|ClassWithWeakProperties
operator|*
name|prop1
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|readonly
argument_list|,
argument|weak
argument_list|,
argument|null_unspecified
argument_list|)
end_macro

begin_decl_stmt
name|ClassWithWeakProperties
modifier|*
name|prop2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|ClassWithWeakProperties
argument_list|()
expr|@
name|property
argument_list|(
argument|readonly
argument_list|,
argument|weak
argument_list|)
name|ClassWithWeakProperties
operator|*
name|prop3
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
end_pragma

end_unit

