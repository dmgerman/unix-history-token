begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SourceFile.h - Class to represent a source code file -----*- C++ -*-===//
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
comment|// This file defines the SourceFile class which is used to represent a single
end_comment

begin_comment
comment|// file of source code in the program, caching data from the file to make access
end_comment

begin_comment
comment|// efficient.
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
name|LLVM_DEBUGGER_SOURCEFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_SOURCEFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|SourceFile
block|{
comment|/// Filename - This is the full path of the file that is loaded.
comment|///
name|sys
operator|::
name|Path
name|Filename
expr_stmt|;
comment|/// Descriptor - The debugging descriptor for this source file.  If there
comment|/// are multiple descriptors for the same file, this is just the first one
comment|/// encountered.
comment|///
specifier|const
name|GlobalVariable
modifier|*
name|Descriptor
decl_stmt|;
comment|/// This is the memory mapping for the file so we can gain access to it.
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
name|File
expr_stmt|;
comment|/// LineOffset - This vector contains a mapping from source line numbers to
comment|/// their offsets in the file.  This data is computed lazily, the first time
comment|/// it is asked for.  If there are zero elements allocated in this vector,
comment|/// then it has not yet been computed.
name|mutable
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|LineOffset
expr_stmt|;
name|public
label|:
comment|/// SourceFile constructor - Read in the specified source file if it exists,
comment|/// but do not build the LineOffsets table until it is requested.  This will
comment|/// NOT throw an exception if the file is not found, if there is an error
comment|/// reading it, or if the user cancels the operation.  Instead, it will just
comment|/// be an empty source file.
name|SourceFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|fn
argument_list|,
specifier|const
name|GlobalVariable
operator|*
name|Desc
argument_list|)
expr_stmt|;
operator|~
name|SourceFile
argument_list|()
expr_stmt|;
comment|/// getDescriptor - Return the debugging decriptor for this source file.
comment|///
specifier|const
name|GlobalVariable
operator|*
name|getDescriptor
argument_list|()
specifier|const
block|{
return|return
name|Descriptor
return|;
block|}
comment|/// getFilename - Return the fully resolved path that this file was loaded
comment|/// from.
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
operator|.
name|toString
argument_list|()
return|;
block|}
comment|/// getSourceLine - Given a line number, return the start and end of the
comment|/// line in the file.  If the line number is invalid, or if the file could
comment|/// not be loaded, null pointers are returned for the start and end of the
comment|/// file.  Note that line numbers start with 0, not 1.  This also strips off
comment|/// any newlines from the end of the line, to ease formatting of the text.
name|void
name|getSourceLine
argument_list|(
name|unsigned
name|LineNo
argument_list|,
specifier|const
name|char
operator|*
operator|&
name|LineStart
argument_list|,
specifier|const
name|char
operator|*
operator|&
name|LineEnd
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumLines - Return the number of lines the source file contains.
comment|///
name|unsigned
name|getNumLines
argument_list|()
specifier|const
block|{
if|if
condition|(
name|LineOffset
operator|.
name|empty
argument_list|()
condition|)
name|calculateLineOffsets
argument_list|()
expr_stmt|;
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|LineOffset
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
name|private
label|:
comment|/// calculateLineOffsets - Compute the LineOffset vector for the current
comment|/// file.
name|void
name|calculateLineOffsets
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

