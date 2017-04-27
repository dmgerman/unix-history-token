begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_hci.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_hci.h,v 1.2 2003/03/18 00:09:37 max Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains everything that application needs to know about  * Host Controller Interface (HCI). All information was obtained from  * Bluetooth Specification Book v1.1.  *  * This file can be included by both kernel and userland applications.  *  * NOTE: Here and after Bluetooth device is called a "unit". Bluetooth  *       specification refers to both devices and units. They are the  *       same thing (i think), so to be consistent word "unit" will be  *       used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_HCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_HCI_H_
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **     Netgraph node hook name, type name and type cookie and commands  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Node type name and type cookie */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_NODE_TYPE
value|"hci"
end_define

begin_define
define|#
directive|define
name|NGM_HCI_COOKIE
value|1000774184
end_define

begin_comment
comment|/* Netgraph node hook names */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_HOOK_DRV
value|"drv"
end_define

begin_comment
comment|/* Driver<-> HCI */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_HOOK_ACL
value|"acl"
end_define

begin_comment
comment|/* HCI<-> Upper */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_HOOK_SCO
value|"sco"
end_define

begin_comment
comment|/* HCI<-> Upper */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_HOOK_RAW
value|"raw"
end_define

begin_comment
comment|/* HCI<-> Upper */
end_comment

begin_comment
comment|/**************************************************************************  **************************************************************************  **                   Common defines and types (HCI)  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* All sizes are in bytes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_BDADDR_SIZE
value|6
end_define

begin_comment
comment|/* unit address */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LAP_SIZE
value|3
end_define

begin_comment
comment|/* unit LAP */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_KEY_SIZE
value|16
end_define

begin_comment
comment|/* link key */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PIN_SIZE
value|16
end_define

begin_comment
comment|/* link PIN */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MASK_SIZE
value|8
end_define

begin_comment
comment|/* event mask */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LE_EVENT_MASK_SIZE
value|8
end_define

begin_comment
comment|/* event mask */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CLASS_SIZE
value|3
end_define

begin_comment
comment|/* unit class */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_FEATURES_SIZE
value|8
end_define

begin_comment
comment|/* LMP features */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_UNIT_NAME_SIZE
value|248
end_define

begin_comment
comment|/* unit name size */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_COMMANDS_SIZE
value|64
end_define

begin_comment
comment|/*Command list BMP size*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EXTINQ_MAX
value|240
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HCI specification */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_SPEC_V10
value|0x00
end_define

begin_comment
comment|/* v1.0 */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_SPEC_V11
value|0x01
end_define

begin_comment
comment|/* v1.1 */
end_comment

begin_comment
comment|/* 0x02 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* LMP features */
end_comment

begin_comment
comment|/* ------------------- byte 0 --------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LMP_3SLOT
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_5SLOT
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_ENCRYPTION
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_SLOT_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_TIMING_ACCURACY
value|0x10
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_SWITCH
value|0x20
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_HOLD_MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_SNIFF_MODE
value|0x80
end_define

begin_comment
comment|/* ------------------- byte 1 --------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LMP_PARK_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_RSSI
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_CHANNEL_QUALITY
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_SCO_LINK
value|0x08
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_HV2_PKT
value|0x10
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_HV3_PKT
value|0x20
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_ULAW_LOG
value|0x40
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_ALAW_LOG
value|0x80
end_define

begin_comment
comment|/* ------------------- byte 2 --------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LMP_CVSD
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_PAGING_SCHEME
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_POWER_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_TRANSPARENT_SCO
value|0x08
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_FLOW_CONTROL_LAG0
value|0x10
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_FLOW_CONTROL_LAG1
value|0x20
end_define

begin_define
define|#
directive|define
name|NG_HCI_LMP_FLOW_CONTROL_LAG2
value|0x40
end_define

begin_comment
comment|/* Link types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_SCO
value|0x00
end_define

begin_comment
comment|/* Voice */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_ACL
value|0x01
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_LE_PUBLIC
value|0x02
end_define

begin_comment
comment|/* LE Public*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_LE_RANDOM
value|0x03
end_define

begin_comment
comment|/* LE Random*/
end_comment

begin_comment
comment|/* 0x02 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Packet types */
end_comment

begin_comment
comment|/* 0x0001 - 0x0004 - reserved for future use */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DM1
value|0x0008
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DH1
value|0x0010
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_HV1
value|0x0020
end_define

begin_comment
comment|/* SCO link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_HV2
value|0x0040
end_define

begin_comment
comment|/* SCO link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_HV3
value|0x0080
end_define

begin_comment
comment|/* SCO link */
end_comment

begin_comment
comment|/* 0x0100 - 0x0200 - reserved for future use */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DM3
value|0x0400
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DH3
value|0x0800
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_comment
comment|/* 0x1000 - 0x2000 - reserved for future use */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DM5
value|0x4000
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PKT_DH5
value|0x8000
end_define

begin_comment
comment|/* ACL link */
end_comment

begin_comment
comment|/*   * Connection modes/Unit modes  *  * This is confusing. It means that one of the units change its mode  * for the specific connection. For example one connection was put on   * hold (but i could be wrong :)   */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_UNIT_MODE_ACTIVE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_MODE_HOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_MODE_SNIFF
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_MODE_PARK
value|0x03
end_define

begin_comment
comment|/* 0x04 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Page scan modes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_MANDATORY_PAGE_SCAN_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_OPTIONAL_PAGE_SCAN_MODE1
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_OPTIONAL_PAGE_SCAN_MODE2
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_OPTIONAL_PAGE_SCAN_MODE3
value|0x03
end_define

begin_comment
comment|/* 0x04 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Page scan repetition modes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_SCAN_REP_MODE0
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_SCAN_REP_MODE1
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_SCAN_REP_MODE2
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Page scan period modes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PAGE_SCAN_PERIOD_MODE0
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_PAGE_SCAN_PERIOD_MODE1
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_PAGE_SCAN_PERIOD_MODE2
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Scan enable */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_NO_SCAN_ENABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_INQUIRY_ENABLE_PAGE_DISABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_INQUIRY_DISABLE_PAGE_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_INQUIRY_ENABLE_PAGE_ENABLE
value|0x03
end_define

begin_comment
comment|/* 0x04 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Hold mode activities */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_HOLD_MODE_NO_CHANGE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_HOLD_MODE_SUSPEND_PAGE_SCAN
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_HOLD_MODE_SUSPEND_INQUIRY_SCAN
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_HOLD_MODE_SUSPEND_PERIOD_INQUIRY
value|0x04
end_define

begin_comment
comment|/* 0x08 - 0x80 - reserved for future use */
end_comment

begin_comment
comment|/* Connection roles */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_ROLE_MASTER
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_ROLE_SLAVE
value|0x01
end_define

begin_comment
comment|/* 0x02 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Key flags */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_USE_SEMI_PERMANENT_LINK_KEYS
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_USE_TEMPORARY_LINK_KEY
value|0x01
end_define

begin_comment
comment|/* 0x02 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Pin types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PIN_TYPE_VARIABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_PIN_TYPE_FIXED
value|0x01
end_define

begin_comment
comment|/* Link key types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_KEY_TYPE_COMBINATION_KEY
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_LINK_KEY_TYPE_LOCAL_UNIT_KEY
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_LINK_KEY_TYPE_REMOTE_UNIT_KEY
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Encryption modes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_ENCRYPTION_MODE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_ENCRYPTION_MODE_P2P
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_ENCRYPTION_MODE_ALL
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Quality of service types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_SERVICE_TYPE_NO_TRAFFIC
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_SERVICE_TYPE_BEST_EFFORT
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_SERVICE_TYPE_GUARANTEED
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Link policy settings */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_POLICY_DISABLE_ALL_LM_MODES
value|0x0000
end_define

