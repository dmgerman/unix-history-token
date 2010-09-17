begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|TInt
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|test
parameter_list|()
block|{
name|int
modifier|*
name|pi
decl_stmt|;
name|int
name|typeof
argument_list|(
name|int
argument_list|)
name|aIntInt
decl_stmt|;
comment|// expected-error{{cannot combine with previous 'int' declaration specifier}}
name|short
name|typeof
argument_list|(
name|int
argument_list|)
name|aShortInt
decl_stmt|;
comment|// expected-error{{'short typeof' is invalid}}
name|int
name|int
name|ttt
decl_stmt|;
comment|// expected-error{{cannot combine with previous 'int' declaration specifier}}
name|typeof
argument_list|(
argument|TInt
argument_list|)
name|anInt
expr_stmt|;
name|short
name|TInt
name|eee
decl_stmt|;
comment|// expected-error{{expected ';' at end of declaration}}
name|void
name|ary
index|[
literal|7
index|]
name|fff
decl_stmt|;
comment|// expected-error{{array has incomplete element type 'void'}} expected-error{{expected ';' at end of declaration}}
name|typeof
argument_list|(
argument|void ary[
literal|7
argument|]
argument_list|)
name|anIntError
expr_stmt|;
comment|// expected-error{{expected ')'}} expected-note {{to match this '('}}  expected-error {{variable has incomplete type 'typeof(void)' (aka 'void')}}
name|typeof
argument_list|(
argument|const int
argument_list|)
name|aci
expr_stmt|;
specifier|const
name|typeof
argument_list|(
argument|*pi
argument_list|)
name|aConstInt
expr_stmt|;
name|int
name|xx
decl_stmt|;
name|int
modifier|*
name|i
decl_stmt|;
block|}
end_function

begin_comment
comment|//<rdar://problem/8237491>
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
name|short
name|b
decl_stmt|;
name|__typeof__
argument_list|(
name|a
argument_list|)
argument_list|(
operator|*
name|f
argument_list|)
argument_list|(
name|__typeof__
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

