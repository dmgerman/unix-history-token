begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b0fea.h,v 1.4 85/08/22 16:41:18 timo Exp $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CWI
end_ifdef

begin_define
define|#
directive|define
name|CONVERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_define
define|#
directive|define
name|PRMNVFILE
value|".prmnv"
end_define

begin_define
define|#
directive|define
name|SAVEPRMNVFILE
value|".prmnv_save"
end_define

begin_define
define|#
directive|define
name|SIGNAL
end_define

begin_define
define|#
directive|define
name|SETJMP
end_define

begin_define
define|#
directive|define
name|KILL
end_define

begin_define
define|#
directive|define
name|TIMING
end_define

begin_define
define|#
directive|define
name|ISATTY
end_define

begin_endif
endif|#
directive|endif
endif|unix
end_endif

begin_comment
comment|/* ********************************************************************	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|unix
end_ifndef

begin_define
define|#
directive|define
name|RENAME
end_define

begin_endif
endif|#
directive|endif
endif|!unix
end_endif

begin_comment
comment|/* ********************************************************************	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|BSD_SELECT
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_comment
comment|/* ********************************************************************	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IBMPC
end_ifdef

begin_define
define|#
directive|define
name|LATTICE
end_define

begin_define
define|#
directive|define
name|SIGNAL
end_define

begin_define
define|#
directive|define
name|START_MESSAGE
end_define

begin_define
define|#
directive|define
name|NO_ABS
end_define

begin_define
define|#
directive|define
name|SETJMP
end_define

begin_define
define|#
directive|define
name|ISATTY
end_define

begin_endif
endif|#
directive|endif
endif|IBMPC
end_endif

begin_comment
comment|/* ********************************************************************	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IBMPC
end_ifndef

begin_comment
comment|/* #define EXT_COMMAND */
end_comment

begin_define
define|#
directive|define
name|TYPE_CHECK
end_define

begin_define
define|#
directive|define
name|PRINT_APPROX
end_define

begin_endif
endif|#
directive|endif
endif|!IBMPC
end_endif

end_unit

