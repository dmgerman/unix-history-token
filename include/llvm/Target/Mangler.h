begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Mangler.h - Self-contained name mangler ----*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// Unified name mangler for various backends.
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
name|LLVM_SUPPORT_MANGLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MANGLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|Mangler
block|{
name|public
label|:
enum|enum
name|ManglerPrefixTy
block|{
name|Default
block|,
comment|///< Emit default string before each symbol.
name|Private
block|,
comment|///< Emit "private" prefix before each symbol.
name|LinkerPrivate
comment|///< Emit "linker private" prefix before each symbol.
block|}
enum|;
name|private
label|:
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
decl_stmt|;
comment|/// AnonGlobalIDs - We need to give global values the same name every time
comment|/// they are mangled.  This keeps track of the number we give to anonymous
comment|/// ones.
comment|///
name|DenseMap
operator|<
specifier|const
name|GlobalValue
operator|*
operator|,
name|unsigned
operator|>
name|AnonGlobalIDs
expr_stmt|;
comment|/// NextAnonGlobalID - This simple counter is used to unique value names.
comment|///
name|unsigned
name|NextAnonGlobalID
decl_stmt|;
name|public
label|:
comment|// Mangler ctor - if a prefix is specified, it will be prepended onto all
comment|// symbols.
name|Mangler
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|mai
argument_list|)
operator|:
name|MAI
argument_list|(
name|mai
argument_list|)
operator|,
name|NextAnonGlobalID
argument_list|(
literal|1
argument_list|)
block|{}
comment|/// getNameWithPrefix - Fill OutName with the name of the appropriate prefix
comment|/// and the specified global variable's name.  If the global variable doesn't
comment|/// have a name, this fills in a unique name for the global.
name|void
name|getNameWithPrefix
argument_list|(
argument|SmallVectorImpl<char>&OutName
argument_list|,
argument|const GlobalValue *GV
argument_list|,
argument|bool isImplicitlyPrivate
argument_list|)
expr_stmt|;
comment|/// getNameWithPrefix - Fill OutName with the name of the appropriate prefix
comment|/// and the specified name as the global variable name.  GVName must not be
comment|/// empty.
name|void
name|getNameWithPrefix
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OutName
argument_list|,
specifier|const
name|Twine
operator|&
name|GVName
argument_list|,
name|ManglerPrefixTy
name|PrefixTy
operator|=
name|Mangler
operator|::
name|Default
argument_list|)
decl_stmt|;
comment|/// getNameWithPrefix - Return the name of the appropriate prefix
comment|/// and the specified global variable's name.  If the global variable doesn't
comment|/// have a name, this fills in a unique name for the global.
name|std
operator|::
name|string
name|getNameWithPrefix
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|bool isImplicitlyPrivate = false
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_MANGLER_H
end_comment

end_unit

