begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: rlc.c,v 1.2 83/08/30 12:31:39 sklower Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*					-[Sat Jan 29 13:32:26 1983 by jkf]-  * 	rlc.c				$Locker:  $  * relocator for data space   *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_include
include|#
directive|include
file|"h/global.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|os_4_2
end_ifdef

begin_define
define|#
directive|define
name|brk
value|_brk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|holend
index|[]
decl_stmt|,
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|usehole
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curhbeg
decl_stmt|;
end_decl_stmt

begin_macro
name|rlc
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|dp
decl_stmt|;
name|brk
argument_list|(
name|end
argument_list|)
expr_stmt|;
name|dp
operator|=
name|holend
expr_stmt|;
name|cp
operator|=
name|dp
operator|-
name|HOLE
expr_stmt|;
while|while
condition|(
name|dp
operator|<
name|end
condition|)
operator|*
name|dp
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
name|curhbeg
operator|=
name|holend
operator|-
name|HOLE
expr_stmt|;
comment|/* set up the hole */
name|usehole
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

end_unit

