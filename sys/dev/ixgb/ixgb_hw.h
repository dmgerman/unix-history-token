begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2004, Intel Corporation   All rights reserved.      Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGB_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGB_HW_H_
end_define

begin_include
include|#
directive|include
file|<dev/ixgb/if_ixgb_osdep.h>
end_include

begin_comment
comment|/* Enums */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_mac_unknown
init|=
literal|0
block|,
name|ixgb_82597
block|,
name|ixgb_num_macs
block|}
name|ixgb_mac_type
typedef|;
end_typedef

begin_comment
comment|/* Types of physical layer modules */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_phy_type_unknown
init|=
literal|0
block|,
name|ixgb_phy_type_g6005
block|,
comment|/* 850nm, MM fiber, XPAK transceiver */
name|ixgb_phy_type_g6104
block|,
comment|/* 1310nm, SM fiber, XPAK transceiver */
name|ixgb_phy_type_txn17201
block|,
comment|/* 850nm, MM fiber, XPAK transceiver */
name|ixgb_phy_type_txn17401
comment|/* 1310nm, SM fiber, XENPAK transceiver */
block|}
name|ixgb_phy_type
typedef|;
end_typedef

begin_comment
comment|/* XPAK transceiver vendors, for the SR adapters */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_xpak_vendor_intel
block|,
name|ixgb_xpak_vendor_infineon
block|}
name|ixgb_xpak_vendor
typedef|;
end_typedef

begin_comment
comment|/* Media Types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_media_type_unknown
init|=
literal|0
block|,
name|ixgb_media_type_fiber
init|=
literal|1
block|,
name|ixgb_num_media_types
block|}
name|ixgb_media_type
typedef|;
end_typedef

begin_comment
comment|/* Flow Control Settings */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_fc_none
init|=
literal|0
block|,
name|ixgb_fc_rx_pause
init|=
literal|1
block|,
name|ixgb_fc_tx_pause
init|=
literal|2
block|,
name|ixgb_fc_full
init|=
literal|3
block|,
name|ixgb_fc_default
init|=
literal|0xFF
block|}
name|ixgb_fc_type
typedef|;
end_typedef

begin_comment
comment|/* PCI bus types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_bus_type_unknown
init|=
literal|0
block|,
name|ixgb_bus_type_pci
block|,
name|ixgb_bus_type_pcix
block|}
name|ixgb_bus_type
typedef|;
end_typedef

begin_comment
comment|/* PCI bus speeds */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_bus_speed_unknown
init|=
literal|0
block|,
name|ixgb_bus_speed_33
block|,
name|ixgb_bus_speed_66
block|,
name|ixgb_bus_speed_100
block|,
name|ixgb_bus_speed_133
block|,
name|ixgb_bus_speed_reserved
block|}
name|ixgb_bus_speed
typedef|;
end_typedef

begin_comment
comment|/* PCI bus widths */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ixgb_bus_width_unknown
init|=
literal|0
block|,
name|ixgb_bus_width_32
block|,
name|ixgb_bus_width_64
block|}
name|ixgb_bus_width
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IXGB_ETH_LENGTH_OF_ADDRESS
value|6
end_define

begin_define
define|#
directive|define
name|IXGB_EEPROM_SIZE
value|64
end_define

begin_comment
comment|/* Size in words */
end_comment

begin_define
define|#
directive|define
name|SPEED_10000
value|10000
end_define

begin_define
define|#
directive|define
name|FULL_DUPLEX
value|2
end_define

begin_define
define|#
directive|define
name|MIN_NUMBER_OF_DESCRIPTORS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NUMBER_OF_DESCRIPTORS
value|0xFFF8
end_define

begin_comment
comment|/* 13 bits in RDLEN/TDLEN, 128B aligned     */
end_comment

begin_define
define|#
directive|define
name|IXGB_DELAY_BEFORE_RESET
value|10
end_define

begin_comment
comment|/* allow 10ms after idling rx/tx units      */
end_comment

begin_define
define|#
directive|define
name|IXGB_DELAY_AFTER_RESET
value|1
end_define

begin_comment
comment|/* allow 1ms after the reset                */
end_comment

begin_define
define|#
directive|define
name|IXGB_DELAY_AFTER_EE_RESET
value|10
end_define

begin_comment
comment|/* allow 10ms after the EEPROM reset        */
end_comment

begin_define
define|#
directive|define
name|IXGB_DELAY_USECS_AFTER_LINK_RESET
value|13
end_define

begin_comment
comment|/* allow 13 microseconds after the reset    */
end_comment

begin_comment
comment|/* NOTE: this is MICROSECONDS               */
end_comment

begin_define
define|#
directive|define
name|MAX_RESET_ITERATIONS
value|8
end_define

begin_comment
comment|/* number of iterations to get things right */
end_comment

begin_comment
comment|/* General Registers */
end_comment

begin_define
define|#
directive|define
name|IXGB_CTRL0
value|0x00000
end_define

begin_comment
comment|/* Device Control Register 0 - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_CTRL1
value|0x00008
end_define

begin_comment
comment|/* Device Control Register 1 - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_STATUS
value|0x00010
end_define

begin_comment
comment|/* Device Status Register - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_EECD
value|0x00018
end_define

begin_comment
comment|/* EEPROM/Flash Control/Data Register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_MFS
value|0x00020
end_define

begin_comment
comment|/* Maximum Frame Size - RW */
end_comment

