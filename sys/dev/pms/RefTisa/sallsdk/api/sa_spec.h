begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ******************************************************************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*! \file sa_spec.h  *  \brief The file defines the constants defined by sas spec  */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SA_SPEC_H__
end_ifndef

begin_define
define|#
directive|define
name|__SA_SPEC_H__
end_define

begin_comment
comment|/****************************************************************  *            SAS Specification related defines                 *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|SA_SAS_PROTOCOL_SMP
value|0x00
end_define

begin_define
define|#
directive|define
name|SA_SAS_PROTOCOL_SSP
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_PROTOCOL_STP
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_OPENFRM_SIZE
value|(28)
end_define

begin_define
define|#
directive|define
name|SA_IDENTIFY_FRAME_SIZE
value|(28)
end_define

begin_comment
comment|//#define SAS_IDENTIFY_FRM_SIZE                             SA_IDENTIFY_FRAME_SIZE
end_comment

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SSP_DATA
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SSP_XRDY
value|0x05
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SSP_CMD
value|0x06
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SSP_RSP
value|0x07
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SSP_TASK
value|0x16
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SMP_REQ
value|0x40
end_define

begin_define
define|#
directive|define
name|SA_SAS_FRAME_TYPE_SMP_RSP
value|0x41
end_define

begin_define
define|#
directive|define
name|SA_SAS_CONNECTION_RATE_1_5G
value|0x08
end_define

begin_define
define|#
directive|define
name|SA_SAS_CONNECTION_RATE_3_0G
value|0x09
end_define

begin_define
define|#
directive|define
name|SA_SAS_CONNECTION_RATE_6_0G
value|0x0A
end_define

begin_define
define|#
directive|define
name|SA_SAS_CONNECTION_RATE_12_0G
value|0x0B
end_define

begin_define
define|#
directive|define
name|SA_SAS_DEV_TYPE_NO_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|SA_SAS_DEV_TYPE_END_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_DEV_TYPE_EDGE_EXPANDER
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SAS_DEV_TYPE_FANOUT_EXPANDER
value|0x03
end_define

begin_define
define|#
directive|define
name|AGSA_DEV_TYPE_END_DEVICE
value|(SA_SAS_DEV_TYPE_END_DEVICE<< 4)
end_define

begin_define
define|#
directive|define
name|AGSA_DEV_TYPE_EDGE_EXPANDER
value|(SA_SAS_DEV_TYPE_EDGE_EXPANDER<< 4)
end_define

begin_define
define|#
directive|define
name|AGSA_DEV_TYPE_FAN_EXPANDER
value|(SA_SAS_DEV_TYPE_FANOUT_EXPANDER<< 4)
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_REPORT_GENERAL
value|0x00
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_REPORT_MANUFACTURE_INFORMATION
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_READ_GPIO_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_DISCOVER
value|0x10
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_REPORT_PHY_ERROR_LOG
value|0x11
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_REPORT_PHY_SATA
value|0x12
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_REPORT_ROUTING_INFORMATION
value|0x13
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_WRITE_GPIO_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_CONFIGURE_ROUTING_INFORMATION
value|0x90
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_PHY_CONTROL
value|0x91
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_PHY_TEST
value|0x92
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_FUNCTION_ACCEPTED
value|0x00
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_FUNCTION_UNKNOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_FUNCTION_FAILED
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_INVALID_REQ_FRAME_LENGTH
value|0x03
end_define

begin_define
define|#
directive|define
name|SA_SAS_SMP_PHY_NOT_EXIST
value|0x10
end_define

begin_define
define|#
directive|define
name|SA_SAS_ROUTING_DIRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|SA_SAS_ROUTING_SUBTRACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_ROUTING_TABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_LINK_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_HARD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_DISABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_CLEAR_ERROR_LOG
value|0x05
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_CLEAR_AFFILIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SA_SAS_PHYCTL_TRANSMIT_PS_SIGNAL
value|0x07
end_define

begin_define
define|#
directive|define
name|SA_SSP_CMDIU_LEN_BYTES
value|28
end_define

begin_define
define|#
directive|define
name|SA_SSP_TMIU_LEN_BYTES
value|28
end_define

begin_define
define|#
directive|define
name|SASD_DEV_SATA_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|SASD_DEV_SAS_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SASD_DEV_SAS_END_DEVICE
value|0x01
end_define

begin_comment
comment|/* SAS end device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SAS_EDGE_EXPANDER
value|0x02
end_define

begin_comment
comment|/* SAS edge expander device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SAS_FAN_EXPANDER
value|0x03
end_define

begin_comment
comment|/* SAS fan out expander device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_ATA_DEVICE
value|0x10
end_define

begin_comment
comment|/* SATA ATA device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_ATAPI_DEVICE
value|0x20
end_define

begin_comment
comment|/* SATA ATAPI device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_PM_DEVICE
value|0x30
end_define

begin_comment
comment|/* SATA PM device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_SEMB_DEVICE
value|0x40
end_define

begin_comment
comment|/* SATA SEMB device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_SEMB_WO_SEP_DEVICE
value|0x50
end_define

begin_comment
comment|/* SATA SEMB without SEP device type */
end_comment

begin_define
define|#
directive|define
name|SASD_DEV_SATA_UNKNOWN_DEVICE
value|0xFF
end_define

begin_comment
comment|/* SAS SATA unknown device type */
end_comment

begin_define
define|#
directive|define
name|SASD_TASK_ATTR_SIMPLE
value|0x0
end_define

begin_define
define|#
directive|define
name|SASD_TASK_ATTR_HEAD_OF_QUEUE
value|0x1
end_define

begin_define
define|#
directive|define
name|SASD_TASK_ATTR_ORDERED
value|0x2
end_define

begin_define
define|#
directive|define
name|SASD_TASK_ATTR_ACA
value|0x4
end_define

begin_comment
comment|/***************************************************************************** ** SAS TM Function definitions *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SASD_SAS_ABORT_TASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SASD_SAS_ABORT_TASK_SET
value|0x02
end_define

begin_define
define|#
directive|define
name|SASD_SAS_CLEAR_TASK_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|SASD_SAS_LOGICAL_UNIT_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|SASD_SAS_CLEAR_ACA
value|0x40
end_define

begin_define
define|#
directive|define
name|SASD_SAS_QUARY_TASK
value|0x80
end_define

begin_comment
comment|/****************************************************************  *            SATA Specification related defines                *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|SA_SATA_MAX_QUEUED_COMMANDS
value|32
end_define

begin_define
define|#
directive|define
name|SA_SATA_MAX_PM_PORTS
value|15
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_HOST_2_DEV
value|0x27
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_DEV_2_HOST
value|0x34
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_SET_DEVICE
value|0xA1
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_DMA_ACTIVE
value|0x39
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_FDMA_SETUP
value|0x41
end_define

begin_define
define|#
directive|define
name|SA_SATA_FIS_TYPE_BIST
value|0x58
end_define

begin_define
define|#
directive|define
name|SA_SATA_CMD_IDENTIFY_DEVICE
value|0xEC
end_define

begin_define
define|#
directive|define
name|SA_SATA_CMD_EXEC_DEV_DIAG
value|0x90
end_define

begin_define
define|#
directive|define
name|SA_SATA_CONTROL_SRST
value|0x04
end_define

begin_define
define|#
directive|define
name|SA_SATA_H2DREG_LEN_BYTES
value|20
end_define

begin_define
define|#
directive|define
name|SA_SATA_H2D_BIST_LEN_BYTES
value|12
end_define

begin_comment
comment|/****************************************************************  *            SAS Specification related structures              *  ****************************************************************/
end_comment

