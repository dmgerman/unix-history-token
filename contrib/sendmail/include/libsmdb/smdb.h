begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Copyright (c) 1999-2000 Sendmail, Inc. and its suppliers. **	All rights reserved. ** ** By using this file, you agree to the terms and conditions set ** forth in the LICENSE file which can be found at the top level of ** the sendmail distribution. ** ** $Id: smdb.h,v 8.29.2.1.2.2 2000/10/05 22:23:55 gshapiro Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMDB_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_include
include|#
directive|include
file|"sendmail/cdefs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __P */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDBM
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NEWDB
end_ifndef

begin_expr_stmt
name|ERROR
name|NDBM
name|or
name|NEWDB
name|must
name|be
name|defined
operator|.
endif|#
directive|endif
comment|/* ! NEWDB */
endif|#
directive|endif
comment|/* ! NDBM */
ifdef|#
directive|ifdef
name|NDBM
include|#
directive|include
file|<ndbm.h>
endif|#
directive|endif
comment|/* NDBM */
ifdef|#
directive|ifdef
name|NEWDB
include|#
directive|include
file|<db.h>
ifndef|#
directive|ifndef
name|DB_VERSION_MAJOR
define|#
directive|define
name|DB_VERSION_MAJOR
value|1
endif|#
directive|endif
comment|/* ! DB_VERSION_MAJOR */
endif|#
directive|endif
comment|/* NEWDB */
comment|/* ** Some size constants */
define|#
directive|define
name|SMDB_MAX_USER_NAME_LEN
value|1024
define|#
directive|define
name|SMDB_MAX_NAME_LEN
value|1024
comment|/* ** This file defines the abstraction for database lookups. It is pretty ** much a copy of the db2 interface with the exception that every function ** returns 0 on success and non-zero on failure. The non-zero return code ** is meaningful. ** ** I'm going to put the function comments in this file since the interface ** MUST be the same for all inheritors of this interface. */
expr|typedef struct
name|database_struct
name|SMDB_DATABASE
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|cursor_struct
name|SMDB_CURSOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|entry_struct
name|SMDB_DBENT
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_CLOSE_FUNC -- close the database ** **	Parameters: **		db -- The database to close. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_close_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_DEL_FUNC -- removes a key and data pair from the database ** **	Parameters: **		db -- The database to close. **		key -- The key to remove. **		flags -- delete options. There are currently no defined **			 flags for delete. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_del_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|SMDB_DBENT
operator|*
name|key
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_FD_FUNC -- Returns a pointer to a file used for the database. ** **	Parameters: **		db -- The database to close. **		fd -- A pointer to store the returned fd in. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_fd_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|int
operator|*
name|fd
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_GET_FUNC -- Gets the data associated with a key. ** **	Parameters: **		db -- The database to close. **		key -- The key to access. **		data -- A place to store the returned data. **		flags -- get options. There are currently no defined **			 flags for get. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_get_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|SMDB_DBENT
operator|*
name|key
operator|,
name|SMDB_DBENT
operator|*
name|data
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_PUT_FUNC -- Sets some data according to the key. ** **	Parameters: **		db -- The database to close. **		key -- The key to use. **		data -- The data to store. **		flags -- put options: **			SMDBF_NO_OVERWRITE - Return an error if key alread **					     exists. **			SMDBF_ALLOW_DUP - Allow duplicates in btree maps. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_put_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|SMDB_DBENT
operator|*
name|key
operator|,
name|SMDB_DBENT
operator|*
name|data
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_SYNC_FUNC -- Flush any cached information to disk. ** **	Parameters: **		db -- The database to sync. **		flags -- sync options: ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_sync_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_SET_OWNER_FUNC -- Set the owner and group of the database files. ** **	Parameters: **		db -- The database to set. **		uid -- The UID for the new owner (-1 for no change) **		gid -- The GID for the new owner (-1 for no change) ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_set_owner_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|uid_t
name|uid
operator|,
name|gid_t
name|gid
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_CURSOR -- Obtain a cursor for sequential access ** **	Parameters: **		db -- The database to use. **		cursor -- The address of a cursor pointer. **		flags -- sync options: ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_cursor_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|,
name|SMDB_CURSOR
operator|*
operator|*
name|cursor
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_lockfd_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
name|db
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|database_struct
block|{
name|db_close_func
name|smdb_close
decl_stmt|;
name|db_del_func
name|smdb_del
decl_stmt|;
name|db_fd_func
name|smdb_fd
decl_stmt|;
name|db_get_func
name|smdb_get
decl_stmt|;
name|db_put_func
name|smdb_put
decl_stmt|;
name|db_sync_func
name|smdb_sync
decl_stmt|;
name|db_set_owner_func
name|smdb_set_owner
decl_stmt|;
name|db_cursor_func
name|smdb_cursor
decl_stmt|;
name|db_lockfd_func
name|smdb_lockfd
decl_stmt|;
name|void
modifier|*
name|smdb_impl
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* ** DB_CURSOR_CLOSE -- Close a cursor ** **	Parameters: **		cursor -- The cursor to close. ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_cursor_close_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_CURSOR
operator|*
name|cursor
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_CURSOR_DEL -- Delete the key/value pair of this cursor ** **	Parameters: **		cursor -- The cursor. **		flags -- flags ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_cursor_del_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_CURSOR
operator|*
name|cursor
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* ** DB_CURSOR_GET -- Get the key/value of this cursor. ** **	Parameters: **		cursor -- The cursor. **		key -- The current key. **		value -- The current value **		flags -- flags ** **	Returns: **		0 - Success, otherwise errno. **		SMDBE_LAST_ENTRY - This is a success condition that **				   gets returned when the end of the **				   database is hit. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_cursor_get_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_CURSOR
operator|*
name|cursor
operator|,
name|SMDB_DBENT
operator|*
name|key
operator|,
name|SMDB_DBENT
operator|*
name|data
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* ** Flags for DB_CURSOR_GET */
end_comment

begin_define
define|#
directive|define
name|SMDB_CURSOR_GET_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|SMDB_CURSOR_GET_LAST
value|1
end_define

begin_define
define|#
directive|define
name|SMDB_CURSOR_GET_NEXT
value|2
end_define

begin_define
define|#
directive|define
name|SMDB_CURSOR_GET_RANGE
value|3
end_define

begin_escape
end_escape

begin_comment
comment|/* ** DB_CURSOR_PUT -- Put the key/value at this cursor. ** **	Parameters: **		cursor -- The cursor. **		key -- The current key. **		value -- The current value **		flags -- flags ** **	Returns: **		0 - Success, otherwise errno. ** */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*db_cursor_put_func
argument_list|)
name|__P
argument_list|(
operator|(
name|SMDB_CURSOR
operator|*
name|cursor
operator|,
name|SMDB_DBENT
operator|*
name|key
operator|,
name|SMDB_DBENT
operator|*
name|data
operator|,
name|u_int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|cursor_struct
block|{
name|db_cursor_close_func
name|smdbc_close
decl_stmt|;
name|db_cursor_del_func
name|smdbc_del
decl_stmt|;
name|db_cursor_get_func
name|smdbc_get
decl_stmt|;
name|db_cursor_put_func
name|smdbc_put
decl_stmt|;
name|void
modifier|*
name|smdbc_impl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|database_params_struct
block|{
name|u_int
name|smdbp_num_elements
decl_stmt|;
name|u_int
name|smdbp_cache_size
decl_stmt|;
name|bool
name|smdbp_allow_dup
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|database_params_struct
name|SMDB_DBPARAMS
typedef|;
end_typedef

begin_struct
struct|struct
name|database_user_struct
block|{
name|uid_t
name|smdbu_id
decl_stmt|;
name|gid_t
name|smdbu_group_id
decl_stmt|;
name|char
name|smdbu_name
index|[
name|SMDB_MAX_USER_NAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|database_user_struct
name|SMDB_USER_INFO
typedef|;
end_typedef

begin_struct
struct|struct
name|entry_struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|char
modifier|*
name|SMDB_DBTYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|SMDB_FLAG
typedef|;
end_typedef

begin_comment
comment|/* ** These are types of databases. */
end_comment

begin_define
define|#
directive|define
name|SMDB_TYPE_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_DEFAULT_LEN
value|0
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_HASH
value|"hash"
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_HASH_LEN
value|5
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_BTREE
value|"btree"
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_BTREE_LEN
value|6
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_NDBM
value|"dbm"
end_define

begin_define
define|#
directive|define
name|SMDB_TYPE_NDBM_LEN
value|4
end_define

begin_comment
comment|/* ** These are flags */
end_comment

begin_comment
comment|/* Flags for put */
end_comment

begin_define
define|#
directive|define
name|SMDBF_NO_OVERWRITE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SMDBF_ALLOW_DUP
value|0x00000002
end_define

begin_decl_stmt
specifier|extern
name|SMDB_DATABASE
modifier|*
name|smdb_malloc_database
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|smdb_free_database
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_open_database
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|long
operator|,
name|SMDB_DBTYPE
operator|,
name|SMDB_USER_INFO
operator|*
operator|,
name|SMDB_DBPARAMS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEWDB
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|smdb_db_open
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|long
operator|,
name|SMDB_DBTYPE
operator|,
name|SMDB_USER_INFO
operator|*
operator|,
name|SMDB_DBPARAMS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEWDB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDBM
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|smdb_ndbm_open
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|long
operator|,
name|SMDB_DBTYPE
operator|,
name|SMDB_USER_INFO
operator|*
operator|,
name|SMDB_DBPARAMS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NDBM */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|smdb_add_extension
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_setup_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|long
operator|,
name|SMDB_USER_INFO
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_lock_file
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_unlock_file
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_filechanged
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|smdb_print_available_types
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|smdb_db_definition
name|__P
argument_list|(
operator|(
name|SMDB_DBTYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_lock_map
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smdb_unlock_map
name|__P
argument_list|(
operator|(
name|SMDB_DATABASE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SMDB_H_ */
end_comment

end_unit