begin_comment
comment|/* Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGB_ICR
value|0x00080
end_define

begin_comment
comment|/* Interrupt Cause Read - R/clr */
end_comment

begin_define
define|#
directive|define
name|IXGB_ICS
value|0x00088
end_define

begin_comment
comment|/* Interrupt Cause Set - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_IMS
value|0x00090
end_define

begin_comment
comment|/* Interrupt Mask Set/Read - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_IMC
value|0x00098
end_define

begin_comment
comment|/* Interrupt Mask Clear - WO */
end_comment

begin_comment
comment|/* Receive */
end_comment

begin_define
define|#
directive|define
name|IXGB_RCTL
value|0x00100
end_define

begin_comment
comment|/* RX Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_FCRTL
value|0x00108
end_define

begin_comment
comment|/* Flow Control Receive Threshold Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_FCRTH
value|0x00110
end_define

begin_comment
comment|/* Flow Control Receive Threshold High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDBAL
value|0x00118
end_define

begin_comment
comment|/* RX Descriptor Base Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDBAH
value|0x0011C
end_define

begin_comment
comment|/* RX Descriptor Base High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDLEN
value|0x00120
end_define

begin_comment
comment|/* RX Descriptor Length - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDH
value|0x00128
end_define

begin_comment
comment|/* RX Descriptor Head - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDT
value|0x00130
end_define

begin_comment
comment|/* RX Descriptor Tail - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RDTR
value|0x00138
end_define

begin_comment
comment|/* RX Delay Timer Ring - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RXDCTL
value|0x00140
end_define

begin_comment
comment|/* Receive Descriptor Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAIDC
value|0x00148
end_define

begin_comment
comment|/* Receive Adaptive Interrupt Delay Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RXCSUM
value|0x00158
end_define

begin_comment
comment|/* Receive Checksum Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RA
value|0x00180
end_define

begin_comment
comment|/* Receive Address Array Base - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAL
value|0x00180
end_define

begin_comment
comment|/* Receive Address Low [0:15] - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAH
value|0x00184
end_define

begin_comment
comment|/* Receive Address High [0:15] - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_MTA
value|0x00200
end_define

begin_comment
comment|/* Multicast Table Array [0:127] - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_VFTA
value|0x00400
end_define

begin_comment
comment|/* VLAN Filter Table Array [0:127] - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_REQ_RX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_comment
comment|/* Transmit */
end_comment

begin_define
define|#
directive|define
name|IXGB_TCTL
value|0x00600
end_define

begin_comment
comment|/* TX Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TDBAL
value|0x00608
end_define

begin_comment
comment|/* TX Descriptor Base Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TDBAH
value|0x0060C
end_define

begin_comment
comment|/* TX Descriptor Base High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TDLEN
value|0x00610
end_define

begin_comment
comment|/* TX Descriptor Length - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TDH
value|0x00618
end_define

begin_comment
comment|/* TX Descriptor Head - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TDT
value|0x00620
end_define

begin_comment
comment|/* TX Descriptor Tail - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TIDV
value|0x00628
end_define

begin_comment
comment|/* TX Interrupt Delay Value - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TXDCTL
value|0x00630
end_define

begin_comment
comment|/* Transmit Descriptor Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_TSPMT
value|0x00638
end_define

begin_comment
comment|/* TCP Segmentation PAD& Min Threshold - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_PAP
value|0x00640
end_define

begin_comment
comment|/* Pause and Pace - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_REQ_TX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_comment
comment|/* Physical */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSC1
value|0x00700
end_define

begin_comment
comment|/* PCS Control 1 - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSC2
value|0x00708
end_define

begin_comment
comment|/* PCS Control 2 - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSS1
value|0x00710
end_define

begin_comment
comment|/* PCS Status 1 - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSS2
value|0x00718
end_define

begin_comment
comment|/* PCS Status 2 - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_XPCSS
value|0x00720
end_define

begin_comment
comment|/* 10GBASE-X PCS Status (or XGXS Lane Status) - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_UCCR
value|0x00728
end_define

begin_comment
comment|/* Unilink Circuit Control Register */
end_comment

begin_define
define|#
directive|define
name|IXGB_XPCSTC
value|0x00730
end_define

begin_comment
comment|/* 10GBASE-X PCS Test Control */
end_comment

begin_define
define|#
directive|define
name|IXGB_MACA
value|0x00738
end_define

begin_comment
comment|/* MDI Autoscan Command and Address - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_APAE
value|0x00740
end_define

begin_comment
comment|/* Autoscan PHY Address Enable - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_ARD
value|0x00748
end_define

begin_comment
comment|/* Autoscan Read Data - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_AIS
value|0x00750
end_define

begin_comment
comment|/* Autoscan Interrupt Status - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA
value|0x00758
end_define

begin_comment
comment|/* MDI Single Command and Address - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSRWD
value|0x00760
end_define

begin_comment
comment|/* MDI Single Read and Write Data - RW, RO */
end_comment

begin_comment
comment|/* Wake-up */
end_comment

begin_define
define|#
directive|define
name|IXGB_WUFC
value|0x00808
end_define

begin_comment
comment|/* Wake Up Filter Control - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_WUS
value|0x00810
end_define

begin_comment
comment|/* Wake Up Status - RO */
end_comment

begin_define
define|#
directive|define
name|IXGB_FFLT
value|0x01000
end_define

begin_comment
comment|/* Flexible Filter Length Table - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_FFMT
value|0x01020
end_define

begin_comment
comment|/* Flexible Filter Mask Table - RW */
end_comment

