begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alloca.c -- allocate automatically reclaimed memory    (Mostly) portable public-domain implementation -- D A Gwyn     This implementation of the PWB library alloca function,    which is used to allocate space off the run-time stack so    that it is automatically reclaimed upon procedure exit,    was inspired by discussions with J. Q. Johnson of Cornell.    J.Otto Tennant<jot@cray.com> contributed the Cray support.     There are some preprocessor constants that can    be defined when compiling for your specific system, for    improved efficiency; however, the defaults should be okay.     The general concept of this implementation is to keep    track of all alloca-allocated blocks, and reclaim any    that are found to be deeper in the stack than the current    invocation.  This heuristic does not reclaim storage as    soon as it becomes invalid, but it will do so eventually.     As a special case, alloca(0) reclaims storage without    allocating any.  It is a good idea to use alloca(0) in    your main control loop, etc. to force garbage collection.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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
file|"blockinput.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If compiling with GCC 2, this file's not needed.  Except of course if    the C alloca is explicitly requested.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_C_ALLOCA
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|<
literal|2
end_if

begin_comment
comment|/* If someone has defined alloca as a macro,    there must be some other way alloca is supposed to work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|emacs
end_ifdef

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
endif|#
directive|endif
comment|/* STACK_DIRECTION undefined */
endif|#
directive|endif
comment|/* static */
endif|#
directive|endif
comment|/* emacs */
comment|/* If your stack is a linked list of frames, you have to    provide an "address metric" ADDRESS_FUNCTION macro.  */
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRAY_STACKSEG_END
argument_list|)
name|long
name|i00afunc
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ADDRESS_FUNCTION
parameter_list|(
name|arg
parameter_list|)
value|(char *) i00afunc (&(arg))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADDRESS_FUNCTION
parameter_list|(
name|arg
parameter_list|)
value|&(arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Different portions of Emacs need to call different versions of    malloc.  The Emacs executable needs alloca to call xmalloc, because    ordinary malloc isn't protected from input signals.  On the other    hand, the utilities in lib-src need alloca to call malloc; some of    them are very simple, and don't have an xmalloc routine.     Non-Emacs programs expect this to call use xmalloc.     Callers below should use malloc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|emacs
end_ifndef

begin_define
define|#
directive|define
name|malloc
value|xmalloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|pointer
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Define STACK_DIRECTION if you know the direction of stack    growth for your system; otherwise it will be automatically    deduced at run-time.     STACK_DIRECTION> 0 => grows toward higher addresses    STACK_DIRECTION< 0 => grows toward lower addresses    STACK_DIRECTION = 0 => direction of growth unknown  */
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
comment|/* Direction unknown.  */
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
comment|/* Known at compile-time.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STACK_DIRECTION == 0; need run-time code.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|stack_dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 or -1 once known.  */
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
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|addr
init|=
name|NULL
decl_stmt|;
comment|/* Address of first `dummy', once known.  */
specifier|auto
name|char
name|dummy
decl_stmt|;
comment|/* To get stack address.  */
if|if
condition|(
name|addr
operator|==
name|NULL
condition|)
block|{
comment|/* Initial entry.  */
name|addr
operator|=
name|ADDRESS_FUNCTION
argument_list|(
name|dummy
argument_list|)
expr_stmt|;
name|find_stack_direction
argument_list|()
expr_stmt|;
comment|/* Recurse once.  */
block|}
else|else
block|{
comment|/* Second entry.  */
if|if
condition|(
name|ADDRESS_FUNCTION
argument_list|(
name|dummy
argument_list|)
operator|>
name|addr
condition|)
name|stack_dir
operator|=
literal|1
expr_stmt|;
comment|/* Stack grew upward.  */
else|else
name|stack_dir
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Stack grew downward.  */
block|}
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
comment|/* An "alloca header" is used to:    (a) chain together all alloca'ed blocks;    (b) keep track of stack depth.     It is very important that sizeof(header) agree with malloc    alignment chunk size.  The following default should work okay.  */
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
comment|/* To force sizeof(header).  */
struct|struct
block|{
name|union
name|hdr
modifier|*
name|next
decl_stmt|;
comment|/* For chaining headers.  */
name|char
modifier|*
name|deep
decl_stmt|;
comment|/* For stack depth measure.  */
block|}
name|h
struct|;
block|}
name|header
typedef|;
end_typedef

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
comment|/* -> last alloca header.  */
end_comment