begin_define
define|#
directive|define
name|NG_HCI_LINK_POLICY_ENABLE_ROLE_SWITCH
value|0x0001
end_define

begin_comment
comment|/* Master/Slave switch */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LINK_POLICY_ENABLE_HOLD_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|NG_HCI_LINK_POLICY_ENABLE_SNIFF_MODE
value|0x0004
end_define

begin_define
define|#
directive|define
name|NG_HCI_LINK_POLICY_ENABLE_PARK_MODE
value|0x0008
end_define

begin_comment
comment|/* 0x0010 - 0x8000 - reserved for future use */
end_comment

begin_comment
comment|/* Event masks */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_ALL
value|0x00000000ffffffff
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_NONE
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_INQUIRY_COMPL
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_INQUIRY_RESULT
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_CON_COMPL
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_CON_REQ
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_DISCON_COMPL
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_AUTH_COMPL
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_REMOTE_NAME_REQ_COMPL
value|0x0000000000000040
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_ENCRYPTION_CHANGE
value|0x0000000000000080
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_CHANGE_CON_LINK_KEY_COMPL
value|0x0000000000000100
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_MASTER_LINK_KEY_COMPL
value|0x0000000000000200
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_READ_REMOTE_FEATURES_COMPL
value|0x0000000000000400
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_READ_REMOTE_VER_INFO_COMPL
value|0x0000000000000800
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_QOS_SETUP_COMPL
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_COMMAND_COMPL
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_COMMAND_STATUS
value|0x0000000000004000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_HARDWARE_ERROR
value|0x0000000000008000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_FLUSH_OCCUR
value|0x0000000000010000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_ROLE_CHANGE
value|0x0000000000020000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_NUM_COMPL_PKTS
value|0x0000000000040000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_MODE_CHANGE
value|0x0000000000080000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_RETURN_LINK_KEYS
value|0x0000000000100000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_PIN_CODE_REQ
value|0x0000000000200000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_LINK_KEY_REQ
value|0x0000000000400000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_LINK_KEY_NOTIFICATION
value|0x0000000000800000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_LOOPBACK_COMMAND
value|0x0000000001000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_DATA_BUFFER_OVERFLOW
value|0x0000000002000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_MAX_SLOT_CHANGE
value|0x0000000004000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_READ_CLOCK_OFFSET_COMLETE
value|0x0000000008000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_CON_PKT_TYPE_CHANGED
value|0x0000000010000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_QOS_VIOLATION
value|0x0000000020000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_PAGE_SCAN_MODE_CHANGE
value|0x0000000040000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVMSK_PAGE_SCAN_REP_MODE_CHANGE
value|0x0000000080000000
end_define

begin_comment
comment|/* 0x0000000100000000 - 0x8000000000000000 - reserved for future use */
end_comment

begin_comment
comment|/* Filter types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_FILTER_TYPE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_TYPE_INQUIRY_RESULT
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_TYPE_CON_SETUP
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Filter condition types for NG_HCI_FILTER_TYPE_INQUIRY_RESULT */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_INQUIRY_NEW_UNIT
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_INQUIRY_UNIT_CLASS
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_INQUIRY_BDADDR
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Filter condition types for NG_HCI_FILTER_TYPE_CON_SETUP */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_CON_ANY_UNIT
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_CON_UNIT_CLASS
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_FILTER_COND_CON_BDADDR
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Xmit level types */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_XMIT_LEVEL_CURRENT
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_XMIT_LEVEL_MAXIMUM
value|0x01
end_define

begin_comment
comment|/* 0x02 - 0xFF - reserved for future use */
end_comment

begin_comment
comment|/* Host to Host Controller flow control */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_H2HC_FLOW_CONTROL_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_H2HC_FLOW_CONTROL_ACL
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_H2HC_FLOW_CONTROL_SCO
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_H2HC_FLOW_CONTROL_BOTH
value|0x03
end_define

begin_comment
comment|/* ACL and SCO */
end_comment

begin_comment
comment|/* 0x04 - 0xFF - reserved future use */
end_comment

begin_comment
comment|/* Country codes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_COUNTRY_CODE_NAM_EUR_JP
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_COUNTRY_CODE_FRANCE
value|0x01
end_define

begin_comment
comment|/* 0x02 - 0xFF - reserved future use */
end_comment

begin_comment
comment|/* Loopback modes */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LOOPBACK_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|NG_HCI_LOOPBACK_LOCAL
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_LOOPBACK_REMOTE
value|0x02
end_define

begin_comment
comment|/* 0x03 - 0xFF - reserved future use */
end_comment

begin_comment
comment|/**************************************************************************  **************************************************************************  **                 Link level defines, headers and types  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/*   * Macro(s) to combine OpCode and extract OGF (OpCode Group Field)   * and OCF (OpCode Command Field) from OpCode.  */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OPCODE
parameter_list|(
name|gf
parameter_list|,
name|cf
parameter_list|)
value|((((gf)& 0x3f)<< 10) | ((cf)& 0x3ff))
end_define

begin_define
define|#
directive|define
name|NG_HCI_OCF
parameter_list|(
name|op
parameter_list|)
value|((op)& 0x3ff)
end_define

begin_define
define|#
directive|define
name|NG_HCI_OGF
parameter_list|(
name|op
parameter_list|)
value|(((op)>> 10)& 0x3f)
end_define

begin_comment
comment|/*   * Marco(s) to extract/combine connection handle, BC (Broadcast) and   * PB (Packet boundary) flags.  */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CON_HANDLE
parameter_list|(
name|h
parameter_list|)
value|((h)& 0x0fff)
end_define

begin_define
define|#
directive|define
name|NG_HCI_PB_FLAG
parameter_list|(
name|h
parameter_list|)
value|(((h)& 0x3000)>> 12)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BC_FLAG
parameter_list|(
name|h
parameter_list|)
value|(((h)& 0xc000)>> 14)
end_define

begin_define
define|#
directive|define
name|NG_HCI_MK_CON_HANDLE
parameter_list|(
name|h
parameter_list|,
name|pb
parameter_list|,
name|bc
parameter_list|)
define|\
value|(((h)& 0x0fff) | (((pb)& 3)<< 12) | (((bc)& 3)<< 14))
end_define

begin_comment
comment|/* PB flag values */
end_comment

begin_comment
comment|/* 00 - reserved for future use */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_PACKET_FRAGMENT
value|0x1
end_define

begin_define
define|#
directive|define
name|NG_HCI_PACKET_START
value|0x2
end_define

begin_comment
comment|/* 11 - reserved for future use */
end_comment

begin_comment
comment|/* BC flag values */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_POINT2POINT
value|0x0
end_define

begin_comment
comment|/* only Host controller to Host */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_BROADCAST_ACTIVE
value|0x1
end_define

begin_comment
comment|/* both directions */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_BROADCAST_PICONET
value|0x2
end_define

begin_comment
comment|/* both directions */
end_comment

begin_comment
comment|/* 11 - reserved for future use */
end_comment

begin_comment
comment|/* HCI command packet header */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CMD_PKT
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_HCI_CMD_PKT_SIZE
value|0xff
end_define

begin_comment
comment|/* without header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* MUST be 0x1 */
name|u_int16_t
name|opcode
decl_stmt|;
comment|/* OpCode */
name|u_int8_t
name|length
decl_stmt|;
comment|/* parameter(s) length in bytes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_cmd_pkt_t
typedef|;
end_typedef

begin_comment
comment|/* ACL data packet header */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_ACL_DATA_PKT
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_HCI_ACL_PKT_SIZE
value|0xffff
end_define

begin_comment
comment|/* without header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* MUST be 0x2 */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle + PB + BC flags */
name|u_int16_t
name|length
decl_stmt|;
comment|/* payload length in bytes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_acldata_pkt_t
typedef|;
end_typedef

begin_comment
comment|/* SCO data packet header */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_SCO_DATA_PKT
value|0x03
end_define

