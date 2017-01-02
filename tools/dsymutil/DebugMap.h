begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== tools/dsymutil/DebugMap.h - Generic debug map representation -*- C++ -*-//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file contains the class declaration of the DebugMap
end_comment

begin_comment
comment|/// entity. A DebugMap lists all the object files linked together to
end_comment

begin_comment
comment|/// produce an executable along with the linked address of all the
end_comment

begin_comment
comment|/// atoms used in these object files.
end_comment

begin_comment
comment|/// The DebugMap is an input to the DwarfLinker class that will
end_comment

begin_comment
comment|/// extract the Dwarf debug information from the referenced object
end_comment

begin_comment
comment|/// files and link their usefull debug info together.
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
name|LLVM_TOOLS_DSYMUTIL_DEBUGMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_DEBUGMAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
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
name|raw_ostream
decl_stmt|;
name|namespace
name|dsymutil
block|{
name|class
name|DebugMapObject
decl_stmt|;
comment|/// \brief The DebugMap object stores the list of object files to
comment|/// query for debug information along with the mapping between the
comment|/// symbols' addresses in the object file to their linked address in
comment|/// the linked binary.
comment|///
comment|/// A DebugMap producer could look like this:
comment|/// DebugMap *DM = new DebugMap();
comment|/// for (const auto&Obj: LinkedObjects) {
comment|///     DebugMapObject&DMO = DM->addDebugMapObject(Obj.getPath());
comment|///     for (const auto&Sym: Obj.getLinkedSymbols())
comment|///         DMO.addSymbol(Sym.getName(), Sym.getObjectFileAddress(),
comment|///                       Sym.getBinaryAddress());
comment|/// }
comment|///
comment|/// A DebugMap consumer can then use the map to link the debug
comment|/// information. For example something along the lines of:
comment|/// for (const auto&DMO: DM->objects()) {
comment|///     auto Obj = createBinary(DMO.getObjectFilename());
comment|///     for (auto&DIE: Obj.getDwarfDIEs()) {
comment|///         if (SymbolMapping *Sym = DMO.lookup(DIE.getName()))
comment|///             DIE.relocate(Sym->ObjectAddress, Sym->BinaryAddress);
comment|///         else
comment|///             DIE.discardSubtree();
comment|///     }
comment|/// }
name|class
name|DebugMap
block|{
name|Triple
name|BinaryTriple
decl_stmt|;
name|std
operator|::
name|string
name|BinaryPath
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMapObject
operator|>>
name|ObjectContainer
expr_stmt|;
name|ObjectContainer
name|Objects
decl_stmt|;
comment|/// For YAML IO support.
comment|///@{
name|friend
name|yaml
operator|::
name|MappingTraits
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMap
operator|>>
expr_stmt|;
name|friend
name|yaml
operator|::
name|MappingTraits
operator|<
name|DebugMap
operator|>
expr_stmt|;
name|DebugMap
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|///@}
name|public
label|:
name|DebugMap
argument_list|(
argument|const Triple&BinaryTriple
argument_list|,
argument|StringRef BinaryPath
argument_list|)
block|:
name|BinaryTriple
argument_list|(
name|BinaryTriple
argument_list|)
operator|,
name|BinaryPath
argument_list|(
argument|BinaryPath
argument_list|)
block|{}
typedef|typedef
name|ObjectContainer
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator_range
operator|<
name|const_iterator
operator|>
name|objects
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Objects
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
name|Objects
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// This function adds an DebugMapObject to the list owned by this
comment|/// debug map.
name|DebugMapObject
modifier|&
name|addDebugMapObject
argument_list|(
name|StringRef
name|ObjectFilePath
argument_list|,
name|sys
operator|::
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|>
name|Timestamp
argument_list|)
decl_stmt|;
specifier|const
name|Triple
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|BinaryTriple
return|;
block|}
name|StringRef
name|getBinaryPath
argument_list|()
specifier|const
block|{
return|return
name|BinaryPath
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|/// Read a debug map for \a InputFile.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMap
operator|>>>
name|parseYAMLDebugMap
argument_list|(
argument|StringRef InputFile
argument_list|,
argument|StringRef PrependPath
argument_list|,
argument|bool Verbose
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief The DebugMapObject represents one object file described by
comment|/// the DebugMap. It contains a list of mappings between addresses in
comment|/// the object file and in the linked binary for all the linked atoms
comment|/// in this object file.
name|class
name|DebugMapObject
block|{
name|public
label|:
struct|struct
name|SymbolMapping
block|{
name|Optional
operator|<
name|yaml
operator|::
name|Hex64
operator|>
name|ObjectAddress
expr_stmt|;
name|yaml
operator|::
name|Hex64
name|BinaryAddress
expr_stmt|;
name|yaml
operator|::
name|Hex32
name|Size
expr_stmt|;
name|SymbolMapping
argument_list|(
argument|Optional<uint64_t> ObjectAddr
argument_list|,
argument|uint64_t BinaryAddress
argument_list|,
argument|uint32_t Size
argument_list|)
block|:
name|BinaryAddress
argument_list|(
name|BinaryAddress
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{
if|if
condition|(
name|ObjectAddr
condition|)
name|ObjectAddress
operator|=
operator|*
name|ObjectAddr
expr_stmt|;
block|}
comment|/// For YAML IO support
name|SymbolMapping
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|SymbolMapping
operator|>
name|YAMLSymbolMapping
expr_stmt|;
typedef|typedef
name|StringMapEntry
operator|<
name|SymbolMapping
operator|>
name|DebugMapEntry
expr_stmt|;
comment|/// \brief Adds a symbol mapping to this DebugMapObject.
comment|/// \returns false if the symbol was already registered. The request
comment|/// is discarded in this case.
name|bool
name|addSymbol
argument_list|(
name|llvm
operator|::
name|StringRef
name|SymName
argument_list|,
name|Optional
operator|<
name|uint64_t
operator|>
name|ObjectAddress
argument_list|,
name|uint64_t
name|LinkedAddress
argument_list|,
name|uint32_t
name|Size
argument_list|)
decl_stmt|;
comment|/// \brief Lookup a symbol mapping.
comment|/// \returns null if the symbol isn't found.
specifier|const
name|DebugMapEntry
modifier|*
name|lookupSymbol
argument_list|(
name|StringRef
name|SymbolName
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Lookup an objectfile address.
comment|/// \returns null if the address isn't found.
specifier|const
name|DebugMapEntry
modifier|*
name|lookupObjectAddress
argument_list|(
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
name|llvm
operator|::
name|StringRef
name|getObjectFilename
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
name|sys
operator|::
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|>
name|getTimestamp
argument_list|()
specifier|const
block|{
return|return
name|Timestamp
return|;
block|}
name|iterator_range
operator|<
name|StringMap
operator|<
name|SymbolMapping
operator|>
operator|::
name|const_iterator
operator|>
name|symbols
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|Symbols
operator|.
name|begin
argument_list|()
argument_list|,
name|Symbols
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|friend
name|class
name|DebugMap
decl_stmt|;
comment|/// DebugMapObjects can only be constructed by the owning DebugMap.
name|DebugMapObject
argument_list|(
argument|StringRef ObjectFilename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp
argument_list|)
empty_stmt|;
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|sys
operator|::
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|>
name|Timestamp
expr_stmt|;
name|StringMap
operator|<
name|SymbolMapping
operator|>
name|Symbols
expr_stmt|;
name|DenseMap
operator|<
name|uint64_t
operator|,
name|DebugMapEntry
operator|*
operator|>
name|AddressToMapping
expr_stmt|;
comment|/// For YAMLIO support.
comment|///@{
name|friend
name|yaml
operator|::
name|MappingTraits
operator|<
name|dsymutil
operator|::
name|DebugMapObject
operator|>
expr_stmt|;
name|friend
name|yaml
operator|::
name|SequenceTraits
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMapObject
operator|>>>
expr_stmt|;
name|DebugMapObject
argument_list|()
operator|=
expr|default
expr_stmt|;
name|public
label|:
name|DebugMapObject
argument_list|(
name|DebugMapObject
operator|&&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|DebugMapObject
modifier|&
name|operator
init|=
operator|(
name|DebugMapObject
operator|&&
operator|)
operator|=
expr|default
decl_stmt|;
comment|///@}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|llvm::dsymutil::DebugMapObject::YAMLSymbolMapping
argument_list|)
end_macro

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
name|using
name|namespace
name|llvm
operator|::
name|dsymutil
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|DebugMapObject
operator|::
name|SymbolMapping
operator|>>
block|{
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|DebugMapObject
operator|::
name|SymbolMapping
operator|>
operator|&
name|s
argument_list|)
block|;
specifier|static
specifier|const
name|bool
name|flow
operator|=
name|true
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|dsymutil
operator|::
name|DebugMapObject
operator|>
block|{   struct
name|YamlDMO
block|;
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|dsymutil
operator|::
name|DebugMapObject
operator|&
name|DMO
argument_list|)
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ScalarTraits
operator|<
name|Triple
operator|>
block|{
specifier|static
name|void
name|output
argument_list|(
specifier|const
name|Triple
operator|&
name|val
argument_list|,
name|void
operator|*
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|out
argument_list|)
block|;
specifier|static
name|StringRef
name|input
argument_list|(
argument|StringRef scalar
argument_list|,
argument|void *
argument_list|,
argument|Triple&value
argument_list|)
block|;
specifier|static
name|bool
name|mustQuote
argument_list|(
argument|StringRef
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|SequenceTraits
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|dsymutil
operator|::
name|DebugMapObject
operator|>>>
block|{
specifier|static
name|size_t
name|size
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|dsymutil
operator|::
name|DebugMapObject
operator|>>
operator|&
name|seq
argument_list|)
block|;
specifier|static
name|dsymutil
operator|::
name|DebugMapObject
operator|&
name|element
argument_list|(
argument|IO&
argument_list|,
argument|std::vector<std::unique_ptr<dsymutil::DebugMapObject>>&seq
argument_list|,
argument|size_t index
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|dsymutil
operator|::
name|DebugMap
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|dsymutil
operator|::
name|DebugMap
operator|&
name|DM
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|dsymutil
operator|::
name|DebugMap
operator|>>
block|{
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|dsymutil
operator|::
name|DebugMap
operator|>
operator|&
name|DM
argument_list|)
block|; }
block|; }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_DSYMUTIL_DEBUGMAP_H
end_comment

end_unit

