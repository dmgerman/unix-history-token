begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dec_exec.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Portions of this file are subject to the following copyright notice:  *  * Copyright (C) 1989 Digital Equipment Corporation.  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies.    * Digital Equipment Corporation makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * /sprite/src/kernel/proc/ds3100.md/RCS/procMach.h,v 9.3 90/02/20 15:35:50  * shirriff Exp $ SPRITE (Berkeley)  */
end_comment

begin_comment
comment|/* Description of the COFF section. */
end_comment

begin_struct
struct|struct
name|coff_exec
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
comment|/* Description of the a.out section. */
name|short
name|aout_magic
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
struct|;
end_struct

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

end_unit

