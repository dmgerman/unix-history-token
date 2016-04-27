begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acclib.h -- C library support. Prototypes for the (optional) local  *                   implementations of required C library functions.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACCLIB_H */
end_comment

end_unit

