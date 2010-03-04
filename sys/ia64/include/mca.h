begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MCA_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MCA_H_
end_define

begin_struct
struct|struct
name|mca_record_header
block|{
name|uint64_t
name|rh_seqnr
decl_stmt|;
comment|/* Record id. */
name|uint8_t
name|rh_major
decl_stmt|;
comment|/* BCD (=02). */
name|uint8_t
name|rh_minor
decl_stmt|;
comment|/* BCD (=00). */
name|uint8_t
name|rh_error
decl_stmt|;
comment|/* Error severity. */
define|#
directive|define
name|MCA_RH_ERROR_RECOVERABLE
value|0
define|#
directive|define
name|MCA_RH_ERROR_FATAL
value|1
define|#
directive|define
name|MCA_RH_ERROR_CORRECTED
value|2
name|uint8_t
name|rh_flags
decl_stmt|;
define|#
directive|define
name|MCA_RH_FLAGS_PLATFORM_ID
value|0x01
comment|/* Platform_id present. */
define|#
directive|define
name|MCA_RH_FLAGS_TIME_STAMP
value|0x02
comment|/* Timestamp invalid. */
name|uint32_t
name|rh_length
decl_stmt|;
comment|/* Size including header. */
name|uint8_t
name|rh_time
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|MCA_RH_TIME_SEC
value|0
define|#
directive|define
name|MCA_RH_TIME_MIN
value|1
define|#
directive|define
name|MCA_RH_TIME_HOUR
value|2
define|#
directive|define
name|MCA_RH_TIME_MDAY
value|4
define|#
directive|define
name|MCA_RH_TIME_MON
value|5
define|#
directive|define
name|MCA_RH_TIME_YEAR
value|6
define|#
directive|define
name|MCA_RH_TIME_CENT
value|7
name|struct
name|uuid
name|rh_platform
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_section_header
block|{
name|struct
name|uuid
name|sh_uuid
decl_stmt|;
name|uint8_t
name|sh_major
decl_stmt|;
comment|/* BCD (=02). */
name|uint8_t
name|sh_minor
decl_stmt|;
comment|/* BCD (=00). */
name|uint8_t
name|sh_flags
decl_stmt|;
define|#
directive|define
name|MCA_SH_FLAGS_CORRECTED
value|0x01
comment|/* Error has been corrected. */
define|#
directive|define
name|MCA_SH_FLAGS_PROPAGATE
value|0x02
comment|/* Possible propagation. */
define|#
directive|define
name|MCA_SH_FLAGS_RESET
value|0x04
comment|/* Reset device before use. */
define|#
directive|define
name|MCA_SH_FLAGS_VALID
value|0x80
comment|/* Flags are valid. */
name|uint8_t
name|__reserved
decl_stmt|;
name|uint32_t
name|sh_length
decl_stmt|;
comment|/* Size including header. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_cpu_record
block|{
name|uint64_t
name|cpu_flags
decl_stmt|;
define|#
directive|define
name|MCA_CPU_FLAGS_ERRMAP
value|(1ULL<< 0)
define|#
directive|define
name|MCA_CPU_FLAGS_STATE
value|(1ULL<< 1)
define|#
directive|define
name|MCA_CPU_FLAGS_CR_LID
value|(1ULL<< 2)
define|#
directive|define
name|MCA_CPU_FLAGS_PSI_STRUCT
value|(1ULL<< 3)
define|#
directive|define
name|MCA_CPU_FLAGS_CACHE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 15)
define|#
directive|define
name|MCA_CPU_FLAGS_TLB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 15)
define|#
directive|define
name|MCA_CPU_FLAGS_BUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 15)
define|#
directive|define
name|MCA_CPU_FLAGS_REG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 15)
define|#
directive|define
name|MCA_CPU_FLAGS_MS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 15)
define|#
directive|define
name|MCA_CPU_FLAGS_CPUID
value|(1ULL<< 24)
name|uint64_t
name|cpu_errmap
decl_stmt|;
name|uint64_t
name|cpu_state
decl_stmt|;
name|uint64_t
name|cpu_cr_lid
decl_stmt|;
comment|/* Nx cpu_mod (cache). */
comment|/* Nx cpu_mod (TLB). */
comment|/* Nx cpu_mod (bus). */
comment|/* Nx cpu_mod (reg). */
comment|/* Nx cpu_mod (MS). */
comment|/* cpu_cpuid. */
comment|/* cpu_psi. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_cpu_cpuid
block|{
name|uint64_t
name|cpuid
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_cpu_mod
block|{
name|uint64_t
name|cpu_mod_flags
decl_stmt|;
define|#
directive|define
name|MCA_CPU_MOD_FLAGS_INFO
value|(1ULL<< 0)
define|#
directive|define
name|MCA_CPU_MOD_FLAGS_REQID
value|(1ULL<< 1)
define|#
directive|define
name|MCA_CPU_MOD_FLAGS_RSPID
value|(1ULL<< 2)
define|#
directive|define
name|MCA_CPU_MOD_FLAGS_TGTID
value|(1ULL<< 3)
define|#
directive|define
name|MCA_CPU_MOD_FLAGS_IP
value|(1ULL<< 4)
name|uint64_t
name|cpu_mod_info
decl_stmt|;
name|uint64_t
name|cpu_mod_reqid
decl_stmt|;
name|uint64_t
name|cpu_mod_rspid
decl_stmt|;
name|uint64_t
name|cpu_mod_tgtid
decl_stmt|;
name|uint64_t
name|cpu_mod_ip
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_cpu_psi
block|{
name|uint64_t
name|cpu_psi_flags
decl_stmt|;
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_STATE
value|(1ULL<< 0)
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_BR
value|(1ULL<< 1)
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_CR
value|(1ULL<< 2)
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_AR
value|(1ULL<< 3)
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_RR
value|(1ULL<< 4)
define|#
directive|define
name|MCA_CPU_PSI_FLAGS_FR
value|(1ULL<< 5)
name|uint8_t
name|cpu_psi_state
index|[
literal|1024
index|]
decl_stmt|;
comment|/* XXX variable? */
name|uint64_t
name|cpu_psi_br
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|cpu_psi_cr
index|[
literal|128
index|]
decl_stmt|;
comment|/* XXX variable? */
name|uint64_t
name|cpu_psi_ar
index|[
literal|128
index|]
decl_stmt|;
comment|/* XXX variable? */
name|uint64_t
name|cpu_psi_rr
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|cpu_psi_fr
index|[
literal|256
index|]
decl_stmt|;
comment|/* 16 bytes per register! */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_mem_record
block|{
name|uint64_t
name|mem_flags
decl_stmt|;
define|#
directive|define
name|MCA_MEM_FLAGS_STATUS
value|(1ULL<< 0)
define|#
directive|define
name|MCA_MEM_FLAGS_ADDR
value|(1ULL<< 1)
define|#
directive|define
name|MCA_MEM_FLAGS_ADDRMASK
value|(1ULL<< 2)
define|#
directive|define
name|MCA_MEM_FLAGS_NODE
value|(1ULL<< 3)
define|#
directive|define
name|MCA_MEM_FLAGS_CARD
value|(1ULL<< 4)
define|#
directive|define
name|MCA_MEM_FLAGS_MODULE
value|(1ULL<< 5)
define|#
directive|define
name|MCA_MEM_FLAGS_BANK
value|(1ULL<< 6)
define|#
directive|define
name|MCA_MEM_FLAGS_DEVICE
value|(1ULL<< 7)
define|#
directive|define
name|MCA_MEM_FLAGS_ROW
value|(1ULL<< 8)
define|#
directive|define
name|MCA_MEM_FLAGS_COLUMN
value|(1ULL<< 9)
define|#
directive|define
name|MCA_MEM_FLAGS_BITPOS
value|(1ULL<< 10)
define|#
directive|define
name|MCA_MEM_FLAGS_REQID
value|(1ULL<< 11)
define|#
directive|define
name|MCA_MEM_FLAGS_RSPID
value|(1ULL<< 12)
define|#
directive|define
name|MCA_MEM_FLAGS_TGTID
value|(1ULL<< 13)
define|#
directive|define
name|MCA_MEM_FLAGS_BUSDATA
value|(1ULL<< 14)
define|#
directive|define
name|MCA_MEM_FLAGS_OEM_ID
value|(1ULL<< 15)
define|#
directive|define
name|MCA_MEM_FLAGS_OEM_DATA
value|(1ULL<< 16)
name|uint64_t
name|mem_status
decl_stmt|;
name|uint64_t
name|mem_addr
decl_stmt|;
name|uint64_t
name|mem_addrmask
decl_stmt|;
name|uint16_t
name|mem_node
decl_stmt|;
name|uint16_t
name|mem_card
decl_stmt|;
name|uint16_t
name|mem_module
decl_stmt|;
name|uint16_t
name|mem_bank
decl_stmt|;
name|uint16_t
name|mem_device
decl_stmt|;
name|uint16_t
name|mem_row
decl_stmt|;
name|uint16_t
name|mem_column
decl_stmt|;
name|uint16_t
name|mem_bitpos
decl_stmt|;
name|uint64_t
name|mem_reqid
decl_stmt|;
name|uint64_t
name|mem_rspid
decl_stmt|;
name|uint64_t
name|mem_tgtid
decl_stmt|;
name|uint64_t
name|mem_busdata
decl_stmt|;
name|struct
name|uuid
name|mem_oem_id
decl_stmt|;
name|uint16_t
name|mem_oem_length
decl_stmt|;
comment|/* Size of OEM data. */
comment|/* N bytes of OEM platform data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_pcibus_record
block|{
name|uint64_t
name|pcibus_flags
decl_stmt|;
define|#
directive|define
name|MCA_PCIBUS_FLAGS_STATUS
value|(1ULL<< 0)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_ERROR
value|(1ULL<< 1)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_BUS
value|(1ULL<< 2)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_ADDR
value|(1ULL<< 3)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_DATA
value|(1ULL<< 4)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_CMD
value|(1ULL<< 5)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_REQID
value|(1ULL<< 6)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_RSPID
value|(1ULL<< 7)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_TGTID
value|(1ULL<< 8)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_OEM_ID
value|(1ULL<< 9)
define|#
directive|define
name|MCA_PCIBUS_FLAGS_OEM_DATA
value|(1ULL<< 10)
name|uint64_t
name|pcibus_status
decl_stmt|;
name|uint16_t
name|pcibus_error
decl_stmt|;
name|uint16_t
name|pcibus_bus
decl_stmt|;
name|uint32_t
name|__reserved
decl_stmt|;
name|uint64_t
name|pcibus_addr
decl_stmt|;
name|uint64_t
name|pcibus_data
decl_stmt|;
name|uint64_t
name|pcibus_cmd
decl_stmt|;
name|uint64_t
name|pcibus_reqid
decl_stmt|;
name|uint64_t
name|pcibus_rspid
decl_stmt|;
name|uint64_t
name|pcibus_tgtid
decl_stmt|;
name|struct
name|uuid
name|pcibus_oem_id
decl_stmt|;
name|uint16_t
name|pcibus_oem_length
decl_stmt|;
comment|/* Size of OEM data. */
comment|/* N bytes of OEM platform data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_pcidev_record
block|{
name|uint64_t
name|pcidev_flags
decl_stmt|;
define|#
directive|define
name|MCA_PCIDEV_FLAGS_STATUS
value|(1ULL<< 0)
define|#
directive|define
name|MCA_PCIDEV_FLAGS_INFO
value|(1ULL<< 1)
define|#
directive|define
name|MCA_PCIDEV_FLAGS_REG_MEM
value|(1ULL<< 2)
define|#
directive|define
name|MCA_PCIDEV_FLAGS_REG_IO
value|(1ULL<< 3)
define|#
directive|define
name|MCA_PCIDEV_FLAGS_REG_DATA
value|(1ULL<< 4)
define|#
directive|define
name|MCA_PCIDEV_FLAGS_OEM_DATA
value|(1ULL<< 5)
name|uint64_t
name|pcidev_status
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|info_vendor
decl_stmt|;
name|uint16_t
name|info_device
decl_stmt|;
name|uint32_t
name|info_ccfn
decl_stmt|;
comment|/* Class code& funct. nr. */
define|#
directive|define
name|MCA_PCIDEV_INFO_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffffff)
define|#
directive|define
name|MCA_PCIDEV_INFO_FUNCTION
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xff)
name|uint8_t
name|info_slot
decl_stmt|;
name|uint8_t
name|info_bus
decl_stmt|;
name|uint8_t
name|info_segment
decl_stmt|;
name|uint8_t
name|__res0
decl_stmt|;
name|uint32_t
name|__res1
decl_stmt|;
block|}
name|pcidev_info
struct|;
name|uint32_t
name|pcidev_reg_mem
decl_stmt|;
name|uint32_t
name|pcidev_reg_io
decl_stmt|;
comment|/* Nx pcidev_reg. */
comment|/* M bytes of OEM platform data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mca_pcidev_reg
block|{
name|uint64_t
name|pcidev_reg_addr
decl_stmt|;
name|uint64_t
name|pcidev_reg_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MCA_UUID_CPU
define|\
value|{0xe429faf1,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_MEMORY
define|\
value|{0xe429faf2,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_SEL
define|\
value|{0xe429faf3,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_PCI_BUS
define|\
value|{0xe429faf4,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_SMBIOS
define|\
value|{0xe429faf5,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_PCI_DEV
define|\
value|{0xe429faf6,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_define
define|#
directive|define
name|MCA_UUID_GENERIC
define|\
value|{0xe429faf7,0x3cb7,0x11d4,0xbc,0xa7,{0x00,0x80,0xc7,0x3c,0x88,0x81}}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ia64_mca_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_mca_populate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_mca_save_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MCA_H_ */
end_comment

end_unit

