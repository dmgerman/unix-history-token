begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	onepass.h	4.2	87/12/10	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ONEPASS_
end_ifndef

begin_define
define|#
directive|define
name|_ONEPASS_
end_define

begin_comment
comment|/*  * Definitions for creating a one-pass  * version of the compiler.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PASS2_
end_ifdef

begin_define
define|#
directive|define
name|crslab
value|crs2lab
end_define

begin_define
define|#
directive|define
name|where
value|where2
end_define

begin_define
define|#
directive|define
name|xdebug
value|x2debug
end_define

begin_define
define|#
directive|define
name|tdebug
value|t2debug
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|deflab
end_ifndef

begin_define
define|#
directive|define
name|deflab
value|def2lab
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|edebug
value|e2debug
end_define

begin_define
define|#
directive|define
name|eprint
value|e2print
end_define

begin_define
define|#
directive|define
name|getlab
value|get2lab
end_define

begin_define
define|#
directive|define
name|filename
value|ftitle
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPREF must be defined for use in first pass tree machine */
end_comment

begin_define
define|#
directive|define
name|NOPREF
value|020000
end_define

begin_comment
comment|/* no preference for register assignment */
end_comment

begin_include
include|#
directive|include
file|"ndu.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

