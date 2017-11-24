begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2011 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 Sun Microsystems, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Basic OpenSM definitions and structures.  *	This object represents an OpenSM "base class".  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_BASE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_BASE_H_
end_define

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_include
include|#
directive|include
file|<vendor/winosm_common.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* OpenSM/Constants * NAME *	Constants * * DESCRIPTION *	The following constants are used throughout the OpenSM. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****h* OpenSM/Base * NAME *	Base * * DESCRIPTION *	The Base object encapsulates basic information needed by the *	OpenSM to manage objects.  Each OpenSM object includes the *	Base object as the first member. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_M_KEY * NAME *	OSM_DEFAULT_M_KEY * * DESCRIPTION *	Managment key value used by the OpenSM. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_M_KEY
value|0
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_SM_KEY * NAME *	OSM_DEFAULT_SM_KEY * * DESCRIPTION *	Subnet Manager key value used by the OpenSM. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SM_KEY
value|CL_HTON64(1)
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_SA_KEY * NAME *	OSM_DEFAULT_SA_KEY * * DESCRIPTION *	Subnet Adminstration key value. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SA_KEY
value|OSM_DEFAULT_SM_KEY
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_LMC * NAME *	OSM_DEFAULT_LMC * * DESCRIPTION *	Default LMC value used by the OpenSM. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_LMC
value|0
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_MAX_OP_VLS * NAME *	OSM_DEFAULT_MAX_OP_VLS * * DESCRIPTION *	Default Maximal Operational VLs to be initialized on *  the link ports PortInfo by the OpenSM. *  Default value provides backward compatibility. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_MAX_OP_VLS
value|5
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_SL * NAME *	OSM_DEFAULT_SL * * DESCRIPTION *	Default SL value used by the OpenSM. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SL
value|0
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_SCATTER_PORTS * NAME *	OSM_DEFAULT_SCATTER_PORTS * * DESCRIPTION *	Default Scatter Ports value used by OpenSM. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SCATTER_PORTS
value|0
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_SM_PRIORITY * NAME *	OSM_DEFAULT_SM_PRIORITY * * DESCRIPTION *	Default SM priority value used by the OpenSM, *	as defined in the SMInfo attribute.  0 is the lowest priority. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SM_PRIORITY
value|0
end_define

