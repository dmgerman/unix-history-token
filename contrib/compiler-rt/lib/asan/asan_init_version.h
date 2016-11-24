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
comment|//
comment|// Changes between ABI versions:
comment|// v1=>v2: added 'module_name' to __asan_global
comment|// v2=>v3: stack frame description (created by the compiler)
comment|//         contains the function PC as the 3rd field (see
comment|//         DescribeAddressIfStack)
comment|// v3=>v4: added '__asan_global_source_location' to __asan_global
comment|// v4=>v5: changed the semantics and format of __asan_stack_malloc_ and
comment|//         __asan_stack_free_ functions
comment|// v5=>v6: changed the name of the version check symbol
comment|// v6=>v7: added 'odr_indicator' to __asan_global
comment|// v7=>v8: added '__asan_(un)register_image_globals' functions for dead
comment|//         stripping support on Mach-O platforms
define|#
directive|define
name|__asan_version_mismatch_check
value|__asan_version_mismatch_check_v8
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

