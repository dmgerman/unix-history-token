begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/kstash/RCS/kstash.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Description.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_kstash_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/kstash/RCS/kstash.c,v 4.1 90/06/25 21:33:13 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<klog.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_include
include|#
directive|include
file|<krb_db.h>
end_include

begin_include
include|#
directive|include
file|<kdc.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* change this later, but krblib_dbm needs it for now */
end_comment

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|C_Block
name|master_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Key_schedule
name|master_key_schedule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Principal
name|s_name_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for services requested */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|master_key_version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|more
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|kfile
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|clear_secrets
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|long
name|n
decl_stmt|;
if|if
condition|(
name|n
operator|=
name|kerb_init
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Kerberos db and cache init failed = %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|kdb_get_master_key
argument_list|(
name|TRUE
argument_list|,
name|master_key
argument_list|,
name|master_key_schedule
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Couldn't read master key.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|clear_secrets
argument_list|()
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|kdb_verify_master_key
argument_list|(
name|master_key
argument_list|,
name|master_key_schedule
argument_list|,
name|stderr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|clear_secrets
argument_list|()
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|kfile
operator|=
name|open
argument_list|(
name|MKEYFILE
argument_list|,
name|O_TRUNC
operator||
name|O_RDWR
operator||
name|O_CREAT
argument_list|,
literal|0600
argument_list|)
expr_stmt|;
if|if
condition|(
name|kfile
operator|<
literal|0
condition|)
block|{
name|clear_secrets
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n\07\07%s: Unable to open master key file\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|write
argument_list|(
name|kfile
argument_list|,
operator|(
name|char
operator|*
operator|)
name|master_key
argument_list|,
literal|8
argument_list|)
operator|<
literal|0
condition|)
block|{
name|clear_secrets
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s: Write I/O error on master key file\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|close
argument_list|(
name|kfile
argument_list|)
expr_stmt|;
name|clear_secrets
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|clear_secrets
parameter_list|()
block|{
name|bzero
argument_list|(
name|master_key_schedule
argument_list|,
sizeof|sizeof
argument_list|(
name|master_key_schedule
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|master_key
argument_list|,
sizeof|sizeof
argument_list|(
name|master_key
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