begin_comment
comment|/********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_TMP_DIR * NAME *	OSM_DEFAULT_TMP_DIR * * DESCRIPTION *	Specifies the default temporary directory for the log file, *  osm-subnet.lst, and other log files. * * SYNOPSIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_define
define|#
directive|define
name|OSM_DEFAULT_TMP_DIR
value|"%TEMP%\\"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_TMP_DIR
value|"/var/log/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_CACHE_DIR * NAME *	OSM_DEFAULT_CACHE_DIR * * DESCRIPTION *	Specifies the default cache directory for the db files. * * SYNOPSIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_define
define|#
directive|define
name|OSM_DEFAULT_CACHE_DIR
value|"%TEMP%"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_CACHE_DIR
value|"/var/cache/opensm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_LOG_FILE * NAME *	OSM_DEFAULT_LOG_FILE * * DESCRIPTION *	Specifies the default log file name * * SYNOPSIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_define
define|#
directive|define
name|OSM_DEFAULT_LOG_FILE
value|OSM_DEFAULT_TMP_DIR "osm.log"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_LOG_FILE
value|"/var/log/opensm.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_CONFIG_FILE * NAME *	OSM_DEFAULT_CONFIG_FILE * * DESCRIPTION *	Specifies the default OpenSM config file name * * SYNOPSIS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DEFAULT_OPENSM_CONFIG_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSM_DEFAULT_CONFIG_FILE
value|HAVE_DEFAULT_OPENSM_CONFIG_FILE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_CONFIG_FILE
value|OPENSM_CONFIG_DIR "/opensm.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_CONFIG_FILE
value|"/etc/opensm/opensm.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_PARTITION_CONFIG_FILE * NAME *	OSM_DEFAULT_PARTITION_CONFIG_FILE * * DESCRIPTION *	Specifies the default partition config file name * * SYNOPSIS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DEFAULT_PARTITION_CONFIG_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSM_DEFAULT_PARTITION_CONFIG_FILE
value|HAVE_DEFAULT_PARTITION_CONFIG_FILE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_PARTITION_CONFIG_FILE
value|OPENSM_CONFIG_DIR "/partitions.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_PARTITION_CONFIG_FILE
value|"/etc/opensm/partitions.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_POLICY_FILE * NAME *	OSM_DEFAULT_QOS_POLICY_FILE * * DESCRIPTION *	Specifies the default QoS policy file name * * SYNOPSIS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DEFAULT_QOS_POLICY_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_POLICY_FILE
value|HAVE_DEFAULT_QOS_POLICY_FILE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_POLICY_FILE
value|OPENSM_CONFIG_DIR "/qos-policy.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_POLICY_FILE
value|"/etc/opensm/qos-policy.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_TORUS_CONF_FILE * NAME *	OSM_DEFAULT_TORUS_CONF_FILE * * DESCRIPTION *	Specifies the default file name for extra torus-2QoS configuration * * SYNOPSIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_define
define|#
directive|define
name|OSM_DEFAULT_TORUS_CONF_FILE
value|strcat(GetOsmCachePath(), "osm-torus-2QoS.conf")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_TORUS_CONF_FILE
value|OPENSM_CONFIG_DIR "/torus-2QoS.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_TORUS_CONF_FILE
value|"/etc/opensm/torus-2QoS.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __WIN__ */
end_comment

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_PREFIX_ROUTES_FILE * NAME *	OSM_DEFAULT_PREFIX_ROUTES_FILE * * DESCRIPTION *	Specifies the default prefix routes file name * * SYNOPSIS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DEFAULT_PREFIX_ROUTES_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSM_DEFAULT_PREFIX_ROUTES_FILE
value|HAVE_DEFAULT_PREFIX_ROUTES_FILE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_PREFIX_ROUTES_FILE
value|OPENSM_CONFIG_DIR "/prefix-routes.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_PREFIX_ROUTES_FILE
value|"/etc/opensm/prefix-routes.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_PER_MOD_LOGGING_CONF_FILE * NAME *	OSM_DEFAULT_PER_MOD_LOGGING_CONF_FILE * * DESCRIPTION *	Specifies the default file name for per module logging configuration * * SYNOPSIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_define
define|#
directive|define
name|OSM_DEFAULT_PER_MOD_LOGGING_CONF_FILE
value|strcat(GetOsmCachePath(), "per-module-logging.conf")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSM_CONFIG_DIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSM_DEFAULT_PER_MOD_LOGGING_CONF_FILE
value|OPENSM_CONFIG_DIR "/per-module-logging.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_DEFAULT_PER_MOD_LOGGING_CONF_FILE
value|"/etc/opensm/per-module-logging.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __WIN__ */
end_comment

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_SWEEP_INTERVAL_SECS * NAME *	OSM_DEFAULT_SWEEP_INTERVAL_SECS * * DESCRIPTION *	Specifies the default number of seconds between subnet sweeps. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SWEEP_INTERVAL_SECS
value|10
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_TRANS_TIMEOUT_MILLISEC * NAME *	OSM_DEFAULT_TRANS_TIMEOUT_MILLISEC * * DESCRIPTION *	Specifies the default transaction timeout in milliseconds. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_TRANS_TIMEOUT_MILLISEC
value|200
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_SUBNET_TIMEOUT * NAME *	OSM_DEFAULT_SUBNET_TIMEOUT * * DESCRIPTION *	Specifies the default subnet timeout. *	timeout time = 4us * 2^timeout. *  We use here ~1sec. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SUBNET_TIMEOUT
value|0x12
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_SWITCH_PACKET_LIFE * NAME *	OSM_DEFAULT_SWITCH_PACKET_LIFE * * DESCRIPTION *	Specifies the default max life time for a pcket on the switch. *	timeout time = 4us * 2^timeout. *  We use here the value of ~1sec *  A Value> 19dec disables this mechanism. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SWITCH_PACKET_LIFE
value|0x12
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_HEAD_OF_QUEUE_LIFE * NAME *	OSM_DEFAULT_HEAD_OF_QUEUE_LIFE * * DESCRIPTION *	Sets the time a packet can live in the head of the VL Queue *  We use here the value of ~1sec *  A Value> 19dec disables this mechanism. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_HEAD_OF_QUEUE_LIFE
value|0x12
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_LEAF_HEAD_OF_QUEUE_LIFE * NAME *	OSM_DEFAULT_LEAF_HEAD_OF_QUEUE_LIFE * * DESCRIPTION *	Sets the time a packet can live in the head of the VL Queue *  of a port that drives a CA port. *  We use here the value of ~256msec * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_LEAF_HEAD_OF_QUEUE_LIFE
value|0x10
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_VL_STALL_COUNT * NAME *	OSM_DEFAULT_LEAF_VL_COUNT * * DESCRIPTION *	Sets the number of consecutive head of queue life time drops that *  puts the VL into stalled state. In stalled state, the port is supposed *  to drop everything for 8*(head of queue lifetime) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_VL_STALL_COUNT
value|0x7
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_LEAF_VL_STALL_COUNT * NAME *	OSM_DEFAULT_LEAF_VL_STALL_COUNT * * DESCRIPTION *	Sets the number of consecutive head of queue life time drops that *  puts the VL into stalled state. In stalled state, the port is supposed *  to drop everything for 8*(head of queue lifetime). This value is for *  switch ports driving a CA port. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_LEAF_VL_STALL_COUNT
value|0x7
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_TRAP_SUPRESSION_TIMEOUT * NAME *	OSM_DEFAULT_TRAP_SUPRESSION_TIMEOUT * * DESCRIPTION *	Specifies the default timeout for ignoring same trap. *	timeout time = 5000000us *  We use here ~5sec. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_TRAP_SUPRESSION_TIMEOUT
value|5000000
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_UNHEALTHY_TIMEOUT * NAME *	OSM_DEFAULT_UNHEALTHY_TIMEOUT * * DESCRIPTION *	Specifies the default timeout for setting port as unhealthy. *	timeout time = 60000000us *  We use here ~60sec. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_UNHEALTHY_TIMEOUT
value|60000000
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_ERROR_THRESHOLD * NAME *	OSM_DEFAULT_ERROR_THRESHOLD * * DESCRIPTION *	Specifies default link error threshold to be set by SubnSet(PortInfo). * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_ERROR_THRESHOLD
value|0x08
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_SMP_MAX_ON_WIRE * NAME *	OSM_DEFAULT_SMP_MAX_ON_WIRE * * DESCRIPTION *	Specifies the default number of VL15 SMP MADs allowed on *	the wire at any one time. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_SMP_MAX_ON_WIRE
value|4
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_QP0_RCV_SIZE * NAME *	OSM_SM_DEFAULT_QP0_RCV_SIZE * * DESCRIPTION *	Specifies the default size (in MADs) of the QP0 receive queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_QP0_RCV_SIZE
value|256
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_QP0_SEND_SIZE * NAME *	OSM_SM_DEFAULT_QP0_SEND_SIZE * * DESCRIPTION *	Specifies the default size (in MADs) of the QP0 send queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_QP0_SEND_SIZE
value|256
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_QP1_RCV_SIZE * NAME *   OSM_SM_DEFAULT_QP1_RCV_SIZE * * DESCRIPTION *   Specifies the default size (in MADs) of the QP1 receive queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_QP1_RCV_SIZE
value|256
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_QP1_SEND_SIZE * NAME *   OSM_SM_DEFAULT_QP1_SEND_SIZE * * DESCRIPTION *   Specifies the default size (in MADs) of the QP1 send queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_QP1_SEND_SIZE
value|256
end_define

