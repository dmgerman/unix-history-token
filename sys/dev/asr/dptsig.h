begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000-2001 Adaptec Corporation.  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DPTSIG_H_
end_ifndef

begin_define
define|#
directive|define
name|__DPTSIG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_SINIX_ADDON
end_ifdef

begin_include
include|#
directive|include
file|"dpt.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DPT SIGNATURE SPEC AND HEADER FILE                           */
end_comment

begin_comment
comment|/* Signature Version 1 (sorry no 'A')                           */
end_comment

begin_comment
comment|/* to make sure we are talking the same size under all OS's     */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|sigBYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|sigWORD
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_MULTI_DATAMODEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ILP32
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|uint32_t
name|sigLONG
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|sigLONG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * use sigWORDLittleEndian for:  *  dsCapabilities  *  dsDeviceSupp  *  dsAdapterSupp  *  dsApplication  * use sigLONGLittleEndian for:  *      dsOS  * so that the sig can be standardised to Little Endian  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|sigWORDLittleEndian
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<8)|(((x)>>8)&0xFF))
end_define

begin_define
define|#
directive|define
name|sigLONGLittleEndian
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)&0xFF)<<24) |             \          (((x)&0xFF00)<<8) |    \          (((x)&0xFF0000L)>>8) | \          (((x)&0xFF000000L)>>24))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sigWORDLittleEndian
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|sigLONGLittleEndian
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* must make sure the structure is not word or double-word aligned      */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------      */
end_comment

begin_comment
comment|/* Borland will ignore the following pragma:                            */
end_comment

begin_comment
comment|/* Word alignment is OFF by default.  If in the, IDE make               */
end_comment

begin_comment
comment|/* sure that Options | Compiler | Code Generation | Word Alignment      */
end_comment

begin_comment
comment|/* is not checked.  If using BCC, do not use the -a option.             */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_PACK
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_AIX
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|packed
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For the Macintosh */
end_comment

begin_if
if|#
directive|if
name|STRUCTALIGNMENTSUPPORTED
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|mac68k
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Current Signature Version - sigBYTE dsSigVersion; */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|SIG_VERSION
value|1
end_define

begin_comment
comment|/* Processor Family - sigBYTE dsProcessorFamily;  DISTINCT VALUES */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* What type of processor the file is meant to run on. */
end_comment

begin_comment
comment|/* This will let us know whether to read sigWORDs as high/low or low/high. */
end_comment

begin_define
define|#
directive|define
name|PROC_INTEL
value|0x00
end_define

begin_comment
comment|/* Intel 80x86 */
end_comment

begin_define
define|#
directive|define
name|PROC_MOTOROLA
value|0x01
end_define

begin_comment
comment|/* Motorola 68K */
end_comment

begin_define
define|#
directive|define
name|PROC_MIPS4000
value|0x02
end_define

begin_comment
comment|/* MIPS RISC 4000 */
end_comment

begin_define
define|#
directive|define
name|PROC_MIPS
value|PROC_MIPS4000
end_define

begin_comment
comment|/* MIPS RISC */
end_comment

begin_define
define|#
directive|define
name|PROC_ALPHA
value|0x03
end_define

begin_comment
comment|/* DEC Alpha */
end_comment

begin_define
define|#
directive|define
name|PROC_POWERPC
value|0x04
end_define

begin_comment
comment|/* IBM Power PC */
end_comment

begin_define
define|#
directive|define
name|PROC_i960
value|0x05
end_define

begin_comment
comment|/* Intel i960 */
end_comment

begin_define
define|#
directive|define
name|PROC_ULTRASPARC
value|0x06
end_define

begin_comment
comment|/* SPARC processor */
end_comment

begin_comment
comment|/* Specific Minimim Processor - sigBYTE dsProcessor;    FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Different bit definitions dependent on processor_family */
end_comment

begin_comment
comment|/* PROC_INTEL: */
end_comment

begin_define
define|#
directive|define
name|PROC_8086
value|0x01
end_define

begin_comment
comment|/* Intel 8086 */
end_comment

begin_define
define|#
directive|define
name|PROC_286
value|0x02
end_define

begin_comment
comment|/* Intel 80286 */
end_comment

begin_define
define|#
directive|define
name|PROC_386
value|0x04
end_define

begin_comment
comment|/* Intel 80386 */
end_comment

begin_define
define|#
directive|define
name|PROC_486
value|0x08
end_define

begin_comment
comment|/* Intel 80486 */
end_comment

begin_define
define|#
directive|define
name|PROC_PENTIUM
value|0x10
end_define

begin_comment
comment|/* Intel 586 aka P5 aka Pentium */
end_comment

begin_define
define|#
directive|define
name|PROC_SEXIUM
value|0x20
end_define

begin_comment
comment|/* Intel 686 aka P6 aka Pentium Pro or MMX */
end_comment

begin_define
define|#
directive|define
name|PROC_ITANIUM
value|0x40
end_define

begin_comment
comment|/* Intel Itanium 64 bit */
end_comment

