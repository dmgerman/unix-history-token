begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  */
end_comment

begin_comment
comment|/*  * LKM init functions and stuff.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
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

begin_macro
name|MOD_MISC
argument_list|(
literal|"ipfw_mod"
argument_list|)
end_macro

begin_macro
name|ipfw_load
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
name|int
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|IPFIREWALL
if|if
condition|(
name|ip_fw_chk_ptr
operator|!=
name|NULL
operator|||
name|ip_fw_ctl_ptr
operator|!=
name|NULL
condition|)
block|{
name|uprintf
argument_list|(
literal|"IpFw/IpAcct already loaded.\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPACCT
if|if
condition|(
name|ip_acct_cnt_ptr
operator|!=
name|NULL
operator|||
name|ip_acct_ctl_ptr
operator|!=
name|NULL
condition|)
block|{
name|uprintf
argument_list|(
literal|"IpFw/IpAcct already loaded.\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPFIREWALL
name|ip_fw_chk_ptr
operator|=
operator|&
name|ip_fw_chk
expr_stmt|;
name|ip_fw_ctl_ptr
operator|=
operator|&
name|ip_fw_ctl
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPACCT
name|ip_acct_cnt_ptr
operator|=
operator|&
name|ip_acct_cnt
expr_stmt|;
name|ip_acct_ctl_ptr
operator|=
operator|&
name|ip_acct_ctl
expr_stmt|;
endif|#
directive|endif
name|uprintf
argument_list|(
literal|"IpFw/IpAcct 1994(c) Ugen J.S.Antsilevich\n"
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|ipfw_unload
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
name|int
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|IPFIREWALL
name|ip_fw_ctl_ptr
operator|=
name|NULL
expr_stmt|;
name|ip_fw_chk_ptr
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPACCT
name|ip_acct_ctl_ptr
operator|=
name|NULL
expr_stmt|;
name|ip_acct_cnt_ptr
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
name|uprintf
argument_list|(
literal|"IpFw/IpAcct removed.\n"
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|ipfw_init
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|,
argument|int ver
argument_list|)
end_macro

begin_block
block|{
name|DISPATCH
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|ipfw_load
argument_list|,
name|ipfw_unload
argument_list|,
name|nosys
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

