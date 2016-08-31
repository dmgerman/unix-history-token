begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/hn_dref/hn_dref_isc3.h */
end_comment

begin_define
define|#
directive|define
name|NFS_HN_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|xstrlcpy((dst), (src), MAXHOSTNAMELEN)
end_define

end_unit