begin_define
define|#
directive|define
name|IXGB_FTVT
value|0x01420
end_define

begin_comment
comment|/* Flexible Filter Value Table - RW */
end_comment

begin_comment
comment|/* Statistics */
end_comment

begin_define
define|#
directive|define
name|IXGB_TPRL
value|0x02000
end_define

begin_comment
comment|/* Total Packets Received (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TPRH
value|0x02004
end_define

begin_comment
comment|/* Total Packets Received (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GPRCL
value|0x02008
end_define

begin_comment
comment|/* Good Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GPRCH
value|0x0200C
end_define

begin_comment
comment|/* Good Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_BPRCL
value|0x02010
end_define

begin_comment
comment|/* Broadcast Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_BPRCH
value|0x02014
end_define

begin_comment
comment|/* Broadcast Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_MPRCL
value|0x02018
end_define

begin_comment
comment|/* Multicast Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_MPRCH
value|0x0201C
end_define

begin_comment
comment|/* Multicast Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_UPRCL
value|0x02020
end_define

begin_comment
comment|/* Unicast Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_UPRCH
value|0x02024
end_define

begin_comment
comment|/* Unicast Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_VPRCL
value|0x02028
end_define

begin_comment
comment|/* VLAN Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_VPRCH
value|0x0202C
end_define

begin_comment
comment|/* VLAN Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_JPRCL
value|0x02030
end_define

begin_comment
comment|/* Jumbo Packets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_JPRCH
value|0x02034
end_define

begin_comment
comment|/* Jumbo Packets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GORCL
value|0x02038
end_define

begin_comment
comment|/* Good Octets Received Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GORCH
value|0x0203C
end_define

begin_comment
comment|/* Good Octets Received Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TORL
value|0x02040
end_define

begin_comment
comment|/* Total Octets Received (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TORH
value|0x02044
end_define

begin_comment
comment|/* Total Octets Received (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_RNBC
value|0x02048
end_define

begin_comment
comment|/* Receive No Buffers Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_RUC
value|0x02050
end_define

begin_comment
comment|/* Receive Undersize Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_ROC
value|0x02058
end_define

begin_comment
comment|/* Receive Oversize Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_RLEC
value|0x02060
end_define

begin_comment
comment|/* Receive Length Error Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_CRCERRS
value|0x02068
end_define

begin_comment
comment|/* CRC Error Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_ICBC
value|0x02070
end_define

begin_comment
comment|/* Illegal control byte in mid-packet Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_ECBC
value|0x02078
end_define

begin_comment
comment|/* Error Control byte in mid-packet Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_MPC
value|0x02080
end_define

begin_comment
comment|/* Missed Packets Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_TPTL
value|0x02100
end_define

begin_comment
comment|/* Total Packets Transmitted (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TPTH
value|0x02104
end_define

begin_comment
comment|/* Total Packets Transmitted (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GPTCL
value|0x02108
end_define

begin_comment
comment|/* Good Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GPTCH
value|0x0210C
end_define

begin_comment
comment|/* Good Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_BPTCL
value|0x02110
end_define

begin_comment
comment|/* Broadcast Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_BPTCH
value|0x02114
end_define

begin_comment
comment|/* Broadcast Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_MPTCL
value|0x02118
end_define

begin_comment
comment|/* Multicast Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_MPTCH
value|0x0211C
end_define

begin_comment
comment|/* Multicast Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_UPTCL
value|0x02120
end_define

begin_comment
comment|/* Unicast Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_UPTCH
value|0x02124
end_define

begin_comment
comment|/* Unicast Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_VPTCL
value|0x02128
end_define

begin_comment
comment|/* VLAN Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_VPTCH
value|0x0212C
end_define

begin_comment
comment|/* VLAN Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_JPTCL
value|0x02130
end_define

begin_comment
comment|/* Jumbo Packets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_JPTCH
value|0x02134
end_define

begin_comment
comment|/* Jumbo Packets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GOTCL
value|0x02138
end_define

begin_comment
comment|/* Good Octets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_GOTCH
value|0x0213C
end_define

begin_comment
comment|/* Good Octets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TOTL
value|0x02140
end_define

begin_comment
comment|/* Total Octets Transmitted Count (Low) */
end_comment

begin_define
define|#
directive|define
name|IXGB_TOTH
value|0x02144
end_define

begin_comment
comment|/* Total Octets Transmitted Count (High) */
end_comment

begin_define
define|#
directive|define
name|IXGB_DC
value|0x02148
end_define

begin_comment
comment|/* Defer Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_PLT64C
value|0x02150
end_define

begin_comment
comment|/* Packet Transmitted was less than 64 bytes Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_TSCTC
value|0x02170
end_define

begin_comment
comment|/* TCP Segmentation Context Transmitted Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_TSCTFC
value|0x02178
end_define

begin_comment
comment|/* TCP Segmentation Context Tx Fail Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_IBIC
value|0x02180
end_define

begin_comment
comment|/* Illegal byte during Idle stream count */
end_comment

begin_define
define|#
directive|define
name|IXGB_RFC
value|0x02188
end_define

