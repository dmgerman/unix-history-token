begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file mpi.h  *  \brief The file defines the MPI constants and structures  *  * The file defines the MPI constants and structures  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__MPI_H__
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* CONSTANTS                                                                   */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_QUEUE_PRIORITY_HIGHEST
value|0xFF
end_define

begin_comment
comment|/**< Highest queue priority */
end_comment

begin_define
define|#
directive|define
name|MPI_QUEUE_PRIORITY_LOWEST
value|0x00
end_define

begin_comment
comment|/**< Lowest queue priority */
end_comment

begin_define
define|#
directive|define
name|MPI_MAX_INBOUND_QUEUES
value|64
end_define

begin_comment
comment|/**< Maximum number of inbound queues */
end_comment

begin_define
define|#
directive|define
name|MPI_MAX_OUTBOUND_QUEUES
value|64
end_define

begin_comment
comment|/**< Maximum number of outbound queues */
end_comment

begin_comment
comment|/**< Max # of memory chunks supported */
end_comment

begin_define
define|#
directive|define
name|MPI_MAX_MEM_REGIONS
value|(MPI_MAX_INBOUND_QUEUES + MPI_MAX_OUTBOUND_QUEUES) + 4
end_define

begin_define
define|#
directive|define
name|MPI_LOGSIZE
value|4096
end_define

begin_comment
comment|/**< default size */
end_comment

begin_define
define|#
directive|define
name|MPI_IB_NUM_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/**< Mask of Inbound Queue Number */
end_comment

begin_define
define|#
directive|define
name|MPI_OB_NUM_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/**< Mask of Outbound Queue Number */
end_comment

begin_define
define|#
directive|define
name|MPI_OB_SHIFT
value|16
end_define

begin_comment
comment|/**< bits shift for outbound queue number */
end_comment

begin_define
define|#
directive|define
name|BAR0
value|0x10
end_define

begin_define
define|#
directive|define
name|BAR1
value|0x14
end_define

begin_define
define|#
directive|define
name|BAR2
value|0x18
end_define

begin_define
define|#
directive|define
name|BAR3
value|0x1C
end_define

begin_define
define|#
directive|define
name|BAR4
value|0x20
end_define

