begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/ByteStreamer.h - ByteStreamer class --------*- C++ -*-===//
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
comment|// This file contains a class that can take bytes that would normally be
end_comment

begin_comment
comment|// streamed via the AsmPrinter.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_BYTESTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_BYTESTREAMER_H
end_define

begin_include
include|#
directive|include
file|"DIEHash.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ByteStreamer
block|{
name|public
label|:
name|virtual
operator|~
name|ByteStreamer
argument_list|()
block|{}
comment|// For now we're just handling the calls we need for dwarf emission/hashing.
name|virtual
name|void
name|EmitInt8
argument_list|(
argument|uint8_t Byte
argument_list|,
argument|const Twine&Comment =
literal|""
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|EmitSLEB128
parameter_list|(
name|uint64_t
name|DWord
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Comment
init|=
literal|""
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|EmitULEB128
parameter_list|(
name|uint64_t
name|DWord
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Comment
init|=
literal|""
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|class
name|APByteStreamer
range|:
name|public
name|ByteStreamer
block|{
name|private
operator|:
name|AsmPrinter
operator|&
name|AP
block|;
name|public
operator|:
name|APByteStreamer
argument_list|(
name|AsmPrinter
operator|&
name|Asm
argument_list|)
operator|:
name|AP
argument_list|(
argument|Asm
argument_list|)
block|{}
name|void
name|EmitInt8
argument_list|(
argument|uint8_t Byte
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|AP
operator|.
name|OutStreamer
operator|.
name|AddComment
argument_list|(
name|Comment
argument_list|)
block|;
name|AP
operator|.
name|EmitInt8
argument_list|(
name|Byte
argument_list|)
block|;   }
name|void
name|EmitSLEB128
argument_list|(
argument|uint64_t DWord
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|AP
operator|.
name|OutStreamer
operator|.
name|AddComment
argument_list|(
name|Comment
argument_list|)
block|;
name|AP
operator|.
name|EmitSLEB128
argument_list|(
name|DWord
argument_list|)
block|;   }
name|void
name|EmitULEB128
argument_list|(
argument|uint64_t DWord
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|AP
operator|.
name|OutStreamer
operator|.
name|AddComment
argument_list|(
name|Comment
argument_list|)
block|;
name|AP
operator|.
name|EmitULEB128
argument_list|(
name|DWord
argument_list|)
block|;   }
block|}
decl_stmt|;
name|class
name|HashingByteStreamer
range|:
name|public
name|ByteStreamer
block|{
name|private
operator|:
name|DIEHash
operator|&
name|Hash
block|;
name|public
operator|:
name|HashingByteStreamer
argument_list|(
name|DIEHash
operator|&
name|H
argument_list|)
operator|:
name|Hash
argument_list|(
argument|H
argument_list|)
block|{}
name|void
name|EmitInt8
argument_list|(
argument|uint8_t Byte
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|Hash
operator|.
name|update
argument_list|(
name|Byte
argument_list|)
block|;   }
name|void
name|EmitSLEB128
argument_list|(
argument|uint64_t DWord
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|Hash
operator|.
name|addSLEB128
argument_list|(
name|DWord
argument_list|)
block|;   }
name|void
name|EmitULEB128
argument_list|(
argument|uint64_t DWord
argument_list|,
argument|const Twine&Comment
argument_list|)
name|override
block|{
name|Hash
operator|.
name|addULEB128
argument_list|(
name|DWord
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

