begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)exec.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMGACT_AOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_IMGACT_AOUT_H_
end_define

begin_define
define|#
directive|define
name|N_GETMAGIC
parameter_list|(
name|ex
parameter_list|)
define|\
value|( (ex).a_midmag& 0xffff )
end_define

begin_define
define|#
directive|define
name|N_GETMID
parameter_list|(
name|ex
parameter_list|)
define|\
value|( (N_GETMAGIC_NET(ex) == ZMAGIC) ? N_GETMID_NET(ex) : \ 	((ex).a_midmag>> 16)& 0x03ff )
end_define

begin_define
define|#
directive|define
name|N_GETFLAG
parameter_list|(
name|ex
parameter_list|)
define|\
value|( (N_GETMAGIC_NET(ex) == ZMAGIC) ? N_GETFLAG_NET(ex) : \ 	((ex).a_midmag>> 26)& 0x3f )
end_define

begin_define
define|#
directive|define
name|N_SETMAGIC
parameter_list|(
name|ex
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|flag
parameter_list|)
define|\
value|( (ex).a_midmag = (((flag)& 0x3f)<<26) | (((mid)& 0x03ff)<< 16) | \ 	((mag)& 0xffff) )
end_define

begin_define
define|#
directive|define
name|N_GETMAGIC_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|(ntohl((ex).a_midmag)& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_GETMID_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ntohl((ex).a_midmag)>> 16)& 0x03ff)
end_define

begin_define
define|#
directive|define
name|N_GETFLAG_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ntohl((ex).a_midmag)>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|N_SETMAGIC_NET
parameter_list|(
name|ex
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|flag
parameter_list|)
define|\
value|( (ex).a_midmag = htonl( (((flag)&0x3f)<<26) | (((mid)&0x03ff)<<16) | \ 	(((mag)&0xffff)) ) )
end_define

begin_define
define|#
directive|define
name|N_ALIGN
parameter_list|(
name|ex
parameter_list|,
name|x
parameter_list|)
define|\
value|(N_GETMAGIC(ex) == ZMAGIC || N_GETMAGIC(ex) == QMAGIC || \ 	 N_GETMAGIC_NET(ex) == ZMAGIC || N_GETMAGIC_NET(ex) == QMAGIC ? \ 	 ((x) + __LDPGSZ - 1)& ~(unsigned long)(__LDPGSZ - 1) : (x))
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
value|(N_GETMAGIC(ex) != OMAGIC&& N_GETMAGIC(ex) != NMAGIC&& \ 	 N_GETMAGIC(ex) != ZMAGIC&& N_GETMAGIC(ex) != QMAGIC&& \ 	 N_GETMAGIC_NET(ex) != OMAGIC&& N_GETMAGIC_NET(ex) != NMAGIC&& \ 	 N_GETMAGIC_NET(ex) != ZMAGIC&& N_GETMAGIC_NET(ex) != QMAGIC)
end_define

begin_comment
comment|/* Address of the bottom of the text segment. */
end_comment

begin_comment
comment|/*  * This can not be done right.  Abuse a_entry in some cases to handle kernels.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|ex
parameter_list|)
define|\
value|((N_GETMAGIC(ex) == OMAGIC || N_GETMAGIC(ex) == NMAGIC || \ 	N_GETMAGIC(ex) == ZMAGIC) ? \ 	((ex).a_entry< (ex).a_text ? 0 : (ex).a_entry& ~__LDPGSZ) : __LDPGSZ)
end_define

begin_comment
comment|/* Address of the bottom of the data segment. */
end_comment

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|ex
parameter_list|)
define|\
value|N_ALIGN(ex, N_TXTADDR(ex) + (ex).a_text)
end_define

begin_comment
comment|/* Text segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_GETMAGIC(ex) == ZMAGIC ? __LDPGSZ : (N_GETMAGIC(ex) == QMAGIC || \ 	N_GETMAGIC_NET(ex) == ZMAGIC) ? 0 : sizeof(struct exec))
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
value|N_ALIGN(ex, N_TXTOFF(ex) + (ex).a_text)
end_define

begin_comment
comment|/* Relocation table offset. */
end_comment

begin_define
define|#
directive|define
name|N_RELOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|N_ALIGN(ex, N_DATOFF(ex) + (ex).a_data)
end_define

begin_comment
comment|/* Symbol table offset. */
end_comment

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_RELOFF(ex) + (ex).a_trsize + (ex).a_drsize)
end_define

begin_comment
comment|/* String table offset. */
end_comment

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|ex
parameter_list|)
value|(N_SYMOFF(ex) + (ex).a_syms)
end_define

begin_comment
comment|/*  * Header prepended to each a.out file.  * only manipulate the a_midmag field via the  * N_SETMAGIC/N_GET{MAGIC,MID,FLAG} macros in a.out.h  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|long
name|a_midmag
decl_stmt|;
comment|/* flags<<26 | mid<<16 | magic */
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
name|a_magic
value|a_midmag
end_define

begin_comment
comment|/* XXX Hack to work with current kern_execve.c */
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

begin_define
define|#
directive|define
name|QMAGIC
value|0314
end_define

begin_comment
comment|/* "compact" demand load format */
end_comment

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
name|MID_I386
value|134
end_define

begin_comment
comment|/* i386 BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_SPARC
value|138
end_define

begin_comment
comment|/* sparc */
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

begin_comment
comment|/*  * a_flags  */
end_comment

begin_define
define|#
directive|define
name|EX_PIC
value|0x10
end_define

begin_comment
comment|/* contains position independent code */
end_comment

begin_define
define|#
directive|define
name|EX_DYNAMIC
value|0x20
end_define

begin_comment
comment|/* contains run-time link-edit info */
end_comment

begin_define
define|#
directive|define
name|EX_DPMASK
value|0x30
end_define

begin_comment
comment|/* mask for the above */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|aout_coredump
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|off_t
name|limit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IMGACT_AOUT_H_ */
end_comment

end_unit

