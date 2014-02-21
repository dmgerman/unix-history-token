begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCObjectSymbolizer.h --------------------------------------===//
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
comment|// This file declares the MCObjectSymbolizer class, an MCSymbolizer that is
end_comment

begin_comment
comment|// backed by an object::ObjectFile.
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
name|LLVM_MC_MCOBJECTSYMBOLIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCOBJECTSYMBOLIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbolizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCRelocationInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief An ObjectFile-backed symbolizer.
name|class
name|MCObjectSymbolizer
range|:
name|public
name|MCSymbolizer
block|{
name|protected
operator|:
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
block|;
comment|// Map a load address to the first relocation that applies there. As far as I
comment|// know, if there are several relocations at the exact same address, they are
comment|// related and the others can be determined from the first that was found in
comment|// the relocation table. For instance, on x86-64 mach-o, a SUBTRACTOR
comment|// relocation (referencing the minuend symbol) is followed by an UNSIGNED
comment|// relocation (referencing the subtrahend symbol).
specifier|const
name|object
operator|::
name|RelocationRef
operator|*
name|findRelocationAt
argument_list|(
argument|uint64_t Addr
argument_list|)
block|;
specifier|const
name|object
operator|::
name|SectionRef
operator|*
name|findSectionContaining
argument_list|(
argument|uint64_t Addr
argument_list|)
block|;
name|MCObjectSymbolizer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|OwningPtr
operator|<
name|MCRelocationInfo
operator|>
operator|&
name|RelInfo
argument_list|,
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|)
block|;
name|public
operator|:
comment|/// \name Overridden MCSymbolizer methods:
comment|/// @{
name|bool
name|tryAddingSymbolicOperand
argument_list|(
argument|MCInst&MI
argument_list|,
argument|raw_ostream&cStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
argument_list|,
argument|bool IsBranch
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t InstSize
argument_list|)
block|;
name|void
name|tryAddingPcLoadReferenceComment
argument_list|(
argument|raw_ostream&cStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
argument_list|)
block|;
comment|/// @}
comment|/// \brief Look for an external function symbol at \p Addr.
comment|/// (References through the ELF PLT, Mach-O stubs, and similar).
comment|/// \returns An MCExpr representing the external symbol, or 0 if not found.
name|virtual
name|StringRef
name|findExternalFunctionAt
argument_list|(
argument|uint64_t Addr
argument_list|)
block|;
comment|/// \brief Create an object symbolizer for \p Obj.
specifier|static
name|MCObjectSymbolizer
operator|*
name|createObjectSymbolizer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|OwningPtr
operator|<
name|MCRelocationInfo
operator|>
operator|&
name|RelInfo
argument_list|,
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|DenseMap
operator|<
name|uint64_t
operator|,
name|object
operator|::
name|RelocationRef
operator|>
name|AddrToRelocMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|object
operator|::
name|SectionRef
operator|>
name|SortedSectionList
expr_stmt|;
name|SortedSectionList
name|SortedSections
decl_stmt|;
name|AddrToRelocMap
name|AddrToReloc
decl_stmt|;
name|void
name|buildSectionList
parameter_list|()
function_decl|;
name|void
name|buildRelocationByAddrMap
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

