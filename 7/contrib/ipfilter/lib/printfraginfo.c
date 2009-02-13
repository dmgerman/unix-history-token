begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2004-2005 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: printfraginfo.c,v 1.1.2.5 2006/12/25 15:10:37 darrenr Exp $  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"kmem.h"
end_include

begin_function
name|void
name|printfraginfo
parameter_list|(
name|prefix
parameter_list|,
name|ifr
parameter_list|)
name|char
modifier|*
name|prefix
decl_stmt|;
name|struct
name|ipfr
modifier|*
name|ifr
decl_stmt|;
block|{
name|frentry_t
name|fr
decl_stmt|;
name|fr
operator|.
name|fr_flags
operator|=
literal|0xffffffff
expr_stmt|;
name|printf
argument_list|(
literal|"%s%s -> "
argument_list|,
name|prefix
argument_list|,
name|hostname
argument_list|(
literal|4
argument_list|,
operator|&
name|ifr
operator|->
name|ipfr_src
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	if (kmemcpy((char *)&fr, (u_long)ifr->ipfr_rule, 		    sizeof(fr)) == -1) 		return; */
name|printf
argument_list|(
literal|"%s id %d ttl %ld pr %d seen0 %d ref %d tos %#02x\n"
argument_list|,
name|hostname
argument_list|(
literal|4
argument_list|,
operator|&
name|ifr
operator|->
name|ipfr_dst
argument_list|)
argument_list|,
name|ifr
operator|->
name|ipfr_id
argument_list|,
name|ifr
operator|->
name|ipfr_ttl
argument_list|,
name|ifr
operator|->
name|ipfr_p
argument_list|,
name|ifr
operator|->
name|ipfr_seen0
argument_list|,
name|ifr
operator|->
name|ipfr_ref
argument_list|,
name|ifr
operator|->
name|ipfr_tos
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

