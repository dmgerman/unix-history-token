begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_LOOKUP_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_LOOKUP_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCLOOKUPADDTABLE
value|_IOWR('r', 60, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELTABLE
value|_IOWR('r', 61, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPSTAT
value|_IOWR('r', 64, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPSTATW
value|_IOW('r', 64, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPFLUSH
value|_IOWR('r', 65, struct iplookupflush)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPADDNODE
value|_IOWR('r', 67, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPADDNODEW
value|_IOW('r', 67, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELNODE
value|_IOWR('r', 68, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELNODEW
value|_IOW('r', 68, struct iplookupop)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCLOOKUPADDTABLE
value|_IOWR(r, 60, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELTABLE
value|_IOWR(r, 61, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPSTAT
value|_IOWR(r, 64, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPSTATW
value|_IOW(r, 64, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPFLUSH
value|_IOWR(r, 65, struct iplookupflush)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPADDNODE
value|_IOWR(r, 67, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPADDNODEW
value|_IOW(r, 67, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELNODE
value|_IOWR(r, 68, struct iplookupop)
end_define

begin_define
define|#
directive|define
name|SIOCLOOKUPDELNODEW
value|_IOW(r, 68, struct iplookupop)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|iplookupop
block|{
name|int
name|iplo_type
decl_stmt|;
comment|/* IPLT_* */
name|int
name|iplo_unit
decl_stmt|;
comment|/* IPL_LOG* */
name|u_int
name|iplo_arg
decl_stmt|;
name|char
name|iplo_name
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
name|size_t
name|iplo_size
decl_stmt|;
comment|/* sizeof struct at iplo_struct */
name|void
modifier|*
name|iplo_struct
decl_stmt|;
block|}
name|iplookupop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|iplookupflush
block|{
name|int
name|iplf_type
decl_stmt|;
comment|/* IPLT_* */
name|int
name|iplf_unit
decl_stmt|;
comment|/* IPL_LOG* */
name|u_int
name|iplf_arg
decl_stmt|;
name|size_t
name|iplf_count
decl_stmt|;
name|char
name|iplf_name
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
block|}
name|iplookupflush_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|iplookuplink
block|{
name|int
name|ipll_type
decl_stmt|;
comment|/* IPLT_* */
name|int
name|ipll_unit
decl_stmt|;
comment|/* IPL_LOG* */
name|u_int
name|ipll_num
decl_stmt|;
name|char
name|ipll_group
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
block|}
name|iplookuplink_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPLT_ALL
value|-1
end_define

begin_define
define|#
directive|define
name|IPLT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IPLT_POOL
value|1
end_define

begin_define
define|#
directive|define
name|IPLT_HASH
value|2
end_define

begin_define
define|#
directive|define
name|IPLT_ANON
value|0x80000000
end_define

begin_decl_stmt
specifier|extern
name|int
name|ip_lookup_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip_lookup_ioctl
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|ioctlcmd_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ip_lookup_unload
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ip_lookup_deref
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_LOOKUP_H__ */
end_comment

end_unit