begin_comment
comment|/* PROC_i960: */
end_comment

begin_define
define|#
directive|define
name|PROC_960RX
value|0x01
end_define

begin_comment
comment|/* Intel 80960RP/RD */
end_comment

begin_define
define|#
directive|define
name|PROC_960HX
value|0x02
end_define

begin_comment
comment|/* Intel 80960HA/HD/HT */
end_comment

begin_define
define|#
directive|define
name|PROC_960RN
value|0x03
end_define

begin_comment
comment|/* Intel 80960RN/RM */
end_comment

begin_define
define|#
directive|define
name|PROC_960RS
value|0x04
end_define

begin_comment
comment|/* Intel 80960RS */
end_comment

begin_define
define|#
directive|define
name|PROC_80303
value|0x05
end_define

begin_comment
comment|/* Intel 80303 (ZION) */
end_comment

begin_comment
comment|/* PROC_MOTOROLA: */
end_comment

begin_define
define|#
directive|define
name|PROC_68000
value|0x01
end_define

begin_comment
comment|/* Motorola 68000 */
end_comment

begin_define
define|#
directive|define
name|PROC_68010
value|0x02
end_define

begin_comment
comment|/* Motorola 68010 */
end_comment

begin_define
define|#
directive|define
name|PROC_68020
value|0x04
end_define

begin_comment
comment|/* Motorola 68020 */
end_comment

begin_define
define|#
directive|define
name|PROC_68030
value|0x08
end_define

begin_comment
comment|/* Motorola 68030 */
end_comment

begin_define
define|#
directive|define
name|PROC_68040
value|0x10
end_define

begin_comment
comment|/* Motorola 68040 */
end_comment

begin_comment
comment|/* PROC_POWERPC */
end_comment

begin_define
define|#
directive|define
name|PROC_PPC601
value|0x01
end_define

begin_comment
comment|/* PowerPC 601 */
end_comment

begin_define
define|#
directive|define
name|PROC_PPC603
value|0x02
end_define

begin_comment
comment|/* PowerPC 603 */
end_comment

begin_define
define|#
directive|define
name|PROC_PPC604
value|0x04
end_define

begin_comment
comment|/* PowerPC 604 */
end_comment

begin_comment
comment|/* PROC_MIPS */
end_comment

begin_define
define|#
directive|define
name|PROC_R4000
value|0x01
end_define

begin_comment
comment|/* MIPS R4000 */
end_comment

begin_define
define|#
directive|define
name|PROC_RM7000
value|0x02
end_define

begin_comment
comment|/* MIPS RM7000 */
end_comment

begin_comment
comment|/* Filetype - sigBYTE dsFiletype;       DISTINCT VALUES */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|FT_EXECUTABLE
value|0
end_define

begin_comment
comment|/* Executable Program */
end_comment

begin_define
define|#
directive|define
name|FT_SCRIPT
value|1
end_define

begin_comment
comment|/* Script/Batch File??? */
end_comment

begin_define
define|#
directive|define
name|FT_HBADRVR
value|2
end_define

begin_comment
comment|/* HBA Driver */
end_comment

begin_define
define|#
directive|define
name|FT_OTHERDRVR
value|3
end_define

begin_comment
comment|/* Other Driver */
end_comment

begin_define
define|#
directive|define
name|FT_IFS
value|4
end_define

begin_comment
comment|/* Installable Filesystem Driver */
end_comment

begin_define
define|#
directive|define
name|FT_ENGINE
value|5
end_define

begin_comment
comment|/* DPT Engine */
end_comment

begin_define
define|#
directive|define
name|FT_COMPDRVR
value|6
end_define

begin_comment
comment|/* Compressed Driver Disk */
end_comment

begin_define
define|#
directive|define
name|FT_LANGUAGE
value|7
end_define

begin_comment
comment|/* Foreign Language file */
end_comment

begin_define
define|#
directive|define
name|FT_FIRMWARE
value|8
end_define

begin_comment
comment|/* Downloadable or actual Firmware */
end_comment

begin_define
define|#
directive|define
name|FT_COMMMODL
value|9
end_define

begin_comment
comment|/* Communications Module */
end_comment

begin_define
define|#
directive|define
name|FT_INT13
value|10
end_define

begin_comment
comment|/* INT 13 style HBA Driver */
end_comment

begin_define
define|#
directive|define
name|FT_HELPFILE
value|11
end_define

begin_comment
comment|/* Help file */
end_comment

begin_define
define|#
directive|define
name|FT_LOGGER
value|12
end_define

begin_comment
comment|/* Event Logger */
end_comment

begin_define
define|#
directive|define
name|FT_INSTALL
value|13
end_define

begin_comment
comment|/* An Install Program */
end_comment

begin_define
define|#
directive|define
name|FT_LIBRARY
value|14
end_define

begin_comment
comment|/* Storage Manager Real-Mode Calls */
end_comment

begin_define
define|#
directive|define
name|FT_RESOURCE
value|15
end_define

