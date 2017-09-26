begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GSI.h - Common Declarations for GlobalsStream and PublicsStream ----===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// The data structures defined in this file are based on the reference
end_comment

begin_comment
comment|// implementation which is available at
end_comment

begin_comment
comment|// https://github.com/Microsoft/microsoft-pdb/blob/master/PDB/dbi/gsi.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When you are reading the reference source code, you'd find the
end_comment

begin_comment
comment|// information below useful.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  - ppdb1->m_fMinimalDbgInfo seems to be always true.
end_comment

begin_comment
comment|//  - SMALLBUCKETS macro is defined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The reference doesn't compile, so I learned just by reading code.
end_comment

begin_comment
comment|// It's not guaranteed to be correct.
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
name|LLVM_LIB_DEBUGINFO_PDB_RAW_GSI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_PDB_RAW_GSI_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
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
comment|/// From https://github.com/Microsoft/microsoft-pdb/blob/master/PDB/dbi/gsi.cpp
specifier|static
specifier|const
name|unsigned
name|IPHR_HASH
init|=
literal|4096
decl_stmt|;
comment|/// Header of the hash tables found in the globals and publics sections.
comment|/// Based on GSIHashHeader in
comment|/// https://github.com/Microsoft/microsoft-pdb/blob/master/PDB/dbi/gsi.h
struct|struct
name|GSIHashHeader
block|{
enum_decl|enum :
name|unsigned
block|{
name|HdrSignature
init|=
operator|~
literal|0U
block|,
name|HdrVersion
init|=
literal|0xeffe0000
operator|+
literal|19990810
block|,   }
enum_decl|;
name|support
operator|::
name|ulittle32_t
name|VerSignature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|VerHdr
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|HrSize
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|NumBuckets
expr_stmt|;
block|}
struct|;
name|Error
name|readGSIHashBuckets
argument_list|(
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
operator|&
name|HashBuckets
argument_list|,
specifier|const
name|GSIHashHeader
operator|*
name|HashHdr
argument_list|,
name|BinaryStreamReader
operator|&
name|Reader
argument_list|)
decl_stmt|;
name|Error
name|readGSIHashHeader
parameter_list|(
specifier|const
name|GSIHashHeader
modifier|*
modifier|&
name|HashHdr
parameter_list|,
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
name|Error
name|readGSIHashRecords
argument_list|(
name|FixedStreamArray
operator|<
name|PSHashRecord
operator|>
operator|&
name|HashRecords
argument_list|,
specifier|const
name|GSIHashHeader
operator|*
name|HashHdr
argument_list|,
name|BinaryStreamReader
operator|&
name|Reader
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

