begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_apxreg.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * SGS Thompson MK5205 structures and registers  */
end_comment

begin_comment
comment|/*   * Device Control Ports (Multiplexed CSR's)  */
end_comment

begin_struct
struct|struct
name|sgcp
block|{
name|u_short
name|sgcp_rdp
decl_stmt|;
name|u_short
name|sgcp_rap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Operating Parameters for timers etc.  * (Suitable for reseting by ioctl).  */
end_comment

begin_struct
struct|struct
name|sgop
block|{
name|u_short
name|lsaddr
decl_stmt|;
name|u_short
name|rsaddr
decl_stmt|;
name|u_short
name|n1
decl_stmt|;
name|u_short
name|n2_scale
decl_stmt|;
name|u_short
name|t1
decl_stmt|;
name|u_short
name|t3
decl_stmt|;
name|u_short
name|tp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common addressing element rife through chip  */
end_comment

begin_struct
struct|struct
name|sgae
block|{
name|u_short
name|f_hi
decl_stmt|;
name|u_short
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common format for tx/rx descriptors  */
end_comment

begin_struct
struct|struct
name|sgdx
block|{
name|struct
name|sgae
name|sgdx_ae
decl_stmt|;
define|#
directive|define
name|sgdx_flags
value|sgdx_ae.f_hi
define|#
directive|define
name|sgdx_addr
value|sgdx_ae.lo
name|short
name|sgdx_bcnt
decl_stmt|;
name|short
name|sgdx_mcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interpretation of reported errors   */
end_comment

begin_struct
struct|struct
name|sger
block|{
name|u_short
name|sger_bad
decl_stmt|;
name|u_short
name|sger_t1timo
decl_stmt|;
name|u_short
name|sger_frmr
decl_stmt|;
name|u_short
name|sger_txrej
decl_stmt|;
name|u_short
name|sger_rxrej
decl_stmt|;
name|u_short
name|sger_short
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status buffer, paired bytes hi order low order  */
end_comment

begin_struct
struct|struct
name|sgsb
block|{
name|u_short
name|sgsb_vrvs
decl_stmt|;
name|u_short
name|sgsb_lsrs
decl_stmt|;
name|u_short
name|sgsb_phzva
decl_stmt|;
name|u_short
name|sgsb_hirxcnt
decl_stmt|;
name|u_short
name|sgsb_lorxcnt
decl_stmt|;
name|u_short
name|sgsb_hitxcnt
decl_stmt|;
name|u_short
name|sgsb_lotxcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SGMTU
value|1032
end_define

begin_define
define|#
directive|define
name|SGRBUF
value|16
end_define

begin_define
define|#
directive|define
name|SGRBUF_LOG2
value|4
end_define

begin_define
define|#
directive|define
name|SG_RLEN
value|(SGRBUF_LOG2<< 12)
end_define

begin_define
define|#
directive|define
name|SGTBUF
value|8
end_define

begin_define
define|#
directive|define
name|SGTBUF_LOG2
value|3
end_define

begin_define
define|#
directive|define
name|SG_TLEN
value|(SGTBUF_LOG2<< 12)
end_define

begin_comment
comment|/*  * APC-PCX RAM  */
end_comment

begin_struct
struct|struct
name|apc_mem
block|{
comment|/* Initialization Block */
name|u_short
name|apc_mode
decl_stmt|;
name|struct
name|sgop
name|apc_sgop
decl_stmt|;
name|struct
name|sgae
name|apc_rxdd
decl_stmt|;
name|struct
name|sgae
name|apc_txdd
decl_stmt|;
name|struct
name|sgdx
name|apc_txtid
decl_stmt|;
name|struct
name|sgdx
name|apc_rxtid
decl_stmt|;
name|struct
name|sgae
name|apc_stdd
decl_stmt|;
name|struct
name|sger
name|apc_sger
decl_stmt|;
name|struct
name|sgsb
name|apc_sgsb
decl_stmt|;
comment|/* Status Buffer */
name|struct
name|sgdx
name|apc_rxmd
index|[
name|SGRBUF
index|]
decl_stmt|;
comment|/* Receive Message Descriptors */
name|struct
name|sgdx
name|apc_txmd
index|[
name|SGTBUF
index|]
decl_stmt|;
comment|/* Transmit Message Descriptors */
name|char
name|apc_rbuf
index|[
name|SGRBUF
index|]
index|[
name|SGMTU
index|]
decl_stmt|;
comment|/* Receive Message Buffers */
name|char
name|apc_tbuf
index|[
name|SGTBUF
index|]
index|[
name|SGMTU
index|]
decl_stmt|;
comment|/* Transmit Message Buffers */
name|char
name|apc_rxidbuf
index|[
name|SGMTU
index|]
decl_stmt|;
name|char
name|apc_txidbuf
index|[
name|SGMTU
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * APC-PCX registers  */
end_comment

begin_struct
struct|struct
name|apc_reg
block|{
name|struct
name|sgcp
name|axr_sgcp
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|arx_pad0
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|axr_cnt0
decl_stmt|;
name|u_char
name|axr_cnt1
decl_stmt|;
name|u_char
name|axr_cnt2
decl_stmt|;
name|u_char
name|axr_ccr
decl_stmt|;
name|u_char
name|axr_mode
decl_stmt|;
name|u_char
name|axr_pad1
decl_stmt|;
name|u_char
name|axr_status
decl_stmt|;
name|u_char
name|axr_pad2
decl_stmt|;
name|u_char
name|axr_altmode
decl_stmt|;
name|u_char
name|axr_pad3
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hardware tweaking  */
end_comment

begin_struct
struct|struct
name|apc_modes
block|{
name|struct
name|sgop
name|apm_sgop
decl_stmt|;
comment|/* tweak timers */
name|u_char
name|apm_txwin
decl_stmt|;
comment|/* set parameter for transmit window */
name|u_char
name|apm_apxmode
decl_stmt|;
name|u_char
name|apm_apxaltmode
decl_stmt|;
name|u_char
name|apm_iftype
decl_stmt|;
comment|/* someday indicate PPP vs X.25 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCSIFMODE
value|_IOW('i', 127, struct apc_modes)
end_define

begin_comment
comment|/* set parameters */
end_comment

begin_comment
comment|/* TX RX descriptor bits */
end_comment

begin_define
define|#
directive|define
name|SG_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|SG_SLF
value|0x2000
end_define

begin_define
define|#
directive|define
name|SG_ELF
value|0x1000
end_define

begin_define
define|#
directive|define
name|SG_TUI
value|0x800
end_define

begin_comment
comment|/* CSR0 quantities */
end_comment

begin_define
define|#
directive|define
name|SG_TDMD
value|0x8000
end_define

begin_define
define|#
directive|define
name|SG_STOPPED
value|0x4000
end_define

begin_define
define|#
directive|define
name|SG_DTX
value|0x2000
end_define

begin_define
define|#
directive|define
name|SG_DRX
value|0x1000
end_define

begin_define
define|#
directive|define
name|SG_TXON
value|0x800
end_define

begin_define
define|#
directive|define
name|SG_RXON
value|0x400
end_define

begin_define
define|#
directive|define
name|SG_INEA
value|0x200
end_define

begin_define
define|#
directive|define
name|SG_INTR
value|0x100
end_define

begin_define
define|#
directive|define
name|SG_MERR
value|0x80
end_define

begin_define
define|#
directive|define
name|SG_MISS
value|0x40
end_define

begin_define
define|#
directive|define
name|SG_ROR
value|0x20
end_define

begin_define
define|#
directive|define
name|SG_TUR
value|0x10
end_define

begin_define
define|#
directive|define
name|SG_PINT
value|0x8
end_define

begin_define
define|#
directive|define
name|SG_TINT
value|0x4
end_define

begin_define
define|#
directive|define
name|SG_RINT
value|0x2
end_define

begin_comment
comment|/* CSR1 quantities */
end_comment

begin_define
define|#
directive|define
name|SG_UAV
value|0x4000
end_define

begin_define
define|#
directive|define
name|SG_PAV
value|0x40
end_define

begin_define
define|#
directive|define
name|SG_STOP
value|0
end_define

begin_define
define|#
directive|define
name|SG_INIT
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|SG_TRANS
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|SG_STAT
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|SG_PROM
value|0x400
end_define

begin_define
define|#
directive|define
name|SG_UIE
value|0x200
end_define

begin_define
define|#
directive|define
name|SG_BSWAP
value|0x20
end_define

end_unit

