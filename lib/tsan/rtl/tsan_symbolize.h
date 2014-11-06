begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_symbolize.h ----------------------------------------*- C++ -*-===//
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
name|TSAN_SYMBOLIZE_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_SYMBOLIZE_H
end_define

begin_include
include|#
directive|include
file|"tsan_defs.h"
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
name|EnterSymbolizer
parameter_list|()
function_decl|;
name|void
name|ExitSymbolizer
parameter_list|()
function_decl|;
name|ReportStack
modifier|*
name|SymbolizeCode
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|ReportLocation
modifier|*
name|SymbolizeData
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|void
name|SymbolizeFlush
parameter_list|()
function_decl|;
name|ReportStack
modifier|*
name|SymbolizeCodeAddr2Line
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|ReportStack
modifier|*
name|NewReportStackEntry
parameter_list|(
name|uptr
name|addr
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
comment|// TSAN_SYMBOLIZE_H
end_comment

end_unit

