begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Used with the types.c test */
end_comment

begin_comment
comment|// TYPE_EXT_QUAL
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
name|int
name|ASInt
typedef|;
end_typedef

begin_comment
comment|// TYPE_COMPLEX
end_comment

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|Cfloat
typedef|;
end_typedef

begin_comment
comment|// TYPE_ATOMIC
end_comment

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|AtomicInt
typedef|;
end_typedef

begin_comment
comment|// TYPE_POINTER
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|int_ptr
typedef|;
end_typedef

begin_comment
comment|// TYPE_BLOCK_POINTER
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|^
name|Block
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// TYPE_CONSTANT_ARRAY
end_comment

begin_typedef
typedef|typedef
name|int
name|five_ints
index|[
literal|5
index|]
typedef|;
end_typedef

begin_comment
comment|// TYPE_INCOMPLETE_ARRAY
end_comment

begin_typedef
typedef|typedef
name|float
name|float_array
index|[]
typedef|;
end_typedef

begin_comment
comment|// TYPE_VARIABLE_ARRAY in stmts.[ch]
end_comment

begin_comment
comment|// TYPE_VECTOR
end_comment

begin_typedef
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_comment
comment|// TYPE_EXT_VECTOR
end_comment

begin_typedef
typedef|typedef
name|float
name|ext_float4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_comment
comment|// TYPE_FUNCTION_NO_PROTO
end_comment

begin_typedef
typedef|typedef
name|int
name|noproto
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// TYPE_FUNCTION_PROTO
end_comment

begin_typedef
typedef|typedef
name|float
name|proto
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// TYPE_TYPEDEF
end_comment

begin_typedef
typedef|typedef
name|int_ptr
modifier|*
name|int_ptr_ptr
typedef|;
end_typedef

begin_comment
comment|// TYPE_TYPEOF_EXPR
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
literal|17
argument_list|)
name|typeof_17
expr_stmt|;
end_typedef

begin_comment
comment|// TYPE_TYPEOF
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|int_ptr *
argument_list|)
name|int_ptr_ptr2
expr_stmt|;
end_typedef

begin_struct_decl
struct_decl|struct
name|S2
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|S2
block|{}
struct|;
end_struct

begin_enum_decl
enum_decl|enum
name|E
enum_decl|;
end_enum_decl

begin_enum
enum|enum
name|E
block|{
name|myenum
block|}
enum|;
end_enum

end_unit

