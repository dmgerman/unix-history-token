begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.   IPMI Intelligent Chassis Management Bus Bridge Specification Version 1.0,   Revision 1.3.    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_BRIDGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_BRIDGE_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Net function definition for Bridge command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_BRIDGE
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Bridge State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_STATE
value|0x00
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Bridge State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Bridge State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_STATE
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Bridge State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ICMB Address command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_ICMB_ADDRESS
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get ICMB Address" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set ICMB Address command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_ICMB_ADDRESS
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set ICMB Address" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Bridge Proxy Address command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_PROXY_ADDRESS
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Bridge Proxy Address" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Bridge Statistics command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_BRIDGE_STATISTICS
value|0x05
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Bridge Statistics" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ICMB Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_ICMB_CAPABILITIES
value|0x06
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get ICMB Capabilities" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Clear Bridge Statistics command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_CLEAR_STATISTICS
value|0x08
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Clear Bridge Statistics" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Bridge Proxy Address command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_PROXY_ADDRESS
value|0x09
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Bridge Proxy Address" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ICMB Connector Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_ICMB_CONNECTOR_INFO
value|0x0A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get ICMB Connector Info " command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ICMB Connection ID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_ICMB_CONNECTION_ID
value|0x0B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get ICMB Connection ID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ICMB Connection ID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SEND_ICMB_CONNECTION_ID
value|0x0C
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Send ICMB Connection ID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Prepare for Discoveery command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_PREPARE_FOR_DISCOVERY
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Prepare for Discoveery" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Addresses command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_ADDRESSES
value|0x11
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Addresses" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Discovered command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_DISCOVERED
value|0x12
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Discovered" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Chassis Device ID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_CHASSIS_DEVICEID
value|0x13
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Chassis Device ID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Chassis Device ID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_CHASSIS_DEVICEID
value|0x14
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Chassis Device ID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Bridge Request command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_REQUEST
value|0x20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Bridge Request" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Bridge Message command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_MESSAGE
value|0x21
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Bridge Message" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Event Count command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_GET_EVENT_COUNT
value|0x30
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Event Count" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Event Destination command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_EVENT_DESTINATION
value|0x31
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Event Destination" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Event Reception State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_EVENT_RECEPTION_STATE
value|0x32
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Event Reception State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Event Reception State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SET_EVENT_RECEPTION_STATE
value|0x32
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Event Reception State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Send ICMB Event Message command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_BRIDGE_SEND_ICMB_EVENT_MESSAGE
value|0x33
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Send ICMB Event Message" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

