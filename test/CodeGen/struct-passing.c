begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This verifies that structs returned from functions by value are passed
end_comment

begin_comment
comment|// correctly according to their attributes and the ABI.
end_comment

begin_comment
comment|// SEE: PR3835
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|T0
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
index|[
literal|16
index|]
decl_stmt|;
block|}
name|T1
typedef|;
end_typedef

begin_decl_stmt
name|T0
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|f0
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|T0
name|__attribute__
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|T1
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|T1
name|__attribute__
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|f3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|f4
argument_list|(
name|T1
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|f5
argument_list|(
name|T1
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|ps
index|[]
init|=
block|{
name|f0
block|,
name|f1
block|,
name|f2
block|,
name|f3
block|,
name|f4
block|,
name|f5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: declare i32 @f0() readnone
end_comment

begin_comment
comment|// CHECK: declare i32 @f1() readonly
end_comment

begin_comment
comment|// CHECK: declare void @f2({{.*}} sret)
end_comment

begin_comment
comment|// CHECK: declare void @f3({{.*}} sret)
end_comment

begin_comment
comment|// CHECK: declare void @f4({{.*}} byval)
end_comment

begin_comment
comment|// CHECK: declare void @f5({{.*}} byval)
end_comment

end_unit

