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
comment|// This file declares the SourceMgr class.  This class is used as a simple
end_comment

begin_comment
comment|// substrate for diagnostics, #include handling, and other low level things for
end_comment

begin_comment
comment|// simple parsers.
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
name|SMLoc
block|{
specifier|const
name|char
modifier|*
name|Ptr
decl_stmt|;
name|public
label|:
name|SMLoc
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{}
name|SMLoc
argument_list|(
specifier|const
name|SMLoc
operator|&
name|RHS
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|RHS.Ptr
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|==
name|Ptr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|!=
name|Ptr
return|;
block|}
specifier|const
name|char
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
specifier|static
name|SMLoc
name|getFromPointer
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|)
block|{
name|SMLoc
name|L
decl_stmt|;
name|L
operator|.
name|Ptr
operator|=
name|Ptr
expr_stmt|;
return|return
name|L
return|;
block|}
block|}
empty_stmt|;
comment|/// SourceMgr - This owns the files read by tblgen, handles include stacks,
comment|/// and handles printing of diagnostics.
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
argument_list|)
decl|const
decl_stmt|;
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

