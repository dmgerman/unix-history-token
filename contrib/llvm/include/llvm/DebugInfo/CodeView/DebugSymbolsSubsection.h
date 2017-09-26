begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugSymbolsSubsection.h --------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSYMBOLSSUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSYMBOLSSUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugSymbolsSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|public
operator|:
name|DebugSymbolsSubsectionRef
argument_list|()
operator|:
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind::Symbols
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsectionRef *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|Symbols
return|;
block|}
name|Error
name|initialize
argument_list|(
argument|BinaryStreamReader Reader
argument_list|)
block|;
name|CVSymbolArray
operator|::
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Records
operator|.
name|begin
argument_list|()
return|;
block|}
name|CVSymbolArray
operator|::
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Records
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|CVSymbolArray
name|Records
block|; }
decl_stmt|;
name|class
name|DebugSymbolsSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|DebugSymbolsSubsection
argument_list|()
operator|:
name|DebugSubsection
argument_list|(
argument|DebugSubsectionKind::Symbols
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|Symbols
return|;
block|}
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
name|override
block|;
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|void
name|addSymbol
argument_list|(
argument|CVSymbol Symbol
argument_list|)
block|;
name|private
operator|:
name|uint32_t
name|Length
operator|=
literal|0
block|;
name|std
operator|::
name|vector
operator|<
name|CVSymbol
operator|>
name|Records
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

