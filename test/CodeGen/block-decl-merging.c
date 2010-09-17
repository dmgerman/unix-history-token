begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -fblocks -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s
end_comment

begin_comment
comment|// CHECK: @_NSConcreteGlobalBlock = extern_weak global
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_NSConcreteStackBlock
index|[
literal|32
index|]
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @_NSConcreteStackBlock = extern_weak global
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_NSConcreteGlobalBlock
index|[
literal|32
index|]
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|_Block_object_dispose
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: declare extern_weak void @_Block_object_assign
end_comment

begin_function_decl
specifier|extern
name|void
name|_Block_object_assign
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: declare extern_weak void @_Block_object_dispose
end_comment

begin_decl_stmt
name|void
modifier|*
name|x
init|=
lambda|^
parameter_list|()
block|{}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f1
parameter_list|(
name|void
function_decl|(
modifier|^
name|a0
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|()
block|{
specifier|__block
name|int
name|x
decl_stmt|;
name|f1
argument_list|(
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
name|x
operator|=
literal|1
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

