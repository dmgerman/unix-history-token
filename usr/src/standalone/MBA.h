begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* *	MBA  definitions */
end_comment

begin_comment
comment|/* *	register  offsets */
end_comment

begin_define
define|#
directive|define
name|M_csr
value|0
end_define

begin_comment
comment|/*  configuration/staus reg */
end_comment

begin_define
define|#
directive|define
name|M_cr
value|1
end_define

begin_comment
comment|/* control reg */
end_comment

begin_define
define|#
directive|define
name|M_sr
value|2
end_define

begin_comment
comment|/* status reg */
end_comment

begin_define
define|#
directive|define
name|M_var
value|3
end_define

begin_comment
comment|/* virtual address reg */
end_comment

begin_define
define|#
directive|define
name|M_bc
value|4
end_define

begin_comment
comment|/* byte count reg */
end_comment

begin_define
define|#
directive|define
name|M_map
value|0x200
end_define

begin_comment
comment|/* start of map regs-longword offset */
end_comment

begin_comment
comment|/* *  misc */
end_comment

begin_define
define|#
directive|define
name|M_BASE
value|0x20010000
end_define

begin_comment
comment|/* phys addr MBA 0 */
end_comment

begin_define
define|#
directive|define
name|NEXSPC
value|0x2000
end_define

begin_comment
comment|/*  no.bytes/NEXUS space */
end_comment

begin_define
define|#
directive|define
name|MAXMBA
value|4
end_define

begin_comment
comment|/*  max. no. of MBA's */
end_comment

begin_define
define|#
directive|define
name|MBAinit
value|1
end_define

begin_comment
comment|/* MBA init in cr */
end_comment

begin_define
define|#
directive|define
name|M_extern
value|0x400
end_define

begin_comment
comment|/*  offset from MBA base to extern reg's */
end_comment

begin_define
define|#
directive|define
name|EXTSIZ
value|0x80
end_define

begin_comment
comment|/*  extern reg space size/device */
end_comment

begin_define
define|#
directive|define
name|M_BCMAX
value|65536
end_define

begin_comment
comment|/* max byte transfer by MBA */
end_comment

begin_comment
comment|/* *  Status  Reg */
end_comment

begin_define
define|#
directive|define
name|M_RDT
value|1
end_define

begin_comment
comment|/* Read Data Timeout */
end_comment

begin_define
define|#
directive|define
name|M_IST
value|2
end_define

begin_comment
comment|/* Interface Sequence Timeout */
end_comment

begin_define
define|#
directive|define
name|M_RDS
value|4
end_define

begin_comment
comment|/* Read Data Substitute */
end_comment

begin_define
define|#
directive|define
name|M_EC
value|8
end_define

begin_comment
comment|/* Error Confirmation */
end_comment

begin_define
define|#
directive|define
name|M_IM
value|0x10
end_define

begin_comment
comment|/* Invalid Map */
end_comment

begin_define
define|#
directive|define
name|M_MPE
value|0x20
end_define

begin_comment
comment|/* Map Parity Error */
end_comment

begin_define
define|#
directive|define
name|M_MDPE
value|0x40
end_define

begin_comment
comment|/* Massbus Data Parity Error */
end_comment

begin_define
define|#
directive|define
name|M_ME
value|0x80
end_define

begin_comment
comment|/* Massbus Exception */
end_comment

begin_define
define|#
directive|define
name|M_MT
value|0x100
end_define

begin_comment
comment|/* Missed Transfer */
end_comment

begin_define
define|#
directive|define
name|M_WCKL
value|0x200
end_define

begin_comment
comment|/* Write Check Lower */
end_comment

begin_define
define|#
directive|define
name|M_WCKU
value|0x400
end_define

begin_comment
comment|/* Write Check Upper */
end_comment

begin_define
define|#
directive|define
name|M_DTL
value|0x800
end_define

begin_comment
comment|/* Data Transfer Late */
end_comment

begin_define
define|#
directive|define
name|M_DTA
value|0x1000
end_define

begin_comment
comment|/* Data Transfer Abort */
end_comment

begin_define
define|#
directive|define
name|M_DTC
value|0x2000
end_define

begin_comment
comment|/* Data Transfer Complete */
end_comment

begin_define
define|#
directive|define
name|M_MA
value|0x10000
end_define

begin_comment
comment|/*  Massbus Attention */
end_comment

begin_define
define|#
directive|define
name|M_MCPE
value|0x20000
end_define

begin_comment
comment|/* Massbus Control Parity Error */
end_comment

begin_define
define|#
directive|define
name|M_NED
value|0x40000
end_define

begin_comment
comment|/* Non-Existent Drive */
end_comment

begin_define
define|#
directive|define
name|M_PE
value|0x80000
end_define

begin_comment
comment|/* Programming Error */
end_comment

begin_define
define|#
directive|define
name|M_CRD
value|0x20000000
end_define

begin_comment
comment|/* Corrected Read Data */
end_comment

begin_define
define|#
directive|define
name|M_NRC
value|0x40000000
end_define

begin_comment
comment|/* No Response Confirmation */
end_comment

begin_define
define|#
directive|define
name|M_DTB
value|0x80000000
end_define

begin_comment
comment|/* Data Transfer Busy */
end_comment

end_unit