begin_comment
comment|/** \brief Structure for SATA BIST FIS  *  * The agsaFisBIST_t data structure describes a SATA FIS (Frame Information Structures)  * for FIS type BIST (Built In Self Test) Activate Bidirectional.  *  * This data structure is one instance of the SATA request structure agsaSATAInitiatorRequest_t,  * which is one instance of the generic request, issued to saSATAStart().  */
end_comment

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_T_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_A_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_S_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_L_BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_F_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_P_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_R_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_SATA_BIST_PATTERN_V_BIT
value|0x01
end_define

begin_comment
comment|/*  * The first SATA DWORD types.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFisBISTHeader_s
block|{
name|bit8
name|fisType
decl_stmt|;
comment|/* fisType, set to 58h for BIST */
name|bit8
name|pmPort
decl_stmt|;
comment|/* b7-b4  reserved */
comment|/* b3-b0  PM Port. device port address that the PM should deliver the FIS to */
name|bit8
name|patternDefinition
decl_stmt|;
comment|/* b7 : T Far end transmit only mode */
comment|/* b6 : A ALIGN Bypass (Do not Transmit Align Primitives) (valid only in combination with T Bit) (optional behavior) */
comment|/* b5 : S Bypass Scrambling (valid only in combination with T Bit) (optional behavior) */
comment|/* b4 : L Far End Retimed Loopback. Transmitter shall insert additional ALIGNS) */
comment|/* b3 : F Far End Analog (AFE) Loopback (Optional) */
comment|/* b2 : P Primitive bit. (valid only in combination with the T Bit) (optional behavior) */
comment|/* b1 : R Reserved */
comment|/* b0 : V Vendor Specific Test Mode. Causes all other bits to be ignored */
name|bit8
name|reserved5
decl_stmt|;
comment|/* Reserved */
block|}
name|agsaFisBISTHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegD2HHeader_s
block|{
name|bit8
name|fisType
decl_stmt|;
comment|/* fisType, set to 34h for DeviceToHostReg */
name|bit8
name|i_pmPort
decl_stmt|;
comment|/* b7     : reserved */
comment|/* b6     : I Interrupt bit */
comment|/* b5-b4  : reserved */
comment|/* b3-b0  : PM Port */
name|bit8
name|status
decl_stmt|;
comment|/* Contains the contents to be placed in the Status(and Alternate status)                        Register of the Shadow Command Block */
name|bit8
name|error
decl_stmt|;
comment|/* Contains the contents to be placed in the Error register of the Shadow Command Block */
block|}
name|agsaFisRegD2HHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisSetDevBitsHeader_s
block|{
name|bit8
name|fisType
decl_stmt|;
comment|/* fisType, set to A1h for SetDeviceBit */
name|bit8
name|n_i_pmPort
decl_stmt|;
comment|/* b7   : n Bit. Notification bit. If set device needs attention. */
comment|/* b6   : i Bit. Interrupt Bit */
comment|/* b5-b4: reserved2 */
comment|/* b3-b0: PM Port */
name|bit8
name|statusHi_Lo
decl_stmt|;
comment|/* b7   : reserved */
comment|/* b6-b4: Status Hi. Contains the contents to be placed in bits 6, 5, and 4 of        the Status register of the Shadow Command Block */
comment|/* b3   : Reserved */
comment|/* b2-b0: Status Lo  Contains the contents to be placed in bits 2,1, and 0 of the        Status register of the Shadow Command Block */
name|bit8
name|error
decl_stmt|;
comment|/* Contains the contents to be placed in the Error register of                          the Shadow Command Block */
block|}
name|agsaFisSetDevBitsHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegH2DHeader_s
block|{
name|bit8
name|fisType
decl_stmt|;
comment|/* fisType, set to 27h for DeviceToHostReg */
name|bit8
name|c_pmPort
decl_stmt|;
comment|/* b7   : C_bit This bit is set to one when the register transfer is        due to an update of the Command register */
comment|/* b6-b4: reserved */
comment|/* b3-b0: PM Port */
name|bit8
name|command
decl_stmt|;
comment|/* Contains the contents of the Command register of                          the Shadow Command Block */
name|bit8
name|features
decl_stmt|;
comment|/* Contains the contents of the Features register of                          the Shadow Command Block */
block|}
name|agsaFisRegH2DHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisPioSetupHeader_s
block|{
name|bit8
name|fisType
decl_stmt|;
comment|/* set to 5F */
name|bit8
name|i_d_pmPort
decl_stmt|;
comment|/* b7   : reserved */
comment|/* b6   : i bit. Interrupt bit */
comment|/* b5   : d bit. data transfer direction. set to 1 for device to host xfer */
comment|/* b4   : reserved */
comment|/* b3-b0: PM Port */
name|bit8
name|status
decl_stmt|;
name|bit8
name|error
decl_stmt|;
block|}
name|agsaFisPioSetupHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|agsaFisHeader_s
block|{
name|agsaFisBISTHeader_t
name|Bist
decl_stmt|;
name|agsaFisRegD2HHeader_t
name|D2H
decl_stmt|;
name|agsaFisRegH2DHeader_t
name|H2D
decl_stmt|;
name|agsaFisSetDevBitsHeader_t
name|SetDevBits
decl_stmt|;
name|agsaFisPioSetupHeader_t
name|PioSetup
decl_stmt|;
block|}
name|agsaFisHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisBISTData_s
block|{
name|bit8
name|data
index|[
literal|8
index|]
decl_stmt|;
comment|/* BIST data */
block|}
name|agsaFisBISTData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisBIST_s
block|{
name|agsaFisBISTHeader_t
name|h
decl_stmt|;
name|agsaFisBISTData_t
name|d
decl_stmt|;
block|}
name|agsaFisBIST_t
typedef|;
end_typedef

begin_comment
comment|/** \brief Structure for SATA Device to Host Register FIS  *  * The agsaFisRegDeviceToHost_t data structure describes a SATA FIS (Frame Information  * Structures) for FIS type Register Device to Host.  *  * This structure is used only as inbound data (device to host) to describe device to  * host response.  */
end_comment