begin_comment
comment|/* Remote Fault Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_LFC
value|0x02190
end_define

begin_comment
comment|/* Local Fault Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_PFRC
value|0x02198
end_define

begin_comment
comment|/* Pause Frame Receive Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_PFTC
value|0x021A0
end_define

begin_comment
comment|/* Pause Frame Transmit Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_MCFRC
value|0x021A8
end_define

begin_comment
comment|/* MAC Control Frames (non-Pause) Received Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_MCFTC
value|0x021B0
end_define

begin_comment
comment|/* MAC Control Frames (non-Pause) Transmitted Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_XONRXC
value|0x021B8
end_define

begin_comment
comment|/* XON Received Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_XONTXC
value|0x021C0
end_define

begin_comment
comment|/* XON Transmitted Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_XOFFRXC
value|0x021C8
end_define

begin_comment
comment|/* XOFF Received Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_XOFFTXC
value|0x021D0
end_define

begin_comment
comment|/* XOFF Transmitted Count */
end_comment

begin_define
define|#
directive|define
name|IXGB_RJC
value|0x021D8
end_define

begin_comment
comment|/* Receive Jabber Count */
end_comment

begin_comment
comment|/* CTRL0 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_CTRL0_LRST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_JFE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_XLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_MDCS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_CMDC
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP0
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP1
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP2
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP3
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP0_DIR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP1_DIR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP2_DIR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_SDP3_DIR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_RST
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_RPE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_TPE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL0_VME
value|0x40000000
end_define

begin_comment
comment|/* CTRL1 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_CTRL1_GPI0_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_GPI1_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_GPI2_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_GPI3_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP4_DIR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP5_DIR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP6_DIR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_SDP7_DIR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_EE_RST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_RO_DIS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_PCIXHM_MASK
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_PCIXHM_1_2
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_PCIXHM_5_8
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_PCIXHM_3_4
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGB_CTRL1_PCIXHM_7_8
value|0x00C00000
end_define

begin_comment
comment|/* STATUS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_STATUS_LU
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_AIP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_TXOFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_XAUIME
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_RES
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_RIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_RIE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_RLF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_RRF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCI_SPD
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_BUS64
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCIX_MODE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCIX_SPD_MASK
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCIX_SPD_66
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCIX_SPD_100
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_PCIX_SPD_133
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_REV_ID_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|IXGB_STATUS_REV_ID_SHIFT
value|16
end_define

begin_comment
comment|/* EECD Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_EECD_SK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_CS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_DI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_DO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_FWE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_FWE_DIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_EECD_FWE_EN
value|0x00000020
end_define

begin_comment
comment|/* MFS */
end_comment

begin_define
define|#
directive|define
name|IXGB_MFS_SHIFT
value|16
end_define

begin_comment
comment|/* Interrupt Register Bit Masks (used for ICR, ICS, IMS, and IMC) */
end_comment

begin_define
define|#
directive|define
name|IXGB_INT_TXDW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGB_INT_TXQE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_INT_LSC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_INT_RXSEQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_INT_RXDMT0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_INT_RXO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGB_INT_RXT0
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGB_INT_AUTOSCAN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGB_INT_GPI0
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGB_INT_GPI1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGB_INT_GPI2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGB_INT_GPI3
value|0x00004000
end_define

begin_comment
comment|/* RCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_RCTL_RXEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_SBP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_UPE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MPE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RDMTS_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RDMTS_1_2
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RDMTS_1_4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RDMTS_1_8
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_47_36
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_46_35
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_45_34
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_43_32
value|0x00003000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MO_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BAM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BSIZE_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BSIZE_2048
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BSIZE_4096
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BSIZE_8192
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_BSIZE_16384
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_VFE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_CFIEN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_CFI
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RPDA_MASK
value|0x00600000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_RPDA_MC_MAC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_MC_ONLY
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_CFF
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_SECRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGB_RDT_FPDB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGB_RCTL_IDLE_RX_UNIT
value|0
end_define

begin_comment
comment|/* FCRTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_FCRTL_XONE
value|0x80000000
end_define

begin_comment
comment|/* RXDCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_RXDCTL_PTHRESH_MASK
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|IXGB_RXDCTL_PTHRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGB_RXDCTL_HTHRESH_MASK
value|0x0003FE00
end_define

begin_define
define|#
directive|define
name|IXGB_RXDCTL_HTHRESH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGB_RXDCTL_WTHRESH_MASK
value|0x07FC0000
end_define

begin_define
define|#
directive|define
name|IXGB_RXDCTL_WTHRESH_SHIFT
value|18
end_define

begin_comment
comment|/* RAIDC Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAIDC_HIGHTHRS_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_DELAY_MASK
value|0x000FF800
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_DELAY_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_MASK
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_RXT_GATE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_1000_INTERRUPTS_PER_SECOND
value|1220
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_5000_INTERRUPTS_PER_SECOND
value|244
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_10000_INTERRUPTS_PER_SECOND
value|122
end_define

begin_define
define|#
directive|define
name|IXGB_RAIDC_POLL_20000_INTERRUPTS_PER_SECOND
value|61
end_define

begin_comment
comment|/* RXCSUM Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_RXCSUM_IPOFL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGB_RXCSUM_TUOFL
value|0x00000200
end_define

begin_comment
comment|/* RAH Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAH_ASEL_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGB_RAH_ASEL_DEST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_RAH_ASEL_SRC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGB_RAH_AV
value|0x80000000
end_define

begin_comment
comment|/* TCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_TCTL_TCE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGB_TCTL_TXEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_TCTL_TPDE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_TCTL_IDLE_TX_UNIT
value|0
end_define

begin_comment
comment|/* TXDCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_TXDCTL_PTHRESH_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|IXGB_TXDCTL_HTHRESH_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|IXGB_TXDCTL_HTHRESH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGB_TXDCTL_WTHRESH_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IXGB_TXDCTL_WTHRESH_SHIFT
value|16
end_define

begin_comment
comment|/* TSPMT Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_TSPMT_TSMT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IXGB_TSPMT_TSPBP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGB_TSPMT_TSPBP_SHIFT
value|16
end_define

begin_comment
comment|/* PAP Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_PAP_TXPC_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_10G
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_1G
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_2G
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_3G
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_4G
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_5G
value|0x00050000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_6G
value|0x00060000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_7G
value|0x00070000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_8G
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_9G
value|0x00090000
end_define

begin_define
define|#
directive|define
name|IXGB_PAP_TXPV_WAN
value|0x000F0000
end_define

begin_comment
comment|/* PCSC1 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSC1_LOOPBACK
value|0x00004000
end_define

begin_comment
comment|/* PCSC2 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSC2_PCS_TYPE_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGB_PCSC2_PCS_TYPE_10GBX
value|0x00000001
end_define

begin_comment
comment|/* PCSS1 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSS1_LOCAL_FAULT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS1_RX_LINK_STATUS
value|0x00000004
end_define

begin_comment
comment|/* PCSS2 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_PCSS2_DEV_PRES_MASK
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_DEV_PRES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_TX_LF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_RX_LF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_10GBW
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_10GBX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_PCSS2_10GBR
value|0x00000001
end_define

begin_comment
comment|/* XPCSS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_XPCSS_ALIGN_STATUS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSS_PATTERN_TEST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSS_LANE_3_SYNC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSS_LANE_2_SYNC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSS_LANE_1_SYNC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSS_LANE_0_SYNC
value|0x00000001
end_define

begin_comment
comment|/* XPCSTC Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_TRIG
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_SST
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_PSZ_MASK
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_PSZ_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_PSZ_INF
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_PSZ_68
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGB_XPCSTC_BERT_PSZ_1028
value|0x00000000
end_define

begin_comment
comment|/* MSCA bit Masks */
end_comment

