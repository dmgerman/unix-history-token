begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id @(#)config.h	34.1 10/22/80	*/
end_comment

begin_comment
comment|/*   * this file contains parameters which each site is likely to modify  * to create (and describe) their own configuration.  * The following names will be stored in the (status features) list.  *  */
end_comment

begin_define
define|#
directive|define
name|OS
value|"unix"
end_define

begin_define
define|#
directive|define
name|MACHINE
value|"vax"
end_define

begin_define
define|#
directive|define
name|SITE
value|"ucbvax"
end_define

begin_comment
comment|/*  TTSIZ is the absolute limit, in pages,   * both text and data, of the  * size to which the lisp system may grow.  * If you change this, you must recompile  * alloc.c and data.c  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOLE
end_ifdef

begin_define
define|#
directive|define
name|TTSIZE
value|10216
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TTSIZE
value|6120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_undef
undef|#
directive|undef
name|TTSIZE
end_undef

begin_define
define|#
directive|define
name|TTSIZE
value|10216
end_define

begin_define
define|#
directive|define
name|FREESIZE
value|512 * 10000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