begin_comment
comment|/* Return a pointer to at least SIZE bytes of storage,    which will be automatically reclaimed upon exit from    the procedure that called alloca.  Originally, this space    was supposed to be taken from the current stack frame of the    caller, but that method cannot be made to work for some    implementations of C, for example under Gould's UTX/32.  */
end_comment

begin_function
name|pointer
name|alloca
parameter_list|(
name|size
parameter_list|)
name|unsigned
name|size
decl_stmt|;
block|{
specifier|auto
name|char
name|probe
decl_stmt|;
comment|/* Probes stack depth: */
specifier|register
name|char
modifier|*
name|depth
init|=
name|ADDRESS_FUNCTION
argument_list|(
name|probe
argument_list|)
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
comment|/* Unknown growth direction.  */
name|find_stack_direction
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* Reclaim garbage, defined as all alloca'd storage that      was allocated from deeper in the stack than currently.  */
block|{
specifier|register
name|header
modifier|*
name|hp
decl_stmt|;
comment|/* Traverses linked list.  */
ifdef|#
directive|ifdef
name|emacs
name|BLOCK_INPUT
expr_stmt|;
endif|#
directive|endif
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
comment|/* Collect garbage.  */
name|hp
operator|=
name|np
expr_stmt|;
comment|/* -> next header.  */
block|}
else|else
break|break;
comment|/* Rest are not deeper.  */
name|last_alloca_header
operator|=
name|hp
expr_stmt|;
comment|/* -> last valid storage.  */
ifdef|#
directive|ifdef
name|emacs
name|UNBLOCK_INPUT
expr_stmt|;
endif|#
directive|endif
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
comment|/* No allocation required.  */
comment|/* Allocate combined header + user data storage.  */
block|{
specifier|register
name|pointer
name|new
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|header
argument_list|)
operator|+
name|size
argument_list|)
decl_stmt|;
comment|/* Address of header.  */
if|if
condition|(
name|new
operator|==
literal|0
condition|)
name|abort
argument_list|()
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
comment|/* User storage begins just after header.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRAY_STACKSEG_END
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_I00AFUNC
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY_STACK
end_ifndef

begin_define
define|#
directive|define
name|CRAY_STACK
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY2
end_ifndef

begin_comment
comment|/* Stack structures for CRAY-1, CRAY X-MP, and CRAY Y-MP */
end_comment

begin_struct
struct|struct
name|stack_control_header
block|{
name|long
name|shgrow
range|:
literal|32
decl_stmt|;
comment|/* Number of times stack has grown.  */
name|long
name|shaseg
range|:
literal|32
decl_stmt|;
comment|/* Size of increments to stack.  */
name|long
name|shhwm
range|:
literal|32
decl_stmt|;
comment|/* High water mark of stack.  */
name|long
name|shsize
range|:
literal|32
decl_stmt|;
comment|/* Current size of stack (all segments).  */
block|}
struct|;
end_struct

begin_comment
comment|/* The stack segment linkage control information occurs at    the high-address end of a stack segment.  (The stack    grows from low addresses to high addresses.)  The initial    part of the stack segment linkage control information is    0200 (octal) words.  This provides for register storage    for the routine which overflows the stack.  */
end_comment

