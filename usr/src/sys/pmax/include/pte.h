begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pte.h 1.11 89/09/03$  *  *	@(#)pte.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * R2000 hardware page table entry  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|pte
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|pg_pfnum
range|:
literal|20
decl_stmt|,
comment|/* HW: core page frame number or 0 */
name|pg_n
range|:
literal|1
decl_stmt|,
comment|/* HW: non-cacheable bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* HW: modified (dirty) bit */
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* HW: valid bit */
name|pg_g
range|:
literal|1
decl_stmt|,
comment|/* HW: ignore pid bit */
range|:
literal|4
decl_stmt|,
name|pg_swapm
range|:
literal|1
decl_stmt|,
comment|/* SW: page must be forced to swap */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* SW: is fill on demand (=0) */
name|pg_prot
range|:
literal|2
decl_stmt|;
comment|/* SW: access control */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|pg_prot
range|:
literal|2
decl_stmt|,
comment|/* SW: access control */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* SW: is fill on demand (=0) */
name|pg_swapm
range|:
literal|1
decl_stmt|,
comment|/* SW: page must be forced to swap */
range|:
literal|4
decl_stmt|,
name|pg_g
range|:
literal|1
decl_stmt|,
comment|/* HW: ignore pid bit */
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* HW: valid bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* HW: modified (dirty) bit */
name|pg_n
range|:
literal|1
decl_stmt|,
comment|/* HW: non-cacheable bit */
name|pg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* HW: core page frame number or 0 */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
name|pt_entry
block|{
name|unsigned
name|int
name|pt_entry
decl_stmt|;
comment|/* for copying, etc. */
name|struct
name|pte
name|pt_pte
decl_stmt|;
comment|/* for getting to bits by name */
block|}
name|pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/* Mach page table entry */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
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
name|PG_PROT
value|0x00000003
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
name|PG_RO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PG_WIRED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PG_G
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PG_V
value|0x00000200
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
name|PG_M
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PG_N
value|0x00000800
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_comment
comment|/*  * Kernel virtual address to page table entry and visa versa.  */
end_comment

begin_define
define|#
directive|define
name|kvtopte
parameter_list|(
name|va
parameter_list|)
define|\
value|(Sysmap + (((vm_offset_t)(va) - VM_MIN_KERNEL_ADDRESS)>> PGSHIFT))
end_define

begin_define
define|#
directive|define
name|ptetokv
parameter_list|(
name|pte
parameter_list|)
define|\
value|((((pt_entry_t *)(pte) - Sysmap)<< PGSHIFT) + VM_MIN_KERNEL_ADDRESS)
end_define

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|Sysmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel pte table */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|Sysmapsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pte's in Sysmap */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

