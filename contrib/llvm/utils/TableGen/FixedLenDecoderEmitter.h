begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------ FixedLenDecoderEmitter.h - Decoder Generator --*- C++ -*-===//
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
comment|// It contains the tablegen backend that emits the decoder functions for
end_comment

begin_comment
comment|// targets with fixed length instruction set.
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
name|FixedLenDECODEREMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|FixedLenDECODEREMITTER_H
end_define

begin_include
include|#
directive|include
file|"CodeGenTarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/TableGenBackend.h"
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
struct|struct
name|EncodingField
block|{
name|unsigned
name|Base
decl_stmt|,
name|Width
decl_stmt|,
name|Offset
decl_stmt|;
name|EncodingField
argument_list|(
argument|unsigned B
argument_list|,
argument|unsigned W
argument_list|,
argument|unsigned O
argument_list|)
block|:
name|Base
argument_list|(
name|B
argument_list|)
operator|,
name|Width
argument_list|(
name|W
argument_list|)
operator|,
name|Offset
argument_list|(
argument|O
argument_list|)
block|{ }
block|}
struct|;
struct|struct
name|OperandInfo
block|{
name|std
operator|::
name|vector
operator|<
name|EncodingField
operator|>
name|Fields
expr_stmt|;
name|std
operator|::
name|string
name|Decoder
expr_stmt|;
name|OperandInfo
argument_list|(
argument|std::string D
argument_list|)
block|:
name|Decoder
argument_list|(
argument|D
argument_list|)
block|{ }
name|void
name|addField
parameter_list|(
name|unsigned
name|Base
parameter_list|,
name|unsigned
name|Width
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
block|{
name|Fields
operator|.
name|push_back
argument_list|(
name|EncodingField
argument_list|(
name|Base
argument_list|,
name|Width
argument_list|,
name|Offset
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|numFields
argument_list|()
specifier|const
block|{
return|return
name|Fields
operator|.
name|size
argument_list|()
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|EncodingField
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Fields
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Fields
operator|.
name|end
argument_list|()
return|;
block|}
block|}
struct|;
name|class
name|FixedLenDecoderEmitter
range|:
name|public
name|TableGenBackend
block|{
name|public
operator|:
name|FixedLenDecoderEmitter
argument_list|(
argument|RecordKeeper&R
argument_list|,
argument|std::string PredicateNamespace
argument_list|,
argument|std::string GPrefix  =
literal|"if ("
argument_list|,
argument|std::string GPostfix =
literal|" == MCDisassembler::Fail)"
literal|" return MCDisassembler::Fail;"
argument_list|,
argument|std::string ROK      =
literal|"MCDisassembler::Success"
argument_list|,
argument|std::string RFail    =
literal|"MCDisassembler::Fail"
argument_list|,
argument|std::string L        =
literal|""
argument_list|)
operator|:
name|Target
argument_list|(
name|R
argument_list|)
block|,
name|PredicateNamespace
argument_list|(
name|PredicateNamespace
argument_list|)
block|,
name|GuardPrefix
argument_list|(
name|GPrefix
argument_list|)
block|,
name|GuardPostfix
argument_list|(
name|GPostfix
argument_list|)
block|,
name|ReturnOK
argument_list|(
name|ROK
argument_list|)
block|,
name|ReturnFail
argument_list|(
name|RFail
argument_list|)
block|,
name|Locals
argument_list|(
argument|L
argument_list|)
block|{}
comment|// run - Output the code emitter
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|private
operator|:
name|CodeGenTarget
name|Target
block|;
name|public
operator|:
name|std
operator|::
name|string
name|PredicateNamespace
block|;
name|std
operator|::
name|string
name|GuardPrefix
block|,
name|GuardPostfix
block|;
name|std
operator|::
name|string
name|ReturnOK
block|,
name|ReturnFail
block|;
name|std
operator|::
name|string
name|Locals
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

