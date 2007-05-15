begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Nuno Antunes<nuno.antunes@gmail.com>  * Copyright (c) 2007 Alexander Motin<mav@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_CAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_CAR_H_
end_define

begin_define
define|#
directive|define
name|NG_CAR_NODE_TYPE
value|"car"
end_define

begin_define
define|#
directive|define
name|NGM_CAR_COOKIE
value|1173648034
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_CAR_HOOK_UPPER
value|"upper"
end_define

begin_define
define|#
directive|define
name|NG_CAR_HOOK_LOWER
value|"lower"
end_define

begin_comment
comment|/* Per hook statistics counters */
end_comment

begin_struct
struct|struct
name|ng_car_hookstats
block|{
name|u_int64_t
name|passed_pkts
decl_stmt|;
comment|/* Counter for passed packets */
name|u_int64_t
name|droped_pkts
decl_stmt|;
comment|/* Counter for droped packets */
name|u_int64_t
name|green_pkts
decl_stmt|;
comment|/* Counter for green packets */
name|u_int64_t
name|yellow_pkts
decl_stmt|;
comment|/* Counter for yellow packets */
name|u_int64_t
name|red_pkts
decl_stmt|;
comment|/* Counter for red packets */
name|u_int64_t
name|errors
decl_stmt|;
comment|/* Counter for operation errors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_CAR_HOOKSTATS
value|{				\ 	  { "passed",&ng_parse_uint64_type	},	\ 	  { "droped",&ng_parse_uint64_type	},	\ 	  { "green",&ng_parse_uint64_type	},	\ 	  { "yellow",&ng_parse_uint64_type	},	\ 	  { "red",&ng_parse_uint64_type	},	\ 	  { "errors",&ng_parse_uint64_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Bulk statistics */
end_comment

begin_struct
struct|struct
name|ng_car_bulkstats
block|{
name|struct
name|ng_car_hookstats
name|upstream
decl_stmt|;
name|struct
name|ng_car_hookstats
name|downstream
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_CAR_BULKSTATS
parameter_list|(
name|hstatstype
parameter_list|)
value|{				\ 	  { "upstream",		(hstatstype)		},	\ 	  { "downstream",	(hstatstype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Per hook configuration */
end_comment

begin_struct
struct|struct
name|ng_car_hookconf
block|{
name|u_int64_t
name|cbs
decl_stmt|;
comment|/* Commited burst size (bytes) */
name|u_int64_t
name|ebs
decl_stmt|;
comment|/* Exceeded/Peak burst size (bytes) */
name|u_int64_t
name|cir
decl_stmt|;
comment|/* Commited information rate (bits/s) */
name|u_int64_t
name|pir
decl_stmt|;
comment|/* Peak information rate (bits/s) */
name|u_int8_t
name|green_action
decl_stmt|;
comment|/* Action for green packets */
name|u_int8_t
name|yellow_action
decl_stmt|;
comment|/* Action for yellow packets */
name|u_int8_t
name|red_action
decl_stmt|;
comment|/* Action for red packets */
name|u_int8_t
name|mode
decl_stmt|;
comment|/* single/double rate, ... */
name|u_int8_t
name|opt
decl_stmt|;
comment|/* color-aware or color-blind */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this definition in sync with the above structure */
end_comment

begin_define
define|#
directive|define
name|NG_CAR_HOOKCONF
value|{					\ 	  { "cbs",&ng_parse_uint64_type	},	\ 	  { "ebs",&ng_parse_uint64_type	},	\ 	  { "cir",&ng_parse_uint64_type	},	\ 	  { "pir",&ng_parse_uint64_type	},	\ 	  { "greenAction",&ng_parse_uint8_type	},	\ 	  { "yellowAction",&ng_parse_uint8_type	},	\ 	  { "redAction",&ng_parse_uint8_type	},	\ 	  { "mode",&ng_parse_uint8_type	},	\ 	  { "opt",&ng_parse_uint8_type	},	\ 	  { NULL }						\ }
end_define

begin_define
define|#
directive|define
name|NG_CAR_CBS_MIN
value|8192
end_define

begin_define
define|#
directive|define
name|NG_CAR_EBS_MIN
value|8192
end_define

begin_define
define|#
directive|define
name|NG_CAR_CIR_DFLT
value|10240
end_define

begin_comment
comment|/* possible actions (...Action) */
end_comment

begin_enum
enum|enum
block|{
name|NG_CAR_ACTION_FORWARD
init|=
literal|1
block|,
name|NG_CAR_ACTION_DROP
block|,
name|NG_CAR_ACTION_MARK
block|,
name|NG_CAR_ACTION_SET_TOS
block|}
enum|;
end_enum

begin_comment
comment|/* operation modes (mode) */
end_comment

begin_enum
enum|enum
block|{
name|NG_CAR_SINGLE_RATE
init|=
literal|0
block|,
name|NG_CAR_DOUBLE_RATE
block|,
name|NG_CAR_RED
block|,
name|NG_CAR_SHAPE
block|}
enum|;
end_enum

begin_comment
comment|/* mode options (opt) */
end_comment

begin_define
define|#
directive|define
name|NG_CAR_COLOR_AWARE
value|1
end_define

begin_comment
comment|/* Bulk config */
end_comment

begin_struct
struct|struct
name|ng_car_bulkconf
block|{
name|struct
name|ng_car_hookconf
name|upstream
decl_stmt|;
name|struct
name|ng_car_hookconf
name|downstream
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_CAR_BULKCONF
parameter_list|(
name|hconftype
parameter_list|)
value|{				\ 	  { "upstream",		(hconftype)		},	\ 	  { "downstream",	(hconftype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_CAR_GET_STATS
init|=
literal|1
block|,
comment|/* Get statistics */
name|NGM_CAR_CLR_STATS
block|,
comment|/* Clear statistics */
name|NGM_CAR_GETCLR_STATS
block|,
comment|/* Get and clear statistics */
name|NGM_CAR_GET_CONF
block|,
comment|/* Get bulk configuration */
name|NGM_CAR_SET_CONF
block|,
comment|/* Set bulk configuration */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_CAR_H_ */
end_comment

end_unit

