begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: pe.h 3441 2016-04-07 15:04:20Z emaste $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PE_H_
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/*  * MS-DOS header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PE_DosHdr
block|{
name|char
name|dh_magic
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|dh_lastsize
decl_stmt|;
name|uint16_t
name|dh_nblock
decl_stmt|;
name|uint16_t
name|dh_nreloc
decl_stmt|;
name|uint16_t
name|dh_hdrsize
decl_stmt|;
name|uint16_t
name|dh_minalloc
decl_stmt|;
name|uint16_t
name|dh_maxalloc
decl_stmt|;
name|uint16_t
name|dh_ss
decl_stmt|;
name|uint16_t
name|dh_sp
decl_stmt|;
name|uint16_t
name|dh_checksum
decl_stmt|;
name|uint16_t
name|dh_ip
decl_stmt|;
name|uint16_t
name|dh_cs
decl_stmt|;
name|uint16_t
name|dh_relocpos
decl_stmt|;
name|uint16_t
name|dh_noverlay
decl_stmt|;
name|uint16_t
name|dh_reserved1
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|dh_oemid
decl_stmt|;
name|uint16_t
name|dh_oeminfo
decl_stmt|;
name|uint16_t
name|dh_reserved2
index|[
literal|10
index|]
decl_stmt|;
name|uint32_t
name|dh_lfanew
decl_stmt|;
block|}
name|PE_DosHdr
typedef|;
end_typedef

begin_comment
comment|/*  * Rich header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PE_RichHdr
block|{
name|uint32_t
name|rh_xor
decl_stmt|;
name|uint32_t
name|rh_total
decl_stmt|;
name|uint32_t
modifier|*
name|rh_compid
decl_stmt|;
name|uint32_t
modifier|*
name|rh_cnt
decl_stmt|;
block|}
name|PE_RichHdr
typedef|;
end_typedef

begin_comment
comment|/*  * COFF header: Machine Types.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_UNKNOWN
value|0x0
end_define

begin_comment
comment|/* not specified */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_AM33
value|0x1d3
end_define

begin_comment
comment|/* Matsushita AM33 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_AMD64
value|0x8664
end_define

begin_comment
comment|/* x86-64 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARM
value|0x1c0
end_define

begin_comment
comment|/* ARM LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARMNT
value|0x1c4
end_define

begin_comment
comment|/* ARMv7(or higher) Thumb */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARM64
value|0xaa64
end_define

begin_comment
comment|/* ARMv8 64-bit */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_EBC
value|0xebc
end_define

begin_comment
comment|/* EFI byte code */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_I386
value|0x14c
end_define

begin_comment
comment|/* x86 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_IA64
value|0x200
end_define

begin_comment
comment|/* IA64 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_M32R
value|0x9041
end_define

begin_comment
comment|/* Mitsubishi M32R LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPS16
value|0x266
end_define

begin_comment
comment|/* MIPS16 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU
value|0x366
end_define

begin_comment
comment|/* MIPS with FPU */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU16
value|0x466
end_define

begin_comment
comment|/* MIPS16 with FPU */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPC
value|0x1f0
end_define

begin_comment
comment|/* Power PC LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPCFP
value|0x1f1
end_define

begin_comment
comment|/* Power PC floating point */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R4000
value|0x166
end_define

begin_comment
comment|/* MIPS R4000 LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_RISCV32
value|0x5032
end_define

begin_comment
comment|/* RISC-V 32-bit */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_RISCV64
value|0x5064
end_define

begin_comment
comment|/* RISC-V 64-bit */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_RISCV128
value|0x5128
end_define

begin_comment
comment|/* RISC-V 128-bit */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3
value|0x1a2
end_define

begin_comment
comment|/* Hitachi SH3 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3DSP
value|0x1a3
end_define

begin_comment
comment|/* Hitachi SH3 DSP */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH4
value|0x1a6
end_define

begin_comment
comment|/* Hitachi SH4 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH5
value|0x1a8
end_define

begin_comment
comment|/* Hitachi SH5 */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_THUMB
value|0x1c2
end_define

begin_comment
comment|/* ARM or Thumb interworking */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_WCEMIPSV2
value|0x169
end_define

begin_comment
comment|/* MIPS LE WCE v2 */
end_comment

