begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Mips/MipsLinkingContext.h ---------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_LINKING_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_LINKING_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"MipsAbiInfoHandler.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief Mips internal references.
enum|enum
block|{
comment|/// \brief Do nothing but mark GOT entry as a global one.
name|LLD_R_MIPS_GLOBAL_GOT
init|=
literal|1024
block|,
comment|/// \brief Apply high 16 bits of symbol + addend.
name|LLD_R_MIPS_32_HI16
init|=
literal|1025
block|,
comment|/// \brief The same as R_MIPS_26 but for global symbols.
name|LLD_R_MIPS_GLOBAL_26
init|=
literal|1026
block|,
comment|/// \brief Represents a reference between PLT and dynamic symbol.
name|LLD_R_MIPS_STO_PLT
init|=
literal|1029
block|,
comment|/// \brief The same as R_MICROMIPS_26_S1 but for global symbols.
name|LLD_R_MICROMIPS_GLOBAL_26_S1
init|=
literal|1030
block|,
comment|/// \brief Apply high 32+16 bits of symbol + addend.
name|LLD_R_MIPS_64_HI16
init|=
literal|1031
block|, }
enum|;
name|class
name|MipsLinkingContext
name|final
range|:
name|public
name|ELFLinkingContext
block|{
name|public
operator|:
name|MipsLinkingContext
argument_list|(
argument|llvm::Triple triple
argument_list|)
block|;
name|void
name|registerRelocationNames
argument_list|(
argument|Registry&r
argument_list|)
name|override
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
name|EM_MIPS
return|;
block|}
name|uint64_t
name|getBaseAddress
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|entrySymbolName
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getDefaultInterpreter
argument_list|()
specifier|const
name|override
block|;
name|void
name|addPasses
argument_list|(
argument|PassManager&pm
argument_list|)
name|override
block|;
name|bool
name|isRelaOutputFormat
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|isDynamicRelocation
argument_list|(
argument|const Reference&r
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCopyRelocation
argument_list|(
argument|const Reference&r
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isPLTRelocation
argument_list|(
argument|const Reference&r
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isRelativeReloc
argument_list|(
argument|const Reference&r
argument_list|)
specifier|const
name|override
block|;
name|MipsAbi
name|getAbi
argument_list|()
specifier|const
block|; }
decl_stmt|;
block|}
comment|// elf
block|}
end_decl_stmt

begin_comment
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

