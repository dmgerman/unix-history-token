begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_suppressions.h -------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_SUPPRESSIONS_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_SUPPRESSIONS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_suppressions.h"
end_include

begin_include
include|#
directive|include
file|"tsan_report.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|void
name|InitializeSuppressions
parameter_list|()
function_decl|;
name|void
name|PrintMatchedSuppressions
parameter_list|()
function_decl|;
name|uptr
name|IsSuppressed
parameter_list|(
name|ReportType
name|typ
parameter_list|,
specifier|const
name|ReportStack
modifier|*
name|stack
parameter_list|,
name|Suppression
modifier|*
modifier|*
name|sp
parameter_list|)
function_decl|;
name|uptr
name|IsSuppressed
parameter_list|(
name|ReportType
name|typ
parameter_list|,
specifier|const
name|ReportLocation
modifier|*
name|loc
parameter_list|,
name|Suppression
modifier|*
modifier|*
name|sp
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_SUPPRESSIONS_H
end_comment

end_unit

