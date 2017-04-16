begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringTable.h - PDB String Table -------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_RAW_STRINGTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_STRINGTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|StringTable
block|{
name|public
label|:
name|StringTable
argument_list|()
expr_stmt|;
name|Error
name|load
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Stream
parameter_list|)
function_decl|;
name|uint32_t
name|getByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getNameCount
argument_list|()
specifier|const
block|{
return|return
name|NameCount
return|;
block|}
name|uint32_t
name|getHashVersion
argument_list|()
specifier|const
block|{
return|return
name|HashVersion
return|;
block|}
name|uint32_t
name|getSignature
argument_list|()
specifier|const
block|{
return|return
name|Signature
return|;
block|}
name|StringRef
name|getStringForID
argument_list|(
name|uint32_t
name|ID
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|getIDForString
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|name_ids
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|BinaryStreamRef
name|NamesBuffer
decl_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|IDs
expr_stmt|;
name|uint32_t
name|ByteSize
init|=
literal|0
decl_stmt|;
name|uint32_t
name|Signature
init|=
literal|0
decl_stmt|;
name|uint32_t
name|HashVersion
init|=
literal|0
decl_stmt|;
name|uint32_t
name|NameCount
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_RAW_STRINGTABLE_H
end_comment

end_unit

