begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  * You may select, at your option, one of the above-listed licenses.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_OPT_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_OPT_H
end_define

begin_include
include|#
directive|include
file|"zstd_compress.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|size_t
name|ZSTD_compressBlock_btopt
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
name|size_t
name|ZSTD_compressBlock_btultra
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
name|size_t
name|ZSTD_compressBlock_btopt_extDict
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
name|size_t
name|ZSTD_compressBlock_btultra_extDict
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
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
comment|/* ZSTD_OPT_H */
end_comment

end_unit

