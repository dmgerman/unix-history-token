begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BENCH_H_121279284357
end_ifndef

begin_define
define|#
directive|define
name|BENCH_H_121279284357
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_define
define|#
directive|define
name|ZSTD_STATIC_LINKING_ONLY
end_define

begin_comment
comment|/* ZSTD_compressionParameters */
end_comment

begin_include
include|#
directive|include
file|"zstd.h"
end_include

begin_comment
comment|/* ZSTD_compressionParameters */
end_comment

begin_function_decl
name|int
name|BMK_benchFiles
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|fileNamesTable
parameter_list|,
name|unsigned
name|nbFiles
parameter_list|,
specifier|const
name|char
modifier|*
name|dictFileName
parameter_list|,
name|int
name|cLevel
parameter_list|,
name|int
name|cLevelLast
parameter_list|,
name|ZSTD_compressionParameters
modifier|*
name|compressionParams
parameter_list|,
name|int
name|setRealTimePrio
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set Parameters */
end_comment

begin_function_decl
name|void
name|BMK_setNbSeconds
parameter_list|(
name|unsigned
name|nbLoops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BMK_setBlockSize
parameter_list|(
name|size_t
name|blockSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BMK_setNbThreads
parameter_list|(
name|unsigned
name|nbThreads
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BMK_setNotificationLevel
parameter_list|(
name|unsigned
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BMK_setAdditionalParam
parameter_list|(
name|int
name|additionalParam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BMK_setDecodeOnlyMode
parameter_list|(
name|unsigned
name|decodeFlag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BENCH_H_121279284357 */
end_comment

end_unit

