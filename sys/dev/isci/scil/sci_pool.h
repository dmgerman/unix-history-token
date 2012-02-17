begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  *  * @brief This file contains the interface to the pool class.  *        This class allows two different two different priority tasks to  *        insert and remove items from the free pool. The user of the pool  *        is expected to evaluate the pool condition empty before a get  *        operation and pool condition full before a put operation.  *        Methods Provided:  *        - sci_pool_create()  *        - sci_pool_initialize()  *        - sci_pool_empty()  *        - sci_pool_full()  *        - sci_pool_get()  *        - sci_pool_put()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_POOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_POOL_H_
end_define

begin_include
include|#
directive|include
file|<dev/isci/types.h>
end_include

begin_comment
comment|/**  * Private operation for the pool  */
end_comment

begin_define
define|#
directive|define
name|SCI_POOL_INCREMENT
parameter_list|(
name|this_pool
parameter_list|,
name|index
parameter_list|)
define|\
value|(((index) + 1) == (this_pool).size ? 0 : (index) + 1)
end_define

begin_comment
comment|/**  * This creates a pool structure of pool_name. The members in the pool are  * of type with number of elements equal to size.  */
end_comment

begin_define
define|#
directive|define
name|SCI_POOL_CREATE
parameter_list|(
name|pool_name
parameter_list|,
name|type
parameter_list|,
name|pool_size
parameter_list|)
define|\
value|struct \ { \    U32 size; \    U32 get; \    U32 put; \    type array[(pool_size) + 1]; \ } pool_name
end_define

begin_comment
comment|/**  * This macro evaluates the pool and returns TRUE if the pool is empty.  * If the pool is empty the user should not perform any get operation on  * the pool.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_empty
parameter_list|(
name|this_pool
parameter_list|)
define|\
value|((this_pool).get == (this_pool).put)
end_define

begin_comment
comment|/**  * This macro evaluates the pool and returns TRUE if the pool is full.  If  * the pool is full the user should not perform any put operation.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_full
parameter_list|(
name|this_pool
parameter_list|)
define|\
value|(SCI_POOL_INCREMENT(this_pool, (this_pool).put) == (this_pool).get)
end_define

begin_comment
comment|/**  * This macro returns the size of the pool created.  The internal size  * of the pool is actually 1 larger then necessary in order to ensure  * get and put pointers can be written simultaneously by different  * users.  As a result, this macro subtracts 1 from the internal size  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_size
parameter_list|(
name|this_pool
parameter_list|)
define|\
value|((this_pool).size - 1)
end_define

begin_comment
comment|/**  * This macro indicates the number of elements currently contained in the  * pool.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_count
parameter_list|(
name|this_pool
parameter_list|)
define|\
value|( \       sci_pool_empty((this_pool)) \       ? 0 \       : ( \            sci_pool_full((this_pool)) \            ? sci_pool_size((this_pool)) \            : ( \                 (this_pool).get> (this_pool).put \                 ? ((this_pool).size - (this_pool).get + (this_pool).put) \                 : ((this_pool).put - (this_pool).get) \              ) \         ) \    )
end_define

begin_comment
comment|/**  * This macro initializes the pool to an empty condition.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_initialize
parameter_list|(
name|this_pool
parameter_list|)
define|\
value|{ \    (this_pool).size = (sizeof((this_pool).array) / sizeof((this_pool).array[0])); \    (this_pool).get = 0; \    (this_pool).put = 0; \ }
end_define

begin_comment
comment|/**  * This macro will get the next free element from the pool.  * This should only be called if the pool is not empty.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_get
parameter_list|(
name|this_pool
parameter_list|,
name|my_value
parameter_list|)
define|\
value|{ \    (my_value) = (this_pool).array[(this_pool).get]; \    (this_pool).get = SCI_POOL_INCREMENT((this_pool), (this_pool).get); \ }
end_define

begin_comment
comment|/**  * This macro will put the value into the pool.  * This should only be called if the pool is not full.  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_put
parameter_list|(
name|this_pool
parameter_list|,
name|the_value
parameter_list|)
define|\
value|{ \    (this_pool).array[(this_pool).put] = (the_value); \    (this_pool).put = SCI_POOL_INCREMENT((this_pool), (this_pool).put); \ }
end_define

begin_comment
comment|/**  * This macro will search the pool and remove any elements in the pool  * matching the supplied value.  * @note This method can only be utilized on pools  */
end_comment

begin_define
define|#
directive|define
name|sci_pool_erase
parameter_list|(
name|this_pool
parameter_list|,
name|type
parameter_list|,
name|the_value
parameter_list|)
define|\
value|{ \    type tmp_value; \    U32 index; \    U32 element_count = sci_pool_count((this_pool)); \  \    for (index = 0; index< element_count; index++) \    { \       sci_pool_get((this_pool), tmp_value); \       if (tmp_value != (the_value)) \          sci_pool_put((this_pool), tmp_value); \    } \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_POOL_H_
end_comment

end_unit

