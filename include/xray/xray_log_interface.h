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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// XRay allows users to implement their own logging handlers and install them
end_comment

begin_comment
comment|/// to replace the default runtime-controllable implementation that comes with
end_comment

begin_comment
comment|/// compiler-rt/xray. The "flight data recorder" (FDR) mode implementation uses
end_comment

begin_comment
comment|/// this API to install itself in an XRay-enabled binary. See
end_comment

begin_comment
comment|/// compiler-rt/lib/xray_fdr_logging.{h,cc} for details of that implementation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The high-level usage pattern for these APIs look like the following:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // Before we try initializing the log implementation, we must set it as
end_comment

begin_comment
comment|///   // the log implementation. We provide the function pointers that define
end_comment

begin_comment
comment|///   // the various initialization, finalization, and other pluggable hooks
end_comment

begin_comment
comment|///   // that we need.
end_comment

begin_comment
comment|///   __xray_set_log_impl({...});
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // Once that's done, we can now initialize the implementation. Each
end_comment

begin_comment
comment|///   // implementation has a chance to let users customize the implementation
end_comment

begin_comment
comment|///   // with a struct that their implementation supports. Roughly this might
end_comment

begin_comment
comment|///   // look like:
end_comment

begin_comment
comment|///   MyImplementationOptions opts;
end_comment

begin_comment
comment|///   opts.enable_feature = true;
end_comment

begin_comment
comment|///   ...
end_comment

begin_comment
comment|///   auto init_status = __xray_log_init(
end_comment

begin_comment
comment|///       BufferSize, MaxBuffers,&opts, sizeof opts);
end_comment

begin_comment
comment|///   if (init_status != XRayLogInitStatus::XRAY_LOG_INITIALIZED) {
end_comment

begin_comment
comment|///     // deal with the error here, if there is one.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // When the log implementation has had the chance to initialize, we can
end_comment

begin_comment
comment|///   // now patch the sleds.
end_comment

begin_comment
comment|///   auto patch_status = __xray_patch();
end_comment

begin_comment
comment|///   if (patch_status != XRayPatchingStatus::SUCCESS) {
end_comment

begin_comment
comment|///     // deal with the error here, if it is an error.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // If we want to stop the implementation, we can then finalize it (before
end_comment

begin_comment
comment|///   // optionally flushing the log).
end_comment

begin_comment
comment|///   auto fin_status = __xray_log_finalize();
end_comment

begin_comment
comment|///   if (fin_status != XRayLogInitStatus::XRAY_LOG_FINALIZED) {
end_comment

begin_comment
comment|///     // deal with the error here, if it is an error.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // We can optionally wait before flushing the log to give other threads a
end_comment

begin_comment
comment|///   // chance to see that the implementation is already finalized. Also, at
end_comment

begin_comment
comment|///   // this point we can optionally unpatch the sleds to reduce overheads at
end_comment

begin_comment
comment|///   // runtime.
end_comment

begin_comment
comment|///   auto unpatch_status = __xray_unpatch();
end_comment

begin_comment
comment|///   if (unpatch_status != XRayPatchingStatus::SUCCESS) {
end_comment

begin_comment
comment|//      // deal with the error here, if it is an error.
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // If there are logs or data to be flushed somewhere, we can do so only
end_comment

begin_comment
comment|///   // after we've finalized the log. Some implementations may not actually
end_comment

begin_comment
comment|///   // have anything to log (it might keep the data in memory, or periodically
end_comment

begin_comment
comment|///   // be logging the data anyway).
end_comment

begin_comment
comment|///   auto flush_status = __xray_log_flushLog();
end_comment

begin_comment
comment|///   if (flush_status != XRayLogFlushStatus::XRAY_LOG_FLUSHED) {
end_comment

begin_comment
comment|///     // deal with the error here, if it is an error.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: Before calling __xray_patch() again, consider re-initializing the
end_comment

begin_comment
comment|/// implementation first. Some implementations might stay in an "off" state when
end_comment

begin_comment
comment|/// they are finalized, while some might be in an invalid/unknown state.
end_comment

