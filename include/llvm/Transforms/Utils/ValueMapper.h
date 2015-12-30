begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ValueMapper.h - Remapping for constants and metadata -----*- C++ -*-===//
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
comment|// This file defines the MapValue interface which is used by various parts of
end_comment

begin_comment
comment|// the Transforms/Utils library to implement cloning and linking facilities.
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
name|LLVM_TRANSFORMS_UTILS_VALUEMAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_VALUEMAPPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/ValueMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
typedef|typedef
name|ValueMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|WeakVH
operator|>
name|ValueToValueMapTy
expr_stmt|;
comment|/// ValueMapTypeRemapper - This is a class that can be implemented by clients
comment|/// to remap types when cloning constants and instructions.
name|class
name|ValueMapTypeRemapper
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
comment|// Out of line method.
name|public
label|:
name|virtual
operator|~
name|ValueMapTypeRemapper
argument_list|()
block|{}
comment|/// remapType - The client should implement this method if they want to
comment|/// remap types while mapping values.
name|virtual
name|Type
operator|*
name|remapType
argument_list|(
name|Type
operator|*
name|SrcTy
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// ValueMaterializer - This is a class that can be implemented by clients
comment|/// to materialize Values on demand.
name|class
name|ValueMaterializer
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
comment|// Out of line method.
name|protected
label|:
operator|~
name|ValueMaterializer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ValueMaterializer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ValueMaterializer
argument_list|(
specifier|const
name|ValueMaterializer
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|ValueMaterializer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ValueMaterializer
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
name|public
label|:
comment|/// The client should implement this method if they want to generate a
comment|/// mapped Value on demand. For example, if linking lazily.
name|virtual
name|Value
modifier|*
name|materializeDeclFor
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// If the data being mapped is recursive, the above function can map
comment|/// just the declaration and this is called to compute the initializer.
comment|/// It is called after the mapping is recorded, so it doesn't need to worry
comment|/// about recursion.
name|virtual
name|void
name|materializeInitFor
parameter_list|(
name|GlobalValue
modifier|*
name|New
parameter_list|,
name|GlobalValue
modifier|*
name|Old
parameter_list|)
function_decl|;
comment|/// If the client needs to handle temporary metadata it must implement
comment|/// these methods.
name|virtual
name|Metadata
modifier|*
name|mapTemporaryMetadata
parameter_list|(
name|Metadata
modifier|*
name|MD
parameter_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|replaceTemporaryMetadata
parameter_list|(
specifier|const
name|Metadata
modifier|*
name|OrigMD
parameter_list|,
name|Metadata
modifier|*
name|NewMD
parameter_list|)
block|{}
comment|/// The client should implement this method if some metadata need
comment|/// not be mapped, for example DISubprogram metadata for functions not
comment|/// linked into the destination module.
name|virtual
name|bool
name|isMetadataNeeded
parameter_list|(
name|Metadata
modifier|*
name|MD
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// RemapFlags - These are flags that the value mapping APIs allow.
enum|enum
name|RemapFlags
block|{
name|RF_None
init|=
literal|0
block|,
comment|/// RF_NoModuleLevelChanges - If this flag is set, the remapper knows that
comment|/// only local values within a function (such as an instruction or argument)
comment|/// are mapped, not global values like functions and global metadata.
name|RF_NoModuleLevelChanges
init|=
literal|1
block|,
comment|/// RF_IgnoreMissingEntries - If this flag is set, the remapper ignores
comment|/// entries that are not in the value map.  If it is unset, it aborts if an
comment|/// operand is asked to be remapped which doesn't exist in the mapping.
name|RF_IgnoreMissingEntries
init|=
literal|2
block|,
comment|/// Instruct the remapper to move distinct metadata instead of duplicating
comment|/// it when there are module-level changes.
name|RF_MoveDistinctMDs
init|=
literal|4
block|,
comment|/// Any global values not in value map are mapped to null instead of
comment|/// mapping to self. Illegal if RF_IgnoreMissingEntries is also set.
name|RF_NullMapMissingGlobalValues
init|=
literal|8
block|,
comment|/// Set when there is still temporary metadata that must be handled,
comment|/// such as when we are doing function importing and will materialize
comment|/// and link metadata as a postpass.
name|RF_HaveUnmaterializedMetadata
init|=
literal|16
block|,   }
enum|;
specifier|static
specifier|inline
name|RemapFlags
name|operator
operator||
operator|(
name|RemapFlags
name|LHS
operator|,
name|RemapFlags
name|RHS
operator|)
block|{
return|return
name|RemapFlags
argument_list|(
name|unsigned
argument_list|(
name|LHS
argument_list|)
operator||
name|unsigned
argument_list|(
name|RHS
argument_list|)
argument_list|)
return|;
block|}
name|Value
modifier|*
name|MapValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|RemapFlags
name|Flags
init|=
name|RF_None
parameter_list|,
name|ValueMapTypeRemapper
modifier|*
name|TypeMapper
init|=
name|nullptr
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
function_decl|;
name|Metadata
modifier|*
name|MapMetadata
parameter_list|(
specifier|const
name|Metadata
modifier|*
name|MD
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|RemapFlags
name|Flags
init|=
name|RF_None
parameter_list|,
name|ValueMapTypeRemapper
modifier|*
name|TypeMapper
init|=
name|nullptr
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// MapMetadata - provide versions that preserve type safety for MDNodes.
name|MDNode
modifier|*
name|MapMetadata
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|MD
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|RemapFlags
name|Flags
init|=
name|RF_None
parameter_list|,
name|ValueMapTypeRemapper
modifier|*
name|TypeMapper
init|=
name|nullptr
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
function_decl|;
name|void
name|RemapInstruction
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|RemapFlags
name|Flags
init|=
name|RF_None
parameter_list|,
name|ValueMapTypeRemapper
modifier|*
name|TypeMapper
init|=
name|nullptr
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// MapValue - provide versions that preserve type safety for Constants.
specifier|inline
name|Constant
modifier|*
name|MapValue
parameter_list|(
specifier|const
name|Constant
modifier|*
name|V
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|RemapFlags
name|Flags
init|=
name|RF_None
parameter_list|,
name|ValueMapTypeRemapper
modifier|*
name|TypeMapper
init|=
name|nullptr
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|cast
operator|<
name|Constant
operator|>
operator|(
name|MapValue
argument_list|(
operator|(
specifier|const
name|Value
operator|*
operator|)
name|V
argument_list|,
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

