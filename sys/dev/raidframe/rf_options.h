begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_options.h,v 1.3 1999/02/05 00:06:13 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_options.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_OPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_OPTIONS_H_
end_define

begin_define
define|#
directive|define
name|RF_DEFAULT_LOCK_TABLE_SIZE
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|RF_DebugNames_s
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|long
modifier|*
name|ptr
decl_stmt|;
block|}
name|RF_DebugName_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|RF_DebugName_t
name|rf_debugNames
index|[]
decl_stmt|;
end_decl_stmt

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
value|extern long rf_##_option_;
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
value|extern long rf_
comment|/**/
value|_option_;
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

begin_function_decl
name|void
name|rf_ResetDebugOptions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_OPTIONS_H_ */
end_comment

end_unit

