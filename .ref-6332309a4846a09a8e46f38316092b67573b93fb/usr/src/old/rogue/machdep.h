begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Defines for things used in find.c  *  * $Revision: 1.4 $, $Date: 85/03/31 19:20:07 $  */
end_comment

begin_comment
comment|/*  * Don't change the constants, since they are used for sizes in many  * places in the program.  */
end_comment

begin_define
define|#
directive|define
name|MAXSTR
value|80
end_define

begin_comment
comment|/* maximum length of strings */
end_comment

begin_define
define|#
directive|define
name|MAXLINES
value|32
end_define

begin_comment
comment|/* maximum number of screen lines used */
end_comment

begin_define
define|#
directive|define
name|MAXCOLS
value|80
end_define

begin_comment
comment|/* maximum number of screen columns used */
end_comment

begin_define
define|#
directive|define
name|RN
value|(((Seed = Seed * 11109 + 13849)>> 16)& 0xffff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CTRL
end_ifdef

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_endif
endif|#
directive|endif
endif|CTRL
end_endif

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'& 037)
end_define

begin_undef
undef|#
directive|undef
name|unctrl
end_undef

begin_comment
comment|/* Sigh..., why me??? */
end_comment

begin_comment
comment|/*  * Now all the global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Got_ltc
decl_stmt|,
name|In_shell
decl_stmt|,
name|Wizard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Fruit
index|[]
decl_stmt|,
name|Orig_dsusp
decl_stmt|,
name|Prbuf
index|[]
decl_stmt|,
name|Whoami
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|Numscores
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGLTC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ltchars
name|Ltc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|TIOCGLTC
end_endif

begin_comment
comment|/*  * Function types  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|brk
argument_list|()
decl_stmt|,
modifier|*
name|charge_str
argument_list|()
decl_stmt|,
modifier|*
name|choose_str
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|inv_name
argument_list|()
decl_stmt|,
modifier|*
name|killname
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|nothing
argument_list|()
decl_stmt|,
modifier|*
name|nullstr
argument_list|()
decl_stmt|,
modifier|*
name|num
argument_list|()
decl_stmt|,
modifier|*
name|pick_color
argument_list|()
decl_stmt|,
modifier|*
name|ring_num
argument_list|()
decl_stmt|,
modifier|*
name|sbrk
argument_list|()
decl_stmt|,
modifier|*
name|set_mname
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|type_name
argument_list|()
decl_stmt|,
modifier|*
name|unctrl
argument_list|()
decl_stmt|,
modifier|*
name|vowelstr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|auto_save
argument_list|()
decl_stmt|,
name|come_down
argument_list|()
decl_stmt|,
name|doctor
argument_list|()
decl_stmt|,
name|endit
argument_list|()
decl_stmt|,
name|land
argument_list|()
decl_stmt|,
name|leave
argument_list|()
decl_stmt|,
name|nohaste
argument_list|()
decl_stmt|,
name|quit
argument_list|()
decl_stmt|,
name|rollwand
argument_list|()
decl_stmt|,
name|runners
argument_list|()
decl_stmt|,
name|sight
argument_list|()
decl_stmt|,
name|stomach
argument_list|()
decl_stmt|,
name|swander
argument_list|()
decl_stmt|,
name|tstp
argument_list|()
decl_stmt|,
name|turn_see
argument_list|()
decl_stmt|,
name|unconfuse
argument_list|()
decl_stmt|,
name|unsee
argument_list|()
decl_stmt|,
name|visuals
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CHECKTIME
end_ifdef

begin_function_decl
name|int
name|checkout
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|CHECKTIME
end_endif

begin_decl_stmt
name|long
name|lseek
argument_list|()
decl_stmt|,
name|time
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

