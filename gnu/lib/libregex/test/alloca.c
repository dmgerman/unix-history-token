begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	alloca -- (mostly) portable public-domain implementation -- D A Gwyn  	last edit:	86/05/30	rms 	   include config.h, since on VMS it renames some symbols. 	   Use xmalloc instead of malloc.  	This implementation of the PWB library alloca() function, 	which is used to allocate space off the run-time stack so 	that it is automatically reclaimed upon procedure exit, 	was inspired by discussions with J. Q. Johnson of Cornell.  	It should work under any C implementation that uses an 	actual procedure stack (as opposed to a linked list of 	frames).  There are some preprocessor constants that can 	be defined when compiling for your specific system, for 	improved efficiency; however, the defaults should be okay.  	The general concept of this implementation is to keep 	track of all alloca()-allocated blocks, and reclaim any 	that are found to be deeper in the stack than the current 	invocation.  This heuristic does not reclaim storage as 	soon as it becomes invalid, but it will do so eventually.  	As a special case, alloca(0) reclaims storage without 	allocating any.  It is a good idea to use alloca(0) in 	your main control loop, etc. to force garbage collection. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|SCCSid
index|[]
init|=
literal|"@(#)alloca.c	1.1"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for the "what" utility */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|static
end_ifdef

begin_comment
comment|/* actually, only want this if static is defined as ""    -- this is for usg, in which emacs must undefine static    in order to make unexec workable    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_DIRECTION
end_ifndef

begin_expr_stmt
name|you
name|lose
operator|--
name|must
name|know
name|STACK_DIRECTION
name|at
name|compile
operator|-
name|time
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STACK_DIRECTION undefined */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* static */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* emacs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* If compiling with GCC, this file's not needed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_comment
comment|/* generic pointer type */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_comment
comment|/* generic pointer type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/* null pointer constant */
end_comment

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pointer
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 	Define STACK_DIRECTION if you know the direction of stack 	growth for your system; otherwise it will be automatically 	deduced at run-time.  	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_DIRECTION
end_ifndef

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|0
end_define

begin_comment
comment|/* direction unknown */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STACK_DIRECTION
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|STACK_DIR
value|STACK_DIRECTION
end_define

begin_comment
comment|/* known at compile-time */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STACK_DIRECTION == 0; need run-time code */
end_comment

begin_decl_stmt
specifier|static
name|int
name|stack_dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 or -1 once known */
end_comment

begin_define
define|#
directive|define
name|STACK_DIR
value|stack_dir
end_define

begin_function
specifier|static
name|void
name|find_stack_direction
parameter_list|(
comment|/* void */
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|addr
init|=
name|NULL
decl_stmt|;
comment|/* address of first 				   `dummy', once known */
specifier|auto
name|char
name|dummy
decl_stmt|;
comment|/* to get stack address */
if|if
condition|(
name|addr
operator|==
name|NULL
condition|)
block|{
comment|/* initial entry */
name|addr
operator|=
operator|&
name|dummy
expr_stmt|;
name|find_stack_direction
argument_list|()
expr_stmt|;
comment|/* recurse once */
block|}
elseif|else
comment|/* second entry */
if|if
condition|(
operator|&
name|dummy
operator|>
name|addr
condition|)
name|stack_dir
operator|=
literal|1
expr_stmt|;
comment|/* stack grew upward */
else|else
name|stack_dir
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* stack grew downward */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STACK_DIRECTION == 0 */
end_comment

begin_comment
comment|/* 	An "alloca header" is used to: 	(a) chain together all alloca()ed blocks; 	(b) keep track of stack depth.  	It is very important that sizeof(header) agree with malloc() 	alignment chunk size.  The following default should work okay. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN_SIZE
end_ifndef

begin_define
define|#
directive|define
name|ALIGN_SIZE
value|sizeof(double)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
union|union
name|hdr
block|{
name|char
name|align
index|[
name|ALIGN_SIZE
index|]
decl_stmt|;
comment|/* to force sizeof(header) */
struct|struct
block|{
name|union
name|hdr
modifier|*
name|next
decl_stmt|;
comment|/* for chaining headers */
name|char
modifier|*
name|deep
decl_stmt|;
comment|/* for stack depth measure */
block|}
name|h
struct|;
block|}
name|header
typedef|;
end_typedef

