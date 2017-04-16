begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.DumpTraversal %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.DumpTraversal -DUSE_EXPR %s | FileCheck %s
end_comment

begin_function_decl
name|int
name|a
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|b
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|c
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_EXPR
end_ifdef

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|x
parameter_list|)
value|((x)& 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: --BEGIN FUNCTION--
end_comment

begin_function
name|void
name|testRemoveDeadBindings
parameter_list|()
block|{
name|int
name|i
init|=
name|a
argument_list|()
decl_stmt|;
if|if
condition|(
name|CHECK
argument_list|(
name|i
argument_list|)
condition|)
name|a
argument_list|()
expr_stmt|;
else|else
name|b
argument_list|()
expr_stmt|;
comment|// At this point the symbol bound to 'i' is dead.
comment|// The effects of a() and b() are identical (they both invalidate globals).
comment|// We should unify the two paths here and only get one end-of-path node.
name|c
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: --END FUNCTION--
end_comment

begin_comment
comment|// CHECK-NOT: --END FUNCTION--
end_comment

end_unit

