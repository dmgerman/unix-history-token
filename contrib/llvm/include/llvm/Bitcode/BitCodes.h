begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BitCodes.h - Enum values for the bitcode format ----------*- C++ -*-===//
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
comment|// This header Bitcode enum values.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The enum values defined in this file should be considered permanent.  If
end_comment

begin_comment
comment|// new features are added, they should have values added at the end of the
end_comment

begin_comment
comment|// respective lists.
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
name|LLVM_BITCODE_BITCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_BITCODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|bitc
block|{
enum|enum
name|StandardWidths
block|{
name|BlockIDWidth
init|=
literal|8
block|,
comment|// We use VBR-8 for block IDs.
name|CodeLenWidth
init|=
literal|4
block|,
comment|// Codelen are VBR-4.
name|BlockSizeWidth
init|=
literal|32
comment|// BlockSize up to 2^32 32-bit words = 16GB per block.
block|}
enum|;
comment|// The standard abbrev namespace always has a way to exit a block, enter a
comment|// nested block, define abbrevs, and define an unabbreviated record.
enum|enum
name|FixedAbbrevIDs
block|{
name|END_BLOCK
init|=
literal|0
block|,
comment|// Must be zero to guarantee termination for broken bitcode.
name|ENTER_SUBBLOCK
init|=
literal|1
block|,
comment|/// DEFINE_ABBREV - Defines an abbrev for the current block.  It consists
comment|/// of a vbr5 for # operand infos.  Each operand info is emitted with a
comment|/// single bit to indicate if it is a literal encoding.  If so, the value is
comment|/// emitted with a vbr8.  If not, the encoding is emitted as 3 bits followed
comment|/// by the info value as a vbr5 if needed.
name|DEFINE_ABBREV
init|=
literal|2
block|,
comment|// UNABBREV_RECORDs are emitted with a vbr6 for the record code, followed by
comment|// a vbr6 for the # operands, followed by vbr6's for each operand.
name|UNABBREV_RECORD
init|=
literal|3
block|,
comment|// This is not a code, this is a marker for the first abbrev assignment.
name|FIRST_APPLICATION_ABBREV
init|=
literal|4
block|}
enum|;
comment|/// StandardBlockIDs - All bitcode files can optionally include a BLOCKINFO
comment|/// block, which contains metadata about other blocks in the file.
enum|enum
name|StandardBlockIDs
block|{
comment|/// BLOCKINFO_BLOCK is used to define metadata about blocks, for example,
comment|/// standard abbrevs that should be available to all blocks of a specified
comment|/// ID.
name|BLOCKINFO_BLOCK_ID
init|=
literal|0
block|,
comment|// Block IDs 1-7 are reserved for future expansion.
name|FIRST_APPLICATION_BLOCKID
init|=
literal|8
block|}
enum|;
comment|/// BlockInfoCodes - The blockinfo block contains metadata about user-defined
comment|/// blocks.
enum|enum
name|BlockInfoCodes
block|{
comment|// DEFINE_ABBREV has magic semantics here, applying to the current SETBID'd
comment|// block, instead of the BlockInfo block.
name|BLOCKINFO_CODE_SETBID
init|=
literal|1
block|,
comment|// SETBID: [blockid#]
name|BLOCKINFO_CODE_BLOCKNAME
init|=
literal|2
block|,
comment|// BLOCKNAME: [name]
name|BLOCKINFO_CODE_SETRECORDNAME
init|=
literal|3
comment|// BLOCKINFO_CODE_SETRECORDNAME: [id, name]
block|}
enum|;
block|}
comment|// End bitc namespace
comment|/// BitCodeAbbrevOp - This describes one or more operands in an abbreviation.
comment|/// This is actually a union of two different things:
comment|///   1. It could be a literal integer value ("the operand is always 17").
comment|///   2. It could be an encoding specification ("this operand encoded like so").
comment|///
name|class
name|BitCodeAbbrevOp
block|{
name|uint64_t
name|Val
decl_stmt|;
comment|// A literal value or data for an encoding.
name|bool
name|IsLiteral
range|:
literal|1
decl_stmt|;
comment|// Indicate whether this is a literal value or not.
name|unsigned
name|Enc
range|:
literal|3
decl_stmt|;
comment|// The encoding to use.
name|public
label|:
enum|enum
name|Encoding
block|{
name|Fixed
init|=
literal|1
block|,
comment|// A fixed width field, Val specifies number of bits.
name|VBR
init|=
literal|2
block|,
comment|// A VBR field where Val specifies the width of each chunk.
name|Array
init|=
literal|3
block|,
comment|// A sequence of fields, next field species elt encoding.
name|Char6
init|=
literal|4
block|,
comment|// A 6-bit fixed field which maps to [a-zA-Z0-9._].
name|Blob
init|=
literal|5
comment|// 32-bit aligned array of 8-bit characters.
block|}
enum|;
name|explicit
name|BitCodeAbbrevOp
argument_list|(
argument|uint64_t V
argument_list|)
block|:
name|Val
argument_list|(
name|V
argument_list|)
operator|,
name|IsLiteral
argument_list|(
argument|true
argument_list|)
block|{}
name|explicit
name|BitCodeAbbrevOp
argument_list|(
argument|Encoding E
argument_list|,
argument|uint64_t Data =
literal|0
argument_list|)
operator|:
name|Val
argument_list|(
name|Data
argument_list|)
operator|,
name|IsLiteral
argument_list|(
name|false
argument_list|)
operator|,
name|Enc
argument_list|(
argument|E
argument_list|)
block|{}
name|bool
name|isLiteral
argument_list|()
specifier|const
block|{
return|return
name|IsLiteral
return|;
block|}
name|bool
name|isEncoding
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsLiteral
return|;
block|}
comment|// Accessors for literals.
name|uint64_t
name|getLiteralValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLiteral
argument_list|()
argument_list|)
block|;
return|return
name|Val
return|;
block|}
comment|// Accessors for encoding info.
name|Encoding
name|getEncoding
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isEncoding
argument_list|()
argument_list|)
block|;
return|return
operator|(
name|Encoding
operator|)
name|Enc
return|;
block|}
name|uint64_t
name|getEncodingData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isEncoding
argument_list|()
operator|&&
name|hasEncodingData
argument_list|()
argument_list|)
block|;
return|return
name|Val
return|;
block|}
name|bool
name|hasEncodingData
argument_list|()
specifier|const
block|{
return|return
name|hasEncodingData
argument_list|(
name|getEncoding
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|hasEncodingData
parameter_list|(
name|Encoding
name|E
parameter_list|)
block|{
switch|switch
condition|(
name|E
condition|)
block|{
default|default:
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unknown encoding"
argument_list|)
expr_stmt|;
case|case
name|Fixed
case|:
case|case
name|VBR
case|:
return|return
name|true
return|;
case|case
name|Array
case|:
case|case
name|Char6
case|:
case|case
name|Blob
case|:
return|return
name|false
return|;
block|}
block|}
comment|/// isChar6 - Return true if this character is legal in the Char6 encoding.
specifier|static
name|bool
name|isChar6
parameter_list|(
name|char
name|C
parameter_list|)
block|{
if|if
condition|(
name|C
operator|>=
literal|'a'
operator|&&
name|C
operator|<=
literal|'z'
condition|)
return|return
name|true
return|;
if|if
condition|(
name|C
operator|>=
literal|'A'
operator|&&
name|C
operator|<=
literal|'Z'
condition|)
return|return
name|true
return|;
if|if
condition|(
name|C
operator|>=
literal|'0'
operator|&&
name|C
operator|<=
literal|'9'
condition|)
return|return
name|true
return|;
if|if
condition|(
name|C
operator|==
literal|'.'
operator|||
name|C
operator|==
literal|'_'
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
specifier|static
name|unsigned
name|EncodeChar6
parameter_list|(
name|char
name|C
parameter_list|)
block|{
if|if
condition|(
name|C
operator|>=
literal|'a'
operator|&&
name|C
operator|<=
literal|'z'
condition|)
return|return
name|C
operator|-
literal|'a'
return|;
if|if
condition|(
name|C
operator|>=
literal|'A'
operator|&&
name|C
operator|<=
literal|'Z'
condition|)
return|return
name|C
operator|-
literal|'A'
operator|+
literal|26
return|;
if|if
condition|(
name|C
operator|>=
literal|'0'
operator|&&
name|C
operator|<=
literal|'9'
condition|)
return|return
name|C
operator|-
literal|'0'
operator|+
literal|26
operator|+
literal|26
return|;
if|if
condition|(
name|C
operator|==
literal|'.'
condition|)
return|return
literal|62
return|;
if|if
condition|(
name|C
operator|==
literal|'_'
condition|)
return|return
literal|63
return|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not a value Char6 character!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|static
name|char
name|DecodeChar6
parameter_list|(
name|unsigned
name|V
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|V
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Not a Char6 encoded character!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|V
operator|<
literal|26
condition|)
return|return
name|V
operator|+
literal|'a'
return|;
if|if
condition|(
name|V
operator|<
literal|26
operator|+
literal|26
condition|)
return|return
name|V
operator|-
literal|26
operator|+
literal|'A'
return|;
if|if
condition|(
name|V
operator|<
literal|26
operator|+
literal|26
operator|+
literal|10
condition|)
return|return
name|V
operator|-
literal|26
operator|-
literal|26
operator|+
literal|'0'
return|;
if|if
condition|(
name|V
operator|==
literal|62
condition|)
return|return
literal|'.'
return|;
if|if
condition|(
name|V
operator|==
literal|63
condition|)
return|return
literal|'_'
return|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not a value Char6 character!"
argument_list|)
expr_stmt|;
return|return
literal|' '
return|;
block|}
block|}
empty_stmt|;
comment|/// BitCodeAbbrev - This class represents an abbreviation record.  An
comment|/// abbreviation allows a complex record that has redundancy to be stored in a
comment|/// specialized format instead of the fully-general, fully-vbr, format.
name|class
name|BitCodeAbbrev
block|{
name|SmallVector
operator|<
name|BitCodeAbbrevOp
operator|,
literal|8
operator|>
name|OperandList
expr_stmt|;
name|unsigned
name|char
name|RefCount
decl_stmt|;
comment|// Number of things using this.
operator|~
name|BitCodeAbbrev
argument_list|()
block|{}
name|public
operator|:
name|BitCodeAbbrev
argument_list|()
operator|:
name|RefCount
argument_list|(
literal|1
argument_list|)
block|{}
name|void
name|addRef
argument_list|()
block|{
operator|++
name|RefCount
block|; }
name|void
name|dropRef
argument_list|()
block|{
if|if
condition|(
operator|--
name|RefCount
operator|==
literal|0
condition|)
name|delete
name|this
decl_stmt|;
block|}
name|unsigned
name|getNumOperandInfos
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|OperandList
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
specifier|const
name|BitCodeAbbrevOp
modifier|&
name|getOperandInfo
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
return|return
name|OperandList
index|[
name|N
index|]
return|;
block|}
name|void
name|Add
parameter_list|(
specifier|const
name|BitCodeAbbrevOp
modifier|&
name|OpInfo
parameter_list|)
block|{
name|OperandList
operator|.
name|push_back
argument_list|(
name|OpInfo
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

