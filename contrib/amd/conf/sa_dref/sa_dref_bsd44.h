begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/sa_dref/sa_dref_bsd44.h */
end_comment

begin_define
define|#
directive|define
name|NFS_SA_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|{ \ 		(dst)->addr = (struct sockaddr *) (src); \ 		(dst)->addrlen = sizeof(*src); \ 	}
end_define

end_unit

