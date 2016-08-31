begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/sa_dref/sa_dref_isc3.h */
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
value|{ \ 		(dst)->raddr.buf = (char *) (src); \ 		(dst)->raddr.len = sizeof(struct sockaddr_in); \ 		(dst)->trans = 1; \ 	}
end_define

begin_comment
comment|/* #undef NFS_ARGS_T_ADDR_IS_POINTER */
end_comment

end_unit

