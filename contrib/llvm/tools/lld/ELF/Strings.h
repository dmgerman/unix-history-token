begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Strings.h ------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_ELF_STRINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_STRINGS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GlobPattern.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|int
name|getPriority
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|bool
name|hasWildcard
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|parseHex
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
name|bool
name|isValidCIdentifier
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|StringRef
name|unquote
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|// This is a lazy version of StringRef. String size is computed lazily
comment|// when it is needed. It is more efficient than StringRef to instantiate
comment|// if you have a string whose size is unknown.
comment|//
comment|// ELF string tables contain a lot of null-terminated strings.
comment|// Most of them are not necessary for the linker because they are names
comment|// of local symbols and the linker doesn't use local symbol names for
comment|// name resolution. So, we use this class to represents strings read
comment|// from string tables.
name|class
name|StringRefZ
block|{
name|public
label|:
name|StringRefZ
argument_list|()
operator|:
name|Start
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
block|{}
name|StringRefZ
argument_list|(
argument|const char *S
argument_list|,
argument|size_t Size
argument_list|)
operator|:
name|Start
argument_list|(
name|S
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
comment|/*implicit*/
name|StringRefZ
argument_list|(
specifier|const
name|char
operator|*
name|S
argument_list|)
operator|:
name|Start
argument_list|(
name|S
argument_list|)
operator|,
name|Size
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
comment|/*implicit*/
name|StringRefZ
argument_list|(
argument|llvm::StringRef S
argument_list|)
operator|:
name|Start
argument_list|(
name|S
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Size
argument_list|(
argument|S.size()
argument_list|)
block|{}
name|operator
name|llvm
operator|::
name|StringRef
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Size
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
name|Size
operator|=
name|strlen
argument_list|(
name|Start
argument_list|)
expr_stmt|;
return|return
block|{
name|Start
block|,
name|Size
block|}
return|;
block|}
name|private
label|:
specifier|const
name|char
modifier|*
name|Start
decl_stmt|;
name|mutable
name|size_t
name|Size
decl_stmt|;
block|}
empty_stmt|;
comment|// This class represents multiple glob patterns.
name|class
name|StringMatcher
block|{
name|public
label|:
name|StringMatcher
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|StringMatcher
argument_list|(
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Pat
argument_list|)
decl_stmt|;
name|bool
name|match
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|GlobPattern
operator|>
name|Patterns
expr_stmt|;
block|}
empty_stmt|;
comment|// Returns a demangled C++ symbol name. If Name is not a mangled
comment|// name, it returns Optional::None.
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|demangle
argument_list|(
argument|StringRef Name
argument_list|)
expr_stmt|;
specifier|inline
name|StringRef
name|toStringRef
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Arr
argument_list|)
block|{
return|return
block|{
operator|(
specifier|const
name|char
operator|*
operator|)
name|Arr
operator|.
name|data
argument_list|()
block|,
name|Arr
operator|.
name|size
argument_list|()
block|}
return|;
block|}
specifier|inline
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|toArrayRef
argument_list|(
argument|StringRef S
argument_list|)
block|{
return|return
block|{
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|S
operator|.
name|data
argument_list|()
block|,
name|S
operator|.
name|size
argument_list|()
block|}
return|;
block|}
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

