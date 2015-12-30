begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|RealNS
block|{
name|int
name|UsingDecl
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|NS
init|=
name|RealNS
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|Typedef
typedef|;
end_typedef

begin_decl_stmt
name|using
name|AliasDecl
init|=
name|int
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|RealNS
operator|::
name|UsingDecl
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|Struct
block|{}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|Variable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|AnotherNS
block|{}
end_decl_stmt

begin_enum
enum|enum
name|X
block|{
name|Enumerator
block|}
enum|;
end_enum

begin_function_decl
name|void
name|Overloads
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Overloads
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

