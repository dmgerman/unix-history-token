begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CVDebugRecord.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_CVDEBUGRECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_CVDEBUGRECORD_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|OMF
block|{
struct|struct
name|Signature
block|{
enum|enum
name|ID
enum|:
name|uint32_t
block|{
name|PDB70
init|=
literal|0x53445352
block|,
comment|// RSDS
name|PDB20
init|=
literal|0x3031424e
block|,
comment|// NB10
name|CV50
init|=
literal|0x3131424e
block|,
comment|// NB11
name|CV41
init|=
literal|0x3930424e
block|,
comment|// NB09
block|}
enum|;
name|support
operator|::
name|ulittle32_t
name|CVSignature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Offset
expr_stmt|;
block|}
struct|;
block|}
name|namespace
name|codeview
block|{
struct|struct
name|PDB70DebugInfo
block|{
name|support
operator|::
name|ulittle32_t
name|CVSignature
expr_stmt|;
name|uint8_t
name|Signature
index|[
literal|16
index|]
decl_stmt|;
name|support
operator|::
name|ulittle32_t
name|Age
expr_stmt|;
comment|// char PDBFileName[];
block|}
struct|;
struct|struct
name|PDB20DebugInfo
block|{
name|support
operator|::
name|ulittle32_t
name|CVSignature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Offset
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Signature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Age
expr_stmt|;
comment|// char PDBFileName[];
block|}
struct|;
union|union
name|DebugInfo
block|{   struct
name|OMF
operator|::
name|Signature
name|Signature
expr_stmt|;
name|struct
name|PDB20DebugInfo
name|PDB20
decl_stmt|;
name|struct
name|PDB70DebugInfo
name|PDB70
decl_stmt|;
block|}
union|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

