begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CMN_ERR_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CMN_ERR_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ASM
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/va_list.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Common error handling severity levels */
define|#
directive|define
name|CE_CONT
value|0
comment|/* continuation		*/
define|#
directive|define
name|CE_NOTE
value|1
comment|/* notice		*/
define|#
directive|define
name|CE_WARN
value|2
comment|/* warning		*/
define|#
directive|define
name|CE_PANIC
value|3
comment|/* panic		*/
define|#
directive|define
name|CE_IGNORE
value|4
comment|/* print nothing	*/
ifndef|#
directive|ifndef
name|_ASM
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*PRINTFLIKE2*/
specifier|extern
name|void
name|cmn_err
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|2
block|)
empty_stmt|;
end_extern

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|cmn_err
name|)
end_pragma

begin_function_decl
specifier|extern
name|void
name|vzcmn_err
parameter_list|(
name|zoneid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vzcmn_err
name|)
end_pragma

begin_function_decl
specifier|extern
name|void
name|vcmn_err
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vcmn_err
name|)
end_pragma

begin_comment
comment|/*PRINTFLIKE3*/
end_comment

begin_function_decl
specifier|extern
name|void
name|zcmn_err
parameter_list|(
name|zoneid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|zcmn_err
name|)
end_pragma

begin_comment
comment|/*PRINTFLIKE1*/
end_comment

begin_function_decl
specifier|extern
name|void
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|printf
name|)
end_pragma

begin_function_decl
specifier|extern
name|void
name|vzprintf
parameter_list|(
name|zoneid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vzprintf
name|)
end_pragma

begin_comment
comment|/*PRINTFLIKE2*/
end_comment

begin_function_decl
specifier|extern
name|void
name|zprintf
parameter_list|(
name|zoneid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|zprintf
name|)
end_pragma

begin_function_decl
specifier|extern
name|void
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vprintf
name|)
end_pragma

begin_comment
comment|/*PRINTFLIKE1*/
end_comment

begin_function_decl
specifier|extern
name|void
name|uprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|uprintf
name|)
end_pragma

begin_function_decl
specifier|extern
name|void
name|vuprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vuprintf
name|)
end_pragma

begin_comment
comment|/*PRINTFLIKE3*/
end_comment

begin_function_decl
specifier|extern
name|size_t
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|size_t
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*PRINTFLIKE2*/
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__KPRINTFLIKE
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__KVPRINTFLIKE
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*PRINTFLIKE1*/
end_comment

begin_decl_stmt
specifier|extern
name|void
name|panic
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__KPRINTFLIKE
argument_list|(
literal|1
argument_list|)
name|__NORETURN
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|panic
name|)
end_pragma

begin_decl_stmt
specifier|extern
name|void
name|vpanic
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|__va_list
argument_list|)
name|__KVPRINTFLIKE
argument_list|(
literal|1
argument_list|)
name|__NORETURN
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|rarely_called
name|(
name|vpanic
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ASM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CMN_ERR_H */
end_comment

end_unit

