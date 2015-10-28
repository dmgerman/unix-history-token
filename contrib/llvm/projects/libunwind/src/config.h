begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------- config.h -------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Defines macros used within libuwind project.
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
name|LIBUNWIND_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|LIBUNWIND_CONFIG_H
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// Define static_assert() unless already defined by compiler.
end_comment

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
name|__x
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
operator|!
operator|(
name|__has_feature
argument_list|(
name|cxx_static_assert
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|static_assert
argument_list|)
end_if

begin_define
define|#
directive|define
name|static_assert
parameter_list|(
name|__b
parameter_list|,
name|__m
parameter_list|)
define|\
value|extern int compile_time_assert_failed[ ( __b ) ? 1 : -1 ]  \                                                   __attribute__( ( unused ) );
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Platform specific configuration defines.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<Availability.h>
end_include

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
name|__assert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_ZERO_COST_APIS
value|(defined(__i386__) || \                                            defined(__x86_64__) || \                                            defined(__arm64__))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_SJLJ_APIS
value|defined(__arm__)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_FRAME_APIS
value|(defined(__i386__) || \                                            defined(__x86_64__))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_EXPORT
value|__attribute__((visibility("default")))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_HIDDEN
value|__attribute__((visibility("hidden")))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_LOG
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
value|fprintf(stderr, "libuwind: " msg, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_ABORT
parameter_list|(
name|msg
parameter_list|)
value|__assert_rtn(__func__, __FILE__, __LINE__, msg)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FOR_DYLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_COMPACT_UNWIND
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_UNWIND
value|0
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_INDEX
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_COMPACT_UNWIND
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_UNWIND
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_INDEX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
unit|static
specifier|inline
name|void
name|assert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
specifier|inline
name|void
name|assert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"libunwind: %s %s:%d - %s\n"
argument_list|,
name|func
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_ZERO_COST_APIS
value|(defined(__i386__) || \                                            defined(__x86_64__) || \                                            defined(__arm__) || \                                            defined(__aarch64__))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_SJLJ_APIS
value|0
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_FRAME_APIS
value|(defined(__i386__) || \                                            defined(__x86_64__))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_EXPORT
value|__attribute__((visibility("default")))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_HIDDEN
value|__attribute__((visibility("hidden")))
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_LOG
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
value|fprintf(stderr, "libuwind: " msg, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_ABORT
parameter_list|(
name|msg
parameter_list|)
value|assert_rtn(__func__, __FILE__, __LINE__, msg)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_COMPACT_UNWIND
value|0
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_UNWIND
value|!defined(__arm__) || \                                           defined(__ARM_DWARF_EH__)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_INDEX
value|_LIBUNWIND_SUPPORT_DWARF_UNWIND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Macros that define away in non-Debug builds
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|_LIBUNWIND_DEBUG_LOG
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACE_API
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACING_UNWINDING
value|0
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACE_UNWINDING
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_LOG_NON_ZERO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

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
specifier|extern
name|bool
name|logAPIs
parameter_list|()
function_decl|;
specifier|extern
name|bool
name|logUnwinding
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

begin_define
define|#
directive|define
name|_LIBUNWIND_DEBUG_LOG
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
value|_LIBUNWIND_LOG(msg, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_LOG_NON_ZERO
parameter_list|(
name|x
parameter_list|)
define|\
value|do { \               int _err = x; \               if ( _err != 0 ) \                 _LIBUNWIND_LOG("" #x "=%d in %s", _err, __FUNCTION__); \              } while (0)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACE_API
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \               if ( logAPIs() ) _LIBUNWIND_LOG(msg, __VA_ARGS__); \             } while(0)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACE_UNWINDING
parameter_list|(
name|msg
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \               if ( logUnwinding() ) _LIBUNWIND_LOG(msg, __VA_ARGS__); \             } while(0)
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TRACING_UNWINDING
value|logUnwinding()
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
comment|// LIBUNWIND_CONFIG_H
end_comment

end_unit

