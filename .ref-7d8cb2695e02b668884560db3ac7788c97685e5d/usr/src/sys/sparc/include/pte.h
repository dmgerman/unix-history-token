begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)pte.h	7.3 (Berkeley) %G%  *  * from: $Header: pte.h,v 1.5 92/11/26 02:04:43 torek Exp $  */
end_comment

begin_comment
comment|/*  * Sun-4 (sort of) and 4c (SparcStation) Page Table Entries  * (Sun call them `Page Map Entries').  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Segment maps contain `pmeg' (Page Map Entry Group) numbers.  * A PMEG is simply an index that names a group of 32 (sun4) or  * 64 (sun4c) PTEs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4
end_ifdef

begin_typedef
typedef|typedef
name|u_short
name|pmeg_t
typedef|;
end_typedef

begin_comment
comment|/* 9 bits needed per Sun-4 segmap entry */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_char
name|pmeg_t
typedef|;
end_typedef

begin_comment
comment|/* 7 bits needed per Sun-4c segmap entry */
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
comment|/*  * Address translation works as follows:  *  *	1. test va<31:29> -- these must be 000 or 111 (or you get a fault)  *	2. concatenate context_reg<2:0> and va<29:18> to get a 15 bit number;  *	   use this to index the segment maps, yeilding a 7 or 9 bit value.  * (for sun4c)  *	3. take the value from (2) above and concatenate va<17:12> to  *	   get a `page map entry' index.  This gives a 32-bit PTE.  * (for sun4)  *	3. take the value from (2) above and concatenate va<17:13> to  *	   get a `page map entry' index.  This gives a 32-bit PTE.  *  * In other words:  *  *	struct sun4_virtual_addr {  *		u_int	:2,		(required to be the same as bit 29)  *			va_seg:12,	(virtual segment)  *			va_pg:5,	(virtual page within segment)  *			va_off:13;	(offset within page)  *	};  *	struct sun4c_virtual_addr {  *		u_int	:2,		(required to be the same as bit 29)  *			va_seg:12,	(virtual segment)  *			va_pg:6,	(virtual page within segment)  *			va_off:12;	(offset within page)  *	};  *  * Then, given any `va':  *  *	extern pmeg_t segmap[8][1<<12];		([16][1<<12] for sun4)  *	extern int ptetable[128][1<<6];		([512][1<<5] for sun4)  *  * (the above being in the hardware, accessed as Alternate Address Spaces)  *  *	physseg = segmap[curr_ctx][va.va_seg];  *	pte = ptetable[physseg][va.va_pg];  *	if (!(pte& PG_V)) TRAP();  *	if (writing&& !pte.pg_w) TRAP();  *	if (usermode&& pte.pg_s) TRAP();  *	if (pte& PG_NC) DO_NOT_USE_CACHE_FOR_THIS_ACCESS();  *	pte |= PG_U;					(mark used/accessed)  *	if (writing) pte |= PG_M;			(mark modified)  *	ptetable[physseg][va.va_pg] = pte;  *	physadr = ((pte& PG_PFNUM)<< PGSHIFT) | va.va_off;  */
end_comment

begin_define
define|#
directive|define
name|NBPSG
value|(1<< 18)
end_define

begin_comment
comment|/* bytes per segment */
end_comment

begin_define
define|#
directive|define
name|SGSHIFT
value|18
end_define

begin_comment
comment|/* log2(NBPSG) */
end_comment

begin_define
define|#
directive|define
name|SGOFSET
value|(NBPSG - 1)
end_define

begin_comment
comment|/* mask for segment offset */
end_comment

begin_comment
comment|/* number of PTEs that map one segment (not number that fit in one segment!) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUN4
argument_list|)
operator|&&
name|defined
argument_list|(
name|SUN4C
argument_list|)
end_if

begin_define
define|#
directive|define
name|NPTESG
value|nptesg
end_define

begin_comment
comment|/* (which someone will have to init) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPTESG
value|(NBPSG / NBPG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* virtual address to virtual segment number */
end_comment

begin_define
define|#
directive|define
name|VA_VSEG
parameter_list|(
name|va
parameter_list|)
value|(((int)(va)>> SGSHIFT)& 0xfff)
end_define

begin_comment
comment|/* virtual address to virtual page number, for Sun-4 and Sun-4c */
end_comment

begin_define
define|#
directive|define
name|VA_SUN4_VPG
parameter_list|(
name|va
parameter_list|)
value|(((int)(va)>> 13)& 31)
end_define

begin_define
define|#
directive|define
name|VA_SUN4C_VPG
parameter_list|(
name|va
parameter_list|)
value|(((int)(va)>> 12)& 63)
end_define

begin_comment
comment|/* truncate virtual address to segment base */
end_comment

begin_define
define|#
directive|define
name|VA_ROUNDDOWNTOSEG
parameter_list|(
name|va
parameter_list|)
value|((int)(va)& ~SGOFSET)
end_define

