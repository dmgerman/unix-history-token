begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_log_interface.h ----------------------------------------------===//
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
comment|// APIs for installing a new logging implementation.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XRAY_XRAY_LOG_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_XRAY_LOG_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|"xray/xray_interface.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_extern
extern|extern
literal|"C"
block|{
enum|enum
name|XRayLogInitStatus
block|{
name|XRAY_LOG_UNINITIALIZED
init|=
literal|0
block|,
name|XRAY_LOG_INITIALIZING
init|=
literal|1
block|,
name|XRAY_LOG_INITIALIZED
init|=
literal|2
block|,
name|XRAY_LOG_FINALIZING
init|=
literal|3
block|,
name|XRAY_LOG_FINALIZED
init|=
literal|4
block|, }
enum|;
enum|enum
name|XRayLogFlushStatus
block|{
name|XRAY_LOG_NOT_FLUSHING
init|=
literal|0
block|,
name|XRAY_LOG_FLUSHING
init|=
literal|1
block|,
name|XRAY_LOG_FLUSHED
init|=
literal|2
block|, }
enum|;
struct|struct
name|XRayLogImpl
block|{
name|XRayLogInitStatus
function_decl|(
modifier|*
name|log_init
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|XRayLogInitStatus
function_decl|(
modifier|*
name|log_finalize
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|handle_arg0
function_decl|)
parameter_list|(
name|int32_t
parameter_list|,
name|XRayEntryType
parameter_list|)
function_decl|;
name|XRayLogFlushStatus
function_decl|(
modifier|*
name|flush_log
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
name|void
name|__xray_set_log_impl
parameter_list|(
name|XRayLogImpl
name|Impl
parameter_list|)
function_decl|;
name|XRayLogInitStatus
name|__xray_log_init
parameter_list|(
name|size_t
name|BufferSize
parameter_list|,
name|size_t
name|MaxBuffers
parameter_list|,
name|void
modifier|*
name|Args
parameter_list|,
name|size_t
name|ArgsSize
parameter_list|)
function_decl|;
name|XRayLogInitStatus
name|__xray_log_finalize
parameter_list|()
function_decl|;
name|XRayLogFlushStatus
name|__xray_log_flushLog
parameter_list|()
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|namespace
name|__xray
block|{
comment|// Options used by the LLVM XRay FDR implementation.
struct|struct
name|FDRLoggingOptions
block|{
name|bool
name|ReportErrors
init|=
name|false
decl_stmt|;
name|int
name|Fd
init|=
operator|-
literal|1
decl_stmt|;
block|}
struct|;
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
comment|// XRAY_XRAY_LOG_INTERFACE_H
end_comment

end_unit

