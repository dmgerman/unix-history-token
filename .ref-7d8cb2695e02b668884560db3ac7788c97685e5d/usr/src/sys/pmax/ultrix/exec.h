begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Portions of this file are subject to the following copyright notice:  *  * Copyright (C) 1989 Digital Equipment Corporation.  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies.    * Digital Equipment Corporation makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * /sprite/src/kernel/proc/ds3100.md/RCS/procMach.h,v 9.3 90/02/20 15:35:50  * shirriff Exp $ SPRITE (Berkeley)  */
end_comment

begin_comment
comment|/* Size of a page in an object file. */
end_comment

begin_define
define|#
directive|define
name|__LDPGSZ
value|4096
end_define

begin_comment
comment|/* Valid magic number check. */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).a_magic != NMAGIC&& (ex).a_magic != OMAGIC&& \ 	    (ex).a_magic != ZMAGIC)
end_define

begin_comment
comment|/* Address of the bottom of the text segment. */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|ex
parameter_list|)
value|0x400000
end_define

begin_comment
comment|/* Address of the bottom of the data segment. */
end_comment

begin_comment
comment|/* NOT DEFINED FOR THE MIPS. */
end_comment

begin_comment
comment|/* Text segment offset. */
end_comment

begin_define
define|#
directive|define
name|__N_TXTOFF_ROUND
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).ex_aout.verStamp< 23 ? 7 : 15)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).ex_aout.magic == ZMAGIC ? 0 : (sizeof(struct exec) + \ 	    (ex).ex_fhdr.numSections * sizeof(ProcSectionHeader) + \ 	    __N_TXTOFF_ROUND(ex))& ~__N_TXTOFF_ROUND(ex))
end_define

begin_comment
comment|/* Data segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_TXTOFF(ex) + (ex).ex_aout.codeSize)
end_define

begin_comment
comment|/* Symbol table offset. */
end_comment

begin_comment
comment|/* NOT DEFINED FOR THE MIPS. */
end_comment

begin_comment
comment|/* String table offset. */
end_comment

begin_comment
comment|/* NOT DEFINED FOR THE MIPS. */
end_comment

begin_comment
comment|/*  * XXX  * The ProcFileHeader structure and the ProcAOUTHeader structure should be  * folded together into a single struct exec.  */
end_comment

begin_comment
comment|/* Description of the COFF section. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
define|#
directive|define
name|COFF_MAGIC
value|0x0162
name|u_short
name|magic
decl_stmt|;
comment|/* The magic number. */
name|u_short
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
name|u_short
name|optHeader
decl_stmt|;
comment|/* Size of optional header. */
name|u_short
name|flags
decl_stmt|;
comment|/* Flags. */
block|}
name|ProcFileHeader
typedef|;
end_typedef

begin_comment
comment|/* Description of the a.out section. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
define|#
directive|define
name|OMAGIC
value|0407
comment|/* old impure format */
define|#
directive|define
name|NMAGIC
value|0410
comment|/* read-only text */
define|#
directive|define
name|ZMAGIC
value|0413
comment|/* demand load format */
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
comment|/* Section header. */
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
comment|/* File pointer to section data. */
name|long
name|relocPtr
decl_stmt|;
comment|/* File pointer to relocation data. */
name|long
name|lnnoPtr
decl_stmt|;
comment|/* File pointer to gp tables. */
name|u_short
name|numReloc
decl_stmt|;
comment|/* Number of relocation entries. */
name|u_short
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
comment|/* Description of the object file header. */
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

end_unit

