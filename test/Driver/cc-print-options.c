begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CC_PRINT_OPTIONS=1 \
end_comment

begin_comment
comment|// RUN:     CC_PRINT_OPTIONS_FILE=%t.log \
end_comment

begin_comment
comment|// RUN: %clang -S -o %t.s %s
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_comment
comment|// CHECK: [Logging clang options]{{.*}}clang{{.*}}"-S"
end_comment

end_unit

