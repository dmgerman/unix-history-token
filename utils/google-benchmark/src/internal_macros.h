begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_INTERNAL_MACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_INTERNAL_MACROS_H_
end_define

begin_include
include|#
directive|include
file|"benchmark/macros.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
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
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPILER_CLANG
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|COMPILER_MSVC
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|COMPILER_GCC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_attributes
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_NORETURN
value|[[noreturn]]
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_NORETURN
value|__attribute__((noreturn))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|COMPILER_MSVC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_NORETURN
value|__declspec(noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_NORETURN
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
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_OS_CYGWIN
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_OS_WINDOWS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"TargetConditionals.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_OS_MAC
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_OS_MACOSX
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_OS_IPHONE
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_OS_IOS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_OS_FREEBSD
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_OS_LINUX
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__native_client__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_OS_NACL
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|EMSCRIPTEN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_OS_EMSCRIPTEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|cxx_exceptions
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cpp_exceptions
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__EXCEPTIONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_HAS_NO_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_INTERNAL_MACROS_H_
end_comment

end_unit

