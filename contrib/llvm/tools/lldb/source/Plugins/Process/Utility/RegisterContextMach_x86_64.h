begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextMach_x86_64.h ------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_RegisterContextMach_x86_64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextMach_x86_64_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"RegisterContextDarwin_x86_64.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextMach_x86_64
range|:
name|public
name|RegisterContextDarwin_x86_64
block|{
name|public
operator|:
name|RegisterContextMach_x86_64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextMach_x86_64
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|int
name|DoReadGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|GPR&gpr
argument_list|)
block|;
name|int
name|DoReadFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|FPU&fpu
argument_list|)
block|;
name|int
name|DoReadEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|EXC&exc
argument_list|)
block|;
name|int
name|DoWriteGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const GPR&gpr
argument_list|)
block|;
name|int
name|DoWriteFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const FPU&fpu
argument_list|)
block|;
name|int
name|DoWriteEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const EXC&exc
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextMach_x86_64_h_
end_comment

end_unit