begin_comment
comment|/****d* OpenSM: Base/OSM_PM_DEFAULT_QP1_RCV_SIZE * NAME *   OSM_PM_DEFAULT_QP1_RCV_SIZE * * DESCRIPTION *   Specifies the default size (in MADs) of the QP1 receive queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_PM_DEFAULT_QP1_RCV_SIZE
value|256
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_PM_DEFAULT_QP1_SEND_SIZE * NAME *   OSM_PM_DEFAULT_QP1_SEND_SIZE * * DESCRIPTION *   Specifies the default size (in MADs) of the QP1 send queue * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_PM_DEFAULT_QP1_SEND_SIZE
value|256
end_define

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_POLLING_TIMEOUT_MILLISECS * NAME *   OSM_SM_DEFAULT_POLLING_TIMEOUT_MILLISECS * * DESCRIPTION *   Specifies the polling timeout (in miliseconds) - the timeout *   between one poll to another. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_POLLING_TIMEOUT_MILLISECS
value|10000
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_SM_DEFAULT_POLLING_RETRY_NUMBER * NAME *   OSM_SM_DEFAULT_POLLING_RETRY_NUMBER * * DESCRIPTION *   Specifies the number of polling retries before the SM goes back *   to DISCOVERY stage. So the default total time for handoff is 40 sec. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SM_DEFAULT_POLLING_RETRY_NUMBER
value|4
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* OpenSM: MC Member Record Receiver/OSM_DEFAULT_MGRP_MTU * Name *	OSM_DEFAULT_MGRP_MTU * * DESCRIPTION *	Default MTU used for new MGRP creation (2048 bytes) *  Note it includes the MTUSelector which is set to "Greater Than" * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_MGRP_MTU
value|0x04
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: MC Member Record Receiver/OSM_DEFAULT_MGRP_RATE * Name *	OSM_DEFAULT_MGRP_RATE * * DESCRIPTION *	Default RATE used for new MGRP creation (10Gb/sec) *  Note it includes the RateSelector which is set to "Greater Than" * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_MGRP_RATE
value|0x03
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: MC Member Record Receiver/OSM_DEFAULT_MGRP_SCOPE * Name *	OSM_DEFAULT_MGRP_SCOPE * * DESCRIPTION *	Default SCOPE used for new MGRP creation (link local) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_MGRP_SCOPE
value|IB_MC_SCOPE_LINK_LOCAL
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_MAX_VLS  * Name  *       OSM_DEFAULT_QOS_MAX_VLS  *  * DESCRIPTION  *       Default Maximum VLs used by the OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_MAX_VLS
value|15
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_HIGH_LIMIT  * Name  *       OSM_DEFAULT_QOS_HIGH_LIMIT  *  * DESCRIPTION  *       Default Limit of High Priority in VL Arbitration used by OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_HIGH_LIMIT
value|0
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_VLARB_HIGH  * Name  *       OSM_DEFAULT_QOS_VLARB_HIGH  *  * DESCRIPTION  *       Default High Priority VL Arbitration table used by the OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_VLARB_HIGH
value|"0:4,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0,13:0,14:0"
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_VLARB_LOW  * Name  *       OSM_DEFAULT_QOS_VLARB_LOW  *  * DESCRIPTION  *       Default Low Priority VL Arbitration table used by the OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_VLARB_LOW
value|"0:0,1:4,2:4,3:4,4:4,5:4,6:4,7:4,8:4,9:4,10:4,11:4,12:4,13:4,14:4"
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_DEFAULT_QOS_SL2VL  * Name  *       OSM_DEFAULT_QOS_SL2VL  *  * DESCRIPTION  *       Default QoS SL2VL Mapping Table used by the OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_QOS_SL2VL
value|"0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,7"
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_NO_PATH * NAME *	OSM_NO_PATH * * DESCRIPTION *	Value indicating there is no path to the given LID. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_NO_PATH
value|0xFF
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_NODE_DESC_UNKNOWN * NAME *	OSM_NODE_DESC_UNKNOWN * * DESCRIPTION *	Value indicating the Node Description is not set and is "unknown" * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_NODE_DESC_UNKNOWN
value|"<unknown>"
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/osm_thread_state_t * NAME *	osm_thread_state_t * * DESCRIPTION *	Enumerates the possible states of worker threads, such *	as the subnet sweeper. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_thread_state
block|{
name|OSM_THREAD_STATE_NONE
init|=
literal|0
block|,
name|OSM_THREAD_STATE_INIT
block|,
name|OSM_THREAD_STATE_RUN
block|,
name|OSM_THREAD_STATE_EXIT
block|}
name|osm_thread_state_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/*  * OSM_CAP are from IBA 1.2.1 Table 117 and Table 188  */
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_TRAP_SUP * Name *	OSM_CAP_IS_SUBN_TRAP_SUP * * DESCRIPTION *	Management class generates Trap() MADs * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_SUBN_TRAP_SUP
value|(1<< 0)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_GET_SET_NOTICE_SUP * Name *	OSM_CAP_IS_GET_SET_NOTICE_SUP * * DESCRIPTION *       Management class supports Get/Set(Notice) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_SUBN_GET_SET_NOTICE_SUP
value|(1<< 1)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_SUBN_OPT_RECS_SUP * Name *	OSM_CAP_IS_SUBN_OPT_RECS_SUP * * DESCRIPTION *	Support all optional attributes except: *  MCMemberRecord, TraceRecord, MultiPathRecord * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_SUBN_OPT_RECS_SUP
value|(1<< 8)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_UD_MCAST_SUP * Name *	OSM_CAP_IS_UD_MCAST_SUP * * DESCRIPTION *	Multicast is supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_UD_MCAST_SUP
value|(1<< 9)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_MULTIPATH_SUP * Name *	OSM_CAP_IS_MULTIPATH_SUP * * DESCRIPTION *	MultiPathRecord and TraceRecord are supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_MULTIPATH_SUP
value|(1<< 10)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_REINIT_SUP * Name *	OSM_CAP_IS_REINIT_SUP * * DESCRIPTION *	SM/SA supports re-initialization supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_REINIT_SUP
value|(1<< 11)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP_IS_PORT_INFO_CAPMASK_MATCH_SUPPORTED * Name *	OSM_CAP_IS_PORT_INFO_CAPMASK_MATCH_SUPPORTED * * DESCRIPTION *	SM/SA supports enhanced SA PortInfoRecord searches per 1.2 Errata: *  ClassPortInfo:CapabilityMask.IsPortInfoCapMaskMatchSupported is 1, *  then the AttributeModifier of the SubnAdmGet() and SubnAdmGetTable() *  methods affects the matching behavior on the PortInfo:CapabilityMask *  component. If the high-order bit (bit 31) of the AttributeModifier *  is set to 1, matching on the CapabilityMask component will not be an *  exact bitwise match as described in<ref to 15.4.4>.  Instead, *  matching will only be performed on those bits which are set to 1 in *  the PortInfo:CapabilityMask embedded in the query. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP_IS_PORT_INFO_CAPMASK_MATCH_SUPPORTED
value|(1<< 13)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_QOS_SUPPORTED * Name *	OSM_CAP2_IS_QOS_SUPPORTED * * DESCRIPTION *	QoS is supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_QOS_SUPPORTED
value|(1<< 1)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_REVERSE_PATH_PKEY_SUPPPORTED * Name *	OSM_CAP2_IS_REVERSE_PATH_PKEY_SUPPPORTED * * DESCRIPTION *	Reverse path PKeys indicate in PathRecord responses * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_REVERSE_PATH_PKEY_SUPPPORTED
value|(1<< 2)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_MCAST_TOP_SUPPORTED * Name *	OSM_CAP2_IS_MCAST_TOP_SUPPORTED * * DESCRIPTION *       SwitchInfo.MulticastFDBTop is supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_MCAST_TOP_SUPPORTED
value|(1<< 3)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_HIERARCHY_SUPPORTED * Name * * DESCRIPTION *	Hierarchy info supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_HIERARCHY_SUPPORTED
value|(1<< 4)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_ALIAS_GUIDS_SUPPORTED * Name * * DESCRIPTION *	Alias GUIDs supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_ALIAS_GUIDS_SUPPORTED
value|(1<< 5)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_FULL_PORTINFO_REC_SUPPORTED * Name *	OSM_CAP2_IS_FULL_PORTINFO_REC_SUPPORTED * * DESCRIPTION *	Full PortInfoRecords supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_FULL_PORTINFO_REC_SUPPORTED
value|(1<< 6)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_EXTENDED_SPEEDS_SUPPORTED * Name *	OSM_CAP2_IS_EXTENDED_SPEEDS_SUPPORTED * * DESCRIPTION *	Extended Link Speeds supported * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_EXTENDED_SPEEDS_SUPPORTED
value|(1<< 7)
end_define

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_MULTICAST_SERVICE_RECS_SUPPORTED  * Name  *	OSM_CAP2_IS_MULTICAST_SERVICE_RECS_SUPPORTED  *  * DESCRIPTION  *	Multicast Service Records supported  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_MULTICAST_SERVICE_RECS_SUPPORTED
value|(1<< 8)
end_define

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_PORT_INFO_CAPMASK2_MATCH_SUPPORTED  * Name  *	OSM_CAP2_IS_PORT_INFO_CAPMASK2_MATCH_SUPPORTED  *  * DESCRIPTION  *	CapMask2 matching for PortInfoRecord supported  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_PORT_INFO_CAPMASK2_MATCH_SUPPORTED
value|(1<< 10)
end_define

