begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SourceMgr.h - Manager for Source Buffers& Diagnostics ---*- C++ -*-===//
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
comment|// This file declares the SMDiagnostic and SourceMgr classes.  This
end_comment

begin_comment
comment|// provides a simple substrate for diagnostics, #include handling, and other low
end_comment

begin_comment
comment|// level things for simple parsers.
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
name|SUPPORT_SOURCEMGR_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_SOURCEMGR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
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

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|SMDiagnostic
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// SourceMgr - This owns the files read by a parser, handles include stacks,
comment|/// and handles diagnostic wrangling.
name|class
name|SourceMgr
block|{
struct|struct
name|SrcBuffer
block|{
comment|/// Buffer - The memory buffer for the file.
name|MemoryBuffer
modifier|*
name|Buffer
decl_stmt|;
comment|/// IncludeLoc - This is the location of the parent include, or null if at
comment|/// the top level.
name|SMLoc
name|IncludeLoc
decl_stmt|;
block|}
struct|;
comment|/// Buffers - This is all of the buffers that we are reading from.
name|std
operator|::
name|vector
operator|<
name|SrcBuffer
operator|>
name|Buffers
expr_stmt|;
comment|// IncludeDirectories - This is the list of directories we should search for
comment|// include files in.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|IncludeDirectories
expr_stmt|;
comment|/// LineNoCache - This is a cache for line number queries, its implementation
comment|/// is really private to SourceMgr.cpp.
name|mutable
name|void
modifier|*
name|LineNoCache
decl_stmt|;
name|SourceMgr
argument_list|(
specifier|const
name|SourceMgr
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|SourceMgr
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|SourceMgr
argument_list|()
operator|:
name|LineNoCache
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|SourceMgr
argument_list|()
expr_stmt|;
name|void
name|setIncludeDirs
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Dirs
argument_list|)
block|{
name|IncludeDirectories
operator|=
name|Dirs
expr_stmt|;
block|}
specifier|const
name|SrcBuffer
modifier|&
name|getBufferInfo
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|Buffers
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Buffer ID!"
argument_list|)
expr_stmt|;
return|return
name|Buffers
index|[
name|i
index|]
return|;
block|}
specifier|const
name|MemoryBuffer
modifier|*
name|getMemoryBuffer
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|Buffers
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Buffer ID!"
argument_list|)
expr_stmt|;
return|return
name|Buffers
index|[
name|i
index|]
operator|.
name|Buffer
return|;
block|}
name|SMLoc
name|getParentIncludeLoc
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|Buffers
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Buffer ID!"
argument_list|)
expr_stmt|;
return|return
name|Buffers
index|[
name|i
index|]
operator|.
name|IncludeLoc
return|;
block|}
name|unsigned
name|AddNewSourceBuffer
parameter_list|(
name|MemoryBuffer
modifier|*
name|F
parameter_list|,
name|SMLoc
name|IncludeLoc
parameter_list|)
block|{
name|SrcBuffer
name|NB
decl_stmt|;
name|NB
operator|.
name|Buffer
operator|=
name|F
expr_stmt|;
name|NB
operator|.
name|IncludeLoc
operator|=
name|IncludeLoc
expr_stmt|;
name|Buffers
operator|.
name|push_back
argument_list|(
name|NB
argument_list|)
expr_stmt|;
return|return
name|Buffers
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// AddIncludeFile - Search for a file with the specified name in the current
comment|/// directory or in one of the IncludeDirs.  If no file is found, this returns
comment|/// ~0, otherwise it returns the buffer ID of the stacked file.
name|unsigned
name|AddIncludeFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|SMLoc
name|IncludeLoc
argument_list|)
decl_stmt|;
comment|/// FindBufferContainingLoc - Return the ID of the buffer containing the
comment|/// specified location, returning -1 if not found.
name|int
name|FindBufferContainingLoc
argument_list|(
name|SMLoc
name|Loc
argument_list|)
decl|const
decl_stmt|;
comment|/// FindLineNumber - Find the line number for the specified location in the
comment|/// specified file.  This is not a fast method.
name|unsigned
name|FindLineNumber
argument_list|(
name|SMLoc
name|Loc
argument_list|,
name|int
name|BufferID
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintMessage - Emit a message about the specified location with the
comment|/// specified string.
comment|///
comment|/// @param Type - If non-null, the kind of message (e.g., "error") which is
comment|/// prefixed to the message.
comment|/// @param ShowLine - Should the diagnostic show the source line.
name|void
name|PrintMessage
argument_list|(
name|SMLoc
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|,
specifier|const
name|char
operator|*
name|Type
argument_list|,
name|bool
name|ShowLine
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// GetMessage - Return an SMDiagnostic at the specified location with the
comment|/// specified string.
comment|///
comment|/// @param Type - If non-null, the kind of message (e.g., "error") which is
comment|/// prefixed to the message.
comment|/// @param ShowLine - Should the diagnostic show the source line.
name|SMDiagnostic
name|GetMessage
argument_list|(
name|SMLoc
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|,
specifier|const
name|char
operator|*
name|Type
argument_list|,
name|bool
name|ShowLine
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|PrintIncludeStack
argument_list|(
name|SMLoc
name|IncludeLoc
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// SMDiagnostic - Instances of this class encapsulate one diagnostic report,
comment|/// allowing printing to a raw_ostream as a caret diagnostic.
name|class
name|SMDiagnostic
block|{
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|int
name|LineNo
decl_stmt|,
name|ColumnNo
decl_stmt|;
name|std
operator|::
name|string
name|Message
operator|,
name|LineContents
expr_stmt|;
name|unsigned
name|ShowLine
range|:
literal|1
decl_stmt|;
name|public
label|:
name|SMDiagnostic
argument_list|()
operator|:
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
name|SMDiagnostic
argument_list|(
argument|const std::string&FN
argument_list|,
argument|int Line
argument_list|,
argument|int Col
argument_list|,
argument|const std::string&Msg
argument_list|,
argument|const std::string&LineStr
argument_list|,
argument|bool showline = true
argument_list|)
operator|:
name|Filename
argument_list|(
name|FN
argument_list|)
operator|,
name|LineNo
argument_list|(
name|Line
argument_list|)
operator|,
name|ColumnNo
argument_list|(
name|Col
argument_list|)
operator|,
name|Message
argument_list|(
name|Msg
argument_list|)
operator|,
name|LineContents
argument_list|(
name|LineStr
argument_list|)
operator|,
name|ShowLine
argument_list|(
argument|showline
argument_list|)
block|{}
name|void
name|Print
argument_list|(
specifier|const
name|char
operator|*
name|ProgName
argument_list|,
name|raw_ostream
operator|&
name|S
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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

