begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The number of seconds to wait at the end of the test inferior before
end_comment

begin_comment
comment|// exiting.  This delay is needed to ensure the logging infrastructure
end_comment

begin_comment
comment|// has flushed out the message.  If we finished before all messages were
end_comment

begin_comment
comment|// flushed, then the test will never see the unflushed messages, causing
end_comment

begin_comment
comment|// some test logic to fail.
end_comment

begin_define
define|#
directive|define
name|FINAL_WAIT_SECONDS
value|5
end_define

end_unit

