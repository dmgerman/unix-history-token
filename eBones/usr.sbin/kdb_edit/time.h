begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Structure for use by time manipulating subroutines.  * The following library routines use it:  *	libc: ctime, localtime, gmtime, asctime  *	libcx: partime, maketime (may not be installed yet)  */
end_comment

begin_comment
comment|/*  *	from: time.h,v 1.1 82/05/06 11:34:29 wft Exp $  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|tm
block|{
comment|/* See defines below for allowable ranges */
name|int
name|tm_sec
decl_stmt|;
name|int
name|tm_min
decl_stmt|;
name|int
name|tm_hour
decl_stmt|;
name|int
name|tm_mday
decl_stmt|;
name|int
name|tm_mon
decl_stmt|;
name|int
name|tm_year
decl_stmt|;
name|int
name|tm_wday
decl_stmt|;
name|int
name|tm_yday
decl_stmt|;
name|int
name|tm_isdst
decl_stmt|;
name|int
name|tm_zon
decl_stmt|;
comment|/* NEW: mins westward of Greenwich */
name|int
name|tm_ampm
decl_stmt|;
comment|/* NEW: 1 if AM, 2 if PM */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LCLZONE
value|(5*60)
end_define

begin_comment
comment|/* Until V7 ftime(2) works, this defines local zone*/
end_comment

begin_define
define|#
directive|define
name|TMNULL
value|(-1)
end_define

begin_comment
comment|/* Items not specified are given this value 			 * in order to distinguish null specs from zero 			 * specs.  This is only used by partime and 			 * maketime. */
end_comment

begin_comment
comment|/* Indices into TM structure */
end_comment

begin_define
define|#
directive|define
name|TM_SEC
value|0
end_define

begin_comment
comment|/* 0-59			*/
end_comment

begin_define
define|#
directive|define
name|TM_MIN
value|1
end_define

begin_comment
comment|/* 0-59			*/
end_comment

begin_define
define|#
directive|define
name|TM_HOUR
value|2
end_define

begin_comment
comment|/* 0-23			*/
end_comment

begin_define
define|#
directive|define
name|TM_MDAY
value|3
end_define

begin_comment
comment|/* 1-31			day of month */
end_comment

begin_define
define|#
directive|define
name|TM_DAY
value|TM_MDAY
end_define

begin_comment
comment|/*  "			synonym      */
end_comment

begin_define
define|#
directive|define
name|TM_MON
value|4
end_define

begin_comment
comment|/* 0-11			*/
end_comment

begin_define
define|#
directive|define
name|TM_YEAR
value|5
end_define

begin_comment
comment|/* (year-1900) (year)	*/
end_comment

begin_define
define|#
directive|define
name|TM_WDAY
value|6
end_define

begin_comment
comment|/* 0-6			day of week (0 = Sunday) */
end_comment

begin_define
define|#
directive|define
name|TM_YDAY
value|7
end_define

begin_comment
comment|/* 0-365		day of year */
end_comment

begin_define
define|#
directive|define
name|TM_ISDST
value|8
end_define

begin_comment
comment|/* 0 Std, 1 DST		*/
end_comment

begin_comment
comment|/* New stuff */
end_comment

begin_define
define|#
directive|define
name|TM_ZON
value|9
end_define

begin_comment
comment|/* 0-(24*60) minutes west of Greenwich */
end_comment

begin_define
define|#
directive|define
name|TM_AMPM
value|10
end_define

begin_comment
comment|/* 1 AM, 2 PM		*/
end_comment

end_unit

