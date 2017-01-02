begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TTYState.h ----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 3/26/07.
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
name|__TTYState_h__
end_ifndef

begin_define
define|#
directive|define
name|__TTYState_h__
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_decl_stmt
name|class
name|TTYState
block|{
name|public
label|:
name|TTYState
argument_list|()
expr_stmt|;
operator|~
name|TTYState
argument_list|()
expr_stmt|;
name|bool
name|GetTTYState
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|saveProcessGroup
parameter_list|)
function_decl|;
name|bool
name|SetTTYState
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|FileDescriptorValid
argument_list|()
operator|&&
name|TFlagsValid
argument_list|()
operator|&&
name|TTYStateValid
argument_list|()
return|;
block|}
name|bool
name|FileDescriptorValid
argument_list|()
specifier|const
block|{
return|return
name|m_fd
operator|>=
literal|0
return|;
block|}
name|bool
name|TFlagsValid
argument_list|()
specifier|const
block|{
return|return
name|m_tflags
operator|!=
operator|-
literal|1
return|;
block|}
name|bool
name|TTYStateValid
argument_list|()
specifier|const
block|{
return|return
name|m_ttystateErr
operator|==
literal|0
return|;
block|}
name|bool
name|ProcessGroupValid
argument_list|()
specifier|const
block|{
return|return
name|m_processGroup
operator|!=
operator|-
literal|1
return|;
block|}
name|protected
label|:
name|int
name|m_fd
decl_stmt|;
comment|// File descriptor
name|int
name|m_tflags
decl_stmt|;
name|int
name|m_ttystateErr
decl_stmt|;
name|struct
name|termios
name|m_ttystate
decl_stmt|;
name|pid_t
name|m_processGroup
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|TTYStateSwitcher
block|{
name|public
label|:
name|TTYStateSwitcher
argument_list|()
expr_stmt|;
operator|~
name|TTYStateSwitcher
argument_list|()
expr_stmt|;
name|bool
name|GetState
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
name|int
name|fd
parameter_list|,
name|bool
name|saveProcessGroup
parameter_list|)
function_decl|;
name|bool
name|SetState
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|NumStates
argument_list|()
specifier|const
block|{
return|return
sizeof|sizeof
argument_list|(
name|m_ttystates
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|TTYState
argument_list|)
return|;
block|}
name|bool
name|ValidStateIndex
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
block|{
return|return
name|idx
operator|<
name|NumStates
argument_list|()
return|;
block|}
name|protected
label|:
name|mutable
name|uint32_t
name|m_currentState
decl_stmt|;
name|TTYState
name|m_ttystates
index|[
literal|2
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

