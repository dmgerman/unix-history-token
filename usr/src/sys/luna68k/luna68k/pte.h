begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1982, 1986, 1990, 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pte.h 1.13 92/01/20$  * from: hp300/hp300/pte.h	7.4 (Berkeley) 6/5/92  *  *	@(#)pte.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * LUNA68K hardware segment/page table entries  */
end_comment

begin_struct
struct|struct
name|ste
block|{
name|unsigned
name|int
name|sg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* page table frame number */
name|unsigned
name|int
range|:
literal|8
decl_stmt|;
comment|/* reserved at 0 */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at 1 */
name|unsigned
name|int
name|sg_prot
range|:
literal|1
decl_stmt|;
comment|/* write protect bit */
name|unsigned
name|int
name|sg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bits */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste40
block|{
name|unsigned
name|int
name|sg_ptaddr
range|:
literal|24
decl_stmt|;
comment|/* page table page addr */
name|unsigned
name|int
range|:
literal|4
decl_stmt|;
comment|/* reserved at 0 */
name|unsigned
name|int
name|sg_u
decl_stmt|;
comment|/* hardware modified (dirty) bit */
name|unsigned
name|int
name|sg_prot
range|:
literal|1
decl_stmt|;
comment|/* write protect bit */
name|unsigned
name|int
name|sg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bits */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pte
block|{
name|unsigned
name|int
name|pg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* page frame number or 0 */
name|unsigned
name|int
range|:
literal|3
decl_stmt|;
name|unsigned
name|int
name|pg_w
range|:
literal|1
decl_stmt|;
comment|/* is wired */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at zero */
name|unsigned
name|int
name|pg_ci
range|:
literal|1
decl_stmt|;
comment|/* cache inhibit bit */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at zero */
name|unsigned
name|int
name|pg_m
range|:
literal|1
decl_stmt|;
comment|/* hardware modified (dirty) bit */
name|unsigned
name|int
name|pg_u
range|:
literal|1
decl_stmt|;
comment|/* hardware used (reference) bit */
name|unsigned
name|int
name|pg_prot
range|:
literal|1
decl_stmt|;
comment|/* write protect bit */
name|unsigned
name|int
name|pg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bit */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ste
name|st_entry_t
typedef|;
end_typedef

begin_comment
comment|/* segment table entry */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pte
name|pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/* Mach page table entry */
end_comment

begin_define
define|#
directive|define
name|PT_ENTRY_NULL
value|((pt_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|ST_ENTRY_NULL
value|((st_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|SG_V
value|0x00000002
end_define

begin_comment
comment|/* segment is valid */
end_comment

begin_define
define|#
directive|define
name|SG_NV
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SG_PROT
value|0x00000004
end_define

begin_comment
comment|/* access protection mask */
end_comment

begin_define
define|#
directive|define
name|SG_RO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SG_RW
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SG_U
value|0x00000008
end_define

begin_comment
comment|/* modified bit (68040) */
end_comment

begin_define
define|#
directive|define
name|SG_FRAME
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|SG_IMASK
value|0xffc00000
end_define

begin_define
define|#
directive|define
name|SG_ISHIFT
value|22
end_define

begin_define
define|#
directive|define
name|SG_PMASK
value|0x003ff000
end_define

begin_define
define|#
directive|define
name|SG_PSHIFT
value|12
end_define

begin_comment
comment|/* 68040 additions */
end_comment

begin_define
define|#
directive|define
name|SG4_MASK1
value|0xfe000000
end_define

begin_define
define|#
directive|define
name|SG4_SHIFT1
value|25
end_define

begin_define
define|#
directive|define
name|SG4_MASK2
value|0x01fc0000
end_define

begin_define
define|#
directive|define
name|SG4_SHIFT2
value|18
end_define

begin_define
define|#
directive|define
name|SG4_MASK3
value|0x0003f000
end_define

begin_define
define|#
directive|define
name|SG4_SHIFT3
value|12
end_define

begin_define
define|#
directive|define
name|SG4_ADDR1
value|0xfffffe00
end_define

begin_define
define|#
directive|define
name|SG4_ADDR2
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|SG4_LEV1SIZE
value|128
end_define

begin_define
define|#
directive|define
name|SG4_LEV2SIZE
value|128
end_define

begin_define
define|#
directive|define
name|SG4_LEV3SIZE
value|64
end_define

begin_define
define|#
directive|define
name|PG_V
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PG_NV
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_U
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PG_M
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PG_W
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PG_RO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_RW
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_FRAME
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|PG_CI
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PG_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PG_PFNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& PG_FRAME)>> PG_SHIFT)
end_define

begin_comment
comment|/* 68040 additions */
end_comment

begin_define
define|#
directive|define
name|PG_CMASK
value|0x00000060
end_define

begin_comment
comment|/* cache mode mask */
end_comment

begin_define
define|#
directive|define
name|PG_CWT
value|0x00000000
end_define

begin_comment
comment|/* writethrough caching */
end_comment

begin_define
define|#
directive|define
name|PG_CCB
value|0x00000020
end_define

begin_comment
comment|/* copyback caching */
end_comment

begin_define
define|#
directive|define
name|PG_CIS
value|0x00000040
end_define

begin_comment
comment|/* cache inhibited serialized */
end_comment

begin_define
define|#
directive|define
name|PG_CIN
value|0x00000060
end_define

begin_comment
comment|/* cache inhibited nonserialized */
end_comment

begin_define
define|#
directive|define
name|PG_SO
value|0x00000080
end_define

begin_comment
comment|/* supervisor only */
end_comment

begin_define
define|#
directive|define
name|LUNA_STSIZE
value|(MAXUL2SIZE*SG4_LEV2SIZE*sizeof(st_entry_t))
end_define

begin_comment
comment|/* user process segment table size */
end_comment

begin_define
define|#
directive|define
name|LUNA_MAX_PTSIZE
value|0x400000
end_define

begin_comment
comment|/* max size of UPT */
end_comment

begin_define
define|#
directive|define
name|LUNA_MAX_KPTSIZE
value|0x100000
end_define

begin_comment
comment|/* max memory to allocate to KPT */
end_comment

begin_define
define|#
directive|define
name|LUNA_PTBASE
value|0x10000000
end_define

begin_comment
comment|/* UPT map base address */
end_comment

begin_define
define|#
directive|define
name|LUNA_PTMAXSIZE
value|0x20000000
end_define

begin_comment
comment|/* UPT map maximum size */
end_comment

begin_comment
comment|/*  * Kernel virtual address to page table entry and to physical address.  */
end_comment

begin_define
define|#
directive|define
name|kvtopte
parameter_list|(
name|va
parameter_list|)
define|\
value|(&Sysmap[((unsigned)(va) - VM_MIN_KERNEL_ADDRESS)>> PGSHIFT])
end_define

begin_define
define|#
directive|define
name|ptetokv
parameter_list|(
name|pt
parameter_list|)
define|\
value|((((pt_entry_t *)(pt) - Sysmap)<< PGSHIFT) + VM_MIN_KERNEL_ADDRESS)
end_define

begin_define
define|#
directive|define
name|kvtophys
parameter_list|(
name|va
parameter_list|)
define|\
value|((kvtopte(va)->pg_pfnum<< PGSHIFT) | ((int)(va)& PGOFSET))
end_define

end_unit

