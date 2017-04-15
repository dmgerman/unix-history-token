begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/* This library is designed for a single-threaded console application. *  It exit() and printf() into stderr when it encounters an error condition. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIBIO_H_003
end_ifndef

begin_define
define|#
directive|define
name|DIBIO_H_003
end_define

begin_comment
comment|/*-************************************* *  Dependencies ***************************************/
end_comment

begin_define
define|#
directive|define
name|ZDICT_STATIC_LINKING_ONLY
end_define

begin_include
include|#
directive|include
file|"zdict.h"
end_include

begin_comment
comment|/* ZDICT_params_t */
end_comment

begin_comment
comment|/*-************************************* *  Public functions ***************************************/
end_comment

begin_comment
comment|/*! DiB_trainFromFiles() :     Train a dictionary from a set of files provided by `fileNamesTable`.     Resulting dictionary is written into file `dictFileName`.     `parameters` is optional and can be provided with values set to 0, meaning "default".     @return : 0 == ok. Any other : error. */
end_comment

begin_function_decl
name|int
name|DiB_trainFromFiles
parameter_list|(
specifier|const
name|char
modifier|*
name|dictFileName
parameter_list|,
name|unsigned
name|maxDictSize
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|fileNamesTable
parameter_list|,
name|unsigned
name|nbFiles
parameter_list|,
name|ZDICT_params_t
modifier|*
name|params
parameter_list|,
name|COVER_params_t
modifier|*
name|coverParams
parameter_list|,
name|int
name|optimizeCover
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

