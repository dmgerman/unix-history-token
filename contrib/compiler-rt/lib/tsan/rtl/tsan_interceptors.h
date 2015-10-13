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
block|}
empty_stmt|;
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

begin_if
if|#
directive|if
name|SANITIZER_FREEBSD
end_if

begin_define
define|#
directive|define
name|__libc_free
value|__free
end_define

begin_define
define|#
directive|define
name|__libc_malloc
value|__malloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
name|void
name|__libc_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|__libc_malloc
parameter_list|(
name|uptr
name|size
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_INTERCEPTORS_H
end_comment

end_unit

