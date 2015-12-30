begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/JamCRC.h - Cyclic Redundancy Check ---------*- C++ -*-===//
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
comment|// This file contains an implementation of JamCRC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We will use the "Rocksoft^tm Model CRC Algorithm" to describe the properties
end_comment

begin_comment
comment|// of this CRC:
end_comment

begin_comment
comment|//   Width  : 32
end_comment

begin_comment
comment|//   Poly   : 04C11DB7
end_comment

begin_comment
comment|//   Init   : FFFFFFFF
end_comment

begin_comment
comment|//   RefIn  : True
end_comment

begin_comment
comment|//   RefOut : True
end_comment

begin_comment
comment|//   XorOut : 00000000
end_comment

begin_comment
comment|//   Check  : 340BC6D9 (result of CRC for "123456789")
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// N.B.  We permit flexibility of the "Init" value.  Some consumers of this need
end_comment

begin_comment
comment|//       it to be zero.
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
name|LLVM_SUPPORT_JAMCRC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_JAMCRC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|JamCRC
block|{
name|public
label|:
name|JamCRC
argument_list|(
argument|uint32_t Init =
literal|0xFFFFFFFFU
argument_list|)
block|:
name|CRC
argument_list|(
argument|Init
argument_list|)
block|{}
comment|// \brief Update the CRC calculation with Data.
name|void
name|update
argument_list|(
name|ArrayRef
operator|<
name|char
operator|>
name|Data
argument_list|)
decl_stmt|;
name|uint32_t
name|getCRC
argument_list|()
specifier|const
block|{
return|return
name|CRC
return|;
block|}
name|private
label|:
name|uint32_t
name|CRC
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

