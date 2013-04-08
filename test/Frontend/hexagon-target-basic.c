begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple hexagon-unknown-unknown %s -S -o /dev/null
end_comment

begin_comment
comment|// REQUIRES: hexagon-registered-target
end_comment

begin_comment
comment|// Testcase for bug 14744.  Empty file is sufficient, since the problem
end_comment

begin_comment
comment|// was a bad data layout string in the Hexagon target causing an ICE
end_comment

begin_comment
comment|// when compiling any Hexagon program.
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// In C99, a translation unit needs to have at least one declaration.
end_comment

end_unit

