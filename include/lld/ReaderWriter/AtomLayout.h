begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- include/lld/ReaderWriter/AtomLayout.h ------------------------------===//
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
name|LLD_READER_WRITER_ATOM_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ATOM_LAYOUT_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|Atom
decl_stmt|;
comment|/// AtomLayouts are used by a writer to manage physical positions of atoms.
comment|/// AtomLayout has two positions; one is file offset, and the other is the
comment|/// address when loaded into memory.
comment|///
comment|/// Construction of AtomLayouts is usually a multi-pass process. When an atom
comment|/// is appended to a section, we don't know the starting address of the
comment|/// section. Thus, we have no choice but to store the offset from the
comment|/// beginning of the section as AtomLayout values. After all sections starting
comment|/// address are fixed, AtomLayout is revisited to get the offsets updated by
comment|/// adding the starting addresses of the section.
struct|struct
name|AtomLayout
block|{
name|AtomLayout
argument_list|(
argument|const Atom *a
argument_list|,
argument|uint64_t fileOff
argument_list|,
argument|uint64_t virAddr
argument_list|)
block|:
name|_atom
argument_list|(
name|a
argument_list|)
operator|,
name|_fileOffset
argument_list|(
name|fileOff
argument_list|)
operator|,
name|_virtualAddr
argument_list|(
argument|virAddr
argument_list|)
block|{}
name|AtomLayout
argument_list|()
operator|:
name|_atom
argument_list|(
name|nullptr
argument_list|)
operator|,
name|_fileOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|_virtualAddr
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|Atom
operator|*
name|_atom
expr_stmt|;
name|uint64_t
name|_fileOffset
decl_stmt|;
name|uint64_t
name|_virtualAddr
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

