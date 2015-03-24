begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Hexagon/HexagonLinkingContext.h ---------------===//
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
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_LINKING_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_LINKING_CONTEXT_H
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
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|ELFType
operator|<
name|llvm
operator|::
name|support
operator|::
name|little
operator|,
literal|2
operator|,
name|false
operator|>
name|HexagonELFType
expr_stmt|;
name|class
name|HexagonLinkingContext
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
name|HexagonLinkingContext
argument_list|(
argument|llvm::Triple triple
argument_list|)
block|;
name|void
name|addPasses
argument_list|(
argument|PassManager&
argument_list|)
name|override
block|;
name|bool
name|isDynamicRelocation
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
name|R_HEX_RELATIVE
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|R_HEX_GLOB_DAT
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
name|bool
name|isPLTRelocation
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
name|R_HEX_JMP_SLOT
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
comment|/// \brief Hexagon has only one relative relocation
comment|/// a) for supporting relative relocs - R_HEX_RELATIVE
name|bool
name|isRelativeReloc
argument_list|(
specifier|const
name|Reference
operator|&
name|r
argument_list|)
decl|const
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
name|R_HEX_RELATIVE
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// elf
end_comment

begin_comment
unit|}
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_LINKING_CONTEXT_H
end_comment

end_unit

