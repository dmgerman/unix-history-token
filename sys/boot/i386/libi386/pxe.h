begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Alfred Perlstein<alfred@freebsd.org>  * All rights reserved.  * Copyright (c) 2000 Paul Saab<ps@freebsd.org>  * All rights reserved.  * Copyright (c) 2000 John Baldwin<jhb@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The typedefs and structures declared in this file  * clearly violate style(9), the reason for this is to conform to the  * typedefs/structure-names used in the Intel literature to avoid confusion.  *  * It's for your own good. :)  */
end_comment

begin_comment
comment|/* It seems that intel didn't think about ABI,  * either that or 16bit ABI != 32bit ABI (which seems reasonable)  * I have to thank Intel for the hair loss I incurred trying to figure  * out why PXE was mis-reading structures I was passing it (at least  * from my point of view)  *  * Solution: use gcc's '__attribute__ ((packed))' to correctly align  * structures passed into PXE  * Question: does this really work for PXE's expected ABI?  */
end_comment

begin_define
define|#
directive|define
name|PACKED
value|__attribute__ ((packed))
end_define

begin_define
define|#
directive|define
name|S_SIZE
parameter_list|(
name|s
parameter_list|)
value|s, sizeof(s) - 1
end_define

begin_define
define|#
directive|define
name|IP_STR
value|"%d.%d.%d.%d"
end_define

begin_define
define|#
directive|define
name|IP_ARGS
parameter_list|(
name|ip
parameter_list|)
define|\
value|(int)(ip>> 24)& 0xff, (int)(ip>> 16)& 0xff, \ 	(int)(ip>> 8)& 0xff, (int)ip& 0xff
end_define

begin_define
define|#
directive|define
name|MAC_STR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_define
define|#
directive|define
name|MAC_ARGS
parameter_list|(
name|mac
parameter_list|)
define|\
value|mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]
end_define

begin_define
define|#
directive|define
name|PXENFSROOTPATH
value|"/pxeroot"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|segment
decl_stmt|;
block|}
name|SEGOFF16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|Seg_Addr
decl_stmt|;
name|uint32_t
name|Phy_Addr
decl_stmt|;
name|uint16_t
name|Seg_Size
decl_stmt|;
block|}
name|SEGDESC_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|SEGSEL_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|PXENV_STATUS_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|IP4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ADDR32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|UDP_PORT_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAC_ADDR_LEN
value|16
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|MAC_ADDR
index|[
name|MAC_ADDR_LEN
index|]
typedef|;
end_typedef

begin_comment
comment|/* PXENV+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|Signature
index|[
literal|6
index|]
decl_stmt|;
comment|/* 'PXENV+' */
name|uint16_t
name|Version
decl_stmt|;
comment|/* MSB = major, LSB = minor */
name|uint8_t
name|Length
decl_stmt|;
comment|/* structure length */
name|uint8_t
name|Checksum
decl_stmt|;
comment|/* checksum pad */
name|SEGOFF16_t
name|RMEntry
decl_stmt|;
comment|/* SEG:OFF to PXE entry point */
comment|/* don't use PMOffset and PMSelector (from the 2.1 PXE manual) */
name|uint32_t
name|PMOffset
decl_stmt|;
comment|/* Protected mode entry */
name|SEGSEL_t
name|PMSelector
decl_stmt|;
comment|/* Protected mode selector */
name|SEGSEL_t
name|StackSeg
decl_stmt|;
comment|/* Stack segment address */
name|uint16_t
name|StackSize
decl_stmt|;
comment|/* Stack segment size (bytes) */
name|SEGSEL_t
name|BC_CodeSeg
decl_stmt|;
comment|/* BC Code segment address */
name|uint16_t
name|BC_CodeSize
decl_stmt|;
comment|/* BC Code segment size (bytes) */
name|SEGSEL_t
name|BC_DataSeg
decl_stmt|;
comment|/* BC Data segment address */
name|uint16_t
name|BC_DataSize
decl_stmt|;
comment|/* BC Data segment size (bytes) */
name|SEGSEL_t
name|UNDIDataSeg
decl_stmt|;
comment|/* UNDI Data segment address */
name|uint16_t
name|UNDIDataSize
decl_stmt|;
comment|/* UNDI Data segment size (bytes) */
name|SEGSEL_t
name|UNDICodeSeg
decl_stmt|;
comment|/* UNDI Code segment address */
name|uint16_t
name|UNDICodeSize
decl_stmt|;
comment|/* UNDI Code segment size (bytes) */
name|SEGOFF16_t
name|PXEPtr
decl_stmt|;
comment|/* SEG:OFF to !PXE struct,  					   only present when Version> 2.1 */
block|}
name|PACKED
name|pxenv_t
typedef|;
end_typedef

