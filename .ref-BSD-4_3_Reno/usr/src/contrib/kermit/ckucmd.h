begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U C M D . H  --  Header file for Unix cmd package  */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/* Special getchars... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|vms_getchar()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|coninc(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sizes of things */
end_comment

begin_define
define|#
directive|define
name|HLPLW
value|78
end_define

begin_comment
comment|/* Width of ?-help line */
end_comment

begin_define
define|#
directive|define
name|HLPCW
value|19
end_define

begin_comment
comment|/* Width of ?-help column */
end_comment

begin_define
define|#
directive|define
name|CMDBL
value|200
end_define

begin_comment
comment|/* Command buffer length */
end_comment

begin_define
define|#
directive|define
name|HLPBL
value|100
end_define

begin_comment
comment|/* Help string buffer length */
end_comment

begin_define
define|#
directive|define
name|ATMBL
value|100
end_define

begin_comment
comment|/* Command atom buffer length*/
end_comment

begin_comment
comment|/* Special characters */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NUL
end_ifndef

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_comment
comment|/* Null */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HT
value|'\t'
end_define

begin_comment
comment|/* Horizontal Tab */
end_comment

begin_define
define|#
directive|define
name|NL
value|'\n'
end_define

begin_comment
comment|/* Newline */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CR
end_ifndef

begin_define
define|#
directive|define
name|CR
value|'\r'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FF
value|0014
end_define

begin_comment
comment|/* Formfeed    (^L) */
end_comment

begin_define
define|#
directive|define
name|RDIS
value|0022
end_define

begin_comment
comment|/* Redisplay   (^R) */
end_comment

begin_define
define|#
directive|define
name|LDEL
value|0025
end_define

begin_comment
comment|/* Delete line (^U) */
end_comment

begin_define
define|#
directive|define
name|WDEL
value|0027
end_define

begin_comment
comment|/* Delete word (^W) */
end_comment

begin_define
define|#
directive|define
name|ESC
value|0033
end_define

begin_comment
comment|/* Escape */
end_comment

begin_define
define|#
directive|define
name|RUB
value|0177
end_define

begin_comment
comment|/* Rubout */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEL
end_ifndef

begin_define
define|#
directive|define
name|BEL
value|0007
end_define

begin_comment
comment|/* Bell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BS
end_ifndef

begin_define
define|#
directive|define
name|BS
value|0010
end_define

begin_comment
comment|/* Backspace */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SP
end_ifndef

begin_define
define|#
directive|define
name|SP
value|0040
end_define

begin_comment
comment|/* Space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Keyword table flags */
end_comment

begin_define
define|#
directive|define
name|CM_INV
value|1
end_define

begin_comment
comment|/* Invisible keyword */
end_comment

begin_comment
comment|/* Keyword Table Template */
end_comment

begin_struct
struct|struct
name|keytab
block|{
comment|/* Keyword table */
name|char
modifier|*
name|kwd
decl_stmt|;
comment|/* Pointer to keyword string */
name|int
name|val
decl_stmt|;
comment|/* Associated value */
name|int
name|flgs
decl_stmt|;
comment|/* Flags (as defined above) */
block|}
struct|;
end_struct

end_unit

