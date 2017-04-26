begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/print_address.h"
end_include

begin_include
include|#
directive|include
file|<sanitizer/tsan_interface.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<mach/mach_time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSan-invisible barrier.
end_comment

begin_comment
comment|// Tests use it to establish necessary execution order in a way that does not
end_comment

begin_comment
comment|// interfere with tsan (does not establish synchronization between threads).
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|invisible_barrier_t
typedef|;
end_typedef

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
name|void
name|__tsan_testonly_barrier_init
parameter_list|(
name|invisible_barrier_t
modifier|*
name|barrier
parameter_list|,
name|unsigned
name|count
parameter_list|)
function_decl|;
name|void
name|__tsan_testonly_barrier_wait
parameter_list|(
name|invisible_barrier_t
modifier|*
name|barrier
parameter_list|)
function_decl|;
name|unsigned
name|long
name|__tsan_testonly_shadow_stack_current_size
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|void
name|barrier_init
parameter_list|(
name|invisible_barrier_t
modifier|*
name|barrier
parameter_list|,
name|unsigned
name|count
parameter_list|)
block|{
name|__tsan_testonly_barrier_init
argument_list|(
name|barrier
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|barrier_wait
parameter_list|(
name|invisible_barrier_t
modifier|*
name|barrier
parameter_list|)
block|{
name|__tsan_testonly_barrier_wait
argument_list|(
name|barrier
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Default instance of the barrier, but a test can declare more manually.
end_comment

begin_decl_stmt
name|invisible_barrier_t
name|barrier
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|monotonic_clock_ns
parameter_list|()
block|{
specifier|static
name|mach_timebase_info_data_t
name|timebase_info
decl_stmt|;
if|if
condition|(
name|timebase_info
operator|.
name|denom
operator|==
literal|0
condition|)
name|mach_timebase_info
argument_list|(
operator|&
name|timebase_info
argument_list|)
expr_stmt|;
return|return
operator|(
name|mach_absolute_time
argument_list|()
operator|*
name|timebase_info
operator|.
name|numer
operator|)
operator|/
name|timebase_info
operator|.
name|denom
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|unsigned
name|long
name|long
name|monotonic_clock_ns
parameter_list|()
block|{
name|struct
name|timespec
name|t
decl_stmt|;
name|clock_gettime
argument_list|(
name|CLOCK_MONOTONIC
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
operator|(
name|unsigned
name|long
name|long
operator|)
name|t
operator|.
name|tv_sec
operator|*
literal|1000000000ull
operator|+
name|t
operator|.
name|tv_nsec
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//The const kPCInc must be in sync with StackTrace::GetPreviousInstructionPc
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_comment
comment|// PCs are always 4 byte aligned.
end_comment

begin_decl_stmt
specifier|const
name|int
name|kPCInc
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_decl_stmt
specifier|const
name|int
name|kPCInc
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|int
name|kPCInc
init|=
literal|1
decl_stmt|;
end_decl_stmt

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
name|void
name|AnnotateRWLockCreate
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|,
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
name|void
name|AnnotateRWLockCreateStatic
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|,
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
name|void
name|AnnotateRWLockDestroy
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|,
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
name|void
name|AnnotateRWLockAcquired
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|long
name|is_w
parameter_list|)
function_decl|;
name|void
name|AnnotateRWLockReleased
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|long
name|is_w
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ANNOTATE_RWLOCK_CREATE
parameter_list|(
name|m
parameter_list|)
define|\
value|AnnotateRWLockCreate(__FILE__, __LINE__, m)
end_define

begin_define
define|#
directive|define
name|ANNOTATE_RWLOCK_CREATE_STATIC
parameter_list|(
name|m
parameter_list|)
define|\
value|AnnotateRWLockCreateStatic(__FILE__, __LINE__, m)
end_define

begin_define
define|#
directive|define
name|ANNOTATE_RWLOCK_DESTROY
parameter_list|(
name|m
parameter_list|)
define|\
value|AnnotateRWLockDestroy(__FILE__, __LINE__, m)
end_define

begin_define
define|#
directive|define
name|ANNOTATE_RWLOCK_ACQUIRED
parameter_list|(
name|m
parameter_list|,
name|is_w
parameter_list|)
define|\
value|AnnotateRWLockAcquired(__FILE__, __LINE__, m, is_w)
end_define

begin_define
define|#
directive|define
name|ANNOTATE_RWLOCK_RELEASED
parameter_list|(
name|m
parameter_list|,
name|is_w
parameter_list|)
define|\
value|AnnotateRWLockReleased(__FILE__, __LINE__, m, is_w)
end_define

end_unit

