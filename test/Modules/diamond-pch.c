begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=diamond_top %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=diamond_left %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=diamond_right %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=diamond_bottom %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-pch -fmodules-cache-path=%t -I %S/Inputs -o %t.pch %S/Inputs/diamond.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -fmodules-cache-path=%t -include-pch %t.pch %s -I %S/Inputs -verify
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

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
comment|// expected-warning@-1{{incompatible pointer types passing 'double *' to parameter of type 'char *'}}
comment|// expected-note@Inputs/diamond_bottom.h:4{{passing argument to parameter 'x' here}}
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

end_unit

