begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextKDP_arm64.h --------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_RegisterContextKDP_arm64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextKDP_arm64_h_
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
file|"Plugins/Process/Utility/RegisterContextDarwin_arm64.h"
end_include

begin_decl_stmt
name|class
name|ThreadKDP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextKDP_arm64
range|:
name|public
name|RegisterContextDarwin_arm64
block|{
name|public
operator|:
name|RegisterContextKDP_arm64
argument_list|(
argument|ThreadKDP&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextKDP_arm64
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
name|DoReadDBG
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|DBG&dbg
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
block|;
name|int
name|DoWriteDBG
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const DBG&dbg
argument_list|)
block|;
name|ThreadKDP
operator|&
name|m_kdp_thread
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextKDP_arm64_h_
end_comment

end_unit