begin_comment
comment|/* New Protocol Address */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_NP_ADDR_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_NP_ADDR_SHIFT
value|0
end_define

begin_comment
comment|/* Either Device Type or Register Address,depending on ST_CODE */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_DEV_TYPE_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_DEV_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_PHY_ADDR_MASK
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_PHY_ADDR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_OP_CODE_MASK
value|0x0C000000
end_define

begin_comment
comment|/* OP_CODE == 00, Address cycle, New Protocol           */
end_comment

begin_comment
comment|/* OP_CODE == 01, Write operation                       */
end_comment

begin_comment
comment|/* OP_CODE == 10, Read operation                        */
end_comment

begin_comment
comment|/* OP_CODE == 11, Read, auto increment, New Protocol    */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_ADDR_CYCLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_WRITE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_READ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_READ_AUTOINC
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_OP_CODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_ST_CODE_MASK
value|0x30000000
end_define

begin_comment
comment|/* ST_CODE == 00, New Protocol  */
end_comment

begin_comment
comment|/* ST_CODE == 01, Old Protocol  */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_NEW_PROTOCOL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_OLD_PROTOCOL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGB_MSCA_ST_CODE_SHIFT
value|28
end_define

begin_comment
comment|/* Initiate command, self-clearing when command completes */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_MDI_COMMAND
value|0x40000000
end_define

begin_comment
comment|/*MDI In Progress Enable. */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSCA_MDI_IN_PROG_EN
value|0x80000000
end_define

begin_comment
comment|/* MSRWD bit masks */
end_comment

begin_define
define|#
directive|define
name|IXGB_MSRWD_WRITE_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IXGB_MSRWD_WRITE_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGB_MSRWD_READ_DATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGB_MSRWD_READ_DATA_SHIFT
value|16
end_define

begin_comment
comment|/* Definitions for the optics devices on the MDIO bus. */
end_comment

begin_define
define|#
directive|define
name|IXGB_PHY_ADDRESS
value|0x0
end_define

begin_comment
comment|/* Single PHY, multiple "Devices" */
end_comment

begin_comment
comment|/* Standard five-bit Device IDs.  See IEEE 802.3ae, clause 45 */
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_PMD_DID
value|0x01
end_define

begin_define
define|#
directive|define
name|MDIO_WIS_DID
value|0x02
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_DID
value|0x03
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_DID
value|0x04
end_define

begin_comment
comment|/* Standard PMA/PMD registers and bit definitions. */
end_comment

begin_comment
comment|/* Note: This is a very limited set of definitions,      */
end_comment

begin_comment
comment|/* only implemented features are defined.                */
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_PMD_CR1
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_PMD_CR1_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_PMD_XPAK_VENDOR_NAME
value|0x803A
end_define

begin_comment
comment|/* XPAK/XENPAK devices only */
end_comment

begin_comment
comment|/* Vendor-specific MDIO registers */
end_comment

begin_define
define|#
directive|define
name|G6XXX_PMA_PMD_VS1
value|0xC001
end_define

begin_comment
comment|/* Vendor-specific register */
end_comment

begin_define
define|#
directive|define
name|G6XXX_XGXS_XAUI_VS2
value|0x18
end_define

begin_comment
comment|/* Vendor-specific register */
end_comment

begin_define
define|#
directive|define
name|G6XXX_PMA_PMD_VS1_PLL_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|G6XXX_PMA_PMD_VS1_REMOVE_PLL_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|G6XXX_XGXS_XAUI_VS2_INPUT_MASK
value|0x0F
end_define

begin_comment
comment|/* XAUI lanes synchronized */
end_comment

