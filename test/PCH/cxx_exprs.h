begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx_exprs.cpp
end_comment

begin_comment
comment|// CXXStaticCastExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|static_cast<void *>(
literal|0
argument|)
argument_list|)
name|static_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXDynamicCastExpr
end_comment

begin_struct
struct|struct
name|Base
block|{
name|virtual
name|void
name|f
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Derived
range|:
name|Base
block|{ }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Base
modifier|*
name|base_ptr
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|dynamic_cast<Derived *>(base_ptr)
argument_list|)
name|dynamic_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXReinterpretCastExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|reinterpret_cast<void *>(
literal|0
argument|)
argument_list|)
name|reinterpret_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXConstCastExpr
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|const_char_ptr_value
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|const_cast<char *>(const_char_ptr_value)
argument_list|)
name|const_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXFunctionalCastExpr
end_comment

begin_decl_stmt
name|int
name|int_value
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|double(int_value)
argument_list|)
name|functional_cast_result
expr_stmt|;
end_typedef

end_unit

