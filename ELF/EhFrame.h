begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- EhFrame.h ------------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_EHFRAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_EHFRAME_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|InputSectionBase
decl_stmt|;
struct_decl|struct
name|EhSectionPiece
struct_decl|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|size_t
name|readEhRecordSize
argument_list|(
argument|InputSectionBase *S
argument_list|,
argument|size_t Off
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint8_t
name|getFdeEncoding
argument_list|(
name|EhSectionPiece
operator|*
name|P
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

