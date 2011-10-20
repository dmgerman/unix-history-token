begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// in diamond-bottom.h: expected-note{{passing argument to parameter 'x' here}}
end_comment

begin_decl_stmt
name|__import_module__
name|diamond_bottom
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_diamond
parameter_list|(
name|int
name|i
parameter_list|,
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|,
name|char
name|c
parameter_list|)
block|{
name|top
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
name|left
argument_list|(
operator|&
name|f
argument_list|)
expr_stmt|;
name|right
argument_list|(
operator|&
name|d
argument_list|)
expr_stmt|;
name|bottom
argument_list|(
operator|&
name|c
argument_list|)
expr_stmt|;
name|bottom
argument_list|(
operator|&
name|d
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible pointer types passing 'double *' to parameter of type 'char *'}}
comment|// Names in multiple places in the diamond.
name|top_left
argument_list|(
operator|&
name|c
argument_list|)
expr_stmt|;
name|left_and_right
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
name|struct
name|left_and_right
name|lr
decl_stmt|;
name|lr
operator|.
name|left
operator|=
literal|17
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: %clang_cc1 -emit-module -o %T/diamond_top.pcm %S/Inputs/diamond_top.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash -emit-module -o %T/diamond_left.pcm %S/Inputs/diamond_left.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash -emit-module -o %T/diamond_right.pcm %S/Inputs/diamond_right.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash -emit-module -o %T/diamond_bottom.pcm %S/Inputs/diamond_bottom.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash %s -verify
end_comment

end_unit

