begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Just exercise the analyzer on code that has at one point caused issues
end_comment

begin_comment
comment|// (i.e., no assertions or crashes).
end_comment

begin_function
specifier|static
name|void
name|f1
parameter_list|(
specifier|const
name|char
modifier|*
name|x
parameter_list|,
name|char
modifier|*
name|y
parameter_list|)
block|{
while|while
condition|(
operator|*
name|x
operator|!=
literal|0
condition|)
block|{
operator|*
name|y
operator|++
operator|=
operator|*
name|x
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// This following case checks that we properly handle typedefs when getting
end_comment

begin_comment
comment|// the RvalueType of an ElementRegion.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|F12_struct
block|{}
name|F12_typedef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|void_typedef
typedef|;
end_typedef

begin_function_decl
name|void_typedef
name|f2_helper
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|f2
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|)
block|{
name|F12_typedef
modifier|*
name|x
decl_stmt|;
name|x
operator|=
name|f2_helper
argument_list|()
expr_stmt|;
name|memcpy
argument_list|(
operator|(
operator|&
name|x
index|[
literal|1
index|]
operator|)
argument_list|,
operator|(
name|buf
operator|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function 'memcpy' with type 'void *(void *, const void *}} \
comment|// expected-note{{include the header<string.h> or explicitly provide a declaration for 'memcpy'}}
block|}
end_function

end_unit

