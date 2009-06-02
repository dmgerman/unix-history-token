begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/FileUtilities.h - File System Utilities -----*- C++ -*-===//
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
comment|// This file defines a family of utility functions which are useful for doing
end_comment

begin_comment
comment|// various things with files.
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
name|LLVM_SUPPORT_FILEUTILITIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FILEUTILITIES_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// DiffFilesWithTolerance - Compare the two files specified, returning 0 if
comment|/// the files match, 1 if they are different, and 2 if there is a file error.
comment|/// This function allows you to specify an absolete and relative FP error that
comment|/// is allowed to exist.  If you specify a string to fill in for the error
comment|/// option, it will set the string to an error message if an error occurs, or
comment|/// if the files are different.
comment|///
name|int
name|DiffFilesWithTolerance
argument_list|(
specifier|const
name|sys
operator|::
name|PathWithStatus
operator|&
name|FileA
argument_list|,
specifier|const
name|sys
operator|::
name|PathWithStatus
operator|&
name|FileB
argument_list|,
name|double
name|AbsTol
argument_list|,
name|double
name|RelTol
argument_list|,
name|std
operator|::
name|string
operator|*
name|Error
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// FileRemover - This class is a simple object meant to be stack allocated.
comment|/// If an exception is thrown from a region, the object removes the filename
comment|/// specified (if deleteIt is true).
comment|///
name|class
name|FileRemover
block|{
name|sys
operator|::
name|Path
name|Filename
expr_stmt|;
name|bool
name|DeleteIt
decl_stmt|;
name|public
label|:
name|explicit
name|FileRemover
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|filename
argument_list|,
name|bool
name|deleteIt
operator|=
name|true
argument_list|)
range|:
name|Filename
argument_list|(
name|filename
argument_list|)
decl_stmt|,
name|DeleteIt
argument_list|(
name|deleteIt
argument_list|)
block|{}
operator|~
name|FileRemover
argument_list|()
block|{
if|if
condition|(
name|DeleteIt
condition|)
block|{
comment|// Ignore problems deleting the file.
name|Filename
operator|.
name|eraseFromDisk
argument_list|()
expr_stmt|;
block|}
block|}
comment|/// releaseFile - Take ownership of the file away from the FileRemover so it
comment|/// will not be removed when the object is destroyed.
name|void
name|releaseFile
argument_list|()
block|{
name|DeleteIt
operator|=
name|false
block|; }
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

