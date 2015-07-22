begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file spcdefs.h  *  \brief The file defines the MPI Application Programming Interface (API)  *  * The file defines the MPI Application Programming Interfacde (API)  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SPCDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SPCDEFS_H__
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* CONSTANTS                                                                    */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* MSGU CONFIGURATION TABLE                                                    */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPC_MSGU_CFG_TABLE_UPDATE
value|0x001
end_define

begin_comment
comment|/* Inbound doorbell bit0 */
end_comment

begin_define
define|#
directive|define
name|SPC_MSGU_CFG_TABLE_RESET
value|0x002
end_define

begin_comment
comment|/* Inbound doorbell bit1 */
end_comment

begin_define
define|#
directive|define
name|SPC_MSGU_CFG_TABLE_FREEZE
value|0x004
end_define

begin_comment
comment|/* Inbound doorbell bit2 */
end_comment

begin_define
define|#
directive|define
name|SPC_MSGU_CFG_TABLE_UNFREEZE
value|0x008
end_define

begin_comment
comment|/* Inbound doorbell bit4 */
end_comment

begin_define
define|#
directive|define
name|SPCV_MSGU_CFG_TABLE_TRANSFER_DEBUG_INFO
value|0x080
end_define

begin_comment
comment|/* Inbound doorbell bit7 SPCV */
end_comment

begin_define
define|#
directive|define
name|SPCV_MSGU_HALT_CPUS
value|0x100
end_define

begin_comment
comment|/* Inbound doorbell bit8 SPCV */
end_comment

begin_comment
comment|/***** Notes *****/
end_comment

begin_comment
comment|/* The firmware side is using Little Endian (MIPs). */
end_comment

begin_comment
comment|/* So anything sending or receiving from FW must be in Little Endian */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiMsgHeader_s  *  \brief MPI message header  *  * The mpiMsgHeader_s defines the fields in the header of every message  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* This structire defines the fields in the header of every message */
end_comment

