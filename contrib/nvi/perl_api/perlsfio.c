begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996  *	Keith Bostic.  All rights reserved.  * Copyright (c) 1996  *	Sven Verdoolaege. All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)perlsfio.c	8.1 (Berkeley) 9/24/96"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_include
include|#
directive|include
file|<EXTERN.h>
end_include

begin_include
include|#
directive|include
file|<perl.h>
end_include

begin_include
include|#
directive|include
file|<XSUB.h>
end_include

begin_include
include|#
directive|include
file|"perl_extern.h"
end_include

begin_comment
comment|/*  * PUBLIC: #ifdef USE_SFIO  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SFIO
end_ifdef

begin_define
define|#
directive|define
name|NIL
parameter_list|(
name|type
parameter_list|)
value|((type)0)
end_define

begin_function
specifier|static
name|int
name|sfnviwrite
parameter_list|(
name|f
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|,
name|disc
parameter_list|)
name|Sfio_t
modifier|*
name|f
decl_stmt|;
comment|/* stream involved */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer to read into */
name|int
name|n
decl_stmt|;
comment|/* number of bytes to read */
name|Sfdisc_t
modifier|*
name|disc
decl_stmt|;
comment|/* discipline */
block|{
name|SCR
modifier|*
name|scrp
decl_stmt|;
name|scrp
operator|=
operator|(
name|SCR
operator|*
operator|)
name|SvIV
argument_list|(
operator|(
name|SV
operator|*
operator|)
name|SvRV
argument_list|(
name|perl_get_sv
argument_list|(
literal|"curscr"
argument_list|,
name|FALSE
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|msgq
argument_list|(
name|scrp
argument_list|,
name|M_INFO
argument_list|,
literal|"%.*s"
argument_list|,
name|n
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|/*  * sfdcnewnvi --  *	Create nvi discipline  *  * PUBLIC: Sfdisc_t* sfdcnewnvi __P((SCR*));  */
end_comment

begin_function
name|Sfdisc_t
modifier|*
name|sfdcnewnvi
parameter_list|(
name|scrp
parameter_list|)
name|SCR
modifier|*
name|scrp
decl_stmt|;
block|{
name|Sfdisc_t
modifier|*
name|disc
decl_stmt|;
name|MALLOC
argument_list|(
name|scrp
argument_list|,
name|disc
argument_list|,
name|Sfdisc_t
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
name|Sfdisc_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|disc
condition|)
return|return
name|disc
return|;
name|disc
operator|->
name|readf
operator|=
operator|(
name|Sfread_f
operator|)
name|NULL
expr_stmt|;
name|disc
operator|->
name|writef
operator|=
name|sfnviwrite
expr_stmt|;
name|disc
operator|->
name|seekf
operator|=
operator|(
name|Sfseek_f
operator|)
name|NULL
expr_stmt|;
name|disc
operator|->
name|exceptf
operator|=
operator|(
name|Sfexcept_f
operator|)
name|NULL
expr_stmt|;
return|return
name|disc
return|;
block|}
end_function

begin_comment
comment|/*  * PUBLIC: #endif  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SFIO */
end_comment

end_unit

