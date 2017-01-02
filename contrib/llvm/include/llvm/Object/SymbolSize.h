begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolSize.h ---------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OBJECT_SYMBOLSIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_SYMBOLSIZE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
struct|struct
name|SymEntry
block|{
name|symbol_iterator
name|I
decl_stmt|;
name|uint64_t
name|Address
decl_stmt|;
name|unsigned
name|Number
decl_stmt|;
name|unsigned
name|SectionID
decl_stmt|;
block|}
struct|;
name|int
name|compareAddress
parameter_list|(
specifier|const
name|SymEntry
modifier|*
name|A
parameter_list|,
specifier|const
name|SymEntry
modifier|*
name|B
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|SymbolRef
operator|,
name|uint64_t
operator|>>
name|computeSymbolSizes
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|O
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

