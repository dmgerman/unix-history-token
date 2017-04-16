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
file|"llvm/IR/GlobalValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
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
name|Triple
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Mangler
block|{
comment|/// We need to give global values the same name every time they are mangled.
comment|/// This keeps track of the number we give to anonymous ones.
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
name|public
label|:
comment|/// Print the appropriate prefix and the specified global variable's name.
comment|/// If the global variable doesn't have a name, this fills in a unique name
comment|/// for the global.
name|void
name|getNameWithPrefix
argument_list|(
name|raw_ostream
operator|&
name|OS
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
specifier|static
name|void
name|getNameWithPrefix
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Twine
modifier|&
name|GVName
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
specifier|static
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
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
name|void
name|emitLinkerFlagsForGlobalCOFF
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|Mangler
modifier|&
name|Mangler
parameter_list|)
function_decl|;
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

