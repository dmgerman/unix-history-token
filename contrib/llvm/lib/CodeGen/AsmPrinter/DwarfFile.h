begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfFile.h - Dwarf Debug Framework -------*- C++ -*--===//
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFFILE_H
end_define

begin_include
include|#
directive|include
file|"AddressPool.h"
end_include

begin_include
include|#
directive|include
file|"DwarfStringPool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|AsmPrinter
decl_stmt|;
name|class
name|DbgVariable
decl_stmt|;
name|class
name|DwarfUnit
decl_stmt|;
name|class
name|DIEAbbrev
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|DIE
decl_stmt|;
name|class
name|DISubprogram
decl_stmt|;
name|class
name|LexicalScope
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|DwarfFile
block|{
comment|// Target of Dwarf emission, used for sizing of abbreviations.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
name|DwarfDebug
modifier|&
name|DD
decl_stmt|;
comment|// Used to uniquely define abbreviations.
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
name|AbbreviationsSet
expr_stmt|;
comment|// A list of all the unique abbreviations in use.
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
name|Abbreviations
expr_stmt|;
comment|// A pointer to all units in the section.
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfUnit
operator|>
operator|,
literal|1
operator|>
name|CUs
expr_stmt|;
name|DwarfStringPool
name|StrPool
decl_stmt|;
comment|// Collection of dbg variables of a scope.
name|DenseMap
operator|<
name|LexicalScope
operator|*
operator|,
name|SmallVector
operator|<
name|DbgVariable
operator|*
operator|,
literal|8
operator|>>
name|ScopeVariables
expr_stmt|;
comment|// Collection of abstract subprogram DIEs.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|AbstractSPDies
expr_stmt|;
comment|/// Maps MDNodes for type system with the corresponding DIEs. These DIEs can
comment|/// be shared across CUs, that is why we keep the map here instead
comment|/// of in DwarfCompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|MDTypeNodeToDieMap
expr_stmt|;
name|public
label|:
name|DwarfFile
argument_list|(
argument|AsmPrinter *AP
argument_list|,
argument|DwarfDebug&DD
argument_list|,
argument|StringRef Pref
argument_list|,
argument|BumpPtrAllocator&DA
argument_list|)
empty_stmt|;
operator|~
name|DwarfFile
argument_list|()
expr_stmt|;
specifier|const
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfUnit
operator|>>
operator|&
name|getUnits
argument_list|()
block|{
return|return
name|CUs
return|;
block|}
comment|/// \brief Compute the size and offset of a DIE given an incoming Offset.
name|unsigned
name|computeSizeAndOffset
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Compute the size and offset of all the DIEs.
name|void
name|computeSizeAndOffsets
parameter_list|()
function_decl|;
comment|/// \brief Define a unique number for the abbreviation.
name|void
name|assignAbbrevNumber
parameter_list|(
name|DIEAbbrev
modifier|&
name|Abbrev
parameter_list|)
function_decl|;
comment|/// \brief Add a unit to the list of CUs.
name|void
name|addUnit
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfUnit
operator|>
name|U
argument_list|)
decl_stmt|;
comment|/// \brief Emit all of the units to the section listed with the given
comment|/// abbreviation section.
name|void
name|emitUnits
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|ASectionSym
parameter_list|)
function_decl|;
comment|/// \brief Emit a set of abbreviations to the specific section.
name|void
name|emitAbbrevs
parameter_list|(
specifier|const
name|MCSection
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Emit all of the strings to the section given.
name|void
name|emitStrings
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|StrSection
parameter_list|,
specifier|const
name|MCSection
modifier|*
name|OffsetSection
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Returns the string pool.
name|DwarfStringPool
modifier|&
name|getStringPool
parameter_list|()
block|{
return|return
name|StrPool
return|;
block|}
name|void
name|addScopeVariable
parameter_list|(
name|LexicalScope
modifier|*
name|LS
parameter_list|,
name|DbgVariable
modifier|*
name|Var
parameter_list|)
function_decl|;
name|DenseMap
operator|<
name|LexicalScope
operator|*
operator|,
name|SmallVector
operator|<
name|DbgVariable
operator|*
operator|,
literal|8
operator|>>
operator|&
name|getScopeVariables
argument_list|()
block|{
return|return
name|ScopeVariables
return|;
block|}
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
operator|&
name|getAbstractSPDies
argument_list|()
block|{
return|return
name|AbstractSPDies
return|;
block|}
name|void
name|insertDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|TypeMD
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|)
block|{
name|MDTypeNodeToDieMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|TypeMD
argument_list|,
name|Die
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|DIE
modifier|*
name|getDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|TypeMD
parameter_list|)
block|{
return|return
name|MDTypeNodeToDieMap
operator|.
name|lookup
argument_list|(
name|TypeMD
argument_list|)
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

