begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bsearch.c  *  * This is something I found on watmath. I've made some minor changes for use  * in this package.  *  * 92/06/04 11:35:15  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char *RCSid = "$OHeader: /usr/mfcf/src/accounts/libuw/RCS/bsearch.c,v 1.1 88/06/11 20:41:48 root Exp $";
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MYBSEARCH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SCCS_IDS
end_ifdef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|SCCSid
index|[]
init|=
literal|"@(#) mytinfo bsearch.c 3.4 92/06/04 public domain, By Ross Ridge"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SHORT_BSEARCH
end_ifdef

begin_define
define|#
directive|define
name|fast_int
value|short
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fast_int
value|mysize_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bsearch - find an element of a sorted vector  *  *	found = bsearch(key, array, dimension, width, compare)  *		returns a pointer to the specified element in the array,  *		or (char*)0 if the element can't be found.  *	key  *		pointer to the element to be searched for in the array  *	array  *		address of an array of elements  *	dimension  *		number of elements in the array  *	width  *		sizeof(type) of each element  *	compare  *		pointer to a function taking (char *) pointers to two elements  *		and returning<0, 0, or>0 as the first element comes before,  *		at, or after the second element.  A compare function is provided  *		for comparing strings. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * $OLog:	bsearch.c,v $  * Revision 1.1  88/06/11  20:41:48  root  * Initial revision  *  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|anyptr
name|bsearch
parameter_list|(
name|key
parameter_list|,
name|array
parameter_list|,
name|dimension
parameter_list|,
name|iwidth
parameter_list|,
name|compare
parameter_list|)
name|anyptr
name|key
decl_stmt|;
name|anyptr
name|array
decl_stmt|;
name|int
name|dimension
decl_stmt|;
name|mysize_t
name|iwidth
decl_stmt|;
name|compar_fn
name|compare
decl_stmt|;
block|{
specifier|register
name|fast_int
name|start
decl_stmt|;
comment|/* offset to start of current interval */
specifier|register
name|fast_int
name|end
decl_stmt|;
comment|/* offset to end+1 of current interval */
specifier|register
name|fast_int
name|middle
decl_stmt|;
comment|/* offset to middle of current interval */
specifier|auto
name|int
name|status
decl_stmt|;
specifier|register
name|fast_int
name|width
decl_stmt|;
name|width
operator|=
name|iwidth
operator|/
sizeof|sizeof
argument_list|(
name|char
argument_list|)
expr_stmt|;
name|start
operator|=
literal|0
expr_stmt|;
name|middle
operator|=
literal|0
expr_stmt|;
name|end
operator|=
name|dimension
expr_stmt|;
while|while
condition|(
name|start
operator|<
name|end
condition|)
block|{
name|middle
operator|=
operator|(
name|start
operator|+
name|end
operator|)
operator|/
literal|2
expr_stmt|;
name|status
operator|=
call|(
modifier|*
name|compare
call|)
argument_list|(
name|key
argument_list|,
operator|(
operator|(
name|char
operator|*
operator|)
name|array
operator|+
name|middle
operator|*
name|width
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
name|end
operator|=
name|middle
expr_stmt|;
elseif|else
if|if
condition|(
name|status
operator|>
literal|0
condition|)
name|start
operator|=
name|middle
operator|+
literal|1
expr_stmt|;
else|else
return|return
call|(
name|anyptr
call|)
argument_list|(
operator|(
operator|(
name|char
operator|*
operator|)
name|array
operator|)
operator|+
name|middle
operator|*
name|width
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MYBSEARCH */
end_comment

end_unit

