begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// rdar://8315199
end_comment

begin_comment
comment|/* Test for builtin conj, creal, cimag.  */
end_comment

begin_comment
comment|/* Origin: Joseph Myers<jsm28@cam.ac.uk> */
end_comment

begin_function_decl
specifier|extern
name|float
specifier|_Complex
name|conjf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
specifier|_Complex
name|conj
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|double
specifier|_Complex
name|conjl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|crealf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|creal
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|double
name|creall
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|cimagf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|cimag
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|double
name|cimagl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|/* For each type, test both runtime and compile time (constant folding)      optimization.  */
specifier|volatile
name|float
specifier|_Complex
name|fc
init|=
literal|1.0F + 2.0iF
decl_stmt|;
specifier|volatile
name|double
specifier|_Complex
name|dc
init|=
literal|1.0 + 2.0i
decl_stmt|;
specifier|volatile
name|long
name|double
specifier|_Complex
name|ldc
init|=
literal|1.0L + 2.0iL
decl_stmt|;
comment|/* Test floats.  */
if|if
condition|(
name|__builtin_conjf
argument_list|(
name|fc
argument_list|)
operator|!=
literal|1.0F - 2.0iF
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_conjf
argument_list|(
literal|1.0F + 2.0iF
argument_list|)
operator|!=
literal|1.0F - 2.0iF
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_crealf
argument_list|(
name|fc
argument_list|)
operator|!=
literal|1.0F
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_crealf
argument_list|(
literal|1.0F + 2.0iF
argument_list|)
operator|!=
literal|1.0F
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimagf
argument_list|(
name|fc
argument_list|)
operator|!=
literal|2.0F
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimagf
argument_list|(
literal|1.0F + 2.0iF
argument_list|)
operator|!=
literal|2.0F
condition|)
name|link_error
argument_list|()
expr_stmt|;
comment|/* Test doubles.  */
if|if
condition|(
name|__builtin_conj
argument_list|(
name|dc
argument_list|)
operator|!=
literal|1.0 - 2.0i
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_conj
argument_list|(
literal|1.0 + 2.0i
argument_list|)
operator|!=
literal|1.0 - 2.0i
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_creal
argument_list|(
name|dc
argument_list|)
operator|!=
literal|1.0
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_creal
argument_list|(
literal|1.0 + 2.0i
argument_list|)
operator|!=
literal|1.0
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimag
argument_list|(
name|dc
argument_list|)
operator|!=
literal|2.0
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimag
argument_list|(
literal|1.0 + 2.0i
argument_list|)
operator|!=
literal|2.0
condition|)
name|link_error
argument_list|()
expr_stmt|;
comment|/* Test long doubles.  */
if|if
condition|(
name|__builtin_conjl
argument_list|(
name|ldc
argument_list|)
operator|!=
literal|1.0L - 2.0iL
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_conjl
argument_list|(
literal|1.0L + 2.0iL
argument_list|)
operator|!=
literal|1.0L - 2.0iL
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_creall
argument_list|(
name|ldc
argument_list|)
operator|!=
literal|1.0L
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_creall
argument_list|(
literal|1.0L + 2.0iL
argument_list|)
operator|!=
literal|1.0L
condition|)
name|link_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimagl
argument_list|(
name|ldc
argument_list|)
operator|!=
literal|2.0L
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|__builtin_cimagl
argument_list|(
literal|1.0L + 2.0iL
argument_list|)
operator|!=
literal|2.0L
condition|)
name|link_error
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: link_error
end_comment

end_unit

