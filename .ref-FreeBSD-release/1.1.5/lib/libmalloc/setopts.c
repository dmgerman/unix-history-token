begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set various malloc options */
end_comment

begin_comment
comment|/*  Author: Mark Moraes<moraes@csri.toronto.edu> */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_macro
name|RCSID
argument_list|(
literal|"$Id: setopts.c,v 1.7 89/10/31 02:01:54 moraes Exp $"
argument_list|)
end_macro

begin_comment
comment|/*   *  Sets debugging level - level 0 and 1 both perform normal checking -  *  making sure a pointer is valid before it is used for any heap data,  *  and doing consistency checking on any block it touches while it  *  works. Level 2 asks for a mal_verify() on every malloc(), free() or  *  realloc(), thus checking the entire heap's pointers for consistency.  *  Level 3 makes mal_verify() check that all free blocks contain a  *  magic pattern that is put into a free block when it is freed.  */
end_comment

begin_function
name|void
name|mal_debug
parameter_list|(
name|level
parameter_list|)
name|int
name|level
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|level
operator|<
literal|0
operator|||
name|level
operator|>
literal|3
condition|)
block|{
return|return;
block|}
name|_malloc_debugging
operator|=
name|level
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
block|}
end_function

begin_comment
comment|/*  *  Allows you to control the number of system calls made, which might  *  be helpful in a program allocating a lot of memory - call this once  *  to set a number big enough to contain all the allocations. Or for  *  very little allocation, so that you don't get a huge space just  *  because you alloc'e a couple of strings  */
end_comment

begin_function
name|void
name|mal_sbrkset
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|<
name|_malloc_minchunk
operator|*
sizeof|sizeof
argument_list|(
name|Word
argument_list|)
condition|)
block|{
comment|/* sbrk'ing anything less than a Word isn't a great idea.*/
return|return;
block|}
name|_malloc_sbrkunits
operator|=
operator|(
name|n
operator|+
sizeof|sizeof
argument_list|(
name|Word
argument_list|)
operator|-
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|Word
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*   *  Since the minimum size block allocated is sizeof(Word)*_malloc_minchunk,  *  adjusting _malloc_minchunk is one way to control  *  memory fragmentation, and if you do a lot of mallocs and frees of  *  objects that have a similar size, then a good way to speed things up  *  is to set _malloc_minchunk such that the minimum size block covers  *  most of the objects you allocate  */
end_comment

begin_function
name|void
name|mal_slopset
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
return|return;
block|}
name|_malloc_minchunk
operator|=
operator|(
name|n
operator|+
sizeof|sizeof
argument_list|(
name|Word
argument_list|)
operator|-
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|Word
argument_list|)
operator|+
name|FIXEDOVERHEAD
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  *  Sets the file used for verbose statistics to 'fd'. Does no  *  verification whatsoever on the file descriptor  */
end_comment

begin_function
name|void
name|mal_setstatsfile
parameter_list|(
name|fd
parameter_list|)
name|FILE
modifier|*
name|fd
decl_stmt|;
block|{
name|_malloc_statsfile
operator|=
name|fd
expr_stmt|;
comment|/* 	 *  This file descriptor had better not have been written to before 	 *  this 	 */
operator|(
name|void
operator|)
name|setvbuf
argument_list|(
name|fd
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|_IONBF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *  Turns tracing on (if value != 0) or off, (if value == 0)  */
end_comment

begin_function
name|void
name|mal_trace
parameter_list|(
name|value
parameter_list|)
name|int
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
condition|)
block|{
comment|/* Try to unbuffer the trace file */
operator|(
name|void
operator|)
name|setvbuf
argument_list|(
name|_malloc_statsfile
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|_IONBF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/*  		 *  Write something to the stats file so stdio can initialize 		 *  its buffers i.e. call malloc() at least once while tracing 		 *  is off, if the unbuffering failed. 		 */
operator|(
name|void
operator|)
name|fputs
argument_list|(
literal|"Malloc tracing starting\n"
argument_list|,
name|_malloc_statsfile
argument_list|)
expr_stmt|;
name|_malloc_tracing
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|_malloc_loword
operator|!=
name|NULL
condition|)
block|{
comment|/* 			 * malloc happened before tracing turned on, so make 			 * sure we print the heap start for xmem analysis. 			 */
name|PRTRACE
argument_list|(
name|sprintf
argument_list|(
name|_malloc_statsbuf
argument_list|,
literal|"heapstart 0x%lx\n"
argument_list|,
operator|(
name|ulong
operator|)
name|_malloc_loword
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* For symmetry */
operator|(
name|void
operator|)
name|fputs
argument_list|(
literal|"Malloc tracing stopped\n"
argument_list|,
name|_malloc_statsfile
argument_list|)
expr_stmt|;
name|_malloc_tracing
operator|=
literal|0
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|_malloc_statsfile
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

