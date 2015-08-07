begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|B
expr|@
name|end
expr|@
name|interface
name|C
operator|:
name|B
expr|@
name|end
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|NSGeneric
operator|<
name|T
operator|:
name|B
operator|*
operator|>
comment|// expected-note{{type parameter 'T' declared here}}
operator|-
operator|(
name|T
operator|)
name|tee
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|nullable
name|T
operator|)
name|maybeTee
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_typedef
typedef|typedef
name|NSGeneric
operator|<
name|C
operator|*
operator|>
operator|*
name|Generic_with_C
expr_stmt|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
end_pragma

begin_expr_stmt
unit|@
name|interface
name|NSGeneric
operator|<
name|T
operator|:
name|C
operator|*
operator|>
operator|(
name|Blah
operator|)
comment|// expected-error{{type bound 'C *' for type parameter 'T' conflicts with previous bound 'B *'}}
expr|@
name|end
end_expr_stmt

end_unit