begin_comment
comment|/*  * COFF header: Characteristics  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_RELOCS_STRIPPED
value|0x0001
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_EXECUTABLE_IMAGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LINE_NUMS_STRIPPED
value|0x0004
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LOCAL_SYMS_STRIPPED
value|0x0008
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_AGGRESSIVE_WS_TRIM
value|0x0010
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LARGE_ADDRESS_AWARE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_LO
value|0x0080
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_32BIT_MACHINE
value|0x0100
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_DEBUG_STRIPPED
value|0x0200
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP
value|0x0400
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_NET_RUN_FROM_SWAP
value|0x0800
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_SYSTEM
value|0x1000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_DLL
value|0x2000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_UP_SYSTEM_ONLY
value|0x4000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_HI
value|0x8000
end_define

begin_comment
comment|/*  * COFF Header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PE_CoffHdr
block|{
name|uint16_t
name|ch_machine
decl_stmt|;
name|uint16_t
name|ch_nsec
decl_stmt|;
name|uint32_t
name|ch_timestamp
decl_stmt|;
name|uint32_t
name|ch_symptr
decl_stmt|;
name|uint32_t
name|ch_nsym
decl_stmt|;
name|uint16_t
name|ch_optsize
decl_stmt|;
name|uint16_t
name|ch_char
decl_stmt|;
block|}
name|PE_CoffHdr
typedef|;
end_typedef

begin_comment
comment|/*  * Optional Header: Subsystem.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_NATIVE
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_GUI
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_CUI
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_POSIX_CUI
value|7
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_CE_GUI
value|9
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_APPLICATION
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER
value|11
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER
value|12
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_ROM
value|13
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_XBOX
value|14
end_define

begin_comment
comment|/*  * Optional Header: DLL Characteristics  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_DYNAMIC_BASE
value|0x0040
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_FORCE_INTEGRITY
value|0x0080
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_NX_COMPAT
value|0x0100
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_NO_ISOLATION
value|0x0200
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_NO_SEH
value|0x0400
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_NO_BIND
value|0x0800
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_WDM_DRIVER
value|0x2000
end_define

begin_define
define|#
directive|define
name|IMAGE_DLL_CHARACTERISTICS_TERMINAL_SERVER_AWARE
value|0x8000
end_define

begin_comment
comment|/*  * Optional Header.  */
end_comment

begin_define
define|#
directive|define
name|PE_FORMAT_ROM
value|0x107
end_define

begin_define
define|#
directive|define
name|PE_FORMAT_32
value|0x10b
end_define

begin_define
define|#
directive|define
name|PE_FORMAT_32P
value|0x20b
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PE_OptHdr
block|{
name|uint16_t
name|oh_magic
decl_stmt|;
name|uint8_t
name|oh_ldvermajor
decl_stmt|;
name|uint8_t
name|oh_ldverminor
decl_stmt|;
name|uint32_t
name|oh_textsize
decl_stmt|;
name|uint32_t
name|oh_datasize
decl_stmt|;
name|uint32_t
name|oh_bsssize
decl_stmt|;
name|uint32_t
name|oh_entry
decl_stmt|;
name|uint32_t
name|oh_textbase
decl_stmt|;
name|uint32_t
name|oh_database
decl_stmt|;
name|uint64_t
name|oh_imgbase
decl_stmt|;
name|uint32_t
name|oh_secalign
decl_stmt|;
name|uint32_t
name|oh_filealign
decl_stmt|;
name|uint16_t
name|oh_osvermajor
decl_stmt|;
name|uint16_t
name|oh_osverminor
decl_stmt|;
name|uint16_t
name|oh_imgvermajor
decl_stmt|;
name|uint16_t
name|oh_imgverminor
decl_stmt|;
name|uint16_t
name|oh_subvermajor
decl_stmt|;
name|uint16_t
name|oh_subverminor
decl_stmt|;
name|uint32_t
name|oh_win32ver
decl_stmt|;
name|uint32_t
name|oh_imgsize
decl_stmt|;
name|uint32_t
name|oh_hdrsize
decl_stmt|;
name|uint32_t
name|oh_checksum
decl_stmt|;
name|uint16_t
name|oh_subsystem
decl_stmt|;
name|uint16_t
name|oh_dllchar
decl_stmt|;
name|uint64_t
name|oh_stacksizer
decl_stmt|;
name|uint64_t
name|oh_stacksizec
decl_stmt|;
name|uint64_t
name|oh_heapsizer
decl_stmt|;
name|uint64_t
name|oh_heapsizec
decl_stmt|;
name|uint32_t
name|oh_ldrflags
decl_stmt|;
name|uint32_t
name|oh_ndatadir
decl_stmt|;
block|}
name|PE_OptHdr
typedef|;
end_typedef

