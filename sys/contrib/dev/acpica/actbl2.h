begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl2.h - ACPI Specification Revision 2.0 Tables  *       $Revision: 27 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2002, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL2_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL2_H__
end_define

begin_comment
comment|/*  * Prefered Power Management Profiles  */
end_comment

begin_define
define|#
directive|define
name|PM_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|PM_DESKTOP
value|1
end_define

begin_define
define|#
directive|define
name|PM_MOBILE
value|2
end_define

begin_define
define|#
directive|define
name|PM_WORKSTATION
value|3
end_define

begin_define
define|#
directive|define
name|PM_ENTERPRISE_SERVER
value|4
end_define

begin_define
define|#
directive|define
name|PM_SOHO_SERVER
value|5
end_define

begin_define
define|#
directive|define
name|PM_APPLIANCE_PC
value|6
end_define

begin_comment
comment|/*  * ACPI Boot Arch Flags  */
end_comment

begin_define
define|#
directive|define
name|BAF_LEGACY_DEVICES
value|0x0001
end_define

begin_define
define|#
directive|define
name|BAF_8042_KEYBOARD_CONTROLLER
value|0x0002
end_define

begin_define
define|#
directive|define
name|FADT2_REVISION_ID
value|3
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
comment|/*  * ACPI 2.0 Root System Description Table (RSDT)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* ACPI table header */
name|UINT32
name|TableOffsetEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of pointers to  */
comment|/* ACPI table headers */
block|}
name|RSDT_DESCRIPTOR_REV2
typedef|;
end_typedef

begin_comment
comment|/*  * ACPI 2.0 Extended System Description Table (XSDT)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* ACPI table header */
name|UINT64
name|TableOffsetEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of pointers to  */
comment|/* ACPI table headers */
block|}
name|XSDT_DESCRIPTOR_REV2
typedef|;
end_typedef

begin_comment
comment|/*  * ACPI 2.0 Firmware ACPI Control Structure (FACS)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|NATIVE_CHAR
name|Signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* ACPI signature */
name|UINT32
name|Length
decl_stmt|;
comment|/* Length of structure, in bytes */
name|UINT32
name|HardwareSignature
decl_stmt|;
comment|/* Hardware configuration signature */
name|UINT32
name|FirmwareWakingVector
decl_stmt|;
comment|/* 32bit physical address of the Firmware Waking Vector. */
name|UINT32
name|GlobalLock
decl_stmt|;
comment|/* Global Lock used to synchronize access to shared hardware resources */
name|UINT32
name|S4Bios_f
range|:
literal|1
decl_stmt|;
comment|/* S4Bios_f - Indicates if S4BIOS support is present */
name|UINT32_BIT
name|Reserved1
range|:
literal|31
decl_stmt|;
comment|/* Must be 0 */
name|UINT64
name|XFirmwareWakingVector
decl_stmt|;
comment|/* 64bit physical address of the Firmware Waking Vector. */
name|UINT8
name|Version
decl_stmt|;
comment|/* Version of this table */
name|UINT8
name|Reserved3
index|[
literal|31
index|]
decl_stmt|;
comment|/* Reserved - must be zero */
block|}
name|FACS_DESCRIPTOR_REV2
typedef|;
end_typedef

