begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"jove.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LOAD_AV
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD2_10
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PURDUE_EE
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|gould
argument_list|)
operator|)
end_if

begin_function
name|void
name|closekmem
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|get_la
parameter_list|()
block|{
return|return
name|loadav
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(defined(PURDUE_EE)&& (defined(vax) || defined(gould))) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_comment
comment|/*  * struct nlist has different sizes on various machines.  So we  * deliberately initialize only the first element.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|nlist
name|nl
index|[]
init|=
block|{
block|{
literal|"_avenrun"
block|}
block|,
define|#
directive|define
name|X_AVENRUN
value|0
block|{
literal|""
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|kmem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|closekmem
parameter_list|()
block|{
if|if
condition|(
name|kmem
operator|>
literal|0
condition|)
name|close
argument_list|(
name|kmem
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|get_la
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|sun
name|long
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
else|#
directive|else
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|long
name|lseek
name|proto
argument_list|(
operator|(
name|int
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|kmem
operator|==
operator|-
literal|1
condition|)
block|{
return|return
literal|400
return|;
comment|/* So shell commands will say "Chugging" */
block|}
elseif|else
if|if
condition|(
name|kmem
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|kmem
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|f_mess
argument_list|(
literal|"Can't open kmem for load average."
argument_list|)
expr_stmt|;
return|return
literal|400
return|;
block|}
name|nlist
argument_list|(
literal|"/vmunix"
argument_list|,
name|nl
argument_list|)
expr_stmt|;
block|}
name|lseek
argument_list|(
name|kmem
argument_list|,
operator|(
name|long
operator|)
name|nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|kmem
argument_list|,
operator|(
name|UnivPtr
operator|)
name|avenrun
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|sun
return|return
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|*
literal|100L
operator|/
name|FSCALE
argument_list|)
return|;
else|#
directive|else
return|return
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|*
literal|100.
operator|+
literal|.5
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(PURDUE_EE)&& (defined(vax) || defined(gould))) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(defined(BSD4_2)&& !defined(BSD2_10)) */
end_comment

begin_function
name|void
name|closekmem
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|get_la
parameter_list|()
block|{
name|short
name|avg
index|[
literal|3
index|]
decl_stmt|;
name|gldav
argument_list|(
name|avg
argument_list|)
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
name|avg
index|[
literal|0
index|]
operator|*
literal|100L
operator|/
literal|256
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(BSD4_2)&& !defined(BSD2_10)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOAD_AV */
end_comment

end_unit

