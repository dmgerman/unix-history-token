begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      CONF.H  *      UTREE system dependent configurable definitions.  *      3.03-um klin, Sat Feb 15 19:23:58 1992  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  *  *      Version:        Consensys V.4 UNIX  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_conf
index|[]
init|=
literal|"@(#) utree 3.03-um (klin) Feb 15 1992 conf.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/*  *      This file contains definitions you can change for your needs.  */
end_comment

begin_comment
comment|/*  *      SOME UTREE DEPENDENT DEFINITIONS.  */
end_comment

begin_comment
comment|/* BSD: define HASVSPRINTF if your system supports vsprintf(3)          */
end_comment

begin_comment
comment|/*#define HASVSPRINTF             /* Not needed for SYSV!                 */
end_comment

begin_comment
comment|/* SYSV: define HASFIONREAD if your system supports the FIONREAD        */
end_comment

begin_comment
comment|/*       ioctl(2) system call to check how many chars are typed ahead   */
end_comment

begin_define
define|#
directive|define
name|HASFIONREAD
end_define

begin_comment
comment|/* Not needed for BSD!                  */
end_comment

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_comment
comment|/* Needed for definition of FIONREAD    */
end_comment

begin_comment
comment|/* SYSV: define HASVFORK if your system supports vfork(2)               */
end_comment

begin_define
define|#
directive|define
name|HASVFORK
end_define

begin_comment
comment|/* Not needed for BSD!                  */
end_comment

begin_comment
comment|/* SYSV: define NODIRENT if your system not supports the directory type */
end_comment

begin_comment
comment|/*       struct dirent with opendir(3), closedir(3) and readdir(3)      */
end_comment

begin_comment
comment|/*#define NODIRENT                /* Needed only for older SYSVs          */
end_comment

begin_comment
comment|/* ALL: define NOWINCHG to ignore sreen resizing on window systems. The */
end_comment

begin_comment
comment|/*      handling of screen resizing is intended as a little bit support */
end_comment

begin_comment
comment|/*      for window systems like X, but it may not run on your system.   */
end_comment

begin_comment
comment|/*      ATTENTION: Resizing may be confusing for utree anyway!          */
end_comment

begin_comment
comment|/*#define NOWINCHG                /* No screen resizing allowed           */
end_comment

begin_comment
comment|/* ALL: define STRUCTCOPY if your compiler doesn't support assignment   */
end_comment

begin_comment
comment|/*      of struct variables, i.e. t[o] = f[rom].                        */
end_comment

begin_comment
comment|/*#define STRUCTCOPY(f, t) memcpy(t, f, sizeof(f))        /* For SYSV     */
end_comment

begin_comment
comment|/*#define STRUCTCOPY(f, t) bcopy(f, t, sizeof(f))         /* For BSD      */
end_comment

begin_comment
comment|/* ALL: define UTCLOCK for a clock updated in echo line every second    */
end_comment

begin_define
define|#
directive|define
name|UTCLOCK
end_define

begin_comment
comment|/* Show/update clock                    */
end_comment

begin_comment
comment|/* ALL: directory for utree startup file and help pages                 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTLIB
end_ifndef

begin_define
define|#
directive|define
name|UTLIB
value|"/usr/local/lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !UTLIB */
end_comment

end_unit

