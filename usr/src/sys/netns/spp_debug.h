begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)spp_debug.h	6.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|spp_debug
block|{
name|u_long
name|sd_time
decl_stmt|;
name|short
name|sd_act
decl_stmt|;
name|short
name|sd_ostate
decl_stmt|;
name|caddr_t
name|sd_cb
decl_stmt|;
name|short
name|sd_req
decl_stmt|;
name|struct
name|spidp
name|sd_si
decl_stmt|;
name|struct
name|sppcb
name|sd_sp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SA_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|SA_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|SA_USER
value|2
end_define

begin_define
define|#
directive|define
name|SA_RESPOND
value|3
end_define

begin_define
define|#
directive|define
name|SA_DROP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SANAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|sanames
index|[]
init|=
block|{
literal|"input"
block|,
literal|"output"
block|,
literal|"user"
block|,
literal|"respond"
block|,
literal|"drop"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPP_NDEBUG
value|100
end_define

begin_decl_stmt
name|struct
name|spp_debug
name|spp_debug
index|[
name|SPP_NDEBUG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spp_debx
decl_stmt|;
end_decl_stmt

end_unit

