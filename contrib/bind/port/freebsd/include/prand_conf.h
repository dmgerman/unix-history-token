begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PRAND_CMD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PRAND_CMD_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DEV_RANDOM
end_ifndef

begin_define
define|#
directive|define
name|HAVE_DEV_RANDOM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DEV_RANDOM */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|cmds
index|[]
init|=
block|{
literal|"/bin/ps -axlw 2>&1"
block|,
literal|"/usr/sbin/arp -an 2>&1"
block|,
literal|"/usr/bin/netstat -an 2>&1"
block|,
literal|"/bin/df  2>&1"
block|,
literal|"/usr/bin/dig com. soa +ti=1 +retry=0 2>&1"
block|,
literal|"/usr/bin/netstat -an 2>&1"
block|,
literal|"/usr/bin/dig . soa +ti=1 +retry=0 2>&1"
block|,
literal|"/usr/sbin/iostat  2>&1"
block|,
literal|"/usr/bin/vmstat  2>&1"
block|,
literal|"/usr/bin/w  2>&1"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|dirs
index|[]
init|=
block|{
literal|"/tmp"
block|,
literal|"/usr/tmp"
block|,
literal|"."
block|,
literal|"/"
block|,
literal|"/var/spool"
block|,
literal|"/dev"
block|,
literal|"/var/mail"
block|,
literal|"/home"
block|,
literal|"/usr/home"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|files
index|[]
init|=
block|{
literal|"/var/log/messages"
block|,
literal|"/var/log/wtmp"
block|,
literal|"/var/log/lastlog"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PRAND_CMD_H_ */
end_comment

end_unit

