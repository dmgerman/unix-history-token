begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|__experimental_modules_import
name|redecl_merge_top
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
name|class
name|A
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|interface
name|B
operator|+
operator|(
name|B
operator|*
operator|)
name|create_a_B
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|class
name|A
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|protocol
name|P1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|protocol
name|P2
operator|-
operator|(
name|void
operator|)
name|protoMethod2
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_struct_decl
struct_decl|struct
name|S1
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|S2
block|{
name|int
name|field
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|S1
modifier|*
name|produce_S1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|consume_S2
parameter_list|(
name|struct
name|S2
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Test declarations in different modules with no common initial
end_comment

begin_comment
comment|// declaration.
end_comment

begin_decl_stmt
unit|@
name|class
name|C
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|accept_a_C
parameter_list|(
name|C
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|@
name|class
name|C2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|accept_a_C2
parameter_list|(
name|C2
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|@
name|class
name|C3
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|accept_a_C3
parameter_list|(
name|C3
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|@
name|class
name|C3
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
name|Explicit
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
modifier|*
name|explicit_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|explicit_struct
struct_decl|;
end_struct_decl

begin_decl_stmt
unit|@
name|protocol
name|P3
decl_stmt|,
name|P4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|protocol
name|P3
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|S3
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|S3
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|S4
block|{
name|int
name|field
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|S3
modifier|*
name|produce_S3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|consume_S4
parameter_list|(
name|struct
name|S4
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|T1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|T2
typedef|;
end_typedef

begin_function_decl
name|int
name|func0
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|func1
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|func2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Spacing matters!
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|var2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|var3
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Vector
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Vector
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make sure this doesn't introduce an ambiguity-creating 'id' at the
end_comment

begin_comment
comment|// top level.
end_comment

begin_typedef
typedef|typedef
name|void
name|funcptr_with_id
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_typedef

end_unit

