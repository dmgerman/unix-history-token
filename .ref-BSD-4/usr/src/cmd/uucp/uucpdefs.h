begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|Thisdir
init|=
name|THISDIR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Spool
init|=
name|SPOOL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Sysfiles
index|[]
init|=
block|{
name|SYSFILE
block|,
name|SYSFILECR
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Devfile
init|=
name|DEVFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dialfile
init|=
name|DIALFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Packflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdrvon
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