begin_define
define|#
directive|define
name|SA_SATA_RD2H_I_BIT
value|0x40
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegD2HData_s
block|{
name|bit8
name|lbaLow
decl_stmt|;
comment|/* Contains the contents to be placed in the LBA Low register                            of the Shadow Command Block */
name|bit8
name|lbaMid
decl_stmt|;
comment|/* Contains the contents to be placed in the LBA Mid register                            of the Shadow Command Block */
name|bit8
name|lbaHigh
decl_stmt|;
comment|/* Contains the contents to be placed in the LBA High register                            of the Shadow Command Block */
name|bit8
name|device
decl_stmt|;
comment|/* Contains the contents to be placed in the Device register of the Shadow Command Block */
name|bit8
name|lbaLowExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field                            of the Shadow Command Block */
name|bit8
name|lbaMidExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field                            of the Shadow Command Block */
name|bit8
name|lbaHighExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field                            of the Shadow Command Block */
name|bit8
name|reserved4
decl_stmt|;
comment|/** reserved */
name|bit8
name|sectorCount
decl_stmt|;
comment|/* Contains the contents to be placed in the Sector                             Count register of the Shadow Command Block */
name|bit8
name|sectorCountExp
decl_stmt|;
comment|/* Contains the contents of the expanded address                                 field of the Shadow Command Block */
name|bit8
name|reserved6
decl_stmt|;
comment|/* Reserved */
name|bit8
name|reserved5
decl_stmt|;
comment|/* Reserved */
name|bit32
name|reserved7
decl_stmt|;
comment|/* Reserved */
block|}
name|agsaFisRegD2HData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegDeviceToHost_s
block|{
name|agsaFisRegD2HHeader_t
name|h
decl_stmt|;
name|agsaFisRegD2HData_t
name|d
decl_stmt|;
block|}
name|agsaFisRegDeviceToHost_t
typedef|;
end_typedef

begin_comment
comment|/** \brief Structure for SATA Host to Device Register FIS  *  * The agsaFisRegHostToDevice_t data structure describes a SATA FIS  * (Frame Information Structures) for FIS type Register Host to Device.   * This data structure is one instance of the SATA request structure  * agsaSATAInitiatorRequest_t, which is one instance of the generic request,  * issued to saSATAStart().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegH2DData_s
block|{
name|bit8
name|lbaLow
decl_stmt|;
comment|/* Contains the contents of the LBA Low register of the Shadow Command Block */
name|bit8
name|lbaMid
decl_stmt|;
comment|/* Contains the contents of the LBA Mid register of the Shadow Command Block */
name|bit8
name|lbaHigh
decl_stmt|;
comment|/* Contains the contents of the LBA High register of the Shadow Command Block */
name|bit8
name|device
decl_stmt|;
comment|/* Contains the contents of the Device register of the Shadow Command Block */
name|bit8
name|lbaLowExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|lbaMidExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|lbaHighExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|featuresExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|sectorCount
decl_stmt|;
comment|/* Contains the contents of the Sector Count register of the                                Shadow Command Block */
name|bit8
name|sectorCountExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of                                the Shadow Command Block */
name|bit8
name|reserved4
decl_stmt|;
comment|/* Reserved */
name|bit8
name|control
decl_stmt|;
comment|/* Contains the contents of the Device Control register of the                              Shadow Command Block */
name|bit32
name|reserved5
decl_stmt|;
comment|/* Reserved */
block|}
name|agsaFisRegH2DData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisRegHostToDevice_s
block|{
name|agsaFisRegH2DHeader_t
name|h
decl_stmt|;
name|agsaFisRegH2DData_t
name|d
decl_stmt|;
block|}
name|agsaFisRegHostToDevice_t
typedef|;
end_typedef

begin_comment
comment|/** \brief Structure for SATA SetDeviceBit FIS  *  * The agsaFisSetDevBits_t data structure describes a SATA FIS (Frame Information Structures)  * for FIS type Set Device Bits - Device to Host.  *  * This structure is used only as inbound data (device to host) to describe device to host  * response.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFisSetDevBitsData_s
block|{
name|bit32
name|reserved6
decl_stmt|;
comment|/* Reserved */
block|}
name|agsaFisSetDevBitsData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisSetDevBits_s
block|{
name|agsaFisSetDevBitsHeader_t
name|h
decl_stmt|;
name|agsaFisSetDevBitsData_t
name|d
decl_stmt|;
block|}
name|agsaFisSetDevBits_t
typedef|;
end_typedef

begin_comment
comment|/** \brief union data structure specifies a FIS from host software  *  * union data structure specifies a FIS from host software  */
end_comment

begin_typedef
typedef|typedef
union|union
name|agsaSATAHostFis_u
block|{
name|agsaFisRegHostToDevice_t
name|fisRegHostToDev
decl_stmt|;
comment|/* Structure containing the FIS request                                                     for Register - Host to Device */
name|agsaFisBIST_t
name|fisBIST
decl_stmt|;
comment|/* Structure containing the FIS request for BIST */
block|}
name|agsaSATAHostFis_t
typedef|;
end_typedef