begin_comment
comment|/* !PXE */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|Signature
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|StructLength
decl_stmt|;
name|uint8_t
name|StructCksum
decl_stmt|;
name|uint8_t
name|StructRev
decl_stmt|;
name|uint8_t
name|reserved_1
decl_stmt|;
name|SEGOFF16_t
name|UNDIROMID
decl_stmt|;
name|SEGOFF16_t
name|BaseROMID
decl_stmt|;
name|SEGOFF16_t
name|EntryPointSP
decl_stmt|;
name|SEGOFF16_t
name|EntryPointESP
decl_stmt|;
name|SEGOFF16_t
name|StatusCallout
decl_stmt|;
name|uint8_t
name|reserved_2
decl_stmt|;
name|uint8_t
name|SegDescCn
decl_stmt|;
name|SEGSEL_t
name|FirstSelector
decl_stmt|;
name|SEGDESC_t
name|Stack
decl_stmt|;
name|SEGDESC_t
name|UNDIData
decl_stmt|;
name|SEGDESC_t
name|UNDICode
decl_stmt|;
name|SEGDESC_t
name|UNDICodeWrite
decl_stmt|;
name|SEGDESC_t
name|BC_Data
decl_stmt|;
name|SEGDESC_t
name|BC_Code
decl_stmt|;
name|SEGDESC_t
name|BC_CodeWrite
decl_stmt|;
block|}
name|PACKED
name|pxe_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_START_UNDI
value|0x0000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|ax
decl_stmt|;
name|uint16_t
name|bx
decl_stmt|;
name|uint16_t
name|dx
decl_stmt|;
name|uint16_t
name|di
decl_stmt|;
name|uint16_t
name|es
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_START_UNDI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_STARTUP
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_STARTUP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_CLEANUP
value|0x0002
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_CLEANUP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_INITIALIZE
value|0x0003
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|ADDR32_t
name|ProtocolIni
decl_stmt|;
comment|/* Phys addr of a copy of the driver module */
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_INITALIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXNUM_MCADDR
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|MCastAddrCount
decl_stmt|;
name|MAC_ADDR
name|McastAddr
index|[
name|MAXNUM_MCADDR
index|]
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_MCAST_ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_RESET_ADAPTER
value|0x0004
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|t_PXENV_UNDI_MCAST_ADDRESS
name|R_Mcast_Buf
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_RESET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_SHUTDOWN
value|0x0005
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_SHUTDOWN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_OPEN
value|0x0006
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|OpenFlag
decl_stmt|;
name|uint16_t
name|PktFilter
decl_stmt|;
define|#
directive|define
name|FLTR_DIRECTED
value|0x0001
define|#
directive|define
name|FLTR_BRDCST
value|0x0002
define|#
directive|define
name|FLTR_PRMSCS
value|0x0003
define|#
directive|define
name|FLTR_SRC_RTG
value|0x0004
name|t_PXENV_UNDI_MCAST_ADDRESS
name|R_Mcast_Buf
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_OPEN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_CLOSE
value|0x0007
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_CLOSE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_TRANSMIT
value|0x0008
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|Protocol
decl_stmt|;
define|#
directive|define
name|P_UNKNOWN
value|0
define|#
directive|define
name|P_IP
value|1
define|#
directive|define
name|P_ARP
value|2
define|#
directive|define
name|P_RARP
value|3
name|uint8_t
name|XmitFlag
decl_stmt|;
define|#
directive|define
name|XMT_DESTADDR
value|0x0000
define|#
directive|define
name|XMT_BROADCAST
value|0x0001
name|SEGOFF16_t
name|DestAddr
decl_stmt|;
name|SEGOFF16_t
name|TBD
decl_stmt|;
name|uint32_t
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_TRANSMIT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_DATA_BLKS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ImmedLength
decl_stmt|;
name|SEGOFF16_t
name|Xmit
decl_stmt|;
name|uint16_t
name|DataBlkCount
decl_stmt|;
struct|struct
name|DataBlk
block|{
name|uint8_t
name|TDPtrType
decl_stmt|;
name|uint8_t
name|TDRsvdByte
decl_stmt|;
name|uint16_t
name|TDDataLen
decl_stmt|;
name|SEGOFF16_t
name|TDDataPtr
decl_stmt|;
block|}
name|DataBlock
index|[
name|MAX_DATA_BLKS
index|]
struct|;
block|}
name|PACKED
name|t_PXENV_UNDI_TBD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_SET_MCAST_ADDRESS
value|0x0009
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|t_PXENV_UNDI_MCAST_ADDRESS
name|R_Mcast_Buf
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_SET_MCAST_ADDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_SET_STATION_ADDRESS
value|0x000A
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|MAC_ADDR
name|StationAddress
decl_stmt|;
comment|/* Temp MAC addres to use */
block|}
name|PACKED
name|t_PXENV_UNDI_SET_STATION_ADDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_SET_PACKET_FILTER
value|0x000B
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|filter
decl_stmt|;
comment|/* see UNDI_OPEN (0x0006) */
block|}
name|PACKED
name|t_PXENV_UNDI_SET_PACKET_FILTER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_GET_INFORMATION
value|0x000C
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|BaseIo
decl_stmt|;
comment|/* Adapter base I/O address */
name|uint16_t
name|IntNumber
decl_stmt|;
comment|/* Adapter IRQ number */
name|uint16_t
name|MaxTranUnit
decl_stmt|;
comment|/* Adapter maximum transmit unit */
name|uint16_t
name|HwType
decl_stmt|;
comment|/* Type of protocol at the hardware addr */
define|#
directive|define
name|ETHER_TYPE
value|1
define|#
directive|define
name|EXP_ETHER_TYPE
value|2
define|#
directive|define
name|IEEE_TYPE
value|6
define|#
directive|define
name|ARCNET_TYPE
value|7
name|uint16_t
name|HwAddrLen
decl_stmt|;
comment|/* Length of hardware address */
name|MAC_ADDR
name|CurrentNodeAddress
decl_stmt|;
comment|/* Current hardware address */
name|MAC_ADDR
name|PermNodeAddress
decl_stmt|;
comment|/* Permanent hardware address */
name|SEGSEL_t
name|ROMAddress
decl_stmt|;
comment|/* Real mode ROM segment address */
name|uint16_t
name|RxBufCt
decl_stmt|;
comment|/* Receive queue length */
name|uint16_t
name|TxBufCt
decl_stmt|;
comment|/* Transmit queue length */
block|}
name|PACKED
name|t_PXENV_UNDI_GET_INFORMATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_GET_STATISTICS
value|0x000D
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint32_t
name|XmitGoodFrames
decl_stmt|;
comment|/* Number of successful transmissions */
name|uint32_t
name|RcvGoodFrames
decl_stmt|;
comment|/* Number of good frames received */
name|uint32_t
name|RcvCRCErrors
decl_stmt|;
comment|/* Number of frames with CRC errors */
name|uint32_t
name|RcvResourceErrors
decl_stmt|;
comment|/* Number of frames dropped */
block|}
name|PACKED
name|t_PXENV_UNDI_GET_STATISTICS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_CLEAR_STATISTICS
value|0x000E
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_CLEAR_STATISTICS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_INITIATE_DIAGS
value|0x000F
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_INITIATE_DIAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_FORCE_INTERRUPT
value|0x0010
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNDI_FORCE_INTERRUPT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_GET_MCAST_ADDRESS
value|0x0011
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|IP4_t
name|InetAddr
decl_stmt|;
comment|/* IP mulicast address */
name|MAC_ADDR
name|MediaAddr
decl_stmt|;
comment|/* MAC multicast address */
block|}
name|PACKED
name|t_PXENV_UNDI_GET_MCAST_ADDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_GET_NIC_TYPE
value|0x0012
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|NicType
decl_stmt|;
comment|/* Type of NIC */
define|#
directive|define
name|PCI_NIC
value|2
define|#
directive|define
name|PnP_NIC
value|3
define|#
directive|define
name|CardBus_NIC
value|4
union|union
block|{
struct|struct
block|{
name|uint16_t
name|Vendor_ID
decl_stmt|;
name|uint16_t
name|Dev_ID
decl_stmt|;
name|uint8_t
name|Base_Class
decl_stmt|;
name|uint8_t
name|Sub_Class
decl_stmt|;
name|uint8_t
name|Prog_Intf
decl_stmt|;
name|uint8_t
name|Rev
decl_stmt|;
name|uint16_t
name|BusDevFunc
decl_stmt|;
name|uint16_t
name|SubVendor_ID
decl_stmt|;
name|uint16_t
name|SubDevice_ID
decl_stmt|;
block|}
name|pci
struct|,
name|cardbus
struct|;
struct|struct
block|{
name|uint32_t
name|EISA_Dev_ID
decl_stmt|;
name|uint8_t
name|Base_Class
decl_stmt|;
name|uint8_t
name|Sub_Class
decl_stmt|;
name|uint8_t
name|Prog_Intf
decl_stmt|;
name|uint16_t
name|CardSelNum
decl_stmt|;
block|}
name|pnp
struct|;
block|}
name|info
union|;
block|}
name|PACKED
name|t_PXENV_UNDI_GET_NIC_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_GET_IFACE_INFO
value|0x0013
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|IfaceType
index|[
literal|16
index|]
decl_stmt|;
comment|/* Name of MAC type in ASCII. */
name|uint32_t
name|LinkSpeed
decl_stmt|;
comment|/* Defined in NDIS 2.0 spec */
name|uint32_t
name|ServiceFlags
decl_stmt|;
comment|/* Defined in NDIS 2.0 spec */
name|uint32_t
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
comment|/* must be 0 */
block|}
name|PACKED
name|t_PXENV_UNDI_GET_NDIS_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNDI_ISR
value|0x0014
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|FuncFlag
decl_stmt|;
comment|/* PXENV_UNDI_ISR_OUT_xxx */
name|uint16_t
name|BufferLength
decl_stmt|;
comment|/* Length of Frame */
name|uint16_t
name|FrameLength
decl_stmt|;
comment|/* Total length of reciever frame */
name|uint16_t
name|FrameHeaderLength
decl_stmt|;
comment|/* Length of the media header in Frame */
name|SEGOFF16_t
name|Frame
decl_stmt|;
comment|/* receive buffer */
name|uint8_t
name|ProtType
decl_stmt|;
comment|/* Protocol type */
name|uint8_t
name|PktType
decl_stmt|;
comment|/* Packet Type */
define|#
directive|define
name|PXENV_UNDI_ISR_IN_START
value|1
define|#
directive|define
name|PXENV_UNDI_ISR_IN_PROCESS
value|2
define|#
directive|define
name|PXENV_UNDI_ISR_IN_GET_NEXT
value|3
comment|/* one of these will be returned for PXENV_UNDI_ISR_IN_START */
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_OURS
value|0
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_NOT_OUTS
value|1
comment|/* 	 * one of these will bre returnd for PXEND_UNDI_ISR_IN_PROCESS 	 * and PXENV_UNDI_ISR_IN_GET_NEXT 	 */
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_DONE
value|0
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_TRANSMIT
value|2
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_RECIEVE
value|3
define|#
directive|define
name|PXENV_UNDI_ISR_OUT_BUSY
value|4
block|}
name|PACKED
name|t_PXENV_UNDI_ISR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_STOP_UNDI
value|0x0015
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_STOP_UNDI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_TFTP_OPEN
value|0x0020
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|IP4_t
name|ServerIPAddress
decl_stmt|;
name|IP4_t
name|GatewayIPAddress
decl_stmt|;
name|uint8_t
name|FileName
index|[
literal|128
index|]
decl_stmt|;
name|UDP_PORT_t
name|TFTPPort
decl_stmt|;
name|uint16_t
name|PacketSize
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_TFTP_OPEN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_TFTP_CLOSE
value|0x0021
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_TFTP_CLOSE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_TFTP_READ
value|0x0022
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|PacketNumber
decl_stmt|;
name|uint16_t
name|BufferSize
decl_stmt|;
name|SEGOFF16_t
name|Buffer
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_TFTP_READ
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_TFTP_READ_FILE
value|0x0023
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|FileName
index|[
literal|128
index|]
decl_stmt|;
name|uint32_t
name|BufferSize
decl_stmt|;
name|ADDR32_t
name|Buffer
decl_stmt|;
name|IP4_t
name|ServerIPAddress
decl_stmt|;
name|IP4_t
name|GatewayIPAdress
decl_stmt|;
name|IP4_t
name|McastIPAdress
decl_stmt|;
name|UDP_PORT_t
name|TFTPClntPort
decl_stmt|;
name|UDP_PORT_t
name|TFTPSrvPort
decl_stmt|;
name|uint16_t
name|TFTPOpenTimeOut
decl_stmt|;
name|uint16_t
name|TFTPReopenDelay
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_TFTP_READ_FILE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_TFTP_GET_FSIZE
value|0x0025
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|IP4_t
name|ServerIPAddress
decl_stmt|;
name|IP4_t
name|GatewayIPAdress
decl_stmt|;
name|uint8_t
name|FileName
index|[
literal|128
index|]
decl_stmt|;
name|uint32_t
name|FileSize
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_TFTP_GET_FSIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UDP_OPEN
value|0x0030
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|status
decl_stmt|;
name|IP4_t
name|src_ip
decl_stmt|;
comment|/* IP address of this station */
block|}
name|PACKED
name|t_PXENV_UDP_OPEN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UDP_CLOSE
value|0x0031
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UDP_CLOSE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UDP_READ
value|0x0032
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|status
decl_stmt|;
name|IP4_t
name|src_ip
decl_stmt|;
comment|/* IP of sender */
name|IP4_t
name|dest_ip
decl_stmt|;
comment|/* Only accept packets sent to this IP */
name|UDP_PORT_t
name|s_port
decl_stmt|;
comment|/* UDP source port of sender */
name|UDP_PORT_t
name|d_port
decl_stmt|;
comment|/* Only accept packets sent to this port */
name|uint16_t
name|buffer_size
decl_stmt|;
comment|/* Size of the packet buffer */
name|SEGOFF16_t
name|buffer
decl_stmt|;
comment|/* SEG:OFF to the packet buffer */
block|}
name|PACKED
name|t_PXENV_UDP_READ
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UDP_WRITE
value|0x0033
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|status
decl_stmt|;
name|IP4_t
name|ip
decl_stmt|;
comment|/* dest ip addr */
name|IP4_t
name|gw
decl_stmt|;
comment|/* ip gateway */
name|UDP_PORT_t
name|src_port
decl_stmt|;
comment|/* source udp port */
name|UDP_PORT_t
name|dst_port
decl_stmt|;
comment|/* destination udp port */
name|uint16_t
name|buffer_size
decl_stmt|;
comment|/* Size of the packet buffer */
name|SEGOFF16_t
name|buffer
decl_stmt|;
comment|/* SEG:OFF to the packet buffer */
block|}
name|PACKED
name|t_PXENV_UDP_WRITE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_UNLOAD_STACK
value|0x0070
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_UNLOAD_STACK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_GET_CACHED_INFO
value|0x0071
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
name|uint16_t
name|PacketType
decl_stmt|;
comment|/* type (defined right here) */
define|#
directive|define
name|PXENV_PACKET_TYPE_DHCP_DISCOVER
value|1
define|#
directive|define
name|PXENV_PACKET_TYPE_DHCP_ACK
value|2
define|#
directive|define
name|PXENV_PACKET_TYPE_BINL_REPLY
value|3
name|uint16_t
name|BufferSize
decl_stmt|;
comment|/* max to copy, leave at 0 for pointer */
name|SEGOFF16_t
name|Buffer
decl_stmt|;
comment|/* copy to, leave at 0 for pointer */
name|uint16_t
name|BufferLimit
decl_stmt|;
comment|/* max size of buffer in BC dataseg ? */
block|}
name|PACKED
name|t_PXENV_GET_CACHED_INFO
typedef|;
end_typedef

