begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAtom.h - MCAtom class ---------------------*- C++ -*-===//
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
comment|// instructions;
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
comment|/// MCData - An entry in a data MCAtom.
comment|// NOTE: This may change to a more complex type in the future.
typedef|typedef
name|uint8_t
name|MCData
typedef|;
comment|/// MCAtom - Represents a contiguous range of either instructions (a TextAtom)
comment|/// or data (a DataAtom).  Address ranges are expressed as _closed_ intervals.
name|class
name|MCAtom
block|{
name|friend
name|class
name|MCModule
decl_stmt|;
typedef|typedef
enum|enum
block|{
name|TextAtom
block|,
name|DataAtom
block|}
name|AtomType
typedef|;
name|AtomType
name|Type
decl_stmt|;
name|MCModule
modifier|*
name|Parent
decl_stmt|;
name|uint64_t
name|Begin
decl_stmt|,
name|End
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|MCInst
operator|>
expr|>
name|Text
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MCData
operator|>
name|Data
expr_stmt|;
comment|// Private constructor - only callable by MCModule
name|MCAtom
argument_list|(
argument|AtomType T
argument_list|,
argument|MCModule *P
argument_list|,
argument|uint64_t B
argument_list|,
argument|uint64_t E
argument_list|)
block|:
name|Type
argument_list|(
name|T
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
name|public
operator|:
name|bool
name|isTextAtom
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|TextAtom
return|;
block|}
name|bool
name|isDataAtom
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|DataAtom
return|;
block|}
name|void
name|addInst
parameter_list|(
specifier|const
name|MCInst
modifier|&
name|I
parameter_list|,
name|uint64_t
name|Address
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|void
name|addData
parameter_list|(
specifier|const
name|MCData
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// split - Splits the atom in two at a given address, which must align with
comment|/// and instruction boundary if this is a TextAtom.  Returns the newly created
comment|/// atom representing the high part of the split.
name|MCAtom
modifier|*
name|split
parameter_list|(
name|uint64_t
name|SplitPt
parameter_list|)
function_decl|;
comment|/// truncate - Truncates an atom so that TruncPt is the last byte address
comment|/// contained in the atom.
name|void
name|truncate
parameter_list|(
name|uint64_t
name|TruncPt
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

