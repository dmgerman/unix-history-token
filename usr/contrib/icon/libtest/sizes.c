begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|double
name|x
decl_stmt|;
name|printf
argument_list|(
literal|"size of double = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of integer = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of descrip = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|descrip
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_int = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_int
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_real = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_real
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_cset = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_cset
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_file = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_file
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_proc = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_proc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_iproc = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_iproc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_list = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_list
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_lelem = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_lelem
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_table = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_table
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_telem = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_telem
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_set = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_set
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_selem = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_selem
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_record = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_record
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_tvsubs = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_tvsubs
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_tvtbl = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_tvtbl
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_estack = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_estack
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of b_eblock = %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_eblock
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

