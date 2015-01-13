begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_placement_new.h -------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer
end_comment

begin_comment
comment|// run-time libraries.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The file provides 'placement new'.
end_comment

begin_comment
comment|// Do not include it into header files, only into source files.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_PLACEMENT_NEW_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PLACEMENT_NEW_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|__sanitizer
operator|::
name|operator_new_size_type
name|sz
argument_list|,
name|void
operator|*
name|p
argument_list|)
block|{
return|return
name|p
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_PLACEMENT_NEW_H
end_comment

end_unit

