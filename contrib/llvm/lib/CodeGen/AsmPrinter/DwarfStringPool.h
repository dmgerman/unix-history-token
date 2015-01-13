begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfStringPool.h - Dwarf Debug Framework -*- C++ -*--===//
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
name|CODEGEN_ASMPRINTER_STRINGPOOL_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_STRINGPOOL_H__
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|// Collection of strings for this unit and assorted symbols.
comment|// A String->Symbol mapping of strings used by indirect
comment|// references.
name|class
name|DwarfStringPool
block|{
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|unsigned
operator|>
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|Pool
expr_stmt|;
name|StringRef
name|Prefix
decl_stmt|;
name|MCSymbol
modifier|*
name|SectionSymbol
decl_stmt|;
name|public
label|:
name|DwarfStringPool
argument_list|(
argument|BumpPtrAllocator&A
argument_list|,
argument|AsmPrinter&Asm
argument_list|,
argument|StringRef Prefix
argument_list|)
block|:
name|Pool
argument_list|(
name|A
argument_list|)
operator|,
name|Prefix
argument_list|(
name|Prefix
argument_list|)
operator|,
name|SectionSymbol
argument_list|(
argument|Asm.GetTempSymbol(Prefix)
argument_list|)
block|{}
name|void
name|emit
argument_list|(
name|AsmPrinter
operator|&
name|Asm
argument_list|,
specifier|const
name|MCSection
operator|*
name|StrSection
argument_list|,
specifier|const
name|MCSection
operator|*
name|OffsetSection
operator|=
name|nullptr
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|StrSecSym
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Returns the entry into the start of the pool.
name|MCSymbol
modifier|*
name|getSectionSymbol
parameter_list|()
function_decl|;
comment|/// \brief Returns an entry into the string pool with the given
comment|/// string text.
name|MCSymbol
modifier|*
name|getSymbol
parameter_list|(
name|AsmPrinter
modifier|&
name|Asm
parameter_list|,
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Returns the index into the string pool with the given
comment|/// string text.
name|unsigned
name|getIndex
parameter_list|(
name|AsmPrinter
modifier|&
name|Asm
parameter_list|,
name|StringRef
name|Str
parameter_list|)
function_decl|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Pool
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

