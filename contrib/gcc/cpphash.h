begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* different kinds of things that can appear in the value field    of a hash node.  Actually, this may be useless now. */
end_comment

begin_union
union|union
name|hashval
block|{
name|int
name|ival
decl_stmt|;
name|char
modifier|*
name|cpval
decl_stmt|;
name|DEFINITION
modifier|*
name|defn
decl_stmt|;
if|#
directive|if
literal|0
block|KEYDEF *keydef;
endif|#
directive|endif
block|}
union|;
end_union

begin_struct
struct|struct
name|hashnode
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
comment|/* double links for easy deletion */
name|struct
name|hashnode
modifier|*
name|prev
decl_stmt|;
name|struct
name|hashnode
modifier|*
modifier|*
name|bucket_hdr
decl_stmt|;
comment|/* also, a back pointer to this node's hash 				   chain is kept, in case the node is the head 				   of the chain and gets deleted. */
name|enum
name|node_type
name|type
decl_stmt|;
comment|/* type of special token */
name|int
name|length
decl_stmt|;
comment|/* length of token, for quick comparison */
name|U_CHAR
modifier|*
name|name
decl_stmt|;
comment|/* the actual name */
name|union
name|hashval
name|value
decl_stmt|;
comment|/* pointer to expansion, or whatever */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hashnode
name|HASHNODE
typedef|;
end_typedef

begin_comment
comment|/* Some definitions for the hash table.  The hash function MUST be    computed as shown in hashf () below.  That is because the rescan    loop computes the hash value `on the fly' for most tokens,    in order to avoid the overhead of a lot of procedure calls to    the hashf () function.  Hashf () only exists for the sake of    politeness, for use when speed isn't so important. */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|1403
end_define

begin_decl_stmt
specifier|static
name|HASHNODE
modifier|*
name|hashtab
index|[
name|HASHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HASHSTEP
parameter_list|(
name|old
parameter_list|,
name|c
parameter_list|)
value|((old<< 2) + c)
end_define

begin_define
define|#
directive|define
name|MAKE_POS
parameter_list|(
name|v
parameter_list|)
value|(v& 0x7fffffff)
end_define

begin_comment
comment|/* make number positive */
end_comment

begin_decl_stmt
specifier|extern
name|HASHNODE
modifier|*
name|install
name|PARAMS
argument_list|(
operator|(
name|U_CHAR
operator|*
operator|,
name|int
operator|,
expr|enum
name|node_type
operator|,
name|int
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
specifier|extern
name|int
name|hashf
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_macro
name|PARAMS
argument_list|(
operator|(
name|HASHNODE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

