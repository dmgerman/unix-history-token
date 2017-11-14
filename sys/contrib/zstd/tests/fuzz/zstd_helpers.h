begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  */
end_comment

begin_comment
comment|/**  * Helper functions for fuzzing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_HELPERS_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_HELPERS_H
end_define

begin_include
include|#
directive|include
file|"zstd.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|void
name|FUZZ_setRandomParameters
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|cctx
parameter_list|,
name|size_t
name|srcSize
parameter_list|,
name|uint32_t
modifier|*
name|state
parameter_list|)
function_decl|;
name|ZSTD_compressionParameters
name|FUZZ_randomCParams
parameter_list|(
name|size_t
name|srcSize
parameter_list|,
name|uint32_t
modifier|*
name|state
parameter_list|)
function_decl|;
name|ZSTD_frameParameters
name|FUZZ_randomFParams
parameter_list|(
name|uint32_t
modifier|*
name|state
parameter_list|)
function_decl|;
name|ZSTD_parameters
name|FUZZ_randomParams
parameter_list|(
name|size_t
name|srcSize
parameter_list|,
name|uint32_t
modifier|*
name|state
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZSTD_HELPERS_H */
end_comment

end_unit

