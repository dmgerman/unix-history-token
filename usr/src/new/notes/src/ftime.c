begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)ftime.c	2.4	4/20/84"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|RCSid
init|=
literal|"$Header: ftime.c,v 1.7.0.1 85/02/06 08:44:29 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	This file performs the "ftime" call for systems which  *	no longer support that system call.  *  *	Currently, this is only the USG systems: System III, System V,  *	and UNIX 4.0 (btl-internal)  *	This code is only compiled for these systems; the entire file  *	is surrounded by an #ifdef USG  *  *	this code taken from news 2.10  */
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

begin_endif
endif|#
directive|endif
endif|USG
end_endif

end_unit