begin_comment
comment|/* Storage Manager Resource File */
end_comment

begin_define
define|#
directive|define
name|FT_MODEM_DB
value|16
end_define

begin_comment
comment|/* Storage Manager Modem Database */
end_comment

begin_define
define|#
directive|define
name|FT_DMI
value|17
end_define

begin_comment
comment|/* DMI component interface */
end_comment

begin_comment
comment|/* Filetype flags - sigBYTE dsFiletypeFlags;    FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|FTF_DLL
value|0x01
end_define

begin_comment
comment|/* Dynamic Link Library */
end_comment

begin_define
define|#
directive|define
name|FTF_NLM
value|0x02
end_define

begin_comment
comment|/* Netware Loadable Module */
end_comment

begin_define
define|#
directive|define
name|FTF_OVERLAYS
value|0x04
end_define

begin_comment
comment|/* Uses overlays */
end_comment

begin_define
define|#
directive|define
name|FTF_DEBUG
value|0x08
end_define

begin_comment
comment|/* Debug version */
end_comment

begin_define
define|#
directive|define
name|FTF_TSR
value|0x10
end_define

begin_comment
comment|/* TSR */
end_comment

begin_define
define|#
directive|define
name|FTF_SYS
value|0x20
end_define

begin_comment
comment|/* DOS Loadable driver */
end_comment

begin_define
define|#
directive|define
name|FTF_PROTECTED
value|0x40
end_define

begin_comment
comment|/* Runs in protected mode */
end_comment

begin_define
define|#
directive|define
name|FTF_APP_SPEC
value|0x80
end_define

begin_comment
comment|/* Application Specific */
end_comment

begin_define
define|#
directive|define
name|FTF_ROM
value|(FTF_SYS|FTF_TSR)
end_define

begin_comment
comment|/* Special Case */
end_comment

begin_comment
comment|/* OEM - sigBYTE dsOEM;         DISTINCT VALUES */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|OEM_DPT
value|0
end_define

begin_comment
comment|/* DPT */
end_comment

begin_define
define|#
directive|define
name|OEM_ATT
value|1
end_define

begin_comment
comment|/* ATT */
end_comment

begin_define
define|#
directive|define
name|OEM_NEC
value|2
end_define

begin_comment
comment|/* NEC */
end_comment

begin_define
define|#
directive|define
name|OEM_ALPHA
value|3
end_define

begin_comment
comment|/* Alphatronix */
end_comment

begin_define
define|#
directive|define
name|OEM_AST
value|4
end_define

begin_comment
comment|/* AST */
end_comment

begin_define
define|#
directive|define
name|OEM_OLIVETTI
value|5
end_define

begin_comment
comment|/* Olivetti */
end_comment

begin_define
define|#
directive|define
name|OEM_SNI
value|6
end_define

begin_comment
comment|/* Siemens/Nixdorf */
end_comment

begin_define
define|#
directive|define
name|OEM_SUN
value|7
end_define

begin_comment
comment|/* SUN Microsystems */
end_comment

begin_define
define|#
directive|define
name|OEM_ADAPTEC
value|8
end_define

begin_comment
comment|/* Adaptec */
end_comment

begin_comment
comment|/* Operating System  - sigLONG dsOS;    FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|OS_DOS
value|0x00000001
end_define

begin_comment
comment|/* PC/MS-DOS                         */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS
value|0x00000002
end_define

begin_comment
comment|/* Microsoft Windows 3.x             */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS_NT
value|0x00000004
end_define

begin_comment
comment|/* Microsoft Windows NT              */
end_comment

begin_define
define|#
directive|define
name|OS_OS2M
value|0x00000008
end_define

begin_comment
comment|/* OS/2 1.2.x,MS 1.3.0,IBM 1.3.x - Monolithic */
end_comment

begin_define
define|#
directive|define
name|OS_OS2L
value|0x00000010
end_define

begin_comment
comment|/* Microsoft OS/2 1.301 - LADDR      */
end_comment

begin_define
define|#
directive|define
name|OS_OS22x
value|0x00000020
end_define

begin_comment
comment|/* IBM OS/2 2.x                      */
end_comment

begin_define
define|#
directive|define
name|OS_NW286
value|0x00000040
end_define

begin_comment
comment|/* Novell NetWare 286                */
end_comment

begin_define
define|#
directive|define
name|OS_NW386
value|0x00000080
end_define

begin_comment
comment|/* Novell NetWare 386                */
end_comment

begin_define
define|#
directive|define
name|OS_GEN_UNIX
value|0x00000100
end_define

begin_comment
comment|/* Generic Unix                      */
end_comment

begin_define
define|#
directive|define
name|OS_SCO_UNIX
value|0x00000200
end_define

begin_comment
comment|/* SCO Unix                          */
end_comment

begin_define
define|#
directive|define
name|OS_ATT_UNIX
value|0x00000400
end_define

begin_comment
comment|/* ATT Unix                          */
end_comment

