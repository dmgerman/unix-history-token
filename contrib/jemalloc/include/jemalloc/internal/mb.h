begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_MB_C_
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/*  * According to the Intel Architecture Software Developer's Manual, current  * processors execute instructions in order from the perspective of other  * processors in a multiprocessor system, but 1) Intel reserves the right to  * change that, and 2) the compiler's optimizer could re-order instructions if  * there weren't some form of barrier.  Therefore, even if running on an  * architecture that does not need memory barriers (everything through at least  * i686), an "optimizer barrier" is necessary.  */
end_comment

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/* This is a true memory barrier. */
block|asm volatile ("pusha;" 	    "xor  %%eax,%%eax;" 	    "cpuid;" 	    "popa;" 	    :
comment|/* Outputs. */
block|:
comment|/* Inputs. */
block|: "memory"
comment|/* Clobbers. */
block|);
else|#
directive|else
comment|/* 	 * This is hopefully enough to keep the compiler from reordering 	 * instructions around this one. 	 */
asm|asm
specifier|volatile
asm|("nop;" 	    :
comment|/* Outputs. */
asm|:
comment|/* Inputs. */
asm|: "memory"
comment|/* Clobbers. */
asm|);
endif|#
directive|endif
block|}
end_function

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("sfence" 	    :
comment|/* Outputs. */
asm|:
comment|/* Inputs. */
asm|: "memory"
comment|/* Clobbers. */
asm|);
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("eieio" 	    :
comment|/* Outputs. */
asm|:
comment|/* Inputs. */
asm|: "memory"
comment|/* Clobbers. */
asm|);
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("membar #StoreStore" 	    :
comment|/* Outputs. */
asm|:
comment|/* Inputs. */
asm|: "memory"
comment|/* Clobbers. */
asm|);
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__tile__
argument_list|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
name|__sync_synchronize
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This is much slower than a simple memory barrier, but the semantics of mutex  * unlock make this work.  */
end_comment

begin_function
name|JEMALLOC_INLINE
name|void
name|mb_write
parameter_list|(
name|void
parameter_list|)
block|{
name|malloc_mutex_t
name|mtx
decl_stmt|;
name|malloc_mutex_init
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
name|malloc_mutex_lock
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
name|malloc_mutex_unlock
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

