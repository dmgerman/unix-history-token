begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This header is included in all the test programs (C and C++) and provides a
end_comment

begin_comment
comment|// hook for dealing with platform-specifics.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|COMPILING_LLDB_TEST_DLL
end_ifdef

begin_define
define|#
directive|define
name|LLDB_TEST_API
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_TEST_API
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_TEST_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_HAS_EXCEPTIONS
operator|==
literal|0
operator|)
end_if

begin_comment
comment|// Compiling MSVC libraries with _HAS_EXCEPTIONS=0, eliminates most but not all
end_comment

begin_comment
comment|// calls to __uncaught_exception.  Unfortunately, it does seem to eliminate
end_comment

begin_comment
comment|// the delcaration of __uncaught_excpeiton.  Including<eh.h> ensures that it is
end_comment

begin_comment
comment|// declared.  This may not be necessary after MSVC 12.
end_comment

begin_include
include|#
directive|include
file|<eh.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_PRETTY_FUNCTION
value|__FUNCSIG__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_PRETTY_FUNCTION
value|LLVM_PRETTY_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// On some systems (e.g., some versions of linux) it is not possible to attach to a process
end_comment

begin_comment
comment|// without it giving us special permissions. This defines the lldb_enable_attach macro, which
end_comment

begin_comment
comment|// should perform any such actions, if needed by the platform. This is a macro instead of a
end_comment

begin_comment
comment|// function to avoid the need for complex linking of the test programs.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_comment
comment|// Android API<= 16 does not have these defined.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PR_SET_PTRACER
end_ifndef

begin_define
define|#
directive|define
name|PR_SET_PTRACER
value|0x59616d61
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PR_SET_PTRACER_ANY
end_ifndef

begin_define
define|#
directive|define
name|PR_SET_PTRACER_ANY
value|((unsigned long)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// For now we execute on best effort basis.  If this fails for some reason, so be it.
end_comment

begin_define
define|#
directive|define
name|lldb_enable_attach
parameter_list|()
define|\
value|do                                                                                \     {                                                                                 \         const int prctl_result = prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY, 0, 0, 0);  \         (void)prctl_result;                                                           \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// not linux
end_comment

begin_define
define|#
directive|define
name|lldb_enable_attach
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|LLDB_USING_LIBSTDCPP
argument_list|)
end_if

begin_comment
comment|// on Darwin, libstdc++ is missing<atomic>, so this would cause any test to fail building
end_comment

begin_comment
comment|// since this header file is being included in every C-family test case, we need to not include it
end_comment

begin_comment
comment|// on Darwin, most tests use libc++ by default, so this will only affect tests that explicitly require libstdc++
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_comment
comment|// Note that although hogging the CPU while waiting for a variable to change
end_comment

begin_comment
comment|// would be terrible in production code, it's great for testing since it
end_comment

begin_comment
comment|// avoids a lot of messy context switching to get multiple threads synchronized.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|atomic
operator|<
name|int
operator|>
name|pseudo_barrier_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|pseudo_barrier_wait
parameter_list|(
name|barrier
parameter_list|)
define|\
value|do                                      \     {                                       \         --(barrier);                        \         while ((barrier).load()> 0)        \             ;                               \     } while (0)
end_define

begin_define
define|#
directive|define
name|pseudo_barrier_init
parameter_list|(
name|barrier
parameter_list|,
name|count
parameter_list|)
define|\
value|do                                      \     {                                       \         (barrier) = (count);                \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__APPLE__)&& defined(LLDB_USING_LIBSTDCPP)
end_comment

end_unit

