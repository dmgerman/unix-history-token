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
name|FinalizeSuppressions
parameter_list|()
function_decl|;
name|bool
name|IsSuppressed
parameter_list|(
name|ReportType
name|typ
parameter_list|,
specifier|const
name|ReportStack
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// Exposed for testing.
enum|enum
name|SuppressionType
block|{
name|SuppressionRace
block|,
name|SuppressionMutex
block|,
name|SuppressionThread
block|,
name|SuppressionSignal
block|, }
enum|;
struct|struct
name|Suppression
block|{
name|Suppression
modifier|*
name|next
decl_stmt|;
name|SuppressionType
name|type
decl_stmt|;
name|char
modifier|*
name|templ
decl_stmt|;
block|}
struct|;
name|Suppression
modifier|*
name|SuppressionParse
parameter_list|(
specifier|const
name|char
modifier|*
name|supp
parameter_list|)
function_decl|;
name|bool
name|SuppressionMatch
parameter_list|(
name|char
modifier|*
name|templ
parameter_list|,
specifier|const
name|char
modifier|*
name|str
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

