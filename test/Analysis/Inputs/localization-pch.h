begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Used to test missing checker for missing localization context comments
end_comment

begin_comment
comment|// in precompiled headers.
end_comment

begin_define
define|#
directive|define
name|MyLocalizedStringInPCH
parameter_list|(
name|key
parameter_list|)
value|NSLocalizedString((key), @"")
end_define

end_unit

