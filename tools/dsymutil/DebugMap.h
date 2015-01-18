begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- tools/dsymutil/DebugMap.h - Generic debug map representation -------===//
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
file|"llvm/ADT/StringMap.h"
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
name|public
label|:
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
parameter_list|(
name|StringRef
name|ObjectFilePath
parameter_list|)
function_decl|;
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
name|uint64_t
name|ObjectAddress
decl_stmt|;
name|uint64_t
name|BinaryAddress
decl_stmt|;
name|SymbolMapping
argument_list|(
argument|uint64_t ObjectAddress
argument_list|,
argument|uint64_t BinaryAddress
argument_list|)
block|:
name|ObjectAddress
argument_list|(
name|ObjectAddress
argument_list|)
operator|,
name|BinaryAddress
argument_list|(
argument|BinaryAddress
argument_list|)
block|{}
block|}
struct|;
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
name|uint64_t
name|ObjectAddress
argument_list|,
name|uint64_t
name|LinkedAddress
argument_list|)
decl_stmt|;
comment|/// \brief Lookup a symbol mapping.
comment|/// \returns null if the symbol isn't found.
specifier|const
name|SymbolMapping
modifier|*
name|lookupSymbol
argument_list|(
name|StringRef
name|SymbolName
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
argument_list|)
empty_stmt|;
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|StringMap
operator|<
name|SymbolMapping
operator|>
name|Symbols
expr_stmt|;
block|}
empty_stmt|;
block|}
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

