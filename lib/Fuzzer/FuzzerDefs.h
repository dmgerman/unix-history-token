begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerDefs.h - Internal header for the Fuzzer ------------*- C++ -* ===//
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
comment|// Basic definitions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_DEFS_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Platform detection.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|LIBFUZZER_APPLE
value|0
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_LINUX
value|1
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_WINDOWS
value|0
end_define

begin_elif
elif|#
directive|elif
name|__APPLE__
end_elif

begin_define
define|#
directive|define
name|LIBFUZZER_APPLE
value|1
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_WINDOWS
value|0
end_define

begin_elif
elif|#
directive|elif
name|_WIN32
end_elif

begin_define
define|#
directive|define
name|LIBFUZZER_APPLE
value|0
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|LIBFUZZER_WINDOWS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Support for your platform has not been implemented"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__has_attribute
end_ifndef

begin_define
define|#
directive|define
name|__has_attribute
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIBFUZZER_POSIX
value|LIBFUZZER_APPLE || LIBFUZZER_LINUX
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64
end_ifdef

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|target
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_TARGET_POPCNT
value|__attribute__((target("popcnt")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_TARGET_POPCNT
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
name|ATTRIBUTE_TARGET_POPCNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_comment
comment|// avoid gcc warning.
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|no_sanitize
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_MEMORY
value|__attribute__((no_sanitize("memory")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_MEMORY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__attribute__((always_inline))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_MEMORY
end_define

begin_define
define|#
directive|define
name|ALWAYS_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __clang__
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ADDRESS
value|__attribute__((no_sanitize_address))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ALL
value|ATTRIBUTE_NO_SANITIZE_ADDRESS
end_define

begin_elif
elif|#
directive|elif
name|__has_feature
argument_list|(
name|memory_sanitizer
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ALL
value|ATTRIBUTE_NO_SANITIZE_MEMORY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ALL
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
name|ATTRIBUTE_NO_SANITIZE_ALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LIBFUZZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_INTERFACE
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_INTERFACE
value|__attribute__((visibility("default")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|fuzzer
block|{
name|template
operator|<
name|class
name|T
operator|>
name|T
name|Min
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
name|Max
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|>
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|class
name|Random
decl_stmt|;
name|class
name|Dictionary
decl_stmt|;
name|class
name|DictionaryEntry
decl_stmt|;
name|class
name|MutationDispatcher
decl_stmt|;
struct_decl|struct
name|FuzzingOptions
struct_decl|;
name|class
name|InputCorpus
decl_stmt|;
struct_decl|struct
name|InputInfo
struct_decl|;
struct_decl|struct
name|ExternalFunctions
struct_decl|;
comment|// Global interface to functions that may or may not be available.
specifier|extern
name|ExternalFunctions
modifier|*
name|EF
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|Unit
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Unit
operator|>
name|UnitVector
expr_stmt|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|UserCallback
function_decl|)
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
name|int
name|FuzzerDriver
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|,
name|UserCallback
name|Callback
parameter_list|)
function_decl|;
struct|struct
name|ScopedDoingMyOwnMemOrStr
block|{
name|ScopedDoingMyOwnMemOrStr
argument_list|()
block|{
name|DoingMyOwnMemOrStr
operator|++
expr_stmt|;
block|}
operator|~
name|ScopedDoingMyOwnMemOrStr
argument_list|()
block|{
name|DoingMyOwnMemOrStr
operator|--
block|; }
specifier|static
name|int
name|DoingMyOwnMemOrStr
expr_stmt|;
block|}
struct|;
specifier|inline
name|uint8_t
name|Bswap
parameter_list|(
name|uint8_t
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
specifier|inline
name|uint16_t
name|Bswap
parameter_list|(
name|uint16_t
name|x
parameter_list|)
block|{
return|return
name|__builtin_bswap16
argument_list|(
name|x
argument_list|)
return|;
block|}
specifier|inline
name|uint32_t
name|Bswap
parameter_list|(
name|uint32_t
name|x
parameter_list|)
block|{
return|return
name|__builtin_bswap32
argument_list|(
name|x
argument_list|)
return|;
block|}
specifier|inline
name|uint64_t
name|Bswap
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|__builtin_bswap64
argument_list|(
name|x
argument_list|)
return|;
block|}
name|uint8_t
modifier|*
name|ExtraCountersBegin
parameter_list|()
function_decl|;
name|uint8_t
modifier|*
name|ExtraCountersEnd
parameter_list|()
function_decl|;
name|void
name|ClearExtraCounters
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_DEFS_H
end_comment

end_unit

