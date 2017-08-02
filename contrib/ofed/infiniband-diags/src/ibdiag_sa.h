begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 The Regents of the University of California.  * Copyright (c) 2004-2009 Voltaire Inc.  All rights reserved.  * Copyright (c) 2002-2010 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  * Copyright (c) 2012 Lawrence Livermore National Security. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBDIAG_SA_H_
end_ifndef

begin_define
define|#
directive|define
name|_IBDIAG_SA_H_
end_define

begin_include
include|#
directive|include
file|<infiniband/mad.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/iba/ib_types.h>
end_include

begin_comment
comment|/* define an SA query structure to be common  * This is by no means optimal but it moves the saquery functionality out of  * the saquery tool and provides it to other utilities.  */
end_comment

begin_struct
struct|struct
name|sa_handle
block|{
name|int
name|fd
decl_stmt|,
name|agent
decl_stmt|;
name|ib_portid_t
name|dport
decl_stmt|;
name|struct
name|ibmad_port
modifier|*
name|srcport
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sa_query_result
block|{
name|uint32_t
name|status
decl_stmt|;
name|unsigned
name|result_cnt
decl_stmt|;
name|void
modifier|*
name|p_result_madw
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* NOTE: umad_init must be called prior to sa_get_handle */
end_comment

begin_function_decl
name|struct
name|sa_handle
modifier|*
name|sa_get_handle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sa_set_handle
parameter_list|(
name|struct
name|sa_handle
modifier|*
name|handle
parameter_list|,
name|int
name|grh_present
parameter_list|,
name|ibmad_gid_t
modifier|*
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa_free_handle
parameter_list|(
name|struct
name|sa_handle
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sa_query
parameter_list|(
name|struct
name|sa_handle
modifier|*
name|h
parameter_list|,
name|uint8_t
name|method
parameter_list|,
name|uint16_t
name|attr
parameter_list|,
name|uint32_t
name|mod
parameter_list|,
name|uint64_t
name|comp_mask
parameter_list|,
name|uint64_t
name|sm_key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datasz
parameter_list|,
name|struct
name|sa_query_result
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa_free_result_mad
parameter_list|(
name|struct
name|sa_query_result
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|sa_get_query_rec
parameter_list|(
name|void
modifier|*
name|mad
parameter_list|,
name|unsigned
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa_report_err
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macros for setting query values and ComponentMasks */
end_comment

begin_define
define|#
directive|define
name|cl_hton8
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|CHECK_AND_SET_VAL
parameter_list|(
name|val
parameter_list|,
name|size
parameter_list|,
name|comp_with
parameter_list|,
name|target
parameter_list|,
name|name
parameter_list|,
name|mask
parameter_list|)
define|\
value|if ((int##size##_t) val != (int##size##_t) comp_with) { \ 		target = cl_hton##size((uint##size##_t) val); \ 		comp_mask |= IB_##name##_COMPMASK_##mask; \ 	}
end_define

begin_define
define|#
directive|define
name|CHECK_AND_SET_GID
parameter_list|(
name|val
parameter_list|,
name|target
parameter_list|,
name|name
parameter_list|,
name|mask
parameter_list|)
define|\
value|if (valid_gid(&(val))) { \ 		memcpy(&(target),&(val), sizeof(val)); \ 		comp_mask |= IB_##name##_COMPMASK_##mask; \ 	}
end_define

begin_define
define|#
directive|define
name|CHECK_AND_SET_VAL_AND_SEL
parameter_list|(
name|val
parameter_list|,
name|target
parameter_list|,
name|name
parameter_list|,
name|mask
parameter_list|,
name|sel
parameter_list|)
define|\
value|if (val) { \ 		target = val; \ 		comp_mask |= IB_##name##_COMPMASK_##mask##sel; \ 		comp_mask |= IB_##name##_COMPMASK_##mask; \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBDIAG_SA_H_ */
end_comment

end_unit

