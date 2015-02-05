begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: osunixmap - Unix OSL for file mappings  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2015, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpidump.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_FreeBSD
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_OS_SERVICES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"osunixmap"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_FreeBSD
end_ifdef

begin_define
define|#
directive|define
name|MMAP_FLAGS
value|MAP_SHARED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MMAP_FLAGS
value|MAP_PRIVATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSTEM_MEMORY
value|"/dev/mem"
end_define

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiOsGetPageSize  *  * PARAMETERS:  None  *  * RETURN:      Page size of the platform.  *  * DESCRIPTION: Obtain page size of the platform.  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|ACPI_SIZE
name|AcpiOsGetPageSize
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PAGE_SIZE
return|return
name|PAGE_SIZE
return|;
else|#
directive|else
return|return
name|sysconf
argument_list|(
name|_SC_PAGESIZE
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsMapMemory  *  * PARAMETERS:  Where               - Physical address of memory to be mapped  *              Length              - How much memory to map  *  * RETURN:      Pointer to mapped memory. Null on error.  *  * DESCRIPTION: Map physical memory into local address space.  *  *****************************************************************************/
end_comment

begin_function
name|void
modifier|*
name|AcpiOsMapMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Where
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
block|{
name|UINT8
modifier|*
name|MappedMemory
decl_stmt|;
name|ACPI_PHYSICAL_ADDRESS
name|Offset
decl_stmt|;
name|ACPI_SIZE
name|PageSize
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|SYSTEM_MEMORY
argument_list|,
name|O_RDONLY
operator||
name|O_BINARY
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open %s\n"
argument_list|,
name|SYSTEM_MEMORY
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* Align the offset to use mmap */
name|PageSize
operator|=
name|AcpiOsGetPageSize
argument_list|()
expr_stmt|;
name|Offset
operator|=
name|Where
operator|%
name|PageSize
expr_stmt|;
comment|/* Map the table header to get the length of the full table */
name|MappedMemory
operator|=
name|mmap
argument_list|(
name|NULL
argument_list|,
operator|(
name|Length
operator|+
name|Offset
operator|)
argument_list|,
name|PROT_READ
argument_list|,
name|MMAP_FLAGS
argument_list|,
name|fd
argument_list|,
operator|(
name|Where
operator|-
name|Offset
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|MappedMemory
operator|==
name|MAP_FAILED
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot map %s\n"
argument_list|,
name|SYSTEM_MEMORY
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ACPI_CAST8
argument_list|(
name|MappedMemory
operator|+
name|Offset
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsUnmapMemory  *  * PARAMETERS:  Where               - Logical address of memory to be unmapped  *              Length              - How much memory to unmap  *  * RETURN:      None.  *  * DESCRIPTION: Delete a previously created mapping. Where and Length must  *              correspond to a previous mapping exactly.  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsUnmapMemory
parameter_list|(
name|void
modifier|*
name|Where
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
block|{
name|ACPI_PHYSICAL_ADDRESS
name|Offset
decl_stmt|;
name|ACPI_SIZE
name|PageSize
decl_stmt|;
name|PageSize
operator|=
name|AcpiOsGetPageSize
argument_list|()
expr_stmt|;
name|Offset
operator|=
operator|(
name|ACPI_PHYSICAL_ADDRESS
operator|)
name|Where
operator|%
name|PageSize
expr_stmt|;
name|munmap
argument_list|(
operator|(
name|UINT8
operator|*
operator|)
name|Where
operator|-
name|Offset
argument_list|,
operator|(
name|Length
operator|+
name|Offset
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

