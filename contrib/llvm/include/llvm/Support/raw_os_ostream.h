begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- raw_os_ostream.h - std::ostream adaptor for raw_ostream --*- C++ -*-===//
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
comment|//  This file defines the raw_os_ostream class.
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
name|LLVM_SUPPORT_RAW_OS_OSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RAW_OS_OSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// raw_os_ostream - A raw_ostream that writes to an std::ostream.  This is a
comment|/// simple adaptor class.  It does not check for output errors; clients should
comment|/// use the underlying stream to detect errors.
name|class
name|raw_os_ostream
range|:
name|public
name|raw_ostream
block|{
name|std
operator|::
name|ostream
operator|&
name|OS
block|;
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
block|;
comment|/// current_pos - Return the current position within the stream, not
comment|/// counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
specifier|const
block|;
name|public
operator|:
name|raw_os_ostream
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|O
argument_list|)
operator|:
name|OS
argument_list|(
argument|O
argument_list|)
block|{}
operator|~
name|raw_os_ostream
argument_list|()
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

