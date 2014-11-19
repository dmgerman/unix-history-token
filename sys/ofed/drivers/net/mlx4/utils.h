begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Mellanox Technologies Ltd.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MLX4_UTILS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MLX4_UTILS_H_
end_define

begin_comment
comment|/* Lagg flags */
end_comment

begin_define
define|#
directive|define
name|MLX4_F_HASHL2
value|0x00000001
end_define

begin_comment
comment|/* hash layer 2 */
end_comment

begin_define
define|#
directive|define
name|MLX4_F_HASHL3
value|0x00000002
end_define

begin_comment
comment|/* hash layer 3 */
end_comment

begin_define
define|#
directive|define
name|MLX4_F_HASHL4
value|0x00000004
end_define

begin_comment
comment|/* hash layer 4 */
end_comment

begin_define
define|#
directive|define
name|MLX4_F_HASHMASK
value|0x00000007
end_define

begin_function_decl
name|uint32_t
name|mlx4_en_hashmbuf
parameter_list|(
name|uint32_t
name|flags
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MLX4_UTILS_H_ */
end_comment

end_unit

