begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tmreg.h	4.6	82/02/03	*/
end_comment

begin_comment
comment|/*  * TM11 controller registers  */
end_comment

begin_struct
struct|struct
name|tmdevice
block|{
name|u_short
name|tmer
decl_stmt|;
comment|/* error register, per drive */
name|u_short
name|tmcs
decl_stmt|;
comment|/* control-status register */
name|short
name|tmbc
decl_stmt|;
comment|/* byte/frame count */
name|u_short
name|tmba
decl_stmt|;
comment|/* address */
name|short
name|tmdb
decl_stmt|;
comment|/* data buffer */
name|short
name|tmrd
decl_stmt|;
comment|/* read lines */
name|short
name|tmmr
decl_stmt|;
comment|/* maintenance register */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|b_repcnt
value|b_bcount
end_define

begin_define
define|#
directive|define
name|b_command
value|b_resid
end_define

begin_comment
comment|/* bits in tmcs */
end_comment

begin_define
define|#
directive|define
name|TM_GO
value|0000001
end_define

begin_define
define|#
directive|define
name|TM_OFFL
value|0000000
end_define

begin_comment
comment|/* offline */
end_comment

begin_define
define|#
directive|define
name|TM_RCOM
value|0000002
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|TM_WCOM
value|0000004
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|TM_WEOF
value|0000006
end_define

begin_comment
comment|/* write-eof */
end_comment

begin_define
define|#
directive|define
name|TM_SFORW
value|0000010
end_define

begin_comment
comment|/* space forward */
end_comment

begin_define
define|#
directive|define
name|TM_SREV
value|0000012
end_define

begin_comment
comment|/* space backwards */
end_comment

begin_define
define|#
directive|define
name|TM_WIRG
value|0000014
end_define

begin_comment
comment|/* write with xtra interrecord gap */
end_comment

begin_define
define|#
directive|define
name|TM_REW
value|0000016
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|TM_SENSE
value|TM_IE
end_define

begin_comment
comment|/* sense (internal to driver) */
end_comment

begin_define
define|#
directive|define
name|tmreverseop
parameter_list|(
name|cmd
parameter_list|)
value|((cmd)==TM_SREV || (cmd)==TM_REW)
end_define

begin_comment
comment|/* TM_SNS is a pseudo-op used to get tape status */
end_comment

begin_define
define|#
directive|define
name|TM_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TM_CUR
value|0000200
end_define

begin_comment
comment|/* control unit is ready */
end_comment

begin_define
define|#
directive|define
name|TM_DCLR
value|0010000
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|TM_D800
value|0060000
end_define

begin_comment
comment|/* select 800 bpi density */
end_comment

begin_define
define|#
directive|define
name|TM_ERR
value|0100000
end_define

begin_comment
comment|/* drive error summary */
end_comment

begin_comment
comment|/* bits in tmer */
end_comment

begin_define
define|#
directive|define
name|TMER_ILC
value|0100000
end_define

begin_comment
comment|/* illegal command */
end_comment

begin_define
define|#
directive|define
name|TMER_EOF
value|0040000
end_define

begin_comment
comment|/* end of file */
end_comment

begin_define
define|#
directive|define
name|TMER_CRE
value|0020000
end_define

begin_comment
comment|/* cyclic redundancy error */
end_comment

begin_define
define|#
directive|define
name|TMER_PAE
value|0010000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|TMER_BGL
value|0004000
end_define

begin_comment
comment|/* bus grant late */
end_comment

begin_define
define|#
directive|define
name|TMER_EOT
value|0002000
end_define

begin_comment
comment|/* at end of tape */
end_comment

begin_define
define|#
directive|define
name|TMER_RLE
value|0001000
end_define

begin_comment
comment|/* record length error */
end_comment

begin_define
define|#
directive|define
name|TMER_BTE
value|0000400
end_define

begin_comment
comment|/* bad tape error */
end_comment

begin_define
define|#
directive|define
name|TMER_NXM
value|0000200
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|TMER_SELR
value|0000100
end_define

begin_comment
comment|/* tape unit properly selected */
end_comment

begin_define
define|#
directive|define
name|TMER_BOT
value|0000040
end_define

begin_comment
comment|/* at beginning of tape */
end_comment

begin_define
define|#
directive|define
name|TMER_CH7
value|0000020
end_define

begin_comment
comment|/* 7 channel tape */
end_comment

begin_define
define|#
directive|define
name|TMER_SDWN
value|0000010
end_define

begin_comment
comment|/* gap settling down */
end_comment

begin_define
define|#
directive|define
name|TMER_WRL
value|0000004
end_define

begin_comment
comment|/* tape unit write protected */
end_comment

begin_define
define|#
directive|define
name|TMER_RWS
value|0000002
end_define

begin_comment
comment|/* tape unit rewinding */
end_comment

begin_define
define|#
directive|define
name|TMER_TUR
value|0000001
end_define

begin_comment
comment|/* tape unit ready */
end_comment

begin_define
define|#
directive|define
name|TMER_BITS
define|\
value|"\10\20ILC\17EOF\16CRE\15PAE\14BGL\13EOT\12RLE\11BTE\10NXM\ \7SELR\6BOT\5CH7\4SDWN\3WRL\2RWS\1TUR"
end_define

begin_define
define|#
directive|define
name|TMER_HARD
value|(TMER_ILC|TMER_EOT)
end_define

begin_define
define|#
directive|define
name|TMER_SOFT
value|(TMER_CRE|TMER_PAE|TMER_BGL|TMER_RLE|TMER_BTE|TMER_NXM)
end_define

end_unit