begin_define
define|#
directive|define
name|OS_UNIXWARE
value|0x00000800
end_define

begin_comment
comment|/* USL Unix                          */
end_comment

begin_define
define|#
directive|define
name|OS_INT_UNIX
value|0x00001000
end_define

begin_comment
comment|/* Interactive Unix                  */
end_comment

begin_define
define|#
directive|define
name|OS_SOLARIS
value|0x00002000
end_define

begin_comment
comment|/* SunSoft Solaris                   */
end_comment

begin_define
define|#
directive|define
name|OS_QNX
value|0x00004000
end_define

begin_comment
comment|/* QNX for Tom Moch                  */
end_comment

begin_define
define|#
directive|define
name|OS_NEXTSTEP
value|0x00008000
end_define

begin_comment
comment|/* NeXTSTEP/OPENSTEP/MACH            */
end_comment

begin_define
define|#
directive|define
name|OS_BANYAN
value|0x00010000
end_define

begin_comment
comment|/* Banyan Vines                      */
end_comment

begin_define
define|#
directive|define
name|OS_OLIVETTI_UNIX
value|0x00020000
end_define

begin_comment
comment|/* Olivetti Unix                     */
end_comment

begin_define
define|#
directive|define
name|OS_MAC_OS
value|0x00040000
end_define

begin_comment
comment|/* Mac OS                            */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS_95
value|0x00080000
end_define

begin_comment
comment|/* Microsoft Windows '95             */
end_comment

begin_define
define|#
directive|define
name|OS_NW4x
value|0x00100000
end_define

begin_comment
comment|/* Novell Netware 4.x                */
end_comment

begin_define
define|#
directive|define
name|OS_BSDI_UNIX
value|0x00200000
end_define

begin_comment
comment|/* BSDi Unix BSD/OS 2.0 and up       */
end_comment

begin_define
define|#
directive|define
name|OS_AIX_UNIX
value|0x00400000
end_define

begin_comment
comment|/* AIX Unix                          */
end_comment

begin_define
define|#
directive|define
name|OS_FREE_BSD
value|0x00800000
end_define

begin_comment
comment|/* FreeBSD Unix                      */
end_comment

begin_define
define|#
directive|define
name|OS_LINUX
value|0x01000000
end_define

begin_comment
comment|/* Linux                             */
end_comment

begin_define
define|#
directive|define
name|OS_DGUX_UNIX
value|0x02000000
end_define

begin_comment
comment|/* Data General Unix                 */
end_comment

begin_define
define|#
directive|define
name|OS_SINIX_N
value|0x04000000
end_define

begin_comment
comment|/* SNI SINIX-N                       */
end_comment

begin_define
define|#
directive|define
name|OS_PLAN9
value|0x08000000
end_define

begin_comment
comment|/* ATT Plan 9                        */
end_comment

begin_define
define|#
directive|define
name|OS_TSX
value|0x10000000
end_define

begin_comment
comment|/* SNH TSX-32                        */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS_98
value|0x20000000
end_define

begin_comment
comment|/* Microsoft Windows '98     */
end_comment

begin_define
define|#
directive|define
name|OS_NW5x
value|0x40000000
end_define

begin_comment
comment|/* Novell Netware 5x */
end_comment

begin_define
define|#
directive|define
name|OS_OTHER
value|0x80000000
end_define

begin_comment
comment|/* Other                             */
end_comment

begin_comment
comment|/* Capabilities - sigWORD dsCapabilities;        FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID0
value|0x0001
end_define

begin_comment
comment|/* RAID-0 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID1
value|0x0002
end_define

begin_comment
comment|/* RAID-1 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID3
value|0x0004
end_define

begin_comment
comment|/* RAID-3 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID5
value|0x0008
end_define

begin_comment
comment|/* RAID-5 */
end_comment

begin_define
define|#
directive|define
name|CAP_SPAN
value|0x0010
end_define

begin_comment
comment|/* Spanning */
end_comment

begin_define
define|#
directive|define
name|CAP_PASS
value|0x0020
end_define

begin_comment
comment|/* Provides passthrough */
end_comment

begin_define
define|#
directive|define
name|CAP_OVERLAP
value|0x0040
end_define

begin_comment
comment|/* Passthrough supports overlapped commands */
end_comment

begin_define
define|#
directive|define
name|CAP_ASPI
value|0x0080
end_define

begin_comment
comment|/* Supports ASPI Command Requests */
end_comment

begin_define
define|#
directive|define
name|CAP_ABOVE16MB
value|0x0100
end_define

begin_comment
comment|/* ISA Driver supports greater than 16MB */
end_comment

begin_define
define|#
directive|define
name|CAP_EXTEND
value|0x8000
end_define

begin_comment
comment|/* Extended info appears after description */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SNI_MIPS
end_ifdef

begin_define
define|#
directive|define
name|CAP_CACHEMODE
value|0x1000
end_define

begin_comment
comment|/* dpt_force_cache is set in driver */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Devices Supported - sigWORD dsDeviceSupp;    FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|DEV_DASD
value|0x0001
end_define

