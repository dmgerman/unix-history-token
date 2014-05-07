begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ARRAY_SIZE
end_ifndef

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Normal byte swap macro  */
end_comment

begin_define
define|#
directive|define
name|SCIC_SWAP_DWORD
parameter_list|(
name|x
parameter_list|)
define|\
value|( \        (((x)>> 24)& 0x000000FF) \      | (((x)>>  8)& 0x0000FF00) \      | (((x)<<  8)& 0x00FF0000) \      | (((x)<< 24)& 0xFF000000) \    )
end_define

begin_define
define|#
directive|define
name|SCIC_BUILD_DWORD
parameter_list|(
name|char_buffer
parameter_list|)
define|\
value|( \      ((char_buffer)[0]<< 24) \    | ((char_buffer)[1]<< 16) \    | ((char_buffer)[2]<<  8) \    | ((char_buffer)[3]) \    )
end_define

begin_define
define|#
directive|define
name|SCI_FIELD_OFFSET
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((POINTER_UINT)&(((type *)0)->field))
end_define

begin_comment
comment|//This macro counts how many bits being set in a mask.
end_comment

begin_define
define|#
directive|define
name|SCI_GET_BITS_SET_COUNT
parameter_list|(
name|mask
parameter_list|,
name|set_bit_count
parameter_list|)
define|\
value|{                                                  \    U8 index;                                       \    set_bit_count = 0;                              \    for (index = 0; index< sizeof(mask)*8; index++)            \    {                                               \       if( mask& (1<<index) )                      \          set_bit_count++;                          \    }                                               \ }
end_define

begin_comment
comment|/**  * This macro simply performs addition on an SCI_PHYSICAL_ADDRESS  * type.  The lower U32 value is "clipped" or "wrapped" back through  * 0.  When this occurs the upper 32-bits are incremented by 1.  */
end_comment

begin_define
define|#
directive|define
name|sci_physical_address_add
parameter_list|(
name|physical_address
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \    U32 lower = sci_cb_physical_address_lower((physical_address)); \    U32 upper = sci_cb_physical_address_upper((physical_address)); \  \    if (lower + (value)< lower) \       upper += 1; \  \    lower += (value); \    sci_cb_make_physical_address(physical_address, upper, lower); \ }
end_define

begin_comment
comment|/**  * This macro simply performs subtraction on an SCI_PHYSICAL_ADDRESS  * type.  The lower U32 value is "clipped" or "wrapped" back through  * 0.  When this occurs the upper 32-bits are decremented by 1.  */
end_comment

begin_define
define|#
directive|define
name|sci_physical_address_subtract
parameter_list|(
name|physical_address
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \    U32 lower = sci_cb_physical_address_lower((physical_address)); \    U32 upper = sci_cb_physical_address_upper((physical_address)); \  \    if (lower - (value)> lower) \       upper -= 1; \  \    lower -= (value); \    sci_cb_make_physical_address(physical_address, upper, lower); \ }
end_define

begin_comment
comment|/**  * @brief Copy the data from source to destination and swap the  *        bytes during the copy.  *  * @param[in] destination This parameter specifies the destination address  *            to which the data is to be copied.  * @param[in] source This parameter specifies the source address from  *            which data is to be copied.  * @param[in] word_count This parameter specifies the number of 32-bit words  *            to copy and byte swap.  *  * @return none  */
end_comment

begin_function_decl
name|void
name|scic_word_copy_with_swap
parameter_list|(
name|U32
modifier|*
name|destination
parameter_list|,
name|U32
modifier|*
name|source
parameter_list|,
name|U32
name|word_count
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sci_ssp_get_sense_data_length
parameter_list|(
name|sense_data_length_buffer
parameter_list|)
define|\
value|SCIC_BUILD_DWORD(sense_data_length_buffer)
end_define

begin_define
define|#
directive|define
name|sci_ssp_get_response_data_length
parameter_list|(
name|response_data_length_buffer
parameter_list|)
define|\
value|SCIC_BUILD_DWORD(response_data_length_buffer)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_UTIL_H_
end_comment

end_unit