begin_comment
comment|///
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
comment|/// This enum defines the valid states in which the logging implementation can
comment|/// be at.
enum|enum
name|XRayLogInitStatus
block|{
comment|/// The default state is uninitialized, and in case there were errors in the
comment|/// initialization, the implementation MUST return XRAY_LOG_UNINITIALIZED.
name|XRAY_LOG_UNINITIALIZED
init|=
literal|0
block|,
comment|/// Some implementations support multi-stage init (or asynchronous init), and
comment|/// may return XRAY_LOG_INITIALIZING to signal callers of the API that
comment|/// there's an ongoing initialization routine running. This allows
comment|/// implementations to support concurrent threads attempting to initialize,
comment|/// while only signalling success in one.
name|XRAY_LOG_INITIALIZING
init|=
literal|1
block|,
comment|/// When an implementation is done initializing, it MUST return
comment|/// XRAY_LOG_INITIALIZED. When users call `__xray_patch()`, they are
comment|/// guaranteed that the implementation installed with
comment|/// `__xray_set_log_impl(...)` has been initialized.
name|XRAY_LOG_INITIALIZED
init|=
literal|2
block|,
comment|/// Some implementations might support multi-stage finalization (or
comment|/// asynchronous finalization), and may return XRAY_LOG_FINALIZING to signal
comment|/// callers of the API that there's an ongoing finalization routine running.
comment|/// This allows implementations to support concurrent threads attempting to
comment|/// finalize, while only signalling success/completion in one.
name|XRAY_LOG_FINALIZING
init|=
literal|3
block|,
comment|/// When an implementation is done finalizing, it MUST return
comment|/// XRAY_LOG_FINALIZED. It is up to the implementation to determine what the
comment|/// semantics of a finalized implementation is. Some implementations might
comment|/// allow re-initialization once the log is finalized, while some might always
comment|/// be on (and that finalization is a no-op).
name|XRAY_LOG_FINALIZED
init|=
literal|4
block|, }
enum|;
comment|/// This enum allows an implementation to signal log flushing operations via
comment|/// `__xray_log_flushLog()`, and the state of flushing the log.
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
comment|/// A valid XRay logging implementation MUST provide all of the function
comment|/// pointers in XRayLogImpl when being installed through `__xray_set_log_impl`.
comment|/// To be precise, ALL the functions pointers MUST NOT be nullptr.
struct|struct
name|XRayLogImpl
block|{
comment|/// The log initialization routine provided by the implementation, always
comment|/// provided with the following parameters:
comment|///
comment|///   - buffer size
comment|///   - maximum number of buffers
comment|///   - a pointer to an argument struct that the implementation MUST handle
comment|///   - the size of the argument struct
comment|///
comment|/// See XRayLogInitStatus for details on what the implementation MUST return
comment|/// when called.
comment|///
comment|/// If the implementation needs to install handlers aside from the 0-argument
comment|/// function call handler, it MUST do so in this initialization handler.
comment|///
comment|/// See xray_interface.h for available handler installation routines.
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
comment|/// The log finalization routine provided by the implementation.
comment|///
comment|/// See XRayLogInitStatus for details on what the implementation MUST return
comment|/// when called.
name|XRayLogInitStatus
function_decl|(
modifier|*
name|log_finalize
function_decl|)
parameter_list|()
function_decl|;
comment|/// The 0-argument function call handler. XRay logging implementations MUST
comment|/// always have a handler for function entry and exit events. In case the
comment|/// implementation wants to support arg1 (or other future extensions to XRay
comment|/// logging) those MUST be installed by the installed 'log_init' handler.
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
comment|/// The log implementation provided routine for when __xray_log_flushLog() is
comment|/// called.
comment|///
comment|/// See XRayLogFlushStatus for details on what the implementation MUST return
comment|/// when called.
name|XRayLogFlushStatus
function_decl|(
modifier|*
name|flush_log
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
comment|/// This function installs a new logging implementation that XRay will use. In
comment|/// case there are any nullptr members in Impl, XRay will *uninstall any
comment|/// existing implementations*. It does NOT patch the instrumentation sleds.
comment|///
comment|/// NOTE: This function does NOT attempt to finalize the currently installed
comment|/// implementation. Use with caution.
comment|///
comment|/// It is guaranteed safe to call this function in the following states:
comment|///
comment|///   - When the implementation is UNINITIALIZED.
comment|///   - When the implementation is FINALIZED.
comment|///   - When there is no current implementation installed.
comment|///
comment|/// It is logging implementation defined what happens when this function is
comment|/// called while in any other states.
name|void
name|__xray_set_log_impl
parameter_list|(
name|XRayLogImpl
name|Impl
parameter_list|)
function_decl|;
comment|/// This function removes the currently installed implementation. It will also
comment|/// uninstall any handlers that have been previously installed. It does NOT
comment|/// unpatch the instrumentation sleds.
comment|///
comment|/// NOTE: This function does NOT attempt to finalize the currently installed
comment|/// implementation. Use with caution.
comment|///
comment|/// It is guaranteed safe to call this function in the following states:
comment|///
comment|///   - When the implementation is UNINITIALIZED.
comment|///   - When the implementation is FINALIZED.
comment|///   - When there is no current implementation installed.
comment|///
comment|/// It is logging implementation defined what happens when this function is
comment|/// called while in any other states.
name|void
name|__xray_remove_log_impl
parameter_list|()
function_decl|;
comment|/// Invokes the installed implementation initialization routine. See
comment|/// XRayLogInitStatus for what the return values mean.
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
comment|/// Invokes the installed implementation finalization routine. See
comment|/// XRayLogInitStatus for what the return values mean.
name|XRayLogInitStatus
name|__xray_log_finalize
parameter_list|()
function_decl|;
comment|/// Invokes the install implementation log flushing routine. See
comment|/// XRayLogFlushStatus for what the return values mean.
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

