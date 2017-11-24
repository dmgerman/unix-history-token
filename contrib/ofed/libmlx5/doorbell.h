begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012 Mellanox Technologies, Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOORBELL_H
end_ifndef

begin_define
define|#
directive|define
name|DOORBELL_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"mlx5.h"
end_include

begin_if
if|#
directive|if
name|SIZEOF_LONG
operator|==
literal|8
end_if

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|MLX5_PAIR_TO_64
parameter_list|(
name|val
parameter_list|)
value|((uint64_t) val[1]<< 32 | val[0])
end_define

begin_elif
elif|#
directive|elif
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|MLX5_PAIR_TO_64
parameter_list|(
name|val
parameter_list|)
value|((uint64_t) val[0]<< 32 | val[1])
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|__BYTE_ORDER not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|void
name|mlx5_write64
parameter_list|(
name|uint32_t
name|val
index|[
literal|2
index|]
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|struct
name|mlx5_spinlock
modifier|*
name|lock
parameter_list|)
block|{
operator|*
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
name|dest
operator|=
name|MLX5_PAIR_TO_64
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|void
name|mlx5_write64
parameter_list|(
name|uint32_t
name|val
index|[
literal|2
index|]
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|struct
name|mlx5_spinlock
modifier|*
name|lock
parameter_list|)
block|{
name|mlx5_spin_lock
argument_list|(
name|lock
argument_list|)
expr_stmt|;
operator|*
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|dest
operator|=
name|val
index|[
literal|0
index|]
expr_stmt|;
operator|*
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|dest
operator|+
literal|4
operator|)
operator|=
name|val
index|[
literal|1
index|]
expr_stmt|;
name|mlx5_spin_unlock
argument_list|(
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOORBELL_H */
end_comment

end_unit

