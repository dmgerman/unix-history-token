begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /tcpdump/master/tcpdump/nfsfh.h,v 1.9 2000/06/01 01:16:36 assar Exp $  *  * nfsfh.h - NFS file handle definitions (for portable use)  *  * Jeffrey C. Mogul  * Digital Equipment Corporation  * Western Research Laboratory  *	$FreeBSD$  *	$NetBSD: nfsfh.h,v 1.1.1.2 1997/10/03 17:25:13 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Internal representation of dev_t, because different NFS servers  * that we might be spying upon use different external representations.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|Minor
decl_stmt|;
comment|/* upper case to avoid clashing with macro names */
name|u_int32_t
name|Major
decl_stmt|;
block|}
name|my_devt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dev_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a.Minor == b.Minor)&& (a.Major == b.Major))
end_define

begin_comment
comment|/*  * Many file servers now use a large file system ID.  This is  * our internal representation of that.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|my_devt
name|Fsid_dev
decl_stmt|;
comment|/* XXX avoid name conflict with AIX */
name|char
name|Opaque_Handle
index|[
literal|2
operator|*
literal|32
operator|+
literal|1
index|]
decl_stmt|;
name|u_int32_t
name|fsid_code
decl_stmt|;
block|}
name|my_fsid
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fsid_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a.fsid_code == b.fsid_code)&&\ 			 dev_eq(a.Fsid_dev, b.Fsid_dev))
end_define

begin_function_decl
specifier|extern
name|void
name|Parse_fh
parameter_list|(
name|caddr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|my_fsid
modifier|*
parameter_list|,
name|ino_t
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

