begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  */
end_comment

begin_comment
comment|/*  * Dumb definitions which needed when   * firewall/accounting module is not loaded.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_fw.h>
end_include

begin_decl_stmt
name|struct
name|ip_fw
modifier|*
name|ip_fw_chain
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|ip_fw_policy
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ip_fw
modifier|*
name|ip_acct_chain
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPFIREWALL
end_ifdef

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_fw_chk_ptr
function_decl|)
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ip_fw
modifier|*
parameter_list|)
init|=
operator|&
name|ip_fw_chk
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_fw_ctl_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
init|=
operator|&
name|ip_fw_ctl
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_fw_chk_ptr
function_decl|)
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ip_fw
modifier|*
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_fw_ctl_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPACCT
end_ifdef

begin_function_decl
name|void
function_decl|(
modifier|*
name|ip_acct_cnt_ptr
function_decl|)
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ip_fw
modifier|*
parameter_list|,
name|int
parameter_list|)
init|=
operator|&
name|ip_acct_cnt
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_acct_ctl_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
init|=
operator|&
name|ip_acct_ctl
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
function_decl|(
modifier|*
name|ip_acct_cnt_ptr
function_decl|)
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ip_fw
modifier|*
parameter_list|,
name|int
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|ip_acct_ctl_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