begin_comment
comment|/* DASD (hard drives) */
end_comment

begin_define
define|#
directive|define
name|DEV_TAPE
value|0x0002
end_define

begin_comment
comment|/* Tape drives */
end_comment

begin_define
define|#
directive|define
name|DEV_PRINTER
value|0x0004
end_define

begin_comment
comment|/* Printers */
end_comment

begin_define
define|#
directive|define
name|DEV_PROC
value|0x0008
end_define

begin_comment
comment|/* Processors */
end_comment

begin_define
define|#
directive|define
name|DEV_WORM
value|0x0010
end_define

begin_comment
comment|/* WORM drives */
end_comment

begin_define
define|#
directive|define
name|DEV_CDROM
value|0x0020
end_define

begin_comment
comment|/* CD-ROM drives */
end_comment

begin_define
define|#
directive|define
name|DEV_SCANNER
value|0x0040
end_define

begin_comment
comment|/* Scanners */
end_comment

begin_define
define|#
directive|define
name|DEV_OPTICAL
value|0x0080
end_define

begin_comment
comment|/* Optical Drives */
end_comment

begin_define
define|#
directive|define
name|DEV_JUKEBOX
value|0x0100
end_define

begin_comment
comment|/* Jukebox */
end_comment

begin_define
define|#
directive|define
name|DEV_COMM
value|0x0200
end_define

begin_comment
comment|/* Communications Devices */
end_comment

begin_define
define|#
directive|define
name|DEV_OTHER
value|0x0400
end_define

begin_comment
comment|/* Other Devices */
end_comment

begin_define
define|#
directive|define
name|DEV_ALL
value|0xFFFF
end_define

begin_comment
comment|/* All SCSI Devices */
end_comment

begin_comment
comment|/* Adapters Families Supported - sigWORD dsAdapterSupp; FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|ADF_2001
value|0x0001
end_define

begin_comment
comment|/* PM2001           */
end_comment

begin_define
define|#
directive|define
name|ADF_2012A
value|0x0002
end_define

begin_comment
comment|/* PM2012A          */
end_comment

begin_define
define|#
directive|define
name|ADF_PLUS_ISA
value|0x0004
end_define

begin_comment
comment|/* PM2011,PM2021    */
end_comment

begin_define
define|#
directive|define
name|ADF_PLUS_EISA
value|0x0008
end_define

begin_comment
comment|/* PM2012B,PM2022   */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_ISA
value|0x0010
end_define

begin_comment
comment|/* PM2021           */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_EISA
value|0x0020
end_define

begin_comment
comment|/* PM2022,PM2122, etc */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_PCI
value|0x0040
end_define

begin_comment
comment|/* SmartCache III PCI */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_ISA
value|0x0080
end_define

begin_comment
comment|/* SmartCache IV ISA */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_EISA
value|0x0100
end_define

begin_comment
comment|/* SmartCache IV EISA */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_PCI
value|0x0200
end_define

begin_comment
comment|/* SmartCache IV PCI */
end_comment

begin_define
define|#
directive|define
name|ADF_SC5_PCI
value|0x0400
end_define

begin_comment
comment|/* Fifth Generation I2O products */
end_comment

begin_comment
comment|/*  *      Combinations of products  */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_2000
value|(ADF_2001|ADF_2012A)
end_define

begin_define
define|#
directive|define
name|ADF_ALL_PLUS
value|(ADF_PLUS_ISA|ADF_PLUS_EISA)
end_define

begin_define
define|#
directive|define
name|ADF_ALL_SC3
value|(ADF_SC3_ISA|ADF_SC3_EISA|ADF_SC3_PCI)
end_define

begin_define
define|#
directive|define
name|ADF_ALL_SC4
value|(ADF_SC4_ISA|ADF_SC4_EISA|ADF_SC4_PCI)
end_define

begin_define
define|#
directive|define
name|ADF_ALL_SC5
value|(ADF_SC5_PCI)
end_define

begin_comment
comment|/* All EATA Cacheing Products */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_CACHE
value|(ADF_ALL_PLUS|ADF_ALL_SC3|ADF_ALL_SC4)
end_define

begin_comment
comment|/* All EATA Bus Mastering Products */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_MASTER
value|(ADF_2012A|ADF_ALL_CACHE)
end_define

begin_comment
comment|/* All EATA Adapter Products */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_EATA
value|(ADF_2001|ADF_ALL_MASTER)
end_define

begin_define
define|#
directive|define
name|ADF_ALL
value|ADF_ALL_EATA
end_define

begin_comment
comment|/* Application - sigWORD dsApplication;         FLAG BITS */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|APP_DPTMGR
value|0x0001
end_define

begin_comment
comment|/* DPT Storage Manager */
end_comment

begin_define
define|#
directive|define
name|APP_ENGINE
value|0x0002
end_define

begin_comment
comment|/* DPT Engine */
end_comment

