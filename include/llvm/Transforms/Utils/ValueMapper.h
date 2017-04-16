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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
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
comment|/// This is a class that can be implemented by clients to remap types when
comment|/// cloning constants and instructions.
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
operator|=
expr|default
expr_stmt|;
comment|/// The client should implement this method if they want to remap types while
comment|/// mapping values.
name|virtual
name|Type
modifier|*
name|remapType
parameter_list|(
name|Type
modifier|*
name|SrcTy
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// This is a class that can be implemented by clients to materialize Values on
comment|/// demand.
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
comment|/// This method can be implemented to generate a mapped Value on demand. For
comment|/// example, if linking lazily. Returns null if the value is not materialized.
name|virtual
name|Value
modifier|*
name|materialize
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// These are flags that the value mapping APIs allow.
enum|enum
name|RemapFlags
block|{
name|RF_None
init|=
literal|0
block|,
comment|/// If this flag is set, the remapper knows that only local values within a
comment|/// function (such as an instruction or argument) are mapped, not global
comment|/// values like functions and global metadata.
name|RF_NoModuleLevelChanges
init|=
literal|1
block|,
comment|/// If this flag is set, the remapper ignores missing function-local entries
comment|/// (Argument, Instruction, BasicBlock) that are not in the value map.  If it
comment|/// is unset, it aborts if an operand is asked to be remapped which doesn't
comment|/// exist in the mapping.
comment|///
comment|/// There are no such assertions in MapValue(), whose results are almost
comment|/// unchanged by this flag.  This flag mainly changes the assertion behaviour
comment|/// in RemapInstruction().
comment|///
comment|/// Since an Instruction's metadata operands (even that point to SSA values)
comment|/// aren't guaranteed to be dominated by their definitions, MapMetadata will
comment|/// return "!{}" instead of "null" for \a LocalAsMetadata instances whose SSA
comment|/// values are unmapped when this flag is set.  Otherwise, \a MapValue()
comment|/// completely ignores this flag.
comment|///
comment|/// \a MapMetadata() always ignores this flag.
name|RF_IgnoreMissingLocals
init|=
literal|2
block|,
comment|/// Instruct the remapper to move distinct metadata instead of duplicating it
comment|/// when there are module-level changes.
name|RF_MoveDistinctMDs
init|=
literal|4
block|,
comment|/// Any global values not in value map are mapped to null instead of mapping
comment|/// to self.  Illegal if RF_IgnoreMissingLocals is also set.
name|RF_NullMapMissingGlobalValues
init|=
literal|8
block|, }
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
comment|/// Context for (re-)mapping values (and metadata).
comment|///
comment|/// A shared context used for mapping and remapping of Value and Metadata
comment|/// instances using \a ValueToValueMapTy, \a RemapFlags, \a
comment|/// ValueMapTypeRemapper, and \a ValueMaterializer.
comment|///
comment|/// There are a number of top-level entry points:
comment|/// - \a mapValue() (and \a mapConstant());
comment|/// - \a mapMetadata() (and \a mapMDNode());
comment|/// - \a remapInstruction(); and
comment|/// - \a remapFunction().
comment|///
comment|/// The \a ValueMaterializer can be used as a callback, but cannot invoke any
comment|/// of these top-level functions recursively.  Instead, callbacks should use
comment|/// one of the following to schedule work lazily in the \a ValueMapper
comment|/// instance:
comment|/// - \a scheduleMapGlobalInitializer()
comment|/// - \a scheduleMapAppendingVariable()
comment|/// - \a scheduleMapGlobalAliasee()
comment|/// - \a scheduleRemapFunction()
comment|///
comment|/// Sometimes a callback needs a diferent mapping context.  Such a context can
comment|/// be registered using \a registerAlternateMappingContext(), which takes an
comment|/// alternate \a ValueToValueMapTy and \a ValueMaterializer and returns a ID to
comment|/// pass into the schedule*() functions.
comment|///
comment|/// TODO: lib/Linker really doesn't need the \a ValueHandle in the \a
comment|/// ValueToValueMapTy.  We should template \a ValueMapper (and its
comment|/// implementation classes), and explicitly instantiate on two concrete
comment|/// instances of \a ValueMap (one as \a ValueToValueMap, and one with raw \a
comment|/// Value pointers).  It may be viable to do away with \a TrackingMDRef in the
comment|/// \a Metadata side map for the lib/Linker case as well, in which case we'll
comment|/// need a new template parameter on \a ValueMap.
comment|///
comment|/// TODO: Update callers of \a RemapInstruction() and \a MapValue() (etc.) to
comment|/// use \a ValueMapper directly.
name|class
name|ValueMapper
block|{
name|void
modifier|*
name|pImpl
decl_stmt|;
name|public
label|:
name|ValueMapper
argument_list|(
argument|ValueToValueMapTy&VM
argument_list|,
argument|RemapFlags Flags = RF_None
argument_list|,
argument|ValueMapTypeRemapper *TypeMapper = nullptr
argument_list|,
argument|ValueMaterializer *Materializer = nullptr
argument_list|)
empty_stmt|;
name|ValueMapper
argument_list|(
name|ValueMapper
operator|&&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|ValueMapper
argument_list|(
specifier|const
name|ValueMapper
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|ValueMapper
modifier|&
name|operator
init|=
operator|(
name|ValueMapper
operator|&&
operator|)
operator|=
name|delete
decl_stmt|;
name|ValueMapper
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ValueMapper
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|ValueMapper
argument_list|()
expr_stmt|;
comment|/// Register an alternate mapping context.
comment|///
comment|/// Returns a MappingContextID that can be used with the various schedule*()
comment|/// API to switch in a different value map on-the-fly.
name|unsigned
name|registerAlternateMappingContext
parameter_list|(
name|ValueToValueMapTy
modifier|&
name|VM
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Add to the current \a RemapFlags.
comment|///
comment|/// \note Like the top-level mapping functions, \a addFlags() must be called
comment|/// at the top level, not during a callback in a \a ValueMaterializer.
name|void
name|addFlags
parameter_list|(
name|RemapFlags
name|Flags
parameter_list|)
function_decl|;
name|Metadata
modifier|*
name|mapMetadata
parameter_list|(
specifier|const
name|Metadata
modifier|&
name|MD
parameter_list|)
function_decl|;
name|MDNode
modifier|*
name|mapMDNode
parameter_list|(
specifier|const
name|MDNode
modifier|&
name|N
parameter_list|)
function_decl|;
name|Value
modifier|*
name|mapValue
parameter_list|(
specifier|const
name|Value
modifier|&
name|V
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|mapConstant
parameter_list|(
specifier|const
name|Constant
modifier|&
name|C
parameter_list|)
function_decl|;
name|void
name|remapInstruction
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|)
function_decl|;
name|void
name|remapFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|void
name|scheduleMapGlobalInitializer
parameter_list|(
name|GlobalVariable
modifier|&
name|GV
parameter_list|,
name|Constant
modifier|&
name|Init
parameter_list|,
name|unsigned
name|MappingContextID
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|scheduleMapAppendingVariable
argument_list|(
name|GlobalVariable
operator|&
name|GV
argument_list|,
name|Constant
operator|*
name|InitPrefix
argument_list|,
name|bool
name|IsOldCtorDtor
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|NewMembers
argument_list|,
name|unsigned
name|MappingContextID
operator|=
literal|0
argument_list|)
decl_stmt|;
name|void
name|scheduleMapGlobalAliasee
parameter_list|(
name|GlobalAlias
modifier|&
name|GA
parameter_list|,
name|Constant
modifier|&
name|Aliasee
parameter_list|,
name|unsigned
name|MappingContextID
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|scheduleRemapFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|unsigned
name|MappingContextID
init|=
literal|0
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Look up or compute a value in the value map.
comment|///
comment|/// Return a mapped value for a function-local value (Argument, Instruction,
comment|/// BasicBlock), or compute and memoize a value for a Constant.
comment|///
comment|///  1. If \c V is in VM, return the result.
comment|///  2. Else if \c V can be materialized with \c Materializer, do so, memoize
comment|///     it in \c VM, and return it.
comment|///  3. Else if \c V is a function-local value, return nullptr.
comment|///  4. Else if \c V is a \a GlobalValue, return \c nullptr or \c V depending
comment|///     on \a RF_NullMapMissingGlobalValues.
comment|///  5. Else if \c V is a \a MetadataAsValue wrapping a LocalAsMetadata,
comment|///     recurse on the local SSA value, and return nullptr or "metadata !{}" on
comment|///     missing depending on RF_IgnoreMissingValues.
comment|///  6. Else if \c V is a \a MetadataAsValue, rewrap the return of \a
comment|///     MapMetadata().
comment|///  7. Else, compute the equivalent constant, and return it.
specifier|inline
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
block|{
return|return
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|mapValue
argument_list|(
operator|*
name|V
argument_list|)
return|;
block|}
comment|/// Lookup or compute a mapping for a piece of metadata.
comment|///
comment|/// Compute and memoize a mapping for \c MD.
comment|///
comment|///  1. If \c MD is mapped, return it.
comment|///  2. Else if \a RF_NoModuleLevelChanges or \c MD is an \a MDString, return
comment|///     \c MD.
comment|///  3. Else if \c MD is a \a ConstantAsMetadata, call \a MapValue() and
comment|///     re-wrap its return (returning nullptr on nullptr).
comment|///  4. Else, \c MD is an \a MDNode.  These are remapped, along with their
comment|///     transitive operands.  Distinct nodes are duplicated or moved depending
comment|///     on \a RF_MoveDistinctNodes.  Uniqued nodes are remapped like constants.
comment|///
comment|/// \note \a LocalAsMetadata is completely unsupported by \a MapMetadata.
comment|/// Instead, use \a MapValue() with its wrapping \a MetadataAsValue instance.
specifier|inline
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
block|{
return|return
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|mapMetadata
argument_list|(
operator|*
name|MD
argument_list|)
return|;
block|}
comment|/// Version of MapMetadata with type safety for MDNode.
specifier|inline
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
block|{
return|return
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|mapMDNode
argument_list|(
operator|*
name|MD
argument_list|)
return|;
block|}
comment|/// Convert the instruction operands from referencing the current values into
comment|/// those specified by VM.
comment|///
comment|/// If \a RF_IgnoreMissingLocals is set and an operand can't be found via \a
comment|/// MapValue(), use the old value.  Otherwise assert that this doesn't happen.
comment|///
comment|/// Note that \a MapValue() only returns \c nullptr for SSA values missing from
comment|/// \c VM.
specifier|inline
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
block|{
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|remapInstruction
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// Remap the operands, metadata, arguments, and instructions of a function.
comment|///
comment|/// Calls \a MapValue() on prefix data, prologue data, and personality
comment|/// function; calls \a MapMetadata() on each attached MDNode; remaps the
comment|/// argument types using the provided \c TypeMapper; and calls \a
comment|/// RemapInstruction() on every instruction.
specifier|inline
name|void
name|RemapFunction
parameter_list|(
name|Function
modifier|&
name|F
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
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|remapFunction
argument_list|(
name|F
argument_list|)
expr_stmt|;
block|}
comment|/// Version of MapValue with type safety for Constant.
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
name|ValueMapper
argument_list|(
name|VM
argument_list|,
name|Flags
argument_list|,
name|TypeMapper
argument_list|,
name|Materializer
argument_list|)
operator|.
name|mapConstant
argument_list|(
operator|*
name|V
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_VALUEMAPPER_H
end_comment

end_unit

