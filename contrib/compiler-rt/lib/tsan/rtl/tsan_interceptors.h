begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_INTERCEPTORS_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_INTERCEPTORS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_include
include|#
directive|include
file|"tsan_rtl.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|class
name|ScopedInterceptor
block|{
name|public
label|:
name|ScopedInterceptor
argument_list|(
argument|ThreadState *thr
argument_list|,
argument|const char *fname
argument_list|,
argument|uptr pc
argument_list|)
empty_stmt|;
operator|~
name|ScopedInterceptor
argument_list|()
expr_stmt|;
name|void
name|DisableIgnores
parameter_list|()
function_decl|;
name|void
name|EnableIgnores
parameter_list|()
function_decl|;
name|private
label|:
name|ThreadState
modifier|*
specifier|const
name|thr_
decl_stmt|;
specifier|const
name|uptr
name|pc_
decl_stmt|;
name|bool
name|in_ignored_lib_
decl_stmt|;
name|bool
name|ignoring_
decl_stmt|;
block|}
empty_stmt|;
name|LibIgnore
modifier|*
name|libignore
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_define
define|#
directive|define
name|SCOPED_INTERCEPTOR_RAW
parameter_list|(
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ThreadState *thr = cur_thread(); \     const uptr caller_pc = GET_CALLER_PC(); \     ScopedInterceptor si(thr, #func, caller_pc); \     const uptr pc = StackTrace::GetCurrentPc(); \     (void)pc;
end_define

begin_comment
unit|\
comment|/**/
end_comment

begin_define
define|#
directive|define
name|SCOPED_TSAN_INTERCEPTOR
parameter_list|(
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|SCOPED_INTERCEPTOR_RAW(func, __VA_ARGS__); \     if (REAL(func) == 0) { \       Report("FATAL: ThreadSanitizer: failed to intercept %s\n", #func); \       Die(); \     }                                                    \     if (!thr->is_inited || thr->ignore_interceptors || thr->in_ignored_lib) \       return REAL(func)(__VA_ARGS__);
end_define

begin_comment
unit|\
comment|/**/
end_comment

begin_define
define|#
directive|define
name|SCOPED_TSAN_INTERCEPTOR_USER_CALLBACK_START
parameter_list|()
define|\
value|si.DisableIgnores();
end_define

begin_define
define|#
directive|define
name|SCOPED_TSAN_INTERCEPTOR_USER_CALLBACK_END
parameter_list|()
define|\
value|si.EnableIgnores();
end_define

begin_define
define|#
directive|define
name|TSAN_INTERCEPTOR
parameter_list|(
name|ret
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
value|INTERCEPTOR(ret, func, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_INTERCEPTORS_H
end_comment

end_unit

