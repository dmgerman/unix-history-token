begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"gmp.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"/* gmp-mparam.h -- Compiler/machine parameter header file.\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    *** CREATED BY A PROGRAM -- DO NOT EDIT ***\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (C) 1996 Free Software Foundation, Inc.  */\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BITS_PER_MP_LIMB %d\n"
argument_list|,
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|mp_limb_t
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BYTES_PER_MP_LIMB %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|mp_limb_t
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BITS_PER_LONGINT %d\n"
argument_list|,
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BITS_PER_INT %d\n"
argument_list|,
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BITS_PER_SHORTINT %d\n"
argument_list|,
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define BITS_PER_CHAR 8\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

