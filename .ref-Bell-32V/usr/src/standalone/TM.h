begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	TM02  register  definitions	*/
end_comment

begin_define
define|#
directive|define
name|TM_cs1
value|0
end_define

begin_comment
comment|/*  TM2 control 1 reg */
end_comment

begin_define
define|#
directive|define
name|TM_ds
value|1
end_define

begin_comment
comment|/*  TM02 status reg */
end_comment

begin_define
define|#
directive|define
name|TM_er
value|2
end_define

begin_comment
comment|/*  TM02 error reg */
end_comment

begin_define
define|#
directive|define
name|TM_mr
value|3
end_define

begin_comment
comment|/*  TM02 maint. reg */
end_comment

begin_define
define|#
directive|define
name|TM_as
value|4
end_define

begin_comment
comment|/*  TM02 attention summary reg */
end_comment

begin_define
define|#
directive|define
name|TM_fc
value|5
end_define

begin_comment
comment|/*  TM02 frame count reg */
end_comment

begin_define
define|#
directive|define
name|TM_dt
value|6
end_define

begin_comment
comment|/*  TM02 drive type reg */
end_comment

begin_define
define|#
directive|define
name|TM_ck
value|7
end_define

begin_comment
comment|/* TM02 check char. reg. */
end_comment

begin_define
define|#
directive|define
name|TM_sn
value|8
end_define

begin_comment
comment|/*  TM02 serial no. reg. */
end_comment

begin_define
define|#
directive|define
name|TM_tc
value|9
end_define

begin_comment
comment|/*  TM02 tape control reg */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM_GO
value|1
end_define

begin_comment
comment|/*  TM2 go bit */
end_comment

begin_define
define|#
directive|define
name|TM_RWND
value|06
end_define

begin_comment
comment|/*  TM2 Rewind  */
end_comment

begin_define
define|#
directive|define
name|TM_DCLR
value|010
end_define

begin_comment
comment|/*  TM2 drive clear function code */
end_comment

begin_define
define|#
directive|define
name|TM_RIP
value|020
end_define

begin_comment
comment|/*  TM02 Read-In Preset command */
end_comment

begin_define
define|#
directive|define
name|TM_ERAS
value|024
end_define

begin_comment
comment|/*  TM02 erase command */
end_comment

begin_define
define|#
directive|define
name|TM_WTM
value|026
end_define

begin_comment
comment|/*  TM02 write-tape-mark command */
end_comment

begin_define
define|#
directive|define
name|TM_SFWD
value|030
end_define

begin_comment
comment|/*  space forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_SREV
value|032
end_define

begin_comment
comment|/*  TM02 space reverse command */
end_comment

begin_define
define|#
directive|define
name|TM_WRTF
value|060
end_define

begin_comment
comment|/* write forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_REDF
value|070
end_define

begin_comment
comment|/*  read forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_RREV
value|076
end_define

begin_comment
comment|/*  TM02 read reverse command */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM_DRDY
value|0x80
end_define

begin_comment
comment|/*  TM2/drive ready,status reg */
end_comment

begin_define
define|#
directive|define
name|TM_ERR
value|0x4000
end_define

begin_comment
comment|/*  TM2 composite error, status reg */
end_comment

begin_define
define|#
directive|define
name|TM_MOL
value|0x1000
end_define

begin_comment
comment|/* TM02 medium-on-line status bit */
end_comment

begin_define
define|#
directive|define
name|TM_TM
value|0x4
end_define

begin_comment
comment|/* tape mark bit in TM02 status reg */
end_comment

begin_define
define|#
directive|define
name|TM_EOT
value|0x400
end_define

begin_comment
comment|/*  end-of-tape bit in status reg */
end_comment

begin_define
define|#
directive|define
name|TM_FCE
value|0x200
end_define

begin_comment
comment|/* TM02 frame count error bit */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM_EPAR
value|0x8
end_define

begin_comment
comment|/* even parity bit in TM02 control reg */
end_comment

begin_define
define|#
directive|define
name|TM_PNOR
value|0xc0
end_define

begin_comment
comment|/*  PDP11 normal mode for tape control reg */
end_comment

begin_define
define|#
directive|define
name|TM_D800
value|0x300
end_define

begin_comment
comment|/* TM02 800BPI for tc reg */
end_comment

begin_define
define|#
directive|define
name|TM_D1600
value|0x400
end_define

begin_comment
comment|/*  TM02 1600BPI PE for tc reg */
end_comment

begin_define
define|#
directive|define
name|TM_EABO
value|0x1000
end_define

begin_comment
comment|/*  TM02 enable abort bit in tc reg */
end_comment

end_unit

