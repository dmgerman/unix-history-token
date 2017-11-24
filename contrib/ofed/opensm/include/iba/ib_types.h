begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2011 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  * Copyright (c) 2013 Oracle and/or its affiliates. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IB_TYPES_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__IB_TYPES_H__
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_byteswap.h>
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

begin_function
name|BEGIN_C_DECLS
if|#
directive|if
name|defined
argument_list|(
name|__WIN__
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|EXPORT_AL_SYMBOLS
argument_list|)
define|#
directive|define
name|OSM_EXPORT
value|__declspec(dllexport)
else|#
directive|else
define|#
directive|define
name|OSM_EXPORT
value|__declspec(dllimport)
endif|#
directive|endif
define|#
directive|define
name|OSM_API
value|__stdcall
define|#
directive|define
name|OSM_CDECL
value|__cdecl
else|#
directive|else
define|#
directive|define
name|OSM_EXPORT
value|extern
define|#
directive|define
name|OSM_API
define|#
directive|define
name|OSM_CDECL
define|#
directive|define
name|__ptr64
endif|#
directive|endif
comment|/****h* IBA Base/Constants * NAME *	Constants * * DESCRIPTION *	The following constants are used throughout the IBA code base. * *	Definitions are from the InfiniBand Architecture Specification v1.3.1 * *********/
comment|/****d* IBA Base: Constants/MAD_BLOCK_SIZE * NAME *	MAD_BLOCK_SIZE * * DESCRIPTION *	Size of a non-RMPP MAD datagram. * * SOURCE */
define|#
directive|define
name|MAD_BLOCK_SIZE
value|256
comment|/**********/
comment|/****d* IBA Base: Constants/MAD_RMPP_HDR_SIZE * NAME *	MAD_RMPP_HDR_SIZE * * DESCRIPTION *	Size of an RMPP header, including the common MAD header. * * SOURCE */
define|#
directive|define
name|MAD_RMPP_HDR_SIZE
value|36
comment|/**********/
comment|/****d* IBA Base: Constants/MAD_RMPP_DATA_SIZE * NAME *	MAD_RMPP_DATA_SIZE * * DESCRIPTION *	Size of an RMPP transaction data section. * * SOURCE */
define|#
directive|define
name|MAD_RMPP_DATA_SIZE
value|(MAD_BLOCK_SIZE - MAD_RMPP_HDR_SIZE)
comment|/**********/
comment|/****d* IBA Base: Constants/MAD_BLOCK_GRH_SIZE * NAME *	MAD_BLOCK_GRH_SIZE * * DESCRIPTION *	Size of a MAD datagram, including the GRH. * * SOURCE */
define|#
directive|define
name|MAD_BLOCK_GRH_SIZE
value|296
comment|/**********/
comment|/****d* IBA Base: Constants/IB_LID_PERMISSIVE * NAME *	IB_LID_PERMISSIVE * * DESCRIPTION *	Permissive LID * * SOURCE */
define|#
directive|define
name|IB_LID_PERMISSIVE
value|0xFFFF
comment|/**********/
comment|/****d* IBA Base: Constants/IB_DEFAULT_PKEY * NAME *	IB_DEFAULT_PKEY * * DESCRIPTION *	P_Key value for the default partition. * * SOURCE */
define|#
directive|define
name|IB_DEFAULT_PKEY
value|0xFFFF
comment|/**********/
comment|/****d* IBA Base: Constants/IB_QP1_WELL_KNOWN_Q_KEY * NAME *	IB_QP1_WELL_KNOWN_Q_KEY * * DESCRIPTION *	Well-known Q_Key for QP1 privileged mode access (15.4.2). * * SOURCE */
define|#
directive|define
name|IB_QP1_WELL_KNOWN_Q_KEY
value|CL_HTON32(0x80010000)
comment|/*********/
define|#
directive|define
name|IB_QP0
value|0
define|#
directive|define
name|IB_QP1
value|CL_HTON32(1)
define|#
directive|define
name|IB_QP_PRIVILEGED_Q_KEY
value|CL_HTON32(0x80000000)
comment|/****d* IBA Base: Constants/IB_LID_UCAST_START * NAME *	IB_LID_UCAST_START * * DESCRIPTION *	Lowest valid unicast LID value. * * SOURCE */
define|#
directive|define
name|IB_LID_UCAST_START_HO
value|0x0001
define|#
directive|define
name|IB_LID_UCAST_START
value|(CL_HTON16(IB_LID_UCAST_START_HO))
comment|/**********/
comment|/****d* IBA Base: Constants/IB_LID_UCAST_END * NAME *	IB_LID_UCAST_END * * DESCRIPTION *	Highest valid unicast LID value. * * SOURCE */
define|#
directive|define
name|IB_LID_UCAST_END_HO
value|0xBFFF
define|#
directive|define
name|IB_LID_UCAST_END
value|(CL_HTON16(IB_LID_UCAST_END_HO))
comment|/**********/
comment|/****d* IBA Base: Constants/IB_LID_MCAST_START * NAME *	IB_LID_MCAST_START * * DESCRIPTION *	Lowest valid multicast LID value. * * SOURCE */
define|#
directive|define
name|IB_LID_MCAST_START_HO
value|0xC000
define|#
directive|define
name|IB_LID_MCAST_START
value|(CL_HTON16(IB_LID_MCAST_START_HO))
comment|/**********/
comment|/****d* IBA Base: Constants/IB_LID_MCAST_END * NAME *	IB_LID_MCAST_END * * DESCRIPTION *	Highest valid multicast LID value. * * SOURCE */
define|#
directive|define
name|IB_LID_MCAST_END_HO
value|0xFFFE
define|#
directive|define
name|IB_LID_MCAST_END
value|(CL_HTON16(IB_LID_MCAST_END_HO))
comment|/**********/
comment|/****d* IBA Base: Constants/IB_DEFAULT_SUBNET_PREFIX * NAME *	IB_DEFAULT_SUBNET_PREFIX * * DESCRIPTION *	Default subnet GID prefix. * * SOURCE */
define|#
directive|define
name|IB_DEFAULT_SUBNET_PREFIX
value|(CL_HTON64(0xFE80000000000000ULL))
define|#
directive|define
name|IB_DEFAULT_SUBNET_PREFIX_HO
value|(0xFE80000000000000ULL)
comment|/**********/
comment|/****d* IBA Base: Constants/IB_NODE_NUM_PORTS_MAX * NAME *	IB_NODE_NUM_PORTS_MAX * * DESCRIPTION *	Maximum number of ports in a single node (14.2.5.7). * SOURCE */
define|#
directive|define
name|IB_NODE_NUM_PORTS_MAX
value|0xFE
comment|/**********/
comment|/****d* IBA Base: Constants/IB_INVALID_PORT_NUM * NAME *	IB_INVALID_PORT_NUM * * DESCRIPTION *	Value used to indicate an invalid port number (14.2.5.10). * * SOURCE */
define|#
directive|define
name|IB_INVALID_PORT_NUM
value|0xFF
comment|/*********/
comment|/****d* IBA Base: Constants/IB_SUBNET_PATH_HOPS_MAX * NAME *	IB_SUBNET_PATH_HOPS_MAX * * DESCRIPTION *	Maximum number of directed route switch hops in a subnet (14.2.1.2). * * SOURCE */
define|#
directive|define
name|IB_SUBNET_PATH_HOPS_MAX
value|64
comment|/*********/
comment|/****d* IBA Base: Constants/IB_HOPLIMIT_MAX * NAME *	IB_HOPLIMIT_MAX * * DESCRIPTION *       Maximum number of router hops allowed. * * SOURCE */
define|#
directive|define
name|IB_HOPLIMIT_MAX
value|255
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MC_SCOPE_* * NAME *	IB_MC_SCOPE_* * * DESCRIPTION *	Scope component definitions from IBA 1.2.1 (Table 3 p. 148) */
define|#
directive|define
name|IB_MC_SCOPE_LINK_LOCAL
value|0x2
define|#
directive|define
name|IB_MC_SCOPE_SITE_LOCAL
value|0x5
define|#
directive|define
name|IB_MC_SCOPE_ORG_LOCAL
value|0x8
define|#
directive|define
name|IB_MC_SCOPE_GLOBAL
value|0xE
comment|/*********/
comment|/****d* IBA Base: Constants/IB_PKEY_MAX_BLOCKS * NAME *	IB_PKEY_MAX_BLOCKS * * DESCRIPTION *	Maximum number of PKEY blocks (14.2.5.7). * * SOURCE */
define|#
directive|define
name|IB_PKEY_MAX_BLOCKS
value|2048
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_MAX_BLOCK_ID * NAME *	IB_MCAST_MAX_BLOCK_ID * * DESCRIPTION *	Maximum number of Multicast port mask blocks * * SOURCE */
define|#
directive|define
name|IB_MCAST_MAX_BLOCK_ID
value|511
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_BLOCK_ID_MASK_HO * NAME *	IB_MCAST_BLOCK_ID_MASK_HO * * DESCRIPTION *	Mask (host order) to recover the Multicast block ID. * * SOURCE */
define|#
directive|define
name|IB_MCAST_BLOCK_ID_MASK_HO
value|0x000001FF
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_BLOCK_SIZE * NAME *	IB_MCAST_BLOCK_SIZE * * DESCRIPTION *	Number of port mask entries in a multicast forwarding table block. * * SOURCE */
define|#
directive|define
name|IB_MCAST_BLOCK_SIZE
value|32
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_MASK_SIZE * NAME *	IB_MCAST_MASK_SIZE * * DESCRIPTION *	Number of port mask bits in each entry in the multicast forwarding table. * * SOURCE */
define|#
directive|define
name|IB_MCAST_MASK_SIZE
value|16
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_POSITION_MASK_HO * NAME *	IB_MCAST_POSITION_MASK_HO * * DESCRIPTION *	Mask (host order) to recover the multicast block position. * * SOURCE */
define|#
directive|define
name|IB_MCAST_POSITION_MASK_HO
value|0xF0000000
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_POSITION_MAX * NAME *	IB_MCAST_POSITION_MAX * * DESCRIPTION *	Maximum value for the multicast block position. * * SOURCE */
define|#
directive|define
name|IB_MCAST_POSITION_MAX
value|0xF
comment|/*********/
comment|/****d* IBA Base: Constants/IB_MCAST_POSITION_SHIFT * NAME *	IB_MCAST_POSITION_SHIFT * * DESCRIPTION *	Shift value to normalize the multicast block position value. * * SOURCE */
define|#
directive|define
name|IB_MCAST_POSITION_SHIFT
value|28
comment|/*********/
comment|/****d* IBA Base: Constants/IB_PKEY_ENTRIES_MAX * NAME *	IB_PKEY_ENTRIES_MAX * * DESCRIPTION *	Maximum number of PKEY entries per port (14.2.5.7). * * SOURCE */
define|#
directive|define
name|IB_PKEY_ENTRIES_MAX
value|(IB_PKEY_MAX_BLOCKS * IB_NUM_PKEY_ELEMENTS_IN_BLOCK)
comment|/*********/
comment|/****d* IBA Base: Constants/IB_PKEY_BASE_MASK * NAME *	IB_PKEY_BASE_MASK * * DESCRIPTION *	Masks for the base P_Key value given a P_Key Entry. * * SOURCE */
define|#
directive|define
name|IB_PKEY_BASE_MASK
value|(CL_HTON16(0x7FFF))
comment|/*********/
comment|/****d* IBA Base: Constants/IB_PKEY_TYPE_MASK * NAME *	IB_PKEY_TYPE_MASK * * DESCRIPTION *	Masks for the P_Key membership type given a P_Key Entry. * * SOURCE */
define|#
directive|define
name|IB_PKEY_TYPE_MASK
value|(CL_HTON16(0x8000))
comment|/*********/
comment|/****d* IBA Base: Constants/IB_DEFAULT_PARTIAL_PKEY * NAME *	IB_DEFAULT_PARTIAL_PKEY * * DESCRIPTION *	0x7FFF in network order * * SOURCE */
define|#
directive|define
name|IB_DEFAULT_PARTIAL_PKEY
value|(CL_HTON16(0x7FFF))
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_SUBN_LID * NAME *	IB_MCLASS_SUBN_LID * * DESCRIPTION *	Subnet Management Class, Subnet Manager LID routed (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_SUBN_LID
value|0x01
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_SUBN_DIR * NAME *	IB_MCLASS_SUBN_DIR * * DESCRIPTION *	Subnet Management Class, Subnet Manager directed route (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_SUBN_DIR
value|0x81
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_SUBN_ADM * NAME *	IB_MCLASS_SUBN_ADM * * DESCRIPTION *	Management Class, Subnet Administration (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_SUBN_ADM
value|0x03
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_PERF * NAME *	IB_MCLASS_PERF * * DESCRIPTION *	Management Class, Performance Management (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_PERF
value|0x04
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_BM * NAME *	IB_MCLASS_BM * * DESCRIPTION *	Management Class, Baseboard Management (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_BM
value|0x05
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_DEV_MGMT * NAME *	IB_MCLASS_DEV_MGMT * * DESCRIPTION *	Management Class, Device Management (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_DEV_MGMT
value|0x06
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_COMM_MGMT * NAME *	IB_MCLASS_COMM_MGMT * * DESCRIPTION *	Management Class, Communication Management (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_COMM_MGMT
value|0x07
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_SNMP * NAME *	IB_MCLASS_SNMP * * DESCRIPTION *	Management Class, SNMP Tunneling (13.4.4) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_SNMP
value|0x08
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_VENDOR_LOW_RANGE_MIN * NAME *	IB_MCLASS_VENDOR_LOW_RANGE_MIN * * DESCRIPTION *	Management Class, Vendor Specific Low Range Start * * SOURCE */
define|#
directive|define
name|IB_MCLASS_VENDOR_LOW_RANGE_MIN
value|0x09
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_VENDOR_LOW_RANGE_MAX * NAME *	IB_MCLASS_VENDOR_LOW_RANGE_MAX * * DESCRIPTION *	Management Class, Vendor Specific Low Range End * * SOURCE */
define|#
directive|define
name|IB_MCLASS_VENDOR_LOW_RANGE_MAX
value|0x0F
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_DEV_ADM * NAME *	IB_MCLASS_DEV_ADM * * DESCRIPTION *	Management Class, Device Administration * * SOURCE */
define|#
directive|define
name|IB_MCLASS_DEV_ADM
value|0x10
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_BIS * NAME *	IB_MCLASS_BIS * * DESCRIPTION *	Management Class, BIS * * SOURCE */
define|#
directive|define
name|IB_MCLASS_BIS
value|0x12
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_CC * NAME *	IB_MCLASS_CC * * DESCRIPTION *	Management Class, Congestion Control (A10.4.1) * * SOURCE */
define|#
directive|define
name|IB_MCLASS_CC
value|0x21
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_VENDOR_HIGH_RANGE_MIN * NAME *	IB_MCLASS_VENDOR_HIGH_RANGE_MIN * * DESCRIPTION *	Management Class, Vendor Specific High Range Start * * SOURCE */
define|#
directive|define
name|IB_MCLASS_VENDOR_HIGH_RANGE_MIN
value|0x30
comment|/**********/
comment|/****d* IBA Base: Constants/IB_MCLASS_VENDOR_HIGH_RANGE_MAX * NAME *	IB_MCLASS_VENDOR_HIGH_RANGE_MAX * * DESCRIPTION *	Management Class, Vendor Specific High Range End * * SOURCE */
define|#
directive|define
name|IB_MCLASS_VENDOR_HIGH_RANGE_MAX
value|0x4F
comment|/**********/
comment|/****f* IBA Base: Types/ib_class_is_vendor_specific_low * NAME *	ib_class_is_vendor_specific_low * * DESCRIPTION *	Indicates if the Class Code if a vendor specific class from *  the low range * * SYNOPSIS */
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_class_is_vendor_specific_low
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|class_code
parameter_list|)
block|{
return|return
operator|(
operator|(
name|class_code
operator|>=
name|IB_MCLASS_VENDOR_LOW_RANGE_MIN
operator|)
operator|&&
operator|(
name|class_code
operator|<=
name|IB_MCLASS_VENDOR_LOW_RANGE_MAX
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	class_code *		[in] The Management Datagram Class Code * * RETURN VALUE *	TRUE if the class is in the Low range of Vendor Specific MADs *	FALSE otherwise. * * NOTES * * SEE ALSO * IB_MCLASS_VENDOR_LOW_RANGE_MIN, IB_MCLASS_VENDOR_LOW_RANGE_MAX *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_is_vendor_specific_high * NAME *	ib_class_is_vendor_specific_high * * DESCRIPTION *	Indicates if the Class Code if a vendor specific class from *  the high range * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_class_is_vendor_specific_high
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|class_code
parameter_list|)
block|{
return|return
operator|(
operator|(
name|class_code
operator|>=
name|IB_MCLASS_VENDOR_HIGH_RANGE_MIN
operator|)
operator|&&
operator|(
name|class_code
operator|<=
name|IB_MCLASS_VENDOR_HIGH_RANGE_MAX
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	class_code *		[in] The Management Datagram Class Code * * RETURN VALUE *	TRUE if the class is in the High range of Vendor Specific MADs *	FALSE otherwise. * * NOTES * * SEE ALSO * IB_MCLASS_VENDOR_HIGH_RANGE_MIN, IB_MCLASS_VENDOR_HIGH_RANGE_MAX *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_is_vendor_specific * NAME *	ib_class_is_vendor_specific * * DESCRIPTION *	Indicates if the Class Code if a vendor specific class * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_class_is_vendor_specific
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|class_code
parameter_list|)
block|{
return|return
operator|(
name|ib_class_is_vendor_specific_low
argument_list|(
name|class_code
argument_list|)
operator|||
name|ib_class_is_vendor_specific_high
argument_list|(
name|class_code
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	class_code *		[in] The Management Datagram Class Code * * RETURN VALUE *	TRUE if the class is a Vendor Specific MAD *	FALSE otherwise. * * NOTES * * SEE ALSO *  ib_class_is_vendor_specific_low, ib_class_is_vendor_specific_high *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_is_rmpp * NAME *	ib_class_is_rmpp * * DESCRIPTION *	Indicates if the Class Code supports RMPP * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_class_is_rmpp
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|class_code
parameter_list|)
block|{
return|return
operator|(
operator|(
name|class_code
operator|==
name|IB_MCLASS_SUBN_ADM
operator|)
operator|||
operator|(
name|class_code
operator|==
name|IB_MCLASS_DEV_MGMT
operator|)
operator|||
operator|(
name|class_code
operator|==
name|IB_MCLASS_DEV_ADM
operator|)
operator|||
operator|(
name|class_code
operator|==
name|IB_MCLASS_BIS
operator|)
operator|||
name|ib_class_is_vendor_specific_high
argument_list|(
name|class_code
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	class_code *		[in] The Management Datagram Class Code * * RETURN VALUE *	TRUE if the class supports RMPP *	FALSE otherwise. * * NOTES * *********/
end_comment

begin_comment
comment|/*  *	MAD methods  */
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAX_METHOD * NAME *	IB_MAX_METHOD * * DESCRIPTION *	Total number of methods available to a class, not including the R-bit. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAX_METHODS
value|128
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_RESP_MASK * NAME *	IB_MAD_METHOD_RESP_MASK * * DESCRIPTION *	Response mask to extract 'R' bit from the method field. (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_RESP_MASK
value|0x80
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_GET * NAME *	IB_MAD_METHOD_GET * * DESCRIPTION *	Get() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GET
value|0x01
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_SET * NAME *	IB_MAD_METHOD_SET * * DESCRIPTION *	Set() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_SET
value|0x02
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_GET_RESP * NAME *	IB_MAD_METHOD_GET_RESP * * DESCRIPTION *	GetResp() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GET_RESP
value|0x81
end_define

begin_comment
comment|/**********/
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_DELETE
value|0x15
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_GETTABLE * NAME *	IB_MAD_METHOD_GETTABLE * * DESCRIPTION *	SubnAdmGetTable() Method (15.2.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GETTABLE
value|0x12
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_GETTABLE_RESP * NAME *	IB_MAD_METHOD_GETTABLE_RESP * * DESCRIPTION *	SubnAdmGetTableResp() Method (15.2.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GETTABLE_RESP
value|0x92
end_define

begin_comment
comment|/**********/
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GETTRACETABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GETMULTI
value|0x14
end_define

begin_define
define|#
directive|define
name|IB_MAD_METHOD_GETMULTI_RESP
value|0x94
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_SEND * NAME *	IB_MAD_METHOD_SEND * * DESCRIPTION *	Send() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_SEND
value|0x03
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_TRAP * NAME *	IB_MAD_METHOD_TRAP * * DESCRIPTION *	Trap() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_TRAP
value|0x05
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_REPORT * NAME *	IB_MAD_METHOD_REPORT * * DESCRIPTION *	Report() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_REPORT
value|0x06
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_REPORT_RESP * NAME *	IB_MAD_METHOD_REPORT_RESP * * DESCRIPTION *	ReportResp() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_REPORT_RESP
value|0x86
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_METHOD_TRAP_REPRESS * NAME *	IB_MAD_METHOD_TRAP_REPRESS * * DESCRIPTION *	TrapRepress() Method (13.4.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_METHOD_TRAP_REPRESS
value|0x07
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_BUSY * NAME *	IB_MAD_STATUS_BUSY * * DESCRIPTION *	Temporarily busy, MAD discarded (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_BUSY
value|(CL_HTON16(0x0001))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_REDIRECT * NAME *	IB_MAD_STATUS_REDIRECT * * DESCRIPTION *	QP Redirection required (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_REDIRECT
value|(CL_HTON16(0x0002))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_UNSUP_CLASS_VER * NAME *	IB_MAD_STATUS_UNSUP_CLASS_VER * * DESCRIPTION *	Unsupported class version (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_UNSUP_CLASS_VER
value|(CL_HTON16(0x0004))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_UNSUP_METHOD * NAME *	IB_MAD_STATUS_UNSUP_METHOD * * DESCRIPTION *	Unsupported method (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_UNSUP_METHOD
value|(CL_HTON16(0x0008))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_UNSUP_METHOD_ATTR * NAME *	IB_MAD_STATUS_UNSUP_METHOD_ATTR * * DESCRIPTION *	Unsupported method/attribute combination (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_UNSUP_METHOD_ATTR
value|(CL_HTON16(0x000C))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_STATUS_INVALID_FIELD * NAME *	IB_MAD_STATUS_INVALID_FIELD * * DESCRIPTION *	Attribute contains one or more invalid fields (13.4.7) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_INVALID_FIELD
value|(CL_HTON16(0x001C))
end_define

begin_comment
comment|/**********/
end_comment

begin_define
define|#
directive|define
name|IB_MAD_STATUS_CLASS_MASK
value|(CL_HTON16(0xFF00))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_SUCCESS
value|(CL_HTON16(0x0000))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_NO_RESOURCES
value|(CL_HTON16(0x0100))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_REQ_INVALID
value|(CL_HTON16(0x0200))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_NO_RECORDS
value|(CL_HTON16(0x0300))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_TOO_MANY_RECORDS
value|(CL_HTON16(0x0400))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_INVALID_GID
value|(CL_HTON16(0x0500))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_INSUF_COMPS
value|(CL_HTON16(0x0600))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_DENIED
value|(CL_HTON16(0x0700))
end_define

begin_define
define|#
directive|define
name|IB_SA_MAD_STATUS_PRIO_SUGGESTED
value|(CL_HTON16(0x0800))
end_define

begin_define
define|#
directive|define
name|IB_DM_MAD_STATUS_NO_IOC_RESP
value|(CL_HTON16(0x0100))
end_define

begin_define
define|#
directive|define
name|IB_DM_MAD_STATUS_NO_SVC_ENTRIES
value|(CL_HTON16(0x0200))
end_define

begin_define
define|#
directive|define
name|IB_DM_MAD_STATUS_IOC_FAILURE
value|(CL_HTON16(0x8000))
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CLASS_PORT_INFO * NAME *	IB_MAD_ATTR_CLASS_PORT_INFO * * DESCRIPTION *	ClassPortInfo attribute (13.4.8) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CLASS_PORT_INFO
value|(CL_HTON16(0x0001))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_NOTICE * NAME *	IB_MAD_ATTR_NOTICE * * DESCRIPTION *	Notice attribute (13.4.8) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_NOTICE
value|(CL_HTON16(0x0002))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_INFORM_INFO * NAME *	IB_MAD_ATTR_INFORM_INFO * * DESCRIPTION *	InformInfo attribute (13.4.8) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_INFORM_INFO
value|(CL_HTON16(0x0003))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_NODE_DESC * NAME *	IB_MAD_ATTR_NODE_DESC * * DESCRIPTION *	NodeDescription attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_NODE_DESC
value|(CL_HTON16(0x0010))
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_SMPL_CTRL * NAME *	IB_MAD_ATTR_PORT_SMPL_CTRL * * DESCRIPTION *	PortSamplesControl attribute (16.1.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_SMPL_CTRL
value|(CL_HTON16(0x0010))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_NODE_INFO * NAME *	IB_MAD_ATTR_NODE_INFO * * DESCRIPTION *	NodeInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_NODE_INFO
value|(CL_HTON16(0x0011))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_SMPL_RSLT * NAME *	IB_MAD_ATTR_PORT_SMPL_RSLT * * DESCRIPTION *	PortSamplesResult attribute (16.1.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_SMPL_RSLT
value|(CL_HTON16(0x0011))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SWITCH_INFO * NAME *	IB_MAD_ATTR_SWITCH_INFO * * DESCRIPTION *	SwitchInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SWITCH_INFO
value|(CL_HTON16(0x0012))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_CNTRS * NAME *	IB_MAD_ATTR_PORT_CNTRS * * DESCRIPTION *	PortCounters attribute (16.1.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_CNTRS
value|(CL_HTON16(0x0012))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_CNTRS_EXT * NAME *       IB_MAD_ATTR_PORT_CNTRS_EXT * * DESCRIPTION *       PortCountersExtended attribute (16.1.4) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_CNTRS_EXT
value|(CL_HTON16(0x001D))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_XMIT_DATA_SL * NAME *	IB_MAD_ATTR_PORT_XMIT_DATA_SL * * DESCRIPTION *	PortXmitDataSL attribute (A13.6.4) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_XMIT_DATA_SL
value|(CL_HTON16(0x0036))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_RCV_DATA_SL * NAME *	IB_MAD_ATTR_PORT_RCV_DATA_SL * * DESCRIPTION *	PortRcvDataSL attribute (A13.6.4) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_RCV_DATA_SL
value|(CL_HTON16(0x0037))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_GUID_INFO * NAME *	IB_MAD_ATTR_GUID_INFO * * DESCRIPTION *	GUIDInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_GUID_INFO
value|(CL_HTON16(0x0014))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORT_INFO * NAME *	IB_MAD_ATTR_PORT_INFO * * DESCRIPTION *	PortInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORT_INFO
value|(CL_HTON16(0x0015))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_P_KEY_TABLE * NAME *	IB_MAD_ATTR_P_KEY_TABLE * * DESCRIPTION *	PartitionTable attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_P_KEY_TABLE
value|(CL_HTON16(0x0016))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SLVL_TABLE * NAME *	IB_MAD_ATTR_SLVL_TABLE * * DESCRIPTION *	SL VL Mapping Table attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SLVL_TABLE
value|(CL_HTON16(0x0017))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_VL_ARBITRATION * NAME *	IB_MAD_ATTR_VL_ARBITRATION * * DESCRIPTION *	VL Arbitration Table attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_VL_ARBITRATION
value|(CL_HTON16(0x0018))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_LIN_FWD_TBL * NAME *	IB_MAD_ATTR_LIN_FWD_TBL * * DESCRIPTION *	Switch linear forwarding table * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_LIN_FWD_TBL
value|(CL_HTON16(0x0019))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_RND_FWD_TBL * NAME *	IB_MAD_ATTR_RND_FWD_TBL * * DESCRIPTION *	Switch random forwarding table * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_RND_FWD_TBL
value|(CL_HTON16(0x001A))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_MCAST_FWD_TBL * NAME *	IB_MAD_ATTR_MCAST_FWD_TBL * * DESCRIPTION *	Switch multicast forwarding table * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_MCAST_FWD_TBL
value|(CL_HTON16(0x001B))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_NODE_RECORD * NAME *	IB_MAD_ATTR_NODE_RECORD * * DESCRIPTION *	NodeRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_NODE_RECORD
value|(CL_HTON16(0x0011))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PORTINFO_RECORD * NAME *	IB_MAD_ATTR_PORTINFO_RECORD * * DESCRIPTION *	PortInfoRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PORTINFO_RECORD
value|(CL_HTON16(0x0012))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SWITCH_INFO_RECORD * NAME *       IB_MAD_ATTR_SWITCH_INFO_RECORD * * DESCRIPTION *       SwitchInfoRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SWITCH_INFO_RECORD
value|(CL_HTON16(0x0014))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_LINK_RECORD * NAME *	IB_MAD_ATTR_LINK_RECORD * * DESCRIPTION *	LinkRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_LINK_RECORD
value|(CL_HTON16(0x0020))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SM_INFO * NAME *	IB_MAD_ATTR_SM_INFO * * DESCRIPTION *	SMInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SM_INFO
value|(CL_HTON16(0x0020))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SMINFO_RECORD * NAME *	IB_MAD_ATTR_SMINFO_RECORD * * DESCRIPTION *	SMInfoRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SMINFO_RECORD
value|(CL_HTON16(0x0018))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_GUIDINFO_RECORD * NAME *       IB_MAD_ATTR_GUIDINFO_RECORD * * DESCRIPTION *       GuidInfoRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_GUIDINFO_RECORD
value|(CL_HTON16(0x0030))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_VENDOR_DIAG * NAME *	IB_MAD_ATTR_VENDOR_DIAG * * DESCRIPTION *	VendorDiag attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_VENDOR_DIAG
value|(CL_HTON16(0x0030))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_LED_INFO * NAME *	IB_MAD_ATTR_LED_INFO * * DESCRIPTION *	LedInfo attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_LED_INFO
value|(CL_HTON16(0x0031))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_MLNX_EXTENDED_PORT_INFO * NAME *	IB_MAD_ATTR_MLNX_EXTENDED_PORT_INFO * * DESCRIPTION *	Vendor specific SM attribute (14.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_MLNX_EXTENDED_PORT_INFO
value|(CL_HTON16(0xFF90))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SERVICE_RECORD * NAME *	IB_MAD_ATTR_SERVICE_RECORD * * DESCRIPTION *	ServiceRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SERVICE_RECORD
value|(CL_HTON16(0x0031))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_LFT_RECORD * NAME *	IB_MAD_ATTR_LFT_RECORD * * DESCRIPTION *	LinearForwardingTableRecord attribute (15.2.5.6) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_LFT_RECORD
value|(CL_HTON16(0x0015))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_MFT_RECORD * NAME *       IB_MAD_ATTR_MFT_RECORD * * DESCRIPTION *       MulticastForwardingTableRecord attribute (15.2.5.8) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_MFT_RECORD
value|(CL_HTON16(0x0017))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PKEYTBL_RECORD * NAME *	IB_MAD_ATTR_PKEYTBL_RECORD * * DESCRIPTION *	PKEY Table Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PKEY_TBL_RECORD
value|(CL_HTON16(0x0033))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PATH_RECORD * NAME *	IB_MAD_ATTR_PATH_RECORD * * DESCRIPTION *	PathRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PATH_RECORD
value|(CL_HTON16(0x0035))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_VLARB_RECORD * NAME *	IB_MAD_ATTR_VLARB_RECORD * * DESCRIPTION *	VL Arbitration Table Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_VLARB_RECORD
value|(CL_HTON16(0x0036))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SLVL_RECORD * NAME *	IB_MAD_ATTR_SLVL_RECORD * * DESCRIPTION *	SLtoVL Mapping Table Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SLVL_RECORD
value|(CL_HTON16(0x0013))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_MCMEMBER_RECORD * NAME *	IB_MAD_ATTR_MCMEMBER_RECORD * * DESCRIPTION *	MCMemberRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_MCMEMBER_RECORD
value|(CL_HTON16(0x0038))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_TRACE_RECORD * NAME *	IB_MAD_ATTR_TRACE_RECORD * * DESCRIPTION *	TraceRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_TRACE_RECORD
value|(CL_HTON16(0x0039))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_MULTIPATH_RECORD * NAME *	IB_MAD_ATTR_MULTIPATH_RECORD * * DESCRIPTION *	MultiPathRecord attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_MULTIPATH_RECORD
value|(CL_HTON16(0x003A))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SVC_ASSOCIATION_RECORD * NAME *	IB_MAD_ATTR_SVC_ASSOCIATION_RECORD * * DESCRIPTION *	Service Association Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SVC_ASSOCIATION_RECORD
value|(CL_HTON16(0x003B))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_INFORM_INFO_RECORD * NAME *	IB_MAD_ATTR_INFORM_INFO_RECORD * * DESCRIPTION *	InformInfo Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_INFORM_INFO_RECORD
value|(CL_HTON16(0x00F3))
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_IO_UNIT_INFO * NAME *	IB_MAD_ATTR_IO_UNIT_INFO * * DESCRIPTION *	IOUnitInfo attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_IO_UNIT_INFO
value|(CL_HTON16(0x0010))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_IO_CONTROLLER_PROFILE * NAME *	IB_MAD_ATTR_IO_CONTROLLER_PROFILE * * DESCRIPTION *	IOControllerProfile attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_IO_CONTROLLER_PROFILE
value|(CL_HTON16(0x0011))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SERVICE_ENTRIES * NAME *	IB_MAD_ATTR_SERVICE_ENTRIES * * DESCRIPTION *	ServiceEntries attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SERVICE_ENTRIES
value|(CL_HTON16(0x0012))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_DIAGNOSTIC_TIMEOUT * NAME *	IB_MAD_ATTR_DIAGNOSTIC_TIMEOUT * * DESCRIPTION *	DiagnosticTimeout attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_DIAGNOSTIC_TIMEOUT
value|(CL_HTON16(0x0020))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_PREPARE_TO_TEST * NAME *	IB_MAD_ATTR_PREPARE_TO_TEST * * DESCRIPTION *	PrepareToTest attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_PREPARE_TO_TEST
value|(CL_HTON16(0x0021))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_TEST_DEVICE_ONCE * NAME *	IB_MAD_ATTR_TEST_DEVICE_ONCE * * DESCRIPTION *	TestDeviceOnce attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_TEST_DEVICE_ONCE
value|(CL_HTON16(0x0022))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_TEST_DEVICE_LOOP * NAME *	IB_MAD_ATTR_TEST_DEVICE_LOOP * * DESCRIPTION *	TestDeviceLoop attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_TEST_DEVICE_LOOP
value|(CL_HTON16(0x0023))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_DIAG_CODE * NAME *	IB_MAD_ATTR_DIAG_CODE * * DESCRIPTION *	DiagCode attribute (16.3.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_DIAG_CODE
value|(CL_HTON16(0x0024))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SVC_ASSOCIATION_RECORD * NAME *	IB_MAD_ATTR_SVC_ASSOCIATION_RECORD * * DESCRIPTION *	Service Association Record attribute (15.2.5) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SVC_ASSOCIATION_RECORD
value|(CL_HTON16(0x003B))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CONG_INFO * NAME *	IB_MAD_ATTR_CONG_INFO * * DESCRIPTION *	CongestionInfo attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CONG_INFO
value|(CL_HTON16(0x0011))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CONG_KEY_INFO * NAME *	IB_MAD_ATTR_CONG_KEY_INFO * * DESCRIPTION *	CongestionKeyInfo attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CONG_KEY_INFO
value|(CL_HTON16(0x0012))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CONG_LOG * NAME *	IB_MAD_ATTR_CONG_LOG * * DESCRIPTION *	CongestionLog attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CONG_LOG
value|(CL_HTON16(0x0013))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SW_CONG_SETTING * NAME *	IB_MAD_ATTR_SW_CONG_SETTING * * DESCRIPTION *	SwitchCongestionSetting attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SW_CONG_SETTING
value|(CL_HTON16(0x0014))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_SW_PORT_CONG_SETTING * NAME *	IB_MAD_ATTR_SW_PORT_CONG_SETTING * * DESCRIPTION *	SwitchPortCongestionSetting attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_SW_PORT_CONG_SETTING
value|(CL_HTON16(0x0015))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CA_CONG_SETTING * NAME *	IB_MAD_ATTR_CA_CONG_SETTING * * DESCRIPTION *	CACongestionSetting attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CA_CONG_SETTING
value|(CL_HTON16(0x0016))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_CC_TBL * NAME *	IB_MAD_ATTR_CC_TBL * * DESCRIPTION *	CongestionControlTable attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_CC_TBL
value|(CL_HTON16(0x0017))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MAD_ATTR_TIME_STAMP * NAME *	IB_MAD_ATTR_TIME_STAMP * * DESCRIPTION *	TimeStamp attribute (A10.4.3) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MAD_ATTR_TIME_STAMP
value|(CL_HTON16(0x0018))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NODE_TYPE_CA * NAME *	IB_NODE_TYPE_CA * * DESCRIPTION *	Encoded generic node type used in MAD attributes (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NODE_TYPE_CA
value|0x01
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NODE_TYPE_SWITCH * NAME *	IB_NODE_TYPE_SWITCH * * DESCRIPTION *	Encoded generic node type used in MAD attributes (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NODE_TYPE_SWITCH
value|0x02
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NODE_TYPE_ROUTER * NAME *	IB_NODE_TYPE_ROUTER * * DESCRIPTION *	Encoded generic node type used in MAD attributes (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NODE_TYPE_ROUTER
value|0x03
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NOTICE_PRODUCER_TYPE_CA * NAME *	IB_NOTICE_PRODUCER_TYPE_CA * * DESCRIPTION *	Encoded generic producer type used in Notice attribute (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_PRODUCER_TYPE_CA
value|(CL_HTON32(0x000001))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NOTICE_PRODUCER_TYPE_SWITCH * NAME *	IB_NOTICE_PRODUCER_TYPE_SWITCH * * DESCRIPTION *	Encoded generic producer type used in Notice attribute (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_PRODUCER_TYPE_SWITCH
value|(CL_HTON32(0x000002))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NOTICE_PRODUCER_TYPE_ROUTER * NAME *	IB_NOTICE_PRODUCER_TYPE_ROUTER * * DESCRIPTION *	Encoded generic producer type used in Notice attribute (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_PRODUCER_TYPE_ROUTER
value|(CL_HTON32(0x000003))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_NOTICE_PRODUCER_TYPE_CLASS_MGR * NAME *	IB_NOTICE_PRODUCER_TYPE_CLASS_MGR * * DESCRIPTION *	Encoded generic producer type used in Notice attribute (13.4.8.2) * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_PRODUCER_TYPE_CLASS_MGR
value|(CL_HTON32(0x000004))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MTU_LEN_TYPE * NAME *	IB_MTU_LEN_TYPE * * DESCRIPTION *	Encoded path MTU. *		1: 256 *		2: 512 *		3: 1024 *		4: 2048 *		5: 4096 *		others: reserved * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MTU_LEN_256
value|1
end_define

begin_define
define|#
directive|define
name|IB_MTU_LEN_512
value|2
end_define

begin_define
define|#
directive|define
name|IB_MTU_LEN_1024
value|3
end_define

begin_define
define|#
directive|define
name|IB_MTU_LEN_2048
value|4
end_define

begin_define
define|#
directive|define
name|IB_MTU_LEN_4096
value|5
end_define

begin_define
define|#
directive|define
name|IB_MIN_MTU
value|IB_MTU_LEN_256
end_define

begin_define
define|#
directive|define
name|IB_MAX_MTU
value|IB_MTU_LEN_4096
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_PATH_SELECTOR_TYPE * NAME *	IB_PATH_SELECTOR_TYPE * * DESCRIPTION *	Path selector. *		0: greater than specified *		1: less than specified *		2: exactly the specified *		3: largest available * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_SELECTOR_GREATER_THAN
value|0
end_define

begin_define
define|#
directive|define
name|IB_PATH_SELECTOR_LESS_THAN
value|1
end_define

begin_define
define|#
directive|define
name|IB_PATH_SELECTOR_EXACTLY
value|2
end_define

begin_define
define|#
directive|define
name|IB_PATH_SELECTOR_LARGEST
value|3
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_STATE_NOTACTIVE * NAME *	IB_SMINFO_STATE_NOTACTIVE * * DESCRIPTION *	Encoded state value used in the SMInfo attribute. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_STATE_NOTACTIVE
value|0
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_STATE_DISCOVERING * NAME *	IB_SMINFO_STATE_DISCOVERING * * DESCRIPTION *	Encoded state value used in the SMInfo attribute. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_STATE_DISCOVERING
value|1
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_STATE_STANDBY * NAME *	IB_SMINFO_STATE_STANDBY * * DESCRIPTION *	Encoded state value used in the SMInfo attribute. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_STATE_STANDBY
value|2
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_STATE_MASTER * NAME *	IB_SMINFO_STATE_MASTER * * DESCRIPTION *	Encoded state value used in the SMInfo attribute. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_STATE_MASTER
value|3
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_PATH_REC_SL_MASK * NAME *	IB_PATH_REC_SL_MASK * * DESCRIPTION *	Mask for the sl field for path record * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_REC_SL_MASK
value|0x000F
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MULTIPATH_REC_SL_MASK * NAME *	IB_MULTIPATH_REC_SL_MASK * * DESCRIPTION *	Mask for the sl field for MultiPath record * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MULTIPATH_REC_SL_MASK
value|0x000F
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_PATH_REC_QOS_CLASS_MASK * NAME *	IB_PATH_REC_QOS_CLASS_MASK * * DESCRIPTION *	Mask for the QoS class field for path record * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_REC_QOS_CLASS_MASK
value|0xFFF0
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MULTIPATH_REC_QOS_CLASS_MASK * NAME *	IB_MULTIPATH_REC_QOS_CLASS_MASK * * DESCRIPTION *	Mask for the QoS class field for MultiPath record * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MULTIPATH_REC_QOS_CLASS_MASK
value|0xFFF0
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_PATH_REC_SELECTOR_MASK * NAME *	IB_PATH_REC_SELECTOR_MASK * * DESCRIPTION *	Mask for the selector field for path record MTU, rate, *	and packet lifetime. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_REC_SELECTOR_MASK
value|0xC0
end_define

begin_comment
comment|/****d* IBA Base: Constants/IB_MULTIPATH_REC_SELECTOR_MASK * NAME *       IB_MULTIPATH_REC_SELECTOR_MASK * * DESCRIPTION *       Mask for the selector field for multipath record MTU, rate, *       and packet lifetime. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MULTIPATH_REC_SELECTOR_MASK
value|0xC0
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_PATH_REC_BASE_MASK * NAME *	IB_PATH_REC_BASE_MASK * * DESCRIPTION *	Mask for the base value field for path record MTU, rate, *	and packet lifetime. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_REC_BASE_MASK
value|0x3F
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_MULTIPATH_REC_BASE_MASK * NAME *       IB_MULTIPATH_REC_BASE_MASK * * DESCRIPTION *       Mask for the base value field for multipath record MTU, rate, *       and packet lifetime. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_MULTIPATH_REC_BASE_MASK
value|0x3F
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****h* IBA Base/Type Definitions * NAME *	Type Definitions * * DESCRIPTION *	Definitions are from the InfiniBand Architecture Specification v1.2 * *********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_net16_t * NAME *	ib_net16_t * * DESCRIPTION *	Defines the network ordered type for 16-bit values. * * SOURCE */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|ib_net16_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_net32_t * NAME *	ib_net32_t * * DESCRIPTION *	Defines the network ordered type for 32-bit values. * * SOURCE */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_net32_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_net64_t * NAME *	ib_net64_t * * DESCRIPTION *	Defines the network ordered type for 64-bit values. * * SOURCE */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|ib_net64_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_gid_prefix_t * NAME *	ib_gid_prefix_t * * DESCRIPTION * * SOURCE */
end_comment

begin_typedef
typedef|typedef
name|ib_net64_t
name|ib_gid_prefix_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/ib_link_states_t * NAME *	ib_link_states_t * * DESCRIPTION *	Defines the link states of a port. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_LINK_NO_CHANGE
value|0
end_define

begin_define
define|#
directive|define
name|IB_LINK_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|IB_LINK_INIT
value|2
end_define

begin_define
define|#
directive|define
name|IB_LINK_ARMED
value|3
end_define

begin_define
define|#
directive|define
name|IB_LINK_ACTIVE
value|4
end_define

begin_define
define|#
directive|define
name|IB_LINK_ACT_DEFER
value|5
end_define

begin_comment
comment|/**********/
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|__ib_node_type_str
index|[]
init|=
block|{
literal|"UNKNOWN"
block|,
literal|"Channel Adapter"
block|,
literal|"Switch"
block|,
literal|"Router"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_node_type_str * NAME *	ib_get_node_type_str * * DESCRIPTION *	Returns a string for the specified node type. *	14.2.5.3 NodeInfo * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_node_type_str
parameter_list|(
name|IN
name|uint8_t
name|node_type
parameter_list|)
block|{
if|if
condition|(
name|node_type
operator|>
name|IB_NODE_TYPE_ROUTER
condition|)
name|node_type
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|__ib_node_type_str
index|[
name|node_type
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	node_type *		[in] Encoded node type as returned in the NodeInfo attribute.  * RETURN VALUES *	Pointer to the node type string. * * NOTES * * SEE ALSO * ib_node_info_t *********/
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|__ib_producer_type_str
index|[]
init|=
block|{
literal|"UNKNOWN"
block|,
literal|"Channel Adapter"
block|,
literal|"Switch"
block|,
literal|"Router"
block|,
literal|"Class Manager"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_producer_type_str * NAME *	ib_get_producer_type_str * * DESCRIPTION *	Returns a string for the specified producer type *	13.4.8.2 Notice *	13.4.8.3 InformInfo * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_producer_type_str
parameter_list|(
name|IN
name|ib_net32_t
name|producer_type
parameter_list|)
block|{
if|if
condition|(
name|cl_ntoh32
argument_list|(
name|producer_type
argument_list|)
operator|>
name|CL_NTOH32
argument_list|(
name|IB_NOTICE_PRODUCER_TYPE_CLASS_MGR
argument_list|)
condition|)
name|producer_type
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|__ib_producer_type_str
index|[
name|cl_ntoh32
argument_list|(
name|producer_type
argument_list|)
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	producer_type *		[in] Encoded producer type from the Notice attribute  * RETURN VALUES *	Pointer to the producer type string. * * NOTES * * SEE ALSO * ib_notice_get_prod_type *********/
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|__ib_port_state_str
index|[]
init|=
block|{
literal|"No State Change (NOP)"
block|,
literal|"DOWN"
block|,
literal|"INIT"
block|,
literal|"ARMED"
block|,
literal|"ACTIVE"
block|,
literal|"ACTDEFER"
block|,
literal|"UNKNOWN"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_port_state_str * NAME *	ib_get_port_state_str * * DESCRIPTION *	Returns a string for the specified port state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_port_state_str
parameter_list|(
name|IN
name|uint8_t
name|port_state
parameter_list|)
block|{
if|if
condition|(
name|port_state
operator|>
name|IB_LINK_ACTIVE
condition|)
name|port_state
operator|=
name|IB_LINK_ACTIVE
operator|+
literal|1
expr_stmt|;
return|return
operator|(
name|__ib_port_state_str
index|[
name|port_state
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	port_state *		[in] Encoded port state as returned in the PortInfo attribute.  * RETURN VALUES *	Pointer to the port state string. * * NOTES * * SEE ALSO * ib_port_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_get_port_state_from_str * NAME *	ib_get_port_state_from_str * * DESCRIPTION *	Returns a string for the specified port state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_get_port_state_from_str
parameter_list|(
name|IN
name|char
modifier|*
name|p_port_state_str
parameter_list|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"No State Change (NOP)"
argument_list|,
literal|12
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"DOWN"
argument_list|,
literal|4
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"INIT"
argument_list|,
literal|4
argument_list|)
condition|)
return|return
operator|(
literal|2
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"ARMED"
argument_list|,
literal|5
argument_list|)
condition|)
return|return
operator|(
literal|3
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"ACTIVE"
argument_list|,
literal|6
argument_list|)
condition|)
return|return
operator|(
literal|4
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|p_port_state_str
argument_list|,
literal|"ACTDEFER"
argument_list|,
literal|8
argument_list|)
condition|)
return|return
operator|(
literal|5
operator|)
return|;
return|return
operator|(
literal|6
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_port_state_str *		[in] A string matching one returned by ib_get_port_state_str * * RETURN VALUES *	The appropriate code. * * NOTES * * SEE ALSO *	ib_port_info_t *********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/Join States * NAME *	Join States * * DESCRIPTION *	Defines the join state flags for multicast group management. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_JOIN_STATE_FULL
value|1
end_define

begin_define
define|#
directive|define
name|IB_JOIN_STATE_NON
value|2
end_define

begin_define
define|#
directive|define
name|IB_JOIN_STATE_SEND_ONLY
value|4
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_pkey_get_base * NAME *	ib_pkey_get_base * * DESCRIPTION *	Returns the base P_Key value with the membership bit stripped. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|OSM_API
name|ib_pkey_get_base
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|pkey
parameter_list|)
block|{
return|return
operator|(
call|(
name|ib_net16_t
call|)
argument_list|(
name|pkey
operator|&
name|IB_PKEY_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	pkey *		[in] P_Key value * * RETURN VALUE *	Returns the base P_Key value with the membership bit stripped. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_pkey_is_full_member * NAME *	ib_pkey_is_full_member * * DESCRIPTION *	Indicates if the port is a full member of the partition. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_pkey_is_full_member
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|pkey
parameter_list|)
block|{
return|return
operator|(
operator|(
name|pkey
operator|&
name|IB_PKEY_TYPE_MASK
operator|)
operator|==
name|IB_PKEY_TYPE_MASK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	pkey *		[in] P_Key value * * RETURN VALUE *	TRUE if the port is a full member of the partition. *	FALSE otherwise. * * NOTES * * SEE ALSO * ib_pkey_get_base, ib_net16_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_pkey_is_invalid * NAME *	ib_pkey_is_invalid * * DESCRIPTION *	Returns TRUE if the given P_Key is an invalid P_Key *  C10-116: the CI shall regard a P_Key as invalid if its low-order *           15 bits are all zero... * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_pkey_is_invalid
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|pkey
parameter_list|)
block|{
return|return
name|ib_pkey_get_base
argument_list|(
name|pkey
argument_list|)
operator|==
literal|0x0000
condition|?
name|TRUE
else|:
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	pkey *		[in] P_Key value * * RETURN VALUE *	Returns the base P_Key value with the membership bit stripped. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_gid_t * NAME *	ib_gid_t * * DESCRIPTION * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
union|union
name|_ib_gid
block|{
name|uint8_t
name|raw
index|[
literal|16
index|]
decl_stmt|;
struct|struct
name|_ib_gid_unicast
block|{
name|ib_gid_prefix_t
name|prefix
decl_stmt|;
name|ib_net64_t
name|interface_id
decl_stmt|;
block|}
name|PACK_SUFFIX
name|unicast
struct|;
struct|struct
name|_ib_gid_multicast
block|{
name|uint8_t
name|header
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|raw_group_id
index|[
literal|14
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|multicast
struct|;
block|}
name|PACK_SUFFIX
name|ib_gid_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	raw *		GID represented as an unformated byte array. * *	unicast *		Typical unicast representation with subnet prefix and *		port GUID. * *	multicast *		Representation for multicast use. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_gid_is_multicast * NAME *	ib_gid_is_multicast * * DESCRIPTION *       Returns a boolean indicating whether a GID is a multicast GID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_gid_is_multicast
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_gid
parameter_list|)
block|{
return|return
operator|(
name|p_gid
operator|->
name|raw
index|[
literal|0
index|]
operator|==
literal|0xFF
operator|)
return|;
block|}
end_function

begin_comment
comment|/****f* IBA Base: Types/ib_gid_get_scope * NAME *	ib_gid_get_scope * * DESCRIPTION *	Returns scope of (assumed) multicast GID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_mgid_get_scope
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_gid
parameter_list|)
block|{
return|return
operator|(
name|p_gid
operator|->
name|raw
index|[
literal|1
index|]
operator|&
literal|0x0F
operator|)
return|;
block|}
end_function

begin_comment
comment|/****f* IBA Base: Types/ib_gid_set_scope * NAME *	ib_gid_set_scope * * DESCRIPTION *	Sets scope of (assumed) multicast GID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_mgid_set_scope
parameter_list|(
name|IN
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|scope
parameter_list|)
block|{
name|p_gid
operator|->
name|raw
index|[
literal|1
index|]
operator|&=
literal|0xF0
expr_stmt|;
name|p_gid
operator|->
name|raw
index|[
literal|1
index|]
operator||=
name|scope
operator|&
literal|0x0F
expr_stmt|;
block|}
end_function

begin_comment
comment|/****f* IBA Base: Types/ib_gid_set_default * NAME *	ib_gid_set_default * * DESCRIPTION *	Sets a GID to the default value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_gid_set_default
parameter_list|(
name|IN
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|interface_id
parameter_list|)
block|{
name|p_gid
operator|->
name|unicast
operator|.
name|prefix
operator|=
name|IB_DEFAULT_SUBNET_PREFIX
expr_stmt|;
name|p_gid
operator|->
name|unicast
operator|.
name|interface_id
operator|=
name|interface_id
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_gid *		[in] Pointer to the GID object. * *	interface_id *		[in] Manufacturer assigned EUI64 value of a port. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_gid_get_subnet_prefix * NAME *	ib_gid_get_subnet_prefix * * DESCRIPTION *	Gets the subnet prefix from a GID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|OSM_API
name|ib_gid_get_subnet_prefix
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|)
block|{
return|return
operator|(
name|p_gid
operator|->
name|unicast
operator|.
name|prefix
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_gid *		[in] Pointer to the GID object. * * RETURN VALUES *	64-bit subnet prefix value. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_gid_is_link_local * NAME *	ib_gid_is_link_local * * DESCRIPTION *	Returns TRUE if the unicast GID scoping indicates link local, *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_gid_is_link_local
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_gid_get_subnet_prefix
argument_list|(
name|p_gid
argument_list|)
operator|&
name|CL_HTON64
argument_list|(
literal|0xFFC0000000000000ULL
argument_list|)
operator|)
operator|==
name|IB_DEFAULT_SUBNET_PREFIX
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_gid *		[in] Pointer to the GID object. * * RETURN VALUES *	Returns TRUE if the unicast GID scoping indicates link local, *	FALSE otherwise. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_gid_is_site_local * NAME *	ib_gid_is_site_local * * DESCRIPTION *	Returns TRUE if the unicast GID scoping indicates site local, *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_gid_is_site_local
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_gid_get_subnet_prefix
argument_list|(
name|p_gid
argument_list|)
operator|&
name|CL_HTON64
argument_list|(
literal|0xFFFFFFFFFFFF0000ULL
argument_list|)
operator|)
operator|==
name|CL_HTON64
argument_list|(
literal|0xFEC0000000000000ULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_gid *		[in] Pointer to the GID object. * * RETURN VALUES *	Returns TRUE if the unicast GID scoping indicates site local, *	FALSE otherwise. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_gid_get_guid * NAME *	ib_gid_get_guid * * DESCRIPTION *	Gets the guid from a GID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|OSM_API
name|ib_gid_get_guid
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_gid
parameter_list|)
block|{
return|return
operator|(
name|p_gid
operator|->
name|unicast
operator|.
name|interface_id
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_gid *		[in] Pointer to the GID object. * * RETURN VALUES *	64-bit GUID value. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_path_rec_t * NAME *	ib_path_rec_t * * DESCRIPTION *	Path records encapsulate the properties of a given *	route between two end-points on a subnet. * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_path_rec
block|{
name|ib_net64_t
name|service_id
decl_stmt|;
name|ib_gid_t
name|dgid
decl_stmt|;
name|ib_gid_t
name|sgid
decl_stmt|;
name|ib_net16_t
name|dlid
decl_stmt|;
name|ib_net16_t
name|slid
decl_stmt|;
name|ib_net32_t
name|hop_flow_raw
decl_stmt|;
name|uint8_t
name|tclass
decl_stmt|;
name|uint8_t
name|num_path
decl_stmt|;
name|ib_net16_t
name|pkey
decl_stmt|;
name|ib_net16_t
name|qos_class_sl
decl_stmt|;
name|uint8_t
name|mtu
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|pkt_life
decl_stmt|;
name|uint8_t
name|preference
decl_stmt|;
name|uint8_t
name|resv2
index|[
literal|6
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_path_rec_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	service_id *		Service ID for QoS. * *	dgid *		GID of destination port. * *	sgid *		GID of source port. * *	dlid *		LID of destination port. * *	slid *		LID of source port. * *	hop_flow_raw *		Global routing parameters: hop count, flow label and raw bit. * *	tclass *		Another global routing parameter. * *	num_path *		Reversible path - 1 bit to say if path is reversible. *		num_path [6:0] In queries, maximum number of paths to return. *		In responses, undefined. * *	pkey *		Partition key (P_Key) to use on this path. * *	qos_class_sl *		QoS class and service level to use on this path. * *	mtu *		MTU and MTU selector fields to use on this path * *	rate *		Rate and rate selector fields to use on this path. * *	pkt_life *		Packet lifetime * *	preference *		Indicates the relative merit of this path versus other path *		records returned from the SA.  Lower numbers are better. * *	resv2 *		Reserved bytes. * SEE ALSO *********/
end_comment

begin_comment
comment|/* Path Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SERVICEID_MSB
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SERVICEID_LSB
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_DGID
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SGID
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_DLID
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SLID
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_RAWTRAFFIC
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_RESV0
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_FLOWLABEL
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_HOPLIMIT
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_TCLASS
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_REVERSIBLE
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_NUMBPATH
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_PKEY
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_QOS_CLASS
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SL
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_MTUSELEC
value|(CL_HTON64(((uint64_t)1)<<16))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_MTU
value|(CL_HTON64(((uint64_t)1)<<17))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_RATESELEC
value|(CL_HTON64(((uint64_t)1)<<18))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_RATE
value|(CL_HTON64(((uint64_t)1)<<19))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_PKTLIFETIMESELEC
value|(CL_HTON64(((uint64_t)1)<<20))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_PKTLIFETIME
value|(CL_HTON64(((uint64_t)1)<<21))
end_define

begin_define
define|#
directive|define
name|IB_PR_COMPMASK_SERVICEID
value|(IB_PR_COMPMASK_SERVICEID_MSB | \ 				   IB_PR_COMPMASK_SERVICEID_LSB)
end_define

begin_comment
comment|/* Link Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_LR_COMPMASK_FROM_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_LR_COMPMASK_FROM_PORT
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_LR_COMPMASK_TO_PORT
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_LR_COMPMASK_TO_LID
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_comment
comment|/* VL Arbitration Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_VLA_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_VLA_COMPMASK_OUT_PORT
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_VLA_COMPMASK_BLOCK
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_comment
comment|/* SLtoVL Mapping Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_SLVL_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_SLVL_COMPMASK_IN_PORT
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_SLVL_COMPMASK_OUT_PORT
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_comment
comment|/* P_Key Table Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_PKEY_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_PKEY_COMPMASK_BLOCK
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_PKEY_COMPMASK_PORT
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_comment
comment|/* Switch Info Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_SWIR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_SWIR_COMPMASK_RESERVED1
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_comment
comment|/* LFT Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_LFTR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_LFTR_COMPMASK_BLOCK
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_comment
comment|/* MFT Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_MFTR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_MFTR_COMPMASK_POSITION
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_MFTR_COMPMASK_RESERVED1
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_MFTR_COMPMASK_BLOCK
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_MFTR_COMPMASK_RESERVED2
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_comment
comment|/* NodeInfo Record Masks */
end_comment

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_RESERVED1
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_BASEVERSION
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_CLASSVERSION
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_NODETYPE
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_NUMPORTS
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_SYSIMAGEGUID
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_NODEGUID
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_PORTGUID
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_PARTCAP
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_DEVID
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_REV
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_PORTNUM
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_VENDID
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_NR_COMPMASK_NODEDESC
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_comment
comment|/* Service Record Component Masks Sec 15.2.5.14 Ver 1.1*/
end_comment

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SGID
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SPKEY
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_RES1
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SLEASE
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SKEY
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SNAME
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_0
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_1
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_2
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_3
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_4
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_5
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_6
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_7
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_8
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_9
value|(CL_HTON64(((uint64_t)1)<<16))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_10
value|(CL_HTON64(((uint64_t)1)<<17))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_11
value|(CL_HTON64(((uint64_t)1)<<18))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_12
value|(CL_HTON64(((uint64_t)1)<<19))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_13
value|(CL_HTON64(((uint64_t)1)<<20))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_14
value|(CL_HTON64(((uint64_t)1)<<21))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA8_15
value|(CL_HTON64(((uint64_t)1)<<22))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_0
value|(CL_HTON64(((uint64_t)1)<<23))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_1
value|(CL_HTON64(((uint64_t)1)<<24))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_2
value|(CL_HTON64(((uint64_t)1)<<25))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_3
value|(CL_HTON64(((uint64_t)1)<<26))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_4
value|(CL_HTON64(((uint64_t)1)<<27))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_5
value|(CL_HTON64(((uint64_t)1)<<28))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_6
value|(CL_HTON64(((uint64_t)1)<<29))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA16_7
value|(CL_HTON64(((uint64_t)1)<<30))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA32_0
value|(CL_HTON64(((uint64_t)1)<<31))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA32_1
value|(CL_HTON64(((uint64_t)1)<<32))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA32_2
value|(CL_HTON64(((uint64_t)1)<<33))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA32_3
value|(CL_HTON64(((uint64_t)1)<<34))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA64_0
value|(CL_HTON64(((uint64_t)1)<<35))
end_define

begin_define
define|#
directive|define
name|IB_SR_COMPMASK_SDATA64_1
value|(CL_HTON64(((uint64_t)1)<<36))
end_define

begin_comment
comment|/* Port Info Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PORTNUM
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_OPTIONS
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MKEY
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_GIDPRE
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_BASELID
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_SMLID
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_CAPMASK
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_DIAGCODE
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MKEYLEASEPRD
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LOCALPORTNUM
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKWIDTHENABLED
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LNKWIDTHSUPPORT
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LNKWIDTHACTIVE
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LNKSPEEDSUPPORT
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PORTSTATE
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PORTPHYSTATE
value|(CL_HTON64(((uint64_t)1)<<16))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKDWNDFLTSTATE
value|(CL_HTON64(((uint64_t)1)<<17))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MKEYPROTBITS
value|(CL_HTON64(((uint64_t)1)<<18))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESV2
value|(CL_HTON64(((uint64_t)1)<<19))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LMC
value|(CL_HTON64(((uint64_t)1)<<20))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKSPEEDACTIVE
value|(CL_HTON64(((uint64_t)1)<<21))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKSPEEDENABLE
value|(CL_HTON64(((uint64_t)1)<<22))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_NEIGHBORMTU
value|(CL_HTON64(((uint64_t)1)<<23))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MASTERSMSL
value|(CL_HTON64(((uint64_t)1)<<24))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_VLCAP
value|(CL_HTON64(((uint64_t)1)<<25))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_INITTYPE
value|(CL_HTON64(((uint64_t)1)<<26))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_VLHIGHLIMIT
value|(CL_HTON64(((uint64_t)1)<<27))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_VLARBHIGHCAP
value|(CL_HTON64(((uint64_t)1)<<28))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_VLARBLOWCAP
value|(CL_HTON64(((uint64_t)1)<<29))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_INITTYPEREPLY
value|(CL_HTON64(((uint64_t)1)<<30))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MTUCAP
value|(CL_HTON64(((uint64_t)1)<<31))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_VLSTALLCNT
value|(CL_HTON64(((uint64_t)1)<<32))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_HOQLIFE
value|(CL_HTON64(((uint64_t)1)<<33))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_OPVLS
value|(CL_HTON64(((uint64_t)1)<<34))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PARENFIN
value|(CL_HTON64(((uint64_t)1)<<35))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PARENFOUT
value|(CL_HTON64(((uint64_t)1)<<36))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_FILTERRAWIN
value|(CL_HTON64(((uint64_t)1)<<37))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_FILTERRAWOUT
value|(CL_HTON64(((uint64_t)1)<<38))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MKEYVIO
value|(CL_HTON64(((uint64_t)1)<<39))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_PKEYVIO
value|(CL_HTON64(((uint64_t)1)<<40))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_QKEYVIO
value|(CL_HTON64(((uint64_t)1)<<41))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_GUIDCAP
value|(CL_HTON64(((uint64_t)1)<<42))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_CLIENTREREG
value|(CL_HTON64(((uint64_t)1)<<43))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESV3
value|(CL_HTON64(((uint64_t)1)<<44))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_SUBNTO
value|(CL_HTON64(((uint64_t)1)<<45))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESV4
value|(CL_HTON64(((uint64_t)1)<<46))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESPTIME
value|(CL_HTON64(((uint64_t)1)<<47))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LOCALPHYERR
value|(CL_HTON64(((uint64_t)1)<<48))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_OVERRUNERR
value|(CL_HTON64(((uint64_t)1)<<49))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_MAXCREDHINT
value|(CL_HTON64(((uint64_t)1)<<50))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESV5
value|(CL_HTON64(((uint64_t)1)<<51))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKRTLAT
value|(CL_HTON64(((uint64_t)1)<<52))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_CAPMASK2
value|(CL_HTON64(((uint64_t)1)<<53))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKSPDEXTACT
value|(CL_HTON64(((uint64_t)1)<<54))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKSPDEXTSUPP
value|(CL_HTON64(((uint64_t)1)<<55))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_RESV7
value|(CL_HTON64(((uint64_t)1)<<56))
end_define

begin_define
define|#
directive|define
name|IB_PIR_COMPMASK_LINKSPDEXTENAB
value|(CL_HTON64(((uint64_t)1)<<57))
end_define

begin_comment
comment|/* Multicast Member Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_GID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_MGID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_PORT_GID
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_QKEY
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_MLID
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_MTU_SEL
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_MTU
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_TCLASS
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_PKEY
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_RATE_SEL
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_RATE
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_LIFE_SEL
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_LIFE
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_SL
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_FLOW
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_HOP
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_SCOPE
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_JOIN_STATE
value|(CL_HTON64(((uint64_t)1)<<16))
end_define

begin_define
define|#
directive|define
name|IB_MCR_COMPMASK_PROXY
value|(CL_HTON64(((uint64_t)1)<<17))
end_define

begin_comment
comment|/* GUID Info Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_BLOCKNUM
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_RESV1
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_RESV2
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID0
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID1
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID2
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID3
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID4
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID5
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID6
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_GIR_COMPMASK_GID7
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_comment
comment|/* MultiPath Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_RAWTRAFFIC
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_RESV0
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_FLOWLABEL
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_HOPLIMIT
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_TCLASS
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_REVERSIBLE
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_NUMBPATH
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_PKEY
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_QOS_CLASS
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_SL
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_MTUSELEC
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_MTU
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_RATESELEC
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_RATE
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_PKTLIFETIMESELEC
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_PKTLIFETIME
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_SERVICEID_MSB
value|(CL_HTON64(((uint64_t)1)<<16))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_INDEPSELEC
value|(CL_HTON64(((uint64_t)1)<<17))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_RESV3
value|(CL_HTON64(((uint64_t)1)<<18))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_SGIDCOUNT
value|(CL_HTON64(((uint64_t)1)<<19))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_DGIDCOUNT
value|(CL_HTON64(((uint64_t)1)<<20))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_SERVICEID_LSB
value|(CL_HTON64(((uint64_t)1)<<21))
end_define

begin_define
define|#
directive|define
name|IB_MPR_COMPMASK_SERVICEID
value|(IB_MPR_COMPMASK_SERVICEID_MSB | \ 				   IB_MPR_COMPMASK_SERVICEID_LSB)
end_define

begin_comment
comment|/* SMInfo Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_LID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_RESV0
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_GUID
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_SMKEY
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_ACTCOUNT
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_PRIORITY
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_SMIR_COMPMASK_SMSTATE
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_comment
comment|/* InformInfo Record Component Masks */
end_comment

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_SUBSCRIBERGID
value|(CL_HTON64(((uint64_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_ENUM
value|(CL_HTON64(((uint64_t)1)<<1))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_RESV0
value|(CL_HTON64(((uint64_t)1)<<2))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_GID
value|(CL_HTON64(((uint64_t)1)<<3))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_LIDRANGEBEGIN
value|(CL_HTON64(((uint64_t)1)<<4))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_LIDRANGEEND
value|(CL_HTON64(((uint64_t)1)<<5))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_RESV1
value|(CL_HTON64(((uint64_t)1)<<6))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_ISGENERIC
value|(CL_HTON64(((uint64_t)1)<<7))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_SUBSCRIBE
value|(CL_HTON64(((uint64_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_TYPE
value|(CL_HTON64(((uint64_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_TRAPNUMB
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_DEVICEID
value|(CL_HTON64(((uint64_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_QPN
value|(CL_HTON64(((uint64_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_RESV2
value|(CL_HTON64(((uint64_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_RESPTIME
value|(CL_HTON64(((uint64_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_RESV3
value|(CL_HTON64(((uint64_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_PRODTYPE
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_define
define|#
directive|define
name|IB_IIR_COMPMASK_VENDID
value|(CL_HTON64(((uint64_t)1)<<15))
end_define

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_init_local * NAME *	ib_path_rec_init_local * * DESCRIPTION *	Initializes a subnet local path record. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_path_rec_init_local
parameter_list|(
name|IN
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|,
name|IN
name|ib_gid_t
modifier|*
specifier|const
name|p_dgid
parameter_list|,
name|IN
name|ib_gid_t
modifier|*
specifier|const
name|p_sgid
parameter_list|,
name|IN
name|ib_net16_t
name|dlid
parameter_list|,
name|IN
name|ib_net16_t
name|slid
parameter_list|,
name|IN
name|uint8_t
name|num_path
parameter_list|,
name|IN
name|ib_net16_t
name|pkey
parameter_list|,
name|IN
name|uint8_t
name|sl
parameter_list|,
name|IN
name|uint16_t
name|qos_class
parameter_list|,
name|IN
name|uint8_t
name|mtu_selector
parameter_list|,
name|IN
name|uint8_t
name|mtu
parameter_list|,
name|IN
name|uint8_t
name|rate_selector
parameter_list|,
name|IN
name|uint8_t
name|rate
parameter_list|,
name|IN
name|uint8_t
name|pkt_life_selector
parameter_list|,
name|IN
name|uint8_t
name|pkt_life
parameter_list|,
name|IN
name|uint8_t
name|preference
parameter_list|)
block|{
name|p_rec
operator|->
name|dgid
operator|=
operator|*
name|p_dgid
expr_stmt|;
name|p_rec
operator|->
name|sgid
operator|=
operator|*
name|p_sgid
expr_stmt|;
name|p_rec
operator|->
name|dlid
operator|=
name|dlid
expr_stmt|;
name|p_rec
operator|->
name|slid
operator|=
name|slid
expr_stmt|;
name|p_rec
operator|->
name|num_path
operator|=
name|num_path
expr_stmt|;
name|p_rec
operator|->
name|pkey
operator|=
name|pkey
expr_stmt|;
name|p_rec
operator|->
name|qos_class_sl
operator|=
name|cl_hton16
argument_list|(
operator|(
name|sl
operator|&
name|IB_PATH_REC_SL_MASK
operator|)
operator||
operator|(
name|qos_class
operator|<<
literal|4
operator|)
argument_list|)
expr_stmt|;
name|p_rec
operator|->
name|mtu
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|mtu
operator|&
name|IB_PATH_REC_BASE_MASK
operator|)
operator||
call|(
name|uint8_t
call|)
argument_list|(
name|mtu_selector
operator|<<
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|p_rec
operator|->
name|rate
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|rate
operator|&
name|IB_PATH_REC_BASE_MASK
operator|)
operator||
call|(
name|uint8_t
call|)
argument_list|(
name|rate_selector
operator|<<
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|p_rec
operator|->
name|pkt_life
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|pkt_life
operator|&
name|IB_PATH_REC_BASE_MASK
operator|)
operator||
call|(
name|uint8_t
call|)
argument_list|(
name|pkt_life_selector
operator|<<
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|p_rec
operator|->
name|preference
operator|=
name|preference
expr_stmt|;
comment|/* Clear global routing fields for local path records */
name|p_rec
operator|->
name|hop_flow_raw
operator|=
literal|0
expr_stmt|;
name|p_rec
operator|->
name|tclass
operator|=
literal|0
expr_stmt|;
name|p_rec
operator|->
name|service_id
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|p_rec
operator|->
name|resv2
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|p_rec
operator|->
name|resv2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * *	dgid *		[in] GID of destination port. * *	sgid *		[in] GID of source port. * *	dlid *		[in] LID of destination port. * *	slid *		[in] LID of source port. * *	num_path *		[in] Reversible path - 1 bit to say if path is reversible. *		num_path [6:0] In queries, maximum number of paths to return. *		In responses, undefined. * *	pkey *		[in] Partition key (P_Key) to use on this path. * *	qos_class *		[in] QoS class to use on this path.  Lower 12-bits are valid. * *	sl *		[in] Service level to use on this path.  Lower 4-bits are valid. * *	mtu_selector *		[in] Encoded MTU selector value to use on this path * *	mtu *		[in] Encoded MTU to use on this path * *	rate_selector *		[in] Encoded rate selector value to use on this path. * *	rate *		[in] Encoded rate to use on this path. * *	pkt_life_selector *		[in] Encoded Packet selector value lifetime for this path. * *	pkt_life *		[in] Encoded Packet lifetime for this path. * *	preference *		[in] Indicates the relative merit of this path versus other path *		records returned from the SA.  Lower numbers are better. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	ib_gid_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_num_path * NAME *	ib_path_rec_num_path * * DESCRIPTION *	Get max number of paths to return. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_num_path
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
name|p_rec
operator|->
name|num_path
operator|&
literal|0x7F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Maximum number of paths to return for each unique SGID_DGID combination. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_set_sl * NAME *	ib_path_rec_set_sl * * DESCRIPTION *	Set path service level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_path_rec_set_sl
parameter_list|(
name|IN
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|sl
parameter_list|)
block|{
name|p_rec
operator|->
name|qos_class_sl
operator|=
operator|(
name|p_rec
operator|->
name|qos_class_sl
operator|&
name|CL_HTON16
argument_list|(
name|IB_PATH_REC_QOS_CLASS_MASK
argument_list|)
operator|)
operator||
name|cl_hton16
argument_list|(
name|sl
operator|&
name|IB_PATH_REC_SL_MASK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * *	sl *		[in] Service level to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_sl * NAME *	ib_path_rec_sl * * DESCRIPTION *	Get path service level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_sl
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
name|cl_ntoh16
argument_list|(
name|p_rec
operator|->
name|qos_class_sl
argument_list|)
operator|&
name|IB_PATH_REC_SL_MASK
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	SL. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_set_qos_class * NAME *	ib_path_rec_set_qos_class * * DESCRIPTION *	Set path QoS class. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_path_rec_set_qos_class
parameter_list|(
name|IN
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|,
name|IN
specifier|const
name|uint16_t
name|qos_class
parameter_list|)
block|{
name|p_rec
operator|->
name|qos_class_sl
operator|=
operator|(
name|p_rec
operator|->
name|qos_class_sl
operator|&
name|CL_HTON16
argument_list|(
name|IB_PATH_REC_SL_MASK
argument_list|)
operator|)
operator||
name|cl_hton16
argument_list|(
name|qos_class
operator|<<
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * *	qos_class *		[in] QoS class to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_qos_class * NAME *	ib_path_rec_qos_class * * DESCRIPTION *	Get QoS class. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|OSM_API
name|ib_path_rec_qos_class
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
name|cl_ntoh16
argument_list|(
name|p_rec
operator|->
name|qos_class_sl
argument_list|)
operator|>>
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	QoS class of the path record. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_mtu * NAME *	ib_path_rec_mtu * * DESCRIPTION *	Get encoded path MTU. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_mtu
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|mtu
operator|&
name|IB_PATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path MTU. *		1: 256 *		2: 512 *		3: 1024 *		4: 2048 *		5: 4096 *		others: reserved * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_mtu_sel * NAME *	ib_path_rec_mtu_sel * * DESCRIPTION *	Get encoded path MTU selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_mtu_sel
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|mtu
operator|&
name|IB_PATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path MTU selector value (for queries). *		0: greater than MTU specified *		1: less than MTU specified *		2: exactly the MTU specified *		3: largest MTU available * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_rate * NAME *	ib_path_rec_rate * * DESCRIPTION *	Get encoded path rate. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_rate
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|rate
operator|&
name|IB_PATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path rate. *		2: 2.5 Gb/sec. *		3: 10 Gb/sec. *		4: 30 Gb/sec. *		5: 5 Gb/sec. *		6: 20 Gb/sec. *		7: 40 Gb/sec. *		8: 60 Gb/sec. *		9: 80 Gb/sec. *		10: 120 Gb/sec. *		11: 14 Gb/sec. *		12: 56 Gb/sec. *		13: 112 Gb/sec. *		14: 168 Gb/sec. *		15: 25 Gb/sec. *		16: 100 Gb/sec. *		17: 200 Gb/sec. *		18: 300 Gb/sec. *		others: reserved * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_rate_sel * NAME *	ib_path_rec_rate_sel * * DESCRIPTION *	Get encoded path rate selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_rate_sel
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|rate
operator|&
name|IB_PATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path rate selector value (for queries). *		0: greater than rate specified *		1: less than rate specified *		2: exactly the rate specified *		3: largest rate available * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_pkt_life * NAME *	ib_path_rec_pkt_life * * DESCRIPTION *	Get encoded path pkt_life. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_pkt_life
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|pkt_life
operator|&
name|IB_PATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path pkt_life = 4.096 usec * 2 ** PacketLifeTime. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_pkt_life_sel * NAME *	ib_path_rec_pkt_life_sel * * DESCRIPTION *	Get encoded path pkt_lifetime selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_pkt_life_sel
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|pkt_life
operator|&
name|IB_PATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Encoded path pkt_lifetime selector value (for queries). *		0: greater than rate specified *		1: less than rate specified *		2: exactly the rate specified *		3: smallest packet lifetime available * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_flow_lbl * NAME *	ib_path_rec_flow_lbl * * DESCRIPTION *	Get flow label. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|OSM_API
name|ib_path_rec_flow_lbl
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|cl_ntoh32
argument_list|(
name|p_rec
operator|->
name|hop_flow_raw
argument_list|)
operator|>>
literal|8
operator|)
operator|&
literal|0x000FFFFF
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Flow label of the path record. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_rec_hop_limit * NAME *	ib_path_rec_hop_limit * * DESCRIPTION *	Get hop limit. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_rec_hop_limit
parameter_list|(
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|cl_ntoh32
argument_list|(
name|p_rec
operator|->
name|hop_flow_raw
argument_list|)
operator|&
literal|0x000000FF
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the path record object. * * RETURN VALUES *	Hop limit of the path record. * * NOTES * * SEE ALSO *	ib_path_rec_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_CAP_TRAP * NAME *	IB_CLASS_CAP_TRAP * * DESCRIPTION *	ClassPortInfo CapabilityMask bits.  This bit will be set *	if the class supports Trap() MADs (13.4.8.1). * * SEE ALSO *	ib_class_port_info_t, IB_CLASS_CAP_GETSET, IB_CLASS_CAP_CAPMASK2 * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_CAP_TRAP
value|0x0001
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_CAP_GETSET * NAME *	IB_CLASS_CAP_GETSET * * DESCRIPTION *	ClassPortInfo CapabilityMask bits.  This bit will be set *	if the class supports Get(Notice) and Set(Notice) MADs (13.4.8.1). * * SEE ALSO *	ib_class_port_info_t, IB_CLASS_CAP_TRAP, IB_CLASS_CAP_CAPMASK2 * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_CAP_GETSET
value|0x0002
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_CAP_CAPMASK2 * NAME *	IB_CLASS_CAP_CAPMASK2 * * DESCRIPTION *	ClassPortInfo CapabilityMask bits. *	This bit will be set of the class supports additional class specific *	capabilities (CapabilityMask2) (13.4.8.1). * * SEE ALSO *	ib_class_port_info_t, IB_CLASS_CAP_TRAP, IB_CLASS_CAP_GETSET * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_CAP_CAPMASK2
value|0x0004
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_ENH_PORT0_CC_MASK * NAME *	IB_CLASS_ENH_PORT0_CC_MASK * * DESCRIPTION *	ClassPortInfo CapabilityMask bits. *	Switch only: This bit will be set if the EnhancedPort0 *	supports CA Congestion Control (A10.4.3.1). * * SEE ALSO *	ib_class_port_info_t * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_ENH_PORT0_CC_MASK
value|0x0100
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_RESP_TIME_MASK * NAME *	IB_CLASS_RESP_TIME_MASK * * DESCRIPTION *	Mask bits to extract the response time value from the *	cap_mask2_resp_time field of ib_class_port_info_t. * * SEE ALSO *	ib_class_port_info_t * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_RESP_TIME_MASK
value|0x1F
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Constants/IB_CLASS_CAPMASK2_SHIFT * NAME *	IB_CLASS_CAPMASK2_SHIFT * * DESCRIPTION *	Number of bits to shift to extract the capability mask2 *	from the cap_mask2_resp_time field of ib_class_port_info_t. * * SEE ALSO *	ib_class_port_info_t * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CLASS_CAPMASK2_SHIFT
value|5
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_class_port_info_t * NAME *	ib_class_port_info_t * * DESCRIPTION *	IBA defined ClassPortInfo attribute (13.4.8.1) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_class_port_info
block|{
name|uint8_t
name|base_ver
decl_stmt|;
name|uint8_t
name|class_ver
decl_stmt|;
name|ib_net16_t
name|cap_mask
decl_stmt|;
name|ib_net32_t
name|cap_mask2_resp_time
decl_stmt|;
name|ib_gid_t
name|redir_gid
decl_stmt|;
name|ib_net32_t
name|redir_tc_sl_fl
decl_stmt|;
name|ib_net16_t
name|redir_lid
decl_stmt|;
name|ib_net16_t
name|redir_pkey
decl_stmt|;
name|ib_net32_t
name|redir_qp
decl_stmt|;
name|ib_net32_t
name|redir_qkey
decl_stmt|;
name|ib_gid_t
name|trap_gid
decl_stmt|;
name|ib_net32_t
name|trap_tc_sl_fl
decl_stmt|;
name|ib_net16_t
name|trap_lid
decl_stmt|;
name|ib_net16_t
name|trap_pkey
decl_stmt|;
name|ib_net32_t
name|trap_hop_qp
decl_stmt|;
name|ib_net32_t
name|trap_qkey
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_class_port_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	base_ver *		Maximum supported MAD Base Version. * *	class_ver *		Maximum supported management class version. * *	cap_mask *		Supported capabilities of this management class. * *	cap_mask2_resp_time *		Maximum expected response time and additional *		supported capabilities of this management class. * *	redir_gid *		GID to use for redirection, or zero * *	redir_tc_sl_fl *		Traffic class, service level and flow label the requester *		should use if the service is redirected. * *	redir_lid *		LID used for redirection, or zero * *	redir_pkey *		P_Key used for redirection * *	redir_qp *		QP number used for redirection * *	redir_qkey *		Q_Key associated with the redirected QP.  This shall be the *		well known Q_Key value. * *	trap_gid *		GID value used for trap messages from this service. * *	trap_tc_sl_fl *		Traffic class, service level and flow label used for *		trap messages originated by this service. * *	trap_lid *		LID used for trap messages, or zero * *	trap_pkey *		P_Key used for trap messages * *	trap_hop_qp *		Hop limit (upper 8 bits) and QP number used for trap messages * *	trap_qkey *		Q_Key associated with the trap messages QP. * * SEE ALSO *	IB_CLASS_CAP_GETSET, IB_CLASS_CAP_TRAP * *********/
end_comment

begin_define
define|#
directive|define
name|IB_PM_ALL_PORT_SELECT
value|(CL_HTON16(((uint16_t)1)<<8))
end_define

begin_define
define|#
directive|define
name|IB_PM_EXT_WIDTH_SUPPORTED
value|(CL_HTON16(((uint16_t)1)<<9))
end_define

begin_define
define|#
directive|define
name|IB_PM_EXT_WIDTH_NOIETF_SUP
value|(CL_HTON16(((uint16_t)1)<<10))
end_define

begin_define
define|#
directive|define
name|IB_PM_SAMPLES_ONLY_SUP
value|(CL_HTON16(((uint16_t)1)<<11))
end_define

begin_define
define|#
directive|define
name|IB_PM_PC_XMIT_WAIT_SUP
value|(CL_HTON16(((uint16_t)1)<<12))
end_define

begin_define
define|#
directive|define
name|IS_PM_INH_LMTD_PKEY_MC_CONSTR_ERR
value|(CL_HTON16(((uint16_t)1)<<13))
end_define

begin_define
define|#
directive|define
name|IS_PM_RSFEC_COUNTERS_SUP
value|(CL_HTON16(((uint16_t)1)<<14))
end_define

begin_define
define|#
directive|define
name|IB_PM_IS_QP1_DROP_SUP
value|(CL_HTON16(((uint16_t)1)<<15))
end_define

begin_comment
comment|/* CapabilityMask2 */
end_comment

begin_define
define|#
directive|define
name|IB_PM_IS_PM_KEY_SUPPORTED
value|(CL_HTON32(((uint32_t)1)<<0))
end_define

begin_define
define|#
directive|define
name|IB_PM_IS_ADDL_PORT_CTRS_EXT_SUP
value|(CL_HTON32(((uint32_t)1)<<1))
end_define

begin_comment
comment|/****f* IBA Base: Types/ib_class_set_resp_time_val * NAME *	ib_class_set_resp_time_val * * DESCRIPTION *	Set maximum expected response time. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_class_set_resp_time_val
parameter_list|(
name|IN
name|ib_class_port_info_t
modifier|*
specifier|const
name|p_cpi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|val
parameter_list|)
block|{
name|p_cpi
operator|->
name|cap_mask2_resp_time
operator|=
operator|(
name|p_cpi
operator|->
name|cap_mask2_resp_time
operator|&
name|CL_HTON32
argument_list|(
operator|~
name|IB_CLASS_RESP_TIME_MASK
argument_list|)
operator|)
operator||
name|cl_hton32
argument_list|(
name|val
operator|&
name|IB_CLASS_RESP_TIME_MASK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cpi *		[in] Pointer to the class port info object. * *	val *		[in] Response time value to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_class_port_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_resp_time_val * NAME *	ib_class_resp_time_val * * DESCRIPTION *	Get response time value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_class_resp_time_val
parameter_list|(
name|IN
name|ib_class_port_info_t
modifier|*
specifier|const
name|p_cpi
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
name|cl_ntoh32
argument_list|(
name|p_cpi
operator|->
name|cap_mask2_resp_time
argument_list|)
operator|&
name|IB_CLASS_RESP_TIME_MASK
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cpi *		[in] Pointer to the class port info object. * * RETURN VALUES *	Response time value. * * NOTES * * SEE ALSO *	ib_class_port_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_set_cap_mask2 * NAME *	ib_class_set_cap_mask2 * * DESCRIPTION *	Set ClassPortInfo:CapabilityMask2. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_class_set_cap_mask2
parameter_list|(
name|IN
name|ib_class_port_info_t
modifier|*
specifier|const
name|p_cpi
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|cap_mask2
parameter_list|)
block|{
name|p_cpi
operator|->
name|cap_mask2_resp_time
operator|=
operator|(
name|p_cpi
operator|->
name|cap_mask2_resp_time
operator|&
name|CL_HTON32
argument_list|(
name|IB_CLASS_RESP_TIME_MASK
argument_list|)
operator|)
operator||
name|cl_hton32
argument_list|(
name|cap_mask2
operator|<<
name|IB_CLASS_CAPMASK2_SHIFT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cpi *		[in] Pointer to the class port info object. * *	cap_mask2 *		[in] CapabilityMask2 value to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_class_port_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_class_cap_mask2 * NAME *	ib_class_cap_mask2 * * DESCRIPTION *	Get ClassPortInfo:CapabilityMask2. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|OSM_API
name|ib_class_cap_mask2
parameter_list|(
name|IN
specifier|const
name|ib_class_port_info_t
modifier|*
specifier|const
name|p_cpi
parameter_list|)
block|{
return|return
operator|(
name|cl_ntoh32
argument_list|(
name|p_cpi
operator|->
name|cap_mask2_resp_time
argument_list|)
operator|>>
name|IB_CLASS_CAPMASK2_SHIFT
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cpi *		[in] Pointer to the class port info object. * * RETURN VALUES *	CapabilityMask2 of the ClassPortInfo. * * NOTES * * SEE ALSO *	ib_class_port_info_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_sm_info_t * NAME *	ib_sm_info_t * * DESCRIPTION *	SMInfo structure (14.2.5.13). * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sm_info
block|{
name|ib_net64_t
name|guid
decl_stmt|;
name|ib_net64_t
name|sm_key
decl_stmt|;
name|ib_net32_t
name|act_count
decl_stmt|;
name|uint8_t
name|pri_state
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sm_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	guid *		Port GUID for this SM. * *	sm_key *		SM_Key of this SM. * *	act_count *		Activity counter used as a heartbeat. * *	pri_state *		Priority and State information * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_sminfo_get_priority * NAME *	ib_sminfo_get_priority * * DESCRIPTION *	Returns the priority value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_sminfo_get_priority
parameter_list|(
name|IN
specifier|const
name|ib_sm_info_t
modifier|*
specifier|const
name|p_smi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_smi
operator|->
name|pri_state
operator|&
literal|0xF0
operator|)
operator|>>
literal|4
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smi *		[in] Pointer to the SMInfo Attribute. * * RETURN VALUES *	Returns the priority value. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_sminfo_get_state * NAME *	ib_sminfo_get_state * * DESCRIPTION *	Returns the state value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_sminfo_get_state
parameter_list|(
name|IN
specifier|const
name|ib_sm_info_t
modifier|*
specifier|const
name|p_smi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_smi
operator|->
name|pri_state
operator|&
literal|0x0F
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smi *		[in] Pointer to the SMInfo Attribute. * * RETURN VALUES *	Returns the state value. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_mad_t * NAME *	ib_mad_t * * DESCRIPTION *	IBA defined MAD header (13.4.3) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_mad
block|{
name|uint8_t
name|base_ver
decl_stmt|;
name|uint8_t
name|mgmt_class
decl_stmt|;
name|uint8_t
name|class_ver
decl_stmt|;
name|uint8_t
name|method
decl_stmt|;
name|ib_net16_t
name|status
decl_stmt|;
name|ib_net16_t
name|class_spec
decl_stmt|;
name|ib_net64_t
name|trans_id
decl_stmt|;
name|ib_net16_t
name|attr_id
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_net32_t
name|attr_mod
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	base_ver *		MAD base format. * *	mgmt_class *		Class of operation. * *	class_ver *		Version of MAD class-specific format. * *	method *		Method to perform, including 'R' bit. * *	status *		Status of operation. * *	class_spec *		Reserved for subnet management. * *	trans_id *		Transaction ID. * *	attr_id *		Attribute ID. * *	resv *		Reserved field. * *	attr_mod *		Attribute modifier. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_rmpp_mad_t * NAME *	ib_rmpp_mad_t * * DESCRIPTION *	IBA defined MAD RMPP header (13.6.2.1) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_rmpp_mad
block|{
name|ib_mad_t
name|common_hdr
decl_stmt|;
name|uint8_t
name|rmpp_version
decl_stmt|;
name|uint8_t
name|rmpp_type
decl_stmt|;
name|uint8_t
name|rmpp_flags
decl_stmt|;
name|uint8_t
name|rmpp_status
decl_stmt|;
name|ib_net32_t
name|seg_num
decl_stmt|;
name|ib_net32_t
name|paylen_newwin
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_rmpp_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * SEE ALSO *	ib_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_mad_init_new * NAME *	ib_mad_init_new * * DESCRIPTION *	Initializes a MAD common header. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_mad_init_new
parameter_list|(
name|IN
name|ib_mad_t
modifier|*
specifier|const
name|p_mad
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|mgmt_class
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|class_ver
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|method
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|trans_id
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|attr_id
parameter_list|,
name|IN
specifier|const
name|ib_net32_t
name|attr_mod
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_mad
argument_list|)
expr_stmt|;
name|p_mad
operator|->
name|base_ver
operator|=
literal|1
expr_stmt|;
name|p_mad
operator|->
name|mgmt_class
operator|=
name|mgmt_class
expr_stmt|;
name|p_mad
operator|->
name|class_ver
operator|=
name|class_ver
expr_stmt|;
name|p_mad
operator|->
name|method
operator|=
name|method
expr_stmt|;
name|p_mad
operator|->
name|status
operator|=
literal|0
expr_stmt|;
name|p_mad
operator|->
name|class_spec
operator|=
literal|0
expr_stmt|;
name|p_mad
operator|->
name|trans_id
operator|=
name|trans_id
expr_stmt|;
name|p_mad
operator|->
name|attr_id
operator|=
name|attr_id
expr_stmt|;
name|p_mad
operator|->
name|resv
operator|=
literal|0
expr_stmt|;
name|p_mad
operator|->
name|attr_mod
operator|=
name|attr_mod
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mad *		[in] Pointer to the MAD common header. * *	mgmt_class *		[in] Class of operation. * *	class_ver *		[in] Version of MAD class-specific format. * *	method *		[in] Method to perform, including 'R' bit. * *	trans_Id *		[in] Transaction ID. * *	attr_id *		[in] Attribute ID. * *	attr_mod *		[in] Attribute modifier. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_mad_init_response * NAME *	ib_mad_init_response * * DESCRIPTION *	Initializes a MAD common header as a response. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_mad_init_response
parameter_list|(
name|IN
specifier|const
name|ib_mad_t
modifier|*
specifier|const
name|p_req_mad
parameter_list|,
name|IN
name|ib_mad_t
modifier|*
specifier|const
name|p_mad
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|status
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_req_mad
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_mad
argument_list|)
expr_stmt|;
operator|*
name|p_mad
operator|=
operator|*
name|p_req_mad
expr_stmt|;
name|p_mad
operator|->
name|status
operator|=
name|status
expr_stmt|;
if|if
condition|(
name|p_mad
operator|->
name|method
operator|==
name|IB_MAD_METHOD_SET
condition|)
name|p_mad
operator|->
name|method
operator|=
name|IB_MAD_METHOD_GET
expr_stmt|;
name|p_mad
operator|->
name|method
operator||=
name|IB_MAD_METHOD_RESP_MASK
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_req_mad *		[in] Pointer to the MAD common header in the original request MAD. * *	p_mad *		[in] Pointer to the MAD common header to initialize. * *	status *		[in] MAD Status value to return; * * RETURN VALUES *	None. * * NOTES *	p_req_mad and p_mad may point to the same MAD. * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_mad_is_response * NAME *	ib_mad_is_response * * DESCRIPTION *	Returns TRUE if the MAD is a response ('R' bit set) *	or if the MAD is a TRAP REPRESS, *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_mad_is_response
parameter_list|(
name|IN
specifier|const
name|ib_mad_t
modifier|*
specifier|const
name|p_mad
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_mad
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_mad
operator|->
name|method
operator|&
name|IB_MAD_METHOD_RESP_MASK
operator|||
name|p_mad
operator|->
name|method
operator|==
name|IB_MAD_METHOD_TRAP_REPRESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mad *		[in] Pointer to the MAD. * * RETURN VALUES *	Returns TRUE if the MAD is a response ('R' bit set), *	FALSE otherwise. * * NOTES * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_TYPE_DATA
value|1
end_define

begin_define
define|#
directive|define
name|IB_RMPP_TYPE_ACK
value|2
end_define

begin_define
define|#
directive|define
name|IB_RMPP_TYPE_STOP
value|3
end_define

begin_define
define|#
directive|define
name|IB_RMPP_TYPE_ABORT
value|4
end_define

begin_define
define|#
directive|define
name|IB_RMPP_NO_RESP_TIME
value|0x1F
end_define

begin_define
define|#
directive|define
name|IB_RMPP_FLAG_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_RMPP_FLAG_FIRST
value|0x02
end_define

begin_define
define|#
directive|define
name|IB_RMPP_FLAG_LAST
value|0x04
end_define

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_RESX
value|1
end_define

begin_comment
comment|/* resources exhausted */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_T2L
value|118
end_define

begin_comment
comment|/* time too long */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_BAD_LEN
value|119
end_define

begin_comment
comment|/* incon. last and payload len */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_BAD_SEG
value|120
end_define

begin_comment
comment|/* incon. first and segment no */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_BADT
value|121
end_define

begin_comment
comment|/* bad rmpp type */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_W2S
value|122
end_define

begin_comment
comment|/* newwindowlast too small */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_S2B
value|123
end_define

begin_comment
comment|/* segment no too big */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_BAD_STATUS
value|124
end_define

begin_comment
comment|/* illegal status */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_UNV
value|125
end_define

begin_comment
comment|/* unsupported version */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_TMR
value|126
end_define

begin_comment
comment|/* too many retries */
end_comment

begin_define
define|#
directive|define
name|IB_RMPP_STATUS_UNSPEC
value|127
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_rmpp_is_flag_set * NAME *	ib_rmpp_is_flag_set * * DESCRIPTION *	Returns TRUE if the MAD has the given RMPP flag set. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_rmpp_is_flag_set
parameter_list|(
name|IN
specifier|const
name|ib_rmpp_mad_t
modifier|*
specifier|const
name|p_rmpp_mad
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|flag
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_rmpp_mad
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|p_rmpp_mad
operator|->
name|rmpp_flags
operator|&
name|flag
operator|)
operator|==
name|flag
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	ib_rmpp_mad_t *		[in] Pointer to a MAD with an RMPP header. * *	flag *		[in] The RMPP flag being examined. * * RETURN VALUES *	Returns TRUE if the MAD has the given RMPP flag set. * * NOTES * * SEE ALSO *	ib_mad_t, ib_rmpp_mad_t *********/
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_rmpp_set_resp_time
parameter_list|(
name|IN
name|ib_rmpp_mad_t
modifier|*
specifier|const
name|p_rmpp_mad
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|resp_time
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_rmpp_mad
argument_list|)
expr_stmt|;
name|p_rmpp_mad
operator|->
name|rmpp_flags
operator||=
operator|(
name|resp_time
operator|<<
literal|3
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_rmpp_get_resp_time
parameter_list|(
name|IN
specifier|const
name|ib_rmpp_mad_t
modifier|*
specifier|const
name|p_rmpp_mad
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_rmpp_mad
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rmpp_mad
operator|->
name|rmpp_flags
operator|>>
literal|3
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/****d* IBA Base: Constants/IB_SMP_DIRECTION * NAME *	IB_SMP_DIRECTION * * DESCRIPTION *	The Direction bit for directed route SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMP_DIRECTION_HO
value|0x8000
end_define

begin_define
define|#
directive|define
name|IB_SMP_DIRECTION
value|(CL_HTON16(IB_SMP_DIRECTION_HO))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMP_STATUS_MASK * NAME *	IB_SMP_STATUS_MASK * * DESCRIPTION *	Mask value for extracting status from a directed route SMP. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMP_STATUS_MASK_HO
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|IB_SMP_STATUS_MASK
value|(CL_HTON16(IB_SMP_STATUS_MASK_HO))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_smp_t * NAME *	ib_smp_t * * DESCRIPTION *	IBA defined SMP. (14.2.1.2) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_SMP_DATA_SIZE
value|64
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_smp
block|{
name|uint8_t
name|base_ver
decl_stmt|;
name|uint8_t
name|mgmt_class
decl_stmt|;
name|uint8_t
name|class_ver
decl_stmt|;
name|uint8_t
name|method
decl_stmt|;
name|ib_net16_t
name|status
decl_stmt|;
name|uint8_t
name|hop_ptr
decl_stmt|;
name|uint8_t
name|hop_count
decl_stmt|;
name|ib_net64_t
name|trans_id
decl_stmt|;
name|ib_net16_t
name|attr_id
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_net32_t
name|attr_mod
decl_stmt|;
name|ib_net64_t
name|m_key
decl_stmt|;
name|ib_net16_t
name|dr_slid
decl_stmt|;
name|ib_net16_t
name|dr_dlid
decl_stmt|;
name|uint32_t
name|resv1
index|[
literal|7
index|]
decl_stmt|;
name|uint8_t
name|data
index|[
name|IB_SMP_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|initial_path
index|[
name|IB_SUBNET_PATH_HOPS_MAX
index|]
decl_stmt|;
name|uint8_t
name|return_path
index|[
name|IB_SUBNET_PATH_HOPS_MAX
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_smp_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	base_ver *		MAD base format. * *	mgmt_class *		Class of operation. * *	class_ver *		Version of MAD class-specific format. * *	method *		Method to perform, including 'R' bit. * *	status *		Status of operation. * *	hop_ptr *		Hop pointer for directed route MADs. * *	hop_count *		Hop count for directed route MADs. * *	trans_Id *		Transaction ID. * *	attr_id *		Attribute ID. * *	resv *		Reserved field. * *	attr_mod *		Attribute modifier. * *	m_key *		Management key value. * *	dr_slid *		Directed route source LID. * *	dr_dlid *		Directed route destination LID. * *	resv0 *		Reserved for 64 byte alignment. * *	data *		MAD data payload. * *	initial_path *		Outbound port list. * *	return_path *		Inbound port list. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_smp_get_status * NAME *	ib_smp_get_status * * DESCRIPTION *	Returns the SMP status value in network order. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|OSM_API
name|ib_smp_get_status
parameter_list|(
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|)
block|{
return|return
operator|(
call|(
name|ib_net16_t
call|)
argument_list|(
name|p_smp
operator|->
name|status
operator|&
name|IB_SMP_STATUS_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smp *		[in] Pointer to the SMP packet. * * RETURN VALUES *	Returns the SMP status value in network order. * * NOTES * * SEE ALSO *	ib_smp_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_smp_is_response * NAME *	ib_smp_is_response * * DESCRIPTION *	Returns TRUE if the SMP is a response MAD, FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_smp_is_response
parameter_list|(
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|)
block|{
return|return
operator|(
name|ib_mad_is_response
argument_list|(
operator|(
specifier|const
name|ib_mad_t
operator|*
operator|)
name|p_smp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smp *		[in] Pointer to the SMP packet. * * RETURN VALUES *	Returns TRUE if the SMP is a response MAD, FALSE otherwise. * * NOTES * * SEE ALSO *	ib_smp_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_smp_is_d * NAME *	ib_smp_is_d * * DESCRIPTION *	Returns TRUE if the SMP 'D' (direction) bit is set. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_smp_is_d
parameter_list|(
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_smp
operator|->
name|status
operator|&
name|IB_SMP_DIRECTION
operator|)
operator|==
name|IB_SMP_DIRECTION
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smp *		[in] Pointer to the SMP packet. * * RETURN VALUES *	Returns TRUE if the SMP 'D' (direction) bit is set. * * NOTES * * SEE ALSO *	ib_smp_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_smp_init_new * NAME *	ib_smp_init_new * * DESCRIPTION *	Initializes a MAD common header. * * TODO *	This is too big for inlining, but leave it here for now *	since there is not yet another convenient spot. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_smp_init_new
parameter_list|(
name|IN
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|method
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|trans_id
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|attr_id
parameter_list|,
name|IN
specifier|const
name|ib_net32_t
name|attr_mod
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|hop_count
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|m_key
parameter_list|,
name|IN
specifier|const
name|uint8_t
modifier|*
name|path_out
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|dr_slid
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|dr_dlid
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_smp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|hop_count
operator|<
name|IB_SUBNET_PATH_HOPS_MAX
argument_list|)
expr_stmt|;
name|p_smp
operator|->
name|base_ver
operator|=
literal|1
expr_stmt|;
name|p_smp
operator|->
name|mgmt_class
operator|=
name|IB_MCLASS_SUBN_DIR
expr_stmt|;
name|p_smp
operator|->
name|class_ver
operator|=
literal|1
expr_stmt|;
name|p_smp
operator|->
name|method
operator|=
name|method
expr_stmt|;
name|p_smp
operator|->
name|status
operator|=
literal|0
expr_stmt|;
name|p_smp
operator|->
name|hop_ptr
operator|=
literal|0
expr_stmt|;
name|p_smp
operator|->
name|hop_count
operator|=
name|hop_count
expr_stmt|;
name|p_smp
operator|->
name|trans_id
operator|=
name|trans_id
expr_stmt|;
name|p_smp
operator|->
name|attr_id
operator|=
name|attr_id
expr_stmt|;
name|p_smp
operator|->
name|resv
operator|=
literal|0
expr_stmt|;
name|p_smp
operator|->
name|attr_mod
operator|=
name|attr_mod
expr_stmt|;
name|p_smp
operator|->
name|m_key
operator|=
name|m_key
expr_stmt|;
name|p_smp
operator|->
name|dr_slid
operator|=
name|dr_slid
expr_stmt|;
name|p_smp
operator|->
name|dr_dlid
operator|=
name|dr_dlid
expr_stmt|;
name|memset
argument_list|(
name|p_smp
operator|->
name|resv1
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|p_smp
operator|->
name|resv1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|p_smp
operator|->
name|data
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|p_smp
operator|->
name|initial_path
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|p_smp
operator|->
name|return_path
argument_list|)
argument_list|)
expr_stmt|;
comment|/* copy the path */
name|memcpy
argument_list|(
operator|&
name|p_smp
operator|->
name|initial_path
argument_list|,
name|path_out
argument_list|,
sizeof|sizeof
argument_list|(
name|p_smp
operator|->
name|initial_path
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smp *		[in] Pointer to the SMP packet. * *	method *		[in] Method to perform, including 'R' bit. * *	trans_Id *		[in] Transaction ID. * *	attr_id *		[in] Attribute ID. * *	attr_mod *		[in] Attribute modifier. * *	hop_count *		[in] Number of hops in the path. * *	m_key *		[in] Management key for this SMP. * *	path_out *		[in] Port array for outbound path. * * * RETURN VALUES *	None. * * NOTES *	Payload area is initialized to zero. * * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_smp_get_payload_ptr * NAME *	ib_smp_get_payload_ptr * * DESCRIPTION *	Gets a pointer to the SMP payload area. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|OSM_API
name|ib_smp_get_payload_ptr
parameter_list|(
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_smp
operator|->
name|data
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_smp *		[in] Pointer to the SMP packet. * * RETURN VALUES *	Pointer to SMP payload area. * * NOTES * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_node_info_t * NAME *	ib_node_info_t * * DESCRIPTION *	IBA defined NodeInfo. (14.2.5.3) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_node_info
block|{
name|uint8_t
name|base_version
decl_stmt|;
name|uint8_t
name|class_version
decl_stmt|;
name|uint8_t
name|node_type
decl_stmt|;
name|uint8_t
name|num_ports
decl_stmt|;
name|ib_net64_t
name|sys_guid
decl_stmt|;
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|ib_net16_t
name|partition_cap
decl_stmt|;
name|ib_net16_t
name|device_id
decl_stmt|;
name|ib_net32_t
name|revision
decl_stmt|;
name|ib_net32_t
name|port_num_vendor_id
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_node_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_sa_mad_t * NAME *	ib_sa_mad_t * * DESCRIPTION *	IBA defined SA MAD format. (15.2.1) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_SA_DATA_SIZE
value|200
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sa_mad
block|{
name|uint8_t
name|base_ver
decl_stmt|;
name|uint8_t
name|mgmt_class
decl_stmt|;
name|uint8_t
name|class_ver
decl_stmt|;
name|uint8_t
name|method
decl_stmt|;
name|ib_net16_t
name|status
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_net64_t
name|trans_id
decl_stmt|;
name|ib_net16_t
name|attr_id
decl_stmt|;
name|ib_net16_t
name|resv1
decl_stmt|;
name|ib_net32_t
name|attr_mod
decl_stmt|;
name|uint8_t
name|rmpp_version
decl_stmt|;
name|uint8_t
name|rmpp_type
decl_stmt|;
name|uint8_t
name|rmpp_flags
decl_stmt|;
name|uint8_t
name|rmpp_status
decl_stmt|;
name|ib_net32_t
name|seg_num
decl_stmt|;
name|ib_net32_t
name|paylen_newwin
decl_stmt|;
name|ib_net64_t
name|sm_key
decl_stmt|;
name|ib_net16_t
name|attr_offset
decl_stmt|;
name|ib_net16_t
name|resv3
decl_stmt|;
name|ib_net64_t
name|comp_mask
decl_stmt|;
name|uint8_t
name|data
index|[
name|IB_SA_DATA_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sa_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/**********/
end_comment

begin_define
define|#
directive|define
name|IB_SA_MAD_HDR_SIZE
value|(sizeof(ib_sa_mad_t) - IB_SA_DATA_SIZE)
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|OSM_API
name|ib_get_attr_size
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|attr_offset
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|uint32_t
operator|)
name|cl_ntoh16
argument_list|(
name|attr_offset
argument_list|)
operator|)
operator|<<
literal|3
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|OSM_API
name|ib_get_attr_offset
parameter_list|(
name|IN
specifier|const
name|uint32_t
name|attr_size
parameter_list|)
block|{
return|return
operator|(
name|cl_hton16
argument_list|(
call|(
name|uint16_t
call|)
argument_list|(
name|attr_size
operator|>>
literal|3
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/****f* IBA Base: Types/ib_sa_mad_get_payload_ptr * NAME *	ib_sa_mad_get_payload_ptr * * DESCRIPTION *	Gets a pointer to the SA MAD's payload area. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|OSM_API
name|ib_sa_mad_get_payload_ptr
parameter_list|(
name|IN
specifier|const
name|ib_sa_mad_t
modifier|*
specifier|const
name|p_sa_mad
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_sa_mad
operator|->
name|data
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sa_mad *		[in] Pointer to the SA MAD packet. * * RETURN VALUES *	Pointer to SA MAD payload area. * * NOTES * * SEE ALSO *	ib_mad_t *********/
end_comment

begin_define
define|#
directive|define
name|IB_NODE_INFO_PORT_NUM_MASK
value|(CL_HTON32(0xFF000000))
end_define

begin_define
define|#
directive|define
name|IB_NODE_INFO_VEND_ID_MASK
value|(CL_HTON32(0x00FFFFFF))
end_define

begin_if
if|#
directive|if
name|CPU_LE
end_if

begin_define
define|#
directive|define
name|IB_NODE_INFO_PORT_NUM_SHIFT
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IB_NODE_INFO_PORT_NUM_SHIFT
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****f* IBA Base: Types/ib_node_info_get_local_port_num * NAME *	ib_node_info_get_local_port_num * * DESCRIPTION *	Gets the local port number from the NodeInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_node_info_get_local_port_num
parameter_list|(
name|IN
specifier|const
name|ib_node_info_t
modifier|*
specifier|const
name|p_ni
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_ni
operator|->
name|port_num_vendor_id
operator|&
name|IB_NODE_INFO_PORT_NUM_MASK
operator|)
operator|>>
name|IB_NODE_INFO_PORT_NUM_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ni *		[in] Pointer to a NodeInfo attribute. * * RETURN VALUES *	Local port number that returned the attribute. * * NOTES * * SEE ALSO *	ib_node_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_node_info_get_vendor_id * NAME *	ib_node_info_get_vendor_id * * DESCRIPTION *	Gets the VendorID from the NodeInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_node_info_get_vendor_id
parameter_list|(
name|IN
specifier|const
name|ib_node_info_t
modifier|*
specifier|const
name|p_ni
parameter_list|)
block|{
return|return
operator|(
call|(
name|ib_net32_t
call|)
argument_list|(
name|p_ni
operator|->
name|port_num_vendor_id
operator|&
name|IB_NODE_INFO_VEND_ID_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ni *		[in] Pointer to a NodeInfo attribute. * * RETURN VALUES *	VendorID that returned the attribute. * * NOTES * * SEE ALSO *	ib_node_info_t *********/
end_comment

begin_define
define|#
directive|define
name|IB_NODE_DESCRIPTION_SIZE
value|64
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_node_desc
block|{
comment|// Node String is an array of UTF-8 characters
comment|// that describe the node in text format
comment|// Note that this string is NOT NULL TERMINATED!
name|uint8_t
name|description
index|[
name|IB_NODE_DESCRIPTION_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_node_desc_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_node_record_t
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_node_info_t
name|node_info
decl_stmt|;
name|ib_node_desc_t
name|node_desc
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_node_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_port_info_t * NAME *	ib_port_info_t * * DESCRIPTION *	IBA defined PortInfo. (14.2.5.6) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_info
block|{
name|ib_net64_t
name|m_key
decl_stmt|;
name|ib_net64_t
name|subnet_prefix
decl_stmt|;
name|ib_net16_t
name|base_lid
decl_stmt|;
name|ib_net16_t
name|master_sm_base_lid
decl_stmt|;
name|ib_net32_t
name|capability_mask
decl_stmt|;
name|ib_net16_t
name|diag_code
decl_stmt|;
name|ib_net16_t
name|m_key_lease_period
decl_stmt|;
name|uint8_t
name|local_port_num
decl_stmt|;
name|uint8_t
name|link_width_enabled
decl_stmt|;
name|uint8_t
name|link_width_supported
decl_stmt|;
name|uint8_t
name|link_width_active
decl_stmt|;
name|uint8_t
name|state_info1
decl_stmt|;
comment|/* LinkSpeedSupported and PortState */
name|uint8_t
name|state_info2
decl_stmt|;
comment|/* PortPhysState and LinkDownDefaultState */
name|uint8_t
name|mkey_lmc
decl_stmt|;
comment|/* M_KeyProtectBits and LMC */
name|uint8_t
name|link_speed
decl_stmt|;
comment|/* LinkSpeedEnabled and LinkSpeedActive */
name|uint8_t
name|mtu_smsl
decl_stmt|;
name|uint8_t
name|vl_cap
decl_stmt|;
comment|/* VLCap and InitType */
name|uint8_t
name|vl_high_limit
decl_stmt|;
name|uint8_t
name|vl_arb_high_cap
decl_stmt|;
name|uint8_t
name|vl_arb_low_cap
decl_stmt|;
name|uint8_t
name|mtu_cap
decl_stmt|;
name|uint8_t
name|vl_stall_life
decl_stmt|;
name|uint8_t
name|vl_enforce
decl_stmt|;
name|ib_net16_t
name|m_key_violations
decl_stmt|;
name|ib_net16_t
name|p_key_violations
decl_stmt|;
name|ib_net16_t
name|q_key_violations
decl_stmt|;
name|uint8_t
name|guid_cap
decl_stmt|;
name|uint8_t
name|subnet_timeout
decl_stmt|;
comment|/* cli_rereg(1b), mcast_pkey_trap_suppr(1b), reserv(1b), timeout(5b) */
name|uint8_t
name|resp_time_value
decl_stmt|;
comment|/* reserv(3b), rtv(5b) */
name|uint8_t
name|error_threshold
decl_stmt|;
comment|/* local phy errors(4b), overrun errors(4b) */
name|ib_net16_t
name|max_credit_hint
decl_stmt|;
name|ib_net32_t
name|link_rt_latency
decl_stmt|;
comment|/* reserv(8b), link round trip lat(24b) */
name|ib_net16_t
name|capability_mask2
decl_stmt|;
name|uint8_t
name|link_speed_ext
decl_stmt|;
comment|/* LinkSpeedExtActive and LinkSpeedExtSupported */
name|uint8_t
name|link_speed_ext_enabled
decl_stmt|;
comment|/* reserv(3b), LinkSpeedExtEnabled(5b) */
block|}
name|PACK_SUFFIX
name|ib_port_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_define
define|#
directive|define
name|IB_PORT_STATE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|IB_PORT_LMC_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|IB_PORT_LMC_MAX
value|0x07
end_define

begin_define
define|#
directive|define
name|IB_PORT_MPB_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|IB_PORT_MPB_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IB_PORT_LINK_SPEED_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IB_PORT_LINK_SPEED_SUPPORTED_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|IB_PORT_LINK_SPEED_ACTIVE_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|IB_PORT_LINK_SPEED_ENABLED_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_NO_CHANGE
value|0
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_SLEEP
value|1
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_POLLING
value|2
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_DISABLED
value|3
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_PORTCONFTRAIN
value|4
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_LINKUP
value|5
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_LINKERRRECOVER
value|6
end_define

begin_define
define|#
directive|define
name|IB_PORT_PHYS_STATE_PHYTEST
value|7
end_define

begin_define
define|#
directive|define
name|IB_PORT_LNKDWNDFTSTATE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_RESV0
value|(CL_HTON32(0x00000001))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_IS_SM
value|(CL_HTON32(0x00000002))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_NOTICE
value|(CL_HTON32(0x00000004))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_TRAP
value|(CL_HTON32(0x00000008))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_IPD
value|(CL_HTON32(0x00000010))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_AUTO_MIG
value|(CL_HTON32(0x00000020))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_SL_MAP
value|(CL_HTON32(0x00000040))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_NV_MKEY
value|(CL_HTON32(0x00000080))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_NV_PKEY
value|(CL_HTON32(0x00000100))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_LED_INFO
value|(CL_HTON32(0x00000200))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_SM_DISAB
value|(CL_HTON32(0x00000400))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_SYS_IMG_GUID
value|(CL_HTON32(0x00000800))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_PKEY_SW_EXT_PORT_TRAP
value|(CL_HTON32(0x00001000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_CABLE_INFO
value|(CL_HTON32(0x00002000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_EXT_SPEEDS
value|(CL_HTON32(0x00004000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_CAP_MASK2
value|(CL_HTON32(0x00008000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_COM_MGT
value|(CL_HTON32(0x00010000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_SNMP
value|(CL_HTON32(0x00020000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_REINIT
value|(CL_HTON32(0x00040000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_DEV_MGT
value|(CL_HTON32(0x00080000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_VEND_CLS
value|(CL_HTON32(0x00100000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_DR_NTC
value|(CL_HTON32(0x00200000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_CAP_NTC
value|(CL_HTON32(0x00400000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_BM
value|(CL_HTON32(0x00800000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_LINK_RT_LATENCY
value|(CL_HTON32(0x01000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_CLIENT_REREG
value|(CL_HTON32(0x02000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_OTHER_LOCAL_CHANGES_NTC
value|(CL_HTON32(0x04000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_LINK_SPEED_WIDTH_PAIRS_TBL
value|(CL_HTON32(0x08000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_VEND_MADS
value|(CL_HTON32(0x10000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_MCAST_PKEY_TRAP_SUPPRESS
value|(CL_HTON32(0x20000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_MCAST_FDB_TOP
value|(CL_HTON32(0x40000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP_HAS_HIER_INFO
value|(CL_HTON32(0x80000000))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_SET_NODE_DESC_SUPPORTED
value|(CL_HTON16(0x0001))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_PORT_INFO_EXT_SUPPORTED
value|(CL_HTON16(0x0002))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_VIRT_SUPPORTED
value|(CL_HTON16(0x0004))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_SWITCH_PORT_STATE_TBL_SUPP
value|(CL_HTON16(0x0008))
end_define

begin_define
define|#
directive|define
name|IB_PORT_CAP2_IS_LINK_WIDTH_2X_SUPPORTED
value|(CL_HTON16(0x0010))
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_port_info_ext_t * NAME *	ib_port_info_ext_t * * DESCRIPTION *	IBA defined PortInfoExtended. (14.2.5.19) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_info_ext
block|{
name|ib_net32_t
name|cap_mask
decl_stmt|;
name|ib_net16_t
name|fec_mode_active
decl_stmt|;
name|ib_net16_t
name|fdr_fec_mode_sup
decl_stmt|;
name|ib_net16_t
name|fdr_fec_mode_enable
decl_stmt|;
name|ib_net16_t
name|edr_fec_mode_sup
decl_stmt|;
name|ib_net16_t
name|edr_fec_mode_enable
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|50
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_info_ext_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_define
define|#
directive|define
name|IB_PORT_EXT_NO_FEC_MODE_ACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|IB_PORT_EXT_FIRE_CODE_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0001))
end_define

begin_define
define|#
directive|define
name|IB_PORT_EXT_RS_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0002))
end_define

begin_define
define|#
directive|define
name|IB_PORT_EXT_LOW_LATENCY_RS_FEC_MODE_ACTIVE
value|(CL_HTON16(0x0003))
end_define

begin_define
define|#
directive|define
name|IB_PORT_EXT_CAP_IS_FEC_MODE_SUPPORTED
value|(CL_HTON32(0x00000001))
end_define

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_port_state * NAME *	ib_port_info_get_port_state * * DESCRIPTION *	Returns the port state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_port_state
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|state_info1
operator|&
name|IB_PORT_STATE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Port state. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_port_state * NAME *	ib_port_info_set_port_state * * DESCRIPTION *	Sets the port state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_port_state
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|port_state
parameter_list|)
block|{
name|p_pi
operator|->
name|state_info1
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|state_info1
operator|&
literal|0xF0
operator|)
operator||
name|port_state
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	port_state *		[in] Port state value to set. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_vl_cap * NAME *	ib_port_info_get_vl_cap * * DESCRIPTION *	Gets the VL Capability of a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_vl_cap
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_pi
operator|->
name|vl_cap
operator|>>
literal|4
operator|)
operator|&
literal|0x0F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	VL_CAP field * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_init_type * NAME *	ib_port_info_get_init_type * * DESCRIPTION *	Gets the init type of a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_init_type
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|vl_cap
operator|&
literal|0x0F
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	InitType field * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_op_vls * NAME *	ib_port_info_get_op_vls * * DESCRIPTION *	Gets the operational VLs on a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_op_vls
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_pi
operator|->
name|vl_enforce
operator|>>
literal|4
operator|)
operator|&
literal|0x0F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	OP_VLS field * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_op_vls * NAME *	ib_port_info_set_op_vls * * DESCRIPTION *	Sets the operational VLs on a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_op_vls
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|op_vls
parameter_list|)
block|{
name|p_pi
operator|->
name|vl_enforce
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|vl_enforce
operator|&
literal|0x0F
operator|)
operator||
operator|(
name|op_vls
operator|<<
literal|4
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	op_vls *		[in] Encoded operation VLs value. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_state_no_change * NAME *	ib_port_info_set_state_no_change * * DESCRIPTION *	Sets the port state fields to the value for "no change". * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_state_no_change
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
name|ib_port_info_set_port_state
argument_list|(
name|p_pi
argument_list|,
name|IB_LINK_NO_CHANGE
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|state_info2
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_sup * NAME *	ib_port_info_get_link_speed_sup * * DESCRIPTION *	Returns the encoded value for the link speed supported. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_sup
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|state_info1
operator|&
name|IB_PORT_LINK_SPEED_SUPPORTED_MASK
operator|)
operator|>>
name|IB_PORT_LINK_SPEED_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the encoded value for the link speed supported. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_link_speed_sup * NAME *	ib_port_info_set_link_speed_sup * * DESCRIPTION *	Given an integer of the supported link speed supported. *	Set the appropriate bits in state_info1 * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_link_speed_sup
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|speed
parameter_list|,
name|IN
name|ib_port_info_t
modifier|*
name|p_pi
parameter_list|)
block|{
name|p_pi
operator|->
name|state_info1
operator|=
operator|(
operator|~
name|IB_PORT_LINK_SPEED_SUPPORTED_MASK
operator|&
name|p_pi
operator|->
name|state_info1
operator|)
operator||
operator|(
name|IB_PORT_LINK_SPEED_SUPPORTED_MASK
operator|&
operator|(
name|speed
operator|<<
name|IB_PORT_LINK_SPEED_SHIFT
operator|)
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	speed *		[in] Supported Speeds Code. * *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_port_phys_state * NAME *	ib_port_info_get_port_phys_state * * DESCRIPTION *	Returns the encoded value for the port physical state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_port_phys_state
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|state_info2
operator|&
name|IB_PORT_PHYS_STATE_MASK
operator|)
operator|>>
name|IB_PORT_PHYS_STATE_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the encoded value for the port physical state. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_port_phys_state * NAME *	ib_port_info_set_port_phys_state * * DESCRIPTION *	Given an integer of the port physical state, *	Set the appropriate bits in state_info2 * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_port_phys_state
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|phys_state
parameter_list|,
name|IN
name|ib_port_info_t
modifier|*
name|p_pi
parameter_list|)
block|{
name|p_pi
operator|->
name|state_info2
operator|=
operator|(
operator|~
name|IB_PORT_PHYS_STATE_MASK
operator|&
name|p_pi
operator|->
name|state_info2
operator|)
operator||
operator|(
name|IB_PORT_PHYS_STATE_MASK
operator|&
operator|(
name|phys_state
operator|<<
name|IB_PORT_PHYS_STATE_SHIFT
operator|)
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	phys_state *		[in] port physical state. * *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_down_def_state * NAME *	ib_port_info_get_link_down_def_state * * DESCRIPTION *	Returns the link down default state. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_down_def_state
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|state_info2
operator|&
name|IB_PORT_LNKDWNDFTSTATE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	link down default state of the port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_link_down_def_state * NAME *	ib_port_info_set_link_down_def_state * * DESCRIPTION *	Sets the link down default state of the port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_link_down_def_state
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|link_dwn_state
parameter_list|)
block|{
name|p_pi
operator|->
name|state_info2
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|state_info2
operator|&
literal|0xF0
operator|)
operator||
name|link_dwn_state
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	link_dwn_state *		[in] Link down default state of the port. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_active * NAME *	ib_port_info_get_link_speed_active * * DESCRIPTION *	Returns the Link Speed Active value assigned to this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_active
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|link_speed
operator|&
name|IB_PORT_LINK_SPEED_ACTIVE_MASK
operator|)
operator|>>
name|IB_PORT_LINK_SPEED_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the link speed active value assigned to this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_define
define|#
directive|define
name|IB_LINK_WIDTH_ACTIVE_1X
value|1
end_define

begin_define
define|#
directive|define
name|IB_LINK_WIDTH_ACTIVE_4X
value|2
end_define

begin_define
define|#
directive|define
name|IB_LINK_WIDTH_ACTIVE_8X
value|4
end_define

begin_define
define|#
directive|define
name|IB_LINK_WIDTH_ACTIVE_12X
value|8
end_define

begin_define
define|#
directive|define
name|IB_LINK_WIDTH_ACTIVE_2X
value|16
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_ACTIVE_EXTENDED
value|0
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_ACTIVE_2_5
value|1
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_ACTIVE_5
value|2
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_ACTIVE_10
value|4
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_EXT_ACTIVE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_EXT_ACTIVE_14
value|1
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_EXT_ACTIVE_25
value|2
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_EXT_DISABLE
value|30
end_define

begin_define
define|#
directive|define
name|IB_LINK_SPEED_EXT_SET_LSES
value|31
end_define

begin_comment
comment|/* following v1 ver1.3 p984 */
end_comment

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_2_5_GBS
value|2
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_10_GBS
value|3
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_30_GBS
value|4
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_5_GBS
value|5
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_20_GBS
value|6
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_40_GBS
value|7
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_60_GBS
value|8
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_80_GBS
value|9
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_120_GBS
value|10
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_14_GBS
value|11
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_56_GBS
value|12
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_112_GBS
value|13
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_168_GBS
value|14
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_25_GBS
value|15
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_100_GBS
value|16
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_200_GBS
value|17
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_300_GBS
value|18
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_28_GBS
value|19
end_define

begin_define
define|#
directive|define
name|IB_PATH_RECORD_RATE_50_GBS
value|20
end_define

begin_define
define|#
directive|define
name|IB_MIN_RATE
value|IB_PATH_RECORD_RATE_2_5_GBS
end_define

begin_define
define|#
directive|define
name|IB_MAX_RATE
value|IB_PATH_RECORD_RATE_50_GBS
end_define

begin_function_decl
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_ext_active
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_compute_rate * NAME *	ib_port_info_compute_rate * * DESCRIPTION *	Returns the encoded value for the path rate. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_compute_rate
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|int
name|extended
parameter_list|)
block|{
name|uint8_t
name|rate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|extended
condition|)
block|{
switch|switch
condition|(
name|ib_port_info_get_link_speed_ext_active
argument_list|(
name|p_pi
argument_list|)
condition|)
block|{
case|case
name|IB_LINK_SPEED_EXT_ACTIVE_14
case|:
switch|switch
condition|(
name|p_pi
operator|->
name|link_width_active
condition|)
block|{
case|case
name|IB_LINK_WIDTH_ACTIVE_1X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_14_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_4X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_56_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_8X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_112_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_12X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_168_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_2X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_28_GBS
expr_stmt|;
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_14_GBS
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|IB_LINK_SPEED_EXT_ACTIVE_25
case|:
switch|switch
condition|(
name|p_pi
operator|->
name|link_width_active
condition|)
block|{
case|case
name|IB_LINK_WIDTH_ACTIVE_1X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_25_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_4X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_100_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_8X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_200_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_12X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_300_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_2X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_50_GBS
expr_stmt|;
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_25_GBS
expr_stmt|;
break|break;
block|}
break|break;
comment|/* IB_LINK_SPEED_EXT_ACTIVE_NONE and any others */
default|default:
break|break;
block|}
if|if
condition|(
name|rate
condition|)
return|return
name|rate
return|;
block|}
switch|switch
condition|(
name|ib_port_info_get_link_speed_active
argument_list|(
name|p_pi
argument_list|)
condition|)
block|{
case|case
name|IB_LINK_SPEED_ACTIVE_2_5
case|:
switch|switch
condition|(
name|p_pi
operator|->
name|link_width_active
condition|)
block|{
case|case
name|IB_LINK_WIDTH_ACTIVE_1X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_2_5_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_4X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_10_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_8X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_20_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_12X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_30_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_2X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_5_GBS
expr_stmt|;
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_2_5_GBS
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|IB_LINK_SPEED_ACTIVE_5
case|:
switch|switch
condition|(
name|p_pi
operator|->
name|link_width_active
condition|)
block|{
case|case
name|IB_LINK_WIDTH_ACTIVE_1X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_5_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_4X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_20_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_8X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_40_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_12X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_60_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_2X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_10_GBS
expr_stmt|;
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_5_GBS
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|IB_LINK_SPEED_ACTIVE_10
case|:
switch|switch
condition|(
name|p_pi
operator|->
name|link_width_active
condition|)
block|{
case|case
name|IB_LINK_WIDTH_ACTIVE_1X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_10_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_4X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_40_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_8X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_80_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_12X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_120_GBS
expr_stmt|;
break|break;
case|case
name|IB_LINK_WIDTH_ACTIVE_2X
case|:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_20_GBS
expr_stmt|;
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_10_GBS
expr_stmt|;
break|break;
block|}
break|break;
default|default:
name|rate
operator|=
name|IB_PATH_RECORD_RATE_2_5_GBS
expr_stmt|;
break|break;
block|}
return|return
name|rate
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	extended *		[in] Indicates whether or not to use extended link speeds. * * RETURN VALUES *	Returns the encoded value for the link speed supported. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_path_get_ipd * NAME *	ib_path_get_ipd * * DESCRIPTION *	Returns the encoded value for the inter packet delay. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_path_get_ipd
parameter_list|(
name|IN
name|uint8_t
name|local_link_width_supported
parameter_list|,
name|IN
name|uint8_t
name|path_rec_rate
parameter_list|)
block|{
name|uint8_t
name|ipd
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|local_link_width_supported
condition|)
block|{
comment|/* link_width_supported = 1: 1x */
case|case
literal|1
case|:
break|break;
comment|/* link_width_supported = 3: 1x or 4x */
case|case
literal|3
case|:
switch|switch
condition|(
name|path_rec_rate
operator|&
literal|0x3F
condition|)
block|{
case|case
name|IB_PATH_RECORD_RATE_2_5_GBS
case|:
name|ipd
operator|=
literal|3
expr_stmt|;
break|break;
default|default:
break|break;
block|}
break|break;
comment|/* link_width_supported = 11: 1x or 4x or 12x */
case|case
literal|11
case|:
switch|switch
condition|(
name|path_rec_rate
operator|&
literal|0x3F
condition|)
block|{
case|case
name|IB_PATH_RECORD_RATE_2_5_GBS
case|:
name|ipd
operator|=
literal|11
expr_stmt|;
break|break;
case|case
name|IB_PATH_RECORD_RATE_10_GBS
case|:
name|ipd
operator|=
literal|2
expr_stmt|;
break|break;
default|default:
break|break;
block|}
break|break;
default|default:
break|break;
block|}
return|return
name|ipd
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	local_link_width_supported *		[in] link with supported for this port * *	path_rec_rate *		[in] rate field of the path record * * RETURN VALUES *	Returns the ipd * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_mtu_cap * NAME *	ib_port_info_get_mtu_cap * * DESCRIPTION *	Returns the encoded value for the maximum MTU supported by this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_mtu_cap
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|mtu_cap
operator|&
literal|0x0F
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the encooded value for the maximum MTU supported by this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_neighbor_mtu * NAME *	ib_port_info_get_neighbor_mtu * * DESCRIPTION *	Returns the encoded value for the neighbor MTU supported by this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_neighbor_mtu
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|mtu_smsl
operator|&
literal|0xF0
operator|)
operator|>>
literal|4
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the encoded value for the neighbor MTU at this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_neighbor_mtu * NAME *	ib_port_info_set_neighbor_mtu * * DESCRIPTION *	Sets the Neighbor MTU value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_neighbor_mtu
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|mtu
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|mtu
operator|<=
literal|5
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|mtu
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|mtu_smsl
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|mtu_smsl
operator|&
literal|0x0F
operator|)
operator||
operator|(
name|mtu
operator|<<
literal|4
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	mtu *		[in] Encoded MTU value to set * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_master_smsl * NAME *	ib_port_info_get_master_smsl * * DESCRIPTION *	Returns the encoded value for the Master SMSL at this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_master_smsl
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|mtu_smsl
operator|&
literal|0x0F
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the encoded value for the Master SMSL at this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_master_smsl * NAME *	ib_port_info_set_master_smsl * * DESCRIPTION *	Sets the Master SMSL value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_master_smsl
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|smsl
parameter_list|)
block|{
name|p_pi
operator|->
name|mtu_smsl
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|mtu_smsl
operator|&
literal|0xF0
operator|)
operator||
name|smsl
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	mtu *		[in] Encoded Master SMSL value to set * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_timeout * NAME *	ib_port_info_set_timeout * * DESCRIPTION *	Sets the encoded subnet timeout value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_timeout
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|timeout
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|timeout
operator|<=
literal|0x1F
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|subnet_timeout
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0xE0
operator|)
operator||
operator|(
name|timeout
operator|&
literal|0x1F
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	timeout *		[in] Encoded timeout value to set * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_client_rereg * NAME *	ib_port_info_set_client_rereg * * DESCRIPTION *	Sets the encoded client reregistration bit value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_client_rereg
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|client_rereg
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|client_rereg
operator|<=
literal|0x1
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|subnet_timeout
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0x7F
operator|)
operator||
operator|(
name|client_rereg
operator|<<
literal|7
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	client_rereg *		[in] Client reregistration value to set (either 1 or 0). * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_mcast_pkey_trap_suppress * NAME *	ib_port_info_set_mcast_pkey_trap_suppress * * DESCRIPTION *	Sets the encoded multicast pkey trap suppression enabled bit value *	in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_mcast_pkey_trap_suppress
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|trap_suppress
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|trap_suppress
operator|<=
literal|0x1
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|subnet_timeout
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0xBF
operator|)
operator||
operator|(
name|trap_suppress
operator|<<
literal|6
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	trap_suppress *		[in] Multicast pkey trap suppression enabled value to set *		     (either 1 or 0). * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_timeout * NAME *	ib_port_info_get_timeout * * DESCRIPTION *	Gets the encoded subnet timeout value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_timeout
parameter_list|(
name|IN
name|ib_port_info_t
specifier|const
modifier|*
name|p_pi
parameter_list|)
block|{
return|return
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0x1F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	The encoded timeout value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_ext_active * NAME *	ib_port_info_get_link_speed_ext_active * * DESCRIPTION *	Gets the encoded LinkSpeedExtActive value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_ext_active
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_pi
operator|->
name|link_speed_ext
operator|&
literal|0xF0
operator|)
operator|>>
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	The encoded LinkSpeedExtActive value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_ext_sup * NAME *	ib_port_info_get_link_speed_ext_sup * * DESCRIPTION *	Returns the encoded value for the link speed extended supported. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_ext_sup
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
name|p_pi
operator|->
name|link_speed_ext
operator|&
literal|0x0F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	The encoded LinkSpeedExtSupported value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_ext_enabled * NAME *	ib_port_info_get_link_speed_ext_enabled * * DESCRIPTION *	Gets the encoded LinkSpeedExtEnabled value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_ext_enabled
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
name|p_pi
operator|->
name|link_speed_ext_enabled
operator|&
literal|0x1F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	The encoded LinkSpeedExtEnabled value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_link_speed_ext_enabled * NAME *	ib_port_info_set_link_speed_ext_enabled * * DESCRIPTION *	Sets the link speed extended enabled value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_link_speed_ext_enabled
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|link_speed_ext_enabled
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|link_speed_ext_enabled
operator|<=
literal|0x1F
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|link_speed_ext_enabled
operator|=
name|link_speed_ext_enabled
operator|&
literal|0x1F
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	link_speed_ext_enabled *		[in] link speed extehded enabled value to set. * * RETURN VALUES *	The encoded LinkSpeedExtEnabled value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_resp_time_value * NAME *	ib_port_info_get_resp_time_value * * DESCRIPTION *	Gets the encoded resp time value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_resp_time_value
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
name|p_pi
operator|->
name|resp_time_value
operator|&
literal|0x1F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	The encoded resp time value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_client_rereg * NAME *	ib_port_info_get_client_rereg * * DESCRIPTION *	Gets the encoded client reregistration bit value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_client_rereg
parameter_list|(
name|IN
name|ib_port_info_t
specifier|const
modifier|*
name|p_pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0x80
operator|)
operator|>>
literal|7
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Client reregistration value (either 1 or 0). * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_mcast_pkey_trap_suppress * NAME *	ib_port_info_get_mcast_pkey_trap_suppress * * DESCRIPTION *	Gets the encoded multicast pkey trap suppression enabled bit value *	in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_mcast_pkey_trap_suppress
parameter_list|(
name|IN
name|ib_port_info_t
specifier|const
modifier|*
name|p_pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_pi
operator|->
name|subnet_timeout
operator|&
literal|0x40
operator|)
operator|>>
literal|6
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Multicast PKey trap suppression enabled value (either 1 or 0). * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_hoq_lifetime * NAME *	ib_port_info_set_hoq_lifetime * * DESCRIPTION *	Sets the Head of Queue Lifetime for which a packet can live in the head *  of VL queue * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_hoq_lifetime
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|hoq_life
parameter_list|)
block|{
name|p_pi
operator|->
name|vl_stall_life
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|hoq_life
operator|&
literal|0x1f
operator|)
operator||
operator|(
name|p_pi
operator|->
name|vl_stall_life
operator|&
literal|0xe0
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	hoq_life *		[in] Encoded lifetime value to set * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_hoq_lifetime * NAME *	ib_port_info_get_hoq_lifetime * * DESCRIPTION *	Gets the Head of Queue Lifetime for which a packet can live in the head *  of VL queue * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_hoq_lifetime
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|vl_stall_life
operator|&
literal|0x1f
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *     Encoded lifetime value * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_vl_stall_count * NAME *	ib_port_info_set_vl_stall_count * * DESCRIPTION *	Sets the VL Stall Count which define the number of contiguous *  HLL (hoq) drops that will put the VL into stalled mode. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_vl_stall_count
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|vl_stall_count
parameter_list|)
block|{
name|p_pi
operator|->
name|vl_stall_life
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|vl_stall_life
operator|&
literal|0x1f
operator|)
operator||
operator|(
operator|(
name|vl_stall_count
operator|<<
literal|5
operator|)
operator|&
literal|0xe0
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	vl_stall_count *		[in] value to set * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_vl_stall_count * NAME *	ib_port_info_get_vl_stall_count * * DESCRIPTION *	Gets the VL Stall Count which define the number of contiguous *  HLL (hoq) drops that will put the VL into stalled mode * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_vl_stall_count
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|vl_stall_life
operator|&
literal|0xe0
argument_list|)
operator|>>
literal|5
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *     vl stall count * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_lmc * NAME *	ib_port_info_get_lmc * * DESCRIPTION *	Returns the LMC value assigned to this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_lmc
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|mkey_lmc
operator|&
name|IB_PORT_LMC_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the LMC value assigned to this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_lmc * NAME *	ib_port_info_set_lmc * * DESCRIPTION *	Sets the LMC value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_lmc
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|lmc
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|lmc
operator|<=
name|IB_PORT_LMC_MAX
argument_list|)
expr_stmt|;
name|p_pi
operator|->
name|mkey_lmc
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|mkey_lmc
operator|&
literal|0xF8
operator|)
operator||
name|lmc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	lmc *		[in] LMC value to set, must be less than 7. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_link_speed_enabled * NAME *	ib_port_info_get_link_speed_enabled * * DESCRIPTION *	Returns the link speed enabled value assigned to this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_link_speed_enabled
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|link_speed
operator|&
name|IB_PORT_LINK_SPEED_ENABLED_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Port state. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_link_speed_enabled * NAME *	ib_port_info_set_link_speed_enabled * * DESCRIPTION *	Sets the link speed enabled value in the PortInfo attribute. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_link_speed_enabled
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|link_speed_enabled
parameter_list|)
block|{
name|p_pi
operator|->
name|link_speed
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|link_speed
operator|&
literal|0xF0
operator|)
operator||
name|link_speed_enabled
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	link_speed_enabled *		[in] link speed enabled value to set. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_mpb * NAME *	ib_port_info_get_mpb * * DESCRIPTION *	Returns the M_Key protect bits assigned to this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_mpb
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|mkey_lmc
operator|&
name|IB_PORT_MPB_MASK
operator|)
operator|>>
name|IB_PORT_MPB_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ni *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the M_Key protect bits assigned to this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_mpb * NAME *	ib_port_info_set_mpb * * DESCRIPTION *	Set the M_Key protect bits of this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_mpb
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
name|p_pi
parameter_list|,
name|IN
name|uint8_t
name|mpb
parameter_list|)
block|{
name|p_pi
operator|->
name|mkey_lmc
operator|=
operator|(
operator|~
name|IB_PORT_MPB_MASK
operator|&
name|p_pi
operator|->
name|mkey_lmc
operator|)
operator||
operator|(
name|IB_PORT_MPB_MASK
operator|&
operator|(
name|mpb
operator|<<
name|IB_PORT_MPB_SHIFT
operator|)
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	mpb *		[in] M_Key protect bits *	p_ni *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_local_phy_err_thd * NAME *	ib_port_info_get_local_phy_err_thd * * DESCRIPTION *	Returns the Phy Link Threshold * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_local_phy_err_thd
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_pi
operator|->
name|error_threshold
operator|&
literal|0xF0
operator|)
operator|>>
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the Phy Link error threshold assigned to this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_overrun_err_thd * NAME *	ib_port_info_get_local_overrun_err_thd * * DESCRIPTION *	Returns the Credits Overrun Errors Threshold * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_port_info_get_overrun_err_thd
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
call|(
name|uint8_t
call|)
argument_list|(
name|p_pi
operator|->
name|error_threshold
operator|&
literal|0x0F
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	Returns the Credits Overrun errors threshold assigned to this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_phy_and_overrun_err_thd * NAME *	ib_port_info_set_phy_and_overrun_err_thd * * DESCRIPTION *	Sets the Phy Link and Credits Overrun Errors Threshold * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_phy_and_overrun_err_thd
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
name|uint8_t
name|phy_threshold
parameter_list|,
name|IN
name|uint8_t
name|overrun_threshold
parameter_list|)
block|{
name|p_pi
operator|->
name|error_threshold
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
operator|(
name|phy_threshold
operator|&
literal|0x0F
operator|)
operator|<<
literal|4
operator|)
operator||
operator|(
name|overrun_threshold
operator|&
literal|0x0F
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * *	phy_threshold *		[in] Physical Link Errors Threshold above which Trap 129 is generated * *  overrun_threshold *     [in] Credits overrun Errors Threshold above which Trap 129 is generated * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_get_m_key * NAME *	ib_port_info_get_m_key * * DESCRIPTION *	Gets the M_Key * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|OSM_API
name|ib_port_info_get_m_key
parameter_list|(
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|)
block|{
return|return
name|p_pi
operator|->
name|m_key
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. * * RETURN VALUES *	M_Key. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_port_info_set_m_key * NAME *	ib_port_info_set_m_key * * DESCRIPTION *	Sets the M_Key value * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_port_info_set_m_key
parameter_list|(
name|IN
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
name|ib_net64_t
name|m_key
parameter_list|)
block|{
name|p_pi
operator|->
name|m_key
operator|=
name|m_key
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pi *		[in] Pointer to a PortInfo attribute. *	m_key *		[in] M_Key value. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_mlnx_ext_port_info_t * NAME *	ib_mlnx_ext_port_info_t * * DESCRIPTION *	Mellanox ExtendedPortInfo (Vendor specific SM class attribute). * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_mlnx_ext_port_info
block|{
name|uint8_t
name|resvd1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|state_change_enable
decl_stmt|;
name|uint8_t
name|resvd2
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|link_speed_supported
decl_stmt|;
name|uint8_t
name|resvd3
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|link_speed_enabled
decl_stmt|;
name|uint8_t
name|resvd4
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|link_speed_active
decl_stmt|;
name|uint8_t
name|resvd5
index|[
literal|48
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_mlnx_ext_port_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_define
define|#
directive|define
name|FDR10
value|0x01
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|ib_svc_name_t
index|[
literal|64
index|]
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_service_record
block|{
name|ib_net64_t
name|service_id
decl_stmt|;
name|ib_gid_t
name|service_gid
decl_stmt|;
name|ib_net16_t
name|service_pkey
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_net32_t
name|service_lease
decl_stmt|;
name|uint8_t
name|service_key
index|[
literal|16
index|]
decl_stmt|;
name|ib_svc_name_t
name|service_name
decl_stmt|;
name|uint8_t
name|service_data8
index|[
literal|16
index|]
decl_stmt|;
name|ib_net16_t
name|service_data16
index|[
literal|8
index|]
decl_stmt|;
name|ib_net32_t
name|service_data32
index|[
literal|4
index|]
decl_stmt|;
name|ib_net64_t
name|service_data64
index|[
literal|2
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_service_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_portinfo_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|uint8_t
name|options
decl_stmt|;
name|ib_port_info_t
name|port_info
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_portinfo_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_portinfoext_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|uint8_t
name|options
decl_stmt|;
name|ib_port_info_ext_t
name|port_info_ext
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_portinfoext_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_link_record
block|{
name|ib_net16_t
name|from_lid
decl_stmt|;
name|uint8_t
name|from_port_num
decl_stmt|;
name|uint8_t
name|to_port_num
decl_stmt|;
name|ib_net16_t
name|to_lid
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_link_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sminfo_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|uint16_t
name|resv0
decl_stmt|;
name|ib_sm_info_t
name|sm_info
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|7
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sminfo_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_lft_record_t * NAME *	ib_lft_record_t * * DESCRIPTION *	IBA defined LinearForwardingTableRecord (15.2.5.6) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_lft_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|ib_net16_t
name|block_num
decl_stmt|;
name|uint32_t
name|resv0
decl_stmt|;
name|uint8_t
name|lft
index|[
literal|64
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_lft_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_mft_record_t * NAME *	ib_mft_record_t * * DESCRIPTION *	IBA defined MulticastForwardingTableRecord (15.2.5.8) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_mft_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|ib_net16_t
name|position_block_num
decl_stmt|;
name|uint32_t
name|resv0
decl_stmt|;
name|ib_net16_t
name|mft
index|[
name|IB_MCAST_BLOCK_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_mft_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_switch_info_t * NAME *	ib_switch_info_t * * DESCRIPTION *	IBA defined SwitchInfo. (14.2.5.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_switch_info
block|{
name|ib_net16_t
name|lin_cap
decl_stmt|;
name|ib_net16_t
name|rand_cap
decl_stmt|;
name|ib_net16_t
name|mcast_cap
decl_stmt|;
name|ib_net16_t
name|lin_top
decl_stmt|;
name|uint8_t
name|def_port
decl_stmt|;
name|uint8_t
name|def_mcast_pri_port
decl_stmt|;
name|uint8_t
name|def_mcast_not_port
decl_stmt|;
name|uint8_t
name|life_state
decl_stmt|;
name|ib_net16_t
name|lids_per_port
decl_stmt|;
name|ib_net16_t
name|enforce_cap
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|resvd
decl_stmt|;
name|ib_net16_t
name|mcast_top
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_switch_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_switch_info_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|uint16_t
name|resv0
decl_stmt|;
name|ib_switch_info_t
name|switch_info
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_switch_info_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_define
define|#
directive|define
name|IB_SWITCH_PSC
value|0x04
end_define

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_get_state_change * NAME *	ib_switch_info_get_state_change * * DESCRIPTION *	Returns the value of the state change flag. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_switch_info_get_state_change
parameter_list|(
name|IN
specifier|const
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_si
operator|->
name|life_state
operator|&
name|IB_SWITCH_PSC
operator|)
operator|==
name|IB_SWITCH_PSC
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. * * RETURN VALUES *	Returns the value of the state change flag. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_clear_state_change * NAME *	ib_switch_info_clear_state_change * * DESCRIPTION *	Clears the switch's state change bit. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_switch_info_clear_state_change
parameter_list|(
name|IN
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|)
block|{
name|p_si
operator|->
name|life_state
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|p_si
operator|->
name|life_state
operator|&
literal|0xFB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_state_change_set * NAME *	ib_switch_info_state_change_set * * DESCRIPTION *	Clears the switch's state change bit. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_switch_info_state_change_set
parameter_list|(
name|IN
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|)
block|{
name|p_si
operator|->
name|life_state
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_si
operator|->
name|life_state
operator|&
operator|~
name|IB_SWITCH_PSC
operator|)
operator||
name|IB_SWITCH_PSC
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_get_opt_sl2vlmapping * NAME *	ib_switch_info_get_state_opt_sl2vlmapping * * DESCRIPTION *       Returns the value of the optimized SLtoVLMapping programming flag. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_switch_info_get_opt_sl2vlmapping
parameter_list|(
name|IN
specifier|const
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_si
operator|->
name|life_state
operator|&
literal|0x01
operator|)
operator|==
literal|0x01
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. * * RETURN VALUES *	Returns the value of the optimized SLtoVLMapping programming flag. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_set_life_time * NAME *	ib_switch_info_set_life_time * * DESCRIPTION *	Sets the value of LifeTimeValue. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_switch_info_set_life_time
parameter_list|(
name|IN
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|life_time_val
parameter_list|)
block|{
name|p_si
operator|->
name|life_state
operator|=
operator|(
name|p_si
operator|->
name|life_state
operator|&
literal|0x1f
operator|)
operator||
operator|(
name|life_time_val
operator|<<
literal|3
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. *	life_time_val *		[in] LiveTimeValue. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_switch_info_is_enhanced_port0 * NAME *	ib_switch_info_is_enhanced_port0 * * DESCRIPTION *	Returns TRUE if the enhancedPort0 bit is on (meaning the switch *  port zero supports enhanced functions). *  Returns FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_switch_info_is_enhanced_port0
parameter_list|(
name|IN
specifier|const
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_si
operator|->
name|flags
operator|&
literal|0x08
operator|)
operator|==
literal|0x08
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_si *		[in] Pointer to a SwitchInfo attribute. * * RETURN VALUES *	Returns TRUE if the switch supports enhanced port 0. FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_guid_info_t * NAME *	ib_guid_info_t * * DESCRIPTION *	IBA defined GuidInfo. (14.2.5.5) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|GUID_TABLE_MAX_ENTRIES
value|8
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_guid_info
block|{
name|ib_net64_t
name|guid
index|[
name|GUID_TABLE_MAX_ENTRIES
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_guid_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_guidinfo_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
name|uint8_t
name|block_num
decl_stmt|;
name|uint8_t
name|resv
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|ib_guid_info_t
name|guid_info
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_guidinfo_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_define
define|#
directive|define
name|IB_MULTIPATH_MAX_GIDS
value|11
end_define

begin_comment
comment|/* Support max that can fit into first MAD (for now) */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_multipath_rec_t
block|{
name|ib_net32_t
name|hop_flow_raw
decl_stmt|;
name|uint8_t
name|tclass
decl_stmt|;
name|uint8_t
name|num_path
decl_stmt|;
name|ib_net16_t
name|pkey
decl_stmt|;
name|ib_net16_t
name|qos_class_sl
decl_stmt|;
name|uint8_t
name|mtu
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|pkt_life
decl_stmt|;
name|uint8_t
name|service_id_8msb
decl_stmt|;
name|uint8_t
name|independence
decl_stmt|;
comment|/* formerly resv2 */
name|uint8_t
name|sgid_count
decl_stmt|;
name|uint8_t
name|dgid_count
decl_stmt|;
name|uint8_t
name|service_id_56lsb
index|[
literal|7
index|]
decl_stmt|;
name|ib_gid_t
name|gids
index|[
name|IB_MULTIPATH_MAX_GIDS
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_multipath_rec_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *       hop_flow_raw *               Global routing parameters: hop count, flow label and raw bit. * *       tclass *               Another global routing parameter. * *       num_path *     Reversible path - 1 bit to say if path is reversible. *               num_path [6:0] In queries, maximum number of paths to return. *               In responses, undefined. * *       pkey *               Partition key (P_Key) to use on this path. * *       qos_class_sl *               QoS class and service level to use on this path. * *       mtu *               MTU and MTU selector fields to use on this path *       rate *               Rate and rate selector fields to use on this path. * *       pkt_life *               Packet lifetime * *	service_id_8msb *		8 most significant bits of Service ID * *	service_id_56lsb *		56 least significant bits of Service ID * *       preference *               Indicates the relative merit of this path versus other path *               records returned from the SA.  Lower numbers are better. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_num_path * NAME *       ib_multipath_rec_num_path * * DESCRIPTION *       Get max number of paths to return. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_num_path
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
name|p_rec
operator|->
name|num_path
operator|&
literal|0x7F
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Maximum number of paths to return for each unique SGID_DGID combination. * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_set_sl * NAME *	ib_multipath_rec_set_sl * * DESCRIPTION *	Set path service level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_multipath_rec_set_sl
parameter_list|(
name|IN
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|sl
parameter_list|)
block|{
name|p_rec
operator|->
name|qos_class_sl
operator|=
operator|(
name|p_rec
operator|->
name|qos_class_sl
operator|&
name|CL_HTON16
argument_list|(
name|IB_MULTIPATH_REC_QOS_CLASS_MASK
argument_list|)
operator|)
operator||
name|cl_hton16
argument_list|(
name|sl
operator|&
name|IB_MULTIPATH_REC_SL_MASK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the MultiPath record object. * *	sl *		[in] Service level to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_sl * NAME *       ib_multipath_rec_sl * * DESCRIPTION *       Get multipath service level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_sl
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|cl_ntoh16
argument_list|(
name|p_rec
operator|->
name|qos_class_sl
argument_list|)
operator|)
operator|&
name|IB_MULTIPATH_REC_SL_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *	SL. * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_set_qos_class * NAME *	ib_multipath_rec_set_qos_class * * DESCRIPTION *	Set path QoS class. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_multipath_rec_set_qos_class
parameter_list|(
name|IN
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|,
name|IN
specifier|const
name|uint16_t
name|qos_class
parameter_list|)
block|{
name|p_rec
operator|->
name|qos_class_sl
operator|=
operator|(
name|p_rec
operator|->
name|qos_class_sl
operator|&
name|CL_HTON16
argument_list|(
name|IB_MULTIPATH_REC_SL_MASK
argument_list|)
operator|)
operator||
name|cl_hton16
argument_list|(
name|qos_class
operator|<<
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the MultiPath record object. * *	qos_class *		[in] QoS class to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_qos_class * NAME *	ib_multipath_rec_qos_class * * DESCRIPTION *	Get QoS class. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|OSM_API
name|ib_multipath_rec_qos_class
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
name|cl_ntoh16
argument_list|(
name|p_rec
operator|->
name|qos_class_sl
argument_list|)
operator|>>
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the MultiPath record object. * * RETURN VALUES *	QoS class of the MultiPath record. * * NOTES * * SEE ALSO *	ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_mtu * NAME *       ib_multipath_rec_mtu * * DESCRIPTION *       Get encoded path MTU. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_mtu
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|mtu
operator|&
name|IB_MULTIPATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Encoded path MTU. *               1: 256 *               2: 512 *               3: 1024 *               4: 2048 *               5: 4096 *               others: reserved * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_mtu_sel * NAME *       ib_multipath_rec_mtu_sel * * DESCRIPTION *       Get encoded multipath MTU selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_mtu_sel
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|mtu
operator|&
name|IB_MULTIPATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Encoded path MTU selector value (for queries). *               0: greater than MTU specified *               1: less than MTU specified *               2: exactly the MTU specified *               3: largest MTU available * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_rate * NAME *	ib_multipath_rec_rate * * DESCRIPTION *	Get encoded multipath rate. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_rate
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|rate
operator|&
name|IB_MULTIPATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the multipath record object. * * RETURN VALUES *	Encoded multipath rate. *		2: 2.5 Gb/sec. *		3: 10 Gb/sec. *		4: 30 Gb/sec. *		5: 5 Gb/sec. *		6: 20 Gb/sec. *		7: 40 Gb/sec. *		8: 60 Gb/sec. *		9: 80 Gb/sec. *		10: 120 Gb/sec. *		11: 14 Gb/sec. *		12: 56 Gb/sec. *		13: 112 Gb/sec. *		14: 168 Gb/sec. *		15: 25 Gb/sec. *		16: 100 Gb/sec. *		17: 200 Gb/sec. *		18: 300 Gb/sec. *               others: reserved * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_rate_sel * NAME *       ib_multipath_rec_rate_sel * * DESCRIPTION *       Get encoded multipath rate selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_rate_sel
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|rate
operator|&
name|IB_MULTIPATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Encoded path rate selector value (for queries). *               0: greater than rate specified *               1: less than rate specified *               2: exactly the rate specified *               3: largest rate available * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_pkt_life * NAME *       ib_multipath_rec_pkt_life * * DESCRIPTION *       Get encoded multipath pkt_life. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_pkt_life
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_rec
operator|->
name|pkt_life
operator|&
name|IB_MULTIPATH_REC_BASE_MASK
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Encoded multipath pkt_life = 4.096 usec * 2 ** PacketLifeTime. * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_pkt_life_sel * NAME *       ib_multipath_rec_pkt_life_sel * * DESCRIPTION *       Get encoded multipath pkt_lifetime selector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_multipath_rec_pkt_life_sel
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|p_rec
operator|->
name|pkt_life
operator|&
name|IB_MULTIPATH_REC_SELECTOR_MASK
operator|)
operator|>>
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *       p_rec *               [in] Pointer to the multipath record object. * * RETURN VALUES *       Encoded path pkt_lifetime selector value (for queries). *               0: greater than rate specified *               1: less than rate specified *               2: exactly the rate specified *               3: smallest packet lifetime available * * NOTES * * SEE ALSO *       ib_multipath_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_multipath_rec_service_id * NAME *	ib_multipath_rec_service_id * * DESCRIPTION *	Get multipath service id. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|OSM_API
name|ib_multipath_rec_service_id
parameter_list|(
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_rec
parameter_list|)
block|{
union|union
block|{
name|ib_net64_t
name|sid
decl_stmt|;
name|uint8_t
name|sid_arr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|sid_union
union|;
name|sid_union
operator|.
name|sid_arr
index|[
literal|0
index|]
operator|=
name|p_rec
operator|->
name|service_id_8msb
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|sid_union
operator|.
name|sid_arr
index|[
literal|1
index|]
argument_list|,
name|p_rec
operator|->
name|service_id_56lsb
argument_list|,
literal|7
argument_list|)
expr_stmt|;
return|return
name|sid_union
operator|.
name|sid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rec *		[in] Pointer to the multipath record object. * * RETURN VALUES *	Service ID * * NOTES * * SEE ALSO *	ib_multipath_rec_t *********/
end_comment

begin_define
define|#
directive|define
name|IB_NUM_PKEY_ELEMENTS_IN_BLOCK
value|32
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_pkey_table_t * NAME *	ib_pkey_table_t * * DESCRIPTION *	IBA defined PKey table. (14.2.5.7) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_pkey_table
block|{
name|ib_net16_t
name|pkey_entry
index|[
name|IB_NUM_PKEY_ELEMENTS_IN_BLOCK
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_pkey_table_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_pkey_table_record_t * NAME *	ib_pkey_table_record_t * * DESCRIPTION *	IBA defined P_Key Table Record for SA Query. (15.2.5.11) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_pkey_table_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
comment|// for CA: lid of port, for switch lid of port 0
name|ib_net16_t
name|block_num
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
comment|// for switch: port number, for CA: reserved
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|ib_pkey_table_t
name|pkey_tbl
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_pkey_table_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_define
define|#
directive|define
name|IB_DROP_VL
value|15
end_define

begin_define
define|#
directive|define
name|IB_MAX_NUM_VLS
value|16
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_slvl_table_t * NAME *	ib_slvl_table_t * * DESCRIPTION *	IBA defined SL2VL Mapping Table Attribute. (14.2.5.8) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_slvl_table
block|{
name|uint8_t
name|raw_vl_by_sl
index|[
name|IB_MAX_NUM_VLS
operator|/
literal|2
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_slvl_table_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_slvl_table_record_t * NAME *	ib_slvl_table_record_t * * DESCRIPTION *	IBA defined SL to VL Mapping Table Record for SA Query. (15.2.5.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_slvl_table_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
comment|// for CA: lid of port, for switch lid of port 0
name|uint8_t
name|in_port_num
decl_stmt|;
comment|// reserved for CAs
name|uint8_t
name|out_port_num
decl_stmt|;
comment|// reserved for CAs
name|uint32_t
name|resv
decl_stmt|;
name|ib_slvl_table_t
name|slvl_tbl
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_slvl_table_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_slvl_table_set * NAME *	ib_slvl_table_set * * DESCRIPTION *	Set slvl table entry. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_slvl_table_set
parameter_list|(
name|IN
name|ib_slvl_table_t
modifier|*
name|p_slvl_tbl
parameter_list|,
name|IN
name|uint8_t
name|sl_index
parameter_list|,
name|IN
name|uint8_t
name|vl
parameter_list|)
block|{
name|uint8_t
name|idx
init|=
name|sl_index
operator|/
literal|2
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|vl
operator|<=
literal|15
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|sl_index
operator|<=
literal|15
argument_list|)
expr_stmt|;
if|if
condition|(
name|sl_index
operator|%
literal|2
condition|)
comment|/* this is an odd sl. Need to update the ls bits */
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|=
operator|(
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|&
literal|0xF0
operator|)
operator||
name|vl
expr_stmt|;
else|else
comment|/* this is an even sl. Need to update the ms bits */
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|=
operator|(
name|vl
operator|<<
literal|4
operator|)
operator||
operator|(
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|&
literal|0x0F
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_slvl_tbl *		[in] pointer to ib_slvl_table_t object. * *	sl_index *		[in] the sl index in the table to be updated. * *	vl *		[in] the vl value to update for that sl. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	ib_slvl_table_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_slvl_table_get * NAME *	ib_slvl_table_get * * DESCRIPTION *	Get slvl table entry. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_slvl_table_get
parameter_list|(
name|IN
specifier|const
name|ib_slvl_table_t
modifier|*
name|p_slvl_tbl
parameter_list|,
name|IN
name|uint8_t
name|sl_index
parameter_list|)
block|{
name|uint8_t
name|idx
init|=
name|sl_index
operator|/
literal|2
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|sl_index
operator|<=
literal|15
argument_list|)
expr_stmt|;
if|if
condition|(
name|sl_index
operator|%
literal|2
condition|)
comment|/* this is an odd sl. Need to return the ls bits. */
return|return
operator|(
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|&
literal|0x0F
operator|)
return|;
else|else
comment|/* this is an even sl. Need to return the ms bits. */
return|return
operator|(
operator|(
name|p_slvl_tbl
operator|->
name|raw_vl_by_sl
index|[
name|idx
index|]
operator|&
literal|0xF0
operator|)
operator|>>
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_slvl_tbl *		[in] pointer to ib_slvl_table_t object. * *	sl_index *		[in] the sl index in the table whose value should be returned. * * RETURN VALUES *	vl for the requested sl_index. * * NOTES * * SEE ALSO *	ib_slvl_table_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_vl_arb_element_t * NAME *	ib_vl_arb_element_t * * DESCRIPTION *	IBA defined VL Arbitration Table Element. (14.2.5.9) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_vl_arb_element
block|{
name|uint8_t
name|vl
decl_stmt|;
name|uint8_t
name|weight
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_vl_arb_element_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_define
define|#
directive|define
name|IB_NUM_VL_ARB_ELEMENTS_IN_BLOCK
value|32
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_vl_arb_table_t * NAME *	ib_vl_arb_table_t * * DESCRIPTION *	IBA defined VL Arbitration Table. (14.2.5.9) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_vl_arb_table
block|{
name|ib_vl_arb_element_t
name|vl_entry
index|[
name|IB_NUM_VL_ARB_ELEMENTS_IN_BLOCK
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_vl_arb_table_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_vl_arb_table_record_t * NAME *	ib_vl_arb_table_record_t * * DESCRIPTION *	IBA defined VL Arbitration Table Record for SA Query. (15.2.5.9) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_vl_arb_table_record
block|{
name|ib_net16_t
name|lid
decl_stmt|;
comment|// for CA: lid of port, for switch lid of port 0
name|uint8_t
name|port_num
decl_stmt|;
name|uint8_t
name|block_num
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|ib_vl_arb_table_t
name|vl_arb_tbl
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_vl_arb_table_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/************/
end_comment

begin_comment
comment|/*  *	Global route header information received with unreliable datagram messages  */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_grh
block|{
name|ib_net32_t
name|ver_class_flow
decl_stmt|;
name|ib_net16_t
name|resv1
decl_stmt|;
name|uint8_t
name|resv2
decl_stmt|;
name|uint8_t
name|hop_limit
decl_stmt|;
name|ib_gid_t
name|src_gid
decl_stmt|;
name|ib_gid_t
name|dest_gid
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_grh_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****f* IBA Base: Types/ib_grh_get_ver_class_flow * NAME *	ib_grh_get_ver_class_flow * * DESCRIPTION *	Get encoded version, traffic class and flow label in grh * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_grh_get_ver_class_flow
parameter_list|(
name|IN
specifier|const
name|ib_net32_t
name|ver_class_flow
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_ver
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_tclass
parameter_list|,
name|OUT
name|uint32_t
modifier|*
specifier|const
name|p_flow_lbl
parameter_list|)
block|{
name|ib_net32_t
name|tmp_ver_class_flow
decl_stmt|;
if|if
condition|(
name|p_ver
condition|)
operator|*
name|p_ver
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|ver_class_flow
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
name|tmp_ver_class_flow
operator|=
name|ver_class_flow
operator|>>
literal|4
expr_stmt|;
if|if
condition|(
name|p_tclass
condition|)
operator|*
name|p_tclass
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|tmp_ver_class_flow
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|tmp_ver_class_flow
operator|=
name|tmp_ver_class_flow
operator|>>
literal|8
expr_stmt|;
if|if
condition|(
name|p_flow_lbl
condition|)
operator|*
name|p_flow_lbl
operator|=
name|tmp_ver_class_flow
operator|&
literal|0xfffff
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	ver_class_flow *		[in] the version, traffic class and flow label info. * * RETURN VALUES *	p_ver *		[out] pointer to the version info. * *	p_tclass *		[out] pointer to the traffic class info. * *	p_flow_lbl *		[out] pointer to the flow label info * * NOTES * * SEE ALSO *	ib_grh_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_grh_set_ver_class_flow * NAME *	ib_grh_set_ver_class_flow * * DESCRIPTION *	Set encoded version, traffic class and flow label in grh * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_grh_set_ver_class_flow
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|ver
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|tclass
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|flow_lbl
parameter_list|)
block|{
name|ib_net32_t
name|ver_class_flow
decl_stmt|;
name|ver_class_flow
operator|=
name|flow_lbl
expr_stmt|;
name|ver_class_flow
operator|=
name|ver_class_flow
operator|<<
literal|8
expr_stmt|;
name|ver_class_flow
operator|=
name|ver_class_flow
operator||
name|tclass
expr_stmt|;
name|ver_class_flow
operator|=
name|ver_class_flow
operator|<<
literal|4
expr_stmt|;
name|ver_class_flow
operator|=
name|ver_class_flow
operator||
name|ver
expr_stmt|;
return|return
operator|(
name|ver_class_flow
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	ver *		[in] the version info. * *	tclass *		[in] the traffic class info. * *	flow_lbl *		[in] the flow label info * * RETURN VALUES *	ver_class_flow *		[out] the version, traffic class and flow label info. * * NOTES * * SEE ALSO *	ib_grh_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_member_rec_t * NAME *	ib_member_rec_t * * DESCRIPTION *	Multicast member record, used to create, join, and leave multicast *	groups. * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_member_rec
block|{
name|ib_gid_t
name|mgid
decl_stmt|;
name|ib_gid_t
name|port_gid
decl_stmt|;
name|ib_net32_t
name|qkey
decl_stmt|;
name|ib_net16_t
name|mlid
decl_stmt|;
name|uint8_t
name|mtu
decl_stmt|;
name|uint8_t
name|tclass
decl_stmt|;
name|ib_net16_t
name|pkey
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|pkt_life
decl_stmt|;
name|ib_net32_t
name|sl_flow_hop
decl_stmt|;
name|uint8_t
name|scope_state
decl_stmt|;
name|uint8_t
name|proxy_join
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_member_rec_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	mgid *		Multicast GID address for this multicast group. * *	port_gid *		Valid GID of the endpoint joining this multicast group. * *	qkey *		Q_Key to be sued by this multicast group. * *	mlid *		Multicast LID for this multicast group. * *	mtu *		MTU and MTU selector fields to use on this path * *	tclass *		Another global routing parameter. * *	pkey *		Partition key (P_Key) to use for this member. * *	rate *		Rate and rate selector fields to use on this path. * *	pkt_life *		Packet lifetime * *	sl_flow_hop *		Global routing parameters: service level, hop count, and flow label. * *	scope_state *		MGID scope and JoinState of multicast request. * *	proxy_join *		Enables others in the Partition to proxy add/remove from the group * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_member_get_sl_flow_hop * NAME *	ib_member_get_sl_flow_hop * * DESCRIPTION *	Get encoded sl, flow label, and hop limit * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_member_get_sl_flow_hop
parameter_list|(
name|IN
specifier|const
name|ib_net32_t
name|sl_flow_hop
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_sl
parameter_list|,
name|OUT
name|uint32_t
modifier|*
specifier|const
name|p_flow_lbl
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_hop
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|tmp
operator|=
name|cl_ntoh32
argument_list|(
name|sl_flow_hop
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_hop
condition|)
operator|*
name|p_hop
operator|=
operator|(
name|uint8_t
operator|)
name|tmp
expr_stmt|;
name|tmp
operator|>>=
literal|8
expr_stmt|;
if|if
condition|(
name|p_flow_lbl
condition|)
operator|*
name|p_flow_lbl
operator|=
call|(
name|uint32_t
call|)
argument_list|(
name|tmp
operator|&
literal|0xfffff
argument_list|)
expr_stmt|;
name|tmp
operator|>>=
literal|20
expr_stmt|;
if|if
condition|(
name|p_sl
condition|)
operator|*
name|p_sl
operator|=
operator|(
name|uint8_t
operator|)
name|tmp
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	sl_flow_hop *		[in] the sl, flow label, and hop limit of MC Group * * RETURN VALUES *	p_sl *		[out] pointer to the service level * *	p_flow_lbl *		[out] pointer to the flow label info * *	p_hop *		[out] pointer to the hop count limit. * * NOTES * * SEE ALSO *	ib_member_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_member_set_sl_flow_hop * NAME *	ib_member_set_sl_flow_hop * * DESCRIPTION *	Set encoded sl, flow label, and hop limit * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_member_set_sl_flow_hop
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|sl
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|flow_label
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|hop_limit
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|tmp
operator|=
operator|(
name|sl
operator|<<
literal|28
operator|)
operator||
operator|(
operator|(
name|flow_label
operator|&
literal|0xfffff
operator|)
operator|<<
literal|8
operator|)
operator||
name|hop_limit
expr_stmt|;
return|return
name|cl_hton32
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	sl *		[in] the service level. * *	flow_lbl *		[in] the flow label info * *	hop_limit *		[in] the hop limit. * * RETURN VALUES *	sl_flow_hop *		[out] the encoded sl, flow label, and hop limit * * NOTES * * SEE ALSO *	ib_member_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_member_get_scope_state * NAME *	ib_member_get_scope_state * * DESCRIPTION *	Get encoded MGID scope and JoinState * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_member_get_scope_state
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|scope_state
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_scope
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_state
parameter_list|)
block|{
name|uint8_t
name|tmp_scope_state
decl_stmt|;
if|if
condition|(
name|p_state
condition|)
operator|*
name|p_state
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|scope_state
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
name|tmp_scope_state
operator|=
name|scope_state
operator|>>
literal|4
expr_stmt|;
if|if
condition|(
name|p_scope
condition|)
operator|*
name|p_scope
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|tmp_scope_state
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	scope_state *		[in] the scope and state * * RETURN VALUES *	p_scope *		[out] pointer to the MGID scope * *	p_state *		[out] pointer to the join state * * NOTES * * SEE ALSO *	ib_member_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_member_set_scope_state * NAME *	ib_member_set_scope_state * * DESCRIPTION *	Set encoded version, MGID scope and JoinState * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_member_set_scope_state
parameter_list|(
name|IN
specifier|const
name|uint8_t
name|scope
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|state
parameter_list|)
block|{
name|uint8_t
name|scope_state
decl_stmt|;
name|scope_state
operator|=
name|scope
expr_stmt|;
name|scope_state
operator|=
name|scope_state
operator|<<
literal|4
expr_stmt|;
name|scope_state
operator|=
name|scope_state
operator||
name|state
expr_stmt|;
return|return
operator|(
name|scope_state
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	scope *		[in] the MGID scope * *	state *		[in] the JoinState * * RETURN VALUES *	scope_state *		[out] the encoded one * * NOTES * * SEE ALSO *	ib_member_rec_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_member_set_join_state * NAME *	ib_member_set_join_state * * DESCRIPTION *	Set JoinState * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_member_set_join_state
parameter_list|(
name|IN
name|OUT
name|ib_member_rec_t
modifier|*
name|p_mc_rec
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|state
parameter_list|)
block|{
comment|/* keep the scope as it is */
name|p_mc_rec
operator|->
name|scope_state
operator|=
operator|(
name|p_mc_rec
operator|->
name|scope_state
operator|&
literal|0xF0
operator|)
operator||
operator|(
literal|0x0f
operator|&
name|state
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mc_rec *		[in] pointer to the member record * *	state *		[in] the JoinState * * RETURN VALUES *	NONE * * NOTES * * SEE ALSO *	ib_member_rec_t *********/
end_comment

begin_comment
comment|/*  * Join State Codes:  */
end_comment

begin_define
define|#
directive|define
name|IB_MC_REC_STATE_FULL_MEMBER
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_MC_REC_STATE_NON_MEMBER
value|0x02
end_define

begin_define
define|#
directive|define
name|IB_MC_REC_STATE_SEND_ONLY_NON_MEMBER
value|0x04
end_define

begin_comment
comment|/*  *	Generic MAD notice types  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_FATAL
value|0x00
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_URGENT
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_SECURITY
value|0x02
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_SUBN_MGMT
value|0x03
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_INFO
value|0x04
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_EMPTY
value|0x7F
end_define

begin_define
define|#
directive|define
name|SM_GID_IN_SERVICE_TRAP
value|64
end_define

begin_define
define|#
directive|define
name|SM_GID_OUT_OF_SERVICE_TRAP
value|65
end_define

begin_define
define|#
directive|define
name|SM_MGID_CREATED_TRAP
value|66
end_define

begin_define
define|#
directive|define
name|SM_MGID_DESTROYED_TRAP
value|67
end_define

begin_define
define|#
directive|define
name|SM_UNPATH_TRAP
value|68
end_define

begin_define
define|#
directive|define
name|SM_REPATH_TRAP
value|69
end_define

begin_define
define|#
directive|define
name|SM_LINK_STATE_CHANGED_TRAP
value|128
end_define

begin_define
define|#
directive|define
name|SM_LINK_INTEGRITY_THRESHOLD_TRAP
value|129
end_define

begin_define
define|#
directive|define
name|SM_BUFFER_OVERRUN_THRESHOLD_TRAP
value|130
end_define

begin_define
define|#
directive|define
name|SM_WATCHDOG_TIMER_EXPIRED_TRAP
value|131
end_define

begin_define
define|#
directive|define
name|SM_LOCAL_CHANGES_TRAP
value|144
end_define

begin_define
define|#
directive|define
name|SM_SYS_IMG_GUID_CHANGED_TRAP
value|145
end_define

begin_define
define|#
directive|define
name|SM_BAD_MKEY_TRAP
value|256
end_define

begin_define
define|#
directive|define
name|SM_BAD_PKEY_TRAP
value|257
end_define

begin_define
define|#
directive|define
name|SM_BAD_QKEY_TRAP
value|258
end_define

begin_define
define|#
directive|define
name|SM_BAD_SWITCH_PKEY_TRAP
value|259
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_mad_notice_attr
comment|// Total Size calc  Accumulated
block|{
name|uint8_t
name|generic_type
decl_stmt|;
comment|// 1                1
union|union
name|_notice_g_or_v
block|{
struct|struct
name|_notice_generic
comment|// 5                6
block|{
name|uint8_t
name|prod_type_msb
decl_stmt|;
name|ib_net16_t
name|prod_type_lsb
decl_stmt|;
name|ib_net16_t
name|trap_num
decl_stmt|;
block|}
name|PACK_SUFFIX
name|generic
struct|;
struct|struct
name|_notice_vend
block|{
name|uint8_t
name|vend_id_msb
decl_stmt|;
name|ib_net16_t
name|vend_id_lsb
decl_stmt|;
name|ib_net16_t
name|dev_id
decl_stmt|;
block|}
name|PACK_SUFFIX
name|vend
struct|;
block|}
name|g_or_v
union|;
name|ib_net16_t
name|issuer_lid
decl_stmt|;
comment|// 2                 8
name|ib_net16_t
name|toggle_count
decl_stmt|;
comment|// 2                 10
union|union
name|_data_details
comment|// 54                64
block|{
struct|struct
name|_raw_data
block|{
name|uint8_t
name|details
index|[
literal|54
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|raw_data
struct|;
struct|struct
name|_ntc_64_67
block|{
name|uint8_t
name|res
index|[
literal|6
index|]
decl_stmt|;
name|ib_gid_t
name|gid
decl_stmt|;
comment|// the Node or Multicast Group that came in/out
block|}
name|PACK_SUFFIX
name|ntc_64_67
struct|;
struct|struct
name|_ntc_128
block|{
name|ib_net16_t
name|sw_lid
decl_stmt|;
comment|// the sw lid of which link state changed
block|}
name|PACK_SUFFIX
name|ntc_128
struct|;
struct|struct
name|_ntc_129_131
block|{
name|ib_net16_t
name|pad
decl_stmt|;
name|ib_net16_t
name|lid
decl_stmt|;
comment|// lid and port number of the violation
name|uint8_t
name|port_num
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ntc_129_131
struct|;
struct|struct
name|_ntc_144
block|{
name|ib_net16_t
name|pad1
decl_stmt|;
name|ib_net16_t
name|lid
decl_stmt|;
comment|// lid where change occured
name|uint8_t
name|pad2
decl_stmt|;
comment|// reserved
name|uint8_t
name|local_changes
decl_stmt|;
comment|// 7b reserved 1b local changes
name|ib_net32_t
name|new_cap_mask
decl_stmt|;
comment|// new capability mask
name|ib_net16_t
name|change_flgs
decl_stmt|;
comment|// 10b reserved 6b change flags
name|ib_net16_t
name|cap_mask2
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ntc_144
struct|;
struct|struct
name|_ntc_145
block|{
name|ib_net16_t
name|pad1
decl_stmt|;
name|ib_net16_t
name|lid
decl_stmt|;
comment|// lid where sys guid changed
name|ib_net16_t
name|pad2
decl_stmt|;
name|ib_net64_t
name|new_sys_guid
decl_stmt|;
comment|// new system image guid
block|}
name|PACK_SUFFIX
name|ntc_145
struct|;
struct|struct
name|_ntc_256
block|{
comment|// total: 54
name|ib_net16_t
name|pad1
decl_stmt|;
comment|// 2
name|ib_net16_t
name|lid
decl_stmt|;
comment|// 2
name|ib_net16_t
name|dr_slid
decl_stmt|;
comment|// 2
name|uint8_t
name|method
decl_stmt|;
comment|// 1
name|uint8_t
name|pad2
decl_stmt|;
comment|// 1
name|ib_net16_t
name|attr_id
decl_stmt|;
comment|// 2
name|ib_net32_t
name|attr_mod
decl_stmt|;
comment|// 4
name|ib_net64_t
name|mkey
decl_stmt|;
comment|// 8
name|uint8_t
name|pad3
decl_stmt|;
comment|// 1
name|uint8_t
name|dr_trunc_hop
decl_stmt|;
comment|// 1
name|uint8_t
name|dr_rtn_path
index|[
literal|30
index|]
decl_stmt|;
comment|// 30
block|}
name|PACK_SUFFIX
name|ntc_256
struct|;
struct|struct
name|_ntc_257_258
comment|// violation of p/q_key // 49
block|{
name|ib_net16_t
name|pad1
decl_stmt|;
comment|// 2
name|ib_net16_t
name|lid1
decl_stmt|;
comment|// 2
name|ib_net16_t
name|lid2
decl_stmt|;
comment|// 2
name|ib_net32_t
name|key
decl_stmt|;
comment|// 4
name|ib_net32_t
name|qp1
decl_stmt|;
comment|// 4b sl, 4b pad, 24b qp1
name|ib_net32_t
name|qp2
decl_stmt|;
comment|// 8b pad, 24b qp2
name|ib_gid_t
name|gid1
decl_stmt|;
comment|// 16
name|ib_gid_t
name|gid2
decl_stmt|;
comment|// 16
block|}
name|PACK_SUFFIX
name|ntc_257_258
struct|;
struct|struct
name|_ntc_259
comment|// pkey violation from switch 51
block|{
name|ib_net16_t
name|data_valid
decl_stmt|;
comment|// 2
name|ib_net16_t
name|lid1
decl_stmt|;
comment|// 2
name|ib_net16_t
name|lid2
decl_stmt|;
comment|// 2
name|ib_net16_t
name|pkey
decl_stmt|;
comment|// 2
name|ib_net32_t
name|sl_qp1
decl_stmt|;
comment|// 4b sl, 4b pad, 24b qp1
name|ib_net32_t
name|qp2
decl_stmt|;
comment|// 8b pad, 24b qp2
name|ib_gid_t
name|gid1
decl_stmt|;
comment|// 16
name|ib_gid_t
name|gid2
decl_stmt|;
comment|// 16
name|ib_net16_t
name|sw_lid
decl_stmt|;
comment|// 2
name|uint8_t
name|port_no
decl_stmt|;
comment|// 1
block|}
name|PACK_SUFFIX
name|ntc_259
struct|;
struct|struct
name|_ntc_bkey_259
comment|// bkey violation
block|{
name|ib_net16_t
name|lidaddr
decl_stmt|;
name|uint8_t
name|method
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|ib_net16_t
name|attribute_id
decl_stmt|;
name|ib_net32_t
name|attribute_modifier
decl_stmt|;
name|ib_net32_t
name|qp
decl_stmt|;
comment|// qp is low 24 bits
name|ib_net64_t
name|bkey
decl_stmt|;
name|ib_gid_t
name|gid
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ntc_bkey_259
struct|;
struct|struct
name|_ntc_cckey_0
comment|// CC key violation
block|{
name|ib_net16_t
name|slid
decl_stmt|;
comment|// source LID from offending packet LRH
name|uint8_t
name|method
decl_stmt|;
comment|// method, from common MAD header
name|uint8_t
name|resv0
decl_stmt|;
name|ib_net16_t
name|attribute_id
decl_stmt|;
comment|// Attribute ID, from common MAD header
name|ib_net16_t
name|resv1
decl_stmt|;
name|ib_net32_t
name|attribute_modifier
decl_stmt|;
comment|// Attribute Modif, from common MAD header
name|ib_net32_t
name|qp
decl_stmt|;
comment|// 8b pad, 24b dest QP from BTH
name|ib_net64_t
name|cc_key
decl_stmt|;
comment|// CC key of the offending packet
name|ib_gid_t
name|source_gid
decl_stmt|;
comment|// GID from GRH of the offending packet
name|uint8_t
name|padding
index|[
literal|14
index|]
decl_stmt|;
comment|// Padding - ignored on read
block|}
name|PACK_SUFFIX
name|ntc_cckey_0
struct|;
block|}
name|data_details
union|;
name|ib_gid_t
name|issuer_gid
decl_stmt|;
comment|// 16          80
block|}
name|PACK_SUFFIX
name|ib_mad_notice_attr_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/**  * Trap 259 masks  */
end_comment

begin_define
define|#
directive|define
name|TRAP_259_MASK_SL
value|(CL_HTON32(0xF0000000))
end_define

begin_define
define|#
directive|define
name|TRAP_259_MASK_QP
value|(CL_HTON32(0x00FFFFFF))
end_define

begin_comment
comment|/**  * Trap 144 masks  */
end_comment

begin_define
define|#
directive|define
name|TRAP_144_MASK_OTHER_LOCAL_CHANGES
value|0x01
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_CAPABILITY_MASK2_CHANGE
value|(CL_HTON16(0x0020))
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_HIERARCHY_INFO_CHANGE
value|(CL_HTON16(0x0010))
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_SM_PRIORITY_CHANGE
value|(CL_HTON16(0x0008))
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_LINK_SPEED_ENABLE_CHANGE
value|(CL_HTON16(0x0004))
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_LINK_WIDTH_ENABLE_CHANGE
value|(CL_HTON16(0x0002))
end_define

begin_define
define|#
directive|define
name|TRAP_144_MASK_NODE_DESCRIPTION_CHANGE
value|(CL_HTON16(0x0001))
end_define

begin_comment
comment|/****f* IBA Base: Types/ib_notice_is_generic * NAME *	ib_notice_is_generic * * DESCRIPTION *	Check if the notice is generic * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|OSM_API
name|ib_notice_is_generic
parameter_list|(
name|IN
specifier|const
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|)
block|{
return|return
operator|(
name|p_ntc
operator|->
name|generic_type
operator|&
literal|0x80
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * * RETURN VALUES *	TRUE if notice MAD is generic * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_get_type * NAME *	ib_notice_get_type * * DESCRIPTION *	Get the notice type * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_notice_get_type
parameter_list|(
name|IN
specifier|const
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|)
block|{
return|return
name|p_ntc
operator|->
name|generic_type
operator|&
literal|0x7f
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to  the notice MAD attribute * * RETURN VALUES *	TRUE if mad is generic * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_get_prod_type * NAME *	ib_notice_get_prod_type * * DESCRIPTION *	Get the notice Producer Type of Generic Notice * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_notice_get_prod_type
parameter_list|(
name|IN
specifier|const
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|)
block|{
name|uint32_t
name|pt
decl_stmt|;
name|pt
operator|=
name|cl_ntoh16
argument_list|(
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_lsb
argument_list|)
operator||
operator|(
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_msb
operator|<<
literal|16
operator|)
expr_stmt|;
return|return
name|cl_hton32
argument_list|(
name|pt
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * * RETURN VALUES *	The producer type * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_set_prod_type * NAME *	ib_notice_set_prod_type * * DESCRIPTION *	Set the notice Producer Type of Generic Notice * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_notice_set_prod_type
parameter_list|(
name|IN
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|,
name|IN
name|ib_net32_t
name|prod_type_val
parameter_list|)
block|{
name|uint32_t
name|ptv
init|=
name|cl_ntoh32
argument_list|(
name|prod_type_val
argument_list|)
decl_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_lsb
operator|=
name|cl_hton16
argument_list|(
call|(
name|uint16_t
call|)
argument_list|(
name|ptv
operator|&
literal|0x0000ffff
argument_list|)
argument_list|)
expr_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_msb
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|ptv
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * *  prod_type *     [in] The producer Type code * * RETURN VALUES *	None * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_set_prod_type_ho * NAME *	ib_notice_set_prod_type_ho * * DESCRIPTION *	Set the notice Producer Type of Generic Notice given Host Order * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_notice_set_prod_type_ho
parameter_list|(
name|IN
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|,
name|IN
name|uint32_t
name|prod_type_val_ho
parameter_list|)
block|{
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_lsb
operator|=
name|cl_hton16
argument_list|(
call|(
name|uint16_t
call|)
argument_list|(
name|prod_type_val_ho
operator|&
literal|0x0000ffff
argument_list|)
argument_list|)
expr_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|prod_type_msb
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|prod_type_val_ho
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * *	prod_type *		[in] The producer Type code in host order * * RETURN VALUES *	None * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_get_vend_id * NAME *	ib_notice_get_vend_id * * DESCRIPTION *	Get the Vendor Id of Vendor type Notice * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_notice_get_vend_id
parameter_list|(
name|IN
specifier|const
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|)
block|{
name|uint32_t
name|vi
decl_stmt|;
name|vi
operator|=
name|cl_ntoh16
argument_list|(
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_lsb
argument_list|)
operator||
operator|(
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_msb
operator|<<
literal|16
operator|)
expr_stmt|;
return|return
name|cl_hton32
argument_list|(
name|vi
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * * RETURN VALUES *	The Vendor Id of Vendor type Notice * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_set_vend_id * NAME *	ib_notice_set_vend_id * * DESCRIPTION *	Set the notice Producer Type of Generic Notice * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_notice_set_vend_id
parameter_list|(
name|IN
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|,
name|IN
name|ib_net32_t
name|vend_id
parameter_list|)
block|{
name|uint32_t
name|vi
init|=
name|cl_ntoh32
argument_list|(
name|vend_id
argument_list|)
decl_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_lsb
operator|=
name|cl_hton16
argument_list|(
call|(
name|uint16_t
call|)
argument_list|(
name|vi
operator|&
literal|0x0000ffff
argument_list|)
argument_list|)
expr_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_msb
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|vi
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * *	vend_id *		[in] The producer Type code * * RETURN VALUES *	None * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_notice_set_vend_id_ho * NAME *	ib_notice_set_vend_id_ho * * DESCRIPTION *	Set the notice Producer Type of Generic Notice given a host order value * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_notice_set_vend_id_ho
parameter_list|(
name|IN
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|,
name|IN
name|uint32_t
name|vend_id_ho
parameter_list|)
block|{
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_lsb
operator|=
name|cl_hton16
argument_list|(
call|(
name|uint16_t
call|)
argument_list|(
name|vend_id_ho
operator|&
literal|0x0000ffff
argument_list|)
argument_list|)
expr_stmt|;
name|p_ntc
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vend_id_msb
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|vend_id_ho
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ntc *		[in] Pointer to the notice MAD attribute * *	vend_id_ho *		[in] The producer Type code in host order * * RETURN VALUES *	None * * SEE ALSO *	ib_mad_notice_attr_t *********/
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_inform_info
block|{
name|ib_gid_t
name|gid
decl_stmt|;
name|ib_net16_t
name|lid_range_begin
decl_stmt|;
name|ib_net16_t
name|lid_range_end
decl_stmt|;
name|ib_net16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|is_generic
decl_stmt|;
name|uint8_t
name|subscribe
decl_stmt|;
name|ib_net16_t
name|trap_type
decl_stmt|;
union|union
name|_inform_g_or_v
block|{
struct|struct
name|_inform_generic
block|{
name|ib_net16_t
name|trap_num
decl_stmt|;
name|ib_net32_t
name|qpn_resp_time_val
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|node_type_msb
decl_stmt|;
name|ib_net16_t
name|node_type_lsb
decl_stmt|;
block|}
name|PACK_SUFFIX
name|generic
struct|;
struct|struct
name|_inform_vend
block|{
name|ib_net16_t
name|dev_id
decl_stmt|;
name|ib_net32_t
name|qpn_resp_time_val
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|vendor_id_msb
decl_stmt|;
name|ib_net16_t
name|vendor_id_lsb
decl_stmt|;
block|}
name|PACK_SUFFIX
name|vend
struct|;
block|}
name|PACK_SUFFIX
name|g_or_v
union|;
block|}
name|PACK_SUFFIX
name|ib_inform_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****f* IBA Base: Types/ib_inform_info_get_qpn_resp_time * NAME *	ib_inform_info_get_qpn_resp_time * * DESCRIPTION *	Get QPN of the inform info * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_inform_info_get_qpn_resp_time
parameter_list|(
name|IN
specifier|const
name|ib_net32_t
name|qpn_resp_time_val
parameter_list|,
name|OUT
name|ib_net32_t
modifier|*
specifier|const
name|p_qpn
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_resp_time_val
parameter_list|)
block|{
name|uint32_t
name|tmp
init|=
name|cl_ntoh32
argument_list|(
name|qpn_resp_time_val
argument_list|)
decl_stmt|;
if|if
condition|(
name|p_qpn
condition|)
operator|*
name|p_qpn
operator|=
name|cl_hton32
argument_list|(
operator|(
name|tmp
operator|&
literal|0xffffff00
operator|)
operator|>>
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_resp_time_val
condition|)
operator|*
name|p_resp_time_val
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|tmp
operator|&
literal|0x0000001f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	qpn_resp_time_val *		[in] the  qpn and resp time val from the mad * * RETURN VALUES *	p_qpn *		[out] pointer to the qpn * *	p_state *		[out] pointer to the resp time val * * NOTES * * SEE ALSO *	ib_inform_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_inform_info_set_qpn * NAME *	ib_inform_info_set_qpn * * DESCRIPTION *	Set the QPN of the inform info * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_inform_info_set_qpn
parameter_list|(
name|IN
name|ib_inform_info_t
modifier|*
name|p_ii
parameter_list|,
name|IN
name|ib_net32_t
specifier|const
name|qpn
parameter_list|)
block|{
name|uint32_t
name|tmp
init|=
name|cl_ntoh32
argument_list|(
name|p_ii
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|qpn_resp_time_val
argument_list|)
decl_stmt|;
name|uint32_t
name|qpn_h
init|=
name|cl_ntoh32
argument_list|(
name|qpn
argument_list|)
decl_stmt|;
name|p_ii
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|qpn_resp_time_val
operator|=
name|cl_hton32
argument_list|(
operator|(
name|tmp
operator|&
literal|0x000000ff
operator|)
operator||
operator|(
operator|(
name|qpn_h
operator|<<
literal|8
operator|)
operator|&
literal|0xffffff00
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS * * NOTES * * SEE ALSO *	ib_inform_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_inform_info_get_prod_type * NAME *	ib_inform_info_get_prod_type * * DESCRIPTION *	Get Producer Type of the Inform Info *	13.4.8.3 InformInfo * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_inform_info_get_prod_type
parameter_list|(
name|IN
specifier|const
name|ib_inform_info_t
modifier|*
name|p_inf
parameter_list|)
block|{
name|uint32_t
name|nt
decl_stmt|;
name|nt
operator|=
name|cl_ntoh16
argument_list|(
name|p_inf
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|node_type_lsb
argument_list|)
operator||
operator|(
name|p_inf
operator|->
name|g_or_v
operator|.
name|generic
operator|.
name|node_type_msb
operator|<<
literal|16
operator|)
expr_stmt|;
return|return
name|cl_hton32
argument_list|(
name|nt
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_inf *		[in] pointer to an inform info * * RETURN VALUES *     The producer type * * NOTES * * SEE ALSO *	ib_inform_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_inform_info_get_vend_id * NAME *	ib_inform_info_get_vend_id * * DESCRIPTION *	Get Node Type of the Inform Info * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net32_t
name|OSM_API
name|ib_inform_info_get_vend_id
parameter_list|(
name|IN
specifier|const
name|ib_inform_info_t
modifier|*
name|p_inf
parameter_list|)
block|{
name|uint32_t
name|vi
decl_stmt|;
name|vi
operator|=
name|cl_ntoh16
argument_list|(
name|p_inf
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vendor_id_lsb
argument_list|)
operator||
operator|(
name|p_inf
operator|->
name|g_or_v
operator|.
name|vend
operator|.
name|vendor_id_msb
operator|<<
literal|16
operator|)
expr_stmt|;
return|return
name|cl_hton32
argument_list|(
name|vi
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_inf *		[in] pointer to an inform info * * RETURN VALUES *     The node type * * NOTES * * SEE ALSO *	ib_inform_info_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_inform_info_record_t * NAME *	ib_inform_info_record_t * * DESCRIPTION *	IBA defined InformInfo Record. (15.2.5.12) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_inform_info_record
block|{
name|ib_gid_t
name|subscriber_gid
decl_stmt|;
name|ib_net16_t
name|subscriber_enum
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|ib_inform_info_t
name|inform_info
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_inform_info_record_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_perfmgt_mad_t * NAME *	ib_perfmgt_mad_t * * DESCRIPTION *	IBA defined Perf Management MAD (16.3.1) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_perfmgt_mad
block|{
name|ib_mad_t
name|header
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|40
index|]
decl_stmt|;
define|#
directive|define
name|IB_PM_DATA_SIZE
value|192
name|uint8_t
name|data
index|[
name|IB_PM_DATA_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_perfmgt_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	header *		Common MAD header. * *	resv *		Reserved. * *	data *		Performance Management payload.  The structure and content of this field *		depends upon the method, attr_id, and attr_mod fields in the header. * * SEE ALSO * ib_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_port_counters * NAME *	ib_port_counters_t * * DESCRIPTION *	IBA defined PortCounters Attribute. (16.1.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_counters
block|{
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|port_select
decl_stmt|;
name|ib_net16_t
name|counter_select
decl_stmt|;
name|ib_net16_t
name|symbol_err_cnt
decl_stmt|;
name|uint8_t
name|link_err_recover
decl_stmt|;
name|uint8_t
name|link_downed
decl_stmt|;
name|ib_net16_t
name|rcv_err
decl_stmt|;
name|ib_net16_t
name|rcv_rem_phys_err
decl_stmt|;
name|ib_net16_t
name|rcv_switch_relay_err
decl_stmt|;
name|ib_net16_t
name|xmit_discards
decl_stmt|;
name|uint8_t
name|xmit_constraint_err
decl_stmt|;
name|uint8_t
name|rcv_constraint_err
decl_stmt|;
name|uint8_t
name|counter_select2
decl_stmt|;
name|uint8_t
name|link_int_buffer_overrun
decl_stmt|;
name|ib_net16_t
name|qp1_dropped
decl_stmt|;
name|ib_net16_t
name|vl15_dropped
decl_stmt|;
name|ib_net32_t
name|xmit_data
decl_stmt|;
name|ib_net32_t
name|rcv_data
decl_stmt|;
name|ib_net32_t
name|xmit_pkts
decl_stmt|;
name|ib_net32_t
name|rcv_pkts
decl_stmt|;
name|ib_net32_t
name|xmit_wait
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_counters_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_define
define|#
directive|define
name|PC_LINK_INT
parameter_list|(
name|integ_buf_over
parameter_list|)
value|((integ_buf_over& 0xF0)>> 4)
end_define

begin_define
define|#
directive|define
name|PC_BUF_OVERRUN
parameter_list|(
name|integ_buf_over
parameter_list|)
value|(integ_buf_over& 0x0F)
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_port_counters_ext * NAME *	ib_port_counters_ext_t * * DESCRIPTION *	IBA defined PortCounters Extended Attribute. (16.1.4.11) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_counters_ext
block|{
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|port_select
decl_stmt|;
name|ib_net16_t
name|counter_select
decl_stmt|;
name|ib_net32_t
name|counter_select2
decl_stmt|;
name|ib_net64_t
name|xmit_data
decl_stmt|;
name|ib_net64_t
name|rcv_data
decl_stmt|;
name|ib_net64_t
name|xmit_pkts
decl_stmt|;
name|ib_net64_t
name|rcv_pkts
decl_stmt|;
name|ib_net64_t
name|unicast_xmit_pkts
decl_stmt|;
name|ib_net64_t
name|unicast_rcv_pkts
decl_stmt|;
name|ib_net64_t
name|multicast_xmit_pkts
decl_stmt|;
name|ib_net64_t
name|multicast_rcv_pkts
decl_stmt|;
name|ib_net64_t
name|symbol_err_cnt
decl_stmt|;
name|ib_net64_t
name|link_err_recover
decl_stmt|;
name|ib_net64_t
name|link_downed
decl_stmt|;
name|ib_net64_t
name|rcv_err
decl_stmt|;
name|ib_net64_t
name|rcv_rem_phys_err
decl_stmt|;
name|ib_net64_t
name|rcv_switch_relay_err
decl_stmt|;
name|ib_net64_t
name|xmit_discards
decl_stmt|;
name|ib_net64_t
name|xmit_constraint_err
decl_stmt|;
name|ib_net64_t
name|rcv_constraint_err
decl_stmt|;
name|ib_net64_t
name|link_integrity_err
decl_stmt|;
name|ib_net64_t
name|buffer_overrun
decl_stmt|;
name|ib_net64_t
name|vl15_dropped
decl_stmt|;
name|ib_net64_t
name|xmit_wait
decl_stmt|;
name|ib_net64_t
name|qp1_dropped
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_counters_ext_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_port_samples_control * NAME *	ib_port_samples_control_t * * DESCRIPTION *	IBA defined PortSamplesControl Attribute. (16.1.3.2) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_samples_control
block|{
name|uint8_t
name|op_code
decl_stmt|;
name|uint8_t
name|port_select
decl_stmt|;
name|uint8_t
name|tick
decl_stmt|;
name|uint8_t
name|counter_width
decl_stmt|;
comment|/* 5 bits res : 3bits counter_width */
name|ib_net32_t
name|counter_mask
decl_stmt|;
comment|/* 2 bits res : 3 bits counter_mask : 27 bits counter_masks_1to9 */
name|ib_net16_t
name|counter_mask_10to14
decl_stmt|;
comment|/* 1 bits res : 15 bits counter_masks_10to14 */
name|uint8_t
name|sample_mech
decl_stmt|;
name|uint8_t
name|sample_status
decl_stmt|;
comment|/* 6 bits res : 2 bits sample_status */
name|ib_net64_t
name|option_mask
decl_stmt|;
name|ib_net64_t
name|vendor_mask
decl_stmt|;
name|ib_net32_t
name|sample_start
decl_stmt|;
name|ib_net32_t
name|sample_interval
decl_stmt|;
name|ib_net16_t
name|tag
decl_stmt|;
name|ib_net16_t
name|counter_select0
decl_stmt|;
name|ib_net16_t
name|counter_select1
decl_stmt|;
name|ib_net16_t
name|counter_select2
decl_stmt|;
name|ib_net16_t
name|counter_select3
decl_stmt|;
name|ib_net16_t
name|counter_select4
decl_stmt|;
name|ib_net16_t
name|counter_select5
decl_stmt|;
name|ib_net16_t
name|counter_select6
decl_stmt|;
name|ib_net16_t
name|counter_select7
decl_stmt|;
name|ib_net16_t
name|counter_select8
decl_stmt|;
name|ib_net16_t
name|counter_select9
decl_stmt|;
name|ib_net16_t
name|counter_select10
decl_stmt|;
name|ib_net16_t
name|counter_select11
decl_stmt|;
name|ib_net16_t
name|counter_select12
decl_stmt|;
name|ib_net16_t
name|counter_select13
decl_stmt|;
name|ib_net16_t
name|counter_select14
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_samples_control_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****d* IBA Base: Types/CounterSelect values * NAME *       Counter select values * * DESCRIPTION *	Mandatory counter select values (16.1.3.3) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CS_PORT_XMIT_DATA
value|(CL_HTON16(0x0001))
end_define

begin_define
define|#
directive|define
name|IB_CS_PORT_RCV_DATA
value|(CL_HTON16(0x0002))
end_define

begin_define
define|#
directive|define
name|IB_CS_PORT_XMIT_PKTS
value|(CL_HTON16(0x0003))
end_define

begin_define
define|#
directive|define
name|IB_CS_PORT_RCV_PKTS
value|(CL_HTON16(0x0004))
end_define

begin_define
define|#
directive|define
name|IB_CS_PORT_XMIT_WAIT
value|(CL_HTON16(0x0005))
end_define

begin_comment
comment|/****s* IBA Base: Types/ib_port_samples_result * NAME *	ib_port_samples_result_t * * DESCRIPTION *	IBA defined PortSamplesControl Attribute. (16.1.3.2) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_samples_result
block|{
name|ib_net16_t
name|tag
decl_stmt|;
name|ib_net16_t
name|sample_status
decl_stmt|;
comment|/* 14 bits res : 2 bits sample_status */
name|ib_net32_t
name|counter0
decl_stmt|;
name|ib_net32_t
name|counter1
decl_stmt|;
name|ib_net32_t
name|counter2
decl_stmt|;
name|ib_net32_t
name|counter3
decl_stmt|;
name|ib_net32_t
name|counter4
decl_stmt|;
name|ib_net32_t
name|counter5
decl_stmt|;
name|ib_net32_t
name|counter6
decl_stmt|;
name|ib_net32_t
name|counter7
decl_stmt|;
name|ib_net32_t
name|counter8
decl_stmt|;
name|ib_net32_t
name|counter9
decl_stmt|;
name|ib_net32_t
name|counter10
decl_stmt|;
name|ib_net32_t
name|counter11
decl_stmt|;
name|ib_net32_t
name|counter12
decl_stmt|;
name|ib_net32_t
name|counter13
decl_stmt|;
name|ib_net32_t
name|counter14
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_samples_result_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_port_xmit_data_sl * NAME *	ib_port_xmit_data_sl_t * * DESCRIPTION *       IBA defined PortXmitDataSL Attribute. (A13.6.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_xmit_data_sl
block|{
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|port_select
decl_stmt|;
name|ib_net16_t
name|counter_select
decl_stmt|;
name|ib_net32_t
name|port_xmit_data_sl
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|124
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_xmit_data_sl_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****s* IBA Base: Types/ib_port_rcv_data_sl * NAME *	ib_port_rcv_data_sl_t * * DESCRIPTION *	IBA defined PortRcvDataSL Attribute. (A13.6.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_rcv_data_sl
block|{
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|port_select
decl_stmt|;
name|ib_net16_t
name|counter_select
decl_stmt|;
name|ib_net32_t
name|port_rcv_data_sl
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|124
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_port_rcv_data_sl_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/****d* IBA Base: Types/DM_SVC_NAME * NAME *	DM_SVC_NAME * * DESCRIPTION *	IBA defined Device Management service name (16.3) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|DM_SVC_NAME
value|"DeviceManager.IBTA"
end_define

begin_comment
comment|/* * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_dm_mad_t * NAME *	ib_dm_mad_t * * DESCRIPTION *	IBA defined Device Management MAD (16.3.1) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_dm_mad
block|{
name|ib_mad_t
name|header
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|40
index|]
decl_stmt|;
define|#
directive|define
name|IB_DM_DATA_SIZE
value|192
name|uint8_t
name|data
index|[
name|IB_DM_DATA_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_dm_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	header *		Common MAD header. * *	resv *		Reserved. * *	data *		Device Management payload.  The structure and content of this field *		depend upon the method, attr_id, and attr_mod fields in the header. * * SEE ALSO * ib_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_iou_info_t * NAME *	ib_iou_info_t * * DESCRIPTION *	IBA defined IO Unit information structure (16.3.3.3) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_iou_info
block|{
name|ib_net16_t
name|change_id
decl_stmt|;
name|uint8_t
name|max_controllers
decl_stmt|;
name|uint8_t
name|diag_rom
decl_stmt|;
define|#
directive|define
name|IB_DM_CTRL_LIST_SIZE
value|128
name|uint8_t
name|controller_list
index|[
name|IB_DM_CTRL_LIST_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|IOC_NOT_INSTALLED
value|0x0
define|#
directive|define
name|IOC_INSTALLED
value|0x1
comment|//              Reserved values                         0x02-0xE
define|#
directive|define
name|SLOT_DOES_NOT_EXIST
value|0xF
block|}
name|PACK_SUFFIX
name|ib_iou_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	change_id *		Value incremented, with rollover, by any change to the controller_list. * *	max_controllers *		Number of slots in controller_list. * *	diag_rom *		A byte containing two fields: DiagDeviceID and OptionROM. *		These fields may be read using the ib_iou_info_diag_dev_id *		and ib_iou_info_option_rom functions. * *	controller_list *		A series of 4-bit nibbles, with each nibble representing a slot *		in the IO Unit.  Individual nibbles may be read using the *		ioc_at_slot function. * * SEE ALSO * ib_dm_mad_t, ib_iou_info_diag_dev_id, ib_iou_info_option_rom, ioc_at_slot *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_iou_info_diag_dev_id * NAME *	ib_iou_info_diag_dev_id * * DESCRIPTION *	Returns the DiagDeviceID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_iou_info_diag_dev_id
parameter_list|(
name|IN
specifier|const
name|ib_iou_info_t
modifier|*
specifier|const
name|p_iou_info
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_iou_info
operator|->
name|diag_rom
operator|>>
literal|6
operator|&
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_iou_info *		[in] Pointer to the IO Unit information structure. * * RETURN VALUES *	DiagDeviceID field of the IO Unit information. * * NOTES * * SEE ALSO *	ib_iou_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_iou_info_option_rom * NAME *	ib_iou_info_option_rom * * DESCRIPTION *	Returns the OptionROM. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ib_iou_info_option_rom
parameter_list|(
name|IN
specifier|const
name|ib_iou_info_t
modifier|*
specifier|const
name|p_iou_info
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint8_t
call|)
argument_list|(
name|p_iou_info
operator|->
name|diag_rom
operator|>>
literal|7
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_iou_info *		[in] Pointer to the IO Unit information structure. * * RETURN VALUES *	OptionROM field of the IO Unit information. * * NOTES * * SEE ALSO *	ib_iou_info_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ioc_at_slot * NAME *	ioc_at_slot * * DESCRIPTION *	Returns the IOC value at the specified slot. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|OSM_API
name|ioc_at_slot
parameter_list|(
name|IN
specifier|const
name|ib_iou_info_t
modifier|*
specifier|const
name|p_iou_info
parameter_list|,
name|IN
name|uint8_t
name|slot
parameter_list|)
block|{
if|if
condition|(
name|slot
operator|>=
name|IB_DM_CTRL_LIST_SIZE
condition|)
return|return
name|SLOT_DOES_NOT_EXIST
return|;
else|else
return|return
call|(
name|int8_t
call|)
argument_list|(
operator|(
name|slot
operator|%
literal|2
operator|)
condition|?
operator|(
operator|(
name|p_iou_info
operator|->
name|controller_list
index|[
name|slot
operator|/
literal|2
index|]
operator|&
literal|0xf0
operator|)
operator|>>
literal|4
operator|)
else|:
operator|(
name|p_iou_info
operator|->
name|controller_list
index|[
name|slot
operator|/
literal|2
index|]
operator|&
literal|0x0f
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_iou_info *		[in] Pointer to the IO Unit information structure. * *	slot *		[in] Pointer to the IO Unit information structure. * * RETURN VALUES *	OptionROM field of the IO Unit information. * * NOTES * * SEE ALSO *	ib_iou_info_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_ioc_profile_t * NAME *	ib_ioc_profile_t * * DESCRIPTION *	IBA defined IO Controller profile structure (16.3.3.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_ioc_profile
block|{
name|ib_net64_t
name|ioc_guid
decl_stmt|;
name|ib_net32_t
name|vend_id
decl_stmt|;
name|ib_net32_t
name|dev_id
decl_stmt|;
name|ib_net16_t
name|dev_ver
decl_stmt|;
name|ib_net16_t
name|resv2
decl_stmt|;
name|ib_net32_t
name|subsys_vend_id
decl_stmt|;
name|ib_net32_t
name|subsys_id
decl_stmt|;
name|ib_net16_t
name|io_class
decl_stmt|;
name|ib_net16_t
name|io_subclass
decl_stmt|;
name|ib_net16_t
name|protocol
decl_stmt|;
name|ib_net16_t
name|protocol_ver
decl_stmt|;
name|ib_net32_t
name|resv3
decl_stmt|;
name|ib_net16_t
name|send_msg_depth
decl_stmt|;
name|uint8_t
name|resv4
decl_stmt|;
name|uint8_t
name|rdma_read_depth
decl_stmt|;
name|ib_net32_t
name|send_msg_size
decl_stmt|;
name|ib_net32_t
name|rdma_size
decl_stmt|;
name|uint8_t
name|ctrl_ops_cap
decl_stmt|;
define|#
directive|define
name|CTRL_OPS_CAP_ST
value|0x01
define|#
directive|define
name|CTRL_OPS_CAP_SF
value|0x02
define|#
directive|define
name|CTRL_OPS_CAP_RT
value|0x04
define|#
directive|define
name|CTRL_OPS_CAP_RF
value|0x08
define|#
directive|define
name|CTRL_OPS_CAP_WT
value|0x10
define|#
directive|define
name|CTRL_OPS_CAP_WF
value|0x20
define|#
directive|define
name|CTRL_OPS_CAP_AT
value|0x40
define|#
directive|define
name|CTRL_OPS_CAP_AF
value|0x80
name|uint8_t
name|resv5
decl_stmt|;
name|uint8_t
name|num_svc_entries
decl_stmt|;
define|#
directive|define
name|MAX_NUM_SVC_ENTRIES
value|0xff
name|uint8_t
name|resv6
index|[
literal|9
index|]
decl_stmt|;
define|#
directive|define
name|CTRL_ID_STRING_LEN
value|64
name|char
name|id_string
index|[
name|CTRL_ID_STRING_LEN
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_ioc_profile_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	ioc_guid *		An EUI-64 GUID used to uniquely identify the IO controller. * *	vend_id *		IO controller vendor ID, IEEE format. * *	dev_id *		A number assigned by the vendor to identify the type of controller. * *	dev_ver *		A number assigned by the vendor to identify the divice version. * *	subsys_vend_id *		ID of the vendor of the enclosure, if any, in which the IO controller *		resides in IEEE format; otherwise zero. * *	subsys_id *		A number identifying the subsystem where the controller resides. * *	io_class *		0x0000 - 0xfffe = reserved for IO classes encompased by InfiniBand *		Architecture.  0xffff = Vendor specific. * *	io_subclass *		0x0000 - 0xfffe = reserved for IO subclasses encompased by InfiniBand *		Architecture.  0xffff = Vendor specific.  This shall be set to 0xfff *		if the io_class component is 0xffff. * *	protocol *		0x0000 - 0xfffe = reserved for IO subclasses encompased by InfiniBand *		Architecture.  0xffff = Vendor specific.  This shall be set to 0xfff *		if the io_class component is 0xffff. * *	protocol_ver *		Protocol specific. * *	send_msg_depth *		Maximum depth of the send message queue. * *	rdma_read_depth *		Maximum depth of the per-channel RDMA read queue. * *	send_msg_size *		Maximum size of send messages. * *	ctrl_ops_cap *		Supported operation types of this IO controller.  A bit set to one *		for affirmation of supported capability. * *	num_svc_entries *		Number of entries in the service entries table. * *	id_string *		UTF-8 encoded string for identifying the controller to an operator. * * SEE ALSO * ib_dm_mad_t *********/
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|OSM_API
name|ib_ioc_profile_get_vend_id
parameter_list|(
name|IN
specifier|const
name|ib_ioc_profile_t
modifier|*
specifier|const
name|p_ioc_profile
parameter_list|)
block|{
return|return
operator|(
name|cl_ntoh32
argument_list|(
name|p_ioc_profile
operator|->
name|vend_id
argument_list|)
operator|>>
literal|8
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_ioc_profile_set_vend_id
parameter_list|(
name|IN
name|ib_ioc_profile_t
modifier|*
specifier|const
name|p_ioc_profile
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|vend_id
parameter_list|)
block|{
name|p_ioc_profile
operator|->
name|vend_id
operator|=
operator|(
name|cl_hton32
argument_list|(
name|vend_id
argument_list|)
operator|<<
literal|8
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/****s* IBA Base: Types/ib_svc_entry_t * NAME *	ib_svc_entry_t * * DESCRIPTION *	IBA defined IO Controller service entry structure (16.3.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_svc_entry
block|{
define|#
directive|define
name|MAX_SVC_ENTRY_NAME_LEN
value|40
name|char
name|name
index|[
name|MAX_SVC_ENTRY_NAME_LEN
index|]
decl_stmt|;
name|ib_net64_t
name|id
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_svc_entry_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	name *		UTF-8 encoded, null-terminated name of the service. * *	id *		An identifier of the associated Service. * * SEE ALSO * ib_svc_entries_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_svc_entries_t * NAME *	ib_svc_entries_t * * DESCRIPTION *	IBA defined IO Controller service entry array (16.3.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_svc_entries
block|{
define|#
directive|define
name|SVC_ENTRY_COUNT
value|4
name|ib_svc_entry_t
name|service_entry
index|[
name|SVC_ENTRY_COUNT
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_svc_entries_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	service_entry *		An array of IO controller service entries. * * SEE ALSO * ib_dm_mad_t, ib_svc_entry_t *********/
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|OSM_API
name|ib_dm_get_slot_lo_hi
parameter_list|(
name|IN
specifier|const
name|ib_net32_t
name|slot_lo_hi
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_slot
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_lo
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_hi
parameter_list|)
block|{
name|ib_net32_t
name|tmp_slot_lo_hi
init|=
name|CL_NTOH32
argument_list|(
name|slot_lo_hi
argument_list|)
decl_stmt|;
if|if
condition|(
name|p_slot
condition|)
operator|*
name|p_slot
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|tmp_slot_lo_hi
operator|>>
literal|16
operator|)
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_hi
condition|)
operator|*
name|p_hi
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|tmp_slot_lo_hi
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_lo
condition|)
operator|*
name|p_lo
operator|=
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|tmp_slot_lo_hi
operator|>>
literal|0
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	IBA defined information describing an I/O controller  */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_ioc_info
block|{
name|ib_net64_t
name|module_guid
decl_stmt|;
name|ib_net64_t
name|iou_guid
decl_stmt|;
name|ib_ioc_profile_t
name|ioc_profile
decl_stmt|;
name|ib_net64_t
name|access_key
decl_stmt|;
name|uint16_t
name|initiators_conf
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|38
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_ioc_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/*  *	The following definitions are shared between the Access Layer and VPD  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ib_ca
modifier|*
name|__ptr64
name|ib_ca_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_pd
modifier|*
name|__ptr64
name|ib_pd_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_rdd
modifier|*
name|__ptr64
name|ib_rdd_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_mr
modifier|*
name|__ptr64
name|ib_mr_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_mw
modifier|*
name|__ptr64
name|ib_mw_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_qp
modifier|*
name|__ptr64
name|ib_qp_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_eec
modifier|*
name|__ptr64
name|ib_eec_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_cq
modifier|*
name|__ptr64
name|ib_cq_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_av
modifier|*
name|__ptr64
name|ib_av_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ib_mcast
modifier|*
name|__ptr64
name|ib_mcast_handle_t
typedef|;
end_typedef

begin_comment
comment|/* Currently for windows branch, use the extended version of ib special verbs struct 	in order to be compliant with Infinicon ib_types; later we'll change it to support 	OpenSM ib_types.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__WIN__
end_ifndef

begin_comment
comment|/****d* Access Layer/ib_api_status_t * NAME *	ib_api_status_t * * DESCRIPTION *	Function return codes indicating the success or failure of an API call. *	Note that success is indicated by the return value IB_SUCCESS, which *	is always zero. * * NOTES *	IB_VERBS_PROCESSING_DONE is used by UVP library to terminate a verbs call *	in the pre-ioctl step itself. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_api_status_t
block|{
name|IB_SUCCESS
block|,
name|IB_INSUFFICIENT_RESOURCES
block|,
name|IB_INSUFFICIENT_MEMORY
block|,
name|IB_INVALID_PARAMETER
block|,
name|IB_INVALID_SETTING
block|,
name|IB_NOT_FOUND
block|,
name|IB_TIMEOUT
block|,
name|IB_CANCELED
block|,
name|IB_INTERRUPTED
block|,
name|IB_INVALID_PERMISSION
block|,
name|IB_UNSUPPORTED
block|,
name|IB_OVERFLOW
block|,
name|IB_MAX_MCAST_QPS_REACHED
block|,
name|IB_INVALID_QP_STATE
block|,
name|IB_INVALID_EEC_STATE
block|,
name|IB_INVALID_APM_STATE
block|,
name|IB_INVALID_PORT_STATE
block|,
name|IB_INVALID_STATE
block|,
name|IB_RESOURCE_BUSY
block|,
name|IB_INVALID_PKEY
block|,
name|IB_INVALID_LKEY
block|,
name|IB_INVALID_RKEY
block|,
name|IB_INVALID_MAX_WRS
block|,
name|IB_INVALID_MAX_SGE
block|,
name|IB_INVALID_CQ_SIZE
block|,
name|IB_INVALID_SERVICE_TYPE
block|,
name|IB_INVALID_GID
block|,
name|IB_INVALID_LID
block|,
name|IB_INVALID_GUID
block|,
name|IB_INVALID_CA_HANDLE
block|,
name|IB_INVALID_AV_HANDLE
block|,
name|IB_INVALID_CQ_HANDLE
block|,
name|IB_INVALID_EEC_HANDLE
block|,
name|IB_INVALID_QP_HANDLE
block|,
name|IB_INVALID_PD_HANDLE
block|,
name|IB_INVALID_MR_HANDLE
block|,
name|IB_INVALID_MW_HANDLE
block|,
name|IB_INVALID_RDD_HANDLE
block|,
name|IB_INVALID_MCAST_HANDLE
block|,
name|IB_INVALID_CALLBACK
block|,
name|IB_INVALID_AL_HANDLE
block|,
comment|/* InfiniBand Access Layer */
name|IB_INVALID_HANDLE
block|,
comment|/* InfiniBand Access Layer */
name|IB_ERROR
block|,
comment|/* InfiniBand Access Layer */
name|IB_REMOTE_ERROR
block|,
comment|/* Infiniband Access Layer */
name|IB_VERBS_PROCESSING_DONE
block|,
comment|/* See Notes above         */
name|IB_INVALID_WR_TYPE
block|,
name|IB_QP_IN_TIMEWAIT
block|,
name|IB_EE_IN_TIMEWAIT
block|,
name|IB_INVALID_PORT
block|,
name|IB_NOT_DONE
block|,
name|IB_UNKNOWN_ERROR
comment|/* ALWAYS LAST ENUM VALUE! */
block|}
name|ib_api_status_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_decl_stmt
name|OSM_EXPORT
specifier|const
name|char
modifier|*
name|ib_error_str
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_err_str * NAME *	ib_get_err_str * * DESCRIPTION *	Returns a string for the specified status value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_err_str
parameter_list|(
name|IN
name|ib_api_status_t
name|status
parameter_list|)
block|{
if|if
condition|(
name|status
operator|>
name|IB_UNKNOWN_ERROR
condition|)
name|status
operator|=
name|IB_UNKNOWN_ERROR
expr_stmt|;
return|return
operator|(
name|ib_error_str
index|[
name|status
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	status *		[in] status value * * RETURN VALUES *	Pointer to the status description string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****d* Verbs/ib_async_event_t * NAME *	ib_async_event_t -- Async event types * * DESCRIPTION *	This type indicates the reason the async callback was called. *	The context in the ib_event_rec_t indicates the resource context *	that associated with the callback.  For example, for IB_AE_CQ_ERROR *	the context provided during the ib_create_cq is returned in the event. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_async_event_t
block|{
name|IB_AE_SQ_ERROR
init|=
literal|1
block|,
name|IB_AE_SQ_DRAINED
block|,
name|IB_AE_RQ_ERROR
block|,
name|IB_AE_CQ_ERROR
block|,
name|IB_AE_QP_FATAL
block|,
name|IB_AE_QP_COMM
block|,
name|IB_AE_QP_APM
block|,
name|IB_AE_EEC_FATAL
block|,
name|IB_AE_EEC_COMM
block|,
name|IB_AE_EEC_APM
block|,
name|IB_AE_LOCAL_FATAL
block|,
name|IB_AE_PKEY_TRAP
block|,
name|IB_AE_QKEY_TRAP
block|,
name|IB_AE_MKEY_TRAP
block|,
name|IB_AE_PORT_TRAP
block|,
name|IB_AE_SYSIMG_GUID_TRAP
block|,
name|IB_AE_BUF_OVERRUN
block|,
name|IB_AE_LINK_INTEGRITY
block|,
name|IB_AE_FLOW_CTRL_ERROR
block|,
name|IB_AE_BKEY_TRAP
block|,
name|IB_AE_QP_APM_ERROR
block|,
name|IB_AE_EEC_APM_ERROR
block|,
name|IB_AE_WQ_REQ_ERROR
block|,
name|IB_AE_WQ_ACCESS_ERROR
block|,
name|IB_AE_PORT_ACTIVE
block|,
name|IB_AE_PORT_DOWN
block|,
name|IB_AE_UNKNOWN
comment|/* ALWAYS LAST ENUM VALUE */
block|}
name|ib_async_event_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	IB_AE_SQ_ERROR *		An error occurred when accessing the send queue of the QP or EEC. *		This event is optional. * *	IB_AE_SQ_DRAINED *		The send queue of the specified QP has completed the outstanding *		messages in progress when the state change was requested and, if *		applicable, has received all acknowledgements for those messages. * *	IB_AE_RQ_ERROR *		An error occurred when accessing the receive queue of the QP or EEC. *		This event is optional. * *	IB_AE_CQ_ERROR *		An error occurred when writing an entry to the CQ. * *	IB_AE_QP_FATAL *		A catastrophic error occurred while accessing or processing the *		work queue that prevents reporting of completions. * *	IB_AE_QP_COMM *		The first packet has arrived for the receive work queue where the *		QP is still in the RTR state. * *	IB_AE_QP_APM *		If alternate path migration is supported, this event indicates that *		the QP connection has migrated to the alternate path. * *	IB_AE_EEC_FATAL *		If reliable datagram service is supported, this event indicates that *		a catastrophic error occurred while accessing or processing the EEC *		that prevents reporting of completions. * *	IB_AE_EEC_COMM *		If reliable datagram service is supported, this event indicates that *		the first packet has arrived for the receive work queue where the *		EEC is still in the RTR state. * *	IB_AE_EEC_APM *		If reliable datagram service and alternate path migration is supported, *		this event indicates that the EEC connection has migrated to the *		alternate path. * *	IB_AE_LOCAL_FATAL *		A catastrophic HCA error occurred which cannot be attributed to *		any resource; behavior is indeterminate. * *	IB_AE_PKEY_TRAP *		A PKEY violation was detected.  This event is optional. * *	IB_AE_QKEY_TRAP *		A QKEY violation was detected.  This event is optional. * *	IB_AE_MKEY_TRAP *		A MKEY violation was detected.  This event is optional. * *	IB_AE_PORT_TRAP *		A port capability change was detected.  This event is optional. * *	IB_AE_SYSIMG_GUID_TRAP *		If the system image GUID is supported, this event indicates that *		the system image GUID of this HCA has been changed.  This event *		is optional. * *	IB_AE_BUF_OVERRUN *		The number of consecutive flow control update periods with at least *		one overrun error in each period has exceeded the threshold specified *		in the port info attributes.  This event is optional. * *	IB_AE_LINK_INTEGRITY *		The detection of excessively frequent local physical errors has *		exceeded the threshold specified in the port info attributes.  This *		event is optional. * *	IB_AE_FLOW_CTRL_ERROR *		An HCA watchdog timer monitoring the arrival of flow control updates *		has expired without receiving an update.  This event is optional. * *	IB_AE_BKEY_TRAP *		An BKEY violation was detected.  This event is optional. * *	IB_AE_QP_APM_ERROR *		If alternate path migration is supported, this event indicates that *		an incoming path migration request to this QP was not accepted. * *	IB_AE_EEC_APM_ERROR *		If reliable datagram service and alternate path migration is supported, *		this event indicates that an incoming path migration request to this *		EEC was not accepted. * *	IB_AE_WQ_REQ_ERROR *		An OpCode violation was detected at the responder. * *	IB_AE_WQ_ACCESS_ERROR *		An access violation was detected at the responder. * *	IB_AE_PORT_ACTIVE *		If the port active event is supported, this event is generated *		when the link becomes active: IB_LINK_ACTIVE. * *	IB_AE_PORT_DOWN *		The link is declared unavailable: IB_LINK_INIT, IB_LINK_ARMED, *		IB_LINK_DOWN. * *	IB_AE_UNKNOWN *		An unknown error occurred which cannot be attributed to any *		resource; behavior is indeterminate. * *****/
end_comment

begin_decl_stmt
name|OSM_EXPORT
specifier|const
name|char
modifier|*
name|ib_async_event_str
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_async_event_str * NAME *	ib_get_async_event_str * * DESCRIPTION *	Returns a string for the specified asynchronous event. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_async_event_str
parameter_list|(
name|IN
name|ib_async_event_t
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|>
name|IB_AE_UNKNOWN
condition|)
name|event
operator|=
name|IB_AE_UNKNOWN
expr_stmt|;
return|return
operator|(
name|ib_async_event_str
index|[
name|event
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	event *		[in] event value * * RETURN VALUES *	Pointer to the asynchronous event description string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* Verbs/ib_event_rec_t * NAME *	ib_event_rec_t -- Async event notification record * * DESCRIPTION *	When an async event callback is made, this structure is passed to indicate *	the type of event, the source of event that caused it, and the context *	associated with this event. * *	context -- Context of the resource that caused the event. *		-- ca_context if this is a port/adapter event. *		-- qp_context if the source is a QP event *		-- cq_context if the source is a CQ event. *		-- ee_context if the source is an EE event. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_event_rec
block|{
name|void
modifier|*
name|context
decl_stmt|;
name|ib_async_event_t
name|type
decl_stmt|;
comment|/* HCA vendor specific event information. */
name|uint64_t
name|vendor_specific
decl_stmt|;
comment|/* The following structures are valid only for trap types. */
union|union
name|_trap
block|{
struct|struct
block|{
name|uint16_t
name|lid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
comment|/* 			 * The following structure is valid only for 			 * P_KEY, Q_KEY, and M_KEY violation traps. 			 */
struct|struct
block|{
name|uint8_t
name|sl
decl_stmt|;
name|uint16_t
name|src_lid
decl_stmt|;
name|uint16_t
name|dest_lid
decl_stmt|;
union|union
name|_key
block|{
name|uint16_t
name|pkey
decl_stmt|;
name|uint32_t
name|qkey
decl_stmt|;
name|uint64_t
name|mkey
decl_stmt|;
block|}
name|key
union|;
name|uint32_t
name|src_qp
decl_stmt|;
name|uint32_t
name|dest_qp
decl_stmt|;
name|ib_gid_t
name|src_gid
decl_stmt|;
name|ib_gid_t
name|dest_gid
decl_stmt|;
block|}
name|violation
struct|;
block|}
name|info
struct|;
name|ib_net64_t
name|sysimg_guid
decl_stmt|;
block|}
name|trap
union|;
block|}
name|ib_event_rec_t
typedef|;
end_typedef

begin_comment
comment|/*******/
end_comment

begin_comment
comment|/****d* Access Layer/ib_atomic_t * NAME *	ib_atomic_t * * DESCRIPTION *	Indicates atomicity levels supported by an adapter. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_atomic_t
block|{
name|IB_ATOMIC_NONE
block|,
name|IB_ATOMIC_LOCAL
block|,
name|IB_ATOMIC_GLOBAL
block|}
name|ib_atomic_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	IB_ATOMIC_NONE *		Atomic operations not supported. * *	IB_ATOMIC_LOCAL *		Atomic operations guaranteed between QPs of a single CA. * *	IB_ATOMIC_GLOBAL *		Atomic operations are guaranteed between CA and any other entity *		in the system. *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_port_cap_t * NAME *	ib_port_cap_t * * DESCRIPTION *	Indicates which management agents are currently available on the specified *	port. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_cap
block|{
name|boolean_t
name|cm
decl_stmt|;
name|boolean_t
name|snmp
decl_stmt|;
name|boolean_t
name|dev_mgmt
decl_stmt|;
name|boolean_t
name|vend
decl_stmt|;
name|boolean_t
name|sm
decl_stmt|;
name|boolean_t
name|sm_disable
decl_stmt|;
name|boolean_t
name|qkey_ctr
decl_stmt|;
name|boolean_t
name|pkey_ctr
decl_stmt|;
name|boolean_t
name|notice
decl_stmt|;
name|boolean_t
name|trap
decl_stmt|;
name|boolean_t
name|apm
decl_stmt|;
name|boolean_t
name|slmap
decl_stmt|;
name|boolean_t
name|pkey_nvram
decl_stmt|;
name|boolean_t
name|mkey_nvram
decl_stmt|;
name|boolean_t
name|sysguid
decl_stmt|;
name|boolean_t
name|dr_notice
decl_stmt|;
name|boolean_t
name|boot_mgmt
decl_stmt|;
name|boolean_t
name|capm_notice
decl_stmt|;
name|boolean_t
name|reinit
decl_stmt|;
name|boolean_t
name|ledinfo
decl_stmt|;
name|boolean_t
name|port_active
decl_stmt|;
block|}
name|ib_port_cap_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_init_type_t * NAME *	ib_init_type_t * * DESCRIPTION *	If supported by the HCA, the type of initialization requested by *	this port before SM moves it to the active or armed state.  If the *	SM implements reinitialization, it shall set these bits to indicate *	the type of initialization performed prior to activating the port. *	Otherwise, these bits shall be set to 0. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|ib_init_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_INIT_TYPE_NO_LOAD
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_INIT_TYPE_PRESERVE_CONTENT
value|0x02
end_define

begin_define
define|#
directive|define
name|IB_INIT_TYPE_PRESERVE_PRESENCE
value|0x04
end_define

begin_define
define|#
directive|define
name|IB_INIT_TYPE_DO_NOT_RESUSCITATE
value|0x08
end_define

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_port_attr_mod_t * NAME *	ib_port_attr_mod_t * * DESCRIPTION *	Port attributes that may be modified. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_attr_mod
block|{
name|ib_port_cap_t
name|cap
decl_stmt|;
name|uint16_t
name|pkey_ctr
decl_stmt|;
name|uint16_t
name|qkey_ctr
decl_stmt|;
name|ib_init_type_t
name|init_type
decl_stmt|;
name|ib_net64_t
name|system_image_guid
decl_stmt|;
block|}
name|ib_port_attr_mod_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_port_cap_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_port_attr_t * NAME *	ib_port_attr_t * * DESCRIPTION *	Information about a port on a given channel adapter. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_port_attr
block|{
name|ib_net64_t
name|port_guid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|uint8_t
name|mtu
decl_stmt|;
name|uint64_t
name|max_msg_size
decl_stmt|;
name|ib_net16_t
name|lid
decl_stmt|;
name|uint8_t
name|lmc
decl_stmt|;
comment|/* 	 * LinkWidthSupported as defined in PortInfo.  Required to calculate 	 * inter-packet delay (a.k.a. static rate). 	 */
name|uint8_t
name|link_width_supported
decl_stmt|;
name|uint16_t
name|max_vls
decl_stmt|;
name|ib_net16_t
name|sm_lid
decl_stmt|;
name|uint8_t
name|sm_sl
decl_stmt|;
name|uint8_t
name|link_state
decl_stmt|;
name|ib_init_type_t
name|init_type_reply
decl_stmt|;
comment|/* Optional */
comment|/* 	 * subnet_timeout: 	 * The maximum expected subnet propagation delay to reach any port on 	 * the subnet.  This value also determines the rate at which traps can 	 * be generated from this node. 	 * 	 * timeout = 4.096 microseconds * 2^subnet_timeout 	 */
name|uint8_t
name|subnet_timeout
decl_stmt|;
name|ib_port_cap_t
name|cap
decl_stmt|;
name|uint16_t
name|pkey_ctr
decl_stmt|;
name|uint16_t
name|qkey_ctr
decl_stmt|;
name|uint16_t
name|num_gids
decl_stmt|;
name|uint16_t
name|num_pkeys
decl_stmt|;
comment|/* 	 * Pointers at the end of the structure to allow doing a simple 	 * memory comparison of contents up to the first pointer. 	 */
name|ib_gid_t
modifier|*
name|p_gid_table
decl_stmt|;
name|ib_net16_t
modifier|*
name|p_pkey_table
decl_stmt|;
block|}
name|ib_port_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	uint8_t, ib_port_cap_t, ib_link_states_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_ca_attr_t * NAME *	ib_ca_attr_t * * DESCRIPTION *	Information about a channel adapter. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_ca_attr
block|{
name|ib_net64_t
name|ca_guid
decl_stmt|;
name|uint32_t
name|vend_id
decl_stmt|;
name|uint16_t
name|dev_id
decl_stmt|;
name|uint16_t
name|revision
decl_stmt|;
name|uint64_t
name|fw_ver
decl_stmt|;
comment|/* 	 * Total size of the ca attributes in bytes 	 */
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|max_qps
decl_stmt|;
name|uint32_t
name|max_wrs
decl_stmt|;
name|uint32_t
name|max_sges
decl_stmt|;
name|uint32_t
name|max_rd_sges
decl_stmt|;
name|uint32_t
name|max_cqs
decl_stmt|;
name|uint32_t
name|max_cqes
decl_stmt|;
name|uint32_t
name|max_pds
decl_stmt|;
name|uint32_t
name|init_regions
decl_stmt|;
name|uint64_t
name|init_region_size
decl_stmt|;
name|uint32_t
name|init_windows
decl_stmt|;
name|uint32_t
name|max_addr_handles
decl_stmt|;
name|uint32_t
name|max_partitions
decl_stmt|;
name|ib_atomic_t
name|atomicity
decl_stmt|;
name|uint8_t
name|max_qp_resp_res
decl_stmt|;
name|uint8_t
name|max_eec_resp_res
decl_stmt|;
name|uint8_t
name|max_resp_res
decl_stmt|;
name|uint8_t
name|max_qp_init_depth
decl_stmt|;
name|uint8_t
name|max_eec_init_depth
decl_stmt|;
name|uint32_t
name|max_eecs
decl_stmt|;
name|uint32_t
name|max_rdds
decl_stmt|;
name|uint32_t
name|max_ipv6_qps
decl_stmt|;
name|uint32_t
name|max_ether_qps
decl_stmt|;
name|uint32_t
name|max_mcast_grps
decl_stmt|;
name|uint32_t
name|max_mcast_qps
decl_stmt|;
name|uint32_t
name|max_qps_per_mcast_grp
decl_stmt|;
name|uint32_t
name|max_fmr
decl_stmt|;
name|uint32_t
name|max_map_per_fmr
decl_stmt|;
comment|/* 	 * local_ack_delay: 	 * Specifies the maximum time interval between the local CA receiving 	 * a message and the transmission of the associated ACK or NAK. 	 * 	 * timeout = 4.096 microseconds * 2^local_ack_delay 	 */
name|uint8_t
name|local_ack_delay
decl_stmt|;
name|boolean_t
name|bad_pkey_ctr_support
decl_stmt|;
name|boolean_t
name|bad_qkey_ctr_support
decl_stmt|;
name|boolean_t
name|raw_mcast_support
decl_stmt|;
name|boolean_t
name|apm_support
decl_stmt|;
name|boolean_t
name|av_port_check
decl_stmt|;
name|boolean_t
name|change_primary_port
decl_stmt|;
name|boolean_t
name|modify_wr_depth
decl_stmt|;
name|boolean_t
name|current_qp_state_support
decl_stmt|;
name|boolean_t
name|shutdown_port_capability
decl_stmt|;
name|boolean_t
name|init_type_support
decl_stmt|;
name|boolean_t
name|port_active_event_support
decl_stmt|;
name|boolean_t
name|system_image_guid_support
decl_stmt|;
name|boolean_t
name|hw_agents
decl_stmt|;
name|ib_net64_t
name|system_image_guid
decl_stmt|;
name|uint32_t
name|num_page_sizes
decl_stmt|;
name|uint8_t
name|num_ports
decl_stmt|;
name|uint32_t
modifier|*
name|p_page_size
decl_stmt|;
name|ib_port_attr_t
modifier|*
name|p_port_attr
decl_stmt|;
block|}
name|ib_ca_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	ca_guid *		GUID for this adapter. * *	vend_id *		IEEE vendor ID for this adapter * *	dev_id *		Device ID of this adapter. (typically from PCI device ID) * *	revision *		Revision ID of this adapter * *	fw_ver *		Device Firmware version. * *	size *		Total size in bytes for the HCA attributes.  This size includes total *		size required for all the variable members of the structure.  If a *		vendor requires to pass vendor specific fields beyond this structure, *		the HCA vendor can choose to report a larger size.  If a vendor is *		reporting extended vendor specific features, they should also provide *		appropriate access functions to aid with the required interpretation. * *	max_qps *		Maximum number of QP's supported by this HCA. * *	max_wrs *		Maximum number of work requests supported by this HCA. * *	max_sges *		Maximum number of scatter gather elements supported per work request. * *	max_rd_sges *		Maximum number of scatter gather elements supported for READ work *		requests for a Reliable Datagram QP.  This value must be zero if RD *		service is not supported. * *	max_cqs *		Maximum number of Completion Queues supported. * *	max_cqes *		Maximum number of CQ elements supported per CQ. * *	max_pds *		Maximum number of protection domains supported. * *	init_regions *		Initial number of memory regions supported.  These are only informative *		values.  HCA vendors can extended and grow these limits on demand. * *	init_region_size *		Initial limit on the size of the registered memory region. * *	init_windows *		Initial number of window entries supported. * *	max_addr_handles *		Maximum number of address handles supported. * *	max_partitions *		Maximum number of partitions supported. * *	atomicity *		Indicates level of atomic operations supported by this HCA. * *	max_qp_resp_res *	max_eec_resp_res *		Maximum limit on number of responder resources for incoming RDMA *		operations, on QPs and EEC's respectively. * *	max_resp_res *		Maximum number of responder resources per HCA, with this HCA used as *		the target. * *	max_qp_init_depth *	max_eec_init_depth *		Maximimum initiator depth per QP or EEC for initiating RDMA reads and *		atomic operations. * *	max_eecs *		Maximimum number of EEC's supported by the HCA. * *	max_rdds *		Maximum number of Reliable datagram domains supported. * *	max_ipv6_qps *	max_ether_qps *		Maximum number of IPV6 and raw ether QP's supported by this HCA. * *	max_mcast_grps *		Maximum number of multicast groups supported. * *	max_mcast_qps *		Maximum number of QP's that can support multicast operations. * *	max_qps_per_mcast_grp *		Maximum number of multicast QP's per multicast group. * *	local_ack_delay *		Specifies the maximum time interval between the local CA receiving *		a message and the transmission of the associated ACK or NAK. *		timeout = 4.096 microseconds * 2^local_ack_delay * *	bad_pkey_ctr_support *	bad_qkey_ctr_support *		Indicates support for the bad pkey and qkey counters. * *	raw_mcast_support *		Indicates support for raw packet multicast. * *	apm_support *		Indicates support for Automatic Path Migration. * *	av_port_check *		Indicates ability to check port number in address handles. * *	change_primary_port *		Indicates ability to change primary port for a QP or EEC during a *		SQD->RTS transition. * *	modify_wr_depth *		Indicates ability to modify QP depth during a modify QP operation. *		Check the verb specification for permitted states. * *	current_qp_state_support *		Indicates ability of the HCA to support the current QP state modifier *		during a modify QP operation. * *	shutdown_port_capability *		Shutdown port capability support indicator. * *	init_type_support *		Indicates init_type_reply and ability to set init_type is supported. * *	port_active_event_support *		Port active event support indicator. * *	system_image_guid_support *		System image GUID support indicator. * *	hw_agents *		Indicates SMA is implemented in HW. * *	system_image_guid *		Optional system image GUID.  This field is valid only if the *		system_image_guid_support flag is set. * *	num_page_sizes *		Indicates support for different page sizes supported by the HCA. *		The variable size array can be obtained from p_page_size. * *	num_ports *		Number of physical ports supported on this HCA. * *	p_page_size *		Array holding different page size supported. * *	p_port_attr *		Array holding port attributes. * * NOTES *	This structure contains the attributes of a channel adapter.  Users must *	call ib_copy_ca_attr to copy the contents of this structure to a new *	memory region. * * SEE ALSO *	ib_port_attr_t, ib_atomic_t, ib_copy_ca_attr *****/
end_comment

begin_comment
comment|/****f* Access layer/ib_copy_ca_attr * NAME *	ib_copy_ca_attr * * DESCRIPTION *	Copies CA attributes. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_ca_attr_t
modifier|*
name|ib_copy_ca_attr
parameter_list|(
name|IN
name|ib_ca_attr_t
modifier|*
specifier|const
name|p_dest
parameter_list|,
name|IN
specifier|const
name|ib_ca_attr_t
modifier|*
specifier|const
name|p_src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_dest *		Pointer to the buffer that is the destination of the copy. * *	p_src *		Pointer to the CA attributes to copy. * * RETURN VALUE *	Pointer to the copied CA attributes. * * NOTES *	The buffer pointed to by the p_dest parameter must be at least the size *	specified in the size field of the buffer pointed to by p_src. * * SEE ALSO *	ib_ca_attr_t, ib_dup_ca_attr, ib_free_ca_attr *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_av_attr_t * NAME *	ib_av_attr_t * * DESCRIPTION *	IBA address vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_av_attr
block|{
name|uint8_t
name|port_num
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|ib_net16_t
name|dlid
decl_stmt|;
name|boolean_t
name|grh_valid
decl_stmt|;
name|ib_grh_t
name|grh
decl_stmt|;
name|uint8_t
name|static_rate
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
struct|struct
name|_av_conn
block|{
name|uint8_t
name|path_mtu
decl_stmt|;
name|uint8_t
name|local_ack_timeout
decl_stmt|;
name|uint8_t
name|seq_err_retry_cnt
decl_stmt|;
name|uint8_t
name|rnr_retry_cnt
decl_stmt|;
block|}
name|conn
struct|;
block|}
name|ib_av_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_gid_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_qp_type_t * NAME *	ib_qp_type_t * * DESCRIPTION *	Indicates the type of queue pair being created. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_qp_type
block|{
name|IB_QPT_RELIABLE_CONN
init|=
literal|0
block|,
comment|/* Matches CM REQ transport type */
name|IB_QPT_UNRELIABLE_CONN
init|=
literal|1
block|,
comment|/* Matches CM REQ transport type */
name|IB_QPT_RELIABLE_DGRM
init|=
literal|2
block|,
comment|/* Matches CM REQ transport type */
name|IB_QPT_UNRELIABLE_DGRM
block|,
name|IB_QPT_QP0
block|,
name|IB_QPT_QP1
block|,
name|IB_QPT_RAW_IPV6
block|,
name|IB_QPT_RAW_ETHER
block|,
name|IB_QPT_MAD
block|,
comment|/* InfiniBand Access Layer */
name|IB_QPT_QP0_ALIAS
block|,
comment|/* InfiniBand Access Layer */
name|IB_QPT_QP1_ALIAS
comment|/* InfiniBand Access Layer */
block|}
name|ib_qp_type_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	IB_QPT_RELIABLE_CONN *		Reliable, connected queue pair. * *	IB_QPT_UNRELIABLE_CONN *		Unreliable, connected queue pair. * *	IB_QPT_RELIABLE_DGRM *		Reliable, datagram queue pair. * *	IB_QPT_UNRELIABLE_DGRM *		Unreliable, datagram queue pair. * *	IB_QPT_QP0 *		Queue pair 0. * *	IB_QPT_QP1 *		Queue pair 1. * *	IB_QPT_RAW_DGRM *		Raw datagram queue pair. * *	IB_QPT_RAW_IPV6 *		Raw IP version 6 queue pair. * *	IB_QPT_RAW_ETHER *		Raw Ethernet queue pair. * *	IB_QPT_MAD *		Unreliable, datagram queue pair that will send and receive management *		datagrams with assistance from the access layer. * *	IB_QPT_QP0_ALIAS *		Alias to queue pair 0.  Aliased QPs can only be created on an aliased *		protection domain. * *	IB_QPT_QP1_ALIAS *		Alias to queue pair 1.  Aliased QPs can only be created on an aliased *		protection domain. *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_access_t * NAME *	ib_access_t * * DESCRIPTION *	Indicates the type of access is permitted on resources such as QPs, *	memory regions and memory windows. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_access_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_AC_RDMA_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_AC_RDMA_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_AC_ATOMIC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_AC_LOCAL_WRITE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_AC_MW_BIND
value|0x00000010
end_define

begin_comment
comment|/* * NOTES *	Users may combine access rights using a bit-wise or operation to specify *	additional access.  For example: IB_AC_RDMA_READ | IB_AC_RDMA_WRITE grants *	RDMA read and write access. *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_qp_state_t * NAME *	ib_qp_state_t * * DESCRIPTION *	Indicates or sets the state of a queue pair.  The current state of a queue *	pair is returned through the ib_qp_query call and set via the *	ib_qp_modify call. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_qp_state_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_QPS_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_QPS_INIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_QPS_RTR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_QPS_RTS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_QPS_SQD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IB_QPS_SQD_DRAINING
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IB_QPS_SQD_DRAINED
value|0x00000050
end_define

begin_define
define|#
directive|define
name|IB_QPS_SQERR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IB_QPS_ERROR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IB_QPS_TIME_WAIT
value|0xDEAD0000
end_define

begin_comment
comment|/* InfiniBand Access Layer */
end_comment

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_apm_state_t * NAME *	ib_apm_state_t * * DESCRIPTION *	The current automatic path migration state of a queue pair * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_apm_state
block|{
name|IB_APM_MIGRATED
init|=
literal|1
block|,
name|IB_APM_REARM
block|,
name|IB_APM_ARMED
block|}
name|ib_apm_state_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_qp_create_t * NAME *	ib_qp_create_t * * DESCRIPTION *	Attributes used to initialize a queue pair at creation time. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_qp_create
block|{
name|ib_qp_type_t
name|qp_type
decl_stmt|;
name|ib_rdd_handle_t
name|h_rdd
decl_stmt|;
name|uint32_t
name|sq_depth
decl_stmt|;
name|uint32_t
name|rq_depth
decl_stmt|;
name|uint32_t
name|sq_sge
decl_stmt|;
name|uint32_t
name|rq_sge
decl_stmt|;
name|ib_cq_handle_t
name|h_sq_cq
decl_stmt|;
name|ib_cq_handle_t
name|h_rq_cq
decl_stmt|;
name|boolean_t
name|sq_signaled
decl_stmt|;
block|}
name|ib_qp_create_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	type *		Specifies the type of queue pair to create. * *	h_rdd *		A handle to a reliable datagram domain to associate with the queue *		pair.  This field is ignored if the queue pair is not a reliable *		datagram type queue pair. * *	sq_depth *		Indicates the requested maximum number of work requests that may be *		outstanding on the queue pair's send queue.  This value must be less *		than or equal to the maximum reported by the channel adapter associated *		with the queue pair. * *	rq_depth *		Indicates the requested maximum number of work requests that may be *		outstanding on the queue pair's receive queue.  This value must be less *		than or equal to the maximum reported by the channel adapter associated *		with the queue pair. * *	sq_sge *		Indicates the maximum number scatter-gather elements that may be *		given in a send work request.  This value must be less *		than or equal to the maximum reported by the channel adapter associated *		with the queue pair. * *	rq_sge *		Indicates the maximum number scatter-gather elements that may be *		given in a receive work request.  This value must be less *		than or equal to the maximum reported by the channel adapter associated *		with the queue pair. * *	h_sq_cq *		A handle to the completion queue that will be used to report send work *		request completions.  This handle must be NULL if the type is *		IB_QPT_MAD, IB_QPT_QP0_ALIAS, or IB_QPT_QP1_ALIAS. * *	h_rq_cq *		A handle to the completion queue that will be used to report receive *		work request completions.  This handle must be NULL if the type is *		IB_QPT_MAD, IB_QPT_QP0_ALIAS, or IB_QPT_QP1_ALIAS. * *	sq_signaled *		A flag that is used to indicate whether the queue pair will signal *		an event upon completion of a send work request.  If set to *		TRUE, send work requests will always generate a completion *		event.  If set to FALSE, a completion event will only be *		generated if the send_opt field of the send work request has the *		IB_SEND_OPT_SIGNALED flag set. * * SEE ALSO *	ib_qp_type_t, ib_qp_attr_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_qp_attr_t * NAME *	ib_qp_attr_t * * DESCRIPTION *	Queue pair attributes returned through ib_query_qp. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_qp_attr
block|{
name|ib_pd_handle_t
name|h_pd
decl_stmt|;
name|ib_qp_type_t
name|qp_type
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|uint32_t
name|sq_depth
decl_stmt|;
name|uint32_t
name|rq_depth
decl_stmt|;
name|uint32_t
name|sq_sge
decl_stmt|;
name|uint32_t
name|rq_sge
decl_stmt|;
name|uint8_t
name|init_depth
decl_stmt|;
name|uint8_t
name|resp_res
decl_stmt|;
name|ib_cq_handle_t
name|h_sq_cq
decl_stmt|;
name|ib_cq_handle_t
name|h_rq_cq
decl_stmt|;
name|ib_rdd_handle_t
name|h_rdd
decl_stmt|;
name|boolean_t
name|sq_signaled
decl_stmt|;
name|ib_qp_state_t
name|state
decl_stmt|;
name|ib_net32_t
name|num
decl_stmt|;
name|ib_net32_t
name|dest_num
decl_stmt|;
name|ib_net32_t
name|qkey
decl_stmt|;
name|ib_net32_t
name|sq_psn
decl_stmt|;
name|ib_net32_t
name|rq_psn
decl_stmt|;
name|uint8_t
name|primary_port
decl_stmt|;
name|uint8_t
name|alternate_port
decl_stmt|;
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|ib_apm_state_t
name|apm_state
decl_stmt|;
block|}
name|ib_qp_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	h_pd *		This is a handle to a protection domain associated with the queue *		pair, or NULL if the queue pair is type IB_QPT_RELIABLE_DGRM. * * NOTES *	Other fields are defined by the Infiniband specification. * * SEE ALSO *	ib_qp_type_t, ib_access_t, ib_qp_state_t, ib_av_attr_t, ib_apm_state_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_qp_opts_t * NAME *	ib_qp_opts_t * * DESCRIPTION *	Optional fields supplied in the modify QP operation. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_qp_opts_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_MOD_QP_ALTERNATE_AV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_PKEY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_APM_STATE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_PRIMARY_AV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_RNR_NAK_TIMEOUT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_RESP_RES
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_INIT_DEPTH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_PRIMARY_PORT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_ACCESS_CTRL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_QKEY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_SQ_DEPTH
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_RQ_DEPTH
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_CURRENT_STATE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_RETRY_CNT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_LOCAL_ACK_TIMEOUT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IB_MOD_QP_RNR_RETRY_CNT
value|0x00008000
end_define

begin_comment
comment|/* * SEE ALSO *	ib_qp_mod_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_qp_mod_t * NAME *	ib_qp_mod_t * * DESCRIPTION *	Information needed to change the state of a queue pair through the *	ib_modify_qp call. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_qp_mod
block|{
name|ib_qp_state_t
name|req_state
decl_stmt|;
union|union
name|_qp_state
block|{
struct|struct
name|_qp_reset
block|{
comment|/* 			 * Time, in milliseconds, that the QP needs to spend in 			 * the time wait state before being reused. 			 */
name|uint32_t
name|timewait
decl_stmt|;
block|}
name|reset
struct|;
struct|struct
name|_qp_init
block|{
name|ib_qp_opts_t
name|opts
decl_stmt|;
name|uint8_t
name|primary_port
decl_stmt|;
name|ib_net32_t
name|qkey
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
block|}
name|init
struct|;
struct|struct
name|_qp_rtr
block|{
name|ib_net32_t
name|rq_psn
decl_stmt|;
name|ib_net32_t
name|dest_qp
decl_stmt|;
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|uint8_t
name|resp_res
decl_stmt|;
name|ib_qp_opts_t
name|opts
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|ib_net32_t
name|qkey
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
name|uint32_t
name|sq_depth
decl_stmt|;
name|uint32_t
name|rq_depth
decl_stmt|;
name|uint8_t
name|rnr_nak_timeout
decl_stmt|;
block|}
name|rtr
struct|;
struct|struct
name|_qp_rts
block|{
name|ib_net32_t
name|sq_psn
decl_stmt|;
name|uint8_t
name|retry_cnt
decl_stmt|;
name|uint8_t
name|rnr_retry_cnt
decl_stmt|;
name|uint8_t
name|rnr_nak_timeout
decl_stmt|;
name|uint8_t
name|local_ack_timeout
decl_stmt|;
name|uint8_t
name|init_depth
decl_stmt|;
name|ib_qp_opts_t
name|opts
decl_stmt|;
name|ib_qp_state_t
name|current_state
decl_stmt|;
name|ib_net32_t
name|qkey
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
name|uint8_t
name|resp_res
decl_stmt|;
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|uint32_t
name|sq_depth
decl_stmt|;
name|uint32_t
name|rq_depth
decl_stmt|;
name|ib_apm_state_t
name|apm_state
decl_stmt|;
name|uint8_t
name|primary_port
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
block|}
name|rts
struct|;
struct|struct
name|_qp_sqd
block|{
name|boolean_t
name|sqd_event
decl_stmt|;
block|}
name|sqd
struct|;
block|}
name|state
union|;
block|}
name|ib_qp_mod_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_qp_state_t, ib_access_t, ib_av_attr_t, ib_apm_state_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_eec_attr_t * NAME *	ib_eec_attr_t * * DESCRIPTION *	Information about an end-to-end context. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_eec_attr
block|{
name|ib_qp_state_t
name|state
decl_stmt|;
name|ib_rdd_handle_t
name|h_rdd
decl_stmt|;
name|ib_net32_t
name|local_eecn
decl_stmt|;
name|ib_net32_t
name|sq_psn
decl_stmt|;
name|ib_net32_t
name|rq_psn
decl_stmt|;
name|uint8_t
name|primary_port
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|uint32_t
name|resp_res
decl_stmt|;
name|ib_net32_t
name|remote_eecn
decl_stmt|;
name|uint32_t
name|init_depth
decl_stmt|;
name|uint32_t
name|dest_num
decl_stmt|;
comment|// ??? What is this?
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|ib_apm_state_t
name|apm_state
decl_stmt|;
block|}
name|ib_eec_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_qp_state_t, ib_av_attr_t, ib_apm_state_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_eec_opts_t * NAME *	ib_eec_opts_t * * DESCRIPTION *	Optional fields supplied in the modify EEC operation. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_eec_opts_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_MOD_EEC_ALTERNATE_AV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_PKEY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_APM_STATE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_PRIMARY_AV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_RNR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_RESP_RES
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_OUTSTANDING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IB_MOD_EEC_PRIMARY_PORT
value|0x00000080
end_define

begin_comment
comment|/* * NOTES * * *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_eec_mod_t * NAME *	ib_eec_mod_t * * DESCRIPTION *	Information needed to change the state of an end-to-end context through *	the ib_modify_eec function. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_eec_mod
block|{
name|ib_qp_state_t
name|req_state
decl_stmt|;
union|union
name|_eec_state
block|{
struct|struct
name|_eec_init
block|{
name|uint8_t
name|primary_port
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
block|}
name|init
struct|;
struct|struct
name|_eec_rtr
block|{
name|ib_net32_t
name|rq_psn
decl_stmt|;
name|ib_net32_t
name|remote_eecn
decl_stmt|;
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|uint8_t
name|resp_res
decl_stmt|;
name|ib_eec_opts_t
name|opts
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
block|}
name|rtr
struct|;
struct|struct
name|_eec_rts
block|{
name|ib_net32_t
name|sq_psn
decl_stmt|;
name|uint8_t
name|retry_cnt
decl_stmt|;
name|uint8_t
name|rnr_retry_cnt
decl_stmt|;
name|uint8_t
name|local_ack_timeout
decl_stmt|;
name|uint8_t
name|init_depth
decl_stmt|;
name|ib_eec_opts_t
name|opts
decl_stmt|;
name|ib_av_attr_t
name|alternate_av
decl_stmt|;
name|ib_apm_state_t
name|apm_state
decl_stmt|;
name|ib_av_attr_t
name|primary_av
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|uint8_t
name|primary_port
decl_stmt|;
block|}
name|rts
struct|;
struct|struct
name|_eec_sqd
block|{
name|boolean_t
name|sqd_event
decl_stmt|;
block|}
name|sqd
struct|;
block|}
name|state
union|;
block|}
name|ib_eec_mod_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_qp_state_t, ib_av_attr_t, ib_apm_state_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_wr_type_t * NAME *	ib_wr_type_t * * DESCRIPTION *	Identifies the type of work request posted to a queue pair. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_wr_type_t
block|{
name|WR_SEND
init|=
literal|1
block|,
name|WR_RDMA_WRITE
block|,
name|WR_RDMA_READ
block|,
name|WR_COMPARE_SWAP
block|,
name|WR_FETCH_ADD
block|}
name|ib_wr_type_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_local_ds_t * NAME *	ib_local_ds_t * * DESCRIPTION *	Local data segment information referenced by send and receive work *	requests.  This is used to specify local data buffers used as part of a *	work request. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_local_ds
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|lkey
decl_stmt|;
block|}
name|ib_local_ds_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_send_opt_t * NAME *	ib_send_opt_t * * DESCRIPTION *	Optional flags used when posting send work requests.  These flags *	indicate specific processing for the send operation. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_send_opt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_SEND_OPT_IMMEDIATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_FENCE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_SIGNALED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_SOLICITED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_INLINE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_LOCAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IB_SEND_OPT_VEND_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* * VALUES *	The following flags determine the behavior of a work request when *	posted to the send side. * *	IB_SEND_OPT_IMMEDIATE *		Send immediate data with the given request. * *	IB_SEND_OPT_FENCE *		The operation is fenced.  Complete all pending send operations *		before processing this request. * *	IB_SEND_OPT_SIGNALED *		If the queue pair is configured for signaled completion, then *		generate a completion queue entry when this request completes. * *	IB_SEND_OPT_SOLICITED *		Set the solicited bit on the last packet of this request. * *	IB_SEND_OPT_INLINE *		Indicates that the requested send data should be copied into a VPD *		owned data buffer.  This flag permits the user to issue send operations *		without first needing to register the buffer(s) associated with the *		send operation.  Verb providers that support this operation may place *		vendor specific restrictions on the size of send operation that may *		be performed as inline. * * *  IB_SEND_OPT_LOCAL *     Indicates that a sent MAD request should be given to the local VPD for *     processing.  MADs sent using this option are not placed on the wire. *     This send option is only valid for MAD send operations. * * *	IB_SEND_OPT_VEND_MASK *		This mask indicates bits reserved in the send options that may be used *		by the verbs provider to indicate vendor specific options.  Bits set *		in this area of the send options are ignored by the Access Layer, but *		may have specific meaning to the underlying VPD. * *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_send_wr_t * NAME *	ib_send_wr_t * * DESCRIPTION *	Information used to submit a work request to the send queue of a queue *	pair. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_send_wr
block|{
name|struct
name|_ib_send_wr
modifier|*
name|p_next
decl_stmt|;
name|uint64_t
name|wr_id
decl_stmt|;
name|ib_wr_type_t
name|wr_type
decl_stmt|;
name|ib_send_opt_t
name|send_opt
decl_stmt|;
name|uint32_t
name|num_ds
decl_stmt|;
name|ib_local_ds_t
modifier|*
name|ds_array
decl_stmt|;
name|ib_net32_t
name|immediate_data
decl_stmt|;
union|union
name|_send_dgrm
block|{
struct|struct
name|_send_ud
block|{
name|ib_net32_t
name|remote_qp
decl_stmt|;
name|ib_net32_t
name|remote_qkey
decl_stmt|;
name|ib_av_handle_t
name|h_av
decl_stmt|;
block|}
name|ud
struct|;
struct|struct
name|_send_rd
block|{
name|ib_net32_t
name|remote_qp
decl_stmt|;
name|ib_net32_t
name|remote_qkey
decl_stmt|;
name|ib_net32_t
name|eecn
decl_stmt|;
block|}
name|rd
struct|;
struct|struct
name|_send_raw_ether
block|{
name|ib_net16_t
name|dest_lid
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|uint8_t
name|max_static_rate
decl_stmt|;
name|ib_net16_t
name|ether_type
decl_stmt|;
block|}
name|raw_ether
struct|;
struct|struct
name|_send_raw_ipv6
block|{
name|ib_net16_t
name|dest_lid
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|uint8_t
name|max_static_rate
decl_stmt|;
block|}
name|raw_ipv6
struct|;
block|}
name|dgrm
union|;
struct|struct
name|_send_remote_ops
block|{
name|uint64_t
name|vaddr
decl_stmt|;
name|uint32_t
name|rkey
decl_stmt|;
name|ib_net64_t
name|atomic1
decl_stmt|;
name|ib_net64_t
name|atomic2
decl_stmt|;
block|}
name|remote_ops
struct|;
block|}
name|ib_send_wr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_next *		A pointer used to chain work requests together.  This permits multiple *		work requests to be posted to a queue pair through a single function *		call.  This value is set to NULL to mark the end of the chain. * *	wr_id *		A 64-bit work request identifier that is returned to the consumer *		as part of the work completion. * *	wr_type *		The type of work request being submitted to the send queue. * *	send_opt *		Optional send control parameters. * *	num_ds *		Number of local data segments specified by this work request. * *	ds_array *		A reference to an array of local data segments used by the send *		operation. * *	immediate_data *		32-bit field sent as part of a message send or RDMA write operation. *		This field is only valid if the send_opt flag IB_SEND_OPT_IMMEDIATE *		has been set. * *	dgrm.ud.remote_qp *		Identifies the destination queue pair of an unreliable datagram send *		operation. * *	dgrm.ud.remote_qkey *		The qkey for the destination queue pair. * *	dgrm.ud.h_av *		An address vector that specifies the path information used to route *		the outbound datagram to the destination queue pair. * *	dgrm.rd.remote_qp *		Identifies the destination queue pair of a reliable datagram send *		operation. * *	dgrm.rd.remote_qkey *		The qkey for the destination queue pair. * *	dgrm.rd.eecn *		The local end-to-end context number to use with the reliable datagram *		send operation. * *	dgrm.raw_ether.dest_lid *		The destination LID that will receive this raw ether send. * *	dgrm.raw_ether.path_bits *		path bits... * *	dgrm.raw_ether.sl *		service level... * *	dgrm.raw_ether.max_static_rate *		static rate... * *	dgrm.raw_ether.ether_type *		ether type... * *	dgrm.raw_ipv6.dest_lid *		The destination LID that will receive this raw ether send. * *	dgrm.raw_ipv6.path_bits *		path bits... * *	dgrm.raw_ipv6.sl *		service level... * *	dgrm.raw_ipv6.max_static_rate *		static rate... * *	remote_ops.vaddr *		The registered virtual memory address of the remote memory to access *		with an RDMA or atomic operation. * *	remote_ops.rkey *		The rkey associated with the specified remote vaddr. This data must *		be presented exactly as obtained from the remote node. No swapping *		of data must be performed. * *	atomic1 *		The first operand for an atomic operation. * *	atomic2 *		The second operand for an atomic operation. * * NOTES *	The format of data sent over the fabric is user-defined and is considered *	opaque to the access layer.  The sole exception to this are MADs posted *	to a MAD QP service.  MADs are expected to match the format defined by *	the Infiniband specification and must be in network-byte order when posted *	to the MAD QP service. * * SEE ALSO *	ib_wr_type_t, ib_local_ds_t, ib_send_opt_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_recv_wr_t * NAME *	ib_recv_wr_t * * DESCRIPTION *	Information used to submit a work request to the receive queue of a queue *	pair. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_recv_wr
block|{
name|struct
name|_ib_recv_wr
modifier|*
name|p_next
decl_stmt|;
name|uint64_t
name|wr_id
decl_stmt|;
name|uint32_t
name|num_ds
decl_stmt|;
name|ib_local_ds_t
modifier|*
name|ds_array
decl_stmt|;
block|}
name|ib_recv_wr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_next *		A pointer used to chain work requests together.  This permits multiple *		work requests to be posted to a queue pair through a single function *		call.  This value is set to NULL to mark the end of the chain. * *	wr_id *		A 64-bit work request identifier that is returned to the consumer *		as part of the work completion. * *	num_ds *		Number of local data segments specified by this work request. * *	ds_array *		A reference to an array of local data segments used by the send *		operation. * * SEE ALSO *	ib_local_ds_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_bind_wr_t * NAME *	ib_bind_wr_t * * DESCRIPTION *	Information used to submit a memory window bind work request to the send *	queue of a queue pair. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_bind_wr
block|{
name|uint64_t
name|wr_id
decl_stmt|;
name|ib_send_opt_t
name|send_opt
decl_stmt|;
name|ib_mr_handle_t
name|h_mr
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
name|uint32_t
name|current_rkey
decl_stmt|;
name|ib_local_ds_t
name|local_ds
decl_stmt|;
block|}
name|ib_bind_wr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	wr_id *		A 64-bit work request identifier that is returned to the consumer *		as part of the work completion. * *	send_opt *		Optional send control parameters. * *	h_mr *		Handle to the memory region to which this window is being bound. * *	access_ctrl *		Access rights for this memory window. * *	current_rkey *		The current rkey assigned to this window for remote access. * *	local_ds *		A reference to a local data segment used by the bind operation. * * SEE ALSO *	ib_send_opt_t, ib_access_t, ib_local_ds_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_wc_status_t * NAME *	ib_wc_status_t * * DESCRIPTION *	Indicates the status of a completed work request.  These VALUES are *	returned to the user when retrieving completions.  Note that success is *	identified as IB_WCS_SUCCESS, which is always zero. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_wc_status_t
block|{
name|IB_WCS_SUCCESS
block|,
name|IB_WCS_LOCAL_LEN_ERR
block|,
name|IB_WCS_LOCAL_OP_ERR
block|,
name|IB_WCS_LOCAL_EEC_OP_ERR
block|,
name|IB_WCS_LOCAL_PROTECTION_ERR
block|,
name|IB_WCS_WR_FLUSHED_ERR
block|,
name|IB_WCS_MEM_WINDOW_BIND_ERR
block|,
name|IB_WCS_REM_ACCESS_ERR
block|,
name|IB_WCS_REM_OP_ERR
block|,
name|IB_WCS_RNR_RETRY_ERR
block|,
name|IB_WCS_TIMEOUT_RETRY_ERR
block|,
name|IB_WCS_REM_INVALID_REQ_ERR
block|,
name|IB_WCS_REM_INVALID_RD_REQ_ERR
block|,
name|IB_WCS_INVALID_EECN
block|,
name|IB_WCS_INVALID_EEC_STATE
block|,
name|IB_WCS_UNMATCHED_RESPONSE
block|,
comment|/* InfiniBand Access Layer */
name|IB_WCS_CANCELED
block|,
comment|/* InfiniBand Access Layer */
name|IB_WCS_UNKNOWN
comment|/* Must be last. */
block|}
name|ib_wc_status_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	IB_WCS_SUCCESS *		Work request completed successfully. * *	IB_WCS_MAD *		The completed work request was associated with a managmenet datagram *		that requires post processing.  The MAD will be returned to the user *		through a callback once all post processing has completed. * *	IB_WCS_LOCAL_LEN_ERR *		Generated for a work request posted to the send queue when the *		total of the data segment lengths exceeds the message length of the *		channel.  Generated for a work request posted to the receive queue when *		the total of the data segment lengths is too small for a *		valid incoming message. * *	IB_WCS_LOCAL_OP_ERR *		An internal QP consistency error was generated while processing this *		work request.  This may indicate that the QP was in an incorrect state *		for the requested operation. * *	IB_WCS_LOCAL_EEC_OP_ERR *		An internal EEC consistency error was generated while processing *		this work request.  This may indicate that the EEC was in an incorrect *		state for the requested operation. * *	IB_WCS_LOCAL_PROTECTION_ERR *		The data segments of the locally posted work request did not refer to *		a valid memory region.  The memory may not have been properly *		registered for the requested operation. * *	IB_WCS_WR_FLUSHED_ERR *		The work request was flushed from the QP before being completed. * *	IB_WCS_MEM_WINDOW_BIND_ERR *		A memory window bind operation failed due to insufficient access *		rights. * *	IB_WCS_REM_ACCESS_ERR, *		A protection error was detected at the remote node for a RDMA or atomic *		operation. * *	IB_WCS_REM_OP_ERR, *		The operation could not be successfully completed at the remote node. *		This may indicate that the remote QP was in an invalid state or *		contained an invalid work request. * *	IB_WCS_RNR_RETRY_ERR, *		The RNR retry count was exceeded while trying to send this message. * *	IB_WCS_TIMEOUT_RETRY_ERR *		The local transport timeout counter expired while trying to send this *		message. * *	IB_WCS_REM_INVALID_REQ_ERR, *		The remote node detected an invalid message on the channel.  This error *		is usually a result of one of the following: *			- The operation was not supported on receive queue. *			- There was insufficient buffers to receive a new RDMA request. *			- There was insufficient buffers to receive a new atomic operation. *			- An RDMA request was larger than 2^31 bytes. * *	IB_WCS_REM_INVALID_RD_REQ_ERR, *		Responder detected an invalid RD message.  This may be the result of an *		invalid qkey or an RDD mismatch. * *	IB_WCS_INVALID_EECN *		An invalid EE context number was detected. * *	IB_WCS_INVALID_EEC_STATE *		The EEC was in an invalid state for the specified request. * *	IB_WCS_UNMATCHED_RESPONSE *		A response MAD was received for which there was no matching send.  The *		send operation may have been canceled by the user or may have timed *		out. * *	IB_WCS_CANCELED *		The completed work request was canceled by the user. *****/
end_comment

begin_decl_stmt
name|OSM_EXPORT
specifier|const
name|char
modifier|*
name|ib_wc_status_str
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* IBA Base: Types/ib_get_wc_status_str * NAME *	ib_get_wc_status_str * * DESCRIPTION *	Returns a string for the specified work completion status. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|OSM_API
name|ib_get_wc_status_str
parameter_list|(
name|IN
name|ib_wc_status_t
name|wc_status
parameter_list|)
block|{
if|if
condition|(
name|wc_status
operator|>
name|IB_WCS_UNKNOWN
condition|)
name|wc_status
operator|=
name|IB_WCS_UNKNOWN
expr_stmt|;
return|return
operator|(
name|ib_wc_status_str
index|[
name|wc_status
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	wc_status *		[in] work completion status value * * RETURN VALUES *	Pointer to the work completion status description string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****d* Access Layer/ib_wc_type_t * NAME *	ib_wc_type_t * * DESCRIPTION *	Indicates the type of work completion. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_ib_wc_type_t
block|{
name|IB_WC_SEND
block|,
name|IB_WC_RDMA_WRITE
block|,
name|IB_WC_RECV
block|,
name|IB_WC_RDMA_READ
block|,
name|IB_WC_MW_BIND
block|,
name|IB_WC_FETCH_ADD
block|,
name|IB_WC_COMPARE_SWAP
block|,
name|IB_WC_RECV_RDMA_WRITE
block|}
name|ib_wc_type_t
typedef|;
end_typedef

begin_comment
comment|/*****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_recv_opt_t * NAME *	ib_recv_opt_t * * DESCRIPTION *	Indicates optional fields valid in a receive work completion. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_recv_opt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_RECV_OPT_IMMEDIATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_RECV_OPT_FORWARD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_RECV_OPT_GRH_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_RECV_OPT_VEND_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* * VALUES *	IB_RECV_OPT_IMMEDIATE *		Indicates that immediate data is valid for this work completion. * *	IB_RECV_OPT_FORWARD *		Indicates that the received trap should be forwarded to the SM. * *	IB_RECV_OPT_GRH_VALID *		Indicates presence of the global route header. When set, the *		first 40 bytes received are the GRH. * *	IB_RECV_OPT_VEND_MASK *		This mask indicates bits reserved in the receive options that may be *		used by the verbs provider to indicate vendor specific options.  Bits *		set in this area of the receive options are ignored by the Access Layer, *		but may have specific meaning to the underlying VPD. *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_wc_t * NAME *	ib_wc_t * * DESCRIPTION *	Work completion information. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_wc
block|{
name|struct
name|_ib_wc
modifier|*
name|p_next
decl_stmt|;
name|uint64_t
name|wr_id
decl_stmt|;
name|ib_wc_type_t
name|wc_type
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|ib_wc_status_t
name|status
decl_stmt|;
name|uint64_t
name|vendor_specific
decl_stmt|;
union|union
name|_wc_recv
block|{
struct|struct
name|_wc_conn
block|{
name|ib_recv_opt_t
name|recv_opt
decl_stmt|;
name|ib_net32_t
name|immediate_data
decl_stmt|;
block|}
name|conn
struct|;
struct|struct
name|_wc_ud
block|{
name|ib_recv_opt_t
name|recv_opt
decl_stmt|;
name|ib_net32_t
name|immediate_data
decl_stmt|;
name|ib_net32_t
name|remote_qp
decl_stmt|;
name|uint16_t
name|pkey_index
decl_stmt|;
name|ib_net16_t
name|remote_lid
decl_stmt|;
name|uint8_t
name|remote_sl
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
block|}
name|ud
struct|;
struct|struct
name|_wc_rd
block|{
name|ib_net32_t
name|remote_eecn
decl_stmt|;
name|ib_net32_t
name|remote_qp
decl_stmt|;
name|ib_net16_t
name|remote_lid
decl_stmt|;
name|uint8_t
name|remote_sl
decl_stmt|;
name|uint32_t
name|free_cnt
decl_stmt|;
block|}
name|rd
struct|;
struct|struct
name|_wc_raw_ipv6
block|{
name|ib_net16_t
name|remote_lid
decl_stmt|;
name|uint8_t
name|remote_sl
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
block|}
name|raw_ipv6
struct|;
struct|struct
name|_wc_raw_ether
block|{
name|ib_net16_t
name|remote_lid
decl_stmt|;
name|uint8_t
name|remote_sl
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
name|ib_net16_t
name|ether_type
decl_stmt|;
block|}
name|raw_ether
struct|;
block|}
name|recv
union|;
block|}
name|ib_wc_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_next *		A pointer used to chain work completions.  This permits multiple *		work completions to be retrieved from a completion queue through a *		single function call.  This value is set to NULL to mark the end of *		the chain. * *	wr_id *		The 64-bit work request identifier that was specified when posting the *		work request. * *	wc_type *		Indicates the type of work completion. * * *	length *		The total length of the data sent or received with the work request. * *	status *		The result of the work request. * *	vendor_specific *		HCA vendor specific information returned as part of the completion. * *	recv.conn.recv_opt *		Indicates optional fields valid as part of a work request that *		completed on a connected (reliable or unreliable) queue pair. * *	recv.conn.immediate_data *		32-bit field received as part of an inbound message on a connected *		queue pair.  This field is only valid if the recv_opt flag *		IB_RECV_OPT_IMMEDIATE has been set. * *	recv.ud.recv_opt *		Indicates optional fields valid as part of a work request that *		completed on an unreliable datagram queue pair. * *	recv.ud.immediate_data *		32-bit field received as part of an inbound message on a unreliable *		datagram queue pair.  This field is only valid if the recv_opt flag *		IB_RECV_OPT_IMMEDIATE has been set. * *	recv.ud.remote_qp *		Identifies the source queue pair of a received datagram. * *	recv.ud.pkey_index *		The pkey index for the source queue pair. This is valid only for *		GSI type QP's. * *	recv.ud.remote_lid *		The source LID of the received datagram. * *	recv.ud.remote_sl *		The service level used by the source of the received datagram. * *	recv.ud.path_bits *		path bits... * *	recv.rd.remote_eecn *		The remote end-to-end context number that sent the received message. * *	recv.rd.remote_qp *		Identifies the source queue pair of a received message. * *	recv.rd.remote_lid *		The source LID of the received message. * *	recv.rd.remote_sl *		The service level used by the source of the received message. * *	recv.rd.free_cnt *		The number of available entries in the completion queue.  Reliable *		datagrams may complete out of order, so this field may be used to *		determine the number of additional completions that may occur. * *	recv.raw_ipv6.remote_lid *		The source LID of the received message. * *	recv.raw_ipv6.remote_sl *		The service level used by the source of the received message. * *	recv.raw_ipv6.path_bits *		path bits... * *	recv.raw_ether.remote_lid *		The source LID of the received message. * *	recv.raw_ether.remote_sl *		The service level used by the source of the received message. * *	recv.raw_ether.path_bits *		path bits... * *	recv.raw_ether.ether_type *		ether type... * NOTES *	When the work request completes with error, the only values that the *	consumer can depend on are the wr_id field, and the status of the *	operation. * *	If the consumer is using the same CQ for completions from more than *	one type of QP (i.e Reliable Connected, Datagram etc), then the consumer *	must have additional information to decide what fields of the union are *	valid. * SEE ALSO *	ib_wc_type_t, ib_qp_type_t, ib_wc_status_t, ib_recv_opt_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_mr_create_t * NAME *	ib_mr_create_t * * DESCRIPTION *	Information required to create a registered memory region. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_mr_create
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
name|uint64_t
name|length
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
block|}
name|ib_mr_create_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	vaddr *		Starting virtual address of the region being registered. * *	length *		Length of the buffer to register. * *	access_ctrl *		Access rights of the registered region. * * SEE ALSO *	ib_access_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_phys_create_t * NAME *	ib_phys_create_t * * DESCRIPTION *	Information required to create a physical memory region. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_phys_create
block|{
name|uint64_t
name|length
decl_stmt|;
name|uint32_t
name|num_bufs
decl_stmt|;
name|uint64_t
modifier|*
name|buf_array
decl_stmt|;
name|uint32_t
name|buf_offset
decl_stmt|;
name|uint32_t
name|page_size
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
block|}
name|ib_phys_create_t
typedef|;
end_typedef

begin_comment
comment|/* *	length *		The length of the memory region in bytes. * *	num_bufs *		Number of buffers listed in the specified buffer array. * *	buf_array *		An array of physical buffers to be registered as a single memory *		region. * *	buf_offset *		The offset into the first physical page of the specified memory *		region to start the virtual address. * *	page_size *		The physical page size of the memory being registered. * *	access_ctrl *		Access rights of the registered region. * * SEE ALSO *	ib_access_t *****/
end_comment

begin_comment
comment|/****s* Access Layer/ib_mr_attr_t * NAME *	ib_mr_attr_t * * DESCRIPTION *	Attributes of a registered memory region. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_mr_attr
block|{
name|ib_pd_handle_t
name|h_pd
decl_stmt|;
name|void
modifier|*
name|local_lb
decl_stmt|;
name|void
modifier|*
name|local_ub
decl_stmt|;
name|void
modifier|*
name|remote_lb
decl_stmt|;
name|void
modifier|*
name|remote_ub
decl_stmt|;
name|ib_access_t
name|access_ctrl
decl_stmt|;
name|uint32_t
name|lkey
decl_stmt|;
name|uint32_t
name|rkey
decl_stmt|;
block|}
name|ib_mr_attr_t
typedef|;
end_typedef

begin_comment
comment|/* * DESCRIPTION *	h_pd *		Handle to the protection domain for this memory region. * *	local_lb *		The virtual address of the lower bound of protection for local *		memory access. * *	local_ub *		The virtual address of the upper bound of protection for local *		memory access. * *	remote_lb *		The virtual address of the lower bound of protection for remote *		memory access. * *	remote_ub *		The virtual address of the upper bound of protection for remote *		memory access. * *	access_ctrl *		Access rights for the specified memory region. * *	lkey *		The lkey associated with this memory region. * *	rkey *		The rkey associated with this memory region. * * NOTES *	The remote_lb, remote_ub, and rkey are only valid if remote memory access *	is enabled for this memory region. * * SEE ALSO *	ib_access_t *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_ca_mod_t * NAME *	ib_ca_mod_t -- Modify port attributes and error counters * * DESCRIPTION *	Specifies modifications to the port attributes of a channel adapter. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_ca_mod_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_CM_SUPPORTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_SNMP_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_DEV_MGMT_SUPPORTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_VEND_SUPPORTED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_SM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_SM_DISABLED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_QKEY_CTR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_PKEY_CTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_NOTICE_SUPPORTED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_TRAP_SUPPORTED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_APM_SUPPORTED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_SLMAP_SUPPORTED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_PKEY_NVRAM_SUPPORTED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_MKEY_NVRAM_SUPPORTED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_SYSGUID_SUPPORTED
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_DR_NOTICE_SUPPORTED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_BOOT_MGMT_SUPPORTED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_CAPM_NOTICE_SUPPORTED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_REINIT_SUPORTED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_IS_LEDINFO_SUPPORTED
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_SHUTDOWN_PORT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_INIT_TYPE_VALUE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IB_CA_MOD_SYSTEM_IMAGE_GUID
value|0x00400000
end_define

begin_comment
comment|/* * VALUES *	IB_CA_MOD_IS_CM_SUPPORTED *		Indicates if there is a communication manager accessible through *		the port. * *	IB_CA_MOD_IS_SNMP_SUPPORTED *		Indicates if there is an SNMP agent accessible through the port. * *	IB_CA_MOD_IS_DEV_MGMT_SUPPORTED *		Indicates if there is a device management agent accessible *		through the port. * *	IB_CA_MOD_IS_VEND_SUPPORTED *		Indicates if there is a vendor supported agent accessible *		through the port. * *	IB_CA_MOD_IS_SM *		Indicates if there is a subnet manager accessible through *		the port. * *	IB_CA_MOD_IS_SM_DISABLED *		Indicates if the port has been disabled for configuration by the *		subnet manager. * *	IB_CA_MOD_QKEY_CTR *		Used to reset the qkey violation counter associated with the *		port. * *	IB_CA_MOD_PKEY_CTR *		Used to reset the pkey violation counter associated with the *		port. * *	IB_CA_MOD_IS_NOTICE_SUPPORTED *		Indicates that this CA supports ability to generate Notices for *		Port State changes. (only applicable to switches) * *	IB_CA_MOD_IS_TRAP_SUPPORTED *		Indicates that this management port supports ability to generate *		trap messages. (only applicable to switches) * *	IB_CA_MOD_IS_APM_SUPPORTED *		Indicates that this port is capable of performing Automatic *		Path Migration. * *	IB_CA_MOD_IS_SLMAP_SUPPORTED *		Indicates this port supports SLMAP capability. * *	IB_CA_MOD_IS_PKEY_NVRAM_SUPPORTED *		Indicates that PKEY is supported in NVRAM * *	IB_CA_MOD_IS_MKEY_NVRAM_SUPPORTED *		Indicates that MKEY is supported in NVRAM * *	IB_CA_MOD_IS_SYSGUID_SUPPORTED *		Indicates System Image GUID support. * *	IB_CA_MOD_IS_DR_NOTICE_SUPPORTED *		Indicate support for generating Direct Routed Notices * *	IB_CA_MOD_IS_BOOT_MGMT_SUPPORTED *		Indicates support for Boot Management * *	IB_CA_MOD_IS_CAPM_NOTICE_SUPPORTED *		Indicates capability to generate notices for changes to CAPMASK * *	IB_CA_MOD_IS_REINIT_SUPORTED *		Indicates type of node init supported. Refer to Chapter 14 for *		Initialization actions. * *	IB_CA_MOD_IS_LEDINFO_SUPPORTED *		Indicates support for LED info. * *	IB_CA_MOD_SHUTDOWN_PORT *		Used to modify the port active indicator. * *	IB_CA_MOD_INIT_TYPE_VALUE *		Used to modify the init_type value for the port. * *	IB_CA_MOD_SYSTEM_IMAGE_GUID *		Used to modify the system image GUID for the port. *****/
end_comment

begin_comment
comment|/****d* Access Layer/ib_mr_mod_t * NAME *	ib_mr_mod_t * * DESCRIPTION *	Mask used to specify which attributes of a registered memory region are *	being modified. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ib_mr_mod_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_MR_MOD_ADDR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IB_MR_MOD_PD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IB_MR_MOD_ACCESS
value|0x00000004
end_define

begin_comment
comment|/* * PARAMETERS *	IB_MEM_MOD_ADDR *		The address of the memory region is being modified. * *	IB_MEM_MOD_PD *		The protection domain associated with the memory region is being *		modified. * *	IB_MEM_MOD_ACCESS *		The access rights the memory region are being modified. *****/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_ATTR_MOD_HANDOVER * NAME *	IB_SMINFO_ATTR_MOD_HANDOVER * * DESCRIPTION *	Encoded attribute modifier value used on SubnSet(SMInfo) SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_ATTR_MOD_HANDOVER
value|(CL_HTON32(0x000001))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_ATTR_MOD_ACKNOWLEDGE * NAME *	IB_SMINFO_ATTR_MOD_ACKNOWLEDGE * * DESCRIPTION *	Encoded attribute modifier value used on SubnSet(SMInfo) SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_ATTR_MOD_ACKNOWLEDGE
value|(CL_HTON32(0x000002))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_ATTR_MOD_DISABLE * NAME *	IB_SMINFO_ATTR_MOD_DISABLE * * DESCRIPTION *	Encoded attribute modifier value used on SubnSet(SMInfo) SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_ATTR_MOD_DISABLE
value|(CL_HTON32(0x000003))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_ATTR_MOD_STANDBY * NAME *	IB_SMINFO_ATTR_MOD_STANDBY * * DESCRIPTION *	Encoded attribute modifier value used on SubnSet(SMInfo) SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_ATTR_MOD_STANDBY
value|(CL_HTON32(0x000004))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****d* IBA Base: Constants/IB_SMINFO_ATTR_MOD_DISCOVER * NAME *	IB_SMINFO_ATTR_MOD_DISCOVER * * DESCRIPTION *	Encoded attribute modifier value used on SubnSet(SMInfo) SMPs. * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_SMINFO_ATTR_MOD_DISCOVER
value|(CL_HTON32(0x000005))
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* Access Layer/ib_ci_op_t * NAME *	ib_ci_op_t * * DESCRIPTION *	A structure used for vendor specific CA interface communication. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ib_ci_op
block|{
name|IN
name|uint32_t
name|command
decl_stmt|;
name|IN
name|OUT
name|void
modifier|*
name|p_buf
name|OPTIONAL
decl_stmt|;
name|IN
name|uint32_t
name|buf_size
decl_stmt|;
name|IN
name|OUT
name|uint32_t
name|num_bytes_ret
decl_stmt|;
name|IN
name|OUT
name|int32_t
name|status
decl_stmt|;
block|}
name|ib_ci_op_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	command *		A command code that is understood by the verbs provider. * *	p_buf *		A reference to a buffer containing vendor specific data.  The verbs *		provider must not access pointers in the p_buf between user-mode and *		kernel-mode.  Any pointers embedded in the p_buf are invalidated by *		the user-mode/kernel-mode transition. * *	buf_size *		The size of the buffer in bytes. * *	num_bytes_ret *		The size in bytes of the vendor specific data returned in the buffer. *		This field is set by the verbs provider.  The verbs provider should *		verify that the buffer size is sufficient to hold the data being *		returned. * *	status *		The completion status from the verbs provider.  This field should be *		initialize to indicate an error to allow detection and cleanup in *		case a communication error occurs between user-mode and kernel-mode. * * NOTES *	This structure is provided to allow the exchange of vendor specific *	data between the originator and the verbs provider.  Users of this *	structure are expected to know the format of data in the p_buf based *	on the structure command field or the usage context. *****/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cc_mad_t * NAME *	ib_cc_mad_t * * DESCRIPTION *	IBA defined Congestion Control MAD format. (A10.4.1) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CC_LOG_DATA_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|IB_CC_MGT_DATA_SIZE
value|192
end_define

begin_define
define|#
directive|define
name|IB_CC_MAD_HDR_SIZE
value|(sizeof(ib_sa_mad_t) - IB_CC_LOG_DATA_SIZE \ 						- IB_CC_MGT_DATA_SIZE)
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cc_mad
block|{
name|ib_mad_t
name|header
decl_stmt|;
name|ib_net64_t
name|cc_key
decl_stmt|;
name|uint8_t
name|log_data
index|[
name|IB_CC_LOG_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|mgt_data
index|[
name|IB_CC_MGT_DATA_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cc_mad_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	header *		Common MAD header. * *	cc_key *		CC_Key of the Congestion Control MAD. * *	log_data *		Congestion Control log data of the CC MAD. * *	mgt_data *		Congestion Control management data of the CC MAD. * * SEE ALSO * ib_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_cc_mad_get_cc_key * NAME *	ib_cc_mad_get_cc_key * * DESCRIPTION *	Gets a CC_Key of the CC MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|OSM_API
name|ib_cc_mad_get_cc_key
parameter_list|(
name|IN
specifier|const
name|ib_cc_mad_t
modifier|*
specifier|const
name|p_cc_mad
parameter_list|)
block|{
return|return
name|p_cc_mad
operator|->
name|cc_key
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cc_mad *		[in] Pointer to the CC MAD packet. * * RETURN VALUES *	CC_Key of the provided CC MAD packet. * * NOTES * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_cc_mad_get_log_data_ptr * NAME *	ib_cc_mad_get_log_data_ptr * * DESCRIPTION *	Gets a pointer to the CC MAD's log data area. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|OSM_API
name|ib_cc_mad_get_log_data_ptr
parameter_list|(
name|IN
specifier|const
name|ib_cc_mad_t
modifier|*
specifier|const
name|p_cc_mad
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_cc_mad
operator|->
name|log_data
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cc_mad *		[in] Pointer to the CC MAD packet. * * RETURN VALUES *	Pointer to CC MAD log data area. * * NOTES * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/ib_cc_mad_get_mgt_data_ptr * NAME *	ib_cc_mad_get_mgt_data_ptr * * DESCRIPTION *	Gets a pointer to the CC MAD's management data area. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|OSM_API
name|ib_cc_mad_get_mgt_data_ptr
parameter_list|(
name|IN
specifier|const
name|ib_cc_mad_t
modifier|*
specifier|const
name|p_cc_mad
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_cc_mad
operator|->
name|mgt_data
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_cc_mad *		[in] Pointer to the CC MAD packet. * * RETURN VALUES *	Pointer to CC MAD management data area. * * NOTES * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cong_info_t * NAME *	ib_cong_info_t * * DESCRIPTION *	IBA defined CongestionInfo attribute (A10.4.3.3) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cong_info
block|{
name|uint8_t
name|cong_info
decl_stmt|;
name|uint8_t
name|resv
decl_stmt|;
name|uint8_t
name|ctrl_table_cap
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cong_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	cong_info *		Congestion control capabilities of the node. * *	ctrl_table_cap *		Number of 64 entry blocks in the CongestionControlTable. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cong_key_info_t * NAME *	ib_cong_key_info_t * * DESCRIPTION *	IBA defined CongestionKeyInfo attribute (A10.4.3.4) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cong_key_info
block|{
name|ib_net64_t
name|cc_key
decl_stmt|;
name|ib_net16_t
name|protect_bit
decl_stmt|;
name|ib_net16_t
name|lease_period
decl_stmt|;
name|ib_net16_t
name|violations
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cong_key_info_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	cc_key *		8-byte CC Key. * *	protect_bit *		Bit 0 is a CC Key Protect Bit, other 15 bits are reserved. * *	lease_period *		How long the CC Key protect bit is to remain non-zero. * *	violations *		Number of received MADs that violated CC Key. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cong_log_event_sw_t * NAME *	ib_cong_log_event_sw_t * * DESCRIPTION *	IBA defined CongestionLogEvent (SW) entry (A10.4.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cong_log_event_sw
block|{
name|ib_net16_t
name|slid
decl_stmt|;
name|ib_net16_t
name|dlid
decl_stmt|;
name|ib_net32_t
name|sl
decl_stmt|;
name|ib_net32_t
name|time_stamp
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cong_log_event_sw_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	slid *		Source LID of congestion event. * *	dlid *		Destination LID of congestion event. * *	sl *		4 bits - SL of congestion event. *		rest of the bits are reserved. * *	time_stamp *		Timestamp of congestion event. * * SEE ALSO *	ib_cc_mad_t, ib_cong_log_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cong_log_event_ca_t * NAME *	ib_cong_log_event_ca_t * * DESCRIPTION *	IBA defined CongestionLogEvent (CA) entry (A10.4.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cong_log_event_ca
block|{
name|ib_net32_t
name|local_qp_resv0
decl_stmt|;
name|ib_net32_t
name|remote_qp_sl_service_type
decl_stmt|;
name|ib_net16_t
name|remote_lid
decl_stmt|;
name|ib_net16_t
name|resv1
decl_stmt|;
name|ib_net32_t
name|time_stamp
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cong_log_event_ca_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS *	resv0_local_qp *		bits [31:8] local QP that reached CN threshold. *		bits [7:0] reserved. * *	remote_qp_sl_service_type *		bits [31:8] remote QP that is connected to local QP. *		bits [7:4] SL of the local QP. *		bits [3:0] Service Type of the local QP. * *	remote_lid *		LID of the remote port that is connected to local QP. * *	time_stamp *		Timestamp when threshold reached. * * SEE ALSO *	ib_cc_mad_t, ib_cong_log_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cong_log_t * NAME *	ib_cong_log_t * * DESCRIPTION *	IBA defined CongestionLog attribute (A10.4.3.5) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cong_log
block|{
name|uint8_t
name|log_type
decl_stmt|;
union|union
name|_log_details
block|{
struct|struct
name|_log_sw
block|{
name|uint8_t
name|cong_flags
decl_stmt|;
name|ib_net16_t
name|event_counter
decl_stmt|;
name|ib_net32_t
name|time_stamp
decl_stmt|;
name|uint8_t
name|port_map
index|[
literal|32
index|]
decl_stmt|;
name|ib_cong_log_event_sw_t
name|entry_list
index|[
literal|15
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|log_sw
struct|;
struct|struct
name|_log_ca
block|{
name|uint8_t
name|cong_flags
decl_stmt|;
name|ib_net16_t
name|event_counter
decl_stmt|;
name|ib_net16_t
name|event_map
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_net32_t
name|time_stamp
decl_stmt|;
name|ib_cong_log_event_ca_t
name|log_event
index|[
literal|13
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|log_ca
struct|;
block|}
name|log_details
union|;
block|}
name|PACK_SUFFIX
name|ib_cong_log_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	log_{sw,ca}.log_type *		Log type: 0x1 is for Switch, 0x2 is for CA * *	log_{sw,ca}.cong_flags *		Congestion Flags. * *	log_{sw,ca}.event_counter *		Number of events since log last sent. * *	log_{sw,ca}.time_stamp *		Timestamp when log sent. * *	log_sw.port_map *		If a bit set to 1, then the corresponding port *		has marked packets with a FECN. *		bits 0 and 255 - reserved *		bits [254..1] - ports [254..1]. * *	log_sw.entry_list *		Array of 13 most recent congestion log events. * *	log_ca.event_map *		array 16 bits, one for each SL. * *	log_ca.log_event *		Array of 13 most recent congestion log events. * * SEE ALSO *	ib_cc_mad_t, ib_cong_log_event_sw_t, ib_cong_log_event_ca_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_sw_cong_setting_t * NAME *	ib_sw_cong_setting_t * * DESCRIPTION *	IBA defined SwitchCongestionSetting attribute (A10.4.3.6) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CC_PORT_MASK_DATA_SIZE
value|32
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sw_cong_setting
block|{
name|ib_net32_t
name|control_map
decl_stmt|;
name|uint8_t
name|victim_mask
index|[
name|IB_CC_PORT_MASK_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|credit_mask
index|[
name|IB_CC_PORT_MASK_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|threshold_resv
decl_stmt|;
name|uint8_t
name|packet_size
decl_stmt|;
name|ib_net16_t
name|cs_threshold_resv
decl_stmt|;
name|ib_net16_t
name|cs_return_delay
decl_stmt|;
name|ib_net16_t
name|marking_rate
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sw_cong_setting_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	control_map *		Indicates which components of this attribute are valid * *	victim_mask *		If the bit set to 1, then the port corresponding to *		that bit shall mark packets that encounter congestion *		with a FECN, whether they are the source or victim *		of congestion. (See A10.2.1.1.1) *		  bit 0: port 0 (enhanced port 0 only) *		  bits [254..1]: ports [254..1] *		  bit 255: reserved * *	credit_mask *		If the bit set to 1, then the port corresponding *		to that bit shall apply Credit Starvation. *		  bit 0: port 0 (enhanced port 0 only) *		  bits [254..1]: ports [254..1] *		  bit 255: reserved * *	threshold_resv *		bits [7..4] Indicates how aggressive cong. marking should be *		bits [3..0] Reserved * *	packet_size *		Any packet less than this size won't be marked with FECN * *	cs_threshold_resv *		bits [15..12] How aggressive Credit Starvation should be *		bits [11..0] Reserved * *	cs_return_delay *		Value that controls credit return rate. * *	marking_rate *		The value that provides the mean number of packets *		between marking eligible packets with FECN. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_sw_port_cong_setting_element_t * NAME *	ib_sw_port_cong_setting_element_t * * DESCRIPTION *	IBA defined SwitchPortCongestionSettingElement (A10.4.3.7) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sw_port_cong_setting_element
block|{
name|uint8_t
name|valid_ctrl_type_res_threshold
decl_stmt|;
name|uint8_t
name|packet_size
decl_stmt|;
name|ib_net16_t
name|cong_param
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sw_port_cong_setting_element_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	valid_ctrl_type_res_threshold *		bit 7: "Valid" *			when set to 1, indicates this switch *			port congestion setting element is valid. *		bit 6: "Control Type" *			Indicates which type of attribute is being set: *			0b = Congestion Control parameters are being set. *			1b = Credit Starvation parameters are being set. *		bits [5..4]: reserved *		bits [3..0]: "Threshold" *			When Control Type is 0, contains the congestion *			threshold value (Threshold) for this port. *			When Control Type is 1, contains the credit *			starvation threshold (CS_Threshold) value for *			this port. * *	packet_size *		When Control Type is 0, this field contains the minimum *		size of packets that may be marked with a FECN. *		When Control Type is 1, this field is reserved. * *	cong_parm *		When Control Type is 0, this field contains the port *		marking_rate. *		When Control Type is 1, this field is reserved. * * SEE ALSO *	ib_cc_mad_t, ib_sw_port_cong_setting_t *********/
end_comment

begin_comment
comment|/****d* IBA Base: Types/ib_sw_port_cong_setting_block_t * NAME *	ib_sw_port_cong_setting_block_t * * DESCRIPTION *	Defines the SwitchPortCongestionSetting Block (A10.4.3.7). * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_CC_SW_PORT_SETTING_ELEMENTS
value|32
end_define

begin_typedef
typedef|typedef
name|ib_sw_port_cong_setting_element_t
name|ib_sw_port_cong_setting_block_t
index|[
name|IB_CC_SW_PORT_SETTING_ELEMENTS
index|]
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_sw_port_cong_setting_t * NAME *	ib_sw_port_cong_setting_t * * DESCRIPTION *	IBA defined SwitchPortCongestionSetting attribute (A10.4.3.7) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_sw_port_cong_setting
block|{
name|ib_sw_port_cong_setting_block_t
name|block
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_sw_port_cong_setting_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	block *		SwitchPortCongestionSetting block. * * SEE ALSO *	ib_cc_mad_t, ib_sw_port_cong_setting_element_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_ca_cong_entry_t * NAME *	ib_ca_cong_entry_t * * DESCRIPTION *	IBA defined CACongestionEntry (A10.4.3.8) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_ca_cong_entry
block|{
name|ib_net16_t
name|ccti_timer
decl_stmt|;
name|uint8_t
name|ccti_increase
decl_stmt|;
name|uint8_t
name|trigger_threshold
decl_stmt|;
name|uint8_t
name|ccti_min
decl_stmt|;
name|uint8_t
name|resv0
decl_stmt|;
name|ib_net16_t
name|resv1
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_ca_cong_entry_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	ccti_timer *		When the timer expires it will be reset to its specified *		value, and 1 will be decremented from the CCTI. * *	ccti_increase *		The number to be added to the table Index (CCTI) *		on the receipt of a BECN. * *	trigger_threshold *		When the CCTI is equal to this value, an event *		is logged in the CAs cyclic event log. * *	ccti_min *		The minimum value permitted for the CCTI. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_ca_cong_setting_t * NAME *	ib_ca_cong_setting_t * * DESCRIPTION *	IBA defined CACongestionSetting attribute (A10.4.3.8) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CA_CONG_ENTRY_DATA_SIZE
value|16
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_ca_cong_setting
block|{
name|ib_net16_t
name|port_control
decl_stmt|;
name|ib_net16_t
name|control_map
decl_stmt|;
name|ib_ca_cong_entry_t
name|entry_list
index|[
name|IB_CA_CONG_ENTRY_DATA_SIZE
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_ca_cong_setting_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	port_control *		Congestion attributes for this port: *		  bit0 = 0: QP based CC *		  bit0 = 1: SL/Port based CC *		All other bits are reserved * *	control_map *		An array of sixteen bits, one for each SL. Each bit indicates *		whether or not the corresponding entry is to be modified. * *	entry_list *		List of 16 CACongestionEntries, one per SL. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cc_tbl_entry_t * NAME *	ib_cc_tbl_entry_t * * DESCRIPTION *	IBA defined CongestionControlTableEntry (A10.4.3.9) * * SYNOPSIS */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cc_tbl_entry
block|{
name|ib_net16_t
name|shift_multiplier
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cc_tbl_entry_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	shift_multiplier *		bits [15..14] - CCT Shift *		  used when calculating the injection rate delay *		bits [13..0] - CCT Multiplier *		  used when calculating the injection rate delay * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_cc_tbl_t * NAME *	ib_cc_tbl_t * * DESCRIPTION *	IBA defined CongestionControlTable attribute (A10.4.3.9) * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CC_TBL_ENTRY_LIST_MAX
value|64
end_define

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_cc_tbl
block|{
name|ib_net16_t
name|ccti_limit
decl_stmt|;
name|ib_net16_t
name|resv
decl_stmt|;
name|ib_cc_tbl_entry_t
name|entry_list
index|[
name|IB_CC_TBL_ENTRY_LIST_MAX
index|]
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_cc_tbl_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	ccti_limit *		Maximum valid CCTI for this table. * *	entry_list *		List of up to 64 CongestionControlTableEntries. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_comment
comment|/****s* IBA Base: Types/ib_time_stamp_t * NAME *	ib_time_stamp_t * * DESCRIPTION *	IBA defined TimeStamp attribute (A10.4.3.10) * * SOURCE */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_packon.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ib_time_stamp
block|{
name|ib_net32_t
name|value
decl_stmt|;
block|}
name|PACK_SUFFIX
name|ib_time_stamp_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<complib/cl_packoff.h>
end_include

begin_comment
comment|/* * FIELDS * *	value *		Free running clock that provides relative time info *		for a device. Time is kept in 1.024 usec units. * * SEE ALSO *	ib_cc_mad_t *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ndef __WIN__ */
end_comment

begin_include
include|#
directive|include
file|<iba/ib_types_extended.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IB_TYPES_H__ */
end_comment

end_unit