begin_struct
struct|struct
name|stack_segment_linkage
block|{
name|long
name|ss
index|[
literal|0200
index|]
decl_stmt|;
comment|/* 0200 overflow words.  */
name|long
name|sssize
range|:
literal|32
decl_stmt|;
comment|/* Number of words in this segment.  */
name|long
name|ssbase
range|:
literal|32
decl_stmt|;
comment|/* Offset to stack base.  */
name|long
label|:
literal|32
expr_stmt|;
name|long
name|sspseg
range|:
literal|32
decl_stmt|;
comment|/* Offset to linkage control of previous 				   segment of stack.  */
name|long
label|:
literal|32
expr_stmt|;
name|long
name|sstcpt
range|:
literal|32
decl_stmt|;
comment|/* Pointer to task common address block.  */
name|long
name|sscsnm
decl_stmt|;
comment|/* Private control structure number for 				   microtasking.  */
name|long
name|ssusr1
decl_stmt|;
comment|/* Reserved for user.  */
name|long
name|ssusr2
decl_stmt|;
comment|/* Reserved for user.  */
name|long
name|sstpid
decl_stmt|;
comment|/* Process ID for pid based multi-tasking.  */
name|long
name|ssgvup
decl_stmt|;
comment|/* Pointer to multitasking thread giveup.  */
name|long
name|sscray
index|[
literal|7
index|]
decl_stmt|;
comment|/* Reserved for Cray Research.  */
name|long
name|ssa0
decl_stmt|;
name|long
name|ssa1
decl_stmt|;
name|long
name|ssa2
decl_stmt|;
name|long
name|ssa3
decl_stmt|;
name|long
name|ssa4
decl_stmt|;
name|long
name|ssa5
decl_stmt|;
name|long
name|ssa6
decl_stmt|;
name|long
name|ssa7
decl_stmt|;
name|long
name|sss0
decl_stmt|;
name|long
name|sss1
decl_stmt|;
name|long
name|sss2
decl_stmt|;
name|long
name|sss3
decl_stmt|;
name|long
name|sss4
decl_stmt|;
name|long
name|sss5
decl_stmt|;
name|long
name|sss6
decl_stmt|;
name|long
name|sss7
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CRAY2 */
end_comment

begin_comment
comment|/* The following structure defines the vector of words    returned by the STKSTAT library routine.  */
end_comment

begin_struct
struct|struct
name|stk_stat
block|{
name|long
name|now
decl_stmt|;
comment|/* Current total stack size.  */
name|long
name|maxc
decl_stmt|;
comment|/* Amount of contiguous space which would 				   be required to satisfy the maximum 				   stack demand to date.  */
name|long
name|high_water
decl_stmt|;
comment|/* Stack high-water mark.  */
name|long
name|overflows
decl_stmt|;
comment|/* Number of stack overflow ($STKOFEN) calls.  */
name|long
name|hits
decl_stmt|;
comment|/* Number of internal buffer hits.  */
name|long
name|extends
decl_stmt|;
comment|/* Number of block extensions.  */
name|long
name|stko_mallocs
decl_stmt|;
comment|/* Block allocations by $STKOFEN.  */
name|long
name|underflows
decl_stmt|;
comment|/* Number of stack underflow calls ($STKRETN).  */
name|long
name|stko_free
decl_stmt|;
comment|/* Number of deallocations by $STKRETN.  */
name|long
name|stkm_free
decl_stmt|;
comment|/* Number of deallocations by $STKMRET.  */
name|long
name|segments
decl_stmt|;
comment|/* Current number of stack segments.  */
name|long
name|maxs
decl_stmt|;
comment|/* Maximum number of stack segments so far.  */
name|long
name|pad_size
decl_stmt|;
comment|/* Stack pad size.  */
name|long
name|current_address
decl_stmt|;
comment|/* Current stack segment address.  */
name|long
name|current_size
decl_stmt|;
comment|/* Current stack segment size.  This 				   number is actually corrupted by STKSTAT to 				   include the fifteen word trailer area.  */
name|long
name|initial_address
decl_stmt|;
comment|/* Address of initial segment.  */
name|long
name|initial_size
decl_stmt|;
comment|/* Size of initial segment.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The following structure describes the data structure which trails    any stack segment.  I think that the description in 'asdef' is    out of date.  I only describe the parts that I am sure about.  */
end_comment

begin_struct
struct|struct
name|stk_trailer
block|{
name|long
name|this_address
decl_stmt|;
comment|/* Address of this block.  */
name|long
name|this_size
decl_stmt|;
comment|/* Size of this block (does not include 				   this trailer).  */
name|long
name|unknown2
decl_stmt|;
name|long
name|unknown3
decl_stmt|;
name|long
name|link
decl_stmt|;
comment|/* Address of trailer block of previous 				   segment.  */
name|long
name|unknown5
decl_stmt|;
name|long
name|unknown6
decl_stmt|;
name|long
name|unknown7
decl_stmt|;
name|long
name|unknown8
decl_stmt|;
name|long
name|unknown9
decl_stmt|;
name|long
name|unknown10
decl_stmt|;
name|long
name|unknown11
decl_stmt|;
name|long
name|unknown12
decl_stmt|;
name|long
name|unknown13
decl_stmt|;
name|long
name|unknown14
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CRAY_STACK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY2
end_ifdef

begin_comment
comment|/* Determine a "stack measure" for an arbitrary ADDRESS.    I doubt that "lint" will like this much.  */
end_comment

begin_function
specifier|static
name|long
name|i00afunc
parameter_list|(
name|long
modifier|*
name|address
parameter_list|)
block|{
name|struct
name|stk_stat
name|status
decl_stmt|;
name|struct
name|stk_trailer
modifier|*
name|trailer
decl_stmt|;
name|long
modifier|*
name|block
decl_stmt|,
name|size
decl_stmt|;
name|long
name|result
init|=
literal|0
decl_stmt|;
comment|/* We want to iterate through all of the segments.  The first      step is to get the stack status structure.  We could do this      more quickly and more directly, perhaps, by referencing the      $LM00 common block, but I know that this works.  */
name|STKSTAT
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* Set up the iteration.  */
name|trailer
operator|=
operator|(
expr|struct
name|stk_trailer
operator|*
operator|)
operator|(
name|status
operator|.
name|current_address
operator|+
name|status
operator|.
name|current_size
operator|-
literal|15
operator|)
expr_stmt|;
comment|/* There must be at least one stack segment.  Therefore it is      a fatal error if "trailer" is null.  */
if|if
condition|(
name|trailer
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* Discard segments that do not contain our argument address.  */
while|while
condition|(
name|trailer
operator|!=
literal|0
condition|)
block|{
name|block
operator|=
operator|(
name|long
operator|*
operator|)
name|trailer
operator|->
name|this_address
expr_stmt|;
name|size
operator|=
name|trailer
operator|->
name|this_size
expr_stmt|;
if|if
condition|(
name|block
operator|==
literal|0
operator|||
name|size
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
name|trailer
operator|=
operator|(
expr|struct
name|stk_trailer
operator|*
operator|)
name|trailer
operator|->
name|link
expr_stmt|;
if|if
condition|(
operator|(
name|block
operator|<=
name|address
operator|)
operator|&&
operator|(
name|address
operator|<
operator|(
name|block
operator|+
name|size
operator|)
operator|)
condition|)
break|break;
block|}
comment|/* Set the result to the offset in this segment and add the sizes      of all predecessor segments.  */
name|result
operator|=
name|address
operator|-
name|block
expr_stmt|;
if|if
condition|(
name|trailer
operator|==
literal|0
condition|)
block|{
return|return
name|result
return|;
block|}
do|do
block|{
if|if
condition|(
name|trailer
operator|->
name|this_size
operator|<=
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
name|result
operator|+=
name|trailer
operator|->
name|this_size
expr_stmt|;
name|trailer
operator|=
operator|(
expr|struct
name|stk_trailer
operator|*
operator|)
name|trailer
operator|->
name|link
expr_stmt|;
block|}
do|while
condition|(
name|trailer
operator|!=
literal|0
condition|)
do|;
comment|/* We are done.  Note that if you present a bogus address (one      not in any segment), you will get a different number back, formed      from subtracting the address of the first block.  This is probably      not what you want.  */
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not CRAY2 */
end_comment

begin_comment
comment|/* Stack address function for a CRAY-1, CRAY X-MP, or CRAY Y-MP.    Determine the number of the cell within the stack,    given the address of the cell.  The purpose of this    routine is to linearize, in some sense, stack addresses    for alloca.  */
end_comment

begin_function
specifier|static
name|long
name|i00afunc
parameter_list|(
name|long
name|address
parameter_list|)
block|{
name|long
name|stkl
init|=
literal|0
decl_stmt|;
name|long
name|size
decl_stmt|,
name|pseg
decl_stmt|,
name|this_segment
decl_stmt|,
name|stack
decl_stmt|;
name|long
name|result
init|=
literal|0
decl_stmt|;
name|struct
name|stack_segment_linkage
modifier|*
name|ssptr
decl_stmt|;
comment|/* Register B67 contains the address of the end of the      current stack segment.  If you (as a subprogram) store      your registers on the stack and find that you are past      the contents of B67, you have overflowed the segment.       B67 also points to the stack segment linkage control      area, which is what we are really interested in.  */
name|stkl
operator|=
name|CRAY_STACKSEG_END
argument_list|()
expr_stmt|;
name|ssptr
operator|=
operator|(
expr|struct
name|stack_segment_linkage
operator|*
operator|)
name|stkl
expr_stmt|;
comment|/* If one subtracts 'size' from the end of the segment,      one has the address of the first word of the segment.       If this is not the first segment, 'pseg' will be      nonzero.  */
name|pseg
operator|=
name|ssptr
operator|->
name|sspseg
expr_stmt|;
name|size
operator|=
name|ssptr
operator|->
name|sssize
expr_stmt|;
name|this_segment
operator|=
name|stkl
operator|-
name|size
expr_stmt|;
comment|/* It is possible that calling this routine itself caused      a stack overflow.  Discard stack segments which do not      contain the target address.  */
while|while
condition|(
operator|!
operator|(
name|this_segment
operator|<=
name|address
operator|&&
name|address
operator|<=
name|stkl
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_I00AFUNC
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%011o %011o %011o\n"
argument_list|,
name|this_segment
argument_list|,
name|address
argument_list|,
name|stkl
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|pseg
operator|==
literal|0
condition|)
break|break;
name|stkl
operator|=
name|stkl
operator|-
name|pseg
expr_stmt|;
name|ssptr
operator|=
operator|(
expr|struct
name|stack_segment_linkage
operator|*
operator|)
name|stkl
expr_stmt|;
name|size
operator|=
name|ssptr
operator|->
name|sssize
expr_stmt|;
name|pseg
operator|=
name|ssptr
operator|->
name|sspseg
expr_stmt|;
name|this_segment
operator|=
name|stkl
operator|-
name|size
expr_stmt|;
block|}
name|result
operator|=
name|address
operator|-
name|this_segment
expr_stmt|;
comment|/* If you subtract pseg from the current end of the stack,      you get the address of the previous stack segment's end.      This seems a little convoluted to me, but I'll bet you save      a cycle somewhere.  */
while|while
condition|(
name|pseg
operator|!=
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_I00AFUNC
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%011o %011o\n"
argument_list|,
name|pseg
argument_list|,
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|stkl
operator|=
name|stkl
operator|-
name|pseg
expr_stmt|;
name|ssptr
operator|=
operator|(
expr|struct
name|stack_segment_linkage
operator|*
operator|)
name|stkl
expr_stmt|;
name|size
operator|=
name|ssptr
operator|->
name|sssize
expr_stmt|;
name|pseg
operator|=
name|ssptr
operator|->
name|sspseg
expr_stmt|;
name|result
operator|+=
name|size
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CRAY2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no alloca */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GCC version 2 */
end_comment

end_unit

