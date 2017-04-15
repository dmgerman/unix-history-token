begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DATAGEN_H
end_ifndef

begin_define
define|#
directive|define
name|DATAGEN_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_function_decl
name|void
name|RDG_genStdout
parameter_list|(
name|unsigned
name|long
name|long
name|size
parameter_list|,
name|double
name|matchProba
parameter_list|,
name|double
name|litProba
parameter_list|,
name|unsigned
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RDG_genBuffer
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|,
name|double
name|matchProba
parameter_list|,
name|double
name|litProba
parameter_list|,
name|unsigned
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!RDG_genBuffer    Generate 'size' bytes of compressible data into 'buffer'.    Compressibility can be controlled using 'matchProba', which is floating point value between 0 and 1.    'LitProba' is optional, it affect variability of individual bytes. If litProba==0.0, default value will be used.    Generated data pattern can be modified using different 'seed'.    For a triplet (matchProba, litProba, seed), the function always generate the same content.     RDG_genStdout    Same as RDG_genBuffer, but generates data into stdout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

