begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * send an IP datagram.  Used when don't have any Internet protocol  * control block associated with the action.  Dummies one up.  */
end_comment

begin_define
define|#
directive|define
name|NOPCB_IPSEND
parameter_list|(
name|mp
parameter_list|,
name|len
parameter_list|,
name|asis
parameter_list|,
name|retval
parameter_list|)
define|\
value|{ struct inpcb inp;                     \ 	bzero ((caddr_t)&inp, sizeof(inp));	\ 	retval = ip_send (&inp, mp, len, asis); \ 	}
end_define

end_unit