begin_define
define|#
directive|define
name|NG_HCI_SCO_PKT_SIZE
value|0xff
end_define

begin_comment
comment|/* without header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* MUST be 0x3 */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle + reserved bits */
name|u_int8_t
name|length
decl_stmt|;
comment|/* payload length in bytes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_scodata_pkt_t
typedef|;
end_typedef

begin_comment
comment|/* HCI event packet header */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EVENT_PKT
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVENT_PKT_SIZE
value|0xff
end_define

begin_comment
comment|/* without header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* MUST be 0x4 */
name|u_int8_t
name|event
decl_stmt|;
comment|/* event */
name|u_int8_t
name|length
decl_stmt|;
comment|/* parameter(s) length in bytes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_event_pkt_t
typedef|;
end_typedef

begin_comment
comment|/* Bluetooth unit address */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|b
index|[
name|NG_HCI_BDADDR_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|bdaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bdaddr_t
modifier|*
name|bdaddr_p
typedef|;
end_typedef

begin_comment
comment|/* Any BD_ADDR. Note: This is actually 7 bytes (count '\0' terminator) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_BDADDR_ANY
value|((bdaddr_p) "\000\000\000\000\000\000")
end_define

begin_comment
comment|/* HCI status return parameter */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_status_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **        Upper layer protocol interface. LP_xxx event parameters  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Connection Request Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_CON_REQ
value|1
end_define

begin_comment
comment|/* Upper -> HCI */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|link_type
decl_stmt|;
comment|/* type of connection */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_hci_lp_con_req_ep
typedef|;
end_typedef

begin_comment
comment|/*  * XXX XXX XXX  *  * NOTE: This request is not defined by Bluetooth specification,   * but i find it useful :)  */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_DISCON_REQ
value|2
end_define

begin_comment
comment|/* Upper -> HCI */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|reason
decl_stmt|;
comment|/* reason to disconnect (only low byte) */
block|}
name|ng_hci_lp_discon_req_ep
typedef|;
end_typedef

begin_comment
comment|/* Connection Confirmation Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_CON_CFM
value|3
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* link type */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* con_handle */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_hci_lp_con_cfm_ep
typedef|;
end_typedef

begin_comment
comment|/* Connection Indication Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_CON_IND
value|4
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* link type */
name|u_int8_t
name|uclass
index|[
name|NG_HCI_CLASS_SIZE
index|]
decl_stmt|;
comment|/* unit class */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_hci_lp_con_ind_ep
typedef|;
end_typedef

begin_comment
comment|/* Connection Response Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_CON_RSP
value|5
end_define

begin_comment
comment|/* Upper -> HCI */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - accept connection */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* link type */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_hci_lp_con_rsp_ep
typedef|;
end_typedef

begin_comment
comment|/* Disconnection Indication Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_DISCON_IND
value|6
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|reason
decl_stmt|;
comment|/* reason to disconnect (only low byte) */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* link type */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|ng_hci_lp_discon_ind_ep
typedef|;
end_typedef

begin_comment
comment|/* QoS Setup Request Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_QOS_REQ
value|7
end_define

begin_comment
comment|/* Upper -> HCI */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* reserved */
name|u_int8_t
name|service_type
decl_stmt|;
comment|/* service type */
name|u_int32_t
name|token_rate
decl_stmt|;
comment|/* bytes/sec */
name|u_int32_t
name|peak_bandwidth
decl_stmt|;
comment|/* bytes/sec */
name|u_int32_t
name|latency
decl_stmt|;
comment|/* msec */
name|u_int32_t
name|delay_variation
decl_stmt|;
comment|/* msec */
block|}
name|ng_hci_lp_qos_req_ep
typedef|;
end_typedef

begin_comment
comment|/* QoS Conformition Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_QOS_CFM
value|8
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|status
decl_stmt|;
comment|/* 0x00 - success  (only low byte) */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|ng_hci_lp_qos_cfm_ep
typedef|;
end_typedef

begin_comment
comment|/* QoS Violation Indication Event */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_QOS_IND
value|9
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|ng_hci_lp_qos_ind_ep
typedef|;
end_typedef

begin_comment
comment|/*Encryption Change event*/
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_LP_ENC_CHG
value|10
end_define

begin_comment
comment|/* HCI->Upper*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|con_handle
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|link_type
decl_stmt|;
block|}
name|ng_hci_lp_enc_change_ep
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **                    HCI node command/event parameters  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Debug levels */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_ALERT_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|NG_HCI_ERR_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|NG_HCI_WARN_LEVEL
value|3
end_define

begin_define
define|#
directive|define
name|NG_HCI_INFO_LEVEL
value|4
end_define

begin_comment
comment|/* Unit states */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_UNIT_CONNECTED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_INITED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_READY
value|(NG_HCI_UNIT_CONNECTED|NG_HCI_UNIT_INITED)
end_define

begin_define
define|#
directive|define
name|NG_HCI_UNIT_COMMAND_PENDING
value|(1<< 2)
end_define

begin_comment
comment|/* Connection state */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CON_CLOSED
value|0
end_define

begin_comment
comment|/* connection closed */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CON_W4_LP_CON_RSP
value|1
end_define

begin_comment
comment|/* wait for LP_ConnectRsp */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CON_W4_CONN_COMPLETE
value|2
end_define

begin_comment
comment|/* wait for Connection_Complete evt */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_CON_OPEN
value|3
end_define

begin_comment
comment|/* connection open */
end_comment

begin_comment
comment|/* Get HCI node (unit) state (see states above) */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_STATE
value|100
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_hci_node_state_ep
typedef|;
end_typedef

begin_comment
comment|/* Turn on "inited" bit */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_INIT
value|101
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_comment
comment|/* No parameters */
end_comment

begin_comment
comment|/* Get/Set node debug level (see debug levels above) */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_DEBUG
value|102
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_SET_DEBUG
value|103
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_hci_node_debug_ep
typedef|;
end_typedef

begin_comment
comment|/* Get node buffer info */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_BUFFER
value|104
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|cmd_free
decl_stmt|;
comment|/* number of free command packets */
name|u_int8_t
name|sco_size
decl_stmt|;
comment|/* max. size of SCO packet */
name|u_int16_t
name|sco_pkts
decl_stmt|;
comment|/* number of SCO packets */
name|u_int16_t
name|sco_free
decl_stmt|;
comment|/* number of free SCO packets */
name|u_int16_t
name|acl_size
decl_stmt|;
comment|/* max. size of ACL packet */
name|u_int16_t
name|acl_pkts
decl_stmt|;
comment|/* number of ACL packets */
name|u_int16_t
name|acl_free
decl_stmt|;
comment|/* number of free ACL packets */
block|}
name|ng_hci_node_buffer_ep
typedef|;
end_typedef

begin_comment
comment|/* Get BDADDR */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_BDADDR
value|105
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_comment
comment|/* bdaddr_t -- BDADDR */
end_comment

