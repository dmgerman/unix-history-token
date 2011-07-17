begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for Objective-C ARC-related PCH tests
end_comment

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_function_decl
name|CFTypeRef
name|CFCreateSomething
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CFStringRef
name|CFCreateString
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CFTypeRef
name|CFGetSomething
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CFStringRef
name|CFGetString
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
unit|@
name|interface
name|NSString
expr|@
name|end
name|id
name|CreateSomething
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|NSString
modifier|*
name|CreateNSString
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|array0
index|[
sizeof|sizeof
argument_list|(
operator|(
name|__bridge
name|id
operator|)
name|CFCreateSomething
argument_list|()
argument_list|)
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|array1
index|[
sizeof|sizeof
argument_list|(
operator|(
name|__bridge
name|CFTypeRef
operator|)
name|CreateSomething
argument_list|()
argument_list|)
index|]
typedef|;
end_typedef

end_unit

