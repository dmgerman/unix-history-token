begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/AArch64/AArch64RelocationHandler.h ------------===//
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
name|AARCH64_RELOCATION_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|AARCH64_RELOCATION_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"AArch64TargetHandler.h"
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
name|true
operator|>
name|AArch64ELFType
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|AArch64TargetLayout
expr_stmt|;
name|class
name|AArch64TargetRelocationHandler
name|final
range|:
name|public
name|TargetRelocationHandler
block|{
name|public
operator|:
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
name|override
block|;
specifier|static
specifier|const
name|Registry
operator|::
name|KindStrings
name|kindStrings
index|[]
block|; }
decl_stmt|;
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

begin_comment
comment|// AArch64_RELOCATION_HANDLER_H
end_comment

end_unit