begin_comment
comment|/* structure filled in by PXENV_GET_CACHED_INFO   * (how we determine which IP we downloaded the initial bootstrap from)  * words can't describe...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|BOOTP_REQ
value|1
define|#
directive|define
name|BOOTP_REP
value|2
name|uint8_t
name|Hardware
decl_stmt|;
comment|/* hardware type */
name|uint8_t
name|Hardlen
decl_stmt|;
comment|/* hardware addr len */
name|uint8_t
name|Gatehops
decl_stmt|;
comment|/* zero it */
name|uint32_t
name|ident
decl_stmt|;
comment|/* random number chosen by client */
name|uint16_t
name|seconds
decl_stmt|;
comment|/* seconds since did initial bootstrap */
name|uint16_t
name|Flags
decl_stmt|;
comment|/* seconds since did initial bootstrap */
define|#
directive|define
name|BOOTP_BCAST
value|0x8000
comment|/* ? */
name|IP4_t
name|cip
decl_stmt|;
comment|/* Client IP */
name|IP4_t
name|yip
decl_stmt|;
comment|/* Your IP */
name|IP4_t
name|sip
decl_stmt|;
comment|/* IP to use for next boot stage */
name|IP4_t
name|gip
decl_stmt|;
comment|/* Relay IP ? */
name|MAC_ADDR
name|CAddr
decl_stmt|;
comment|/* Client hardware address */
name|uint8_t
name|Sname
index|[
literal|64
index|]
decl_stmt|;
comment|/* Server's hostname (Optional) */
name|uint8_t
name|bootfile
index|[
literal|128
index|]
decl_stmt|;
comment|/* boot filename */
union|union
block|{
if|#
directive|if
literal|1
define|#
directive|define
name|BOOTP_DHCPVEND
value|1024
comment|/* DHCP extended vendor field size */
else|#
directive|else
define|#
directive|define
name|BOOTP_DHCPVEND
value|312
comment|/* DHCP standard vendor field size */
endif|#
directive|endif
name|uint8_t
name|d
index|[
name|BOOTP_DHCPVEND
index|]
decl_stmt|;
comment|/* raw array of vendor/dhcp options */
struct|struct
block|{
name|uint8_t
name|magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* DHCP magic cookie */
ifndef|#
directive|ifndef
name|VM_RFC1048
define|#
directive|define
name|VM_RFC1048
value|0x63825363L
comment|/* ? */
endif|#
directive|endif
name|uint32_t
name|flags
decl_stmt|;
comment|/* bootp flags/opcodes */
name|uint8_t
name|pad
index|[
literal|56
index|]
decl_stmt|;
comment|/* I don't think intel knows what a 							   union does... */
block|}
name|v
struct|;
block|}
name|vendor
union|;
block|}
name|PACKED
name|BOOTPLAYER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_RESTART_TFTP
value|0x0073
end_define

begin_define
define|#
directive|define
name|t_PXENV_RESTART_TFTP
value|t_PXENV_TFTP_READ_FILE
end_define

begin_define
define|#
directive|define
name|PXENV_START_BASE
value|0x0075
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_START_BASE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXENV_STOP_BASE
value|0x0076
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXENV_STATUS_t
name|Status
decl_stmt|;
block|}
name|PACKED
name|t_PXENV_STOP_BASE
typedef|;
end_typedef

end_unit

