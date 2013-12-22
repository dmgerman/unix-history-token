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
file|"llvm/ADT/ValueMap.h"
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
name|public
label|:
name|virtual
operator|~
name|ValueMaterializer
argument_list|()
block|{}
comment|/// materializeValueFor - The client should implement this method if they
comment|/// want to generate a mapped Value on demand. For example, if linking
comment|/// lazily.
name|virtual
name|Value
operator|*
name|materializeValueFor
argument_list|(
name|Value
operator|*
name|V
argument_list|)
operator|=
literal|0
expr_stmt|;
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
block|}
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
literal|0
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
literal|0
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
literal|0
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// MapValue - provide versions that preserve type safety for MDNode and
comment|/// Constants.
specifier|inline
name|MDNode
modifier|*
name|MapValue
parameter_list|(
specifier|const
name|MDNode
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
literal|0
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
literal|0
parameter_list|)
block|{
return|return
name|cast
operator|<
name|MDNode
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
literal|0
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
literal|0
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

