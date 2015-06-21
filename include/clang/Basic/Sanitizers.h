begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Sanitizers.h - C Language Family Language Options ------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::SanitizerKind enum.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_SANITIZERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SANITIZERS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
typedef|typedef
name|uint64_t
name|SanitizerMask
typedef|;
name|namespace
name|SanitizerKind
block|{
comment|// Assign ordinals to possible values of -fsanitize= flag, which we will use as
comment|// bit positions.
enum|enum
name|SanitizerOrdinal
enum|:
name|uint64_t
block|{
define|#
directive|define
name|SANITIZER
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
value|SO_##ID,
define|#
directive|define
name|SANITIZER_GROUP
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|ALIAS
parameter_list|)
value|SO_##ID##Group,
include|#
directive|include
file|"clang/Basic/Sanitizers.def"
name|SO_Count
block|}
enum|;
comment|// Define the set of sanitizer kinds, as well as the set of sanitizers each
comment|// sanitizer group expands into.
define|#
directive|define
name|SANITIZER
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
define|\
value|const SanitizerMask ID = 1ULL<< SO_##ID;
define|#
directive|define
name|SANITIZER_GROUP
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|ALIAS
parameter_list|)
define|\
value|const SanitizerMask ID = ALIAS; \   const SanitizerMask ID##Group = 1ULL<< SO_##ID##Group;
include|#
directive|include
file|"clang/Basic/Sanitizers.def"
block|}
struct|struct
name|SanitizerSet
block|{
name|SanitizerSet
argument_list|()
expr_stmt|;
comment|/// \brief Check if a certain (single) sanitizer is enabled.
name|bool
name|has
argument_list|(
name|SanitizerMask
name|K
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if one or more sanitizers are enabled.
name|bool
name|hasOneOf
argument_list|(
name|SanitizerMask
name|K
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Enable or disable a certain (single) sanitizer.
name|void
name|set
parameter_list|(
name|SanitizerMask
name|K
parameter_list|,
name|bool
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Disable all sanitizers.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// \brief Returns true if at least one sanitizer is enabled.
name|bool
name|empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Bitmask of enabled sanitizers.
name|SanitizerMask
name|Mask
decl_stmt|;
block|}
struct|;
comment|/// Parse a single value from a -fsanitize= or -fno-sanitize= value list.
comment|/// Returns a non-zero SanitizerMask, or \c 0 if \p Value is not known.
name|SanitizerMask
name|parseSanitizerValue
parameter_list|(
name|StringRef
name|Value
parameter_list|,
name|bool
name|AllowGroups
parameter_list|)
function_decl|;
comment|/// For each sanitizer group bit set in \p Kinds, set the bits for sanitizers
comment|/// this group enables.
name|SanitizerMask
name|expandSanitizerGroups
parameter_list|(
name|SanitizerMask
name|Kinds
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