begin_comment
comment|/*  * Optional Header: Data Directories.  */
end_comment

begin_define
define|#
directive|define
name|PE_DD_EXPORT
value|0
end_define

begin_define
define|#
directive|define
name|PE_DD_IMPORT
value|1
end_define

begin_define
define|#
directive|define
name|PE_DD_RESROUCE
value|2
end_define

begin_define
define|#
directive|define
name|PE_DD_EXCEPTION
value|3
end_define

begin_define
define|#
directive|define
name|PE_DD_CERTIFICATE
value|4
end_define

begin_define
define|#
directive|define
name|PE_DD_BASERELOC
value|5
end_define

begin_define
define|#
directive|define
name|PE_DD_DEBUG
value|6
end_define

begin_define
define|#
directive|define
name|PE_DD_ARCH
value|7
end_define

begin_define
define|#
directive|define
name|PE_DD_GLOBALPTR
value|8
end_define

begin_define
define|#
directive|define
name|PE_DD_TLS
value|9
end_define

begin_define
define|#
directive|define
name|PE_DD_LOADCONFIG
value|10
end_define

begin_define
define|#
directive|define
name|PE_DD_BOUNDIMPORT
value|11
end_define

begin_define
define|#
directive|define
name|PE_DD_IAT
value|12
end_define

begin_define
define|#
directive|define
name|PE_DD_DELAYIMPORT
value|13
end_define

begin_define
define|#
directive|define
name|PE_DD_CLRRUNTIME
value|14
end_define

begin_define
define|#
directive|define
name|PE_DD_RESERVED
value|15
end_define

begin_define
define|#
directive|define
name|PE_DD_MAX
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PE_DataDirEntry
block|{
name|uint32_t
name|de_addr
decl_stmt|;
name|uint32_t
name|de_size
decl_stmt|;
block|}
name|PE_DataDirEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PE_DataDir
block|{
name|PE_DataDirEntry
name|dd_e
index|[
name|PE_DD_MAX
index|]
decl_stmt|;
name|uint32_t
name|dd_total
decl_stmt|;
block|}
name|PE_DataDir
typedef|;
end_typedef

begin_comment
comment|/*  * Section Headers: Section flags.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_TYPE_NO_PAD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_CODE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_INITIALIZED_DATA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_UNINITIALIZED_DATA
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_OTHER
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_INFO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_REMOVE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_COMDAT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_GPREL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_PURGEABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_16BIT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_LOCKED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_PRELOAD
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_1BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_2BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_4BYTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_8BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_16BYTES
value|0x00500000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_32BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_64BYTES
value|0x00700000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_128BYTES
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_256BYTES
value|0x00900000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_512BYTES
value|0x00A00000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_1024BYTES
value|0x00B00000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_2048BYTES
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_4096BYTES
value|0x00D00000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_8192BYTES
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_NRELOC_OVFL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_DISCARDABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_CACHED
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_PAGED
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_SHARED
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_EXECUTE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_READ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_WRITE
value|0x80000000
end_define

begin_comment
comment|/*  * Section Headers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PE_SecHdr
block|{
name|char
name|sh_name
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|sh_virtsize
decl_stmt|;
name|uint32_t
name|sh_addr
decl_stmt|;
name|uint32_t
name|sh_rawsize
decl_stmt|;
name|uint32_t
name|sh_rawptr
decl_stmt|;
name|uint32_t
name|sh_relocptr
decl_stmt|;
name|uint32_t
name|sh_lineptr
decl_stmt|;
name|uint16_t
name|sh_nreloc
decl_stmt|;
name|uint16_t
name|sh_nline
decl_stmt|;
name|uint32_t
name|sh_char
decl_stmt|;
block|}
name|PE_SecHdr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PE_H_ */
end_comment

end_unit