begin_comment
comment|/* virtual segment to virtual address (must sign extend!) */
end_comment

begin_define
define|#
directive|define
name|VSTOVA
parameter_list|(
name|vseg
parameter_list|)
value|(((int)(vseg)<< 20)>> 2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4C
end_ifdef

begin_decl_stmt
name|int
name|issun4c
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VA_VPG
parameter_list|(
name|va
parameter_list|)
value|(issun4c ? VA_SUN4C_VPG(va) : VA_SUN4_VPG(va))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun4 and not sun4c */
end_comment

begin_define
define|#
directive|define
name|VA_VPG
parameter_list|(
name|va
parameter_list|)
value|VA_SUN4_VPG(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sun4; must be 4c */
end_comment

begin_define
define|#
directive|define
name|VA_VPG
parameter_list|(
name|va
parameter_list|)
value|VA_SUN4C_VPG(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* there is no `struct pte'; we just use `int' */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x60000000
end_define

begin_comment
comment|/* both protection bits */
end_comment

begin_define
define|#
directive|define
name|PG_W
value|0x40000000
end_define

begin_comment
comment|/* allowed to write */
end_comment

begin_define
define|#
directive|define
name|PG_S
value|0x20000000
end_define

begin_comment
comment|/* supervisor only */
end_comment

begin_define
define|#
directive|define
name|PG_NC
value|0x10000000
end_define

begin_comment
comment|/* non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PG_TYPE
value|0x0c000000
end_define

begin_comment
comment|/* both type bits */
end_comment

begin_define
define|#
directive|define
name|PG_OBMEM
value|0x00000000
end_define

begin_comment
comment|/* on board memory */
end_comment

begin_define
define|#
directive|define
name|PG_OBIO
value|0x04000000
end_define

begin_comment
comment|/* on board I/O (incl. Sbus on 4c) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4
end_ifdef

begin_define
define|#
directive|define
name|PG_VME16
value|0x08000000
end_define

begin_comment
comment|/* 16-bit-data VME space */
end_comment

begin_define
define|#
directive|define
name|PG_VME32
value|0x0c000000
end_define

begin_comment
comment|/* 32-bit-data VME space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PG_U
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PG_M
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PG_MBZ
value|0x00f80000
end_define

begin_comment
comment|/* unused; must be zero (oh really?) */
end_comment

begin_define
define|#
directive|define
name|PG_PFNUM
value|0x0007ffff
end_define

begin_comment
comment|/* n.b.: only 16 bits on sun4c */
end_comment

begin_define
define|#
directive|define
name|PG_TNC_SHIFT
value|26
end_define

begin_comment
comment|/* shift to get PG_TYPE + PG_NC */
end_comment

begin_define
define|#
directive|define
name|PG_M_SHIFT
value|24
end_define

begin_comment
comment|/* shift to get PG_M, PG_U */
end_comment

begin_comment
comment|/*efine	PG_NOACC	0		** XXX */
end_comment

begin_define
define|#
directive|define
name|PG_KR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PG_KW
value|0x60000000
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|0
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x40000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KGDB
end_ifdef

begin_comment
comment|/* but we will define one for gdb anyway */
end_comment

begin_struct
struct|struct
name|pte
block|{
name|u_int
name|pg_v
range|:
literal|1
decl_stmt|,
name|pg_w
range|:
literal|1
decl_stmt|,
name|pg_s
range|:
literal|1
decl_stmt|,
name|pg_nc
range|:
literal|1
decl_stmt|;
enum|enum
name|pgtype
block|{
name|pg_obmem
block|,
name|pg_obio
block|,
name|pg_vme16
block|,
name|pg_vme32
block|}
name|pg_type
range|:
literal|2
enum|;
name|u_int
name|pg_u
range|:
literal|1
decl_stmt|,
name|pg_m
range|:
literal|1
decl_stmt|,
name|pg_mbz
range|:
literal|5
decl_stmt|,
name|pg_pfnum
range|:
literal|19
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are needed in the register window code  * to check the validity of (ostensible) user stack PTEs.  */
end_comment

begin_define
define|#
directive|define
name|PG_VSHIFT
value|30
end_define

begin_comment
comment|/* (va>>vshift)==0 or -1 => valid */
end_comment

begin_comment
comment|/* XXX fix this name, it is a va shift not a pte bit shift! */
end_comment

begin_define
define|#
directive|define
name|PG_PROTSHIFT
value|29
end_define

begin_define
define|#
directive|define
name|PG_PROTUWRITE
value|6
end_define

begin_comment
comment|/* PG_V,PG_W,!PG_S */
end_comment

begin_define
define|#
directive|define
name|PG_PROTUREAD
value|4
end_define

begin_comment
comment|/* PG_V,!PG_W,!PG_S */
end_comment

begin_comment
comment|/* static __inline int PG_VALID(void *va) { 	register int t = va; t>>= PG_VSHIFT; return (t == 0 || t == -1); } */
end_comment

end_unit

