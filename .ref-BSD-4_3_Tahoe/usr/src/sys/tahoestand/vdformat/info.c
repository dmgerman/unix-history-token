begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)info.c	1.2 (Berkeley/CCI) 11/23/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"vdfmt.h"
end_include

begin_comment
comment|/* ** */
end_comment

begin_macro
name|info
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|boolean
name|read_bad_sector_map
parameter_list|()
function_decl|;
name|boolean
name|has_map
decl_stmt|;
name|cur
operator|.
name|state
operator|=
name|inf
expr_stmt|;
name|print
argument_list|(
literal|"Gathering information for "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"controller %d, drive %d.\n\n"
argument_list|,
name|cur
operator|.
name|controller
argument_list|,
name|cur
operator|.
name|drive
argument_list|)
expr_stmt|;
name|has_map
operator|=
name|read_bad_sector_map
argument_list|()
expr_stmt|;
name|print
argument_list|(
literal|"Module serial number is %d.\n"
argument_list|,
name|bad_map
operator|->
name|bs_id
argument_list|)
expr_stmt|;
name|print
argument_list|(
literal|"Drive type is %s.\n"
argument_list|,
name|lab
operator|->
name|d_typename
argument_list|)
expr_stmt|;
if|if
condition|(
name|has_map
operator|==
name|true
condition|)
name|print
argument_list|(
literal|"Drive contains a bad sector map.\n"
argument_list|)
expr_stmt|;
else|else
name|print
argument_list|(
literal|"Drive does not contain a bad sector map.\n"
argument_list|)
expr_stmt|;
name|print_bad_sector_list
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

