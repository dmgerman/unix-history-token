begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   VAX clock registers  */
end_comment

begin_define
define|#
directive|define
name|ICCS_RUN
value|0x1
end_define

begin_define
define|#
directive|define
name|ICCS_TRANS
value|0x10
end_define

begin_define
define|#
directive|define
name|ICCS_SS
value|0x20
end_define

begin_define
define|#
directive|define
name|ICCS_IE
value|0x40
end_define

begin_define
define|#
directive|define
name|ICCS_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|ICCS_ERR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|YRCURR
value|1979
end_define

begin_comment
comment|/*  current year */
end_comment

begin_define
define|#
directive|define
name|YRREF
value|1970
end_define

begin_comment
comment|/*  reference year for time */
end_comment

begin_define
define|#
directive|define
name|SECHR
value|(60*60)
end_define

begin_comment
comment|/* seconds/hr */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|(24*SECHR)
end_define

begin_comment
comment|/* seconds/day */
end_comment

begin_define
define|#
directive|define
name|SECYR
value|(365*SECDAY)
end_define

begin_comment
comment|/* seconds/common year */
end_comment

end_unit

