begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acclib.h -- C library support. Prototypes for the (optional) local  *                   implementations of required C library functions.  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCLIB_H
end_ifndef

begin_define
define|#
directive|define
name|_ACCLIB_H
end_define

begin_comment
comment|/*  * Prototypes and macros for local implementations of C library functions  */
end_comment

begin_comment
comment|/* is* functions. The AcpiGbl_Ctypes array is defined in utclib.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_Ctypes
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_ACPI_XA
value|0x00
end_define

begin_comment
comment|/* extra alphabetic - not supported */
end_comment

begin_define
define|#
directive|define
name|_ACPI_XS
value|0x40
end_define

begin_comment
comment|/* extra space */
end_comment

begin_define
define|#
directive|define
name|_ACPI_BB
value|0x00
end_define

begin_comment
comment|/* BEL, BS, etc. - not supported */
end_comment

begin_define
define|#
directive|define
name|_ACPI_CN
value|0x20
end_define

begin_comment
comment|/* CR, FF, HT, NL, VT */
end_comment

begin_define
define|#
directive|define
name|_ACPI_DI
value|0x04
end_define

begin_comment
comment|/* '0'-'9' */
end_comment

begin_define
define|#
directive|define
name|_ACPI_LO
value|0x02
end_define

begin_comment
comment|/* 'a'-'z' */
end_comment

begin_define
define|#
directive|define
name|_ACPI_PU
value|0x10
end_define

begin_comment
comment|/* punctuation */
end_comment

begin_define
define|#
directive|define
name|_ACPI_SP
value|0x08
end_define

begin_comment
comment|/* space, tab, CR, LF, VT, FF */
end_comment

begin_define
define|#
directive|define
name|_ACPI_UP
value|0x01
end_define

begin_comment
comment|/* 'A'-'Z' */
end_comment

begin_define
define|#
directive|define
name|_ACPI_XD
value|0x80
end_define

begin_comment
comment|/* '0'-'9', 'A'-'F', 'a'-'f' */
end_comment

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_DI))
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_SP))
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_XD))
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_UP))
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_LO))
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_LO | _ACPI_UP | _ACPI_DI | _ACPI_XS | _ACPI_PU))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(AcpiGbl_Ctypes[(unsigned char)(c)]& (_ACPI_LO | _ACPI_UP))
end_define

begin_comment
comment|/* Error code */
end_comment

begin_define
define|#
directive|define
name|EPERM
value|1
end_define

begin_comment
comment|/* Operation not permitted */
end_comment

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_comment
comment|/* No such file or directory */
end_comment

begin_define
define|#
directive|define
name|EINTR
value|4
end_define

begin_comment
comment|/* Interrupted system call */
end_comment

begin_define
define|#
directive|define
name|EIO
value|5
end_define

begin_comment
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|EBADF
value|9
end_define

begin_comment
comment|/* Bad file number */
end_comment

begin_define
define|#
directive|define
name|EAGAIN
value|11
end_define

begin_comment
comment|/* Try again */
end_comment

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_comment
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|EACCES
value|13
end_define

begin_comment
comment|/* Permission denied */
end_comment

begin_define
define|#
directive|define
name|EFAULT
value|14
end_define

begin_comment
comment|/* Bad address */
end_comment

begin_define
define|#
directive|define
name|EBUSY
value|16
end_define

begin_comment
comment|/* Device or resource busy */
end_comment

begin_define
define|#
directive|define
name|EEXIST
value|17
end_define

begin_comment
comment|/* File exists */
end_comment

begin_define
define|#
directive|define
name|ENODEV
value|19
end_define

begin_comment
comment|/* No such device */
end_comment

begin_define
define|#
directive|define
name|EINVAL
value|22
end_define

begin_comment
comment|/* Invalid argument */
end_comment

begin_define
define|#
directive|define
name|EPIPE
value|32
end_define

begin_comment
comment|/* Broken pipe */
end_comment

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_comment
comment|/* Math result not representable */
end_comment

begin_comment
comment|/* Strings */
end_comment

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strpbrk
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
specifier|const
name|char
modifier|*
name|Delimiters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
specifier|const
name|char
modifier|*
name|Delimiters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|String1
parameter_list|,
specifier|const
name|char
modifier|*
name|String2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_SIZE
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|(
specifier|const
name|char
modifier|*
name|String1
parameter_list|,
specifier|const
name|char
modifier|*
name|String2
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strstr
parameter_list|(
name|char
modifier|*
name|String1
parameter_list|,
name|char
modifier|*
name|String2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Conversion */
end_comment

begin_function_decl
name|UINT32
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|char
modifier|*
modifier|*
name|Terminator
parameter_list|,
name|UINT32
name|Base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory */
end_comment

begin_function_decl
name|int
name|memcmp
parameter_list|(
name|void
modifier|*
name|Buffer1
parameter_list|,
name|void
modifier|*
name|Buffer2
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
specifier|const
name|void
modifier|*
name|Src
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
specifier|const
name|void
modifier|*
name|Src
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
name|int
name|Value
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* upper/lower case */
end_comment

begin_function_decl
name|int
name|tolower
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toupper
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utprint - printf/vprintf output functions  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtScanNumber
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|UINT64
modifier|*
name|NumberPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtPrintNumber
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|UINT64
name|Number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/*  * NOTE: Currently we only need to update errno for file IOs. Other  *       Clibrary invocations in ACPICA do not make descisions according to  *       the errno.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|EOF
end_ifndef

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|c
parameter_list|)
value|fputc(stdout, c)
end_define

begin_define
define|#
directive|define
name|getchar
parameter_list|(
name|c
parameter_list|)
value|fgetc(stdin)
end_define

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|(
specifier|const
name|char
modifier|*
name|Path
parameter_list|,
specifier|const
name|char
modifier|*
name|Modes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fclose
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fread
parameter_list|(
name|void
modifier|*
name|Buffer
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|,
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fwrite
parameter_list|(
name|void
modifier|*
name|Buffer
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|,
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fseek
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|,
name|long
name|Offset
parameter_list|,
name|int
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ftell
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetc
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputc
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|,
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fgets
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACCLIB_H */
end_comment

end_unit

