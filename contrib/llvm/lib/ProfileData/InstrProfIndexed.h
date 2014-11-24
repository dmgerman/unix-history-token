begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- InstrProfIndexed.h - Indexed profiling format support -------*- C++ -*-=//
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
comment|// Shared header for the instrumented profile data reader and writer.
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
name|LLVM_PROFILEDATA_INSTRPROF_INDEXED_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_INSTRPROF_INDEXED_H_
end_define

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|IndexedInstrProf
block|{
name|enum
name|class
name|HashT
range|:
name|uint32_t
block|{
name|MD5
block|,
name|Last
operator|=
name|MD5
block|}
decl_stmt|;
specifier|static
specifier|inline
name|uint64_t
name|MD5Hash
parameter_list|(
name|StringRef
name|Str
parameter_list|)
block|{
name|MD5
name|Hash
decl_stmt|;
name|Hash
operator|.
name|update
argument_list|(
name|Str
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|MD5
operator|::
name|MD5Result
name|Result
expr_stmt|;
name|Hash
operator|.
name|final
argument_list|(
name|Result
argument_list|)
expr_stmt|;
comment|// Return the least significant 8 bytes. Our MD5 implementation returns the
comment|// result in little endian, so we may need to swap bytes.
name|using
name|namespace
name|llvm
operator|::
name|support
expr_stmt|;
return|return
name|endian
operator|::
name|read
operator|<
name|uint64_t
operator|,
name|little
operator|,
name|unaligned
operator|>
operator|(
name|Result
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uint64_t
name|ComputeHash
parameter_list|(
name|HashT
name|Type
parameter_list|,
name|StringRef
name|K
parameter_list|)
block|{
switch|switch
condition|(
name|Type
condition|)
block|{
case|case
name|HashT
operator|::
name|MD5
case|:
return|return
name|IndexedInstrProf
operator|::
name|MD5Hash
argument_list|(
name|K
argument_list|)
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unhandled hash type"
argument_list|)
expr_stmt|;
block|}
specifier|const
name|uint64_t
name|Magic
init|=
literal|0x8169666f72706cff
decl_stmt|;
comment|// "\xfflprofi\x81"
specifier|const
name|uint64_t
name|Version
init|=
literal|1
decl_stmt|;
specifier|const
name|HashT
name|HashType
init|=
name|HashT
operator|::
name|MD5
decl_stmt|;
block|}
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
comment|// LLVM_PROFILEDATA_INSTRPROF_INDEXED_H_
end_comment

end_unit