begin_comment
comment|/* Get features */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_FEATURES
value|106
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_comment
comment|/* features[NG_HCI_FEATURES_SIZE] -- features */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_STAT
value|107
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|cmd_sent
decl_stmt|;
comment|/* number of HCI commands sent */
name|u_int32_t
name|evnt_recv
decl_stmt|;
comment|/* number of HCI events received */
name|u_int32_t
name|acl_recv
decl_stmt|;
comment|/* number of ACL packets received */
name|u_int32_t
name|acl_sent
decl_stmt|;
comment|/* number of ACL packets sent */
name|u_int32_t
name|sco_recv
decl_stmt|;
comment|/* number of SCO packets received */
name|u_int32_t
name|sco_sent
decl_stmt|;
comment|/* number of SCO packets sent */
name|u_int32_t
name|bytes_recv
decl_stmt|;
comment|/* total number of bytes received */
name|u_int32_t
name|bytes_sent
decl_stmt|;
comment|/* total number of bytes sent */
block|}
name|ng_hci_node_stat_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_NODE_RESET_STAT
value|108
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_comment
comment|/* No parameters */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_FLUSH_NEIGHBOR_CACHE
value|109
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_NEIGHBOR_CACHE
value|110
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|num_entries
decl_stmt|;
comment|/* number of entries */
block|}
name|ng_hci_node_get_neighbor_cache_ep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* page rep scan mode */
name|u_int16_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* clock offset */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* bdaddr */
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
comment|/* features */
name|uint8_t
name|addrtype
decl_stmt|;
name|uint8_t
name|extinq_size
decl_stmt|;
comment|/* MAX 240*/
name|uint8_t
name|extinq_data
index|[
name|NG_HCI_EXTINQ_MAX
index|]
decl_stmt|;
block|}
name|ng_hci_node_neighbor_cache_entry_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_MAX_NEIGHBOR_NUM
define|\
value|((0xffff - sizeof(ng_hci_node_get_neighbor_cache_ep))/sizeof(ng_hci_node_neighbor_cache_entry_ep))
end_define

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_CON_LIST
value|111
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|num_connections
decl_stmt|;
comment|/* number of connections */
block|}
name|ng_hci_node_con_list_ep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* ACL or SCO */
name|u_int8_t
name|encryption_mode
decl_stmt|;
comment|/* none, p2p, ... */
name|u_int8_t
name|mode
decl_stmt|;
comment|/* ACTIVE, HOLD ... */
name|u_int8_t
name|role
decl_stmt|;
comment|/* MASTER/SLAVE */
name|u_int16_t
name|state
decl_stmt|;
comment|/* connection state */
name|u_int16_t
name|reserved
decl_stmt|;
comment|/* place holder */
name|u_int16_t
name|pending
decl_stmt|;
comment|/* number of pending packets */
name|u_int16_t
name|queue_len
decl_stmt|;
comment|/* number of packets in queue */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote bdaddr */
block|}
name|ng_hci_node_con_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_MAX_CON_NUM
define|\
value|((0xffff - sizeof(ng_hci_node_con_list_ep))/sizeof(ng_hci_node_con_ep))
end_define

begin_define
define|#
directive|define
name|NGM_HCI_NODE_UP
value|112
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|pkt_size
decl_stmt|;
comment|/* max. ACL/SCO packet size (w/out header) */
name|u_int16_t
name|num_pkts
decl_stmt|;
comment|/* ACL/SCO packet queue size */
name|u_int16_t
name|reserved
decl_stmt|;
comment|/* place holder */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* bdaddr */
block|}
name|ng_hci_node_up_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_SYNC_CON_QUEUE
value|113
end_define

begin_comment
comment|/* HCI -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|completed
decl_stmt|;
comment|/* number of completed packets */
block|}
name|ng_hci_sync_con_queue_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_LINK_POLICY_SETTINGS_MASK
value|114
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_SET_LINK_POLICY_SETTINGS_MASK
value|115
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_hci_node_link_policy_mask_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_PACKET_MASK
value|116
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_SET_PACKET_MASK
value|117
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_hci_node_packet_mask_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_NODE_GET_ROLE_SWITCH
value|118
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_HCI_NODE_SET_ROLE_SWITCH
value|119
end_define

begin_comment
comment|/* User -> HCI */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_hci_node_role_switch_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_HCI_NODE_LIST_NAMES
value|200
end_define

begin_comment
comment|/* HCI -> User */
end_comment

begin_comment
comment|/**************************************************************************  **************************************************************************  **             Link control commands and return parameters  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_LINK_CONTROL
value|0x01
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_INQUIRY
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|lap
index|[
name|NG_HCI_LAP_SIZE
index|]
decl_stmt|;
comment|/* LAP */
name|u_int8_t
name|inquiry_length
decl_stmt|;
comment|/* (N x 1.28) sec */
name|u_int8_t
name|num_responses
decl_stmt|;
comment|/* Max. # of responses before halted */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_inquiry_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_INQUIRY_CANCEL
value|0x0002
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_inquiry_cancel_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_PERIODIC_INQUIRY
value|0x0003
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|max_period_length
decl_stmt|;
comment|/* Max. and min. amount of time */
name|u_int16_t
name|min_period_length
decl_stmt|;
comment|/* between consecutive inquiries */
name|u_int8_t
name|lap
index|[
name|NG_HCI_LAP_SIZE
index|]
decl_stmt|;
comment|/* LAP */
name|u_int8_t
name|inquiry_length
decl_stmt|;
comment|/* (inquiry_length * 1.28) sec */
name|u_int8_t
name|num_responses
decl_stmt|;
comment|/* Max. # of responses */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_periodic_inquiry_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_periodic_inquiry_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_EXIT_PERIODIC_INQUIRY
value|0x0004
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_exit_periodic_inquiry_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_CREATE_CON
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* destination address */
name|u_int16_t
name|pkt_type
decl_stmt|;
comment|/* packet type */
name|u_int8_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* page scan repetition mode */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* clock offset */
name|u_int8_t
name|accept_role_switch
decl_stmt|;
comment|/* accept role switch? 0x00 - no */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_create_con_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_DISCON
value|0x0006
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|reason
decl_stmt|;
comment|/* reason to disconnect */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_discon_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_ADD_SCO_CON
value|0x0007
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|pkt_type
decl_stmt|;
comment|/* packet type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_add_sco_con_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_ACCEPT_CON
value|0x0009
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* address of unit to be connected */
name|u_int8_t
name|role
decl_stmt|;
comment|/* connection role */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_accept_con_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_REJECT_CON
value|0x000a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int8_t
name|reason
decl_stmt|;
comment|/* reason to reject */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_reject_con_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_LINK_KEY_REP
value|0x000b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int8_t
name|key
index|[
name|NG_HCI_KEY_SIZE
index|]
decl_stmt|;
comment|/* key */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_rep_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_rep_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LINK_KEY_NEG_REP
value|0x000c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_neg_rep_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_neg_rep_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_PIN_CODE_REP
value|0x000d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int8_t
name|pin_size
decl_stmt|;
comment|/* pin code length (in bytes) */
name|u_int8_t
name|pin
index|[
name|NG_HCI_PIN_SIZE
index|]
decl_stmt|;
comment|/* pin code */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_pin_code_rep_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_pin_code_rep_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_PIN_CODE_NEG_REP
value|0x000e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_pin_code_neg_rep_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_pin_code_neg_rep_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_CHANGE_CON_PKT_TYPE
value|0x000f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|pkt_type
decl_stmt|;
comment|/* packet type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_change_con_pkt_type_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_AUTH_REQ
value|0x0011
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_auth_req_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_SET_CON_ENCRYPTION
value|0x0013
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|encryption_enable
decl_stmt|;
comment|/* 0x00 - disable, 0x01 - enable */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_set_con_encryption_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_CHANGE_CON_LINK_KEY
value|0x0015
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_change_con_link_key_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_MASTER_LINK_KEY
value|0x0017
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|key_flag
decl_stmt|;
comment|/* key flag */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_master_link_key_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_REMOTE_NAME_REQ
value|0x0019
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int8_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* page scan repetition mode */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* clock offset */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_remote_name_req_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_REMOTE_FEATURES
value|0x001b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_remote_features_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_REMOTE_VER_INFO
value|0x001d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_remote_ver_info_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_CLOCK_OFFSET
value|0x001f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_clock_offset_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_comment
comment|/**************************************************************************  **************************************************************************  **        Link policy commands and return parameters  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_LINK_POLICY
value|0x02
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_HOLD_MODE
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|max_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
name|u_int16_t
name|min_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_hold_mode_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_SNIFF_MODE
value|0x0003
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|max_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
name|u_int16_t
name|min_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
name|u_int16_t
name|attempt
decl_stmt|;
comment|/* (2 * attempt - 1) * 0.625 msec */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* (2 * attempt - 1) * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_sniff_mode_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_EXIT_SNIFF_MODE
value|0x0004
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_exit_sniff_mode_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_PARK_MODE
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|max_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
name|u_int16_t
name|min_interval
decl_stmt|;
comment|/* (max_interval * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_park_mode_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_EXIT_PARK_MODE
value|0x0006
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_exit_park_mode_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_QOS_SETUP
value|0x0007
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* reserved for future use */
name|u_int8_t
name|service_type
decl_stmt|;
comment|/* service type */
name|u_int32_t
name|token_rate
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|peak_bandwidth
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|latency
decl_stmt|;
comment|/* microseconds */
name|u_int32_t
name|delay_variation
decl_stmt|;
comment|/* microseconds */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_qos_setup_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_ROLE_DISCOVERY
value|0x0009
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_role_discovery_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|role
decl_stmt|;
comment|/* role for the connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_role_discovery_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_SWITCH_ROLE
value|0x000b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int8_t
name|role
decl_stmt|;
comment|/* new local role */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_switch_role_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LINK_POLICY_SETTINGS
value|0x000c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_link_policy_settings_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|settings
decl_stmt|;
comment|/* link policy settings */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_link_policy_settings_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_LINK_POLICY_SETTINGS
value|0x000d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|settings
decl_stmt|;
comment|/* link policy settings */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_link_policy_settings_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_link_policy_settings_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **   Host controller and baseband commands and return parameters   **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_HC_BASEBAND
value|0x03
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_SET_EVENT_MASK
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|event_mask
index|[
name|NG_HCI_EVENT_MASK_SIZE
index|]
decl_stmt|;
comment|/* event_mask */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_set_event_mask_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_set_event_mask_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MASK_DEFAULT
value|0x1fffffffffff
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MASK_LE
value|0x2000000000000000
end_define

