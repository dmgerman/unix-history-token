begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|DEBUG
value|1
end_define

begin_comment
comment|/* enable debugging code (needed for dig) */
end_comment

begin_define
define|#
directive|define
name|RESOLVSORT
end_define

begin_comment
comment|/* allow sorting of addresses in gethostbyname */
end_comment

begin_define
define|#
directive|define
name|RFC1535
end_define

begin_comment
comment|/* comply with RFC1535 (STRONGLY reccomended by vixie)*/
end_comment

begin_undef
undef|#
directive|undef
name|USELOOPBACK
end_undef

begin_comment
comment|/* res_init() bind to localhost */
end_comment

begin_undef
undef|#
directive|undef
name|SUNSECURITY
end_undef

begin_comment
comment|/* verify gethostbyaddr() calls - WE DONT NEED IT  */
end_comment

begin_define
define|#
directive|define
name|MULTI_PTRS_ARE_ALIASES
value|1
end_define

begin_comment
comment|/* fold multiple PTR records into aliases */
end_comment

begin_define
define|#
directive|define
name|CHECK_SRVR_ADDR
value|1
end_define

begin_comment
comment|/* confirm that the server requested sent the reply */
end_comment

begin_define
define|#
directive|define
name|BIND_UPDATE
value|1
end_define

begin_comment
comment|/* update support */
end_comment

end_unit

