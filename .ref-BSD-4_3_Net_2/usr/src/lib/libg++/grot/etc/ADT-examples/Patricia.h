begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implements the PATRICIA Trie ADT.  PATRICIA stands for ``Practical    Algorithm to Retrieve Information Coded in Alphanumeric.''  PATRICIA    was developed by D.R. Morrison.  The current implementation is    based upon Robert Sedgewick's description in his Algorithms book.        Includes operations for  * Initialization  * Insertion  * Retrieval */
end_comment

begin_comment
comment|/* This could change, depending on what client wants */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|CONTENTS
typedef|;
end_typedef

begin_comment
comment|/* Record structure that *must* be visible to clients. */
end_comment

begin_decl_stmt
name|class
name|Trie_Record
block|{
name|private
label|:
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Only works safely and easily for char *'s */
name|CONTENTS
name|contents
decl_stmt|;
comment|/* Pointer to record Contents referenced by Key */
name|public
label|:
name|char
modifier|*
name|get_key
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|key
return|;
block|}
name|CONTENTS
name|get_contents
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|contents
return|;
block|}
name|void
name|set_key
parameter_list|(
name|char
modifier|*
name|k
parameter_list|)
block|{
name|key
operator|=
name|k
expr_stmt|;
block|}
name|void
name|set_contents
parameter_list|(
name|CONTENTS
name|c
parameter_list|)
block|{
name|contents
operator|=
name|c
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Patricia_Trie
block|{
name|private
label|:
specifier|const
name|int
name|HI_WORD
init|=
literal|7
decl_stmt|;
comment|/* Hi-order bit, starting count from 0 */
specifier|const
name|int
name|BIT_MASK
init|=
literal|07
decl_stmt|;
comment|/* WORD_SHIFT low-order bits enabled */
specifier|const
name|int
name|WORD_BITS
init|=
literal|8
decl_stmt|;
comment|/* Number of Bits in a Block */
specifier|const
name|int
name|WORD_SHIFT
init|=
literal|3
decl_stmt|;
comment|/* i.e. lg (WORD_BITS) */
comment|/* Nested class definition, should be invisible to clients with new C++       scoping rules... */
struct|struct
name|Trie_Node
block|{
name|Trie_Record
name|trie_rec
decl_stmt|;
comment|/* Stores data in the Trie */
name|int
name|branch_bit
decl_stmt|;
comment|/* Stores index of next Bit to compare */
name|Trie_Node
modifier|*
name|left
decl_stmt|;
comment|/* Pointer to left child. */
name|Trie_Node
modifier|*
name|right
decl_stmt|;
comment|/* Pointer to right child. */
name|Trie_Node
argument_list|(
argument|char *k =
literal|""
argument_list|,
argument|int len =
literal|0
argument_list|,
argument|CONTENTS new_contents =
literal|0
argument_list|,
argument|int b =
literal|0
argument_list|)
empty_stmt|;
block|}
struct|;
comment|/* Root for the entire Patricia tree, (actually a dummy header!). */
name|Trie_Node
modifier|*
name|root
decl_stmt|;
comment|/* Recursively free tree memory via modified post-order traversal. */
name|void
name|dispose_trie
parameter_list|(
name|Trie_Node
modifier|*
name|root
parameter_list|)
function_decl|;
comment|/* Normalizes the ith Bit representation */
specifier|inline
name|int
name|get_bit
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|HI_WORD
operator|-
name|i
return|;
block|}
comment|/* Returns 1 if bit is set. */
specifier|inline
name|int
name|is_bit_set
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
operator|(
name|block
operator|&
operator|(
literal|1
operator|<<
name|shift
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/* Return the ith power of 2. */
specifier|inline
name|int
name|POW2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
literal|1
operator|<<
name|i
return|;
block|}
name|public
label|:
name|Patricia_Trie
argument_list|(
name|void
argument_list|)
expr_stmt|;
operator|~
name|Patricia_Trie
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|Trie_Record
modifier|*
name|find
parameter_list|(
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
name|void
name|insert
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|CONTENTS
name|contents
parameter_list|,
name|int
name|key_len
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

