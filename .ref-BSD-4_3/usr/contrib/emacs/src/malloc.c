begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dynamic memory allocation for GNU.    Copyright (C) 1985 Richard M. Stallman,     based mostly on the public domain work of others.  This program is distributed in the hope that it will be useful, but without any warranty.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.     Permission is granted to anyone to distribute verbatim copies    of this program's source code as received, in any medium, provided that    the copyright notice, the nonwarraty notice above    and this permission notice are preserved,    and that the distributor grants the recipient all rights    for further redistribution as permitted by this notice,    and informs him of these rights.     Permission is granted to distribute modified versions of this    program's source code, or of portions of it, under the above    conditions, plus the conditions that all changed files carry    prominent notices stating who last changed them and that the    derived material, including anything packaged together with it and    conceptually functioning as a modification of it rather than an    application of it, is in its entirety subject to a permission    notice identical to this one.     Permission is granted to distribute this program (verbatim or    as modified) in compiled or executable form, provided verbatim    redistribution is permitted as stated above for source code, and     A.  it is accompanied by the corresponding machine-readable       source code, under the above conditions, or     B.  it is accompanied by a written offer, with no time limit,       to distribute the corresponding machine-readable source code,       under the above conditions, to any one, in return for reimbursement       of the cost of distribution.   Verbatim redistribution of the       written offer must be permitted.  Or,     C.  it is distributed by someone who received only the       compiled or executable form, and is accompanied by a copy of the       written offer of source code which he received along with it.     Permission is granted to distribute this program (verbatim or as modified)    in executable form as part of a larger system provided that the source    code for this program, including any modifications used,    is also distributed or offered as stated in the preceding paragraph.  In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_comment
comment|/*  * @(#)nmalloc.c 1 (Caltech) 2/21/82  *  *	U of M Modified: 20 Jun 1983 ACT: strange hacks for Emacs  *  *	Nov 1983, Mike@BRL, Added support for 4.1C/4.2 BSD.  *  * This is a very fast storage allocator.  It allocates blocks of a small   * number of different sizes, and keeps free lists of each size.  Blocks  * that don't exactly fit are passed up to the next larger size.  In this   * implementation, the available sizes are (2^n)-4 (or -16) bytes long.  * This is designed for use in a program that uses vast quantities of  * memory, but bombs when it runs out.  To make it a little better, it  * warns the user when he starts to get near the end.  *  * June 84, ACT: modified rcheck code to check the range given to malloc,  * rather than the range determined by the 2-power used.  *  * Jan 85, RMS: calls malloc_warning to issue warning on nearly full.  * No longer Emacs-specific; can serve as all-purpose malloc for GNU.  * You should call malloc_init to reinitialize after loading dumped Emacs.  * Call malloc_stats to get info on memory stats if MSTATS turned on.  * realloc knows how to return same block given, just changing its size,  * if the power of 2 is correct.  */
end_comment

begin_comment
comment|/*  * nextf[i] is the pointer to the next free block of size 2^(i+3).  The  * smallest allocatable block is 8 bytes.  The overhead information will  * go in the first int of the block, and the returned pointer will point  * to the second.  * #ifdef MSTATS  * nmalloc[i] is the difference between the number of mallocs and frees  * for a given block size. #endif /* MSTATS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|emacs
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* emacs */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* Determine which kind of system this is.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTSTP
end_ifndef

begin_define
define|#
directive|define
name|USG
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SIGTSTP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGIO
end_ifdef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTSTP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/vlimit.h>
end_include

begin_comment
comment|/* warn the user when near the end */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* if BSD42 */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD42 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_1
argument_list|)
operator|||
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|EXEC_PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NBPG
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|NBPG * CLSIZE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CLSIZE
end_ifndef

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no CLSIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPG */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|NBPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no NBPG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no EXEC_PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_1 or USG */
end_comment

begin_define
define|#
directive|define
name|ISALLOC
value|((char) 0xf7)
end_define

begin_comment
comment|/* magic byte that implies allocation */
end_comment

begin_define
define|#
directive|define
name|ISFREE
value|((char) 0x54)
end_define

begin_comment
comment|/* magic byte that implies free block */
end_comment

