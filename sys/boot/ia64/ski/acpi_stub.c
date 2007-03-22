begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_define
define|#
directive|define
name|APIC_IO_SAPIC
value|6
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_SAPIC
value|7
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
comment|/* LOCAL SAPIC */
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|LocalSapicId
decl_stmt|;
comment|/* Processor local SAPIC id */
name|UINT8
name|LocalSapicEid
decl_stmt|;
comment|/* Processor local SAPIC eid */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|ProcessorEnabled
range|:
literal|1
decl_stmt|;
name|UINT32
name|FlagsReserved
range|:
literal|31
decl_stmt|;
block|}
name|LOCAL_SAPIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* IO SAPIC */
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|IoSapicId
decl_stmt|;
comment|/* I/O SAPIC ID */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* reserved - must be zero */
name|UINT32
name|Vector
decl_stmt|;
comment|/* interrupt base */
name|UINT64
name|IoSapicAddress
decl_stmt|;
comment|/* SAPIC's physical address */
block|}
name|IO_SAPIC
typedef|;
end_typedef

begin_comment
comment|/*  */
end_comment

begin_struct
struct|struct
block|{
name|ACPI_TABLE_MADT
name|MADT
decl_stmt|;
name|ACPI_MADT_LOCAL_SAPIC
name|cpu0
decl_stmt|;
name|ACPI_MADT_LOCAL_SAPIC
name|cpu1
decl_stmt|;
name|ACPI_MADT_LOCAL_SAPIC
name|cpu2
decl_stmt|;
name|ACPI_MADT_LOCAL_SAPIC
name|cpu3
decl_stmt|;
name|ACPI_MADT_IO_SAPIC
name|sapic
decl_stmt|;
block|}
name|apic
init|=
block|{
comment|/* Header. */
block|{
name|ACPI_SIG_MADT
block|,
comment|/* Signature. */
sizeof|sizeof
argument_list|(
name|apic
argument_list|)
block|,
comment|/* Length of table. */
literal|0
block|,
comment|/* ACPI minor revision. */
literal|0
block|,
comment|/* Checksum. */
literal|"FBSD"
block|,
comment|/* OEM Id. */
literal|"SKI"
block|,
comment|/* OEM table Id. */
literal|0
block|,
comment|/* OEM revision. */
literal|"FBSD"
block|,
comment|/* ASL compiler Id. */
literal|0
block|,
comment|/* ASL revision. */
literal|0xfee00000
block|, 	}
block|,
comment|/* cpu0. */
block|{
name|APIC_LOCAL_SAPIC
block|,
comment|/* Type. */
sizeof|sizeof
argument_list|(
name|apic
operator|.
name|cpu0
argument_list|)
block|,
comment|/* Length. */
literal|0
block|,
comment|/* ACPI processor id */
literal|0
block|,
comment|/* Processor local SAPIC id */
literal|0
block|,
comment|/* Processor local SAPIC eid */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* FL: Enabled. */
block|}
block|,
comment|/* cpu1. */
block|{
name|APIC_LOCAL_SAPIC
block|,
comment|/* Type. */
sizeof|sizeof
argument_list|(
name|apic
operator|.
name|cpu1
argument_list|)
block|,
comment|/* Length. */
literal|1
block|,
comment|/* ACPI processor id */
literal|0
block|,
comment|/* Processor local SAPIC id */
literal|1
block|,
comment|/* Processor local SAPIC eid */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* FL: Enabled. */
block|}
block|,
comment|/* cpu2. */
block|{
name|APIC_LOCAL_SAPIC
block|,
comment|/* Type. */
sizeof|sizeof
argument_list|(
name|apic
operator|.
name|cpu2
argument_list|)
block|,
comment|/* Length. */
literal|2
block|,
comment|/* ACPI processor id */
literal|1
block|,
comment|/* Processor local SAPIC id */
literal|0
block|,
comment|/* Processor local SAPIC eid */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|0
block|,
comment|/* FL: Enabled. */
block|}
block|,
comment|/* cpu3. */
block|{
name|APIC_LOCAL_SAPIC
block|,
comment|/* Type. */
sizeof|sizeof
argument_list|(
name|apic
operator|.
name|cpu3
argument_list|)
block|,
comment|/* Length. */
literal|3
block|,
comment|/* ACPI processor id */
literal|1
block|,
comment|/* Processor local SAPIC id */
literal|1
block|,
comment|/* Processor local SAPIC eid */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|0
block|,
comment|/* FL: Enabled. */
block|}
block|,
comment|/* sapic. */
block|{
name|APIC_IO_SAPIC
block|,
comment|/* Type. */
sizeof|sizeof
argument_list|(
name|apic
operator|.
name|sapic
argument_list|)
block|,
comment|/* Length. */
literal|4
block|,
comment|/* IO SAPIC id. */
literal|0
block|,
literal|16
block|,
comment|/* Interrupt base. */
literal|0xfec00000
comment|/* IO SAPIC address. */
block|}
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
name|UINT64
name|apic_tbl
decl_stmt|;
block|}
name|xsdt
init|=
block|{
block|{
name|ACPI_SIG_XSDT
block|,
comment|/* Signature. */
sizeof|sizeof
argument_list|(
name|xsdt
argument_list|)
block|,
comment|/* Length of table. */
literal|0
block|,
comment|/* ACPI minor revision. */
literal|0
block|,
comment|/* XXX checksum. */
literal|"FBSD"
block|,
comment|/* OEM Id. */
literal|"SKI"
block|,
comment|/* OEM table Id. */
literal|0
block|,
comment|/* OEM revision. */
literal|"FBSD"
block|,
comment|/* ASL compiler Id. */
literal|0
comment|/* ASL revision. */
block|}
block|,
literal|0UL
comment|/* XXX APIC table address. */
block|}
struct|;
end_struct

