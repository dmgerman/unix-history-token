begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SNOOP_H__
end_ifndef

begin_define
define|#
directive|define
name|__SNOOP_H__
end_define

begin_comment
comment|/*  * written to comply with the RFC (1761) from Sun.  * $Id: snoop.h,v 2.2.2.1 2001/06/26 10:43:20 darrenr Exp $  */
end_comment

begin_struct
struct|struct
name|snoophdr
block|{
name|char
name|s_id
index|[
literal|8
index|]
decl_stmt|;
name|int
name|s_v
decl_stmt|;
name|int
name|s_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SNOOP_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|SDL_8023
value|0
end_define

begin_define
define|#
directive|define
name|SDL_8024
value|1
end_define

begin_define
define|#
directive|define
name|SDL_8025
value|2
end_define

begin_define
define|#
directive|define
name|SDL_8026
value|3
end_define

begin_define
define|#
directive|define
name|SDL_ETHER
value|4
end_define

begin_define
define|#
directive|define
name|SDL_HDLC
value|5
end_define

begin_define
define|#
directive|define
name|SDL_CHSYNC
value|6
end_define

begin_define
define|#
directive|define
name|SDL_IBMCC
value|7
end_define

begin_define
define|#
directive|define
name|SDL_FDDI
value|8
end_define

begin_define
define|#
directive|define
name|SDL_OTHER
value|9
end_define

begin_define
define|#
directive|define
name|SDL_MAX
value|9
end_define

begin_struct
struct|struct
name|snooppkt
block|{
name|int
name|sp_olen
decl_stmt|;
name|int
name|sp_ilen
decl_stmt|;
name|int
name|sp_plen
decl_stmt|;
name|int
name|sp_drop
decl_stmt|;
name|int
name|sp_sec
decl_stmt|;
name|int
name|sp_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SNOOP_H__ */
end_comment

end_unit

