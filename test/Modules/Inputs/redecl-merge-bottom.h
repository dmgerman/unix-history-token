begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|import
name|redecl_merge_left
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|C4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|C4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|protocol
name|P4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|protocol
name|P4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|protocol
name|P4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|import
name|redecl_merge_right
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|B
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|class
name|A
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|protocol
name|P1
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|S1
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|S3
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|refers_to_C4
parameter_list|(
name|C4
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|@
name|interface
name|UnrelatedToDeclaredThenLoaded
operator|-
name|declaredThenLoadedMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|class
name|DeclaredThenLoaded
expr_stmt|;
end_expr_stmt

end_unit

