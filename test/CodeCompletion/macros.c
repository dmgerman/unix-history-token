begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Green
block|,
name|Blue
block|}
enum|;
end_enum

begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|enum
name|Color
name|color
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
comment|// RUN: %clang_cc1 -include %S/Inputs/macros.h -fsyntax-only -code-completion-macros -code-completion-at=%s:12:14 %s -o - | FileCheck -check-prefix=CC1 %s
switch|switch
condition|(
name|p
operator|->
name|IDENTITY
argument_list|(
name|color
argument_list|)
condition|)
block|{
comment|// RUN: %clang_cc1 -include %S/Inputs/macros.h -fsyntax-only -code-completion-macros -code-completion-at=%s:14:9 %s -o - | FileCheck -check-prefix=CC2 %s
case|case
block|}
comment|// Run the same tests, this time with macros loaded from the PCH file.
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/Inputs/macros.h
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -code-completion-macros -code-completion-at=%s:12:14 %s -o - | FileCheck -check-prefix=CC1 %s
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -code-completion-macros -code-completion-at=%s:14:9 %s -o - | FileCheck -check-prefix=CC2 %s
comment|// CC1: BAR(<#X#>,<#Y#>)
comment|// CC1: color
comment|// CC1: FOO
comment|// CC1: IDENTITY(<#X#>)
comment|// CC1: WIBBLE
comment|// CC1: x
comment|// CC1: y
comment|// CC1: z
comment|// CC2: BAR(<#X#>,<#Y#>)
comment|// CC2: Blue
comment|// CC2: FOO
comment|// CC2: Green
comment|// CC2: IDENTITY(<#X#>)
comment|// CC2: Red
comment|// CC2: WIBBLE
block|}
end_function

end_unit

