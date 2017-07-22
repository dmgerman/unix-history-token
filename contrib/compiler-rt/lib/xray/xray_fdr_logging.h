begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_fdr_logging.h ------------------------------------------------===//
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
comment|// This file is a part of XRay, a function call tracing system.
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
name|XRAY_XRAY_FDR_LOGGING_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_XRAY_FDR_LOGGING_H
end_define

begin_include
include|#
directive|include
file|"xray/xray_log_interface.h"
end_include

begin_include
include|#
directive|include
file|"xray_fdr_log_records.h"
end_include

begin_comment
comment|// FDR (Flight Data Recorder) Mode
end_comment

begin_comment
comment|// ===============================
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The XRay whitepaper describes a mode of operation for function call trace
end_comment

begin_comment
comment|// logging that involves writing small records into an in-memory circular
end_comment

begin_comment
comment|// buffer, that then gets logged to disk on demand. To do this efficiently and
end_comment

begin_comment
comment|// capture as much data as we can, we use smaller records compared to the
end_comment

begin_comment
comment|// default mode of always writing fixed-size records.
end_comment

begin_decl_stmt
name|namespace
name|__xray
block|{
name|XRayLogInitStatus
name|fdrLoggingInit
parameter_list|(
name|size_t
name|BufferSize
parameter_list|,
name|size_t
name|BufferMax
parameter_list|,
name|void
modifier|*
name|Options
parameter_list|,
name|size_t
name|OptionsSize
parameter_list|)
function_decl|;
name|XRayLogInitStatus
name|fdrLoggingFinalize
parameter_list|()
function_decl|;
name|void
name|fdrLoggingHandleArg0
parameter_list|(
name|int32_t
name|FuncId
parameter_list|,
name|XRayEntryType
name|Entry
parameter_list|)
function_decl|;
name|XRayLogFlushStatus
name|fdrLoggingFlush
parameter_list|()
function_decl|;
name|XRayLogInitStatus
name|fdrLoggingReset
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_XRAY_FDR_LOGGING_H
end_comment

end_unit

