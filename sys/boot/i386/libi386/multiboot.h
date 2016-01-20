begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* multiboot.h - Multiboot header file. */
end_comment

begin_comment
comment|/* Copyright (C) 1999,2003,2007,2008,2009  Free Software Foundation, Inc. * *  Permission is hereby granted, free of charge, to any person obtaining a copy *  of this software and associated documentation files (the "Software"), to *  deal in the Software without restriction, including without limitation the *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or *  sell copies of the Software, and to permit persons to whom the Software is *  furnished to do so, subject to the following conditions: * *  The above copyright notice and this permission notice shall be included in *  all copies or substantial portions of the Software. * *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL ANY *  DEVELOPER OR DISTRIBUTOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. * * $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MULTIBOOT_HEADER
end_ifndef

begin_define
define|#
directive|define
name|MULTIBOOT_HEADER
value|1
end_define

begin_comment
comment|/* How many bytes from the start of the file we search for the header. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_SEARCH
value|8192
end_define

begin_comment
comment|/* The magic field should contain this. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_HEADER_MAGIC
value|0x1BADB002
end_define

begin_comment
comment|/* This should be in %eax. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_BOOTLOADER_MAGIC
value|0x2BADB002
end_define

begin_comment
comment|/* The bits in the required part of flags field we don't support. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_UNSUPPORTED
value|0x0000fffc
end_define

begin_comment
comment|/* Alignment of multiboot modules. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_MOD_ALIGN
value|0x00001000
end_define

begin_comment
comment|/* Alignment of the multiboot info structure. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_ALIGN
value|0x00000004
end_define

begin_comment
comment|/* Flags set in the 'flags' member of the multiboot header. */
end_comment

begin_comment
comment|/* Align all boot modules on i386 page (4KB) boundaries. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_PAGE_ALIGN
value|0x00000001
end_define

begin_comment
comment|/* Must pass memory information to OS. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_MEMORY_INFO
value|0x00000002
end_define

begin_comment
comment|/* Must pass video information to OS. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_VIDEO_MODE
value|0x00000004
end_define

begin_comment
comment|/* This flag indicates the use of the address fields in the header. */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_AOUT_KLUDGE
value|0x00010000
end_define

begin_comment
comment|/* Flags to be set in the 'flags' member of the multiboot info structure. */
end_comment

begin_comment
comment|/* is there basic lower/upper memory information? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_MEMORY
value|0x00000001
end_define

begin_comment
comment|/* is there a boot device set? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_BOOTDEV
value|0x00000002
end_define

begin_comment
comment|/* is the command-line defined? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_CMDLINE
value|0x00000004
end_define

begin_comment
comment|/* are there modules to do something with? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_MODS
value|0x00000008
end_define

begin_comment
comment|/* These next two are mutually exclusive */
end_comment

begin_comment
comment|/* is there a symbol table loaded? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_AOUT_SYMS
value|0x00000010
end_define

begin_comment
comment|/* is there an ELF section header table? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_ELF_SHDR
value|0X00000020
end_define

begin_comment
comment|/* is there a full memory map? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_MEM_MAP
value|0x00000040
end_define

begin_comment
comment|/* Is there drive info? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_DRIVE_INFO
value|0x00000080
end_define

begin_comment
comment|/* Is there a config table? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_CONFIG_TABLE
value|0x00000100
end_define

begin_comment
comment|/* Is there a boot loader name? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_BOOT_LOADER_NAME
value|0x00000200
end_define

begin_comment
comment|/* Is there a APM table? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_APM_TABLE
value|0x00000400
end_define

begin_comment
comment|/* Is there video information? */
end_comment

begin_define
define|#
directive|define
name|MULTIBOOT_INFO_VIDEO_INFO
value|0x00000800
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FILE
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|multiboot_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|multiboot_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|multiboot_uint64_t
typedef|;
end_typedef