begin_comment
comment|/****d* OpenSM: Base/OSM_CAP2_IS_LINK_WIDTH_2X_SUPPORTED  * Name  *	OSM_CAP2_IS_LINK_WIDTH_2X_SUPPORTED  *  * DESCRIPTION  *	2x link widths supported  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_CAP2_IS_LINK_WIDTH_2X_SUPPORTED
value|(1<< 13)
end_define

begin_comment
comment|/****d* OpenSM: Base/osm_signal_t * NAME *	osm_signal_t * * DESCRIPTION *	Enumerates the possible signal codes used by the OSM managers *	This cannot be an enum type, since conversion to and from *	integral types is necessary when passing signals through *	the dispatcher. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_SIGNAL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OSM_SIGNAL_SWEEP
value|1
end_define

begin_define
define|#
directive|define
name|OSM_SIGNAL_IDLE_TIME_PROCESS_REQUEST
value|2
end_define

begin_define
define|#
directive|define
name|OSM_SIGNAL_PERFMGR_SWEEP
value|3
end_define

begin_define
define|#
directive|define
name|OSM_SIGNAL_GUID_PROCESS_REQUEST
value|4
end_define

begin_define
define|#
directive|define
name|OSM_SIGNAL_MAX
value|5
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|osm_signal_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: Base/osm_sm_signal_t * NAME *	osm_sm_signal_t * * DESCRIPTION *	Enumerates the possible signals used by the OSM_SM_MGR * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_sm_signal
block|{
name|OSM_SM_SIGNAL_NONE
init|=
literal|0
block|,
name|OSM_SM_SIGNAL_DISCOVERY_COMPLETED
block|,
name|OSM_SM_SIGNAL_POLLING_TIMEOUT
block|,
name|OSM_SM_SIGNAL_DISCOVER
block|,
name|OSM_SM_SIGNAL_DISABLE
block|,
name|OSM_SM_SIGNAL_HANDOVER
block|,
name|OSM_SM_SIGNAL_HANDOVER_SENT
block|,
name|OSM_SM_SIGNAL_ACKNOWLEDGE
block|,
name|OSM_SM_SIGNAL_STANDBY
block|,
name|OSM_SM_SIGNAL_MASTER_OR_HIGHER_SM_DETECTED
block|,
name|OSM_SM_SIGNAL_WAIT_FOR_HANDOVER
block|,
name|OSM_SM_SIGNAL_MAX
block|}
name|osm_sm_signal_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/MAX_GUID_FILE_LINE_LENGTH * NAME *	MAX_GUID_FILE_LINE_LENGTH * * DESCRIPTION *	The maximum line number when reading guid file * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|MAX_GUID_FILE_LINE_LENGTH
value|120
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* OpenSM: Base/VendorOUIs * NAME *	VendorOUIs * * DESCRIPTION *	Known device vendor ID and GUID OUIs * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_INTEL
value|0x00D0B7
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_MELLANOX
value|0x0002C9
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_REDSWITCH
value|0x000617
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_SILVERSTORM
value|0x00066A
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_TOPSPIN
value|0x0005AD
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_FUJITSU
value|0x00E000
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_FUJITSU2
value|0x000B5D
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_VOLTAIRE
value|0x0008F1
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_YOTTAYOTTA
value|0x000453
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_PATHSCALE
value|0x001175
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_IBM
value|0x000255
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_DIVERGENET
value|0x00084E
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_FLEXTRONICS
value|0x000B8C
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_AGILENT
value|0x0030D3
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_OBSIDIAN
value|0x001777
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_BAYMICRO
value|0x000BC1
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_LSILOGIC
value|0x00A0B8
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_DDN
value|0x0001FF
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_PANTA
value|0x001393
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_HP
value|0x001708
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_RIOWORKS
value|0x005045
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_SUN
value|0x0003BA
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_SUN2
value|0x002128
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_3LEAFNTWKS
value|0x0016A1
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_XSIGO
value|0x001397
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_HP2
value|0x0018FE
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_DELL
value|0x00188B
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_SUPERMICRO
value|0x003048
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_HP3
value|0x0019BB
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_HP4
value|0x00237D
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_OPENIB
value|0x001405
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_IBM2
value|0x5CF3FC
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_MELLANOX2
value|0xF45214
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_MELLANOX3
value|0x00258B
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_MELLANOX4
value|0xE41D2D
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_MELLANOX5
value|0x7CFE90
end_define

begin_define
define|#
directive|define
name|OSM_VENDOR_ID_BULL
value|0x080038
end_define

begin_comment
comment|/* IPoIB Broadcast Defaults */
end_comment

begin_define
define|#
directive|define
name|OSM_IPOIB_BROADCAST_MGRP_QKEY
value|0x0b1b
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|ib_gid_t
name|osm_ipoib_broadcast_mgid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_BASE_H_ */
end_comment

end_unit

