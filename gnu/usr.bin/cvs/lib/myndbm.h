begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)myndbm.h 1.3 92/02/29	 */
end_comment

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

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|DBM
modifier|*
name|mydbm_open
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mydbm_close
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_fetch
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|,
name|datum
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_firstkey
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_nextkey
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DBM
modifier|*
name|mydbm_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mydbm_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|mydbm_nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MY_NDBM */
end_comment

end_unit