begin_comment
comment|/** \brief  *  * This structure is used  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFisPioSetupData_s
block|{
name|bit8
name|lbaLow
decl_stmt|;
comment|/* Contains the contents of the LBA Low register of the Shadow Command Block */
name|bit8
name|lbaMid
decl_stmt|;
comment|/* Contains the contents of the LBA Mid register of the Shadow Command Block */
name|bit8
name|lbaHigh
decl_stmt|;
comment|/* Contains the contents of the LBA High register of the Shadow Command Block */
name|bit8
name|device
decl_stmt|;
comment|/* Contains the contents of the Device register of the Shadow Command Block */
name|bit8
name|lbaLowExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|lbaMidExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|lbaHighExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of the                              Shadow Command Block */
name|bit8
name|reserved1
decl_stmt|;
comment|/* reserved */
name|bit8
name|sectorCount
decl_stmt|;
comment|/* Contains the contents of the Sector Count register of the                                Shadow Command Block */
name|bit8
name|sectorCountExp
decl_stmt|;
comment|/* Contains the contents of the expanded address field of                                the Shadow Command Block */
name|bit8
name|reserved2
decl_stmt|;
comment|/* Reserved */
name|bit8
name|e_status
decl_stmt|;
comment|/* Contains the new value of Status Reg of the Command block                              at the conclusion of the subsequent Data FIS */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved */
name|bit8
name|transferCount
index|[
literal|2
index|]
decl_stmt|;
comment|/* the number of bytes to be xfered in the subsequent Data FiS */
block|}
name|agsaFisPioSetupData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFisPioSetup_s
block|{
name|agsaFisPioSetupHeader_t
name|h
decl_stmt|;
name|agsaFisPioSetupData_t
name|d
decl_stmt|;
block|}
name|agsaFisPioSetup_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe SAS IDENTIFY address frame  *  * describe SAS IDENTIFY address frame, the CRC field is not included in the structure  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASIdentify_s
block|{
name|bit8
name|deviceType_addressFrameType
decl_stmt|;
comment|/* b7   : reserved */
comment|/* b6-4 : device type */
comment|/* b3-0 : address frame type */
name|bit8
name|reason
decl_stmt|;
comment|/* reserved */
comment|/* b7-4 : reserved */
comment|/* b3-0 : reason SAS2 */
name|bit8
name|initiator_ssp_stp_smp
decl_stmt|;
comment|/* b8-4 : reserved */
comment|/* b3   : SSP initiator port */
comment|/* b2   : STP initiator port */
comment|/* b1   : SMP initiator port */
comment|/* b0   : reserved */
name|bit8
name|target_ssp_stp_smp
decl_stmt|;
comment|/* b8-4 : reserved */
comment|/* b3   : SSP target port */
comment|/* b2   : STP target port */
comment|/* b1   : SMP target port */
comment|/* b0   : reserved */
name|bit8
name|deviceName
index|[
literal|8
index|]
decl_stmt|;
comment|/* reserved */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* BE SAS address Lo */
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* BE SAS address Hi */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* phy identifier of the phy transmitting the IDENTIFY address frame */
name|bit8
name|zpsds_breakReplyCap
decl_stmt|;
comment|/* b7-3 : reserved */
comment|/* b2   : Inside ZPSDS Persistent */
comment|/* b1   : Requested Inside ZPSDS */
comment|/* b0   : Break Reply Capable */
name|bit8
name|reserved3
index|[
literal|6
index|]
decl_stmt|;
comment|/* reserved */
block|}
name|agsaSASIdentify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_IDFRM_GET_SAS_ADDRESSLO
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(identFrame)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_GET_SAS_ADDRESSHI
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(identFrame)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_GET_DEVICETTYPE
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->deviceType_addressFrameType& 0x70)>> 4)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_PUT_SAS_ADDRESSLO
parameter_list|(
name|identFrame
parameter_list|,
name|src32
parameter_list|)
define|\
value|((*(bit32 *)((identFrame)->sasAddressLo)) = BIT32_TO_DMA_BEBIT32(src32))
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_PUT_SAS_ADDRESSHI
parameter_list|(
name|identFrame
parameter_list|,
name|src32
parameter_list|)
define|\
value|((*(bit32 *)((identFrame)->sasAddressHi)) = BIT32_TO_DMA_BEBIT32(src32))
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_SSP_BIT
value|0x8
end_define

begin_comment
comment|/* SSP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_IDFRM_STP_BIT
value|0x4
end_define

begin_comment
comment|/* STP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_IDFRM_SMP_BIT
value|0x2
end_define

begin_comment
comment|/* SMP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_IDFRM_SATA_BIT
value|0x1
end_define

begin_comment
comment|/* SATA device, valid in the discovery response only */
end_comment

begin_define
define|#
directive|define
name|SA_IDFRM_IS_SSP_INITIATOR
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->initiator_ssp_stp_smp& SA_IDFRM_SSP_BIT) == SA_IDFRM_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_STP_INITIATOR
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->initiator_ssp_stp_smp& SA_IDFRM_STP_BIT) == SA_IDFRM_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_SMP_INITIATOR
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->initiator_ssp_stp_smp& SA_IDFRM_SMP_BIT) == SA_IDFRM_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_SSP_TARGET
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->target_ssp_stp_smp& SA_IDFRM_SSP_BIT) == SA_IDFRM_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_STP_TARGET
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->target_ssp_stp_smp& SA_IDFRM_STP_BIT) == SA_IDFRM_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_SMP_TARGET
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->target_ssp_stp_smp& SA_IDFRM_SMP_BIT) == SA_IDFRM_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_IDFRM_IS_SATA_DEVICE
parameter_list|(
name|identFrame
parameter_list|)
define|\
value|(((identFrame)->target_ssp_stp_smp& SA_IDFRM_SATA_BIT) == SA_IDFRM_SATA_BIT)
end_define

