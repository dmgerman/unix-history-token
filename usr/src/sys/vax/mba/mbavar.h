begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mbavar.h	4.3	%G%	*/
end_comment

begin_if
if|#
directive|if
name|VAX
operator|==
literal|780
end_if

begin_comment
comment|/*  * VAX Massbus adapter registers  */
end_comment

begin_struct
struct|struct
name|mba_drv
block|{
name|int
name|mbd_cs1
decl_stmt|;
name|int
name|mbd_ds
decl_stmt|;
name|int
name|mbd_er1
decl_stmt|;
name|int
name|mbd_mr1
decl_stmt|;
name|int
name|mbd_as
decl_stmt|;
name|int
name|mbd_da
decl_stmt|;
define|#
directive|define
name|mbd_fc
value|mbd_da
name|int
name|mbd_dt
decl_stmt|;
name|int
name|mbd_la
decl_stmt|;
define|#
directive|define
name|mbd_ck
value|mbd_la
name|int
name|mbd_sn
decl_stmt|;
name|int
name|mbd_of
decl_stmt|;
define|#
directive|define
name|mbd_tc
value|mbd_of
name|int
name|mbd_fill
index|[
literal|22
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in mbd_dt.  */
end_comment

begin_define
define|#
directive|define
name|MBDT_NSA
value|0x8000
end_define

begin_comment
comment|/* not sector addressible */
end_comment

begin_define
define|#
directive|define
name|MBDT_TAP
value|0x4000
end_define

begin_comment
comment|/* is a tape */
end_comment

begin_define
define|#
directive|define
name|MBDT_MOH
value|0x2000
end_define

begin_comment
comment|/* moving head */
end_comment

begin_define
define|#
directive|define
name|MBDT_7CH
value|0x1000
end_define

begin_comment
comment|/* 7 channel */
end_comment

begin_define
define|#
directive|define
name|MBDT_DRQ
value|0x800
end_define

begin_comment
comment|/* drive request required */
end_comment

begin_define
define|#
directive|define
name|MBDT_SPR
value|0x400
end_define

begin_comment
comment|/* slave present */
end_comment

begin_define
define|#
directive|define
name|MBDT_TYPE
value|0x1ff
end_define

begin_define
define|#
directive|define
name|MBDT_MASK
value|(MBDT_NSA|MBDT_TAP|MBDT_TYPE)
end_define

begin_define
define|#
directive|define
name|MBDT_RP04
value|020
end_define

begin_define
define|#
directive|define
name|MBDT_RP05
value|021
end_define

begin_define
define|#
directive|define
name|MBDT_RP06
value|022
end_define

begin_define
define|#
directive|define
name|MBDT_RP07
value|042
end_define

begin_define
define|#
directive|define
name|MBDT_RM03
value|024
end_define

begin_define
define|#
directive|define
name|MBDT_RM05
value|027
end_define

begin_define
define|#
directive|define
name|MBDT_RM80
value|026
end_define

begin_define
define|#
directive|define
name|MBDT_TM03
value|050
end_define

begin_define
define|#
directive|define
name|MBDT_TE16
value|051
end_define

begin_define
define|#
directive|define
name|MBDT_TU45
value|052
end_define

begin_define
define|#
directive|define
name|MBDT_TU77
value|054
end_define

begin_define
define|#
directive|define
name|MBDT_TU78
value|0140
end_define

begin_comment
comment|/*  * Bits in mbd_ds.  */
end_comment

begin_define
define|#
directive|define
name|MBD_DRY
value|0x80
end_define

begin_define
define|#
directive|define
name|MBD_MOL
value|0x1000
end_define

begin_define
define|#
directive|define
name|MBD_DPR
value|0x100
end_define

begin_define
define|#
directive|define
name|MBD_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|MBD_WCOM
value|0x30
end_define

begin_define
define|#
directive|define
name|MBD_RCOM
value|0x38
end_define

begin_define
define|#
directive|define
name|MBD_GO
value|0x1
end_define

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
name|struct
name|mba_drv
name|mba_drv
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|pte
name|mba_map
index|[
literal|256
index|]
decl_stmt|;
name|int
name|mba_pad2
index|[
literal|256
operator|*
literal|5
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
value|((struct device *)&mba->mba_drv[unit])
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

