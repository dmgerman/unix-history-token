begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Author: Mark Moraes<moraes@csri.toronto.edu> */
end_comment

begin_comment
comment|/*  *  All globals are names starting with _malloc, which should not clash  *  with anything else.  */
end_comment

begin_comment
comment|/*  *  Remember to initialize the variable in globals.c if you want, and  *  provide an alternative short name in globrename.h  */
end_comment

begin_include
include|#
directive|include
file|"globrename.h"
end_include

begin_include
include|#
directive|include
file|"version.c"
end_include

begin_comment
comment|/*  *  _malloc_minchunk is the minimum number of units that a block can be  *  cut down to.  If the difference between the required block size, and  *  the first available block is greater than _malloc_minchunk, the  *  block is chopped into two pieces, else the whole block is returned.  *  The larger this is, the less fragmentation there will be, but the  *  greater the waste. The actual minimum size of a block is therefore  *  _malloc_minchunk*sizeof(Word) This consists of one word each for the  *  boundary tags, one for the next and one for the prev pointers in a  *  free block.  */
end_comment

begin_decl_stmt
name|size_t
name|_malloc_minchunk
init|=
name|FIXEDOVERHEAD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   *  _malloc_rover is the pointer that points 'someplace' in the free  *  list. We start our search for a block from _malloc_rover, thus  *  starting the search at a different place everytime, rather than at  *  the start of the list.  This improves performance considerably, sez  *  Knuth  */
end_comment

begin_decl_stmt
name|Word
modifier|*
name|_malloc_rover
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Word
modifier|*
name|_malloc_hiword
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Word
modifier|*
name|_malloc_loword
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   *  _malloc_sbrkunits is the multiple of sizeof(Word) to actually use in  *  sbrk() calls - _malloc_sbrkunits should be large enough that sbrk  *  isn't called too often, but small enough that any program that  *  mallocs a few bytes doesn't end up being very large. I've set it to  *  1K resulting in a sbrk'ed size of 8K. This is (coincidentally!) the  *  pagesize on Suns.  I think that this seems a reasonable number for  *  modern programs that malloc heavily. For small programs, you may  *  want to set it to a lower number.  */
end_comment

begin_decl_stmt
name|size_t
name|_malloc_sbrkunits
init|=
name|DEF_SBRKUNITS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  optimization of keeping total amount available, so we know to sbrk  *  without searching list. No point searching list unless we have a  *  fair chance of success. Ideally, we'd keep the size of the largest  *  block available and a pointer to it, so we could check definitely if  *  we had enough space. But that is too much housekeeping - we'd have to  *  update that on all mallocs and frees too. (Updating  *  _malloc_totalavail is easier)  */
end_comment

begin_decl_stmt
name|size_t
name|_malloc_totalavail
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Word
modifier|*
name|_malloc_mem
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  Do not call any output routine other than fputs() - use sprintf() if  *  you want to format something before printing. We don't want stdio  *  calling malloc() if we can help it  */
end_comment

begin_decl_stmt
name|int
name|_malloc_tracing
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No tracing */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|_malloc_statsfile
init|=
name|stderr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|_malloc_statsbuf
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_malloc_leaktrace
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PROFILESIZES
end_ifdef

begin_decl_stmt
name|int
name|_malloc_scount
index|[
name|MAXPROFILESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILESIZES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  *  0 or 1 means checking all pointers before using them. Reasonably  *  thorough.  2 means check the entire heap on every call to  *  malloc/free/realloc/memalign. (the rest call these)  */
end_comment

begin_decl_stmt
name|int
name|_malloc_debugging
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_macro
name|univptr_t
argument_list|(
argument|* _malloc_memfunc
argument_list|)
end_macro

begin_expr_stmt
name|proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
operator|=
name|_mal_sbrk
expr_stmt|;
end_expr_stmt

end_unit

