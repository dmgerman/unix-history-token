begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Valgrind.h - Communication with Valgrind -----*- C++ -*-===//
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
comment|// Methods for communicating with a valgrind instance this program is running
end_comment

begin_comment
comment|// under.  These are all no-ops unless LLVM was configured on a system with the
end_comment

begin_comment
comment|// valgrind headers installed and valgrind is controlling this process.
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
name|LLVM_SYSTEM_VALGRIND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_VALGRIND_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|// True if Valgrind is controlling this process.
name|bool
name|RunningOnValgrind
parameter_list|()
function_decl|;
comment|// Discard valgrind's translation of code in the range [Addr .. Addr + Len).
comment|// Otherwise valgrind may continue to execute the old version of the code.
name|void
name|ValgrindDiscardTranslations
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Len
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

