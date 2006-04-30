begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|MY_NDBM
end_ifdef

begin_define
define|#
directive|define
name|DBLKSIZ
value|4096
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|List
modifier|*
name|dbm_list
decl_stmt|;
comment|/* cached database */
name|Node
modifier|*
name|dbm_next
decl_stmt|;
comment|/* next key to return for nextkey() */
comment|/* Name of the file to write to if modified is set.  malloc'd.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Nonzero if the database has been modified and dbm_close needs to        write it out to disk.  */
name|int
name|modified
decl_stmt|;
block|}
name|DBM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_comment
comment|/*  * So as not to conflict with other dbm_open, etc., routines that may  * be included by someone's libc, all of my emulation routines are prefixed  * by "my" and we define the "standard" ones to be "my" ones here.  */
end_comment

begin_define
define|#
directive|define
name|dbm_open
value|mydbm_open
end_define

begin_define
define|#
directive|define
name|dbm_close
value|mydbm_close
end_define

begin_define
define|#
directive|define
name|dbm_fetch
value|mydbm_fetch
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
value|mydbm_firstkey
end_define

begin_define
define|#
directive|define
name|dbm_nextkey
value|mydbm_nextkey
end_define

begin_define
define|#
directive|define
name|dbm_store
value|mydbm_store
end_define

begin_define
define|#
directive|define
name|DBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_decl_stmt
name|DBM
modifier|*
name|mydbm_open
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|int
name|flags
operator|,
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mydbm_close
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|mydbm_fetch
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|,
name|datum
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|mydbm_firstkey
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|mydbm_nextkey
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mydbm_store
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|,
name|datum
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MY_NDBM */
end_comment

end_unit