begin_struct
struct|struct
name|multiboot_header
block|{
comment|/* Must be MULTIBOOT_MAGIC - see above. */
name|multiboot_uint32_t
name|magic
decl_stmt|;
comment|/* Feature flags. */
name|multiboot_uint32_t
name|flags
decl_stmt|;
comment|/* The above fields plus this one must equal 0 mod 2^32. */
name|multiboot_uint32_t
name|checksum
decl_stmt|;
comment|/* These are only valid if MULTIBOOT_AOUT_KLUDGE is set. */
name|multiboot_uint32_t
name|header_addr
decl_stmt|;
name|multiboot_uint32_t
name|load_addr
decl_stmt|;
name|multiboot_uint32_t
name|load_end_addr
decl_stmt|;
name|multiboot_uint32_t
name|bss_end_addr
decl_stmt|;
name|multiboot_uint32_t
name|entry_addr
decl_stmt|;
comment|/* These are only valid if MULTIBOOT_VIDEO_MODE is set. */
name|multiboot_uint32_t
name|mode_type
decl_stmt|;
name|multiboot_uint32_t
name|width
decl_stmt|;
name|multiboot_uint32_t
name|height
decl_stmt|;
name|multiboot_uint32_t
name|depth
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The symbol table for a.out. */
end_comment

begin_struct
struct|struct
name|multiboot_aout_symbol_table
block|{
name|multiboot_uint32_t
name|tabsize
decl_stmt|;
name|multiboot_uint32_t
name|strsize
decl_stmt|;
name|multiboot_uint32_t
name|addr
decl_stmt|;
name|multiboot_uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multiboot_aout_symbol_table
name|multiboot_aout_symbol_table_t
typedef|;
end_typedef

begin_comment
comment|/* The section header table for ELF. */
end_comment

begin_struct
struct|struct
name|multiboot_elf_section_header_table
block|{
name|multiboot_uint32_t
name|num
decl_stmt|;
name|multiboot_uint32_t
name|size
decl_stmt|;
name|multiboot_uint32_t
name|addr
decl_stmt|;
name|multiboot_uint32_t
name|shndx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multiboot_elf_section_header_table
name|multiboot_elf_section_header_table_t
typedef|;
end_typedef

begin_struct
struct|struct
name|multiboot_info
block|{
comment|/* Multiboot info version number */
name|multiboot_uint32_t
name|flags
decl_stmt|;
comment|/* Available memory from BIOS */
name|multiboot_uint32_t
name|mem_lower
decl_stmt|;
name|multiboot_uint32_t
name|mem_upper
decl_stmt|;
comment|/* "root" partition */
name|multiboot_uint32_t
name|boot_device
decl_stmt|;
comment|/* Kernel command line */
name|multiboot_uint32_t
name|cmdline
decl_stmt|;
comment|/* Boot-Module list */
name|multiboot_uint32_t
name|mods_count
decl_stmt|;
name|multiboot_uint32_t
name|mods_addr
decl_stmt|;
union|union
block|{
name|multiboot_aout_symbol_table_t
name|aout_sym
decl_stmt|;
name|multiboot_elf_section_header_table_t
name|elf_sec
decl_stmt|;
block|}
name|u
union|;
comment|/* Memory Mapping buffer */
name|multiboot_uint32_t
name|mmap_length
decl_stmt|;
name|multiboot_uint32_t
name|mmap_addr
decl_stmt|;
comment|/* Drive Info buffer */
name|multiboot_uint32_t
name|drives_length
decl_stmt|;
name|multiboot_uint32_t
name|drives_addr
decl_stmt|;
comment|/* ROM configuration table */
name|multiboot_uint32_t
name|config_table
decl_stmt|;
comment|/* Boot Loader Name */
name|multiboot_uint32_t
name|boot_loader_name
decl_stmt|;
comment|/* APM table */
name|multiboot_uint32_t
name|apm_table
decl_stmt|;
comment|/* Video */
name|multiboot_uint32_t
name|vbe_control_info
decl_stmt|;
name|multiboot_uint32_t
name|vbe_mode_info
decl_stmt|;
name|multiboot_uint16_t
name|vbe_mode
decl_stmt|;
name|multiboot_uint16_t
name|vbe_interface_seg
decl_stmt|;
name|multiboot_uint16_t
name|vbe_interface_off
decl_stmt|;
name|multiboot_uint16_t
name|vbe_interface_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multiboot_info
name|multiboot_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|multiboot_mmap_entry
block|{
name|multiboot_uint32_t
name|size
decl_stmt|;
name|multiboot_uint64_t
name|addr
decl_stmt|;
name|multiboot_uint64_t
name|len
decl_stmt|;
define|#
directive|define
name|MULTIBOOT_MEMORY_AVAILABLE
value|1
define|#
directive|define
name|MULTIBOOT_MEMORY_RESERVED
value|2
name|multiboot_uint32_t
name|type
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multiboot_mmap_entry
name|multiboot_memory_map_t
typedef|;
end_typedef

begin_struct
struct|struct
name|multiboot_mod_list
block|{
comment|/* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
name|multiboot_uint32_t
name|mod_start
decl_stmt|;
name|multiboot_uint32_t
name|mod_end
decl_stmt|;
comment|/* Module command line */
name|multiboot_uint32_t
name|cmdline
decl_stmt|;
comment|/* padding to take it to 16 bytes (must be zero) */
name|multiboot_uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multiboot_mod_list
name|multiboot_module_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ASM_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MULTIBOOT_HEADER */
end_comment

end_unit