begin_decl_stmt
name|ACPI_TABLE_RSDP
name|acpi_root
init|=
block|{
name|ACPI_SIG_RSDP
block|,
literal|0
block|,
comment|/* XXX checksum. */
literal|"FBSD"
block|,
literal|2
block|,
comment|/* ACPI Rev 2.0. */
literal|0UL
block|,
sizeof|sizeof
argument_list|(
name|xsdt
argument_list|)
block|,
comment|/* XSDT length. */
literal|0UL
block|,
comment|/* XXX PA of XSDT. */
literal|0
block|,
comment|/* XXX Extended checksum. */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|cksum
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|sz
parameter_list|,
name|UINT8
modifier|*
name|sum
parameter_list|)
block|{
name|UINT8
modifier|*
name|p
decl_stmt|,
name|s
decl_stmt|;
name|p
operator|=
name|addr
expr_stmt|;
name|s
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|sz
operator|--
condition|)
name|s
operator|+=
operator|*
name|p
operator|++
expr_stmt|;
operator|*
name|sum
operator|=
operator|-
name|s
expr_stmt|;
block|}
end_function

begin_function
name|void
name|acpi_stub_init
parameter_list|(
name|void
parameter_list|)
block|{
name|acpi_root
operator|.
name|XsdtPhysicalAddress
operator|=
operator|(
name|UINT64
operator|)
operator|&
name|xsdt
expr_stmt|;
name|cksum
argument_list|(
operator|&
name|acpi_root
argument_list|,
literal|20
argument_list|,
operator|&
name|acpi_root
operator|.
name|Checksum
argument_list|)
expr_stmt|;
name|cksum
argument_list|(
operator|&
name|acpi_root
argument_list|,
sizeof|sizeof
argument_list|(
name|acpi_root
argument_list|)
argument_list|,
operator|&
name|acpi_root
operator|.
name|ExtendedChecksum
argument_list|)
expr_stmt|;
name|cksum
argument_list|(
operator|&
name|apic
argument_list|,
sizeof|sizeof
argument_list|(
name|apic
argument_list|)
argument_list|,
operator|&
name|apic
operator|.
name|MADT
operator|.
name|Header
operator|.
name|Checksum
argument_list|)
expr_stmt|;
name|xsdt
operator|.
name|apic_tbl
operator|=
operator|(
name|UINT32
operator|)
operator|&
name|apic
expr_stmt|;
name|cksum
argument_list|(
operator|&
name|xsdt
argument_list|,
sizeof|sizeof
argument_list|(
name|xsdt
argument_list|)
argument_list|,
operator|&
name|xsdt
operator|.
name|Header
operator|.
name|Checksum
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

