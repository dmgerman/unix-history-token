begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rf_options.c,v 1.3 1999/02/05 00:06:13 oster Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * rf_options.c  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_general.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_options.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RF_DBG_OPTION
end_ifdef

begin_undef
undef|#
directive|undef
name|RF_DBG_OPTION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_DBG_OPTION */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|long rf_##_option_ = _defval_;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|long rf_
comment|/**/
value|_option_ = _defval_;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_include
include|#
directive|include
file|<dev/raidframe/rf_optnames.h>
end_include

begin_undef
undef|#
directive|undef
name|RF_DBG_OPTION
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|{ RF_STRING(_option_),&rf_##_option_ },
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|{ RF_STRING(_option_),&rf_
comment|/**/
value|_option_ },
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
name|RF_DebugName_t
name|rf_debugNames
index|[]
init|=
block|{
include|#
directive|include
file|<dev/raidframe/rf_optnames.h>
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|RF_DBG_OPTION
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|rf_##_option_  = _defval_ ;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|RF_DBG_OPTION
parameter_list|(
name|_option_
parameter_list|,
name|_defval_
parameter_list|)
value|rf_
comment|/**/
value|_option_ = _defval_ ;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_function
name|void
name|rf_ResetDebugOptions
parameter_list|()
block|{
include|#
directive|include
file|<dev/raidframe/rf_optnames.h>
block|}
end_function

end_unit

