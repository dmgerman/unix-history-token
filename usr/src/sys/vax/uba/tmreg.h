begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tmreg.h	4.2	81/02/19	*/
end_comment

begin_struct
struct|struct
name|device
block|{
name|u_short
name|tmer
decl_stmt|;
name|u_short
name|tmcs
decl_stmt|;
name|short
name|tmbc
decl_stmt|;
name|u_short
name|tmba
decl_stmt|;
name|short
name|tmdb
decl_stmt|;
name|short
name|tmrd
decl_stmt|;
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
name|GO
value|01
end_define

begin_define
define|#
directive|define
name|OFFL
value|0
end_define

begin_define
define|#
directive|define
name|RCOM
value|02
end_define

begin_define
define|#
directive|define
name|WCOM
value|04
end_define

begin_define
define|#
directive|define
name|WEOF
value|06
end_define

begin_define
define|#
directive|define
name|SFORW
value|010
end_define

begin_define
define|#
directive|define
name|SREV
value|012
end_define

begin_define
define|#
directive|define
name|WIRG
value|014
end_define

begin_define
define|#
directive|define
name|REW
value|016
end_define

begin_define
define|#
directive|define
name|IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|CUR
value|0200
end_define

begin_define
define|#
directive|define
name|NOP
value|IENABLE
end_define

begin_define
define|#
directive|define
name|DCLR
value|010000
end_define

begin_define
define|#
directive|define
name|D800
value|060000
end_define

begin_define
define|#
directive|define
name|ERROR
value|0100000
end_define

begin_comment
comment|/* bits in tmer */
end_comment

begin_define
define|#
directive|define
name|TUR
value|1
end_define

begin_define
define|#
directive|define
name|RWS
value|02
end_define

begin_define
define|#
directive|define
name|WRL
value|04
end_define

begin_define
define|#
directive|define
name|SDWN
value|010
end_define

begin_define
define|#
directive|define
name|BOT
value|040
end_define

begin_define
define|#
directive|define
name|SELR
value|0100
end_define

begin_define
define|#
directive|define
name|NXM
value|0200
end_define

begin_define
define|#
directive|define
name|TMBTE
value|0400
end_define

begin_define
define|#
directive|define
name|RLE
value|01000
end_define

begin_define
define|#
directive|define
name|EOT
value|02000
end_define

begin_define
define|#
directive|define
name|BGL
value|04000
end_define

begin_define
define|#
directive|define
name|PAE
value|010000
end_define

begin_define
define|#
directive|define
name|CRE
value|020000
end_define

begin_define
define|#
directive|define
name|EOF
value|040000
end_define

begin_define
define|#
directive|define
name|ILC
value|0100000
end_define

begin_define
define|#
directive|define
name|HARD
value|(ILC|EOT)
end_define

begin_define
define|#
directive|define
name|SOFT
value|(CRE|PAE|BGL|RLE|TMBTE|NXM)
end_define

end_unit