begin_comment
comment|/* Layout of a single receive descriptor.  The controller assumes that this  * structure is packed into 16 bytes, which is a safe assumption with most  * compilers.  However, some compilers may insert padding between the fields,  * in which case the structure must be packed in some compiler-specific  * manner. */
end_comment

begin_struct
struct|struct
name|ixgb_rx_desc
block|{
name|uint64_t
name|buff_addr
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|errors
decl_stmt|;
name|uint16_t
name|special
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_DD
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_EOP
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_IXSM
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_VP
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_TCPCS
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_IPCS
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_STATUS_PIF
value|0x80
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_CE
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_SE
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_P
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_TCPE
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_IPE
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_ERRORS_RXE
value|0x80
end_define

begin_define
define|#
directive|define
name|IXGB_RX_DESC_SPECIAL_VLAN_MASK
value|0x0FFF
end_define

begin_comment
comment|/* VLAN ID is in lower 12 bits */
end_comment

begin_define
define|#
directive|define
name|IXGB_RX_DESC_SPECIAL_PRI_MASK
value|0xE000
end_define

begin_comment
comment|/* Priority is in upper 3 bits */
end_comment

begin_define
define|#
directive|define
name|IXGB_RX_DESC_SPECIAL_PRI_SHIFT
value|0x000D
end_define

begin_comment
comment|/* Priority is in upper 3 of 16 */
end_comment

begin_comment
comment|/* Layout of a single transmit descriptor.  The controller assumes that this  * structure is packed into 16 bytes, which is a safe assumption with most  * compilers.  However, some compilers may insert padding between the fields,  * in which case the structure must be packed in some compiler-specific  * manner. */
end_comment

begin_struct
struct|struct
name|ixgb_tx_desc
block|{
name|uint64_t
name|buff_addr
decl_stmt|;
name|uint32_t
name|cmd_type_len
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|popts
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGB_TX_DESC_LENGTH_MASK
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_TYPE_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_TYPE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_EOP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_TSE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_RS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_VLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_CMD_IDE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_TYPE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_STATUS_DD
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_POPTS_IXSM
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_POPTS_TXSM
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGB_TX_DESC_SPECIAL_PRI_SHIFT
value|IXGB_RX_DESC_SPECIAL_PRI_SHIFT
end_define

begin_comment
comment|/* Priority is in upper 3 of 16 */
end_comment

begin_struct
struct|struct
name|ixgb_context_desc
block|{
name|uint8_t
name|ipcss
decl_stmt|;
name|uint8_t
name|ipcso
decl_stmt|;
name|uint16_t
name|ipcse
decl_stmt|;
name|uint8_t
name|tucss
decl_stmt|;
name|uint8_t
name|tucso
decl_stmt|;
name|uint16_t
name|tucse
decl_stmt|;
name|uint32_t
name|cmd_type_len
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|hdr_len
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_CMD_TCP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_CMD_IP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_CMD_TSE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_CMD_RS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_CMD_IDE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_TYPE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGB_CONTEXT_DESC_STATUS_DD
value|0x01
end_define

begin_comment
comment|/* Filters */
end_comment

begin_define
define|#
directive|define
name|IXGB_RAR_ENTRIES
value|16
end_define

begin_comment
comment|/* Number of entries in Rx Address array */
end_comment

begin_define
define|#
directive|define
name|IXGB_MC_TBL_SIZE
value|128
end_define

begin_comment
comment|/* Multicast Filter Table (4096 bits) */
end_comment

begin_define
define|#
directive|define
name|IXGB_VLAN_FILTER_TBL_SIZE
value|128
end_define

begin_comment
comment|/* VLAN Filter Table (4096 bits) */
end_comment

begin_define
define|#
directive|define
name|IXGB_MEMORY_REGISTER_BASE_ADDRESS
value|0
end_define

begin_define
define|#
directive|define
name|ENET_HEADER_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|ENET_FCS_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_NUM_MULTICAST_ADDRESSES
value|128
end_define

begin_define
define|#
directive|define
name|IXGB_MIN_ENET_FRAME_SIZE_WITHOUT_FCS
value|60
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_ENET_FRAME_SIZE_WITHOUT_FCS
value|1514
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_JUMBO_FRAME_SIZE
value|0x3F00
end_define

begin_comment
comment|/* Phy Addresses */
end_comment

begin_define
define|#
directive|define
name|IXGB_OPTICAL_PHY_ADDR
value|0x0
end_define

begin_comment
comment|/* Optical Module phy address*/
end_comment

begin_define
define|#
directive|define
name|IXGB_XAUII_PHY_ADDR
value|0x1
end_define

begin_comment
comment|/* Xauii transceiver phy address*/
end_comment

begin_define
define|#
directive|define
name|IXGB_DIAG_PHY_ADDR
value|0x1F
end_define

begin_comment
comment|/* Diagnostic Device phy address*/
end_comment

begin_comment
comment|/* This structure takes a 64k flash and maps it for identification commands */
end_comment

begin_struct
struct|struct
name|ixgb_flash_buffer
block|{
name|uint8_t
name|manufacturer_id
decl_stmt|;
name|uint8_t
name|device_id
decl_stmt|;
name|uint8_t
name|filler1
index|[
literal|0x2AA8
index|]
decl_stmt|;
name|uint8_t
name|cmd2
decl_stmt|;
name|uint8_t
name|filler2
index|[
literal|0x2AAA
index|]
decl_stmt|;
name|uint8_t
name|cmd1
decl_stmt|;
name|uint8_t
name|filler3
index|[
literal|0xAAAA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is a little-endian specific check.  */
end_comment

begin_define
define|#
directive|define
name|IS_MULTICAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|(boolean_t)(((uint8_t *)(Address))[0]& ((uint8_t)0x01))
end_define

begin_comment
comment|/*  * Check whether an address is broadcast.  */
end_comment

begin_define
define|#
directive|define
name|IS_BROADCAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|((((uint8_t *)(Address))[0] == ((uint8_t)0xff))&& (((uint8_t *)(Address))[1] == ((uint8_t)0xff)))
end_define

begin_comment
comment|/* Flow control parameters */
end_comment

begin_struct
struct|struct
name|ixgb_fc
block|{
name|uint32_t
name|high_water
decl_stmt|;
comment|/* Flow Control High-water          */
name|uint32_t
name|low_water
decl_stmt|;
comment|/* Flow Control Low-water           */
name|uint16_t
name|pause_time
decl_stmt|;
comment|/* Flow Control Pause timer         */
name|boolean_t
name|send_xon
decl_stmt|;
comment|/* Flow control send XON            */
name|ixgb_fc_type
name|type
decl_stmt|;
comment|/* Type of flow control             */
block|}
struct|;
end_struct

begin_comment
comment|/* The historical defaults for the flow control values are given below. */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_HI_THRESH
value|(0x8000)
end_define

begin_comment
comment|/* 32KB */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_LO_THRESH
value|(0x4000)
end_define

begin_comment
comment|/* 16KB */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_TX_TIMER
value|(0x100)
end_define

begin_comment
comment|/* ~130 us */
end_comment

begin_comment
comment|/* Phy definitions */
end_comment

begin_define
define|#
directive|define
name|IXGB_MAX_PHY_REG_ADDRESS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_PHY_ADDRESS
value|31
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_PHY_DEV_TYPE
value|31
end_define

begin_comment
comment|/* Bus parameters */
end_comment

begin_struct
struct|struct
name|ixgb_bus
block|{
name|ixgb_bus_speed
name|speed
decl_stmt|;
name|ixgb_bus_width
name|width
decl_stmt|;
name|ixgb_bus_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgb_hw
block|{
name|uint8_t
modifier|*
name|hw_addr
decl_stmt|;
comment|/* Base Address of the hardware     */
name|void
modifier|*
name|back
decl_stmt|;
comment|/* Pointer to OS-dependent struct   */
name|struct
name|ixgb_fc
name|fc
decl_stmt|;
comment|/* Flow control parameters          */
name|struct
name|ixgb_bus
name|bus
decl_stmt|;
comment|/* Bus parameters                   */
name|uint32_t
name|phy_id
decl_stmt|;
comment|/* Phy Identifier                   */
name|uint32_t
name|phy_addr
decl_stmt|;
comment|/* XGMII address of Phy             */
name|ixgb_mac_type
name|mac_type
decl_stmt|;
comment|/* Identifier for MAC controller    */
name|ixgb_phy_type
name|phy_type
decl_stmt|;
comment|/* Transceiver/phy identifier       */
name|uint32_t
name|max_frame_size
decl_stmt|;
comment|/* Maximum frame size supported     */
name|uint32_t
name|mc_filter_type
decl_stmt|;
comment|/* Multicast filter hash type       */
name|uint32_t
name|num_mc_addrs
decl_stmt|;
comment|/* Number of current Multicast addrs*/
name|uint8_t
name|curr_mac_addr
index|[
name|IXGB_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
comment|/* Individual address currently programmed in MAC */
name|uint32_t
name|num_tx_desc
decl_stmt|;
comment|/* Number of Transmit descriptors   */
name|uint32_t
name|num_rx_desc
decl_stmt|;
comment|/* Number of Receive descriptors    */
name|uint32_t
name|rx_buffer_size
decl_stmt|;
comment|/* Size of Receive buffer           */
name|boolean_t
name|link_up
decl_stmt|;
comment|/* TRUE if link is valid            */
name|boolean_t
name|adapter_stopped
decl_stmt|;
comment|/* State of adapter                 */
name|uint16_t
name|device_id
decl_stmt|;
comment|/* device id from PCI configuration space */
name|uint16_t
name|vendor_id
decl_stmt|;
comment|/* vendor id from PCI configuration space */
name|uint8_t
name|revision_id
decl_stmt|;
comment|/* revision id from PCI configuration space */
name|uint16_t
name|subsystem_vendor_id
decl_stmt|;
comment|/* subsystem vendor id from PCI configuration space */
name|uint16_t
name|subsystem_id
decl_stmt|;
comment|/* subsystem id from PCI configuration space */
name|uint32_t
name|bar0
decl_stmt|;
comment|/* Base Address registers           */
name|uint32_t
name|bar1
decl_stmt|;
name|uint32_t
name|bar2
decl_stmt|;
name|uint32_t
name|bar3
decl_stmt|;
name|uint16_t
name|pci_cmd_word
decl_stmt|;
comment|/* PCI command register id from PCI configuration space */
name|uint16_t
name|eeprom
index|[
name|IXGB_EEPROM_SIZE
index|]
decl_stmt|;
comment|/* EEPROM contents read at init time  */
name|unsigned
name|long
name|io_base
decl_stmt|;
comment|/* Our I/O mapped location */
name|uint32_t
name|lastLFC
decl_stmt|;
name|uint32_t
name|lastRFC
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics reported by the hardware */
end_comment

begin_struct
struct|struct
name|ixgb_hw_stats
block|{
name|uint64_t
name|tprl
decl_stmt|;
name|uint64_t
name|tprh
decl_stmt|;
name|uint64_t
name|gprcl
decl_stmt|;
name|uint64_t
name|gprch
decl_stmt|;
name|uint64_t
name|bprcl
decl_stmt|;
name|uint64_t
name|bprch
decl_stmt|;
name|uint64_t
name|mprcl
decl_stmt|;
name|uint64_t
name|mprch
decl_stmt|;
name|uint64_t
name|uprcl
decl_stmt|;
name|uint64_t
name|uprch
decl_stmt|;
name|uint64_t
name|vprcl
decl_stmt|;
name|uint64_t
name|vprch
decl_stmt|;
name|uint64_t
name|jprcl
decl_stmt|;
name|uint64_t
name|jprch
decl_stmt|;
name|uint64_t
name|gorcl
decl_stmt|;
name|uint64_t
name|gorch
decl_stmt|;
name|uint64_t
name|torl
decl_stmt|;
name|uint64_t
name|torh
decl_stmt|;
name|uint64_t
name|rnbc
decl_stmt|;
name|uint64_t
name|ruc
decl_stmt|;
name|uint64_t
name|roc
decl_stmt|;
name|uint64_t
name|rlec
decl_stmt|;
name|uint64_t
name|crcerrs
decl_stmt|;
name|uint64_t
name|icbc
decl_stmt|;
name|uint64_t
name|ecbc
decl_stmt|;
name|uint64_t
name|mpc
decl_stmt|;
name|uint64_t
name|tptl
decl_stmt|;
name|uint64_t
name|tpth
decl_stmt|;
name|uint64_t
name|gptcl
decl_stmt|;
name|uint64_t
name|gptch
decl_stmt|;
name|uint64_t
name|bptcl
decl_stmt|;
name|uint64_t
name|bptch
decl_stmt|;
name|uint64_t
name|mptcl
decl_stmt|;
name|uint64_t
name|mptch
decl_stmt|;
name|uint64_t
name|uptcl
decl_stmt|;
name|uint64_t
name|uptch
decl_stmt|;
name|uint64_t
name|vptcl
decl_stmt|;
name|uint64_t
name|vptch
decl_stmt|;
name|uint64_t
name|jptcl
decl_stmt|;
name|uint64_t
name|jptch
decl_stmt|;
name|uint64_t
name|gotcl
decl_stmt|;
name|uint64_t
name|gotch
decl_stmt|;
name|uint64_t
name|totl
decl_stmt|;
name|uint64_t
name|toth
decl_stmt|;
name|uint64_t
name|dc
decl_stmt|;
name|uint64_t
name|plt64c
decl_stmt|;
name|uint64_t
name|tsctc
decl_stmt|;
name|uint64_t
name|tsctfc
decl_stmt|;
name|uint64_t
name|ibic
decl_stmt|;
name|uint64_t
name|rfc
decl_stmt|;
name|uint64_t
name|lfc
decl_stmt|;
name|uint64_t
name|pfrc
decl_stmt|;
name|uint64_t
name|pftc
decl_stmt|;
name|uint64_t
name|mcfrc
decl_stmt|;
name|uint64_t
name|mcftc
decl_stmt|;
name|uint64_t
name|xonrxc
decl_stmt|;
name|uint64_t
name|xontxc
decl_stmt|;
name|uint64_t
name|xoffrxc
decl_stmt|;
name|uint64_t
name|xofftxc
decl_stmt|;
name|uint64_t
name|rjc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
specifier|extern
name|boolean_t
name|ixgb_adapter_stop
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|ixgb_init_hw
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|ixgb_adapter_start
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_init_rx_addrs
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_check_for_link
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|ixgb_check_for_bad_link
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|ixgb_setup_fc
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_clear_hw_cntrs
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|mac_addr_valid
parameter_list|(
name|uint8_t
modifier|*
name|mac_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint16_t
name|ixgb_read_phy_reg
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint32_t
name|phy_addr
parameter_list|,
name|uint32_t
name|device_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_write_phy_reg
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint32_t
name|phy_addr
parameter_list|,
name|uint32_t
name|device_type
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_rar_set
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint8_t
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Filters (multicast, vlan, receive) */
end_comment

begin_function_decl
specifier|extern
name|void
name|ixgb_mc_addr_list_update
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint8_t
modifier|*
name|mc_addr_list
parameter_list|,
name|uint32_t
name|mc_addr_count
parameter_list|,
name|uint32_t
name|pad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Vfta functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|ixgb_write_vfta
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ixgb_clear_vfta
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Access functions to eeprom data */
end_comment

begin_function_decl
name|void
name|ixgb_get_ee_mac_addr
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint8_t
modifier|*
name|mac_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_compatibility
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ixgb_get_ee_pba_number
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_init_ctrl_reg_1
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_init_ctrl_reg_2
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_subsystem_id
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_subvendor_id
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_device_id
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_vendor_id
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_ee_swdpins_reg
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ixgb_get_ee_d3_power
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ixgb_get_ee_d0_power
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|ixgb_get_eeprom_data
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ixgb_get_eeprom_word
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint16_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Everything else */
end_comment

begin_function_decl
name|void
name|ixgb_led_on
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgb_led_off
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgb_write_pci_cfg
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGB_HW_H_ */
end_comment

end_unit

