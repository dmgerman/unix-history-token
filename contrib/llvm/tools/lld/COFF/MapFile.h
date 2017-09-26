begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MapFile.h ------------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_MAPFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_MAPFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|class
name|OutputSection
decl_stmt|;
name|void
name|writeMapFile
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|OutputSection
operator|*
operator|>
name|OutputSections
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

