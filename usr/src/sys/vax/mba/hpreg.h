begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hpreg.h	4.2	81/02/19	*/
end_comment

begin_struct
struct|struct
name|device
block|{
name|int
name|hpcs1
decl_stmt|;
comment|/* control and Status register 1 */
name|int
name|hpds
decl_stmt|;
comment|/* Drive Status */
name|int
name|hper1
decl_stmt|;
comment|/* Error register 1 */
name|int
name|hpmr
decl_stmt|;
comment|/* Maintenance */
name|int
name|hpas
decl_stmt|;
comment|/* Attention Summary */
name|int
name|hpda
decl_stmt|;
comment|/* Desired address register */
name|int
name|hpdt
decl_stmt|;
comment|/* Drive type */
name|int
name|hpla
decl_stmt|;
comment|/* Look ahead */
name|int
name|hpsn
decl_stmt|;
comment|/* serial number */
name|int
name|hpof
decl_stmt|;
comment|/* Offset register */
name|int
name|hpdc
decl_stmt|;
comment|/* Desired Cylinder address register */
name|int
name|hpcc
decl_stmt|;
comment|/* Current Cylinder */
name|int
name|hper2
decl_stmt|;
comment|/* Error register 2 */
name|int
name|hper3
decl_stmt|;
comment|/* Error register 3 */
name|int
name|hpec1
decl_stmt|;
comment|/* Burst error bit position */
name|int
name|hpec2
decl_stmt|;
comment|/* Burst error bit pattern */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GO
value|01
end_define

begin_define
define|#
directive|define
name|PRESET
value|020
end_define

begin_define
define|#
directive|define
name|RTC
value|016
end_define

begin_define
define|#
directive|define
name|OFFSET
value|014
end_define

begin_define
define|#
directive|define
name|SEEK
value|04
end_define

begin_define
define|#
directive|define
name|SEARCH
value|030
end_define

begin_define
define|#
directive|define
name|RECAL
value|06
end_define

begin_define
define|#
directive|define
name|DCLR
value|010
end_define

begin_define
define|#
directive|define
name|WCOM
value|060
end_define

begin_define
define|#
directive|define
name|RCOM
value|070
end_define

begin_define
define|#
directive|define
name|RELEASE
value|012
end_define

begin_define
define|#
directive|define
name|DVA
value|04000
end_define

begin_define
define|#
directive|define
name|IE
value|0100
end_define

begin_define
define|#
directive|define
name|PIP
value|020000
end_define

begin_define
define|#
directive|define
name|DRY
value|0200
end_define

begin_define
define|#
directive|define
name|ERR
value|040000
end_define

begin_define
define|#
directive|define
name|TRE
value|040000
end_define

begin_define
define|#
directive|define
name|DCK
value|0100000
end_define

begin_define
define|#
directive|define
name|WLE
value|04000
end_define

begin_define
define|#
directive|define
name|ECH
value|0100
end_define

begin_define
define|#
directive|define
name|VV
value|0100
end_define

begin_define
define|#
directive|define
name|DPR
value|0400
end_define

begin_define
define|#
directive|define
name|MOL
value|010000
end_define

begin_define
define|#
directive|define
name|FMT22
value|010000
end_define

begin_define
define|#
directive|define
name|P400
value|020
end_define

begin_define
define|#
directive|define
name|M400
value|0220
end_define

begin_define
define|#
directive|define
name|P800
value|040
end_define

begin_define
define|#
directive|define
name|M800
value|0240
end_define

begin_define
define|#
directive|define
name|P1200
value|060
end_define

begin_define
define|#
directive|define
name|M1200
value|0260
end_define

end_unit

