begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  **********************************************************************  * HISTORY  * $Log: libc.h,v $  * Revision 1.1.1.1  1995/12/26 04:54:47  peter  * Import the unmodified version of the sup that we are using.  * The heritage of this version is not clear.  It appears to be NetBSD  * derived from some time ago.  *  * Revision 1.1.1.1  1993/08/21  00:46:33  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:17  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.7  89/04/03  11:10:45  vanryzin  * 	Changed definition of qsort for c++ to indicate the procedure  * 	passed to qsort has parameters.  Since we were unsure if ANSI C  * 	could handle the syntax I placed the new definition within #if  * 	defined(c_plusplus) conditionals.  This may not be necessary  * 	and perhaps should be fixed at a later time.  * 	[89/04/03            vanryzin]  *   * Revision 1.6  89/02/05  15:55:57  gm0w  * 	Added extern char *errmsg().  * 	[89/02/04            gm0w]  *   * Revision 1.5  89/01/20  15:34:40  gm0w  * 	Moved all of the STDC changes to other existing include files  * 	back into this one.  Added non-STDC extern declarations for  * 	all functions without int return values to match those defined  * 	by STDC.  Added include of sysent.h.  Removed obsolete cdate  * 	extern declaration.  * 	[88/12/17            gm0w]  *   * Revision 1.4  88/12/22  16:58:56  mja  * 	Correct __STDC__ parameter type for getenv().  * 	[88/12/20            dld]  *   * Revision 1.3  88/12/14  23:31:42  mja  * 	Made file reentrant.  Added declarations for __STDC__.  * 	[88/01/06            jjk]  *   * 30-Apr-88  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added pathof() extern.  *  * 01-Dec-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added getname() extern.  *  * 29-Nov-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added lseek() extern.  *  * 02-Nov-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added salloc() extern.  *  * 14-Aug-81  Mike Accetta (mja) at Carnegie-Mellon University  *	Created.  *  **********************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBC_H_
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TYPES_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSENT_H_
end_ifndef

begin_include
include|#
directive|include
file|<sysent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSENT_H_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRINGS_H_
end_ifndef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRINGS_H_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_H_
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TIME_H_ */
end_comment

begin_comment
comment|/*  CMU stdio additions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fopenp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fwantread
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fwantwrite
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fopenp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fwantread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fwantwrite
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* CMU string routines */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|foldup
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|folddown
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sindex
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|skipto
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|skipover
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nxtarg
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|_argbreak
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|getstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getstab
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getsearch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|stabarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|searcharg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|intarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|getlong
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|longarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|getshort
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|shortarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|getfloat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|floatarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|getdouble
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|doublearg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|getoct
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|octarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|gethex
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|hexarg
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|atoo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|atoh
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|salloc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|concat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|foldup
argument_list|()
decl_stmt|,
modifier|*
name|folddown
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sindex
argument_list|()
decl_stmt|,
modifier|*
name|skipto
argument_list|()
decl_stmt|,
modifier|*
name|skipover
argument_list|()
decl_stmt|,
modifier|*
name|nxtarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getstr
argument_list|()
decl_stmt|,
modifier|*
name|strarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|getlong
argument_list|()
decl_stmt|,
name|longarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|getshort
argument_list|()
decl_stmt|,
name|shortarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|getfloat
argument_list|()
decl_stmt|,
name|floatarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|getdouble
argument_list|()
decl_stmt|,
name|doublearg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|getoct
argument_list|()
decl_stmt|,
name|octarg
argument_list|()
decl_stmt|,
name|gethex
argument_list|()
decl_stmt|,
name|hexarg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|atoo
argument_list|()
decl_stmt|,
name|atoh
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|salloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|concat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* CMU library routines */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|getname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pathof
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|errmsg
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pathof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|errmsg
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/*  CMU time additions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|long
name|gtime
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|atot
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|long
name|gtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|atot
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* 4.3 BSD standard library routines; taken from man(3) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|PFI
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|c_plusplus
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|PFI2
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* c_plusplus */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|utimes
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SH
end_ifndef

begin_define
define|#
directive|define
name|LOCK_SH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_EX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_EX
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_NB
end_ifndef

begin_define
define|#
directive|define
name|LOCK_NB
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_UN
end_ifndef

begin_define
define|#
directive|define
name|LOCK_UN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hpux */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|extern void abort(void); extern int abs(int); extern double atof(const char *); extern int atoi(const char *); extern long atol(const char *); extern void bcopy(const void *, void *, int); extern int bcmp(const void *, const void *, int); extern void bzero(void *, int); extern int ffs(int); extern char *crypt(const char *, const char *); extern void setkey(char *); extern void encrypt(char *, int); extern char *ecvt(double, int, int *, int *); extern char *fcvt(double, int, int *, int *); extern char *gcvt(double, int, char *); extern int execl(const char *, ...); extern int execv(const char *, const char **); extern int execle(const char *, ...); extern int exect(const char *, const char **, const char **); extern void exit(int); extern char *getenv(const char *); extern char *getlogin(void); extern int getopt(int, const char **, const char *); extern char *getpass(const char *); extern char *getusershell(void); extern void setusershell(void); extern void endusershell(void); extern char *getwd(char *); extern int initgroups(const char *, gid_t); extern void *malloc(unsigned); extern void free(void *); extern void *realloc(void *, unsigned); extern void *calloc(unsigned, unsigned); extern void *alloca(int); extern char *mktemp(char *); extern int mkstemp(char *); extern void monitor(PFI, PFI, short *, int, int); extern void monstartup(PFI, PFI); extern void moncontrol(int); extern int pause(void);
if|#
directive|if
name|defined
argument_list|(
name|c_plusplus
argument_list|)
end_if

begin_else
unit|extern void qsort(void *, int, int, PFI2);
else|#
directive|else
end_else

begin_comment
comment|/* c_plusplus */
end_comment

begin_endif
unit|extern void qsort(void *, int, int, PFI);
endif|#
directive|endif
end_endif

begin_comment
comment|/* c_plusplus */
end_comment

begin_endif
unit|extern long random(void); extern int srandom(int); extern void *initstate(unsigned, void *, int); extern void *setstate(void *); extern int rcmd(char **, int, const char *, const char *, const char *, int); extern int rresvport(int *); extern int ruserok(char *, int, const char *, const char *); extern char *re_comp(char *); extern int re_exec(char *); extern int rexec(char **, int, const char *, const char *, const char *, 		 int *); extern int setuid(uid_t); extern int seteuid(uid_t); extern int setruid(uid_t); extern int setgid(gid_t); extern int setegid(gid_t); extern int setrgid(gid_t); extern void sleep(unsigned); extern void swab(void *, void *, int); extern int system(const char *); extern char *ttyname(int); extern int isatty(int); extern int ttyslot(void); extern unsigned ualarm(unsigned, unsigned); extern void usleep(unsigned);
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ecvt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fcvt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gcvt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpass
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getusershell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|initstate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|setstate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_comp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|ualarm
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _LIBC_H_ */
end_comment

end_unit

