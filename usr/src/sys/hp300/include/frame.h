begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: frame.h 1.8 92/12/20$  *  *	@(#)frame.h	8.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|f_regs
index|[
literal|16
index|]
decl_stmt|;
name|short
name|f_pad
decl_stmt|;
name|short
name|f_stackadj
decl_stmt|;
name|u_short
name|f_sr
decl_stmt|;
name|u_int
name|f_pc
decl_stmt|;
name|u_short
name|f_format
range|:
literal|4
decl_stmt|,
name|f_vector
range|:
literal|12
decl_stmt|;
union|union
name|F_u
block|{
struct|struct
name|fmt2
block|{
name|u_int
name|f_iaddr
decl_stmt|;
block|}
name|F_fmt2
struct|;
struct|struct
name|fmt3
block|{
name|u_int
name|f_ea
decl_stmt|;
block|}
name|F_fmt3
struct|;
struct|struct
name|fmt7
block|{
name|u_int
name|f_ea
decl_stmt|;
name|u_short
name|f_ssw
decl_stmt|;
name|u_short
name|f_wb3s
decl_stmt|,
name|f_wb2s
decl_stmt|,
name|f_wb1s
decl_stmt|;
name|u_int
name|f_fa
decl_stmt|;
name|u_int
name|f_wb3a
decl_stmt|,
name|f_wb3d
decl_stmt|;
name|u_int
name|f_wb2a
decl_stmt|,
name|f_wb2d
decl_stmt|;
name|u_int
name|f_wb1a
decl_stmt|,
name|f_wb1d
decl_stmt|;
define|#
directive|define
name|f_pd0
value|f_wb1d
name|u_int
name|f_pd1
decl_stmt|,
name|f_pd2
decl_stmt|,
name|f_pd3
decl_stmt|;
block|}
name|F_fmt7
struct|;
struct|struct
name|fmt9
block|{
name|u_int
name|f_iaddr
decl_stmt|;
name|u_short
name|f_iregs
index|[
literal|4
index|]
decl_stmt|;
block|}
name|F_fmt9
struct|;
struct|struct
name|fmtA
block|{
name|u_short
name|f_ir0
decl_stmt|;
name|u_short
name|f_ssw
decl_stmt|;
name|u_short
name|f_ipsc
decl_stmt|;
name|u_short
name|f_ipsb
decl_stmt|;
name|u_int
name|f_dcfa
decl_stmt|;
name|u_short
name|f_ir1
decl_stmt|,
name|f_ir2
decl_stmt|;
name|u_int
name|f_dob
decl_stmt|;
name|u_short
name|f_ir3
decl_stmt|,
name|f_ir4
decl_stmt|;
block|}
name|F_fmtA
struct|;
struct|struct
name|fmtB
block|{
name|u_short
name|f_ir0
decl_stmt|;
name|u_short
name|f_ssw
decl_stmt|;
name|u_short
name|f_ipsc
decl_stmt|;
name|u_short
name|f_ipsb
decl_stmt|;
name|u_int
name|f_dcfa
decl_stmt|;
name|u_short
name|f_ir1
decl_stmt|,
name|f_ir2
decl_stmt|;
name|u_int
name|f_dob
decl_stmt|;
name|u_short
name|f_ir3
decl_stmt|,
name|f_ir4
decl_stmt|;
name|u_short
name|f_ir5
decl_stmt|,
name|f_ir6
decl_stmt|;
name|u_int
name|f_sba
decl_stmt|;
name|u_short
name|f_ir7
decl_stmt|,
name|f_ir8
decl_stmt|;
name|u_int
name|f_dib
decl_stmt|;
name|u_short
name|f_iregs
index|[
literal|22
index|]
decl_stmt|;
block|}
name|F_fmtB
struct|;
block|}
name|F_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|f_fmt2
value|F_u.F_fmt2
end_define

begin_define
define|#
directive|define
name|f_fmt3
value|F_u.F_fmt3
end_define

begin_define
define|#
directive|define
name|f_fmt7
value|F_u.F_fmt7
end_define

begin_define
define|#
directive|define
name|f_fmt9
value|F_u.F_fmt9
end_define

begin_define
define|#
directive|define
name|f_fmtA
value|F_u.F_fmtA
end_define

begin_define
define|#
directive|define
name|f_fmtB
value|F_u.F_fmtB
end_define

begin_comment
comment|/* common frame size */
end_comment

begin_define
define|#
directive|define
name|CFSIZE
value|(sizeof(struct frame) - sizeof(union F_u))
end_define

begin_define
define|#
directive|define
name|NFMTSIZE
value|8
end_define

begin_define
define|#
directive|define
name|FMT0
value|0x0
end_define

begin_define
define|#
directive|define
name|FMT1
value|0x1
end_define

begin_define
define|#
directive|define
name|FMT2
value|0x2
end_define

begin_define
define|#
directive|define
name|FMT3
value|0x3
end_define

begin_define
define|#
directive|define
name|FMT7
value|0x7
end_define

begin_define
define|#
directive|define
name|FMT9
value|0x9
end_define

begin_define
define|#
directive|define
name|FMTA
value|0xA
end_define

begin_define
define|#
directive|define
name|FMTB
value|0xB
end_define

begin_comment
comment|/* frame specific info sizes */
end_comment

begin_define
define|#
directive|define
name|FMT0SIZE
value|0
end_define

begin_define
define|#
directive|define
name|FMT1SIZE
value|0
end_define

begin_define
define|#
directive|define
name|FMT2SIZE
value|sizeof(struct fmt2)
end_define

begin_define
define|#
directive|define
name|FMT3SIZE
value|sizeof(struct fmt3)
end_define

begin_define
define|#
directive|define
name|FMT7SIZE
value|sizeof(struct fmt7)
end_define

begin_define
define|#
directive|define
name|FMT9SIZE
value|sizeof(struct fmt9)
end_define

begin_define
define|#
directive|define
name|FMTASIZE
value|sizeof(struct fmtA)
end_define

begin_define
define|#
directive|define
name|FMTBSIZE
value|sizeof(struct fmtB)
end_define

begin_define
define|#
directive|define
name|V_BUSERR
value|0x008
end_define

begin_define
define|#
directive|define
name|V_ADDRERR
value|0x00C
end_define

begin_define
define|#
directive|define
name|V_TRAP1
value|0x084
end_define

begin_comment
comment|/* 68020/68030 SSW bits */
end_comment

begin_define
define|#
directive|define
name|SSW_RC
value|0x2000
end_define

begin_define
define|#
directive|define
name|SSW_RB
value|0x1000
end_define

begin_define
define|#
directive|define
name|SSW_DF
value|0x0100
end_define

begin_define
define|#
directive|define
name|SSW_RM
value|0x0080
end_define

begin_define
define|#
directive|define
name|SSW_RW
value|0x0040
end_define

begin_define
define|#
directive|define
name|SSW_FCMASK
value|0x0007
end_define

begin_comment
comment|/* 68040 SSW bits */
end_comment

begin_define
define|#
directive|define
name|SSW4_CP
value|0x8000
end_define

begin_define
define|#
directive|define
name|SSW4_CU
value|0x4000
end_define

begin_define
define|#
directive|define
name|SSW4_CT
value|0x2000
end_define

begin_define
define|#
directive|define
name|SSW4_CM
value|0x1000
end_define

begin_define
define|#
directive|define
name|SSW4_MA
value|0x0800
end_define

begin_define
define|#
directive|define
name|SSW4_ATC
value|0x0400
end_define

begin_define
define|#
directive|define
name|SSW4_LK
value|0x0200
end_define

begin_define
define|#
directive|define
name|SSW4_RW
value|0x0100
end_define

begin_define
define|#
directive|define
name|SSW4_WBSV
value|0x0080
end_define

begin_comment
comment|/* really in WB status, not SSW */
end_comment

begin_define
define|#
directive|define
name|SSW4_SZMASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|SSW4_SZLW
value|0x0000
end_define

begin_define
define|#
directive|define
name|SSW4_SZB
value|0x0020
end_define

begin_define
define|#
directive|define
name|SSW4_SZW
value|0x0040
end_define

begin_define
define|#
directive|define
name|SSW4_SZLN
value|0x0060
end_define

begin_define
define|#
directive|define
name|SSW4_TTMASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|SSW4_TTNOR
value|0x0000
end_define

begin_define
define|#
directive|define
name|SSW4_TTM16
value|0x0008
end_define

begin_define
define|#
directive|define
name|SSW4_TMMASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|SSW4_TMDCP
value|0x0000
end_define

begin_define
define|#
directive|define
name|SSW4_TMUD
value|0x0001
end_define

begin_define
define|#
directive|define
name|SSW4_TMUC
value|0x0002
end_define

begin_define
define|#
directive|define
name|SSW4_TMKD
value|0x0005
end_define

begin_define
define|#
directive|define
name|SSW4_TMKC
value|0x0006
end_define

begin_struct
struct|struct
name|fpframe
block|{
union|union
name|FPF_u1
block|{
name|u_int
name|FPF_null
decl_stmt|;
struct|struct
block|{
name|u_char
name|FPF_version
decl_stmt|;
name|u_char
name|FPF_fsize
decl_stmt|;
name|u_short
name|FPF_res1
decl_stmt|;
block|}
name|FPF_nonnull
struct|;
block|}
name|FPF_u1
union|;
union|union
name|FPF_u2
block|{
struct|struct
name|fpidle
block|{
name|u_short
name|fpf_ccr
decl_stmt|;
name|u_short
name|fpf_res2
decl_stmt|;
name|u_int
name|fpf_iregs1
index|[
literal|8
index|]
decl_stmt|;
name|u_int
name|fpf_xops
index|[
literal|3
index|]
decl_stmt|;
name|u_int
name|fpf_opreg
decl_stmt|;
name|u_int
name|fpf_biu
decl_stmt|;
block|}
name|FPF_idle
struct|;
struct|struct
name|fpbusy
block|{
name|u_int
name|fpf_iregs
index|[
literal|53
index|]
decl_stmt|;
block|}
name|FPF_busy
struct|;
struct|struct
name|fpunimp
block|{
name|u_int
name|fpf_state
index|[
literal|10
index|]
decl_stmt|;
block|}
name|FPF_unimp
struct|;
block|}
name|FPF_u2
union|;
name|u_int
name|fpf_regs
index|[
literal|8
operator|*
literal|3
index|]
decl_stmt|;
name|u_int
name|fpf_fpcr
decl_stmt|;
name|u_int
name|fpf_fpsr
decl_stmt|;
name|u_int
name|fpf_fpiar
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fpf_null
value|FPF_u1.FPF_null
end_define

begin_define
define|#
directive|define
name|fpf_version
value|FPF_u1.FPF_nonnull.FPF_version
end_define

begin_define
define|#
directive|define
name|fpf_fsize
value|FPF_u1.FPF_nonnull.FPF_fsize
end_define

begin_define
define|#
directive|define
name|fpf_res1
value|FPF_u1.FPF_nonnull.FPF_res1
end_define

begin_define
define|#
directive|define
name|fpf_idle
value|FPF_u2.FPF_idle
end_define

begin_define
define|#
directive|define
name|fpf_busy
value|FPF_u2.FPF_busy
end_define

begin_define
define|#
directive|define
name|fpf_unimp
value|FPF_u2.FPF_unimp
end_define

end_unit

