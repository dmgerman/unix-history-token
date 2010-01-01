begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: ModuleID
end_comment

begin_comment
comment|// CHECK-NOT: opaque
end_comment

begin_comment
comment|// CHECK: define void @f0
end_comment

begin_decl_stmt
name|enum
name|teste1
name|test1f
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|test1
argument_list|)
argument_list|(
name|void
argument_list|)
init|=
name|test1f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tests2
name|test2f
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|test2
argument_list|)
argument_list|()
init|=
name|test2f
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|tests3
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|test3f
argument_list|(
expr|struct
name|tests3
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|test3
argument_list|)
argument_list|(
expr|struct
name|tests3
argument_list|)
init|=
name|test3f
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|teste1
block|{
name|TEST1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|tests2
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|,
name|f
decl_stmt|,
name|g
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tests3
block|{
name|float
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f0
parameter_list|()
block|{}
end_function

end_unit