begin_define
define|#
directive|define
name|APP_SYTOS
value|0x0004
end_define

begin_comment
comment|/* Sytron Sytos Plus */
end_comment

begin_define
define|#
directive|define
name|APP_CHEYENNE
value|0x0008
end_define

begin_comment
comment|/* Cheyenne ARCServe + ARCSolo */
end_comment

begin_define
define|#
directive|define
name|APP_MSCDEX
value|0x0010
end_define

begin_comment
comment|/* Microsoft CD-ROM extensions */
end_comment

begin_define
define|#
directive|define
name|APP_NOVABACK
value|0x0020
end_define

begin_comment
comment|/* NovaStor Novaback */
end_comment

begin_define
define|#
directive|define
name|APP_AIM
value|0x0040
end_define

begin_comment
comment|/* Archive Information Manager */
end_comment

begin_comment
comment|/* Requirements - sigBYTE dsRequirements;         FLAG BITS             */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_define
define|#
directive|define
name|REQ_SMARTROM
value|0x01
end_define

begin_comment
comment|/* Requires SmartROM to be present      */
end_comment

begin_define
define|#
directive|define
name|REQ_DPTDDL
value|0x02
end_define

begin_comment
comment|/* Requires DPTDDL.SYS to be loaded     */
end_comment

begin_define
define|#
directive|define
name|REQ_HBA_DRIVER
value|0x04
end_define

begin_comment
comment|/* Requires an HBA driver to be loaded  */
end_comment

begin_define
define|#
directive|define
name|REQ_ASPI_TRAN
value|0x08
end_define

begin_comment
comment|/* Requires an ASPI Transport Modules   */
end_comment

begin_define
define|#
directive|define
name|REQ_ENGINE
value|0x10
end_define

begin_comment
comment|/* Requires a DPT Engine to be loaded   */
end_comment

begin_define
define|#
directive|define
name|REQ_COMM_ENG
value|0x20
end_define

begin_comment
comment|/* Requires a DPT Communications Engine */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_comment
comment|/* Requirements - sigWORD dsFirmware;         FLAG BITS                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_define
define|#
directive|define
name|dsFirmware
value|dsApplication
end_define

begin_define
define|#
directive|define
name|FW_DNLDSIZE16_OLD
value|0x0000
end_define

begin_comment
comment|/* 0..3 DownLoader Size 16K - TO SUPPORT OLD IMAGES */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE16k
value|0x0000
end_define

begin_comment
comment|/* 0..3 DownLoader Size 16k             */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE16
value|0x0001
end_define

begin_comment
comment|/* 0..3 DownLoader Size 16K         */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE32
value|0x0002
end_define

begin_comment
comment|/* 0..3 DownLoader Size 32K         */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE64
value|0x0004
end_define

begin_comment
comment|/* 0..3 DownLoader Size 64K         */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE0
value|0x000f
end_define

begin_comment
comment|/* 0..3 DownLoader Size 0K - NONE   */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDSIZE_NONE
value|0x000F
end_define

begin_comment
comment|/* 0..3 DownLoader Size - NONE      */
end_comment

begin_comment
comment|/* Code Offset is position of the code within the ROM CODE Segment */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDR_TOP
value|0x0000
end_define

begin_comment
comment|/* 12 DownLoader Position (0=Top, 1=Bottom) */
end_comment

begin_define
define|#
directive|define
name|FW_DNLDR_BTM
value|0x1000
end_define

begin_comment
comment|/* 12 DownLoader Position (0=Top, 1=Bottom) Dominator */
end_comment

begin_define
define|#
directive|define
name|FW_LOAD_BTM
value|0x0000
end_define

begin_comment
comment|/* 13 Code Offset (0=Btm, 1=Top) MIPS   */
end_comment

begin_define
define|#
directive|define
name|FW_LOAD_TOP
value|0x2000
end_define

begin_comment
comment|/* 13 Code Offset (0=Btm, 1=Top) i960   */
end_comment

begin_define
define|#
directive|define
name|FW_SIG_VERSION1
value|0x0000
end_define

begin_comment
comment|/* 15..14 Version Bits 0=Ver1               */
end_comment

begin_define
define|#
directive|define
name|FW_SIG_VERSION2
value|0x4000
end_define

begin_comment
comment|/* 15..14 Version Bits 1=Ver2       */
end_comment

begin_comment
comment|/*                                 0..3   Downloader Size (Value * 16K)                                  4                                 5                                 6                                 7                                  8                                 9                                 10                                 11                                  12              Downloader Position (0=Top of Image  1= Bottom of Image (Dominator) )                                 13              Load Offset (0=BTM (MIPS) -- 1=TOP (960) )                                 14..15  F/W Sig Version (0=Ver1) */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_comment
comment|/* Sub System Vendor IDs - The PCI Sub system and vendor IDs for each   */
end_comment

