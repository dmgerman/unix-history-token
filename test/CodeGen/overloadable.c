begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple %itanium_abi_triple -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: _Z1fPA10_1X
end_comment

begin_comment
comment|// CHECK: _Z1fPFvE
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|int
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|float
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|float
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|double
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|double
specifier|_Complex
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|double
specifier|_Complex
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|short
name|v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_decl_stmt
name|v4hi
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|v4hi
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_struct
struct|struct
name|X
block|{ }
struct|;
end_struct

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
expr|struct
name|X
argument_list|(
operator|*
name|ptr
argument_list|)
index|[
literal|10
index|]
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
operator|...
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f
argument_list|(
name|void
argument_list|(
operator|*
name|x
argument_list|)
argument_list|()
argument_list|)
block|{}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|iv
init|=
literal|17
decl_stmt|;
name|float
name|fv
init|=
literal|3.0f
decl_stmt|;
name|double
name|dv
init|=
literal|4.0
decl_stmt|;
name|double
specifier|_Complex
name|cdv
decl_stmt|;
name|v4hi
name|vv
decl_stmt|;
name|iv
operator|=
name|f
argument_list|(
name|iv
argument_list|)
expr_stmt|;
name|fv
operator|=
name|f
argument_list|(
name|fv
argument_list|)
expr_stmt|;
name|dv
operator|=
name|f
argument_list|(
name|dv
argument_list|)
expr_stmt|;
name|cdv
operator|=
name|f
argument_list|(
name|cdv
argument_list|)
expr_stmt|;
name|vv
operator|=
name|f
argument_list|(
name|vv
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Ensuring that we pick the correct function for taking the address of an
end_comment

begin_comment
comment|// overload when conversions are involved.
end_comment

begin_function_decl
name|void
name|addrof_many
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addrof_many
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addrof_many
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addrof_single
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addrof_single
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addrof_single
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @foo
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: store void (i8*)* @_Z11addrof_manyPc
name|void
function_decl|(
modifier|*
name|p1
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
init|=
operator|&
name|addrof_many
function_decl|;
comment|// CHECK: store void (i8*)* @_Z11addrof_manyPv
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
operator|&
name|addrof_many
function_decl|;
comment|// CHECK: void (i8*)* @_Z11addrof_manyPc
name|void
modifier|*
name|vp1
init|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|)
operator|)
operator|&
name|addrof_many
decl_stmt|;
comment|// CHECK: void (i8*)* @_Z11addrof_manyPv
name|void
modifier|*
name|vp2
init|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
operator|&
name|addrof_many
decl_stmt|;
comment|// CHECK: store void (i8*)* @_Z13addrof_singlePc
name|void
function_decl|(
modifier|*
name|p3
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
init|=
operator|&
name|addrof_single
function_decl|;
comment|// CHECK: @_Z13addrof_singlePc
name|void
function_decl|(
modifier|*
name|p4
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
init|=
operator|&
name|addrof_single
function_decl|;
comment|// CHECK: @_Z13addrof_singlePc
name|void
modifier|*
name|vp3
init|=
operator|&
name|addrof_single
decl_stmt|;
block|}
end_function

begin_function_decl
name|void
name|ovl_bar
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ovl_bar
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @bar
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
name|char
name|charbuf
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|ucharbuf
index|[
literal|1
index|]
decl_stmt|;
comment|// CHECK: call void @_Z7ovl_barPc
name|ovl_bar
argument_list|(
name|charbuf
argument_list|)
expr_stmt|;
comment|// CHECK: call void @_Z7ovl_barPc
name|ovl_bar
argument_list|(
name|ucharbuf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|ovl_baz
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ovl_baz
parameter_list|(
name|unsigned
name|int
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ovl_baz2
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ovl_baz2
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @baz
end_comment

begin_function
name|void
name|baz
parameter_list|()
block|{
name|unsigned
name|int
name|j
decl_stmt|;
comment|// Initial rules for incompatible pointer conversions made this overload
comment|// ambiguous.
comment|// CHECK: call void @_Z7ovl_bazPjj
name|ovl_baz
argument_list|(
operator|&
name|j
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @_Z7ovl_bazPjj
name|ovl_baz
argument_list|(
operator|&
name|j
argument_list|,
literal|0u
argument_list|)
expr_stmt|;
comment|// CHECK: call void @_Z8ovl_baz2jPj
name|ovl_baz2
argument_list|(
literal|0
argument_list|,
operator|&
name|j
argument_list|)
expr_stmt|;
comment|// CHECK: call void @_Z8ovl_baz2jPj
name|ovl_baz2
argument_list|(
literal|0u
argument_list|,
operator|&
name|j
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

