begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       delta_common.h
end_comment

begin_comment
comment|/// \brief      Common stuff for Delta encoder and decoder
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_DELTA_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_DELTA_COMMON_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_delta_coder_memusage
parameter_list|(
specifier|const
name|void
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