begin_comment
comment|/* 	alloca( size ) returns a pointer to at least `size' bytes of 	storage which will be automatically reclaimed upon exit from 	the procedure that called alloca().  Originally, this space 	was supposed to be taken from the current stack frame of the 	caller, but that method cannot be made to work for some 	implementations of C, for example under Gould's UTX/32. */
end_comment

begin_decl_stmt
specifier|static
name|header
modifier|*
name|last_alloca_header
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> last alloca header */
end_comment

begin_function
name|pointer
name|alloca
parameter_list|(
name|size
parameter_list|)
comment|/* returns pointer to storage */
name|unsigned
name|size
decl_stmt|;
comment|/* # bytes to allocate */
block|{
specifier|auto
name|char
name|probe
decl_stmt|;
comment|/* probes stack depth: */
specifier|register
name|char
modifier|*
name|depth
init|=
operator|&
name|probe
decl_stmt|;
if|#
directive|if
name|STACK_DIRECTION
operator|==
literal|0
if|if
condition|(
name|STACK_DIR
operator|==
literal|0
condition|)
comment|/* unknown growth direction */
name|find_stack_direction
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* Reclaim garbage, defined as all alloca()ed storage that 				   was allocated from deeper in the stack than currently. */
block|{
specifier|register
name|header
modifier|*
name|hp
decl_stmt|;
comment|/* traverses linked list */
for|for
control|(
name|hp
operator|=
name|last_alloca_header
init|;
name|hp
operator|!=
name|NULL
condition|;
control|)
if|if
condition|(
operator|(
name|STACK_DIR
operator|>
literal|0
operator|&&
name|hp
operator|->
name|h
operator|.
name|deep
operator|>
name|depth
operator|)
operator|||
operator|(
name|STACK_DIR
operator|<
literal|0
operator|&&
name|hp
operator|->
name|h
operator|.
name|deep
operator|<
name|depth
operator|)
condition|)
block|{
specifier|register
name|header
modifier|*
name|np
init|=
name|hp
operator|->
name|h
operator|.
name|next
decl_stmt|;
name|free
argument_list|(
operator|(
name|pointer
operator|)
name|hp
argument_list|)
expr_stmt|;
comment|/* collect garbage */
name|hp
operator|=
name|np
expr_stmt|;
comment|/* -> next header */
block|}
else|else
break|break;
comment|/* rest are not deeper */
name|last_alloca_header
operator|=
name|hp
expr_stmt|;
comment|/* -> last valid storage */
block|}
if|if
condition|(
name|size
operator|==
literal|0
condition|)
return|return
name|NULL
return|;
comment|/* no allocation required */
comment|/* Allocate combined header + user data storage. */
block|{
specifier|register
name|pointer
name|new
init|=
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|header
argument_list|)
operator|+
name|size
argument_list|)
decl_stmt|;
comment|/* address of header */
operator|(
operator|(
name|header
operator|*
operator|)
name|new
operator|)
operator|->
name|h
operator|.
name|next
operator|=
name|last_alloca_header
expr_stmt|;
operator|(
operator|(
name|header
operator|*
operator|)
name|new
operator|)
operator|->
name|h
operator|.
name|deep
operator|=
name|depth
expr_stmt|;
name|last_alloca_header
operator|=
operator|(
name|header
operator|*
operator|)
name|new
expr_stmt|;
comment|/* User storage begins just after header. */
return|return
call|(
name|pointer
call|)
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new
operator|+
sizeof|sizeof
argument_list|(
name|header
argument_list|)
argument_list|)
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no alloca */
end_comment

end_unit

