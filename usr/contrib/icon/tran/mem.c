begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Memory initialization and allocation for the translator.  */
end_comment

begin_include
include|#
directive|include
file|"itran.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_decl_stmt
name|struct
name|lentry
modifier|*
modifier|*
name|lhash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for local table */
end_comment

begin_decl_stmt
name|struct
name|gentry
modifier|*
modifier|*
name|ghash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for global table */
end_comment

begin_decl_stmt
name|struct
name|centry
modifier|*
modifier|*
name|chash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for constant table */
end_comment

begin_decl_stmt
name|struct
name|ientry
modifier|*
modifier|*
name|ihash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for identifier table */
end_comment

begin_decl_stmt
name|nodeptr
name|tree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parse tree space */
end_comment

begin_decl_stmt
name|nodeptr
name|tend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of parse tree space */
end_comment

begin_decl_stmt
name|struct
name|lentry
modifier|*
name|ltable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local table */
end_comment

begin_decl_stmt
name|struct
name|gentry
modifier|*
name|gtable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global table */
end_comment

begin_decl_stmt
name|struct
name|centry
modifier|*
name|ctable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* constant table */
end_comment

begin_decl_stmt
name|struct
name|ientry
modifier|*
name|itable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* identifier table */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|send
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space */
end_comment

begin_decl_stmt
name|nodeptr
name|tfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for parse tree space */
end_comment

begin_decl_stmt
name|struct
name|lentry
modifier|*
name|lfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for local table */
end_comment

begin_decl_stmt
name|struct
name|gentry
modifier|*
name|gfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for global table */
end_comment

begin_decl_stmt
name|struct
name|centry
modifier|*
name|ctfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer to constant table */
end_comment

begin_decl_stmt
name|struct
name|ientry
modifier|*
name|ifree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for identifier table */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for string space */
end_comment

begin_decl_stmt
name|int
name|tsize
init|=
name|TSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of parse tree space */
end_comment

begin_decl_stmt
name|int
name|lsize
init|=
name|LSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of local table */
end_comment

begin_decl_stmt
name|int
name|gsize
init|=
name|GSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of global table */
end_comment

begin_decl_stmt
name|int
name|csize
init|=
name|CSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of constant table */
end_comment

begin_decl_stmt
name|int
name|isize
init|=
name|ISIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of identifier table */
end_comment

begin_decl_stmt
name|int
name|ssize
init|=
name|SSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of string space */
end_comment

begin_decl_stmt
name|int
name|lhsize
init|=
name|LHSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of local hash table */
end_comment

begin_decl_stmt
name|int
name|ghsize
init|=
name|GHSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of global hash table */
end_comment

begin_decl_stmt
name|int
name|chsize
init|=
name|CHSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of constant hash table */
end_comment

begin_decl_stmt
name|int
name|ihsize
init|=
name|IHSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of identifier hash table */
end_comment

begin_decl_stmt
name|int
name|lmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for local table hash */
end_comment

begin_decl_stmt
name|int
name|gmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for global table hash */
end_comment

begin_decl_stmt
name|int
name|cmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for constant table hash */
end_comment

begin_decl_stmt
name|int
name|imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for identifier table hash */
end_comment

begin_decl_stmt
name|char
modifier|*
name|memfree
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * meminit does per-file initialization of various data structures used  *  by the translator.  */
end_comment

begin_macro
name|meminit
argument_list|()
end_macro

