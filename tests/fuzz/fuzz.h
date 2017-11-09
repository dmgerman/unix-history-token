begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  */
end_comment

begin_comment
comment|/**  * Fuzz target interface.  * Fuzz targets have some common parameters passed as macros during compilation.  * Check the documentation for each individual fuzzer for more parameters.  *  * @param STATEFUL_FUZZING:  *        Define this to reuse state between fuzzer runs. This can be useful to  *        test code paths which are only executed when contexts are reused.  *        WARNING: Makes reproducing crashes much harder.  *        Default: Not defined.  * @param FUZZ_RNG_SEED_SIZE:  *        The number of bytes of the source to look at when constructing a seed  *        for the deterministic RNG. These bytes are discarded before passing  *        the data to zstd functions. Every fuzzer initializes the RNG exactly  *        once before doing anything else, even if it is unused.  *        Default: 4.  * @param ZSTD_DEBUG:  *        This is a parameter for the zstd library. Defining `ZSTD_DEBUG=1`  *        enables assert() statements in the zstd library. Higher levels enable  *        logging, so aren't recommended. Defining `ZSTD_DEBUG=1` is  *        recommended.  * @param MEM_FORCE_MEMORY_ACCESS:  *        This flag controls how the zstd library accesses unaligned memory.  *        It can be undefined, or 0 through 2. If it is undefined, it selects  *        the method to use based on the compiler. If testing with UBSAN set  *        MEM_FORCE_MEMORY_ACCESS=0 to use the standard compliant method.  * @param FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION  *        This is the canonical flag to enable deterministic builds for fuzzing.  *        Changes to zstd for fuzzing are gated behind this define.  *        It is recommended to define this when building zstd for fuzzing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUZZ_H
end_ifndef

begin_define
define|#
directive|define
name|FUZZ_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FUZZ_RNG_SEED_SIZE
end_ifndef

begin_define
define|#
directive|define
name|FUZZ_RNG_SEED_SIZE
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
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
name|int
name|LLVMFuzzerTestOneInput
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|src
parameter_list|,
name|size_t
name|size
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

end_unit