begin_struct
struct|struct
name|mpiMsgHeader_s
block|{
name|bit32
name|Header
decl_stmt|;
comment|/* Bits [11:0]  - Message operation code */
comment|/* Bits [15:12] - Message Category */
comment|/* Bits [21:16] - Outboundqueue ID for the operation completion message */
comment|/* Bits [23:22] - Reserved */
comment|/* Bits [28:24] - Buffer Count, indicates how many buffer are allocated for the massage */
comment|/* Bits [30:29] - Reserved */
comment|/* Bits [31]    - Message Valid bit */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiMsgHeader_s
name|mpiMsgHeader_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|V_BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|BC_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|OBID_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|CAT_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|OPCODE_MASK
value|0xFFF
end_define

begin_define
define|#
directive|define
name|HEADER_V_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HEADER_BC_MASK
value|0x1f000000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SPC_CONFIG
end_ifndef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spc_ConfigMainDescriptor_s  *  \brief This structure is used to configure main part of Configuration Table  *  * This structure specifies all required attributes to configuration table  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* new MPI configuration main table */
end_comment

begin_struct
struct|struct
name|spc_configMainDescriptor_s
block|{
name|bit8
name|Signature
index|[
literal|4
index|]
decl_stmt|;
comment|/**< DW0 signature - Indicate coherent table */
name|bit32
name|InterfaceRev
decl_stmt|;
comment|/**< DW1 Revsion of Interface */
name|bit32
name|FWRevision
decl_stmt|;
comment|/**< DW2 Revsion of FW */
name|bit32
name|MaxOutstandingIO
decl_stmt|;
comment|/**< DW3 Max outstanding IO */
name|bit32
name|MDevMaxSGL
decl_stmt|;
comment|/**< DW4 Maximum SGL elements& Max Devices */
comment|/* bit0-15  Maximum SGL */
comment|/* bit16-31 Maximum Devices */
name|bit32
name|ContrlCapFlag
decl_stmt|;
comment|/**< DW5 Controller Capability */
comment|/* bit0-7   Max number of inbound queue */
comment|/* bit8-15  Max number of outbound queue */
comment|/* bit16    high priority of inbound queue is supported */
comment|/* bit17    reserved */
comment|/* bit18    interrupt coalescing is supported, SPCV-reserved */
comment|/* bit19-24 Maximum number of valid phys */
comment|/* bit25-31 SAS Revision SPecification */
name|bit32
name|GSTOffset
decl_stmt|;
comment|/**< DW6 General Status Table */
name|bit32
name|inboundQueueOffset
decl_stmt|;
comment|/**< DW7 inbound configuration table offset */
comment|/* bit23-0  inbound queue table offset */
comment|/* bit31-24 entry size, new in SPCV */
name|bit32
name|outboundQueueOffset
decl_stmt|;
comment|/**< DW8 outbound configuration table offset */
comment|/* bit23-0  outbound queue table offset */
comment|/* bit31-24 entry size, new in SPCV */
name|bit32
name|iQNPPD_HPPD_GEvent
decl_stmt|;
comment|/**< DW9 inbound Queue Process depth and General Event */
comment|/* bit0-7   inbound normal priority process depth */
comment|/* bit8-15  inbound high priority process depth */
comment|/* bit16-23 OQ number to receive GENERAL_EVENT Notification */
comment|/* bit24-31 OQ number to receive DEVICE_HANDLE_REMOVAL Notification */
name|bit32
name|outboundHWEventPID0_3
decl_stmt|;
comment|/**< DWA outbound HW event for PortId 0 to 3, SPCV-reserved */
comment|/* bit0-7   outbound queue number of SAS_HW event for PhyId 0 */
comment|/* bit8-15  outbound queue number of SAS_HW event for PhyId 1 */
comment|/* bit16-23 outbound queue number of SAS_HW event for PhyId 2 */
comment|/* bit24-31 outbound queue number of SAS_HW event for PhyId 3 */
name|bit32
name|outboundHWEventPID4_7
decl_stmt|;
comment|/**< DWB outbound HW event for PortId 4 to 7, SPCV-reserved */
comment|/* bit0-7   outbound queue number of SAS_HW event for PhyId 4 */
comment|/* bit8-15  outbound queue number of SAS_HW event for PhyId 5 */
comment|/* bit16-23 outbound queue number of SAS_HW event for PhyId 6 */
comment|/* bit24-31 outbound queue number of SAS_HW event for PhyId 7 */
name|bit32
name|outboundNCQEventPID0_3
decl_stmt|;
comment|/**< DWC outbound NCQ event for PortId 0 to 3, SPCV-reserved */
comment|/* bit0-7   outbound queue number of SATA_NCQ event for PhyId 0 */
comment|/* bit8-15  outbound queue number of SATA_NCQ event for PhyId 1 */
comment|/* bit16-23 outbound queue number of SATA_NCQ event for PhyId 2 */
comment|/* bit24-31 outbound queue number of SATA_NCQ event for PortId 3 */
name|bit32
name|outboundNCQEventPID4_7
decl_stmt|;
comment|/**< DWD outbound NCQ event for PortId 4 to 7, SPCV-reserved*/
comment|/* bit0-7   outbound queue number of SATA_NCQ event for PhyId 4 */
comment|/* bit8-15  outbound queue number of SATA_NCQ event for PhyId 5 */
comment|/* bit16-23 outbound queue number of SATA_NCQ event for PhyId 6 */
comment|/* bit24-31 outbound queue number of SATA_NCQ event for PhyId 7 */
name|bit32
name|outboundTargetITNexusEventPID0_3
decl_stmt|;
comment|/**< DWE outbound target ITNexus Event for PortId 0 to 3, SPCV-reserved */
comment|/* bit0-7   outbound queue number of ITNexus event for PhyId 0 */
comment|/* bit8-15  outbound queue number of ITNexus event for PhyId 1 */
comment|/* bit16-23 outbound queue number of ITNexus event for PhyId 2 */
comment|/* bit24-31 outbound queue number of ITNexus event for PhyId 3 */
name|bit32
name|outboundTargetITNexusEventPID4_7
decl_stmt|;
comment|/**< DWF outbound target ITNexus Event for PortId 4 to 7, SPCV-reserved */
comment|/* bit0-7   outbound queue number of ITNexus event for PhyId 4 */
comment|/* bit8-15  outbound queue number of ITNexus event for PhyId 5 */
comment|/* bit16-23 outbound queue number of ITNexus event for PhyId 6 */
comment|/* bit24-31 outbound queue number of ITNexus event for PhyId 7 */
name|bit32
name|outboundTargetSSPEventPID0_3
decl_stmt|;
comment|/**< DW10 outbound target SSP event for PordId 0 to 3, SPCV-reserved */
comment|/* bit0-7   outbound queue number of SSP event for PhyId 0 */
comment|/* bit8-15  outbound queue number of SSP event for PhyId 1 */
comment|/* bit16-23 outbound queue number of SSP event for PhyId 2 */
comment|/* bit24-31 outbound queue number of SSP event for PhyId 3 */
name|bit32
name|outboundTargetSSPEventPID4_7
decl_stmt|;
comment|/**< DW11 outbound target SSP event for PordId 4 to 7, SPCV-reserved */
comment|/* bit0-7   outbound queue number of SSP event for PhyId 4 */
comment|/* bit8-15  outbound queue number of SSP event for PhyId 5 */
comment|/* bit16-23 outbound queue number of SSP event for PhyId 6 */
comment|/* bit24-31 outbound queue number of SSP event for PhyId 7 */
name|bit32
name|ioAbortDelay
decl_stmt|;
comment|/**< DW12 IO Abort Delay (bit15:0) MPI_TABLE_CHANGE*/
name|bit32
name|custset
decl_stmt|;
comment|/**< DW13 custset */
name|bit32
name|upperEventLogAddress
decl_stmt|;
comment|/**< DW14 Upper physical MSGU Event log address */
name|bit32
name|lowerEventLogAddress
decl_stmt|;
comment|/**< DW15 Lower physical MSGU Event log address */
name|bit32
name|eventLogSize
decl_stmt|;
comment|/**< DW16 Size of MSGU Event log, 0 means log disable */
name|bit32
name|eventLogOption
decl_stmt|;
comment|/**< DW17 Option of MSGU Event log */
comment|/* bit3-0 log severity, 0x0 Disable Logging */
comment|/*                      0x1 Critical Error */
comment|/*                      0x2 Minor Error    */
comment|/*                      0x3 Warning        */
comment|/*                      0x4 Information    */
comment|/*                      0x5 Debugging      */
comment|/*                      0x6 - 0xF Reserved */
name|bit32
name|upperIOPeventLogAddress
decl_stmt|;
comment|/**< DW18 Upper physical IOP Event log address */
name|bit32
name|lowerIOPeventLogAddress
decl_stmt|;
comment|/**< DW19 Lower physical IOP Event log address */
name|bit32
name|IOPeventLogSize
decl_stmt|;
comment|/**< DW1A Size of IOP Event log, 0 means log disable */
name|bit32
name|IOPeventLogOption
decl_stmt|;
comment|/**< DW1B Option of IOP Event log */
comment|/* bit3-0 log severity, 0x0 Critical Error */
comment|/*                      0x1 Minor Error    */
comment|/*                      0x2 Warning        */
comment|/*                      0x3 Information    */
comment|/*                      0x4 Unknown        */
comment|/*                      0x5 - 0xF Reserved */
name|bit32
name|FatalErrorInterrupt
decl_stmt|;
comment|/**< DW1C Fatal Error Interrupt enable and vector */
comment|/* bit0     Fatal Error Interrupt Enable   */
comment|/* bit1     PI/CI 64bit address            */
comment|/* bit2     SGPIO IOMB support */
comment|/* bit6-2   Reserved                       */
comment|/* bit7     OQ NP/HPriority Path enable    */
comment|/* bit15-8  Fatal Error Interrupt Vector   */
comment|/* bit16    Enable IQ/OQ 64                */
comment|/* bit17    Interrupt Reassertion Enable   */
comment|/* bit18    Interrupt Reassertion Delay in ms          */
comment|/* bit31-19 Interrupt Reassertion delay, 0-default 1ms */
name|bit32
name|FatalErrorDumpOffset0
decl_stmt|;
comment|/**< DW1D FERDOMS-GU Fatal Error Register Dump Offset for MSGU */
name|bit32
name|FatalErrorDumpLength0
decl_stmt|;
comment|/**< DW1E FERDLMS-GU Fatal Error Register Dump Length for MSGU */
name|bit32
name|FatalErrorDumpOffset1
decl_stmt|;
comment|/**< DW1F FERDO-SSTRUCPCS Fatal Error Register Dump Offset for IOP */
name|bit32
name|FatalErrorDumpLength1
decl_stmt|;
comment|/**< DW20 FERDLSTRUCTTPCS  Fatal Error Register Dump Length for IOP */
name|bit32
name|HDAModeFlags
decl_stmt|;
comment|/**< DW21 HDA Mode Flags, SPCV-reserved */
name|bit32
name|analogSetupTblOffset
decl_stmt|;
comment|/**< DW22 SPASTO Phy Calibration Table offset */
comment|/* bit23-0  phy calib table offset */
comment|/* bit31-24 entry size */
name|bit32
name|InterruptVecTblOffset
decl_stmt|;
comment|/**< DW23 Interrupt Vector Table MPI_TABLE_CHANG */
comment|/* bit23-0  interrupt vector table offset */
comment|/* bit31-24 entry size */
name|bit32
name|phyAttributeTblOffset
decl_stmt|;
comment|/**< DW24 SAS Phy Attribute Table Offset MPI_TABLE_CHANG*/
comment|/* bit23-0  phy attribute table offset */
comment|/* bit31-24 entry size */
name|bit32
name|portRecoveryResetTimer
decl_stmt|;
comment|/* Offset 0x25 [31:16] Port recovery timer default that is 0                                               used for all SAS ports. Granularity of this timer is 100ms. The host can                                               change the individual port recovery timer by using the PORT_CONTROL                                               [15:0] Port reset timer default that is used 3 (i.e 300ms) for all                                               SAS ports. Granularity of this timer is 100ms. Host can change the                                               individual port recovery timer by using PORT_CONTROL Command */
name|bit32
name|interruptReassertionDelay
decl_stmt|;
comment|/* Offset 0x26 [23:0] Remind host of outbound completion 0 disabled 100usec per increment */
name|bit32
name|ilaRevision
decl_stmt|;
comment|/* Offset 0x27 */
block|}
struct|;
end_struct

begin_comment
comment|/* main configuration offset - byte offset */
end_comment

begin_define
define|#
directive|define
name|MAIN_SIGNATURE_OFFSET
value|0x00
end_define

begin_comment
comment|/* DWORD 0x00 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_INTERFACE_REVISION
value|0x04
end_define

begin_comment
comment|/* DWORD 0x01 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FW_REVISION
value|0x08
end_define

begin_comment
comment|/* DWORD 0x02 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_MAX_OUTSTANDING_IO_OFFSET
value|0x0C
end_define

begin_comment
comment|/* DWORD 0x03 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_MAX_SGL_OFFSET
value|0x10
end_define

begin_comment
comment|/* DWORD 0x04 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_CNTRL_CAP_OFFSET
value|0x14
end_define

begin_comment
comment|/* DWORD 0x05 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_GST_OFFSET
value|0x18
end_define

begin_comment
comment|/* DWORD 0x06 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IBQ_OFFSET
value|0x1C
end_define

begin_comment
comment|/* DWORD 0x07 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_OBQ_OFFSET
value|0x20
end_define

begin_comment
comment|/* DWORD 0x08 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IQNPPD_HPPD_OFFSET
value|0x24
end_define

begin_comment
comment|/* DWORD 0x09 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_HW_EVENT_PID03_OFFSET
value|0x28
end_define

begin_comment
comment|/* DWORD 0x0A (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_HW_EVENT_PID47_OFFSET
value|0x2C
end_define

begin_comment
comment|/* DWORD 0x0B (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_NCQ_EVENT_PID03_OFFSET
value|0x30
end_define

begin_comment
comment|/* DWORD 0x0C (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_NCQ_EVENT_PID47_OFFSET
value|0x34
end_define

begin_comment
comment|/* DWORD 0x0D (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_TITNX_EVENT_PID03_OFFSET
value|0x38
end_define

begin_comment
comment|/* DWORD 0x0E (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_TITNX_EVENT_PID47_OFFSET
value|0x3C
end_define

begin_comment
comment|/* DWORD 0x0F (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_SSP_EVENT_PID03_OFFSET
value|0x40
end_define

begin_comment
comment|/* DWORD 0x10 (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_OB_SSP_EVENT_PID47_OFFSET
value|0x44
end_define

begin_comment
comment|/* DWORD 0x11 (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_IO_ABORT_DELAY
value|0x48
end_define

begin_comment
comment|/* DWORD 0x12 (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_CUSTOMER_SETTING
value|0x4C
end_define

begin_comment
comment|/* DWORD 0x13 (W) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_EVENT_LOG_ADDR_HI
value|0x50
end_define

begin_comment
comment|/* DWORD 0x14 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_EVENT_LOG_ADDR_LO
value|0x54
end_define

begin_comment
comment|/* DWORD 0x15 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_EVENT_LOG_BUFF_SIZE
value|0x58
end_define

begin_comment
comment|/* DWORD 0x16 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_EVENT_LOG_OPTION
value|0x5C
end_define

begin_comment
comment|/* DWORD 0x17 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IOP_EVENT_LOG_ADDR_HI
value|0x60
end_define

begin_comment
comment|/* DWORD 0x18 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IOP_EVENT_LOG_ADDR_LO
value|0x64
end_define

begin_comment
comment|/* DWORD 0x19 (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IOP_EVENT_LOG_BUFF_SIZE
value|0x68
end_define

begin_comment
comment|/* DWORD 0x1A (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_IOP_EVENT_LOG_OPTION
value|0x6C
end_define

begin_comment
comment|/* DWORD 0x1B (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FATAL_ERROR_INTERRUPT
value|0x70
end_define

begin_comment
comment|/* DWORD 0x1C (W) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FATAL_ERROR_RDUMP0_OFFSET
value|0x74
end_define

begin_comment
comment|/* DWORD 0x1D (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FATAL_ERROR_RDUMP0_LENGTH
value|0x78
end_define

begin_comment
comment|/* DWORD 0x1E (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FATAL_ERROR_RDUMP1_OFFSET
value|0x7C
end_define

begin_comment
comment|/* DWORD 0x1F (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_FATAL_ERROR_RDUMP1_LENGTH
value|0x80
end_define

begin_comment
comment|/* DWORD 0x20 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_HDA_FLAGS_OFFSET
value|0x84
end_define

begin_comment
comment|/* DWORD 0x21 (R) */
end_comment

begin_comment
comment|/* reserved for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_ANALOG_SETUP_OFFSET
value|0x88
end_define

begin_comment
comment|/* DWORD 0x22 (R) */
end_comment

begin_define
define|#
directive|define
name|MAIN_INT_VEC_TABLE_OFFSET
value|0x8C
end_define

begin_comment
comment|/* DWORD 0x23 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_PHY_ATTRIBUTE_OFFSET
value|0x90
end_define

begin_comment
comment|/* DWORD 0x24 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_PRECTD_PRESETD
value|0x94
end_define

begin_comment
comment|/* DWORD 0x25 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_IRAD_RESERVED
value|0x98
end_define

begin_comment
comment|/* DWORD 0x26 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_MOQFOT_MOQFOES
value|0x9C
end_define

begin_comment
comment|/* DWORD 0x27 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_MERRDCTO_MERRDCES
value|0xA0
end_define

begin_comment
comment|/* DWORD 0x28 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_ILAT_ILAV_ILASMRN_ILAMRN_ILAMJN
value|0xA4
end_define

begin_comment
comment|/* DWORD 0x29 (W) */
end_comment

begin_comment
comment|/*  for SPCV */
end_comment

begin_define
define|#
directive|define
name|MAIN_INACTIVE_ILA_REVSION
value|0xA8
end_define

begin_comment
comment|/* DWORD 0x2A (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.02 */
end_comment

begin_define
define|#
directive|define
name|MAIN_SEEPROM_REVSION
value|0xAC
end_define

begin_comment
comment|/* DWORD 0x2B (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.02 */
end_comment

begin_define
define|#
directive|define
name|MAIN_UNKNOWN1
value|0xB0
end_define

begin_comment
comment|/* DWORD 0x2C (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.03 */
end_comment

begin_define
define|#
directive|define
name|MAIN_UNKNOWN2
value|0xB4
end_define

begin_comment
comment|/* DWORD 0x2D (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.03 */
end_comment

begin_define
define|#
directive|define
name|MAIN_UNKNOWN3
value|0xB8
end_define

begin_comment
comment|/* DWORD 0x2E (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.03 */
end_comment

begin_define
define|#
directive|define
name|MAIN_XCBI_REF_TAG_PAT
value|0xBC
end_define

begin_comment
comment|/* DWORD 0x2F (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.03 */
end_comment

begin_define
define|#
directive|define
name|MAIN_AWT_MIDRANGE
value|0xC0
end_define

begin_comment
comment|/* DWORD 0x30 (W) */
end_comment

begin_comment
comment|/*  for SPCV V 3.03 */
end_comment

begin_typedef
typedef|typedef
name|struct
name|spc_configMainDescriptor_s
name|spc_configMainDescriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPC_CONFIG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit to disable end to end crc checking ins SPCv */
end_comment

begin_define
define|#
directive|define
name|MAIN_IO_ABORT_DELAY_END_TO_END_CRC_DISABLE
value|0x00010000
end_define

begin_comment
comment|/* bit mask for field Controller Capability in main part */
end_comment

begin_define
define|#
directive|define
name|MAIN_MAX_IB_MASK
value|0x000000ff
end_define

begin_comment
comment|/* bit7-0 */
end_comment

begin_define
define|#
directive|define
name|MAIN_MAX_OB_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* bit15-8 */
end_comment

begin_define
define|#
directive|define
name|MAIN_PHY_COUNT_MASK
value|0x01f80000
end_define

begin_comment
comment|/* bit24-19 */
end_comment

begin_define
define|#
directive|define
name|MAIN_QSUPPORT_BITS
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|MAIN_SAS_SUPPORT_BITS
value|0xfe000000
end_define

begin_comment
comment|/* bit mask for field max sgl in main part */
end_comment

begin_define
define|#
directive|define
name|MAIN_MAX_SGL_BITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|MAIN_MAX_DEV_BITS
value|0xFFFF0000
end_define

begin_comment
comment|/* bit mask for HDA flags field */
end_comment

begin_define
define|#
directive|define
name|MAIN_HDA_FLAG_BITS
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FATAL_ERROR_INT_BITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|INT_REASRT_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INT_REASRT_MS_ENABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INT_REASRT_DELAY_BITS
value|0xFFF80000
end_define

begin_define
define|#
directive|define
name|MAX_VALID_PHYS
value|8
end_define

begin_define
define|#
directive|define
name|IB_QUEUE_CFGSIZE
value|64
end_define

begin_define
define|#
directive|define
name|OB_QUEUE_CFGSIZE
value|64
end_define

begin_comment
comment|/* inbound queue configuration offset - byte offset */
end_comment

begin_define
define|#
directive|define
name|IB_PROPERITY_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|IB_BASE_ADDR_HI_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|IB_BASE_ADDR_LO_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|IB_CI_BASE_ADDR_HI_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|IB_CI_BASE_ADDR_LO_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|IB_PIPCI_BAR
value|0x14
end_define

begin_define
define|#
directive|define
name|IB_PIPCI_BAR_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|IB_RESERVED_OFFSET
value|0x1C
end_define

begin_comment
comment|/* outbound queue configuration offset - byte offset */
end_comment

begin_define
define|#
directive|define
name|OB_PROPERITY_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|OB_BASE_ADDR_HI_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|OB_BASE_ADDR_LO_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|OB_PI_BASE_ADDR_HI_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|OB_PI_BASE_ADDR_LO_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|OB_CIPCI_BAR
value|0x14
end_define

begin_define
define|#
directive|define
name|OB_CIPCI_BAR_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|OB_INTERRUPT_COALES_OFFSET
value|0x1C
end_define

begin_define
define|#
directive|define
name|OB_DYNAMIC_COALES_OFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|OB_PROPERTY_INT_ENABLE
value|0x40000000
end_define

begin_comment
comment|/* General Status Table offset - byte offset */
end_comment

begin_define
define|#
directive|define
name|GST_GSTLEN_MPIS_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|GST_IQ_FREEZE_STATE0_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|GST_IQ_FREEZE_STATE1_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|GST_MSGUTCNT_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|GST_IOPTCNT_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|GST_IOP1TCNT_OFFSET
value|0x14
end_define

begin_define
define|#
directive|define
name|GST_PHYSTATE_OFFSET
value|0x18
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE0_OFFSET
value|0x18
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE1_OFFSET
value|0x1C
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE2_OFFSET
value|0x20
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE3_OFFSET
value|0x24
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE4_OFFSET
value|0x28
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE5_OFFSET
value|0x2C
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE6_OFFSET
value|0x30
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_PHYSTATE7_OFFSET
value|0x34
end_define

begin_comment
comment|/* SPCV reserved */
end_comment

begin_define
define|#
directive|define
name|GST_GPIO_PINS_OFFSET
value|0x38
end_define

begin_define
define|#
directive|define
name|GST_RERRINFO_OFFSET
value|0x44
end_define

begin_comment
comment|/* General Status Table - MPI state */
end_comment

begin_define
define|#
directive|define
name|GST_MPI_STATE_UNINIT
value|0x00
end_define

begin_define
define|#
directive|define
name|GST_MPI_STATE_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|GST_MPI_STATE_TERMINATION
value|0x02
end_define

begin_define
define|#
directive|define
name|GST_MPI_STATE_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|GST_MPI_STATE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|GST_INF_STATE_BITS
value|0xfffe0007
end_define

begin_comment
comment|/* MPI fatal and non fatal offset mask */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_ERROR_TABLE_OFFSET_MASK
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|MPI_FATAL_ERROR_TABLE_SIZE
parameter_list|(
name|value
parameter_list|)
value|((0xFF000000& value)>> SHIFT24)
end_define

begin_comment
comment|/*  for SPCV */
end_comment

begin_comment
comment|/* MPI fatal and non fatal Error dump capture table offset - byte offset */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_LO_OFFSET
value|0x00
end_define

begin_comment
comment|/* HNFBUFL */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_HI_OFFSET
value|0x04
end_define

begin_comment
comment|/* HNFBUFH */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_LENGTH
value|0x08
end_define

begin_comment
comment|/* HNFBLEN */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_HANDSHAKE
value|0x0C
end_define

begin_comment
comment|/* FDDHSHK */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_STATUS
value|0x10
end_define

begin_comment
comment|/* FDDTSTAT */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_ACCUM_LEN
value|0x14
end_define

begin_comment
comment|/* ACCDDLEN */
end_comment

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_HANDSHAKE_RDY
value|0x1
end_define

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_HANDSHAKE_BUSY
value|0x0
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_STAT_RSVD
value|0x0
end_define

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_STAT_DMA_FAILED
value|0x1
end_define

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_STAT_NF_SUCCESS_MORE_DATA
value|0x2
end_define

begin_define
define|#
directive|define
name|MPI_FATAL_EDUMP_TABLE_STAT_NF_SUCCESS_DONE
value|0x3
end_define

begin_define
define|#
directive|define
name|IOCTL_ERROR_NO_FATAL_ERROR
value|0x77
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spc_GSTableDescriptor_s  *  \brief This structure is used for SPC MPI General Status Table  *  * This structure specifies all required attributes to Gereral Status Table  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|spc_GSTableDescriptor_s
block|{
name|bit32
name|GSTLenMPIS
decl_stmt|;
comment|/**< DW0 - GST Length, MPI State */
comment|/**< bit02-00 MPI state */
comment|/**< 000 - not initialized, 001 - initialized,                                        010 - Configuration termination in progress */
comment|/**< bit3 - IQ Frozen */
comment|/**< bit15-04 GST Length */
comment|/**< bit31-16 MPI-S Initialize Error */
name|bit32
name|IQFreezeState0
decl_stmt|;
comment|/**< DW1 - Inbound Queue Freeze State0 */
name|bit32
name|IQFreezeState1
decl_stmt|;
comment|/**< DW2 - Inbound Qeue Freeze State1 */
name|bit32
name|MsguTcnt
decl_stmt|;
comment|/**< DW3 - MSGU Tick count */
name|bit32
name|IopTcnt
decl_stmt|;
comment|/**< DW4 - IOP Tick count */
name|bit32
name|Iop1Tcnt
decl_stmt|;
comment|/**< DW5 - IOP1 Tick count */
name|bit32
name|PhyState
index|[
name|MAX_VALID_PHYS
index|]
decl_stmt|;
comment|/* SPCV = reserved */
comment|/**< DW6 to DW 0D - Phy Link state 0 to 7, Phy Start State 0 to 7 */
comment|/**< bit00 Phy Start state n, 0 not started, 1 started */
comment|/**< bit01 Phy Link state n, 0 link down, 1 link up */
comment|/**< bit31-2 Reserved */
name|bit32
name|GPIOpins
decl_stmt|;
comment|/**< DWE - GPIO pins */
name|bit32
name|reserved1
decl_stmt|;
comment|/**< DWF - reserved */
name|bit32
name|reserved2
decl_stmt|;
comment|/**< DW10 - reserved */
name|bit32
name|recoverErrInfo
index|[
literal|8
index|]
decl_stmt|;
comment|/**< DW11 to DW18 - Recoverable Error Information */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|spc_GSTableDescriptor_s
name|spc_GSTableDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spc_SPASTable_s  *  \brief SAS Phy Analog Setup Table  *  * The spc_SPASTable_s structure is used to set Phy Calibration  * attributes  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|spc_SPASTable_s
block|{
name|bit32
name|spaReg0
decl_stmt|;
comment|/* transmitter per port configuration 1 SAS_SATA G1 */
name|bit32
name|spaReg1
decl_stmt|;
comment|/* transmitter per port configuration 2 SAS_SATA G1*/
name|bit32
name|spaReg2
decl_stmt|;
comment|/* transmitter per port configuration 3 SAS_SATA G1*/
name|bit32
name|spaReg3
decl_stmt|;
comment|/* transmitter configuration 1 */
name|bit32
name|spaReg4
decl_stmt|;
comment|/* reveiver per port configuration 1 SAS_SATA G1G2 */
name|bit32
name|spaReg5
decl_stmt|;
comment|/* reveiver per port configuration 2 SAS_SATA G3 */
name|bit32
name|spaReg6
decl_stmt|;
comment|/* reveiver per configuration 1 */
name|bit32
name|spaReg7
decl_stmt|;
comment|/* reveiver per configuration 2 */
name|bit32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|spc_SPASTable_s
name|spc_SPASTable_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spc_inboundQueueDescriptor_s  *  \brief This structure is used to configure inbound queues  *  * This structure specifies all required attributes to configure inbound queues  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|spc_inboundQueueDescriptor_s
block|{
name|bit32
name|elementPriSizeCount
decl_stmt|;
comment|/**< Priority, Size, Count in the queue */
comment|/**< bit00-15 Count */
comment|/**< When set to 0, this queue is disabled */
comment|/**< bit16-29 Size */
comment|/**< bit30-31 Priority 00:Normal, 01:High Priority */
name|bit32
name|upperBaseAddress
decl_stmt|;
comment|/**< Upper address bits for the queue message buffer pool */
name|bit32
name|lowerBaseAddress
decl_stmt|;
comment|/**< Lower address bits for the queue message buffer pool */
name|bit32
name|ciUpperBaseAddress
decl_stmt|;
comment|/**< Upper physical address for inbound queue CI */
name|bit32
name|ciLowerBaseAddress
decl_stmt|;
comment|/**< Lower physical address for inbound queue CI */
name|bit32
name|PIPCIBar
decl_stmt|;
comment|/**< PCI BAR for PI Offset */
name|bit32
name|PIOffset
decl_stmt|;
comment|/**< Offset address for inbound queue PI */
name|bit32
name|reserved
decl_stmt|;
comment|/**< reserved */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|spc_inboundQueueDescriptor_s
name|spc_inboundQueueDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spc_outboundQueueDescriptor_s  *  \brief This structure is used to configure outbound queues  *  * This structure specifies all required attributes to configure outbound queues  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|spc_outboundQueueDescriptor_s
block|{
name|bit32
name|elementSizeCount
decl_stmt|;
comment|/**< Size& Count of each element (slot) in the queue) */
comment|/**< bit00-15 Count */
comment|/**< When set to 0, this queue is disabled */
comment|/**< bit16-29 Size */
comment|/**< bit30    Interrupt enable/disable */
comment|/**< bit31    reserved */
name|bit32
name|upperBaseAddress
decl_stmt|;
comment|/**< Upper address bits for the queue message buffer pool */
name|bit32
name|lowerBaseAddress
decl_stmt|;
comment|/**< Lower address bits for the queue message buffer pool */
name|bit32
name|piUpperBaseAddress
decl_stmt|;
comment|/**< PI Upper Base Address for outbound queue */
name|bit32
name|piLowerBaseAddress
decl_stmt|;
comment|/**< PI Lower Base Address for outbound queue */
name|bit32
name|CIPCIBar
decl_stmt|;
comment|/**< PCI BAR for CI Offset */
name|bit32
name|CIOffset
decl_stmt|;
comment|/**< Offset address for outbound queue CI */
name|bit32
name|interruptVecCntDelay
decl_stmt|;
comment|/**< Delay in microseconds before the interrupt is asserted */
comment|/**< if the interrupt threshold has not been reached */
comment|/**< Number of interrupt events before the interrupt is asserted */
comment|/**< If set to 0, interrupts for this queue are disable */
comment|/**< Interrupt vector number for this queue */
comment|/**< Note that the interrupt type can be MSI or MSI-X */
comment|/**< depending on the system configuration */
comment|/**< bit00-15 Delay */
comment|/**< bit16-23 Count */
comment|/**< bit24-31 Vector */
name|bit32
name|DInterruptTOPCIOffset
decl_stmt|;
comment|/**< Dynamic Interrupt Coalescing Timeout PCI Bar Offset */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|spc_outboundQueueDescriptor_s
name|spc_outboundQueueDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|InterruptVT_s
block|{
name|bit32
name|iccict
decl_stmt|;
comment|/**< DW0 - Interrupt Colescing Control and Timer */
name|bit32
name|iraeirad
decl_stmt|;
comment|/**< DW1 - Interrupt Reassertion Enable/Delay */
block|}
name|InterruptVT_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpiInterruptVT_s
block|{
name|InterruptVT_t
name|IntVecTble
index|[
name|MAX_NUM_VECTOR
operator|<<
literal|1
index|]
decl_stmt|;
block|}
name|mpiInterruptVT_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INT_VT_Coal_CNT_TO
value|0
end_define

begin_define
define|#
directive|define
name|INT_VT_Coal_ReAssert_Enab
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|phyAttrb_s
block|{
name|bit32
name|phyState
decl_stmt|;
name|bit32
name|phyEventOQ
decl_stmt|;
block|}
name|phyAttrb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sasPhyAttribute_s
block|{
name|phyAttrb_t
name|phyAttribute
index|[
name|MAX_VALID_PHYS
index|]
decl_stmt|;
block|}
name|sasPhyAttribute_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PHY_STATE
value|0
end_define

begin_define
define|#
directive|define
name|PHY_EVENT_OQ
value|4
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct spcMSGUConfig_s  *  \brief This structure is used to configure controller's message unit  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fwMSGUConfig_s
block|{
name|spc_configMainDescriptor_t
name|mainConfiguration
decl_stmt|;
comment|/**< main part of Configuration Table */
name|spc_GSTableDescriptor_t
name|GeneralStatusTable
decl_stmt|;
comment|/**< MPI general status table */
name|spc_inboundQueueDescriptor_t
name|inboundQueue
index|[
name|IB_QUEUE_CFGSIZE
index|]
decl_stmt|;
comment|/**< Inbound queue configuration array */
name|spc_outboundQueueDescriptor_t
name|outboundQueue
index|[
name|OB_QUEUE_CFGSIZE
index|]
decl_stmt|;
comment|/**< Outbound queue configuration array */
name|agsaPhyAnalogSetupTable_t
name|phyAnalogConfig
decl_stmt|;
name|mpiInterruptVT_t
name|interruptVTable
decl_stmt|;
name|sasPhyAttribute_t
name|phyAttributeTable
decl_stmt|;
block|}
name|fwMSGUConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|EnadDisabHandler_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|interruptVectorIndex
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bit32
function_decl|(
modifier|*
name|InterruptOurs_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|interruptVectorIndex
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SPC_DEFS__ */
end_comment

end_unit

