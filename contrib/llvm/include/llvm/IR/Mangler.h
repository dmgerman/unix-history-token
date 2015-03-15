begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/IR/Mangler.h - Self-contained name mangler ---------*- C++ -*-===//
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
name|LLVM_IR_MANGLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_MANGLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
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
name|Twine
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
name|DataLayout
modifier|*
name|DL
decl_stmt|;
comment|/// AnonGlobalIDs - We need to give global values the same name every time
comment|/// they are mangled.  This keeps track of the number we give to anonymous
comment|/// ones.
comment|///
name|mutable
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
name|mutable
name|unsigned
name|NextAnonGlobalID
decl_stmt|;
name|public
label|:
name|Mangler
argument_list|(
specifier|const
name|DataLayout
operator|*
name|DL
argument_list|)
operator|:
name|DL
argument_list|(
name|DL
argument_list|)
operator|,
name|NextAnonGlobalID
argument_list|(
literal|1
argument_list|)
block|{}
comment|/// Print the appropriate prefix and the specified global variable's name.
comment|/// If the global variable doesn't have a name, this fills in a unique name
comment|/// for the global.
name|void
name|getNameWithPrefix
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const GlobalValue *GV
argument_list|,
argument|bool CannotUsePrivateLabel
argument_list|)
specifier|const
expr_stmt|;
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
name|GlobalValue
operator|*
name|GV
argument_list|,
name|bool
name|CannotUsePrivateLabel
argument_list|)
decl|const
decl_stmt|;
comment|/// Print the appropriate prefix and the specified name as the global variable
comment|/// name. GVName must not be empty.
name|void
name|getNameWithPrefix
argument_list|(
name|raw_ostream
operator|&
name|OS
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
decl|const
decl_stmt|;
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
decl|const
decl_stmt|;
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

end_unit