begin_define
define|#
directive|define
name|NG_HCI_OCF_RESET
value|0x0003
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_reset_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_SET_EVENT_FILTER
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|filter_type
decl_stmt|;
comment|/* filter type */
name|u_int8_t
name|filter_condition_type
decl_stmt|;
comment|/* filter condition type */
name|u_int8_t
name|condition
index|[
literal|0
index|]
decl_stmt|;
comment|/* conditions - variable size */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_set_event_filter_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_set_event_filter_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_FLUSH
value|0x0008
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_flush_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_flush_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_PIN_TYPE
value|0x0009
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|pin_type
decl_stmt|;
comment|/* PIN type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_pin_type_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_PIN_TYPE
value|0x000a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|pin_type
decl_stmt|;
comment|/* PIN type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_pin_type_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_pin_type_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_CREATE_NEW_UNIT_KEY
value|0x000b
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_create_new_unit_key_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_STORED_LINK_KEY
value|0x000d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* address */
name|u_int8_t
name|read_all
decl_stmt|;
comment|/* read all keys? 0x01 - yes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_stored_link_key_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|max_num_keys
decl_stmt|;
comment|/* Max. number of keys */
name|u_int16_t
name|num_keys_read
decl_stmt|;
comment|/* Number of stored keys */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_stored_link_key_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_STORED_LINK_KEY
value|0x0011
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_keys_write
decl_stmt|;
comment|/* # of keys to write */
comment|/* these are repeated "num_keys_write" times  	bdaddr_t	bdaddr;                --- remote address(es) 	u_int8_t	key[NG_HCI_KEY_SIZE];  --- key(s) */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_stored_link_key_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|num_keys_written
decl_stmt|;
comment|/* # of keys successfully written */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_stored_link_key_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_DELETE_STORED_LINK_KEY
value|0x0012
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* address */
name|u_int8_t
name|delete_all
decl_stmt|;
comment|/* delete all keys? 0x01 - yes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_delete_stored_link_key_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|num_keys_deleted
decl_stmt|;
comment|/* Number of keys deleted */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_delete_stored_link_key_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_CHANGE_LOCAL_NAME
value|0x0013
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
name|NG_HCI_UNIT_NAME_SIZE
index|]
decl_stmt|;
comment|/* new unit name */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_change_local_name_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_change_local_name_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LOCAL_NAME
value|0x0014
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|char
name|name
index|[
name|NG_HCI_UNIT_NAME_SIZE
index|]
decl_stmt|;
comment|/* unit name */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_local_name_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_CON_ACCEPT_TIMO
value|0x0015
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* (timeout * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_con_accept_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_CON_ACCEPT_TIMO
value|0x0016
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* (timeout * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_con_accept_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_con_accept_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_PAGE_TIMO
value|0x0017
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* (timeout * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_page_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_PAGE_TIMO
value|0x0018
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* (timeout * 0.625) msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_page_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_page_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_SCAN_ENABLE
value|0x0019
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|scan_enable
decl_stmt|;
comment|/* Scan enable */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_scan_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_SCAN_ENABLE
value|0x001a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|scan_enable
decl_stmt|;
comment|/* Scan enable */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_scan_enable_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_scan_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_PAGE_SCAN_ACTIVITY
value|0x001b
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|page_scan_interval
decl_stmt|;
comment|/* interval * 0.625 msec */
name|u_int16_t
name|page_scan_window
decl_stmt|;
comment|/* window * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_page_scan_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_PAGE_SCAN_ACTIVITY
value|0x001c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|page_scan_interval
decl_stmt|;
comment|/* interval * 0.625 msec */
name|u_int16_t
name|page_scan_window
decl_stmt|;
comment|/* window * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_page_scan_activity_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_page_scan_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_INQUIRY_SCAN_ACTIVITY
value|0x001d
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|inquiry_scan_interval
decl_stmt|;
comment|/* interval * 0.625 msec */
name|u_int16_t
name|inquiry_scan_window
decl_stmt|;
comment|/* window * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_inquiry_scan_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_INQUIRY_SCAN_ACTIVITY
value|0x001e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|inquiry_scan_interval
decl_stmt|;
comment|/* interval * 0.625 msec */
name|u_int16_t
name|inquiry_scan_window
decl_stmt|;
comment|/* window * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_inquiry_scan_activity_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_inquiry_scan_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_AUTH_ENABLE
value|0x001f
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|auth_enable
decl_stmt|;
comment|/* 0x01 - enabled */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_auth_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_AUTH_ENABLE
value|0x0020
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|auth_enable
decl_stmt|;
comment|/* 0x01 - enabled */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_auth_enable_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_auth_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_ENCRYPTION_MODE
value|0x0021
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|encryption_mode
decl_stmt|;
comment|/* encryption mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_encryption_mode_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_ENCRYPTION_MODE
value|0x0022
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|encryption_mode
decl_stmt|;
comment|/* encryption mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_encryption_mode_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_encryption_mode_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_UNIT_CLASS
value|0x0023
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|uclass
index|[
name|NG_HCI_CLASS_SIZE
index|]
decl_stmt|;
comment|/* unit class */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_unit_class_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_UNIT_CLASS
value|0x0024
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|uclass
index|[
name|NG_HCI_CLASS_SIZE
index|]
decl_stmt|;
comment|/* unit class */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_unit_class_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_unit_class_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_VOICE_SETTINGS
value|0x0025
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|settings
decl_stmt|;
comment|/* voice settings */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_voice_settings_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_VOICE_SETTINGS
value|0x0026
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|settings
decl_stmt|;
comment|/* voice settings */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_voice_settings_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_voice_settings_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_AUTO_FLUSH_TIMO
value|0x0027
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_auto_flush_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 0x00 - no flush, timeout * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_auto_flush_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_AUTO_FLUSH_TIMO
value|0x0028
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 0x00 - no flush, timeout * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_auto_flush_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_auto_flush_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_NUM_BROADCAST_RETRANS
value|0x0029
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|counter
decl_stmt|;
comment|/* number of broadcast retransmissions */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_num_broadcast_retrans_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_NUM_BROADCAST_RETRANS
value|0x002a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|counter
decl_stmt|;
comment|/* number of broadcast retransmissions */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_num_broadcast_retrans_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_num_broadcast_retrans_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_HOLD_MODE_ACTIVITY
value|0x002b
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|hold_mode_activity
decl_stmt|;
comment|/* Hold mode activities */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_hold_mode_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_HOLD_MODE_ACTIVITY
value|0x002c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|hold_mode_activity
decl_stmt|;
comment|/* Hold mode activities */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_hold_mode_activity_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_hold_mode_activity_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_XMIT_LEVEL
value|0x002d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|type
decl_stmt|;
comment|/* Xmit level type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_xmit_level_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|char
name|level
decl_stmt|;
comment|/* -30<= level<= 30 dBm */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_xmit_level_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_SCO_FLOW_CONTROL
value|0x002e
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|flow_control
decl_stmt|;
comment|/* 0x00 - disabled */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_sco_flow_control_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_SCO_FLOW_CONTROL
value|0x002f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|flow_control
decl_stmt|;
comment|/* 0x00 - disabled */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_sco_flow_control_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_sco_flow_control_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_H2HC_FLOW_CONTROL
value|0x0031
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|h2hc_flow
decl_stmt|;
comment|/* Host to Host controller flow control */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_h2hc_flow_control_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_h2hc_flow_control_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_HOST_BUFFER_SIZE
value|0x0033
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|max_acl_size
decl_stmt|;
comment|/* Max. size of ACL packet (bytes) */
name|u_int8_t
name|max_sco_size
decl_stmt|;
comment|/* Max. size of SCO packet (bytes) */
name|u_int16_t
name|num_acl_pkt
decl_stmt|;
comment|/* Max. number of ACL packets */
name|u_int16_t
name|num_sco_pkt
decl_stmt|;
comment|/* Max. number of SCO packets */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_host_buffer_size_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_host_buffer_size_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_HOST_NUM_COMPL_PKTS
value|0x0035
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_con_handles
decl_stmt|;
comment|/* # of connection handles */
comment|/* these are repeated "num_con_handles" times 	u_int16_t	con_handle; --- connection handle(s) 	u_int16_t	compl_pkt;  --- # of completed packets */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_host_num_compl_pkts_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameter(s) */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LINK_SUPERVISION_TIMO
value|0x0036
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_link_supervision_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* Link supervision timeout * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_link_supervision_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_LINK_SUPERVISION_TIMO
value|0x0037
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* Link supervision timeout * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_link_supervision_timo_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_link_supervision_timo_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_SUPPORTED_IAC_NUM
value|0x0038
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|num_iac
decl_stmt|;
comment|/* # of supported IAC during scan */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_supported_iac_num_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_IAC_LAP
value|0x0039
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|num_iac
decl_stmt|;
comment|/* # of IAC */
comment|/* these are repeated "num_iac" times  	u_int8_t	laps[NG_HCI_LAP_SIZE]; --- LAPs */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_iac_lap_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_IAC_LAP
value|0x003a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_iac
decl_stmt|;
comment|/* # of IAC */
comment|/* these are repeated "num_iac" times  	u_int8_t	laps[NG_HCI_LAP_SIZE]; --- LAPs */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_iac_lap_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_iac_lap_rp
typedef|;
end_typedef

begin_comment
comment|/*0x003b-0x003e commands are depricated v2.0 or later*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_PAGE_SCAN_PERIOD
value|0x003b
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|page_scan_period_mode
decl_stmt|;
comment|/* Page scan period mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_page_scan_period_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_PAGE_SCAN_PERIOD
value|0x003c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|page_scan_period_mode
decl_stmt|;
comment|/* Page scan period mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_page_scan_period_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_page_scan_period_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_PAGE_SCAN
value|0x003d
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* Page scan mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_page_scan_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_PAGE_SCAN
value|0x003e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* Page scan mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_page_scan_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_page_scan_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LE_HOST_SUPPORTED
value|0x6c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|le_supported_host
decl_stmt|;
comment|/* LE host supported?*/
name|u_int8_t
name|simultaneous_le_host
decl_stmt|;
comment|/* BR/LE simulateneous? */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_le_host_supported_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_LE_HOST_SUPPORTED
value|0x6d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|le_supported_host
decl_stmt|;
comment|/* LE host supported?*/
name|u_int8_t
name|simultaneous_le_host
decl_stmt|;
comment|/* LE host supported?*/
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_le_host_supported_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_le_host_supported_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **           Informational commands and return parameters   **     All commands in this category do not accept any parameters  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_INFO
value|0x04
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LOCAL_VER
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|hci_version
decl_stmt|;
comment|/* HCI version */
name|u_int16_t
name|hci_revision
decl_stmt|;
comment|/* HCI revision */
name|u_int8_t
name|lmp_version
decl_stmt|;
comment|/* LMP version */
name|u_int16_t
name|manufacturer
decl_stmt|;
comment|/* Hardware manufacturer name */
name|u_int16_t
name|lmp_subversion
decl_stmt|;
comment|/* LMP sub-version */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_local_ver_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LOCAL_COMMANDS
value|0x0002
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|features
index|[
name|NG_HCI_COMMANDS_SIZE
index|]
decl_stmt|;
comment|/* command bitmsk*/
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_local_commands_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LOCAL_FEATURES
value|0x0003
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
comment|/* LMP features bitmsk*/
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_local_features_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_BUFFER_SIZE
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|max_acl_size
decl_stmt|;
comment|/* Max. size of ACL packet (bytes) */
name|u_int8_t
name|max_sco_size
decl_stmt|;
comment|/* Max. size of SCO packet (bytes) */
name|u_int16_t
name|num_acl_pkt
decl_stmt|;
comment|/* Max. number of ACL packets */
name|u_int16_t
name|num_sco_pkt
decl_stmt|;
comment|/* Max. number of SCO packets */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_buffer_size_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_COUNTRY_CODE
value|0x0007
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|country_code
decl_stmt|;
comment|/* 0x00 - NAM, EUR, JP; 0x01 - France */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_country_code_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_BDADDR
value|0x0009
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_bdaddr_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **            Status commands and return parameters   **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_STATUS
value|0x05
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_FAILED_CONTACT_CNTR
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_failed_contact_cntr_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|counter
decl_stmt|;
comment|/* number of consecutive failed contacts */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_failed_contact_cntr_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_RESET_FAILED_CONTACT_CNTR
value|0x0002
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_reset_failed_contact_cntr_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_reset_failed_contact_cntr_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_GET_LINK_QUALITY
value|0x0003
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_get_link_quality_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|quality
decl_stmt|;
comment|/* higher value means better quality */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_get_link_quality_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_RSSI
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_rssi_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|char
name|rssi
decl_stmt|;
comment|/* -127<= rssi<= 127 dB */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_rssi_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **             Testing commands and return parameters   **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_TESTING
value|0x06
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_READ_LOOPBACK_MODE
value|0x0001
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int8_t
name|lbmode
decl_stmt|;
comment|/* loopback mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_loopback_mode_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_WRITE_LOOPBACK_MODE
value|0x0002
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|lbmode
decl_stmt|;
comment|/* loopback mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_write_loopback_mode_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_write_loopback_mode_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_ENABLE_UNIT_UNDER_TEST
value|0x0003
end_define

begin_comment
comment|/* No command parameter(s) */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_enable_unit_under_test_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **                LE OpCode group field  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_LE
value|0x08
end_define

begin_comment
comment|/* OpCode Group Field */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_EVENT_MASK
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|event_mask
index|[
name|NG_HCI_LE_EVENT_MASK_SIZE
index|]
decl_stmt|;
comment|/* event_mask*/
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_event_mask_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_event_mask_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_LE_EVENT_MASK_ALL
value|0x1f
end_define

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_BUFFER_SIZE
value|0x0002
end_define

begin_comment
comment|/*No command parameter */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/*status*/
name|u_int16_t
name|hc_le_data_packet_length
decl_stmt|;
name|u_int8_t
name|hc_total_num_le_data_packets
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_buffer_size_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_LOCAL_SUPPORTED_FEATURES
value|0x0003
end_define

begin_comment
comment|/*No command parameter */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/*status*/
name|u_int64_t
name|le_features
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_local_supported_features_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_RANDOM_ADDRESS
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|random_address
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_random_address_cp_
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_random_address_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_ADVERTISING_PARAMETERS
value|0x0006
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|advertising_interval_min
decl_stmt|;
name|u_int16_t
name|advertising_interval_max
decl_stmt|;
name|u_int8_t
name|advertising_type
decl_stmt|;
name|u_int8_t
name|own_address_type
decl_stmt|;
name|u_int8_t
name|direct_address_type
decl_stmt|;
name|bdaddr_t
name|direct_address
decl_stmt|;
name|u_int8_t
name|advertising_channel_map
decl_stmt|;
name|u_int8_t
name|advertising_filter_policy
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_advertising_parameters_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_advertising_parameters_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_ADVERTISING_CHANNEL_TX_POWER
value|0x0007
end_define

begin_comment
comment|/*No command parameter*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|transmit_power_level
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_advertising_channel_tx_power_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_ADVERTISING_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|NG_HCI_ADVERTISING_DATA_SIZE
value|31
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|advertising_data_length
decl_stmt|;
name|char
name|advertising_data
index|[
name|NG_HCI_ADVERTISING_DATA_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_advertising_data_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_advertising_data_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_SCAN_RESPONSE_DATA
value|0x0009
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|scan_response_data_length
decl_stmt|;
name|char
name|scan_response_data
index|[
name|NG_HCI_ADVERTISING_DATA_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_scan_response_data_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_scan_response_data_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_ADVERTISE_ENABLE
value|0x000a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|advertising_enable
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_advertise_enable_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_advertise_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_SCAN_PARAMETERS
value|0x000b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|le_scan_type
decl_stmt|;
name|u_int16_t
name|le_scan_interval
decl_stmt|;
name|u_int16_t
name|le_scan_window
decl_stmt|;
name|u_int8_t
name|own_address_type
decl_stmt|;
name|u_int8_t
name|scanning_filter_policy
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_scan_parameters_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_scan_parameters_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_SCAN_ENABLE
value|0x000c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|le_scan_enable
decl_stmt|;
name|u_int8_t
name|filter_duplicates
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_scan_enable_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_scan_enable_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_CREATE_CONNECTION
value|0x000d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|scan_interval
decl_stmt|;
name|u_int16_t
name|scan_window
decl_stmt|;
name|u_int8_t
name|filter_policy
decl_stmt|;
name|u_int8_t
name|peer_addr_type
decl_stmt|;
name|bdaddr_t
name|peer_addr
decl_stmt|;
name|u_int8_t
name|own_address_type
decl_stmt|;
name|u_int16_t
name|conn_interval_min
decl_stmt|;
name|u_int16_t
name|conn_interval_max
decl_stmt|;
name|u_int16_t
name|conn_latency
decl_stmt|;
name|u_int16_t
name|supervision_timeout
decl_stmt|;
name|u_int16_t
name|min_ce_length
decl_stmt|;
name|u_int16_t
name|max_ce_length
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_create_connection_cp
typedef|;
end_typedef

begin_comment
comment|/* No return parameters. */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_CREATE_CONNECTION_CANCEL
value|0x000e
end_define

begin_comment
comment|/*No command parameter*/
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_create_connection_cancel_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_WHITE_LIST_SIZE
value|0x000f
end_define

begin_comment
comment|/*No command parameter*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|white_list_size
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_white_list_size_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_CLEAR_WHITE_LIST
value|0x0010
end_define

begin_comment
comment|/* No command parameters. */
end_comment

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_clear_white_list_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_ADD_DEVICE_TO_WHITE_LIST
value|0x0011
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|address_type
decl_stmt|;
name|bdaddr_t
name|address
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_add_device_to_white_list_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_add_device_to_white_list_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_REMOVE_DEVICE_FROM_WHITE_LIST
value|0x0012
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|address_type
decl_stmt|;
name|bdaddr_t
name|address
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_remove_device_from_white_list_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_remove_device_from_white_list_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_CONNECTION_UPDATE
value|0x0013
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
name|u_int16_t
name|conn_interval_min
decl_stmt|;
name|u_int16_t
name|conn_interval_max
decl_stmt|;
name|u_int16_t
name|conn_latency
decl_stmt|;
name|u_int16_t
name|supervision_timeout
decl_stmt|;
name|u_int16_t
name|minimum_ce_length
decl_stmt|;
name|u_int16_t
name|maximum_ce_length
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_connection_update_cp
typedef|;
end_typedef

begin_comment
comment|/*no return parameter*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_SET_HOST_CHANNEL_CLASSIFICATION
value|0x0014
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|le_channel_map
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_set_host_channel_classification_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_set_host_channel_classification_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_CHANNEL_MAP
value|0x0015
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_channel_map_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|connection_handle
decl_stmt|;
name|u_int8_t
name|le_channel_map
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_channel_map_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_REMOTE_USED_FEATURES
value|0x0016
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_remote_used_features_cp
typedef|;
end_typedef

begin_comment
comment|/*No return parameter*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_128BIT
value|16
end_define

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_ENCRYPT
value|0x0017
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|key
index|[
name|NG_HCI_128BIT
index|]
decl_stmt|;
name|u_int8_t
name|plaintext_data
index|[
name|NG_HCI_128BIT
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_encrypt_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|plaintext_data
index|[
name|NG_HCI_128BIT
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_encrypt_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_RAND
value|0x0018
end_define

begin_comment
comment|/*No command parameter*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int64_t
name|random_number
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_rand_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_START_ENCRYPTION
value|0x0019
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
name|u_int64_t
name|random_number
decl_stmt|;
name|u_int16_t
name|encrypted_diversifier
decl_stmt|;
name|u_int8_t
name|long_term_key
index|[
name|NG_HCI_128BIT
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_start_encryption_cp
typedef|;
end_typedef

begin_comment
comment|/*No return parameter*/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_LONG_TERM_KEY_REQUEST_REPLY
value|0x001a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
name|u_int8_t
name|long_term_key
index|[
name|NG_HCI_128BIT
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_long_term_key_request_reply_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|connection_handle
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_long_term_key_request_reply_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_LONG_TERM_KEY_REQUEST_NEGATIVE_REPLY
value|0x001b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|connection_handle
decl_stmt|;
block|}
name|ng_hci_le_long_term_key_request_negative_reply_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|connection_handle
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_long_term_key_request_negative_reply_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_READ_SUPPORTED_STATUS
value|0x001c
end_define

begin_comment
comment|/*No command parameter*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int64_t
name|le_status
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_read_supported_status_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_RECEIVER_TEST
value|0x001d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|rx_frequency
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_le_receiver_test_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_receiver_test_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_TRANSMITTER_TEST
value|0x001e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|tx_frequency
decl_stmt|;
name|u_int8_t
name|length_of_test_data
decl_stmt|;
name|u_int8_t
name|packet_payload
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_le_transmitter_test_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_status_rp
name|ng_hci_le_transmitter_test_rp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_OCF_LE_TEST_END
value|0x001f
end_define

begin_comment
comment|/* No command parameter. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|number_of_packets
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_test_end_rp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **                Special HCI OpCode group field values  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_OGF_BT_LOGO
value|0x3e
end_define

begin_define
define|#
directive|define
name|NG_HCI_OGF_VENDOR
value|0x3f
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **                         Events and event parameters  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EVENT_INQUIRY_COMPL
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_inquiry_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_INQUIRY_RESULT
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_responses
decl_stmt|;
comment|/* number of responses */
comment|/*	ng_hci_inquiry_response[num_responses]   -- see below */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_inquiry_result_ep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
name|u_int8_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* page scan rep. mode */
name|u_int8_t
name|page_scan_period_mode
decl_stmt|;
comment|/* page scan period mode */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
name|u_int8_t
name|uclass
index|[
name|NG_HCI_CLASS_SIZE
index|]
decl_stmt|;
comment|/* unit class */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* clock offset */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_inquiry_response
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_CON_COMPL
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* Link type */
name|u_int8_t
name|encryption_mode
decl_stmt|;
comment|/* Encryption mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_con_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_CON_REQ
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int8_t
name|uclass
index|[
name|NG_HCI_CLASS_SIZE
index|]
decl_stmt|;
comment|/* remote unit class */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* link type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_con_req_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_DISCON_COMPL
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|reason
decl_stmt|;
comment|/* reason to disconnect */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_discon_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_AUTH_COMPL
value|0x06
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_auth_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_REMOTE_NAME_REQ_COMPL
value|0x7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|char
name|name
index|[
name|NG_HCI_UNIT_NAME_SIZE
index|]
decl_stmt|;
comment|/* remote unit name */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_remote_name_req_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_ENCRYPTION_CHANGE
value|0x08
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|u_int8_t
name|encryption_enable
decl_stmt|;
comment|/* 0x00 - disable */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_encryption_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_CHANGE_CON_LINK_KEY_COMPL
value|0x09
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_change_con_link_key_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MASTER_LINK_KEY_COMPL
value|0x0a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|u_int8_t
name|key_flag
decl_stmt|;
comment|/* Key flag */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_master_link_key_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_READ_REMOTE_FEATURES_COMPL
value|0x0b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
comment|/* LMP features bitmsk*/
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_remote_features_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_READ_REMOTE_VER_INFO_COMPL
value|0x0c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|u_int8_t
name|lmp_version
decl_stmt|;
comment|/* LMP version */
name|u_int16_t
name|manufacturer
decl_stmt|;
comment|/* Hardware manufacturer name */
name|u_int16_t
name|lmp_subversion
decl_stmt|;
comment|/* LMP sub-version */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_remote_ver_info_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_QOS_SETUP_COMPL
value|0x0d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* reserved for future use */
name|u_int8_t
name|service_type
decl_stmt|;
comment|/* service type */
name|u_int32_t
name|token_rate
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|peak_bandwidth
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|latency
decl_stmt|;
comment|/* microseconds */
name|u_int32_t
name|delay_variation
decl_stmt|;
comment|/* microseconds */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_qos_setup_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_COMMAND_COMPL
value|0x0e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_cmd_pkts
decl_stmt|;
comment|/* # of HCI command packets */
name|u_int16_t
name|opcode
decl_stmt|;
comment|/* command OpCode */
comment|/* command return parameters (if any) */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_command_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_COMMAND_STATUS
value|0x0f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - pending */
name|u_int8_t
name|num_cmd_pkts
decl_stmt|;
comment|/* # of HCI command packets */
name|u_int16_t
name|opcode
decl_stmt|;
comment|/* command OpCode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_command_status_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_HARDWARE_ERROR
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|hardware_code
decl_stmt|;
comment|/* hardware error code */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_hardware_error_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_FLUSH_OCCUR
value|0x11
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_flush_occur_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_ROLE_CHANGE
value|0x12
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* address of remote unit */
name|u_int8_t
name|role
decl_stmt|;
comment|/* new connection role */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_role_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_NUM_COMPL_PKTS
value|0x13
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_con_handles
decl_stmt|;
comment|/* # of connection handles */
comment|/* these are repeated "num_con_handles" times  	u_int16_t	con_handle; --- connection handle(s) 	u_int16_t	compl_pkt;  --- # of completed packets */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_num_compl_pkts_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MODE_CHANGE
value|0x14
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|unit_mode
decl_stmt|;
comment|/* remote unit mode */
name|u_int16_t
name|interval
decl_stmt|;
comment|/* interval * 0.625 msec */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_mode_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_RETURN_LINK_KEYS
value|0x15
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_keys
decl_stmt|;
comment|/* # of keys */
comment|/* these are repeated "num_keys" times  	bdaddr_t	bdaddr;               --- remote address(es) 	u_int8_t	key[NG_HCI_KEY_SIZE]; --- key(s) */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_return_link_keys_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_PIN_CODE_REQ
value|0x16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_pin_code_req_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_LINK_KEY_REQ
value|0x17
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_req_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_LINK_KEY_NOTIFICATION
value|0x18
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int8_t
name|key
index|[
name|NG_HCI_KEY_SIZE
index|]
decl_stmt|;
comment|/* link key */
name|u_int8_t
name|key_type
decl_stmt|;
comment|/* type of the key */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_link_key_notification_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_LOOPBACK_COMMAND
value|0x19
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
index|[
literal|0
index|]
decl_stmt|;
comment|/* Command packet */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_loopback_command_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_DATA_BUFFER_OVERFLOW
value|0x1a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* Link type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_data_buffer_overflow_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_MAX_SLOT_CHANGE
value|0x1b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int8_t
name|lmp_max_slots
decl_stmt|;
comment|/* Max. # of slots allowed */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_max_slot_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_READ_CLOCK_OFFSET_COMPL
value|0x1c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* Connection handle */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* Clock offset */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_read_clock_offset_compl_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_CON_PKT_TYPE_CHANGED
value|0x1d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|pkt_type
decl_stmt|;
comment|/* packet type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_con_pkt_type_changed_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_QOS_VIOLATION
value|0x1e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_qos_violation_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_PAGE_SCAN_MODE_CHANGE
value|0x1f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* destination address */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_page_scan_mode_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_PAGE_SCAN_REP_MODE_CHANGE
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* destination address */
name|u_int8_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* page scan repetition mode */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_page_scan_rep_mode_change_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_EVENT_LE
value|0x3e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|subevent_code
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_LEEV_CON_COMPL
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|handle
decl_stmt|;
name|u_int8_t
name|role
decl_stmt|;
name|u_int8_t
name|address_type
decl_stmt|;
name|bdaddr_t
name|address
decl_stmt|;
name|u_int16_t
name|interval
decl_stmt|;
name|u_int8_t
name|latency
decl_stmt|;
name|u_int16_t
name|supervision_timeout
decl_stmt|;
name|u_int8_t
name|master_clock_accracy
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_connection_complete_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_LEEV_ADVREP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_reports
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_advertising_report_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_SCAN_RESPONSE_DATA_MAX
value|0x1f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|event_type
decl_stmt|;
name|u_int8_t
name|addr_type
decl_stmt|;
name|bdaddr_t
name|bdaddr
decl_stmt|;
name|u_int8_t
name|length_data
decl_stmt|;
name|u_int8_t
name|data
index|[
name|NG_HCI_SCAN_RESPONSE_DATA_MAX
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_le_advreport
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_LEEV_CON_UPDATE_COMPL
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|connection_handle
decl_stmt|;
name|u_int16_t
name|conn_interval
decl_stmt|;
name|u_int16_t
name|conn_latency
decl_stmt|;
name|u_int16_t
name|supervision_timeout
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_hci_connection_update_complete_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_HCI_LEEV_READ_REMOTE_FEATURES_COMPL
value|0x04
end_define

begin_comment
comment|//TBD
end_comment

begin_define
define|#
directive|define
name|NG_HCI_LEEV_LONG_TERM_KEY_REQUEST
value|0x05
end_define

begin_comment
comment|//TBD
end_comment

begin_define
define|#
directive|define
name|NG_HCI_EVENT_BT_LOGO
value|0xfe
end_define

begin_define
define|#
directive|define
name|NG_HCI_EVENT_VENDOR
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_HCI_H_ */
end_comment

end_unit

