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
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|MacroInfo
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
name|class
name|FileEntry
decl_stmt|;
comment|/// \brief Base class that describes a preprocessed entity, which may be a
comment|/// preprocessor directive or macro expansion.
name|class
name|PreprocessedEntity
block|{
name|public
label|:
comment|/// \brief The kind of preprocessed entity an object describes.
enum|enum
name|EntityKind
block|{
comment|/// \brief Indicates a problem trying to load the preprocessed entity.
name|InvalidKind
block|,
comment|/// \brief A macro expansion.
name|MacroExpansionKind
block|,
comment|/// \defgroup Preprocessing directives
comment|/// @{
comment|/// \brief A macro definition.
name|MacroDefinitionKind
block|,
comment|/// \brief An inclusion directive, such as \c \#include, \c
comment|/// \#import, or \c \#include_next.
name|InclusionDirectiveKind
block|,
comment|/// @}
name|FirstPreprocessingDirective
init|=
name|MacroDefinitionKind
block|,
name|LastPreprocessingDirective
init|=
name|InclusionDirectiveKind
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
name|friend
name|class
name|PreprocessingRecord
expr_stmt|;
name|public
label|:
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
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
comment|/// \brief Returns true if there was a problem loading the preprocessed
comment|/// entity.
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|InvalidKind
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
comment|/// \brief Records the presence of a preprocessor directive.
name|class
name|PreprocessingDirective
range|:
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
name|public
operator|:
name|explicit
name|MacroDefinition
argument_list|(
argument|const IdentifierInfo *Name
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
argument|Name
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
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
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
expr|}
block|;
comment|/// \brief Records the location of a macro expansion.
name|class
name|MacroExpansion
operator|:
name|public
name|PreprocessedEntity
block|{
comment|/// \brief The definition of this macro or the name of the macro if it is
comment|/// a builtin macro.
name|llvm
operator|::
name|PointerUnion
operator|<
name|IdentifierInfo
operator|*
block|,
name|MacroDefinition
operator|*
operator|>
name|NameOrDef
block|;
name|public
operator|:
name|MacroExpansion
argument_list|(
argument|IdentifierInfo *BuiltinName
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|PreprocessedEntity
argument_list|(
name|MacroExpansionKind
argument_list|,
name|Range
argument_list|)
block|,
name|NameOrDef
argument_list|(
argument|BuiltinName
argument_list|)
block|{ }
name|MacroExpansion
argument_list|(
argument|MacroDefinition *Definition
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|PreprocessedEntity
argument_list|(
name|MacroExpansionKind
argument_list|,
name|Range
argument_list|)
block|,
name|NameOrDef
argument_list|(
argument|Definition
argument_list|)
block|{ }
comment|/// \brief True if it is a builtin macro.
name|bool
name|isBuiltinMacro
argument_list|()
specifier|const
block|{
return|return
name|NameOrDef
operator|.
name|is
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief The name of the macro being expanded.
specifier|const
name|IdentifierInfo
operator|*
name|getName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|MacroDefinition
modifier|*
name|Def
init|=
name|getDefinition
argument_list|()
condition|)
return|return
name|Def
operator|->
name|getName
argument_list|()
return|;
return|return
name|NameOrDef
operator|.
name|get
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief The definition of the macro being expanded. May return null if
comment|/// this is a builtin macro.
name|MacroDefinition
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|NameOrDef
operator|.
name|dyn_cast
operator|<
name|MacroDefinition
operator|*
operator|>
operator|(
operator|)
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
name|MacroExpansionKind
return|;
block|}
expr|}
block|;
comment|/// \brief Record the location of an inclusion directive, such as an
comment|/// \c \#include or \c \#import statement.
name|class
name|InclusionDirective
operator|:
name|public
name|PreprocessingDirective
block|{
name|public
operator|:
comment|/// \brief The kind of inclusion directives known to the
comment|/// preprocessor.
expr|enum
name|InclusionKind
block|{
comment|/// \brief An \c \#include directive.
name|Include
block|,
comment|/// \brief An Objective-C \c \#import directive.
name|Import
block|,
comment|/// \brief A GNU \c \#include_next directive.
name|IncludeNext
block|,
comment|/// \brief A Clang \c \#__include_macros directive.
name|IncludeMacros
block|}
block|;
name|private
operator|:
comment|/// \brief The name of the file that was included, as written in
comment|/// the source.
name|StringRef
name|FileName
block|;
comment|/// \brief Whether the file name was in quotation marks; otherwise, it was
comment|/// in angle brackets.
name|unsigned
name|InQuotes
operator|:
literal|1
block|;
comment|/// \brief The kind of inclusion directive we have.
comment|///
comment|/// This is a value of type InclusionKind.
name|unsigned
name|Kind
operator|:
literal|2
block|;
comment|/// \brief Whether the inclusion directive was automatically turned into
comment|/// a module import.
name|unsigned
name|ImportedModule
operator|:
literal|1
block|;
comment|/// \brief The file that was included.
specifier|const
name|FileEntry
operator|*
name|File
block|;
name|public
operator|:
name|InclusionDirective
argument_list|(
argument|PreprocessingRecord&PPRec
argument_list|,
argument|InclusionKind Kind
argument_list|,
argument|StringRef FileName
argument_list|,
argument|bool InQuotes
argument_list|,
argument|bool ImportedModule
argument_list|,
argument|const FileEntry *File
argument_list|,
argument|SourceRange Range
argument_list|)
block|;
comment|/// \brief Determine what kind of inclusion directive this is.
name|InclusionKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|InclusionKind
operator|>
operator|(
name|Kind
operator|)
return|;
block|}
comment|/// \brief Retrieve the included file name as it was written in the source.
name|StringRef
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|FileName
return|;
block|}
comment|/// \brief Determine whether the included file name was written in quotes;
comment|/// otherwise, it was written in angle brackets.
name|bool
name|wasInQuotes
argument_list|()
specifier|const
block|{
return|return
name|InQuotes
return|;
block|}
comment|/// \brief Determine whether the inclusion directive was automatically
comment|/// turned into a module import.
name|bool
name|importedModule
argument_list|()
specifier|const
block|{
return|return
name|ImportedModule
return|;
block|}
comment|/// \brief Retrieve the file entry for the actual file that was included
comment|/// by this directive.
specifier|const
name|FileEntry
operator|*
name|getFile
argument_list|()
specifier|const
block|{
return|return
name|File
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
name|InclusionDirectiveKind
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
comment|/// \brief Read a preallocated preprocessed entity from the external source.
comment|///
comment|/// \returns null if an error occurred that prevented the preprocessed
comment|/// entity from being loaded.
name|virtual
name|PreprocessedEntity
operator|*
name|ReadPreprocessedEntity
argument_list|(
argument|unsigned Index
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Returns a pair of [Begin, End) indices of preallocated
comment|/// preprocessed entities that \p Range encompasses.
name|virtual
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|findPreprocessedEntitiesInRange
argument_list|(
argument|SourceRange Range
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Optionally returns true or false if the preallocated preprocessed
comment|/// entity with index \p Index came from file \p FID.
name|virtual
name|Optional
operator|<
name|bool
operator|>
name|isPreprocessedEntityInFileID
argument_list|(
argument|unsigned Index
argument_list|,
argument|FileID FID
argument_list|)
block|{
return|return
name|None
return|;
block|}
expr|}
block|;
comment|/// \brief A record of the steps taken while preprocessing a source file,
comment|/// including the various preprocessing directives processed, macros
comment|/// expanded, etc.
name|class
name|PreprocessingRecord
operator|:
name|public
name|PPCallbacks
block|{
name|SourceManager
operator|&
name|SourceMgr
block|;
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
comment|/// \brief The set of preprocessed entities in this record that have been
comment|/// loaded from external sources.
comment|///
comment|/// The entries in this vector are loaded lazily from the external source,
comment|/// and are referenced by the iterator using negative indices.
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
name|LoadedPreprocessedEntities
block|;
comment|/// \brief Global (loaded or local) ID for a preprocessed entity.
comment|/// Negative values are used to indicate preprocessed entities
comment|/// loaded from the external source while non-negative values are used to
comment|/// indicate preprocessed entities introduced by the current preprocessor.
comment|/// Value -1 corresponds to element 0 in the loaded entities vector,
comment|/// value -2 corresponds to element 1 in the loaded entities vector, etc.
comment|/// Value 0 is an invalid value, the index to local entities is 1-based,
comment|/// value 1 corresponds to element 0 in the local entities vector,
comment|/// value 2 corresponds to element 1 in the local entities vector, etc.
name|class
name|PPEntityID
block|{
name|int
name|ID
block|;
name|explicit
name|PPEntityID
argument_list|(
argument|int ID
argument_list|)
operator|:
name|ID
argument_list|(
argument|ID
argument_list|)
block|{}
name|friend
name|class
name|PreprocessingRecord
block|;
name|public
operator|:
name|PPEntityID
argument_list|()
operator|:
name|ID
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
specifier|static
name|PPEntityID
name|getPPEntityID
argument_list|(
argument|unsigned Index
argument_list|,
argument|bool isLoaded
argument_list|)
block|{
return|return
name|isLoaded
operator|?
name|PPEntityID
argument_list|(
operator|-
name|int
argument_list|(
name|Index
argument_list|)
operator|-
literal|1
argument_list|)
operator|:
name|PPEntityID
argument_list|(
name|Index
operator|+
literal|1
argument_list|)
return|;
block|}
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
comment|/// \brief Retrieve the preprocessed entity at the given ID.
name|PreprocessedEntity
operator|*
name|getPreprocessedEntity
argument_list|(
argument|PPEntityID PPID
argument_list|)
block|;
comment|/// \brief Retrieve the loaded preprocessed entity at the given index.
name|PreprocessedEntity
operator|*
name|getLoadedPreprocessedEntity
argument_list|(
argument|unsigned Index
argument_list|)
block|;
comment|/// \brief Determine the number of preprocessed entities that were
comment|/// loaded (or can be loaded) from an external source.
name|unsigned
name|getNumLoadedPreprocessedEntities
argument_list|()
specifier|const
block|{
return|return
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Returns a pair of [Begin, End) indices of local preprocessed
comment|/// entities that \p Range encompasses.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|findLocalPreprocessedEntitiesInRange
argument_list|(
argument|SourceRange Range
argument_list|)
specifier|const
block|;
name|unsigned
name|findBeginLocalPreprocessedEntity
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|;
name|unsigned
name|findEndLocalPreprocessedEntity
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|;
comment|/// \brief Allocate space for a new set of loaded preprocessed entities.
comment|///
comment|/// \returns The index into the set of loaded preprocessed entities, which
comment|/// corresponds to the first newly-allocated entity.
name|unsigned
name|allocateLoadedEntities
argument_list|(
argument|unsigned NumEntities
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
name|Def
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Construct a new preprocessing record.
name|explicit
name|PreprocessingRecord
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
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
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
block|;
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
comment|// Iteration over the preprocessed entities.
name|class
name|iterator
block|{
name|PreprocessingRecord
operator|*
name|Self
block|;
comment|/// \brief Position within the preprocessed entity sequence.
comment|///
comment|/// In a complete iteration, the Position field walks the range [-M, N),
comment|/// where negative values are used to indicate preprocessed entities
comment|/// loaded from the external source while non-negative values are used to
comment|/// indicate preprocessed entities introduced by the current preprocessor.
comment|/// However, to provide iteration in source order (for, e.g., chained
comment|/// precompiled headers), dereferencing the iterator flips the negative
comment|/// values (corresponding to loaded entities), so that position -M
comment|/// corresponds to element 0 in the loaded entities vector, position -M+1
comment|/// corresponds to element 1 in the loaded entities vector, etc. This
comment|/// gives us a reasonably efficient, source-order walk.
name|int
name|Position
block|;
name|public
operator|:
typedef|typedef
name|PreprocessedEntity
modifier|*
name|value_type
typedef|;
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|int
name|difference_type
typedef|;
name|iterator
argument_list|()
operator|:
name|Self
argument_list|(
literal|0
argument_list|)
block|,
name|Position
argument_list|(
literal|0
argument_list|)
block|{ }
name|iterator
argument_list|(
argument|PreprocessingRecord *Self
argument_list|,
argument|int Position
argument_list|)
operator|:
name|Self
argument_list|(
name|Self
argument_list|)
block|,
name|Position
argument_list|(
argument|Position
argument_list|)
block|{ }
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|bool
name|isLoaded
operator|=
name|Position
operator|<
literal|0
block|;
name|unsigned
name|Index
operator|=
name|isLoaded
condition|?
name|Self
operator|->
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
operator|+
name|Position
else|:
name|Position
block|;
name|PPEntityID
name|ID
operator|=
name|Self
operator|->
name|getPPEntityID
argument_list|(
name|Index
argument_list|,
name|isLoaded
argument_list|)
block|;
return|return
name|Self
operator|->
name|getPreprocessedEntity
argument_list|(
name|ID
argument_list|)
return|;
block|}
name|value_type
name|operator
index|[]
operator|(
name|difference_type
name|D
operator|)
block|{
return|return
operator|*
operator|(
operator|*
name|this
operator|+
name|D
operator|)
return|;
block|}
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Position
block|;
return|return
operator|*
name|this
return|;
block|}
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|Prev
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
name|Position
block|;
return|return
name|Prev
return|;
block|}
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|Position
block|;
return|return
operator|*
name|this
return|;
block|}
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|Prev
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
name|Position
block|;
return|return
name|Prev
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|==
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|!=
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|<
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|bool
name|operator
operator|>
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|>
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|<
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|>
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|iterator
operator|&
name|operator
operator|+=
operator|(
name|iterator
operator|&
name|X
expr|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
name|friend
name|iterator
operator|&
name|operator
operator|-=
operator|(
name|iterator
operator|&
name|X
expr|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|-=
name|D
block|;
return|return
name|X
return|;
block|}
name|friend
name|iterator
name|operator
operator|+
operator|(
name|iterator
name|X
expr|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
name|friend
name|iterator
name|operator
operator|+
operator|(
name|difference_type
name|D
expr|,
name|iterator
name|X
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
name|friend
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|iterator
operator|&
name|X
expr|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|-
name|Y
operator|.
name|Position
return|;
block|}
name|friend
name|iterator
name|operator
operator|-
operator|(
name|iterator
name|X
expr|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|-=
name|D
block|;
return|return
name|X
return|;
block|}
name|friend
name|class
name|PreprocessingRecord
block|;     }
decl_stmt|;
name|friend
name|class
name|iterator
decl_stmt|;
comment|/// \brief Begin iterator for all preprocessed entities.
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
operator|-
operator|(
name|int
operator|)
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief End iterator for all preprocessed entities.
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|PreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Begin iterator for local, non-loaded, preprocessed entities.
name|iterator
name|local_begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief End iterator for local, non-loaded, preprocessed entities.
name|iterator
name|local_end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|PreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief begin/end iterator pair for the given range of loaded
comment|/// preprocessed entities.
name|std
operator|::
name|pair
operator|<
name|iterator
operator|,
name|iterator
operator|>
name|getIteratorsForLoadedRange
argument_list|(
argument|unsigned start
argument_list|,
argument|unsigned count
argument_list|)
block|{
name|unsigned
name|end
operator|=
name|start
operator|+
name|count
block|;
name|assert
argument_list|(
name|end
operator|<=
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|iterator
argument_list|(
name|this
argument_list|,
name|int
argument_list|(
name|start
argument_list|)
operator|-
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|iterator
argument_list|(
name|this
argument_list|,
name|int
argument_list|(
name|end
argument_list|)
operator|-
name|LoadedPreprocessedEntities
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Returns a pair of [Begin, End) iterators of preprocessed entities
comment|/// that source range \p R encompasses.
comment|///
comment|/// \param R the range to look for preprocessed entities.
comment|///
name|std
operator|::
name|pair
operator|<
name|iterator
operator|,
name|iterator
operator|>
name|getPreprocessedEntitiesInRange
argument_list|(
argument|SourceRange R
argument_list|)
expr_stmt|;
comment|/// \brief Returns true if the preprocessed entity that \p PPEI iterator
comment|/// points to is coming from the file \p FID.
comment|///
comment|/// Can be used to avoid implicit deserializations of preallocated
comment|/// preprocessed entities if we only care about entities of a specific file
comment|/// and not from files \#included in the range given at
comment|/// \see getPreprocessedEntitiesInRange.
name|bool
name|isEntityInFileID
parameter_list|(
name|iterator
name|PPEI
parameter_list|,
name|FileID
name|FID
parameter_list|)
function_decl|;
comment|/// \brief Add a new preprocessed entity to this record.
name|PPEntityID
name|addPreprocessedEntity
parameter_list|(
name|PreprocessedEntity
modifier|*
name|Entity
parameter_list|)
function_decl|;
comment|/// \brief Set the external source for preprocessed entities.
name|void
name|SetExternalSource
parameter_list|(
name|ExternalPreprocessingRecordSource
modifier|&
name|Source
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the external source for preprocessed entities.
name|ExternalPreprocessingRecordSource
operator|*
name|getExternalSource
argument_list|()
specifier|const
block|{
return|return
name|ExternalSource
return|;
block|}
comment|/// \brief Retrieve the macro definition that corresponds to the given
comment|/// \c MacroInfo.
name|MacroDefinition
modifier|*
name|findMacroDefinition
parameter_list|(
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
name|private
label|:
name|virtual
name|void
name|MacroExpands
parameter_list|(
specifier|const
name|Token
modifier|&
name|Id
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|MacroArgs
modifier|*
name|Args
parameter_list|)
function_decl|;
name|virtual
name|void
name|MacroDefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|Id
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
name|virtual
name|void
name|MacroUndefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|Id
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
name|virtual
name|void
name|InclusionDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
specifier|const
name|Token
modifier|&
name|IncludeTok
parameter_list|,
name|StringRef
name|FileName
parameter_list|,
name|bool
name|IsAngled
parameter_list|,
name|CharSourceRange
name|FilenameRange
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|StringRef
name|SearchPath
parameter_list|,
name|StringRef
name|RelativePath
parameter_list|,
specifier|const
name|Module
modifier|*
name|Imported
parameter_list|)
function_decl|;
name|virtual
name|void
name|Ifdef
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
name|virtual
name|void
name|Ifndef
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
comment|/// \brief Hook called whenever the 'defined' operator is seen.
name|virtual
name|void
name|Defined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
function_decl|;
name|void
name|addMacroExpansion
parameter_list|(
specifier|const
name|Token
modifier|&
name|Id
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
function_decl|;
comment|/// \brief Cached result of the last \see getPreprocessedEntitiesInRange
comment|/// query.
struct|struct
block|{
name|SourceRange
name|Range
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|Result
expr_stmt|;
block|}
name|CachedRangeQuery
struct|;
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|getPreprocessedEntitiesInRangeSlow
argument_list|(
argument|SourceRange R
argument_list|)
expr_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_decl_stmt
unit|inline
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
end_decl_stmt

begin_decl_stmt
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

