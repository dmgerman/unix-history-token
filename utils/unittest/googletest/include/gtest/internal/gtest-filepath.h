begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2008, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: keith.ray@gmail.com (Keith Ray)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test filepath utilities
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header file declares classes and functions used internally by
end_comment

begin_comment
comment|// Google Test.  They are subject to change without notice.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is #included in testing/base/internal/gtest-internal.h
end_comment

begin_comment
comment|// Do not include this header file separately!
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_FILEPATH_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_FILEPATH_H_
end_define

begin_include
include|#
directive|include
file|<gtest/internal/gtest-string.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// FilePath - a class for file and directory pathname manipulation which
comment|// handles platform-specific conventions (like the pathname separator).
comment|// Used for helper functions for naming files in a directory for xml output.
comment|// Except for Set methods, all methods are const or static, which provides an
comment|// "immutable value object" -- useful for peace of mind.
comment|// A FilePath with a value ending in a path separator ("like/this/") represents
comment|// a directory, otherwise it is assumed to represent a file. In either case,
comment|// it may or may not represent an actual file or directory in the file system.
comment|// Names are NOT checked for syntax correctness -- no checking for illegal
comment|// characters, malformed paths, etc.
name|class
name|FilePath
block|{
name|public
label|:
name|FilePath
argument_list|()
operator|:
name|pathname_
argument_list|(
literal|""
argument_list|)
block|{ }
name|FilePath
argument_list|(
specifier|const
name|FilePath
operator|&
name|rhs
argument_list|)
operator|:
name|pathname_
argument_list|(
argument|rhs.pathname_
argument_list|)
block|{ }
name|explicit
name|FilePath
argument_list|(
specifier|const
name|char
operator|*
name|pathname
argument_list|)
operator|:
name|pathname_
argument_list|(
argument|pathname
argument_list|)
block|{
name|Normalize
argument_list|()
block|;   }
name|explicit
name|FilePath
argument_list|(
specifier|const
name|String
operator|&
name|pathname
argument_list|)
operator|:
name|pathname_
argument_list|(
argument|pathname
argument_list|)
block|{
name|Normalize
argument_list|()
block|;   }
name|FilePath
operator|&
name|operator
operator|=
operator|(
specifier|const
name|FilePath
operator|&
name|rhs
operator|)
block|{
name|Set
argument_list|(
name|rhs
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|Set
parameter_list|(
specifier|const
name|FilePath
modifier|&
name|rhs
parameter_list|)
block|{
name|pathname_
operator|=
name|rhs
operator|.
name|pathname_
expr_stmt|;
block|}
name|String
name|ToString
argument_list|()
specifier|const
block|{
return|return
name|pathname_
return|;
block|}
specifier|const
name|char
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|pathname_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the current working directory, or "" if unsuccessful.
specifier|static
name|FilePath
name|GetCurrentDir
parameter_list|()
function_decl|;
comment|// Given directory = "dir", base_name = "test", number = 0,
comment|// extension = "xml", returns "dir/test.xml". If number is greater
comment|// than zero (e.g., 12), returns "dir/test_12.xml".
comment|// On Windows platform, uses \ as the separator rather than /.
specifier|static
name|FilePath
name|MakeFileName
parameter_list|(
specifier|const
name|FilePath
modifier|&
name|directory
parameter_list|,
specifier|const
name|FilePath
modifier|&
name|base_name
parameter_list|,
name|int
name|number
parameter_list|,
specifier|const
name|char
modifier|*
name|extension
parameter_list|)
function_decl|;
comment|// Returns a pathname for a file that does not currently exist. The pathname
comment|// will be directory/base_name.extension or
comment|// directory/base_name_<number>.extension if directory/base_name.extension
comment|// already exists. The number will be incremented until a pathname is found
comment|// that does not already exist.
comment|// Examples: 'dir/foo_test.xml' or 'dir/foo_test_1.xml'.
comment|// There could be a race condition if two or more processes are calling this
comment|// function at the same time -- they could both pick the same filename.
specifier|static
name|FilePath
name|GenerateUniqueFileName
parameter_list|(
specifier|const
name|FilePath
modifier|&
name|directory
parameter_list|,
specifier|const
name|FilePath
modifier|&
name|base_name
parameter_list|,
specifier|const
name|char
modifier|*
name|extension
parameter_list|)
function_decl|;
comment|// Returns true iff the path is NULL or "".
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|c_str
argument_list|()
operator|==
name|NULL
operator|||
operator|*
name|c_str
argument_list|()
operator|==
literal|'\0'
return|;
block|}
comment|// If input name has a trailing separator character, removes it and returns
comment|// the name, otherwise return the name string unmodified.
comment|// On Windows platform, uses \ as the separator, other platforms use /.
name|FilePath
name|RemoveTrailingPathSeparator
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns a copy of the FilePath with the directory part removed.
comment|// Example: FilePath("path/to/file").RemoveDirectoryName() returns
comment|// FilePath("file"). If there is no directory part ("just_a_file"), it returns
comment|// the FilePath unmodified. If there is no file part ("just_a_dir/") it
comment|// returns an empty FilePath ("").
comment|// On Windows platform, '\' is the path separator, otherwise it is '/'.
name|FilePath
name|RemoveDirectoryName
argument_list|()
specifier|const
expr_stmt|;
comment|// RemoveFileName returns the directory path with the filename removed.
comment|// Example: FilePath("path/to/file").RemoveFileName() returns "path/to/".
comment|// If the FilePath is "a_file" or "/a_file", RemoveFileName returns
comment|// FilePath("./") or, on Windows, FilePath(".\\"). If the filepath does
comment|// not have a file, like "just/a/dir/", it returns the FilePath unmodified.
comment|// On Windows platform, '\' is the path separator, otherwise it is '/'.
name|FilePath
name|RemoveFileName
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns a copy of the FilePath with the case-insensitive extension removed.
comment|// Example: FilePath("dir/file.exe").RemoveExtension("EXE") returns
comment|// FilePath("dir/file"). If a case-insensitive extension is not
comment|// found, returns a copy of the original FilePath.
name|FilePath
name|RemoveExtension
argument_list|(
specifier|const
name|char
operator|*
name|extension
argument_list|)
decl|const
decl_stmt|;
comment|// Creates directories so that path exists. Returns true if successful or if
comment|// the directories already exist; returns false if unable to create
comment|// directories for any reason. Will also return false if the FilePath does
comment|// not represent a directory (that is, it doesn't end with a path separator).
name|bool
name|CreateDirectoriesRecursively
argument_list|()
specifier|const
expr_stmt|;
comment|// Create the directory so that path exists. Returns true if successful or
comment|// if the directory already exists; returns false if unable to create the
comment|// directory for any reason, including if the parent directory does not
comment|// exist. Not named "CreateDirectory" because that's a macro on Windows.
name|bool
name|CreateFolder
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true if FilePath describes something in the file-system,
comment|// either a file, directory, or whatever, and that something exists.
name|bool
name|FileOrDirectoryExists
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true if pathname describes a directory in the file-system
comment|// that exists.
name|bool
name|DirectoryExists
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true if FilePath ends with a path separator, which indicates that
comment|// it is intended to represent a directory. Returns false otherwise.
comment|// This does NOT check that a directory (or file) actually exists.
name|bool
name|IsDirectory
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true if pathname describes a root directory. (Windows has one
comment|// root directory per disk drive.)
name|bool
name|IsRootDirectory
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|// Replaces multiple consecutive separators with a single separator.
comment|// For example, "bar///foo" becomes "bar/foo". Does not eliminate other
comment|// redundancies that might be in a pathname involving "." or "..".
comment|//
comment|// A pathname with multiple consecutive separators may occur either through
comment|// user error or as a result of some scripts or APIs that generate a pathname
comment|// with a trailing separator. On other platforms the same API or script
comment|// may NOT generate a pathname with a trailing "/". Then elsewhere that
comment|// pathname may have another "/" and pathname components added to it,
comment|// without checking for the separator already being there.
comment|// The script language and operating system may allow paths like "foo//bar"
comment|// but some of the functions in FilePath will not handle that correctly. In
comment|// particular, RemoveTrailingPathSeparator() only removes one separator, and
comment|// it is called in CreateDirectoriesRecursively() assuming that it will change
comment|// a pathname from directory syntax (trailing separator) to filename syntax.
name|void
name|Normalize
parameter_list|()
function_decl|;
name|String
name|pathname_
decl_stmt|;
block|}
empty_stmt|;
comment|// class FilePath
block|}
comment|// namespace internal
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_FILEPATH_H_
end_comment

end_unit

