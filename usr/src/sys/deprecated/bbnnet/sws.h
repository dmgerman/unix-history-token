begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SWS_QFF_MAX
value|100
end_define

begin_define
define|#
directive|define
name|SWS_QFF_MIN
value|5
end_define

begin_comment
comment|/* a guess */
end_comment

begin_define
define|#
directive|define
name|SWS_QFF_DEC
value|20
end_define

begin_comment
comment|/* applied to connection on ICMP quench */
end_comment

begin_comment
comment|/*  * The following were determined by measurement.  */
end_comment

begin_define
define|#
directive|define
name|SWS_IMP
value|75
end_define

begin_define
define|#
directive|define
name|SWS_ETHER
value|65
end_define

begin_comment
comment|/*  * Should be for network most likely to be redirected toward.  */
end_comment

begin_define
define|#
directive|define
name|SWS_QFF_DEF
value|SWS_IMP
end_define

end_unit

