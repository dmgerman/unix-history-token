begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * general-purpose in-core hashing  */
end_comment

begin_define
define|#
directive|define
name|HASHDATUM
value|struct hashdatum
end_define

begin_macro
name|HASHDATUM
end_macro

begin_block
block|{
name|char
modifier|*
name|dat_ptr
decl_stmt|;
name|unsigned
name|dat_len
decl_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HASHTABLE
end_ifndef

begin_define
define|#
directive|define
name|HASHTABLE
value|struct hashtable
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|HASHTABLE
modifier|*
name|hashcreate
name|_
argument_list|(
operator|(
name|unsigned
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|void
name|hashdestroy
name|_
argument_list|(
operator|(
name|HASHTABLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|void
name|hashstore
name|_
argument_list|(
operator|(
name|HASHTABLE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|HASHDATUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|void
name|hashdelete
name|_
argument_list|(
operator|(
name|HASHTABLE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|HASHDATUM
name|hashfetch
name|_
argument_list|(
operator|(
name|HASHTABLE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|void
name|hashstorelast
name|_
argument_list|(
operator|(
name|HASHDATUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|void
name|hashwalk
name|_
argument_list|(
operator|(
name|HASHTABLE
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_define
define|#
directive|define
name|BADTBL
parameter_list|(
name|tbl
parameter_list|)
value|(((tbl)->ht_magic&BYTEMASK) != HASHMAG)
end_define

begin_define
define|#
directive|define
name|HASHMAG
value|0257
end_define

begin_define
define|#
directive|define
name|BYTEMASK
value|0377
end_define

begin_define
define|#
directive|define
name|HASHENT
value|struct hashent
end_define

begin_macro
name|HASHENT
end_macro

begin_block
block|{
name|HASHENT
modifier|*
name|he_next
decl_stmt|;
comment|/* in hash chain */
name|HASHDATUM
name|he_data
decl_stmt|;
name|int
name|he_keylen
decl_stmt|;
comment|/* to help verify a match */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|HASHTABLE
end_macro

begin_block
block|{
name|HASHENT
modifier|*
modifier|*
name|ht_addr
decl_stmt|;
comment|/* array of HASHENT pointers */
name|unsigned
name|ht_size
decl_stmt|;
name|char
name|ht_magic
decl_stmt|;
name|int
function_decl|(
modifier|*
name|ht_cmp
function_decl|)
parameter_list|()
function_decl|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

