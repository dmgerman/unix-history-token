begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-EDToken.h - LLVM Enhanced Disassembler --------------------*- C++ -*-===//
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
comment|// This file defines the interface for the Enhanced Disassembly library's token
end_comment

begin_comment
comment|// class.  The token is responsible for vending information about the token,
end_comment

begin_comment
comment|// such as its type and logical value.
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
name|EDToken_
end_ifndef

begin_define
define|#
directive|define
name|EDToken_
end_define

begin_include
include|#
directive|include
file|"llvm-c/EnhancedDisassembly.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|/// EDToken - Encapsulates a single token, which can provide a string
end_comment

begin_comment
comment|///   representation of itself or interpret itself in various ways, depending
end_comment

begin_comment
comment|///   on the token type.
end_comment

begin_struct
struct|struct
name|EDToken
block|{
enum|enum
name|tokenType
block|{
name|kTokenWhitespace
block|,
name|kTokenOpcode
block|,
name|kTokenLiteral
block|,
name|kTokenRegister
block|,
name|kTokenPunctuation
block|}
enum|;
comment|/// The parent disassembler
name|EDDisassembler
modifier|&
name|Disassembler
decl_stmt|;
comment|/// The token's string representation
name|llvm
operator|::
name|StringRef
name|Str
expr_stmt|;
comment|/// The token's string representation, but in a form suitable for export
name|std
operator|::
name|string
name|PermStr
expr_stmt|;
comment|/// The type of the token, as exposed through the external API
name|enum
name|tokenType
name|Type
decl_stmt|;
comment|/// The type of the token, as recorded by the syntax-specific tokenizer
name|uint64_t
name|LocalType
decl_stmt|;
comment|/// The operand corresponding to the token, or (unsigned int)-1 if not
comment|///   part of an operand.
name|int
name|OperandID
decl_stmt|;
comment|/// The sign if the token is a literal (1 if negative, 0 otherwise)
name|bool
name|LiteralSign
decl_stmt|;
comment|/// The absolute value if the token is a literal
name|uint64_t
name|LiteralAbsoluteValue
decl_stmt|;
comment|/// The LLVM register ID if the token is a register name
name|unsigned
name|RegisterID
decl_stmt|;
comment|/// Constructor - Initializes an EDToken with the information common to all
comment|///   tokens
comment|///
comment|/// @arg str          - The string corresponding to the token
comment|/// @arg type         - The token's type as exposed through the public API
comment|/// @arg localType    - The token's type as recorded by the tokenizer
comment|/// @arg disassembler - The disassembler responsible for the token
name|EDToken
argument_list|(
argument|llvm::StringRef str
argument_list|,
argument|enum tokenType type
argument_list|,
argument|uint64_t localType
argument_list|,
argument|EDDisassembler&disassembler
argument_list|)
empty_stmt|;
comment|/// makeLiteral - Adds the information specific to a literal
comment|/// @arg sign           - The sign of the literal (1 if negative, 0
comment|///                       otherwise)
comment|///
comment|/// @arg absoluteValue  - The absolute value of the literal
name|void
name|makeLiteral
parameter_list|(
name|bool
name|sign
parameter_list|,
name|uint64_t
name|absoluteValue
parameter_list|)
function_decl|;
comment|/// makeRegister - Adds the information specific to a register
comment|///
comment|/// @arg registerID - The LLVM register ID
name|void
name|makeRegister
parameter_list|(
name|unsigned
name|registerID
parameter_list|)
function_decl|;
comment|/// setOperandID - Links the token to a numbered operand
comment|///
comment|/// @arg operandID  - The operand ID to link to
name|void
name|setOperandID
parameter_list|(
name|int
name|operandID
parameter_list|)
function_decl|;
operator|~
name|EDToken
argument_list|()
expr_stmt|;
comment|/// type - Returns the public type of the token
block|enum
name|tokenType
name|type
argument_list|()
specifier|const
expr_stmt|;
comment|/// localType - Returns the tokenizer-specific type of the token
name|uint64_t
name|localType
argument_list|()
specifier|const
expr_stmt|;
comment|/// string - Returns the string representation of the token
name|llvm
operator|::
name|StringRef
name|string
argument_list|()
specifier|const
expr_stmt|;
comment|/// operandID - Returns the operand ID of the token
name|int
name|operandID
argument_list|()
specifier|const
expr_stmt|;
comment|/// literalSign - Returns the sign of the token
comment|///   (1 if negative, 0 if positive or unsigned, -1 if it is not a literal)
name|int
name|literalSign
argument_list|()
specifier|const
expr_stmt|;
comment|/// literalAbsoluteValue - Retrieves the absolute value of the token, and
comment|///   returns -1 if the token is not a literal
comment|/// @arg value  - A reference to a value that is filled in with the absolute
comment|///               value, if it is valid
name|int
name|literalAbsoluteValue
argument_list|(
name|uint64_t
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
comment|/// registerID - Retrieves the register ID of the token, and returns -1 if the
comment|///   token is not a register
comment|///
comment|/// @arg registerID - A reference to a value that is filled in with the
comment|///                   register ID, if it is valid
name|int
name|registerID
argument_list|(
name|unsigned
operator|&
name|registerID
argument_list|)
decl|const
decl_stmt|;
comment|/// tokenize - Tokenizes a string using the platform- and syntax-specific
comment|///   tokenizer, and returns 0 on success (-1 on failure)
comment|///
comment|/// @arg tokens       - A vector that will be filled in with pointers to
comment|///                     allocated tokens
comment|/// @arg str          - The string, as outputted by the AsmPrinter
comment|/// @arg operandOrder - The order of the operands from the operandFlags array
comment|///                     as they appear in str
comment|/// @arg disassembler - The disassembler for the desired target and
comment|//                      assembly syntax
specifier|static
name|int
name|tokenize
argument_list|(
name|std
operator|::
name|vector
operator|<
name|EDToken
operator|*
operator|>
operator|&
name|tokens
argument_list|,
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|char
operator|*
name|operandOrder
argument_list|,
name|EDDisassembler
operator|&
name|disassembler
argument_list|)
decl_stmt|;
comment|/// getString - Directs a character pointer to the string, returning 0 on
comment|///   success (-1 on failure)
comment|/// @arg buf  - A reference to a pointer that is set to point to the string.
comment|///   The string is still owned by the token.
name|int
name|getString
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|buf
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