begin_comment
comment|/* this is for error checking only */
end_comment

begin_define
define|#
directive|define
name|ISMEMALIGN
value|((char) 0xd6)
end_define

begin_comment
comment|/* Stored before the value returned by 				     memalign, with the rest of the word 				     being the distance to the true 				     beginning of the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|start_of_data
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* These two are for user programs to look at, when they are interested.  */
end_comment

begin_decl_stmt
name|int
name|malloc_sbrk_used
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount of data space used now */
end_comment

begin_decl_stmt
name|int
name|malloc_sbrk_unused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount more we can have */
end_comment

begin_comment
comment|/* start of data space; can be changed by calling init_malloc */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|data_space_start
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MSTATS
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|nmalloc
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|nmal
decl_stmt|,
name|nfre
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSTATS */
end_comment

begin_comment
comment|/* If range checking is not turned on, all we have is a flag indicating    whether memory is allocated, an index in nextf[], and a size field; to    realloc() memory we copy either size bytes or 1<<(index+3) bytes depending    on whether the former can hold the exact size (given the value of    'index').  If range checking is on, we always need to know how much space    is allocated, so the 'size' field is never used. */
end_comment

begin_struct
struct|struct
name|mhead
block|{
name|char
name|mh_alloc
decl_stmt|;
comment|/* ISALLOC or ISFREE */
name|char
name|mh_index
decl_stmt|;
comment|/* index in nextf[] */
comment|/* Remainder are valid only when block is allocated */
name|unsigned
name|short
name|mh_size
decl_stmt|;
comment|/* size, if< 0x10000 */
ifdef|#
directive|ifdef
name|rcheck
name|unsigned
name|mh_nbytes
decl_stmt|;
comment|/* number of bytes allocated */
name|int
name|mh_magic4
decl_stmt|;
comment|/* should be == MAGIC4 */
endif|#
directive|endif
comment|/* rcheck */
block|}
struct|;
end_struct

begin_comment
comment|/* Access free-list pointer of a block.   It is stored at block + 4.   This is not a field in the mhead structure   because we want sizeof (struct mhead)   to describe the overhead for when the block is in use,   and we do not want the free-list pointer to count in that.  */
end_comment

