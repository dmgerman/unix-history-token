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
comment|//  Defines macros used within libunwind project.
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

begin_include
include|#
directive|include
file|<stdlib.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_DWARF_EH__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

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
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_DWARF_INDEX
value|1
end_define

begin_else
else|#
directive|else
end_else

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
value|0
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FIXME: these macros are not correct for COFF targets
end_comment

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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__USING_SJLJ_EXCEPTIONS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_SJLJ_APIS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_SJLJ_APIS
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
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_FRAME_APIS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_SUPPORT_FRAME_APIS
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
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__riscv
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_ZERO_COST_APIS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_BUILD_ZERO_COST_APIS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_LIBUNWIND_ABORT
parameter_list|(
name|msg
parameter_list|)
define|\
value|do {                                                                         \     fprintf(stderr, "libunwind: %s %s:%d - %s\n", __func__, __FILE__,          \             __LINE__, msg);                                                    \     fflush(stderr);                                                            \     abort();                                                                   \   } while (0)
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
value|fprintf(stderr, "libunwind: " msg "\n", __VA_ARGS__)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// Used to fit UnwindCursor and Registers_xxx types against unw_context_t /
end_comment

begin_comment
comment|// unw_cursor_t sized memory blocks.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBUNWIND_IS_NATIVE_ONLY
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMP_OP
value|==
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMP_OP
value|<
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|typename
name|_Type
operator|,
name|typename
name|_Mem
operator|>
expr|struct
name|check_fit
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|blk_count
block|{
specifier|static
specifier|const
name|size_t
name|count
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|-
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
block|;   }
block|;
specifier|static
specifier|const
name|bool
name|does_fit
operator|=
operator|(
name|blk_count
operator|<
name|_Type
operator|>
operator|::
name|count
name|COMP_OP
name|blk_count
operator|<
name|_Mem
operator|>
operator|::
name|count
operator|)
block|; }
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|COMP_OP
end_undef

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
comment|// LIBUNWIND_CONFIG_H
end_comment

end_unit

