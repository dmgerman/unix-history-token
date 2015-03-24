begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/TargetHandler.h -------------------------------===//
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
comment|/// \brief These interfaces provide target specific hooks to change the linker's
end_comment

begin_comment
comment|/// behaivor.
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
name|LLD_READER_WRITER_ELF_TARGET_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_TARGET_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"Layout.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Atom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/STDExtras.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Hashing.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileOutputBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|namespace
name|elf
block|{
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicTable
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicSymbolTable
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ELFDefinedAtom
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ELFReference
expr_stmt|;
name|class
name|ELFWriter
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ELFHeader
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Section
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetLayout
expr_stmt|;
name|class
name|TargetRelocationHandler
block|{
name|public
label|:
comment|/// Constructor
name|TargetRelocationHandler
argument_list|()
block|{}
name|virtual
operator|~
name|TargetRelocationHandler
argument_list|()
block|{}
name|virtual
name|std
operator|::
name|error_code
name|applyRelocation
argument_list|(
argument|ELFWriter&
argument_list|,
argument|llvm::FileOutputBuffer&
argument_list|,
argument|const lld::AtomLayout&
argument_list|,
argument|const Reference&
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief TargetHandler contains all the information responsible to handle a
comment|/// a particular target on ELF. A target might wish to override implementation
comment|/// of creating atoms and how the atoms are written to the output file.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetHandler
operator|:
name|public
name|TargetHandlerBase
block|{
name|public
operator|:
comment|/// The layout determined completely by the Target.
name|virtual
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|getTargetLayout
argument_list|()
operator|=
literal|0
block|;
comment|/// Determine how relocations need to be applied.
name|virtual
specifier|const
name|TargetRelocationHandler
operator|&
name|getRelocationHandler
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// How does the target deal with reading input files.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getObjReader
argument_list|()
operator|=
literal|0
block|;
comment|/// How does the target deal with reading dynamic libraries.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getDSOReader
argument_list|()
operator|=
literal|0
block|;
comment|/// How does the target deal with writing ELF output.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|getWriter
argument_list|()
operator|=
literal|0
block|; }
expr_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_unhandled_reloc_error
argument_list|()
block|{
return|return
name|make_dynamic_error_code
argument_list|(
name|Twine
argument_list|(
literal|"Unhandled reference type"
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|std
operator|::
name|error_code
name|make_out_of_range_reloc_error
argument_list|()
block|{
return|return
name|make_dynamic_error_code
argument_list|(
name|Twine
argument_list|(
literal|"Relocation out of range"
argument_list|)
argument_list|)
return|;
block|}
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

