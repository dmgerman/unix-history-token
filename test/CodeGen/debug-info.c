begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -o %t --emit-llvm -g %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// PR3023
end_comment

begin_function
name|void
name|convert
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
block|{
name|typeof
argument_list|(
literal|0
argument_list|)
name|f0
expr_stmt|;
block|}
name|v0
struct|;
block|}
end_function

begin_comment
comment|// PR2784
end_comment

begin_struct_decl
struct_decl|struct
name|OPAQUE
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|OPAQUE
modifier|*
name|PTR
typedef|;
end_typedef

begin_decl_stmt
name|PTR
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2950
end_comment

begin_struct_decl
struct_decl|struct
name|s0
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|s0
block|{
name|struct
name|s0
modifier|*
name|p
decl_stmt|;
block|}
name|g0
struct|;
end_struct

begin_function
name|struct
name|s0
modifier|*
name|f0
parameter_list|(
name|struct
name|s0
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|p
return|;
block|}
end_function

begin_comment
comment|// PR3134
end_comment

begin_decl_stmt
name|char
name|xpto
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR3427
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|a
decl_stmt|;
name|void
modifier|*
name|ptrs
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
name|bar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR4143
end_comment

begin_struct
struct|struct
name|foo2
block|{
name|enum
name|bar
modifier|*
name|bar
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo2
name|foo2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Radar 7325611
end_comment

begin_comment
comment|// CHECK: "barfoo"
end_comment

begin_typedef
typedef|typedef
name|int
name|barfoo
typedef|;
end_typedef

begin_function
name|barfoo
name|foo
parameter_list|()
block|{ }
end_function

end_unit

