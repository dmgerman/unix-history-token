begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86/X86LinkingContext.h -----------------------===//
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
name|LLD_READER_WRITER_ELF_X86_TARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_TARGETINFO_H
end_define

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|X86LinkingContext
name|final
range|:
name|public
name|ELFLinkingContext
block|{
name|public
operator|:
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|create
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
block|;
name|int
name|getMachineType
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|ELF
operator|::
name|EM_386
return|;
block|}
name|X86LinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
block|;
name|void
name|registerRelocationNames
argument_list|(
argument|Registry&r
argument_list|)
name|override
block|;
comment|/// \brief X86 has only two relative relocation
comment|/// a) for supporting IFUNC relocs - R_386_IRELATIVE
comment|/// b) for supporting relative relocs - R_386_RELATIVE
name|bool
name|isRelativeReloc
argument_list|(
argument|const Reference&r
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|r
operator|.
name|kindNamespace
argument_list|()
operator|!=
name|Reference
operator|::
name|KindNamespace
operator|::
name|ELF
condition|)
return|return
name|false
return|;
name|assert
argument_list|(
name|r
operator|.
name|kindArch
argument_list|()
operator|==
name|Reference
operator|::
name|KindArch
operator|::
name|x86
argument_list|)
block|;
switch|switch
condition|(
name|r
operator|.
name|kindValue
argument_list|()
condition|)
block|{
case|case
name|llvm
operator|::
name|ELF
operator|::
name|R_386_IRELATIVE
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|R_386_RELATIVE
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

