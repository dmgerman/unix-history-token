begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WindowsResource.h ---------------------------------------*- C++-*-===//
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
comment|//===---------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the .res file class.  .res files are intermediate
end_comment

begin_comment
comment|// products of the typical resource-compilation process on Windows.  This
end_comment

begin_comment
comment|// process is as follows:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// .rc file(s) ---(rc.exe)---> .res file(s) ---(cvtres.exe)---> COFF file
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// .rc files are human-readable scripts that list all resources a program uses.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// They are compiled into .res files, which are a list of the resources in
end_comment

begin_comment
comment|// binary form.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Finally the data stored in the .res is compiled into a COFF file, where it
end_comment

begin_comment
comment|// is organized in a directory tree structure for optimized access by the
end_comment

begin_comment
comment|// program during runtime.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ref: msdn.microsoft.com/en-us/library/windows/desktop/ms648007(v=vs.85).aspx
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_INCLUDE_LLVM_OBJECT_RESFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_LLVM_OBJECT_RESFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Binary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryByteStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|WindowsResource
decl_stmt|;
name|class
name|ResourceEntryRef
block|{
name|public
label|:
name|Error
name|moveNext
parameter_list|(
name|bool
modifier|&
name|End
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|WindowsResource
decl_stmt|;
name|ResourceEntryRef
argument_list|(
argument|BinaryStreamRef Ref
argument_list|,
argument|const WindowsResource *Owner
argument_list|,
argument|Error&Err
argument_list|)
empty_stmt|;
name|Error
name|loadNext
parameter_list|()
function_decl|;
name|BinaryStreamReader
name|Reader
decl_stmt|;
name|BinaryStreamRef
name|HeaderBytes
decl_stmt|;
name|BinaryStreamRef
name|DataBytes
decl_stmt|;
specifier|const
name|WindowsResource
modifier|*
name|OwningRes
init|=
name|nullptr
decl_stmt|;
block|}
empty_stmt|;
name|class
name|WindowsResource
range|:
name|public
name|Binary
block|{
name|public
operator|:
operator|~
name|WindowsResource
argument_list|()
name|override
block|;
name|Expected
operator|<
name|ResourceEntryRef
operator|>
name|getHeadEntry
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Binary *V
argument_list|)
block|{
return|return
name|V
operator|->
name|isWinRes
argument_list|()
return|;
block|}
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|WindowsResource
operator|>>
name|createWindowsResource
argument_list|(
argument|MemoryBufferRef Source
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|ResourceEntryRef
block|;
name|WindowsResource
argument_list|(
argument|MemoryBufferRef Source
argument_list|)
block|;
name|BinaryByteStream
name|BBS
block|; }
decl_stmt|;
block|}
comment|// namespace object
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

