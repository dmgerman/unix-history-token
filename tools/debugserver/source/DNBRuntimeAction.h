begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBRuntimeAction.h --------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 10/8/07.
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
name|__DNBRuntimeAction_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBRuntimeAction_h__
end_define

begin_decl_stmt
name|class
name|DNBRuntimeAction
block|{
name|virtual
name|void
name|Initialize
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|ProcessStateChanged
parameter_list|(
name|nub_state_t
name|state
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|SharedLibraryStateChanged
parameter_list|(
name|DNBExecutableImageInfo
modifier|*
name|image_infos
parameter_list|,
name|nub_size_t
name|num_image_infos
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DNBRuntimeAction_h__
end_comment

end_unit

