begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -rtlib=compiler-rt -### %s 2>&1 | FileCheck %s -check-prefix ARM-GNUEABI
end_comment

begin_comment
comment|// ARM-GNUEABI: "{{.*[/\\]}}libclang_rt.builtins-arm.a"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -rtlib=compiler-rt -mfloat-abi=hard -### %s 2>&1 | FileCheck %s -check-prefix ARM-GNUEABI-ABI
end_comment

begin_comment
comment|// ARM-GNUEABI-ABI: "{{.*[/\\]}}libclang_rt.builtins-armhf.a"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabihf -rtlib=compiler-rt -### %s 2>&1 | FileCheck %s -check-prefix ARM-GNUEABIHF
end_comment

begin_comment
comment|// ARM-GNUEABIHF: "{{.*[/\\]}}libclang_rt.builtins-armhf.a"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabihf -rtlib=compiler-rt -mfloat-abi=soft -### %s 2>&1 | FileCheck %s -check-prefix ARM-GNUEABIHF-ABI
end_comment

begin_comment
comment|// ARM-GNUEABIHF-ABI: "{{.*[/\\]}}libclang_rt.builtins-arm.a"
end_comment

begin_comment
comment|// RUN: %clang -target arm-windows-itanium -rtlib=compiler-rt -### %s 2>&1 | FileCheck %s -check-prefix ARM-WINDOWS
end_comment

begin_comment
comment|// ARM-WINDOWS: "{{.*[/\\]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -rtlib=compiler-rt -### %s 2>&1 | FileCheck %s -check-prefix ARM-ANDROID
end_comment

begin_comment
comment|// ARM-ANDROID: "{{.*[/\\]}}libclang_rt.builtins-arm-android.a"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -rtlib=compiler-rt -mfloat-abi=hard -### %s 2>&1 | FileCheck %s -check-prefix ARM-ANDROIDHF
end_comment

begin_comment
comment|// ARM-ANDROIDHF: "{{.*[/\\]}}libclang_rt.builtins-armhf-android.a"
end_comment

end_unit