begin_define
define|#
directive|define
name|CHAIN
parameter_list|(
name|a
parameter_list|)
define|\
value|(*(struct mhead **) (sizeof (char *) + (char *) (a)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|rcheck
end_ifdef

begin_comment
comment|/* To implement range checking, we write magic values in at the beginning and    end of each allocated block, and make sure they are undisturbed whenever a    free or a realloc occurs. */
end_comment

begin_comment
comment|/* Written in each of the 4 bytes following the block's real space */
end_comment

begin_define
define|#
directive|define
name|MAGIC1
value|0x55
end_define

begin_comment
comment|/* Written in the 4 bytes before the block's real space */
end_comment

begin_define
define|#
directive|define
name|MAGIC4
value|0x55555555
end_define

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|p
parameter_list|)
value|if (!(p)) botch("p"); else
end_define

begin_define
define|#
directive|define
name|EXTRA
value|4
end_define

begin_comment
comment|/* 4 bytes extra for MAGIC1s */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EXTRA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rcheck */
end_comment

begin_comment
comment|/* nextf[i] is free list of blocks of size 2**(i + 3)  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|mhead
modifier|*
name|nextf
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of bytes of writable memory we can expect to be able to get */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lim_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Level number of warnings already issued.   0 -- no warnings issued.   1 -- 75% warning already issued.   2 -- 85% warning already issued. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|warnlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero once initial bunch of free blocks made */
end_comment

begin_decl_stmt
specifier|static
name|int
name|gotpool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cause reinitialization based on job parameters;   also declare where the end of pure storage is. */
end_comment

begin_macro
name|malloc_init
argument_list|(
argument|start
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|start
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|data_space_start
operator|=
name|start
expr_stmt|;
name|lim_data
operator|=
literal|0
expr_stmt|;
name|warnlevel
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_expr_stmt
specifier|static
name|morecore
argument_list|(
name|nu
argument_list|)
comment|/* ask system for more memory */
specifier|register
name|int
name|nu
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* size index to get more of  */
end_comment

begin_block
block|{
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
name|int
name|nblks
decl_stmt|;
specifier|register
name|int
name|siz
decl_stmt|;
if|if
condition|(
operator|!
name|data_space_start
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
name|defined
argument_list|(
name|emacs
argument_list|)
name|data_space_start
operator|=
name|start_of_data
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* not USG, or not Emacs */
name|data_space_start
operator|=
operator|&
name|etext
expr_stmt|;
endif|#
directive|endif
comment|/* not USG, or not Emacs */
block|}
if|if
condition|(
name|lim_data
operator|==
literal|0
condition|)
name|get_lim_data
argument_list|()
expr_stmt|;
comment|/* On initial startup, get two blocks of each size up to 1k bytes */
if|if
condition|(
operator|!
name|gotpool
condition|)
name|getpool
argument_list|()
operator|,
name|getpool
argument_list|()
operator|,
name|gotpool
operator|=
literal|1
expr_stmt|;
comment|/* Find current end of memory and issue warning if getting near max */
name|cp
operator|=
name|sbrk
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|siz
operator|=
name|cp
operator|-
name|data_space_start
expr_stmt|;
name|malloc_sbrk_used
operator|=
name|siz
expr_stmt|;
name|malloc_sbrk_unused
operator|=
name|lim_data
operator|-
name|siz
expr_stmt|;
switch|switch
condition|(
name|warnlevel
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|siz
operator|>
operator|(
name|lim_data
operator|/
literal|4
operator|)
operator|*
literal|3
condition|)
block|{
name|warnlevel
operator|++
expr_stmt|;
name|malloc_warning
argument_list|(
literal|"Warning: past 75% of memory limit"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
if|if
condition|(
name|siz
operator|>
operator|(
name|lim_data
operator|/
literal|20
operator|)
operator|*
literal|17
condition|)
block|{
name|warnlevel
operator|++
expr_stmt|;
name|malloc_warning
argument_list|(
literal|"Warning: past 85% of memory limit"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|siz
operator|>
operator|(
name|lim_data
operator|/
literal|20
operator|)
operator|*
literal|19
condition|)
block|{
name|warnlevel
operator|++
expr_stmt|;
name|malloc_warning
argument_list|(
literal|"Warning: past 95% of memory limit"
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
if|if
condition|(
operator|(
name|int
operator|)
name|cp
operator|&
literal|0x3ff
condition|)
comment|/* land on 1K boundaries */
name|sbrk
argument_list|(
literal|1024
operator|-
operator|(
operator|(
name|int
operator|)
name|cp
operator|&
literal|0x3ff
operator|)
argument_list|)
expr_stmt|;
comment|/* Take at least 2k, and figure out how many blocks of the desired size     we're about to get */
name|nblks
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|siz
operator|=
name|nu
operator|)
operator|<
literal|8
condition|)
name|nblks
operator|=
literal|1
operator|<<
operator|(
operator|(
name|siz
operator|=
literal|8
operator|)
operator|-
name|nu
operator|)
expr_stmt|;
if|if
condition|(
operator|(
name|cp
operator|=
name|sbrk
argument_list|(
literal|1
operator|<<
operator|(
name|siz
operator|+
literal|3
operator|)
argument_list|)
operator|)
operator|==
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
condition|)
return|return;
comment|/* no more room! */
if|if
condition|(
operator|(
name|int
operator|)
name|cp
operator|&
literal|7
condition|)
block|{
comment|/* shouldn't happen, but just in case */
name|cp
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
operator|(
name|int
operator|)
name|cp
operator|+
literal|8
operator|)
operator|&
operator|~
literal|7
operator|)
expr_stmt|;
name|nblks
operator|--
expr_stmt|;
block|}
comment|/* save new header and link the nblks blocks together */
name|nextf
index|[
name|nu
index|]
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
expr_stmt|;
name|siz
operator|=
literal|1
operator|<<
operator|(
name|nu
operator|+
literal|3
operator|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_alloc
operator|=
name|ISFREE
expr_stmt|;
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_index
operator|=
name|nu
expr_stmt|;
if|if
condition|(
operator|--
name|nblks
operator|<=
literal|0
condition|)
break|break;
name|CHAIN
argument_list|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
argument_list|)
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
operator|(
name|cp
operator|+
name|siz
operator|)
expr_stmt|;
name|cp
operator|+=
name|siz
expr_stmt|;
block|}
comment|/* CHAIN ((struct mhead *) cp) = 0; */
comment|/* since sbrk() returns cleared core, this is already set */
block|}
end_block

begin_expr_stmt
specifier|static
name|getpool
argument_list|()
block|{
specifier|register
name|int
name|nu
block|;
specifier|register
name|char
operator|*
name|cp
operator|=
name|sbrk
argument_list|(
literal|0
argument_list|)
block|;
if|if
condition|(
operator|(
name|int
operator|)
name|cp
operator|&
literal|0x3ff
condition|)
comment|/* land on 1K boundaries */
name|sbrk
argument_list|(
literal|1024
operator|-
operator|(
operator|(
name|int
operator|)
name|cp
operator|&
literal|0x3ff
operator|)
argument_list|)
expr_stmt|;
comment|/* Get 2k of storage */
name|cp
operator|=
name|sbrk
argument_list|(
literal|04000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|cp
operator|==
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
condition|)
return|return;
end_if

begin_comment
comment|/* Divide it into an initial 8-word block      plus one block of size 2**nu for nu = 3 ... 10.  */
end_comment

begin_expr_stmt
name|CHAIN
argument_list|(
name|cp
argument_list|)
operator|=
name|nextf
index|[
literal|0
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nextf
index|[
literal|0
index|]
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_alloc
operator|=
name|ISFREE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_index
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cp
operator|+=
literal|8
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|nu
operator|=
literal|0
init|;
name|nu
operator|<
literal|7
condition|;
name|nu
operator|++
control|)
block|{
name|CHAIN
argument_list|(
name|cp
argument_list|)
operator|=
name|nextf
index|[
name|nu
index|]
expr_stmt|;
name|nextf
index|[
name|nu
index|]
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
expr_stmt|;
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_alloc
operator|=
name|ISFREE
expr_stmt|;
operator|(
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|cp
operator|)
operator|->
name|mh_index
operator|=
name|nu
expr_stmt|;
name|cp
operator|+=
literal|8
operator|<<
name|nu
expr_stmt|;
block|}
end_for

begin_escape
unit|}
end_escape

begin_expr_stmt
unit|char
operator|*
name|malloc
argument_list|(
argument|n
argument_list|)
comment|/* get a block */
name|unsigned
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|struct
name|mhead
modifier|*
name|p
decl_stmt|;
specifier|register
name|unsigned
name|int
name|nbytes
decl_stmt|;
specifier|register
name|int
name|nunits
init|=
literal|0
decl_stmt|;
comment|/* Figure out how many bytes are required, rounding up to the nearest      multiple of 4, then figure out which nextf[] area to use */
name|nbytes
operator|=
operator|(
name|n
operator|+
sizeof|sizeof
expr|*
name|p
operator|+
name|EXTRA
operator|+
literal|3
operator|)
operator|&
operator|~
literal|3
expr_stmt|;
block|{
specifier|register
name|unsigned
name|int
name|shiftr
init|=
operator|(
name|nbytes
operator|-
literal|1
operator|)
operator|>>
literal|2
decl_stmt|;
while|while
condition|(
name|shiftr
operator|>>=
literal|1
condition|)
name|nunits
operator|++
expr_stmt|;
block|}
comment|/* If there are no blocks of the appropriate size, go get some */
comment|/* COULD SPLIT UP A LARGER BLOCK HERE ... ACT */
if|if
condition|(
name|nextf
index|[
name|nunits
index|]
operator|==
literal|0
condition|)
name|morecore
argument_list|(
name|nunits
argument_list|)
expr_stmt|;
comment|/* Get one block off the list, and set the new list head */
if|if
condition|(
operator|(
name|p
operator|=
name|nextf
index|[
name|nunits
index|]
operator|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|nextf
index|[
name|nunits
index|]
operator|=
name|CHAIN
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Check for free block clobbered */
comment|/* If not for this check, we would gobble a clobbered free chain ptr */
comment|/* and bomb out on the NEXT allocate of this size block */
if|if
condition|(
name|p
operator|->
name|mh_alloc
operator|!=
name|ISFREE
operator|||
name|p
operator|->
name|mh_index
operator|!=
name|nunits
condition|)
ifdef|#
directive|ifdef
name|rcheck
name|botch
argument_list|(
literal|"block on free list clobbered"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not rcheck */
name|abort
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* not rcheck */
comment|/* Fill in the info, and if range checking, set up the magic numbers */
name|p
operator|->
name|mh_alloc
operator|=
name|ISALLOC
expr_stmt|;
ifdef|#
directive|ifdef
name|rcheck
name|p
operator|->
name|mh_nbytes
operator|=
name|n
expr_stmt|;
name|p
operator|->
name|mh_magic4
operator|=
name|MAGIC4
expr_stmt|;
block|{
specifier|register
name|char
modifier|*
name|m
init|=
operator|(
name|char
operator|*
operator|)
operator|(
name|p
operator|+
literal|1
operator|)
operator|+
name|n
decl_stmt|;
operator|*
name|m
operator|++
operator|=
name|MAGIC1
operator|,
operator|*
name|m
operator|++
operator|=
name|MAGIC1
operator|,
operator|*
name|m
operator|++
operator|=
name|MAGIC1
operator|,
operator|*
name|m
operator|=
name|MAGIC1
expr_stmt|;
block|}
else|#
directive|else
comment|/* not rcheck */
name|p
operator|->
name|mh_size
operator|=
name|n
expr_stmt|;
endif|#
directive|endif
comment|/* not rcheck */
ifdef|#
directive|ifdef
name|MSTATS
name|nmalloc
index|[
name|nunits
index|]
operator|++
expr_stmt|;
name|nmal
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* MSTATS */
return|return
operator|(
name|char
operator|*
operator|)
operator|(
name|p
operator|+
literal|1
operator|)
return|;
block|}
end_block

begin_macro
name|free
argument_list|(
argument|mem
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|mem
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|mhead
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ap
init|=
name|mem
decl_stmt|;
if|if
condition|(
name|ap
operator|==
literal|0
condition|)
return|return;
name|p
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|ap
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|mh_alloc
operator|==
name|ISMEMALIGN
condition|)
block|{
name|ap
operator|-=
name|p
operator|->
name|mh_size
expr_stmt|;
name|p
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|ap
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|->
name|mh_alloc
operator|!=
name|ISALLOC
condition|)
name|abort
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|rcheck
name|ASSERT
argument_list|(
name|p
operator|->
name|mh_magic4
operator|==
name|MAGIC4
argument_list|)
expr_stmt|;
name|ap
operator|+=
name|p
operator|->
name|mh_nbytes
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|ap
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|ap
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|ap
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|ap
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* rcheck */
block|}
block|{
specifier|register
name|int
name|nunits
init|=
name|p
operator|->
name|mh_index
decl_stmt|;
name|ASSERT
argument_list|(
name|nunits
operator|<=
literal|29
argument_list|)
expr_stmt|;
name|p
operator|->
name|mh_alloc
operator|=
name|ISFREE
expr_stmt|;
name|CHAIN
argument_list|(
name|p
argument_list|)
operator|=
name|nextf
index|[
name|nunits
index|]
expr_stmt|;
name|nextf
index|[
name|nunits
index|]
operator|=
name|p
expr_stmt|;
ifdef|#
directive|ifdef
name|MSTATS
name|nmalloc
index|[
name|nunits
index|]
operator|--
expr_stmt|;
name|nfre
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* MSTATS */
block|}
block|}
end_block

begin_function
name|char
modifier|*
name|realloc
parameter_list|(
name|mem
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|mem
decl_stmt|;
specifier|register
name|unsigned
name|n
decl_stmt|;
block|{
specifier|register
name|struct
name|mhead
modifier|*
name|p
decl_stmt|;
specifier|register
name|unsigned
name|int
name|tocopy
decl_stmt|;
specifier|register
name|int
name|nbytes
decl_stmt|;
specifier|register
name|int
name|nunits
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|mem
operator|)
operator|==
literal|0
condition|)
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
name|p
operator|--
expr_stmt|;
name|nunits
operator|=
name|p
operator|->
name|mh_index
expr_stmt|;
name|ASSERT
argument_list|(
name|p
operator|->
name|mh_alloc
operator|==
name|ISALLOC
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|rcheck
name|ASSERT
argument_list|(
name|p
operator|->
name|mh_magic4
operator|==
name|MAGIC4
argument_list|)
expr_stmt|;
block|{
specifier|register
name|char
modifier|*
name|m
init|=
name|mem
operator|+
operator|(
name|tocopy
operator|=
name|p
operator|->
name|mh_nbytes
operator|)
decl_stmt|;
name|ASSERT
argument_list|(
operator|*
name|m
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|m
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|m
operator|++
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|*
name|m
operator|==
name|MAGIC1
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* not rcheck */
if|if
condition|(
name|p
operator|->
name|mh_index
operator|>=
literal|13
condition|)
name|tocopy
operator|=
operator|(
literal|1
operator|<<
operator|(
name|p
operator|->
name|mh_index
operator|+
literal|3
operator|)
operator|)
operator|-
sizeof|sizeof
expr|*
name|p
expr_stmt|;
else|else
name|tocopy
operator|=
name|p
operator|->
name|mh_size
expr_stmt|;
endif|#
directive|endif
comment|/* not rcheck */
comment|/* See if desired size rounds to same power of 2 as actual size. */
name|nbytes
operator|=
operator|(
name|n
operator|+
sizeof|sizeof
expr|*
name|p
operator|+
name|EXTRA
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7
expr_stmt|;
comment|/* If ok, use the same block, just marking its size as changed.  */
if|if
condition|(
name|nbytes
operator|>
operator|(
literal|4
operator|<<
name|nunits
operator|)
operator|&&
name|nbytes
operator|<=
operator|(
literal|8
operator|<<
name|nunits
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|rcheck
specifier|register
name|char
modifier|*
name|m
init|=
name|mem
operator|+
name|tocopy
decl_stmt|;
operator|*
name|m
operator|++
operator|=
literal|0
expr_stmt|;
operator|*
name|m
operator|++
operator|=
literal|0
expr_stmt|;
operator|*
name|m
operator|++
operator|=
literal|0
expr_stmt|;
operator|*
name|m
operator|++
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|mh_nbytes
operator|=
name|n
expr_stmt|;
name|m
operator|=
name|mem
operator|+
name|n
expr_stmt|;
operator|*
name|m
operator|++
operator|=
name|MAGIC1
expr_stmt|;
operator|*
name|m
operator|++
operator|=
name|MAGIC1
expr_stmt|;
operator|*
name|m
operator|++
operator|=
name|MAGIC1
expr_stmt|;
operator|*
name|m
operator|++
operator|=
name|MAGIC1
expr_stmt|;
else|#
directive|else
comment|/* not rcheck */
name|p
operator|->
name|mh_size
operator|=
name|n
expr_stmt|;
endif|#
directive|endif
comment|/* not rcheck */
return|return
name|mem
return|;
block|}
if|if
condition|(
name|n
operator|<
name|tocopy
condition|)
name|tocopy
operator|=
name|n
expr_stmt|;
block|{
specifier|register
name|char
modifier|*
name|new
decl_stmt|;
if|if
condition|(
operator|(
name|new
operator|=
name|malloc
argument_list|(
name|n
argument_list|)
operator|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|bcopy
argument_list|(
name|mem
argument_list|,
name|new
argument_list|,
name|tocopy
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|mem
argument_list|)
expr_stmt|;
return|return
name|new
return|;
block|}
block|}
end_function

begin_function
name|char
modifier|*
name|memalign
parameter_list|(
name|alignment
parameter_list|,
name|size
parameter_list|)
name|unsigned
name|alignment
decl_stmt|,
name|size
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ptr
init|=
name|malloc
argument_list|(
name|size
operator|+
name|alignment
argument_list|)
decl_stmt|;
specifier|register
name|char
modifier|*
name|aligned
decl_stmt|;
specifier|register
name|struct
name|mhead
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|ptr
operator|==
literal|0
condition|)
return|return
literal|0
return|;
comment|/* If entire block has the desired alignment, just accept it.  */
if|if
condition|(
operator|(
operator|(
name|int
operator|)
name|ptr
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
condition|)
return|return
name|ptr
return|;
comment|/* Otherwise, get address of byte in the block that has that alignment.  */
name|aligned
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
operator|(
name|int
operator|)
name|ptr
operator|+
name|alignment
operator|-
literal|1
operator|)
operator|&
operator|-
name|alignment
operator|)
expr_stmt|;
comment|/* Store a suitable indication of how to free the block,      so that free can find the true beginning of it.  */
name|p
operator|=
operator|(
expr|struct
name|mhead
operator|*
operator|)
name|aligned
operator|-
literal|1
expr_stmt|;
name|p
operator|->
name|mh_size
operator|=
name|aligned
operator|-
name|ptr
expr_stmt|;
name|p
operator|->
name|mh_alloc
operator|=
name|ISMEMALIGN
expr_stmt|;
return|return
name|aligned
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_comment
comment|/* This runs into trouble with getpagesize on HPUX.    Patching out seems cleaner than the ugly fix needed.  */
end_comment

begin_function
name|char
modifier|*
name|valloc
parameter_list|(
name|size
parameter_list|)
block|{
return|return
name|memalign
argument_list|(
name|getpagesize
argument_list|()
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HPUX */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|MSTATS
end_ifdef

begin_comment
comment|/* Return statistics describing allocation of blocks of size 2**n. */
end_comment

begin_struct
struct|struct
name|mstats_value
block|{
name|int
name|blocksize
decl_stmt|;
name|int
name|nfree
decl_stmt|;
name|int
name|nused
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|mstats_value
name|malloc_stats
parameter_list|(
name|size
parameter_list|)
name|int
name|size
decl_stmt|;
block|{
name|struct
name|mstats_value
name|v
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|struct
name|mhead
modifier|*
name|p
decl_stmt|;
name|v
operator|.
name|nfree
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|size
operator|<
literal|0
operator|||
name|size
operator|>=
literal|30
condition|)
block|{
name|v
operator|.
name|blocksize
operator|=
literal|0
expr_stmt|;
name|v
operator|.
name|nused
operator|=
literal|0
expr_stmt|;
return|return
name|v
return|;
block|}
name|v
operator|.
name|blocksize
operator|=
literal|1
operator|<<
operator|(
name|size
operator|+
literal|3
operator|)
expr_stmt|;
name|v
operator|.
name|nused
operator|=
name|nmalloc
index|[
name|size
index|]
expr_stmt|;
for|for
control|(
name|p
operator|=
name|nextf
index|[
name|size
index|]
init|;
name|p
condition|;
name|p
operator|=
name|CHAIN
argument_list|(
name|p
argument_list|)
control|)
name|v
operator|.
name|nfree
operator|++
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSTATS */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *	This function returns the total number of bytes that the process  *	will be allowed to allocate via the sbrk(2) system call.  On  *	BSD systems this is the total space allocatable to stack and  *	data.  On USG systems this is the data space only.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_macro
name|get_lim_data
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|long
name|ulimit
parameter_list|()
function_decl|;
name|lim_data
operator|=
name|ulimit
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|lim_data
operator|-=
operator|(
name|long
operator|)
name|data_space_start
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not USG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_macro
name|get_lim_data
argument_list|()
end_macro

begin_block
block|{
name|lim_data
operator|=
name|vlimit
argument_list|(
name|LIM_DATA
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD42 */
end_comment

begin_macro
name|get_lim_data
argument_list|()
end_macro

begin_block
block|{
name|struct
name|rlimit
name|XXrlimit
decl_stmt|;
name|getrlimit
argument_list|(
name|RLIMIT_DATA
argument_list|,
operator|&
name|XXrlimit
argument_list|)
expr_stmt|;
name|lim_data
operator|=
name|XXrlimit
operator|.
name|rlim_cur
expr_stmt|;
comment|/* soft limit */
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD42 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not USG */
end_comment

end_unit