begin_comment
comment|/*  * ACPI 2.0 Generic Address Structure (GAS)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AddressSpaceId
decl_stmt|;
comment|/* Address space where struct or register exists. */
name|UINT8
name|RegisterBitWidth
decl_stmt|;
comment|/* Size in bits of given register */
name|UINT8
name|RegisterBitOffset
decl_stmt|;
comment|/* Bit offset within the register */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Must be 0 */
name|UINT64
name|Address
decl_stmt|;
comment|/* 64-bit address of struct or register */
block|}
name|ACPI_GENERIC_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/*  * ACPI 2.0 Fixed ACPI Description Table (FADT)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* ACPI table header */
name|UINT32
name|V1_FirmwareCtrl
decl_stmt|;
comment|/* 32-bit physical address of FACS */
name|UINT32
name|V1_Dsdt
decl_stmt|;
comment|/* 32-bit physical address of DSDT */
name|UINT8
name|Reserved1
decl_stmt|;
comment|/* System Interrupt Model isn't used in ACPI 2.0*/
name|UINT8
name|Prefer_PM_Profile
decl_stmt|;
comment|/* Conveys preferred power management profile to OSPM. */
name|UINT16
name|SciInt
decl_stmt|;
comment|/* System vector of SCI interrupt */
name|UINT32
name|SmiCmd
decl_stmt|;
comment|/* Port address of SMI command port */
name|UINT8
name|AcpiEnable
decl_stmt|;
comment|/* Value to write to smi_cmd to enable ACPI */
name|UINT8
name|AcpiDisable
decl_stmt|;
comment|/* Value to write to smi_cmd to disable ACPI */
name|UINT8
name|S4BiosReq
decl_stmt|;
comment|/* Value to write to SMI CMD to enter S4BIOS state */
name|UINT8
name|PstateCnt
decl_stmt|;
comment|/* Processor performance state control*/
name|UINT32
name|V1_Pm1aEvtBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1a AcpiEvent Reg Blk */
name|UINT32
name|V1_Pm1bEvtBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1b AcpiEvent Reg Blk */
name|UINT32
name|V1_Pm1aCntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1a Control Reg Blk */
name|UINT32
name|V1_Pm1bCntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1b Control Reg Blk */
name|UINT32
name|V1_Pm2CntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 2 Control Reg Blk */
name|UINT32
name|V1_PmTmrBlk
decl_stmt|;
comment|/* Port address of Power Mgt Timer Ctrl Reg Blk */
name|UINT32
name|V1_Gpe0Blk
decl_stmt|;
comment|/* Port addr of General Purpose AcpiEvent 0 Reg Blk */
name|UINT32
name|V1_Gpe1Blk
decl_stmt|;
comment|/* Port addr of General Purpose AcpiEvent 1 Reg Blk */
name|UINT8
name|Pm1EvtLen
decl_stmt|;
comment|/* Byte Length of ports at pm1X_evt_blk */
name|UINT8
name|Pm1CntLen
decl_stmt|;
comment|/* Byte Length of ports at pm1X_cnt_blk */
name|UINT8
name|Pm2CntLen
decl_stmt|;
comment|/* Byte Length of ports at pm2_cnt_blk */
name|UINT8
name|PmTmLen
decl_stmt|;
comment|/* Byte Length of ports at pm_tm_blk */
name|UINT8
name|Gpe0BlkLen
decl_stmt|;
comment|/* Byte Length of ports at gpe0_blk */
name|UINT8
name|Gpe1BlkLen
decl_stmt|;
comment|/* Byte Length of ports at gpe1_blk */
name|UINT8
name|Gpe1Base
decl_stmt|;
comment|/* Offset in gpe model where gpe1 events start */
name|UINT8
name|CstCnt
decl_stmt|;
comment|/* Support for the _CST object and C States change notification.*/
name|UINT16
name|Plvl2Lat
decl_stmt|;
comment|/* Worst case HW latency to enter/exit C2 state */
name|UINT16
name|Plvl3Lat
decl_stmt|;
comment|/* Worst case HW latency to enter/exit C3 state */
name|UINT16
name|FlushSize
decl_stmt|;
comment|/* Number of flush strides that need to be read */
name|UINT16
name|FlushStride
decl_stmt|;
comment|/* Processor's memory cache line width, in bytes */
name|UINT8
name|DutyOffset
decl_stmt|;
comment|/* Processors duty cycle index in processor's P_CNT reg*/
name|UINT8
name|DutyWidth
decl_stmt|;
comment|/* Processors duty cycle value bit width in P_CNT register.*/
name|UINT8
name|DayAlrm
decl_stmt|;
comment|/* Index to day-of-month alarm in RTC CMOS RAM */
name|UINT8
name|MonAlrm
decl_stmt|;
comment|/* Index to month-of-year alarm in RTC CMOS RAM */
name|UINT8
name|Century
decl_stmt|;
comment|/* Index to century in RTC CMOS RAM */
name|UINT16
name|IapcBootArch
decl_stmt|;
comment|/* IA-PC Boot Architecture Flags. See Table 5-10 for description*/
name|UINT8
name|Reserved2
decl_stmt|;
comment|/* Reserved */
name|UINT32_BIT
name|WbInvd
range|:
literal|1
decl_stmt|;
comment|/* The wbinvd instruction works properly */
name|UINT32_BIT
name|WbInvdFlush
range|:
literal|1
decl_stmt|;
comment|/* The wbinvd flushes but does not invalidate */
name|UINT32_BIT
name|ProcC1
range|:
literal|1
decl_stmt|;
comment|/* All processors support C1 state */
name|UINT32_BIT
name|Plvl2Up
range|:
literal|1
decl_stmt|;
comment|/* C2 state works on MP system */
name|UINT32_BIT
name|PwrButton
range|:
literal|1
decl_stmt|;
comment|/* Power button is handled as a generic feature */
name|UINT32_BIT
name|SleepButton
range|:
literal|1
decl_stmt|;
comment|/* Sleep button is handled as a generic feature, or not present */
name|UINT32_BIT
name|FixedRTC
range|:
literal|1
decl_stmt|;
comment|/* RTC wakeup stat not in fixed register space */
name|UINT32_BIT
name|Rtcs4
range|:
literal|1
decl_stmt|;
comment|/* RTC wakeup stat not possible from S4 */
name|UINT32_BIT
name|TmrValExt
range|:
literal|1
decl_stmt|;
comment|/* Indicates tmr_val is 32 bits 0=24-bits*/
name|UINT32_BIT
name|DockCap
range|:
literal|1
decl_stmt|;
comment|/* Supports Docking */
name|UINT32_BIT
name|ResetRegSup
range|:
literal|1
decl_stmt|;
comment|/* Indicates system supports system reset via the FADT RESET_REG*/
name|UINT32_BIT
name|SealedCase
range|:
literal|1
decl_stmt|;
comment|/* Indicates system has no internal expansion capabilities and case is sealed. */
name|UINT32_BIT
name|Headless
range|:
literal|1
decl_stmt|;
comment|/* Indicates system does not have local video capabilities or local input devices.*/
name|UINT32_BIT
name|CpuSwSleep
range|:
literal|1
decl_stmt|;
comment|/* Indicates to OSPM that a processor native instruction */
comment|/* Must be executed after writing the SLP_TYPx register. */
name|UINT32_BIT
name|Reserved6
range|:
literal|18
decl_stmt|;
comment|/* Reserved - must be zero */
name|ACPI_GENERIC_ADDRESS
name|ResetRegister
decl_stmt|;
comment|/* Reset register address in GAS format */
name|UINT8
name|ResetValue
decl_stmt|;
comment|/* Value to write to the ResetRegister port to reset the system. */
name|UINT8
name|Reserved7
index|[
literal|3
index|]
decl_stmt|;
comment|/* These three bytes must be zero */
name|UINT64
name|XFirmwareCtrl
decl_stmt|;
comment|/* 64-bit physical address of FACS */
name|UINT64
name|XDsdt
decl_stmt|;
comment|/* 64-bit physical address of DSDT */
name|ACPI_GENERIC_ADDRESS
name|XPm1aEvtBlk
decl_stmt|;
comment|/* Extended Power Mgt 1a AcpiEvent Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1bEvtBlk
decl_stmt|;
comment|/* Extended Power Mgt 1b AcpiEvent Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1aCntBlk
decl_stmt|;
comment|/* Extended Power Mgt 1a Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1bCntBlk
decl_stmt|;
comment|/* Extended Power Mgt 1b Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm2CntBlk
decl_stmt|;
comment|/* Extended Power Mgt 2 Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPmTmrBlk
decl_stmt|;
comment|/* Extended Power Mgt Timer Ctrl Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XGpe0Blk
decl_stmt|;
comment|/* Extended General Purpose AcpiEvent 0 Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XGpe1Blk
decl_stmt|;
comment|/* Extended General Purpose AcpiEvent 1 Reg Blk address */
block|}
name|FADT_DESCRIPTOR_REV2
typedef|;
end_typedef

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

begin_comment
comment|/* __ACTBL2_H__ */
end_comment

end_unit

