begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|protocol
name|foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|itf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Expressions
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@
literal|"foo"
literal|"bar"
argument_list|)
name|objc_string
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@encode(int)
argument_list|)
name|objc_encode
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@protocol(foo)
argument_list|)
name|objc_protocol
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@selector(noArgs)
argument_list|)
name|objc_selector_noArgs
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@selector(oneArg:)
argument_list|)
name|objc_selector_oneArg
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|@selector(foo:bar:)
argument_list|)
name|objc_selector_twoArg
expr_stmt|;
end_typedef

begin_comment
comment|// Types.
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|id<foo>
argument_list|)
name|objc_id_protocol_ty
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|itf*
argument_list|)
name|objc_interface_ty
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|itf<foo>*
argument_list|)
name|objc_qual_interface_ty
expr_stmt|;
end_typedef

begin_expr_stmt
unit|@
name|interface
name|PP
expr|@
name|property
argument_list|(
argument|assign
argument_list|)
name|id
name|prop
expr_stmt|;
end_expr_stmt

begin_function
unit|@
name|end
specifier|static
specifier|inline
name|id
name|getPseudoObject
parameter_list|(
name|PP
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
operator|.
name|prop
return|;
block|}
end_function

end_unit

