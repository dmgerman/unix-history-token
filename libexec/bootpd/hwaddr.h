begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * hwaddr.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HWADDR_H
end_ifndef

begin_define
define|#
directive|define
name|HWADDR_H
end_define

begin_define
define|#
directive|define
name|MAXHADDRLEN
value|8
end_define

begin_comment
comment|/* Max hw address length in bytes */
end_comment

begin_comment
comment|/*  * This structure holds information about a specific network type.  The  * length of the network hardware address is stored in "hlen".  * The string pointed to by "name" is the cononical name of the network.  */
end_comment

begin_struct
struct|struct
name|hwinfo
block|{
name|unsigned
name|int
name|hlen
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hwinfo
name|hwinfolist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hwinfocnt
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|setarp
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|haddrtoa
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|haddr_conv802
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P
end_undef

begin_comment
comment|/*  * Return the length in bytes of a hardware address of the given type.  * Return the canonical name of the network of the given type.  */
end_comment

begin_define
define|#
directive|define
name|haddrlength
parameter_list|(
name|type
parameter_list|)
value|((hwinfolist[(int) (type)]).hlen)
end_define

begin_define
define|#
directive|define
name|netname
parameter_list|(
name|type
parameter_list|)
value|((hwinfolist[(int) (type)]).name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HWADDR_H */
end_comment

end_unit

