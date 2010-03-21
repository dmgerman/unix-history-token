begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PreprocessingRecord.h - Record of Preprocessing --------*- C++ -*-===//
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
comment|//  This file defines the PreprocessingRecord class, which maintains a record
end_comment

begin_comment
comment|//  of what occurred during preprocessing.
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
name|LLVM_CLANG_LEX_PREPROCESSINGRECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PREPROCESSINGRECORD_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|PreprocessingRecord
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Allocates memory within a Clang preprocessing record.
end_comment

begin_decl_stmt
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|bytes
argument_list|,
name|clang
operator|::
name|PreprocessingRecord
operator|&
name|PR
argument_list|,
name|unsigned
name|alignment
operator|=
literal|8
argument_list|)
name|throw
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Frees memory allocated in a Clang preprocessing record.
end_comment

begin_decl_stmt
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
name|clang
operator|::
name|PreprocessingRecord
operator|&
name|PR
argument_list|,
name|unsigned
argument_list|)
name|throw
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MacroDefinition
decl_stmt|;
comment|/// \brief Base class that describes a preprocessed entity, which may be a
comment|/// preprocessor directive or macro instantiation.
name|class
name|PreprocessedEntity
block|{
name|public
label|:
comment|/// \brief The kind of preprocessed entity an object describes.
enum|enum
name|EntityKind
block|{
comment|/// \brief A macro instantiation.
name|MacroInstantiationKind
block|,
comment|/// \brief A preprocessing directive whose kind is not specified.
comment|///
comment|/// This kind will be used for any preprocessing directive that does not
comment|/// have a more specific kind within the \c DirectiveKind enumeration.
name|PreprocessingDirectiveKind
block|,
comment|/// \brief A macro definition.
name|MacroDefinitionKind
block|,
name|FirstPreprocessingDirective
init|=
name|PreprocessingDirectiveKind
block|,
name|LastPreprocessingDirective
init|=
name|MacroDefinitionKind
block|}
enum|;
name|private
label|:
comment|/// \brief The kind of preprocessed entity that this object describes.
name|EntityKind
name|Kind
decl_stmt|;
comment|/// \brief The source range that covers this preprocessed entity.
name|SourceRange
name|Range
decl_stmt|;
name|protected
label|:
name|PreprocessedEntity
argument_list|(
argument|EntityKind Kind
argument_list|,
argument|SourceRange Range
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Range
argument_list|(
argument|Range
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Retrieve the kind of preprocessed entity stored in this object.
name|EntityKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Retrieve the source range that covers this entire preprocessed
comment|/// entity.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|PreprocessedEntity
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Only allow allocation of preprocessed entities using the allocator
comment|// in PreprocessingRecord or by doing a placement new.
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|bytes
parameter_list|,
name|PreprocessingRecord
modifier|&
name|PR
parameter_list|,
name|unsigned
name|alignment
init|=
literal|8
parameter_list|)
function|throw
parameter_list|()
block|{
return|return
operator|::
name|operator
name|new
argument_list|(
name|bytes
argument_list|,
name|PR
argument_list|,
name|alignment
argument_list|)
return|;
block|}
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|bytes
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|)
function|throw
parameter_list|()
block|{
return|return
name|mem
return|;
block|}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|PreprocessingRecord
modifier|&
name|PR
parameter_list|,
name|unsigned
name|alignment
parameter_list|)
function|throw
parameter_list|()
block|{
return|return
operator|::
name|operator
name|delete
argument_list|(
name|ptr
argument_list|,
name|PR
argument_list|,
name|alignment
argument_list|)
return|;
block|}
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
argument_list|,
name|std
operator|::
name|size_t
argument_list|)
name|throw
argument_list|()
block|{ }
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function|throw
parameter_list|()
block|{ }
name|private
label|:
comment|// Make vanilla 'new' and 'delete' illegal for preprocessed entities.
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|bytes
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Records the location of a macro instantiation.
name|class
name|MacroInstantiation
range|:
name|public
name|PreprocessedEntity
block|{
comment|/// \brief The name of the macro being instantiation.
name|IdentifierInfo
operator|*
name|Name
block|;
comment|/// \brief The definition of this macro.
name|MacroDefinition
operator|*
name|Definition
block|;
name|public
operator|:
name|MacroInstantiation
argument_list|(
argument|IdentifierInfo *Name
argument_list|,
argument|SourceRange Range
argument_list|,
argument|MacroDefinition *Definition
argument_list|)
operator|:
name|PreprocessedEntity
argument_list|(
name|MacroInstantiationKind
argument_list|,
name|Range
argument_list|)
block|,
name|Name
argument_list|(
name|Name
argument_list|)
block|,
name|Definition
argument_list|(
argument|Definition
argument_list|)
block|{ }
comment|/// \brief The name of the macro being instantiated.
name|IdentifierInfo
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief The definition of the macro being instantiated.
name|MacroDefinition
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|Definition
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const PreprocessedEntity *PE
argument_list|)
block|{
return|return
name|PE
operator|->
name|getKind
argument_list|()
operator|==
name|MacroInstantiationKind
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MacroInstantiation *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief Records the presence of a preprocessor directive.
name|class
name|PreprocessingDirective
operator|:
name|public
name|PreprocessedEntity
block|{
name|public
operator|:
name|PreprocessingDirective
argument_list|(
argument|EntityKind Kind
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|PreprocessedEntity
argument_list|(
argument|Kind
argument_list|,
argument|Range
argument_list|)
block|{ }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const PreprocessedEntity *PD
argument_list|)
block|{
return|return
name|PD
operator|->
name|getKind
argument_list|()
operator|>=
name|FirstPreprocessingDirective
operator|&&
name|PD
operator|->
name|getKind
argument_list|()
operator|<=
name|LastPreprocessingDirective
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PreprocessingDirective *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief Record the location of a macro definition.
name|class
name|MacroDefinition
operator|:
name|public
name|PreprocessingDirective
block|{
comment|/// \brief The name of the macro being defined.
specifier|const
name|IdentifierInfo
operator|*
name|Name
block|;
comment|/// \brief The location of the macro name in the macro definition.
name|SourceLocation
name|Location
block|;
name|public
operator|:
name|explicit
name|MacroDefinition
argument_list|(
argument|const IdentifierInfo *Name
argument_list|,
argument|SourceLocation Location
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|PreprocessingDirective
argument_list|(
name|MacroDefinitionKind
argument_list|,
name|Range
argument_list|)
block|,
name|Name
argument_list|(
name|Name
argument_list|)
block|,
name|Location
argument_list|(
argument|Location
argument_list|)
block|{ }
comment|/// \brief Retrieve the name of the macro being defined.
specifier|const
name|IdentifierInfo
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Retrieve the location of the macro name in the definition.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Location
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const PreprocessedEntity *PE
argument_list|)
block|{
return|return
name|PE
operator|->
name|getKind
argument_list|()
operator|==
name|MacroDefinitionKind
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MacroDefinition *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief An abstract class that should be subclassed by any external source
comment|/// of preprocessing record entries.
name|class
name|ExternalPreprocessingRecordSource
block|{
name|public
operator|:
name|virtual
operator|~
name|ExternalPreprocessingRecordSource
argument_list|()
block|;
comment|/// \brief Read any preallocated preprocessed entities from the external
comment|/// source.
name|virtual
name|void
name|ReadPreprocessedEntities
argument_list|()
operator|=
literal|0
block|;   }
block|;
comment|/// \brief A record of the steps taken while preprocessing a source file,
comment|/// including the various preprocessing directives processed, macros
comment|/// instantiated, etc.
name|class
name|PreprocessingRecord
operator|:
name|public
name|PPCallbacks
block|{
comment|/// \brief Allocator used to store preprocessing objects.
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
block|;
comment|/// \brief The set of preprocessed entities in this record, in order they
comment|/// were seen.
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
name|PreprocessedEntities
block|;
comment|/// \brief Mapping from MacroInfo structures to their definitions.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MacroInfo
operator|*
block|,
name|MacroDefinition
operator|*
operator|>
name|MacroDefinitions
block|;
comment|/// \brief External source of preprocessed entities.
name|ExternalPreprocessingRecordSource
operator|*
name|ExternalSource
block|;
comment|/// \brief The number of preallocated entities (that are known to the
comment|/// external source).
name|unsigned
name|NumPreallocatedEntities
block|;
comment|/// \brief Whether we have already loaded all of the preallocated entities.
name|mutable
name|bool
name|LoadedPreallocatedEntities
block|;
name|void
name|MaybeLoadPreallocatedEntities
argument_list|()
specifier|const
block|;
name|public
operator|:
name|PreprocessingRecord
argument_list|()
block|;
comment|/// \brief Allocate memory in the preprocessing record.
name|void
operator|*
name|Allocate
argument_list|(
argument|unsigned Size
argument_list|,
argument|unsigned Align =
literal|8
argument_list|)
block|{
return|return
name|BumpAlloc
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
return|;
block|}
comment|/// \brief Deallocate memory in the preprocessing record.
name|void
name|Deallocate
argument_list|(
argument|void *Ptr
argument_list|)
block|{ }
comment|// Iteration over the preprocessed entities.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
argument_list|(
argument|bool OnlyLocalEntities = false
argument_list|)
block|;
name|iterator
name|end
argument_list|(
argument|bool OnlyLocalEntities = false
argument_list|)
block|;
name|const_iterator
name|begin
argument_list|(
argument|bool OnlyLocalEntities = false
argument_list|)
specifier|const
block|;
name|const_iterator
name|end
argument_list|(
argument|bool OnlyLocalEntities = false
argument_list|)
specifier|const
block|;
comment|/// \brief Add a new preprocessed entity to this record.
name|void
name|addPreprocessedEntity
argument_list|(
name|PreprocessedEntity
operator|*
name|Entity
argument_list|)
block|;
comment|/// \brief Set the external source for preprocessed entities.
name|void
name|SetExternalSource
argument_list|(
argument|ExternalPreprocessingRecordSource&Source
argument_list|,
argument|unsigned NumPreallocatedEntities
argument_list|)
block|;
comment|/// \brief Set the preallocated entry at the given index to the given
comment|/// preprocessed entity.
name|void
name|SetPreallocatedEntity
argument_list|(
argument|unsigned Index
argument_list|,
argument|PreprocessedEntity *Entity
argument_list|)
block|;
comment|/// \brief Register a new macro definition.
name|void
name|RegisterMacroDefinition
argument_list|(
name|MacroInfo
operator|*
name|Macro
argument_list|,
name|MacroDefinition
operator|*
name|MD
argument_list|)
block|;
comment|/// \brief Retrieve the preprocessed entity at the given index.
name|PreprocessedEntity
operator|*
name|getPreprocessedEntity
argument_list|(
argument|unsigned Index
argument_list|)
block|{
name|assert
argument_list|(
name|Index
operator|<
name|PreprocessedEntities
operator|.
name|size
argument_list|()
operator|&&
literal|"Out-of-bounds preprocessed entity"
argument_list|)
block|;
return|return
name|PreprocessedEntities
index|[
name|Index
index|]
return|;
block|}
comment|/// \brief Retrieve the macro definition that corresponds to the given
comment|/// \c MacroInfo.
name|MacroDefinition
operator|*
name|findMacroDefinition
argument_list|(
specifier|const
name|MacroInfo
operator|*
name|MI
argument_list|)
block|;
name|virtual
name|void
name|MacroExpands
argument_list|(
specifier|const
name|Token
operator|&
name|Id
argument_list|,
specifier|const
name|MacroInfo
operator|*
name|MI
argument_list|)
block|;
name|virtual
name|void
name|MacroDefined
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|,
specifier|const
name|MacroInfo
operator|*
name|MI
argument_list|)
block|;
name|virtual
name|void
name|MacroUndefined
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|,
specifier|const
name|MacroInfo
operator|*
name|MI
argument_list|)
block|;   }
block|; }
comment|// end namespace clang
specifier|inline
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t bytes
argument_list|,
argument|clang::PreprocessingRecord& PR
argument_list|,
argument|unsigned alignment
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|PR
operator|.
name|Allocate
argument_list|(
name|bytes
argument_list|,
name|alignment
argument_list|)
return|;
block|}
specifier|inline
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
name|clang
operator|::
name|PreprocessingRecord
operator|&
name|PR
argument_list|,
name|unsigned
argument_list|)
name|throw
argument_list|()
block|{
name|PR
operator|.
name|Deallocate
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_PREPROCESSINGRECORD_H
end_comment

end_unit

