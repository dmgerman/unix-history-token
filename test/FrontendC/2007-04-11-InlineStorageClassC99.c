begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep declare | \
end_comment

begin_comment
comment|// RUN:   grep xglobWeak | grep extern_weak | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep define | \
end_comment

begin_comment
comment|// RUN:   grep xextWeak | grep weak | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep define | \
end_comment

begin_comment
comment|// RUN:   grep xWeaknoinline | grep weak | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep define | \
end_comment

begin_comment
comment|// RUN:   grep xWeakextnoinline | grep weak | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep declare | \
end_comment

begin_comment
comment|// RUN:   grep xglobnoWeak | grep -v internal | grep -v weak | \
end_comment

begin_comment
comment|// RUN:   grep -v linkonce | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep define | \
end_comment

begin_comment
comment|// RUN:   grep xstatnoWeak | grep internal | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -emit-llvm -O0 -o - | grep define | \
end_comment

begin_comment
comment|// RUN:   grep xextnoWeak | grep -v internal | grep -v weak | \
end_comment

begin_comment
comment|// RUN:   grep -v linkonce | count 1
end_comment

begin_function_decl
specifier|inline
name|int
name|xglobWeak
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
name|int
name|xglobWeak
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|2
return|;
block|}
end_function

begin_function_decl
specifier|inline
name|int
name|xextWeak
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|extern
specifier|inline
name|int
name|xextWeak
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|4
return|;
block|}
end_function

begin_function_decl
name|int
name|xWeaknoinline
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|xWeaknoinline
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|8
return|;
block|}
end_function

begin_function_decl
name|int
name|xWeakextnoinline
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|extern
name|int
name|xWeakextnoinline
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|16
return|;
block|}
end_function

begin_function
specifier|inline
name|int
name|xglobnoWeak
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|32
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|xstatnoWeak
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|64
return|;
block|}
end_function

begin_function
specifier|extern
specifier|inline
name|int
name|xextnoWeak
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|*
literal|128
return|;
block|}
end_function

begin_function
name|int
name|j
parameter_list|(
name|int
name|y
parameter_list|)
block|{
return|return
name|xglobnoWeak
argument_list|(
name|y
argument_list|)
operator|+
name|xstatnoWeak
argument_list|(
name|y
argument_list|)
operator|+
name|xextnoWeak
argument_list|(
name|y
argument_list|)
operator|+
name|xglobWeak
argument_list|(
name|y
argument_list|)
operator|+
name|xextWeak
argument_list|(
name|y
argument_list|)
operator|+
name|xWeakextnoinline
argument_list|(
name|y
argument_list|)
operator|+
name|xWeaknoinline
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

end_unit

