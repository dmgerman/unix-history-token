begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine specific defines for the SCO Unix V.3.2 ODT */
end_comment

begin_define
define|#
directive|define
name|scounix
end_define

begin_comment
comment|/* Return true if s (a non null string pointer), points to a local variable name. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|n
parameter_list|)
value|((n)[0] == '.'&& (n)[1] == 'L')
end_define

begin_comment
comment|/* end of te-sco386.h */
end_comment

end_unit

