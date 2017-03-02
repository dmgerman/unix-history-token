begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolDumpDelegate.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPDELEGATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPDELEGATE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorDelegate.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|SymbolDumpDelegate
range|:
name|public
name|SymbolVisitorDelegate
block|{
name|public
operator|:
operator|~
name|SymbolDumpDelegate
argument_list|()
name|override
operator|=
expr|default
block|;
name|virtual
name|void
name|printRelocatedField
argument_list|(
argument|StringRef Label
argument_list|,
argument|uint32_t RelocOffset
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|StringRef *RelocSym = nullptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|printBinaryBlockWithRelocs
argument_list|(
argument|StringRef Label
argument_list|,
argument|ArrayRef<uint8_t> Block
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPDELEGATE_H
end_comment

end_unit

