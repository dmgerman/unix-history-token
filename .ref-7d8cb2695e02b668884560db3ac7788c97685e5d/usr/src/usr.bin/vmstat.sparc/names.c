begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)names.c	5.1 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|defdrives
index|[]
init|=
block|{
literal|"sd0"
block|,
literal|"sd1"
block|,
literal|"sd2"
block|,
literal|"rd0"
block|,
literal|"rd1"
block|,
literal|"rd2"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|defdrives
index|[]
init|=
block|{
literal|"dk0"
block|,
literal|"dk1"
block|,
literal|"dk2"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|defdrives
index|[]
init|=
block|{
literal|"hp0"
block|,
literal|"hp1"
block|,
literal|"hp2"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DONE
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|defdrives
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

