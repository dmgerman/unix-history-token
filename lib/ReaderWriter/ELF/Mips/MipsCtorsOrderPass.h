begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Mips/MipsCtorsOrderPass.h ---------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_CTORS_ORDER_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_CTORS_ORDER_PASS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief This pass sorts atoms in .{ctors,dtors}.<priority> sections.
name|class
name|MipsCtorsOrderPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|std
operator|::
name|error_code
name|perform
argument_list|(
argument|SimpleFile&mergedFile
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

