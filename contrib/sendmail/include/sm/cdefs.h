begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: cdefs.h,v 1.14 2001/06/07 20:04:53 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm C language portability macros **  See libsm/cdefs.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CDEFS_H
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_comment
comment|/* **  BSD and Linux have<sys/cdefs.h> which defines a set of C language **  portability macros that are a defacto standard in the open source **  community. */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_SYS_CDEFS_H
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SYS_CDEFS_H */
end_comment

begin_comment
comment|/* **  Define the standard C language portability macros **  for platforms that lack<sys/cdefs.h>. */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_SYS_CDEFS_H
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__END_DECLS
value|};
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__cplusplus) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
comment|/**/
value|y
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|"x"
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_SYS_CDEFS_H */
end_comment

begin_comment
comment|/* **  Define SM_DEAD, a macro used to declare functions that do not return **  to their caller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_DEAD
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
end_if

begin_define
define|#
directive|define
name|SM_DEAD
parameter_list|(
name|proto
parameter_list|)
value|volatile proto
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__< 5 */
end_comment

begin_define
define|#
directive|define
name|SM_DEAD
parameter_list|(
name|proto
parameter_list|)
value|proto __attribute__((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__< 5 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__>= 2 */
end_comment

begin_define
define|#
directive|define
name|SM_DEAD
parameter_list|(
name|proto
parameter_list|)
value|proto
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__>= 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DEAD */
end_comment

begin_comment
comment|/* **  Define SM_UNUSED, a macro used to declare variables that may be unused. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_UNUSED
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
end_if

begin_define
define|#
directive|define
name|SM_UNUSED
parameter_list|(
name|decl
parameter_list|)
value|decl
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__< 7 */
end_comment

begin_define
define|#
directive|define
name|SM_UNUSED
parameter_list|(
name|decl
parameter_list|)
value|decl __attribute__((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__< 7 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__>= 2 */
end_comment

begin_define
define|#
directive|define
name|SM_UNUSED
parameter_list|(
name|decl
parameter_list|)
value|decl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__>= 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_UNUSED */
end_comment

begin_comment
comment|/* **  The SM_NONVOLATILE macro is used to declare variables that are not **  volatile, but which must be declared volatile when compiling with **  gcc -O -Wall in order to suppress bogus warning messages. ** **  Variables that actually are volatile should be declared volatile **  using the "volatile" keyword.  If a variable actually is volatile, **  then SM_NONVOLATILE should not be used. ** **  To compile sendmail with gcc and see all non-bogus warnings, **  you should use **	gcc -O -Wall -DSM_OMIT_BOGUS_WARNINGS ... **  Do not use -DSM_OMIT_BOGUS_WARNINGS when compiling the production **  version of sendmail, because there is a performance hit. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SM_OMIT_BOGUS_WARNINGS
end_ifdef

begin_define
define|#
directive|define
name|SM_NONVOLATILE
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_OMIT_BOGUS_WARNINGS */
end_comment

begin_define
define|#
directive|define
name|SM_NONVOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_OMIT_BOGUS_WARNINGS */
end_comment

begin_comment
comment|/* **  Turn on format string argument checking. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_FORMAT_TEST
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
end_if

begin_define
define|#
directive|define
name|SM_CONF_FORMAT_TEST
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__>= 7 */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_FORMAT_TEST
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ == 2&& __GNUC_MINOR__>= 7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_FORMAT_TEST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PRINTFLIKE
end_ifndef

begin_if
if|#
directive|if
name|SM_CONF_FORMAT_TEST
end_if

begin_define
define|#
directive|define
name|PRINTFLIKE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__attribute__ ((__format__ (__printf__, x, y)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_FORMAT_TEST */
end_comment

begin_define
define|#
directive|define
name|PRINTFLIKE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_FORMAT_TEST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! PRINTFLIKE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCANFLIKE
end_ifndef

begin_if
if|#
directive|if
name|SM_CONF_FORMAT_TEST
end_if

begin_define
define|#
directive|define
name|SCANFLIKE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__attribute__ ((__format__ (__scanf__, x, y)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_FORMAT_TEST */
end_comment

begin_define
define|#
directive|define
name|SCANFLIKE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_FORMAT_TEST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SCANFLIKE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CDEFS_H */
end_comment

end_unit

