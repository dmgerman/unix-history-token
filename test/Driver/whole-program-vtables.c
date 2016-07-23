begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -fwhole-program-vtables -### %s 2>&1 | FileCheck --check-prefix=NO-LTO %s
end_comment

begin_comment
comment|// NO-LTO: invalid argument '-fwhole-program-vtables' only allowed with '-flto'
end_comment

end_unit

