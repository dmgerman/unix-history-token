begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_init_version.h -------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header defines a versioned __asan_init function to be called at the
end_comment

begin_comment
comment|// startup of the instrumented program.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INIT_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INIT_VERSION_H
end_define

begin_extern
extern|extern
literal|"C"
block|{
comment|// Every time the ASan ABI changes we also change the version number in the
comment|// __asan_init function name.  Objects built with incompatible ASan ABI
comment|// versions will not link with run-time.
comment|// Changes between ABI versions:
comment|// v1=>v2: added 'module_name' to __asan_global
comment|// v2=>v3: stack frame description (created by the compiler)
comment|//         contains the function PC as the 3-rd field (see
comment|//         DescribeAddressIfStack).
comment|// v3=>v4: added '__asan_global_source_location' to __asan_global.
define|#
directive|define
name|__asan_init
value|__asan_init_v4
define|#
directive|define
name|__asan_init_name
value|"__asan_init_v4"
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_INIT_VERSION_H
end_comment

end_unit