begin_comment
comment|/* Adaptec Raid controller                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_define
define|#
directive|define
name|PM1554U2_SUB_ID
value|0xC0011044
end_define

begin_define
define|#
directive|define
name|PM1654U2_SUB_ID
value|0xC0021044
end_define

begin_define
define|#
directive|define
name|PM1564U3_1_SUB_ID
value|0xC0031044
end_define

begin_define
define|#
directive|define
name|PM1564U3_2_SUB_ID
value|0xC0041044
end_define

begin_define
define|#
directive|define
name|PM1554U2_NOACPI_SUB_ID
value|0xC0051044
end_define

begin_define
define|#
directive|define
name|PM2554U2_SUB_ID
value|0xC00A1044
end_define

begin_define
define|#
directive|define
name|PM2654U2_SUB_ID
value|0xC00B1044
end_define

begin_define
define|#
directive|define
name|PM2664U3_1_SUB_ID
value|0xC00C1044
end_define

begin_define
define|#
directive|define
name|PM2664U3_2_SUB_ID
value|0xC00D1044
end_define

begin_define
define|#
directive|define
name|PM2554U2_NOACPI_SUB_ID
value|0xC00E1044
end_define

begin_define
define|#
directive|define
name|PM2654U2_NOACPI_SUB_ID
value|0xC00F1044
end_define

begin_define
define|#
directive|define
name|PM3754U2_SUB_ID
value|0xC0141044
end_define

begin_define
define|#
directive|define
name|PM3755U2B_SUB_ID
value|0xC0151044
end_define

begin_define
define|#
directive|define
name|PM3755F_SUB_ID
value|0xC0161044
end_define

begin_define
define|#
directive|define
name|PM3757U2_1_SUB_ID
value|0xC01E1044
end_define

begin_define
define|#
directive|define
name|PM3757U2_2_SUB_ID
value|0xC01F1044
end_define

begin_define
define|#
directive|define
name|PM3767U3_2_SUB_ID
value|0xC0201044
end_define

begin_define
define|#
directive|define
name|PM3767U3_4_SUB_ID
value|0xC0211044
end_define

begin_define
define|#
directive|define
name|PM2865U3_1_SUB_ID
value|0xC0281044
end_define

begin_define
define|#
directive|define
name|PM2865U3_2_SUB_ID
value|0xC0291044
end_define

begin_define
define|#
directive|define
name|PM2865F_SUB_ID
value|0xC02A1044
end_define

begin_define
define|#
directive|define
name|ADPT2000S_1_SUB_ID
value|0xC03C1044
end_define

begin_define
define|#
directive|define
name|ADPT2000S_2_SUB_ID
value|0xC03D1044
end_define

begin_define
define|#
directive|define
name|ADPT2000F_SUB_ID
value|0xC03E1044
end_define

begin_define
define|#
directive|define
name|ADPT3000S_1_SUB_ID
value|0xC0461044
end_define

begin_define
define|#
directive|define
name|ADPT3000S_2_SUB_ID
value|0xC0471044
end_define

begin_define
define|#
directive|define
name|ADPT3000F_SUB_ID
value|0xC0481044
end_define

begin_define
define|#
directive|define
name|ADPT5000S_1_SUB_ID
value|0xC0501044
end_define

begin_define
define|#
directive|define
name|ADPT5000S_2_SUB_ID
value|0xC0511044
end_define

begin_define
define|#
directive|define
name|ADPT5000F_SUB_ID
value|0xC0521044
end_define

begin_define
define|#
directive|define
name|ADPT1000UDMA_SUB_ID
value|0xC05A1044
end_define

begin_define
define|#
directive|define
name|ADPT1000UDMA_DAC_SUB_ID
value|0xC05B1044
end_define

begin_define
define|#
directive|define
name|ADPTI2O_DEVICE_ID
value|0xa501
end_define

begin_define
define|#
directive|define
name|ADPTDOMINATOR_DEVICE_ID
value|0xa511
end_define

begin_define
define|#
directive|define
name|ADPTDOMINATOR_SUB_ID_START
value|0xC0321044
end_define

begin_define
define|#
directive|define
name|ADPTDOMINATOR_SUB_ID_END
value|0xC03b1044
end_define

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------   */
end_comment

