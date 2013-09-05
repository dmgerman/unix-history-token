begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm-objdump.h ----------------------------------------------------===//
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
name|LLVM_OBJDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJDUMP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryObject.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|COFFObjectFile
decl_stmt|;
name|class
name|ObjectFile
decl_stmt|;
name|class
name|RelocationRef
decl_stmt|;
block|}
name|class
name|error_code
decl_stmt|;
extern|extern cl::opt<std::string> TripleName;
extern|extern cl::opt<std::string> ArchName;
comment|// Various helper functions.
name|bool
name|error
parameter_list|(
name|error_code
name|ec
parameter_list|)
function_decl|;
name|bool
name|RelocAddressLess
argument_list|(
name|object
operator|::
name|RelocationRef
name|a
argument_list|,
name|object
operator|::
name|RelocationRef
name|b
argument_list|)
decl_stmt|;
name|void
name|DumpBytes
parameter_list|(
name|StringRef
name|bytes
parameter_list|)
function_decl|;
name|void
name|DisassembleInputMachO
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
function_decl|;
name|void
name|printCOFFUnwindInfo
argument_list|(
specifier|const
name|object
operator|::
name|COFFObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printELFFileHeader
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|class
name|StringRefMemoryObject
range|:
name|public
name|MemoryObject
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|StringRef
name|Bytes
block|;
name|public
operator|:
name|StringRefMemoryObject
argument_list|(
argument|StringRef bytes
argument_list|)
operator|:
name|Bytes
argument_list|(
argument|bytes
argument_list|)
block|{}
name|uint64_t
name|getBase
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|uint64_t
name|getExtent
argument_list|()
specifier|const
block|{
return|return
name|Bytes
operator|.
name|size
argument_list|()
return|;
block|}
name|int
name|readByte
argument_list|(
argument|uint64_t Addr
argument_list|,
argument|uint8_t *Byte
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Addr
operator|>=
name|getExtent
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|Byte
operator|=
name|Bytes
index|[
name|Addr
index|]
block|;
return|return
literal|0
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

