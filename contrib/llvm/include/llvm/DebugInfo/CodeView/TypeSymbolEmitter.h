begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeSymbolEmitter.h --------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_CODEVIEW_TYPESYMBOLEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPESYMBOLEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeSymbolEmitter
block|{
name|private
label|:
name|TypeSymbolEmitter
argument_list|(
specifier|const
name|TypeSymbolEmitter
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|TypeSymbolEmitter
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TypeSymbolEmitter
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|protected
label|:
name|TypeSymbolEmitter
argument_list|()
block|{}
name|public
label|:
name|virtual
operator|~
name|TypeSymbolEmitter
argument_list|()
block|{}
name|public
operator|:
name|virtual
name|void
name|writeUserDefinedType
argument_list|(
argument|TypeIndex TI
argument_list|,
argument|StringRef Name
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

