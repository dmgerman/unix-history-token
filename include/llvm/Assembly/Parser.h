begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Assembly/Parser.h - Parser for VM assembly files ---*- C++ -*-===//
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
comment|//  These classes are implemented by the lib/AsmParser library.
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
name|LLVM_ASSEMBLY_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASSEMBLY_PARSER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|ParseError
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// This function is the main interface to the LLVM Assembly Parser. It parses
comment|/// an ASCII file that (presumably) contains LLVM Assembly code. It returns a
comment|/// Module (intermediate representation) with the corresponding features. Note
comment|/// that this does not verify that the generated Module is valid, so you should
comment|/// run the verifier after parsing the file to check that it is okay.
comment|/// @brief Parse LLVM Assembly from a file
name|Module
modifier|*
name|ParseAssemblyFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
comment|///< The name of the file to parse
name|ParseError
operator|&
name|Error
comment|///< If not null, an object to return errors in.
argument_list|)
decl_stmt|;
comment|/// The function is a secondary interface to the LLVM Assembly Parser. It parses
comment|/// an ASCII string that (presumably) contains LLVM Assembly code. It returns a
comment|/// Module (intermediate representation) with the corresponding features. Note
comment|/// that this does not verify that the generated Module is valid, so you should
comment|/// run the verifier after parsing the file to check that it is okay.
comment|/// @brief Parse LLVM Assembly from a string
name|Module
modifier|*
name|ParseAssemblyString
parameter_list|(
specifier|const
name|char
modifier|*
name|AsmString
parameter_list|,
comment|///< The string containing assembly
name|Module
modifier|*
name|M
parameter_list|,
comment|///< A module to add the assembly too.
name|ParseError
modifier|&
name|Error
comment|///< If not null, an object to return errors in.
parameter_list|)
function_decl|;
comment|//===------------------------------------------------------------------------===
comment|//                              Helper Classes
comment|//===------------------------------------------------------------------------===
comment|/// An instance of this class can be passed to ParseAssemblyFile or
comment|/// ParseAssemblyString functions in order to capture error information from
comment|/// the parser.  It provides a standard way to print out the error message
comment|/// including the file name and line number where the error occurred.
comment|/// @brief An LLVM Assembly Parsing Error Object
name|class
name|ParseError
block|{
name|public
label|:
name|ParseError
argument_list|()
operator|:
name|Filename
argument_list|(
literal|"unknown"
argument_list|)
operator|,
name|Message
argument_list|(
literal|"none"
argument_list|)
operator|,
name|LineNo
argument_list|(
literal|0
argument_list|)
operator|,
name|ColumnNo
argument_list|(
literal|0
argument_list|)
block|{}
name|ParseError
argument_list|(
specifier|const
name|ParseError
operator|&
name|E
argument_list|)
expr_stmt|;
name|void
name|setFilename
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|F
argument_list|)
block|{
name|Filename
operator|=
name|F
expr_stmt|;
block|}
specifier|inline
specifier|const
name|std
operator|::
name|string
operator|&
name|getRawMessage
argument_list|()
specifier|const
block|{
comment|// Just the raw message.
return|return
name|Message
return|;
block|}
specifier|inline
specifier|const
name|std
operator|::
name|string
operator|&
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
name|void
name|setError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|message
argument_list|,
name|int
name|lineNo
operator|=
operator|-
literal|1
argument_list|,
name|int
name|ColNo
operator|=
operator|-
literal|1
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FileContents
operator|=
literal|""
argument_list|)
block|{
name|Message
operator|=
name|message
expr_stmt|;
name|LineNo
operator|=
name|lineNo
expr_stmt|;
name|ColumnNo
operator|=
name|ColNo
expr_stmt|;
name|LineContents
operator|=
name|FileContents
expr_stmt|;
block|}
comment|// getErrorLocation - Return the line and column number of the error in the
comment|// input source file.  The source filename can be derived from the
comment|// ParserOptions in effect.  If positional information is not applicable,
comment|// these will return a value of -1.
comment|//
specifier|inline
name|void
name|getErrorLocation
argument_list|(
name|int
operator|&
name|Line
argument_list|,
name|int
operator|&
name|Column
argument_list|)
decl|const
block|{
name|Line
operator|=
name|LineNo
expr_stmt|;
name|Column
operator|=
name|ColumnNo
expr_stmt|;
block|}
name|void
name|PrintError
parameter_list|(
specifier|const
name|char
modifier|*
name|ProgName
parameter_list|,
name|raw_ostream
modifier|&
name|S
parameter_list|)
function_decl|;
name|private
label|:
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|std
operator|::
name|string
name|Message
expr_stmt|;
name|int
name|LineNo
decl_stmt|,
name|ColumnNo
decl_stmt|;
comment|// -1 if not relevant
name|std
operator|::
name|string
name|LineContents
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ParseError
operator|&
name|E
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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

