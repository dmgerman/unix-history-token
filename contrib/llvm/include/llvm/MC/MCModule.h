begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCModule.h - MCModule class ---------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCModule class, which is used to
end_comment

begin_comment
comment|// represent a complete, disassembled object file or executable.
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
name|LLVM_MC_MCMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|MCAtom
decl_stmt|;
name|class
name|MCBasicBlock
decl_stmt|;
name|class
name|MCDataAtom
decl_stmt|;
name|class
name|MCFunction
decl_stmt|;
name|class
name|MCObjectDisassembler
decl_stmt|;
name|class
name|MCTextAtom
decl_stmt|;
comment|/// \brief A completely disassembled object file or executable.
comment|/// It comprises a list of MCAtom's, each representing a contiguous range of
comment|/// either instructions or data.
comment|/// An MCModule is created using MCObjectDisassembler::buildModule.
name|class
name|MCModule
block|{
comment|/// \name Atom tracking
comment|/// @{
comment|/// \brief Atoms in this module, sorted by begin address.
comment|/// FIXME: This doesn't handle overlapping atoms (which happen when a basic
comment|/// block starts in the middle of an instruction of another basic block.)
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCAtom
operator|*
operator|>
name|AtomListTy
expr_stmt|;
name|AtomListTy
name|Atoms
decl_stmt|;
comment|// For access to map/remap.
name|friend
name|class
name|MCAtom
decl_stmt|;
comment|/// \brief Remap \p Atom to the given range, and update its Begin/End fields.
comment|/// \param Atom An atom belonging to this module.
comment|/// An atom should always use this method to update its bounds, because this
comment|/// enables the owning MCModule to keep track of its atoms.
name|void
name|remap
parameter_list|(
name|MCAtom
modifier|*
name|Atom
parameter_list|,
name|uint64_t
name|NewBegin
parameter_list|,
name|uint64_t
name|NewEnd
parameter_list|)
function_decl|;
comment|/// \brief Insert an atom in the module, using its Begin and End addresses.
name|void
name|map
parameter_list|(
name|MCAtom
modifier|*
name|NewAtom
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Basic block tracking
comment|/// @{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCBasicBlock
operator|*
operator|>
name|BBsByAtomTy
expr_stmt|;
name|BBsByAtomTy
name|BBsByAtom
decl_stmt|;
comment|// For access to basic block> atom tracking.
name|friend
name|class
name|MCBasicBlock
decl_stmt|;
name|friend
name|class
name|MCTextAtom
decl_stmt|;
comment|/// \brief Keep track of \p BBBackedByAtom as being backed by \p Atom.
comment|/// This is used to update succs/preds when \p Atom is split.
name|void
name|trackBBForAtom
parameter_list|(
specifier|const
name|MCTextAtom
modifier|*
name|Atom
parameter_list|,
name|MCBasicBlock
modifier|*
name|BBBackedByAtom
parameter_list|)
function_decl|;
name|void
name|splitBasicBlocksForAtom
parameter_list|(
specifier|const
name|MCTextAtom
modifier|*
name|TA
parameter_list|,
specifier|const
name|MCTextAtom
modifier|*
name|NewTA
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Function tracking
comment|/// @{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCFunction
operator|*
operator|>
name|FunctionListTy
expr_stmt|;
name|FunctionListTy
name|Functions
decl_stmt|;
comment|/// @}
comment|/// The address of the entrypoint function.
name|uint64_t
name|Entrypoint
decl_stmt|;
name|MCModule
argument_list|(
argument|const MCModule&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|MCModule
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCModule
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|// MCObjectDisassembler creates MCModules.
name|friend
name|class
name|MCObjectDisassembler
decl_stmt|;
name|public
label|:
name|MCModule
argument_list|()
operator|:
name|Entrypoint
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|MCModule
argument_list|()
expr_stmt|;
comment|/// \name Create a new MCAtom covering the specified offset range.
comment|/// @{
name|MCTextAtom
modifier|*
name|createTextAtom
parameter_list|(
name|uint64_t
name|Begin
parameter_list|,
name|uint64_t
name|End
parameter_list|)
function_decl|;
name|MCDataAtom
modifier|*
name|createDataAtom
parameter_list|(
name|uint64_t
name|Begin
parameter_list|,
name|uint64_t
name|End
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Access to the owned atom list, ordered by begin address.
comment|/// @{
specifier|const
name|MCAtom
modifier|*
name|findAtomContaining
argument_list|(
name|uint64_t
name|Addr
argument_list|)
decl|const
decl_stmt|;
name|MCAtom
modifier|*
name|findAtomContaining
parameter_list|(
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
specifier|const
name|MCAtom
modifier|*
name|findFirstAtomAfter
argument_list|(
name|uint64_t
name|Addr
argument_list|)
decl|const
decl_stmt|;
name|MCAtom
modifier|*
name|findFirstAtomAfter
parameter_list|(
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
typedef|typedef
name|AtomListTy
operator|::
name|const_iterator
name|const_atom_iterator
expr_stmt|;
typedef|typedef
name|AtomListTy
operator|::
name|iterator
name|atom_iterator
expr_stmt|;
name|const_atom_iterator
name|atom_begin
argument_list|()
specifier|const
block|{
return|return
name|Atoms
operator|.
name|begin
argument_list|()
return|;
block|}
name|atom_iterator
name|atom_begin
parameter_list|()
block|{
return|return
name|Atoms
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_atom_iterator
name|atom_end
argument_list|()
specifier|const
block|{
return|return
name|Atoms
operator|.
name|end
argument_list|()
return|;
block|}
name|atom_iterator
name|atom_end
parameter_list|()
block|{
return|return
name|Atoms
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @}
comment|/// \brief Create a new MCFunction.
name|MCFunction
modifier|*
name|createFunction
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \name Access to the owned function list.
comment|/// @{
typedef|typedef
name|FunctionListTy
operator|::
name|const_iterator
name|const_func_iterator
expr_stmt|;
typedef|typedef
name|FunctionListTy
operator|::
name|iterator
name|func_iterator
expr_stmt|;
name|const_func_iterator
name|func_begin
argument_list|()
specifier|const
block|{
return|return
name|Functions
operator|.
name|begin
argument_list|()
return|;
block|}
name|func_iterator
name|func_begin
parameter_list|()
block|{
return|return
name|Functions
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_func_iterator
name|func_end
argument_list|()
specifier|const
block|{
return|return
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
name|func_iterator
name|func_end
parameter_list|()
block|{
return|return
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @}
comment|/// \brief Get the address of the entrypoint function, or 0 if there is none.
name|uint64_t
name|getEntrypoint
argument_list|()
specifier|const
block|{
return|return
name|Entrypoint
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

