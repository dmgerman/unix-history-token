begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemoryLocation.h - Memory location descriptions ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file provides utility analysis objects describing memory locations.
end_comment

begin_comment
comment|/// These are used both by the Alias Analysis infrastructure and more
end_comment

begin_comment
comment|/// specialized memory analysis layers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_MEMORYLOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORYLOCATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LoadInst
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|MemTransferInst
decl_stmt|;
name|class
name|MemIntrinsic
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
comment|/// Representation for a specific memory location.
comment|///
comment|/// This abstraction can be used to represent a specific location in memory.
comment|/// The goal of the location is to represent enough information to describe
comment|/// abstract aliasing, modification, and reference behaviors of whatever
comment|/// value(s) are stored in memory at the particular location.
comment|///
comment|/// The primary user of this interface is LLVM's Alias Analysis, but other
comment|/// memory analyses such as MemoryDependence can use it as well.
name|class
name|MemoryLocation
block|{
name|public
label|:
comment|/// UnknownSize - This is a special value which can be used with the
comment|/// size arguments in alias queries to indicate that the caller does not
comment|/// know the sizes of the potential memory references.
enum_decl|enum :
name|uint64_t
block|{
name|UnknownSize
init|=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
block|}
enum_decl|;
comment|/// The address of the start of the location.
specifier|const
name|Value
modifier|*
name|Ptr
decl_stmt|;
comment|/// The maximum size of the location, in address-units, or
comment|/// UnknownSize if the size is not known.
comment|///
comment|/// Note that an unknown size does not mean the pointer aliases the entire
comment|/// virtual address space, because there are restrictions on stepping out of
comment|/// one object and into another. See
comment|/// http://llvm.org/docs/LangRef.html#pointeraliasing
name|uint64_t
name|Size
decl_stmt|;
comment|/// The metadata nodes which describes the aliasing of the location (each
comment|/// member is null if that kind of information is unavailable).
name|AAMDNodes
name|AATags
decl_stmt|;
comment|/// Return a location with information about the memory reference by the given
comment|/// instruction.
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|StoreInst
modifier|*
name|SI
parameter_list|)
function_decl|;
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|VAArgInst
modifier|*
name|VI
parameter_list|)
function_decl|;
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|AtomicCmpXchgInst
modifier|*
name|CXI
parameter_list|)
function_decl|;
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|AtomicRMWInst
modifier|*
name|RMWI
parameter_list|)
function_decl|;
specifier|static
name|MemoryLocation
name|get
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|I
operator|=
name|dyn_cast
operator|<
name|LoadInst
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|get
argument_list|(
name|I
argument_list|)
return|;
elseif|else
if|if
condition|(
name|auto
operator|*
name|I
operator|=
name|dyn_cast
operator|<
name|StoreInst
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|get
argument_list|(
name|I
argument_list|)
return|;
elseif|else
if|if
condition|(
name|auto
operator|*
name|I
operator|=
name|dyn_cast
operator|<
name|VAArgInst
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|get
argument_list|(
name|I
argument_list|)
return|;
elseif|else
if|if
condition|(
name|auto
operator|*
name|I
operator|=
name|dyn_cast
operator|<
name|AtomicCmpXchgInst
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|get
argument_list|(
name|I
argument_list|)
return|;
elseif|else
if|if
condition|(
name|auto
operator|*
name|I
operator|=
name|dyn_cast
operator|<
name|AtomicRMWInst
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|get
argument_list|(
name|I
argument_list|)
return|;
name|llvm_unreachable
argument_list|(
literal|"unsupported memory instruction"
argument_list|)
expr_stmt|;
block|}
comment|/// Return a location representing the source of a memory transfer.
specifier|static
name|MemoryLocation
name|getForSource
parameter_list|(
specifier|const
name|MemTransferInst
modifier|*
name|MTI
parameter_list|)
function_decl|;
comment|/// Return a location representing the destination of a memory set or
comment|/// transfer.
specifier|static
name|MemoryLocation
name|getForDest
parameter_list|(
specifier|const
name|MemIntrinsic
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// Return a location representing a particular argument of a call.
specifier|static
name|MemoryLocation
name|getForArgument
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
name|unsigned
name|ArgIdx
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|&
name|TLI
parameter_list|)
function_decl|;
name|explicit
name|MemoryLocation
argument_list|(
argument|const Value *Ptr = nullptr
argument_list|,
argument|uint64_t Size = UnknownSize
argument_list|,
argument|const AAMDNodes&AATags = AAMDNodes()
argument_list|)
block|:
name|Ptr
argument_list|(
name|Ptr
argument_list|)
operator|,
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|AATags
argument_list|(
argument|AATags
argument_list|)
block|{}
name|MemoryLocation
name|getWithNewPtr
argument_list|(
argument|const Value *NewPtr
argument_list|)
specifier|const
block|{
name|MemoryLocation
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Copy
operator|.
name|Ptr
operator|=
name|NewPtr
block|;
return|return
name|Copy
return|;
block|}
name|MemoryLocation
name|getWithNewSize
argument_list|(
name|uint64_t
name|NewSize
argument_list|)
decl|const
block|{
name|MemoryLocation
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|Copy
operator|.
name|Size
operator|=
name|NewSize
expr_stmt|;
return|return
name|Copy
return|;
block|}
name|MemoryLocation
name|getWithoutAATags
argument_list|()
specifier|const
block|{
name|MemoryLocation
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Copy
operator|.
name|AATags
operator|=
name|AAMDNodes
argument_list|()
block|;
return|return
name|Copy
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MemoryLocation
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
name|Other
operator|.
name|Ptr
operator|&&
name|Size
operator|==
name|Other
operator|.
name|Size
operator|&&
name|AATags
operator|==
name|Other
operator|.
name|AATags
return|;
block|}
block|}
empty_stmt|;
comment|// Specialize DenseMapInfo for MemoryLocation.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|MemoryLocation
operator|>
block|{
specifier|static
specifier|inline
name|MemoryLocation
name|getEmptyKey
argument_list|()
block|{
return|return
name|MemoryLocation
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|MemoryLocation
name|getTombstoneKey
argument_list|()
block|{
return|return
name|MemoryLocation
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const MemoryLocation&Val
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|Ptr
argument_list|)
operator|^
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|Size
argument_list|)
operator|^
name|DenseMapInfo
operator|<
name|AAMDNodes
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|AATags
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const MemoryLocation&LHS
argument_list|,
argument|const MemoryLocation&RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

