begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * igmpv2.h,v 3.8.4.1 1997/11/18 23:25:58 fenner Exp  */
end_comment

begin_comment
comment|/*  * Constants for IGMP Version 2.  Several of these, especially the  * robustness variable, should be variables and not constants.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_ROBUSTNESS_VARIABLE
value|2
end_define

begin_define
define|#
directive|define
name|IGMP_QUERY_INTERVAL
value|125
end_define

begin_define
define|#
directive|define
name|IGMP_QUERY_RESPONSE_INTERVAL
value|10
end_define

begin_define
define|#
directive|define
name|IGMP_GROUP_MEMBERSHIP_INTERVAL
value|(IGMP_ROBUSTNESS_VARIABLE * \ 					IGMP_QUERY_INTERVAL + \ 					IGMP_QUERY_RESPONSE_INTERVAL)
end_define

begin_define
define|#
directive|define
name|IGMP_OTHER_QUERIER_PRESENT_INTERVAL
value|(IGMP_ROBUSTNESS_VARIABLE * \ 					IGMP_QUERY_INTERVAL + \ 					IGMP_QUERY_RESPONSE_INTERVAL / 2)
end_define

begin_comment
comment|/* Round to the nearest TIMER_INTERVAL */
end_comment

begin_define
define|#
directive|define
name|IGMP_STARTUP_QUERY_INTERVAL
value|(((IGMP_QUERY_INTERVAL / 4) \ 							/ TIMER_INTERVAL) * TIMER_INTERVAL)
end_define

begin_define
define|#
directive|define
name|IGMP_STARTUP_QUERY_COUNT
value|IGMP_ROBUSTNESS_VARIABLE
end_define

begin_define
define|#
directive|define
name|IGMP_LAST_MEMBER_QUERY_INTERVAL
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_LAST_MEMBER_QUERY_COUNT
value|IGMP_ROBUSTNESS_VARIABLE
end_define

begin_comment
comment|/*  * OLD_AGE_THRESHOLD is the number of IGMP_QUERY_INTERVAL's to remember the  * presence of an IGMPv1 group member.  According to the IGMPv2 specification,  * routers remember this presence for [Robustness Variable] * [Query Interval] +  * [Query Response Interval].  However, OLD_AGE_THRESHOLD is in units of  * [Query Interval], so doesn't have sufficient resolution to represent  * [Query Response Interval].  When the timer mechanism gets an efficient  * method of refreshing timers, this should get fixed.  */
end_comment

begin_define
define|#
directive|define
name|OLD_AGE_THRESHOLD
value|IGMP_ROBUSTNESS_VARIABLE
end_define

end_unit

