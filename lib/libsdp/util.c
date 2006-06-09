begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util.c  *  * Copyright (c) 2001-2003 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: util.c,v 1.5 2003/09/08 02:29:35 max Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sdp.h>
end_include

begin_comment
comment|/*  * SDP attribute description  */
end_comment

begin_struct
struct|struct
name|sdp_attr_desc
block|{
name|uint32_t
name|attr
decl_stmt|;
name|char
specifier|const
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_attr_desc
name|sdp_attr_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_attr_desc
modifier|*
name|sdp_attr_desc_p
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|sdp_attr_desc_t
name|sdp_uuids_desc
index|[]
init|=
block|{
block|{
name|SDP_UUID_PROTOCOL_SDP
block|,
literal|"SDP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_UDP
block|,
literal|"UDP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_RFCOMM
block|,
literal|"RFCOMM"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_TCP
block|,
literal|"TCP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_TCS_BIN
block|,
literal|"TCS BIN"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_TCS_AT
block|,
literal|"TCS AT"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_OBEX
block|,
literal|"OBEX"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_IP
block|,
literal|"IP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_FTP
block|,
literal|"FTP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_HTTP
block|,
literal|"HTTP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_WSP
block|,
literal|"WSP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_BNEP
block|,
literal|"BNEP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_UPNP
block|,
literal|"UPNP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_HIDP
block|,
literal|"HIDP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_HARDCOPY_CONTROL_CHANNEL
block|,
literal|"Hardcopy Control Channel"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_HARDCOPY_DATA_CHANNEL
block|,
literal|"Hardcopy Data Channel"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_HARDCOPY_NOTIFICATION
block|,
literal|"Hardcopy Notification"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_AVCTP
block|,
literal|"AVCTP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_AVDTP
block|,
literal|"AVDTP"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_CMPT
block|,
literal|"CMPT"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_UDI_C_PLANE
block|,
literal|"UDI C-Plane"
block|, }
block|,
block|{
name|SDP_UUID_PROTOCOL_L2CAP
block|,
literal|"L2CAP"
block|, }
block|,
comment|/* Service Class IDs/Bluetooth Profile IDs */
block|{
name|SDP_SERVICE_CLASS_SERVICE_DISCOVERY_SERVER
block|,
literal|"Service Discovery Server"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_BROWSE_GROUP_DESCRIPTOR
block|,
literal|"Browse Group Descriptor"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_PUBLIC_BROWSE_GROUP
block|,
literal|"Public Browse Group"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_SERIAL_PORT
block|,
literal|"Serial Port"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_LAN_ACCESS_USING_PPP
block|,
literal|"LAN Access Using PPP"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_DIALUP_NETWORKING
block|,
literal|"Dial-Up Networking"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IR_MC_SYNC
block|,
literal|"IrMC Sync"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_OBEX_OBJECT_PUSH
block|,
literal|"OBEX Object Push"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_OBEX_FILE_TRANSFER
block|,
literal|"OBEX File Transfer"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IR_MC_SYNC_COMMAND
block|,
literal|"IrMC Sync Command"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HEADSET
block|,
literal|"Headset"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_CORDLESS_TELEPHONY
block|,
literal|"Cordless Telephony"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_AUDIO_SOURCE
block|,
literal|"Audio Source"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_AUDIO_SINK
block|,
literal|"Audio Sink"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_AV_REMOTE_CONTROL_TARGET
block|,
literal|"A/V Remote Control Target"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_ADVANCED_AUDIO_DISTRIBUTION
block|,
literal|"Advanced Audio Distribution"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_AV_REMOTE_CONTROL
block|,
literal|"A/V Remote Control"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_VIDEO_CONFERENCING
block|,
literal|"Video Conferencing"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_INTERCOM
block|,
literal|"Intercom"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_FAX
block|,
literal|"Fax"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HEADSET_AUDIO_GATEWAY
block|,
literal|"Headset Audio Gateway"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_WAP
block|,
literal|"WAP"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_WAP_CLIENT
block|,
literal|"WAP Client"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_PANU
block|,
literal|"PANU"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_NAP
block|,
literal|"Network Access Point"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_GN
block|,
literal|"GN"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_DIRECT_PRINTING
block|,
literal|"Direct Printing"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_REFERENCE_PRINTING
block|,
literal|"Reference Printing"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IMAGING
block|,
literal|"Imaging"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IMAGING_RESPONDER
block|,
literal|"Imaging Responder"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IMAGING_AUTOMATIC_ARCHIVE
block|,
literal|"Imaging Automatic Archive"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_IMAGING_REFERENCED_OBJECTS
block|,
literal|"Imaging Referenced Objects"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HANDSFREE
block|,
literal|"Handsfree"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HANDSFREE_AUDIO_GATEWAY
block|,
literal|"Handsfree Audio Gateway"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_DIRECT_PRINTING_REFERENCE_OBJECTS
block|,
literal|"Direct Printing Reference Objects"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_REFLECTED_UI
block|,
literal|"Reflected UI"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_BASIC_PRINTING
block|,
literal|"Basic Printing"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_PRINTING_STATUS
block|,
literal|"Printing Status"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HUMAN_INTERFACE_DEVICE
block|,
literal|"Human Interface Device"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HARDCOPY_CABLE_REPLACEMENT
block|,
literal|"Hardcopy Cable Replacement"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HCR_PRINT
block|,
literal|"HCR Print"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_HCR_SCAN
block|,
literal|"HCR Scan"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_COMMON_ISDN_ACCESS
block|,
literal|"Common ISDN Access"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_VIDEO_CONFERENCING_GW
block|,
literal|"Video Conferencing Gateway"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_UDI_MT
block|,
literal|"UDI MT"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_UDI_TA
block|,
literal|"UDI TA"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_AUDIO_VIDEO
block|,
literal|"Audio/Video"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_SIM_ACCESS
block|,
literal|"SIM Access"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_PNP_INFORMATION
block|,
literal|"PNP Information"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_GENERIC_NETWORKING
block|,
literal|"Generic Networking"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_GENERIC_FILE_TRANSFER
block|,
literal|"Generic File Transfer"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_GENERIC_AUDIO
block|,
literal|"Generic Audio"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_GENERIC_TELEPHONY
block|,
literal|"Generic Telephony"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_UPNP
block|,
literal|"UPNP"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_UPNP_IP
block|,
literal|"UPNP IP"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_ESDP_UPNP_IP_PAN
block|,
literal|"ESDP UPNP IP PAN"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_ESDP_UPNP_IP_LAP
block|,
literal|"ESDP UPNP IP LAP"
block|, }
block|,
block|{
name|SDP_SERVICE_CLASS_ESDP_UPNP_L2CAP
block|,
literal|"ESDP UPNP L2CAP"
block|, }
block|,
block|{
literal|0xffff
block|,
name|NULL
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|sdp_attr_desc_t
name|sdp_attrs_desc
index|[]
init|=
block|{
block|{
name|SDP_ATTR_SERVICE_RECORD_HANDLE
block|,
literal|"Record handle"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_CLASS_ID_LIST
block|,
literal|"Service Class ID list"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_RECORD_STATE
block|,
literal|"Service Record State"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_ID
block|,
literal|"Service ID"
block|,   }
block|,
block|{
name|SDP_ATTR_PROTOCOL_DESCRIPTOR_LIST
block|,
literal|"Protocol Descriptor List"
block|,   }
block|,
block|{
name|SDP_ATTR_BROWSE_GROUP_LIST
block|,
literal|"Browse Group List"
block|,   }
block|,
block|{
name|SDP_ATTR_LANGUAGE_BASE_ATTRIBUTE_ID_LIST
block|,
literal|"Language Base Attribute ID List"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_INFO_TIME_TO_LIVE
block|,
literal|"Service Info Time-To-Live"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_AVAILABILITY
block|,
literal|"Service Availability"
block|,   }
block|,
block|{
name|SDP_ATTR_BLUETOOTH_PROFILE_DESCRIPTOR_LIST
block|,
literal|"Bluetooh Profile Descriptor List"
block|,   }
block|,
block|{
name|SDP_ATTR_DOCUMENTATION_URL
block|,
literal|"Documentation URL"
block|,   }
block|,
block|{
name|SDP_ATTR_CLIENT_EXECUTABLE_URL
block|,
literal|"Client Executable URL"
block|,   }
block|,
block|{
name|SDP_ATTR_ICON_URL
block|,
literal|"Icon URL"
block|,   }
block|,
block|{
name|SDP_ATTR_ADDITIONAL_PROTOCOL_DESCRIPTOR_LISTS
block|,
literal|"Additional Protocol Descriptor Lists"
block|}
block|,
block|{
name|SDP_ATTR_GROUP_ID
block|,
comment|/*SDP_ATTR_IP_SUBNET,   SDP_ATTR_VERSION_NUMBER_LIST*/
literal|"Group ID/IP Subnet/Version Number List"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_DATABASE_STATE
block|,
literal|"Service Database State"
block|,   }
block|,
block|{
name|SDP_ATTR_SERVICE_VERSION
block|,
literal|"Service Version"
block|,   }
block|,
block|{
name|SDP_ATTR_EXTERNAL_NETWORK
block|,
comment|/*SDP_ATTR_NETWORK,   SDP_ATTR_SUPPORTED_DATA_STORES_LIST*/
literal|"External Network/Network/Supported Data Stores List"
block|,   }
block|,
block|{
name|SDP_ATTR_FAX_CLASS1_SUPPORT
block|,
comment|/*SDP_ATTR_REMOTE_AUDIO_VOLUME_CONTROL*/
literal|"Fax Class1 Support/Remote Audio Volume Control"
block|,   }
block|,
block|{
name|SDP_ATTR_FAX_CLASS20_SUPPORT
block|,
comment|/*SDP_ATTR_SUPPORTED_FORMATS_LIST*/
literal|"Fax Class20 Support/Supported Formats List"
block|,   }
block|,
block|{
name|SDP_ATTR_FAX_CLASS2_SUPPORT
block|,
literal|"Fax Class2 Support"
block|,   }
block|,
block|{
name|SDP_ATTR_AUDIO_FEEDBACK_SUPPORT
block|,
literal|"Audio Feedback Support"
block|,   }
block|,
block|{
name|SDP_ATTR_NETWORK_ADDRESS
block|,
literal|"Network Address"
block|,   }
block|,
block|{
name|SDP_ATTR_WAP_GATEWAY
block|,
literal|"WAP Gateway"
block|,   }
block|,
block|{
name|SDP_ATTR_HOME_PAGE_URL
block|,
literal|"Home Page URL"
block|,   }
block|,
block|{
name|SDP_ATTR_WAP_STACK_TYPE
block|,
literal|"WAP Stack Type"
block|,   }
block|,
block|{
name|SDP_ATTR_SECURITY_DESCRIPTION
block|,
literal|"Security Description"
block|,   }
block|,
block|{
name|SDP_ATTR_NET_ACCESS_TYPE
block|,
literal|"Net Access Type"
block|,   }
block|,
block|{
name|SDP_ATTR_MAX_NET_ACCESS_RATE
block|,
literal|"Max Net Access Rate"
block|,   }
block|,
block|{
name|SDP_ATTR_IPV4_SUBNET
block|,
literal|"IPv4 Subnet"
block|,   }
block|,
block|{
name|SDP_ATTR_IPV6_SUBNET
block|,
literal|"IPv6 Subnet"
block|,   }
block|,
block|{
name|SDP_ATTR_SUPPORTED_CAPABALITIES
block|,
literal|"Supported Capabalities"
block|,   }
block|,
block|{
name|SDP_ATTR_SUPPORTED_FEATURES
block|,
literal|"Supported Features"
block|,   }
block|,
block|{
name|SDP_ATTR_SUPPORTED_FUNCTIONS
block|,
literal|"Supported Functions"
block|,   }
block|,
block|{
name|SDP_ATTR_TOTAL_IMAGING_DATA_CAPACITY
block|,
literal|"Total Imaging Data Capacity"
block|,   }
block|,
block|{
literal|0xffff
block|,
name|NULL
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
specifier|const
modifier|*
name|sdp_attr2desc
parameter_list|(
name|uint16_t
name|attr
parameter_list|)
block|{
specifier|register
name|sdp_attr_desc_p
name|a
init|=
name|sdp_attrs_desc
decl_stmt|;
for|for
control|(
init|;
name|a
operator|->
name|desc
operator|!=
name|NULL
condition|;
name|a
operator|++
control|)
if|if
condition|(
name|attr
operator|==
name|a
operator|->
name|attr
condition|)
break|break;
return|return
operator|(
operator|(
name|a
operator|->
name|desc
operator|!=
name|NULL
operator|)
condition|?
name|a
operator|->
name|desc
else|:
literal|"Unknown"
operator|)
return|;
block|}
end_function

begin_function
name|char
specifier|const
modifier|*
name|sdp_uuid2desc
parameter_list|(
name|uint16_t
name|uuid
parameter_list|)
block|{
specifier|register
name|sdp_attr_desc_p
name|a
init|=
name|sdp_uuids_desc
decl_stmt|;
for|for
control|(
init|;
name|a
operator|->
name|desc
operator|!=
name|NULL
condition|;
name|a
operator|++
control|)
if|if
condition|(
name|uuid
operator|==
name|a
operator|->
name|attr
condition|)
break|break;
return|return
operator|(
operator|(
name|a
operator|->
name|desc
operator|!=
name|NULL
operator|)
condition|?
name|a
operator|->
name|desc
else|:
literal|"Unknown"
operator|)
return|;
block|}
end_function

begin_function
name|void
name|sdp_print
parameter_list|(
name|uint32_t
name|level
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|start
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|end
parameter_list|)
block|{
union|union
block|{
name|int8_t
name|int8
decl_stmt|;
name|int16_t
name|int16
decl_stmt|;
name|int32_t
name|int32
decl_stmt|;
name|int64_t
name|int64
decl_stmt|;
name|int128_t
name|int128
decl_stmt|;
name|uint8_t
name|uint8
decl_stmt|;
name|uint16_t
name|uint16
decl_stmt|;
name|uint32_t
name|uint32
decl_stmt|;
name|uint64_t
name|uint64
decl_stmt|;
block|}
name|value
union|;
name|uint8_t
name|type
decl_stmt|;
name|uint32_t
name|i
decl_stmt|;
if|if
condition|(
name|start
operator|==
name|NULL
operator|||
name|end
operator|==
name|NULL
condition|)
return|return;
while|while
condition|(
name|start
operator|<
name|end
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|level
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"\t"
argument_list|)
expr_stmt|;
name|SDP_GET8
argument_list|(
name|type
argument_list|,
name|start
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|SDP_DATA_NIL
case|:
name|printf
argument_list|(
literal|"nil\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UINT8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uint8 %u\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UINT16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uint16 %u\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UINT32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uint32 %u\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UINT64
case|:
name|SDP_GET64
argument_list|(
name|value
operator|.
name|uint64
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uint64 %ju\n"
argument_list|,
name|value
operator|.
name|uint64
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UINT128
case|:
case|case
name|SDP_DATA_INT128
case|:
name|SDP_GET128
argument_list|(
operator|&
name|value
operator|.
name|int128
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"u/int128 %#8.8x%8.8x%8.8x%8.8x\n"
argument_list|,
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|0
index|]
argument_list|,
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|4
index|]
argument_list|,
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|8
index|]
argument_list|,
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|12
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UUID128
case|:
name|SDP_GET_UUID128
argument_list|(
operator|&
name|value
operator|.
name|int128
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uuid128 %#8.8x-%4.4x-%4.4x-%4.4x-%4.4x%8.8x\n"
argument_list|,
name|ntohl
argument_list|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
name|uint16_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|4
index|]
argument_list|)
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
name|uint16_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|6
index|]
argument_list|)
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
name|uint16_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|8
index|]
argument_list|)
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
name|uint16_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|10
index|]
argument_list|)
argument_list|,
name|ntohl
argument_list|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|value
operator|.
name|int128
operator|.
name|b
index|[
literal|12
index|]
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_INT8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|int8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int8 %d\n"
argument_list|,
name|value
operator|.
name|int8
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_INT16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|int16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int16 %d\n"
argument_list|,
name|value
operator|.
name|int16
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_INT32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|int32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int32 %d\n"
argument_list|,
name|value
operator|.
name|int32
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_INT64
case|:
name|SDP_GET64
argument_list|(
name|value
operator|.
name|int64
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int64 %ju\n"
argument_list|,
name|value
operator|.
name|int64
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UUID16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uuid16 %#4.4x - %s\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|,
name|sdp_uuid2desc
argument_list|(
name|value
operator|.
name|uint16
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_UUID32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"uuid32 %#8.8x\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_STR8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"str8 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|,
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint8
expr_stmt|;
break|break;
case|case
name|SDP_DATA_STR16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"str16 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|,
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint16
expr_stmt|;
break|break;
case|case
name|SDP_DATA_STR32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"str32 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|,
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint32
expr_stmt|;
break|break;
case|case
name|SDP_DATA_BOOL
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"bool %d\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
break|break;
case|case
name|SDP_DATA_SEQ8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"seq8 %d\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint8
expr_stmt|;
break|break;
case|case
name|SDP_DATA_SEQ16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"seq16 %d\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint16
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint16
expr_stmt|;
break|break;
case|case
name|SDP_DATA_SEQ32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"seq32 %d\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint32
expr_stmt|;
break|break;
case|case
name|SDP_DATA_ALT8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"alt8 %d\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint8
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint8
expr_stmt|;
break|break;
case|case
name|SDP_DATA_ALT16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"alt16 %d\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint16
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint16
expr_stmt|;
break|break;
case|case
name|SDP_DATA_ALT32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"alt32 %d\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
name|sdp_print
argument_list|(
name|level
operator|+
literal|1
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|value
operator|.
name|uint32
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint32
expr_stmt|;
break|break;
case|case
name|SDP_DATA_URL8
case|:
name|SDP_GET8
argument_list|(
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"url8 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint8
argument_list|,
name|value
operator|.
name|uint8
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint8
expr_stmt|;
break|break;
case|case
name|SDP_DATA_URL16
case|:
name|SDP_GET16
argument_list|(
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"url16 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint16
argument_list|,
name|value
operator|.
name|uint16
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint16
expr_stmt|;
break|break;
case|case
name|SDP_DATA_URL32
case|:
name|SDP_GET32
argument_list|(
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"url32 %*.*s\n"
argument_list|,
name|value
operator|.
name|uint32
argument_list|,
name|value
operator|.
name|uint32
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
name|value
operator|.
name|uint32
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"unknown data type: %#02x\n"
argument_list|,
operator|*
name|start
operator|++
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

end_unit

