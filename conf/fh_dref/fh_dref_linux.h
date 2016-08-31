begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/fh_dref/fh_dref_linux.h */
end_comment

begin_define
define|#
directive|define
name|NFS_FH_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|memcpy((char *)&(dst.data), (char *) src, sizeof(struct nfs_fh))
end_define

end_unit

