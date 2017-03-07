begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    This file contains all NetFn Transport commands, including:     IPM LAN Commands (Chapter 23)     IPMI Serial/Modem Commands (Chapter 25)     SOL Commands (Chapter 26)     Command Forwarding Commands (Chapter 35b)    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_TRANSPORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_TRANSPORT_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Net function definition for Transport command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_TRANSPORT
value|0x0C
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for IPM LAN Commands (Chapter 23)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Lan Configuration Parameters command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_LAN_CONFIG_PARAMETERS
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Lan Configuration Parameters" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LAN Management Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IpmiLanReserved1
block|,
name|IpmiLanReserved2
block|,
name|IpmiLanAuthType
block|,
name|IpmiLanIpAddress
block|,
name|IpmiLanIpAddressSource
block|,
name|IpmiLanMacAddress
block|,
name|IpmiLanSubnetMask
block|,
name|IpmiLanIpv4HeaderParam
block|,
name|IpmiLanPrimaryRcmpPort
block|,
name|IpmiLanSecondaryRcmpPort
block|,
name|IpmiLanBmcGeneratedArpCtrl
block|,
name|IpmiLanArpInterval
block|,
name|IpmiLanDefaultGateway
block|,
name|IpmiLanDefaultGatewayMac
block|,
name|IpmiLanBackupGateway
block|,
name|IpmiLanBackupGatewayMac
block|,
name|IpmiLanCommunityString
block|,
name|IpmiLanReserved3
block|,
name|IpmiLanDestinationType
block|,
name|IpmiLanDestinationAddress
block|}
name|IPMI_LAN_OPTION_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// IP Address Source
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IpmiUnspecified
block|,
name|IpmiStaticAddrsss
block|,
name|IpmiDynamicAddressBmcDhcp
block|,
name|IpmiDynamicAddressBiosDhcp
block|,
name|IpmiDynamicAddressBmcNonDhcp
block|}
name|IPMI_IP_ADDRESS_SRC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Destination Type
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IpmiPetTrapDestination
block|,
name|IpmiDirectedEventDestination
block|,
name|IpmiReserved1
block|,
name|IpmiReserved2
block|,
name|IpmiReserved3
block|,
name|IpmiReserved4
block|,
name|IpmiReserved5
block|,
name|IpmiOem1
block|,
name|IpmiOem2
block|}
name|IPMI_LAN_DEST_TYPE_DEST_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|NoAuth
range|:
literal|1
decl_stmt|;
name|UINT8
name|MD2Auth
range|:
literal|1
decl_stmt|;
name|UINT8
name|MD5Auth
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|1
decl_stmt|;
name|UINT8
name|StraightPswd
range|:
literal|1
decl_stmt|;
name|UINT8
name|OemType
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|2
decl_stmt|;
block|}
name|IPMI_LAN_AUTH_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|IpAddress
index|[
literal|4
index|]
decl_stmt|;
block|}
name|IPMI_LAN_IP_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AddressSrc
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_LAN_IP_ADDRESS_SRC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|MacAddress
index|[
literal|6
index|]
decl_stmt|;
block|}
name|IPMI_LAN_MAC_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|IpAddress
index|[
literal|4
index|]
decl_stmt|;
block|}
name|IPMI_LAN_SUBNET_MASK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TimeToLive
decl_stmt|;
name|UINT8
name|IpFlag
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|5
decl_stmt|;
name|UINT8
name|Precedence
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|1
decl_stmt|;
name|UINT8
name|ServiceType
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_LAN_IPV4_HDR_PARAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|RcmpPortMsb
decl_stmt|;
name|UINT8
name|RcmpPortLsb
decl_stmt|;
block|}
name|IPMI_LAN_RCMP_PORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EnableBmcArpResponse
range|:
literal|1
decl_stmt|;
name|UINT8
name|EnableBmcGratuitousArp
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
block|}
name|IPMI_LAN_BMC_GENERATED_ARP_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ArpInterval
decl_stmt|;
block|}
name|IPMI_LAN_ARP_INTERVAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Data
index|[
literal|18
index|]
decl_stmt|;
block|}
name|IPMI_LAN_COMMUNITY_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DestinationSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT8
name|DestinationType
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|AlertAcknowledged
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_LAN_DEST_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DestinationSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|AlertingIpAddressSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|AddressFormat
range|:
literal|4
decl_stmt|;
name|UINT8
name|UseDefaultGateway
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|7
decl_stmt|;
name|IPMI_LAN_IP_ADDRESS
name|AlertingIpAddress
decl_stmt|;
name|IPMI_LAN_MAC_ADDRESS
name|AlertingMacAddress
decl_stmt|;
block|}
name|IPMI_LAN_DEST_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|IPMI_LAN_AUTH_TYPE
name|IpmiLanAuthType
decl_stmt|;
name|IPMI_LAN_IP_ADDRESS
name|IpmiLanIpAddress
decl_stmt|;
name|IPMI_LAN_IP_ADDRESS_SRC
name|IpmiLanIpAddressSrc
decl_stmt|;
name|IPMI_LAN_MAC_ADDRESS
name|IpmiLanMacAddress
decl_stmt|;
name|IPMI_LAN_SUBNET_MASK
name|IpmiLanSubnetMask
decl_stmt|;
name|IPMI_LAN_IPV4_HDR_PARAM
name|IpmiLanIpv4HdrParam
decl_stmt|;
name|IPMI_LAN_RCMP_PORT
name|IpmiLanPrimaryRcmpPort
decl_stmt|;
name|IPMI_LAN_BMC_GENERATED_ARP_CONTROL
name|IpmiLanArpControl
decl_stmt|;
name|IPMI_LAN_ARP_INTERVAL
name|IpmiLanArpInterval
decl_stmt|;
name|IPMI_LAN_COMMUNITY_STRING
name|IpmiLanCommunityString
decl_stmt|;
name|IPMI_LAN_DEST_TYPE
name|IpmiLanDestType
decl_stmt|;
name|IPMI_LAN_DEST_ADDRESS
name|IpmiLanDestAddress
decl_stmt|;
block|}
name|IPMI_LAN_OPTIONS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Lan Configuration Parameters command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_LAN_CONFIG_PARAMETERS
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Lan Configuration Parameters" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Suspend BMC ARPs command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SUSPEND_BMC_ARPS
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Suspend BMC ARPs" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get IP-UDP-RMCP Statistics command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_PACKET_STATISTICS
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get IP-UDP-RMCP Statistics" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for IPMI Serial/Modem Commands (Chapter 25)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Serial/Modem Configuration command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_SERIAL_CONFIGURATION
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Serial/Modem Configuration" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// EMP OPTION DATA
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|NoAuthentication
range|:
literal|1
decl_stmt|;
name|UINT8
name|MD2Authentication
range|:
literal|1
decl_stmt|;
name|UINT8
name|MD5Authentication
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|1
decl_stmt|;
name|UINT8
name|StraightPassword
range|:
literal|1
decl_stmt|;
name|UINT8
name|OemProprietary
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reservd2
range|:
literal|2
decl_stmt|;
block|}
name|IPMI_EMP_AUTH_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EnableBasicMode
range|:
literal|1
decl_stmt|;
name|UINT8
name|EnablePPPMode
range|:
literal|1
decl_stmt|;
name|UINT8
name|EnableTerminalMode
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|2
decl_stmt|;
name|UINT8
name|SnoopOsPPPNegotiation
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|1
decl_stmt|;
name|UINT8
name|DirectConnect
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_EMP_CONNECTION_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|InactivityTimeout
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_EMP_INACTIVITY_TIMEOUT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|IpmiCallback
range|:
literal|1
decl_stmt|;
name|UINT8
name|CBCPCallback
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|6
decl_stmt|;
name|UINT8
name|CbcpEnableNoCallback
range|:
literal|1
decl_stmt|;
name|UINT8
name|CbcpEnablePreSpecifiedNumber
range|:
literal|1
decl_stmt|;
name|UINT8
name|CbcpEnableUserSpecifiedNumber
range|:
literal|1
decl_stmt|;
name|UINT8
name|CbcpEnableCallbackFromList
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|CallbackDestination1
decl_stmt|;
name|UINT8
name|CallbackDestination2
decl_stmt|;
name|UINT8
name|CallbackDestination3
decl_stmt|;
block|}
name|IPMI_EMP_CHANNEL_CALLBACK_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CloseSessionOnDCDLoss
range|:
literal|1
decl_stmt|;
name|UINT8
name|EnableSessionInactivityTimeout
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
block|}
name|IPMI_EMP_SESSION_TERMINATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved1
range|:
literal|5
decl_stmt|;
name|UINT8
name|EnableDtrHangup
range|:
literal|1
decl_stmt|;
name|UINT8
name|FlowControl
range|:
literal|2
decl_stmt|;
name|UINT8
name|BitRate
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT8
name|SaveSetting
range|:
literal|1
decl_stmt|;
name|UINT8
name|SetComPort
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved3
range|:
literal|6
decl_stmt|;
block|}
name|IPMI_EMP_MESSAGING_COM_SETTING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|RingDurationInterval
range|:
literal|6
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|2
decl_stmt|;
name|UINT8
name|RingDeadTime
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_EMP_MODEM_RING_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved
decl_stmt|;
name|UINT8
name|InitString
index|[
literal|48
index|]
decl_stmt|;
block|}
name|IPMI_EMP_MODEM_INIT_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EscapeSequence
index|[
literal|5
index|]
decl_stmt|;
block|}
name|IPMI_EMP_MODEM_ESC_SEQUENCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|HangupSequence
index|[
literal|8
index|]
decl_stmt|;
block|}
name|IPMI_EMP_MODEM_HANGUP_SEQUENCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ModelDialCommend
index|[
literal|8
index|]
decl_stmt|;
block|}
name|IPMI_MODEM_DIALUP_COMMAND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PageBlackoutInterval
decl_stmt|;
block|}
name|IPMI_PAGE_BLACKOUT_INTERVAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CommunityString
index|[
literal|18
index|]
decl_stmt|;
block|}
name|IPMI_EMP_COMMUNITY_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved5
range|:
literal|4
decl_stmt|;
name|UINT8
name|DialStringSelector
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_DIAL_PAGE_DESTINATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TapAccountSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_TAP_PAGE_DESTINATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PPPAccountSetSelector
decl_stmt|;
name|UINT8
name|DialStringSelector
decl_stmt|;
block|}
name|IPMI_PPP_ALERT_DESTINATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|IPMI_DIAL_PAGE_DESTINATION
name|DialPageDestination
decl_stmt|;
name|IPMI_TAP_PAGE_DESTINATION
name|TapPageDestination
decl_stmt|;
name|IPMI_PPP_ALERT_DESTINATION
name|PppAlertDestination
decl_stmt|;
block|}
name|IPMI_DEST_TYPE_SPECIFIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DestinationSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|DestinationType
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|3
decl_stmt|;
name|UINT8
name|AlertAckRequired
range|:
literal|1
decl_stmt|;
name|UINT8
name|AlertAckTimeoutSeconds
decl_stmt|;
name|UINT8
name|NumRetriesCall
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved3
range|:
literal|1
decl_stmt|;
name|UINT8
name|NumRetryAlert
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved4
range|:
literal|1
decl_stmt|;
name|IPMI_DEST_TYPE_SPECIFIC
name|DestinationTypeSpecific
decl_stmt|;
block|}
name|IPMI_EMP_DESTINATION_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DestinationSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|Parity
range|:
literal|3
decl_stmt|;
name|UINT8
name|CharacterSize
range|:
literal|1
decl_stmt|;
name|UINT8
name|StopBit
range|:
literal|1
decl_stmt|;
name|UINT8
name|DtrHangup
range|:
literal|1
decl_stmt|;
name|UINT8
name|FlowControl
range|:
literal|2
decl_stmt|;
name|UINT8
name|BitRate
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT8
name|SaveSetting
range|:
literal|1
decl_stmt|;
name|UINT8
name|SetComPort
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved3
range|:
literal|6
decl_stmt|;
block|}
name|IPMI_EMP_DESTINATION_COM_SETTING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DialStringSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
name|UINT8
name|DialString
index|[
literal|48
index|]
decl_stmt|;
block|}
name|IPMI_DESTINATION_DIAL_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT32
name|IpAddressLong
decl_stmt|;
name|UINT8
name|IpAddress
index|[
literal|4
index|]
decl_stmt|;
block|}
name|IPMI_PPP_IP_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|IpAddressSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|IPMI_PPP_IP_ADDRESS
name|PppIpAddress
decl_stmt|;
block|}
name|IPMI_DESTINATION_IP_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TapSelector
decl_stmt|;
name|UINT8
name|TapServiceSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|TapDialStringSelector
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_DESTINATION_TAP_ACCOUNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TapSelector
decl_stmt|;
name|UINT8
name|PagerIdString
index|[
literal|16
index|]
decl_stmt|;
block|}
name|IPMI_TAP_PAGER_ID_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
name|OptionData
decl_stmt|;
name|IPMI_EMP_AUTH_TYPE
name|EmpAuthType
decl_stmt|;
name|IPMI_EMP_CONNECTION_TYPE
name|EmpConnectionType
decl_stmt|;
name|IPMI_EMP_INACTIVITY_TIMEOUT
name|EmpInactivityTimeout
decl_stmt|;
name|IPMI_EMP_CHANNEL_CALLBACK_CONTROL
name|EmpCallbackControl
decl_stmt|;
name|IPMI_EMP_SESSION_TERMINATION
name|EmpSessionTermination
decl_stmt|;
name|IPMI_EMP_MESSAGING_COM_SETTING
name|EmpMessagingComSetting
decl_stmt|;
name|IPMI_EMP_MODEM_RING_TIME
name|EmpModemRingTime
decl_stmt|;
name|IPMI_EMP_MODEM_INIT_STRING
name|EmpModemInitString
decl_stmt|;
name|IPMI_EMP_MODEM_ESC_SEQUENCE
name|EmpModemEscSequence
decl_stmt|;
name|IPMI_EMP_MODEM_HANGUP_SEQUENCE
name|EmpModemHangupSequence
decl_stmt|;
name|IPMI_MODEM_DIALUP_COMMAND
name|EmpModemDialupCommand
decl_stmt|;
name|IPMI_PAGE_BLACKOUT_INTERVAL
name|EmpPageBlackoutInterval
decl_stmt|;
name|IPMI_EMP_COMMUNITY_STRING
name|EmpCommunityString
decl_stmt|;
name|IPMI_EMP_DESTINATION_INFO
name|EmpDestinationInfo
decl_stmt|;
name|IPMI_EMP_DESTINATION_COM_SETTING
name|EmpDestinationComSetting
decl_stmt|;
name|UINT8
name|CallRetryBusySignalInterval
decl_stmt|;
name|IPMI_DESTINATION_DIAL_STRING
name|DestinationDialString
decl_stmt|;
name|IPMI_DESTINATION_IP_ADDRESS
name|DestinationIpAddress
decl_stmt|;
name|IPMI_DESTINATION_TAP_ACCOUNT
name|DestinationTapAccount
decl_stmt|;
name|IPMI_TAP_PAGER_ID_STRING
name|TapPagerIdString
decl_stmt|;
block|}
name|IPMI_EMP_OPTIONS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Serial/Modem Configuration command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_SERIAL_CONFIGURATION
value|0x11
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Serial/Modem Configuration" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Serial/Modem Mux command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_SERIAL_MUX
value|0x12
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Serial/Modem Mux" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ChannelNo
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
name|UINT8
name|MuxSetting
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_SET_SERIAL_MODEM_MUX_COMMAND_REQUEST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|MuxSetToBmc
range|:
literal|1
decl_stmt|;
name|UINT8
name|CommandStatus
range|:
literal|1
decl_stmt|;
name|UINT8
name|MessagingSessionActive
range|:
literal|1
decl_stmt|;
name|UINT8
name|AlertInProgress
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved2
range|:
literal|2
decl_stmt|;
name|UINT8
name|MuxToBmcAllowed
range|:
literal|1
decl_stmt|;
name|UINT8
name|MuxToSystemBlocked
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_SET_SERIAL_MODEM_MUX_COMMAND_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get TAP Response Code command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_TAP_RESPONSE_CODE
value|0x13
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get TAP Response Code" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set PPP UDP Proxy Transmit Data command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_PPP_UDP_PROXY_TXDATA
value|0x14
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set PPP UDP Proxy Transmit Data" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get PPP UDP Proxy Transmit Data command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_PPP_UDP_PROXY_TXDATA
value|0x15
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get PPP UDP Proxy Transmit Data" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Send PPP UDP Proxy Packet command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SEND_PPP_UDP_PROXY_PACKET
value|0x16
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Send PPP UDP Proxy Packet" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get PPP UDP Proxy Receive Data command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_PPP_UDP_PROXY_RX
value|0x17
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get PPP UDP Proxy Receive Data" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Serial/Modem connection active command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SERIAL_CONNECTION_ACTIVE
value|0x18
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Serial/Modem connection active" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Callback command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_CALLBACK
value|0x19
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Callback" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set user Callback Options command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_USER_CALLBACK_OPTIONS
value|0x1A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set user Callback Options" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get user Callback Options command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_USER_CALLBACK_OPTIONS
value|0x1B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get user Callback Options" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for SOL Commands (Chapter 26)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for SOL activating command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SOL_ACTIVATING
value|0x20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "SOL activating" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set SOL Configuration Parameters command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_SET_SOL_CONFIG_PARAM
value|0x21
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set SOL Configuration Parameters" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SOL Configuration Parameters command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_TRANSPORT_GET_SOL_CONFIG_PARAM
value|0x22
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SOL Configuration Parameters" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

