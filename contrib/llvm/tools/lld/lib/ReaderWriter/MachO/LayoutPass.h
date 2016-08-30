begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ lib/ReaderWriter/MachO/LayoutPass.h - Handles Layout of atoms -===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_MACHO_LAYOUT_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_LAYOUT_PASS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reader.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|DefinedAtom
decl_stmt|;
name|class
name|SimpleFile
decl_stmt|;
name|namespace
name|mach_o
block|{
comment|/// This linker pass does the layout of the atoms. The pass is done after the
comment|/// order their .o files were found on the command line, then by order of the
comment|/// atoms (address) in the .o file.  But some atoms have a preferred location
comment|/// in their section (such as pinned to the start or end of the section), so
comment|/// the sort must take that into account too.
name|class
name|LayoutPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
expr|struct
name|SortKey
block|{
name|SortKey
argument_list|(
argument|OwningAtomPtr<DefinedAtom>&&atom
argument_list|,
argument|const DefinedAtom *root
argument_list|,
argument|uint64_t override
argument_list|)
operator|:
name|_atom
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|atom
argument_list|)
argument_list|)
block|,
name|_root
argument_list|(
name|root
argument_list|)
block|,
name|_override
argument_list|(
argument|override
argument_list|)
block|{}
name|OwningAtomPtr
operator|<
name|DefinedAtom
operator|>
name|_atom
block|;
specifier|const
name|DefinedAtom
operator|*
name|_root
block|;
name|uint64_t
name|_override
block|;
comment|// Note, these are only here to appease MSVC bots which didn't like
comment|// the same methods being implemented/deleted in OwningAtomPtr.
name|SortKey
argument_list|(
name|SortKey
operator|&&
name|key
argument_list|)
operator|:
name|_atom
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|key
operator|.
name|_atom
argument_list|)
argument_list|)
block|,
name|_root
argument_list|(
name|key
operator|.
name|_root
argument_list|)
block|,
name|_override
argument_list|(
argument|key._override
argument_list|)
block|{
name|key
operator|.
name|_root
operator|=
name|nullptr
block|;     }
name|SortKey
operator|&
name|operator
operator|=
operator|(
name|SortKey
operator|&&
name|key
operator|)
block|{
name|_atom
operator|=
name|std
operator|::
name|move
argument_list|(
name|key
operator|.
name|_atom
argument_list|)
block|;
name|_root
operator|=
name|key
operator|.
name|_root
block|;
name|key
operator|.
name|_root
operator|=
name|nullptr
block|;
name|_override
operator|=
name|key
operator|.
name|_override
block|;
return|return
operator|*
name|this
return|;
block|}
name|private
operator|:
name|SortKey
argument_list|(
specifier|const
name|SortKey
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|SortKey
operator|&
operator|)
operator|=
name|delete
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|DefinedAtom
operator|*
name|left
argument_list|,
specifier|const
name|DefinedAtom
operator|*
name|right
argument_list|,
name|bool
operator|&
name|leftBeforeRight
argument_list|)
operator|>
name|SortOverride
expr_stmt|;
name|LayoutPass
argument_list|(
argument|const Registry&registry
argument_list|,
argument|SortOverride sorter
argument_list|)
decl_stmt|;
comment|/// Sorts atoms in mergedFile by content type then by command line order.
name|llvm
operator|::
name|Error
name|perform
argument_list|(
argument|SimpleFile&mergedFile
argument_list|)
name|override
expr_stmt|;
operator|~
name|LayoutPass
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
name|private
label|:
comment|// Build the followOn atoms chain as specified by the kindLayoutAfter
comment|// reference type
name|void
name|buildFollowOnTable
argument_list|(
specifier|const
name|File
operator|::
name|AtomRange
operator|<
name|DefinedAtom
operator|>
operator|&
name|range
argument_list|)
decl_stmt|;
comment|// Build a map of Atoms to ordinals for sorting the atoms
name|void
name|buildOrdinalOverrideMap
argument_list|(
specifier|const
name|File
operator|::
name|AtomRange
operator|<
name|DefinedAtom
operator|>
operator|&
name|range
argument_list|)
decl_stmt|;
specifier|const
name|Registry
modifier|&
name|_registry
decl_stmt|;
name|SortOverride
name|_customSorter
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DefinedAtom
operator|*
operator|,
specifier|const
name|DefinedAtom
operator|*
operator|>
name|AtomToAtomT
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DefinedAtom
operator|*
operator|,
name|uint64_t
operator|>
name|AtomToOrdinalT
expr_stmt|;
comment|// A map to be used to sort atoms. It represents the order of atoms in the
comment|// result; if Atom X is mapped to atom Y in this map, X will be located
comment|// immediately before Y in the output file. Y might be mapped to another
comment|// atom, constructing a follow-on chain. An atom cannot be mapped to more
comment|// than one atom unless all but one atom are of size zero.
name|AtomToAtomT
name|_followOnNexts
decl_stmt|;
comment|// A map to be used to sort atoms. It's a map from an atom to its root of
comment|// follow-on chain. A root atom is mapped to itself. If an atom is not in
comment|// _followOnNexts, the atom is not in this map, and vice versa.
name|AtomToAtomT
name|_followOnRoots
decl_stmt|;
name|AtomToOrdinalT
name|_ordinalOverrideMap
decl_stmt|;
comment|// Helper methods for buildFollowOnTable().
specifier|const
name|DefinedAtom
modifier|*
name|findAtomFollowedBy
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|targetAtom
parameter_list|)
function_decl|;
name|bool
name|checkAllPrevAtomsZeroSize
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|targetAtom
parameter_list|)
function_decl|;
name|void
name|setChainRoot
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|targetAtom
parameter_list|,
specifier|const
name|DefinedAtom
modifier|*
name|root
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|SortKey
operator|>
name|decorate
argument_list|(
argument|File::AtomRange<DefinedAtom>&atomRange
argument_list|)
specifier|const
expr_stmt|;
name|void
name|undecorate
argument_list|(
name|File
operator|::
name|AtomRange
operator|<
name|DefinedAtom
operator|>
operator|&
name|atomRange
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SortKey
operator|>
operator|&
name|keys
argument_list|)
decl|const
decl_stmt|;
comment|// Check if the follow-on graph is a correct structure. For debugging only.
name|void
name|checkFollowonChain
argument_list|(
specifier|const
name|File
operator|::
name|AtomRange
operator|<
name|DefinedAtom
operator|>
operator|&
name|range
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace mach_o
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_MACHO_LAYOUT_PASS_H
end_comment

end_unit

