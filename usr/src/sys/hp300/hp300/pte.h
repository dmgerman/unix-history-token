begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pte.h 1.11 89/09/03$  *  *	@(#)pte.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * HP300 hardware segment/page table entries  */
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
name|SG_PMASK
value|0x003ff000
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
name|SG_PSHIFT
value|12
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

begin_define
define|#
directive|define
name|HP_STSIZE
value|HP_PAGE_SIZE
end_define

begin_comment
comment|/* segment table size */
end_comment

begin_define
define|#
directive|define
name|HP_MAX_PTSIZE
value|HP_SEG_SIZE
end_define

begin_comment
comment|/* max size of UPT */
end_comment

begin_define
define|#
directive|define
name|HP_MAX_KPTSIZE
value|0x100000
end_define

begin_comment
comment|/* max memory to allocate to KPT */
end_comment

begin_define
define|#
directive|define
name|HP_PTBASE
value|0x10000000
end_define

begin_comment
comment|/* UPT map base address */
end_comment

begin_define
define|#
directive|define
name|HP_PTMAXSIZE
value|0x70000000
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