begin_comment
comment|/** \brief data structure provides the identify data of the SATA device  *  * data structure provides the identify data of the SATA device  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAIdentifyData_s
block|{
name|bit16
name|rm_ataDevice
decl_stmt|;
comment|/* b15-b9 :  */
comment|/* b8     :  ataDevice */
comment|/* b7-b1  : */
comment|/* b0     :  removableMedia */
name|bit16
name|word1_9
index|[
literal|9
index|]
decl_stmt|;
comment|/**< word 1 to 9 of identify device information */
name|bit8
name|serialNumber
index|[
literal|20
index|]
decl_stmt|;
comment|/**< word 10 to 19 of identify device information, 20 ASCII chars */
name|bit16
name|word20_22
index|[
literal|3
index|]
decl_stmt|;
comment|/**< word 20 to 22 of identify device information */
name|bit8
name|firmwareVersion
index|[
literal|8
index|]
decl_stmt|;
comment|/**< word 23 to 26 of identify device information, 4 ASCII chars */
name|bit8
name|modelNumber
index|[
literal|40
index|]
decl_stmt|;
comment|/**< word 27 to 46 of identify device information, 40 ASCII chars */
name|bit16
name|word47_48
index|[
literal|2
index|]
decl_stmt|;
comment|/**< word 47 to 48 of identify device information, 40 ASCII chars */
name|bit16
name|dma_lba_iod_ios_stimer
decl_stmt|;
comment|/* b15-b14:word49_bit14_15 */
comment|/* b13    : standbyTimerSupported */
comment|/* b12    : word49_bit12 */
comment|/* b11    : IORDYSupported */
comment|/* b10     : IORDYDisabled */
comment|/* b9     : lbaSupported */
comment|/* b8     : dmaSupported */
comment|/* b7-b0  : retired */
name|bit16
name|word50_52
index|[
literal|3
index|]
decl_stmt|;
comment|/**< word 50 to 52 of identify device information, 40 ASCII chars */
name|bit16
name|valid_w88_w70
decl_stmt|;
comment|/* b15-3  : word53_bit3_15 */
comment|/* b2     : validWord88  */
comment|/* b1     : validWord70_64  */
comment|/* b0     : word53_bit0  */
name|bit16
name|word54_59
index|[
literal|6
index|]
decl_stmt|;
comment|/**< word54-59 of identify device information  */
name|bit16
name|numOfUserAddressableSectorsLo
decl_stmt|;
comment|/**< word60 of identify device information  */
name|bit16
name|numOfUserAddressableSectorsHi
decl_stmt|;
comment|/**< word61 of identify device information  */
name|bit16
name|word62_74
index|[
literal|13
index|]
decl_stmt|;
comment|/**< word62-74 of identify device information  */
name|bit16
name|queueDepth
decl_stmt|;
comment|/* b15-5  : word75_bit5_15 */
comment|/* b4-0   : queueDepth */
name|bit16
name|sataCapabilities
decl_stmt|;
comment|/* b15-b11: word76_bit11_15  */
comment|/* b10    : phyEventCountersSupport */
comment|/* b9     : hostInitPowerMangment */
comment|/* b8     : nativeCommandQueuing */
comment|/* b7-b3  : word76_bit4_7 */
comment|/* b2     : sataGen2Supported (3.0 Gbps) */
comment|/* b1     : sataGen1Supported (1.5 Gbps) */
comment|/* b0      :word76_bit0 */
name|bit16
name|word77
decl_stmt|;
comment|/**< word77 of identify device information */
comment|/* b15-b6 : word77 bit6_15, Reserved */
comment|/* b5     : DMA Setup Auto-Activate support */
comment|/* b4     : NCQ streaming support */
comment|/* b3-b1  : coded value indicating current negotiated SATA signal speed */
comment|/* b0     : shall be zero */
name|bit16
name|sataFeaturesSupported
decl_stmt|;
comment|/* b15-b7 : word78_bit7_15 */
comment|/* b6     : softSettingPreserveSupported */
comment|/* b5     : word78_bit5 */
comment|/* b4     : inOrderDataDeliverySupported */
comment|/* b3     : devInitPowerManagementSupported */
comment|/* b2     : autoActiveDMASupported */
comment|/* b1     : nonZeroBufOffsetSupported */
comment|/* b0     : word78_bit0  */
name|bit16
name|sataFeaturesEnabled
decl_stmt|;
comment|/* b15-7  : word79_bit7_15  */
comment|/* b6     : softSettingPreserveEnabled */
comment|/* b5     : word79_bit5  */
comment|/* b4     : inOrderDataDeliveryEnabled */
comment|/* b3     : devInitPowerManagementEnabled */
comment|/* b2     : autoActiveDMAEnabled */
comment|/* b1     : nonZeroBufOffsetEnabled */
comment|/* b0     : word79_bit0 */
name|bit16
name|majorVersionNumber
decl_stmt|;
comment|/* b15    : word80_bit15 */
comment|/* b14    : supportATA_ATAPI14 */
comment|/* b13    : supportATA_ATAPI13 */
comment|/* b12    : supportATA_ATAPI12 */
comment|/* b11    : supportATA_ATAPI11 */
comment|/* b10    : supportATA_ATAPI10 */
comment|/* b9     : supportATA_ATAPI9  */
comment|/* b8     : supportATA_ATAPI8  */
comment|/* b7     : supportATA_ATAPI7  */
comment|/* b6     : supportATA_ATAPI6  */
comment|/* b5     : supportATA_ATAPI5  */
comment|/* b4     : supportATA_ATAPI4 */
comment|/* b3     : supportATA3 */
comment|/* b2-0   : word80_bit0_2 */
name|bit16
name|minorVersionNumber
decl_stmt|;
comment|/**< word81 of identify device information */
name|bit16
name|commandSetSupported
decl_stmt|;
comment|/* b15    : word82_bit15 */
comment|/* b14    : NOPSupported */
comment|/* b13    : READ_BUFFERSupported */
comment|/* b12    : WRITE_BUFFERSupported */
comment|/* b11    : word82_bit11 */
comment|/* b10    : hostProtectedAreaSupported */
comment|/* b9     : DEVICE_RESETSupported */
comment|/* b8     : SERVICEInterruptSupported */
comment|/* b7     : releaseInterruptSupported */
comment|/* b6     : lookAheadSupported */
comment|/* b5     : writeCacheSupported */
comment|/* b4     : word82_bit4 */
comment|/* b3     : mandPowerManagmentSupported */
comment|/* b2     : removableMediaSupported */
comment|/* b1     : securityModeSupported */
comment|/* b0     : SMARTSupported */
name|bit16
name|commandSetSupported1
decl_stmt|;
comment|/* b15-b14: word83_bit14_15  */
comment|/* b13    : FLUSH_CACHE_EXTSupported  */
comment|/* b12    : mandatoryFLUSH_CACHESupported */
comment|/* b11    : devConfOverlaySupported */
comment|/* b10    : address48BitsSupported */
comment|/* b9     : autoAcousticManageSupported */
comment|/* b8     : SET_MAX_SecurityExtSupported */
comment|/* b7     : word83_bit7 */
comment|/* b6     : SET_FEATUREReqSpinupSupported */
comment|/* b5     : powerUpInStandyBySupported */
comment|/* b4     : removableMediaStNotifSupported */
comment|/* b3     : advanPowerManagmentSupported */
comment|/* b2     : CFASupported */
comment|/* b1     : DMAQueuedSupported */
comment|/* b0     : DOWNLOAD_MICROCODESupported */
name|bit16
name|commandSetFeatureSupportedExt
decl_stmt|;
comment|/* b15-b13: word84_bit13_15 */
comment|/* b12    : timeLimitRWContSupported */
comment|/* b11    : timeLimitRWSupported */
comment|/* b10    : writeURGBitSupported */
comment|/* b9     : readURGBitSupported */
comment|/* b8     : wwwNameSupported */
comment|/* b7     : WRITE_DMAQ_FUA_EXTSupported */
comment|/* b6     : WRITE_FUA_EXTSupported */
comment|/* b5     : generalPurposeLogSupported */
comment|/* b4     : streamingSupported  */
comment|/* b3     : mediaCardPassThroughSupported */
comment|/* b2     : mediaSerialNoSupported */
comment|/* b1     : SMARTSelfRestSupported */
comment|/* b0     : SMARTErrorLogSupported */
name|bit16
name|commandSetFeatureEnabled
decl_stmt|;
comment|/* b15    : word85_bit15 */
comment|/* b14    : NOPEnabled */
comment|/* b13    : READ_BUFFEREnabled  */
comment|/* b12    : WRITE_BUFFEREnabled */
comment|/* b11    : word85_bit11 */
comment|/* b10    : hostProtectedAreaEnabled  */
comment|/* b9     : DEVICE_RESETEnabled */
comment|/* b8     : SERVICEInterruptEnabled */
comment|/* b7     : releaseInterruptEnabled */
comment|/* b6     : lookAheadEnabled */
comment|/* b5     : writeCacheEnabled */
comment|/* b4     : word85_bit4 */
comment|/* b3     : mandPowerManagmentEnabled */
comment|/* b2     : removableMediaEnabled */
comment|/* b1     : securityModeEnabled */
comment|/* b0     : SMARTEnabled */
name|bit16
name|commandSetFeatureEnabled1
decl_stmt|;
comment|/* b15-b14: word86_bit14_15 */
comment|/* b13    : FLUSH_CACHE_EXTEnabled */
comment|/* b12    : mandatoryFLUSH_CACHEEnabled */
comment|/* b11    : devConfOverlayEnabled */
comment|/* b10    : address48BitsEnabled */
comment|/* b9     : autoAcousticManageEnabled */
comment|/* b8     : SET_MAX_SecurityExtEnabled */
comment|/* b7     : word86_bit7 */
comment|/* b6     : SET_FEATUREReqSpinupEnabled */
comment|/* b5     : powerUpInStandyByEnabled  */
comment|/* b4     : removableMediaStNotifEnabled */
comment|/* b3     : advanPowerManagmentEnabled */
comment|/* b2     : CFAEnabled */
comment|/* b1     : DMAQueuedEnabled */
comment|/* b0     : DOWNLOAD_MICROCODEEnabled */
name|bit16
name|commandSetFeatureDefault
decl_stmt|;
comment|/* b15-b13: word87_bit13_15 */
comment|/* b12    : timeLimitRWContEnabled */
comment|/* b11    : timeLimitRWEnabled */
comment|/* b10    : writeURGBitEnabled */
comment|/* b9     : readURGBitEnabled */
comment|/* b8     : wwwNameEnabled */
comment|/* b7     : WRITE_DMAQ_FUA_EXTEnabled */
comment|/* b6     : WRITE_FUA_EXTEnabled */
comment|/* b5     : generalPurposeLogEnabled */
comment|/* b4     : streamingEnabled */
comment|/* b3     : mediaCardPassThroughEnabled */
comment|/* b2     : mediaSerialNoEnabled */
comment|/* b1     : SMARTSelfRestEnabled */
comment|/* b0     : SMARTErrorLogEnabled */
name|bit16
name|ultraDMAModes
decl_stmt|;
comment|/* b15    : word88_bit15 */
comment|/* b14    : ultraDMAMode6Selected */
comment|/* b13    : ultraDMAMode5Selected */
comment|/* b12    : ultraDMAMode4Selected */
comment|/* b11    : ultraDMAMode3Selected */
comment|/* b10    : ultraDMAMode2Selected */
comment|/* b9     : ultraDMAMode1Selected */
comment|/* b8     : ultraDMAMode0Selected */
comment|/* b7     : word88_bit7  */
comment|/* b6     : ultraDMAMode6Supported */
comment|/* b5     : ultraDMAMode5Supported */
comment|/* b4     : ultraDMAMode4Supported */
comment|/* b3     : ultraDMAMode3Supported */
comment|/* b2     : ultraDMAMode2Supported */
comment|/* b1     : ultraDMAMode1Supported */
comment|/* b0     : ultraDMAMode0Supported */
name|bit16
name|timeToSecurityErase
decl_stmt|;
name|bit16
name|timeToEnhhancedSecurityErase
decl_stmt|;
name|bit16
name|currentAPMValue
decl_stmt|;
name|bit16
name|masterPasswordRevCode
decl_stmt|;
name|bit16
name|hardwareResetResult
decl_stmt|;
comment|/* b15-b14: word93_bit15_14 */
comment|/* b13    : deviceDetectedCBLIBbelow Vil */
comment|/* b12-b8 : device1 HardwareResetResult */
comment|/* b7-b0  : device0 HardwareResetResult */
name|bit16
name|currentAutoAccousticManagementValue
decl_stmt|;
comment|/* b15-b8 : Vendor recommended value */
comment|/* b7-b0  : current value */
name|bit16
name|word95_99
index|[
literal|5
index|]
decl_stmt|;
comment|/**< word85-99 of identify device information  */
name|bit16
name|maxLBA0_15
decl_stmt|;
comment|/**< word100 of identify device information  */
name|bit16
name|maxLBA16_31
decl_stmt|;
comment|/**< word101 of identify device information  */
name|bit16
name|maxLBA32_47
decl_stmt|;
comment|/**< word102 of identify device information  */
name|bit16
name|maxLBA48_63
decl_stmt|;
comment|/**< word103 of identify device information  */
name|bit16
name|word104_107
index|[
literal|4
index|]
decl_stmt|;
comment|/**< word104-107 of identify device information  */
name|bit16
name|namingAuthority
decl_stmt|;
comment|/* b15-b12: NAA_bit0_3  */
comment|/* b11-b0 : IEEE_OUI_bit12_23*/
name|bit16
name|namingAuthority1
decl_stmt|;
comment|/* b15-b4 : IEEE_OUI_bit0_11 */
comment|/* b3-b0  : uniqueID_bit32_35 */
name|bit16
name|uniqueID_bit16_31
decl_stmt|;
comment|/**< word110 of identify device information  */
name|bit16
name|uniqueID_bit0_15
decl_stmt|;
comment|/**< word111 of identify device information  */
name|bit16
name|word112_126
index|[
literal|15
index|]
decl_stmt|;
name|bit16
name|removableMediaStatusNotificationFeature
decl_stmt|;
comment|/* b15-b2 : word127_b16_2 */
comment|/* b1-b0  : supported set see ATAPI6 spec */
name|bit16
name|securityStatus
decl_stmt|;
comment|/* b15-b9 : word128_b15_9 */
comment|/* b8     : securityLevel */
comment|/* b7-b6  : word128_b7_6 */
comment|/* b5     : enhancedSecurityEraseSupported */
comment|/* b4     : securityCountExpired */
comment|/* b3     : securityFrozen */
comment|/* b2     : securityLocked */
comment|/* b1     : securityEnabled */
comment|/* b0     : securitySupported */
name|bit16
name|vendorSpecific
index|[
literal|31
index|]
decl_stmt|;
name|bit16
name|cfaPowerMode1
decl_stmt|;
comment|/* b15    : word 160 supported */
comment|/* b14    : word160_b14 */
comment|/* b13    : cfaPowerRequired */
comment|/* b12    : cfaPowerModeDisabled */
comment|/* b11-b0 : maxCurrentInMa */
name|bit16
name|word161_175
index|[
literal|15
index|]
decl_stmt|;
name|bit16
name|currentMediaSerialNumber
index|[
literal|30
index|]
decl_stmt|;
name|bit16
name|word206_254
index|[
literal|49
index|]
decl_stmt|;
comment|/**< word206-254 of identify device information  */
name|bit16
name|integrityWord
decl_stmt|;
comment|/* b15-b8 : cheksum */
comment|/* b7-b0  : signature */
block|}
name|agsaSATAIdentifyData_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes an SSP Command INFORMATION UNIT  *  * data structure describes an SSP Command INFORMATION UNIT used for SSP command and is part of  * the SSP frame.  *  * Currently, only CDB up to 16 bytes is supported. Additional CDB length is supported to 0 bytes..  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPCmdInfoUnit_s
block|{
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
comment|/* SCSI Logical Unit Number */
name|bit8
name|reserved1
decl_stmt|;
comment|/* reserved */
name|bit8
name|efb_tp_taskAttribute
decl_stmt|;
comment|/* B7   : enabledFirstBurst */
comment|/* B6-3 : taskPriority */
comment|/* B2-0 : taskAttribute */
name|bit8
name|reserved2
decl_stmt|;
comment|/* reserved */
name|bit8
name|additionalCdbLen
decl_stmt|;
comment|/* B7-2 : additionalCdbLen */
comment|/* B1-0 : reserved */
name|bit8
name|cdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* The SCSI CDB up to 16 bytes length */
block|}
name|agsaSSPCmdInfoUnit_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_SSPCMD_GET_TASKATTRIB
parameter_list|(
name|pCmd
parameter_list|)
value|((pCmd)->efb_tp_taskAttribute& 0x7)
end_define

