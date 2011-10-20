begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %T/test1 %T/test2
end_comment

begin_comment
comment|// RUN: env CPATH=%T/test1 %clang -x c -E -v %s 2>&1 | FileCheck %s -check-prefix=CPATH
end_comment

begin_comment
comment|// CPATH: -I {{.*}}/test1
end_comment

begin_comment
comment|// CPATH: search starts here
end_comment

begin_comment
comment|// CPATH: test1
end_comment

begin_comment
comment|// RUN: env OBJC_INCLUDE_PATH=%T/test1  OBJCPLUS_INCLUDE_PATH=%T/test1  CPLUS_INCLUDE_PATH=%T/test1 C_INCLUDE_PATH=%T/test2 %clang -x c -E -v %s 2>&1 | FileCheck %s -check-prefix=C_INCLUDE_PATH
end_comment

begin_comment
comment|// C_INCLUDE_PATH: -c-isystem {{"?.*}}/test2{{"?}} -cxx-isystem {{"?.*}}/test1{{"?}} -objc-isystem {{"?.*}}/test1{{"?}} -objcxx-isystem {{"?.*}}/test1{{"?}}
end_comment

begin_comment
comment|// C_INCLUDE_PATH: search starts here
end_comment

begin_comment
comment|// C_INCLUDE_PATH-NOT: test1
end_comment

begin_comment
comment|// C_INCLUDE_PATH: test2
end_comment

begin_comment
comment|// C_INCLUDE_PATH-NOT: test1
end_comment

begin_comment
comment|// RUN: env OBJC_INCLUDE_PATH=%T/test1 OBJCPLUS_INCLUDE_PATH=%T/test2 CPLUS_INCLUDE_PATH=%T/test2 C_INCLUDE_PATH=%T/test1 %clang -x objective-c++ -E -v %s 2>&1 | FileCheck %s -check-prefix=OBJCPLUS_INCLUDE_PATH
end_comment

begin_comment
comment|// OBJCPLUS_INCLUDE_PATH: -c-isystem {{"?.*}}/test1{{"?}} -cxx-isystem {{"?.*}}/test2{{"?}} -objc-isystem {{"?.*}}/test1{{"?}} -objcxx-isystem {{"?.*}}/test2{{"?}}
end_comment

begin_comment
comment|// OBJCPLUS_INCLUDE_PATH: search starts here
end_comment

begin_comment
comment|// OBJCPLUS_INCLUDE_PATH-NOT: test1
end_comment

begin_comment
comment|// OBJCPLUS_INCLUDE_PATH: test2
end_comment

begin_comment
comment|// OBJCPLUS_INCLUDE_PATH-NOT: test1
end_comment

end_unit

