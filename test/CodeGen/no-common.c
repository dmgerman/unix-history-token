begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@x = common global' %t
end_comment

begin_comment
comment|// RUN: %clang -fno-common -emit-llvm -S -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@x = global' %t
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