begin_comment
comment|/** \brief structure describes an SSP Response INFORMATION UNIT  *  * data structure describes an SSP Response INFORMATION UNIT used for SSP response to Command IU  * or Task IU and is part of the SSP frame  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPResponseInfoUnit_s
block|{
name|bit8
name|reserved1
index|[
literal|10
index|]
decl_stmt|;
comment|/* reserved */
name|bit8
name|dataPres
decl_stmt|;
comment|/* which data is present */
comment|/* B7-2 : reserved */
comment|/* B1-0 : data Present */
name|bit8
name|status
decl_stmt|;
comment|/* SCSI status as define by SAM-3 */
name|bit8
name|reserved4
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved */
name|bit8
name|senseDataLen
index|[
literal|4
index|]
decl_stmt|;
comment|/* SCSI Sense Data length */
name|bit8
name|responsedataLen
index|[
literal|4
index|]
decl_stmt|;
comment|/* Response data length */
comment|/* Follow by Response Data if any */
comment|/* Follow by Sense Data if any */
block|}
name|agsaSSPResponseInfoUnit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPFrameFormat_s
block|{
name|bit8
name|frameType
decl_stmt|;
comment|/* frame type */
name|bit8
name|hdsa
index|[
literal|3
index|]
decl_stmt|;
comment|/* Hashed destination SAS Address */
name|bit8
name|reserved1
decl_stmt|;
name|bit8
name|hssa
index|[
literal|3
index|]
decl_stmt|;
comment|/* Hashed source SAS Address */
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
name|bit8
name|tlr_rdf
decl_stmt|;
comment|/* B7-5 : reserved */
comment|/* B4-3 : TLR control*/
comment|/* B2   : Retry Data Frames */
comment|/* B1   : Retransmit */
comment|/* B0   : Changing Data Pointer */
name|bit8
name|fill_bytes
decl_stmt|;
comment|/* B7-2 : reserved */
comment|/* B1-0 : Number of Fill bytes*/
name|bit8
name|reserved5
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|tag
index|[
literal|2
index|]
decl_stmt|;
comment|/* CMD or TM tag */
name|bit8
name|tptt
index|[
literal|2
index|]
decl_stmt|;
comment|/* target port transfer tag */
name|bit8
name|dataOffset
index|[
literal|4
index|]
decl_stmt|;
comment|/* data offset */
comment|/* Follow by IU  */
block|}
name|agsaSSPFrameFormat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPOpenFrame_s
block|{
name|bit8
name|frameType
decl_stmt|;
comment|/* frame type */
comment|/* B7   : Initiator Port */
comment|/* B6-4 : Protocol */
comment|/* B3-0 : Address Frame Type */
name|bit8
name|feat_connrate
decl_stmt|;
comment|/* B7-4 : features */
comment|/* B3-0 : connection rate */
name|bit8
name|initiatorConnTag
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initiator connection tag */
name|bit8
name|dstSasAddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Destination SAS Address */
name|bit8
name|srcSasAddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Source SAS Address */
name|bit8
name|zoneSrcGroup
decl_stmt|;
comment|/* Zone source group */
name|bit8
name|pathwayBlockCount
decl_stmt|;
comment|/* pathway block count */
name|bit8
name|arbWaitTime
index|[
literal|2
index|]
decl_stmt|;
comment|/* Arbitration Wait Time */
name|bit8
name|moreCompatFeat
index|[
literal|4
index|]
decl_stmt|;
comment|/* More Compatibility Features */
comment|/* Follow by CRC  */
block|}
name|agsaSSPOpenFrame_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_SSPRESP_GET_SENSEDATALEN
parameter_list|(
name|pSSPResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32*)(pSSPResp)->senseDataLen)
end_define

