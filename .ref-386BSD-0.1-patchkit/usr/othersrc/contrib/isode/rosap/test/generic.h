begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|APDU_OP1
value|1
end_define

begin_comment
comment|/* Simple generic request - no arguements */
end_comment

begin_define
define|#
directive|define
name|APDU_ERR
value|2
end_define

begin_comment
comment|/* Generate an error return */
end_comment

begin_define
define|#
directive|define
name|APDU_URJ
value|3
end_define

begin_comment
comment|/* Generate a User Reject */
end_comment

begin_define
define|#
directive|define
name|APDU_PRJ
value|3
end_define

begin_comment
comment|/* Generate a Provider Reject - not supported */
end_comment

begin_define
define|#
directive|define
name|APDU_UNKNOWN
value|5
end_define

begin_define
define|#
directive|define
name|ERROR_UNKNOWN
value|6
end_define

begin_define
define|#
directive|define
name|ERROR_MISTYPED
value|7
end_define

begin_define
define|#
directive|define
name|ERROR_ERROR
value|8
end_define

begin_comment
comment|/*  * Types of underlying service we use  */
end_comment

begin_define
define|#
directive|define
name|RoRt
value|0
end_define

begin_comment
comment|/* Reliable Transfer */
end_comment

begin_define
define|#
directive|define
name|RoP
value|1
end_define

begin_comment
comment|/* Presentation */
end_comment

begin_define
define|#
directive|define
name|RoS
value|2
end_define

begin_comment
comment|/* Session */
end_comment

end_unit

