begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/ELFTargets.h --------------------------------------===//
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
name|LLD_READER_WRITER_ELF_TARGETS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_TARGETS_H
end_define

begin_include
include|#
directive|include
file|"ELFLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|class TargetName##LinkingContext final : public ELFLinkingContext { \   public: \     static std::unique_ptr<ELFLinkingContext> create(llvm::Triple); \   };
comment|// FIXME: #include "llvm/Config/Targets.def"
name|LLVM_TARGET
argument_list|(
argument|AArch64
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|ARM
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|Hexagon
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|Mips
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|X86
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|Example
argument_list|)
name|LLVM_TARGET
argument_list|(
argument|X86_64
argument_list|)
undef|#
directive|undef
name|LLVM_TARGET
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

