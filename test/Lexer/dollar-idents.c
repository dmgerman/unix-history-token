begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -dump-tokens %s 2> %t&&
end_comment

begin_comment
comment|// RUN: grep "identifier '\$A'" %t&&
end_comment

begin_comment
comment|// RUN: clang-cc -dump-tokens -x assembler-with-cpp %s 2> %t&&
end_comment

begin_comment
comment|// RUN: grep "identifier 'A'" %t
end_comment

begin_comment
comment|// PR3808
end_comment

begin_macro
name|$A
end_macro

end_unit

