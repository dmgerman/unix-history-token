begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal format of COFF object file data structures, for GNU BFD.    This file is part of BFD, the Binary File Descriptor library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNU_COFF_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|GNU_COFF_INTERNAL_H
value|1
end_define

begin_comment
comment|/* First, make "signed char" work, even on old compilers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|signed
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|signed
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_comment
comment|/* extra stuff in a PE header. */
end_comment

begin_struct
struct|struct
name|internal_extra_pe_filehdr
block|{
comment|/* DOS header data follows for PE stuff */
name|unsigned
name|short
name|e_magic
decl_stmt|;
comment|/* Magic number, 0x5a4d */
name|unsigned
name|short
name|e_cblp
decl_stmt|;
comment|/* Bytes on last page of file, 0x90 */
name|unsigned
name|short
name|e_cp
decl_stmt|;
comment|/* Pages in file, 0x3 */
name|unsigned
name|short
name|e_crlc
decl_stmt|;
comment|/* Relocations, 0x0 */
name|unsigned
name|short
name|e_cparhdr
decl_stmt|;
comment|/* Size of header in paragraphs, 0x4 */
name|unsigned
name|short
name|e_minalloc
decl_stmt|;
comment|/* Minimum extra paragraphs needed, 0x0 */
name|unsigned
name|short
name|e_maxalloc
decl_stmt|;
comment|/* Maximum extra paragraphs needed, 0xFFFF */
name|unsigned
name|short
name|e_ss
decl_stmt|;
comment|/* Initial (relative) SS value, 0x0 */
name|unsigned
name|short
name|e_sp
decl_stmt|;
comment|/* Initial SP value, 0xb8 */
name|unsigned
name|short
name|e_csum
decl_stmt|;
comment|/* Checksum, 0x0 */
name|unsigned
name|short
name|e_ip
decl_stmt|;
comment|/* Initial IP value, 0x0 */
name|unsigned
name|short
name|e_cs
decl_stmt|;
comment|/* Initial (relative) CS value, 0x0 */
name|unsigned
name|short
name|e_lfarlc
decl_stmt|;
comment|/* File address of relocation table, 0x40 */
name|unsigned
name|short
name|e_ovno
decl_stmt|;
comment|/* Overlay number, 0x0 */
name|unsigned
name|short
name|e_res
index|[
literal|4
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0 */
name|unsigned
name|short
name|e_oemid
decl_stmt|;
comment|/* OEM identifier (for e_oeminfo), 0x0 */
name|unsigned
name|short
name|e_oeminfo
decl_stmt|;
comment|/* OEM information; e_oemid specific, 0x0 */
name|unsigned
name|short
name|e_res2
index|[
literal|10
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0 */
name|bfd_vma
name|e_lfanew
decl_stmt|;
comment|/* File address of new exe header, 0x80 */
name|unsigned
name|long
name|dos_message
index|[
literal|16
index|]
decl_stmt|;
comment|/* text which always follows dos header */
name|bfd_vma
name|nt_signature
decl_stmt|;
comment|/* required NT signature, 0x4550 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|internal_filehdr
block|{
name|struct
name|internal_extra_pe_filehdr
name|pe
decl_stmt|;
comment|/* standard coff  internal info */
name|unsigned
name|short
name|f_magic
decl_stmt|;
comment|/* magic number			*/
name|unsigned
name|short
name|f_nscns
decl_stmt|;
comment|/* number of sections		*/
name|long
name|f_timdat
decl_stmt|;
comment|/* time& date stamp		*/
name|bfd_vma
name|f_symptr
decl_stmt|;
comment|/* file pointer to symtab	*/
name|long
name|f_nsyms
decl_stmt|;
comment|/* number of symtab entries	*/
name|unsigned
name|short
name|f_opthdr
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|unsigned
name|short
name|f_flags
decl_stmt|;
comment|/* flags			*/
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for f_flags:  *	F_RELFLG	relocation info stripped from file  *	F_EXEC		file is executable (no unresolved external references)  *	F_LNNO		line numbers stripped from file  *	F_LSYMS		local symbols stripped from file  *	F_AR16WR	file is 16-bit little-endian  *	F_AR32WR	file is 32-bit little-endian  *	F_AR32W		file is 32-bit big-endian  *	F_DYNLOAD	rs/6000 aix: dynamically loadable w/imports& exports  *	F_SHROBJ	rs/6000 aix: file is a shared object  *      F_DLL           PE format DLL  */
end_comment

begin_define
define|#
directive|define
name|F_RELFLG
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|F_EXEC
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|F_LNNO
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|F_LSYMS
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|F_AR16WR
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|F_AR32WR
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|F_AR32W
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|F_DYNLOAD
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|F_SHROBJ
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_DLL
value|(0x2000)
end_define

begin_comment
comment|/* extra structure which is used in the optional header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_DATA_DIRECTORY
block|{
name|bfd_vma
name|VirtualAddress
decl_stmt|;
name|long
name|Size
decl_stmt|;
block|}
name|IMAGE_DATA_DIRECTORY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_NUMBEROF_DIRECTORY_ENTRIES
value|16
end_define

begin_comment
comment|/* default image base for NT */
end_comment

begin_define
define|#
directive|define
name|NT_EXE_IMAGE_BASE
value|0x400000
end_define

begin_define
define|#
directive|define
name|NT_DLL_IMAGE_BASE
value|0x10000000
end_define

begin_comment
comment|/* Extra stuff in a PE aouthdr */
end_comment

begin_define
define|#
directive|define
name|PE_DEF_SECTION_ALIGNMENT
value|0x1000
end_define

begin_define
define|#
directive|define
name|PE_DEF_FILE_ALIGNMENT
value|0x200
end_define

begin_struct
struct|struct
name|internal_extra_pe_aouthdr
block|{
comment|/* PE stuff  */
name|bfd_vma
name|ImageBase
decl_stmt|;
comment|/* address of specific location in memory that 				   file is located, NT default 0x10000 */
name|bfd_vma
name|SectionAlignment
decl_stmt|;
comment|/* section alignment default 0x1000 */
name|bfd_vma
name|FileAlignment
decl_stmt|;
comment|/* file alignment default 0x200 */
name|short
name|MajorOperatingSystemVersion
decl_stmt|;
comment|/* minimum version of the operating */
name|short
name|MinorOperatingSystemVersion
decl_stmt|;
comment|/* system req'd for exe, default to 1*/
name|short
name|MajorImageVersion
decl_stmt|;
comment|/* user defineable field to store version of */
name|short
name|MinorImageVersion
decl_stmt|;
comment|/* exe or dll being created, default to 0 */
name|short
name|MajorSubsystemVersion
decl_stmt|;
comment|/* minimum subsystem version required to */
name|short
name|MinorSubsystemVersion
decl_stmt|;
comment|/* run exe; default to 3.1 */
name|long
name|Reserved1
decl_stmt|;
comment|/* seems to be 0 */
name|long
name|SizeOfImage
decl_stmt|;
comment|/* size of memory to allocate for prog */
name|long
name|SizeOfHeaders
decl_stmt|;
comment|/* size of PE header and section table */
name|long
name|CheckSum
decl_stmt|;
comment|/* set to 0 */
name|short
name|Subsystem
decl_stmt|;
comment|/* type of subsystem exe uses for user interface,      possible values:      1 - NATIVE   Doesn't require a subsystem      2 - WINDOWS_GUI runs in Windows GUI subsystem      3 - WINDOWS_CUI runs in Windows char sub. (console app)      5 - OS2_CUI runs in OS/2 character subsystem      7 - POSIX_CUI runs in Posix character subsystem */
name|short
name|DllCharacteristics
decl_stmt|;
comment|/* flags for DLL init, use 0 */
name|bfd_vma
name|SizeOfStackReserve
decl_stmt|;
comment|/* amount of memory to reserve  */
name|bfd_vma
name|SizeOfStackCommit
decl_stmt|;
comment|/* amount of memory initially committed for  				   initial thread's stack, default is 0x1000 */
name|bfd_vma
name|SizeOfHeapReserve
decl_stmt|;
comment|/* amount of virtual memory to reserve and */
name|bfd_vma
name|SizeOfHeapCommit
decl_stmt|;
comment|/* commit, don't know what to defaut it to */
name|long
name|LoaderFlags
decl_stmt|;
comment|/* can probably set to 0 */
name|long
name|NumberOfRvaAndSizes
decl_stmt|;
comment|/* number of entries in next entry, 16 */
name|IMAGE_DATA_DIRECTORY
name|DataDirectory
index|[
name|IMAGE_NUMBEROF_DIRECTORY_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
end_comment

begin_struct
struct|struct
name|internal_aouthdr
block|{
name|short
name|magic
decl_stmt|;
comment|/* type of file				*/
name|short
name|vstamp
decl_stmt|;
comment|/* version stamp			*/
name|bfd_vma
name|tsize
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|bfd_vma
name|dsize
decl_stmt|;
comment|/* initialized data "  "		*/
name|bfd_vma
name|bsize
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|bfd_vma
name|entry
decl_stmt|;
comment|/* entry pt.				*/
name|bfd_vma
name|text_start
decl_stmt|;
comment|/* base of text used for this file */
name|bfd_vma
name|data_start
decl_stmt|;
comment|/* base of data used for this file */
comment|/* i960 stuff */
name|unsigned
name|long
name|tagentries
decl_stmt|;
comment|/* number of tag entries to follow */
comment|/* RS/6000 stuff */
name|unsigned
name|long
name|o_toc
decl_stmt|;
comment|/* address of TOC			*/
name|short
name|o_snentry
decl_stmt|;
comment|/* section number for entry point */
name|short
name|o_sntext
decl_stmt|;
comment|/* section number for text	*/
name|short
name|o_sndata
decl_stmt|;
comment|/* section number for data	*/
name|short
name|o_sntoc
decl_stmt|;
comment|/* section number for toc	*/
name|short
name|o_snloader
decl_stmt|;
comment|/* section number for loader section */
name|short
name|o_snbss
decl_stmt|;
comment|/* section number for bss	*/
name|short
name|o_algntext
decl_stmt|;
comment|/* max alignment for text	*/
name|short
name|o_algndata
decl_stmt|;
comment|/* max alignment for data	*/
name|short
name|o_modtype
decl_stmt|;
comment|/* Module type field, 1R,RE,RO	*/
name|short
name|o_cputype
decl_stmt|;
comment|/* Encoded CPU type		*/
name|unsigned
name|long
name|o_maxstack
decl_stmt|;
comment|/* max stack size allowed.	*/
name|unsigned
name|long
name|o_maxdata
decl_stmt|;
comment|/* max data size allowed.	*/
comment|/* ECOFF stuff */
name|bfd_vma
name|bss_start
decl_stmt|;
comment|/* Base of bss section.		*/
name|bfd_vma
name|gp_value
decl_stmt|;
comment|/* GP register value.		*/
name|unsigned
name|long
name|gprmask
decl_stmt|;
comment|/* General registers used.	*/
name|unsigned
name|long
name|cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Coprocessor registers used.	*/
name|unsigned
name|long
name|fprmask
decl_stmt|;
comment|/* Floating pointer registers used.  */
comment|/* Apollo stuff */
name|long
name|o_inlib
decl_stmt|;
comment|/* inlib data */
name|long
name|o_sri
decl_stmt|;
comment|/* Static Resource Information */
name|long
name|vid
index|[
literal|2
index|]
decl_stmt|;
comment|/* Version id */
name|struct
name|internal_extra_pe_aouthdr
name|pe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** STORAGE CLASSES **********************/
end_comment

begin_comment
comment|/* This used to be defined as -1, but now n_sclass is unsigned.  */
end_comment

begin_define
define|#
directive|define
name|C_EFCN
value|0xff
end_define

begin_comment
comment|/* physical end of function	*/
end_comment

begin_define
define|#
directive|define
name|C_NULL
value|0
end_define

begin_define
define|#
directive|define
name|C_AUTO
value|1
end_define

begin_comment
comment|/* automatic variable		*/
end_comment

begin_define
define|#
directive|define
name|C_EXT
value|2
end_define

begin_comment
comment|/* external symbol		*/
end_comment

begin_define
define|#
directive|define
name|C_STAT
value|3
end_define

begin_comment
comment|/* static			*/
end_comment

begin_define
define|#
directive|define
name|C_REG
value|4
end_define

begin_comment
comment|/* register variable		*/
end_comment

begin_define
define|#
directive|define
name|C_EXTDEF
value|5
end_define

begin_comment
comment|/* external definition		*/
end_comment

begin_define
define|#
directive|define
name|C_LABEL
value|6
end_define

begin_comment
comment|/* label			*/
end_comment

begin_define
define|#
directive|define
name|C_ULABEL
value|7
end_define

begin_comment
comment|/* undefined label		*/
end_comment

begin_define
define|#
directive|define
name|C_MOS
value|8
end_define

begin_comment
comment|/* member of structure		*/
end_comment

begin_define
define|#
directive|define
name|C_ARG
value|9
end_define

begin_comment
comment|/* function argument		*/
end_comment

begin_define
define|#
directive|define
name|C_STRTAG
value|10
end_define

begin_comment
comment|/* structure tag		*/
end_comment

begin_define
define|#
directive|define
name|C_MOU
value|11
end_define

begin_comment
comment|/* member of union		*/
end_comment

begin_define
define|#
directive|define
name|C_UNTAG
value|12
end_define

begin_comment
comment|/* union tag			*/
end_comment

begin_define
define|#
directive|define
name|C_TPDEF
value|13
end_define

begin_comment
comment|/* type definition		*/
end_comment

begin_define
define|#
directive|define
name|C_USTATIC
value|14
end_define

begin_comment
comment|/* undefined static		*/
end_comment

begin_define
define|#
directive|define
name|C_ENTAG
value|15
end_define

begin_comment
comment|/* enumeration tag		*/
end_comment

begin_define
define|#
directive|define
name|C_MOE
value|16
end_define

begin_comment
comment|/* member of enumeration	*/
end_comment

begin_define
define|#
directive|define
name|C_REGPARM
value|17
end_define

begin_comment
comment|/* register parameter		*/
end_comment

begin_define
define|#
directive|define
name|C_FIELD
value|18
end_define

begin_comment
comment|/* bit field			*/
end_comment

begin_define
define|#
directive|define
name|C_AUTOARG
value|19
end_define

begin_comment
comment|/* auto argument		*/
end_comment

begin_define
define|#
directive|define
name|C_LASTENT
value|20
end_define

begin_comment
comment|/* dummy entry (end of block)	*/
end_comment

begin_define
define|#
directive|define
name|C_BLOCK
value|100
end_define

begin_comment
comment|/* ".bb" or ".eb"		*/
end_comment

begin_define
define|#
directive|define
name|C_FCN
value|101
end_define

begin_comment
comment|/* ".bf" or ".ef"		*/
end_comment

begin_define
define|#
directive|define
name|C_EOS
value|102
end_define

begin_comment
comment|/* end of structure		*/
end_comment

begin_define
define|#
directive|define
name|C_FILE
value|103
end_define

begin_comment
comment|/* file name			*/
end_comment

begin_define
define|#
directive|define
name|C_LINE
value|104
end_define

begin_comment
comment|/* line # reformatted as symbol table entry */
end_comment

begin_define
define|#
directive|define
name|C_ALIAS
value|105
end_define

begin_comment
comment|/* duplicate tag		*/
end_comment

begin_define
define|#
directive|define
name|C_HIDDEN
value|106
end_define

begin_comment
comment|/* ext symbol in dmert public lib */
end_comment

begin_comment
comment|/* New storage classes for WINDOWS_NT   */
end_comment

begin_define
define|#
directive|define
name|C_SECTION
value|104
end_define

begin_comment
comment|/* section name */
end_comment

begin_define
define|#
directive|define
name|C_NT_WEAK
value|105
end_define

begin_comment
comment|/* weak external */
end_comment

begin_comment
comment|/* New storage classes for 80960 */
end_comment

begin_comment
comment|/* C_LEAFPROC is obsolete.  Use C_LEAFEXT or C_LEAFSTAT */
end_comment

begin_define
define|#
directive|define
name|C_LEAFPROC
value|108
end_define

begin_comment
comment|/* Leaf procedure, "call" via BAL */
end_comment

begin_define
define|#
directive|define
name|C_SCALL
value|107
end_define

begin_comment
comment|/* Procedure reachable via system call */
end_comment

begin_define
define|#
directive|define
name|C_LEAFEXT
value|108
end_define

begin_comment
comment|/* External leaf */
end_comment

begin_define
define|#
directive|define
name|C_LEAFSTAT
value|113
end_define

begin_comment
comment|/* Static leaf */
end_comment

begin_define
define|#
directive|define
name|C_OPTVAR
value|109
end_define

begin_comment
comment|/* Optimized variable		*/
end_comment

begin_define
define|#
directive|define
name|C_DEFINE
value|110
end_define

begin_comment
comment|/* Preprocessor #define		*/
end_comment

begin_define
define|#
directive|define
name|C_PRAGMA
value|111
end_define

begin_comment
comment|/* Advice to compiler or linker	*/
end_comment

begin_define
define|#
directive|define
name|C_SEGMENT
value|112
end_define

begin_comment
comment|/* 80960 segment name		*/
end_comment

begin_comment
comment|/* Storage classes for m88k */
end_comment

begin_define
define|#
directive|define
name|C_SHADOW
value|107
end_define

begin_comment
comment|/* shadow symbol                */
end_comment

begin_define
define|#
directive|define
name|C_VERSION
value|108
end_define

begin_comment
comment|/* coff version symbol          */
end_comment

begin_comment
comment|/* New storage classes for RS/6000 */
end_comment

begin_define
define|#
directive|define
name|C_HIDEXT
value|107
end_define

begin_comment
comment|/* Un-named external symbol */
end_comment

begin_define
define|#
directive|define
name|C_BINCL
value|108
end_define

begin_comment
comment|/* Marks beginning of include file */
end_comment

begin_define
define|#
directive|define
name|C_EINCL
value|109
end_define

begin_comment
comment|/* Marks ending of include file */
end_comment

begin_comment
comment|/* storage classes for stab symbols for RS/6000 */
end_comment

begin_define
define|#
directive|define
name|C_GSYM
value|(0x80)
end_define

begin_define
define|#
directive|define
name|C_LSYM
value|(0x81)
end_define

begin_define
define|#
directive|define
name|C_PSYM
value|(0x82)
end_define

begin_define
define|#
directive|define
name|C_RSYM
value|(0x83)
end_define

begin_define
define|#
directive|define
name|C_RPSYM
value|(0x84)
end_define

begin_define
define|#
directive|define
name|C_STSYM
value|(0x85)
end_define

begin_define
define|#
directive|define
name|C_TCSYM
value|(0x86)
end_define

begin_define
define|#
directive|define
name|C_BCOMM
value|(0x87)
end_define

begin_define
define|#
directive|define
name|C_ECOML
value|(0x88)
end_define

begin_define
define|#
directive|define
name|C_ECOMM
value|(0x89)
end_define

begin_define
define|#
directive|define
name|C_DECL
value|(0x8c)
end_define

begin_define
define|#
directive|define
name|C_ENTRY
value|(0x8d)
end_define

begin_define
define|#
directive|define
name|C_FUN
value|(0x8e)
end_define

begin_define
define|#
directive|define
name|C_BSTAT
value|(0x8f)
end_define

begin_define
define|#
directive|define
name|C_ESTAT
value|(0x90)
end_define

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_define
define|#
directive|define
name|SCNNMLEN
value|(8)
end_define

begin_struct
struct|struct
name|internal_scnhdr
block|{
name|char
name|s_name
index|[
name|SCNNMLEN
index|]
decl_stmt|;
comment|/* section name			*/
comment|/* Physical address, aliased s_nlib.      In the pei format, this field is the virtual section size      (the size of the section after being loaded int memory),      NOT the physical address.  */
name|bfd_vma
name|s_paddr
decl_stmt|;
name|bfd_vma
name|s_vaddr
decl_stmt|;
comment|/* virtual address		*/
name|bfd_vma
name|s_size
decl_stmt|;
comment|/* section size			*/
name|bfd_vma
name|s_scnptr
decl_stmt|;
comment|/* file ptr to raw data for section */
name|bfd_vma
name|s_relptr
decl_stmt|;
comment|/* file ptr to relocation	*/
name|bfd_vma
name|s_lnnoptr
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|unsigned
name|long
name|s_nreloc
decl_stmt|;
comment|/* number of relocation entries	*/
name|unsigned
name|long
name|s_nlnno
decl_stmt|;
comment|/* number of line number entries*/
name|long
name|s_flags
decl_stmt|;
comment|/* flags			*/
name|long
name|s_align
decl_stmt|;
comment|/* used on I960			*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * s_flags "type"  */
end_comment

begin_define
define|#
directive|define
name|STYP_REG
value|(0x0000)
end_define

begin_comment
comment|/* "regular": allocated, relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_DSECT
value|(0x0001)
end_define

begin_comment
comment|/* "dummy":  relocated only*/
end_comment

begin_define
define|#
directive|define
name|STYP_NOLOAD
value|(0x0002)
end_define

begin_comment
comment|/* "noload": allocated, relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_GROUP
value|(0x0004)
end_define

begin_comment
comment|/* "grouped": formed of input sections */
end_comment

begin_define
define|#
directive|define
name|STYP_PAD
value|(0x0008)
end_define

begin_comment
comment|/* "padding": not allocated, not relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_COPY
value|(0x0010)
end_define

begin_comment
comment|/* "copy": for decision function used by field update;  not allocated, not relocated, 									     loaded; reloc& lineno entries processed normally */
end_comment

begin_define
define|#
directive|define
name|STYP_TEXT
value|(0x0020)
end_define

begin_comment
comment|/* section contains text only */
end_comment

begin_define
define|#
directive|define
name|S_SHRSEG
value|(0x0020)
end_define

begin_comment
comment|/* In 3b Update files (output of ogen), sections which appear in SHARED segments of the Pfile 									     will have the S_SHRSEG flag set by ogen, to inform dufr that updating 1 copy of the proc. will 									     update all process invocations. */
end_comment

begin_define
define|#
directive|define
name|STYP_DATA
value|(0x0040)
end_define

begin_comment
comment|/* section contains data only */
end_comment

begin_define
define|#
directive|define
name|STYP_BSS
value|(0x0080)
end_define

begin_comment
comment|/* section contains bss only */
end_comment

begin_define
define|#
directive|define
name|S_NEWFCN
value|(0x0100)
end_define

begin_comment
comment|/* In a minimal file or an update file, a new function (as compared with a replaced function) */
end_comment

begin_define
define|#
directive|define
name|STYP_INFO
value|(0x0200)
end_define

begin_comment
comment|/* comment: not allocated not relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_OVER
value|(0x0400)
end_define

begin_comment
comment|/* overlay: relocated not allocated or loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_LIB
value|(0x0800)
end_define

begin_comment
comment|/* for .lib: same as INFO */
end_comment

begin_define
define|#
directive|define
name|STYP_MERGE
value|(0x2000)
end_define

begin_comment
comment|/* merge section -- combines with text, data or bss sections only */
end_comment

begin_define
define|#
directive|define
name|STYP_REVERSE_PAD
value|(0x4000)
end_define

begin_comment
comment|/* section will be padded with no-op instructions wherever padding is necessary and there is a 					 									     word of contiguous bytes 									     beginning on a word boundary. */
end_comment

begin_define
define|#
directive|define
name|STYP_LIT
value|0x8020
end_define

begin_comment
comment|/* Literal data (like STYP_TEXT) */
end_comment

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_comment
comment|/* 1 line number entry for every "breakpointable" source line in a section.  * Line numbers are grouped on a per function basis; first entry in a function  * grouping will have l_lnno = 0 and in place of physical address will be the  * symbol table index of the function name.  */
end_comment

begin_struct
struct|struct
name|internal_lineno
block|{
union|union
block|{
name|long
name|l_symndx
decl_stmt|;
comment|/* function name symbol index, iff l_lnno == 0*/
name|long
name|l_paddr
decl_stmt|;
comment|/* (physical) address of line number	*/
block|}
name|l_addr
union|;
name|unsigned
name|long
name|l_lnno
decl_stmt|;
comment|/* line number		*/
block|}
struct|;
end_struct

begin_comment
comment|/********************** SYMBOLS **********************/
end_comment

begin_define
define|#
directive|define
name|SYMNMLEN
value|8
end_define

begin_comment
comment|/* # characters in a symbol name	*/
end_comment

begin_define
define|#
directive|define
name|FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name		*/
end_comment

begin_define
define|#
directive|define
name|DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_struct
struct|struct
name|internal_syment
block|{
union|union
block|{
name|char
name|_n_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
comment|/* old COFF version	*/
struct|struct
block|{
name|long
name|_n_zeroes
decl_stmt|;
comment|/* new == 0		*/
name|long
name|_n_offset
decl_stmt|;
comment|/* offset into string table */
block|}
name|_n_n
struct|;
name|char
modifier|*
name|_n_nptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* allows for overlaying	*/
block|}
name|_n
union|;
name|long
name|n_value
decl_stmt|;
comment|/* value of symbol		*/
name|short
name|n_scnum
decl_stmt|;
comment|/* section number		*/
name|unsigned
name|short
name|n_flags
decl_stmt|;
comment|/* copy of flags from filhdr	*/
name|unsigned
name|short
name|n_type
decl_stmt|;
comment|/* type and derived type	*/
name|unsigned
name|char
name|n_sclass
decl_stmt|;
comment|/* storage class		*/
name|unsigned
name|char
name|n_numaux
decl_stmt|;
comment|/* number of aux. entries	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_name
value|_n._n_name
end_define

begin_define
define|#
directive|define
name|n_zeroes
value|_n._n_n._n_zeroes
end_define

begin_define
define|#
directive|define
name|n_offset
value|_n._n_n._n_offset
end_define

begin_comment
comment|/* Relocatable symbols have number of the section in which they are defined,    or one of the following: */
end_comment

begin_define
define|#
directive|define
name|N_UNDEF
value|((short)0)
end_define

begin_comment
comment|/* undefined symbol */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|((short)-1)
end_define

begin_comment
comment|/* value of symbol is absolute */
end_comment

begin_define
define|#
directive|define
name|N_DEBUG
value|((short)-2)
end_define

begin_comment
comment|/* debugging symbol -- value is meaningless */
end_comment

begin_define
define|#
directive|define
name|N_TV
value|((short)-3)
end_define

begin_comment
comment|/* indicates symbol needs preload transfer vector */
end_comment

begin_define
define|#
directive|define
name|P_TV
value|((short)-4)
end_define

begin_comment
comment|/* indicates symbol needs postload transfer vector*/
end_comment

begin_comment
comment|/*  * Type of a symbol, in low N bits of the word  */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|0
end_define

begin_define
define|#
directive|define
name|T_VOID
value|1
end_define

begin_comment
comment|/* function argument (only used by compiler) */
end_comment

begin_define
define|#
directive|define
name|T_CHAR
value|2
end_define

begin_comment
comment|/* character		*/
end_comment

begin_define
define|#
directive|define
name|T_SHORT
value|3
end_define

begin_comment
comment|/* short integer	*/
end_comment

begin_define
define|#
directive|define
name|T_INT
value|4
end_define

begin_comment
comment|/* integer		*/
end_comment

begin_define
define|#
directive|define
name|T_LONG
value|5
end_define

begin_comment
comment|/* long integer		*/
end_comment

begin_define
define|#
directive|define
name|T_FLOAT
value|6
end_define

begin_comment
comment|/* floating point	*/
end_comment

begin_define
define|#
directive|define
name|T_DOUBLE
value|7
end_define

begin_comment
comment|/* double word		*/
end_comment

begin_define
define|#
directive|define
name|T_STRUCT
value|8
end_define

begin_comment
comment|/* structure 		*/
end_comment

begin_define
define|#
directive|define
name|T_UNION
value|9
end_define

begin_comment
comment|/* union 		*/
end_comment

begin_define
define|#
directive|define
name|T_ENUM
value|10
end_define

begin_comment
comment|/* enumeration 		*/
end_comment

begin_define
define|#
directive|define
name|T_MOE
value|11
end_define

begin_comment
comment|/* member of enumeration*/
end_comment

begin_define
define|#
directive|define
name|T_UCHAR
value|12
end_define

begin_comment
comment|/* unsigned character	*/
end_comment

begin_define
define|#
directive|define
name|T_USHORT
value|13
end_define

begin_comment
comment|/* unsigned short	*/
end_comment

begin_define
define|#
directive|define
name|T_UINT
value|14
end_define

begin_comment
comment|/* unsigned integer	*/
end_comment

begin_define
define|#
directive|define
name|T_ULONG
value|15
end_define

begin_comment
comment|/* unsigned long	*/
end_comment

begin_define
define|#
directive|define
name|T_LNGDBL
value|16
end_define

begin_comment
comment|/* long double		*/
end_comment

begin_comment
comment|/*  * derived types, in n_type */
end_comment

begin_define
define|#
directive|define
name|DT_NON
value|(0)
end_define

begin_comment
comment|/* no derived type */
end_comment

begin_define
define|#
directive|define
name|DT_PTR
value|(1)
end_define

begin_comment
comment|/* pointer */
end_comment

begin_define
define|#
directive|define
name|DT_FCN
value|(2)
end_define

begin_comment
comment|/* function */
end_comment

begin_define
define|#
directive|define
name|DT_ARY
value|(3)
end_define

begin_comment
comment|/* array */
end_comment

begin_define
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& N_BTMASK)
end_define

begin_define
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_PTR<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISFCN
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_FCN<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_ARY<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISTAG
parameter_list|(
name|x
parameter_list|)
value|((x)==C_STRTAG||(x)==C_UNTAG||(x)==C_ENTAG)
end_define

begin_define
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
end_define

begin_union
union|union
name|internal_auxent
block|{
struct|struct
block|{
union|union
block|{
name|long
name|l
decl_stmt|;
comment|/* str, un, or enum tag indx */
name|struct
name|coff_ptr_struct
modifier|*
name|p
decl_stmt|;
block|}
name|x_tagndx
union|;
union|union
block|{
struct|struct
block|{
name|unsigned
name|short
name|x_lnno
decl_stmt|;
comment|/* declaration line number */
name|unsigned
name|short
name|x_size
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
name|long
name|x_fsize
decl_stmt|;
comment|/* size of function */
block|}
name|x_misc
union|;
union|union
block|{
struct|struct
block|{
comment|/* if ISFCN, tag, or .bb */
name|long
name|x_lnnoptr
decl_stmt|;
comment|/* ptr to fcn line # */
union|union
block|{
comment|/* entry ndx past block end */
name|long
name|l
decl_stmt|;
name|struct
name|coff_ptr_struct
modifier|*
name|p
decl_stmt|;
block|}
name|x_endndx
union|;
block|}
name|x_fcn
struct|;
struct|struct
block|{
comment|/* if ISARY, up to 4 dimen. */
name|unsigned
name|short
name|x_dimen
index|[
name|DIMNUM
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|unsigned
name|short
name|x_tvndx
decl_stmt|;
comment|/* tv index */
block|}
name|x_sym
struct|;
union|union
block|{
name|char
name|x_fname
index|[
name|FILNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|long
name|x_zeroes
decl_stmt|;
name|long
name|x_offset
decl_stmt|;
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|long
name|x_scnlen
decl_stmt|;
comment|/* section length */
name|unsigned
name|short
name|x_nreloc
decl_stmt|;
comment|/* # relocation entries */
name|unsigned
name|short
name|x_nlinno
decl_stmt|;
comment|/* # line numbers */
name|unsigned
name|long
name|x_checksum
decl_stmt|;
comment|/* section COMDAT checksum for PE */
name|unsigned
name|short
name|x_associated
decl_stmt|;
comment|/* COMDAT associated section index for PE */
name|unsigned
name|char
name|x_comdat
decl_stmt|;
comment|/* COMDAT selection number for PE */
block|}
name|x_scn
struct|;
struct|struct
block|{
name|long
name|x_tvfill
decl_stmt|;
comment|/* tv fill value */
name|unsigned
name|short
name|x_tvlen
decl_stmt|;
comment|/* length of .tv */
name|unsigned
name|short
name|x_tvran
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv range */
block|}
name|x_tv
struct|;
comment|/* info about .tv section (in auxent of symbol .tv)) */
comment|/******************************************    * RS/6000-specific auxent - last auxent for every external symbol    ******************************************/
struct|struct
block|{
union|union
block|{
comment|/* csect length or enclosing csect */
name|long
name|l
decl_stmt|;
name|struct
name|coff_ptr_struct
modifier|*
name|p
decl_stmt|;
block|}
name|x_scnlen
union|;
name|long
name|x_parmhash
decl_stmt|;
comment|/* parm type hash index */
name|unsigned
name|short
name|x_snhash
decl_stmt|;
comment|/* sect num with parm hash */
name|unsigned
name|char
name|x_smtyp
decl_stmt|;
comment|/* symbol align and type */
comment|/* 0-4 - Log 2 of alignment */
comment|/* 5-7 - symbol type */
name|unsigned
name|char
name|x_smclas
decl_stmt|;
comment|/* storage mapping class */
name|long
name|x_stab
decl_stmt|;
comment|/* dbx stab info index */
name|unsigned
name|short
name|x_snstab
decl_stmt|;
comment|/* sect num with dbx stab */
block|}
name|x_csect
struct|;
comment|/* csect definition information */
comment|/* x_smtyp values:  */
define|#
directive|define
name|SMTYP_ALIGN
parameter_list|(
name|x
parameter_list|)
value|((x)>> 3)
comment|/* log2 of alignment */
define|#
directive|define
name|SMTYP_SMTYP
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
comment|/* symbol type */
comment|/* Symbol type values:  */
define|#
directive|define
name|XTY_ER
value|0
comment|/* External reference */
define|#
directive|define
name|XTY_SD
value|1
comment|/* Csect definition */
define|#
directive|define
name|XTY_LD
value|2
comment|/* Label definition */
define|#
directive|define
name|XTY_CM
value|3
comment|/* .BSS */
define|#
directive|define
name|XTY_EM
value|4
comment|/* Error message */
define|#
directive|define
name|XTY_US
value|5
comment|/* "Reserved for internal use" */
comment|/* x_smclas values:  */
define|#
directive|define
name|XMC_PR
value|0
comment|/* Read-only program code */
define|#
directive|define
name|XMC_RO
value|1
comment|/* Read-only constant */
define|#
directive|define
name|XMC_DB
value|2
comment|/* Read-only debug dictionary table */
define|#
directive|define
name|XMC_TC
value|3
comment|/* Read-write general TOC entry */
define|#
directive|define
name|XMC_UA
value|4
comment|/* Read-write unclassified */
define|#
directive|define
name|XMC_RW
value|5
comment|/* Read-write data */
define|#
directive|define
name|XMC_GL
value|6
comment|/* Read-only global linkage */
define|#
directive|define
name|XMC_XO
value|7
comment|/* Read-only extended operation */
define|#
directive|define
name|XMC_SV
value|8
comment|/* Read-only supervisor call */
define|#
directive|define
name|XMC_BS
value|9
comment|/* Read-write BSS */
define|#
directive|define
name|XMC_DS
value|10
comment|/* Read-write descriptor csect */
define|#
directive|define
name|XMC_UC
value|11
comment|/* Read-write unnamed Fortran common */
define|#
directive|define
name|XMC_TI
value|12
comment|/* Read-only traceback index csect */
define|#
directive|define
name|XMC_TB
value|13
comment|/* Read-only traceback table csect */
comment|/* 		14	??? */
define|#
directive|define
name|XMC_TC0
value|15
comment|/* Read-write TOC anchor */
define|#
directive|define
name|XMC_TD
value|16
comment|/* Read-write data in TOC */
comment|/******************************************    *  I960-specific *2nd* aux. entry formats    ******************************************/
struct|struct
block|{
comment|/* This is a very old typo that keeps getting propagated. */
define|#
directive|define
name|x_stdindx
value|x_stindx
name|long
name|x_stindx
decl_stmt|;
comment|/* sys. table entry */
block|}
name|x_sc
struct|;
comment|/* system call entry */
struct|struct
block|{
name|unsigned
name|long
name|x_balntry
decl_stmt|;
comment|/* BAL entry point */
block|}
name|x_bal
struct|;
comment|/* BAL-callable function */
struct|struct
block|{
name|unsigned
name|long
name|x_timestamp
decl_stmt|;
comment|/* time stamp */
name|char
name|x_idstring
index|[
literal|20
index|]
decl_stmt|;
comment|/* producer identity string */
block|}
name|x_ident
struct|;
comment|/* Producer ident info */
block|}
union|;
end_union

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|internal_reloc
block|{
name|bfd_vma
name|r_vaddr
decl_stmt|;
comment|/* Virtual address of reference */
name|long
name|r_symndx
decl_stmt|;
comment|/* Index into symbol table	*/
name|unsigned
name|short
name|r_type
decl_stmt|;
comment|/* Relocation type		*/
name|unsigned
name|char
name|r_size
decl_stmt|;
comment|/* Used by RS/6000 and ECOFF	*/
name|unsigned
name|char
name|r_extern
decl_stmt|;
comment|/* Used by ECOFF		*/
name|unsigned
name|long
name|r_offset
decl_stmt|;
comment|/* Used by Alpha ECOFF, SPARC, others */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|R_RELBYTE
value|017
end_define

begin_define
define|#
directive|define
name|R_RELWORD
value|020
end_define

begin_define
define|#
directive|define
name|R_PCRBYTE
value|022
end_define

begin_define
define|#
directive|define
name|R_PCRWORD
value|023
end_define

begin_define
define|#
directive|define
name|R_PCRLONG
value|024
end_define

begin_define
define|#
directive|define
name|R_DIR16
value|01
end_define

begin_define
define|#
directive|define
name|R_DIR32
value|06
end_define

begin_define
define|#
directive|define
name|R_PCLONG
value|020
end_define

begin_define
define|#
directive|define
name|R_RELBYTE
value|017
end_define

begin_define
define|#
directive|define
name|R_RELWORD
value|020
end_define

begin_define
define|#
directive|define
name|R_IMAGEBASE
value|07
end_define

begin_define
define|#
directive|define
name|R_PCR16L
value|128
end_define

begin_define
define|#
directive|define
name|R_PCR26L
value|129
end_define

begin_define
define|#
directive|define
name|R_VRT16
value|130
end_define

begin_define
define|#
directive|define
name|R_HVRT16
value|131
end_define

begin_define
define|#
directive|define
name|R_LVRT16
value|132
end_define

begin_define
define|#
directive|define
name|R_VRT32
value|133
end_define

begin_define
define|#
directive|define
name|R_RELLONG
value|(0x11)
end_define

begin_comment
comment|/* Direct 32-bit relocation */
end_comment

begin_define
define|#
directive|define
name|R_IPRSHORT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|R_IPRLONG
value|(0x1a)
end_define

begin_define
define|#
directive|define
name|R_GETSEG
value|(0x1d)
end_define

begin_define
define|#
directive|define
name|R_GETPA
value|(0x1e)
end_define

begin_define
define|#
directive|define
name|R_TAGWORD
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|R_JUMPTARG
value|0x20
end_define

begin_comment
comment|/* strange 29k 00xx00xx reloc */
end_comment

begin_comment
comment|/* This reloc identifies mov.b instructions with a 16bit absolute    address.  The linker tries to turn insns with this reloc into    an absolute 8-bit address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOV16B1
value|0x41
end_define

begin_comment
comment|/* This reloc identifies mov.b instructions which had a 16bit    absolute address which have been shortened into a 8-bit    absolute address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOV16B2
value|0x42
end_define

begin_comment
comment|/* This reloc identifies jmp insns with a 16bit target address;    the linker tries to turn these insns into bra insns with    an 8bit pc-relative target.  */
end_comment

begin_define
define|#
directive|define
name|R_JMP1
value|0x43
end_define

begin_comment
comment|/* This reloc identifies a bra with an 8-bit pc-relative    target that was formerlly a jmp insn with a 16bit target.  */
end_comment

begin_define
define|#
directive|define
name|R_JMP2
value|0x44
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|R_RELLONG_NEG
value|0x45
end_define

begin_comment
comment|/* This reloc identifies jmp insns with a 24bit target address;    the linker tries to turn these insns into bra insns with    an 8bit pc-relative target.  */
end_comment

begin_define
define|#
directive|define
name|R_JMPL1
value|0x46
end_define

begin_comment
comment|/* This reloc identifies a bra with an 8-bit pc-relative    target that was formerlly a jmp insn with a 24bit target.  */
end_comment

begin_define
define|#
directive|define
name|R_JMPL2
value|0x47
end_define

begin_comment
comment|/* This reloc identifies mov.b instructions with a 24bit absolute    address.  The linker tries to turn insns with this reloc into    an absolute 8-bit address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOV24B1
value|0x48
end_define

begin_comment
comment|/* This reloc identifies mov.b instructions which had a 24bit    absolute address which have been shortened into a 8-bit    absolute address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOV24B2
value|0x49
end_define

begin_comment
comment|/* An h8300 memory indirect jump/call.  Forces the address of the jump/call    target into the function vector (in page zero), and the address of the    vector entry to be placed in the jump/call instruction.  */
end_comment

begin_define
define|#
directive|define
name|R_MEM_INDIRECT
value|0x4a
end_define

begin_comment
comment|/* This reloc identifies a 16bit pc-relative branch target which was    shortened into an 8bit pc-relative branch target.  */
end_comment

begin_define
define|#
directive|define
name|R_PCRWORD_B
value|0x4b
end_define

begin_comment
comment|/* This reloc identifies mov.[wl] instructions with a 32/24 bit    absolute address; the linker may turn this into a mov.[wl]    insn with a 16bit absolute address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOVL1
value|0x4c
end_define

begin_comment
comment|/* This reloc identifies mov.[wl] insns which formerlly had    a 32/24bit absolute address and how have a 16bit absolute address.  */
end_comment

begin_define
define|#
directive|define
name|R_MOVL2
value|0x4d
end_define

begin_comment
comment|/* This reloc identifies a bCC:8 which will have it's condition    inverted and its target redirected to the target of the branch    in the following insn.  */
end_comment

begin_define
define|#
directive|define
name|R_BCC_INV
value|0x4e
end_define

begin_comment
comment|/* This reloc identifies a jmp instruction that has been deleted.  */
end_comment

begin_define
define|#
directive|define
name|R_JMP_DEL
value|0x4f
end_define

begin_comment
comment|/* Z8k modes */
end_comment

begin_define
define|#
directive|define
name|R_IMM16
value|0x01
end_define

begin_comment
comment|/* 16 bit abs */
end_comment

begin_define
define|#
directive|define
name|R_JR
value|0x02
end_define

begin_comment
comment|/* jr  8 bit disp */
end_comment

begin_define
define|#
directive|define
name|R_IMM4L
value|0x23
end_define

begin_comment
comment|/* low nibble */
end_comment

begin_define
define|#
directive|define
name|R_IMM8
value|0x22
end_define

begin_comment
comment|/* 8 bit abs */
end_comment

begin_define
define|#
directive|define
name|R_IMM32
value|R_RELLONG
end_define

begin_comment
comment|/* 32 bit abs */
end_comment

begin_define
define|#
directive|define
name|R_CALL
value|R_DA
end_define

begin_comment
comment|/* Absolute address which could be a callr */
end_comment

begin_define
define|#
directive|define
name|R_JP
value|R_DA
end_define

begin_comment
comment|/* Absolute address which could be a jp */
end_comment

begin_define
define|#
directive|define
name|R_REL16
value|0x04
end_define

begin_comment
comment|/* 16 bit PC rel */
end_comment

begin_define
define|#
directive|define
name|R_CALLR
value|0x05
end_define

begin_comment
comment|/* callr 12 bit disp */
end_comment

begin_define
define|#
directive|define
name|R_SEG
value|0x10
end_define

begin_comment
comment|/* set if in segmented mode */
end_comment

begin_define
define|#
directive|define
name|R_IMM4H
value|0x24
end_define

begin_comment
comment|/* high nibble */
end_comment

begin_define
define|#
directive|define
name|R_DISP7
value|0x25
end_define

begin_comment
comment|/* djnz displacement */
end_comment

begin_comment
comment|/* H8500 modes */
end_comment

begin_define
define|#
directive|define
name|R_H8500_IMM8
value|1
end_define

begin_comment
comment|/*  8 bit immediate 	*/
end_comment

begin_define
define|#
directive|define
name|R_H8500_IMM16
value|2
end_define

begin_comment
comment|/* 16 bit immediate	*/
end_comment

begin_define
define|#
directive|define
name|R_H8500_PCREL8
value|3
end_define

begin_comment
comment|/*  8 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_H8500_PCREL16
value|4
end_define

begin_comment
comment|/* 16 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_H8500_HIGH8
value|5
end_define

begin_comment
comment|/* high 8 bits of 24 bit address */
end_comment

begin_define
define|#
directive|define
name|R_H8500_LOW16
value|7
end_define

begin_comment
comment|/* low 16 bits of 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_H8500_IMM24
value|6
end_define

begin_comment
comment|/* 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_H8500_IMM32
value|8
end_define

begin_comment
comment|/* 32 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_H8500_HIGH16
value|9
end_define

begin_comment
comment|/* high 16 bits of 32 bit immediate */
end_comment

begin_comment
comment|/* W65 modes */
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS8
value|1
end_define

begin_comment
comment|/* addr& 0xff 		*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS16
value|2
end_define

begin_comment
comment|/* addr& 0xffff 		*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS24
value|3
end_define

begin_comment
comment|/* addr& 0xffffff 		*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS8S8
value|4
end_define

begin_comment
comment|/* (addr>> 8)& 0xff 	*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS8S16
value|5
end_define

begin_comment
comment|/* (addr>> 16)& 0xff 	*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS16S8
value|6
end_define

begin_comment
comment|/* (addr>> 8)& 0ffff 	*/
end_comment

begin_define
define|#
directive|define
name|R_W65_ABS16S16
value|7
end_define

begin_comment
comment|/* (addr>> 16)& 0ffff 	*/
end_comment

begin_define
define|#
directive|define
name|R_W65_PCR8
value|8
end_define

begin_define
define|#
directive|define
name|R_W65_PCR16
value|9
end_define

begin_define
define|#
directive|define
name|R_W65_DP
value|10
end_define

begin_comment
comment|/* direct page 8 bits only   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU_COFF_INTERNAL_H */
end_comment

end_unit