begin_define
define|#
directive|define
name|BAR5
value|0x24
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* ENUMERATIONS                                                                */
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
comment|/** \enum mpiMsgCategory_e,  *  \brief MPI message categories  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_enum
enum|enum
name|mpiMsgCategory_e
block|{
name|MPI_CATEGORY_ETHERNET
init|=
literal|0
block|,
name|MPI_CATEGORY_FC
block|,
name|MPI_CATEGORY_SAS_SATA
block|,
name|MPI_CATEGORY_SCSI
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|mpiMsgCategory_e
name|mpiMsgCategory_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* TYPES                                                                       */
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
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* DATA STRUCTURES                                                             */
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
comment|/** \struct mpiMem_s  *  \brief Structure that descibes memory regions  *  * The mpiMemoryDescriptor_t is used to describe the attributes for a memory  * region. Each element in the memory chunk has to be physically contiguous.  * Different elements in the memory chunk do not necessarily have to be  * contiguous to each other.  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiMem_s
block|{
name|void
modifier|*
name|virtPtr
decl_stmt|;
comment|/**< Virtual pointer to the memory region */
name|void
modifier|*
name|appHandle
decl_stmt|;
comment|/**< Handle used for the application to free memory */
name|bit32
name|physAddrUpper
decl_stmt|;
comment|/**< Upper 32 bits of physical address */
name|bit32
name|physAddrLower
decl_stmt|;
comment|/**< Lower 32 bits of physical address */
name|bit32
name|totalLength
decl_stmt|;
comment|/**< Total length in bytes allocated */
name|bit32
name|numElements
decl_stmt|;
comment|/**< Number of elements */
name|bit32
name|elementSize
decl_stmt|;
comment|/**< Size in bytes of an element */
name|bit32
name|alignment
decl_stmt|;
comment|/**< Alignment in bytes needed. A value of one indicates */
comment|/**< no specific alignment requirement */
name|bit32
name|type
decl_stmt|;
comment|/**< Memory type */
name|bit32
name|reserved
decl_stmt|;
comment|/**< Reserved */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiMem_s
name|mpiMem_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiMemReq_s  *  \brief Describes MPI memory requirements  *  * The mpiMemRequirements_t  is used to specify the memory allocation requirement  * for the MPI. This is the data structure used in the mpiGetRequirements()  * and the mpiInitialize() function calls  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiMemReq_s
block|{
name|bit32
name|count
decl_stmt|;
comment|/**< The number of element in the mpiMemory array */
name|mpiMem_t
name|region
index|[
name|MPI_MAX_MEM_REGIONS
index|]
decl_stmt|;
comment|/**< Pointer to the array of structures that define memroy regions */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiMemReq_s
name|mpiMemReq_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiQCQueue_s  *  \brief Circular Queue descriptor  *  * This structure holds outbound circular queue attributes.  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiOCQueue_s
block|{
name|bit32
name|qNumber
decl_stmt|;
comment|/**< this queue number */
name|bit32
name|numElements
decl_stmt|;
comment|/**< The total number of queue elements. A value 0 disables the queue */
name|bit32
name|elementSize
decl_stmt|;
comment|/**< The size of each queue element, in bytes */
name|bit32
name|priority
decl_stmt|;
comment|/**< The queue priority. Possible values for this field are */
comment|/**< MPI_QUEUE_PRIORITY_HIGHEST and MPI_QUEUE_PRIORITY_LOWEST */
name|bit32
name|CIPCIBar
decl_stmt|;
comment|/**< PCI Bar */
name|bit32
name|CIPCIOffset
decl_stmt|;
comment|/**< PCI Offset */
name|bit32
name|DIntTOffset
decl_stmt|;
comment|/**< Dynamic Interrupt Coalescing Timeout offset */
name|void
modifier|*
name|piPointer
decl_stmt|;
comment|/**< pointer of PI (virtual address)*/
name|mpiMem_t
name|memoryRegion
decl_stmt|;
comment|/**< Queue's memory region descriptor */
name|bit32
name|producerIdx
decl_stmt|;
comment|/**< Copy of the producer index */
name|bit32
name|consumerIdx
decl_stmt|;
comment|/**< Copy of the consumer index */
name|bit32
name|pcibar
decl_stmt|;
comment|/**< CPI Logical Bar Number */
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
comment|/**< Pointer of LL Layer structure */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiOCQueue_s
name|mpiOCQueue_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiICQueue_s  *  \brief Circular Queue descriptor  *  * This structure holds inbound circular queue attributes.  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiICQueue_s
block|{
name|bit32
name|qNumber
decl_stmt|;
comment|/**< this queue number */
name|bit32
name|numElements
decl_stmt|;
comment|/**< The total number of queue elements. A value 0 disables the queue */
name|bit32
name|elementSize
decl_stmt|;
comment|/**< The size of each queue element, in bytes */
name|bit32
name|priority
decl_stmt|;
comment|/**< The queue priority. Possible values for this field are */
comment|/**< MPI_QUEUE_PRIORITY_HIGHEST and MPI_QUEUE_PRIORITY_LOWEST */
name|bit32
name|PIPCIBar
decl_stmt|;
comment|/**< PCI Bar */
name|bit32
name|PIPCIOffset
decl_stmt|;
comment|/**< PCI Offset */
name|void
modifier|*
name|ciPointer
decl_stmt|;
comment|/**< Pointer of CI (virtual Address) */
name|mpiMem_t
name|memoryRegion
decl_stmt|;
comment|/**< Queue's memory region descriptor */
name|bit32
name|producerIdx
decl_stmt|;
comment|/**< Copy of the producer index */
name|bit32
name|consumerIdx
decl_stmt|;
comment|/**< Copy of the consumer index */
ifdef|#
directive|ifdef
name|SA_FW_TEST_BUNCH_STARTS
name|bit32
name|BunchStarts_QPending
decl_stmt|;
comment|// un-started bunched IOs on queue
name|bit32
name|BunchStarts_QPendingTick
decl_stmt|;
comment|// tick value when 1st IO is bunched
endif|#
directive|endif
comment|/* SA_FW_TEST_BUNCH_STARTS */
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
comment|/**< Pointer of LL Layer structure */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiICQueue_s
name|mpiICQueue_t
typedef|;
end_typedef

begin_struct
struct|struct
name|mpiHostLLConfigDescriptor_s
block|{
name|bit32
name|regDumpPCIBAR
decl_stmt|;
name|bit32
name|iQNPPD_HPPD_GEvent
decl_stmt|;
comment|/**< inbound Queue Process depth */
comment|/* bit0-7   inbound normal priority process depth */
comment|/* bit8-15  inbound high priority process depth */
comment|/* bit16-23 OQ number to receive GENERAL_EVENT Notification */
comment|/* bit24-31 reserved */
name|bit32
name|outboundHWEventPID0_3
decl_stmt|;
comment|/**< outbound HW event for PortId 0 to 3 */
comment|/* bit0-7   outbound queue number of SAS_HW event for PortId 0 */
comment|/* bit8-15  outbound queue number of SAS_HW event for PortId 1 */
comment|/* bit16-23 outbound queue number of SAS_HW event for PortId 2 */
comment|/* bit24-31 outbound queue number of SAS_HW event for PortId 3 */
name|bit32
name|outboundHWEventPID4_7
decl_stmt|;
comment|/**< outbound HW event for PortId 4 to 7 */
comment|/* bit0-7   outbound queue number of SAS_HW event for PortId 4 */
comment|/* bit8-15  outbound queue number of SAS_HW event for PortId 5 */
comment|/* bit16-23 outbound queue number of SAS_HW event for PortId 6 */
comment|/* bit24-31 outbound queue number of SAS_HW event for PortId 7 */
name|bit32
name|outboundNCQEventPID0_3
decl_stmt|;
comment|/**< outbound NCQ event for PortId 0 to 3 */
comment|/* bit0-7   outbound queue number of SATA_NCQ event for PortId 0 */
comment|/* bit8-15  outbound queue number of SATA_NCQ event for PortId 1 */
comment|/* bit16-23 outbound queue number of SATA_NCQ event for PortId 2 */
comment|/* bit24-31 outbound queue number of SATA_NCQ event for PortId 3 */
name|bit32
name|outboundNCQEventPID4_7
decl_stmt|;
comment|/**< outbound NCQ event for PortId 4 to 7 */
comment|/* bit0-7   outbound queue number of SATA_NCQ event for PortId 4 */
comment|/* bit8-15  outbound queue number of SATA_NCQ event for PortId 5 */
comment|/* bit16-23 outbound queue number of SATA_NCQ event for PortId 6 */
comment|/* bit24-31 outbound queue number of SATA_NCQ event for PortId 7 */
name|bit32
name|outboundTargetITNexusEventPID0_3
decl_stmt|;
comment|/**< outbound target ITNexus Event for PortId 0 to 3 */
comment|/* bit0-7   outbound queue number of ITNexus event for PortId 0 */
comment|/* bit8-15  outbound queue number of ITNexus event for PortId 1 */
comment|/* bit16-23 outbound queue number of ITNexus event for PortId 2 */
comment|/* bit24-31 outbound queue number of ITNexus event for PortId 3 */
name|bit32
name|outboundTargetITNexusEventPID4_7
decl_stmt|;
comment|/**< outbound target ITNexus Event for PortId 4 to 7 */
comment|/* bit0-7   outbound queue number of ITNexus event for PortId 4 */
comment|/* bit8-15  outbound queue number of ITNexus event for PortId 5 */
comment|/* bit16-23 outbound queue number of ITNexus event for PortId 6 */
comment|/* bit24-31 outbound queue number of ITNexus event for PortId 7 */
name|bit32
name|outboundTargetSSPEventPID0_3
decl_stmt|;
comment|/**< outbound target SSP event for PordId 0 to 3 */
comment|/* bit0-7   outbound queue number of SSP event for PortId 0 */
comment|/* bit8-15  outbound queue number of SSP event for PortId 1 */
comment|/* bit16-23 outbound queue number of SSP event for PortId 2 */
comment|/* bit24-31 outbound queue number of SSP event for PortId 3 */
name|bit32
name|outboundTargetSSPEventPID4_7
decl_stmt|;
comment|/**< outbound target SSP event for PordId 4 to 7 */
comment|/* bit0-7   outbound queue number of SSP event for PortId 4 */
comment|/* bit8-15  outbound queue number of SSP event for PortId 5 */
comment|/* bit16-23 outbound queue number of SSP event for PortId 6 */
comment|/* bit24-31 outbound queue number of SSP event for PortId 7 */
name|bit32
name|ioAbortDelay
decl_stmt|;
comment|/* was reserved */
comment|/**< io Abort delay MPI_TABLE_CHANGE */
name|bit32
name|custset
decl_stmt|;
comment|/**< custset */
name|bit32
name|upperEventLogAddress
decl_stmt|;
comment|/**< Upper physical MSGU Event log address */
name|bit32
name|lowerEventLogAddress
decl_stmt|;
comment|/**< Lower physical MSGU Event log address */
name|bit32
name|eventLogSize
decl_stmt|;
comment|/**< Size of MSGU Event log, 0 means log disable */
name|bit32
name|eventLogOption
decl_stmt|;
comment|/**< Option of MSGU Event log */
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
comment|/**< Upper physical IOP Event log address */
name|bit32
name|lowerIOPeventLogAddress
decl_stmt|;
comment|/**< Lower physical IOP Event log address */
name|bit32
name|IOPeventLogSize
decl_stmt|;
comment|/**< Size of IOP Event log, 0 means log disable */
name|bit32
name|IOPeventLogOption
decl_stmt|;
comment|/**< Option of IOP Event log */
comment|/* bit3-0 log severity, 0x0 Disable Logging */
comment|/*                      0x1 Critical Error */
comment|/*                      0x2 Minor Error    */
comment|/*                      0x3 Warning        */
comment|/*                      0x4 Information    */
comment|/*                      0x5 Debugging      */
comment|/*                      0x6 - 0xF Reserved */
name|bit32
name|FatalErrorInterrupt
decl_stmt|;
comment|/**< Fatal Error Interrupt enable and vector */
comment|/* bit0     Fatal Error Interrupt Enable   */
comment|/* bit1     PI/CI Address                  */
comment|/* bit5     enable or disable outbound coalesce   */
comment|/* bit7-6  reserved */
comment|/* bit15-8  Fatal Error Interrupt Vector   */
comment|/* bit31-16 Reserved                       */
name|bit32
name|FatalErrorDumpOffset0
decl_stmt|;
comment|/**< Fatal Error Register Dump Offset for MSGU */
name|bit32
name|FatalErrorDumpLength0
decl_stmt|;
comment|/**< Fatal Error Register Dump Length for MSGU */
name|bit32
name|FatalErrorDumpOffset1
decl_stmt|;
comment|/**< Fatal Error Register Dump Offset for IOP */
name|bit32
name|FatalErrorDumpLength1
decl_stmt|;
comment|/**< Fatal Error Register Dump Length for IOP */
name|bit32
name|HDAModeFlags
decl_stmt|;
comment|/**< HDA Mode Flags */
comment|/* bit1-0   Bootstrap pins */
comment|/* bit2     Force HDA Mode bit */
comment|/* bit3     HDA Firmware load method */
name|bit32
name|analogSetupTblOffset
decl_stmt|;
comment|/**< Phy Calibration Table offset */
comment|/* bit23-0  phy calib table offset */
comment|/* bit31-24 entry size */
name|bit32
name|InterruptVecTblOffset
decl_stmt|;
comment|/**< DW23 Interrupt Vector Table */
comment|/* bit23-0  interrupt vector table offset */
comment|/* bit31-24 entry size */
name|bit32
name|phyAttributeTblOffset
decl_stmt|;
comment|/**< DW24 SAS Phy Attribute Table Offset */
comment|/* bit23-0  phy attribute table offset */
comment|/* bit31-24 entry size */
name|bit32
name|PortRecoveryTimerPortResetTimer
decl_stmt|;
comment|/**< DW25 Port Recovery Timer and Port Reset Timer */
name|bit32
name|InterruptReassertionDelay
decl_stmt|;
comment|/**< DW26 Interrupt Reassertion Delay 0:23 Reserved 24:31 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiHostLLConfigDescriptor_s
name|mpiHostLLConfigDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiInboundQueueDescriptor_s  *  \brief MPI inbound queue attributes  *  * The mpiInboundQueueDescriptor_t structure is used to describe an inbound queue  * attributes  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiInboundQueueDescriptor_s
block|{
name|bit32
name|numElements
decl_stmt|;
comment|/**< The total number of queue elements. A value 0 disables the queue */
name|bit32
name|elementSize
decl_stmt|;
comment|/**< The size of each queue element, in bytes */
name|bit32
name|priority
decl_stmt|;
comment|/**< The queue priority. Possible values for this field are */
comment|/**< MPI_QUEUE_PRIORITY_HIGHEST and MPI_QUEUE_PRIORITY_LOWEST */
name|bit32
name|PIPCIBar
decl_stmt|;
comment|/**< PI PCIe Bar */
name|bit32
name|PIOffset
decl_stmt|;
comment|/**< PI PCI Bar Offset */
name|void
modifier|*
name|ciPointer
decl_stmt|;
comment|/**< Pointer of CI (virtual Address) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiInboundQueueDescriptor_s
name|mpiInboundQueueDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiOutboundQueueDescriptor_s  *  \brief MPI outbound queue attributes  *  * The mpiOutboundQueueDescriptor_t structure is used to describe an outbound queue  * attributes  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiOutboundQueueDescriptor_s
block|{
name|bit32
name|numElements
decl_stmt|;
comment|/**< The total number of queue elements. A value 0 disables the queue */
name|bit32
name|elementSize
decl_stmt|;
comment|/**< The size of each queue element, in bytes */
name|bit32
name|interruptDelay
decl_stmt|;
comment|/**< Delay in microseconds before the interrupt is asserted */
comment|/**< if the interrupt threshold has not been reached */
name|bit32
name|interruptThreshold
decl_stmt|;
comment|/**< Number of interrupt events before the interrupt is asserted */
comment|/**< If set to 0, interrupts for this queue are disablec */
name|bit32
name|interruptVector
decl_stmt|;
comment|/**< Interrupt vector assigned to this queue */
name|bit32
name|CIPCIBar
decl_stmt|;
comment|/**< offset 0x14:PCI BAR for CI Offset */
name|bit32
name|CIOffset
decl_stmt|;
comment|/**< offset 0x18:Offset address for outbound queue CI */
name|bit32
name|DIntTOffset
decl_stmt|;
comment|/**< Dynamic Interrupt Coalescing Timeout offset */
name|bit32
name|interruptEnable
decl_stmt|;
comment|/**< Interrupt enable flag */
name|void
modifier|*
name|piPointer
decl_stmt|;
comment|/**< pointer of PI (virtual address)*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiOutboundQueueDescriptor_s
name|mpiOutboundQueueDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiPhyCalibration_s  *  \brief MPI Phy Calibration Table  *  * The mpiPhyCalibration_s structure is used to set Phy Calibration  * attributes  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiPhyCalibration_s
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
name|mpiPhyCalibration_s
name|mpiPhyCalibration_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ANALOG_SETUP_ENTRY_NO
value|10
end_define

begin_define
define|#
directive|define
name|ANALOG_SETUP_ENTRY_SIZE
value|10
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiConfig_s  *  \brief MPI layer configuration parameters  *  * The mpiConfig_s structure is used as a parameter passed in  * mpiGetRequirements() and mpiInitialize() to describe the MPI software  * configuration  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiVConfig_s
block|{
name|mpiHostLLConfigDescriptor_t
name|mainConfig
decl_stmt|;
comment|/**< main part of configuration table */
name|mpiInboundQueueDescriptor_t
name|inboundQueues
index|[
name|MPI_MAX_INBOUND_QUEUES
index|]
decl_stmt|;
comment|/**< mpiQueueDescriptor structures that provide initialization */
comment|/**< attributes for the inbound queues. The maximum number of */
comment|/**< inbound queues is MPI_MAX_INBOUND_QUEUES */
name|mpiOutboundQueueDescriptor_t
name|outboundQueues
index|[
name|MPI_MAX_OUTBOUND_QUEUES
index|]
decl_stmt|;
comment|/**< mpiQueueDescriptor structures that provide initialization */
comment|/**< attributes for the outbound queues. The maximum number of */
comment|/**< inbound queues is MPI_MAX_OUTBOUND_QUEUES */
name|agsaPhyAnalogSetupTable_t
name|phyAnalogConfig
decl_stmt|;
name|mpiInterruptVT_t
name|interruptVTable
decl_stmt|;
name|sasPhyAttribute_t
name|phyAttributeTable
decl_stmt|;
name|bit16
name|numInboundQueues
decl_stmt|;
name|bit16
name|numOutboundQueues
decl_stmt|;
name|bit16
name|maxNumInboundQueues
decl_stmt|;
name|bit16
name|maxNumOutboundQueues
decl_stmt|;
name|bit32
name|queueOption
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \struct mpiConfig_s  *  \brief MPI layer configuration parameters  *  * The mpiConfig_s structure is used as a parameter passed in  * mpiGetRequirements() and mpiInitialize() to describe the MPI software  * configuration  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_struct
struct|struct
name|mpiConfig_s
block|{
name|mpiHostLLConfigDescriptor_t
name|mainConfig
decl_stmt|;
comment|/**< main part of configuration table */
name|mpiInboundQueueDescriptor_t
name|inboundQueues
index|[
name|MPI_MAX_INBOUND_QUEUES
index|]
decl_stmt|;
comment|/**< mpiQueueDescriptor structures that provide initialization */
comment|/**< attributes for the inbound queues. The maximum number of */
comment|/**< inbound queues is MPI_MAX_INBOUND_QUEUES */
name|mpiOutboundQueueDescriptor_t
name|outboundQueues
index|[
name|MPI_MAX_OUTBOUND_QUEUES
index|]
decl_stmt|;
comment|/**< mpiQueueDescriptor structures that provide initialization */
comment|/**< attributes for the outbound queues. The maximum number of */
comment|/**< inbound queues is MPI_MAX_OUTBOUND_QUEUES */
name|agsaPhyAnalogSetupTable_t
name|phyAnalogConfig
decl_stmt|;
name|bit16
name|numInboundQueues
decl_stmt|;
name|bit16
name|numOutboundQueues
decl_stmt|;
name|bit16
name|maxNumInboundQueues
decl_stmt|;
name|bit16
name|maxNumOutboundQueues
decl_stmt|;
name|bit32
name|queueOption
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mpiConfig_s
name|mpiConfig_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TX_PORT_CFG1_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|TX_PORT_CFG2_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|TX_PORT_CFG3_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|TX_CFG_OFFSET
value|0x0c
end_define

begin_define
define|#
directive|define
name|RV_PORT_CFG1_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|RV_PORT_CFG2_OFFSET
value|0x14
end_define

begin_define
define|#
directive|define
name|RV_CFG1_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|RV_CFG2_OFFSET
value|0x1c
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/* FUNCTIONS                                                                   */
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

begin_function_decl
name|void
name|mpiRequirementsGet
parameter_list|(
name|mpiConfig_t
modifier|*
name|config
parameter_list|,
name|mpiMemReq_t
modifier|*
name|memoryRequirement
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FORCEINLINE
name|bit32
name|mpiMsgFreeGet
parameter_list|(
name|mpiICQueue_t
modifier|*
name|circularQ
parameter_list|,
name|bit16
name|messageSize
parameter_list|,
name|void
modifier|*
modifier|*
name|messagePtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FORCEINLINE
name|bit32
name|mpiMsgProduce
parameter_list|(
name|mpiICQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
name|messagePtr
parameter_list|,
name|mpiMsgCategory_t
name|category
parameter_list|,
name|bit16
name|opCode
parameter_list|,
name|bit8
name|responseQueue
parameter_list|,
name|bit8
name|hiPriority
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LOOPBACK_MPI
end_ifdef

begin_function_decl
name|GLOBAL
name|bit32
name|mpiMsgProduceOQ
parameter_list|(
name|mpiOCQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
name|messagePtr
parameter_list|,
name|mpiMsgCategory_t
name|category
parameter_list|,
name|bit16
name|opCode
parameter_list|,
name|bit8
name|responseQueue
parameter_list|,
name|bit8
name|hiPriority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GLOBAL
name|bit32
name|mpiMsgFreeGetOQ
parameter_list|(
name|mpiOCQueue_t
modifier|*
name|circularQ
parameter_list|,
name|bit16
name|messageSize
parameter_list|,
name|void
modifier|*
modifier|*
name|messagePtr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_function_decl
name|bit32
name|mpiMsgPrepare
parameter_list|(
name|mpiICQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
name|messagePtr
parameter_list|,
name|mpiMsgCategory_t
name|category
parameter_list|,
name|bit16
name|opCode
parameter_list|,
name|bit8
name|responseQueue
parameter_list|,
name|bit8
name|hiPriority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bit32
name|mpiMsgProduceSend
parameter_list|(
name|mpiICQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
name|messagePtr
parameter_list|,
name|mpiMsgCategory_t
name|category
parameter_list|,
name|bit16
name|opCode
parameter_list|,
name|bit8
name|responseQueue
parameter_list|,
name|bit8
name|hiPriority
parameter_list|,
name|int
name|sendFl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GLOBAL
name|void
name|mpiIBQMsgSend
parameter_list|(
name|mpiICQueue_t
modifier|*
name|circularQ
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INQ
parameter_list|(
name|queueNum
parameter_list|)
value|(bit8)(queueNum& MPI_IB_NUM_MASK)
end_define

begin_define
define|#
directive|define
name|OUQ
parameter_list|(
name|queueNum
parameter_list|)
value|(bit8)((queueNum& MPI_OB_NUM_MASK)>> MPI_OB_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|FORCEINLINE
name|bit32
name|mpiMsgConsume
parameter_list|(
name|mpiOCQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
modifier|*
name|messagePtr1
parameter_list|,
name|mpiMsgCategory_t
modifier|*
name|pCategory
parameter_list|,
name|bit16
modifier|*
name|pOpCode
parameter_list|,
name|bit8
modifier|*
name|pBC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FORCEINLINE
name|bit32
name|mpiMsgFreeSet
parameter_list|(
name|mpiOCQueue_t
modifier|*
name|circularQ
parameter_list|,
name|void
modifier|*
name|messagePtr1
parameter_list|,
name|bit8
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MPI_H__ */
end_comment

end_unit

