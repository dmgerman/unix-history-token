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

begin_function_decl
specifier|extern
name|void
name|setarp
parameter_list|(
name|int
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|haddrtoa
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|haddr_conv802
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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

