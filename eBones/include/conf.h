begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Configuration info for operating system, hardware description,  * language implementation, C library, etc.  *  * This file should be included in (almost) every file in the Kerberos  * sources, and probably should *not* be needed outside of those  * sources.  (How do we deal with /usr/include/des.h and  * /usr/include/krb.h?)  *  *	from: conf.h,v 4.0 89/01/23 09:58:40 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONF_H_
end_ifndef

begin_include
include|#
directive|include
file|"osconf.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SHORTNAMES
end_ifdef

begin_include
include|#
directive|include
file|"names.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Language implementation-specific definitions  */
end_comment

begin_comment
comment|/* special cases */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_comment
comment|/* broken implementation of ANSI C */
end_comment

begin_undef
undef|#
directive|undef
name|__STDC__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_comment
comment|/* pointer to generic data */
end_comment

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Does your compiler understand "void"? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A few checks to see that necessary definitions are included.  */
end_comment

begin_comment
comment|/* byte order */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSBFIRST
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|LSBFIRST
end_ifndef

begin_label
name|Error
label|:
end_label

begin_decl_stmt
name|byte
name|order
name|not
name|defined
operator|.
endif|#
directive|endif
endif|#
directive|endif
comment|/* machine size */
ifndef|#
directive|ifndef
name|BITS16
ifndef|#
directive|ifndef
name|BITS32
name|Error
range|:
name|how
name|big
name|is
name|this
name|machine
name|anyways
condition|?
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of checks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONF_H_ */
end_comment

end_unit

