begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mtio.h	4.7	81/11/03	*/
end_comment

begin_comment
comment|/*  * Structures and definitions for mag tape io control commands  */
end_comment

begin_comment
comment|/* mag tape io control commands */
end_comment

begin_define
define|#
directive|define
name|MTIOCTOP
value|(('m'<<8)|1)
end_define

begin_comment
comment|/* do a mag tape op */
end_comment

begin_define
define|#
directive|define
name|MTIOCGET
value|(('m'<<8)|2)
end_define

begin_comment
comment|/* get mag tape status */
end_comment

begin_comment
comment|/* structure for MTIOCTOP - mag tape op command */
end_comment

begin_struct
struct|struct
name|mtop
block|{
name|short
name|mt_op
decl_stmt|;
comment|/* operations defined below */
name|daddr_t
name|mt_count
decl_stmt|;
comment|/* how many of them */
block|}
struct|;
end_struct

begin_comment
comment|/* operations */
end_comment

begin_define
define|#
directive|define
name|MTWEOF
value|0
end_define

begin_comment
comment|/* write an end-of-file record */
end_comment

begin_define
define|#
directive|define
name|MTFSF
value|1
end_define

begin_comment
comment|/* forward space file */
end_comment

begin_define
define|#
directive|define
name|MTBSF
value|2
end_define

begin_comment
comment|/* backward space file */
end_comment

begin_define
define|#
directive|define
name|MTFSR
value|3
end_define

begin_comment
comment|/* forward space record */
end_comment

begin_define
define|#
directive|define
name|MTBSR
value|4
end_define

begin_comment
comment|/* backward space record */
end_comment

begin_define
define|#
directive|define
name|MTREW
value|5
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|MTOFFL
value|6
end_define

begin_comment
comment|/* rewind and put the drive offline */
end_comment

begin_define
define|#
directive|define
name|MTNOP
value|7
end_define

begin_comment
comment|/* no operation, sets status only */
end_comment

begin_comment
comment|/* structure for MTIOCGET - mag tape get status command */
end_comment

begin_struct
struct|struct
name|mtget
block|{
name|short
name|mt_type
decl_stmt|;
comment|/* type of magtape device */
comment|/* the following two registers are grossly device dependent */
name|short
name|mt_dsreg
decl_stmt|;
comment|/* ``drive status'' register */
name|short
name|mt_erreg
decl_stmt|;
comment|/* ``error'' register */
comment|/* end device-dependent registers */
name|short
name|mt_resid
decl_stmt|;
comment|/* residual count */
comment|/* the following two are not yet implemented */
name|daddr_t
name|mt_fileno
decl_stmt|;
comment|/* file number of current position */
name|daddr_t
name|mt_blkno
decl_stmt|;
comment|/* block number of current position */
comment|/* end not yet implemented */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Constants for mt_type byte  */
end_comment

begin_define
define|#
directive|define
name|MT_ISTS
value|01
end_define

begin_define
define|#
directive|define
name|MT_ISHT
value|02
end_define

begin_define
define|#
directive|define
name|MT_ISTM
value|03
end_define

begin_define
define|#
directive|define
name|MT_ISMT
value|04
end_define

begin_define
define|#
directive|define
name|MT_ISUT
value|05
end_define

end_unit

