begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x c -DINCLUDE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x objective-c -DINCLUDE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x c++ -DINCLUDE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x objective-c -DAT_IMPORT=1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x objective-c++ -DAT_IMPORT=1 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x c++ -fmodules-ts -DIMPORT=1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x objective-c++ -fmodules-ts -DIMPORT=1 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x c -DPRAGMA %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x objective-c -DPRAGMA %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fimplicit-module-maps -I%S/Inputs -verify -x c++ -DPRAGMA %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// All forms of module import should make both declarations and macros visible.
end_comment

begin_if
if|#
directive|if
name|INCLUDE
end_if

begin_include
include|#
directive|include
file|"dummy.h"
end_include

begin_elif
elif|#
directive|elif
name|AT_IMPORT
end_elif

begin_decl_stmt
unit|@
name|import
name|dummy
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|IMPORT
end_elif

begin_decl_stmt
name|import
name|dummy
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|PRAGMA
end_elif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|dummy
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DUMMY_H
end_ifndef

begin_error
error|#
directive|error
literal|"macros not visible"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
modifier|*
name|p
init|=
operator|&
name|dummy1
decl_stmt|;
end_decl_stmt

end_unit

