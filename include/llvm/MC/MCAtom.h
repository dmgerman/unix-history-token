begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAtom.h ----------------------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCAtom class, which is used to
end_comment

begin_comment
comment|// represent a contiguous region in a decoded object that is uniformly data or
end_comment

begin_comment
comment|// instructions.
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
name|LLVM_MC_MCATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCATOM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|MCModule
decl_stmt|;
name|class
name|MCAtom
decl_stmt|;
name|class
name|MCTextAtom
decl_stmt|;
name|class
name|MCDataAtom
decl_stmt|;
comment|/// \brief Represents a contiguous range of either instructions (a TextAtom)
comment|/// or data (a DataAtom).  Address ranges are expressed as _closed_ intervals.
name|class
name|MCAtom
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MCAtom
argument_list|()
block|{}
expr|enum
name|AtomKind
block|{
name|TextAtom
block|,
name|DataAtom
block|}
expr_stmt|;
name|AtomKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Get the start address of the atom.
name|uint64_t
name|getBeginAddr
argument_list|()
specifier|const
block|{
return|return
name|Begin
return|;
block|}
comment|/// \brief Get the end address, i.e. the last one inside the atom.
name|uint64_t
name|getEndAddr
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
comment|/// \name Atom modification methods:
comment|/// When modifying a TextAtom, keep instruction boundaries in mind.
comment|/// For instance, split must me given the start address of an instruction.
comment|/// @{
comment|/// \brief Splits the atom in two at a given address.
comment|/// \param SplitPt Address at which to start a new atom, splitting this one.
comment|/// \returns The newly created atom starting at \p SplitPt.
name|virtual
name|MCAtom
modifier|*
name|split
parameter_list|(
name|uint64_t
name|SplitPt
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Truncates an atom, discarding everything after \p TruncPt.
comment|/// \param TruncPt Last byte address to be contained in this atom.
name|virtual
name|void
name|truncate
parameter_list|(
name|uint64_t
name|TruncPt
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @}
comment|/// \name Naming:
comment|///
comment|/// This is mostly for display purposes, and may contain anything that hints
comment|/// at what the atom contains: section or symbol name, BB start address, ..
comment|/// @{
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|void
name|setName
parameter_list|(
name|StringRef
name|NewName
parameter_list|)
block|{
name|Name
operator|=
name|NewName
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
comment|/// @}
name|protected
label|:
specifier|const
name|AtomKind
name|Kind
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|MCModule
modifier|*
name|Parent
decl_stmt|;
name|uint64_t
name|Begin
decl_stmt|,
name|End
decl_stmt|;
name|friend
name|class
name|MCModule
decl_stmt|;
name|MCAtom
argument_list|(
argument|AtomKind K
argument_list|,
argument|MCModule *P
argument_list|,
argument|uint64_t B
argument_list|,
argument|uint64_t E
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|Name
argument_list|(
literal|"(unknown)"
argument_list|)
operator|,
name|Parent
argument_list|(
name|P
argument_list|)
operator|,
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|End
argument_list|(
argument|E
argument_list|)
block|{ }
comment|/// \name Atom remapping helpers
comment|/// @{
comment|/// \brief Remap the atom, using the given range, updating Begin/End.
comment|/// One or both of the bounds can remain the same, but overlapping with other
comment|/// atoms in the module is still forbidden.
name|void
name|remap
argument_list|(
argument|uint64_t NewBegin
argument_list|,
argument|uint64_t NewEnd
argument_list|)
expr_stmt|;
comment|/// \brief Remap the atom to prepare for a truncation at TruncPt.
comment|/// Equivalent to:
comment|/// \code
comment|///   // Bound checks
comment|///   remap(Begin, TruncPt);
comment|/// \endcode
name|void
name|remapForTruncate
parameter_list|(
name|uint64_t
name|TruncPt
parameter_list|)
function_decl|;
comment|/// \brief Remap the atom to prepare for a split at SplitPt.
comment|/// The bounds for the resulting atoms are returned in {L,R}{Begin,End}.
comment|/// The current atom is truncated to \p LEnd.
name|void
name|remapForSplit
parameter_list|(
name|uint64_t
name|SplitPt
parameter_list|,
name|uint64_t
modifier|&
name|LBegin
parameter_list|,
name|uint64_t
modifier|&
name|LEnd
parameter_list|,
name|uint64_t
modifier|&
name|RBegin
parameter_list|,
name|uint64_t
modifier|&
name|REnd
parameter_list|)
function_decl|;
comment|/// @}
block|}
empty_stmt|;
comment|/// \name Text atom
comment|/// @{
comment|/// \brief An entry in an MCTextAtom: a disassembled instruction.
comment|/// NOTE: Both the Address and Size field are actually redundant when taken in
comment|/// the context of the text atom, and may better be exposed in an iterator
comment|/// instead of stored in the atom, which would replace this class.
name|class
name|MCDecodedInst
block|{
name|public
label|:
name|MCInst
name|Inst
decl_stmt|;
name|uint64_t
name|Address
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|MCDecodedInst
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|uint64_t Address
argument_list|,
argument|uint64_t Size
argument_list|)
block|:
name|Inst
argument_list|(
name|Inst
argument_list|)
operator|,
name|Address
argument_list|(
name|Address
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief An atom consisting of disassembled instructions.
name|class
name|MCTextAtom
range|:
name|public
name|MCAtom
block|{
name|private
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCDecodedInst
operator|>
name|InstListTy
expr_stmt|;
name|InstListTy
name|Insts
decl_stmt|;
comment|/// \brief The address of the next appended instruction, i.e., the
comment|/// address immediately after the last instruction in the atom.
name|uint64_t
name|NextInstAddress
decl_stmt|;
name|public
label|:
comment|/// Append an instruction, expanding the atom if necessary.
name|void
name|addInst
parameter_list|(
specifier|const
name|MCInst
modifier|&
name|Inst
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
function_decl|;
comment|/// \name Instruction list access
comment|/// @{
typedef|typedef
name|InstListTy
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|end
argument_list|()
return|;
block|}
specifier|const
name|MCDecodedInst
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|back
argument_list|()
return|;
block|}
specifier|const
name|MCDecodedInst
modifier|&
name|at
argument_list|(
name|size_t
name|n
argument_list|)
decl|const
block|{
return|return
name|Insts
operator|.
name|at
argument_list|(
name|n
argument_list|)
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// \name Atom type specific split/truncate logic.
comment|/// @{
name|MCTextAtom
modifier|*
name|split
argument_list|(
name|uint64_t
name|SplitPt
argument_list|)
name|LLVM_OVERRIDE
decl_stmt|;
name|void
name|truncate
argument_list|(
name|uint64_t
name|TruncPt
argument_list|)
name|LLVM_OVERRIDE
decl_stmt|;
comment|/// @}
comment|// Class hierarchy.
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCAtom
modifier|*
name|A
parameter_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|TextAtom
return|;
block|}
name|private
label|:
name|friend
name|class
name|MCModule
decl_stmt|;
comment|// Private constructor - only callable by MCModule
name|MCTextAtom
argument_list|(
argument|MCModule *P
argument_list|,
argument|uint64_t Begin
argument_list|,
argument|uint64_t End
argument_list|)
block|:
name|MCAtom
argument_list|(
name|TextAtom
argument_list|,
name|P
argument_list|,
name|Begin
argument_list|,
name|End
argument_list|)
operator|,
name|NextInstAddress
argument_list|(
argument|Begin
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Data atom
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief An entry in an MCDataAtom.
end_comment

begin_comment
comment|// NOTE: This may change to a more complex type in the future.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|MCData
typedef|;
end_typedef

begin_comment
comment|/// \brief An atom consising of a sequence of bytes.
end_comment

begin_decl_stmt
name|class
name|MCDataAtom
range|:
name|public
name|MCAtom
block|{
name|std
operator|::
name|vector
operator|<
name|MCData
operator|>
name|Data
block|;
name|public
operator|:
comment|/// Append a data entry, expanding the atom if necessary.
name|void
name|addData
argument_list|(
specifier|const
name|MCData
operator|&
name|D
argument_list|)
block|;
comment|/// Get a reference to the data in this atom.
name|ArrayRef
operator|<
name|MCData
operator|>
name|getData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// \name Atom type specific split/truncate logic.
comment|/// @{
name|MCDataAtom
operator|*
name|split
argument_list|(
argument|uint64_t SplitPt
argument_list|)
name|LLVM_OVERRIDE
block|;
name|void
name|truncate
argument_list|(
argument|uint64_t TruncPt
argument_list|)
name|LLVM_OVERRIDE
block|;
comment|/// @}
comment|// Class hierarchy.
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCAtom *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|DataAtom
return|;
block|}
name|private
operator|:
name|friend
name|class
name|MCModule
block|;
comment|// Private constructor - only callable by MCModule
name|MCDataAtom
argument_list|(
argument|MCModule *P
argument_list|,
argument|uint64_t Begin
argument_list|,
argument|uint64_t End
argument_list|)
operator|:
name|MCAtom
argument_list|(
argument|DataAtom
argument_list|,
argument|P
argument_list|,
argument|Begin
argument_list|,
argument|End
argument_list|)
block|{
name|Data
operator|.
name|reserve
argument_list|(
name|End
operator|+
literal|1
operator|-
name|Begin
argument_list|)
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

