begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|PE
name|mkpelist
argument_list|()
decl_stmt|,
name|mkpe
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Possible operations we can test */
end_comment

begin_define
define|#
directive|define
name|SIMP_SEND
value|1
end_define

begin_comment
comment|/* Simple transfer - send some data */
end_comment

begin_define
define|#
directive|define
name|CPLX_SEND
value|2
end_define

begin_comment
comment|/* Complex transfer - send incremental */
end_comment

begin_define
define|#
directive|define
name|SIMP_RCV
value|3
end_define

begin_comment
comment|/* Simple transfer - receive some data */
end_comment

begin_define
define|#
directive|define
name|CPLX_RCV
value|4
end_define

begin_comment
comment|/* Complex transfer - receive incremental */
end_comment

begin_define
define|#
directive|define
name|RCV_PLS
value|5
end_define

begin_comment
comment|/* Receive a Please indication */
end_comment

begin_define
define|#
directive|define
name|RCV_GIVE
value|6
end_define

begin_comment
comment|/* Receive a Give indication */
end_comment

begin_define
define|#
directive|define
name|SEND_PLS
value|7
end_define

begin_comment
comment|/* Send a Please request */
end_comment

begin_define
define|#
directive|define
name|SEND_GIVE
value|8
end_define

begin_comment
comment|/* Send a Give request */
end_comment

begin_define
define|#
directive|define
name|SEND_ABRT
value|9
end_define

begin_comment
comment|/* Send an Abort */
end_comment

begin_define
define|#
directive|define
name|RCV_ABRT
value|10
end_define

begin_comment
comment|/* Receive an Abort */
end_comment

begin_define
define|#
directive|define
name|RCV_CLOSE
value|11
end_define

begin_comment
comment|/* Receive a CLOSE indication and respond */
end_comment

begin_define
define|#
directive|define
name|SEND_CLOSE
value|12
end_define

begin_comment
comment|/* Send a Close request */
end_comment

begin_define
define|#
directive|define
name|RCV_FINISH
value|13
end_define

begin_comment
comment|/* Receive a X410 Finish */
end_comment

begin_define
define|#
directive|define
name|SEND_FINISH
value|14
end_define

begin_comment
comment|/* Send a X410 Finish */
end_comment

end_unit

