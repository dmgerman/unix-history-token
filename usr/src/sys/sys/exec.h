begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	7.8 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXEC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|COFF
end_ifndef

begin_comment
comment|/* Header prepended to each a.out file. */
end_comment

begin_struct
struct|struct
name|exec
block|{
ifdef|#
directive|ifdef
name|sparc
name|unsigned
name|char
name|a_dynamic
range|:
literal|1
decl_stmt|;
comment|/* dynamically linked */
name|unsigned
name|char
name|a_toolversion
range|:
literal|7
decl_stmt|;
comment|/* Sun toolset version  XXX */
name|unsigned
name|char
name|a_mid
decl_stmt|;
comment|/* machine ID */
name|unsigned
name|short
name|a_magic
decl_stmt|;
comment|/* magic number */
else|#
directive|else
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
name|unsigned
name|short
name|a_mid
decl_stmt|;
comment|/* machine ID */
name|unsigned
name|short
name|a_magic
decl_stmt|;
comment|/* magic number */
else|#
directive|else
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
endif|#
directive|endif
endif|#
directive|endif
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* text segment size */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* initialized data size */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* uninitialized data size */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* symbol table size */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* text relocation size */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* data relocation size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|a_machtype
value|a_mid
end_define

begin_comment
comment|/* SUN compatibility */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF */
end_comment

begin_comment
comment|/* a_magic */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_comment
comment|/* a_mid */
end_comment

begin_define
define|#
directive|define
name|MID_ZERO
value|0
end_define

begin_comment
comment|/* unknown - implementation dependent */
end_comment

begin_define
define|#
directive|define
name|MID_SUN010
value|1
end_define

begin_comment
comment|/* sun 68010/68020 binary */
end_comment

begin_define
define|#
directive|define
name|MID_SUN020
value|2
end_define

begin_comment
comment|/* sun 68020-only binary */
end_comment

begin_define
define|#
directive|define
name|MID_SUN_SPARC
value|3
end_define

begin_comment
comment|/* sparc binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP200
value|200
end_define

begin_comment
comment|/* hp200 (68010) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP300
value|300
end_define

begin_comment
comment|/* hp300 (68020+68881) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX
value|0x20C
end_define

begin_comment
comment|/* hp200/300 HP-UX binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX800
value|0x20B
end_define

begin_comment
comment|/* hp800 HP-UX binary */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COFF
end_ifdef

begin_comment
comment|/*  * procAOUT.h --  *  *	The a.out format for an object file.  *  * Copyright (C) 1989 Digital Equipment Corporation.  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies.    * Digital Equipment Corporation makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * $Header: /sprite/src/kernel/proc/ds3100.md/RCS/procMach.h,v 9.3 90/02/20 15:35:50 shirriff Exp $ SPRITE (Berkeley)  */
end_comment

begin_comment
comment|/*  * File header magic number.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|0x0162
end_define

begin_comment
comment|/*  * Description of the file.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|magic
decl_stmt|;
comment|/* The magic number. */
name|unsigned
name|short
name|numSections
decl_stmt|;
comment|/* The number of sections. */
name|long
name|timeDateStamp
decl_stmt|;
comment|/* Time and date stamp. */
name|long
name|symPtr
decl_stmt|;
comment|/* File pointer to symbolic header. */
name|long
name|numSyms
decl_stmt|;
comment|/* Size of symbolic header. */
name|unsigned
name|short
name|optHeader
decl_stmt|;
comment|/* Size of optional header. */
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* Flags. */
block|}
name|ProcFileHeader
typedef|;
end_typedef

begin_comment
comment|/*  * A.out header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|magic
decl_stmt|;
comment|/* Magic number. */
name|short
name|verStamp
decl_stmt|;
comment|/* Version stamp. */
name|long
name|codeSize
decl_stmt|;
comment|/* Code size in bytes. */
name|long
name|heapSize
decl_stmt|;
comment|/* Initialized data size in bytes. */
name|long
name|bssSize
decl_stmt|;
comment|/* Uninitialized data size in bytes. */
name|long
name|entry
decl_stmt|;
comment|/* Entry point. */
name|long
name|codeStart
decl_stmt|;
comment|/* Base of code used for this file. */
name|long
name|heapStart
decl_stmt|;
comment|/* Base of heap used for this file. */
name|long
name|bssStart
decl_stmt|;
comment|/* Base of bss used for this file. */
name|long
name|gprMask
decl_stmt|;
comment|/* General purpose register mask. */
name|long
name|cprMask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Co-processor register masks. */
name|long
name|gpValue
decl_stmt|;
comment|/* The gp value for this object. */
block|}
name|ProcAOUTHeader
typedef|;
end_typedef

begin_comment
comment|/*  * Section header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* Section name. */
name|long
name|physAddr
decl_stmt|;
comment|/* Section physical address. */
name|long
name|virtAddr
decl_stmt|;
comment|/* Section virtual address. */
name|long
name|size
decl_stmt|;
comment|/* Section size. */
name|long
name|sectionPtr
decl_stmt|;
comment|/* File pointer to section data.  */
name|long
name|relocPtr
decl_stmt|;
comment|/* File pointer to relocation data.  */
name|long
name|lnnoPtr
decl_stmt|;
comment|/* File pointer to gp tables. */
name|unsigned
name|short
name|numReloc
decl_stmt|;
comment|/* Number of relocation entries. */
name|unsigned
name|short
name|numLnno
decl_stmt|;
comment|/* Numberof gp tables. */
name|long
name|flags
decl_stmt|;
comment|/* Section flags. */
block|}
name|ProcSectionHeader
typedef|;
end_typedef

begin_comment
comment|/*  * The header at the beginning of each file.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|ProcFileHeader
name|ex_fhdr
decl_stmt|;
name|ProcAOUTHeader
name|ex_aout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|a_magic
value|ex_aout.magic
end_define

begin_define
define|#
directive|define
name|a_text
value|ex_aout.codeSize
end_define

begin_define
define|#
directive|define
name|a_data
value|ex_aout.heapSize
end_define

begin_define
define|#
directive|define
name|a_bss
value|ex_aout.bssSize
end_define

begin_define
define|#
directive|define
name|a_entry
value|ex_aout.entry
end_define

begin_comment
comment|/*  * Determine the offset of the text segment in the file, given the header.  * (This is the same function as N_TXTOFF)  */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|hdr
parameter_list|)
define|\
value|( ((hdr).ex_aout.magic == ZMAGIC) ? 0 : \ 	((sizeof(struct exec) + \ 	    (hdr).ex_fhdr.numSections*sizeof(ProcSectionHeader) + \ 	    ((hdr).ex_aout.verStamp< 23 ? 7 : 15))& \ 		~((long)(((hdr).ex_aout.verStamp< 23 ? 7 : 15))) ) )
end_define

begin_define
define|#
directive|define
name|N_DATAOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_TXTOFF(x) + (x).ex_aout.codeSize)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_EXEC_H_ */
end_comment

end_unit

