begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl32.h - ACPI tables specific to IA32  *       $Revision: 11 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights  * reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL32_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL32_H__
end_define

begin_comment
comment|/* IA32 Root System Description Table */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|header
decl_stmt|;
comment|/* Table header */
name|void
modifier|*
name|TableOffsetEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of pointers to other */
comment|/* tables' headers */
block|}
name|ROOT_SYSTEM_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|/* IA32 Firmware ACPI Control Structure */
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
comment|/* signature "FACS" */
name|UINT32
name|Length
decl_stmt|;
comment|/* length of structure, in bytes */
name|UINT32
name|HardwareSignature
decl_stmt|;
comment|/* hardware configuration signature */
name|UINT32
name|FirmwareWakingVector
decl_stmt|;
comment|/* ACPI OS waking vector */
name|UINT32
name|GlobalLock
decl_stmt|;
comment|/* Global Lock */
name|UINT32_BIT
name|S4Bios_f
range|:
literal|1
decl_stmt|;
comment|/* Indicates if S4BIOS support is present */
name|UINT32_BIT
name|Reserved1
range|:
literal|31
decl_stmt|;
comment|/* must be 0 */
name|UINT8
name|Resverved3
index|[
literal|40
index|]
decl_stmt|;
comment|/* reserved - must be zero */
block|}
name|FIRMWARE_ACPI_CONTROL_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|/* IA32 Fixed ACPI Description Table */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|header
decl_stmt|;
comment|/* table header */
name|ACPI_TBLPTR
name|FirmwareCtrl
decl_stmt|;
comment|/* Physical address of FACS */
name|ACPI_TBLPTR
name|Dsdt
decl_stmt|;
comment|/* Physical address of DSDT */
name|UINT8
name|Model
decl_stmt|;
comment|/* System Interrupt Model */
name|UINT8
name|Reserved1
decl_stmt|;
comment|/* reserved */
name|UINT16
name|SciInt
decl_stmt|;
comment|/* System vector of SCI interrupt */
name|ACPI_IO_ADDRESS
name|SmiCmd
decl_stmt|;
comment|/* Port address of SMI command port */
name|UINT8
name|AcpiEnable
decl_stmt|;
comment|/* value to write to smi_cmd to enable ACPI */
name|UINT8
name|AcpiDisable
decl_stmt|;
comment|/* value to write to smi_cmd to disable ACPI */
name|UINT8
name|S4BiosReq
decl_stmt|;
comment|/* Value to write to SMI CMD to enter S4BIOS state */
name|UINT8
name|Reserved2
decl_stmt|;
comment|/* reserved - must be zero */
name|ACPI_IO_ADDRESS
name|Pm1aEvtBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1a AcpiEvent Reg Blk */
name|ACPI_IO_ADDRESS
name|Pm1bEvtBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1b AcpiEvent Reg Blk */
name|ACPI_IO_ADDRESS
name|Pm1aCntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1a Control Reg Blk */
name|ACPI_IO_ADDRESS
name|Pm1bCntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 1b Control Reg Blk */
name|ACPI_IO_ADDRESS
name|Pm2CntBlk
decl_stmt|;
comment|/* Port address of Power Mgt 2 Control Reg Blk */
name|ACPI_IO_ADDRESS
name|PmTmrBlk
decl_stmt|;
comment|/* Port address of Power Mgt Timer Ctrl Reg Blk */
name|ACPI_IO_ADDRESS
name|Gpe0Blk
decl_stmt|;
comment|/* Port addr of General Purpose AcpiEvent 0 Reg Blk */
name|ACPI_IO_ADDRESS
name|Gpe1Blk
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
comment|/* offset in gpe model where gpe1 events start */
name|UINT8
name|Reserved3
decl_stmt|;
comment|/* reserved */
name|UINT16
name|Plvl2Lat
decl_stmt|;
comment|/* worst case HW latency to enter/exit C2 state */
name|UINT16
name|Plvl3Lat
decl_stmt|;
comment|/* worst case HW latency to enter/exit C3 state */
name|UINT16
name|FlushSize
decl_stmt|;
comment|/* Size of area read to flush caches */
name|UINT16
name|FlushStride
decl_stmt|;
comment|/* Stride used in flushing caches */
name|UINT8
name|DutyOffset
decl_stmt|;
comment|/* bit location of duty cycle field in p_cnt reg */
name|UINT8
name|DutyWidth
decl_stmt|;
comment|/* bit width of duty cycle field in p_cnt reg */
name|UINT8
name|DayAlrm
decl_stmt|;
comment|/* index to day-of-month alarm in RTC CMOS RAM */
name|UINT8
name|MonAlrm
decl_stmt|;
comment|/* index to month-of-year alarm in RTC CMOS RAM */
name|UINT8
name|Century
decl_stmt|;
comment|/* index to century in RTC CMOS RAM */
name|UINT8
name|Reserved4
decl_stmt|;
comment|/* reserved */
name|UINT8
name|Reserved4a
decl_stmt|;
comment|/* reserved */
name|UINT8
name|Reserved4b
decl_stmt|;
comment|/* reserved */
name|UINT32_BIT
name|WbInvd
range|:
literal|1
decl_stmt|;
comment|/* wbinvd instruction works properly */
name|UINT32_BIT
name|WbInvdFlush
range|:
literal|1
decl_stmt|;
comment|/* wbinvd flushes but does not invalidate */
name|UINT32_BIT
name|ProcC1
range|:
literal|1
decl_stmt|;
comment|/* all processors support C1 state */
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
comment|/* tmr_val is 32 bits */
name|UINT32_BIT
name|Reserved5
range|:
literal|23
decl_stmt|;
comment|/* reserved - must be zero */
block|}
name|FIXED_ACPI_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTBL32_H__ */
end_comment

end_unit