begin_define
define|#
directive|define
name|SA_SSPRESP_GET_RESPONSEDATALEN
parameter_list|(
name|pSSPResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32*)(pSSPResp)->responsedataLen)
end_define

begin_define
define|#
directive|define
name|SA_SSPRESP_GET_DATAPRES
parameter_list|(
name|pSSPResp
parameter_list|)
value|((pSSPResp)->dataPres& 0x3)
end_define

begin_comment
comment|/** \brief structure describes a SAS SSP Task Management command request  *  * The agsaSSPScsiTaskMgntReq_t data structure describes a SAS SSP Task Management command request sent by the  * initiator or received by the target.  *  * The response to Task Management is specified by agsaSSPResponseInfoUnit_t.  *  * This data structure is one instance of the generic request issued to saSSPStart() and is passed  * as an agsaSASRequestBody_t  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPScsiTaskMgntReq_s
block|{
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
comment|/* SCSI Logical Unit Number */
name|bit16
name|reserved1
decl_stmt|;
comment|/* reserved */
name|bit8
name|taskMgntFunction
decl_stmt|;
comment|/* task management function code */
name|bit8
name|reserved2
decl_stmt|;
comment|/* reserved */
name|bit16
name|tagOfTaskToBeManaged
decl_stmt|;
comment|/* Tag/context of task to be managed */
name|bit16
name|reserved3
decl_stmt|;
comment|/* reserved */
name|bit32
name|reserved4
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved */
name|bit32
name|tmOption
decl_stmt|;
comment|/* Not part of SSP TMF IU */
comment|/* B7-2 : reserved */
comment|/* B1   : DS_OPTION */
comment|/* B0   : ADS_OPTION */
block|}
name|agsaSSPScsiTaskMgntReq_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes the first four bytes of the SMP frame.  *  * The agsaSMPFrameHeader_t data structure describes the first four bytes of the SMP frame.  *  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPFrameHeader_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* The first byte of SMP frame represents the SMP FRAME TYPE */
name|bit8
name|smpFunction
decl_stmt|;
comment|/* The second byte of the SMP frame represents the SMP FUNCTION */
name|bit8
name|smpFunctionResult
decl_stmt|;
comment|/* The third byte of SMP frame represents FUNCTION RESULT of the SMP response. */
name|bit8
name|smpReserved
decl_stmt|;
comment|/* reserved */
block|}
name|agsaSMPFrameHeader_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report general response  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|SA_REPORT_GENERAL_CONFIGURING_BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|SA_REPORT_GENERAL_CONFIGURABLE_BIT
value|0x1
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpRespReportGeneral_s
block|{
name|bit8
name|expanderChangeCount16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndexes16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved1
decl_stmt|;
name|bit8
name|numOfPhys
decl_stmt|;
name|bit8
name|configuring_configurable
decl_stmt|;
comment|/* B7-2 : reserved */
comment|/* B1   : configuring */
comment|/* B0   : configurable */
name|bit8
name|reserved4
index|[
literal|17
index|]
decl_stmt|;
block|}
name|agsaSmpRespReportGeneral_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_REPORT_GENERAL_IS_CONFIGURING
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& SA_REPORT_GENERAL_CONFIGURING_BIT) == \       SA_REPORT_GENERAL_CONFIGURING_BIT)
end_define

