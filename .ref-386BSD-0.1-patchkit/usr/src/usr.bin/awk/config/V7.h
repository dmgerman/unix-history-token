begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** V7.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* The port of mawk to V7 is the work of Carl Mascott (cmascott@world.std.com) */
end_comment

begin_comment
comment|/*$Log:	V7.h,v $  * Revision 4.2  91/11/21  13:30:34  brennan  *      *   * 11/17/91  C. Mascott		declare fprintf, sprintf on V7  *  * Revision 4.1  91/09/25  11:40:41  brennan  * VERSION 1.0  *   * Revision 1.4  91/08/16  08:22:09  brennan  * Carl's addition of SW_FP_CHECK for XNX23A  *   * Revision 1.3  91/08/13  09:04:07  brennan  * VERSION .9994  *   * Revision 1.2  91/06/15  09:28:54  brennan  * Carl's diffs for V7  *   * 06/11/91  C. Mascott		change NO_FMOD to HAVE_FMOD  *				change NO_STRTOD to HAVE_STRTOD  *  * Revision 1.1  91/06/10  14:20:03  brennan  * Initial revision  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
value|1
end_define

begin_define
define|#
directive|define
name|V7
end_define

begin_define
define|#
directive|define
name|HAVE_VOID_PTR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STRTOD
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_FMOD
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_MATHERR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|0
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_define
define|#
directive|define
name|vfprintf
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|_doprnt(f,a,s)
end_define

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XNX23A
end_ifdef

begin_comment
comment|/* convert double to Boolean.  This is a bug work-around for    XENIX-68K 2.3A, where logical test of double doesn't work.  This    macro NG for register double. */
end_comment

begin_define
define|#
directive|define
name|D2BOOL
parameter_list|(
name|x
parameter_list|)
value|(*((long *)&(x)))
end_define

begin_define
define|#
directive|define
name|SW_FP_CHECK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* these are missing and print.c needs them */
end_comment

begin_function_decl
name|void
name|fprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"config/Idefault.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

