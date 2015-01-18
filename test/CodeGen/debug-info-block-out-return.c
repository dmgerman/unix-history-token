begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -g -fblocks -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Check that arg numbering is not affected by LLVM IR argument numbering -
end_comment

begin_comment
comment|// since the latter is affected by return-by-out-parameter ABI requirements
end_comment

begin_comment
comment|// 1 for the argument number (1 indexed), 2 for the line number
end_comment

begin_comment
comment|// 16777218 == 1<< 24 | 2
end_comment

begin_comment
comment|// 33554434 == 2<< 24 | 2
end_comment

begin_comment
comment|// This explains the two magic numbers below, testing that these two arguments
end_comment

begin_comment
comment|// are numbered correctly. If they are not numbered correctly they may appear
end_comment

begin_comment
comment|// out of order or not at all (the latter would occur if they were both assigned
end_comment

begin_comment
comment|// the same argument number by mistake).
end_comment

begin_comment
comment|// CHECK: !"0x101\00.block_descriptor\0016777218\00{{[0-9]+}}", {{.*}} ; [ DW_TAG_arg_variable ] [.block_descriptor]
end_comment

begin_comment
comment|// CHECK: !"0x101\00param\0033554434\00{{[0-9]+}}", {{.*}} ; [ DW_TAG_arg_variable ] [param]
end_comment

begin_comment
comment|// Line directive so we don't have to worry about how many lines preceed the
end_comment

begin_comment
comment|// test code (as the line number is mangled in with the argument number as shown
end_comment

begin_comment
comment|// above)
end_comment

begin_line
line|#
directive|line
number|1
end_line

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|array
index|[
literal|12
index|]
decl_stmt|;
block|}
name|BigStruct_t
typedef|;
end_typedef

begin_function_decl
name|BigStruct_t
function_decl|(
modifier|^
name|a
function_decl|)
parameter_list|()
init|=
lambda|^
parameter_list|(
name|int
name|param
parameter_list|)
block|{
name|BigStruct_t
name|b
function_decl|;
end_function_decl

begin_return
return|return
name|b
return|;
end_return

unit|};
end_unit

