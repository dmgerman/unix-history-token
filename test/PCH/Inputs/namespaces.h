begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test namespaces.cpp
end_comment

begin_decl_stmt
name|namespace
name|N1
block|{
typedef|typedef
name|int
name|t1
typedef|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|N1
block|{
typedef|typedef
name|int
name|t2
typedef|;
name|void
name|used_func
parameter_list|()
function_decl|;
struct|struct
name|used_cls
block|{ }
struct|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|N2
block|{
typedef|typedef
name|float
name|t1
typedef|;
name|namespace
name|Inner
block|{
typedef|typedef
name|int
name|t3
typedef|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_macro
name|namespace
end_macro

begin_block
block|{
name|void
name|anon
parameter_list|()
block|{ }
name|class
name|C
decl_stmt|;
block|}
end_block

begin_decl_stmt
name|namespace
name|N3
block|{
name|namespace
block|{
name|class
name|C
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|Alias1
init|=
name|N2
operator|::
name|Inner
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|namespace
name|N2
operator|::
name|Inner
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern
literal|"C"
block|{
name|void
name|ext
parameter_list|()
function_decl|;
block|}
end_extern

begin_decl_stmt
specifier|inline
name|namespace
name|N4
block|{
struct_decl|struct
name|MemberOfN4
struct_decl|;
block|}
end_decl_stmt

end_unit

