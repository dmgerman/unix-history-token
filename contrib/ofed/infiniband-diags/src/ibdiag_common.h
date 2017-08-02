begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 The Regents of the University of California.  * Copyright (c) 2004-2009 Voltaire Inc.  All rights reserved.  * Copyright (c) 2002-2010 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  * Copyright (c) 2011 Lawrence Livermore National Security. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBDIAG_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_IBDIAG_COMMON_H_
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

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

begin_include
include|#
directive|include
file|<infiniband/ibnetdisc.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|ibverbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ibd_ca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibd_ca_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|MAD_DEST
name|ibd_dest_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ib_portid_t
modifier|*
name|ibd_sm_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibd_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|ibd_ibnetdisc_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|ibd_mkey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|ibd_sakey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|show_keys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ibd_nd_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/*                External interface                      */
end_comment

begin_comment
comment|/*========================================================*/
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { \ 	if (ibdebug) IBDEBUG(fmt, ## __VA_ARGS__); \ } while (0)
end_define

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { \ 	if (ibverbose) IBVERBOSE(fmt, ## __VA_ARGS__); \ } while (0)
end_define

begin_define
define|#
directive|define
name|IBEXIT
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|ibexit(__FUNCTION__, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|NOT_DISPLAYED_STR
value|"<not displayed>"
end_define

begin_comment
comment|/* not all versions of ib_types.h will have this define */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PM_PC_XMIT_WAIT_SUP
end_ifndef

begin_define
define|#
directive|define
name|IB_PM_PC_XMIT_WAIT_SUP
value|(CL_HTON16(((uint16_t)1)<<12))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PM ClassPortInfo CapabilityMask Bits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IS_PM_RSFEC_COUNTERS_SUP
end_ifndef

begin_define
define|#
directive|define
name|IS_PM_RSFEC_COUNTERS_SUP
value|(CL_HTON16(((uint16_t)1)<<14))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PM_IS_QP1_DROP_SUP
end_ifndef

begin_define
define|#
directive|define
name|IB_PM_IS_QP1_DROP_SUP
value|(CL_HTON16(((uint16_t)1)<<15))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PM ClassPortInfo CapabilityMask2 Bits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PM_IS_ADDL_PORT_CTRS_EXT_SUP
end_ifndef

begin_define
define|#
directive|define
name|IB_PM_IS_ADDL_PORT_CTRS_EXT_SUP
value|(CL_HTON32(((uint32_t)1)<<1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM PortInfo CapabilityMask2 Bits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_CAP2_IS_PORT_INFO_EXT_SUPPORTED
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_PORT_INFO_EXT_SUPPORTED
value|(CL_HTON16(0x0002))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM PortInfoExtended Fec Mode Bits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_EXT_NO_FEC_MODE_ACTIVE
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_EXT_NO_FEC_MODE_ACTIVE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_EXT_FIRE_CODE_FEC_MODE_ACTIVE
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_EXT_FIRE_CODE_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0001))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_EXT_RS_FEC_MODE_ACTIVE
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_EXT_RS_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0002))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_EXT_LOW_LATENCY_RS_FEC_MODE_ACTIVE
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_EXT_LOW_LATENCY_RS_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0003))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM PortInfoExtended CapabilityMask Bits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_PORT_EXT_CAP_IS_FEC_MODE_SUPPORTED
end_ifndef

begin_define
define|#
directive|define
name|IB_PORT_EXT_CAP_IS_FEC_MODE_SUPPORTED
value|(CL_HTON32(0x00000001))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ibdiag_opt
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|letter
decl_stmt|;
name|unsigned
name|has_arg
decl_stmt|;
specifier|const
name|char
modifier|*
name|arg_tmpl
decl_stmt|;
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ibdiag_process_opts
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|exclude_common_str
parameter_list|,
specifier|const
name|struct
name|ibdiag_opt
name|custom_opts
index|[]
parameter_list|,
name|int
function_decl|(
modifier|*
name|custom_handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|int
name|val
parameter_list|,
name|char
modifier|*
name|optarg
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|usage_args
parameter_list|,
specifier|const
name|char
modifier|*
name|usage_examples
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ibdiag_show_usage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ibexit
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert counter values to a float with a unit specifier returned (using  * binary prefix)  * "data" is a flag indicating this counter is a byte counter multiplied by 4  * as per PortCounters[Extended]  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|conv_cnt_human_readable
parameter_list|(
name|uint64_t
name|val64
parameter_list|,
name|float
modifier|*
name|val
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_mlnx_ext_port_info_supported
parameter_list|(
name|uint32_t
name|vendorid
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_port_info_extended_supported
parameter_list|(
name|ib_portid_t
modifier|*
name|dest
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|ibmad_port
modifier|*
name|srcport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_max_msg
parameter_list|(
name|char
modifier|*
name|width_msg
parameter_list|,
name|char
modifier|*
name|speed_msg
parameter_list|,
name|int
name|msg_size
parameter_list|,
name|ibnd_port_t
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resolve_sm_portid
parameter_list|(
name|char
modifier|*
name|ca_name
parameter_list|,
name|uint8_t
name|portnum
parameter_list|,
name|ib_portid_t
modifier|*
name|sm_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resolve_self
parameter_list|(
name|char
modifier|*
name|ca_name
parameter_list|,
name|uint8_t
name|ca_port
parameter_list|,
name|ib_portid_t
modifier|*
name|portid
parameter_list|,
name|int
modifier|*
name|port
parameter_list|,
name|ibmad_gid_t
modifier|*
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resolve_portid_str
parameter_list|(
name|char
modifier|*
name|ca_name
parameter_list|,
name|uint8_t
name|ca_port
parameter_list|,
name|ib_portid_t
modifier|*
name|portid
parameter_list|,
name|char
modifier|*
name|addr_str
parameter_list|,
name|enum
name|MAD_DEST
name|dest_type
parameter_list|,
name|ib_portid_t
modifier|*
name|sm_id
parameter_list|,
specifier|const
name|struct
name|ibmad_port
modifier|*
name|srcport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsnprint_field
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|,
name|enum
name|MAD_FIELDS
name|f
parameter_list|,
name|int
name|spacing
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|va_args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snprint_field
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|,
name|enum
name|MAD_FIELDS
name|f
parameter_list|,
name|int
name|spacing
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_portinfo
parameter_list|(
name|void
modifier|*
name|pi
parameter_list|,
name|int
name|tabs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Some common command line parsing  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
name|op_fn_t
function_decl|)
parameter_list|(
name|ib_portid_t
modifier|*
name|dest
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|match_rec
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|alias
decl_stmt|;
name|op_fn_t
modifier|*
name|fn
decl_stmt|;
name|unsigned
name|opt_portnum
decl_stmt|;
name|char
modifier|*
name|ops_extra
decl_stmt|;
block|}
name|match_rec_t
typedef|;
end_typedef

begin_function_decl
name|op_fn_t
modifier|*
name|match_op
parameter_list|(
specifier|const
name|match_rec_t
name|match_tbl
index|[]
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBDIAG_COMMON_H_ */
end_comment

end_unit

