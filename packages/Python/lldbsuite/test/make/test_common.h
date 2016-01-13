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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PR_SET_PTRACER
argument_list|)
operator|&&
name|defined
argument_list|(
name|PR_SET_PTRACER_ANY
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

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

end_unit

