begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ctreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|ct_iocmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|saddr
decl_stmt|;
name|short
name|addr0
decl_stmt|;
name|long
name|addr
decl_stmt|;
name|char
name|nop2
decl_stmt|;
name|char
name|slen
decl_stmt|;
name|long
name|len
decl_stmt|;
name|char
name|nop3
decl_stmt|;
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_rscmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_stat
block|{
name|char
name|c_vu
decl_stmt|;
name|char
name|c_pend
decl_stmt|;
name|short
name|c_ref
decl_stmt|;
name|short
name|c_fef
decl_stmt|;
name|short
name|c_aef
decl_stmt|;
name|short
name|c_ief
decl_stmt|;
name|short
name|c_blk0
decl_stmt|;
name|long
name|c_blk
decl_stmt|;
name|char
name|c_pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_ssmcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|cmd
decl_stmt|;
name|short
name|refm
decl_stmt|;
name|short
name|fefm
decl_stmt|;
name|short
name|aefm
decl_stmt|;
name|short
name|iefm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_srcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|nop
decl_stmt|;
name|char
name|cmd
decl_stmt|;
name|char
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_soptcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|nop
decl_stmt|;
name|char
name|cmd
decl_stmt|;
name|char
name|opt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_ulcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_wfmcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_clearcmd
block|{
name|char
name|unit
decl_stmt|;
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_describe
block|{
name|u_int
name|d_iuw
range|:
literal|16
decl_stmt|,
comment|/* controller: installed unit word */
name|d_cmaxxfr
range|:
literal|16
decl_stmt|,
comment|/* controller: max transfer rate (Kb) */
name|d_ctype
range|:
literal|8
decl_stmt|,
comment|/* controller: controller type */
name|d_utype
range|:
literal|8
decl_stmt|,
comment|/* unit: unit type */
name|d_name
range|:
literal|24
decl_stmt|,
comment|/* unit: name (6 BCD digits) */
name|d_sectsize
range|:
literal|16
decl_stmt|,
comment|/* unit: # of bytes per block (sector) */
name|d_blkbuf
range|:
literal|8
decl_stmt|,
comment|/* unit: # of blocks which can be buffered */
name|d_burstsize
range|:
literal|8
decl_stmt|,
comment|/* unit: recommended burst size */
name|d_blocktime
range|:
literal|16
decl_stmt|,
comment|/* unit: block time (u-sec) */
name|d_uavexfr
range|:
literal|16
decl_stmt|,
comment|/* unit: average transfer rate (Kb) */
name|d_retry
range|:
literal|16
decl_stmt|,
comment|/* unit: optimal retry time (1/100-sec) */
name|d_access
range|:
literal|16
decl_stmt|,
comment|/* unit: access time param (1/100-sec) */
name|d_maxint
range|:
literal|8
decl_stmt|,
comment|/* unit: maximum interleave */
name|d_fvbyte
range|:
literal|8
decl_stmt|,
comment|/* unit: fixed volume byte */
name|d_rvbyte
range|:
literal|8
decl_stmt|,
comment|/* unit: removeable volume byte */
name|d_maxcyl
range|:
literal|24
decl_stmt|,
comment|/* volume: maximum cylinder */
name|d_maxhead
range|:
literal|8
decl_stmt|,
comment|/* volume: maximum head */
name|d_maxsect
range|:
literal|16
decl_stmt|,
comment|/* volume: maximum sector on track */
name|d_maxvsecth
range|:
literal|16
decl_stmt|,
comment|/* volume: maximum sector on volume (MSW) */
name|d_maxvsectl
range|:
literal|32
decl_stmt|,
comment|/* volume: maximum sector on volume (LSWs) */
name|d_interleave
range|:
literal|8
decl_stmt|;
comment|/* volume: current interleave */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CT7946ID
value|0x220
end_define

begin_define
define|#
directive|define
name|CT9145ID
value|0x268
end_define

begin_define
define|#
directive|define
name|CT9144ID
value|0x260
end_define

begin_define
define|#
directive|define
name|CT9144
value|0
end_define

begin_define
define|#
directive|define
name|CT7912PID
value|0x209
end_define

begin_define
define|#
directive|define
name|CT7914PID
value|0x20B
end_define

begin_define
define|#
directive|define
name|CT88140
value|1
end_define

begin_comment
comment|/* convert bytes to 1k tape block and back */
end_comment

begin_define
define|#
directive|define
name|CTBTOK
parameter_list|(
name|x
parameter_list|)
value|((x)>> 10)
end_define

begin_define
define|#
directive|define
name|CTKTOB
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|CTCTLR
value|15
end_define

begin_define
define|#
directive|define
name|REF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|FEF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|AEF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|IEF_MASK
value|0xF970
end_define

begin_define
define|#
directive|define
name|FEF_PF
value|0x0002
end_define

begin_define
define|#
directive|define
name|FEF_REXMT
value|0x0001
end_define

begin_define
define|#
directive|define
name|AEF_EOF
value|0x0010
end_define

begin_define
define|#
directive|define
name|AEF_EOV
value|0x0008
end_define

begin_define
define|#
directive|define
name|C_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|C_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|C_CLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|C_STATUS
value|0x0d
end_define

begin_define
define|#
directive|define
name|C_SADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|C_SLEN
value|0x18
end_define

begin_define
define|#
directive|define
name|C_SUNIT
parameter_list|(
name|x
parameter_list|)
value|(0x20 | (x))
end_define

begin_define
define|#
directive|define
name|C_SVOL
parameter_list|(
name|x
parameter_list|)
value|(0x40 | (x))
end_define

begin_define
define|#
directive|define
name|C_NOP
value|0x34
end_define

begin_define
define|#
directive|define
name|C_DESC
value|0x35
end_define

begin_define
define|#
directive|define
name|C_SOPT
value|0x38
end_define

begin_define
define|#
directive|define
name|C_SREL
value|0x3b
end_define

begin_define
define|#
directive|define
name|C_SSM
value|0x3e
end_define

begin_define
define|#
directive|define
name|C_WFM
value|0x49
end_define

begin_define
define|#
directive|define
name|C_UNLOAD
value|0x4a
end_define

begin_define
define|#
directive|define
name|C_REL
value|0x140
end_define

begin_define
define|#
directive|define
name|C_CMD
value|0x05
end_define

begin_define
define|#
directive|define
name|C_EXEC
value|0x0e
end_define

begin_define
define|#
directive|define
name|C_QSTAT
value|0x10
end_define

begin_define
define|#
directive|define
name|C_TCMD
value|0x12
end_define

begin_define
define|#
directive|define
name|C_CC
value|1
end_define

begin_define
define|#
directive|define
name|C_SKSPAR
value|2
end_define

begin_define
define|#
directive|define
name|C_OPT
value|4
end_define

begin_define
define|#
directive|define
name|C_SPAR
value|4
end_define

begin_define
define|#
directive|define
name|C_IMRPT
value|8
end_define

end_unit

