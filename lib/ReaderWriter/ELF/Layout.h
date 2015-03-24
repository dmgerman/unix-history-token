begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Layout.h --------------------------------------===//
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
name|LLD_READER_WRITER_ELF_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_LAYOUT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/DefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/AtomLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The ELFLayout is an abstract class for managing the final layout for
comment|///        the kind of binaries(Shared Libraries / Relocatables / Executables 0
comment|///        Each architecture (Hexagon, MIPS) would have a concrete
comment|///        subclass derived from Layout for generating each binary thats
comment|//         needed by the lld linker
name|class
name|Layout
block|{
name|public
label|:
typedef|typedef
name|uint32_t
name|SectionOrder
typedef|;
typedef|typedef
name|uint32_t
name|SegmentType
typedef|;
typedef|typedef
name|uint32_t
name|Flags
typedef|;
name|public
label|:
comment|/// Return the order the section would appear in the output file
name|virtual
name|SectionOrder
name|getSectionOrder
parameter_list|(
name|StringRef
name|name
parameter_list|,
name|int32_t
name|contentType
parameter_list|,
name|int32_t
name|contentPerm
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Append the Atom to the layout and create appropriate sections.
comment|/// \returns A reference to the atom layout or an error. The atom layout will
comment|/// be updated as linking progresses.
name|virtual
name|ErrorOr
operator|<
specifier|const
name|lld
operator|::
name|AtomLayout
operator|*
operator|>
name|addAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// find the Atom in the current layout
name|virtual
specifier|const
name|AtomLayout
modifier|*
name|findAtomLayoutByName
argument_list|(
name|StringRef
name|name
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// associates a section to a segment
name|virtual
name|void
name|assignSectionsToSegments
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// associates a virtual address to the segment, section, and the atom
name|virtual
name|void
name|assignVirtualAddress
parameter_list|()
init|=
literal|0
function_decl|;
name|public
label|:
name|Layout
argument_list|()
block|{}
name|virtual
operator|~
name|Layout
argument_list|()
block|{ }
block|}
empty_stmt|;
block|}
comment|// end namespace elf
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