begin_define
define|#
directive|define
name|SA_REPORT_GENERAL_IS_CONFIGURABLE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& SA_REPORT_GENERAL_CONFIGURABLE_BIT) == \       SA_REPORT_GENERAL_CONFIGURABLE_BIT)
end_define

begin_define
define|#
directive|define
name|SA_REPORT_GENERAL_GET_ROUTEINDEXES
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT16_TO_BIT16(*(bit16 *)((pResp)->expanderRouteIndexes16))
end_define

begin_comment
comment|/****************************************************************  *            report manufacturer info response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpRespReportManufactureInfo_s
block|{
name|bit8
name|reserved1
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|vendorIdentification
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|productIdentification
index|[
literal|16
index|]
decl_stmt|;
name|bit8
name|productRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|20
index|]
decl_stmt|;
block|}
name|agsaSmpRespReportManufactureInfo_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpReqDiscover_s
block|{
name|bit32
name|reserved1
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|ignored
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
block|}
name|agsaSmpReqDiscover_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpRespDiscover_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|attachedDeviceType
decl_stmt|;
comment|/* B7   : reserved */
comment|/* B6-4 : attachedDeviceType */
comment|/* B3-0 : reserved */
name|bit8
name|negotiatedPhyLinkRate
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3-0 : negotiatedPhyLinkRate */
name|bit8
name|attached_Ssp_Stp_Smp_Sata_Initiator
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3   : attachedSspInitiator */
comment|/* B2   : attachedStpInitiator */
comment|/* B1   : attachedSmpInitiator */
comment|/* B0   : attachedSataHost */
name|bit8
name|attached_SataPS_Ssp_Stp_Smp_Sata_Target
decl_stmt|;
comment|/* B7   : attachedSataPortSelector */
comment|/* B6-4 : reserved */
comment|/* B3   : attachedSspTarget */
comment|/* B2   : attachedStpTarget */
comment|/* B1   : attachedSmpTarget */
comment|/* B0   : attachedSatadevice */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedPhyIdentifier
decl_stmt|;
name|bit8
name|reserved9
index|[
literal|7
index|]
decl_stmt|;
name|bit8
name|programmedAndHardware_MinPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMinPhyLinkRate */
comment|/* B3-0 : hardwareMinPhyLinkRate */
name|bit8
name|programmedAndHardware_MaxPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMaxPhyLinkRate */
comment|/* B3-0 : hardwareMaxPhyLinkRate */
name|bit8
name|phyChangeCount
decl_stmt|;
name|bit8
name|virtualPhy_partialPathwayTimeout
decl_stmt|;
comment|/* B7   : virtualPhy*/
comment|/* B6-4 : reserved */
comment|/* B3-0 : partialPathwayTimeout */
name|bit8
name|routingAttribute
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3-0 : routingAttribute */
name|bit8
name|reserved13
index|[
literal|5
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|2
index|]
decl_stmt|;
block|}
name|agsaSmpRespDiscover_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_DISCRSP_SSP_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_STP_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_SMP_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_SATA_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_SATA_PS_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_ATTACHED_DEVTYPE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attachedDeviceType& 0x70)>> 4)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_LINKRATE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->negotiatedPhyLinkRate& 0x0F)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SSP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& SA_DISCRSP_SSP_BIT) == SA_DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_STP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& SA_DISCRSP_STP_BIT) == SA_DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SMP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& SA_DISCRSP_SMP_BIT) == SA_DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SATA_HOST
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& SA_DISCRSP_SATA_BIT) == SA_DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SSP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& SA_DISCRSP_SSP_BIT) == SA_DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_STP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& SA_DISCRSP_STP_BIT) == SA_DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SMP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& SA_DISCRSP_SMP_BIT) == SA_DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SATA_DEVICE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& SA_DISCRSP_SATA_BIT) == SA_DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_SATA_PORTSELECTOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& SA_DISCRSP_SATA_PS_BIT) == SA_DISCRSP_SATA_PS_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_ATTACHED_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressHi)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_ATTACHED_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressLo)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_VIRTUALPHY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_IS_VIRTUALPHY
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->virtualPhy_partialPathwayTimeout& SA_DISCRSP_VIRTUALPHY_BIT) == SA_DISCRSP_VIRTUALPHY_BIT)
end_define

begin_define
define|#
directive|define
name|SA_DISCRSP_GET_ROUTINGATTRIB
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->routingAttribute& 0x0F)
end_define

begin_comment
comment|/****************************************************************  *            report route table request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpReqReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|agsaSmpReqReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report route response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpRespReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabled
decl_stmt|;
comment|/* B7   : expander route entry disabled */
comment|/* B6-0 : reserved */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|agsaSmpRespReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route information request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpReqConfigureRouteInformation_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabledBit_reserved4
decl_stmt|;
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|agsaSmpReqConfigureRouteInformation_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report Phy Sata request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpReqReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|agsaSmpReqReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report Phy Sata response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpRespReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
name|bit8
name|affiliations_sup_valid
decl_stmt|;
comment|/* b7-2 : reserved */
comment|/* b1   : Affiliations supported */
comment|/* b0   : Affiliation valid */
name|bit8
name|reserved5
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|regDevToHostFis
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
block|}
name|agsaSmpRespReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSmpReqPhyControl_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|phyOperation
decl_stmt|;
name|bit8
name|updatePartialPathwayTOValue
decl_stmt|;
comment|/* b7-1 : reserved */
comment|/* b0   : update partial pathway timeout value */
name|bit8
name|reserved3
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|programmedMinPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Minimum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|programmedMaxPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Maximum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|partialPathwayTOValue
decl_stmt|;
comment|/* b7-4 : reserved */
comment|/* b3-0 : partial Pathway TO Value */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
block|}
name|agsaSmpReqPhyControl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SASPEC_H__ */
end_comment

end_unit

