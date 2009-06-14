begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -checker-simple -analyzer-store=basic -analyzer-constraints=basic -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=basic -analyzer-constraints=basic -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=basic -analyzer-constraints=range -verify %s
end_comment

begin_comment
comment|// RegionStore now has an infinite recursion with this test case.
end_comment

begin_comment
comment|// NOWORK: clang-cc -analyze -checker-cfref -analyzer-store=region -analyzer-constraints=basic -verify %s&&
end_comment

begin_comment
comment|// NOWORK: clang-cc -analyze -checker-cfref -analyzer-store=region -analyzer-constraints=range -verify %s
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|data
decl_stmt|;
name|int
name|data_array
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|data
decl_stmt|;
block|}
name|STYPE
typedef|;
end_typedef

begin_function_decl
name|void
name|g
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g1
parameter_list|(
name|struct
name|s
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Array to pointer conversion. Array in the struct field.
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
name|int
argument_list|(
operator|*
name|p
argument_list|)
index|[
literal|10
index|]
expr_stmt|;
name|p
operator|=
operator|&
name|a
expr_stmt|;
operator|(
operator|*
name|p
operator|)
index|[
literal|3
index|]
operator|=
literal|1
expr_stmt|;
name|struct
name|s
name|d
decl_stmt|;
name|struct
name|s
modifier|*
name|q
decl_stmt|;
name|q
operator|=
operator|&
name|d
expr_stmt|;
name|q
operator|->
name|data
operator|=
literal|3
expr_stmt|;
name|d
operator|.
name|data_array
index|[
literal|9
index|]
operator|=
literal|17
expr_stmt|;
block|}
end_function

begin_comment
comment|// StringLiteral in lvalue context and pointer to array type.
end_comment

begin_comment
comment|// p: ElementRegion, q: StringRegion
end_comment

begin_function
name|void
name|f2
parameter_list|()
block|{
name|char
modifier|*
name|p
init|=
literal|"/usr/local"
decl_stmt|;
name|char
argument_list|(
operator|*
name|q
argument_list|)
index|[
literal|4
index|]
expr_stmt|;
name|q
operator|=
operator|&
literal|"abc"
expr_stmt|;
block|}
end_function

begin_comment
comment|// Typedef'ed struct definition.
end_comment

begin_function
name|void
name|f3
parameter_list|()
block|{
name|STYPE
name|s
decl_stmt|;
block|}
end_function

begin_comment
comment|// Initialize array with InitExprList.
end_comment

begin_function
name|void
name|f4
parameter_list|()
block|{
name|int
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
name|int
name|b
index|[
literal|3
index|]
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
name|struct
name|s
name|c
index|[]
init|=
block|{
block|{
literal|1
block|,
block|{
literal|1
block|}
block|}
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// Struct variable in lvalue context.
end_comment

begin_comment
comment|// Assign UnknownVal to the whole struct.
end_comment

begin_function
name|void
name|f5
parameter_list|()
block|{
name|struct
name|s
name|data
decl_stmt|;
name|g1
argument_list|(
operator|&
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AllocaRegion test.
end_comment

begin_function
name|void
name|f6
parameter_list|()
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|__builtin_alloca
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|g
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|char
name|c
init|=
operator|*
name|p
decl_stmt|;
name|p
index|[
literal|1
index|]
operator|=
literal|'a'
expr_stmt|;
comment|// Test if RegionStore::EvalBinOp converts the alloca region to element
comment|// region.
name|p
operator|+=
literal|2
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|s2
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|g2
parameter_list|(
name|struct
name|s2
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Incomplete struct pointer used as function argument.
end_comment

begin_function
name|void
name|f7
parameter_list|()
block|{
name|struct
name|s2
modifier|*
name|p
init|=
name|__builtin_alloca
argument_list|(
literal|10
argument_list|)
decl_stmt|;
name|g2
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// sizeof() is unsigned while -1 is signed in array index.
end_comment

begin_function
name|void
name|f8
parameter_list|()
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
name|a
index|[
sizeof|sizeof
argument_list|(
name|a
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Initialization of struct array elements.
end_comment

begin_function
name|void
name|f9
parameter_list|()
block|{
name|struct
name|s
name|a
index|[
literal|10
index|]
decl_stmt|;
block|}
end_function

begin_comment
comment|// Initializing array with string literal.
end_comment

begin_function
name|void
name|f10
parameter_list|()
block|{
name|char
name|a1
index|[
literal|4
index|]
init|=
literal|"abc"
decl_stmt|;
name|char
name|a3
index|[
literal|6
index|]
init|=
literal|"abc"
decl_stmt|;
block|}
end_function

begin_comment
comment|// Retrieve the default value of element/field region.
end_comment

begin_function
name|void
name|f11
parameter_list|()
block|{
name|struct
name|s
name|a
decl_stmt|;
name|g1
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|.
name|data
operator|==
literal|0
condition|)
comment|// no-warning
name|a
operator|.
name|data
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// Convert unsigned offset to signed when creating ElementRegion from
end_comment

begin_comment
comment|// SymbolicRegion.
end_comment

begin_function
name|void
name|f12
parameter_list|(
name|int
modifier|*
name|list
parameter_list|)
block|{
name|unsigned
name|i
init|=
literal|0
decl_stmt|;
name|list
index|[
name|i
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|s1
block|{
struct|struct
name|s2
block|{
name|int
name|d
decl_stmt|;
block|}
name|e
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// The binding of a.e.d should not be removed. Test recursive subregion map
end_comment

begin_comment
comment|// building: a->e, e->d. Only then 'a' could be added to live region roots.
end_comment

begin_function
name|void
name|f13
parameter_list|(
name|double
name|timeout
parameter_list|)
block|{
name|struct
name|s1
name|a
decl_stmt|;
name|a
operator|.
name|e
operator|.
name|d
operator|=
operator|(
name|long
operator|)
name|timeout
expr_stmt|;
if|if
condition|(
name|a
operator|.
name|e
operator|.
name|d
operator|==
literal|10
condition|)
name|a
operator|.
name|e
operator|.
name|d
operator|=
literal|4
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|s3
block|{
name|int
name|a
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|s3
name|opt
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Test if the embedded array is retrieved correctly.
end_comment

begin_function
name|void
name|f14
parameter_list|()
block|{
name|struct
name|s3
name|my_opt
init|=
name|opt
decl_stmt|;
block|}
end_function

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Test if the array is correctly invalidated.
end_comment

begin_function
name|void
name|f15
parameter_list|()
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
name|bar
argument_list|(
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
index|[
literal|1
index|]
condition|)
comment|// no-warning
literal|1
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|s3
name|p
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Code from postgresql.
end_comment

begin_comment
comment|// Current cast logic of region store mistakenly leaves the final result region
end_comment

begin_comment
comment|// an ElementRegion of type 'char'. Then load a nonloc::SymbolVal from it and
end_comment

begin_comment
comment|// assigns to 'a'.
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|struct
name|s3
modifier|*
name|p
parameter_list|)
block|{
name|struct
name|s3
name|a
init|=
operator|*
operator|(
operator|(
expr|struct
name|s3
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|p
index|[
literal|0
index|]
operator|)
operator|)
decl_stmt|;
block|}
end_function

end_unit

