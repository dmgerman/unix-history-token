begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)ftime.c	2.5	4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSCID */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
name|unsigned
name|short
name|millitm
decl_stmt|;
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|long
name|timezone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|daylight
decl_stmt|;
end_decl_stmt

begin_macro
name|ftime
argument_list|(
argument|tp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeb
modifier|*
name|tp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|t
decl_stmt|;
name|time
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|tp
operator|->
name|time
operator|=
name|t
expr_stmt|;
name|tp
operator|->
name|millitm
operator|=
literal|0
expr_stmt|;
name|tp
operator|->
name|timezone
operator|=
name|timezone
operator|/
literal|60
expr_stmt|;
name|tp
operator|->
name|dstflag
operator|=
name|daylight
expr_stmt|;
block|}
end_block

end_unit

