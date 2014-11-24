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
name|CODEGEN_ASMPRINTER_DWARFFILE_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFFILE_H__
end_define

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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
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
name|public
label|:
name|DwarfFile
argument_list|(
argument|AsmPrinter *AP
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
name|DwarfDebug
modifier|*
name|DD
parameter_list|,
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
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|StrSecSym
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