begin_comment
comment|/*  * You may adjust dsDescription_size with an override to a value less than  * 50 so that the structure allocates less real space.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|dsDescription_size
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|dsDescription_size
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|dpt_sig
block|{
name|char
name|dsSignature
index|[
literal|6
index|]
decl_stmt|;
comment|/* ALWAYS "dPtSiG" */
name|sigBYTE
name|dsSigVersion
decl_stmt|;
comment|/* signature version (currently 1) */
name|sigBYTE
name|dsProcessorFamily
decl_stmt|;
comment|/* what type of processor */
name|sigBYTE
name|dsProcessor
decl_stmt|;
comment|/* precise processor */
name|sigBYTE
name|dsFiletype
decl_stmt|;
comment|/* type of file */
name|sigBYTE
name|dsFiletypeFlags
decl_stmt|;
comment|/* flags to specify load type, etc. */
name|sigBYTE
name|dsOEM
decl_stmt|;
comment|/* OEM file was created for */
name|sigLONG
name|dsOS
decl_stmt|;
comment|/* which Operating systems */
name|sigWORD
name|dsCapabilities
decl_stmt|;
comment|/* RAID levels, etc. */
name|sigWORD
name|dsDeviceSupp
decl_stmt|;
comment|/* Types of SCSI devices supported */
name|sigWORD
name|dsAdapterSupp
decl_stmt|;
comment|/* DPT adapter families supported */
name|sigWORD
name|dsApplication
decl_stmt|;
comment|/* applications file is for */
name|sigBYTE
name|dsRequirements
decl_stmt|;
comment|/* Other driver dependencies */
name|sigBYTE
name|dsVersion
decl_stmt|;
comment|/* 1 */
name|sigBYTE
name|dsRevision
decl_stmt|;
comment|/* 'J' */
name|sigBYTE
name|dsSubRevision
decl_stmt|;
comment|/* '9'   ' ' if N/A */
name|sigBYTE
name|dsMonth
decl_stmt|;
comment|/* creation month */
name|sigBYTE
name|dsDay
decl_stmt|;
comment|/* creation day */
name|sigBYTE
name|dsYear
decl_stmt|;
comment|/* creation year since 1980 (1993=13) */
comment|/* description (NULL terminated) */
name|char
name|dsDescription
index|[
name|dsDescription_size
index|]
decl_stmt|;
block|}
name|dpt_sig_S
typedef|;
end_typedef

begin_comment
comment|/* 32 bytes minimum - with no description.  Put NULL at description[0] */
end_comment

begin_comment
comment|/* 81 bytes maximum - with 49 character description plus NULL. */
end_comment

begin_if
if|#
directive|if
name|defined
name|__bsdi__
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PACK
end_ifndef

begin_define
define|#
directive|define
name|PACK
value|__attribute__ ((packed))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|dpt_sig_Packed
block|{
name|char
name|dsSignature
index|[
literal|6
index|]
name|PACK
decl_stmt|;
comment|/* ALWAYS "dPtSiG" */
name|sigBYTE
name|dsSigVersion
name|PACK
decl_stmt|;
comment|/* signature version (currently 1) */
name|sigBYTE
name|dsProcessorFamily
name|PACK
decl_stmt|;
comment|/* what type of processor */
name|sigBYTE
name|dsProcessor
name|PACK
decl_stmt|;
comment|/* precise processor */
name|sigBYTE
name|dsFiletype
name|PACK
decl_stmt|;
comment|/* type of file */
name|sigBYTE
name|dsFiletypeFlags
name|PACK
decl_stmt|;
comment|/* flags to specify load type, etc. */
name|sigBYTE
name|dsOEM
name|PACK
decl_stmt|;
comment|/* OEM file was created for */
name|sigLONG
name|dsOS
name|PACK
decl_stmt|;
comment|/* which Operating systems */
name|sigWORD
name|dsCapabilities
name|PACK
decl_stmt|;
comment|/* RAID levels, etc. */
name|sigWORD
name|dsDeviceSupp
name|PACK
decl_stmt|;
comment|/* Types of SCSI devices supported */
name|sigWORD
name|dsAdapterSupp
name|PACK
decl_stmt|;
comment|/* DPT adapter families supported */
name|sigWORD
name|dsApplication
name|PACK
decl_stmt|;
comment|/* applications file is for */
name|sigBYTE
name|dsRequirements
name|PACK
decl_stmt|;
comment|/* Other driver dependencies */
name|sigBYTE
name|dsVersion
name|PACK
decl_stmt|;
comment|/* 1 */
name|sigBYTE
name|dsRevision
name|PACK
decl_stmt|;
comment|/* 'J' */
name|sigBYTE
name|dsSubRevision
name|PACK
decl_stmt|;
comment|/* '9'   ' ' if N/A */
name|sigBYTE
name|dsMonth
name|PACK
decl_stmt|;
comment|/* creation month */
name|sigBYTE
name|dsDay
name|PACK
decl_stmt|;
comment|/* creation day */
name|sigBYTE
name|dsYear
name|PACK
decl_stmt|;
comment|/* creation year since 1980 (1993=13) */
comment|/* description (NULL terminated) */
name|char
name|dsDescription
index|[
name|dsDescription_size
index|]
name|PACK
decl_stmt|;
block|}
name|dpt_sig_S_Packed
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PACKED_SIG_SIZE
value|sizeof(dpt_sig_S_Packed)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This line added at Roycroft's request */
end_comment

begin_comment
comment|/* Microsoft's NT compiler gets confused if you do a pack and don't */
end_comment

begin_comment
comment|/* restore it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNPACK
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_AIX
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
end_pragma

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|UNPACK_FOUR
argument_list|)
end_elif

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_else
else|#
directive|else
end_else

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
comment|/* aix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For the Macintosh */
end_comment

begin_if
if|#
directive|if
name|STRUCTALIGNMENTSUPPORTED
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

