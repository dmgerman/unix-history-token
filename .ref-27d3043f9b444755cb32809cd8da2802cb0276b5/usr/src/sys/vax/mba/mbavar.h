begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mbavar.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * VAX Massbus adapter registers  */
end_comment

begin_struct
struct|struct
name|mba_regs
block|{
name|int
name|mba_csr
decl_stmt|;
name|int
name|mba_cr
decl_stmt|;
name|int
name|mba_sr
decl_stmt|;
name|int
name|mba_var
decl_stmt|;
name|int
name|mba_bcr
decl_stmt|;
name|int
name|mba_dr
decl_stmt|;
name|int
name|mba_pad1
index|[
literal|250
index|]
decl_stmt|;
name|int
name|mba_erb
index|[
literal|8
index|]
index|[
literal|32
index|]
decl_stmt|;
comment|/* external register base */
name|struct
name|pte
name|mba_map
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MBAINIT
value|0x1
end_define

begin_define
define|#
directive|define
name|MBAIE
value|0x4
end_define

begin_define
define|#
directive|define
name|MBAEBITS
value|0xe0770
end_define

begin_define
define|#
directive|define
name|PHYSMBA0
value|((struct mba_regs *)0x20010000)
end_define

begin_define
define|#
directive|define
name|PHYSMBA1
value|((struct mba_regs *)0x20012000)
end_define

begin_define
define|#
directive|define
name|mbadev
parameter_list|(
name|mba
parameter_list|,
name|unit
parameter_list|)
value|((struct device *)mba->mba_erb[unit])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|mba_info
block|{
name|struct
name|mba_regs
modifier|*
name|mi_loc
decl_stmt|;
comment|/* virtual mba */
name|struct
name|mba_regs
modifier|*
name|mi_phys
decl_stmt|;
comment|/* physical mba */
name|struct
name|pte
modifier|*
name|mi_map
decl_stmt|;
comment|/* page table base for nexus */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MBA0
value|((struct mba_regs *)0x80064000)
end_define

begin_define
define|#
directive|define
name|MBA1
value|((struct mba_regs *)0x80066000)
end_define

begin_decl_stmt
name|int
name|mbanum
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mba_info
name|mbainfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mbaact
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

