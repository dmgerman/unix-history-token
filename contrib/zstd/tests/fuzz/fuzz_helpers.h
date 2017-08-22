begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/**  * Helper functions for fuzzing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUZZ_HELPERS_H
end_ifndef

begin_define
define|#
directive|define
name|FUZZ_HELPERS_H
end_define

begin_include
include|#
directive|include
file|"fuzz.h"
end_include

begin_include
include|#
directive|include
file|"xxhash.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|FUZZ_QUOTE_IMPL
parameter_list|(
name|str
parameter_list|)
value|#str
end_define

begin_define
define|#
directive|define
name|FUZZ_QUOTE
parameter_list|(
name|str
parameter_list|)
value|FUZZ_QUOTE_IMPL(str)
end_define

begin_comment
comment|/**  * Asserts for fuzzing that are always enabled.  */
end_comment

begin_define
define|#
directive|define
name|FUZZ_ASSERT_MSG
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
define|\
value|((cond) ? (void)0                                                            \           : (fprintf(stderr, "%s: %u: Assertion: `%s' failed. %s\n", __FILE__, \                      __LINE__, FUZZ_QUOTE(cond), (msg)),                       \              abort()))
end_define

begin_define
define|#
directive|define
name|FUZZ_ASSERT
parameter_list|(
name|cond
parameter_list|)
value|FUZZ_ASSERT_MSG((cond), "");
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FUZZ_STATIC
value|static __inline __attribute__((unused))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
operator|(
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|)
comment|/* C99 */
operator|)
end_elif

begin_define
define|#
directive|define
name|FUZZ_STATIC
value|static inline
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FUZZ_STATIC
value|static __inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUZZ_STATIC
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Determininistically constructs a seed based on the fuzz input.  * Only looks at the first FUZZ_RNG_SEED_SIZE bytes of the input.  */
end_comment

begin_function
name|FUZZ_STATIC
name|uint32_t
name|FUZZ_seed
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|size_t
specifier|const
name|toHash
init|=
name|MIN
argument_list|(
name|FUZZ_RNG_SEED_SIZE
argument_list|,
name|size
argument_list|)
decl_stmt|;
return|return
name|XXH32
argument_list|(
name|src
argument_list|,
name|toHash
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|FUZZ_rotl32
parameter_list|(
name|x
parameter_list|,
name|r
parameter_list|)
value|(((x)<< (r)) | ((x)>> (32 - (r))))
end_define

begin_function
name|FUZZ_STATIC
name|uint32_t
name|FUZZ_rand
parameter_list|(
name|uint32_t
modifier|*
name|state
parameter_list|)
block|{
specifier|static
specifier|const
name|uint32_t
name|prime1
init|=
literal|2654435761U
decl_stmt|;
specifier|static
specifier|const
name|uint32_t
name|prime2
init|=
literal|2246822519U
decl_stmt|;
name|uint32_t
name|rand32
init|=
operator|*
name|state
decl_stmt|;
name|rand32
operator|*=
name|prime1
expr_stmt|;
name|rand32
operator|+=
name|prime2
expr_stmt|;
name|rand32
operator|=
name|FUZZ_rotl32
argument_list|(
name|rand32
argument_list|,
literal|13
argument_list|)
expr_stmt|;
operator|*
name|state
operator|=
name|rand32
expr_stmt|;
return|return
name|rand32
operator|>>
literal|5
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

