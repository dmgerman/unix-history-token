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
file|"lld/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
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
literal|"Unhandled reference type"
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
literal|"Relocation out of range"
argument_list|)
return|;
block|}
specifier|inline
name|std
operator|::
name|error_code
name|make_unaligned_range_reloc_error
argument_list|()
block|{
return|return
name|make_dynamic_error_code
argument_list|(
literal|"Relocation not aligned"
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

