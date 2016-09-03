begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/esan_interface.h ------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_ESAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ESAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
end_include

begin_comment
comment|// We declare our interface routines as weak to allow the user to avoid
end_comment

begin_comment
comment|// ifdefs and instead use this pattern to allow building the same sources
end_comment

begin_comment
comment|// with and without our runtime library:
end_comment

begin_comment
comment|//     if (__esan_report)
end_comment

begin_comment
comment|//       __esan_report();
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|/* selectany is as close to weak as we'll get. */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
value|__declspec(selectany)
end_define

begin_elif
elif|#
directive|elif
name|__GNUC__
end_elif

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
value|__attribute__((weak))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// This function can be called mid-run (or at the end of a run for
comment|// a server process that doesn't shut down normally) to request that
comment|// data for that point in the run be reported from the tool.
name|void
name|COMPILER_RT_WEAK
name|__esan_report
parameter_list|()
function_decl|;
comment|// This function returns the number of samples that the esan tool has collected
comment|// to this point.  This is useful for testing.
name|unsigned
name|int
name|COMPILER_RT_WEAK
name|__esan_get_sample_count
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ESAN_INTERFACE_H
end_comment

end_unit