begin_block
block|{
specifier|register
operator|*
name|p
expr_stmt|;
if|if
condition|(
name|memfree
operator|==
name|NULL
condition|)
name|memalloc
argument_list|()
expr_stmt|;
comment|/* allocate data regions for first file */
comment|/*     * Reset the free pointer for each region.     */
name|lfree
operator|=
name|ltable
expr_stmt|;
name|gfree
operator|=
name|gtable
expr_stmt|;
name|ctfree
operator|=
name|ctable
expr_stmt|;
name|ifree
operator|=
name|itable
expr_stmt|;
name|sfree
operator|=
name|strings
expr_stmt|;
name|tfree
operator|=
name|tree
expr_stmt|;
comment|/*     * Zero out the hash tables.     */
for|for
control|(
name|p
operator|=
operator|(
name|int
operator|*
operator|)
name|lhash
init|;
name|p
operator|<
operator|(
name|int
operator|*
operator|)
operator|&
name|lhash
index|[
name|lhsize
index|]
condition|;
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|p
operator|=
operator|(
name|int
operator|*
operator|)
name|ghash
init|;
name|p
operator|<
operator|(
name|int
operator|*
operator|)
operator|&
name|ghash
index|[
name|ghsize
index|]
condition|;
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|p
operator|=
operator|(
name|int
operator|*
operator|)
name|chash
init|;
name|p
operator|<
operator|(
name|int
operator|*
operator|)
operator|&
name|chash
index|[
name|chsize
index|]
condition|;
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|p
operator|=
operator|(
name|int
operator|*
operator|)
name|ihash
init|;
name|p
operator|<
operator|(
name|int
operator|*
operator|)
operator|&
name|ihash
index|[
name|ihsize
index|]
condition|;
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
comment|/*     * Vestigial structures - these flags are only incremented after     *  a call to syserr.  Idea was apparently to count number of     *  entries in an overflowing table, but wasn't completely     *  implemented.     */
name|alclflg
operator|=
literal|0
expr_stmt|;
name|alcgflg
operator|=
literal|0
expr_stmt|;
name|alccflg
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * allocate gets n*size bytes of storage and returns a pointer to it.  */
end_comment

begin_function
name|char
modifier|*
name|allocate
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|)
name|int
name|n
decl_stmt|,
name|size
decl_stmt|;
block|{
specifier|register
name|int
name|need
decl_stmt|;
specifier|register
name|char
modifier|*
name|mfree
decl_stmt|;
specifier|extern
name|char
modifier|*
name|brk
parameter_list|()
function_decl|;
name|need
operator|=
name|n
operator|*
name|size
expr_stmt|;
name|mfree
operator|=
name|memfree
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|brk
argument_list|(
name|memfree
operator|+=
name|need
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|mfree
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * memalloc computes sizes of data regions needed by the translator  * obtains space for them, and initializes pointers to them  */
end_comment

begin_macro
name|memalloc
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|allocate
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
name|memfree
operator|=
name|sbrk
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*     * Round sizes of hash tables for locals, globals, constants, and     *  identifiers to next larger power of two.  The corresponding     *  mask values are set to one less than the hash table size so that     *  an integer value can be&'d with the mask to produce a hash value.     *  (See [lgc]hasher in sym.h.)     */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|lhsize
condition|;
name|i
operator|<<=
literal|1
control|)
empty_stmt|;
name|lhsize
operator|=
name|i
expr_stmt|;
name|lmask
operator|=
name|i
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ghsize
condition|;
name|i
operator|<<=
literal|1
control|)
empty_stmt|;
name|ghsize
operator|=
name|i
expr_stmt|;
name|gmask
operator|=
name|i
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|chsize
condition|;
name|i
operator|<<=
literal|1
control|)
empty_stmt|;
name|chsize
operator|=
name|i
expr_stmt|;
name|cmask
operator|=
name|i
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ihsize
condition|;
name|i
operator|<<=
literal|1
control|)
empty_stmt|;
name|ihsize
operator|=
name|i
expr_stmt|;
name|imask
operator|=
name|i
operator|-
literal|1
expr_stmt|;
comment|/*     * Allocate the various data structures.     */
name|lhash
operator|=
operator|(
expr|struct
name|lentry
operator|*
operator|*
operator|)
name|allocate
argument_list|(
name|lhsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|lentry
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ghash
operator|=
operator|(
expr|struct
name|gentry
operator|*
operator|*
operator|)
name|allocate
argument_list|(
name|ghsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|gentry
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|chash
operator|=
operator|(
expr|struct
name|centry
operator|*
operator|*
operator|)
name|allocate
argument_list|(
name|chsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|centry
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ihash
operator|=
operator|(
expr|struct
name|ientry
operator|*
operator|*
operator|)
name|allocate
argument_list|(
name|ihsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ientry
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ltable
operator|=
operator|(
expr|struct
name|lentry
operator|*
operator|)
name|allocate
argument_list|(
name|lsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|lentry
argument_list|)
argument_list|)
expr_stmt|;
name|gtable
operator|=
operator|(
expr|struct
name|gentry
operator|*
operator|)
name|allocate
argument_list|(
name|gsize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|gentry
argument_list|)
argument_list|)
expr_stmt|;
name|ctable
operator|=
operator|(
expr|struct
name|centry
operator|*
operator|)
name|allocate
argument_list|(
name|csize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|centry
argument_list|)
argument_list|)
expr_stmt|;
name|itable
operator|=
operator|(
expr|struct
name|ientry
operator|*
operator|)
name|allocate
argument_list|(
name|isize
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ientry
argument_list|)
argument_list|)
expr_stmt|;
name|tree
operator|=
operator|(
name|nodeptr
operator|)
name|allocate
argument_list|(
name|tsize
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|strings
operator|=
name|allocate
argument_list|(
name|ssize
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
name|tend
operator|=
call|(
name|nodeptr
call|)
argument_list|(
operator|(
name|int
operator|*
operator|)
name|tree
operator|+
name|tsize
argument_list|)
expr_stmt|;
name|send
operator|=
name|strings
operator|+
name|ssize
expr_stmt|;
comment|/*     * Check to see if there was enough memory.  This assumes that the     *  allocation for strings fails if any of the other allocations     *  failed.  Apparent bug - That assumption is not necessarily valid.     */
if|if
condition|(
name|strings
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't get enough memory\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

