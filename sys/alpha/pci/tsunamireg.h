begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * 21271 Chipset registers and constants.  *  * Taken from Tsunami/Typhoon Specification Rev. 1.2  * and Compaq Professional Workstation XP1000: Technical  * Information, both graciously provided by Don Rice   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|u_int64_t
name|reg
name|__attribute__
decl|((
name|aligned
decl|(64
decl_stmt|)
block|)
typedef|);
end_typedef

begin_empty_stmt
unit|} tsunami_reg
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* notes */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tsunami_reg
name|csc
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|mtr
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|misc
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|mpd
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|aar0
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|aar1
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|aar2
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|aar3
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|dim0
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|dim1
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|dir0
decl_stmt|;
comment|/* ro */
name|tsunami_reg
name|dir1
decl_stmt|;
comment|/* ro */
name|tsunami_reg
name|drir
decl_stmt|;
comment|/* ro */
name|tsunami_reg
name|prben
decl_stmt|;
comment|/* "special" */
name|tsunami_reg
name|iic0
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|iic1
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|mpr0
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|mpr1
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|mpr2
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|mpr3
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|mctl
decl_stmt|;
comment|/* rw, Tsunami only */
name|tsunami_reg
name|ttr
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|tdr
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|dim2
decl_stmt|;
comment|/* rw, Typhoon only */
name|tsunami_reg
name|dim3
decl_stmt|;
comment|/* rw, Typhoon only */
name|tsunami_reg
name|dir2
decl_stmt|;
comment|/* ro, Typhoon only */
name|tsunami_reg
name|dir3
decl_stmt|;
comment|/* ro, Typhoon only */
name|tsunami_reg
name|iic2
decl_stmt|;
comment|/* rw, Typhoon only */
name|tsunami_reg
name|iic3
decl_stmt|;
comment|/* rw, Typhoon only */
name|tsunami_reg
name|pwr
decl_stmt|;
comment|/* rw */
block|}
name|tsunami_cchip
typedef|;
end_typedef

begin_comment
comment|/*  *  cchip csc defines  */
end_comment

begin_define
define|#
directive|define
name|CSC_P1P
value|(1L<< 14)
end_define

begin_comment
comment|/* pchip1 present if this bit is set in  				   chip->csc */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tsunami_reg
name|dsc
decl_stmt|;
name|tsunami_reg
name|str
decl_stmt|;
name|tsunami_reg
name|drev
decl_stmt|;
block|}
name|tsunami_dchip
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tsunami_reg
name|wsba
index|[
literal|4
index|]
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|wsm
index|[
literal|4
index|]
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|tba
index|[
literal|4
index|]
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|pctl
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|plat
decl_stmt|;
comment|/* ro */
name|tsunami_reg
name|reserved
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|perror
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|perrmask
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|perrset
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|tlbiv
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|tlbia
decl_stmt|;
comment|/* wo */
name|tsunami_reg
name|pmonctl
decl_stmt|;
comment|/* rw */
name|tsunami_reg
name|pmoncnt
decl_stmt|;
comment|/* rw */
block|}
name|tsunami_pchip
typedef|;
end_typedef

begin_comment
comment|/*  * pchip window defines  */
end_comment

begin_define
define|#
directive|define
name|WINDOW_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|WINDOW_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|WINDOW_SCATTER_GATHER
value|0x2
end_define

begin_define
define|#
directive|define
name|WINDOW_DIRECT_MAPPED
value|0x0
end_define

begin_define
define|#
directive|define
name|KV
parameter_list|(
name|pa
parameter_list|)
value|ALPHA_PHYS_TO_K0SEG(pa)
end_define

begin_define
define|#
directive|define
name|cchip
value|((tsunami_cchip *)(KV(0x101A0000000UL)))
end_define

begin_define
define|#
directive|define
name|dchip
value|((tsunami_dchip *)(KV(0x101B0000800UL)))
end_define

begin_define
define|#
directive|define
name|pchip0
value|((tsunami_pchip *)(KV(0x10180000000UL)))
end_define

begin_define
define|#
directive|define
name|pchip1
value|((tsunami_pchip *)(KV(0x10380000000UL)))
end_define

begin_comment
comment|/*  *   memory / i/o space macros  *  */
end_comment

begin_define
define|#
directive|define
name|HOSE
parameter_list|(
name|h
parameter_list|)
value|(((unsigned long)(h))<< 33)
end_define

begin_define
define|#
directive|define
name|TSUNAMI_MEM
parameter_list|(
name|h
parameter_list|)
value|(0x10000000000UL + HOSE(h))
end_define

begin_define
define|#
directive|define
name|TSUNAMI_IACK_SC
parameter_list|(
name|h
parameter_list|)
value|(0x101F8000000UL + HOSE(h))
end_define

begin_define
define|#
directive|define
name|TSUNAMI_IO
parameter_list|(
name|h
parameter_list|)
value|(0x101FC000000UL + HOSE(h))
end_define

begin_define
define|#
directive|define
name|TSUNAMI_CONF
parameter_list|(
name|h
parameter_list|)
value|(0x101FE000000UL + HOSE(h))
end_define

begin_define
define|#
directive|define
name|TSUNAMI_MAXHOSES
value|4
end_define

end_unit

