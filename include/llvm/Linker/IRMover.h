begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRMover.h ------------------------------------------------*- C++ -*-===//
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
name|LLVM_LINKER_IRMOVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKER_IRMOVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Error
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Metadata
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|TrackingMDRef
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|IRMover
block|{
struct|struct
name|StructTypeKeyInfo
block|{
struct|struct
name|KeyTy
block|{
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|ETypes
expr_stmt|;
name|bool
name|IsPacked
decl_stmt|;
name|KeyTy
argument_list|(
argument|ArrayRef<Type *> E
argument_list|,
argument|bool P
argument_list|)
empty_stmt|;
name|KeyTy
argument_list|(
specifier|const
name|StructType
operator|*
name|ST
argument_list|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|KeyTy
operator|&
name|that
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|KeyTy
operator|&
name|that
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
specifier|static
name|StructType
modifier|*
name|getEmptyKey
parameter_list|()
function_decl|;
specifier|static
name|StructType
modifier|*
name|getTombstoneKey
parameter_list|()
function_decl|;
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|KeyTy
modifier|&
name|Key
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|StructType
modifier|*
name|ST
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|KeyTy
modifier|&
name|LHS
parameter_list|,
specifier|const
name|StructType
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|StructType
modifier|*
name|LHS
parameter_list|,
specifier|const
name|StructType
modifier|*
name|RHS
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// Type of the Metadata map in \a ValueToValueMapTy.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Metadata
operator|*
operator|,
name|TrackingMDRef
operator|>
name|MDMapT
expr_stmt|;
name|public
label|:
name|class
name|IdentifiedStructTypeSet
block|{
comment|// The set of opaque types is the composite module.
name|DenseSet
operator|<
name|StructType
operator|*
operator|>
name|OpaqueStructTypes
expr_stmt|;
comment|// The set of identified but non opaque structures in the composite module.
name|DenseSet
operator|<
name|StructType
operator|*
operator|,
name|StructTypeKeyInfo
operator|>
name|NonOpaqueStructTypes
expr_stmt|;
name|public
label|:
name|void
name|addNonOpaque
parameter_list|(
name|StructType
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|void
name|switchToNonOpaque
parameter_list|(
name|StructType
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|void
name|addOpaque
parameter_list|(
name|StructType
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|StructType
modifier|*
name|findNonOpaque
argument_list|(
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|ETypes
argument_list|,
name|bool
name|IsPacked
argument_list|)
decl_stmt|;
name|bool
name|hasType
parameter_list|(
name|StructType
modifier|*
name|Ty
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|IRMover
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|GlobalValue
operator|&
argument_list|)
operator|>
name|ValueAdder
expr_stmt|;
comment|/// Move in the provide values in \p ValuesToLink from \p Src.
comment|///
comment|/// - \p AddLazyFor is a call back that the IRMover will call when a global
comment|///   value is referenced by one of the ValuesToLink (transitively) but was
comment|///   not present in ValuesToLink. The GlobalValue and a ValueAdder callback
comment|///   are passed as an argument, and the callback is expected to be called
comment|///   if the GlobalValue needs to be added to the \p ValuesToLink and linked.
comment|/// - \p LinkModuleInlineAsm is true if the ModuleInlineAsm string in Src
comment|///   should be linked with (concatenated into) the ModuleInlineAsm string
comment|///   for the destination module. It should be true for full LTO, but not
comment|///   when importing for ThinLTO, otherwise we can have duplicate symbols.
comment|/// - \p IsPerformingImport is true when this IR link is to perform ThinLTO
comment|///   function importing from Src.
name|Error
name|move
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|Src
argument_list|,
name|ArrayRef
operator|<
name|GlobalValue
operator|*
operator|>
name|ValuesToLink
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
argument|GlobalValue&GV
argument_list|,
argument|ValueAdder Add
argument_list|)
operator|>
name|AddLazyFor
argument_list|,
name|bool
name|LinkModuleInlineAsm
argument_list|,
name|bool
name|IsPerformingImport
argument_list|)
decl_stmt|;
name|Module
modifier|&
name|getModule
parameter_list|()
block|{
return|return
name|Composite
return|;
block|}
name|private
label|:
name|Module
modifier|&
name|Composite
decl_stmt|;
name|IdentifiedStructTypeSet
name|IdentifiedStructTypes
decl_stmt|;
name|MDMapT
name|SharedMDs
decl_stmt|;
comment|///< A Metadata map to use for all calls to \a move().
block|}
empty_stmt|;
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

