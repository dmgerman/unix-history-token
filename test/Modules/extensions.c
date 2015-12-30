begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test creation of modules that include extension blocks.
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fdisable-module-hash -ftest-module-file-extension=clang.testA:1:5:0:user_info_for_A -ftest-module-file-extension=clang.testB:2:3:0:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// Make sure the extension blocks are actually there.
end_comment

begin_comment
comment|// RUN: llvm-bcanalyzer %t/ExtensionTestA.pcm | FileCheck -check-prefix=CHECK-BCANALYZER %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -module-file-info %t/ExtensionTestA.pcm | FileCheck -check-prefix=CHECK-INFO %s
end_comment

begin_comment
comment|// Make sure that the readers are able to check the metadata.
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -ftest-module-file-extension=clang.testA:1:5:0:user_info_for_A -ftest-module-file-extension=clang.testB:2:3:0:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -ftest-module-file-extension=clang.testA:1:3:0:user_info_for_A -ftest-module-file-extension=clang.testB:3:2:0:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s -verify
end_comment

begin_comment
comment|// Make sure that extension blocks can be part of the module hash.
end_comment

begin_comment
comment|// We test this in an obscure way, by making sure we don't get conflicts when
end_comment

begin_comment
comment|// using different "versions" of the extensions. Above, the "-verify" test
end_comment

begin_comment
comment|// checks that such conflicts produce errors.
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -ftest-module-file-extension=clang.testA:1:5:1:user_info_for_A -ftest-module-file-extension=clang.testB:2:3:1:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -ftest-module-file-extension=clang.testA:1:3:1:user_info_for_A -ftest-module-file-extension=clang.testB:3:2:1:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -ftest-module-file-extension=clang.testA:2:5:0:user_info_for_A -ftest-module-file-extension=clang.testB:7:3:0:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// Make sure we can read the message back.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fdisable-module-hash -ftest-module-file-extension=clang.testA:1:5:0:user_info_for_A -ftest-module-file-extension=clang.testB:2:3:0:user_info_for_B -fmodules-cache-path=%t -I %S/Inputs %s> %t.log 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MESSAGE %s< %t.log
end_comment

begin_comment
comment|// Make sure we diagnose duplicate module file extensions.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fdisable-module-hash -ftest-module-file-extension=clang.testA:1:5:0:user_info_for_A -ftest-module-file-extension=clang.testA:1:5:0:user_info_for_A -fmodules-cache-path=%t -I %S/Inputs %s> %t.log 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DUPLICATE %s< %t.log
end_comment

begin_include
include|#
directive|include
file|"ExtensionTestA.h"
end_include

begin_comment
comment|// expected-error@-1{{test module file extension 'clang.testA' has different version (1.5) than expected (1.3)}}
end_comment

begin_comment
comment|// expected-error@-2{{test module file extension 'clang.testB' has different version (2.3) than expected (3.2)}}
end_comment

begin_comment
comment|// CHECK-BCANALYZER: {{Block ID.*EXTENSION_BLOCK}}
end_comment

begin_comment
comment|// CHECK-BCANALYZER: {{100.00.*EXTENSION_METADATA}}
end_comment

begin_comment
comment|// CHECK-INFO: Module file extension 'clang.testA' 1.5: user_info_for_A
end_comment

begin_comment
comment|// CHECK-INFO: Module file extension 'clang.testB' 2.3: user_info_for_B
end_comment

begin_comment
comment|// CHECK-MESSAGE: Read extension block message: Hello from clang.testA v1.5
end_comment

begin_comment
comment|// CHECK-MESSAGE: Read extension block message: Hello from clang.testB v2.3
end_comment

begin_comment
comment|// CHECK-DUPLICATE: warning: duplicate module file extension block name 'clang.testA'
end_comment

end_unit

